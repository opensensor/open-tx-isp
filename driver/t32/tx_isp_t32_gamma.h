/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 gamma: the 129 point curve from the IQ bin, as the vendor tisp does at
 * AddSensor (S4 step 5).
 *
 * Reverse engineered flow (PRJ007 driver): tisp_gamma_init ->
 * tisp_gamma_interp_by_ev (strength byte at EV 0), tisp_gamma_update_curve
 * (curve from the look-up table payload behind IQ bin section 13),
 * tisp_gamma_strength_transform (curve blended with the linear ramp by the
 * strength), tisp_gamma_write_lut_rgb (the same 128 packed pairs through the
 * three LUT ports 0x32040/0x32044, 0x32080/0x32084, 0x32060/0x32064).
 *
 * Section 13 (92 bytes): +0 block id, +0x18 twelve u32 EV knots, +0x48 strength
 * mode (0: 255, 1: interpolated over the knots, other: byte +0x49), +0x4a
 * twelve strength bytes, +0x5a number of curves in the payload.
 * Only the single curve form (block id below 0x134ff91, 0x102 bytes of curve
 * payload) is built; the multi-curve form selected by EV is refused.
 */
#ifndef TX_ISP_T32_GAMMA_H
#define TX_ISP_T32_GAMMA_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_GAMMA		13
#define T32_GAMMA_SEC_BYTES	92U
#define T32_GAMMA_CURVE_BYTES	0x102U
#define T32_GAMMA_POINTS	129U
#define T32_GAMMA_MAX_WRITES	(3 + 3 * 128 + 3)

/* strength at EV 0 (tisp_gamma_interp_by_ev); 0xffffffff for knots that are not increasing */
static inline u32 t32_gamma_strength(const u8 *sec)
{
	unsigned int i;
	u32 knot, lo, d, iv;

	if (sec[0x48] == 0)
		return 0xff;
	if (sec[0x48] != 1)
		return sec[0x49];
	for (i = 0; i < 12; i++) {
		knot = t32_front_le32(sec + 0x18 + 4 * i);
		if (0 < knot) {
			if (i == 0)
				return sec[0x4a];
			lo = t32_front_le32(sec + 0x18 + 4 * (i - 1));
			d = knot - lo;
			iv = 0U - lo;
			if (d == 0)
				return 0xffffffffU;
			return (sec[0x49 + i] * (d - iv) + sec[0x4a + i] * iv + (d >> 1)) / d;
		}
	}
	return sec[0x55];
}

/* sec: section 13, lut: payload behind it; the 129 writes of 128 pairs follow */
static inline int t32_gamma_init(const u8 *sec, const u8 *lut, u32 lutbytes,
				 struct t32_front_write *w)
{
	static const u32 ports[3][2] = { { 0x32040, 0x32044 }, { 0x32080, 0x32084 }, { 0x32060, 0x32064 } };
	u16 cur[T32_GAMMA_POINTS], out[T32_GAMMA_POINTS];
	u32 k, acc = 0, v;
	unsigned int n = 0, i, p;

	if (t32_front_le32(sec) >= 0x134ff91U || lutbytes < T32_GAMMA_CURVE_BYTES || sec[0x5a] < 1)
		return -1;
	for (i = 0; i < T32_GAMMA_POINTS; i++)
		cur[i] = lut[2 * i] | lut[2 * i + 1] << 8;
	k = t32_gamma_strength(sec);
	if (k > 0xff)
		return -1;
	k += k >> 7;
	for (i = 0; i < 128; i++) {
		v = (u32)cur[i] * k + (acc << 5) + 128;	/* tisp_round_int64(.., 8) */
		out[i] = (u16)(v >> 8);
		acc += 0x100 - k;
	}
	v = (u32)cur[128] * k + (0x100 - k) * 0xfff + 128;
	out[128] = (u16)(v >> 8);
	for (p = 0; p < 3; p++)
		T32_FWR(w, n, ports[p][0], 0x101);
	for (i = 0; i < 128; i++)
		for (p = 0; p < 3; p++)
			T32_FWR(w, n, ports[p][1], (u32)(out[i + 1] & 0xfff) << 12 | (out[i] & 0xfff));
	for (p = 0; p < 3; p++)
		T32_FWR(w, n, ports[p][0], 0x7f0102);
	return (int)n;
}

#endif /* TX_ISP_T32_GAMMA_H */
