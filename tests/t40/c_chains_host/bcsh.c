/* T40 BCSH: literal OEM chain (lit/bcsh_lit.inc) vs readable driver/t40/tx_isp_t40_bcsh.h.
 * ./bcsh <bin>... (run.sh bcsh <bins>) */
#include "common.h"
#define REGTRACE_KERNEL_TREE_BUILD 1
static void *private_vmalloc(size_t n) { return vzalloc(n); }
/* driver helper (OEM 0x162d4) */
static int32_t fix_point_mult2_32(int32_t shift, int32_t left, int32_t right)
{
    uint32_t q = (uint32_t)shift & 31U;
    uint32_t mask = 0xffffffffU >> ((0U - q) & 31U);
    uint32_t x = (uint32_t)left, y = (uint32_t)right;
    uint32_t xi = x >> q, yi = y >> q;
    uint32_t xf = x & mask, yf = y & mask;
    return (int32_t)(((xi * yi) << q) + xf * yi + xi * yf + ((xf * yf) >> q));
}
#include "lit/csc_tables.inc"
/* address-only dispatch keys of the literal code */
static char tisp_bcsh_ct_interpolation, tisp_bcsh_ct_set_parameter, tisp_bcsh_ev_set_parameter, tisp_bcsh_ev_update_TransitParam,
    tisp_bcsh_para2reg, tisp_bcsh_reg2para, tisp_bcsh_StrenCal, tisp_bcsh_Tccm_Comp2Orig, tisp_bcsh_Tccm_RGB2YUV, tisp_bcsh_Tccm_RGBYUV,
    tisp_bcsh_Toffset_RGB2YUV, tisp_bcsh_Toffset_RGBYUV;
#include "lit/bcsh_lit.inc"
#include "../../../driver/t40/tx_isp_t40_bcsh.h"

/* high LCG bits (the low ones have short periods) */
static uint32_t rnd(void) { uint32_t a = lcg() >> 7, b = lcg() >> 7; return a ^ (b << 16); }
#define LIT_IN stMainBcshInterOri_lit
#define LIT_OUT ((uint8_t *)stMainBcshOuter_lit)
static uint8_t *bank_of(uint8_t *bin, int night) { return night ? BANK_NIGHT(bin) : BANK_DAY(bin); }
static unsigned long nwr, nsteps;

static unsigned compare(const char *tag, struct wr *a, unsigned na, struct wr *b, unsigned nb)
{
    unsigned bad = cmp_logs(tag, a, na, b, nb), i;
    nwr += na; nsteps++;
    for (i = 0; i < T40_BCSH_IN_BYTES; i++)
        if (LIT_IN[i] != t40_bcsh.in[i]) { printf("  %s: in[0x%x] lit %02x c %02x\n", tag, i, LIT_IN[i], t40_bcsh.in[i]); bad++; break; }
    if (stMainBcshOuter_lit)
        for (i = 0; i < T40_BCSH_OUT_BYTES; i++)
            if (LIT_OUT[i] != t40_bcsh.out[i]) { printf("  %s: out[0x%x] lit %02x c %02x\n", tag, i, LIT_OUT[i], t40_bcsh.out[i]); bad++; break; }
    if (t40_bcsh.ready && stMainBcshOuter_lit)	/* OEM pointer table: same field of the same image */
        for (i = 0; i < 72; i++) {
            uint32_t l = pstMainBcshOri_lit[i], c = t40_bcsh_oem_ctx[i];
            uint32_t lo = l - (uint32_t)(uintptr_t)LIT_IN < T40_BCSH_IN_BYTES ? l - (uint32_t)(uintptr_t)LIT_IN : 0x10000 + l - (uint32_t)stMainBcshOuter_lit;
            uint32_t co = c - (uint32_t)(uintptr_t)t40_bcsh.in < T40_BCSH_IN_BYTES ? c - (uint32_t)(uintptr_t)t40_bcsh.in : 0x10000 + c - (uint32_t)(uintptr_t)t40_bcsh.out;
            if (lo != co) { printf("  %s: ctx[%u] lit +%x c +%x\n", tag, i, lo, co); bad++; break; }
        }
    if (lit_bcsh_ev != regtrace_bcsh_ev) { printf("  %s: ev lit %u c %u\n", tag, lit_bcsh_ev, regtrace_bcsh_ev); bad++; }
    free(a); free(b);
    return bad;
}

/* driver glue, literal side (as in next e96b92ea) */
static void lit_apply_ctl(unsigned slot, uint8_t v)
{
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[slot] = v;
    tisp_bcsh_ev_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, 0);
}
static void lit_apply_hue(uint8_t hue)
{
    uint32_t deg = ((uint32_t)hue * 120U + 255U) >> 8;
    if (deg > 120) deg = 120;
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[6] = 1;
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[25] = deg;
    tisp_bcsh_ct_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, 0);
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[26] = hue;
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[6] = 0;
}
static void lit_csc(uint32_t mode)
{
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[27] = mode;
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[6] = 1;
    tisp_bcsh_params_refresh_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, (uint32_t)stMainBcshOuter_lit, (uint32_t)tparamsN[0] + 0x11e38U);
    tisp_bcsh_ev_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, 0);
    tisp_bcsh_ct_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, 0);
    *(uint8_t *)(uintptr_t)pstMainBcshOri_lit[6] = 0;
}
/* vendor-AWB follow of next e96b92ea (tx_isp_t40_vawb.h, OEM main_ev/ct_update) */
static void lit_main_ev(uint32_t e10)
{
    uint32_t *b = pstMainBcshOri_lit, last = *(uint32_t *)(uintptr_t)b[39];
    *(uint32_t *)(uintptr_t)b[38] = e10;
    if (*(uint8_t *)(uintptr_t)b[6] == 1 || (last > e10 ? last - e10 : e10 - last) > *(uint32_t *)(uintptr_t)b[40]) {
        (void)tisp_bcsh_ev_update_lit((uint32_t)(uintptr_t)b, 0);
        *(uint8_t *)(uintptr_t)b[6] = 0;
        *(uint32_t *)(uintptr_t)b[39] = e10;
    }
}
static void lit_main_ct(uint32_t ct)
{
    uint32_t *b = pstMainBcshOri_lit; uint16_t last = *(uint16_t *)(uintptr_t)b[42];
    *(uint16_t *)(uintptr_t)b[41] = (uint16_t)ct;
    if (*(uint8_t *)(uintptr_t)b[6] == 1 || (last > ct ? last - ct : ct - last) > *(uint16_t *)(uintptr_t)b[43]) {
        (void)tisp_bcsh_ct_update_lit((uint32_t)(uintptr_t)b, 0);
        *(uint8_t *)(uintptr_t)b[6] = 0;
        *(uint16_t *)(uintptr_t)b[42] = (uint16_t)ct;
    }
}
/* driver glue, C side */
static void c_apply_ctl(uint32_t off, uint8_t v) { t40_bcsh.in[off] = v; t40_bcsh_ev_update(0); }
static void c_apply_hue(uint8_t hue)
{
    uint32_t deg = ((uint32_t)hue * 120U + 255U) >> 8;
    if (deg > 120) deg = 120;
    t40_bcsh.in[BI_BUSY] = 1; t40_bcsh.in[BI_HUE] = deg;
    t40_bcsh_ct_update(0);
    t40_bcsh.in[BI_HUE_RAW] = hue; t40_bcsh.in[BI_BUSY] = 0;
}

enum { S_INIT, S_EV, S_CT, S_BRI, S_CON, S_SAT, S_HUE, S_CSC, S_EVUPD, S_CTUPD, S_MEV, S_MCT };
static unsigned step(int what, uint32_t v, uint8_t *bank, const char *tag)
{
    struct wr *a, *b; unsigned na, nb;
    tparamsN[0] = (uintptr_t)bank;
    switch (what) {
    case S_INIT: lit_bcsh_ev = regtrace_bcsh_ev; lit_bcsh_ct = regtrace_bcsh_ct; lit_bcsh_main_init_lit(v); break;
    case S_CT: *(uint16_t *)(uintptr_t)pstMainBcshOri_lit[41] = v; tisp_bcsh_ct_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, 0); break;
    case S_BRI: lit_apply_ctl(46, v); break;
    case S_CON: lit_apply_ctl(47, v); break;
    case S_SAT: lit_apply_ctl(48, v); break;
    case S_HUE: lit_apply_hue(v); break;
    case S_CSC: lit_csc(v); break;
    case S_EVUPD: tisp_bcsh_ev_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, v); break;
    case S_CTUPD: tisp_bcsh_ct_update_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, v); break;
    case S_MEV: lit_main_ev(v); break;
    case S_MCT: lit_main_ct(v); break;
    }
    a = snap(&na);
    switch (what) {
    case S_INIT: t40_bcsh_init(v); break;
    case S_CT: *t40_bcsh_in16(BI_CT) = v; t40_bcsh_ct_update(0); break;
    case S_BRI: c_apply_ctl(BI_BRIGHTNESS, v); break;
    case S_CON: c_apply_ctl(BI_CONTRAST, v); break;
    case S_SAT: c_apply_ctl(BI_SATURATION, v); break;
    case S_HUE: c_apply_hue(v); break;
    case S_CSC: t40_bcsh_set_csc(v); break;
    case S_EVUPD: t40_bcsh_ev_update(v); break;
    case S_CTUPD: t40_bcsh_ct_update(v); break;
    case S_MEV: t40_bcsh_main_ev_update(v); break;
    case S_MCT: t40_bcsh_main_ct_update(v); break;
    }
    b = snap(&nb);
    return compare(tag, a, na, b, nb);
}

/* random state: both sides get the same inter/outer bytes */
static void randomize(int keep_controls)
{
    unsigned i;
    uint8_t ctl[3]; memcpy(ctl, LIT_IN + BI_BRIGHTNESS, 3);
    for (i = 0; i < T40_BCSH_IN_BYTES; i++) LIT_IN[i] = rnd() >> 5;
    for (i = 0; i < T40_BCSH_OUT_BYTES; i++) LIT_OUT[i] = rnd() >> 5;
    /* realistic magnitudes for most words, garbage for some */
    if (rnd() % 4) {
        for (i = 0; i + 4 <= T40_BCSH_IN_BYTES; i += 4) if (rnd() % 3) *(uint32_t *)(LIT_IN + i) = rnd() % (rnd() % 2 ? 0x2000 : 0x20000);
        for (i = 0; i + 4 <= T40_BCSH_OUT_BYTES; i += 4) if (rnd() % 3) *(uint32_t *)(LIT_OUT + i) = rnd() % (rnd() % 2 ? 0x2000 : 0x20000);
    }
    if (rnd() % 2) {	/* ascending knots */
        uint32_t *k = (uint32_t *)(LIT_OUT + BO_EV_KNOTS + (LIT_IN[BI_WDR] ? T40_BCSH_WDR_HALF : 0)), x = 0;
        for (i = 0; i < 9; i++) { x += rnd() % 3000; k[i] = x; }
    }
    if (keep_controls) memcpy(LIT_IN + BI_BRIGHTNESS, ctl, 3);
    LIT_IN[BI_HUE] = rnd() % 121;
    {   /* EV / CT exactly on a knot or next to it */
        uint32_t h = LIT_IN[BI_WDR] ? T40_BCSH_WDR_HALF : 0, j = rnd() % 9;
        uint32_t *k = (uint32_t *)(LIT_OUT + BO_EV_KNOTS + h), *ck = (uint32_t *)(LIT_IN + BI_CT_KNOTS);
        if (rnd() % 3 == 0) *(uint32_t *)(LIT_IN + BI_EV) = k[j] + (rnd() % 3) - 1;
        if (rnd() % 3 == 0) *(uint16_t *)(LIT_IN + BI_CT) = ck[j % 4] + (rnd() % 3) - 1;
        if (rnd() % 2) { ck[0] = 2000 + rnd() % 1000; ck[1] = ck[0] + rnd() % 1500; ck[2] = ck[1] + rnd() % 1500; ck[3] = ck[2] + rnd() % 1500; }
        if (rnd() % 4 == 0) LIT_IN[BI_CT_ZONE_OLD] = rnd() % 5;
        if (rnd() % 6 == 0) *(uint32_t *)(LIT_OUT + BO_CURVE + h) = 0;	/* contrast curve off */
        if (rnd() % 8 == 0) {	/* brightness offset at the 1900 clamp */
            uint32_t *bt = (uint32_t *)(LIT_OUT + BO_BRI_TAB + h), v = 1899 + rnd() % 5;
            for (j = 0; j < 9; j++) bt[j] = v;
            LIT_IN[BI_BRIGHTNESS] = 128;
        }
    }
    tisp_bcsh_params_transmit_lit((uint32_t)(uintptr_t)pstMainBcshOri_lit, (uint32_t)stMainBcshOuter_lit, (uint32_t)(uintptr_t)stMainBcshInterOri_lit);
    memcpy(t40_bcsh.in, LIT_IN, T40_BCSH_IN_BYTES);
    memcpy(t40_bcsh.out, LIT_OUT, T40_BCSH_OUT_BYTES);
    t40_bcsh.half = LIT_IN[BI_WDR] ? T40_BCSH_WDR_HALF : 0;
    if (t40_bcsh.ready) t40_bcsh_build_ctx();
}

/* bcsh_user_full=1 (issue 83): CSC mode 4 and the user CCM take the whole user tables, in both
 * WDR halves; =0 is the OEM (compared bit-exact by chain_main) */
static unsigned user_full_check(uint8_t *bank)
{
    static const struct { uint16_t in, out, len; } t[] = {
        { BI_USER_OFF, BO_Y_OFFSET, 4 }, { BI_USER_CLIP0, BO_CLIP0, 8 }, { BI_USER_CLIP1, BO_CLIP1, 8 },
        { BI_USER_CLIP2, BO_CLIP2, 8 }, { BI_USER_M, BO_M, 36 }, { BI_USER_MINV, BO_MINV, 36 },
    };
    static const uint16_t ccm[3] = { BO_CCM0, BO_CCM1, BO_CCM2 };
    unsigned bad = 0, i, h, en, full, nw[2] = { 0, 0 };
    struct wr *w[2] = { NULL, NULL };

    tparamsN[0] = (uintptr_t)bank;
    for (full = 0; full < 2; full++)
        for (en = 0; en < 2; en++) {
            regtrace_bcsh_user_full = full;
            for (i = BI_USER_OFF; i < BI_USER_CCM_EN; i++)
                t40_bcsh.in[i] = (uint8_t)(i * 7 + 3);
            t40_bcsh.in[BI_USER_CCM_EN] = en;
            t40_bcsh.in[BI_USER_CCM_B] = 1;
            memset(t40_bcsh.out, 0x5a, T40_BCSH_OUT_BYTES);
            free(snap(&i));
            t40_bcsh_init(4);
            if (en)
                w[full] = snap(&nw[full]);
            for (i = 0; i < sizeof(t) / sizeof(t[0]); i++) {
                unsigned n = full ? t[i].len : 4;
                if (memcmp(t40_bcsh.out + t[i].out, t40_bcsh.in + t[i].in, n)) {
                    printf("  user_full=%u: CSC table @0x%x not copied (%u bytes)\n", full, t[i].out, n);
                    bad++;
                }
                if (!full && t[i].len > 4 && !memcmp(t40_bcsh.out + t[i].out, t40_bcsh.in + t[i].in, t[i].len)) {
                    printf("  user_full=0: CSC table @0x%x copied past the first word\n", t[i].out);
                    bad++;
                }
            }
            for (h = 0; en && h <= T40_BCSH_WDR_HALF; h += T40_BCSH_WDR_HALF)
                for (i = 0; i < 3; i++) {
                    int same = !memcmp(t40_bcsh.out + h + ccm[i], t40_bcsh.in + BI_USER_CCM, 36);
                    if (same != (int)full || memcmp(t40_bcsh.out + h + ccm[i], t40_bcsh.in + BI_USER_CCM, 4)) {
                        printf("  user_full=%u: user CCM %u half 0x%x wrong\n", full, i, h);
                        bad++;
                    }
                }
        }
    /* the whole tables change what reaches the BCSH registers */
    if (nw[0] == nw[1] && !memcmp(w[0], w[1], nw[0] * sizeof(*w[0]))) {
        printf("  user_full=1: register writes identical to the OEM copy\n");
        bad++;
    }
    free(w[0]);
    free(w[1]);
    regtrace_bcsh_user_full = false;
    printf("bcsh user_full: %s\n", bad ? "FAIL" : "ok (mode 4 tables and user CCM whole, OEM first word only)");
    return bad;
}

static int chain_main(int argc, char **argv)
{
    unsigned total = 0;
    char tag[96];
    regtrace_bcsh_user_full = false;	/* the OEM comparison */
    for (int k = 1; k < argc; k++) {
        uint8_t *bin = load_bin(argv[k]); unsigned bad = 0, i, r;
        int night = 0;
        lcg_state = 900 + k;
        /* whole chain as the driver runs it */
        for (uint32_t mode = 0; mode < 6; mode++) {
            snprintf(tag, sizeof(tag), "init mode %u", mode);
            regtrace_bcsh_ev = 400 + rnd() % 5000; regtrace_bcsh_ct = 2000 + rnd() % 6000;
            if (mode == 5) { LIT_IN[BI_WDR] = t40_bcsh.in[BI_WDR] = 1; LIT_IN[BI_USER_CCM_EN] = t40_bcsh.in[BI_USER_CCM_EN] = 1; }
            bad += step(S_INIT, mode == 5 ? 2 : mode, bank_of(bin, night), tag);
            for (i = 0; i < 400; i++) {
                r = rnd() % 17;
                snprintf(tag, sizeof(tag), "mode %u #%u op %u", mode, i, r);
                if (r < 5) bad += step(S_MEV, /* the EV input: one OEM path since #85 */ r == 4 ? *t40_bcsh_in32(BI_EV) : rnd() % (r ? 20000 : 0x400000), bank_of(bin, night), tag);
                else if (r < 8) bad += step(S_CT, rnd() % 12000, bank_of(bin, night), tag);
                else if (r == 8) bad += step(S_BRI, rnd() % 256, bank_of(bin, night), tag);
                else if (r == 9) bad += step(S_CON, rnd() % 256, bank_of(bin, night), tag);
                else if (r == 10) bad += step(S_SAT, rnd() % 256, bank_of(bin, night), tag);
                else if (r == 11) bad += step(S_HUE, rnd() % 256, bank_of(bin, night), tag);
                else if (r == 12) bad += step(S_CSC, rnd() % 5, bank_of(bin, night), tag);
                else if (r == 13) { night = !night; bad += step(S_INIT, rnd() % 5, bank_of(bin, night), "dn"); }
                else if (r == 14) {
                    uint32_t w = rnd() % 4, ev_last = *t40_bcsh_in32(0x1b4), ct_last = *t40_bcsh_in16(0x1be);
                    uint32_t d = rnd() % 2 ? *t40_bcsh_in32(0x1b8) : *t40_bcsh_in16(0x1c0);
                    if (w == 0) bad += step(S_MEV, rnd() % 20000, bank_of(bin, night), tag);
                    else if (w == 1) bad += step(S_MCT, 1500 + rnd() % 9000, bank_of(bin, night), tag);
                    else if (w == 2) bad += step(S_MEV, rnd() % 2 ? ev_last + d : ev_last - d, bank_of(bin, night), tag);	/* exactly the threshold */
                    else bad += step(S_MCT, rnd() % 2 ? ct_last + d : ct_last - d, bank_of(bin, night), tag);
                }
                else bad += step(S_EVUPD, 0, bank_of(bin, night), tag);
            }
            LIT_IN[BI_WDR] = t40_bcsh.in[BI_WDR] = 0; LIT_IN[BI_USER_CCM_EN] = t40_bcsh.in[BI_USER_CCM_EN] = 0;
        }
        /* random state per call */
        for (i = 0; i < 3000; i++) {
            randomize(rnd() % 2);
            r = rnd() % 4;
            snprintf(tag, sizeof(tag), "rnd #%u op %u", i, r);
            if (r == 0) bad += step(S_EVUPD, rnd() % 2, bank_of(bin, night), tag);
            else if (r == 1) bad += step(S_CTUPD, rnd() % 2, bank_of(bin, night), tag);
            else if (r == 2) bad += step(S_CSC, rnd() % 6, bank_of(bin, night), tag);
            else bad += step(S_HUE, rnd() % 256, bank_of(bin, night), tag);
            if (lit_ub) { printf("  %s: undefined OEM input (division by zero), bin stopped\n", tag); lit_ub = 0; break; }
        }
        /* back to a sane state for the next bin */
        memset(LIT_IN + BI_BRIGHTNESS, 128, 3); memcpy(t40_bcsh.in + BI_BRIGHTNESS, LIT_IN + BI_BRIGHTNESS, 3);
        LIT_IN[BI_WDR] = t40_bcsh.in[BI_WDR] = 0; LIT_IN[BI_USER_CCM_EN] = t40_bcsh.in[BI_USER_CCM_EN] = 0;
        printf("%s: %s\n", argv[k], bad ? "DIFF" : "bit-exact");
        total += bad;
    }
    if (argc > 1)
        total += user_full_check(bank_of(load_bin(argv[1]), 0));
    printf("bcsh: %d bins, %lu steps, %lu register writes compared, %u differences\n", argc - 1, nsteps, nwr, total);
    return total != 0;
}
