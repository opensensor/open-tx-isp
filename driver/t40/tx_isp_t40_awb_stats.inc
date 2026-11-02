/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AWB statistics.  Hand translation of the Eufy OEM module (tx-isp-t40.ko):
 *   tisp_awb_get_statistics   0x32e08   unpack of the hardware zone records (AWB IRQ, every frame)
 *   tisp_awb_sat_weight       0x33a04   per-zone saturation weight (called by tisp_awb_long_alogrithm)
 * They run in place of the translated OEM code (VAE_STOP, tx_isp_t40_vawb.h), bit for bit the same
 * (tests/t40_vawb_host.sh with GR_REF: both versions on the same fuzzed records and state).
 *
 * Zone record = 16 bytes = four words holding five bit fields:
 *   plane 0 = w0[21:0]            plane 1 = w0[31:22] | w1[11:0] << 10     plane 2 = w1[31:12] | w2[1:0] << 20
 *   plane 3 = w2[23:2]            plane 4 = w2[31:24] | w3[5:0] << 8
 * The hardware writes eight records per zone (groups 0..7, rows of the statistics RAM); a group g
 * lands in ctx[59 + 5 g .. 63 + 5 g] at zone index row * 15 + column (u32 per zone).  ctx[0] is the
 * AWB config block: u16 rows at +2, u16 columns at +6, u8 +94 "pair select" n, u8 +96 pair m.
 * n == 0: all four pairs of every zone are read (zone stride 128 B); n != 0: only pair m is in the
 * buffer (zone stride 32 B) and m > 3 reads nothing.  Pair k = groups (4 + k, k), records at
 * zone + (k - n * m) * 32 and + 16 bytes.
 * Divisions by zero give 0 like the translated code (the OEM traps there; never seen with real values).
 */

static u32 t40_ag_divu(u32 x, u32 y, u32 pc)
{
	if (unlikely(!y)) { vawb_fault_note(0, pc); return 0; }
	return x / y;
}

static void t40_as_unpack(const u32 *ctx, u32 grp, const u32 *rec, u32 z)
{
	u32 w0 = rec[0], w1 = rec[1], w2 = rec[2], w3 = rec[3];
	u32 *pl = (u32 *)(uintptr_t)ctx[59 + 5 * grp];

	pl[z] = w0 & 0x3fffffU;
	pl = (u32 *)(uintptr_t)ctx[60 + 5 * grp];
	pl[z] = (w1 << 10 & 0x3ffc00U) | w0 >> 22;
	pl = (u32 *)(uintptr_t)ctx[61 + 5 * grp];
	pl[z] = (w2 << 20 & 0x300000U) | w1 >> 12;
	pl = (u32 *)(uintptr_t)ctx[62 + 5 * grp];
	pl[z] = w2 >> 2 & 0x3fffffU;
	pl = (u32 *)(uintptr_t)ctx[63 + 5 * grp];
	pl[z] = (w3 << 8 & 0x3f00U) | w2 >> 24;
}

static void t40_awb_get_statistics(u32 addr, const u32 *ctx)
{
	const u8 *cfg, *raw = (const u8 *)(uintptr_t)addr;
	u32 rows, cols, n, m, zs, k, row, col, i;

	if (unlikely(!vawb_ok(addr, 3) || !vawb_ok((u32)(uintptr_t)ctx, 3) || !vawb_ok(ctx[0], 1))) {
		vawb_fault_note(addr, 207000U);
		return;
	}
	for (i = 59; i <= 98; i++)
		if (unlikely(!vawb_ok(ctx[i], 3))) { vawb_fault_note(ctx[i], 207004U); return; }
	cfg = (const u8 *)(uintptr_t)ctx[0];
	rows = *(const u16 *)(cfg + 2); cols = *(const u16 *)(cfg + 6);
	n = cfg[94]; m = cfg[96];
	zs = 128U - 96U * n;			/* bytes per zone */
	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++) {
			const u8 *zone = raw + row * zs * cols + col * zs;
			u32 z = row * 15 + col;

			for (k = 0; k < 4; k++) {
				const u8 *pair;

				if (n && k != m)	/* n != 0: only pair m is present */
					continue;
				pair = zone + (int32_t)((k - n * m) * 32U);
				t40_as_unpack(ctx, 4 + k, (const u32 *)pair, z);
				t40_as_unpack(ctx, k, (const u32 *)(pair + 16), z);
			}
		}
}

/*
 * OEM tisp_awb_sat_weight(sumR, sumG, sumB, count, sat, gain, ctx): per zone saturation weight
 *   sat[z] = 1                                   empty zone, count at or below the minimum, or no colour left
 *   sat[z] = (m << s) / max(n, a, b)             ctx[24] == 1       a = R * gain[0] >> s, b = B * gain[1] >> s
 *   sat[z] = (m << s) / ((a + b + n) / 3)        otherwise          m = min(a, b, n), n = sumG
 * s = ctx[3] precision, minimum count = *ctx[1], zones as in ctx[0] (rows +2, columns +6).
 */
static void t40_awb_sat_weight(const u32 *pr, const u32 *pg, const u32 *pb, const u32 *pcnt, u32 *sat, const u32 *gain,
			       const u32 *ctx)
{
	const u8 *cfg = (const u8 *)(uintptr_t)ctx[0];
	u32 rows = *(const u16 *)(cfg + 2), cols = *(const u16 *)(cfg + 6);
	u32 thr = *(const u32 *)(uintptr_t)ctx[1], s = *(const u16 *)(uintptr_t)ctx[3];
	u32 mode = *(const u16 *)(uintptr_t)ctx[24], r, c, z;

	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			u32 n, a, b, m, d;

			z = r * 15 + c;
			n = pg[z];
			if (!n || !(thr < pcnt[z])) { sat[z] = 1; continue; }
			a = pr[z] * gain[0] >> (s & 31);
			b = pb[z] * gain[1] >> (s & 31);
			m = b < a ? b : a;
			if (n < m) m = n;
			if (!m) { sat[z] = 1; continue; }
			if (mode == 1) {
				d = a < b ? b : a;
				if (d < n) d = n;
			} else {
				d = t40_ag_divu(a + b + n, 3, 206652U);
			}
			sat[z] = t40_ag_divu(m << (s & 31), d, mode == 1 ? 206624U : 206664U);
		}
}

/* VAE_STOP adapters: same o32 arguments as the OEM calls; no caller uses the return value */
static u64 vawb_s_tisp_awb_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_awb_get_statistics(a0, (const u32 *)(uintptr_t)a1);
	return 0;
}
