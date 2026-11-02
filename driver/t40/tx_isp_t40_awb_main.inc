/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AWB per-frame process.  Hand translation of the Eufy OEM module (tx-isp-t40.ko):
 *   tisp_awb_main_process      0x33f08   one frame: parameters, statistics windows, long algorithm, gains, CT event
 *   tisp_awb_long_par_update   0x2d0a8   exposure value -> zone parameter set the colour-temperature detection reads
 *   tisp_awb_spec_calculate    0x33880   special-zone statistics window registers (and their gain-corrected limits)
 * They run in place of the translated OEM code (tx_isp_t40_vawb.h), bit for bit the same
 * (tests/t40_vawb_host.sh with GR_REF: both versions on every call with fuzzed state; register writes and
 * reads, events, all state the functions reach, faults).
 *
 * The OEM event 13 of a dual-sensor build carries the colour temperature of the second sensor when
 * awb_wide_tele_para[0] == 1; the open stack runs one sensor and clears that byte, so the branch (and the
 * parameter block) are gone, as is the tele gain in tx_isp_t40_awb_gain.inc.
 *
 * ctx = pstMainAwbOri (see tx_isp_t40_awb_init.inc), ct = pstMainAwbCtDetectOri (34 words the
 * colour-temperature detection reads: pointers into ctx[] and the zone parameter set ct[2] / ct[3]).
 */

#define T40_AM_P32(i) ((u32 *)(uintptr_t)ctx[i])
#define T40_AM_P16(i) ((u16 *)(uintptr_t)ctx[i])
#define T40_AM_P8(i)  ((u8 *)(uintptr_t)ctx[i])

/* d3 * p[k] + (q[k] - p[k]) * w, divided by d3: four words of the zone parameter set */
static void t40_am_blend4(u32 *dst, const u32 *p, const u32 *q, u32 d3, u32 w)
{
	u32 k;

	for (k = 0; k < 4; k++)
		dst[k] = t40_la_divs(d3 * p[k] + (q[k] - p[k]) * w, d3, 205672U);
}

static void t40_am_copy4(u32 *dst, const u32 *src)
{
	u32 k;

	for (k = 0; k < 4; k++)
		dst[k] = src[k];
}

/*
 * The exposure value ev (ctx[116]) picks the zone parameter set of the colour-temperature detection: below the
 * first threshold lo the set ctx[15], above the second one hi the set ctx[17], in between ctx[16]; each step is
 * blended over a third of the threshold distance (d3) on both sides.  ct[3] holds the matching weight pair
 * (ctx[46] / ctx[47], mode m0 / m1 of the pairs, for the day / night modes) and ct[4] the matching table.
 */
static void t40_am_long_par_update(const u32 *ctx, u32 *ct, u32 inter)
{
	static const u8 w32[] = { 6, 7, 8, 15, 16, 17, 18, 19, 46, 47, 116 };
	static const u8 w16[] = { 3 };
	static const u8 w8[] = { 12, 48 };
	/* ct[i] = ctx[ct_src[i]] (pointers the detection dereferences) */
	static const u8 ct_src[] = { 10, 48, 0, 0, 0, 0, 13, 14, 33, 35, 20, 7, 57, 3, 26, 24, 25, 11, 51, 28, 52, 53, 43, 44, 45,
				     107, 108, 109, 110, 111, 112, 113, 114, 115 };
	u32 *ct2 = (u32 *)(uintptr_t)(inter + 14636U), *ct3 = (u32 *)(uintptr_t)(inter + 14652U);
	const u32 *thr, *p15, *p16, *p17, *src18, *src19;
	u32 *pair46, *pair47;
	u8 *flag;
	const u8 *src12;
	u32 shift, ev, lo, hi, d3, mid, m0, m1, i;
	int tail = 0;			/* 1: ev in [hi, mid) with m1 == 0, 2: ev >= mid with m1 == 0 */

	if (unlikely(!t40_am_ok(ctx, w32, ARRAY_SIZE(w32), w16, ARRAY_SIZE(w16), w8, ARRAY_SIZE(w8)) ||
		     !vawb_ok((u32)(uintptr_t)ct, 3) || !vawb_ok(inter + 14636U, 3) || !vawb_ok(inter + 14652U, 3))) {
		vawb_fault_note((u32)(uintptr_t)ctx, 204940U);
		return;
	}
	thr = T40_AM_P32(6);
	p15 = T40_AM_P32(15); p16 = T40_AM_P32(16); p17 = T40_AM_P32(17);
	src18 = T40_AM_P32(18); src19 = T40_AM_P32(19);
	pair46 = T40_AM_P32(46); pair47 = T40_AM_P32(47);
	flag = T40_AM_P8(48);
	src12 = T40_AM_P8(12);
	shift = T40_AM_P16(3)[1];
	ev = *T40_AM_P32(116);
	lo = thr[0]; hi = thr[1];

	ct[2] = (u32)(uintptr_t)ct2;
	ct[3] = (u32)(uintptr_t)ct3;
	*T40_AM_P32(8) = *T40_AM_P32(7);
	pair46[0] = src18[0]; pair46[1] = src18[1] << (shift & 31);
	pair47[0] = src19[0]; pair47[1] = src19[1] << (shift & 31);
	m0 = pair46[0] & 0xffff;
	m1 = pair47[0] & 0xffff;

	if (ev < lo || ev < hi) {		/* below the second threshold: the first weight pair */
		flag[0] = 0;
		flag[1] = src12[1];
		ct[4] = ctx[32];
		ct3[0] = m0;
		ct3[1] = pair46[1];
	} else {
		flag[0] = src12[0];
		flag[1] = src12[1];
		ct[4] = ctx[31];
		ct3[0] = m1;
		ct3[1] = pair47[1];
	}

	d3 = t40_la_divs(hi - lo, 3, 205180U);
	mid = d3 + hi;
	if (m0 == 1) {
		bool via_common = true;

		if ((s32)ev < (s32)lo) {
			t40_am_copy4(ct2, p15);
		} else if ((s32)ev < (s32)(lo + d3)) {
			t40_am_blend4(ct2, p15, p16, d3, ev - lo);
		} else if ((s32)ev < (s32)hi) {
			t40_am_copy4(ct2, p16);
		} else if ((s32)ev < (s32)mid) {
			t40_am_blend4(ct2, p16, p17, d3, ev - hi);
			ct3[1] = t40_la_divs(d3 * pair46[1] + (pair47[1] - pair46[1]) * (ev - hi), d3, 205880U);
			via_common = false;
			if (!m1)
				tail = 1;
		} else {
			t40_am_copy4(ct2, p17);
			via_common = false;
			if (!m1)
				tail = 2;
		}
		if (via_common && !m1) {
			if ((s32)ev >= (s32)mid)
				tail = 2;
			else if ((s32)ev >= (s32)hi)
				tail = 1;
		}
	} else if (m0 == 0) {
		t40_am_copy4(ct2, p17);
		ct3[1] = 0x10000U;
		if (m1 == 1) {
			if ((s32)ev >= (s32)mid)
				ct3[1] = pair47[1];
			else if ((s32)ev >= (s32)hi)
				ct3[1] = t40_la_divs((d3 << 16) - (0x10000U - pair47[1]) * (ev - hi), d3, 205984U);
		}
	}
	if (tail == 1) {
		ct3[0] = m0;
		t40_am_copy4(ct2, p16);
		ct3[1] = t40_la_divs(d3 * pair46[1] + (0x10000U - pair46[1]) * (ev - hi), d3, 205984U);
	} else if (tail == 2) {
		ct3[0] = m1;
		t40_am_copy4(ct2, p16);
		ct3[1] = 0x10000U;
	}

	/* the pointers of the detection's argument block (ct[2..4] are the zone parameter set above) */
	for (i = 0; i < ARRAY_SIZE(ct_src); i++)
		if (i < 2 || i > 4)
			ct[i] = ctx[ct_src[i]];
}

/* OEM leaf: 32-bit word at any byte address (lwl / lwr pair) */
static u32 t40_am_rd32u(const u8 *p)
{
	u32 v;

	memcpy(&v, p, sizeof(v));
	return v;
}

/* limit u16 pair * gain (fix point 10) rounded to Q2 */
static void t40_am_gain_limits(const u32 *gain, u8 *o0, u8 *o1, u32 off, u32 x, u32 y)
{
	*(u16 *)(o0 + off) = (u32)(t40_la_mul2(10, x << 2, gain[0]) + 2) >> 2;
	*(u16 *)(o1 + off) = (u32)(t40_la_mul2(10, y << 2, gain[1]) + 2) >> 2;
}

/*
 * Six special-zone statistics windows (steps 0..5).  Step k has an enable flag ctx[27][fo], a window register
 * value ctx[28][fo] for register base-rg and a pair of u16 limits at ctx[29] / ctx[30] + wo.  Flag 1: the limit
 * words go to the registers base-s1 / base-s2 and the window register carries the flag in bit 16; any other
 * non-zero flag derives the output limits ctx[52] / ctx[53] from the gain ctx[9].  Step 0 additionally measures
 * the limits from three statistics registers (only once the settle counter ctx[50][1] reached 2).
 */
static void t40_am_spec_calculate(const u32 *ctx, u32 ch)
{
	static const u8 w32[] = { 9, 28 };
	static const u8 w16[] = { 29, 30, 52, 53 };
	static const u8 w8[] = { 27, 50, 51 };
	static const u8 fo[6] = { 0, 5, 6, 7, 8, 9 };		/* flag / window value index */
	static const u8 rg[6] = { 56, 36, 32, 28, 24, 20 };	/* window register below base */
	static const u8 wo[6] = { 0, 10, 12, 14, 16, 18 };	/* limit u16 offset */
	static const u8 wl[6] = { 0, 8, 12, 12, 16, 16 };	/* limit word offset */
	static const u8 r1[6] = { 96, 88, 84, 84, 80, 80 };	/* limit word registers below base */
	static const u8 r2[6] = { 76, 68, 64, 64, 60, 60 };
	u32 base = ch ? 0x182b4U : 0x180b4U;
	u8 *st, *cur, *w0, *w1, *o0, *o1;
	const u8 *flag;
	const u32 *par, *gain;
	u32 k;

	if (unlikely(!t40_am_ok(ctx, w32, ARRAY_SIZE(w32), w16, ARRAY_SIZE(w16), w8, ARRAY_SIZE(w8)))) {
		vawb_fault_note((u32)(uintptr_t)ctx, 211120U);
		return;
	}
	st = T40_AM_P8(50); cur = T40_AM_P8(51); flag = T40_AM_P8(27);
	par = T40_AM_P32(28); gain = T40_AM_P32(9);
	w0 = T40_AM_P8(29); w1 = T40_AM_P8(30); o0 = T40_AM_P8(52); o1 = T40_AM_P8(53);

	t40_am_memcpy((u32)(uintptr_t)cur, (u32)(uintptr_t)flag, 10);
	if (st[0] == 1 && st[1] < 2)
		st[1]++;

	for (k = 0; k < 6; k++) {
		u32 f = flag[fo[k]], val = par[fo[k]];

		if (k == 0 && f) {
			if (st[0] != 1 || st[1] < 2) {
				cur[0] = 0;		/* the window is not settled: plain value */
				f = 0;
			} else {
				u32 x = system_reg_read(base - 8), y = system_reg_read(base - 4), z = system_reg_read(base);
				u32 a = 0, b = 0;

				if (y) {
					b = t40_ag_divu(z << 8, y, 211448U);
					a = t40_ag_divu(x << 8, y, 211464U);
				}
				*(u16 *)w0 = a;
				*(u16 *)w1 = b;
				if (flag[0] != 1) {
					t40_am_gain_limits(gain, o0, o1, 0, a, b);
					f = 0;
				}
			}
		}
		if (k && f && f != 1) {
			t40_am_gain_limits(gain, o0, o1, wo[k], *(u16 *)(w0 + wo[k]), *(u16 *)(w1 + wo[k]));
			f = 0;
		}
		if (f == 1) {
			system_reg_write(base - r1[k], t40_am_rd32u(w0 + wl[k]));
			system_reg_write(base - r2[k], t40_am_rd32u(w1 + wl[k]));
			val |= (u32)cur[fo[k]] << 16;
		}
		system_reg_write(base - rg[k], val);
	}
}

/* OEM tisp_awb_main_process: the per-frame AWB step run after the statistics interrupt */
static void t40_am_main_process(void)
{
	u32 *ctx = pstMainAwbOri;
	u32 ev[12] = { 0 }, n;

	t40_am_long_par_update(ctx, pstMainAwbCtDetectOri, (u32)stMainAwbInter);
	t40_am_spec_calculate(ctx, 0);
	(void)vawb_s_tisp_awb_long_alogrithm((u32)(uintptr_t)ctx, (u32)(uintptr_t)pstMainAwbCtDetectOri, 0, 0, 0);
	if (vawb_tawb_custom_en[0] == 1)	/* custom algorithm library registered: wake its worker */
		(void)vawb_x_private_complete((u32)(uintptr_t)awb_algo_comp, 0, 0, 0, 0);
	(void)vawb_s_tisp_awb_set_gain((u32)(uintptr_t)ctx, 0, 0, 0, 0);

	/* event 13: the colour temperature, consumed by CCM / LSC / BCSH */
	if (unlikely(!vawb_ok(ctx[7], 3))) {
		vawb_fault_note(ctx[7], 212952U);
		ev[4] = 0;
	} else {
		ev[4] = *T40_AM_P32(7);
	}
	ev[2] = 13;
	(void)vawb_x_tisp_event_push(0, (u32)(uintptr_t)ev, 0, 0, 0);
	n = (vawb_awb_num + 1U) & 255U;
	vawb_awb_num = n < 51U ? n : 0;
	vawb_peter_test_count[0]++;
}

static u64 vawb_s_tisp_awb_long_par_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_long_par_update((const u32 *)(uintptr_t)a0, (u32 *)(uintptr_t)a1, a2);
	return 0;
}
static u64 vawb_s_tisp_awb_spec_calculate(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_spec_calculate((const u32 *)(uintptr_t)a0, a1);
	return 0;
}
static u64 vawb_s_tisp_awb_main_process(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	t40_am_main_process();
	return 0;
}

#undef T40_AM_P32
#undef T40_AM_P16
#undef T40_AM_P8
