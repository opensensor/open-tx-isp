/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 CCM (colour correction matrix) chain in plain C (#85).
 *
 * Replaces the literal mips2c bodies of the OEM tisp_ccm_params_transmit (0x6f5xx), tisp_ccm_params_refresh,
 * tisp_ct_ccm_interpolation (0x6f9xx), cm_control (OEM .text 0x1b6xx), tisp_ccm_lut_parameter (0x6fc4x) and
 * tisp_ccm_ev_ct_update (0x6fdxx).  The OEM code addresses everything through a 26-word pointer table (ctx) that
 * tisp_ccm_params_transmit fills with the addresses of the fields of the "outer" (working) and "inter" (parameter
 * record) blocks; the layout is kept so the hand-translated callers and the Unicorn check
 * (tools/ko_emu/diff_ccm_chain.py: OEM instructions vs this file built for mipsel) see the same memory.
 *
 *   ctx[0] outer  ctx[1] outer+0xe4 (3 x u16 CT anchors)  ctx[2] inter (byte 0: manual mode)
 *   ctx[3] ev now, [4] ev last, [5] -> ev threshold, [6] ct now, [7] ct last, [8] ct threshold (u16 each, [8] also the CT hysteresis),
 *   ctx[9] ct zone, [10] last zone, [11] saturation scalar, [12..14] reference matrices, [15] result matrix,
 *   ctx[16] manual flag, [17] manual-scalar flag, [18] manual matrix, [19] inter+0xd8, [20..22] CT matrices (3 of 6),
 *   ctx[23] ev table (9 x u32), [24] saturation per ev (9 x u32), [25] last matrix.
 * Needs from the includer: uint32_t/int32_t, memcpy, t40_ccm_reg_write(reg, val), fix_point_mult2_32(shift, a, b),
 * tx_isp_t40_ccm_conv.h (parameter convert / para2reg).  Addresses are 32-bit guest/kernel addresses (uintptr_t).
 */
#ifndef TX_ISP_T40_CCM_CHAIN_H
#define TX_ISP_T40_CCM_CHAIN_H

#define CCM_U32(a) (*(uint32_t *)(uintptr_t)(a))
#define CCM_U16(a) (*(uint16_t *)(uintptr_t)(a))
#define CCM_U8(a)  (*(uint8_t *)(uintptr_t)(a))

/* ctx[3..19]: offsets into the inter (parameter) block */
static const uint16_t t40_ccm_inter_off[17] = {
	0x04, 0x08, 0x0c, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1c, 0x20, 0x44, 0x68, 0x8c, 0xb0, 0xb1, 0xb4, 0xd8,
};
/* ctx[20..25]: offsets into the outer block (inter byte 0xd8 == 0: first set, else the second set) */
static const uint16_t t40_ccm_outer_off[2][6] = {
	{ 0x00c, 0x030, 0x054, 0x0ec, 0x110, 0x134 },
	{ 0x078, 0x09c, 0x0c0, 0x158, 0x17c, 0x1a0 },
};

static void t40_ccm_params_transmit(uintptr_t ctx, uintptr_t outer, uintptr_t inter)
{
	unsigned int i;
	const uint16_t *o = t40_ccm_outer_off[CCM_U8(inter + 216) != 0];

	CCM_U32(ctx + 4) = outer + 0xe4U;
	for (i = 0; i < 17; i++)
		CCM_U32(ctx + 12 + 4 * i) = inter + t40_ccm_inter_off[i];
	CCM_U32(ctx + 0) = outer;
	CCM_U32(ctx + 8) = inter;
	for (i = 0; i < 6; i++)
		CCM_U32(ctx + 80 + 4 * i) = outer + o[i];
}

static void t40_ccm_params_refresh(uintptr_t ctx, uintptr_t outer, uintptr_t src)
{
	unsigned int i;
	static const uint16_t cts[6] = { 0x0c, 0x30, 0x54, 0x78, 0x9c, 0xc0 };

	memcpy((void *)outer, (const void *)src, 10);
	memcpy((void *)(outer + 0xe4U), (const void *)(src + 0xe4U), 6);
	memcpy((void *)(outer + 0xecU), (const void *)(src + 0xecU), 36);
	memcpy((void *)(outer + 0x134U), (const void *)(src + 0x134U), 36);
	memcpy((void *)(outer + 0x158U), (const void *)(src + 0x158U), 36);
	memcpy((void *)(outer + 0x1a0U), (const void *)(src + 0x1a0U), 36);
	if (CCM_U8(CCM_U32(ctx + 64)) == 1) {
		/* manual CCM: the user matrix goes into all six CT matrices.  T40-CCM-SET: the OEM copies 4 bytes (li a2,4), one
		 * coefficient, here the whole matrix (36 bytes) - the OEM stays the Unicorn reference with that one immediate patched */
		for (i = 0; i < 6; i++)
			memcpy((void *)(outer + cts[i]), (const void *)(uintptr_t)CCM_U32(ctx + 72), 36);
		if (!CCM_U8(CCM_U32(ctx + 68))) {
			for (i = 0; i < 9; i++) {
				CCM_U32(outer + 0x110U + 4 * i) = 256U;
				CCM_U32(outer + 0x17cU + 4 * i) = 256U;
			}
		}
		return;
	}
	for (i = 0; i < 6; i++)
		memcpy((void *)(outer + cts[i]), (const void *)(src + cts[i]), 36);
	memcpy((void *)(outer + 0x110U), (const void *)(src + 0x110U), 36);
	memcpy((void *)(outer + 0x17cU), (const void *)(src + 0x17cU), 36);
}

/* |a - b| for u32 */
static inline uint32_t t40_ccm_absdiff(uint32_t a, uint32_t b)
{
	return a < b ? b - a : a - b;
}

/* linear blend of two 9-word matrices: dst = from +- |to - from| * num / den (the OEM divides unsigned) */
static void t40_ccm_blend(uintptr_t dst, uintptr_t from, uintptr_t to, uint32_t num, uint32_t den, int same)
{
	unsigned int i;

	for (i = 0; i < 9; i++) {
		uint32_t f = CCM_U32(from + 4 * i);

		if (!same) {
			uint32_t t = CCM_U32(to + 4 * i);

			if ((int32_t)t < (int32_t)f)
				f -= (f - t) * num / den;
			else
				f += (t - f) * num / den;
		}
		CCM_U32(dst + 4 * i) = f;
	}
}

/* chooses the CT zone (0 > ct2-d, 1, 2, 3, 4) from the current CT and the three anchors with hysteresis d, then
 * interpolates the result matrix ctx[15] between the reference matrices ctx[12..14] */
static void t40_ccm_ct_interpolation(uintptr_t ctx)
{
	uintptr_t anchors = CCM_U32(ctx + 4), dst = CCM_U32(ctx + 60);
	uintptr_t m0 = CCM_U32(ctx + 48), m1 = CCM_U32(ctx + 52), m2 = CCM_U32(ctx + 56);
	uint16_t *zone = (uint16_t *)(uintptr_t)CCM_U32(ctx + 36), *last = (uint16_t *)(uintptr_t)CCM_U32(ctx + 40);
	uint32_t d = CCM_U16(CCM_U32(ctx + 32));
	uint32_t c = CCM_U16(CCM_U32(ctx + 24));
	uint32_t a0 = CCM_U16(anchors) + d, a1 = CCM_U16(anchors + 2) + d, a1m = CCM_U16(anchors + 2) - d, a2m = CCM_U16(anchors + 4) - d;
	uint32_t z, lz;

	if (a2m < c)
		z = 0;
	else if (a1 < c)
		z = 1;
	else if (a1m < c)
		z = 2;
	else if (a0 < c)
		z = 3;
	else
		z = 4;
	*zone = (uint16_t)z;
	lz = *last;
	if (!CCM_U8(CCM_U32(ctx + 8))) {	/* automatic mode: nothing to do while the zone is the one already applied */
		if (z == 0 ? lz == 0 : z == 2 ? lz == z : z == 4 ? lz == z : 0)
			return;
	}
	*last = (uint16_t)z;
	switch (z) {
	case 1:
		t40_ccm_blend(dst, m1, m2, t40_ccm_absdiff(c, a1), t40_ccm_absdiff(a1, a2m), a1 == a2m);
		break;
	case 3:
		t40_ccm_blend(dst, m0, m1, t40_ccm_absdiff(c, a0), t40_ccm_absdiff(a0, a1m), a0 == a1m);
		break;
	case 2:
		memcpy((void *)dst, (const void *)m1, 36);
		break;
	case 4:
		memcpy((void *)dst, (const void *)m0, 36);
		break;
	default:
		memcpy((void *)dst, (const void *)m2, 36);
		break;
	}
}

/* sign / magnitude split of a 9-word matrix (OEM: sign 1 or -1, then |v|) */
static void t40_ccm_split(const int32_t *m, uint32_t *sg, uint32_t *mag)
{
	unsigned int i;

	for (i = 0; i < 9; i++) {
		sg[i] = m[i] < 0 ? 0xffffffffU : 1U;
		mag[i] = m[i] < 0 ? 0U - (uint32_t)m[i] : (uint32_t)m[i];
	}
}

/* out = in x S(sat) in 10.6 fixed point, S = the saturation matrix of the Y/Cb/Cr weights 19595/38470/7471 (OEM cm_control) */
static void t40_ccm_cm_control(uintptr_t in, uint32_t sat, uintptr_t out)
{
	int32_t s[9];
	uint32_t as[9], am[9], bs[9], bm[9];
	unsigned int r, c, k;

	s[0] = (int32_t)(((sat * 45941U) >> 8) + 19595U);
	s[1] = s[7] = (int32_t)(38470U - ((sat * 38470U) >> 8));
	s[2] = s[5] = (int32_t)(7471U - ((sat * 7471U) >> 8));
	s[3] = s[6] = (int32_t)(19595U - ((sat * 19595U) >> 8));
	s[4] = (int32_t)(((sat * 27066U) >> 8) + 38470U);
	s[8] = (int32_t)(((sat * 58065U) >> 8) + 7471U);
	t40_ccm_split((const int32_t *)in, as, am);
	t40_ccm_split(s, bs, bm);
	for (r = 0; r < 3; r++) {
		for (c = 0; c < 3; c++) {
			uint32_t acc = 0;
			int32_t v;

			for (k = 0; k < 3; k++)
				acc += as[3 * r + k] * bs[3 * k + c] *
				       (uint32_t)fix_point_mult2_32(16, (int32_t)(am[3 * r + k] << 6), (int32_t)bm[3 * k + c]);
			v = (int32_t)acc;
			if (v < 0)
				v = (int32_t)(0U - (uint32_t)(((int32_t)(0U - (uint32_t)v)) >> 6));
			else
				v >>= 6;
			CCM_U32(out + 4 * (3 * r + c)) = (uint32_t)v;
		}
	}
}

/* writes the 3x3 matrix (register form, 9 words) and its dither/shift controls to the CCM block (sec = second sensor) */
static void t40_ccm_lut_parameter(uintptr_t ctx, const uint32_t *m, uint32_t sec)
{
	uintptr_t outer = CCM_U32(ctx);
	uint32_t ctrl = sec ? 0xb040U : 0xb000U, mat = ctrl + 4U, sh = sec ? 0xb058U : 0xb018U;
	uint32_t w1 = sec ? 0xb05cU : 0xb01cU, w2 = sec ? 0xb060U : 0xb020U;
	unsigned int i;

	for (i = 0; i < 8; i += 2)
		t40_ccm_reg_write(mat + 2 * i, m[i] | (m[i + 1] << 16));
	t40_ccm_reg_write(mat + 16U, m[8]);
	if (CCM_U8(CCM_U32(ctx + 8)) == 1) {
		uint32_t b = CCM_U16(outer + 2), a = CCM_U16(outer + 4);
		uint32_t d;

		t40_ccm_reg_write(sh, (b << 16) | ((uint32_t)CCM_U16(outer) << 12) | a);
		d = b != a ? (b < a ? a - b : b - a) : 0U;
		t40_ccm_reg_write(w1, b != a ? (uint32_t)((int32_t)32 / (int32_t)d) : 1U);
		t40_ccm_reg_write(w2, (uint32_t)CCM_U8(outer + 6) | ((uint32_t)CCM_U8(outer + 7) << 8) |
				      ((uint32_t)CCM_U8(outer + 8) << 16) | ((uint32_t)CCM_U8(outer + 9) << 24));
	}
	t40_ccm_reg_write(ctrl, 1U);
}

/* EV/CT update: picks the saturation scalar for the current EV (interpolated through the 9-point table), re-converts the
 * parameter block, re-interpolates over CT when due, runs cm_control and writes the result to the hardware */
static void t40_ccm_ev_ct_update(uintptr_t ctx, uint32_t sec)
{
	uint32_t reg[9], para[9];
	uintptr_t sat = CCM_U32(ctx + 44);
	uint32_t ev = CCM_U32(CCM_U32(ctx + 12));
	uint32_t ct = CCM_U16(CCM_U32(ctx + 24)), ct_last = CCM_U16(CCM_U32(ctx + 28)), ct_th = CCM_U16(CCM_U32(ctx + 32));
	uint8_t manual = CCM_U8(CCM_U32(ctx + 8));
	unsigned int i;

	if (manual == 1 || t40_ccm_absdiff(CCM_U32(CCM_U32(ctx + 16)), ev) > CCM_U32(CCM_U32(ctx + 20))) {
		uintptr_t evt = CCM_U32(ctx + 92), sv = CCM_U32(ctx + 96);

		for (i = 0; i < 9; i++)
			if (!(CCM_U32(evt + 4 * i) < ev))
				break;
		if (i == 9) {
			CCM_U32(sat) = CCM_U32(sv + 32);
		} else if (i == 0) {
			CCM_U32(sat) = CCM_U32(sv);
		} else {
			uint32_t e0 = CCM_U32(evt + 4 * (i - 1)), e1 = CCM_U32(evt + 4 * i);
			uint32_t s0 = CCM_U32(sv + 4 * (i - 1)), s1 = CCM_U32(sv + 4 * i);

			if (e1 == e0) {
				CCM_U32(sat) = s1;
			} else if (s1 < s0) {
				CCM_U32(sat) = s0 - t40_ccm_absdiff(e0, ev) * (s0 - s1) / t40_ccm_absdiff(e1, e0);
			} else {
				CCM_U32(sat) = s0 + t40_ccm_absdiff(e0, ev) * (s1 - s0) / t40_ccm_absdiff(e1, e0);
			}
		}
	}
	(void)t40_ccm_parameter_convert(ctx);
	if (manual == 1 || (int32_t)ct_th < (int32_t)t40_ccm_absdiff(ct_last, ct))
		t40_ccm_ct_interpolation(ctx);
	t40_ccm_cm_control(CCM_U32(ctx + 60), CCM_U32(sat), (uintptr_t)para);
	(void)t40_ccm_para2reg(reg, para);
	t40_ccm_lut_parameter(ctx, reg, sec);
}

#endif
