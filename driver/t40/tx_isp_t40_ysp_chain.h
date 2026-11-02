/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 YSP (luma sharpen) chain in plain C (#85).
 *
 * Replaces the literal mips2c bodies of the OEM tisp_ysp_wdr_en, tisp_ysp_intp, tisp_ysp_noref_reg_cfg, tisp_ysp_ref_reg_cfg and
 * tisp_ysp_reg_trig.  The OEM keeps three blocks per ISP channel:
 *   par   3432 bytes, the YSP parameter record (copied from the tuning file),
 *   comb  420 bytes, a table of 105 pointers into par (tisp_ysp_wdr_en fills it, here t40_ysp_comb_fill; one offset set for the normal and one for the WDR layout),
 *   intp  146 bytes, the gain-interpolated values (tisp_ysp_intp output, input of tisp_ysp_ref_reg_cfg).
 * Register block of channel ch: (ch + 0x98) << 9.  The layout of the three blocks is kept, so the Unicorn check
 * (tools/ko_emu/diff_ysp_chain.py: OEM instructions vs this file built for mipsel) sees identical memory and identical register writes.
 * ref_reg_cfg contains eight "ramps": eight values start + k * step, each clamped to an end value (min for rising, max for falling ramps), the
 * second half continuing from the clamped fourth value; the end value is capped first (rising: upper cap, falling: floor 0 where the OEM does).
 * Needs from the includer: uint32_t, t40_ysp_reg_write(reg, val), tisp_simple_intp_int8/int16(int32_t, int32_t, void *).
 */
#ifndef TX_ISP_T40_YSP_CHAIN_H
#define TX_ISP_T40_YSP_CHAIN_H

#define YSP_U32(a) (*(uint32_t *)(uintptr_t)(a))
#define YSP_U16(a) (*(uint16_t *)(uintptr_t)(a))
#define YSP_U8(a)  (*(uint8_t *)(uintptr_t)(a))
/* unaligned little-endian word (the OEM uses an lwl/lwr pair) */
#define YSP_U32U(a) ((uint32_t)YSP_U8(a) | ((uint32_t)YSP_U8((a) + 1) << 8) | ((uint32_t)YSP_U8((a) + 2) << 16) | ((uint32_t)YSP_U8((a) + 3) << 24))

#define T40_YSP_PAR_SIZE  3432U
#define T40_YSP_COMB_SIZE 420U
#define T40_YSP_INTP_SIZE 146U

/* tisp_ysp_wdr_en: comb[i] = par + offset (i = 0..104); [0] normal, [1] WDR layout */
static const uint16_t t40_ysp_comb_off[2][105] = {
	{
		0x000b, 0x0016, 0x0022, 0x0038, 0x004e, 0x0064, 0x0007, 0x0072,
		0x0088, 0x00a2, 0x00aa, 0x00b2, 0x00bd, 0x00c8, 0x00d3, 0x00de,
		0x00e9, 0x00f4, 0x00ff, 0x010a, 0x0115, 0x0120, 0x012b, 0x0136,
		0x0141, 0x014c, 0x0157, 0x0172, 0x0175, 0x0180, 0x018b, 0x0196,
		0x01a1, 0x01ac, 0x01b7, 0x01c2, 0x01cd, 0x01eb, 0x01f6, 0x020c,
		0x0222, 0x022d, 0x0238, 0x0243, 0x024e, 0x0259, 0x0264, 0x026f,
		0x027a, 0x0285, 0x0290, 0x029b, 0x02a6, 0x02ba, 0x02d0, 0x02e6,
		0x02fc, 0x0312, 0x0328, 0x033e, 0x0354, 0x036a, 0x0380, 0x0396,
		0x03ac, 0x03c2, 0x03d8, 0x03ee, 0x0404, 0x041a, 0x0425, 0x0430,
		0x0446, 0x045c, 0x047c, 0x048a, 0x04a0, 0x04b6, 0x04cc, 0x04e2,
		0x04f8, 0x050e, 0x0524, 0x053a, 0x0550, 0x0566, 0x057c, 0x0592,
		0x05a8, 0x05be, 0x05d4, 0x05ea, 0x05f6, 0x060c, 0x0622, 0x0642,
		0x064c, 0x0659, 0x0668, 0x067e, 0x0694, 0x06aa, 0x06b5, 0x06c0,
		0x06cb,
	},
	{
		0x06d6, 0x06e1, 0x06ec, 0x0702, 0x0718, 0x072e, 0x0739, 0x073e,
		0x0754, 0x076a, 0x0772, 0x077a, 0x0785, 0x0790, 0x079b, 0x07a6,
		0x07b1, 0x07bc, 0x07c7, 0x07d2, 0x07dd, 0x07e8, 0x07f3, 0x07fe,
		0x0809, 0x0814, 0x081f, 0x082a, 0x082d, 0x0838, 0x0843, 0x084e,
		0x0859, 0x0864, 0x086f, 0x087a, 0x0885, 0x0890, 0x089c, 0x08b2,
		0x08c8, 0x08d3, 0x08de, 0x08e9, 0x08f4, 0x08ff, 0x090a, 0x0915,
		0x0920, 0x092b, 0x0936, 0x0941, 0x094c, 0x0958, 0x096e, 0x0984,
		0x099a, 0x09b0, 0x09c6, 0x09dc, 0x09f2, 0x0a08, 0x0a1e, 0x0a34,
		0x0a4a, 0x0a60, 0x0a76, 0x0a8c, 0x0aa2, 0x0ab8, 0x0ac3, 0x0ace,
		0x0ae4, 0x0afa, 0x0b1a, 0x0b22, 0x0b38, 0x0b4e, 0x0b64, 0x0b7a,
		0x0b90, 0x0ba6, 0x0bbc, 0x0bd2, 0x0be8, 0x0bfe, 0x0c14, 0x0c2a,
		0x0c40, 0x0c56, 0x0c6c, 0x0c82, 0x0c8e, 0x0ca4, 0x0cba, 0x0cda,
		0x0ce4, 0x0cef, 0x0cfa, 0x0d10, 0x0d26, 0x0d3c, 0x0d47, 0x0d52,
		0x0d5d,
	},
};

static void t40_ysp_comb_fill(uintptr_t par, uintptr_t comb, uint32_t wdr)
{
	const uint16_t *off = t40_ysp_comb_off[wdr != 0];
	unsigned int i;

	for (i = 0; i < 105; i++)
		YSP_U32(comb + 4 * i) = (uint32_t)(par + off[i]);
}

/* tisp_ysp_intp: 96 interpolated values in the order of the OEM calls { comb entry, offset in intp, width in bits } */
static const struct { uint8_t comb, out, bits; } t40_ysp_intp_tab[96] = {
	{ 97, 0, 8 }, { 7, 2, 16 }, { 98, 4, 16 }, { 99, 6, 16 },
	{ 100, 8, 16 }, { 101, 10, 8 }, { 102, 11, 8 }, { 103, 12, 8 },
	{ 104, 13, 8 }, { 0, 14, 8 }, { 1, 15, 8 }, { 2, 16, 16 },
	{ 3, 18, 16 }, { 4, 20, 16 }, { 5, 22, 8 }, { 37, 23, 8 },
	{ 69, 24, 8 }, { 70, 25, 8 }, { 71, 26, 16 }, { 72, 28, 16 },
	{ 38, 30, 16 }, { 91, 32, 8 }, { 92, 34, 16 }, { 93, 36, 16 },
	{ 96, 144, 8 }, { 39, 38, 16 }, { 28, 40, 8 }, { 29, 41, 8 },
	{ 30, 42, 8 }, { 31, 43, 8 }, { 32, 44, 8 }, { 33, 45, 8 },
	{ 34, 46, 8 }, { 35, 47, 8 }, { 36, 48, 8 }, { 53, 50, 16 },
	{ 54, 52, 16 }, { 55, 54, 16 }, { 56, 56, 16 }, { 57, 58, 16 },
	{ 58, 60, 16 }, { 59, 62, 16 }, { 60, 64, 16 }, { 61, 66, 16 },
	{ 62, 68, 16 }, { 63, 70, 16 }, { 64, 72, 16 }, { 65, 74, 16 },
	{ 66, 76, 16 }, { 67, 78, 16 }, { 68, 80, 16 }, { 11, 82, 8 },
	{ 12, 83, 8 }, { 13, 84, 8 }, { 14, 85, 8 }, { 15, 86, 8 },
	{ 16, 87, 8 }, { 17, 88, 8 }, { 18, 89, 8 }, { 19, 90, 8 },
	{ 20, 91, 8 }, { 21, 92, 8 }, { 22, 93, 8 }, { 23, 94, 8 },
	{ 24, 95, 8 }, { 25, 96, 8 }, { 26, 97, 8 }, { 75, 98, 16 },
	{ 76, 100, 16 }, { 77, 102, 16 }, { 78, 104, 16 }, { 79, 106, 16 },
	{ 80, 108, 16 }, { 81, 110, 16 }, { 82, 112, 16 }, { 83, 114, 16 },
	{ 84, 116, 16 }, { 85, 118, 16 }, { 86, 120, 16 }, { 87, 122, 16 },
	{ 88, 124, 16 }, { 89, 126, 16 }, { 90, 128, 16 }, { 40, 130, 8 },
	{ 41, 131, 8 }, { 42, 132, 8 }, { 43, 133, 8 }, { 44, 134, 8 },
	{ 45, 135, 8 }, { 46, 136, 8 }, { 47, 137, 8 }, { 48, 138, 8 },
	{ 49, 139, 8 }, { 50, 140, 8 }, { 51, 141, 8 }, { 8, 142, 16 },
};

static void t40_ysp_intp(uintptr_t comb, uintptr_t intp, uint32_t gain)
{
	int32_t hi = (int32_t)gain >> 16, lo = (int32_t)(gain & 0xffffU);
	unsigned int i;

	for (i = 0; i < 96; i++) {
		void *tab = (void *)(uintptr_t)YSP_U32(comb + 4 * t40_ysp_intp_tab[i].comb);

		if (t40_ysp_intp_tab[i].bits == 8)
			YSP_U8(intp + t40_ysp_intp_tab[i].out) = (uint8_t)tisp_simple_intp_int8(hi, lo, tab);
		else
			YSP_U16(intp + t40_ysp_intp_tab[i].out) = (uint16_t)tisp_simple_intp_int16(hi, lo, tab);
	}
}

static inline int32_t t40_ysp_reg_trig(uint32_t ch)
{
	return t40_ysp_reg_write(((ch + 0x98U) << 9) + 0x78U, 1);
}

#define YSP_CB(i, k) ((uint32_t)YSP_U8(YSP_U32(comb + 4 * (i)) + (k)))	/* byte k of the table comb[i] points to */
#define YSP_CW(i, k) YSP_U32U(YSP_U32(comb + 4 * (i)) + (k))

static int32_t t40_ysp_noref_reg_cfg(uint32_t ch, uintptr_t par, uintptr_t comb)
{
	uint32_t rb = (ch + 0x98U) << 9;
	int32_t rv = 0;

#define P(o) ((uint32_t)YSP_U8(par + (o)))
#define PW(o) YSP_U32U(par + (o))
#define W(off, v) rv = t40_ysp_reg_write(rb + (off), (v))
	W(0x4, (((P(111) << 16) | (P(112) << 20)) | P(1624)));
	W(0x30, (((YSP_CB(74, 6) << 8) | (YSP_CB(74, 7) << 12)) | YSP_CB(74, 5)));
	W(0x34, (((((YSP_CB(74, 1) << 4) | (YSP_CB(74, 2) << 8)) | YSP_CB(74, 0)) | (YSP_CB(74, 3) << 12)) | (YSP_CB(74, 4) << 16)));
	W(0x38, (((((P(158) << 12) | YSP_CB(27, 0)) | (P(159) << 16)) | (YSP_CB(27, 1) << 4)) | (YSP_CB(27, 2) << 8)));
	W(0x40, ((((P(694) << 4) | (P(695) << 8)) | P(693)) | (P(696) << 16)));
	W(0x4c, ((((((P(1156) << 4) | (P(1157) << 8)) | P(161)) | (P(1158) << 12)) | (P(1159) << 16)) | (P(1160) << 24)));
	W(0x80, PW(472));
	W(0x84, PW(476));
	W(0x90, PW(480));
	W(0x94, PW(484));
	W(0xa8, PW(354));
	W(0xac, PW(358));
	W(0xb0, PW(362));
	W(0xb4, PW(366));
	W(0xc8, YSP_CW(73, 0));
	W(0xcc, YSP_CW(73, 4));
	W(0xd0, YSP_CW(73, 8));
	W(0xd4, YSP_CW(73, 12));
	W(0xd8, YSP_CW(73, 16));
	W(0xdc, YSP_CW(73, 20));
	W(0xe0, YSP_CW(73, 24));
	W(0xe4, YSP_CW(73, 28));
	W(0x128, YSP_CW(94, 0));
	W(0x12c, YSP_CW(94, 4));
	W(0x130, YSP_CW(94, 8));
	W(0x134, YSP_CW(94, 12));
	W(0x138, YSP_CW(94, 16));
	W(0x13c, YSP_CW(94, 20));
	W(0x140, YSP_CW(94, 24));
	W(0x144, YSP_CW(94, 28));
	W(0x1e0, ((((YSP_CB(95, 3) << 6) | (YSP_CB(95, 4) << 16)) | YSP_CB(95, 2)) | (YSP_CB(95, 5) << 24)));
	W(0x1e4, ((((YSP_CB(95, 7) << 6) | (YSP_CB(95, 8) << 16)) | YSP_CB(95, 6)) | (YSP_CB(95, 9) << 24)));
#undef W
#undef PW
#undef P
	return rv;
}

/*
 * Eight-value ramp of ref_reg_cfg: x[0..3] = start + k * step, x[4..7] continue from the clamped x[3].  Rising ramps (step >= 0) are limited
 * from above by the end value e, falling ones from below.  Before that e is capped: rising ramps to cap (0 = no cap), falling ones to >= 0
 * when e_floor is set.  clamp0 = 0 leaves x[0] as it is (the three ramps taken straight from the interpolated block).
 */
static void t40_ysp_ramp8(int32_t x[8], int32_t start, int32_t step, int32_t e, int32_t cap, int e_floor, int clamp0)
{
	int neg = step < 0;
	int32_t r = start;
	unsigned int k;

	if (!neg && cap && !(e < cap + 1))
		e = cap;
	if (neg && e_floor && e < 0)
		e = 0;
	for (k = 0; k < 8; k++) {
		if (k == 4)
			r = x[3] + step;
		else if (k)
			r += step;
		x[k] = (k == 0 && !clamp0) ? r : (neg ? (r < e ? e : r) : (e < r ? e : r));
	}
}

/* v limited to 0..hi (hi = 0: no upper limit), signed like the OEM slt/movn pairs */
static inline uint32_t t40_ysp_lim(int32_t v, int32_t hi)
{
	if (hi && !(v < hi + 1))
		v = hi;
	return (uint32_t)(v < 0 ? 0 : v);
}

#define YSP_M18 0x3fc0000U
#define YSP_M2  0x3fcU

/* ref_reg_cfg: the writes that depend on the interpolated block.  ch, par, comb, intp as in t40_ysp_noref_reg_cfg */
static int32_t t40_ysp_ref_reg_cfg(uint32_t ch, uintptr_t par, uintptr_t comb, uintptr_t intp)
{
	static const uint16_t ramp_reg[3] = { 0x88, 0x98, 0xa0 };
	uint32_t rb = (ch + 0x98U) << 9;
	int32_t rv = 0, x[8];
	uint32_t i, a, b, X[8];

#define P(o) ((uint32_t)YSP_U8(par + (o)))
#define I(o) ((int32_t)YSP_U8(intp + (o)))
#define IU(o) ((uint32_t)YSP_U8(intp + (o)))
#define H(o) ((uint32_t)YSP_U16(intp + (o)))
#define IW(o) YSP_U32U(intp + (o))
#define W(off, v) rv = t40_ysp_reg_write(rb + (off), (v))
#define XS() do { for (a = 0; a < 8; a++) X[a] = (uint32_t)x[a]; } while (0)
	W(0x0, (P(1623) << 16) | IU(0));
	W(0x8, IW(2));
	W(0xc, (P(1636) << 12) | (H(8) << 16) | H(6) | (P(1639) << 28));
	W(0x10, (P(1637) << 30) | IW(10));
	W(0x14, (IU(15) << 16) | IU(14));
	W(0x18, (P(2) << 16) | (P(1) << 24) | H(16));
	W(0x1c, (t40_ysp_lim(I(15) + (int32_t)YSP_CB(6, 1) - 0x80, 255) << 16) | t40_ysp_lim(I(14) + (int32_t)YSP_CB(6, 0) - 0x80, 255));
	W(0x20, (P(0) << 12) | (P(4) << 16) | H(18) | (P(3) << 24));
	W(0x24, (t40_ysp_lim(I(15) + (int32_t)YSP_CB(6, 3) - 0x80, 0) << 16) | t40_ysp_lim(I(14) + (int32_t)YSP_CB(6, 2) - 0x80, 0));
	W(0x28, (P(6) << 16) | (P(5) << 24) | H(20));
	W(0x2c, (IU(23) << 16) | (P(488) << 24) | IU(22));
	W(0x3c, (P(160) << 2) | (P(691) << 4) | P(690) | (P(692) << 8) | (IU(24) << 17));
	W(0x44, (P(489) << 12) | IU(25));
	W(0x48, (H(30) << 16) | H(26));
	W(0x50, (P(490) << 12) | (P(1161) << 16) | IU(32));
	W(0x54, (H(38) << 16) | H(34));
	W(0x7c, (P(1638) << 8) | (H(142) << 16) | P(113));
	/* three byte ramps straight from the interpolated block (start, step - 128, end; a rising end is capped to 128, x[0] stays as it is) */
	for (i = 0; i < 3; i++) {
		t40_ysp_ramp8(x, I(40 + 3 * i), I(41 + 3 * i) - 0x80, I(42 + 3 * i), 128, 0, 0);
		XS();
		W(ramp_reg[i], (X[1] << 8) | (X[2] << 16) | X[0] | (X[3] << 24));
		W(ramp_reg[i] + 4, X[4] | (X[5] << 8) | (X[6] << 16) | (X[7] << 24));
	}
	/* four pairs of bytes: interpolated value + table byte - 128, limited to 0..255 */
	for (i = 0; i < 4; i++)
		W(0xb8 + 4 * i, (t40_ysp_lim(I(83 + 2 * i) + (int32_t)YSP_CB(9, 2 * i + 1) - 0x80, 255) << 16) | t40_ysp_lim(I(82 + 2 * i) + (int32_t)YSP_CB(9, 2 * i) - 0x80, 255));
	/* ramps from the interpolated block plus the parameter record (start + p - 128, step + p - 256, end + p - 128; rising end capped to 255, falling end to >= 0) */
#define RAMP_IP(is, ps) t40_ysp_ramp8(x, I(is) + (int32_t)P(ps) - 0x80, I((is) + 1) + (int32_t)P((ps) + 1) - 0x100, I((is) + 2) + (int32_t)P((ps) + 2) - 0x80, 255, 1, 1); XS()
	RAMP_IP(130, 678);
	W(0xe8, (X[1] << 8) | (X[2] << 16) | X[0] | (X[3] << 24));
	W(0xec, X[4] | (X[5] << 8) | (X[6] << 16) | (X[7] << 24));
	RAMP_IP(133, 681);
	W(0xf0, (X[1] << 18) | (X[0] << 2));
	W(0xf4, (X[3] << 18) | (X[2] << 2));
	W(0xf8, (X[5] << 18) | (X[4] << 2));
	W(0xfc, (X[7] << 18) | (X[6] << 2));
	RAMP_IP(136, 684);
	W(0x100, (X[1] << 8) | (X[2] << 16) | X[0] | (X[3] << 24));
	W(0x104, X[4] | (X[5] << 8) | (X[6] << 16) | (X[7] << 24));
	RAMP_IP(139, 687);
	W(0x108, (X[1] << 18) | (X[0] << 2));
	W(0x10c, ((X[3] << 18) & YSP_M18) | ((X[2] << 2) & YSP_M2));
	W(0x110, (X[5] << 18) | (X[4] << 2));
	W(0x114, ((X[7] << 18) & YSP_M18) | ((X[6] << 2) & YSP_M2));
	for (i = 0; i < 4; i++)
		W(0x118 + 4 * i, (IU(83 + 2 * i) << 16) | IU(82 + 2 * i));
	/* ramps straight from the interpolated block with byte (4 x 8 bit) or 10-bit (4 x 2 x 8 bit) lanes, masked */
#define RAMP_I(is) t40_ysp_ramp8(x, I(is), I((is) + 1) - 0x80, I((is) + 2), 0, 0, 1); XS()
#define PACK_B() \
	W(b, X[0] | ((X[1] << 8) & 0xffffU) | ((X[2] << 16) & 0xff0000U) | (X[3] << 24)); \
	W(b + 4, (X[4] & 0xffU) | (X[7] << 24) | ((X[5] << 8) & 0xffffU) | ((X[6] << 16) & 0xff0000U))
#define PACK_10() \
	W(b, ((X[1] << 18) & YSP_M18) | (X[0] << 2)); \
	W(b + 4, ((X[3] << 18) & YSP_M18) | ((X[2] << 2) & YSP_M2)); \
	W(b + 8, ((X[5] << 18) & YSP_M18) | ((X[4] << 2) & YSP_M2)); \
	W(b + 12, ((X[7] << 18) & YSP_M18) | ((X[6] << 2) & YSP_M2))
	b = 0x148; RAMP_I(130); PACK_B();
	b = 0x150; RAMP_I(133); PACK_10();
	b = 0x160; RAMP_I(136); PACK_B();
	b = 0x168; RAMP_I(139); PACK_10();
	/* four pairs: (interpolated + table byte - 128) * 4 limited to 0..1023 */
	for (i = 0; i < 4; i++)
		W(0x178 + 4 * i, (t40_ysp_lim((I(91 + 2 * i) + (int32_t)YSP_CB(10, 2 * i + 1) - 0x80) * 4, 1023) << 16) | t40_ysp_lim((I(90 + 2 * i) + (int32_t)YSP_CB(10, 2 * i) - 0x80) * 4, 1023));
	for (i = 0; i < 8; i++)
		W(0x188 + 4 * i, IW(50 + 4 * i));
	for (i = 0; i < 4; i++)
		W(0x1a8 + 4 * i, (IU(91 + 2 * i) << 18) | (IU(90 + 2 * i) << 2));
	for (i = 0; i < 8; i++)
		W(0x1b8 + 4 * i, IW(98 + 4 * i));
	W(0x1d8, (H(36) << 16) | H(28));
	W(0x1dc, (IU(144) << 25) | (YSP_CB(95, 1) << 16) | YSP_CB(95, 0));
#undef PACK_10
#undef PACK_B
#undef RAMP_I
#undef RAMP_IP
#undef XS
#undef W
#undef IW
#undef H
#undef IU
#undef I
#undef P
	return rv;
}

#undef YSP_CW
#undef YSP_CB
#endif
