/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 BLC block in C (issue #85), bit-exact to the vendor tx-isp-t40.ko functions
 * tisp_blc_ag_interp, tisp_blc_calc_digital_gain, tisp_blc_write_reg, tisp_blc_ag_long/short_frame_update,
 * tisp_blc_ae_write_dgain, tisp_blc_init and tisp_blc_dn_params_refresh (checked by tests/t40_blc_host.sh against
 * the OEM instructions in Unicorn).  The OEM allocates a 252-byte tool copy and a 72-byte hard record per channel
 * with private_kmalloc; here they are static arrays.
 *
 * Per channel (0 main, 1 secondary): tool block (copy of the tuning bin at +0x2350: four 11-entry u16 black-level
 * tables at +36/+58/+80/+102), two 36-byte hard records (index 0 long frame, 1 short frame), the last gain per
 * record and the Bayer type.  Registers: block base (ch + 64) << 7 = 0x2000 (main) / 0x2080.
 *
 * Needs system_reg_read/system_reg_write, memcpy/memset and the tparamsN pointer array from the includer.
 */
#ifndef TX_ISP_T40_BLC_H
#define TX_ISP_T40_BLC_H

static inline uint16_t regtrace_t40_tuning_u16(const uint8_t *p, uint32_t off)
{
    return (uint16_t)((uint16_t)p[off] | ((uint16_t)p[off + 1U] << 8));
}

/* Exact tisp_simple_intp_int16 rounding, without depending on recovered state. */
static uint16_t regtrace_t40_tuning_intp16(uint32_t gain,
                                           const uint8_t *table)
{
    uint32_t index = gain >> 16;
    uint32_t fract = gain & 0xffffU;
    uint32_t left, right, diff, product, step;

    if (index >= 10U)
        return regtrace_t40_tuning_u16(table, 20U);
    left = regtrace_t40_tuning_u16(table, index * 2U);
    right = regtrace_t40_tuning_u16(table, (index + 1U) * 2U);
    if (left == right)
        return (uint16_t)left;
    diff = left < right ? right - left : left - right;
    product = diff * fract;
    step = (product >> 16) + ((product >> 15) & 1U);
    return (uint16_t)(left < right ? left + step : left - step);
}

/* OEM hard record (36 bytes): the four black levels in Bayer order, their maximum and self gain, the digital
 * gain terms p[] (1024 = 1.0, set by tisp_blc_ae_write_dgain) and the three register gains g[] with the shift code. */
struct t40_blc_rec {
    uint16_t v[4];      /* +0  */
    uint16_t mx;        /* +8  */
    uint16_t self;      /* +10 */
    uint8_t code;       /* +12 */
    uint8_t pad[3];
    uint32_t p[3];      /* +16 */
    uint16_t g[3];      /* +28 */
    uint16_t pad2;
};
typedef char t40_blc_rec_size_check[sizeof(struct t40_blc_rec) == 36U ? 1 : -1];

static uint8_t t40_blc_tool[2][252];
static struct t40_blc_rec t40_blc_hard[2][2];
static uint32_t t40_blc_again[4];
static uint8_t t40_blc_bayer[2];

/* The OEM tests the channel argument against zero only. */
static inline uint32_t t40_blc_ch(uint32_t ch)
{
    return ch ? 1U : 0U;
}

/* OEM 0x2000000/(4096-max) with the u16 quotient halved and rounded.  max in 2048..4095 gives 8192.  max == 4096 is a
 * division by zero in the OEM (undefined result); the C returns 8192 there. */
static uint32_t t40_blc_self_gain(uint32_t mx)
{
    int32_t den;
    uint32_t q;

    if ((mx >> 11) == 1U)
        return 8192U;
    den = 4096 - (int32_t)mx;
    if (den == 0)
        return 8192U;
    q = (uint32_t)(0x2000000 / den) & 0xffffU;
    return (q >> 1) + (q & 1U);
}

/* Returns 1 (nothing done) when the gain moved less than 1024 and force is 0, else 0. */
static int t40_blc_ag_interp(uint32_t ch, uint32_t idx, uint32_t gain, uint32_t force)
{
    const uint8_t *tool = t40_blc_tool[t40_blc_ch(ch)];
    struct t40_blc_rec *rec = &t40_blc_hard[t40_blc_ch(ch)][idx ? 1 : 0];
    uint32_t *last = &t40_blc_again[t40_blc_ch(ch) * 2U + (idx ? 1U : 0U)];
    uint32_t old = *last, d = old < gain ? gain - old : old - gain;
    uint32_t a, b, c, e, mx;

    if (!(d >> 10) && !force)
        return 1;
    *last = gain;
    a = regtrace_t40_tuning_intp16(gain, tool + 36U);
    b = regtrace_t40_tuning_intp16(gain, tool + 58U);
    c = regtrace_t40_tuning_intp16(gain, tool + 80U);
    e = regtrace_t40_tuning_intp16(gain, tool + 102U);
    mx = a;
    if (b > mx)
        mx = b;
    if (c > mx)
        mx = c;
    if (e > mx)
        mx = e;
    switch (t40_blc_bayer[t40_blc_ch(ch)]) {
    case 0:
        rec->v[0] = a; rec->v[1] = b; rec->v[2] = c; rec->v[3] = e;
        break;
    case 1:
        rec->v[0] = e; rec->v[1] = c; rec->v[2] = b; rec->v[3] = a;
        break;
    case 2:
        rec->v[0] = b; rec->v[1] = a; rec->v[2] = e; rec->v[3] = c;
        break;
    case 3:
        rec->v[0] = c; rec->v[1] = e; rec->v[2] = a; rec->v[3] = b;
        break;
    default:
        break;
    }
    rec->mx = (uint16_t)mx;
    rec->self = (uint16_t)t40_blc_self_gain(mx & 0xffffU);
    return 0;
}

/* g[] = self * p[] >> 12, scaled down by 1..4 extra bits when the largest exceeds 15 bits (code = the OEM byte). */
static void t40_blc_calc_digital_gain(uint32_t ch, uint32_t idx)
{
    struct t40_blc_rec *rec = &t40_blc_hard[t40_blc_ch(ch)][idx ? 1 : 0];
    uint32_t s = rec->self, m0 = s * rec->p[0], m1 = s * rec->p[1], m2 = s * rec->p[2];
    uint32_t t0 = m0 >> 12, t1 = m1 >> 12, t2 = m2 >> 12, mx = t0;

    if (t1 > mx)
        mx = t1;
    if (t2 > mx)
        mx = t2;
    if ((mx >> 18) == 1U) {
        rec->g[0] = (uint16_t)(m0 >> 16); rec->g[1] = (uint16_t)(m1 >> 16); rec->g[2] = (uint16_t)(m2 >> 16);
        rec->code = 3;
    } else if ((mx >> 17) == 1U) {
        rec->g[0] = (uint16_t)(m0 >> 15); rec->g[1] = (uint16_t)(m1 >> 15); rec->g[2] = (uint16_t)(m2 >> 15);
        rec->code = 3;
    } else if ((mx >> 16) == 1U) {
        rec->g[0] = (uint16_t)(m0 >> 14); rec->g[1] = (uint16_t)(m1 >> 14); rec->g[2] = (uint16_t)(m2 >> 14);
        rec->code = 2;
    } else if ((mx >> 15) == 1U) {
        rec->g[0] = (uint16_t)(m0 >> 13); rec->g[1] = (uint16_t)(m1 >> 13); rec->g[2] = (uint16_t)(m2 >> 13);
        rec->code = 1;
    } else if (mx >> 10) {
        rec->g[0] = (uint16_t)t0; rec->g[1] = (uint16_t)t1; rec->g[2] = (uint16_t)t2;
        rec->code = 0;
    } else {
        rec->g[0] = 1024; rec->g[1] = 1024; rec->g[2] = 1024;
        rec->code = 0;
    }
}

/* mode 0: black levels + gains, 1: black levels only, 2: gains only; every mode ends with the commit write. */
static void t40_blc_write_reg(uint32_t ch, uint32_t idx, uint32_t mode)
{
    const struct t40_blc_rec *rec = &t40_blc_hard[t40_blc_ch(ch)][idx ? 1 : 0];
    uint32_t base = (ch + 64U) << 7;
    uint32_t vo = idx ? 20U : 4U, go = idx ? 48U : 36U;

    if (mode < 2U) {
        system_reg_write(base + vo, (((uint32_t)rec->v[1] << 16) & 0x0fff0000U) | (rec->v[0] & 0xfffU));
        system_reg_write(base + vo + 4U, (((uint32_t)rec->v[3] << 16) & 0x0fff0000U) | (rec->v[2] & 0xfffU));
    }
    if (mode == 0U || mode == 2U) {
        system_reg_write(base + go, (((uint32_t)rec->g[1] << 16) & 0x7fff0000U) | (rec->g[0] & 0x7fffU));
        system_reg_write(base + go + 4U, (rec->g[2] & 0x7fffU) | 0x04000000U);
        system_reg_write(base + go + 8U, rec->code & 3U);
    }
    system_reg_write(base, 1);
}

/* AE callback (channel, ignored, analog gain 16.16 log2): refresh black levels when the gain moved >= 1024. */
static __maybe_unused int tisp_blc_ag_long_frame_update(uint32_t ch, uint32_t unused, uint32_t gain)
{
    (void)unused;
    if (!t40_blc_ag_interp(ch, 0, gain, 0)) {
        t40_blc_calc_digital_gain(ch, 0);
        t40_blc_write_reg(ch, 0, 1);
    }
    return 0;
}

static __maybe_unused int tisp_blc_ag_short_frame_update(uint32_t ch, uint32_t unused, uint32_t gain)
{
    (void)unused;
    if (!t40_blc_ag_interp(ch, 1, gain, 0)) {
        t40_blc_calc_digital_gain(ch, 1);
        t40_blc_write_reg(ch, 1, 1);
    }
    return 0;
}

/* AE digital gain terms for record idx (1 = short frame), masked to 15 bits, then the gain registers. */
static __maybe_unused int tisp_blc_ae_write_dgain(uint32_t ch, uint32_t idx, uint32_t a2, uint32_t a3, uint32_t a4)
{
    struct t40_blc_rec *rec = &t40_blc_hard[t40_blc_ch(ch)][idx == 1U ? 1 : 0];

    rec->p[2] = a4 & 0x7fffU;
    rec->p[0] = a2 & 0x7fffU;
    rec->p[1] = a3 & 0x7fffU;
    t40_blc_calc_digital_gain(ch, idx);
    t40_blc_write_reg(ch, idx, 2);
    return 0;
}

/*
 * OEM tisp_blc_init (init != 0) / tisp_blc_dn_params_refresh: reload the tool block from the tuning bin
 * (tparamsN[ch] + 0x2350), reset the hard records (gain terms 1024), run both records at `gain` (the OEM
 * uses 1024) and write the registers.  init additionally clears the two soft-offset registers first.
 */
static int t40_blc_update(uint32_t ch, uint32_t gain, int init)
{
    uint32_t c = t40_blc_ch(ch), p[3] = { 1024, 1024, 1024 };
    const uint8_t *bin = (const uint8_t *)(uintptr_t)tparamsN[ch];
    uint32_t base = (ch + 64U) << 7;

    t40_blc_bayer[c] = (uint8_t)(system_reg_read((ch + 34U) << 2) & 3U);
    t40_blc_again[c * 2U] = gain;
    t40_blc_again[c * 2U + 1U] = gain;
    memcpy(t40_blc_tool[c], bin + 0x2350U, 252);
    memset(t40_blc_hard[c], 0, sizeof(t40_blc_hard[c]));
    memcpy(t40_blc_hard[c][0].p, p, 12);
    memcpy(t40_blc_hard[c][1].p, p, 12);
    t40_blc_ag_interp(ch, 0, t40_blc_again[c * 2U], 1);
    t40_blc_ag_interp(ch, 1, t40_blc_again[c * 2U + 1U], 1);
    t40_blc_calc_digital_gain(ch, 0);
    t40_blc_calc_digital_gain(ch, 1);
    if (init) {
        system_reg_write(base + 16U, 0);
        system_reg_write(base + 32U, 0);
    }
    t40_blc_write_reg(ch, 0, 0);
    t40_blc_write_reg(ch, 1, 0);
    return 0;
}

static __maybe_unused int tisp_blc_init(uint32_t ch)
{
    return t40_blc_update(ch, 1024U, 1);
}

static __maybe_unused int tisp_blc_dn_params_refresh(uint32_t ch)
{
    return t40_blc_update(ch, 1024U, 0);
}

#endif
