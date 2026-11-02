/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AWB gain / threshold chain.  Hand translation of the Eufy OEM module (tx-isp-t40.ko):
 *   tisp_awb_set_gain             0x417ec   tisp_awb_gain_reg        0x417b8
 *   tisp_awb_set_regional_threshold 0x40f5c tisp_awb_set_lum_th_freq 0x41124
 *   tisp_awb_tgain_update         0x44b28   tisp_simple_intp_int16   0x40e14
 *   tisp_ae_main_mean_update / tisp_ae_sec_mean_update (the AE mean read by set_lum_th_freq)
 *   system_reg_set_awb_trig
 * They run in place of the translated OEM code (VAE_STOP, tx_isp_t40_vawb.h), bit for bit the same
 * (tests/t40_vawb_host.sh with GR_REF: both versions on every call with fuzzed state, register write
 * order and values, all state the functions touch).
 *
 * The OEM tele path of set_gain (tisp_awb_calc_tele_gain + tisp_awb_calc_div_sqrt_distance, taken only
 * when awb_wide_tele_para[0] == 1) is not translated: the open stack runs one sensor and
 * the event 13 of the process (tx_isp_t40_awb_main.inc) carries the colour temperature of the one channel, so the branch is never taken.
 *
 * ctx = pstMainAwbOri / pstSecAwbOri (u32 pointer table):
 *   ctx[0]   u16 config block: +68..+82 regional thresholds [8], +84..+90 luma threshold / frequency [4]
 *   ctx[3]   u16 [0] fixed-point precision, [1] gain shift     ctx[5] u32 convergence state, [4]/[5] current r/b
 *   ctx[7]   u32 colour temperature   ctx[9] u32 [2] algorithm gains r, b (Q10)
 *   ctx[34]  u16 tables, 11 knots per row (22 B): rows 0..7 regional thresholds, rows 8..10 luma
 *   ctx[36]  u32 [8] CT-zone offsets (hot / cold / mid pairs and the two CT limits)
 *   ctx[56]  u32 last CT that switched the zone   ctx[58] u32 [2] zone offset pair in use
 *   ctx[117] u32 interpolation position (index << 16 | fraction)   ctx[118] u8 force flag
 *   ctx[119] u8 freeze   ctx[120] u8 override mode (1..8 table, 9 scale)   ctx[121] u32 override CT
 *   ctx[122] u16 [2] override gains   ctx[124] u16 [4] gain pair history (previous, 65536 / gain)
 * Divisions by zero give 0 like the translated code (the OEM traps there; never seen with real values).
 */

#define T40_AG_P32(i) ((u32 *)(uintptr_t)ctx[i])
#define T40_AG_P16(i) ((u16 *)(uintptr_t)ctx[i])
#define T40_AG_P8(i)  ((u8 *)(uintptr_t)ctx[i])

/* every pointer of ctx[] the functions use must be a valid (aligned kernel) address, as the guarded loads require */
static bool t40_ag_ctx_ok(const u32 *ctx)
{
	static const u8 w32[] = { 5, 7, 9, 36, 56, 58, 117, 121 };
	static const u8 w16[] = { 0, 3, 34, 122, 124 };
	static const u8 w8[] = { 118, 119, 120 };
	u32 i;

	if (!vawb_ok((u32)(uintptr_t)ctx, 3))
		return false;
	for (i = 0; i < ARRAY_SIZE(w32); i++) if (!vawb_ok(ctx[w32[i]], 3)) return false;
	for (i = 0; i < ARRAY_SIZE(w16); i++) if (!vawb_ok(ctx[w16[i]], 1)) return false;
	for (i = 0; i < ARRAY_SIZE(w8); i++) if (!vawb_ok(ctx[w8[i]], 0)) return false;
	return true;
}

/* OEM tisp_simple_intp_int16: linear interpolation between knots idx and idx + 1 of an 11-knot u16 row,
 * fraction in 1/65536 with rounding on bit 15; idx >= 10 takes the last knot */
static u32 t40_ag_intp(u32 idx, u32 frac, const u16 *row)
{
	u32 a, b, d, r;

	if (idx >= 10)
		return row[10];
	a = row[idx]; b = row[idx + 1];
	if (a == b)
		return a;
	d = (a < b ? b - a : a - b) * frac;
	r = ((d >> 16) + ((d >> 15) & 1)) & 0xffff;
	return (a < b ? a + r : a - r) & 0xffff;
}

/* OEM system_reg_set_awb_trig: latch the written block (1 thresholds, 2 / 3 gains) for channel ch */
static void t40_ag_trig(u32 sel, u32 ch)
{
	static const u16 reg[2][3] = { { 0x8000, 0x4000, 0x5000 }, { 0x8200, 0x4020, 0x5020 } };

	if (sel - 1 < 3)
		system_reg_write(sel == 1 ? 0x10000U | reg[ch != 0][0] : reg[ch != 0][sel - 1], 1);
}

/* OEM tisp_ae_{main,sec}_mean_update: mean of the AE zone sums divided by the exposure value */
static void t40_ag_ae_mean(const u8 *ae)
{
	const u32 *a = (const u32 *)ae;
	const u16 *geo = (const u16 *)(uintptr_t)a[71];
	const u32 *sum = (const u32 *)(uintptr_t)a[34];
	u32 rows, cols, r, c, s = 0, q;

	if (unlikely(!vawb_ok(a[71], 1) || !vawb_ok(a[34], 3) || !vawb_ok(a[11] + 8, 3) || !vawb_ok(a[68], 3))) {
		vawb_fault_note(a[71], 165504U);
		return;
	}
	rows = geo[1]; cols = geo[3];
	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++)
			s += sum[r * 15 + c];
	q = t40_ag_divu(s, cols * rows, 165528U);
	q = t40_ag_divu(q << 10, *(const u32 *)(uintptr_t)(a[11] + 8), 165548U);
	*(u32 *)(uintptr_t)a[68] = q;
}

static void t40_ag_regional_threshold(const u32 *ctx, u32 ch)
{
	u16 *cfg = T40_AG_P16(0);
	const u16 *tbl = T40_AG_P16(34);
	u32 pos = *T40_AG_P32(117), idx = pos >> 16, frac = pos & 0xffff, k;

	for (k = 0; k < 8; k++)
		cfg[34 + k] = t40_ag_intp(idx, frac, tbl + 11 * k);
	if (!*T40_AG_P8(119)) {
		u32 w0 = (u32)cfg[35] << 16 | cfg[34], w1 = (u32)cfg[37] << 16 | cfg[36];
		u32 w2 = (u32)cfg[39] << 16 | cfg[38], w3 = (u32)cfg[41] << 16 | cfg[40];
		u32 base = ch ? 0x18228U : 0x18028U;

		system_reg_write(base, w0);
		system_reg_write(base + 4, w1);
		system_reg_write(base + 8, w2);
		system_reg_write(base + 12, w3);
		t40_ag_trig(1, ch);
	}
}

static void t40_ag_lum_th_freq(const u32 *ctx, u32 ch)
{
	u16 *cfg = T40_AG_P16(0);
	const u16 *tbl = T40_AG_P16(34);
	u32 pos = *T40_AG_P32(117), idx = pos >> 16, frac = pos & 0xffff;

	cfg[42] = t40_ag_intp(idx, frac, tbl + 88);
	cfg[43] = t40_ag_intp(idx, frac, tbl + 99);
	cfg[44] = t40_ag_intp(idx, frac, tbl + 110);
	t40_ag_ae_mean(ch ? pstSecAeOri_storage : pstMainAeOri_storage);
	system_reg_write(ch ? 0x18238U : 0x18038U,
			 (u32)cfg[45] << 24 | (u32)cfg[44] << 16 | (u32)cfg[43] << 8 | cfg[42]);
	t40_ag_trig(1, ch);
}

/* OEM tisp_awb_tgain_update(sensor, unused, position): store the interpolation position, refresh thresholds */
static void t40_ag_tgain_update(u32 sensor, u32 pos)
{
	const u32 *ctx = sensor ? pstSecAwbOri : pstMainAwbOri;
	u32 ch = sensor & 255;

	if (unlikely(!t40_ag_ctx_ok(ctx))) { vawb_fault_note((u32)(uintptr_t)ctx, 214600U); return; }
	*T40_AG_P32(117) = pos;
	t40_ag_regional_threshold(ctx, ch);
	t40_ag_lum_th_freq(ctx, ch);
}

/* OEM tisp_awb_set_gain: algorithm gains -> hardware gain registers of channel ch (0 / 1) */
static void t40_ag_set_gain(const u32 *ctx, u32 ch)
{
	const u16 *prec_p;
	const u32 *zt, *gain, *cur;
	u16 *hist;
	u32 *pair;
	u32 prec, shift, rnd, gr, gb, mode, ct, last, diff, z0, z1;
	u32 out[2];

	if (unlikely(!t40_ag_ctx_ok(ctx))) { vawb_fault_note((u32)(uintptr_t)ctx, 200832U); return; }
	prec_p = T40_AG_P16(3); prec = prec_p[0]; shift = prec_p[1];
	zt = T40_AG_P32(36);
	gain = T40_AG_P32(9);
	cur = T40_AG_P32(5);
	pair = T40_AG_P32(58);
	hist = T40_AG_P16(124);

	/* current statistics gains times the algorithm gains, rounded back to the working precision */
	rnd = 1U << ((shift - 1) & 31);
	gr = ((u32)fix_point_mult2_32(prec, cur[4] << (shift & 31), gain[0] << ((prec - 10) & 31)) + rnd) >> (shift & 31);
	gb = ((u32)fix_point_mult2_32(prec, cur[5] << (shift & 31), gain[1] << ((prec - 10) & 31)) + rnd) >> (shift & 31);

	/* the reciprocal pair the AE / CCM side reads, keeping the previous one */
	hist[2] = hist[0];
	hist[3] = hist[1];
	hist[0] = t40_ag_divu(0x10000U, gr, 201308U);
	hist[1] = t40_ag_divu(0x10000U, gb, 201328U);

	mode = *T40_AG_P8(120);
	if (mode - 1 < 8) {		/* fixed gains of a manual white balance mode and its colour temperature */
		const u16 *ov = T40_AG_P16(122);

		gr = ov[0]; gb = ov[1];
		*T40_AG_P32(7) = *T40_AG_P32(121);
	} else if (mode == 9) {		/* manual scale: (value + 64) / 64 */
		const u16 *ov = T40_AG_P16(122);

		gr = (ov[0] + 64U) * gr >> 6;
		gb = (ov[1] + 64U) * gb >> 6;
	}

	/* colour temperature zone: hot / mid / cold gain offset pair, re-selected after a 200 K move or when forced */
	ct = *T40_AG_P32(7);
	last = *T40_AG_P32(56);
	diff = ct > last ? ct - last : last - ct;
	if (diff >= 200 || *T40_AG_P8(118) == 1) {
		*T40_AG_P32(56) = ct;
		if (*T40_AG_P32(7) < zt[7]) {
			if (zt[6] < *T40_AG_P32(7)) { z0 = zt[2]; z1 = zt[3]; }
			else { z0 = zt[4]; z1 = zt[5]; }
		} else {
			z0 = zt[0]; z1 = zt[1];
		}
		pair[0] = z0;
		pair[1] = z1;
	}

	gr = gr * 4 - 1024 + pair[0];
	gb = gb * 4 - 1024 + pair[1];
	out[0] = (gr < 0x4000 ? gr : 0x3fff) | 0x4000000;	/* OEM tisp_awb_gain_reg: 14-bit gain, bit 26 = valid */
	out[1] = (gb < 0x4000 ? gb : 0x3fff) | 0x4000000;

	if (!*T40_AG_P8(119)) {
		u32 base = ch ? 0x4024U : 0x4004U;

		system_reg_write(base, out[0]);
		system_reg_write(base + 4, out[1]);
		system_reg_write(base + 8, out[0]);
		system_reg_write(base + 12, out[1]);
		t40_ag_trig(2, ch);
		base = ch ? 0x5024U : 0x5004U;
		system_reg_write(base, out[0]);
		system_reg_write(base + 4, out[1]);
		system_reg_write(base + 8, out[0]);
		system_reg_write(base + 12, out[1]);
		t40_ag_trig(3, ch);
	}
	*T40_AG_P8(118) = 0;
}

/* VAE_STOP adapters: same o32 arguments as the OEM calls; no caller uses the return value */
static u64 vawb_s_tisp_awb_set_gain(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_ag_set_gain((const u32 *)(uintptr_t)a0, a1);
	return 0;
}
static u64 vawb_s_tisp_awb_set_regional_threshold(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	const u32 *ctx = (const u32 *)(uintptr_t)a0;

	if (unlikely(!t40_ag_ctx_ok(ctx))) { vawb_fault_note(a0, 199200U); return 0; }
	t40_ag_regional_threshold(ctx, a1);
	return 0;
}
static u64 vawb_s_tisp_awb_set_lum_th_freq(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	const u32 *ctx = (const u32 *)(uintptr_t)a0;

	if (unlikely(!t40_ag_ctx_ok(ctx))) { vawb_fault_note(a0, 199600U); return 0; }
	t40_ag_lum_th_freq(ctx, a1);
	return 0;
}
static u64 vawb_s_tisp_awb_tgain_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_ag_tgain_update(a0, a2);
	return 0;
}

#undef T40_AG_P32
#undef T40_AG_P16
#undef T40_AG_P8
