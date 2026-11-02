/*
 * T40 MDNS state and entry points (#85): the three blocks of the main channel (parameter record, pointer table, interpolated block) live in
 * main_mdns / main_mdns_comb / main_mdns_intp, the second sensor's in sec_mdns* (not driven on this driver), and the wrappers below run the
 * plain-C chain in tx_isp_t40_mdns_chain.h on them.  Frame size, last gain and WDR flag are the regtrace_mdns_* variables
 * (second channel: t40_mdns_sec_state).
 */
static inline int32_t t40_mdns_reg_write(uint32_t reg, uint32_t val)
{
    return system_reg_write(reg, val);
}

#include "tx_isp_t40_mdns_chain.h"

static bool t40_mdns_channel(uint32_t ch, struct t40_mdns_ch *c)
{
    c->ch = ch ? 1U : 0U;
    if (!ch) {
        c->par = main_mdns;
        c->comb = main_mdns_comb;
        c->intp = main_mdns_intp;
        c->width = regtrace_mdns_width;
        c->height = regtrace_mdns_height;
        c->gain_old = &regtrace_mdns_gain_old;
    } else {
        c->par = sec_mdns;
        c->comb = sec_mdns_comb;
        c->intp = sec_mdns_intp;
        c->width = t40_mdns_sec_state[0];
        c->height = t40_mdns_sec_state[1];
        c->gain_old = &t40_mdns_sec_state[2];
    }
    return c->par && c->comb && c->intp;
}

/* OEM tisp_mdns_wdr_en: linear or WDR layout of the pointer table; remembers the flag for the strength ratio */
static int32_t tisp_mdns_wdr_en_lit(uint32_t a0_in, uint32_t a1_in)
{
    struct t40_mdns_ch c;

    if (!t40_mdns_channel(a0_in, &c))
        return -1;
    regtrace_mdns_wdr_flags[c.ch] = a1_in;
    t40_mdns_comb_fill(c.par, c.comb, a1_in);
    return 0;
}

/* OEM tisp_mdns_par_refresh: re-program when the gain moved by thresh or more (first call also enables and starts the unit) */
static int32_t tisp_mdns_par_refresh_lit(uint32_t a0_in, uint32_t a1_in, uint32_t a2_in)
{
    struct t40_mdns_ch c;

    if (!t40_mdns_channel(a0_in, &c))
        return -ENODEV;
    return t40_mdns_par_refresh(&c, a1_in, a2_in, get_isp_memopt());
}

/* OEM tisp_mdns_refresh */
static int32_t tisp_mdns_refresh_lit(uint32_t a0_in, uint32_t a1_in)
{
    struct t40_mdns_ch c;

    if (!t40_mdns_channel(a0_in, &c))
        return -ENODEV;
    return t40_mdns_refresh(&c, a1_in, get_isp_memopt());
}

/* OEM tisp_mdns_params_refresh: the MDNS record of the tuning bank into the parameter block */
static int32_t tisp_mdns_params_refresh_lit(uint32_t a0_in)
{
    struct t40_mdns_ch c;
    uintptr_t bank = tparamsN[a0_in ? 1 : 0];

    if (!t40_mdns_channel(a0_in, &c) || !bank)
        return -ENODEV;
    t40_mdns_params_refresh(c.par, bank);
    return 0;
}

/* OEM tisp_mdns_func_en / tisp_mdns_all_reg_refresh / tisp_mdns_start / tisp_mdns_reg_trig for the param-array setter */
static int32_t tisp_mdns_func_en_lit(uint32_t a0_in, uint32_t a1_in)
{
    struct t40_mdns_ch c;

    (void)a1_in;
    if (!t40_mdns_channel(a0_in, &c))
        return -ENODEV;
    return t40_mdns_func_en(c.ch, c.par, get_isp_memopt());
}

static int32_t tisp_mdns_all_reg_refresh_lit(uint32_t a0_in, uint32_t a1_in)
{
    struct t40_mdns_ch c;

    if (!t40_mdns_channel(a0_in, &c))
        return -ENODEV;
    return t40_mdns_all_reg_refresh(&c, a1_in);
}

static int32_t tisp_mdns_start_lit(uint32_t a0_in)
{
    return t40_mdns_start(a0_in ? 1U : 0U);
}

static int32_t tisp_mdns_reg_trig_lit(uint32_t a0_in)
{
    return t40_mdns_reg_trig(a0_in ? 1U : 0U);
}
