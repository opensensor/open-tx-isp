/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 local contrast enhancement (LCE, block 0xc000, plus the 0x25054..0x25070
 * smoothing words) from the IQ bin at AddSensor (S4 step 7): tisp_lce_init ->
 * tisp_lce_malloc_cfg, tisp_lce_size_para_calc, the register setup,
 * tisp_lce_curve_init_default -> tisp_lce_write_all_reg and
 * tisp_lce_write_ctrl_reg (with the 5x5 Gaussian of tisp_lce_gauss_lpf).
 *
 * IQ bin section 15 (712 bytes).  The grid geometry comes from the frame
 * size alone (blocks of 64 x 32 pixels; the 1920x1080 frame takes a
 * different, table driven path of the vendor that is not built here).  The
 * gain dependent strength tables are read at gain index 0 (the vendor's
 * initial state).  The default curve is the 20 byte pattern 0, 8 .. 0x38,
 * 0x40, 0x50 .. 0xf0 repeated 576 times, in both halves of a 0x5a00 byte
 * buffer (t32_lce_curve).
 *
 * Two DMA buffers are needed: the working buffer (0x26400 bytes; the four
 * address registers 0xc090 .. 0xc09c at +0, +0x9900, +0x13200, +0x1cb00)
 * and the curve buffer (0x5a00 bytes, register 0xc0a4); their physical
 * addresses are arguments.
 */
#ifndef TX_ISP_T32_LCE_H
#define TX_ISP_T32_LCE_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_LCE		15
#define T32_LCE_SEC_BYTES	712U
#define T32_LCE_ID		0x0134dacdU
#define T32_LCE_WORK_BYTES	0x26400U
#define T32_LCE_CURVE_BYTES	0x5a00U
#define T32_LCE_WRITES		33
#define T32_LCE_MAX_WRITES	33

/* the default curve: 576 x the 20 byte pattern, in out (0x2d00 bytes) */
static inline void t32_lce_curve(u8 *out)
{
	u8 pat[20];
	unsigned int i;

	for (i = 0; i < 8; i++)
		pat[i] = (u8)(8 * i);
	for (i = 0; i < 12; i++)
		pat[8 + i] = (u8)(0x40 + 16 * i);
	for (i = 0; i < 576; i++)
		memcpy(out + 20 * i, pat, 20);
}

/* tisp_lce_gauss_calc_exp: e^x in Q8 by 15 series terms with the vendor's 32 bit wrap */
static inline int t32_lce_exp(int x)
{
	int acc = 1 << 8, k;
	long long t = acc;

	for (k = 1; k <= 15; k++) {
		int f = (x / k) >> 2;

		t = (long long)((unsigned long long)t * (unsigned long long)(long long)f);
		t >>= 8;
		acc = (int)((unsigned int)acc + (unsigned int)t);
	}
	return acc;
}

/* tisp_lce_gauss_lpf: the 15 weights of a quadrant of the 9 x 9 kernel for strength sigma */
static inline void t32_lce_lpf(u32 sigma, u16 out[15])
{
	static u32 w[9][9];
	int dy, dx, tot = 0, r, c;
	u32 s2, u6 = 0xe;

	if (sigma < 9)
		sigma = 9;
	s2 = sigma * sigma;
	for (dy = 0; dy < 9; dy++) {
		for (dx = 0; dx < 9; dx++) {
			u32 r2 = (u32)((dy - 4) * (dy - 4) + (dx - 4) * (dx - 4));
			int e = t32_lce_exp((int)((r2 * 0x80000U + (s2 >> 1)) / s2));
			int v = e ? ((e >> 1) + 0x1000000) / e : 0;

			w[dy][dx] = (u32)v;
			tot += v;
		}
	}
	for (r = 0; r < 5; r++) {
		for (c = r; c < 5; c++) {
			unsigned long long num = (unsigned long long)(long long)(int)w[r][c] << 16;

			out[(r + u6 - c) & 0xff] = (u16)t32_tp_div64(num, (unsigned long long)(long long)tot);
		}
		u6 = (u6 + r - 5) & 0xff;
	}
}

/*
 * sec: section 15 (712 bytes, not modified), width/height of the frame,
 * work_pa / curve_pa: physical addresses of the two buffers.  Returns the
 * number of writes (33) or -1 for a refused case.
 */
static inline int t32_lce_init(const u8 *sec, u32 width, u32 height, u32 work_pa, u32 curve_pa,
			       struct t32_front_write *w)
{
	u32 q = height >> 1, r = q % 18, v = (width & 0x3f) >> 1, c2 = (width >> 5) & 0xfe;
	u32 c5 = ((q / 18) & 0x7f) * 2, l[9], p7[10], x, idx, n44[6];
	u16 g[15];
	unsigned int n = 0, i, j;

	if (t32_front_le32(sec) != T32_LCE_ID || sec[0x1fb] || (width == 1920 && height == 1080) ||
	    !c2 || !c5)
		return -1;
	n44[0] = v ? c2 + 2 : c2;
	n44[1] = v ? c2 + 1 : c2;
	n44[2] = c2;
	n44[3] = r ? c5 + 2 : c5;
	n44[4] = r ? c5 + 1 : c5;
	n44[5] = c5;
	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			l[3 * i + j] = n44[j] * n44[3 + i];
	if (l[8] > 0x4000) {
		idx = 3;
	} else if (l[8] > 0x2000) {
		idx = 4;
	} else if (l[8] > 0x1000) {
		idx = 5;
	} else if (l[8] > 0x800) {
		idx = 6;
	} else if (l[8] > 0x400) {
		idx = 7;
	} else if (l[8] > 0x200) {
		idx = 8;
	} else if (l[8] > 0x100) {
		idx = 9;
	} else {
		idx = 10;
	}
	x = 0x8000000U >> (idx - 3);
	for (i = 0; i < 9; i++) {
		if (!l[i])
			return -1;
		p7[i] = ((l[i] >> 1) + x) / l[i];
	}
	p7[9] = idx;

	/* tisp_lce_malloc_cfg */
	T32_FWR(w, n, 0xc090, work_pa);
	T32_FWR(w, n, 0xc094, work_pa + 0x9900);
	T32_FWR(w, n, 0xc098, work_pa + 0x13200);
	T32_FWR(w, n, 0xc09c, work_pa + 0x1cb00);
	T32_FWR(w, n, 0xc080, 3);
	/* tisp_lce_init */
	T32_FWR(w, n, 0xc040, c5 << 16 | c2);
	T32_FWR(w, n, 0xc044, (r & 0x1f) << 8 | (v & 0x3f) | (p7[9] & 0xf) << 20);
	T32_FWR(w, n, 0xc048, (p7[1] & 0x1fff) << 16 | (p7[0] & 0x1fff));
	T32_FWR(w, n, 0xc04c, p7[2] & 0x1fff);
	T32_FWR(w, n, 0xc050, (p7[4] & 0x1fff) << 16 | (p7[3] & 0x1fff));
	T32_FWR(w, n, 0xc054, p7[5] & 0x1fff);
	T32_FWR(w, n, 0xc058, (p7[7] & 0x1fff) << 16 | (p7[6] & 0x1fff));
	T32_FWR(w, n, 0xc05c, p7[8] & 0x1fff);
	T32_FWR(w, n, 0xc0a0, 0x280);
	T32_FWR(w, n, 0xc010, 1);
	/* tisp_lce_curve_init_default -> tisp_lce_write_all_reg */
	T32_FWR(w, n, 0xc0a4, curve_pa);
	/* tisp_lce_write_ctrl_reg */
	T32_FWR(w, n, 0xc068, (sec[0x1ac] & 1U) << 4 | (sec[0x1ad] & 3U) << 8 | (sec[0x1ab] & 1U) |
		(sec[0x1ae] & 1U) << 12 | (sec[0x1af] & 1U) << 16);
	for (i = 0; i < 4; i++)
		T32_FWR(w, n, 0xc06c + 4 * i, (t32_tp_le16(sec + 0xf0 + 0x16 * 2 * i) & 0x1ffU) << 16 |
			(t32_tp_le16(sec + 0xda + 0x16 * 2 * i) & 0x1ff));
	T32_FWR(w, n, 0xc07c, t32_tp_le16(sec + 0x18a) & 0x1ff);
	T32_FWR(w, n, 0xc060, (t32_tp_le16(sec + 0x1a2) & 0x3ffU) << 16 | (t32_tp_le16(sec + 0x1a0) & 0x3ff));
	T32_FWR(w, n, 0xc064, (t32_tp_le16(sec + 0x1a6) & 0x3ffU) << 16 | (t32_tp_le16(sec + 0x1a4) & 0x3ff));
	memset(g, 0, sizeof(g));
	if (sec[0x1b0])
		t32_lce_lpf(sec[0x1b0], g);
	for (i = 0; i < 7; i++)
		T32_FWR(w, n, 0x25054 + 4 * i, (u32)g[2 * i] | (u32)g[2 * i + 1] << 16);
	T32_FWR(w, n, 0x25070, g[14]);
	T32_FWR(w, n, 0xc010, 1);
	return (int)n;
}

#endif /* TX_ISP_T32_LCE_H */
