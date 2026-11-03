/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 CLM (colour LUT mapping, TOP 0x40 bit 16) in plain C (#85): tisp_clm_init, tisp_clm_ct_interp (with tisp_clm_itp and
 * tisp_round_int64), tisp_clm_write_csc_para, tisp_clm_real_write_lut, tisp_clm_prepare_write_lut, tisp_clm_get_wlut_times,
 * tisp_clm_dn_params_refresh, tisp_clm_wdr_en and tisp_clm_deinit of the vendor tx-isp-t40.ko (thingino vendor-image build).
 * Checked against the OEM instructions in Unicorn (tools/ko_emu/diff_clm.py, tests/t40_clm_host.sh): return values, every
 * byte of the parameter copy, LUT image, state and CSC block, the table selection, and the order and values of the
 * register writes.
 *
 * OEM facts this file keeps:
 *  - One context per sensor: parameters (18924 bytes copied from the active tuning bank at +65536+9132), a table of 8
 *    pointers into them (here byte offsets), the LUT image (1050 s16 entries, then 1050 s8 entries), an 8-byte state
 *    (CT, threshold, zone, WDR flag) and a 92-byte CSC block (CLM_CSC_BT709_FULL at init).
 *  - ct_interp classifies the CT against three CT points (+-100 K hysteresis) into 5 zones: the outer and middle zones
 *    copy one table set, the two zones in between interpolate with a Q12 weight (tisp_clm_itp = a + round((b - a) * w, 12)
 *    on the low 32 bits).  Without force it returns 1 (nothing changed) when the zone is an even one and unchanged, or
 *    when the CT moved by no more than the threshold (signed compare).
 *  - real_write_lut streams 30 x 7 groups through the four LUT ports 0x500c0/0x500e0/0x50100/0x50120 (+0x10 for
 *    sensor 1), each word written to two ports, framed by 0x101 and 0xd10102 on the control words; then 0x12004 = first
 *    parameter half-word & 0x7ff and 0x12000 = 1 (0x12084/0x12080 for sensor 1); clears the write counter.
 *  - prepare_write_lut only counts (wlut_times++); tisp_hardware_reg_refresh writes the LUT when the counter is non-zero
 *    and CLM is not bypassed in TOP (get_wlut_times).  The driver calls t40_clm_hw_refresh for that step.
 *  - The vendor ct_interp prints the first byte of table 1 with printk on every call; not kept (log noise only).
 *  - Allocation: the OEM kmallocs a new context on every init and never frees the old one; here the context of a sensor
 *    is allocated once and reused, deinit frees it.
 *
 * Needs from the includer: uint8_t..uint64_t, memcpy/memset, system_reg_write/system_reg_read, tparamsN[] and
 *   T40_CLM_ALLOC(n)  zeroed memory or NULL,   T40_CLM_FREE(p)
 */
#ifndef TX_ISP_T40_CLM_H
#define TX_ISP_T40_CLM_H

#define T40_CLM_PARAMS   18924U
#define T40_CLM_REAL     3150U
#define T40_CLM_BIN_OFF  (65536U + 9132U)

struct t40_clm {
	uint8_t *params;	/* OEM ctx[0] */
	uint32_t tab[8];	/* OEM ctx[1]: pointers into params, here byte offsets */
	uint8_t *real;		/* OEM ctx[2]: s16 LUT[1050], s8 LUT[1050] */
	uint32_t ct;		/* OEM ctx[3] +0 */
	uint16_t thr;		/* +4 */
	uint8_t zone;		/* +6 */
	uint8_t wdr;		/* +7 */
	uint8_t csc[92];	/* OEM ctx[4] */
};

static struct t40_clm *t40_clm_ctx[2];
static uint8_t t40_clm_wlut_times[2];			/* OEM clm_wlut_times */
static uint64_t t40_clm_frame_saved[2];			/* OEM clm_frame_num_saved */
static uint8_t t40_clm_wlut_frequency[2] = { 5, 5 };	/* OEM clm_wlut_frequency (.data) */

/* OEM CLM_CSC_BT709_FULL */
static const int32_t t40_clm_csc_bt709[23] = {
	2, 13933, 46871, 4732, -7509, -25259, 32768, 32768, -29763, -3005, -16744448, 65280,
	65536, 0, 103206, 65536, -12276, -30679, 65536, 121609, 0, -16744448, 65280,
};
static const uint32_t t40_clm_tab_linear[8] = { 0, 6, 6312, 7362, 1056, 8412, 10512, 18912 };
static const uint32_t t40_clm_tab_wdr[8] = { 3156, 3162, 12612, 13662, 4212, 14712, 16812, 18918 };

static inline int16_t t40_clm_s16(const uint8_t *p)
{
	return (int16_t)(p[0] | (p[1] << 8));
}
static inline uint16_t t40_clm_u16(const uint8_t *p)
{
	return (uint16_t)(p[0] | (p[1] << 8));
}

/* OEM tisp_round_int64(x, n): x >> n rounded half up (arithmetic shift); n outside 1..62 returns x */
static int64_t t40_clm_round64(int64_t x, uint32_t n)
{
	if (n - 1U >= 62U)
		return x;
	return (x >> n) + ((x >> (n - 1U)) & 1);
}

/* OEM tisp_clm_itp: a + round((b - a) * w, 12), the product taken as an unsigned 32-bit value, result s16 */
static int16_t t40_clm_itp(int32_t a, int32_t b, uint32_t w)
{
	uint32_t p = (uint32_t)(b - a) * w;

	return (int16_t)(uint32_t)((uint32_t)a + (uint32_t)t40_clm_round64((int64_t)(uint64_t)p, 12));
}

/* the interpolated zones: dst8/dst16 = itp(lo, hi, w) element by element */
static void t40_clm_blend(struct t40_clm *c, uint32_t lo8, uint32_t hi8, uint32_t lo16, uint32_t hi16, uint32_t w)
{
	const uint8_t *p = c->params;
	uint8_t *d16 = c->real, *d8 = c->real + 2100U;
	uint32_t i;

	for (i = 0; i < 1050U; i++) {
		int16_t v;

		d8[i] = (uint8_t)t40_clm_itp((int8_t)p[lo8 + i], (int8_t)p[hi8 + i], w);
		v = t40_clm_itp(t40_clm_s16(p + lo16 + 2U * i), t40_clm_s16(p + hi16 + 2U * i), w);
		d16[2U * i] = (uint8_t)v;
		d16[2U * i + 1U] = (uint8_t)((uint16_t)v >> 8);
	}
}

static void t40_clm_copy(struct t40_clm *c, uint32_t t8, uint32_t t16)
{
	memcpy(c->real + 2100U, c->params + t8, 1050U);
	memcpy(c->real, c->params + t16, 2100U);
}

/* OEM tisp_clm_ct_interp(sensor, ct, force): 0 = LUT image rebuilt, 1 = unchanged, -1 = CT outside the zone (state kept) */
static int32_t t40_clm_ct_interp(uint32_t bank, uint32_t ct, uint32_t force)
{
	struct t40_clm *c = t40_clm_ctx[bank];
	const uint8_t *cp = c->params + c->tab[7];
	uint32_t ct0 = t40_clm_u16(cp), ct1 = t40_clm_u16(cp + 2), ct2 = t40_clm_u16(cp + 4);
	uint32_t m_lo = (ct1 - 100U) & 0xffffU, m_hi = (ct1 + 100U) & 0xffffU;
	uint32_t l_hi = (ct2 + 100U) & 0xffffU, h_lo = (ct0 - 100U) & 0xffffU;
	uint32_t zone, d;

	if (!(l_hi < ct))
		zone = 0;
	else if (ct < m_lo)
		zone = 1;
	else if (!(m_hi < ct))
		zone = 2;
	else
		zone = ct >= h_lo ? 4U : 3U;
	d = c->ct < ct ? ct - c->ct : c->ct - ct;
	if (!force) {
		if (c->zone == zone && !(zone & 1U))
			return 1;
		if (!((int32_t)c->thr < (int32_t)d))
			return 1;
	}
	c->ct = ct;
	c->zone = (uint8_t)zone;
	switch (zone) {
	case 0:
		t40_clm_copy(c, c->tab[3], c->tab[6]);
		return 0;
	case 1:
		if (!(l_hi < ct) || !(ct < m_lo))
			return -1;
		t40_clm_blend(c, c->tab[3], c->tab[2], c->tab[6], c->tab[5], ((ct - l_hi) << 12) / (m_lo - l_hi));
		return 0;
	case 2:
		t40_clm_copy(c, c->tab[2], c->tab[5]);
		return 0;
	case 3:
		if (!(m_hi < ct) || !(ct < h_lo))
			return -1;
		t40_clm_blend(c, c->tab[2], c->tab[1], c->tab[5], c->tab[4], ((ct - m_hi) << 12) / (h_lo - m_hi));
		return 0;
	default:
		t40_clm_copy(c, c->tab[1], c->tab[4]);
		return 0;
	}
}

/* |round(v, n)| of a CSC field (the OEM folds the sign with the high word of the 64-bit result) */
static uint32_t t40_clm_csc_mag(const uint8_t *csc, uint32_t off, uint32_t n)
{
	int32_t v = (int32_t)(csc[off] | (csc[off + 1] << 8) | (csc[off + 2] << 16) | ((uint32_t)csc[off + 3] << 24));
	int64_t r = t40_clm_round64(v, n);
	uint32_t lo = (uint32_t)r, s = (uint32_t)((int32_t)(uint32_t)((uint64_t)r >> 32) >> 31);

	return (lo ^ s) - s;
}

/* OEM tisp_clm_write_csc_para */
static int32_t t40_clm_write_csc_para(uint32_t bank)
{
	const uint8_t *s = t40_clm_ctx[bank]->csc;
	uint32_t base = bank ? 0x12080U : 0x12000U;
	uint32_t w0, w1, w2, w3, w4;

	w0 = ((t40_clm_csc_mag(s, 76, 6) << 16) & 0x0fff0000U) | (t40_clm_csc_mag(s, 56, 6) & 0xfffU);
	w1 = ((t40_clm_csc_mag(s, 68, 6) << 16) & 0x03ff0000U) | (t40_clm_csc_mag(s, 64, 6) & 0x3ffU);
	w2 = ((t40_clm_csc_mag(s, 20, 8) << 8) & 0xffffU) | ((t40_clm_csc_mag(s, 24, 8) << 16) & 0xff0000U) |
	     (t40_clm_csc_mag(s, 16, 8) & 0xffU);
	w3 = ((t40_clm_csc_mag(s, 32, 8) << 8) & 0xffffU) | ((t40_clm_csc_mag(s, 36, 8) << 16) & 0xff0000U) |
	     (t40_clm_csc_mag(s, 28, 8) & 0xffU);
	w4 = ((t40_clm_csc_mag(s, 60, 8) << 16) & 0x01ff0000U) | ((uint32_t)(s[42] != 0) << 8) | s[40];
	system_reg_write(base + 8U, w0);
	system_reg_write(base + 12U, w1);
	system_reg_write(base + 16U, w2);
	system_reg_write(base + 20U, w3);
	system_reg_write(base + 24U, w4);
	return system_reg_write(base, 1);
}

/* OEM tisp_clm_real_write_lut */
static int32_t t40_clm_real_write_lut(uint32_t bank)
{
	struct t40_clm *c = t40_clm_ctx[bank];
	uint32_t port = bank == 1U ? 0x500d0U : 0x500c0U, k, row, g;
	const uint8_t *b8 = c->real + 2100U, *b16 = c->real;

	for (k = 0; k < 4; k++)
		system_reg_write(port + 32U * k, 0x101);
	for (row = 0; row < 1050U; row += 35U) {
		for (g = 0; g < 7U; g++) {
			const uint8_t *b = b8 + row + 5U * g, *h = b16 + 2U * row + 10U * g;
			uint32_t w1 = (b[0] & 0x7fU) | ((uint32_t)b[4] << 28) | ((b[1] << 7) & 0x3f80U) | ((b[2] << 14) & 0x1fc000U) |
				      (((uint32_t)b[3] << 21) & 0xfe00000U);
			uint32_t w2 = (b[4] >> 4) & 7U;
			uint32_t w3 = (t40_clm_u16(h) & 0x1ffU) | ((uint32_t)t40_clm_u16(h + 6) << 27) |
				      (((uint32_t)t40_clm_u16(h + 2) << 9) & 0x3fe00U) | (((uint32_t)t40_clm_u16(h + 4) << 18) & 0x7fc0000U);
			uint32_t w4 = (((uint32_t)t40_clm_u16(h + 8) << 4) & 0x1ff0U) | ((t40_clm_u16(h + 6) >> 5) & 0xfU);

			system_reg_write(port + 4U, w1);
			system_reg_write(port + 36U, w1);
			system_reg_write(port + 4U, w2);
			system_reg_write(port + 36U, w2);
			system_reg_write(port + 68U, w3);
			system_reg_write(port + 100U, w3);
			system_reg_write(port + 68U, w4);
			system_reg_write(port + 100U, w4);
		}
	}
	for (k = 0; k < 4; k++)
		system_reg_write(port + 32U * k, 0xd10102);
	system_reg_write(bank ? 0x12084U : 0x12004U, t40_clm_u16(c->params + c->tab[0]) & 0x7ffU);
	system_reg_write(bank ? 0x12080U : 0x12000U, 1);
	t40_clm_wlut_times[bank] = 0;
	return 0;
}

/* OEM tisp_clm_prepare_write_lut */
static int32_t t40_clm_prepare_write_lut(uint32_t bank)
{
	t40_clm_wlut_times[bank]++;
	return 0;
}

/* OEM tisp_clm_get_wlut_times: 0 while CLM is bypassed in TOP (0x40 / 0x44 bit 16) */
static int32_t t40_clm_get_wlut_times(uint32_t bank, uint32_t *out)
{
	*out = (system_reg_read((bank + 16U) << 2) >> 16) & 1U ? 0U : t40_clm_wlut_times[bank];
	return 0;
}

/* the CLM step of OEM tisp_hardware_reg_refresh: write the armed LUT unless CLM is bypassed */
static int32_t t40_clm_hw_refresh(uint32_t bank)
{
	uint32_t n;

	if (bank > 1U || !t40_clm_ctx[bank])
		return 0;
	t40_clm_get_wlut_times(bank, &n);
	return n ? t40_clm_real_write_lut(bank) : 0;
}

/* OEM tisp_clm_init(sensor) */
static int32_t t40_clm_init(uint32_t bank)
{
	struct t40_clm *c;

	if (bank > 1U || !tparamsN[bank])
		return -1;
	c = t40_clm_ctx[bank];
	if (!c) {
		c = T40_CLM_ALLOC(sizeof(*c));
		if (!c)
			return -1;
		c->params = T40_CLM_ALLOC(T40_CLM_PARAMS);
		c->real = T40_CLM_ALLOC(T40_CLM_REAL);
		if (!c->params || !c->real) {
			T40_CLM_FREE(c->params);
			T40_CLM_FREE(c->real);
			T40_CLM_FREE(c);
			return -1;
		}
		t40_clm_ctx[bank] = c;
	}
	memset(c->real, 0, T40_CLM_REAL);
	memcpy(c->params, (const uint8_t *)(uintptr_t)tparamsN[bank] + T40_CLM_BIN_OFF, T40_CLM_PARAMS);
	memcpy(c->tab, t40_clm_tab_linear, sizeof(c->tab));
	c->ct = 5000;
	c->zone = 5;
	c->thr = 64;
	c->wdr = 0;
	memcpy(c->csc, t40_clm_csc_bt709, sizeof(c->csc));
	t40_clm_write_csc_para(bank);
	t40_clm_ct_interp(bank, c->ct, 1);
	t40_clm_real_write_lut(bank);
	return 0;
}

/* OEM tisp_clm_dn_params_refresh(sensor): new bank parameters, LUT rebuilt for the current CT and armed */
static int32_t t40_clm_dn_params_refresh(uint32_t bank)
{
	struct t40_clm *c = bank < 2U ? t40_clm_ctx[bank] : NULL;

	if (!c || !tparamsN[bank])
		return -1;
	memcpy(c->params, (const uint8_t *)(uintptr_t)tparamsN[bank] + T40_CLM_BIN_OFF, T40_CLM_PARAMS);
	t40_clm_ct_interp(bank, c->ct, 1);
	t40_clm_prepare_write_lut(bank);
	return 0;
}

/* OEM tisp_clm_wdr_en(sensor, en): en == 1 selects the WDR table set */
static int32_t t40_clm_wdr_en(uint32_t bank, uint32_t en)
{
	struct t40_clm *c = bank < 2U ? t40_clm_ctx[bank] : NULL;

	if (!c)
		return -1;
	memcpy(c->tab, en == 1U ? t40_clm_tab_wdr : t40_clm_tab_linear, sizeof(c->tab));
	c->wdr = (uint8_t)en;
	t40_clm_ct_interp(bank, c->ct, 1);
	t40_clm_prepare_write_lut(bank);
	return 0;
}

/* OEM tisp_clm_deinit(sensor) */
static int32_t t40_clm_deinit(uint32_t bank)
{
	struct t40_clm *c = bank < 2U ? t40_clm_ctx[bank] : NULL;

	if (!c)
		return 0;
	t40_clm_ctx[bank] = NULL;
	T40_CLM_FREE(c->params);
	T40_CLM_FREE(c->real);
	T40_CLM_FREE(c);
	return 0;
}

#endif
