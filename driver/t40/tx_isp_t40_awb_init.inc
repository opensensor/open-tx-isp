/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AWB context set-up (init, day/night, EV).  Hand translation of the Eufy OEM module (tx-isp-t40.ko):
 *   tisp_awb_params_transmit   0x2e800   the 128-entry context pointer table
 *   tisp_awb_params_refresh    0x300bc   tuning parameter block -> outer block, statistics window geometry
 *   tisp_awb_set_hardware_param 0x30c9c  AWB statistics window / zone registers 0x8004.. (0x8204.. second sensor)
 *   tisp_awb_dn_params_refresh 0x34548   day / night switch: transmit + refresh + hardware parameters
 *   tisp_awb_main_ev_update    0x34fb4   exposure value -> Y weights
 *   tisp_awb_ev_update_Ywgt    0x341d0   luma weight table interpolated over the exposure value
 * They run in place of the translated OEM code (tx_isp_t40_vawb.h), bit for bit the same
 * (tests/t40_vawb_host.sh with GR_REF: both versions on every call with fuzzed state; register writes,
 * all state the functions reach, faults).
 *
 * ctx = pstMainAwbOri / pstSecAwbOri (u32 pointer table, see t40_am_params_transmit):
 *   ctx[0]   u16 config block (outer +0): +0 rows/2 origin, +2 columns, +4 ... statistics window, +94 u8 pair select
 *   ctx[21]  u32 [9] exposure thresholds     ctx[22] u16 [9] luma weights     ctx[55] u16 [4] interpolated weights
 *   ctx[49]  u16 [2] sensor width / height   ctx[54] u8 pair select source
 *   ctx[100] u8 (0 = hardware parameters may be written)    ctx[101] u8 refresh flag    ctx[118] u8 force flag
 *   ctx[116] u32 exposure value >> 10        ctx[119] u8 freeze
 * Divisions by zero give 0 like the translated code (the OEM traps there).
 */

#define T40_AM_P32(i) ((u32 *)(uintptr_t)ctx[i])
#define T40_AM_P16(i) ((u16 *)(uintptr_t)ctx[i])
#define T40_AM_P8(i)  ((u8 *)(uintptr_t)ctx[i])

/* the context of a channel and its tuning parameter source (tparamsN[ch] + 4288) */
static u32 *t40_am_ctx(u32 sensor)
{
	return sensor ? pstSecAwbOri : pstMainAwbOri;
}

/* every pointer of ctx[] a function dereferences must be a valid aligned kernel address, as the guarded OEM accesses require */
static bool t40_am_ok(const u32 *ctx, const u8 *w32, u32 n32, const u8 *w16, u32 n16, const u8 *w8, u32 n8)
{
	u32 i;

	if (!vawb_ok((u32)(uintptr_t)ctx, 3))
		return false;
	for (i = 0; i < n32; i++) if (!vawb_ok(ctx[w32[i]], 3)) return false;
	for (i = 0; i < n16; i++) if (!vawb_ok(ctx[w16[i]], 1)) return false;
	for (i = 0; i < n8; i++) if (!vawb_ok(ctx[w8[i]], 0)) return false;
	return true;
}

/* OEM tisp_awb_params_transmit: ctx[0..38] point into the outer block, ctx[39..127] into the inter block of the channel */
static const u16 t40_am_outer_off[39] = {
	    0,   100,   104,   108,   112,   124,   148,   160,
	  164,   168,   176,   216,   256,   260,   320,   380,
	  396,   412,   428,   436,   444,   456,   492,   512,
	  528,   540,   572,   584,   596,   636,   656,   676,
	 1576,  2476,  3376,  4404,  4632,  4672,  4712,
};
static const u16 t40_am_inter_off[89] = {
	    0,  1800,  3600,  5400,  7200, 10800, 12600, 13500,
	13508, 13516, 13518, 13534, 13536, 13546, 13566, 13586,
	13588, 13596, 13600, 14628, 14660, 15560, 16460, 17360,
	18260, 19160, 20060, 20960, 21860, 22760, 23660, 24560,
	25460, 26360, 27260, 28160, 29060, 29960, 30860, 31760,
	32660, 33560, 34460, 35360, 36260, 37160, 38060, 38960,
	39860, 40760, 41660, 42560, 43460, 44360, 45260, 46160,
	47060, 47960, 48860, 49760, 50660, 50680, 50681, 50684,
	50688, 50692, 50752, 50812, 50872, 51264, 51408, 52128,
	53088, 53988, 54888, 55788, 56688, 57588, 57592, 57596,
	57597, 57598, 57600, 57604, 57608, 57620, 57628, 58528,
	59428,
};

static void t40_am_params_transmit(u32 *ctx, u32 sensor)
{
	u32 outer = sensor ? (u32)stSecAwbOuter : (u32)stMainAwbOuter;
	u32 inter = sensor ? (u32)stSecAwbInter : (u32)stMainAwbInter;
	u32 i;

	if (unlikely(!vawb_ok((u32)(uintptr_t)ctx, 3))) { vawb_fault_note((u32)(uintptr_t)ctx, 190724U); return; }
	for (i = 0; i < ARRAY_SIZE(t40_am_outer_off); i++)
		ctx[i] = outer + t40_am_outer_off[i];
	for (i = 0; i < ARRAY_SIZE(t40_am_inter_off); i++)
		ctx[ARRAY_SIZE(t40_am_outer_off) + i] = inter + t40_am_inter_off[i];
}

/* OEM tisp_awb_params_refresh: byte ranges of the tuning block copied into the outer block of the channel (the
 * second sensor has no +456 / +492 part), then the zone width / height tables of the statistics window */
struct t40_am_copy { u16 off, len; };
static const struct t40_am_copy t40_am_copy_a[] = {
	{ 104, 4 }, { 108, 4 }, { 112, 12 }, { 148, 12 }, { 168, 8 }, { 176, 40 }, { 216, 40 }, { 256, 2 }, { 260, 60 },
	{ 320, 60 }, { 380, 16 }, { 396, 16 }, { 412, 16 }, { 428, 8 }, { 436, 8 }, { 444, 12 },
};
static const struct t40_am_copy t40_am_copy_main[] = { { 456, 36 }, { 492, 20 } };
static const struct t40_am_copy t40_am_copy_b[] = {
	{ 512, 16 }, { 528, 10 }, { 540, 32 }, { 572, 12 }, { 584, 10 }, { 596, 40 },
};
static const struct t40_am_copy t40_am_copy_c[] = {
	{ 676, 900 }, { 1576, 900 }, { 2476, 900 }, { 3376, 1028 }, { 4404, 225 }, { 4632, 40 }, { 4672, 40 }, { 4712, 40 },
};

/* OEM leaf memcpy: both addresses must be valid kernel addresses */
static void t40_am_memcpy(u32 dst, u32 src, u32 n)
{
	if (unlikely(!vawb_ok(dst, 0) || !vawb_ok(src, 0) || n > 0x10000U)) { vawb_fault_note(dst, 1); return; }
	memcpy((void *)(uintptr_t)dst, (const void *)(uintptr_t)src, n);
}

static void t40_am_copy_list(u32 outer, u32 src, const struct t40_am_copy *c, u32 n)
{
	u32 i;

	for (i = 0; i < n; i++)
		t40_am_memcpy(outer + c[i].off, src + c[i].off, c[i].len);
}

static void t40_am_params_refresh(u32 *ctx, u32 sensor, u32 src)
{
	static const u8 w16[] = { 0, 49 };
	static const u8 w8[] = { 54, 101, 118 };
	u32 outer = sensor ? (u32)stSecAwbOuter : (u32)stMainAwbOuter;
	u32 i;
	u16 *cfg;
	const u16 *wh;
	s32 w, h, nx, ny;
	u32 cx, cy;

	if (unlikely(!t40_am_ok(ctx, NULL, 0, w16, ARRAY_SIZE(w16), w8, ARRAY_SIZE(w8)) || !vawb_ok(outer, 3) || !vawb_ok(src, 3))) {
		vawb_fault_note(outer, 196912U);
		return;
	}
	*(u32 *)(uintptr_t)(outer + 100) = *(const u32 *)(uintptr_t)(src + 100);
	t40_am_memcpy(outer, src, 98);
	*(u16 *)(uintptr_t)(outer + 94) = *T40_AM_P8(54);
	t40_am_copy_list(outer, src, t40_am_copy_a, ARRAY_SIZE(t40_am_copy_a));
	if (!sensor)
		t40_am_copy_list(outer, src, t40_am_copy_main, ARRAY_SIZE(t40_am_copy_main));
	t40_am_copy_list(outer, src, t40_am_copy_b, ARRAY_SIZE(t40_am_copy_b));
	if (!*T40_AM_P8(101) && !*T40_AM_P8(118)) {
		*(u32 *)(uintptr_t)(outer + 160) = *(const u32 *)(uintptr_t)(src + 160);
		*(u32 *)(uintptr_t)(outer + 128) = 0;
		*(u32 *)(uintptr_t)(outer + 164) = *(const u32 *)(uintptr_t)(src + 164);
		*(u32 *)(uintptr_t)(outer + 124) = 1;
		*(u32 *)(uintptr_t)(outer + 132) = *(const u32 *)(uintptr_t)(src + 132);
		*(u32 *)(uintptr_t)(outer + 136) = *(const u32 *)(uintptr_t)(src + 136);
		*(u32 *)(uintptr_t)(outer + 140) = *(const u32 *)(uintptr_t)(src + 140);
		*(u32 *)(uintptr_t)(outer + 144) = *(const u32 *)(uintptr_t)(src + 144);
		t40_am_memcpy(outer + 636, src + 636, 20);
		t40_am_memcpy(outer + 656, src + 656, 20);
	} else {
		static const u16 off[] = { 646, 648, 650, 652, 654, 666, 668, 670, 672, 674 };

		for (i = 0; i < ARRAY_SIZE(off); i++)
			*(u16 *)(uintptr_t)(outer + off[i]) = *(const u16 *)(uintptr_t)(src + off[i]);
	}
	*T40_AM_P8(101) = 0;
	t40_am_copy_list(outer, src, t40_am_copy_c, ARRAY_SIZE(t40_am_copy_c));

	/* statistics window: zone width / height tables, rows and columns of half the sensor size around the origin */
	cfg = (u16 *)(uintptr_t)ctx[0];
	wh = (const u16 *)(uintptr_t)ctx[49];
	cx = cfg[2]; cy = cfg[0];
	nx = cfg[3]; ny = cfg[1];
	w = ((s32)wh[0] - (s32)cx + 1) / 2;
	h = ((s32)wh[1] - (s32)cy + 1) / 2;
	for (i = 0; (s32)i < nx; i++)
		cfg[4 + i] = (u16)(w / nx);
	for (i = 0; (s32)i < ny; i++)
		cfg[19 + i] = (u16)(h / ny);
}

/* OEM tisp_awb_set_hardware_param: pack the config block into the statistics window registers 0x18004.. (second sensor 0x18204..) */
static void t40_am_set_hardware_param(u32 *ctx, u32 sensor)
{
	static const u8 w32[] = { 0, 100 };
	const u16 *p;
	const u8 *b;
	u32 base, v[10];
	u32 i;

	if (unlikely(!t40_am_ok(ctx, w32, ARRAY_SIZE(w32), NULL, 0, NULL, 0))) { vawb_fault_note((u32)(uintptr_t)ctx, 199884U); return; }
	if (!*T40_AM_P8(100)) {
		p = T40_AM_P16(0);
		b = T40_AM_P8(0);
		v[0] = (u32)p[3] << 28 | (u32)p[2] << 16 | (u32)p[1] << 12 | p[0];
		v[1] = (u32)p[7] << 24 | (u32)p[6] << 16 | (u32)p[5] << 8 | p[4];
		v[2] = (u32)p[11] << 24 | (u32)p[10] << 16 | (u32)p[9] << 8 | p[8];
		v[3] = (u32)p[15] << 24 | (u32)p[14] << 16 | (u32)p[13] << 8 | p[12];
		v[4] = (u32)p[18] << 16 | (u32)p[17] << 8 | p[16];
		v[5] = (u32)p[22] << 24 | (u32)p[21] << 16 | (u32)p[20] << 8 | p[19];
		v[6] = (u32)p[26] << 24 | (u32)p[25] << 16 | (u32)p[24] << 8 | p[23];
		v[7] = (u32)p[30] << 24 | (u32)p[29] << 16 | (u32)p[28] << 8 | p[27];
		v[8] = (u32)p[33] << 16 | (u32)p[32] << 8 | p[31];
		v[9] = (u32)b[96] << 25 | (u32)b[94] << 28 | 0x01010103U | (u32)b[92] << 12;
		base = sensor ? 0x18204U : 0x18004U;
		for (i = 0; i < 9; i++)
			system_reg_write(base + 4 * i, v[i]);
		system_reg_write(base + 0x48, v[9]);
	}
	vawb_s_tisp_awb_set_regional_threshold((u32)(uintptr_t)ctx, sensor, 0, 0, 0);
	vawb_s_tisp_awb_set_lum_th_freq((u32)(uintptr_t)ctx, sensor, 0, 0, 0);
}

/* OEM tisp_awb_dn_params_refresh: day / night switch of channel `sensor` */
static void t40_am_dn_params_refresh(u32 sensor)
{
	u32 *ctx = t40_am_ctx(sensor);
	static const u8 w8[] = { 100, 101 };
	u32 ch = sensor & 255;

	if (unlikely(!t40_am_ok(ctx, NULL, 0, NULL, 0, w8, 2) || sensor > 1)) {
		vawb_fault_note((u32)(uintptr_t)ctx, 214392U);
		return;
	}
	*T40_AM_P8(100) = 0;
	*T40_AM_P8(101) = 1;
	t40_am_params_transmit(ctx, ch);
	t40_am_params_refresh(ctx, ch, (u32)tparamsN[sensor] + 4288);
	if (unlikely(!vawb_ok(pstMainAwbOri[119], 0))) { vawb_fault_note(pstMainAwbOri[119], 214476U); return; }
	if (!*(u8 *)(uintptr_t)pstMainAwbOri[119])
		t40_am_set_hardware_param(ctx, ch);
}

/* OEM tisp_awb_ev_update_Ywgt: the four luma weights follow the exposure value between the nine knots of ctx[21] / ctx[22] */
static void t40_am_ev_update_ywgt(const u32 *ctx)
{
	static const u8 w32[] = { 21, 116 };
	static const u8 w16[] = { 22, 55 };
	const u32 *thr, *evp;
	const u16 *tab;
	u16 *out;
	u32 ev, i, k;

	if (unlikely(!t40_am_ok(ctx, w32, ARRAY_SIZE(w32), w16, ARRAY_SIZE(w16), NULL, 0))) { vawb_fault_note((u32)(uintptr_t)ctx, 213456U); return; }
	evp = T40_AM_P32(116);
	thr = T40_AM_P32(21);
	tab = T40_AM_P16(22);
	out = T40_AM_P16(55);
	ev = *evp;
	if (ev <= thr[0]) {
		for (k = 0; k < 4; k++) out[k] = tab[0];
		return;
	}
	if (ev >= thr[8]) {
		for (k = 0; k < 4; k++) out[k] = tab[8];
		return;
	}
	for (i = 0; i < 8; i++) {
		u32 lo = thr[i], hi = thr[i + 1], v;

		if (lo >= ev || hi < ev)
			continue;
		/* lo < ev <= hi: linear interpolation between the two knots (all four weights are the same value) */
		if (lo == hi) {
			v = tab[i];
		} else {
			u32 a = tab[i], b = tab[i + 1], d = hi - lo, n = ev - lo;

			if (b < a)
				v = a - t40_ag_divu((a - b) * n, d, 214056U);
			else
				v = a + t40_ag_divu((b - a) * n, d, 214008U);
		}
		for (k = 0; k < 4; k++) out[k] = (u16)v;
		return;
	}
}

/* OEM tisp_awb_main_ev_update: the AE event's exposure value (Q10 gain times time) */
static void t40_am_main_ev_update(u32 ev)
{
	const u32 *ctx = pstMainAwbOri;

	if (unlikely(!vawb_ok(ctx[116], 3))) { vawb_fault_note(ctx[116], 217032U); return; }
	*T40_AM_P32(116) = ev >> 10;
	t40_am_ev_update_ywgt(ctx);
}

/* adapters (same o32 arguments as the OEM calls; no caller uses the return value) */
static u64 vawb_s_tisp_awb_params_transmit(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_params_transmit((u32 *)(uintptr_t)a0, a1);
	return 0;
}
static u64 vawb_s_tisp_awb_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_params_refresh((u32 *)(uintptr_t)a0, a1, a2);
	return 0;
}
static u64 vawb_s_tisp_awb_set_hardware_param(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_set_hardware_param((u32 *)(uintptr_t)a0, a1);
	return 0;
}
static u64 vawb_s_tisp_awb_dn_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_dn_params_refresh(a0);
	return 0;
}
static u64 vawb_s_tisp_awb_main_ev_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_main_ev_update(a0);
	return 0;
}
static u64 vawb_s_tisp_awb_ev_update_Ywgt(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_ev_update_ywgt((const u32 *)(uintptr_t)a0);
	return 0;
}

#undef T40_AM_P32
#undef T40_AM_P16
#undef T40_AM_P8
