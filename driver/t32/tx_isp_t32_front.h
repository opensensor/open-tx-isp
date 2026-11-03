/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 ISP front end: colour space conversion (CSC), chroma range (CSCCR)
 * and the ISP top block, initialised from the IQ bin as the vendor tisp does
 * at AddSensor (S4).  Register writes in the vendor's order.
 *
 * Reverse engineered flow (PRJ007 driver): tisp_csc_init / _update_para /
 * _write_reg, tisp_csccr_init / _update_para / _write_reg, tisp_top_init and
 * tisp_top_reg_cfg.  Parameter blocks are IQ bin sections 9 (CSC, 104
 * bytes), 10 (CSCCR, 20 bytes) and 0 (top, 100 bytes; one byte per control
 * bit).  Checked against the vendor's writes in the QEMU trace (run v1, cv8001
 * PRJ007 bin, 3840x2160 SRGGB10): host test tx_isp_t32_front_test.
 *
 * Only the default parameter path is built (CSC/CSCCR taken from the bin, no
 * mode table, no day/night switch, single pipeline, no WDR).
 */
#ifndef TX_ISP_T32_FRONT_H
#define TX_ISP_T32_FRONT_H

#ifndef __KERNEL__
#ifndef T32_HOST_U32
#define T32_HOST_U32
typedef uint32_t u32;
#endif
#ifndef T32_HOST_U8
#define T32_HOST_U8
typedef uint8_t u8;
typedef uint16_t u16;
#endif
#endif

#define T32_FRONT_ID		0x0134da11U
#define T32_FRONT_MAX_WRITES	48

/* IQ bin section indexes (tx_isp_t32_iq.h walks the table) */
#define T32_IQ_SEC_TOP		0
#define T32_IQ_SEC_CSC		9
#define T32_IQ_SEC_CSCCR	10

#define T32_CSC_BYTES		104U
#define T32_CSCCR_BYTES		20U
#define T32_TOP_BYTES		100U

struct t32_front_write {
	u32 reg, val;
};

/* input_mbus_fmt of the vendor ABI (tx-isp-videodev.h) */
#define T32_MBUS_SBGGR8		0x5200U
#define T32_MBUS_SRGGB12	0x520bU

/*
 * isp_mbus_to_bayer, for the Bayer codes of 8, 10 and 12 bits (0x5200 ..
 * 0x520b): bit depth class (0, 1, 2) << 16 | colour order (BGGR 1, GBRG 3,
 * GRBG 2, RGGB 0).  -1 for codes the front end does not take here.
 */
static inline int t32_mbus_to_bayer(u32 code)
{
	static const u8 order[4] = { 1, 3, 2, 0 };

	if (code < T32_MBUS_SBGGR8 || code > T32_MBUS_SRGGB12)
		return -1;
	return (int)((((code - T32_MBUS_SBGGR8) >> 2) << 16) | order[(code - T32_MBUS_SBGGR8) & 3]);
}

static inline u32 t32_front_le32(const u8 *p)
{
	return p[0] | (u32)p[1] << 8 | (u32)p[2] << 16 | (u32)p[3] << 24;
}

static inline int t32_front_s16(const u8 *p)
{
	return (short)(p[0] | p[1] << 8);
}

/* tisp_round_int64(x, sign, 6): arithmetic shift with the bit below rounding up */
static inline int t32_front_round6(int x)
{
	return (x >> 6) + ((x >> 5) & 1);
}

#define T32_FW(w, n, r, v) do { (w)[(n)].reg = (r); (w)[(n)].val = (v); (n)++; } while (0)

/*
 * The vendor loads the matrix of the selected mode (byte 0x5b of the section:
 * BT.601, BT.709, BT.2020, each full or limited range) into its working copy
 * at init, over the bin's own values; the bin supplies the mode and a few
 * offsets.  Rows are Y, Cb, Cr coefficients in Q16 (Y row sums to 65536),
 * then the offset and clip bytes of the mode.
 */
struct t32_csc_mode {
	int m[9];
	u8 tail[5];
};
static const struct t32_csc_mode t32_csc_modes[6] = {
	{ { 19595, 38470, 7471, -11058, -21710, 32768, 32768, -27439, -5329 }, { 0x80, 0x00, 0xff, 0x00, 0xff } },
	{ { 16829, 33039, 6416, -9714, -19071, 28784, 28784, -24103, -4681 }, { 0x80, 0x10, 0xeb, 0x10, 0xf0 } },
	{ { 13933, 46871, 4732, -7509, -25259, 32768, 32768, -29763, -3005 }, { 0x80, 0x00, 0xff, 0x00, 0xff } },
	{ { 11966, 40254, 4064, -6596, -22189, 28784, 28784, -26145, -2639 }, { 0x80, 0x10, 0xeb, 0x10, 0xf0 } },
	{ { 17216, 44433, 3886, -9151, -23617, 32768, 32768, -30133, -2635 }, { 0x80, 0x00, 0xff, 0x00, 0xff } },
	{ { 14786, 38160, 3338, -8038, -20746, 28784, 28784, -26469, -2315 }, { 0x80, 0x10, 0xeb, 0x10, 0xf0 } },
};

/* tisp_csc_init: sec = IQ section 9 (104 bytes); 8 writes plus the block id, 0 for a mode above 5 */
static inline unsigned int t32_csc_init(const u8 *sec, struct t32_front_write *w)
{
	short p[14];	/* the vendor's csc_cp: s16 at byte offsets 0 .. 0x1a */
	u8 b[0x22];
	unsigned int n = 0, i;

	const struct t32_csc_mode *md;

	if (sec[0x5b] > 5)
		return 0;
	md = &t32_csc_modes[sec[0x5b]];
	for (i = 0; i < sizeof(b); i++)
		b[i] = 0;
	b[0] = sec[0x58];
	b[1] = sec[0x59];
	b[2] = sec[0x5a];
	p[0] = p[1] = 0;
	p[2] = (short)t32_front_s16(sec + 0x4c);
	p[3] = (short)t32_front_s16(sec + 0x4e);
	p[4] = (short)t32_front_s16(sec + 0x50);
	p[5] = (short)t32_front_round6(md->m[0]);
	p[6] = (short)t32_front_round6(md->m[1]);
	p[7] = (short)t32_front_round6(md->m[2]);
	p[8] = (short)-t32_front_round6(md->m[3]);
	p[9] = (short)-t32_front_round6(md->m[4]);
	p[10] = (short)t32_front_round6(md->m[5]);
	p[11] = (short)t32_front_round6(md->m[6]);
	p[12] = (short)-t32_front_round6(md->m[7]);
	p[13] = (short)-t32_front_round6(md->m[8]);
	for (i = 0; i < 5; i++)
		b[0x1d + i] = md->tail[i];

	T32_FW(w, n, 0xb040, (b[1] & 7U) << 4 | (b[2] & 7U) << 8 | (b[0] & 1U) |
	       ((u32)p[2] & 0x1ff) << 16);
	T32_FW(w, n, 0xb044, ((u32)p[4] & 0x1ff) << 12 | ((u32)p[3] & 0x1ff));
	T32_FW(w, n, 0xb048, ((u32)p[6] & 0x3ff) << 10 | ((u32)p[7] & 0xff) << 20 | ((u32)p[5] & 0x1ff));
	T32_FW(w, n, 0xb04c, ((u32)p[9] & 0x1ff) << 10 | ((u32)p[10] & 0x3ff) << 20 | ((u32)p[8] & 0x1ff));
	T32_FW(w, n, 0xb050, ((u32)p[12] & 0x1ff) << 10 | ((u32)p[13] & 0x1ff) << 20 | ((u32)p[11] & 0x3ff));
	T32_FW(w, n, 0xb054, b[0x1c] | (u32)b[0x1d] << 8);
	T32_FW(w, n, 0xb058, b[0x1e] | (u32)b[0x1f] << 8 | (u32)b[0x20] << 16 | (u32)b[0x21] << 24);
	T32_FW(w, n, 0xb010, 0xffffffff);
	T32_FW(w, n, 0xb000, T32_FRONT_ID);
	return n;
}

/* CSCCR range pairs per mode (default, stretch, compress): min/max Y in, out, min/max C in, out */
static const u8 t32_csccr_modes[3][8] = {
	{ 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff },
	{ 0x10, 0xeb, 0x00, 0xff, 0x10, 0xf0, 0x00, 0xff },
	{ 0x00, 0xff, 0x10, 0xeb, 0x00, 0xff, 0x10, 0xf0 },
};

/* tisp_csccr_init: sec = IQ section 10 (20 bytes, mode in byte 4); -1 for modes not built / bad ranges */
static inline int t32_csccr_init(const u8 *sec, struct t32_front_write *w)
{
	const u8 *m;
	int y_in, y_out, c_in, c_out, k_y, k_c;
	unsigned int n = 0;

	if (sec[4] > 2)
		return -1;
	m = t32_csccr_modes[sec[4]];
	if (m[1] < m[0] || m[3] < m[2] || m[5] < m[4] || m[7] < m[6] || m[1] == m[0] || m[5] == m[4])
		return -1;
	y_in = m[1] - m[0];
	y_out = m[3] - m[2];
	c_in = m[5] - m[4];
	c_out = m[7] - m[6];
	k_y = (y_out * 0x400 + y_in / 2) / y_in;
	k_c = (c_out * 0x400 + c_in / 2) / c_in;
	if (k_y > 0x7ff)
		k_y = 0x7ff;
	if (k_c > 0x7ff)
		k_c = 0x7ff;
	T32_FW(w, n, 0x14040, (u32)k_y & 0x7ff);
	T32_FW(w, n, 0x14044, ((u32)y_out & 0xff) << 8 | (u32)m[2] << 16 | m[0]);
	T32_FW(w, n, 0x14050, (u32)k_c & 0x7ff);
	T32_FW(w, n, 0x14054, ((u32)(m[7] - 0x80) & 0x1ff) << 16 | ((u32)(m[6] - 0x80) & 0x1ff));
	T32_FW(w, n, 0x14010, 0xffffffff);
	T32_FW(w, n, 0x14000, T32_FRONT_ID);
	return (int)n;
}

/*
 * tisp_top_init (+ tisp_top_reg_cfg): sec = IQ section 0 (100 bytes), bayer
 * from t32_mbus_to_bayer.  Pipeline 0, single pipeline, no WDR.
 */
static inline unsigned int t32_top_init(const u8 *sec, u32 width, u32 height, u32 bayer,
					struct t32_front_write *w)
{
	u32 size = width << 16 | height, en = 0, ctl = 0, sta = 0;
	u32 idx = bayer & 0x1f, deir = idx < 4 ? 0 : 1;
	unsigned int n = 0, i;

	for (i = 0; i < 32; i++) {
		en |= (u32)(sec[4 + i] & 1) << i;
		ctl |= (u32)(sec[0x24 + i] & 1) << i;
	}
	for (i = 0; i < 10; i++)
		sta |= (u32)sec[0x44 + i] << i;
	if (deir)
		sta |= 4;
	T32_FW(w, n, 0x70, size);
	T32_FW(w, n, 0x80, size);
	T32_FW(w, n, 0x78, deir << 20 | idx | ((bayer & 0x3ffff) >> 16) << 8);
	T32_FW(w, n, 0x88, deir << 20 | ((bayer & 0x3ffff) >> 16) << 8);
	T32_FW(w, n, 0x48, 0xffffffff);
	T32_FW(w, n, 0x48, 0xfff7ffff);
	T32_FW(w, n, 0x100, 4);
	T32_FW(w, n, 0x40, en);
	T32_FW(w, n, 0x60, sta);
	T32_FW(w, n, 0x6c, ctl);
	return n;
}

#undef T32_FW

#endif /* TX_ISP_T32_FRONT_H */
