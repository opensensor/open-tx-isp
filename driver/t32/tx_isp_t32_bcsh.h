/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 brightness/contrast/saturation/hue block (BCSH, block 0xf000) from the
 * IQ bin at AddSensor (S4 step 8): tisp_bcsh_init -> get_new_para,
 * interp_by_ev (exposure 0, forced), interp_by_ct (5000 K, forced),
 * calc_para_refresh(0), write_reg and the block id.
 *
 * IQ bin section 19 (1204 bytes) with its colour temperature knots behind it
 * (+0x4af knots of 10 s32 { colour temperature, 3x3 matrix }, +0x4b0 the
 * hysteresis in K), and the colour space conversion section (9): its
 * matrices, offsets and mode are what the vendor's tisp_csc_api_get hands
 * the block.  The block's own user settings (brightness, contrast,
 * saturation, hue) start at 128 each, the neutral value.
 *
 * Built: the init flow of the vendor.  The transcription keeps the vendor's
 * buffer layout (parameter set "cp" of 300 bytes, user/csc set "ap") so each
 * line can be compared with the decompiled function; offsets are in bytes.
 * Refused: sections that select the exposure mode keyed by the section byte
 * +0x4b1 (thresholds in a different unit; not seen in a bin), a colour space
 * section whose +0x62/+0x63 select the other vendor path, and a matrix mode
 * byte (+0x492) above 2.
 */
#ifndef TX_ISP_T32_BCSH_H
#define TX_ISP_T32_BCSH_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_BCSH		19
#define T32_BCSH_SEC_BYTES	0x4b4U
#define T32_BCSH_CSC_BYTES	0x64U
#define T32_BCSH_ID		0x0134dae2U
#define T32_BCSH_CT		5000
#define T32_BCSH_WRITES		49
#define T32_BCSH_MAX_WRITES	49

struct t32_bcsh {
	u8 cp[300];
	u8 ap[0x90];
	u8 p5[48];
};

static inline int t32_bcsh_s16(const u8 *p, u32 o)
{
	return (s16)(p[o] | p[o + 1] << 8);
}

static inline int t32_bcsh_s32(const u8 *p, u32 o)
{
	return (int)(p[o] | (u32)p[o + 1] << 8 | (u32)p[o + 2] << 16 | (u32)p[o + 3] << 24);
}

static inline void t32_bcsh_p16(u8 *p, u32 o, u32 v)
{
	p[o] = (u8)v;
	p[o + 1] = (u8)(v >> 8);
}

static inline void t32_bcsh_p32(u8 *p, u32 o, u32 v)
{
	t32_bcsh_p16(p, o, v);
	t32_bcsh_p16(p, o + 2, v >> 16);
}

/* tisp_round_int64(x, x >> 63, n): x / 2^n rounded half up */
static inline long long t32_bcsh_rnd(long long x, unsigned int n)
{
	return (x >> n) + ((x >> (n - 1)) & 1);
}

/* the same, rounded away from zero (the hue block's) */
static inline long long t32_bcsh_symrnd(long long v, unsigned int n)
{
	long long h = 1LL << (n - 1);

	return v >= 0 ? (v + h) >> n : -((h - v) >> n);
}

/* tisp_bcsh_sub_interp: a + round((b - a) * f / 4096), the product in 32 bit */
static inline int t32_bcsh_si(int f, int a, int b)
{
	return a + (int)t32_bcsh_rnd((int)((u32)(b - a) * (u32)f), 12);
}

static inline int t32_bcsh_clip(int v, int lo, int hi)
{
	return v < lo ? lo : v > hi ? hi : v;
}

/* tisp_bcsh_adjust_contrast */
static inline void t32_bcsh_contrast(u32 c, const u32 *x, const u32 *y, u32 *ox, u32 *oy)
{
	int i;

	for (i = 0; i < 9; i++) {
		if (c == 0x80) {
			ox[i] = x[i];
			oy[i] = y[i];
		} else if (c & 0x80) {
			int iv = x[i] >= 0x201 ? 0x3ff : 0;

			ox[i] = (u16)t32_bcsh_rnd((int)(x[i] * (0x100 - c) + (c - 0x80) * 0x200), 7);
			oy[i] = (u16)t32_bcsh_rnd(iv * (int)(c - 0x80) + (int)(y[i] * (0x100 - c)), 7);
		} else {
			int iv = y[i] >= 0x201 ? 0x3ff : 0;

			ox[i] = (u16)t32_bcsh_rnd(iv * (int)(0x80 - c) + (int)(x[i] * c), 7);
			oy[i] = (u16)t32_bcsh_rnd((int)(y[i] * c + (0x80 - c) * 0x200), 7);
		}
	}
}

/* tisp_bcsh_matrix_multi: out = a * b (3x3, row major), rounded, >> sh */
static inline void t32_bcsh_mmul(int *out, const int *a, const int *b, unsigned int sh)
{
	long long h = 1LL << (sh - 1);
	int i, j, k;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			long long s = 0;

			for (k = 0; k < 3; k++)
				s += (long long)a[3 * i + k] * b[3 * k + j];
			if (s < 0x100000000LL && (s >> 32 != 0 || (u32)s == 0))
				out[3 * i + j] = (int)-((h - s) >> sh);
			else
				out[3 * i + j] = (int)((s + h) >> sh);
		}
	}
}

/* tisp_bcsh_itp */
static inline u32 t32_bcsh_itp(u32 x, u32 lo, u32 hi, u32 v0, u32 v1)
{
	if (lo < hi && lo < x) {
		if (x < hi)
			return ((x - lo) * v1 + (hi - x) * v0 + ((hi - lo) >> 1)) / (hi - lo);
		return v1;
	}
	return v0;
}

/* tisp_bcsh_adjust_hue: out = the colour matrix rotated by the hue (128 = none) */
static inline void t32_bcsh_hue(u32 h, const int *ccm, const int *m1, const int *m2, int *out)
{
	static const u32 sin_t[5] = { 0, 0x61f8, 0xb505, 0xec83, 0x10000 };
	int t54[9], t78[9], j;
	u32 q, a, b, c4, c5;
	long long s, c;

	h &= 0xff;
	q = h >> 4;
#define T32_BCSH_FOLD(x)	((x) <= 4 ? (x) : 8 - (x))
	a = T32_BCSH_FOLD(q & 7);
	b = T32_BCSH_FOLD((q + 1) & 7);
	c4 = T32_BCSH_FOLD((q + 4) & 7);
	c5 = T32_BCSH_FOLD((q + 5) & 7);
#undef T32_BCSH_FOLD
	s = (long long)t32_bcsh_itp(h & 0xf, 0, 0x10, sin_t[a], sin_t[b]);
	c = (long long)t32_bcsh_itp(h & 0xf, 0, 0x10, sin_t[c4], sin_t[c5]);
	if (!(h >> 7))
		s = -s;
	if (((h - 0x40) & 0xff) >= 0x80)
		c = -c;
	t32_bcsh_mmul(t54, m1, ccm, 10);
	t32_bcsh_mmul(t78, t54, m2, 16);
	for (j = 0; j < 3; j++) {
		out[j] = (int)t32_bcsh_symrnd(t78[j], 6);
		out[3 + j] = (int)t32_bcsh_symrnd(t78[3 + j] * c + t78[6 + j] * s, 22);
		out[6 + j] = (int)t32_bcsh_symrnd(t78[6 + j] * c - t78[3 + j] * s, 22);
	}
}

/*
 * sec: writable copy of section 19 (the block clears ten of its bytes), lut:
 * the knots behind it (lutbytes long), csc: the colour space section.
 * Returns the number of writes (49), -1 on a refused section.
 */
#ifdef __KERNEL__
#define T32_BCSH_FN	static noinline_for_stack int
#else
#define T32_BCSH_FN	static inline int
#endif
T32_BCSH_FN t32_bcsh_init(u8 *sec, const u8 *lut, u32 lutbytes, const u8 *csc, struct t32_front_write *w)
{
	static const u16 clear[] = { 0x49e, 0x49f, 0x467, 0x468, 0x461, 0x462, 0x498, 0x499, 0x493, 0x494 };
	struct t32_bcsh st;
	u8 *cp = st.cp, *ap = st.ap, *p5 = st.p5;
	int knots, hy, ct = T32_BCSH_CT, i17 = 0, i18 = 0, a, b, i, k;
	const int f = 0;
	int mat[9], m1[9], m2[9], hm[9];
	unsigned int n = 0;

	if (t32_front_le32(sec) != T32_BCSH_ID)
		return -1;
	if (sec[0x4b1] || sec[0x492] > 2)
		return -1;
	if (!(csc[0x62] == 1 || (csc[0x62] == 0 && csc[0x63] < 2)))
		return -1;
	knots = sec[0x4af];
	hy = sec[0x4b0];
	if (knots < 1 || lutbytes < (u32)knots * 40U)
		return -1;
	memset(&st, 0, sizeof(st));

	/* tisp_csc_api_get into the user/csc set; the four user settings start neutral */
	memset(ap, 0x80, 4);
	t32_bcsh_p32(ap, 0x2c, csc[0x5b]);
	memcpy(ap + 0x54, csc + 0x52, 6);
	memcpy(ap + 0x80, csc + 0x5c, 6);
	memcpy(ap + 0x30, csc + 4, 0x24);
	memcpy(ap + 0x5c, csc + 0x28, 0x24);
	for (k = 0; k < (int)(sizeof(clear) / sizeof(clear[0])); k++)
		sec[clear[k]] = 0;

	/* tisp_bcsh_get_new_para */
	if (t32_tp_le16(sec + 0x108) <= t32_tp_le16(sec + 0x106)) {
		t32_bcsh_p16(sec, 0x106, 0);
		t32_bcsh_p16(sec, 0x108, 1);
	}
	for (k = 0; k < 12; k++) {
		u32 lo = ((t32_tp_le16(sec + 0x262 + 0x18 + 2 * k) & 0x7fff) >> 10) * 0x20 +
			 ((t32_tp_le16(sec + 0x262 + 2 * k) & 0x7fff) >> 10);
		u32 hi = ((t32_tp_le16(sec + 0x262 + 0xf0 + 2 * k) & 0x7fff) >> 10) * 0x20 +
			 ((t32_tp_le16(sec + 0x262 + 0xd8 + 2 * k) & 0x7fff) >> 10);

		if (hi <= lo) {
			lo = 0;
			hi = 1;
		}
		t32_bcsh_p16(p5, 2 * k, lo);
		t32_bcsh_p16(p5, 2 * k + 0x18, hi);
	}

	/*
	 * tisp_bcsh_interp_by_ev at exposure 0: the threshold search finds the
	 * first threshold above 0; with the lower ones 0 as well the fraction
	 * between index i18 and i17 is 0 (the pair is only a source of the two
	 * values), and past the last threshold both are the last index.
	 */
	{
		int found = 0;

		for (k = 0; k < 12; k++) {
			if (t32_front_le32(sec + 4 + 4 * k) > 0) {
				found = 1;
				if (k) {
					if (t32_front_le32(sec + 4 + 4 * (k - 1)))
						return -1;
					i18 = k - 1;
					i17 = k;
				}
				break;
			}
		}
		if (!found)
			i18 = i17 = 11;
	}
	a = i18 * 2;
	b = i17 * 2;
#define SIH(dst, o, mask) \
	t32_bcsh_p16(cp, 2 * (dst), t32_bcsh_si(f, t32_tp_le16(sec + a + (o)) & (mask), t32_tp_le16(sec + b + (o)) & (mask)))
	SIH(0x81, 0x412, 0xffff);
	SIH(0x82, 0x42a, 0xffff);
	SIH(0x83, 0x442, 0xffff);
	SIH(0x25, 0x262, 0x3ff);
	SIH(0x26, 0x27a, 0x3ff);
	for (k = 0; k < 7; k++)
		SIH(0x27 + k, 0x292 + 0x18 * k, 0xffff);
	SIH(0x2e, 0x33a, 0x3ff);
	SIH(0x2f, 0x352, 0x3ff);
	for (k = 0; k < 7; k++)
		SIH(0x30 + k, 0x36a + 0x18 * k, 0xffff);
	switch (sec[0x45c]) {
	case 0:
		cp[0x24] = 0;
		break;
	case 1:
		cp[0x24] = 1;
		SIH(0x13, 0xd6, 0xffff);
		SIH(0x14, 0xee, 0xffff);
		break;
	case 2:
		cp[0x24] = 1;
		t32_bcsh_p16(cp, 0x26, t32_tp_le16(sec + 0xd2));
		t32_bcsh_p16(cp, 0x28, t32_tp_le16(sec + 0xd4));
		break;
	}
	if (sec[0x45a] == 1) {
		SIH(0, 0x9e, 0xffff);
		SIH(1, 0xb6, 0xffff);
	}
	for (k = 0; k < 10; k++)
		SIH(4 + k, 0x172 + 0x18 * k, 0xffff);
	switch (sec[0x45d]) {
	case 0:
		for (k = 0x19; k <= 0x1c; k++)
			t32_bcsh_p16(cp, 2 * k, 0x400);
		break;
	case 1:
		t32_bcsh_p16(cp, 2 * 0x17, t32_bcsh_si(f, t32_tp_le16(p5 + a), t32_tp_le16(p5 + b)));
		t32_bcsh_p16(cp, 2 * 0x18, t32_bcsh_si(f, t32_tp_le16(p5 + a + 0x18), t32_tp_le16(p5 + b + 0x18)));
		SIH(0x19, 0x112, 0xffff);
		SIH(0x1a, 0x12a, 0xffff);
		SIH(0x1b, 0x142, 0xffff);
		SIH(0x1c, 0x15a, 0xffff);
		break;
	case 2:
		for (k = 0; k < 6; k++)
			t32_bcsh_p16(cp, 2 * (0x17 + k), t32_tp_le16(sec + 0x106 + 2 * k));
		break;
	}
	if (sec[0x461] == 1 || (sec[0x461] == 0 && sec[0x462] != 2)) {
		if (sec[0x45d] <= 2)
			cp[0x2c] = sec[0x45d] ? 1 : 0;
		cp[0x3a] = sec[0x45e];
	} else {
		cp[0x2c] = 1;
		cp[0x3a] = ap[2];
	}
	if (sec[0x467] == 1 || (sec[0x467] == 0 && sec[0x468] != 2)) {
		switch (sec[0x466]) {
		case 0:
			cp[0x48] = 0;
			cp[0x49] = 0x80;
			break;
		case 1:
			cp[0x48] = 1;
			cp[0x49] = (u8)t32_bcsh_si(f, sec[a + 0x46c], sec[b + 0x46c]);
			break;
		case 2:
			cp[0x48] = 1;
			cp[0x49] = sec[0x46b];
			break;
		}
	} else {
		cp[0x48] = 1;
		cp[0x49] = ap[1];
	}
	cp[0xb2] = (u8)t32_bcsh_si(f, sec[a + 0x47a], sec[b + 0x47a]);
	cp[0xb3] = (u8)t32_bcsh_si(f, sec[a + 0x486], sec[b + 0x486]);
	if (sec[0x49e] == 1 || (sec[0x49e] == 0 && sec[0x49f] != 2)) {
		switch (sec[0x49d]) {
		case 0:
			cp[0x100] = 0x80;
			break;
		case 1:
			cp[0x100] = (u8)t32_bcsh_si(f, sec[a + 0x4a3], sec[b + 0x4a3]);
			break;
		case 2:
			cp[0x100] = sec[0x4a2];
			break;
		}
	} else {
		cp[0x100] = ap[0];
	}
#undef SIH

	/* tisp_bcsh_interp_by_ct at 5000 K */
#define L(i, j)	t32_bcsh_s32(lut, 40 * (i) + 4 * (j))
	if (sec[0x492] == 0) {
		for (i = 0; i < 9; i++)
			mat[i] = (i % 4) ? 0 : 0x400;
	} else if (sec[0x492] == 2) {
		for (i = 0; i < 9; i++)
			mat[i] = t32_bcsh_s32(sec, 0x68 + 4 * i);
	} else if (knots == 1 || L(0, 0) >= ct) {
		for (i = 0; i < 9; i++)
			mat[i] = L(0, 1 + i);
	} else if (ct >= L(knots - 1, 0)) {
		for (i = 0; i < 9; i++)
			mat[i] = L(knots - 1, 1 + i);
	} else {
		for (k = 1; k < knots && ct > L(k, 0); k++)
			;
		if (k >= knots)
			return -1;
		k--;
		{
			int c0 = L(k, 0), c1 = L(k + 1, 0);

			if (ct <= hy + c0) {
				for (i = 0; i < 9; i++)
					mat[i] = L(k, 1 + i);
			} else if (ct < c1 - hy) {
				int d = c1 - c0 - 2 * hy, nn = ct - c0 - hy;

				for (i = 0; i < 9; i++) {
					int s = (d - nn) * L(k, 1 + i) + nn * L(k + 1, 1 + i);
					int r = d >> 1;

					if (s < 1)
						r = -r;
					mat[i] = t32_bcsh_clip((s + r) / d, -0x2000, 0x1fff);
				}
			} else {
				for (i = 0; i < 9; i++)
					mat[i] = L(k + 1, 1 + i);
			}
		}
	}
#undef L
	for (i = 0; i < 9; i++)
		t32_bcsh_p32(cp, 0xb8 + 4 * i, (u32)mat[i]);

	/* tisp_bcsh_calc_para_refresh(0) */
	{
		int m[9], in[3], o[3], d, v, p;
		u32 x[9], y[9], ox[9], oy[9], u7, u5, hue;

		for (i = 0; i < 9; i++)
			m[i] = t32_bcsh_s32(ap, 0x30 + 4 * i);
		for (i = 0; i < 3; i++)
			in[i] = t32_bcsh_s16(cp, 2 * (0x81 + i));
		for (i = 0; i < 3; i++)
			o[i] = (int)t32_bcsh_rnd((long long)in[0] * m[3 * i] + (long long)in[1] * m[3 * i + 1] +
						 (long long)in[2] * m[3 * i + 2], 16);
		t32_bcsh_p16(cp, 2 * 0x87, o[0] + ap[0x54] * 4 + ((int)cp[0x100] - 0x80) * 8);
		t32_bcsh_p16(cp, 2 * 0x88, o[1]);
		t32_bcsh_p16(cp, 2 * 0x89, o[2]);
		d = (int)t32_tp_le16(cp + 0x28) - (int)t32_tp_le16(cp + 0x26);
		t32_bcsh_p16(cp, 2 * 0x15, t32_bcsh_clip(d > 0 ? ((d >> 1) + 0x1000) / d : 0, 0, 0x3ff));
		p = sec[0x466] ? 0x2e : 0x25;
		for (i = 0; i < 9; i++) {
			x[i] = t32_tp_le16(cp + 2 * (0x25 + i));
			y[i] = t32_tp_le16(cp + 2 * (p + i));
		}
		for (i = 0; i < 9; i++) {
			ox[i] = 0;
			oy[i] = 0;
		}
		t32_bcsh_contrast(cp[0x49], x, y, ox, oy);
		for (i = 0; i < 9; i++) {
			t32_bcsh_p16(cp, 2 * (0x3f + i), ox[i]);
			t32_bcsh_p16(cp, 2 * (0x48 + i), oy[i]);
		}
		for (p = 0x40; p < 0x48; p++) {
			d = (int)t32_tp_le16(cp + 2 * p) - (int)t32_tp_le16(cp + 2 * (p - 1));
			v = 0;
			if (d > 0)
				v = ((int)t32_tp_le16(cp + 2 * (p + 9)) - (int)t32_tp_le16(cp + 2 * (p + 8))) * 0x400;
			if (d > 0)
				v = (v + (d >> 1)) / d;
			t32_bcsh_p16(cp, 2 * (p + 0x11), t32_bcsh_clip(v, 0, 0x7fff));
		}
		u7 = cp[0x3a];
		if (sec[0x460] && cp[0x49] < 0x80)
			u7 = (u8)t32_bcsh_rnd(u7 * cp[0x49], 7);
		if (sec[0x45f] && cp[0x100] < 0x80)
			u7 = (u8)t32_bcsh_rnd(u7 * cp[0x100], 7);
		u5 = t32_tp_le16(cp + 2 * 0x19);
		t32_bcsh_p16(cp, 2 * 0x1e, t32_bcsh_rnd(u5 * u7, 7));
		t32_bcsh_p16(cp, 2 * 0x1f, t32_bcsh_rnd(t32_tp_le16(cp + 2 * 0x1a) * u7, 7));
		t32_bcsh_p16(cp, 2 * 0x20, t32_bcsh_rnd(t32_tp_le16(cp + 2 * 0x1b) * u7, 7));
		u7 = (u16)t32_bcsh_rnd(t32_tp_le16(cp + 2 * 0x1c) * u7, 7);
		t32_bcsh_p16(cp, 2 * 0x21, u7);
		d = (int)t32_tp_le16(cp + 2 * 0x18) - (int)t32_tp_le16(cp + 2 * 0x17);
		if (d < 1) {
			t32_bcsh_p16(cp, 2 * 0x22, 0);
			t32_bcsh_p16(cp, 2 * 0x23, 0);
		} else {
			int d1 = (int)t32_tp_le16(cp + 2 * 0x1f) - (int)t32_tp_le16(cp + 2 * 0x1e);
			int d2 = (int)u7 - (int)t32_tp_le16(cp + 2 * 0x20);

			t32_bcsh_p16(cp, 2 * 0x22, ((d1 < 0 ? -d1 : d1) + (d >> 1)) / d);
			t32_bcsh_p16(cp, 2 * 0x23, ((d2 < 0 ? -d2 : d2) + (d >> 1)) / d);
		}
		v = cp[0xb3];
		t32_bcsh_p16(cp, 2 * 0x5a, t32_bcsh_clip(v ? ((v >> 1) + 0x400) / v : 0, 0, 0x3ff));
		d = (int)t32_tp_le16(cp + 2) - (int)t32_tp_le16(cp);
		t32_bcsh_p16(cp, 4, t32_bcsh_clip(d > 0 ? ((d >> 1) + 0x1000) / d : 0, 0, 0x3ff));
		for (p = 5; p < 9; p++) {
			d = (int)t32_tp_le16(cp + 2 * p) - (int)t32_tp_le16(cp + 2 * (p - 1));
			v = 0;
			if (d > 0) {
				v = (int)t32_tp_le16(cp + 2 * (p + 5)) - (int)t32_tp_le16(cp + 2 * (p + 4));
				v = ((v < 0 ? -v : v) * 0x400 + (d >> 1)) / d;
			}
			t32_bcsh_p16(cp, 2 * (p + 9), t32_bcsh_clip(v, 0, 0x7fff));
		}

		/* hue */
		if (sec[0x498] == 1 || (sec[0x498] == 0 && sec[0x499] != 2))
			hue = sec[0x497] ? sec[0x49c] : 0x80;
		else
			hue = ap[3];
		cp[0xb6] = (u8)hue;
		for (i = 0; i < 9; i++) {
			m1[i] = t32_bcsh_s32(ap, 0x30 + 4 * i);
			m2[i] = t32_bcsh_s32(ap, 0x5c + 4 * i);
		}
		t32_bcsh_hue(hue, mat, m1, m2, hm);
		for (i = 0; i < 9; i++)
			t32_bcsh_p32(cp, 0xdc + 4 * i, (u32)hm[i]);
		d = (int)t32_tp_le16(sec + 0xd0) - (int)t32_tp_le16(sec + 0xce);
		t32_bcsh_p16(cp, 6, t32_bcsh_clip(d > 0 ? ((d >> 1) + 0x1000) / d : 0, 0, 0x3ff));
		t32_bcsh_p16(cp, 2 * 0x8a, (u32)ap[0x56] << 2);
		t32_bcsh_p16(cp, 2 * 0x8b, 0);
		v = ap[0x57] == 0xff ? 0x3ff : 0x3ac;
		t32_bcsh_p16(cp, 2 * 0x8d, v);
		t32_bcsh_p16(cp, 2 * 0x8c, (u32)ap[0x56] << 2);
		t32_bcsh_p16(cp, 2 * 0x8f, v);
		t32_bcsh_p16(cp, 2 * 0x8e, ((int)ap[0x57] - (int)ap[0x56]) * 4);
		t32_bcsh_p16(cp, 2 * 0x90, (u32)ap[0x58] << 2);
		t32_bcsh_p16(cp, 2 * 0x91, 0);
		v = ap[0x59] == 0xff ? 0x3ff : 0x3c0;
		t32_bcsh_p16(cp, 2 * 0x93, v);
		t32_bcsh_p16(cp, 2 * 0x92, (u32)ap[0x58] << 2);
		t32_bcsh_p16(cp, 2 * 0x95, v);
		t32_bcsh_p16(cp, 2 * 0x94, ((int)ap[0x59] - (int)ap[0x58]) * 4);
		t32_bcsh_p16(cp, 2 * 0x84, 0);
		t32_bcsh_p16(cp, 2 * 0x85, 0);
		t32_bcsh_p16(cp, 2 * 0x86, 0);
	}

	/* tisp_bcsh_write_reg */
#define P(i)		t32_tp_le16(cp + 2 * (i))
#define HM(i)		(t32_front_le32(cp + 0xdc + 4 * (i)) & 0x3fff)
	T32_FWR(w, n, 0xf040, (P(0x8a) & 0x3ff) << 16 | (P(0x8d) & 0x3ff));
	T32_FWR(w, n, 0xf044, (P(0x8b) & 0x3ff) << 16 | (P(0x8e) & 0x3ff));
	T32_FWR(w, n, 0xf048, (P(0x8c) & 0x3ff) << 16 | (P(0x8f) & 0x3ff));
	T32_FWR(w, n, 0xf04c, (P(0x90) & 0x3ff) << 16 | (P(0x93) & 0x3ff));
	T32_FWR(w, n, 0xf050, (P(0x91) & 0x3ff) << 16 | (P(0x94) & 0x3ff));
	T32_FWR(w, n, 0xf054, (P(0x92) & 0x3ff) << 16 | (P(0x95) & 0x3ff));
	T32_FWR(w, n, 0xf058, (P(0x87) & 0x7ff) << 16 | (P(0x84) & 0x7ff));
	T32_FWR(w, n, 0xf05c, (P(0x88) & 0x7ff) << 16 | (P(0x85) & 0x7ff));
	T32_FWR(w, n, 0xf060, (P(0x89) & 0x7ff) << 16 | (P(0x86) & 0x7ff));
	T32_FWR(w, n, 0xf064, HM(1) << 16 | HM(0));
	T32_FWR(w, n, 0xf068, HM(2));
	T32_FWR(w, n, 0xf06c, HM(4) << 16 | HM(3));
	T32_FWR(w, n, 0xf070, HM(5));
	T32_FWR(w, n, 0xf074, HM(7) << 16 | HM(6));
	T32_FWR(w, n, 0xf078, HM(8));
	T32_FWR(w, n, 0xf07c, (P(2) & 0x3ff) << 16 | (sec[0x45a] & 1U));
	T32_FWR(w, n, 0xf080, (P(1) & 0x3ff) << 16 | (P(0) & 0x3ff));
	T32_FWR(w, n, 0xf084, (P(3) & 0x3ff) << 16 | (sec[0x45b] & 1U));
	T32_FWR(w, n, 0xf088, (t32_tp_le16(sec + 0xd0) & 0x3ff) << 16 | (t32_tp_le16(sec + 0xce) & 0x3ff));
	T32_FWR(w, n, 0xf08c, (P(0x15) & 0x3ff) << 16 | (cp[0x24] & 1U));
	T32_FWR(w, n, 0xf090, (P(0x14) & 0x3ff) << 16 | (P(0x13) & 0x3ff));
	for (k = 0; k < 4; k++)
		T32_FWR(w, n, 0xf094 + 4 * k, (P(0x40 + 2 * k) & 0x3ff) << 16 | (P(0x3f + 2 * k) & 0x3ff));
	T32_FWR(w, n, 0xf0a4, (cp[0x48] & 1U) << 16 | (P(0x47) & 0x3ff));
	for (k = 0; k < 4; k++)
		T32_FWR(w, n, 0xf0a8 + 4 * k, (P(0x49 + 2 * k) & 0x3ff) << 16 | (P(0x48 + 2 * k) & 0x3ff));
	T32_FWR(w, n, 0xf0b8, P(0x50) & 0x3ff);
	for (k = 0; k < 4; k++)
		T32_FWR(w, n, 0xf0bc + 4 * k, (P(0x52 + 2 * k) & 0x7fff) << 16 | (P(0x51 + 2 * k) & 0x7fff));
	T32_FWR(w, n, 0xf0cc, (P(0x22) & 0x1fffU) << 3 | (P(0x23) & 0x1fffU) << 16 | (cp[0x2c] & 1U));
	T32_FWR(w, n, 0xf0d0, (P(0x18) & 0x3ff) << 16 | (P(0x17) & 0x3ff));
	T32_FWR(w, n, 0xf0d4, (P(0x1e) & 0x1fffU) << 16 | (P(0x1f) & 0x1fff));
	T32_FWR(w, n, 0xf0d8, (P(0x20) & 0x1fffU) << 16 | (P(0x21) & 0x1fff));
	T32_FWR(w, n, 0xf0dc, (P(5) & 0x3ff) << 16 | (P(4) & 0x3ff));
	T32_FWR(w, n, 0xf0e0, (P(7) & 0x3ff) << 16 | (P(6) & 0x3ff));
	T32_FWR(w, n, 0xf0e4, (sec[0x465] & 1U) << 16 | (P(8) & 0x3ff));
	T32_FWR(w, n, 0xf0e8, (P(10) & 0x3ff) << 16 | (P(9) & 0x3ff));
	T32_FWR(w, n, 0xf0ec, (P(12) & 0x3ff) << 16 | (P(11) & 0x3ff));
	T32_FWR(w, n, 0xf0f0, P(13) & 0x3ff);
	T32_FWR(w, n, 0xf0f4, t32_front_le32(cp + 0x1c));
	T32_FWR(w, n, 0xf0f8, t32_front_le32(cp + 0x20));
	T32_FWR(w, n, 0xf0fc, (cp[0xb3] & 0x3fU) << 4 | (P(0x5a) & 0x3ffU) << 16 | (cp[0xb2] & 3U));
	T32_FWR(w, n, 0xf000, T32_BCSH_ID);
#undef P
#undef HM
	return (int)n;
}

#endif /* TX_ISP_T32_BCSH_H */
