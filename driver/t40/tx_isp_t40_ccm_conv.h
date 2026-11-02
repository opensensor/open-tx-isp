/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 CCM matrix register <-> parameter conversion (tiziano-ccm leaf helpers).
 *
 * Plain C of the OEM tisp_ccm_reg2par (.text 0x6f5b4), tisp_ccm_para2reg (0x6f88c) and
 * tisp_ccm_parameter_convert (0x6f5e4).  A matrix is 9 words.  The register form is a 15-bit
 * two's complement value, the parameter form a signed 32-bit value:
 *   reg2par: v >= 0x2000 (unsigned) -> v - 0x4000;  para2reg: v < 0 -> v & 0x3fff.
 * Both return the last converted word (the OEM leaves it in v0).  Shared with the host check
 * tests/t40/ccm_conv_host (OEM instructions in Unicorn vs this file).
 */
#ifndef TX_ISP_T40_CCM_CONV_H
#define TX_ISP_T40_CCM_CONV_H

#define T40_CCM_WORDS 9

static uint32_t t40_ccm_reg2par(uint32_t *dst, const uint32_t *src)
{
    uint32_t v = 0;
    unsigned int i;

    for (i = 0; i < T40_CCM_WORDS; i++) {
        v = src[i];
        if (v >= 8192U)
            v -= 0x4000U;
        dst[i] = v;
    }
    return v;
}

static uint32_t t40_ccm_para2reg(uint32_t *dst, const uint32_t *src)
{
    uint32_t v = 0;
    unsigned int i;

    for (i = 0; i < T40_CCM_WORDS; i++) {
        v = src[i];
        if ((int32_t)v < 0)
            v &= 0x3fffU;
        dst[i] = v;
    }
    return v;
}

/* the context stores 32-bit addresses; the host check maps them through its own table (64-bit host) */
#ifndef T40_CCM_PTR
#define T40_CCM_PTR(ctx, off) ((uint32_t *)(uintptr_t)*(const uint32_t *)((ctx) + (off)))
#endif

/* ccm context: matrices at +48/+52/+56 (parameter form, pointers), sources at +80/+84/+88 (register form) */
static uint32_t t40_ccm_parameter_convert(uintptr_t ctx)
{
    uint32_t v = 0;
    unsigned int i;

    for (i = 0; i < 3; i++)
        v = t40_ccm_reg2par(T40_CCM_PTR(ctx, 48U + 4U * i), T40_CCM_PTR(ctx, 80U + 4U * i));
    return v;
}

#endif
