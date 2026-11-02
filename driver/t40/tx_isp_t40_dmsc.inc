/*
 * T40 DMSC state and entry points (#85): the three blocks of the main channel (parameter record, pointer table, interpolated block),
 * the gain the chain was last run for, and the wrappers around the plain-C chain in tx_isp_t40_dmsc_chain.h.
 * Channel 1 (second sensor) has no DMSC state on this driver.
 */
static bool regtrace_enable_dmsc_lit;
static uint regtrace_dmsc_lit_gain = 212541U;
static uint32_t regtrace_dmsc_lit_gain_now;
module_param_named(enable_dmsc_lit, regtrace_enable_dmsc_lit, bool, 0644);
module_param_named(dmsc_lit_gain, regtrace_dmsc_lit_gain, uint, 0644);
module_param_named(dmsc_lit_gain_now, regtrace_dmsc_lit_gain_now, uint, 0444);

static uintptr_t regtrace_main_dmsc_lit;
static uintptr_t regtrace_main_dmsc_comb_lit;
static uintptr_t regtrace_main_dmsc_intp_lit;

static inline int32_t t40_dmsc_reg_write(uint32_t reg, uint32_t val)
{
    return system_reg_write(reg, val);
}

#include "tx_isp_t40_dmsc_chain.h"

/* the OEM wrappers run the chain on channel 0 (tisp_dmsc_all_reg_refresh = intp, noref, ref, trig) */
static void t40_dmsc_noref_main(void)
{
    t40_dmsc_noref_reg_cfg(0, regtrace_main_dmsc_lit, regtrace_main_dmsc_comb_lit);
}

static void t40_dmsc_ref_main(void)
{
    t40_dmsc_ref_reg_cfg(0, regtrace_main_dmsc_lit, regtrace_main_dmsc_comb_lit, regtrace_main_dmsc_intp_lit);
}

static void t40_dmsc_intp_main(uint32_t gain)
{
    t40_dmsc_intp(regtrace_main_dmsc_lit, regtrace_main_dmsc_comb_lit, regtrace_main_dmsc_intp_lit, gain);
}

static void t40_dmsc_all_reg_refresh_main(uint32_t gain)
{
    t40_dmsc_intp_main(gain);
    t40_dmsc_noref_main();
    t40_dmsc_ref_main();
    (void)t40_dmsc_reg_trig(0);
}

static int32_t regtrace_dmsc_main_init_lit(void)
{
    uint32_t nbuf = *(uint32_t *)((char *)&tparamsN);

    if (!nbuf)
        return -ENOENT;
    if (!regtrace_main_dmsc_lit)
        regtrace_main_dmsc_lit = (uintptr_t)vzalloc(6074U);
    if (!regtrace_main_dmsc_comb_lit)
        regtrace_main_dmsc_comb_lit = (uintptr_t)vzalloc(932U);
    if (!regtrace_main_dmsc_intp_lit)
        regtrace_main_dmsc_intp_lit = (uintptr_t)vzalloc(280U);
    if (!regtrace_main_dmsc_lit || !regtrace_main_dmsc_comb_lit ||
        !regtrace_main_dmsc_intp_lit)
        return -ENOMEM;

    memcpy((void *)(uintptr_t)regtrace_main_dmsc_lit,
           (const void *)(uintptr_t)(nbuf + 60780U), 6074U);
    memset((void *)(uintptr_t)regtrace_main_dmsc_comb_lit, 0, 932U);
    memset((void *)(uintptr_t)regtrace_main_dmsc_intp_lit, 0, 280U);
    t40_dmsc_comb_fill(regtrace_main_dmsc_lit, regtrace_main_dmsc_comb_lit, 0);   /* flag 0: the literal init never set another one */
    t40_dmsc_all_reg_refresh_main(regtrace_dmsc_lit_gain);
    regtrace_dmsc_lit_gain_now = regtrace_dmsc_lit_gain;
    printk(KERN_INFO
           "tx_isp_t40_recovered: dmsc-main-init-lit gain=%u par=%p comb=%p intp=%p\n",
           regtrace_dmsc_lit_gain,
           (void *)(uintptr_t)regtrace_main_dmsc_lit,
           (void *)(uintptr_t)regtrace_main_dmsc_comb_lit,
           (void *)(uintptr_t)regtrace_main_dmsc_intp_lit);
    return 0;
}

static void regtrace_dmsc_lit_gain_update(uint32_t gain)
{
    if (!regtrace_main_dmsc_lit || gain == regtrace_dmsc_lit_gain_now)
        return;
    t40_dmsc_all_reg_refresh_main(gain);
    regtrace_dmsc_lit_gain_now = gain;
}

static void regtrace_dmsc_lit_cleanup(void)
{
    vfree((void *)(uintptr_t)regtrace_main_dmsc_intp_lit);
    vfree((void *)(uintptr_t)regtrace_main_dmsc_comb_lit);
    vfree((void *)(uintptr_t)regtrace_main_dmsc_lit);
    regtrace_main_dmsc_intp_lit = 0;
    regtrace_main_dmsc_comb_lit = 0;
    regtrace_main_dmsc_lit = 0;
}
