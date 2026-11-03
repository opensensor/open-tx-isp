/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 BCSH (brightness / contrast / saturation / hue and the RGB->YUV
 * conversion of channel 0, TOP bit 15) in plain C.
 *
 * Rebuilt from the flow of the OEM tisp_bcsh_* functions (sc830ai
 * tx-isp-t40.ko).  The OEM keeps two buffers behind a table of 72 field
 * pointers (pstMainBcshOri): the "inter" block (460 bytes of .data: user
 * controls, EV/CT inputs, intermediate results) and the "outer" block
 * (1396 bytes, vmalloc: the CSC standard tables and a copy of the tuning
 * bank section at +0x11e38, with a linear and a WDR half).  This version
 * keeps the same two byte images (so the state compares 1:1 with the OEM)
 * and addresses the fields by offset instead of through the pointer table.
 *
 * EV path (tisp_bcsh_ev_update): 9-knot EV interpolation of the gain words,
 * the strength curves for saturation / brightness / contrast, the luma
 * offset through the CSC matrix, the clip slopes -> 0x11000..0x11070.
 * CT path (tisp_bcsh_ct_update): 3 CT matrices -> zone / interpolation at
 * the colour temperature, M * CT * Minv with the hue rotation -> 0x11024..
 * 0x11038.  Second channel: +0x100.
 *
 * This replaces the literal mips2c chain (tx_isp_t40_bcsh_lit.inc up to
 * open-tx-isp next e96b92ea); tests/t40/c_chains_host compares both.  The
 * driver glue keeps the literal behaviour: init (block init, day/night
 * refresh) copies the bank section for the CSC mode, sets EV/CT from the
 * module state and runs both paths; the frame follow feeds the AE EV.
 */
#ifndef TX_ISP_T40_BCSH_H
#define TX_ISP_T40_BCSH_H

#define T40_BCSH_IN_BYTES   460U
#define T40_BCSH_OUT_BYTES  0x574U
#define T40_BCSH_PAR_OFFSET 0x11e38U	/* bank offset of the outer image */
#define T40_BCSH_WDR_HALF   0x238U	/* outer: WDR copy of 0x1c..0x253 */

/* inter block (OEM stMainBcshInterOri) */
#define BI_BUSY        0x000	/* u8: an update from the CSC/hue setters is running */
#define BI_CCM0        0x004	/* s32[9]: CT matrices in parameter form */
#define BI_CCM1        0x028
#define BI_CCM2        0x04c
#define BI_CCM_REG     0x070	/* u32[9]: resulting matrix, register form */
#define BI_CLIP_SLOPE  0x094	/* u32[3]: 1024 / clip ranges of the three u16 triples */
#define BI_Y_SLOPE0    0x0a0	/* u32: contrast curve slopes */
#define BI_Y_SLOPE1    0x0a4
#define BI_Y_SLOPE2    0x0a8
#define BI_GAIN        0x0ac	/* u32[4]: EV-interpolated, scaled by sat/bri/con */
#define BI_GAIN_SLOPE  0x0bc	/* u32[2] */
#define BI_OFFSET      0x0c4	/* u32[3]: offset vector through the CSC matrix */
#define BI_OFF_A       0x0d0	/* u32[3] */
#define BI_OFF_B       0x0dc	/* u32[3] */
#define BI_CCM_CT      0x0e8	/* s32[9]: matrix at the current CT */
#define BI_BRI_GAIN    0x10c	/* u32: EV-interpolated brightness gain */
#define BI_CT_KNOTS    0x110	/* u32[4] */
#define BI_HUE         0x120	/* u8: hue angle 0..120, 60 neutral */
#define BI_HUE_RAW     0x121	/* u8: hue as the user set it */
#define BI_CSC_MODE    0x122	/* u8: 0/1 BT601 full/limited, 2/3 BT709, 4 user */
#define BI_USER_OFF    0x124	/* user CSC tables (mode 4) */
#define BI_USER_CLIP0  0x128
#define BI_USER_CLIP1  0x130
#define BI_USER_CLIP2  0x138
#define BI_USER_M      0x140
#define BI_USER_MINV   0x164
#define BI_USER_CCM    0x188
#define BI_USER_CCM_EN 0x1ac	/* u8 */
#define BI_USER_CCM_B  0x1ad	/* u8 */
#define BI_WDR         0x1ae	/* u8: half selected at init */
#define BI_EV          0x1b0	/* u32 */
#define BI_CT          0x1bc	/* u16 */
#define BI_CT_ZONE     0x1c2	/* u16 */
#define BI_CT_ZONE_OLD 0x1c4	/* u16 */
#define BI_BRIGHTNESS  0x1c8	/* u8, 128 neutral */
#define BI_CONTRAST    0x1c9
#define BI_SATURATION  0x1ca

/* outer block (OEM stMainBcshOuter), linear-half offsets */
#define BO_Y_OFFSET    0x000	/* u16[2] */
#define BO_CLIP0       0x004	/* u16[4] */
#define BO_CLIP1       0x00c
#define BO_CLIP2       0x014
#define BO_CCM0        0x01c	/* s32[9] register form, three CT matrices */
#define BO_CCM1        0x040
#define BO_CCM2        0x064
#define BO_TRI0        0x088	/* u16[3] ranges */
#define BO_TRI1        0x08e
#define BO_TRI2        0x094	/* [1], [2] follow the EV */
#define BO_TRI2_LO_TAB 0x09a	/* u16[9] */
#define BO_TRI2_HI_TAB 0x0ac	/* u16[9] */
#define BO_GAIN_RANGE  0x0c0	/* u32[3] */
#define BO_EV_KNOTS    0x0cc	/* u32[9] */
#define BO_GAIN_TAB    0x0f0	/* u32[4][9] */
#define BO_CURVE       0x180	/* u32[5]: enable + four contrast curve points */
#define BO_CURVE_TAB   0x194	/* u32[4][9] -> curve[1..4] */
#define BO_BRI_TAB     0x224	/* u32[9] */
#define BO_OFFSET_VEC  0x248	/* u32[3] */
#define BO_M           0x48c	/* s32[9]: RGB->YUV matrix of the CSC mode */
#define BO_MINV        0x4b0

static bool regtrace_enable_bcsh;
static uint32_t regtrace_bcsh_mode = 2; /* OEM tisp_main_init passes 2 */
static uint32_t regtrace_bcsh_ev = 400;
static uint32_t regtrace_bcsh_ct = 6000;
module_param_named(enable_bcsh, regtrace_enable_bcsh, bool, 0644);
module_param_named(bcsh_mode, regtrace_bcsh_mode, uint, 0644);
module_param_named(bcsh_ev, regtrace_bcsh_ev, uint, 0644);
module_param_named(bcsh_ct, regtrace_bcsh_ct, uint, 0644);
/* CSC mode 4 and the user CCM: the OEM copies only the first word of each
 * user table (a 4-byte memcpy), the rest of the matrix stays from the previous
 * CSC mode / the bank.  1 (default) takes the whole tables, 0 = OEM. */
static bool regtrace_bcsh_user_full = true;
module_param_named(bcsh_user_full, regtrace_bcsh_user_full, bool, 0644);

static struct t40_bcsh_state {
	uint8_t in[T40_BCSH_IN_BYTES] __attribute__((aligned(4)));
	uint8_t out[T40_BCSH_OUT_BYTES] __attribute__((aligned(4)));
	uint32_t half;		/* WDR half chosen at init (OEM params_transmit) */
	uint8_t mjpeg_mode[2], mjpeg_y_low[2], mjpeg_y_high[2];	/* OEM MJPEG range, never set here */
	bool ready;
} t40_bcsh T40C2 = {
	.in = {
	0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x01, 0x04, 0x00, 0x00, 0x04, 0x3e, 0x00, 0x00, 0xf3, 0x3e, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00,
	0x05, 0x09, 0x00, 0x00, 0x5f, 0x01, 0x00, 0x00, 0xfe, 0x3f, 0x00, 0x00, 0xf1, 0x02, 0x00, 0x00,
	0x9b, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
	0x00, 0x05, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x00, 0x04, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
	0x22, 0x0b, 0x00, 0x00, 0xa6, 0x0e, 0x00, 0x00, 0x0a, 0x0f, 0x00, 0x00, 0x56, 0x13, 0x00, 0x00,
	0x3c, 0x80, 0x00, 0x00, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03,
	0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03, 0x00, 0x00, 0xff, 0x03,
	0x6d, 0x36, 0x00, 0x00, 0x17, 0xb7, 0x00, 0x00, 0x7c, 0x12, 0x00, 0x00, 0xaa, 0xe2, 0xff, 0xff,
	0x56, 0x9d, 0xff, 0xff, 0x00, 0x80, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0xba, 0x8b, 0xff, 0xff,
	0x46, 0xf4, 0xff, 0xff, 0x00, 0x00, 0x01, 0x00, 0xf6, 0xff, 0xff, 0xff, 0x24, 0x93, 0x01, 0x00,
	0x00, 0x00, 0x01, 0x00, 0x0e, 0xd0, 0xff, 0xff, 0x29, 0x88, 0xff, 0xff, 0x00, 0x00, 0x01, 0x00,
	0x09, 0xdb, 0x01, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x90, 0x01, 0x00, 0x00, 0x90, 0x01, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x70, 0x17, 0x70, 0x17,
	0x64, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x00,
	},
	.mjpeg_y_high = { 0xff, 0xff },
};

/* field access */
static inline uint32_t *t40_bcsh_in32(uint32_t off) { return (uint32_t *)(t40_bcsh.in + off); }
static inline uint16_t *t40_bcsh_in16(uint32_t off) { return (uint16_t *)(t40_bcsh.in + off); }
static inline uint32_t *t40_bcsh_out32(uint32_t off) { return (uint32_t *)(t40_bcsh.out + off); }
static inline uint16_t *t40_bcsh_out16(uint32_t off) { return (uint16_t *)(t40_bcsh.out + off); }
/* fields of the selected half */
static inline uint32_t *t40_bcsh_h32(uint32_t off) { return t40_bcsh_out32(off + t40_bcsh.half); }
static inline uint16_t *t40_bcsh_h16(uint32_t off) { return t40_bcsh_out16(off + t40_bcsh.half); }

/*
 * OEM table interpolation: y0 + or - |x - k0| * |y1 - y0| / |k1 - k0|,
 * 32-bit product, unsigned quotient.  The CT matrices compare y signed.
 */
static inline uint32_t t40_bcsh_lerp(uint32_t x, uint32_t k0, uint32_t k1, uint32_t y0, uint32_t y1, bool sgn)
{
	uint32_t dx, dk;
	bool down;

	if (k0 == k1)
		return y0;
	dx = k0 < x ? x - k0 : k0 - x;
	dk = k1 < k0 ? k0 - k1 : k1 - k0;
	down = sgn ? (int32_t)y1 < (int32_t)y0 : y1 < y0;
	return down ? y0 - dx * (y0 - y1) / dk : y0 + dx * (y1 - y0) / dk;
}

static inline uint32_t t40_bcsh_absdiff(uint32_t a, uint32_t b)
{
	return a < b ? b - a : a - b;
}

/* OEM tisp_bcsh_StrenCal_part_0 / tisp_bcsh_StrenCal: strength curve of a
 * user control v over [lo, hi] between the values a and b (always adds the
 * distance; the second form measures from hi) */
static uint32_t t40_bcsh_stren(uint32_t v, uint32_t lo, uint32_t hi, uint32_t a, uint32_t b)
{
	uint32_t d = t40_bcsh_absdiff(lo, hi);

	if (!d)
		return a;
	return (d * a + t40_bcsh_absdiff(lo, v) * t40_bcsh_absdiff(a, b)) / d;
}

static uint32_t t40_bcsh_stren_hi(uint32_t v, uint32_t lo, uint32_t hi, uint32_t a, uint32_t b)
{
	uint32_t d = t40_bcsh_absdiff(lo, hi);

	if (!d)
		return b;
	return (d * b + t40_bcsh_absdiff(v, hi) * t40_bcsh_absdiff(a, b)) / d;
}

/* sign/magnitude product of the OEM matrix code: fix_point_mult2_32 on the
 * magnitudes (Q16), the sign applied with a 32-bit multiply */
static inline int32_t t40_bcsh_smul(uint32_t a, uint32_t b, unsigned int shift)
{
	int32_t s = ((int32_t)a < 0) != ((int32_t)b < 0) ? -1 : 1;
	uint32_t ma = (int32_t)a < 0 ? 0U - a : a, mb = (int32_t)b < 0 ? 0U - b : b;

	return (int32_t)((uint32_t)s * (uint32_t)fix_point_mult2_32(16, (int32_t)ma, (int32_t)(mb << shift)));
}

/* x / 64 rounded towards zero */
static inline uint32_t t40_bcsh_div64(uint32_t v)
{
	if ((int32_t)v < 0)
		return 0U - (uint32_t)((int32_t)(0U - v) >> 6);
	return (uint32_t)((int32_t)v >> 6);
}

/* tisp_bcsh_Toffset_RGB2YUV: offset vector (bias 0x400) through the matrix */
static void t40_bcsh_offset_rgb2yuv(uint32_t *dst, const uint32_t *vec, const uint32_t *m)
{
	unsigned int r, k;

	for (r = 0; r < 3; r++) {
		uint32_t sum = 0;

		for (k = 0; k < 3; k++)
			sum += (uint32_t)t40_bcsh_smul(m[3 * r + k], vec[k] - 0x400, 6);
		dst[r] = t40_bcsh_div64(sum) + 0x400;
	}
}

/* tisp_bcsh_Tccm_RGBYUV: out = M * C * Minv, then the hue rotation of the
 * two chroma rows (angle 0..120, 60 = none; linear sine/cosine) */
static void t40_bcsh_rgbyuv(uint32_t *out, const uint32_t *m, const uint32_t *c, const uint32_t *minv, uint32_t hue)
{
	uint32_t row[3], snap[9], cosv, sinv, s;
	unsigned int r, i, k;

	for (r = 0; r < 3; r++) {
		for (i = 0; i < 3; i++) {
			row[i] = 0;
			for (k = 0; k < 3; k++)
				row[i] += (uint32_t)t40_bcsh_smul(m[3 * r + k], c[3 * k + i], 6);
		}
		for (i = 0; i < 3; i++) {
			out[3 * r + i] = 0;
			for (k = 0; k < 3; k++)
				out[3 * r + i] += (uint32_t)t40_bcsh_smul(row[k], minv[3 * k + i], 0);
		}
	}
	if (hue == 60) {
		sinv = 0;
		cosv = 0x10000;
		s = 1;
	} else if (hue < 60) {
		cosv = (hue << 15) / 60 + 0x8000;
		sinv = 56756 - hue * 56756 / 60;
		s = 0xffffffffU;
	} else {
		cosv = 0x10000 - ((hue - 60) << 15) / 60;
		sinv = (hue - 60) * 56756 / 60;
		s = 1;
	}
	memcpy(snap, out, sizeof(snap));
	for (i = 3; i < 6; i++)
		out[i] = (uint32_t)t40_bcsh_smul(cosv, snap[i], 0) + s * (uint32_t)t40_bcsh_smul(sinv, snap[i + 3], 0);
	for (i = 6; i < 9; i++)
		out[i] = (0U - s) * (uint32_t)t40_bcsh_smul(sinv, snap[i - 3], 0) + (uint32_t)t40_bcsh_smul(cosv, snap[i], 0);
	for (i = 0; i < 9; i++)
		out[i] = t40_bcsh_div64(out[i]);
}

/* tisp_bcsh_ev_update, interpolation part: everything that follows the EV */
static void t40_bcsh_ev_interpolate(void)
{
	const uint32_t *k = t40_bcsh_h32(BO_EV_KNOTS);
	uint32_t ev = *t40_bcsh_in32(BI_EV), *gain = t40_bcsh_in32(BI_GAIN), *curve = t40_bcsh_h32(BO_CURVE);
	uint16_t *tri2 = t40_bcsh_h16(BO_TRI2);
	const uint16_t *lo_tab = t40_bcsh_h16(BO_TRI2_LO_TAB), *hi_tab = t40_bcsh_h16(BO_TRI2_HI_TAB);
	unsigned int i, j;

	if (!(k[0] < ev) || !(ev < k[8])) {
		i = k[0] < ev ? 8 : 0;
		tri2[1] = lo_tab[i];
		tri2[2] = hi_tab[i];
		for (j = 0; j < 4; j++)
			gain[j] = t40_bcsh_h32(BO_GAIN_TAB + 36 * j)[i];
		for (j = 0; j < 4; j++)
			curve[1 + j] = t40_bcsh_h32(BO_CURVE_TAB + 36 * j)[i];
		*t40_bcsh_in32(BI_BRI_GAIN) = t40_bcsh_h32(BO_BRI_TAB)[i];
		return;
	}
	for (i = 0; i < 8; i++)
		if (k[i] < ev && !(k[i + 1] < ev))
			break;
	if (i == 8)
		return;	/* knots not ascending: nothing matches */
#define LERP(tab) t40_bcsh_lerp(ev, k[i], k[i + 1], (tab)[i], (tab)[i + 1], false)
	tri2[1] = LERP(lo_tab);
	tri2[2] = LERP(hi_tab);
	for (j = 0; j < 4; j++)
		gain[j] = LERP(t40_bcsh_h32(BO_GAIN_TAB + 36 * j));
	for (j = 0; j < 4; j++)
		curve[1 + j] = LERP(t40_bcsh_h32(BO_CURVE_TAB + 36 * j));
	*t40_bcsh_in32(BI_BRI_GAIN) = LERP(t40_bcsh_h32(BO_BRI_TAB));
#undef LERP
}

/* tisp_bcsh_ev_update_TransitParam: user controls on the EV values, curve
 * slopes */
static void t40_bcsh_ev_transit(uint32_t ch)
{
	uint32_t *gain = t40_bcsh_in32(BI_GAIN), *curve = t40_bcsh_h32(BO_CURVE), *rng = t40_bcsh_h32(BO_GAIN_RANGE);
	uint32_t sat = t40_bcsh.in[BI_SATURATION], bri = t40_bcsh.in[BI_BRIGHTNESS], con = t40_bcsh.in[BI_CONTRAST];
	uint32_t *off_b = t40_bcsh_in32(BI_OFF_B), *off = t40_bcsh_in32(BI_OFFSET);
	uint32_t c1, c2, c3, c4, mid, bri_off, clip;
	static const uint32_t tri[3] = { BO_TRI0, BO_TRI1, BO_TRI2 };
	unsigned int j;

	t40_bcsh_in32(BI_OFF_A)[0] = *t40_bcsh_out16(BO_Y_OFFSET);
	t40_bcsh_in32(BI_OFF_A)[1] = 1024;
	t40_bcsh_in32(BI_OFF_A)[2] = 1024;
	if (sat < 128)
		for (j = 0; j < 4; j++)
			gain[j] = t40_bcsh_stren(sat, 0, 128, 0, gain[j]);
	else if (sat != 128)
		for (j = 0; j < 4; j++)
			gain[j] = t40_bcsh_stren(sat, 128, 256, gain[j], 6144);
	bri_off = (bri * *t40_bcsh_in32(BI_BRI_GAIN)) >> 7;
	if (bri_off > 1900)
		bri_off = 1900;
	if (bri < 128)
		for (j = 0; j < 4; j++)
			gain[j] = t40_bcsh_stren(bri, 0, 128, 0, gain[j]);
	t40_bcsh_offset_rgb2yuv(off, t40_bcsh_h32(BO_OFFSET_VEC), t40_bcsh_out32(BO_M));
	off_b[0] = off[0] - 0x800 + t40_bcsh_out16(BO_Y_OFFSET)[1] + bri_off;
	off_b[1] = off[1];
	off_b[2] = off[2];

	/* contrast: four points of the luma curve */
	c1 = curve[1];
	c2 = curve[2];
	c3 = curve[3];
	c4 = curve[4];
	if (curve[0] && con != 128) {
		if (con < 128) {
			mid = (t40_bcsh_absdiff(c3, c4) >> 1) + c3;
			c1 = t40_bcsh_stren(con, 0, 128, 0, curve[1]);
			c2 = t40_bcsh_stren_hi(con, 0, 128, 1023, curve[2]);
			c3 = t40_bcsh_stren_hi(con, 0, 128, mid, curve[3]);
			c4 = t40_bcsh_stren(con, 0, 128, mid, curve[4]);
			for (j = 0; j < 4; j++)
				gain[j] = t40_bcsh_stren(con, 0, 128, 0, gain[j]);
		} else {
			mid = (t40_bcsh_absdiff(c1, c2) >> 1) + c1;
			c1 = t40_bcsh_stren(con, 128, 255, curve[1], mid);
			c2 = t40_bcsh_stren_hi(con, 128, 255, curve[2], mid);
			c3 = t40_bcsh_stren_hi(con, 128, 255, curve[3], 0);
			c4 = t40_bcsh_stren(con, 128, 255, curve[4], 1023);
		}
	}
	curve[1] = c1;
	curve[2] = c2;
	curve[3] = c3;
	curve[4] = c4;
	if (t40_bcsh.mjpeg_mode[ch & 1] == 1) {
		curve[0] = 1;
		curve[3] = 0;
		curve[1] = t40_bcsh.mjpeg_y_low[ch & 1] << 2;
		curve[2] = (t40_bcsh.mjpeg_y_high[ch & 1] << 2) + 3;
		curve[4] = 1023;
	}
	*t40_bcsh_in32(BI_Y_SLOPE0) = curve[1] ? (curve[3] << 10) / curve[1] : 0;
	if (curve[1] < curve[2]) {
		*t40_bcsh_in32(BI_Y_SLOPE1) = (t40_bcsh_absdiff(curve[3], curve[4]) << 10) / (curve[2] - curve[1]);
	} else {
		curve[1] = curve[2];
		*t40_bcsh_in32(BI_Y_SLOPE1) = 0;
	}
	clip = t40_bcsh_out16(BO_CLIP1)[1];
	if (curve[2] < clip) {
		*t40_bcsh_in32(BI_Y_SLOPE2) = (t40_bcsh_absdiff(curve[4], clip) << 10) / (clip - curve[2]);
	} else {
		curve[2] = clip;
		*t40_bcsh_in32(BI_Y_SLOPE2) = 0;
	}
	if (rng[1] < rng[2]) {
		t40_bcsh_in32(BI_GAIN_SLOPE)[0] = t40_bcsh_absdiff(gain[0], gain[1]) / (rng[2] - rng[1]);
		t40_bcsh_in32(BI_GAIN_SLOPE)[1] = t40_bcsh_absdiff(gain[2], gain[3]) / (rng[2] - rng[1]);
	} else {
		rng[1] = rng[2];
		t40_bcsh_in32(BI_GAIN_SLOPE)[0] = 0;
		t40_bcsh_in32(BI_GAIN_SLOPE)[1] = 0;
	}
	for (j = 0; j < 3; j++) {
		uint16_t *t = t40_bcsh_h16(tri[j]);

		if (t[1] < t[2]) {
			t40_bcsh_in32(BI_CLIP_SLOPE)[j] = (uint32_t)(1024 / (int32_t)(t[2] - t[1]));
		} else {
			t[1] = t[2];
			t40_bcsh_in32(BI_CLIP_SLOPE)[j] = 0;
		}
	}
}

/* tisp_bcsh_ev_set_parameter: offsets, clips, curve and gains -> 0x11000.. */
static int t40_bcsh_ev_write(uint32_t ch)
{
	const uint16_t *c0 = t40_bcsh_out16(BO_CLIP0), *c1 = t40_bcsh_out16(BO_CLIP1), *c2 = t40_bcsh_out16(BO_CLIP2);
	const uint32_t *oa = t40_bcsh_in32(BI_OFF_A), *ob = t40_bcsh_in32(BI_OFF_B);
	const uint32_t *slope = t40_bcsh_in32(BI_CLIP_SLOPE), *curve = t40_bcsh_h32(BO_CURVE);
	const uint32_t *gs = t40_bcsh_in32(BI_GAIN_SLOPE), *rng = t40_bcsh_h32(BO_GAIN_RANGE);
	const uint32_t *g = t40_bcsh_in32(BI_GAIN);
	static const uint32_t tri[3] = { BO_TRI0, BO_TRI1, BO_TRI2 };
	uint32_t base = ch ? 0x11100U : 0x11000U;
	unsigned int j;

	system_reg_write(base + 0x00, (uint32_t)c0[0] << 16 | c0[1]);
	system_reg_write(base + 0x04, (uint32_t)c1[0] << 16 | c1[1]);
	system_reg_write(base + 0x08, (uint32_t)c2[0] << 16 | c2[1]);
	system_reg_write(base + 0x0c, (uint32_t)c0[2] << 16 | c0[3]);
	system_reg_write(base + 0x10, (uint32_t)c1[2] << 16 | c1[3]);
	system_reg_write(base + 0x14, (uint32_t)c2[2] << 16 | c2[3]);
	for (j = 0; j < 3; j++)
		system_reg_write(base + 0x18 + 4 * j, ob[j] << 16 | oa[j]);
	for (j = 0; j < 3; j++) {
		const uint16_t *t = t40_bcsh_h16(tri[j]);

		system_reg_write(base + 0x3c + 8 * j, slope[j] << 16 | t[0]);
		system_reg_write(base + 0x40 + 8 * j, (uint32_t)t[2] << 16 | t[1]);
	}
	system_reg_write(base + 0x54, *t40_bcsh_in32(BI_Y_SLOPE0) << 16 | curve[0]);
	system_reg_write(base + 0x58, *t40_bcsh_in32(BI_Y_SLOPE2) << 16 | *t40_bcsh_in32(BI_Y_SLOPE1));
	system_reg_write(base + 0x5c, curve[2] << 16 | curve[1]);
	system_reg_write(base + 0x60, curve[4] << 16 | curve[3]);
	system_reg_write(base + 0x64, gs[1] << 16 | gs[0] << 3 | rng[0]);
	system_reg_write(base + 0x68, rng[2] << 16 | rng[1]);
	system_reg_write(base + 0x6c, g[0] << 16 | g[1]);
	return system_reg_write(base + 0x70, g[2] << 16 | g[3]);
}

/* tisp_bcsh_ev_update (returns the last register write like the OEM tail call) */
static int t40_bcsh_ev_update(uint32_t ch)
{
	t40_bcsh_ev_interpolate();
	t40_bcsh_ev_transit(ch);
	return t40_bcsh_ev_write(ch);
}

/* tisp_bcsh_reg2para: 14-bit register form -> signed parameter */
static void t40_bcsh_reg2para(uint32_t *dst, const uint32_t *src)
{
	unsigned int i;

	for (i = 0; i < 9; i++)
		dst[i] = src[i] < 8192 ? src[i] : src[i] - 0x4000;
}

/* tisp_bcsh_ct_interpolation: matrix for the colour temperature; zones 0, 2,
 * 4 take a matrix as it is (only when the zone changed or a setter is
 * busy), zones 1 and 3 interpolate */
static void t40_bcsh_ct_interpolate(void)
{
	const uint32_t *k = t40_bcsh_in32(BI_CT_KNOTS);
	const uint32_t *m0 = t40_bcsh_in32(BI_CCM0), *m1 = t40_bcsh_in32(BI_CCM1), *m2 = t40_bcsh_in32(BI_CCM2);
	uint32_t ct = *t40_bcsh_in16(BI_CT), *dst = t40_bcsh_in32(BI_CCM_CT);
	uint16_t *zone = t40_bcsh_in16(BI_CT_ZONE), *old = t40_bcsh_in16(BI_CT_ZONE_OLD);
	unsigned int i;

	if (k[3] < ct)
		*zone = 0;
	else if (k[2] < ct)
		*zone = 1;
	else if (k[1] < ct)
		*zone = 2;
	else if (k[0] < ct)
		*zone = 3;
	else
		*zone = 4;
	if (!t40_bcsh.in[BI_BUSY] && !(*zone & 1) && *zone == *old)
		return;
	*old = *zone;
	switch (*zone) {
	case 1:
		for (i = 0; i < 9; i++)
			dst[i] = t40_bcsh_lerp(ct, k[2], k[3], m1[i], m0[i], true);
		break;
	case 2:
		memcpy(dst, m1, 36);
		break;
	case 3:
		for (i = 0; i < 9; i++)
			dst[i] = t40_bcsh_lerp(ct, k[0], k[1], m2[i], m1[i], true);
		break;
	case 4:
		memcpy(dst, m2, 36);
		break;
	default:
		memcpy(dst, m0, 36);
		break;
	}
}

/* tisp_bcsh_ct_update: CT matrices -> M * CT * Minv with hue -> 0x11024.. */
static int t40_bcsh_ct_update(uint32_t ch)
{
	uint32_t m[9], *reg = t40_bcsh_in32(BI_CCM_REG), base = ch ? 0x11124U : 0x11024U;
	unsigned int i;

	t40_bcsh_reg2para(t40_bcsh_in32(BI_CCM0), t40_bcsh_h32(BO_CCM0));
	t40_bcsh_reg2para(t40_bcsh_in32(BI_CCM1), t40_bcsh_h32(BO_CCM1));
	t40_bcsh_reg2para(t40_bcsh_in32(BI_CCM2), t40_bcsh_h32(BO_CCM2));
	t40_bcsh_ct_interpolate();
	t40_bcsh_rgbyuv(m, t40_bcsh_out32(BO_M), t40_bcsh_in32(BI_CCM_CT), t40_bcsh_out32(BO_MINV),
			t40_bcsh.in[BI_HUE]);
	/* tisp_bcsh_para2reg */
	for (i = 0; i < 9; i++)
		reg[i] = (int32_t)m[i] < 0 ? m[i] & 0x3fff : m[i];
	/* tisp_bcsh_ct_set_parameter */
	system_reg_write(base + 0x00, reg[1] << 16 | reg[0]);
	system_reg_write(base + 0x04, reg[2]);
	system_reg_write(base + 0x08, reg[4] << 16 | reg[3]);
	system_reg_write(base + 0x0c, reg[5]);
	system_reg_write(base + 0x10, reg[7] << 16 | reg[6]);
	return system_reg_write(base + 0x14, reg[8]);
}

/* tisp_bcsh_params_refresh: CSC standard of the mode + bank section */
static void t40_bcsh_load(const uint8_t *bank)
{
	static const struct { const uint8_t *off, *c0, *c1, *c2, *m, *minv; } csc[4] = {
		{ au16BT601FullOffsetYUVy, au16BT601FullClip0, au16BT601FullClip1, au16BT601FullClip2,
		  as32BT601FullMMatrix, as32BT601FullMinvMatrix },
		{ au16BT601LimitedOffsetYUVy, au16BT601LimitedClip0, au16BT601LimitedClip1, au16BT601LimitedClip2,
		  as32BT601LimitedMMatrix, as32BT601LimitedMinvMatrix },
		{ au16BT709FullOffsetYUVy, au16BT709FullClip0, au16BT709FullClip1, au16BT709FullClip2,
		  as32BT709FullMMatrix, as32BT709FullMinvMatrix },
		{ au16BT709LimitedOffsetYUVy, au16BT709LimitedClip0, au16BT709LimitedClip1, au16BT709LimitedClip2,
		  as32BT709LimitedMMatrix, as32BT709LimitedMinvMatrix },
	};
	uint8_t *o = t40_bcsh.out, *in = t40_bcsh.in;
	uint32_t mode = in[BI_CSC_MODE], h;
	bool full = regtrace_bcsh_user_full;
	/* the bank copy skips the 2-byte pads after the u16[9] tables */
	static const struct { uint16_t off, len; } sect[] = {
		{ 0x1c, 0xbe - 0x1c }, { 0xc0, 0x254 - 0xc0 },
	};

	if (mode == 4) {
		/* user tables: the OEM copies only the first word of each (bcsh_user_full=0) */
		memcpy(o + BO_Y_OFFSET, in + BI_USER_OFF, 4);
		memcpy(o + BO_CLIP0, in + BI_USER_CLIP0, full ? 8 : 4);
		memcpy(o + BO_CLIP1, in + BI_USER_CLIP1, full ? 8 : 4);
		memcpy(o + BO_CLIP2, in + BI_USER_CLIP2, full ? 8 : 4);
		memcpy(o + BO_M, in + BI_USER_M, full ? 36 : 4);
		memcpy(o + BO_MINV, in + BI_USER_MINV, full ? 36 : 4);
	} else {
		unsigned int s = mode == 0 ? 0 : mode == 1 ? 1 : mode == 3 ? 3 : 2;

		memcpy(o + BO_Y_OFFSET, csc[s].off, 4);
		memcpy(o + BO_CLIP0, csc[s].c0, 8);
		memcpy(o + BO_CLIP1, csc[s].c1, 8);
		memcpy(o + BO_CLIP2, csc[s].c2, 8);
		memcpy(o + BO_M, csc[s].m, 36);
		memcpy(o + BO_MINV, csc[s].minv, 36);
	}
	for (h = 0; h <= T40_BCSH_WDR_HALF; h += T40_BCSH_WDR_HALF) {
		memcpy(o + h + sect[0].off, bank + h + sect[0].off, sect[0].len);
		memcpy(o + h + sect[1].off, bank + h + sect[1].off, sect[1].len);
	}
	memcpy(o + 0x4d4, bank + 0x4d4, 0x574 - 0x4d4);
	if (in[BI_USER_CCM_EN] == 1) {
		/* user CCM: the OEM again only the first word of each CT matrix */
		for (h = 0; h <= T40_BCSH_WDR_HALF; h += T40_BCSH_WDR_HALF) {
			memcpy(o + h + BO_CCM0, in + BI_USER_CCM, full ? 36 : 4);
			memcpy(o + h + BO_CCM1, in + BI_USER_CCM, full ? 36 : 4);
			memcpy(o + h + BO_CCM2, in + BI_USER_CCM, full ? 36 : 4);
		}
		if (!in[BI_USER_CCM_B]) {
			*t40_bcsh_out32(BO_GAIN_RANGE) = 0;
			*t40_bcsh_out32(BO_GAIN_RANGE + T40_BCSH_WDR_HALF) = 0;
		}
	}
}

/*
 * OEM pointer table (tisp_bcsh_params_transmit layout) into the two images,
 * built like the OEM init does it.  The driver's C consumers address the images
 * directly; tests/t40/c_chains_host compares this table with the lifted one.
 */
static uint32_t t40_bcsh_oem_ctx[72] T40C2;

static void t40_bcsh_build_ctx(void)
{
	static const uint16_t in_off[42] = {
		0x004, 0x028, 0x04c, 0x070, 0x094, 0x098, 0x09c, 0x0a0, 0x0a4, 0x0a8, 0x0ac, 0x0bc, 0x0c4, 0x0d0,
		0x0dc, 0x0e8, 0x10c, 0x110, 0x120, 0x121, 0x122, 0x124, 0x128, 0x130, 0x138, 0x140, 0x164, 0x188,
		0x1ac, 0x1ad, 0x1ae, 0x1b0, 0x1b4, 0x1b8, 0x1bc, 0x1be, 0x1c0, 0x1c2, 0x1c4, 0x1c8, 0x1c9, 0x1ca,
	};
	static const uint16_t half_off[21] = {
		0x01c, 0x040, 0x064, 0x088, 0x08e, 0x094, 0x09a, 0x0ac, 0x0c0, 0x0cc, 0x0f0, 0x114, 0x138, 0x15c,
		0x180, 0x194, 0x1b8, 0x1dc, 0x200, 0x224, 0x248,
	};
	static const uint16_t fixed_out[6] = { 0x000, 0x004, 0x00c, 0x014, BO_M, BO_MINV };
	uint32_t *c = t40_bcsh_oem_ctx, in = (uint32_t)(uintptr_t)t40_bcsh.in, out = (uint32_t)(uintptr_t)t40_bcsh.out;
	uint32_t half2 = t40_bcsh.half ? 0x50 : 0;
	unsigned int i;

	for (i = 0; i < 6; i++)
		c[i] = out + fixed_out[i];
	c[6] = in;
	for (i = 0; i < 42; i++)
		c[7 + i] = in + in_off[i];
	for (i = 0; i < 21; i++)
		c[49 + i] = out + t40_bcsh.half + half_off[i];
	c[70] = out + 0x4d4 + half2;
	c[71] = out + 0x4fc + half2;
}

/* user controls / inputs for the driver glue */
static inline uint8_t *t40_bcsh_ctl(uint32_t off) { return &t40_bcsh.in[off]; }

/* OEM tisp_bcsh_main_init as the literal glue runs it (also on a day/night
 * refresh): select the half, load the CSC mode and the bank, set EV/CT
 * from the module state, run both paths */
static int t40_bcsh_init(uint32_t mode)
{
	const uint8_t *bank = (const uint8_t *)(uintptr_t)tparamsN[0];

	if (!bank)
		return -ENOENT;
	t40_bcsh.half = t40_bcsh.in[BI_WDR] ? T40_BCSH_WDR_HALF : 0;
	t40_bcsh_build_ctx();
	t40_bcsh.ready = true;
	t40_bcsh.in[BI_CSC_MODE] = (uint8_t)mode;
	t40_bcsh_load(bank + T40_BCSH_PAR_OFFSET);
	*t40_bcsh_in32(BI_EV) = regtrace_bcsh_ev;
	*t40_bcsh_in16(BI_CT) = (uint16_t)regtrace_bcsh_ct;
	t40_bcsh_ev_update(0);
	t40_bcsh_ct_update(0);
	t40_bcsh.in[BI_BUSY] = 0;
	return 0;
}

/* OEM tisp_bcsh_main_ev_update / main_ct_update (vendor AWB follow, event
 * 8 / 13): store the input, repack when a setter is busy or the input moved
 * by more than its threshold (BI 0x1b8 / 0x1c0) from the last packed one */
#define BI_EV_LAST     0x1b4
#define BI_EV_THRESH   0x1b8
#define BI_CT_LAST     0x1be
#define BI_CT_THRESH   0x1c0
static void t40_bcsh_main_ev_update(uint32_t ev)
{
	uint32_t last = *t40_bcsh_in32(BI_EV_LAST);

	if (!t40_bcsh.ready)
		return;
	*t40_bcsh_in32(BI_EV) = ev;
	if (t40_bcsh.in[BI_BUSY] == 1 || t40_bcsh_absdiff(last, ev) > *t40_bcsh_in32(BI_EV_THRESH)) {
		t40_bcsh_ev_update(0);
		t40_bcsh.in[BI_BUSY] = 0;
		*t40_bcsh_in32(BI_EV_LAST) = ev;
	}
}

static void t40_bcsh_main_ct_update(uint32_t ct)
{
	uint16_t last = *t40_bcsh_in16(BI_CT_LAST);

	if (!t40_bcsh.ready)
		return;
	*t40_bcsh_in16(BI_CT) = (uint16_t)ct;
	if (t40_bcsh.in[BI_BUSY] == 1 ||
	    (last > ct ? last - ct : ct - last) > *t40_bcsh_in16(BI_CT_THRESH)) {
		t40_bcsh_ct_update(0);
		t40_bcsh.in[BI_BUSY] = 0;
		*t40_bcsh_in16(BI_CT_LAST) = (uint16_t)ct;
	}
}

/* tisp_bcsh_csc_attr: new CSC mode, reload and repack both paths */
static void t40_bcsh_set_csc(uint32_t mode)
{
	const uint8_t *bank = (const uint8_t *)(uintptr_t)tparamsN[0];

	t40_bcsh.in[BI_CSC_MODE] = (uint8_t)mode;
	t40_bcsh.in[BI_BUSY] = 1;
	t40_bcsh_load(bank + T40_BCSH_PAR_OFFSET);
	t40_bcsh_ev_update(0);
	t40_bcsh_ct_update(0);
	t40_bcsh.in[BI_BUSY] = 0;
}

#endif
