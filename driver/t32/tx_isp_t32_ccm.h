/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 colour correction matrix (CCM, block 0x9000) from the IQ bin at
 * AddSensor (S4 step 7): tisp_ccm_init -> tisp_ccm_interp_by_ct (5000 K),
 * tisp_ccm_interp_by_ev (exposure 0), tisp_ccm_calc_para_refresh,
 * tisp_ccm_write_reg and the block id.
 *
 * IQ bin section 12 (872 bytes) and the payload behind it: +0x364 knots of
 * 10 s32 { colour temperature, 3x3 matrix }, +0x365 the hysteresis in K.
 * The matrix of the knot at or around 5000 K is taken as it is when the
 * temperature is within the hysteresis of a knot, otherwise the nine
 * coefficients are interpolated linearly (clamped to +-0x1fff).  The
 * saturation/ev byte tables of the section are copied when the exposure
 * is below the first threshold (the init case: exposure 0), and the
 * 1/(range) factors of the five ranges are computed with the vendor's
 * power-of-two buckets.
 *
 * Built: the init flow with the vendor's initial state (colour temperature
 * 5000, exposure 0, no API override, no tuning array: section bytes
 * +0x360/+0x361 are cleared as the vendor does, so pass a writable copy).
 * Refused: sections whose +0x35f byte is 0 (that path keeps compiled-in
 * defaults of the vendor driver) and +0x38 = 1 (fixed matrix from the
 * section).
 */
#ifndef TX_ISP_T32_CCM_H
#define TX_ISP_T32_CCM_H

#include "tx_isp_t32_tp.h"


#define T32_SEC_CCM		12
#define T32_CCM_SEC_BYTES	872U
#define T32_CCM_ID		0x0134dacdU
#define T32_CCM_CT		5000
#define T32_CCM_WRITES		24
#define T32_CCM_MAX_WRITES	24

static inline int t32_ccm_i32(const u8 *p)
{
	return (int)(p[0] | (u32)p[1] << 8 | (u32)p[2] << 16 | (u32)p[3] << 24);
}

/* tisp_ccm_sub_interp: a + round((b - a) * f / 4096) */
static inline int t32_ccm_sub(int f, int a, int b)
{
	long long v = (long long)(b - a) * f;

	return a + (int)((v >> 12) + ((v >> 11) & 1));
}

/* the bucket of tisp_ccm_calc_para_refresh: *shift and 1 / d scaled by 2^(shift + 10) */
static inline u32 t32_ccm_bucket(int d, u8 *shift)
{
	int k, base;

	if (d < 3) {
		*shift = 0;
		return d == 2 ? 0x200 : 0;
	}
	k = d > 0x400 ? 10 : d > 0x200 ? 9 : d > 0x100 ? 8 : d > 0x80 ? 7 : d > 0x40 ? 6 :
	    d > 0x20 ? 5 : d > 0x10 ? 4 : d > 8 ? 3 : d > 4 ? 2 : 1;
	base = 0x400 << k;
	*shift = (u8)k;
	return (u16)((u32)((d >> 1) + base) / (u32)d);
}

/* section u16 */
#define T32_CCM_S16(s, o)	t32_tp_le16((s) + (o))

/*
 * sec: writable copy of section 12, lut: the payload behind it (lutbytes
 * long, knots * 40).  Returns the number of writes (24), -1 on a refused
 * section.
 */
static inline int t32_ccm_init(u8 *sec, const u8 *lut, u32 lutbytes, struct t32_front_write *w)
{
	u8 cp[0x68];
	int mat[9], i, knots, hyst, idx;
	unsigned int n = 0;
	u32 v;
	u8 sh;
	int d;

	if (t32_front_le32(sec) != T32_CCM_ID || !sec[0x35f] || t32_front_le32(sec + 0x38) == 1)
		return -1;
	memset(cp, 0, sizeof(cp));
	sec[0x360] = 0;
	sec[0x361] = 0;
	knots = sec[0x364];
	hyst = sec[0x365];
	if (knots < 1 || lutbytes < (u32)knots * 40U)
		return -1;

	/* tisp_ccm_interp_by_ct at 5000 K */
	if (knots == 1) {
		for (i = 0; i < 9; i++)
			mat[i] = t32_ccm_i32(lut + 4 + 4 * i);
	} else if (t32_ccm_i32(lut) >= T32_CCM_CT) {
		for (i = 0; i < 9; i++)
			mat[i] = t32_ccm_i32(lut + 4 + 4 * i);
	} else if (t32_ccm_i32(lut + 40 * (knots - 1)) <= T32_CCM_CT) {
		for (i = 0; i < 9; i++)
			mat[i] = t32_ccm_i32(lut + 40 * (knots - 1) + 4 + 4 * i);
	} else {
		for (idx = 1; idx < knots && t32_ccm_i32(lut + 40 * idx) < T32_CCM_CT; idx++)
			;
		if (idx >= knots)
			return -1;
		{
			const u8 *lo = lut + 40 * (idx - 1), *hi = lut + 40 * idx;
			int clo = t32_ccm_i32(lo), chi = t32_ccm_i32(hi);

			if (clo + hyst < T32_CCM_CT && T32_CCM_CT < chi - hyst) {
				int den = chi - clo - 2 * hyst, num = T32_CCM_CT - clo - hyst;

				for (i = 0; i < 9; i++) {
					int a = t32_ccm_i32(lo + 4 + 4 * i), b = t32_ccm_i32(hi + 4 + 4 * i);
					int s = (den - num) * a + num * b;
					int r = den >> 1;

					if (s < 1)
						r = -r;
					s = (s + r) / den;
					mat[i] = s < -0x2000 ? -0x2000 : s > 0x1fff ? 0x1fff : s;
				}
			} else {
				/* within the hysteresis of a knot: that knot's matrix */
				const u8 *k = clo + hyst < T32_CCM_CT ? hi : lo;

				for (i = 0; i < 9; i++)
					mat[i] = t32_ccm_i32(k + 4 + 4 * i);
			}
		}
	}
	for (i = 0; i < 9; i++)
		t32_tp_put32(cp + 4 * i, (u32)mat[i]);

	/* tisp_ccm_interp_by_ev at exposure 0 (below the first threshold) */
	if (t32_front_le32(sec + 4) == 0)
		return -1;
	t32_tp_put16(cp + 0x4c, T32_CCM_S16(sec, 0x316));
	t32_tp_put16(cp + 0x4e, T32_CCM_S16(sec, 0x32e));
	for (i = 0; i < 12; i++)
		t32_tp_put16(cp + 0x50 + 2 * i, T32_CCM_S16(sec, 0xe0 + 0x18 * i));
	t32_tp_put16(cp + 0x3c, T32_CCM_S16(sec, 0x2b6));
	t32_tp_put16(cp + 0x3e, T32_CCM_S16(sec, 0x2ce));
	t32_tp_put16(cp + 0x40, T32_CCM_S16(sec, 0x2e6));
	t32_tp_put16(cp + 0x42, T32_CCM_S16(sec, 0x2fe));
	t32_tp_put16(cp + 0x44, T32_CCM_S16(sec, 0x24a));
	t32_tp_put16(cp + 0x46, T32_CCM_S16(sec, 0x262));
	t32_tp_put16(cp + 0x48, T32_CCM_S16(sec, 0x27e));
	t32_tp_put16(cp + 0x4a, T32_CCM_S16(sec, 0x296));

	/* tisp_ccm_calc_para_refresh: { hi, lo, scale, shift } of five ranges */
	{
		static const u8 ranges[5][4] = {	/* hi, lo, scale, shift offset in cp */
			{ 0x46, 0x44, 0x26, 0x24 }, { 0, 0, 0x2a, 0x28 }, { 0x4a, 0x48, 0x2e, 0x2c },
			{ 0x4e, 0x4c, 0x32, 0x30 }, { 0x3e, 0x3c, 0x36, 0x34 } };

		for (i = 0; i < 5; i++) {
			if (i == 1)
				d = (int)T32_CCM_S16(sec, 0x27c) - (int)T32_CCM_S16(sec, 0x27a);
			else
				d = (int)t32_tp_le16(cp + ranges[i][0]) - (int)t32_tp_le16(cp + ranges[i][1]);
			v = t32_ccm_bucket(d, &sh);
			t32_tp_put16(cp + ranges[i][2], v);
			cp[ranges[i][3]] = sh;
		}
		d = (int)t32_tp_le16(cp + 0x42) - (int)t32_tp_le16(cp + 0x40);
		v = t32_ccm_bucket(d, &sh);
		t32_tp_put16(cp + 0x3a, v);
		cp[0x38] = sh;
	}

	/* tisp_ccm_write_reg(0): all groups */
#define CP32(i)		t32_front_le32(cp + 4 * (i))
#define CP16(o)		t32_tp_le16(cp + (o))
	for (i = 0; i < 4; i++)
		T32_FWR(w, n, 0x9040 + 4 * i, (CP32(2 * i + 1) & 0x3fff) << 16 | (CP32(2 * i) & 0x3fff));
	T32_FWR(w, n, 0x9050, (sec[0x356] & 1U) << 16 | (sec[0x357] & 1U) << 20 | (CP32(8) & 0x3fff) |
		(sec[0x358] & 3U) << 24 | (sec[0x359] & 3U) << 28);
	T32_FWR(w, n, 0x9054, (sec[0x35a] & 1U) | (u32)cp[0x24] << 28 | (CP16(0x44) & 0x7ff) << 4 | (CP16(0x46) & 0x7ffU) << 16);
	T32_FWR(w, n, 0x9058, (CP16(0x26) & 0x3ff) | (u32)cp[0x28] << 28 | (sec[0x35b] & 1U) << 12 |
		(T32_CCM_S16(sec, 0x27a) & 0xfffU) << 16);
	T32_FWR(w, n, 0x905c, (CP16(0x2a) & 0x3ffU) << 12 | (T32_CCM_S16(sec, 0x27c) & 0xfff));
	T32_FWR(w, n, 0x9060, (sec[0x35c] & 1U) | (u32)cp[0x2c] << 28 | (CP16(0x48) & 0x7ff) << 4 | (CP16(0x4a) & 0x7ffU) << 16);
	T32_FWR(w, n, 0x9064, (CP16(0x2e) & 0x3ff) | (u32)cp[0x30] << 28 | (sec[0x35d] & 1U) << 12 | (CP16(0x4c) & 0x7ffU) << 16);
	T32_FWR(w, n, 0x9068, (CP16(0x32) & 0x3ffU) << 12 | (CP16(0x4e) & 0x7ff));
	T32_FWR(w, n, 0x906c, (CP16(0x3c) & 0x7ff) << 4 | (CP16(0x3e) & 0x7ffU) << 16 | (sec[0x35e] & 1U));
	T32_FWR(w, n, 0x9070, (CP16(0x42) & 0x7ffU) << 12 | (CP16(0x40) & 0x7ff));
	T32_FWR(w, n, 0x9074, (CP16(0x36) & 0x3ff) | (u32)cp[0x38] << 28 | (CP16(0x3a) & 0x3ffU) << 12 | (cp[0x34] & 0xfU) << 24);
	for (i = 0; i < 6; i++)
		T32_FWR(w, n, 0x9078 + 4 * i, (CP16(0x52 + 4 * i) & 0x3fffU) << 16 | (CP16(0x50 + 4 * i) & 0x3fff));
	T32_FWR(w, n, 0x9090, (u32)sec[0x34a] | (u32)T32_CCM_S16(sec, 0x350) << 24 | (T32_CCM_S16(sec, 0x34c) & 0xffU) << 8 |
		(u32)sec[0x34e] << 16);
	T32_FWR(w, n, 0x9094, (T32_CCM_S16(sec, 0x354) & 0xffU) << 8 | sec[0x352]);
	T32_FWR(w, n, 0x9010, 1);
	T32_FWR(w, n, 0x9000, T32_CCM_ID);
#undef CP32
#undef CP16
	return (int)n;
}

#endif /* TX_ISP_T32_CCM_H */
