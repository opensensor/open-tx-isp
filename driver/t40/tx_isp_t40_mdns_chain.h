/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 MDNS (temporal / motion denoise) chain in plain C (#85).
 *
 * Replaces the literal mips2c bodies of the OEM tisp_mdns_reg_cfg_equation_smp / _dif, tisp_mdns_reg_cfg, tisp_mdns_start,
 * tisp_mdns_reg_trig, tisp_mdns_intp, tisp_mdns_wdr_en, tisp_mdns_func_en, tisp_mdns_all_reg_refresh, tisp_mdns_par_refresh,
 * tisp_mdns_refresh and tisp_mdns_params_refresh.  The OEM keeps three blocks per ISP channel:
 *   par   2398 bytes, the MDNS parameter record (copied from the tuning file),
 *   comb  336 bytes, 84 pointers into par (tisp_mdns_wdr_en fills them, here t40_mdns_comb_fill; linear or WDR layout),
 *   intp  136 bytes, the gain-interpolated bytes (tisp_mdns_intp output, tisp_mdns_reg_cfg input).
 * Register block of channel ch: (ch + 0x1e) << 11.  The OEM draws its eight-point ramps in module globals
 * (mdns_equation_smp_yval*, mdns_equation_dif_yval* / cutval / segopt); here they are private arrays, the register writes are identical.
 * The layout of the three blocks is kept, so the Unicorn check (tools/ko_emu/diff_mdns_chain.py: OEM instructions vs this file built for
 * mipsel) sees identical memory and identical register writes.  Division by zero (undefined LO/HI on the CPU) yields 0 here.
 * Needs from the includer: uint32_t, t40_mdns_reg_write(reg, val), tisp_simple_intp_int8(int32_t, int32_t, void *), memcpy.
 */
#ifndef TX_ISP_T40_MDNS_CHAIN_H
#define TX_ISP_T40_MDNS_CHAIN_H

#define MDNS_PAR_SIZE  2398U
#define MDNS_COMB_SIZE 336U
#define MDNS_INTP_SIZE 136U
#define MDNS_PARAM_OFF 0x1105cU   /* the MDNS record inside the tuning bank (tparamsN[ch]) */

#define MDNS_U32(a) (*(uint32_t *)(uintptr_t)(a))
#define MDNS_U8(a)  (*(uint8_t *)(uintptr_t)(a))
/* unaligned little-endian word (the OEM uses an lwl/lwr pair) */
#define MDNS_U32U(a) ((uint32_t)MDNS_U8(a) | ((uint32_t)MDNS_U8((a) + 1) << 8) | ((uint32_t)MDNS_U8((a) + 2) << 16) | ((uint32_t)MDNS_U8((a) + 3) << 24))

/* one MDNS channel: the three blocks, the frame size the geometry registers are computed for, and the gain the registers were last programmed for */
struct t40_mdns_ch {
	uint32_t ch;
	uintptr_t par, comb, intp;
	uint32_t width, height;
	uint32_t *gain_old;
};

static inline int32_t t40_mdns_div(int32_t n, int32_t d)
{
	return d ? n / d : 0;
}

static inline int32_t t40_mdns_rem(int32_t n, int32_t d)
{
	return d ? n % d : 0;
}

/*
 * tisp_mdns_reg_cfg_equation_smp: eight-point ramp y[0..7] from y0 to y7; y[1..sel] stay at y0, then a slope of |y7 - y0| / (to - sel)
 * per step (to = from, at least sel + 1, at most 7; sel above 6 counts as 6); every point is limited to the y7 side.
 */
static void t40_mdns_ramp_smp(int32_t y[8], int32_t sel, int32_t from, int32_t y0, int32_t y7)
{
	int32_t k = sel < 7 ? sel : 6, to = from, first = (sel >= 0 && sel <= 5) ? sel : 6;
	uint32_t diff = (uint32_t)y7 - (uint32_t)y0, sign = (uint32_t)((int32_t)diff >> 31);
	int32_t step, i;

	if (!(k < to))
		to = (int32_t)((uint32_t)k + 1);
	if (!(to < 8))
		to = 7;
	step = t40_mdns_div((int32_t)((diff ^ sign) - sign), (int32_t)((uint32_t)to - (uint32_t)k));
	y[0] = y0;
	for (i = 1; i < 7; i++) {
		uint32_t n = i > first ? (uint32_t)(i - first) : 0;

		y[i] = (int32_t)((int32_t)diff > 0 ? (uint32_t)y0 + n * (uint32_t)step : (uint32_t)y0 - n * (uint32_t)step);
	}
	y[7] = y7;
	for (i = 0; i < 7; i++) {
		if ((int32_t)diff > 0 ? !(y[i] < y7) : !(y7 < y[i]))
			y[i] = y7;
	}
}

/*
 * tisp_mdns_reg_cfg_equation_dif: eight-point ramp y[0..7] from y0 to yend in Q13 steps: the slope |yend - y0| << 13 / (to - sel)
 * is spread over seven points with a weight of (256 - sel) / 7 per point; every point is limited to the yend side.
 * *cut gets sel (255 counts as 254), *seg is 0.
 */
static void t40_mdns_ramp_dif(int32_t y[8], int32_t *cut, int32_t *seg, int32_t sel, int32_t from, int32_t y0, int32_t yend)
{
	int32_t k = sel != 0xff ? sel : 254, to = from, i;
	uint32_t diff = (uint32_t)yend - (uint32_t)y0, shifted = diff << 13, sign = (uint32_t)((int32_t)shifted >> 31);
	int32_t q, d = t40_mdns_div((int32_t)(256U - (uint32_t)sel), 7);

	if (!(k < to))
		to = (int32_t)((uint32_t)k + 1);
	q = t40_mdns_div((int32_t)((shifted ^ sign) - sign), (int32_t)((uint32_t)to - (uint32_t)k));
	y[0] = y0;
	for (i = 1; i < 8; i++) {
		int32_t x = t40_mdns_div((int32_t)((uint32_t)i * (uint32_t)d * (uint32_t)q), 8192);

		y[i] = (int32_t)((int32_t)diff > 0 ? (uint32_t)y0 + (uint32_t)x : (uint32_t)y0 - (uint32_t)x);
	}
	for (i = 0; i < 8; i++) {
		if ((int32_t)diff > 0 ? !(y[i] < yend) : !(yend < y[i]))
			y[i] = yend;
	}
	*cut = k;
	*seg = 0;
}

/* tisp_mdns_wdr_en: comb[i] = pointer into par; the 11-byte node arrays of the linear layout, or the WDR layout (contiguous records) */
static const uint16_t t40_mdns_comb_lin_off[84] = {
	10, 21, 32, 109, 120, 131, 175, 186, 197, 252, 263, 274,
	484, 495, 506, 517, 682, 693, 704, 715, 726, 737, 748, 759,
	792, 803, 814, 825, 770, 781, 836, 847, 858, 869, 880, 891,
	902, 913, 924, 935, 946, 957, 968, 979, 990, 1001, 1012, 1023,
	1034, 1078, 1089, 1100, 1111, 1122, 1155, 1166, 1177, 1188, 1199,
	1210, 1221, 1232, 1243, 1254, 1265, 1276, 1287, 1298, 1309, 1353,
	1364, 1375, 1386, 1397, 1408, 1419, 1430, 1441, 1452, 1463, 1474,
	1485, 1496, 1507,
};

static void t40_mdns_comb_fill(uintptr_t par, uintptr_t comb, uint32_t wdr)
{
	uint32_t i;

	if (!wdr) {
		for (i = 0; i < 84; i++)
			MDNS_U32(comb + 4 * i) = (uint32_t)(par + t40_mdns_comb_lin_off[i]);
		return;
	}
	for (i = 0; i < 24; i++)
		MDNS_U32(comb + 4 * i) = (uint32_t)(par + 1518 + i * 11);
	MDNS_U32(comb + 4 * 24) = (uint32_t)(par + 792);
	MDNS_U32(comb + 4 * 25) = (uint32_t)(par + 803);
	MDNS_U32(comb + 4 * 26) = (uint32_t)(par + 814);
	MDNS_U32(comb + 4 * 27) = (uint32_t)(par + 825);
	for (i = 28; i < 83; i++)
		MDNS_U32(comb + 4 * i) = (uint32_t)(par + 1782 + (i - 28) * 11);
	MDNS_U32(comb + 4 * 83) = (uint32_t)(par + 2387);
}

/*
 * tisp_mdns_intp: intp[i] = interpolate(gain, 11-byte node array) for i = 0..135; the node array is par + offset, or (0x8000 | n) the
 * array the pointer comb[n] points at.
 */
static const uint16_t t40_mdns_intp_src[MDNS_INTP_SIZE] = {
	0x8000, 0x8001, 0x8002, 0x002b, 0x0036, 0x0041, 0x004c, 0x0057,
	0x0062, 0x8003, 0x8004, 0x8005, 0x008e, 0x0099, 0x00a4, 0x8006,
	0x8007, 0x8008, 0x00d0, 0x00db, 0x00e6, 0x00f1, 0x8009, 0x800a,
	0x800b, 0x011d, 0x0128, 0x0133, 0x013e, 0x0149, 0x0154, 0x015f,
	0x016a, 0x0175, 0x0180, 0x018b, 0x0196, 0x01a1, 0x01ac, 0x01b7,
	0x01c2, 0x01cd, 0x800c, 0x800d, 0x800e, 0x800f, 0x0210, 0x021b,
	0x0226, 0x0231, 0x023c, 0x0247, 0x0252, 0x025d, 0x0268, 0x0273,
	0x027e, 0x0289, 0x0294, 0x029f, 0x8010, 0x8011, 0x8012, 0x8013,
	0x8014, 0x8015, 0x8016, 0x8017, 0x801c, 0x801d, 0x8018, 0x8019,
	0x801a, 0x801b, 0x801e, 0x801f, 0x8020, 0x8021, 0x8022, 0x8023,
	0x8024, 0x8025, 0x8026, 0x8027, 0x8028, 0x8029, 0x802a, 0x802b,
	0x802c, 0x802d, 0x802e, 0x802f, 0x8030, 0x0415, 0x0420, 0x042b,
	0x8031, 0x8032, 0x8033, 0x8034, 0x8035, 0x046d, 0x0478, 0x8036,
	0x8037, 0x8038, 0x8039, 0x803a, 0x803b, 0x803c, 0x803d, 0x803e,
	0x803f, 0x8040, 0x8041, 0x8042, 0x8043, 0x8044, 0x0528, 0x0533,
	0x053e, 0x8045, 0x8046, 0x8047, 0x8048, 0x8049, 0x804a, 0x804b,
	0x804c, 0x804d, 0x804e, 0x804f, 0x8050, 0x8051, 0x8052, 0x8053,
};

static void t40_mdns_intp(uintptr_t par, uintptr_t comb, uintptr_t intp, uint32_t gain)
{
	int32_t hi = (int32_t)gain >> 16, lo = (int32_t)(gain & 0xffff);
	uint32_t i;

	for (i = 0; i < MDNS_INTP_SIZE; i++) {
		uint32_t s = t40_mdns_intp_src[i];
		void *node = (void *)(uintptr_t)((s & 0x8000) ? MDNS_U32(comb + 4 * (s & 0x7fff)) : par + s);

		MDNS_U8(intp + i) = (uint8_t)tisp_simple_intp_int8(hi, lo, node);
	}
}

/* tisp_mdns_start / tisp_mdns_reg_trig */
static int32_t t40_mdns_start(uint32_t ch)
{
	return t40_mdns_reg_write(((ch + 0x1e) << 11) + 8, 1);
}

static int32_t t40_mdns_reg_trig(uint32_t ch)
{
	return t40_mdns_reg_write(((ch + 0x1e) << 11) + 4, 1);
}

/*
 * tisp_mdns_func_en: the enable bits of par[0..8] into the two function-enable registers; the memory optimisation nibble of the channel
 * (memopt >> 4 * ch, memopt = get_isp_memopt()) 1 or 2 first clears the plane enable bits of par[4] and par[7] (nibble 1: bit 0, nibble 2: bits 0..1).
 */
static int32_t t40_mdns_func_en(uint32_t ch, uintptr_t par, uint32_t memopt)
{
	uint32_t rb = (ch + 0x1e) << 11, nib = (uint32_t)((int32_t)memopt >> ((ch << 2) & 31)) & 0xf, v;
	uint32_t p4 = MDNS_U8(par + 4), p7 = MDNS_U8(par + 7);

	if (nib - 1 < 2) {
		p7 &= 0xfffffffeU;
		p4 &= nib == 1 ? 0xfffffffeU : 0xfcU;
		MDNS_U8(par + 4) = (uint8_t)p4;
		MDNS_U8(par + 7) = (uint8_t)p7;
	}
	(void)t40_mdns_reg_write(rb + 0x20, ((MDNS_U8(par + 1) << 4) & 0x10) | (MDNS_U8(par) & 1));
	v = (MDNS_U8(par + 2) & 1) | 0x10000000U;
	v |= (MDNS_U8(par + 3) << 4) & 0x10;
	v |= (MDNS_U8(par + 5) << 8) & 0x100;
	v |= (MDNS_U8(par + 6) << 12) & 0x1000;
	v |= (MDNS_U8(par + 4) << 16) & 0x30000;
	v |= (MDNS_U8(par + 7) << 20) & 0x300000;
	v |= (MDNS_U8(par + 8) << 24) & 0x1000000;
	return t40_mdns_reg_write(rb + 0x24, v);
}

/* tisp_mdns_reg_cfg: all MDNS registers of the channel from par, intp and the frame size */
#define MDNS_RAMP_LO(y) (((uint32_t)(y)[0] & 0xff) | ((uint32_t)(y)[3] << 24) | (((uint32_t)(y)[1] << 8) & 0xffff) | (((uint32_t)(y)[2] << 16) & 0xff0000))
#define MDNS_RAMP_HI(y) (((uint32_t)(y)[4] & 0xff) | ((uint32_t)(y)[7] << 24) | (((uint32_t)(y)[5] << 8) & 0xffff) | (((uint32_t)(y)[6] << 16) & 0xff0000))
#define MDNS_DIF_CTL ((((uint32_t)dcut << 8) & 0xffff) | ((uint32_t)dseg & 3))

static int32_t t40_mdns_reg_cfg(const struct t40_mdns_ch *c)
{
	uintptr_t par = c->par, ip = c->intp;
	uint32_t rb = (c->ch + 0x1e) << 11;
	int32_t w = (int32_t)c->width, h = (int32_t)c->height, s = MDNS_U8(ip + 4);
	int32_t dy[8], sy[8], dcut, dseg, wr = 0, x, y, rw, rh;
	uint32_t lo1, lo2, hi1, hi2;

#define I(n)  ((uint32_t)MDNS_U8(ip + (n)))
#define P(n)  ((uint32_t)MDNS_U8(par + (n)))
#define IU32(n) MDNS_U32U(ip + (n))
#define PU32(n) MDNS_U32U(par + (n))
#define W(off, v) (wr = t40_mdns_reg_write(rb + (off), (v)))
	W(0x68, (uint32_t)h * (uint32_t)(w / 16 + ((w & 0xf) != 0)));
	W(0x6c, ((uint32_t)h * (uint32_t)(w / 32 + ((w & 0x1f) != 0))) >> 1);
	W(0x100, I(4));
	/* x / y: picture offset inside the first tile row / column, rw / rh: what is left of the frame */
	x = (int32_t)(I(5) * (uint32_t)s + (uint32_t)t40_mdns_rem(w, s));
	y = (int32_t)(I(6) * (uint32_t)s + (uint32_t)t40_mdns_rem(h, s));
	rw = (int32_t)((uint32_t)w - (uint32_t)x);
	rh = (int32_t)((uint32_t)h - (uint32_t)y);
	W(0x104, ((uint32_t)((y / 2) << 8) & 0xffff) | ((uint32_t)(x / 2) & 0xff));
	W(0x108, ((uint32_t)rw & 0xffff) | ((uint32_t)rh << 16));
	W(0x10c, ((uint32_t)t40_mdns_div(rw, s) & 0xffff) | ((uint32_t)t40_mdns_div(rh, s) << 16));
	W(0x110, ((I(7) << 8) & 0x300) | ((I(8) << 16) & 0x30000) | ((uint32_t)t40_mdns_div(s + 0x800, s << 1) & 0xff));
	W(0x114, (((((I(1) << 8) | (I(3) << 24)) | I(0)) | ((I(2) << 16) & 0xf0000)) | ((I(21) << 23) & 0x800000)));
	W(0x118, ((((((I(10) << 8) | (I(13) << 24)) | I(9)) | ((I(11) << 16) & 0xf0000)) | ((I(12) << 20) & 0x700000)) | ((I(14) << 23) & 0x800000)));
	W(0x11c, ((((((I(16) << 8) | (I(19) << 24)) | I(15)) | ((I(17) << 16) & 0xf0000)) | ((I(18) << 20) & 0x700000)) | ((I(20) << 23) & 0x800000)));
	W(0x120, ((I(27) << 16) | I(26)));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(28), I(29), I(30), I(31));
	W(0x124, MDNS_DIF_CTL);
	W(0x128, MDNS_RAMP_LO(dy));
	W(0x12c, MDNS_RAMP_HI(dy));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(32), I(33), I(34), I(35));
	W(0x130, MDNS_DIF_CTL);
	W(0x134, MDNS_RAMP_LO(dy));
	W(0x138, MDNS_RAMP_HI(dy));
	W(0x13c, ((((I(24) << 16) & 0xf0000) | ((I(25) << 20) & 0x700000)) | ((I(23) << 8) | I(22))));
	W(0x150, ((((I(66) << 8) | (P(472) << 16)) | I(65)) | (P(473) << 24)));
	W(0x154, PU32(472));
	W(0x158, PU32(476));
	W(0x15c, PU32(472));
	W(0x160, PU32(476));
	W(0x164, PU32(472));
	W(0x168, PU32(476));
	W(0x16c, PU32(480));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(42), I(43), I(44), I(45));
	W(0x170, MDNS_DIF_CTL);
	W(0x174, MDNS_RAMP_LO(dy));
	W(0x178, MDNS_RAMP_HI(dy));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(48), I(49), I(50), I(51));
	W(0x17c, ((MDNS_DIF_CTL | (I(47) << 24)) | ((I(46) << 16) & 0x30000)));
	W(0x180, MDNS_RAMP_LO(dy));
	W(0x184, MDNS_RAMP_HI(dy));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(52), I(53), I(54), I(55));
	W(0x188, MDNS_DIF_CTL);
	W(0x18c, MDNS_RAMP_LO(dy));
	W(0x190, MDNS_RAMP_HI(dy));
	W(0x194, IU32(56));
	W(0x198, (((((I(61) << 8) | (I(62) << 16)) | I(60)) | (I(64) << 28)) | ((I(63) << 24) & 0xf000000)));
	W(0x1b0, ((I(74) << 8) | (I(80) << 16)));
	W(0x1b4, IU32(75));
	W(0x1b8, ((((I(79) << 8) | (I(79) << 16)) | I(79)) | (I(79) << 24)));
	W(0x1bc, ((((((int32_t)((P(473) + P(474))) >> 1) << 8) | (((int32_t)((P(474) + P(475))) >> 1) << 16)) | 0x14) | (((int32_t)((P(475) + P(476))) >> 1) << 24)));
	W(0x1c0, (((((int32_t)((P(477) + P(478))) >> 1) << 8) | (((int32_t)((P(479) + P(478))) >> 1) << 16)) | ((int32_t)((P(476) + P(477))) >> 1)));
	W(0x1c4, (((I(37) << 8) & 0x300) | (I(36) & 0x3)));
	t40_mdns_ramp_smp(sy, I(38), I(39), I(40), I(41));
	W(0x1c8, MDNS_RAMP_LO(sy));
	W(0x1cc, MDNS_RAMP_HI(sy));
	W(0x1d0, MDNS_RAMP_LO(sy));
	W(0x1d4, MDNS_RAMP_HI(sy));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(70), I(71), I(72), I(73));
	W(0x1d8, MDNS_DIF_CTL);
	W(0x1dc, MDNS_RAMP_LO(dy));
	W(0x1e0, MDNS_RAMP_HI(dy));
	W(0x1e4, MDNS_DIF_CTL);
	W(0x1e8, MDNS_RAMP_LO(dy));
	W(0x1ec, MDNS_RAMP_HI(dy));
	W(0x1f0, ((((I(69) << 8) & 0x100) | ((I(68) << 16) | I(68))) | ((I(69) << 24) & 0x1000000)));
	W(0x1f4, IU32(81));
	W(0x1f8, IU32(85));
	t40_mdns_ramp_smp(sy, I(89), I(90), I(91), I(92));
	W(0x1fc, MDNS_RAMP_LO(sy));
	W(0x200, MDNS_RAMP_HI(sy));
	W(0x204, MDNS_RAMP_LO(sy));
	W(0x208, MDNS_RAMP_HI(sy));
	W(0x20c, I(67));
	W(0x210, (((I(94) << 8) | (I(95) << 16)) | I(93)));
	t40_mdns_ramp_smp(sy, I(96), I(97), I(98), I(99));
	W(0x214, MDNS_RAMP_LO(sy));
	W(0x218, MDNS_RAMP_HI(sy));
	W(0x230, ((((I(102) & 0xf) | (I(100) << 8)) | ((I(103) << 16) & 0xf0000)) | ((I(101) << 20) & 0x700000)));
	W(0x234, ((((I(105) << 8) | (P(472) << 16)) | I(104)) | (P(473) << 24)));
	W(0x238, (((I(111) & 0x3) | (I(111) << 8)) | (I(112) << 16)));
	W(0x23c, ((((I(111) << 16) | (I(111) << 8)) | I(111)) | (I(111) << 24)));
	W(0x240, ((((I(111) << 16) | (I(111) << 8)) | I(111)) | (I(111) << 24)));
	W(0x244, ((((I(113) << 8) | (I(113) << 16)) | I(113)) | (I(113) << 24)));
	W(0x248, ((((I(113) << 8) | (I(113) << 16)) | I(113)) | (I(113) << 24)));
	t40_mdns_ramp_dif(dy, &dcut, &dseg, I(107), I(108), I(109), I(110));
	W(0x24c, MDNS_DIF_CTL);
	W(0x250, MDNS_RAMP_LO(dy));
	W(0x254, MDNS_RAMP_HI(dy));
	W(0x258, MDNS_DIF_CTL);
	W(0x25c, MDNS_RAMP_LO(dy));
	W(0x260, MDNS_RAMP_HI(dy));
	t40_mdns_ramp_smp(sy, I(114), I(115), I(116), I(117));
	W(0x264, MDNS_RAMP_LO(sy));
	W(0x268, MDNS_RAMP_HI(sy));
	W(0x26c, MDNS_RAMP_LO(sy));
	W(0x270, MDNS_RAMP_HI(sy));
	W(0x274, I(106));
	W(0x278, (((I(119) << 8) | (I(120) << 16)) | I(118)));
	t40_mdns_ramp_smp(sy, I(121), I(122), I(123), I(124));
	W(0x27c, MDNS_RAMP_LO(sy));
	W(0x280, MDNS_RAMP_HI(sy));
	/* ramp edge points 132..135: the low ends are limited to 128, the high ends keep a distance of 8 */
	lo1 = I(132) < 129 ? I(132) : 128;
	lo2 = I(134) < 129 ? I(134) : 128;
	hi1 = I(133);
	hi2 = I(135);
	if ((int32_t)(hi1 - lo1) < 8)
		hi1 += 8;
	if ((int32_t)(hi2 - lo2) < 8)
		hi2 += 8;
	W(0x2a0, (I(126) << 8) | (I(127) << 16) | I(125));
	W(0x2a4, IU32(128));
	W(0x2a8, (((uint32_t)t40_mdns_div(1024, (int32_t)(hi1 - lo1)) << 16) & 0xff0000) | ((hi1 << 8) & 0xffff) | lo1);
	W(0x2ac, (((uint32_t)t40_mdns_div(1024, (int32_t)(hi2 - lo2)) << 16) & 0xff0000) | ((hi2 << 8) & 0xffff) | lo2);
	W(0xc, (P(9) & 0x3f) | 0x40);
#undef I
#undef P
#undef IU32
#undef PU32
#undef W
	return wr;
}

#undef MDNS_RAMP_LO
#undef MDNS_RAMP_HI
#undef MDNS_DIF_CTL

/* tisp_mdns_all_reg_refresh: interpolate for the gain, then program the registers */
static int32_t t40_mdns_all_reg_refresh(const struct t40_mdns_ch *c, uint32_t gain)
{
	t40_mdns_intp(c->par, c->comb, c->intp, gain);
	return t40_mdns_reg_cfg(c);
}

/*
 * tisp_mdns_par_refresh: the first call after a reset (gain_old = -1), or a gain further than thresh from the last programmed one,
 * re-programs the channel; the first call also enables the functions and starts the unit.
 */
static int32_t t40_mdns_par_refresh(const struct t40_mdns_ch *c, uint32_t gain, uint32_t thresh, uint32_t memopt)
{
	uint32_t old = *c->gain_old;

	if (old == 0xffffffffU) {
		*c->gain_old = gain;
		(void)t40_mdns_func_en(c->ch, c->par, memopt);
		(void)t40_mdns_all_reg_refresh(c, gain);
		(void)t40_mdns_start(c->ch);
		return t40_mdns_reg_trig(c->ch);
	}
	if ((gain < old ? old - gain : gain - old) < thresh)
		return 0;
	*c->gain_old = gain;
	(void)t40_mdns_all_reg_refresh(c, gain);
	return t40_mdns_reg_trig(c->ch);
}

/* tisp_mdns_refresh: par_refresh with a threshold of 256, then the registers once more for the programmed gain */
static int32_t t40_mdns_refresh(const struct t40_mdns_ch *c, uint32_t gain, uint32_t memopt)
{
	(void)t40_mdns_par_refresh(c, gain, 256, memopt);
	return t40_mdns_all_reg_refresh(c, *c->gain_old);
}

/* tisp_mdns_params_refresh: copy the MDNS record of the tuning bank into par */
static void t40_mdns_params_refresh(uintptr_t par, uintptr_t bank)
{
	memcpy((void *)par, (const void *)(bank + MDNS_PARAM_OFF), MDNS_PAR_SIZE);
}

#endif
