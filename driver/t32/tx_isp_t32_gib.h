/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 black level / green imbalance (GIB, block 0x3000) from the IQ bin at
 * AddSensor (S4 step 6): tisp_gib_init -> tisp_gib_interp_by_again (gain
 * 0x400), tisp_gib_slope_update (tisp_gib_calc_slope x5), tisp_gib_write_reg,
 * tisp_gib_interp_by_again_s, tisp_gib_write_blc_s_reg and the block id.
 *
 * IQ bin section 8 (548 bytes).  The vendor keeps the interpolated values
 * in a working block (here "cp", 0x84 bytes) and a table of 16 pointers to
 * them, which depends on the Bayer pattern; the pattern with RGGB first (the
 * vendor's default case) is built, the others are refused.  The vendor's
 * initial state (all-zero working block, gain words 0x400, no copy-back
 * mode, normal black level path) is reproduced.  The interpolated black
 * levels are also copied back into the section (the vendor does so when
 * section byte 0x223 is 0), so pass a writable copy.
 */
#ifndef TX_ISP_T32_GIB_H
#define TX_ISP_T32_GIB_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_GIB		8
#define T32_GIB_SEC_BYTES	548U
#define T32_GIB_VALUES		0x84U
#define T32_GIB_ID		0x0134da11U
#define T32_GIB_MAX_WRITES	128

/* The vendor's pointer table: the working block offset each of the 16 black level words reads (Bayer RGGB first). */
static const u8 t32_gib_ptr[16] = { 0x40, 0x42, 0x40, 0x42, 0x44, 0x46, 0x44, 0x46,
				    0x4c, 0x4e, 0x4c, 0x4e, 0x50, 0x52, 0x50, 0x52 };
#define T32_GIB_GP(i)	t32_tp_le16(cp + t32_gib_ptr[i])

/* tisp_round_int64(x, 0, 1) */
static inline u32 t32_gib_round1(u32 x)
{
	return (x >> 1) + (x & 1);
}

/* tisp_gib_calc_slope: slopes (x 256) between five knots, 0 when the knots are not ordered */
static inline void t32_gib_slope(const u8 *xs, const u8 *ys, u8 *out)
{
	u32 x0 = t32_tp_le16(xs), x1 = t32_tp_le16(xs + 2), x2 = t32_tp_le16(xs + 4), x3 = t32_tp_le16(xs + 6);
	u32 x4 = t32_tp_le16(xs + 8), y0 = t32_tp_le16(ys), y1 = t32_tp_le16(ys + 2), y2 = t32_tp_le16(ys + 4);
	u32 y3 = t32_tp_le16(ys + 6), y4 = t32_tp_le16(ys + 8);
	u32 s0, s1, s2, s3;

	t32_tp_put16(out, 0);
	t32_tp_put16(out + 2, 0);
	t32_tp_put16(out + 4, 0);
	t32_tp_put16(out + 6, 0);
	if (!(x0 < x1) && !(x1 < x2) && !(x2 < x3) && x4 <= x3)
		return;
	if (y1 < y0 || y2 < y1 || y3 < y2 || y3 > y4)
		return;
	s0 = (u32)((int)((y1 - y0) * 0x100) / (int)(x1 - x0));
	s1 = (u32)((int)((y2 - y1) * 0x100) / (int)(x2 - x1));
	s2 = (u32)((int)((y3 - y2) * 0x100) / (int)(x3 - x2));
	s3 = (u32)((int)((y4 - y3) * 0x100) / (int)(x4 - x3));
	t32_tp_put16(out, (s0 & 0xffff) > 0xfff ? 0xfff : s0);
	t32_tp_put16(out + 2, (s1 & 0xffff) > 0xfff ? 0xfff : s1);
	t32_tp_put16(out + 4, (s2 & 0xffff) > 0xfff ? 0xfff : s2);
	t32_tp_put16(out + 6, (s3 & 0xffff) > 0xfff ? 0xfff : s3);
}

/* the largest of five black levels and the matching 0x4a / 0x56 word */
static inline u32 t32_gib_gain(const u8 *p)
{
	u32 v = t32_tp_le16(p), k;

	for (k = 1; k < 5; k++)
		if (v <= t32_tp_le16(p + 2 * k))
			v = t32_tp_le16(p + 2 * k);
	return (v >> 11) ? 0x1fff : t32_gib_round1(0x2000000U / (0x1000 - v));
}

/* The expressions below keep the operator precedence of the transcribed code. */
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#endif

/* tisp_gib_write_reg(0): the black level words, then the section words */
static inline void t32_gib_write_reg(const u8 *sec, const u8 *cp, int ip10, struct t32_front_write *w, unsigned int *np)
{
	unsigned int n = *np;

	T32_FWR(w, n, 0x3044, (T32_GIB_GP(1) & 0xfff) << 0x10 | T32_GIB_GP(0) & 0xfff);
	T32_FWR(w, n, 0x3048, (T32_GIB_GP(3) & 0xfff) << 0x10 | T32_GIB_GP(2) & 0xfff);
	T32_FWR(w, n, 0x3050,t32_tp_le16(cp + 0x4a) & 0x1fff);
	T32_FWR(w, n, 0x317c, (T32_GIB_GP(5) & 0xfff) << 0x10 | T32_GIB_GP(4) & 0xfff);
	T32_FWR(w, n, 0x3180, (T32_GIB_GP(7) & 0xfff) << 0x10 | T32_GIB_GP(6) & 0xfff);
	if (!ip10) {
		T32_FWR(w, n, 0x318c, (T32_GIB_GP(1) & 0xfff) << 0x10 | T32_GIB_GP(0) & 0xfff);
		T32_FWR(w, n, 0x3190, (T32_GIB_GP(3) & 0xfff) << 0x10 | T32_GIB_GP(2) & 0xfff);
		T32_FWR(w, n, 0x3200,t32_tp_le16(cp + 0x4a) & 0x1fff);
		T32_FWR(w, n, 0x3194, (T32_GIB_GP(5) & 0xfff) << 0x10 | T32_GIB_GP(4) & 0xfff);
		T32_FWR(w, n, 0x3198, (T32_GIB_GP(7) & 0xfff) << 0x10 | T32_GIB_GP(6) & 0xfff);
	}
	T32_FWR(w, n, 0x3068, cp[0x80]);
	T32_FWR(w, n, 0x3040,sec[0x202] & 1);
	T32_FWR(w, n, 0x304c,sec[0x203] & 1);
	if (!ip10) {
		T32_FWR(w, n, 0x3188,sec[0x202] & 1);
		T32_FWR(w, n, 0x319c,sec[0x203] & 1);
	}
	T32_FWR(w, n, 0x3064,sec[0x206] & 1);
	T32_FWR(w, n, 0x306c, (t32_tp_le16(sec + 10) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 8) & 0x3ff);
	T32_FWR(w, n, 0x3070,t32_tp_le16(sec + 0xc) & 0x3ff);
	T32_FWR(w, n, 0x3074,t32_tp_le16(sec + 0xe) & 0x7ff);
	T32_FWR(w, n, 0x3078, (t32_tp_le16(sec + 0x12) & 0x7ff) << 0x10 |
			t32_tp_le16(sec + 0x10) & 0x7ff);
	T32_FWR(w, n, 0x307c,t32_tp_le16(sec + 0x14) & 0x7ff);
	T32_FWR(w, n, 0x3080,sec[0x213] & 3);
	T32_FWR(w, n, 0x3084,sec[0x215] & 1);
	T32_FWR(w, n, 0x3088,sec[0x1ff] & 0x1f);
	T32_FWR(w, n, 0x308c,sec[0x200] & 0x1f);
	T32_FWR(w, n, 0x3090,sec[0x201] & 0x1f);
	T32_FWR(w, n, 0x3094,sec[0x216] & 1);
	T32_FWR(w, n, 0x3098, (t32_tp_le16(sec + 0x116) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x114) & 0xfff);
	T32_FWR(w, n, 0x309c, (t32_tp_le16(sec + 0x11a) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x118) & 0xfff);
	T32_FWR(w, n, 0x30a0,t32_tp_le16(sec + 0x11c) & 0xfff);
	T32_FWR(w, n, 0x30a4, (t32_tp_le16(sec + 0x120) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x11e) & 0x3ff);
	T32_FWR(w, n, 0x30a8, (t32_tp_le16(sec + 0x124) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x122) & 0x3ff);
	T32_FWR(w, n, 0x30ac,t32_tp_le16(sec + 0x126) & 0x3ff);
	T32_FWR(w, n, 0x30b0, (t32_tp_le16(cp + 0x5a) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x58) & 0xfff);
	T32_FWR(w, n, 0x30b4, (t32_tp_le16(cp + 0x5e) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x5c) & 0xfff);
	T32_FWR(w, n, 0x30b8,sec[0x217] & 1);
	T32_FWR(w, n, 0x30bc, (t32_tp_le16(sec + 0x12a) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x128) & 0xfff);
	T32_FWR(w, n, 0x30c0, (t32_tp_le16(sec + 0x12e) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 300) & 0xfff);
	T32_FWR(w, n, 0x30c4,t32_tp_le16(sec + 0x130) & 0xfff);
	T32_FWR(w, n, 0x30c8, (t32_tp_le16(sec + 0x134) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x132) & 0x3ff);
	T32_FWR(w, n, 0x30cc, (t32_tp_le16(sec + 0x138) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x136) & 0x3ff);
	T32_FWR(w, n, 0x30d0,t32_tp_le16(sec + 0x13a) & 0x3ff);
	T32_FWR(w, n, 0x30d4, (t32_tp_le16(cp + 0x62) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x60) & 0xfff);
	T32_FWR(w, n, 0x30d8, (t32_tp_le16(cp + 0x66) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 100) & 0xfff);
	T32_FWR(w, n, 0x30dc,sec[0x218] & 1);
	T32_FWR(w, n, 0x30e0,sec[0x219] & 3);
	T32_FWR(w, n, 0x30e4, (t32_tp_le16(sec + 0x13e) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x13c) & 0xfff);
	T32_FWR(w, n, 0x30e8, (t32_tp_le16(sec + 0x142) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x140) & 0xfff);
	T32_FWR(w, n, 0x30ec,t32_tp_le16(sec + 0x144) & 0xfff);
	T32_FWR(w, n, 0x30f0, (t32_tp_le16(sec + 0x148) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x146) & 0x3ff);
	T32_FWR(w, n, 0x30f4, (t32_tp_le16(sec + 0x14c) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x14a) & 0x3ff);
	T32_FWR(w, n, 0x30f8,t32_tp_le16(sec + 0x14e) & 0x3ff);
	T32_FWR(w, n, 0x30fc, (t32_tp_le16(cp + 0x6a) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x68) & 0xfff);
	T32_FWR(w, n, 0x3100, (t32_tp_le16(cp + 0x6e) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x6c) & 0xfff);
	T32_FWR(w, n, 0x3104,sec[0x21a] & 1);
	T32_FWR(w, n, 0x3108,sec[0x21b] & 3);
	T32_FWR(w, n, 0x310c, (t32_tp_le16(sec + 0x152) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x150) & 0xfff);
	T32_FWR(w, n, 0x3110, (t32_tp_le16(sec + 0x156) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x154) & 0xfff);
	T32_FWR(w, n, 0x3114,t32_tp_le16(sec + 0x158) & 0xfff);
	T32_FWR(w, n, 0x3118, (t32_tp_le16(sec + 0x15c) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x15a) & 0x3ff);
	T32_FWR(w, n, 0x311c, (t32_tp_le16(sec + 0x160) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x15e) & 0x3ff);
	T32_FWR(w, n, 0x3120,t32_tp_le16(sec + 0x162) & 0x3ff);
	T32_FWR(w, n, 0x3124, (t32_tp_le16(cp + 0x72) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x70) & 0xfff);
	T32_FWR(w, n, 0x3128, (t32_tp_le16(cp + 0x76) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x74) & 0xfff);
	T32_FWR(w, n, 0x312c,sec[0x21c] & 1);
	T32_FWR(w, n, 0x3130,sec[0x21d] & 3);
	T32_FWR(w, n, 0x3134, (t32_tp_le16(sec + 0x166) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x164) & 0xfff);
	T32_FWR(w, n, 0x3138, (t32_tp_le16(sec + 0x16a) & 0xfff) << 0x10 |
			t32_tp_le16(sec + 0x168) & 0xfff);
	T32_FWR(w, n, 0x313c,t32_tp_le16(sec + 0x16c) & 0xfff);
	T32_FWR(w, n, 0x3140, (t32_tp_le16(sec + 0x170) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x16e) & 0x3ff);
	T32_FWR(w, n, 0x3144, (t32_tp_le16(sec + 0x174) & 0x3ff) << 0x10 |
			t32_tp_le16(sec + 0x172) & 0x3ff);
	T32_FWR(w, n, 0x3148,t32_tp_le16(sec + 0x176) & 0x3ff);
	T32_FWR(w, n, 0x314c, (t32_tp_le16(cp + 0x7a) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x78) & 0xfff);
	T32_FWR(w, n, 0x3150, (t32_tp_le16(cp + 0x7e) & 0xfff) << 0x10 |
			t32_tp_le16(cp + 0x7c) & 0xfff);
	T32_FWR(w, n, 0x3154,sec[0x21f] & 3);
	T32_FWR(w, n, 0x3158,t32_tp_le16(sec + 0x178) & 0x3ff);
	T32_FWR(w, n, 0x315c,t32_tp_le16(sec + 0x17a) & 0x3ff);
	T32_FWR(w, n, 0x3160,t32_tp_le16(sec + 0x17c) & 0x3ff);
	T32_FWR(w, n, 0x3164,sec[0x1fe] & 0xf);
	T32_FWR(w, n, 0x3010, 3);
	*np = n;
}

/* tisp_gib_write_blc_s_reg (the normal black level path) */
static inline void t32_gib_write_blc_s(const u8 *sec, const u8 *cp, struct t32_front_write *w, unsigned int *np)
{
	unsigned int n = *np;

	T32_FWR(w, n, 0x3188,sec[0x202] & 1);
	T32_FWR(w, n, 0x319c,sec[0x203] & 1);
	T32_FWR(w, n, 0x318c, (T32_GIB_GP(1) & 0xfff) << 0x10 | T32_GIB_GP(0) & 0xfff);
	T32_FWR(w, n, 0x3190, (T32_GIB_GP(3) & 0xfff) << 0x10 | T32_GIB_GP(2) & 0xfff);
	T32_FWR(w, n, 0x3200,t32_tp_le16(cp + 0x4a) & 0x1fff);
	T32_FWR(w, n, 0x3194, (T32_GIB_GP(5) & 0xfff) << 0x10 | T32_GIB_GP(4) & 0xfff);
	T32_FWR(w, n, 0x3198, (T32_GIB_GP(7) & 0xfff) << 0x10 | T32_GIB_GP(6) & 0xfff);
	T32_FWR(w, n, 0x3010, 3);
	*np = n;
}


#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*
 * sec: writable copy of section 8 (T32_GIB_SEC_BYTES); bayer: the init
 * parameter's pattern (word 2 of the AddSensor init block, & 0x1f; 0 = RGGB
 * first).  The writes go to w (T32_GIB_MAX_WRITES entries).  Returns their
 * number, -1 for a Bayer pattern whose pointer table is not built.
 */
static inline int t32_gib_init(u8 *sec, u32 bayer, struct t32_front_write *w)
{
	u8 cp[T32_GIB_VALUES];
	unsigned int n = 0, k;
	static const u8 src[5] = { 0x24, 0x3a, 0x50, 0x66, 0x7c };
	static const u8 srcs[5] = { 0x9c, 0xb2, 0xc8, 0xde, 0xf4 };
	static const u16 slx[5] = { 0x114, 0x128, 0x13c, 0x150, 0x164 };
	u32 f = 0x400;	/* the vendor's gain words: index 0, fraction 0x400 */

	bayer &= 0x1f;
	if (bayer == 1 || (bayer >= 0xe && bayer <= 0x13))
		return -1;
	for (k = 0; k < T32_GIB_VALUES; k++)
		cp[k] = 0;
	sec[0x220] = 0;
	sec[0x221] = 0;
	/* tisp_gib_interp_by_again */
	for (k = 0; k < 5; k++) {
		if (!t32_front_le32(sec + 4))
			t32_tp_put16(cp + 0x40 + 2 * k, t32_tp_intp_u16(0, f, sec + src[k]));
		else
			t32_tp_put16(cp + 0x40 + 2 * k, t32_tp_le16(sec + 0x92 + 2 * k));
	}
	if (!t32_front_le32(sec + 4) && !sec[0x223])
		for (k = 0; k < 5; k++)
			t32_tp_put16(sec + 0x92 + 2 * k, t32_tp_le16(cp + 0x40 + 2 * k));
	cp[0x80] = !t32_front_le32(sec + 4) ? t32_tp_intp_u8(0, f, sec + 0x207) : sec[0x212];
	t32_tp_put16(cp + 0x4a, t32_gib_gain(cp + 0x40));
	/* tisp_gib_slope_update */
	for (k = 0; k < 5; k++)
		t32_gib_slope(sec + slx[k], sec + slx[k] + 10, cp + 0x58 + 8 * k);
	t32_gib_write_reg(sec, cp, 0, w, &n);
	/* tisp_gib_interp_by_again_s */
	for (k = 0; k < 5; k++) {
		if (!t32_front_le32(sec + 4))
			t32_tp_put16(cp + 0x4c + 2 * k, t32_tp_intp_u16(0, f, sec + srcs[k]));
		else
			t32_tp_put16(cp + 0x4c + 2 * k, t32_tp_le16(sec + 0x10a + 2 * k));
	}
	if (!t32_front_le32(sec + 4) && !sec[0x223])
		for (k = 0; k < 5; k++)
			t32_tp_put16(sec + 0x10a + 2 * k, t32_tp_le16(cp + 0x4c + 2 * k));
	t32_tp_put16(cp + 0x56, t32_gib_gain(cp + 0x4c));
	t32_gib_write_blc_s(sec, cp, w, &n);
	T32_FWR(w, n, 0x3000, T32_GIB_ID);
	return (int)n;
}

#undef T32_GIB_GP
#endif /* TX_ISP_T32_GIB_H */
