/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T41 AF statistics block (issue #179): register setup, DMA unpack, per-frame
 * metric and the two public queries, in plain C.  Rebuilt from the flow of the
 * OEM 1.2.5 module (tisp_af_set_hardware_param, tisp_af_get_statistics,
 * tisp_af_alogrithm, tisp_af_api_get_metric / get_statis_info), checked
 * against the SDK libt41-firmware disassembly: unaligned u32 parameter loads
 * (lwl/lwr), lhu for every u16 field, unsigned divisions, MIPS shift
 * semantics (amount & 31).  Pure functions without kernel state:
 * tests/tx_isp_t41_af_test.c builds them on the host.
 *
 * params: the 756-byte AF parameter block of the tuning bin
 *         (tparamsP + 0x17be8, packed little-endian, may be unaligned).
 * ws:     the 6432-byte AF workspace (af_info[ch]->workspace, u32 aligned):
 *         6 x u32[15][15] statistics, 0x1518 frame tag, 0x151c.. 255-entry
 *         metric history, 0x191c stats shift, 0x191e hw-init flag,
 *         0x191f history source.
 */
#ifndef TX_ISP_T41_AF_H
#define TX_ISP_T41_AF_H

#define T41_AF_PARAM_BYTES	756U
#define T41_AF_WS_BYTES		6432U
#define T41_AF_ZONES		15U
#define T41_AF_STATIS_BYTES	(6U * T41_AF_ZONES * T41_AF_ZONES * 4U)	/* 5400 */
#define T41_AF_BUF_BYTES	0x1000U
#define T41_AF_BUFS		4U
#define T41_AF_MAX_REGS		51U

/* workspace offsets */
#define T41_AF_WS_TAG		0x1518U
#define T41_AF_WS_HIST		0x151cU
#define T41_AF_WS_HIST_LAST	0x1914U
#define T41_AF_WS_SHIFT		0x191cU
#define T41_AF_WS_HW_DONE	0x191eU
#define T41_AF_WS_HIST_SRC	0x191fU

/* parameter block offsets */
#define T41_AF_P_YSTART		0x4cU
#define T41_AF_P_NY		0x4eU
#define T41_AF_P_XSTART		0x50U
#define T41_AF_P_NX		0x52U
#define T41_AF_P_XWIDTH		0x54U	/* u16[15] zone widths */
#define T41_AF_P_YHEIGHT	0x72U	/* u16[15] zone heights */
#define T41_AF_P_METRIC		0x40U
#define T41_AF_P_METRIC_ALT	0x3cU
#define T41_AF_P_WEIGHT		0x213U	/* u8[15][15] */

static inline uint32_t t41_af_rd8(const uint8_t *p, unsigned int o)
{
	return p[o];
}

static inline uint32_t t41_af_rd16(const uint8_t *p, unsigned int o)
{
	return (uint32_t)p[o] | ((uint32_t)p[o + 1] << 8);
}

static inline uint32_t t41_af_rd32(const uint8_t *p, unsigned int o)
{
	return t41_af_rd16(p, o) | (t41_af_rd16(p, o + 2) << 16);
}

static inline void t41_af_wr16(uint8_t *p, unsigned int o, uint32_t v)
{
	p[o] = (uint8_t)v;
	p[o + 1] = (uint8_t)(v >> 8);
}

static inline void t41_af_wr32(uint8_t *p, unsigned int o, uint32_t v)
{
	t41_af_wr16(p, o, v & 0xffffU);
	t41_af_wr16(p, o + 2, v >> 16);
}

/* OEM fix_point_mult2_32 (same arithmetic incl. the 32-bit wrap). */
static inline uint32_t t41_af_fpm2(uint32_t bits, uint32_t a, uint32_t b)
{
	uint32_t s = bits & 31U;
	uint32_t mask = 0xffffffffU >> ((0U - bits) & 31U);
	uint32_t ah = a >> s, bh = b >> s, al = a & mask, bl = b & mask;

	return al * bh + ah * bl + ((ah * bh) << s) + ((al * bl) >> s);
}

/*
 * Geometry sanity before the block is armed: the OEM divides by both zone
 * counts and indexes 15-entry tables with them, so 1..15 zones each and at
 * least 2 pixels per zone (the OEM subtracts 14 / 2 border pixels).
 */
static inline int t41_af_geometry_ok(const uint8_t *params, uint32_t width,
				     uint32_t height)
{
	uint32_t nx = t41_af_rd16(params, T41_AF_P_NX);
	uint32_t ny = t41_af_rd16(params, T41_AF_P_NY);
	uint32_t xs = t41_af_rd16(params, T41_AF_P_XSTART);
	uint32_t ys = t41_af_rd16(params, T41_AF_P_YSTART);

	if (nx < 1 || nx > T41_AF_ZONES || ny < 1 || ny > T41_AF_ZONES)
		return 0;
	if (width < xs + 14U + 2U * nx || height < ys + 2U + 2U * ny)
		return 0;
	return 1;
}

static inline uint32_t t41_af_even_zone(uint32_t span, uint32_t n)
{
	uint32_t q = (uint32_t)((int32_t)span / (int32_t)n);
	uint32_t v = q & 0xffffU;

	if (q & 1U)
		v = (v - 1U) & 0xffffU;
	return v;
}

static inline uint32_t t41_af_pack16x4(const uint8_t *p, unsigned int a,
				       unsigned int b, unsigned int c,
				       unsigned int d)
{
	return t41_af_rd16(p, a) | (t41_af_rd16(p, b) << 8) |
	       (t41_af_rd16(p, c) << 16) | (t41_af_rd16(p, d) << 24);
}

static inline uint32_t t41_af_pack16x3(const uint8_t *p, unsigned int a,
				       unsigned int b, unsigned int c)
{
	return t41_af_rd16(p, a) | (t41_af_rd16(p, b) << 8) |
	       (t41_af_rd16(p, c) << 16);
}

static inline uint32_t t41_af_pack8x8(const uint8_t *p, unsigned int o)
{
	/* byte o in bits 0..7, bytes o+1..o+7 at nibble steps 4..28 */
	uint32_t v = t41_af_rd8(p, o);
	unsigned int i;

	for (i = 1; i < 8; i++)
		v |= t41_af_rd8(p, o + i) << (4U * i);
	return v;
}

/*
 * OEM tisp_af_set_hardware_param: register (offset, value) pairs in OEM
 * write order.  The zone grid (0x1a004..0x1a034) is computed and written
 * once per workspace (flag ws+0x191e); 0x1a000 = 1 (block on, OEM
 * system_reg_write_af) precedes 0x1a038.  Returns the pair count.
 * The caller checks t41_af_geometry_ok() first.
 */
static inline unsigned int t41_af_hw_param(uint8_t *params, uint8_t *ws,
					   uint32_t width, uint32_t height,
					   uint32_t regs[T41_AF_MAX_REGS][2])
{
	unsigned int n = 0, i;
	uint32_t v;

#define T41_AF_REG(r, val) do { regs[n][0] = (r); regs[n][1] = (val); n++; } while (0)
	if (!ws[T41_AF_WS_HW_DONE]) {
		uint32_t nx = t41_af_rd16(params, T41_AF_P_NX);
		uint32_t ny = t41_af_rd16(params, T41_AF_P_NY);
		uint32_t xs = t41_af_rd16(params, T41_AF_P_XSTART);
		uint32_t ys = t41_af_rd16(params, T41_AF_P_YSTART);
		uint32_t zw = t41_af_even_zone((width & 0xffffU) - xs - 14U, nx);
		uint32_t zh;

		ws[T41_AF_WS_HW_DONE] = 1;
		for (i = 0; i < nx; i++)
			t41_af_wr16(params, T41_AF_P_XWIDTH + 2U * i, zw);
		zh = t41_af_even_zone((height & 0xffffU) - ys - 2U, ny);
		for (i = 0; i < ny; i++)
			t41_af_wr16(params, T41_AF_P_YHEIGHT + 2U * i, zh);

		T41_AF_REG(0x1a004, (nx << 28) | (xs << 16) | ys | (ny << 12));
		for (i = 0; i < 7; i++)
			T41_AF_REG(0x1a008 + 4U * i, t41_af_rd32(params, 0x54 + 4U * i));
		T41_AF_REG(0x1a024, t41_af_rd16(params, 0x70));
		T41_AF_REG(0x1a028, t41_af_pack16x4(params, 0x72, 0x74, 0x76, 0x78));
		T41_AF_REG(0x1a02c, t41_af_pack16x4(params, 0x7a, 0x7c, 0x7e, 0x80));
		T41_AF_REG(0x1a030, t41_af_pack16x4(params, 0x82, 0x84, 0x86, 0x88));
		T41_AF_REG(0x1a034, t41_af_pack16x3(params, 0x8a, 0x8c, 0x8e));
	}
	T41_AF_REG(0x1a000, 1);
	v = t41_af_rd16(params, 0x90) | (t41_af_rd8(params, 0x1fe) << 4) |
	    (t41_af_rd8(params, 0x1ff) << 5) | (t41_af_rd8(params, 0x200) << 6) |
	    (t41_af_rd8(params, 0x201) << 7) | (t41_af_rd8(params, 0x202) << 8) |
	    (t41_af_rd16(params, 0x92) << 16);
	T41_AF_REG(0x1a038, v);
	T41_AF_REG(0x1a03c, t41_af_pack8x8(params, 0x203));
	T41_AF_REG(0x1a040, t41_af_rd32(params, 0x118));
	T41_AF_REG(0x1a044, t41_af_rd32(params, 0x11c));
	T41_AF_REG(0x1a048, t41_af_rd16(params, 0x120));
	T41_AF_REG(0x1a04c, t41_af_rd32(params, 0x142));
	T41_AF_REG(0x1a050, t41_af_rd32(params, 0x146));
	T41_AF_REG(0x1a054, t41_af_rd16(params, 0x14a));
	T41_AF_REG(0x1a058, t41_af_rd16(params, 0x16c) | (t41_af_rd16(params, 0x170) << 16));
	T41_AF_REG(0x1a05c, t41_af_rd32(params, 0x172));
	T41_AF_REG(0x1a060, t41_af_rd16(params, 0x176) | (t41_af_rd16(params, 0x17a) << 16));
	T41_AF_REG(0x1a064, t41_af_rd32(params, 0x17c));
	T41_AF_REG(0x1a068, t41_af_rd16(params, 0x1a0) | (t41_af_rd16(params, 0x1a4) << 16));
	T41_AF_REG(0x1a06c, t41_af_rd32(params, 0x1a6));
	T41_AF_REG(0x1a070, t41_af_rd16(params, 0x1aa) | (t41_af_rd16(params, 0x1ae) << 16));
	T41_AF_REG(0x1a074, t41_af_rd32(params, 0x1b0));
	T41_AF_REG(0x1a078, t41_af_pack16x3(params, 0x122, 0x124, 0x126));
	T41_AF_REG(0x1a07c, t41_af_pack16x3(params, 0x12a, 0x12c, 0x12e));
	T41_AF_REG(0x1a080, t41_af_pack16x3(params, 0x14c, 0x14e, 0x150));
	T41_AF_REG(0x1a084, t41_af_pack16x3(params, 0x154, 0x156, 0x158));
	T41_AF_REG(0x1a088, t41_af_pack16x3(params, 0x180, 0x182, 0x184));
	T41_AF_REG(0x1a08c, t41_af_pack16x3(params, 0x188, 0x18a, 0x18c));
	T41_AF_REG(0x1a090, t41_af_pack16x3(params, 0x1b4, 0x1b6, 0x1b8));
	T41_AF_REG(0x1a094, t41_af_pack16x3(params, 0x1bc, 0x1be, 0x1c0));
	T41_AF_REG(0x1a098, t41_af_pack16x4(params, 0x128, 0x130, 0x152, 0x15a));
	T41_AF_REG(0x1a09c, t41_af_pack16x4(params, 0x186, 0x18e, 0x1ba, 0x1c2));
	T41_AF_REG(0x1a0a0, t41_af_pack16x4(params, 0x132, 0x134, 0x136, 0x138));
	T41_AF_REG(0x1a0a4, t41_af_pack16x4(params, 0x15c, 0x15e, 0x160, 0x162));
	T41_AF_REG(0x1a0a8, t41_af_pack16x4(params, 0x190, 0x192, 0x194, 0x196));
	T41_AF_REG(0x1a0ac, t41_af_pack16x4(params, 0x1c4, 0x1c6, 0x1c8, 0x1ca));
	T41_AF_REG(0x1a0b0, t41_af_pack8x8(params, 0x20b));
	T41_AF_REG(0x1a0b4, t41_af_pack16x4(params, 0x13a, 0x13c, 0x164, 0x166));
	T41_AF_REG(0x1a0b8, t41_af_pack16x4(params, 0x198, 0x19a, 0x1cc, 0x1ce));
	T41_AF_REG(0x1a0bc, t41_af_rd32(params, 0x13e));
	T41_AF_REG(0x1a0c0, t41_af_rd32(params, 0x168));
	T41_AF_REG(0x1a0c4, t41_af_rd32(params, 0x19c));
	T41_AF_REG(0x1a0c8, t41_af_rd32(params, 0x1d0));
#undef T41_AF_REG
	return n;
}

/* OEM CSWTCH.12: DMA row length in 8-byte units for 1..15 zones per row. */
static const uint8_t t41_af_row_units[15] = {
	3, 5, 7, 9, 11, 13, 15, 17, 20, 22, 24, 26, 28, 30, 32,
};

static inline uint32_t *t41_af_ws32(uint8_t *ws, unsigned int o)
{
	return (uint32_t *)(void *)(ws + o);
}

/*
 * OEM tisp_af_get_statistics: unpack one DMA buffer (zones of 136 bits, 4
 * zones per 17 words, rows of t41_af_row_units[nx-1] * 8 bytes) into the
 * six 15x15 u32 tables of the workspace.  The caller stores the frame tag
 * (0x1a120) and clears the buffer.  dma: 1024 words.
 */
static inline void t41_af_unpack(const uint8_t *params, uint8_t *ws,
				 const uint32_t *dma)
{
	uint32_t nx = t41_af_rd16(params, T41_AF_P_NX);
	uint32_t ny = t41_af_rd16(params, T41_AF_P_NY);
	uint32_t units = ((nx - 1U) & 0xffffU) < 15U ?
		t41_af_row_units[(nx - 1U) & 0xffffU] : 32U;
	uint32_t y, x, row = 0, f[6], k;

	if (nx > T41_AF_ZONES)
		nx = T41_AF_ZONES;
	if (ny > T41_AF_ZONES)
		ny = T41_AF_ZONES;
	for (y = 0; y < ny; y++, row += 2U * units) {
		for (x = 0; x < nx; x++) {
			const uint32_t *w = dma + 4U * x + row + x / 4U;
			uint32_t w0 = w[0], w1 = w[1], w2 = w[2], w3 = w[3], w4 = w[4];
			uint32_t idx = y * T41_AF_ZONES + x;

			switch (x & 3U) {
			case 0:
				f[0] = w0 & 0x7fffffU;
				f[1] = (w1 & 0x3fffU) << 9 | w0 >> 23;
				f[2] = (w2 & 0x1fU) << 18 | w1 >> 14;
				f[3] = (w2 & 0xfffffffU) >> 5;
				f[4] = (w3 & 0xfffffU) << 4 | w2 >> 28;
				f[5] = (w4 & 0xfU) << 12 | w3 >> 20;
				break;
			case 1:
				f[0] = (w0 & 0x7fffffffU) >> 8;
				f[1] = (w1 & 0x3fffffU) << 1 | w0 >> 31;
				f[2] = (w2 & 0x1fffU) << 10 | w1 >> 22;
				f[3] = (w3 & 0xfU) << 19 | w2 >> 13;
				f[4] = (w3 & 0xfffffffU) >> 4;
				f[5] = (w4 & 0xfffU) << 4 | w3 >> 28;
				break;
			case 2:
				f[0] = (w1 & 0x7fU) << 16 | w0 >> 16;
				f[1] = (w1 & 0x3fffffffU) >> 7;
				f[2] = (w2 & 0x1fffffU) << 2 | w1 >> 30;
				f[3] = (w3 & 0xfffU) << 11 | w2 >> 21;
				f[4] = (w4 & 0xfU) << 20 | w3 >> 12;
				f[5] = (w4 & 0xfffffU) >> 4;
				break;
			default:
				f[0] = (w1 & 0x7fffU) << 8 | w0 >> 24;
				f[1] = (w2 & 0x3fU) << 17 | w1 >> 15;
				f[2] = (w2 & 0x1fffffffU) >> 6;
				f[3] = (w3 & 0xfffffU) << 3 | w2 >> 29;
				f[4] = (w4 & 0xfffU) << 12 | w3 >> 20;
				f[5] = (w4 & 0xfffffffU) >> 12;
				break;
			}
			for (k = 0; k < 6; k++)
				*t41_af_ws32(ws, 4U * (k * T41_AF_ZONES * T41_AF_ZONES + idx)) = f[k];
		}
	}
}

/*
 * OEM tisp_af_alogrithm: weighted, blended sharpness over the zone grid,
 * metric history in the parameter block (words 0..14 shift register,
 * 0x3c/0x40/0x44/0x48 results) and the 255-entry history in the workspace.
 * Returns the weight sum; 0 = no update (the OEM divides by zero there).
 */
static inline uint32_t t41_af_algorithm(uint8_t *params, uint8_t *ws)
{
	uint32_t c_iir0 = t41_af_rd16(params, 0x1d4);
	uint32_t c_iir1 = t41_af_rd16(params, 0x1d6);
	uint32_t c_out0 = t41_af_rd16(params, 0x1d8);
	uint32_t c_out1 = t41_af_rd16(params, 0x1da);
	uint32_t bits = t41_af_rd16(params, 0x1dc) & 31U;
	uint32_t ny = t41_af_rd16(params, T41_AF_P_NY);
	uint32_t nx = t41_af_rd16(params, T41_AF_P_NX);
	uint32_t ss = t41_af_rd16(ws, T41_AF_WS_SHIFT) & 31U;
	uint32_t one = 1U << bits;
	uint32_t half = (uint32_t)((int32_t)one / 2);
	uint32_t y, x, i, sh = 0, sv = 0, sw = 0, mh, mv, metric, alt, n;
	uint8_t src;

	if (nx > T41_AF_ZONES || ny > T41_AF_ZONES)
		return 0;
	for (y = 0; y < ny; y++) {
		for (x = 0; x < nx; x++) {
			uint32_t z = y * T41_AF_ZONES + x;
			uint32_t a0 = *t41_af_ws32(ws, 4U * z) >> ss;
			uint32_t a1 = *t41_af_ws32(ws, 900U + 4U * z) >> ss;
			uint32_t a2 = *t41_af_ws32(ws, 1800U + 4U * z) >> ss;
			uint32_t a3 = *t41_af_ws32(ws, 2700U + 4U * z) >> ss;
			uint32_t w = params[T41_AF_P_WEIGHT + y * T41_AF_ZONES + x];
			uint32_t h = t41_af_fpm2(bits, a2 << bits, c_iir0) +
				     t41_af_fpm2(bits, a0 << bits, one - c_iir0);
			uint32_t v = t41_af_fpm2(bits, a3 << bits, c_iir1) +
				     t41_af_fpm2(bits, a1 << bits, one - c_iir1);

			sh += ((half + h) >> bits) * w;
			sv += ((v + half) >> bits) * w;
			sw += w;
		}
	}
	if (!sw)
		return 0;
	mh = sh / sw;
	mv = sv / sw;
	metric = (t41_af_fpm2(bits, mh << bits, c_out0) +
		  t41_af_fpm2(bits, mv << bits, c_out1)) >> bits;
	alt = (t41_af_fpm2(bits, (sh >> 3) << bits, c_out0) +
	       t41_af_fpm2(bits, (sv >> 3) << bits, c_out1)) >> bits;
	for (i = 0; i < 14; i++)
		t41_af_wr32(params, 4U * i, t41_af_rd32(params, 4U * i + 4U));
	t41_af_wr32(params, 0x38, metric);
	t41_af_wr32(params, 0x3c, alt);
	n = nx * ny;
	t41_af_wr32(params, 0x44, n * mh);
	t41_af_wr32(params, 0x40, n * metric);
	t41_af_wr32(params, 0x48, n * mv);

	src = ws[T41_AF_WS_HIST_SRC];
	if (src > 3)
		return sw;
	for (i = 0; i < 254; i++)
		*t41_af_ws32(ws, T41_AF_WS_HIST + 4U * i) =
			*t41_af_ws32(ws, T41_AF_WS_HIST + 4U * i + 4U);
	*t41_af_ws32(ws, T41_AF_WS_HIST_LAST) =
		src == 0 ? alt : t41_af_rd32(params, 0x40U + 4U * (src - 1U));
	return sw;
}

/* OEM tisp_af_api_get_metric: { metric >> s, alt >> s, (u8) frame tag }. */
static inline void t41_af_metric(const uint8_t *params, uint8_t *ws,
				 uint32_t shift, uint32_t out[3])
{
	shift &= 31U;
	out[0] = t41_af_rd32(params, T41_AF_P_METRIC) >> shift;
	out[1] = t41_af_rd32(params, T41_AF_P_METRIC_ALT) >> shift;
	out[2] = *t41_af_ws32(ws, T41_AF_WS_TAG) & 0xffU;
}

#endif
