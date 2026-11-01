/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 CDNS (chroma denoise, TOP bit 19) in plain C.
 *
 * Rebuilt from the flow of the OEM tisp_cdns_* functions (sc830ai
 * tx-isp-t40.ko): the tuning bank holds a 683-byte CDNS section at +0x11b8b.
 * Byte 0 is a static enable/mode word; 30 fields (11-knot u8 gain tables)
 * are taken from the linear half (+1) or the WDR half (+353) of the section;
 * two more tables at the fixed linear offsets 0x11f / 0x12a are used in both
 * modes.  All 32 values are interpolated at the denoise EV (16.16 log2 gain)
 * and packed into the unit at ((ch + 0x380) << 7) = 0x1c000 (main) /
 * 0x1c080 (second sensor); +0x04 latches.
 *
 * This replaces the literal mips2c chain (tx_isp_t40_cdns_lit.inc up to
 * open-tx-isp next e96b92ea); tests/t40/c_chains_host compares both.
 * The driver glue keeps the literal behaviour: init (block init and the
 * day/night bank refresh) copies the section, selects the half, forgets the
 * remembered gain and packs at EV 1.0 (once; the OEM main_init packs the same
 * values twice); the frame-done DNS step repacks when the EV moved by at
 * least t40 cdns_thresh (OEM .data word: 0x10000 at load, 256 after
 * cdns_remove).
 *
 * The OEM keeps the section copy, a 30-pointer field table and the 32-byte
 * value buffer in vmalloc memory (main_cdns / main_cdns_comb /
 * main_cdns_intp); nothing else in this driver reads them, so the C state
 * holds them itself.
 */
#ifndef TX_ISP_T40_CDNS_H
#define TX_ISP_T40_CDNS_H

#include "tx_isp_t40_intp.h"

#define T40_CDNS_PAR_OFFSET 0x11b8bU
#define T40_CDNS_PAR_BYTES  683U
#define T40_CDNS_FIELDS     30U
#define T40_CDNS_CUR_BYTES  32U
#define T40_CDNS_GAIN_NONE  0xffffffffU

static bool regtrace_enable_cdns;
static int regtrace_cdns_dbg_init_ret = -1;
static unsigned int regtrace_cdns_init_count;
static unsigned int regtrace_cdns_refresh_count;
static unsigned int regtrace_cdns_skip_count;
static uint32_t regtrace_cdns_gain_now;
static uint regtrace_cdns_thresh = 0x10000U;
t40_bringup_param_named(cdns_thresh, regtrace_cdns_thresh, uint, 0644);
module_param_named(enable_cdns, regtrace_enable_cdns, bool, 0644);
MODULE_PARM_DESC(enable_cdns, "1 runs the CDNS chroma denoise and clears TOP bit 19 (default 0)");
t40_bringup_param_named(cdns_dbg_init_ret, regtrace_cdns_dbg_init_ret, int, 0444);
t40_bringup_param_named(cdns_init_count, regtrace_cdns_init_count, uint, 0444);
t40_bringup_param_named(cdns_refresh_count, regtrace_cdns_refresh_count, uint, 0444);
t40_bringup_param_named(cdns_skip_count, regtrace_cdns_skip_count, uint, 0444);
t40_bringup_param_named(cdns_gain_now, regtrace_cdns_gain_now, uint, 0444);

static struct t40_cdns_chan {
	uint8_t par[T40_CDNS_PAR_BYTES];	/* OEM main_cdns / sec_cdns */
	uint8_t cur[T40_CDNS_CUR_BYTES];	/* OEM main_cdns_intp: interpolated values */
	uint32_t wdr;			/* OEM cdns_wdr_en[ch] */
	bool wdr_half;			/* half selected by the last wdr_en (OEM main_cdns_comb) */
	uint32_t gain_old;		/* OEM .data gain-old word, T40_CDNS_GAIN_NONE: repack */
	bool loaded;			/* par holds a bank section */
} t40_cdns[2] T40C2 = {	/* outside .bss/.data (see T40-LAYOUT in tx_isp_t40_recovered.c) */
	{ .gain_old = T40_CDNS_GAIN_NONE }, { .gain_old = T40_CDNS_GAIN_NONE },
};

/* OEM tisp_cdns_wdr_en: 11-byte tables from +1.  The linear half has 32 of
 * them (fields 0..25, the two fixed tables 0x11f / 0x12a, fields 26..29),
 * the WDR half (+353) only the 30 fields. */
static inline const uint8_t *t40_cdns_field(const struct t40_cdns_chan *c, unsigned int i)
{
	return c->par + 1 + 11 * (c->wdr_half ? 32 + i : i + (i >= 26 ? 2 : 0));
}

/* tisp_cdns_intp: cur[0..25] = fields 0..25, cur[26..27] = the fixed
 * tables, cur[28..31] = fields 26..29 */
static void t40_cdns_interpolate(struct t40_cdns_chan *c, uint32_t ev)
{
	unsigned int i;

	for (i = 0; i < 26; i++)
		c->cur[i] = t40_intp_u8_at(ev, t40_cdns_field(c, i));
	c->cur[26] = t40_intp_u8_at(ev, c->par + 0x11f);
	c->cur[27] = t40_intp_u8_at(ev, c->par + 0x12a);
	for (i = 26; i < T40_CDNS_FIELDS; i++)
		c->cur[i + 2] = t40_intp_u8_at(ev, t40_cdns_field(c, i));
}

static inline uint32_t t40_cdns_base(uint32_t ch)
{
	return (ch + 0x380U) << 7;
}

/* tisp_cdns_reg_cfg + tisp_cdns_reg_trig */
static void t40_cdns_write(const struct t40_cdns_chan *c, uint32_t ch)
{
	const uint8_t *v = c->cur;
	uint32_t base = t40_cdns_base(ch), q = 0;
	int32_t lo = (int8_t)v[30], hi = (int8_t)v[31];
	unsigned int j;

	system_reg_write(base + 0x08, c->par[0]);
	system_reg_write(base + 0x10, v[0] & 0xf);
	/* eight byte triples */
	for (j = 0; j < 8; j++)
		system_reg_write(base + 0x20 + 4 * j,
				 v[1 + 3 * j] | ((uint32_t)v[2 + 3 * j] << 8) | ((uint32_t)v[3 + 3 * j] << 16));
	system_reg_write(base + 0x40, v[25] | ((uint32_t)v[26] << 8) | ((uint32_t)v[27] << 16) |
				      (((uint32_t)v[28] & 3) << 24) | (((uint32_t)v[29] & 3) << 28));
	/* signed range [lo, hi] (hi raised to lo) and its slope 4080 / (hi - lo) */
	if (hi < lo)
		hi = lo;
	else if (hi > lo)
		q = 4080 / (hi - lo);
	system_reg_write(base + 0x50, (lo & 0xff) | (((uint32_t)hi << 8) & 0xffff) | ((q << 16) & 0xfff0000));
	system_reg_write(base + 0x04, 1);
}

/* tisp_cdns_all_reg_refresh (tisp_cdns_intp_reg_refresh is the same) */
static int t40_cdns_pack(uint32_t ch, uint32_t ev)
{
	struct t40_cdns_chan *c = &t40_cdns[ch & 1];

	if (!c->loaded)
		return 0;
	t40_cdns_interpolate(c, ev);
	t40_cdns_write(c, ch & 1);
	regtrace_cdns_refresh_count++;
	regtrace_cdns_gain_now = ev;
	return 0;
}

/* tisp_cdns_par_refresh: repack when the EV moved by at least thresh
 * (always after a reset of the remembered gain) */
static int t40_cdns_par_refresh(uint32_t ch, uint32_t ev, uint32_t thresh)
{
	struct t40_cdns_chan *c = &t40_cdns[ch & 1];
	uint32_t old = c->gain_old;

	if (!c->loaded)
		return 0;
	if (old != T40_CDNS_GAIN_NONE && (ev < old ? old - ev : ev - old) < thresh) {
		regtrace_cdns_skip_count++;
		return 0;
	}
	c->gain_old = ev;
	return t40_cdns_pack(ch, ev);
}

/* tisp_cdns_refresh (tgain callback): par_refresh, then an unconditional
 * repack at the remembered gain */
static int t40_cdns_refresh(uint32_t ch, uint32_t ev)
{
	(void)t40_cdns_par_refresh(ch, ev, regtrace_cdns_thresh);
	return t40_cdns_pack(ch, t40_cdns[ch & 1].gain_old);
}

/* tisp_cdns_params_refresh: copy the section of the active bank */
static int t40_cdns_load(uint32_t ch)
{
	struct t40_cdns_chan *c = &t40_cdns[ch & 1];
	const uint8_t *bank = (const uint8_t *)(uintptr_t)tparamsN[ch & 1];

	if (!bank)
		return -ENOENT;
	memcpy(c->par, bank + T40_CDNS_PAR_OFFSET, T40_CDNS_PAR_BYTES);
	c->loaded = true;
	return 0;
}

/* tisp_cdns_wdr_en: remember the flag and select the half */
static void t40_cdns_set_wdr(uint32_t ch, uint32_t wdr)
{
	t40_cdns[ch & 1].wdr = wdr;
	t40_cdns[ch & 1].wdr_half = wdr != 0;
}

/* OEM tisp_cdns_main_init / tisp_cdns_sec_init (the literal glue: also on a
 * day/night bank refresh) */
static int t40_cdns_init(uint32_t ch)
{
	struct t40_cdns_chan *c = &t40_cdns[ch & 1];
	int ret = t40_cdns_load(ch);

	if (ret)
		return ret;
	t40_cdns_set_wdr(ch, c->wdr);
	c->gain_old = T40_CDNS_GAIN_NONE;
	(void)t40_cdns_par_refresh(ch, 0x10000U, 0x10000U);
	regtrace_cdns_init_count++;
	return 0;
}

/* tisp_cdns_dn_params_refresh */
static int t40_cdns_dn_refresh(uint32_t ch)
{
	if (t40_cdns_load(ch))
		return 0;
	t40_cdns_set_wdr(ch, t40_cdns[ch & 1].wdr);
	return t40_cdns_pack(ch, t40_cdns[ch & 1].gain_old);
}

/* tisp_cdns_param_array_get / _set (tuning ioctl: raw section) */
static int t40_cdns_param_get(uint32_t ch, void *dst, uint32_t *len)
{
	if (!dst || !len)
		return -EINVAL;
	memcpy(dst, t40_cdns[ch & 1].par, T40_CDNS_PAR_BYTES);
	*len = T40_CDNS_PAR_BYTES;
	return 0;
}

static int t40_cdns_param_set(uint32_t ch, const void *src)
{
	if (!src)
		return -EINVAL;
	memcpy(t40_cdns[ch & 1].par, src, T40_CDNS_PAR_BYTES);
	t40_cdns[ch & 1].loaded = true;
	(void)t40_cdns_pack(ch, t40_cdns[ch & 1].gain_old);
	return 0;
}

/* cdns_remove: forget both gains, WDR flags off (the selected half stays
 * until the next init), threshold 1/256 */
static void t40_cdns_remove(void)
{
	t40_cdns[0].gain_old = T40_CDNS_GAIN_NONE;
	t40_cdns[1].gain_old = T40_CDNS_GAIN_NONE;
	regtrace_cdns_thresh = 256;
	t40_cdns[0].wdr = 0;
	t40_cdns[1].wdr = 0;
}

/* tisp_cdns_main_deinit / sec_deinit: the buffers are static here */
static void t40_cdns_deinit(uint32_t ch)
{
	t40_cdns[ch & 1].loaded = false;
}

/*
 * TOP 0x40 bit 19 = CDNS bypass.  Clear it only after a successful init
 * (and never against t40_force_bypass); set it again when init failed so
 * the block cannot run on stale parameters.  The callers commit
 * regtrace_t40_quality_top40_final to 0x40.
 */
static void regtrace_t40_cdns_top_bit(int init_ret)
{
	regtrace_cdns_dbg_init_ret = init_ret;
	if (!init_ret && !(regtrace_t40_force_bypass & BIT(19)))
		regtrace_t40_quality_top40_final &= ~BIT(19);
	else
		regtrace_t40_quality_top40_final |= BIT(19);
}

#endif
