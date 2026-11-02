/*
 * T40 CLM (colour lookup) start-up from the sensor parameter bank: plain C (regtrace_clm_oem_init_lit below).
 * Default-off until live validation (enable_clm=1).  The generated mips2c literal chain of the OEM tisp_clm_* functions
 * (params_transmit / refresh / ct_interp / set_params, two 6.5 KB default tables, clm_stage_limit / clm_defer_trig) is removed (#85):
 * 0 of its instructions ran in the QEMU apitest + stream workload, it was only reachable through the clm_stage_limit debug
 * parameter (the legacy 420-word LUT format, documented as the unsafe stage-14 path) and the opt-in t40_ct_chains build.
 */
static bool regtrace_enable_clm;
static uint32_t regtrace_clm_stage_reached;
static int32_t regtrace_clm_last_ret;
static uint32_t regtrace_clm_ct = 5000U;
static uint32_t regtrace_clm_ct_now = 5000U;
static uint32_t regtrace_clm_ct_region;
module_param_named(enable_clm, regtrace_enable_clm, bool, 0644);
module_param_named(clm_stage_reached, regtrace_clm_stage_reached, uint, 0444);
module_param_named(clm_last_ret, regtrace_clm_last_ret, int, 0444);
module_param_named(clm_ct, regtrace_clm_ct, uint, 0644);
module_param_named(clm_ct_now, regtrace_clm_ct_now, uint, 0444);
module_param_named(clm_ct_region, regtrace_clm_ct_region, uint, 0444);

static uint8_t regtrace_clm_h_interp_lit[1050];
static uint16_t regtrace_clm_s_interp_lit[1050];

static int32_t regtrace_clm_oem_init_lit(const uint8_t *nbuf, uint32_t stream);

static int32_t regtrace_clm_main_init_lit(void)
{
    uint32_t nbuf = *(uint32_t *)((char *)&tparamsN);

    regtrace_clm_stage_reached = 0;
    regtrace_clm_last_ret = 0;
    if (!nbuf) {
        regtrace_clm_last_ret = -ENOENT;
        return -ENOENT;
    }
    /* The stock T40 tisp_clm_init() sequence: write_csc_para -> ct_interp(5000) -> real_write_lut.  real_write_lut packs five
     * 7-bit hue and five 9-bit saturation values into two writes per CLM port and commits 210 groups with 0x00d10102. */
    return regtrace_clm_oem_init_lit((const uint8_t *)(uintptr_t)nbuf, 0);
}

/*
 * Compact, literal implementation of the stock T40 CLM startup path.
 *
 * The sensor parameter bank begins at nbuf.  tisp_clm_init() copies the
 * 18,924-byte CLM record at +0x123ac.  The T40 record does not lay out each
 * hue table next to its saturation table: the normal-mode pointer graph is
 *
 *   high: h +6,    s +6312
 *   mid:  h +7362, s +8412
 *   low:  h +1056, s +10512
 *
 * with the descending CT triplet at +18912.  Keep that OEM mapping here;
 * treating +1056 as the high-CT saturation table reads hue bytes as signed
 * saturation words and produces a conspicuously over-saturated image.
 */
static int32_t regtrace_clm_interp_lit(int32_t low, int32_t high,
                                      uint32_t numerator,
                                      uint32_t denominator)
{
    uint32_t magnitude;

    if (!denominator || low == high)
        return low;
    if (low < high) {
        magnitude = (uint32_t)(high - low) * numerator / denominator;
        return low + (int32_t)magnitude;
    }
    magnitude = (uint32_t)(low - high) * numerator / denominator;
    return low - (int32_t)magnitude;
}

static int32_t regtrace_clm_oem_init_lit(const uint8_t *nbuf, uint32_t stream)
{
    const uint8_t *clm = nbuf + 0x123acU;
    const uint8_t *h_high = clm + 6U;
    const uint16_t *s_high =
        (const uint16_t *)(const void *)(clm + 6312U);
    const uint8_t *h_mid = clm + 7362U;
    const uint16_t *s_mid =
        (const uint16_t *)(const void *)(clm + 8412U);
    const uint8_t *h_low = clm + 1056U;
    const uint16_t *s_low =
        (const uint16_t *)(const void *)(clm + 10512U);
    const uint16_t *ct_list =
        (const uint16_t *)(const void *)(clm + 18912U);
    const uint8_t *hue;
    const uint16_t *sat;
    uint32_t port_h_lo, port_h_hi, port_s_lo, port_s_hi;
    uint32_t ctrl_mode, ctrl_trig;
    uint32_t ct = regtrace_clm_ct;
    uint32_t numerator = 0, denominator = 0;
    const uint8_t *h_from = NULL, *h_to = NULL;
    const uint16_t *s_from = NULL, *s_to = NULL;
    uint32_t i, j;

    /*
     * Literal T40 CT regions use a 100 K hold band around the middle
     * anchor.  Region numbering matches tisp_ct_clm_interpolation():
     * 0 high, 1 high/mid, 2 mid, 3 mid/low, 4 low.
     */
    if (ct > (uint32_t)ct_list[0] - 100U) {
        regtrace_clm_ct_region = 0U;
        hue = h_high;
        sat = s_high;
    } else if (ct > (uint32_t)ct_list[1] + 100U) {
        regtrace_clm_ct_region = 1U;
        h_from = h_mid;
        h_to = h_high;
        s_from = s_mid;
        s_to = s_high;
        numerator = ct - ((uint32_t)ct_list[1] + 100U);
        denominator = ((uint32_t)ct_list[0] - 100U) -
                      ((uint32_t)ct_list[1] + 100U);
        hue = regtrace_clm_h_interp_lit;
        sat = regtrace_clm_s_interp_lit;
    } else if (ct > (uint32_t)ct_list[1] - 100U) {
        regtrace_clm_ct_region = 2U;
        hue = h_mid;
        sat = s_mid;
    } else if (ct > (uint32_t)ct_list[2] + 100U) {
        regtrace_clm_ct_region = 3U;
        h_from = h_low;
        h_to = h_mid;
        s_from = s_low;
        s_to = s_mid;
        numerator = ct - ((uint32_t)ct_list[2] + 100U);
        denominator = ((uint32_t)ct_list[1] - 100U) -
                      ((uint32_t)ct_list[2] + 100U);
        hue = regtrace_clm_h_interp_lit;
        sat = regtrace_clm_s_interp_lit;
    } else {
        regtrace_clm_ct_region = 4U;
        hue = h_low;
        sat = s_low;
    }
    regtrace_clm_ct_now = ct;

    if (h_from) {
        for (i = 0; i < 1050U; ++i) {
            regtrace_clm_h_interp_lit[i] = (uint8_t)
                regtrace_clm_interp_lit((int8_t)h_from[i],
                                        (int8_t)h_to[i],
                                        numerator, denominator);
            regtrace_clm_s_interp_lit[i] = (uint16_t)
                regtrace_clm_interp_lit((int16_t)s_from[i],
                                        (int16_t)s_to[i],
                                        numerator, denominator);
        }
    }

    if (stream == 0) {
        port_h_lo = 0x500c0U;
        port_h_hi = 0x500e0U;
        port_s_lo = 0x50100U;
        port_s_hi = 0x50120U;
        ctrl_mode = 0x12004U;
        ctrl_trig = 0x12000U;
    } else if (stream == 1) {
        port_h_lo = 0x500d0U;
        port_h_hi = 0x500f0U;
        port_s_lo = 0x50110U;
        port_s_hi = 0x50130U;
        ctrl_mode = 0x12084U;
        ctrl_trig = 0x12080U;
    } else {
        regtrace_clm_last_ret = -EINVAL;
        return -EINVAL;
    }

    /* CLM_CSC_BT709_FULL after the OEM fixed-point conversion. */
    if (stream == 0) {
        (void)system_reg_write(0x12008U, 0x076c064dU);
        (void)system_reg_write(0x1200cU, 0x01df00c0U);
        (void)system_reg_write(0x12010U, 0x0080631dU);
        (void)system_reg_write(0x12014U, 0x000c7480U);
        (void)system_reg_write(0x12018U, 0x01000000U);
    } else {
        (void)system_reg_write(0x12088U, 0x076c064dU);
        (void)system_reg_write(0x1208cU, 0x01df00c0U);
        (void)system_reg_write(0x12090U, 0x0080631dU);
        (void)system_reg_write(0x12094U, 0x000c7480U);
        (void)system_reg_write(0x12098U, 0x01000000U);
    }
    (void)system_reg_write(ctrl_trig, 1U);
    regtrace_clm_stage_reached = 15;

    (void)system_reg_write(port_h_lo, 0x101U);
    (void)system_reg_write(port_h_hi, 0x101U);
    (void)system_reg_write(port_s_lo, 0x101U);
    (void)system_reg_write(port_s_hi, 0x101U);
    regtrace_clm_stage_reached = 16;

    for (i = 0; i < 1050U; i += 35U) {
        for (j = 0; j < 7U; ++j) {
            const uint8_t *h = hue + i + j * 5U;
            const uint16_t *s = sat + i + j * 5U;
            uint32_t h0, h1;
            uint32_t s0, s1;

            h0 = ((uint32_t)h[0] & 0x7fU) |
                 (((uint32_t)h[1] << 7) & 0x00003f80U) |
                 (((uint32_t)h[2] << 14) & 0x001fc000U) |
                 (((uint32_t)h[3] << 21) & 0x0fe00000U) |
                 ((uint32_t)h[4] << 28);
            h1 = ((uint32_t)h[4] >> 4) & 0x7U;

            s0 = ((uint32_t)s[0] & 0x1ffU) |
                 (((uint32_t)s[1] << 9) & 0x0003fe00U) |
                 (((uint32_t)s[2] << 18) & 0x07fc0000U) |
                 (((uint32_t)s[3] & 0x1fU) << 27);
            s1 = (((uint32_t)s[3] >> 5) & 0xfU) |
                 (((uint32_t)s[4] << 4) & 0x1ff0U);

            (void)system_reg_write(port_h_lo + 4U, h0);
            (void)system_reg_write(port_h_hi + 4U, h0);
            (void)system_reg_write(port_h_lo + 4U, h1);
            (void)system_reg_write(port_h_hi + 4U, h1);
            (void)system_reg_write(port_s_lo + 4U, s0);
            (void)system_reg_write(port_s_hi + 4U, s0);
            (void)system_reg_write(port_s_lo + 4U, s1);
            (void)system_reg_write(port_s_hi + 4U, s1);
        }
    }

    (void)system_reg_write(port_h_lo, 0x00d10102U);
    (void)system_reg_write(port_h_hi, 0x00d10102U);
    (void)system_reg_write(port_s_lo, 0x00d10102U);
    (void)system_reg_write(port_s_hi, 0x00d10102U);
    regtrace_clm_stage_reached = 17;

    (void)system_reg_write(ctrl_mode,
                           (uint32_t)(*(const uint16_t *)(const void *)clm) &
                           0x7ffU);
    regtrace_clm_last_ret = system_reg_write(ctrl_trig, 1U);
    regtrace_clm_stage_reached = 18;
    printk(KERN_INFO
           "tx_isp_t40_recovered: clm-oem-init stream=%u ct=%u region=%u anchors=%u/%u/%u mode=0x%x stage=%u ret=%d\n",
           stream, ct, regtrace_clm_ct_region,
           (uint32_t)ct_list[0], (uint32_t)ct_list[1],
           (uint32_t)ct_list[2],
           (uint32_t)(*(const uint16_t *)(const void *)clm) & 0x7ffU,
           regtrace_clm_stage_reached, regtrace_clm_last_ret);
    return regtrace_clm_last_ret;
}
