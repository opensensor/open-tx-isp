/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AE leaf and parameter functions in plain C (issue #85, "AE leftovers" classes A and B), bit-exact to the vendor
 * tx-isp-t40.ko functions of the same names (checked by tests/t40_ae_leaf_host.sh against the OEM instructions in Unicorn):
 *   A: tisp_ae_g_luma, g_comp, get_state, sensor_trig, ev_start_set, algo_deinit_internal, get_hist_bin, set_hist_bin, get_y_zone
 *   A (cont.): tisp_ae_algo_init
 *   B: tisp_ae_g_scene_luma, s_comp, api_set_exp_list, tisp_s_ae_explist, tisp_s_ae_exprinfo_attr,
 *      tisp_s_ae_scence_attr, tisp_g_ae_scence_attr, tisp_g_ae_exprinfo_attr
 * Context: pstMainAeOri / pstSecAeOri (0x164 bytes of pointers to the live AE objects, filled by tisp_ae_params_transmit),
 * the two stM/SAeOuter pointers, the per-channel ae_cache block and the tisp_tattr copy.
 *
 * Differences to the OEM, none visible to a correct caller:
 *  - T40_AE_OK(): every context pointer that is dereferenced is tested first and the call returns -EINVAL (or zeroed
 *    outputs for the getters) instead of an oops when the AE is not set up yet.  The oracle builds with T40_AE_OK == 1.
 *  - Return values the OEM leaves as a stale register (g_luma, g_comp, ev_start_set, deinit... see each function) are fixed.
 *  - Bounds: the OEM indexes ae_cache / tparamsN / ta_custom_en with the raw channel; the callers pass 0 or 1.
 *
 * Includer provides: stdint, string.h, EINVAL, the storage objects named below, T40_AE_OK, T40_AE_LOCK/T40_AE_UNLOCK,
 * T40_AE_CACHE(ch) (the ae_cache block of a channel, 0 if unusable), and the callees tisp_ae_param_now_get,
 * tisp_ae_set_hardware_param, tisp_ae_par_calc, tisp_ae_set_exprinfo_attr, fix_point_div_32, fix_point_mult2_32, tisp_log2_fixed_to_fixed;
 * tisp_ae_{main,sec}_ctrls_storage, tisp_par_info, tisp_tattr for the exposure info calls.
 * Offsets verified against the vendor-image module; tisp_ae_sensor_trig / tisp_ae_ev_start_set are checked against the
 * factory Eufy module (the vendor image moved the ae_cache fields; this driver uses the factory layout).
 */
#ifndef TX_ISP_T40_AE_LEAF_H
#define TX_ISP_T40_AE_LEAF_H

static inline uint8_t *t40_ae_ctx(uint32_t ch)
{
    return ch ? pstSecAeOri_storage : pstMainAeOri_storage;
}

static inline uint32_t t40_ae_w(const uint8_t *base, uint32_t off)
{
    return *(const uint32_t *)(base + off);
}

static inline uint8_t *t40_ae_p(const uint8_t *base, uint32_t off)
{
    return (uint8_t *)(uintptr_t)t40_ae_w(base, off);
}

static inline uint32_t t40_ae_h(const uint8_t *base, uint32_t off)
{
    return *(const uint16_t *)(base + off);
}

/* OEM tisp_ae_g_luma: mean luma = sum(i * hist[i]) / (zone width * height * ... from the geometry halfwords +2/+6/+8/+38).
 * The OEM returns the divisor in v0 and divides by zero for an empty geometry (undefined result); the C writes 0. */
int32_t tisp_ae_g_luma(int32_t arg1, uint8_t *arg2)
{
    const uint8_t *ctx = t40_ae_ctx((uint32_t)arg1);
    const uint8_t *geo = t40_ae_p(ctx, 284);
    const uint32_t *hist = (const uint32_t *)t40_ae_p(ctx, 104);
    uint32_t acc = 0, div, i;

    if (!arg2)
        return -EINVAL;
    if (!T40_AE_OK(geo) || !T40_AE_OK(hist)) {
        *arg2 = 0;
        return 0;
    }
    for (i = 0; i < 256; i++)
        acc += i * hist[i];
    div = t40_ae_h(geo, 2) * t40_ae_h(geo, 6) * t40_ae_h(geo, 8) * t40_ae_h(geo, 38);
    *arg2 = div ? (uint8_t)(acc / div) : 0;
    return 0;
}

/* OEM tisp_ae_g_comp: *a1 = (u8) **(u32 **)(ctx + 276).  The OEM returns the loaded word; the callers ignore it. */
char tisp_ae_g_comp(uint32_t a0, uintptr_t a1)
{
    const uint8_t *ctx = t40_ae_ctx(a0);
    const uint32_t *p = (const uint32_t *)t40_ae_p(ctx, 276);
    uint8_t v = T40_AE_OK(p) ? (uint8_t)*p : 0;

    if (a1)
        *(uint8_t *)a1 = v;
    return (char)v;
}

/* OEM tisp_ae_get_state: out-of-line status words of the AE (stM/SAeOuter -> halfwords +298 / +296 / +300). */
uint32_t tisp_ae_get_state(uint32_t a0, uintptr_t a1, uintptr_t a2, uintptr_t a3)
{
    const uint8_t *p = (const uint8_t *)(uintptr_t)(a0 ? stSecAeOuter : stMainAeOuter);
    uint32_t v;

    if (!T40_AE_OK(p)) {
        *(uint8_t *)a1 = 0;
        *(uint32_t *)a2 = 0;
        *(uint32_t *)a3 = 0;
        return 0;
    }
    *(uint8_t *)a1 = t40_ae_h(p, 298) != 0;
    *(uint32_t *)a2 = t40_ae_h(p, 296);
    v = t40_ae_h(p, 300);
    *(uint32_t *)a3 = v;
    return v;
}

/* OEM tisp_ae_sensor_trig (factory layout): ae_cache[ch] + 0x50c = 1 (sensor integration-time trigger flag). */
int32_t tisp_ae_sensor_trig(int32_t arg1)
{
    uint8_t *cache = (uint8_t *)(uintptr_t)T40_AE_CACHE((uint32_t)arg1);

    if (!T40_AE_OK(cache))
        return -EINVAL;
    cache[1292] = 1;
    return 0;
}

/* OEM tisp_ae_ev_start_set (factory module): ctx+264 -> u32 = a2, ctx+260 -> u8 = a1; a1 == 1 also arms the three update
 * flags ctx+152 / +176 / +192.  The previous lift additionally wrote ae_cache[ch << 2] + 1297 (shifted channel; only the vendor
 * image has such a store, at another layout): dropped.  The OEM returns a stale register; the C returns NULL. */
int32_t *tisp_ae_ev_start_set(uint32_t a0, uint32_t a1, uint32_t a2)
{
    const uint8_t *ctx = t40_ae_ctx(a0);

    if (!T40_AE_OK(t40_ae_w(ctx, 264)) || !T40_AE_OK(t40_ae_w(ctx, 260)) || (a1 == 1U && (!T40_AE_OK(t40_ae_w(ctx, 152)) ||
        !T40_AE_OK(t40_ae_w(ctx, 176)) || !T40_AE_OK(t40_ae_w(ctx, 192)))))
        return NULL;
    *(uint32_t *)t40_ae_p(ctx, 264) = a2;
    *t40_ae_p(ctx, 260) = (uint8_t)a1;
    if (a1 == 1) {
        *t40_ae_p(ctx, 152) = (uint8_t)a1;
        *t40_ae_p(ctx, 176) = (uint8_t)a1;
        *t40_ae_p(ctx, 192) = (uint8_t)a1;
    }
    return NULL;
}

/* OEM tisp_ae_algo_deinit_internal: a custom-algorithm slot in state 1 goes back to 0.  Returns 1 (the OEM leaves 1 in v0). */
int32_t tisp_ae_algo_deinit_internal(int32_t arg1)
{
    if (ta_custom_en[arg1 ? 1 : 0] == 1)
        ta_custom_en[arg1 ? 1 : 0] = 0;
    return 1;
}

/* OEM tisp_ae_get_hist_bin / set_hist_bin: the last histogram (1052 bytes, threshold word at +1044) under the hist lock.
 * Channel 0 is main in both (the earlier lift of set_hist_bin had them swapped; fixed in a previous step). */
int32_t tisp_ae_get_hist_bin(int32_t arg1, int32_t arg2)
{
    uint32_t flags = 0;

    T40_AE_LOCK(arg1 ? &sec_slock_hist : &main_slock_hist, &flags);
    memcpy((void *)(uintptr_t)arg2, arg1 ? tisp_ae_sec_hist_last : tisp_ae_main_hist_last, 1052);
    T40_AE_UNLOCK(arg1 ? &sec_slock_hist : &main_slock_hist, flags);
    return 0;
}

int32_t tisp_ae_set_hist_bin(int32_t arg1, int32_t arg2)
{
    uint32_t flags = 0;

    T40_AE_LOCK(arg1 ? &sec_slock_hist : &main_slock_hist, &flags);
    memcpy((arg1 ? tisp_ae_sec_hist_last : tisp_ae_main_hist_last) + 1044, (const void *)(uintptr_t)arg2, 4);
    T40_AE_UNLOCK(arg1 ? &sec_slock_hist : &main_slock_hist, flags);
    return 0;
}

/* OEM tisp_ae_get_y_zone: copy of the 15 x 15 zone luma table (ctx + 140) under the AE lock; zeros when it is not set up. */
int32_t tisp_ae_get_y_zone(uint32_t a0, uint32_t a1)
{
    const uint8_t *ctx = t40_ae_ctx(a0);
    const uint8_t *zone = t40_ae_p(ctx, 140);
    uint32_t flags = 0;

    T40_AE_LOCK(a0 ? &sec_slock : &main_slock, &flags);
    if (T40_AE_OK(zone))
        memcpy((void *)(uintptr_t)a1, zone, 900);
    else
        memset((void *)(uintptr_t)a1, 0, 900);
    T40_AE_UNLOCK(a0 ? &sec_slock : &main_slock, flags);
    return 0;
}

/* OEM tisp_ae_g_scene_luma: scene luma = 1..8 weighted mean of a 15 entry history ring (ctx+56), newest entry
 * fix_point_div(table[idx + 1] * hist_ratio, mean luma) >> 2.  Returns the result like the OEM (v0 of the final divide). */
uint32_t tisp_ae_g_scene_luma(uint32_t a0, uintptr_t a1)
{
    const uint8_t *ctx = t40_ae_ctx(a0);
    const uint8_t *p_sh = t40_ae_p(ctx, 4), *p_idx = t40_ae_p(ctx, 288), *geo = t40_ae_p(ctx, 284);
    const uint32_t *hist = (const uint32_t *)t40_ae_p(ctx, 104), *tbl = (const uint32_t *)t40_ae_p(ctx, 208);
    uint32_t *r = (uint32_t *)t40_ae_p(ctx, 56);
    uint32_t sh, idx, hsum, area, num, q, t5, i, acc = 0;
    uint8_t lum = 0;

    if (!a1 || !T40_AE_OK(p_sh) || !T40_AE_OK(p_idx) || !T40_AE_OK(geo) || !T40_AE_OK(hist) || !T40_AE_OK(r) || !T40_AE_OK(tbl))
        return 0;
    sh = t40_ae_h(p_sh, 0);
    idx = t40_ae_h(p_idx, 20);
    hsum = ((hist[0] >> 1) & 0x3fffffffU) + (hist[255] & 0x3fffffffU);
    area = t40_ae_h(geo, 2) * t40_ae_h(geo, 6) * t40_ae_h(geo, 8) * t40_ae_h(geo, 38);
    num = hsum < area ? area - hsum : 1;
    q = (uint32_t)fix_point_div_32((int32_t)sh, (int32_t)(num << (sh & 31)), (int32_t)(area << (sh & 31)));
    t5 = (uint32_t)fix_point_mult2_32((int32_t)sh, (int32_t)tbl[idx + 1], (int32_t)q);
    if (!t5)
        t5 = 1;
    tisp_ae_g_luma((int32_t)a0, &lum);
    if (!lum)
        lum = 1;
    for (i = 0; i < 14; i++)
        r[i] = r[i + 1];
    r[14] = (uint32_t)fix_point_div_32((int32_t)sh, (int32_t)t5, (int32_t)((uint32_t)lum << (sh & 31))) >> 2;
    for (i = 1; i <= 8; i++)
        acc += i * r[i - 1];
    acc /= 36;
    *(uint32_t *)a1 = acc;
    return acc;
}

/* OEM tisp_ae_s_comp: AE target compensation (128 = 1.0, 255 = 3.34x) into the target word at ctx+328 +4, then
 * tisp_ae_set_hardware_param(ctx, ch) (tail call in the OEM).  The OEM divides the signed product a1 * 300; the previous
 * C divided it unsigned (different only for a1 * 300 >= 2^31). */
int32_t tisp_ae_s_comp(uint32_t a0, uint32_t a1)
{
    uint8_t *ctx = t40_ae_ctx(a0);
    uint32_t base;
    int32_t target;

    if (!T40_AE_OK(t40_ae_w(ctx, 276)) || !T40_AE_OK(t40_ae_w(ctx, 328)) || !T40_AE_OK(t40_ae_w(ctx, 160)) ||
        !T40_AE_OK(t40_ae_w(ctx, 164)) || !T40_AE_OK(tparamsN[a0 ? 1 : 0]))
        return -EINVAL;
    base = t40_ae_h((const uint8_t *)tparamsN[a0 ? 1 : 0], 1024);
    *(uint32_t *)t40_ae_p(ctx, 276) = a1;
    if (a1 < 129U)
        target = (int32_t)(base * a1) >> 7;
    else
        target = (int32_t)base + (int32_t)(a1 * 300U) / 127 - 302;
    *(uint16_t *)(t40_ae_p(ctx, 328) + 4) = (uint16_t)target;
    *t40_ae_p(ctx, 160) = 1;
    *t40_ae_p(ctx, 164) = 1;
    return (int32_t)tisp_ae_set_hardware_param((uintptr_t)ctx, a0 & 0xffU);
}

/* OEM tisp_ae_api_set_exp_list: SetAeExpList.  Flags ctx+160/+164 = 1, ctx+172 = 0, AE mode halfword *(ctx+4)+6 = mode; for
 * mode 1 the 16 ladder entries (4 words of every 5 word source entry) go to ctx+348 (the pointer is re-read for every store
 * like the OEM); then tisp_ae_par_calc(ch & 0xff, ctx). */
int32_t tisp_ae_api_set_exp_list(uint32_t a0, uint32_t a1, uintptr_t a2)
{
    uint8_t *ctx = t40_ae_ctx(a0);
    const uint32_t *src = (const uint32_t *)a2;
    uint32_t i;

    if (!T40_AE_OK(t40_ae_w(ctx, 160)) || !T40_AE_OK(t40_ae_w(ctx, 164)) || !T40_AE_OK(t40_ae_w(ctx, 172)) ||
        !T40_AE_OK(t40_ae_w(ctx, 4)) || (a1 == 1U && (!T40_AE_OK(t40_ae_w(ctx, 348)) || !T40_AE_OK(src))))
        return -EINVAL;
    *t40_ae_p(ctx, 160) = 1;
    *t40_ae_p(ctx, 164) = 1;
    *t40_ae_p(ctx, 172) = 0;
    *(uint16_t *)(t40_ae_p(ctx, 4) + 6) = (uint16_t)a1;
    if (a1 == 1U) {
        for (i = 0; i < 16U; i++) {
            *(uint32_t *)(t40_ae_p(ctx, 348) + 16U * i) = src[5U * i];
            *(uint32_t *)(t40_ae_p(ctx, 348) + 16U * i + 4U) = src[5U * i + 1U];
            *(uint32_t *)(t40_ae_p(ctx, 348) + 16U * i + 8U) = src[5U * i + 2U];
            *(uint32_t *)(t40_ae_p(ctx, 348) + 16U * i + 12U) = src[5U * i + 3U];
        }
    }
    tisp_ae_par_calc(a0 & 0xffU, (uintptr_t)ctx);
    return 0;
}

/* OEM tisp_s_ae_explist: buf = { mode, 25 entries ... } -> tisp_ae_api_set_exp_list(ch, mode, buf + 4) (tail call). */
int32_t tisp_s_ae_explist(uint32_t a0, uintptr_t a1)
{
    const uint32_t *l = (const uint32_t *)a1;

    if (!T40_AE_OK(l))
        return -EINVAL;
    return tisp_ae_api_set_exp_list(a0, l[0], a1 + 4);
}

/* OEM tisp_s_ae_exprinfo_attr: the app's exposure info block into the tuning attribute copy (tisp_tattr + ch * 220), then
 * tisp_ae_set_exprinfo_attr(ch, buf). */
int32_t tisp_s_ae_exprinfo_attr(uint32_t a0, uintptr_t a1)
{
    const uint32_t *in = (const uint32_t *)a1;
    uint8_t *v = (uint8_t *)(uintptr_t)tisp_tattr + a0 * 220U;
    uint32_t i;

    if (!T40_AE_OK(in) || !T40_AE_OK(tisp_tattr))
        return -EINVAL;
    *(uint32_t *)(v + 16) = in[0];
    for (i = 0; i < 8; i++)
        *(uint32_t *)(v + 56 + 4 * i) = in[10 + i];
    for (i = 0; i < 7; i++)
        *(uint32_t *)(v + 156 + 4 * i) = in[35 + i];
    *(uint32_t *)(v + 184) = in[42];
    tisp_ae_set_exprinfo_attr(a0, a1);
    return 0;
}

/* OEM tisp_s_ae_scence_attr: SetAeScene.  in = { mode_x, x_zone, mode_y, y_zone, comp mode, comp value, ev mode, ev value ... }
 * as the words/bytes below; writes the AE scene control words (*(ctx+320)), the zone sizes (*(ctx+324)) and calls
 * tisp_ae_s_comp / tisp_ae_ev_start_set. */
int64_t tisp_s_ae_scence_attr(uint32_t a0, uintptr_t a1)
{
    const uint8_t *in = (const uint8_t *)a1;
    uint8_t *ctx = (uint8_t *)tisp_ae_param_now_get((int32_t)a0);
    uint32_t *c0, m;
    uint16_t *c4;
    uint32_t v;

    if (!T40_AE_OK(in) || !T40_AE_OK(ctx) || !T40_AE_OK(t40_ae_w(ctx, 320)) || !T40_AE_OK(t40_ae_w(ctx, 324)))
        return -EINVAL;
    c0 = (uint32_t *)t40_ae_p(ctx, 320);
    c4 = (uint16_t *)t40_ae_p(ctx, 324);
    m = t40_ae_w(in, 0);
    if (m == 1U) {
        c4[5] = 1;
        c0[5] = 1;
        c0[6] = 1;
    } else if (m == 3U) {
        c0[0] = 1;
        c4[5] = (uint16_t)(in[4] + 1U);
    } else if (m == 2U) {
        c0[0] = 1;
        c0[5] = 1;
        c0[6] = in[4] + 1U;
    }
    m = t40_ae_w(in, 8);
    if (m == 1U) {
        c4[4] = 1;
        c0[7] = 1;
        c0[8] = 1;
    } else if (m == 3U) {
        c0[0] = 1;
        c4[4] = (uint16_t)(in[12] + 1U);
    } else if (m == 2U) {
        c0[0] = 1;
        c0[7] = in[12] + 1U;
        c0[8] = 1;
    }
    v = t40_ae_w(in, 16);
    if (v == 1U)
        tisp_ae_s_comp(a0, 128);
    else if (v - 2U < 2U)
        tisp_ae_s_comp(a0, t40_ae_h(in, 20));
    tisp_ae_ev_start_set(a0, t40_ae_w(in, 24) == 1U ? 0U : 1U, t40_ae_w(in, 28));
    return 0;
}

/* OEM tisp_g_ae_scence_attr: GetAeScene, 52 bytes: [0] mode_x, [4] x zone - 1, [8] mode_y, [12] y zone - 1, [16] comp mode,
 * [20] comp, [24] ev mode, [28] ev value, [32] luma, [36] scene luma, [40] stable flag, [44] state word, [48] state word 2. */
int64_t tisp_g_ae_scence_attr(uint32_t a0, uintptr_t a1)
{
    uint8_t *out = (uint8_t *)a1;
    const uint8_t *ctx = (const uint8_t *)tisp_ae_param_now_get((int32_t)a0);
    const uint32_t *c0;
    const uint8_t *c4;
    uint8_t comp = 0, lum = 0;
    uint32_t m;

    if (!T40_AE_OK(out) || !T40_AE_OK(ctx) || !T40_AE_OK(t40_ae_w(ctx, 320)) || !T40_AE_OK(t40_ae_w(ctx, 324)) ||
        !T40_AE_OK(t40_ae_w(ctx, 260)) || !T40_AE_OK(t40_ae_w(ctx, 264)))
        return -EINVAL;
    c0 = (const uint32_t *)t40_ae_p(ctx, 320);
    c4 = t40_ae_p(ctx, 324);
    m = c0[0];
    if (m == 0U) {
        *(uint32_t *)(out + 0) = 1;
        out[4] = 0;
        *(uint32_t *)(out + 8) = 1;
        out[12] = 0;
    } else if (m == 1U) {
        *(uint32_t *)(out + 0) = 3;
        out[4] = (uint8_t)(c4[10] - 1U);
        *(uint32_t *)(out + 8) = 3;
        out[12] = (uint8_t)(c4[8] - 1U);
    } else if (m == 2U) {
        *(uint32_t *)(out + 0) = 2;
        out[4] = (uint8_t)(c0[6] - 1U);
        *(uint32_t *)(out + 8) = 2;
        out[12] = (uint8_t)(c0[7] - 1U);
    }
    tisp_ae_g_comp(a0, (uintptr_t)&comp);
    *(uint32_t *)(out + 20) = comp;
    *(uint32_t *)(out + 16) = comp == 128 ? 1U : 3U;
    if (*t40_ae_p(ctx, 260) == 1) {
        *(uint32_t *)(out + 24) = 3;
        *(uint32_t *)(out + 28) = *(const uint32_t *)t40_ae_p(ctx, 264);
    } else {
        *(uint32_t *)(out + 24) = 1;
        *(uint32_t *)(out + 28) = 0;
    }
    tisp_ae_g_luma((int32_t)a0, &lum);
    *(uint32_t *)(out + 32) = lum;
    tisp_ae_g_scene_luma(a0, (uintptr_t)(out + 36));
    tisp_ae_get_state(a0, (uintptr_t)(out + 40), (uintptr_t)(out + 44), (uintptr_t)(out + 48));
    return 0;
}

/* OEM tisp_g_ae_exprinfo_attr: GetAeExprInfo, 55 words from the AE control words (tisp_ae_{main,sec}_ctrls) and the cached
 * attribute (tisp_tattr + ch * 220); the integration times are converted back to microseconds (times the line time k =
 * 1000000 * (par44 & 0xffff) / ((par70 * par44) >> 16)) when the cached "unit" word (tattr + 16) is set.  Mirror of
 * tisp_s_ae_exprinfo_attr.  The OEM divides by zero for an empty line time (undefined result); the C uses 0 there.  Channels
 * above 1 are refused (the OEM would index tisp_par_info / tisp_tattr beyond their two entries). */
int32_t tisp_g_ae_exprinfo_attr(uint32_t a0, uintptr_t a1)
{
    const uint32_t *c = a0 ? tisp_ae_sec_ctrls_storage : tisp_ae_main_ctrls_storage;
    const uint8_t *tb = (const uint8_t *)(uintptr_t)tisp_tattr;
    const uint8_t *pi = tisp_par_info + a0 * 152U;
    uint32_t p44, den, k, unit, i;
    uint32_t *o = (uint32_t *)a1;
    const uint8_t *t;

    if (a0 > 1U || !T40_AE_OK(o) || !T40_AE_OK(tb))
        return -EINVAL;
    p44 = *(const uint32_t *)(pi + 44);
    den = (t40_ae_h(pi, 70) * p44) >> 16;
    k = den ? ((p44 & 0xffffU) * 1000000U) / den : 0;
    t = tb + a0 * 220U;
    unit = *(const uint32_t *)(t + 16);
#define T40_M(v) (unit ? k * (v) : (v))
    o[0] = unit;
    o[1] = c[0]; o[2] = c[13]; o[3] = c[14]; o[4] = c[36]; o[5] = c[15];
    o[6] = T40_M(c[3]); o[7] = c[1]; o[8] = c[2]; o[9] = c[4];
    for (i = 0; i < 8; i++)
        o[10 + i] = *(const uint32_t *)(t + 56 + 4 * i);
    o[18] = T40_M(c[30]); o[19] = c[28]; o[20] = c[29]; o[21] = c[31];
    o[22] = T40_M(c[7]); o[23] = c[5]; o[24] = c[6]; o[25] = c[8];
    o[26] = c[24]; o[27] = c[16]; o[28] = c[17]; o[29] = c[37]; o[30] = c[26];
    o[31] = T40_M(c[19]); o[32] = c[18]; o[33] = c[25]; o[34] = c[27];
    for (i = 0; i < 8; i++)
        o[35 + i] = *(const uint32_t *)(t + 156 + 4 * i);
    o[43] = T40_M(c[33]); o[44] = c[32]; o[45] = c[34]; o[46] = c[35];
    o[47] = T40_M(c[21]); o[48] = c[20]; o[49] = c[22]; o[50] = c[23];
    o[51] = c[10]; o[52] = c[39]; o[53] = c[9] >> 10;
    o[54] = (uint32_t)tisp_log2_fixed_to_fixed(c[9], 10, 16);
#undef T40_M
    return 0;
}

/* OEM tisp_ae_algo_init: arms (arg2 == 1) or disarms the custom AE algorithm slot of a channel and, when arming, fills the
 * init attribute `u` for the algorithm from the AE control words and the last histogram: 25 control words, then the 24 byte
 * block at u + 112 { 1, 1, 1, hist[1048], hist[1049], 2 bytes the OEM copies from uninitialised stack (zero here), 0,
 * hist threshold word hist[1044] }.  The OEM leaves a stale register as return value; the C returns NULL. */
int32_t *tisp_ae_algo_init(int32_t arg1, int32_t arg2, void *arg3)
{
    const uint32_t *c = arg1 ? tisp_ae_sec_ctrls_storage : tisp_ae_main_ctrls_storage;
    const uint8_t *hist = arg1 ? tisp_ae_sec_hist_last : tisp_ae_main_hist_last;
    uint32_t *u = (uint32_t *)arg3;
    uint8_t t[24];

    ta_custom_en[arg1 ? 1 : 0] = arg2;
    if (arg2 != 1 || !T40_AE_OK(u))
        return NULL;
    u[2] = 0;
    u[3] = c[3]; u[4] = c[1]; u[5] = c[2]; u[6] = c[4];
    u[15] = c[19]; u[16] = c[18]; u[17] = c[25]; u[18] = c[27];
    u[12] = c[5]; u[13] = c[6]; u[11] = c[7]; u[14] = c[8];
    u[24] = c[20]; u[23] = c[21]; u[25] = c[22]; u[26] = c[23];
    u[8] = c[28]; u[9] = c[29]; u[7] = c[30]; u[10] = c[31];
    u[20] = c[32]; u[19] = c[33]; u[21] = c[34]; u[22] = c[35];
    memset(t, 0, sizeof(t));
    t[0] = t[4] = t[8] = 1;
    t[12] = hist[1048];
    t[13] = hist[1049];
    memcpy(t + 20, hist + 1044, 4);
    memcpy(u + 28, t, sizeof(t));
    return NULL;
}

#endif /* TX_ISP_T40_AE_LEAF_H */
