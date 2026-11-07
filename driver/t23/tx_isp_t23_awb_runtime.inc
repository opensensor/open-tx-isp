/* Active T23 Tiziano AWB path reconstructed from tx-isp-t23-hlil.txt. */

#include "tx_isp_t23_tuning_ext.h"
#include "tx_isp_t23_awb_cluster.h"

/* SetAwbCt: the colour temperature used in the manual WB mode (stock .bss
 * +31488), see t23x_awb_ct_select */
static uint32_t regtrace_t23_awb_custom_ct;

/*
 * Set/GetAwbClust and Set/GetAwbCtTrend objects (see t23x_awb_cluster_set):
 * the AWB run reads them under this mutex, the controls and the IQ bank
 * load write them under it.
 */
static DEFINE_MUTEX(t23x_awb_api_mutex);
/* the stock .bss of the cluster stage (never cleared, as in stock) */
static struct t23x_awb_cluster_state regtrace_t23_awb_cluster_state;
/* zone ratios as stock Tiziano_awb_fpga leaves them: raw rg / bg, 0 where
 * the zone has no green; per run, written by regtrace_t23_awb_hlil_calculate */
static uint32_t regtrace_t23_awb_raw_rg[T23X_CL_ZONES];
static uint32_t regtrace_t23_awb_raw_bg[T23X_CL_ZONES];
/* the cluster object of this run (picked like stock JZ_Isp_Awb) */
static uint32_t regtrace_t23_awb_cl_run[T23X_AWB_CLUSTER_WORDS];
/* ToleranceEn: the automatic Q8 gains the AWB follows (see the work) */
static uint32_t regtrace_t23_awb_tol_rg;
static uint32_t regtrace_t23_awb_tol_bg;
static bool regtrace_t23_awb_tol_valid;

static uint32_t regtrace_t23_awb_absdiff(uint32_t a, uint32_t b)
{
    return a < b ? b - a : a - b;
}

/*
 * Stock awb_interrupt_static -> tiziano_awb_set_lum_th_freq, on every AWB
 * statistics interrupt (core status bit 30, stock irq_func_cb[30]):
 *   0xb038 = par[176] << 16 | par[172] << 8 | max(1, min(wmean, par[168]) * s >> 10)
 * with _awb_parameter (IQ 0x1028, 180 bytes, stock tiziano_awb_params_refresh)
 * and wmean / s from stock tisp_ae_mean_update over the AE0 zone means of
 * the running AE (t23_aelift_mean_update).  The three IQ words are read
 * with the bank (stream start, day/night) since the interrupt cannot read
 * the file.  source_awb_lum_th=0 keeps the fixed startup value 0x0001f005.
 */
#define T23X_AWB_LUM_PAR_OFFSET (0x1028U + 168U)
static bool t23x_awb_lum_th_en = true;
module_param_named(source_awb_lum_th, t23x_awb_lum_th_en, bool, 0644);
MODULE_PARM_DESC(source_awb_lum_th,
                 "stock per-interrupt AWB luminance threshold 0xb038 from the AE mean (default 1); 0 = fixed startup value");
static DEFINE_SPINLOCK(t23x_awb_lum_lock);
/* [0] cap (+168), [1] bits 15:8 (+172), [2] bits 23:16 (+176) */
static uint32_t t23x_awb_lum_par[3];
static bool t23x_awb_lum_par_valid;
/* 0xb038 writes by the AWB interrupt, last value written */
static uint t23x_awb_lum_th_runs;
static uint t23x_awb_lum_th_last;
module_param_named(awb_lum_th_runs, t23x_awb_lum_th_runs, uint, 0444);
MODULE_PARM_DESC(awb_lum_th_runs, "AWB interrupts that rewrote 0xb038 (stock tiziano_awb_set_lum_th_freq)");
module_param_named(awb_lum_th_last, t23x_awb_lum_th_last, uint, 0444);
MODULE_PARM_DESC(awb_lum_th_last, "last 0xb038 value written by the AWB interrupt");

static bool t23_aelift_mean_update(uint32_t *mean, uint32_t *scale);

static void t23x_awb_lum_load_bank(void)
{
    uint32_t par[3];
    unsigned long flags;
    bool ok;

    ok = !regtrace_t23_read_tuning_data(T23X_AWB_LUM_PAR_OFFSET, par,
                                        sizeof(par));
    spin_lock_irqsave(&t23x_awb_lum_lock, flags);
    if (ok)
        memcpy(t23x_awb_lum_par, par, sizeof(par));
    t23x_awb_lum_par_valid = ok;
    spin_unlock_irqrestore(&t23x_awb_lum_lock, flags);
}

/* hard IRQ, after the AE0 handlers of the same interrupt */
static noinline void t23x_awb_set_lum_th_freq(void)
{
    uint32_t mean, scale, lum, val;

    if (!t23x_awb_lum_th_en)
        return;
    spin_lock(&t23x_awb_lum_lock);
    if (!t23x_awb_lum_par_valid ||
        !t23_aelift_mean_update(&mean, &scale)) {
        spin_unlock(&t23x_awb_lum_lock);
        return;
    }
    lum = (min(mean, t23x_awb_lum_par[0]) * scale) >> 10;
    if (!lum)
        lum = 1;
    val = (t23x_awb_lum_par[2] << 16) | (t23x_awb_lum_par[1] << 8) | lum;
    spin_unlock(&t23x_awb_lum_lock);
    /* stock system_reg_write_awb(1, ...): 0xb000 = 1 before the write */
    system_reg_write(0xb000U, 1U);
    system_reg_write(0xb038U, val);
    t23x_awb_lum_th_last = val;
    t23x_awb_lum_th_runs++;
}

/*
 * The cluster and trend objects from the active IQ bank, as stock
 * tiziano_awb_params_refresh (stream start, day/night switch): the IQ
 * status word and block become *_api_status[0] and *_api_para, the pending
 * user mark (status[1]) is cleared, and the live object follows the IQ block
 * unless its IQ status word is 2.  A SetAwbClust / SetAwbCtTrend before the
 * refresh is dropped, as in stock.  An unreadable bank leaves them as they
 * are.
 */
static void regtrace_t23_awb_api_load_bank(void)
{
    uint32_t cl_status, tr_status;
    uint32_t cl[T23X_AWB_CLUSTER_WORDS];
    uint32_t tr[T23X_AWB_TREND_WORDS];
    uint32_t *st;

    /* stock tiziano_awb_params_refresh also reloads _awb_parameter */
    t23x_awb_lum_load_bank();
    if (regtrace_t23_read_tuning_data(REGTRACE_T23_AWB_CLUSTER_STATUS_OFFSET,
                                      &cl_status, sizeof(cl_status)) ||
        regtrace_t23_read_tuning_data(REGTRACE_T23_AWB_CLUSTER_OFFSET, cl,
                                      sizeof(cl)) ||
        regtrace_t23_read_tuning_data(REGTRACE_T23_AWB_TREND_STATUS_OFFSET,
                                      &tr_status, sizeof(tr_status)) ||
        regtrace_t23_read_tuning_data(REGTRACE_T23_AWB_TREND_OFFSET, tr,
                                      sizeof(tr)))
        return;
    mutex_lock(&t23x_awb_api_mutex);
    st = (uint32_t *)(void *)awb_cluster_api_status;
    st[0] = cl_status;
    st[1] = 0;
    memcpy(awb_cluster_api_para, cl, sizeof(cl));
    if (cl_status != 2U)
        memcpy(_awb_cluster, cl, sizeof(cl));
    st = (uint32_t *)(void *)&awb_trend_api_status;
    st[0] = tr_status;
    st[1] = 0;
    memcpy(awb_trend_api_para, tr, sizeof(tr));
    if (tr_status != 2U)
        memcpy((void *)&_awb_trend, tr, sizeof(tr));
    mutex_unlock(&t23x_awb_api_mutex);
}

#define REGTRACE_T23_AWB_HLIL_COLS 15U
#define REGTRACE_T23_AWB_HLIL_ROWS 15U
#define REGTRACE_T23_AWB_HLIL_ZONES \
    (REGTRACE_T23_AWB_HLIL_COLS * REGTRACE_T23_AWB_HLIL_ROWS)

struct regtrace_t23_awb_hlil_snapshot {
    uint32_t r[REGTRACE_T23_AWB_HLIL_ZONES];
    uint32_t g[REGTRACE_T23_AWB_HLIL_ZONES];
    uint32_t b[REGTRACE_T23_AWB_HLIL_ZONES];
    uint32_t pixels[REGTRACE_T23_AWB_HLIL_ZONES];
    uint32_t bank;
    uint32_t snapshot;
    unsigned long stamp;    /* jiffies of the capture, 0 = none (GetAwbZone) */
};

struct regtrace_t23_awb_hlil_result {
    uint32_t rg;
    uint32_t bg;
    uint32_t ct;
    uint32_t active_zones;
    uint32_t light_source_zones;
};

static struct regtrace_t23_awb_hlil_snapshot
    regtrace_t23_awb_hlil_snapshot_data;
static uint32_t regtrace_t23_awb_hlil_ratio[REGTRACE_T23_AWB_HLIL_ZONES * 2U];
static uint32_t regtrace_t23_awb_hlil_pixel_weight[REGTRACE_T23_AWB_HLIL_ZONES];
static uint32_t regtrace_t23_awb_hlil_mesh_weight[REGTRACE_T23_AWB_HLIL_ZONES];
static uint32_t regtrace_t23_awb_hlil_distance[REGTRACE_T23_AWB_HLIL_ZONES];
static uint32_t regtrace_t23_awb_hlil_distance_weight[REGTRACE_T23_AWB_HLIL_ZONES];
static uint32_t regtrace_t23_awb_hlil_history_rg[15];
static uint32_t regtrace_t23_awb_hlil_history_bg[15];
static uint32_t regtrace_t23_awb_hlil_history_ct[15];
static uint32_t regtrace_t23_awb_hlil_history_count;
static bool regtrace_t23_awb_hlil_pending;
/* Set while a parameter-bank switch reloads the blocks; blocks new work. */
static bool regtrace_t23_awb_hlil_paused;
/* WB_GOL_STATIS r/b and WB_STATIS r/b ratios, Q8 (0x10000 / mf gain). */
static uint32_t regtrace_t23_awb_statis[4];
static DEFINE_SPINLOCK(regtrace_t23_awb_hlil_lock);

static void regtrace_t23_source_awb_hlil_work(struct work_struct *work);
TX_LS_TIMED_WORK(regtrace_t23_awb_hlil_work_timed, regtrace_t23_source_awb_hlil_work, T23_LS_WORK_AWB)
static DECLARE_WORK(regtrace_t23_source_awb_hlil_work_item,
                    regtrace_t23_awb_hlil_work_timed);

static uint32_t regtrace_t23_awb_hlil_mul_q(uint32_t left, uint32_t right)
{
    return (uint32_t)(((uint64_t)left * right) >>
                      REGTRACE_T23_AWB_HLIL_POINT_POSITION);
}

static uint32_t regtrace_t23_awb_hlil_div_q(uint64_t numerator,
                                            uint64_t denominator)
{
    if (!denominator)
        return 0;
    return (uint32_t)div64_u64(
        numerator << REGTRACE_T23_AWB_HLIL_POINT_POSITION, denominator);
}

static uint32_t regtrace_t23_awb_hlil_interpolate_q(uint32_t x_q,
                                                    uint32_t x0,
                                                    uint32_t x1,
                                                    uint32_t y0_q,
                                                    uint32_t y1_q)
{
    uint32_t q = REGTRACE_T23_AWB_HLIL_POINT_POSITION;
    uint32_t x0_q = x0 << q;
    uint32_t span_q = (x1 - x0) << q;
    uint32_t delta_x;
    uint64_t delta;

    if (!span_q || x_q <= x0_q)
        return y0_q;
    if (x_q >= (x1 << q))
        return y1_q;

    delta_x = x_q - x0_q;
    if (y1_q >= y0_q) {
        delta = (uint64_t)(y1_q - y0_q) * delta_x;
        return y0_q + (uint32_t)div64_u64(delta, span_q);
    }

    delta = (uint64_t)(y0_q - y1_q) * delta_x;
    return y0_q - (uint32_t)div64_u64(delta, span_q);
}

static uint32_t regtrace_t23_awb_hlil_mesh_q(const uint32_t *mesh,
                                             uint32_t rg_q,
                                             uint32_t bg_q)
{
    const uint32_t *rg_pos = regtrace_t23_awb_hlil_rg_positions;
    const uint32_t *bg_pos = regtrace_t23_awb_hlil_bg_positions;
    uint32_t q = REGTRACE_T23_AWB_HLIL_POINT_POSITION;
    uint32_t rg_index = 13U;
    uint32_t bg_index = 13U;
    uint32_t row0_q;
    uint32_t row1_q;
    uint32_t i;

    rg_q = max(rg_q, rg_pos[0] << q);
    rg_q = min(rg_q, rg_pos[14] << q);
    bg_q = max(bg_q, bg_pos[0] << q);
    bg_q = min(bg_q, bg_pos[14] << q);

    for (i = 0; i < 14U; ++i) {
        if (rg_q <= (rg_pos[i + 1U] << q)) {
            rg_index = i;
            break;
        }
    }
    for (i = 0; i < 14U; ++i) {
        if (bg_q <= (bg_pos[i + 1U] << q)) {
            bg_index = i;
            break;
        }
    }

    row0_q = regtrace_t23_awb_hlil_interpolate_q(
        rg_q, rg_pos[rg_index], rg_pos[rg_index + 1U],
        mesh[bg_index * 15U + rg_index] << q,
        mesh[bg_index * 15U + rg_index + 1U] << q);
    row1_q = regtrace_t23_awb_hlil_interpolate_q(
        rg_q, rg_pos[rg_index], rg_pos[rg_index + 1U],
        mesh[(bg_index + 1U) * 15U + rg_index] << q,
        mesh[(bg_index + 1U) * 15U + rg_index + 1U] << q);

    return regtrace_t23_awb_hlil_interpolate_q(
        bg_q, bg_pos[bg_index], bg_pos[bg_index + 1U], row0_q, row1_q);
}

static uint32_t regtrace_t23_awb_hlil_light_source_weight_q(uint32_t rg_q,
                                                            uint32_t bg_q)
{
    const uint32_t q = REGTRACE_T23_AWB_HLIL_POINT_POSITION;
    const uint32_t rounding = 1U << (q - 1U);
    uint32_t rg = (rg_q + rounding) >> q;
    uint32_t bg = (bg_q + rounding) >> q;
    uint32_t best_weight_q = 0;
    uint32_t source;

    for (source = 0; source < REGTRACE_T23_AWB_HLIL_LIGHT_SOURCE_COUNT;
         ++source) {
        uint32_t ref_rg = regtrace_t23_awb_hlil_light_sources[source * 2U];
        uint32_t ref_bg =
            regtrace_t23_awb_hlil_light_sources[source * 2U + 1U];
        uint32_t delta_rg;
        uint32_t delta_bg;
        uint32_t distance;
        uint32_t weight = 0;

        if (ref_rg)
            ref_rg--;
        if (ref_bg)
            ref_bg--;
        delta_rg = rg >= ref_rg ? rg - ref_rg : ref_rg - rg;
        delta_bg = bg >= ref_bg ? bg - ref_bg : ref_bg - bg;
        distance = delta_rg * delta_rg + delta_bg * delta_bg;

        if (distance < 0x332U) {
            weight = 1U;
            if (distance < 0x2a7U) {
                weight = 2U;
                if (distance < 0x267U) {
                    weight = 3U;
                    if (distance < 0x23cU) {
                        weight = 4U;
                        if (distance < 0x21cU) {
                            weight = 5U;
                            if (distance < 0x202U)
                                weight =
                                    regtrace_t23_awb_hlil_light_source_weight_lut[
                                        distance];
                        }
                    }
                }
            }
        }
        best_weight_q = max(best_weight_q, weight << q);
    }

    return best_weight_q;
}

/*
 * The cluster part of stock Tiziano_Awb_Ct_Detect.  Every run fills the
 * rg/bg histogram of the 225 zones as stock does (it is state of the next
 * cluster run); with the cluster object enabled (ClusterEn == 1) the zone
 * weights are then replaced by the cluster weights (0x14e8c..0x15628).
 * Stock handles every zone, also the ones below the pixel threshold (their
 * ratios read 0 and are clamped to the first position): the arrays here are
 * built that way, and only the zones this run uses get a new weight.
 */
static void regtrace_t23_awb_cluster_stage(
    const struct regtrace_t23_awb_hlil_snapshot *snapshot, bool indoor,
    const uint32_t *mesh, bool use_result)
{
    static uint32_t zr[T23X_CL_ZONES], zb[T23X_CL_ZONES], zw[T23X_CL_ZONES];
    const uint32_t q = REGTRACE_T23_AWB_HLIL_POINT_POSITION;
    uint32_t i;

    for (i = 0; i < T23X_CL_ZONES; ++i) {
        uint32_t r = regtrace_t23_awb_raw_rg[i];
        uint32_t b = regtrace_t23_awb_raw_bg[i];

        if (snapshot->pixels[i] <= REGTRACE_T23_AWB_HLIL_PIXEL_THRESHOLD) {
            r = 0;
            b = 0;
        }
        r = max(r, regtrace_t23_awb_hlil_rg_positions[0] << q);
        r = min(r, regtrace_t23_awb_hlil_rg_positions[14] << q);
        b = max(b, regtrace_t23_awb_hlil_bg_positions[0] << q);
        b = min(b, regtrace_t23_awb_hlil_bg_positions[14] << q);
        zr[i] = r;
        zb[i] = b;
        zw[i] = regtrace_t23_awb_hlil_mesh_q(mesh, r, b);
        if (indoor)
            zw[i] = max(zw[i],
                        regtrace_t23_awb_hlil_light_source_weight_q(r, b));
    }
    t23x_awb_cluster_count(&regtrace_t23_awb_cluster_state, zr, zb,
                           regtrace_t23_awb_hlil_rg_positions,
                           regtrace_t23_awb_hlil_bg_positions, q);
    if (regtrace_t23_awb_cl_run[0] != 1U)
        return;
    if (!t23x_awb_cluster_weights(&regtrace_t23_awb_cluster_state,
                                  regtrace_t23_awb_cl_run, zr, zb, zw,
                                  regtrace_t23_awb_hlil_rg_positions,
                                  regtrace_t23_awb_hlil_bg_positions, q) ||
        !use_result)
        return;
    for (i = 0; i < T23X_CL_ZONES; ++i)
        if (regtrace_t23_awb_hlil_pixel_weight[i])
            regtrace_t23_awb_hlil_mesh_weight[i] = zw[i];
}

static int regtrace_t23_awb_hlil_calculate(
    const struct regtrace_t23_awb_hlil_snapshot *snapshot,
    struct regtrace_t23_awb_hlil_result *result)
{
    const uint32_t q = REGTRACE_T23_AWB_HLIL_POINT_POSITION;
    const uint32_t rounding = 1U << (q - 1U);
    const uint32_t total = REGTRACE_T23_AWB_HLIL_ZONES;
    const uint32_t bg_offset = REGTRACE_T23_AWB_HLIL_ZONES;
    uint32_t max_pixels = 0;
    uint32_t coefficient_rg_q;
    uint32_t coefficient_bg_q;
    uint64_t total_mesh_weight = 0;
    uint64_t sum_rg = 0;
    uint64_t sum_bg = 0;
    uint64_t sum_weight = 0;
    uint32_t average_rg_q;
    uint32_t average_bg_q;
    uint32_t active_zones = 0;
    bool indoor = regtrace_t23_ae_ev_q10() >=
                  (REGTRACE_T23_AWB_HLIL_INDOOR_EV << q);
    const uint32_t *rgbg_weight_mesh = indoor ?
        regtrace_t23_awb_hlil_indoor_ct_weight_mesh :
        regtrace_t23_awb_hlil_outdoor_ct_weight_mesh;
    uint32_t i;

    coefficient_rg_q = regtrace_t23_awb_hlil_mul_q(
        0x100U << q, regtrace_t23_awb_hlil_wb_static[0]);
    coefficient_bg_q = regtrace_t23_awb_hlil_mul_q(
        0x100U << q, regtrace_t23_awb_hlil_wb_static[1]);

    for (i = 0; i < total; ++i)
        max_pixels = max(max_pixels, snapshot->pixels[i]);
    if (!max_pixels) {
        /* stock still runs the histogram and the cluster stage */
        regtrace_t23_awb_cluster_stage(snapshot, indoor, rgbg_weight_mesh,
                                       false);
        return -ENODATA;
    }

    for (i = 0; i < total; ++i) {
        uint32_t green = snapshot->g[i];
        uint32_t pixels = snapshot->pixels[i];
        uint32_t rg_q = 0;
        uint32_t bg_q = 0;

        if (green) {
            uint32_t raw_rg_q = (uint32_t)div64_u64(
                (uint64_t)snapshot->r[i] << q, green);
            uint32_t raw_bg_q = (uint32_t)div64_u64(
                (uint64_t)snapshot->b[i] << q, green);

            rg_q = regtrace_t23_awb_hlil_mul_q(raw_rg_q, coefficient_rg_q);
            bg_q = regtrace_t23_awb_hlil_mul_q(raw_bg_q, coefficient_bg_q);
        }
        regtrace_t23_awb_raw_rg[i] = rg_q;
        regtrace_t23_awb_raw_bg[i] = bg_q;

        if (pixels < regtrace_t23_source_awb_hlil_min_pixels ||
            !rg_q || !bg_q) {
            regtrace_t23_awb_hlil_ratio[i] = 0;
            regtrace_t23_awb_hlil_ratio[bg_offset + i] = 0;
            regtrace_t23_awb_hlil_pixel_weight[i] = 0;
            regtrace_t23_awb_hlil_mesh_weight[i] = 0;
            continue;
        }

        rg_q = max(rg_q, regtrace_t23_awb_hlil_rg_positions[0] << q);
        rg_q = min(rg_q, regtrace_t23_awb_hlil_rg_positions[14] << q);
        bg_q = max(bg_q, regtrace_t23_awb_hlil_bg_positions[0] << q);
        bg_q = min(bg_q, regtrace_t23_awb_hlil_bg_positions[14] << q);
        regtrace_t23_awb_hlil_ratio[i] = rg_q;
        regtrace_t23_awb_hlil_ratio[bg_offset + i] = bg_q;
        regtrace_t23_awb_hlil_pixel_weight[i] =
            regtrace_t23_awb_hlil_div_q(pixels, max_pixels);
        regtrace_t23_awb_hlil_mesh_weight[i] =
            regtrace_t23_awb_hlil_mesh_q(
                rgbg_weight_mesh, rg_q, bg_q);
        active_zones++;
    }

    if (indoor) {
        for (i = 0; i < total; ++i) {
            uint32_t light_weight;

            if (!regtrace_t23_awb_hlil_ratio[i] ||
                !regtrace_t23_awb_hlil_ratio[bg_offset + i] ||
                !regtrace_t23_awb_hlil_pixel_weight[i])
                continue;
            light_weight = regtrace_t23_awb_hlil_light_source_weight_q(
                regtrace_t23_awb_hlil_ratio[i],
                regtrace_t23_awb_hlil_ratio[bg_offset + i]);
            if (light_weight > regtrace_t23_awb_hlil_mesh_weight[i]) {
                regtrace_t23_awb_hlil_mesh_weight[i] = light_weight;
                result->light_source_zones++;
            }
        }
    }
    regtrace_t23_awb_cluster_stage(snapshot, indoor, rgbg_weight_mesh, true);
    for (i = 0; i < total; ++i)
        total_mesh_weight += regtrace_t23_awb_hlil_mesh_weight[i];

    if (!active_zones || !total_mesh_weight)
        goto no_usable_zone;

    for (i = 0; i < total; ++i) {
        uint32_t weight = regtrace_t23_awb_hlil_mul_q(
            regtrace_t23_awb_hlil_mesh_weight[i],
            regtrace_t23_awb_hlil_pixel_weight[i]);

        sum_rg += regtrace_t23_awb_hlil_mul_q(
            regtrace_t23_awb_hlil_ratio[i], weight);
        sum_bg += regtrace_t23_awb_hlil_mul_q(
            regtrace_t23_awb_hlil_ratio[bg_offset + i], weight);
        sum_weight += weight;
    }
    if (!sum_weight)
        goto no_usable_zone;

    average_rg_q = regtrace_t23_awb_hlil_div_q(sum_rg, sum_weight);
    average_bg_q = regtrace_t23_awb_hlil_div_q(sum_bg, sum_weight);

    if (regtrace_t23_awb_hlil_distance_parameters[0] == 1U) {
        uint64_t distance_sum = 0;
        uint64_t refined_rg = 0;
        uint64_t refined_bg = 0;
        uint64_t refined_weight = 0;
        uint32_t normalized_distance;

        for (i = 0; i < total; ++i) {
            uint32_t rg_q = regtrace_t23_awb_hlil_ratio[i];
            uint32_t bg_q = regtrace_t23_awb_hlil_ratio[bg_offset + i];
            uint32_t delta_rg;
            uint32_t delta_bg;
            uint32_t distance;

            if (!regtrace_t23_awb_hlil_mesh_weight[i] ||
                !regtrace_t23_awb_hlil_pixel_weight[i]) {
                regtrace_t23_awb_hlil_distance[i] = 0;
                continue;
            }
            delta_rg = average_rg_q >= rg_q ?
                average_rg_q - rg_q : rg_q - average_rg_q;
            delta_bg = average_bg_q >= bg_q ?
                average_bg_q - bg_q : bg_q - average_bg_q;
            distance = regtrace_t23_awb_hlil_mul_q(delta_rg, delta_rg) +
                       regtrace_t23_awb_hlil_mul_q(delta_bg, delta_bg);
            regtrace_t23_awb_hlil_distance[i] = distance;
            distance_sum += regtrace_t23_awb_hlil_mul_q(
                regtrace_t23_awb_hlil_mul_q(
                    distance, regtrace_t23_awb_hlil_mesh_weight[i]),
                regtrace_t23_awb_hlil_zone_weight_mesh[i] << q);
        }

        normalized_distance = regtrace_t23_awb_hlil_div_q(
            distance_sum, sum_weight);
        if (normalized_distance) {
            uint32_t distance_hi =
                regtrace_t23_awb_hlil_distance_parameters[1];
            uint32_t distance_lo =
                regtrace_t23_awb_hlil_distance_parameters[2];

            for (i = 0; i < total; ++i) {
                uint32_t relative_distance;
                uint32_t distance_weight;
                uint32_t weight;

                if (!regtrace_t23_awb_hlil_mesh_weight[i] ||
                    !regtrace_t23_awb_hlil_pixel_weight[i])
                    continue;
                relative_distance = regtrace_t23_awb_hlil_div_q(
                    regtrace_t23_awb_hlil_distance[i], normalized_distance);
                if (relative_distance > distance_hi) {
                    distance_weight = 0;
                } else if (relative_distance >= distance_lo) {
                    uint32_t ramp = regtrace_t23_awb_hlil_div_q(
                        relative_distance - distance_lo,
                        distance_hi - distance_lo);

                    distance_weight = regtrace_t23_awb_hlil_mul_q(
                        regtrace_t23_awb_hlil_mesh_weight[i],
                        (1U << q) - min(ramp, 1U << q));
                } else {
                    distance_weight = regtrace_t23_awb_hlil_mesh_weight[i];
                }
                regtrace_t23_awb_hlil_distance_weight[i] = distance_weight;
                weight = regtrace_t23_awb_hlil_mul_q(
                    distance_weight, regtrace_t23_awb_hlil_pixel_weight[i]);
                refined_rg += regtrace_t23_awb_hlil_mul_q(
                    regtrace_t23_awb_hlil_ratio[i], weight);
                refined_bg += regtrace_t23_awb_hlil_mul_q(
                    regtrace_t23_awb_hlil_ratio[bg_offset + i], weight);
                refined_weight += weight;
            }
            if (refined_weight) {
                average_rg_q = regtrace_t23_awb_hlil_div_q(
                    refined_rg, refined_weight);
                average_bg_q = regtrace_t23_awb_hlil_div_q(
                    refined_bg, refined_weight);
            }
        }
    }

    average_rg_q = max(average_rg_q,
                       regtrace_t23_awb_hlil_rg_positions[0] << q);
    average_rg_q = min(average_rg_q,
                       regtrace_t23_awb_hlil_rg_positions[14] << q);
    average_bg_q = max(average_bg_q,
                       regtrace_t23_awb_hlil_bg_positions[0] << q);
    average_bg_q = min(average_bg_q,
                       regtrace_t23_awb_hlil_bg_positions[14] << q);

    result->rg = (average_rg_q + rounding) >> q;
    result->bg = (average_bg_q + rounding) >> q;
    result->active_zones = active_zones;
    {
        uint32_t inverse_ct_q = regtrace_t23_awb_hlil_mesh_q(
            regtrace_t23_awb_hlil_color_temperature_mesh,
            average_rg_q, average_bg_q);

        result->ct = inverse_ct_q ?
            (uint32_t)div64_u64(((uint64_t)1000000U << q) +
                                (inverse_ct_q >> 1), inverse_ct_q) :
            5000U;
    }
    return 0;

no_usable_zone:
    /*
     * Statistics present but no zone inside the CT weight mesh (dark or
     * IR-lit scene, saturated or partial first frame).  Stock JZ_Isp_Awb
     * does not keep the previous gains here: its weighted mean stays 0,
     * which is unity MF over the static WB gains at the 5000 K default
     * (emulated: 0x6c0/0x770 on the sc1a4t IQ).  Do the same instead of
     * failing with -ENODATA and holding stale gains; the caller keeps
     * this result out of the history.
     */
    result->rg = 0;
    result->bg = 0;
    result->ct = 5000U;
    result->active_zones = active_zones;
    return 0;
}

static void regtrace_t23_awb_hlil_history_update(uint32_t *rg,
                                                 uint32_t *bg,
                                                 uint32_t *ct)
{
    uint32_t window;
    uint32_t start;
    uint32_t i;
    uint32_t weight_sum = 0;
    uint64_t rg_sum = 0;
    uint64_t bg_sum = 0;
    uint64_t ct_sum = 0;

    if (!regtrace_t23_awb_hlil_history_count) {
        for (i = 0; i < 15U; ++i) {
            regtrace_t23_awb_hlil_history_rg[i] = *rg;
            regtrace_t23_awb_hlil_history_bg[i] = *bg;
            regtrace_t23_awb_hlil_history_ct[i] = *ct;
        }
        regtrace_t23_awb_hlil_history_count = 1U;
    } else {
        memmove(regtrace_t23_awb_hlil_history_rg,
                regtrace_t23_awb_hlil_history_rg + 1, 14U * sizeof(uint32_t));
        memmove(regtrace_t23_awb_hlil_history_bg,
                regtrace_t23_awb_hlil_history_bg + 1, 14U * sizeof(uint32_t));
        memmove(regtrace_t23_awb_hlil_history_ct,
                regtrace_t23_awb_hlil_history_ct + 1, 14U * sizeof(uint32_t));
        regtrace_t23_awb_hlil_history_rg[14] = *rg;
        regtrace_t23_awb_hlil_history_bg[14] = *bg;
        regtrace_t23_awb_hlil_history_ct[14] = *ct;
        regtrace_t23_awb_hlil_history_count = min(
            regtrace_t23_awb_hlil_history_count + 1U, 15U);
    }

    window = min((uint32_t)REGTRACE_T23_AWB_HLIL_HISTORY_WINDOW,
                 regtrace_t23_awb_hlil_history_count);
    window = max(window, 1U);
    start = 15U - window;
    for (i = start; i < 15U; ++i) {
        uint32_t weight = i + 1U;

        rg_sum += (uint64_t)weight * regtrace_t23_awb_hlil_history_rg[i];
        bg_sum += (uint64_t)weight * regtrace_t23_awb_hlil_history_bg[i];
        ct_sum += (uint64_t)weight * regtrace_t23_awb_hlil_history_ct[i];
        weight_sum += weight;
    }
    *rg = (uint32_t)div64_u64(rg_sum + (weight_sum >> 1), weight_sum);
    *bg = (uint32_t)div64_u64(bg_sum + (weight_sum >> 1), weight_sum);
    *ct = (uint32_t)div64_u64(ct_sum + (weight_sum >> 1), weight_sum);
}

static uint32_t regtrace_t23_awb_hlil_ratio_to_mf(uint32_t ratio)
{
    uint32_t q = REGTRACE_T23_AWB_HLIL_POINT_POSITION;
    uint32_t rounding = 1U << (q - 1U);
    uint64_t reciprocal;

    if (!ratio)
        return 0x100U;
    reciprocal = div64_u64(1ULL << (q + 16U), ratio);
    return (uint32_t)((reciprocal + rounding) >> q);
}

static void regtrace_t23_source_awb_hlil_work_body(struct work_struct *work);

static void regtrace_t23_source_awb_hlil_work(struct work_struct *work)
{
    regtrace_t23_text_check("awb_hlil_work-enter", 0);
    regtrace_t23_source_awb_hlil_work_body(work);
    regtrace_t23_text_check("awb_hlil_work-exit", 0);
}

static void regtrace_t23_source_awb_hlil_work_body(struct work_struct *work)
{
    struct regtrace_t23_awb_hlil_result result;
    unsigned long flags;
    uint32_t auto_mf_rg;
    uint32_t auto_mf_bg;
    uint32_t mf_rg;
    uint32_t mf_bg;
    uint32_t wb_mode;
    uint32_t gain_rg;
    uint32_t gain_bg;
    uint32_t trend_ct;
    uint32_t trend[T23X_AWB_TREND_WORDS];
    uint32_t tolerance_en;
    uint32_t tolerance_th;
    int ret;

    (void)work;
    /* the cluster / trend objects of this run, picked like stock
     * (JZ_Isp_Awb, JZ_Isp_Awb_Awbg2reg); the update tolerance reads the
     * live cluster object (Tiziano_awb_fpga gets &_awb_cluster) */
    mutex_lock(&t23x_awb_api_mutex);
    memcpy(regtrace_t23_awb_cl_run,
           t23x_awb_obj_pick((const uint32_t *)(const void *)_awb_cluster,
                             (const uint32_t *)(const void *)awb_cluster_api_para,
                             (const uint32_t *)(const void *)awb_cluster_api_status),
           sizeof(regtrace_t23_awb_cl_run));
    tolerance_en = ((const uint32_t *)(const void *)_awb_cluster)[8];
    tolerance_th = ((const uint32_t *)(const void *)_awb_cluster)[9];
    memcpy(trend,
           t23x_awb_obj_pick((const uint32_t *)(const void *)&_awb_trend,
                             (const uint32_t *)(const void *)awb_trend_api_para,
                             (const uint32_t *)(const void *)&awb_trend_api_status),
           sizeof(trend));
    mutex_unlock(&t23x_awb_api_mutex);
    memset(&result, 0, sizeof(result));
    ret = regtrace_t23_awb_hlil_calculate(
        &regtrace_t23_awb_hlil_snapshot_data, &result);
    regtrace_t23_source_awb_hlil_runs++;
    regtrace_t23_source_awb_hlil_status = ret ? 1U : 0U;

    if (!ret) {
        uint32_t raw_mf_rg = regtrace_t23_awb_hlil_ratio_to_mf(result.rg);
        uint32_t raw_mf_bg = regtrace_t23_awb_hlil_ratio_to_mf(result.bg);

        regtrace_t23_awb_statis[0] = raw_mf_rg ? 0x10000U / raw_mf_rg : 0x100U;
        regtrace_t23_awb_statis[1] = raw_mf_bg ? 0x10000U / raw_mf_bg : 0x100U;
        /* a no-zone result (rg = bg = 0) must not enter the ratio
         * history: with a history window > 1 it would average toward
         * zero ratios, i.e. huge gains */
        if (result.rg || result.bg)
            regtrace_t23_awb_hlil_history_update(
                &result.rg, &result.bg, &result.ct);
        auto_mf_rg = regtrace_t23_awb_hlil_ratio_to_mf(result.rg);
        auto_mf_bg = regtrace_t23_awb_hlil_ratio_to_mf(result.bg);
        /*
         * ToleranceEn (SetAwbClust): the automatic gains only follow a
         * change of the summed Q8 gains above tolerance_th (stock
         * Tiziano_awb_fpga, the part that decides a new target; stock then
         * also ramps to it over the history length, here it is taken at
         * once).  Off: the update rule stays as it is.
         */
        if (tolerance_en) {
            if (!regtrace_t23_awb_tol_valid ||
                regtrace_t23_awb_absdiff(auto_mf_rg, regtrace_t23_awb_tol_rg) +
                regtrace_t23_awb_absdiff(auto_mf_bg, regtrace_t23_awb_tol_bg) >
                tolerance_th) {
                regtrace_t23_awb_tol_rg = auto_mf_rg;
                regtrace_t23_awb_tol_bg = auto_mf_bg;
                regtrace_t23_awb_tol_valid = true;
            }
            auto_mf_rg = regtrace_t23_awb_tol_rg;
            auto_mf_bg = regtrace_t23_awb_tol_bg;
        } else {
            regtrace_t23_awb_tol_valid = false;
        }
        regtrace_t23_source_awb_last_mf_rg = auto_mf_rg;
        regtrace_t23_source_awb_last_mf_bg = auto_mf_bg;
        regtrace_t23_awb_statis[2] = auto_mf_rg ? 0x10000U / auto_mf_rg : 0x100U;
        regtrace_t23_awb_statis[3] = auto_mf_bg ? 0x10000U / auto_mf_bg : 0x100U;
        ((uint32_t *)(void *)_awb_mf_para)[4] = auto_mf_rg;
        ((uint32_t *)(void *)_awb_mf_para)[5] = auto_mf_bg;

        wb_mode = ACCESS_ONCE(regtrace_t23_source_wb_mode);
        /* the colour temperature the gains are written at (stock sets
         * the custom SetAwbCt value only after Tiziano_awb_fpga) */
        trend_ct = result.ct;
        result.ct = t23x_awb_ct_select(wb_mode, result.ct,
                                       &regtrace_t23_awb_custom_ct);
        mf_rg = auto_mf_rg;
        mf_bg = auto_mf_bg;
        if (wb_mode == 9U) {
            mf_rg = ((ACCESS_ONCE(regtrace_t23_source_wb_mode_rg) + 0x40U) *
                     auto_mf_rg) >> 6;
            mf_bg = ((ACCESS_ONCE(regtrace_t23_source_wb_mode_bg) + 0x40U) *
                     auto_mf_bg) >> 6;
        } else if (wb_mode != 0U) {
            mf_rg = ACCESS_ONCE(regtrace_t23_source_wb_mode_rg);
            mf_bg = ACCESS_ONCE(regtrace_t23_source_wb_mode_bg);
        }
        gain_rg = (mf_rg * regtrace_t23_awb_hlil_wb_static[0] +
                   (1U << (REGTRACE_T23_AWB_HLIL_POINT_POSITION - 1U))) >>
                  REGTRACE_T23_AWB_HLIL_POINT_POSITION;
        gain_bg = (mf_bg * regtrace_t23_awb_hlil_wb_static[1] +
                   (1U << (REGTRACE_T23_AWB_HLIL_POINT_POSITION - 1U))) >>
                  REGTRACE_T23_AWB_HLIL_POINT_POSITION;
        /* Awbg2reg: Q2 gain, the colour temperature trend, the limit */
        gain_rg = t23x_awb_gain_trend(trend, trend_ct, gain_rg, 0);
        gain_bg = t23x_awb_gain_trend(trend, trend_ct, gain_bg, 1);
        gain_rg = min((gain_rg *
                       ACCESS_ONCE(regtrace_t23_source_awb_profile_rbias) +
                       (REGTRACE_T23_AWB_PROFILE_BIAS_UNITY >> 1)) >> 10,
                      0x3fffU);
        gain_bg = min((gain_bg *
                       ACCESS_ONCE(regtrace_t23_source_awb_profile_bbias) +
                       (REGTRACE_T23_AWB_PROFILE_BIAS_UNITY >> 1)) >> 10,
                      0x3fffU);

        regtrace_t23_source_awb_hlil_rg = result.rg;
        regtrace_t23_source_awb_hlil_bg = result.bg;
        regtrace_t23_source_awb_hlil_ct = result.ct;
        if (regtrace_t23_source_ccm_events &&
            regtrace_t23_source_ccm_tuning_init &&
            result.ct >= 1500U && result.ct <= 10000U) {
            uint32_t delta = regtrace_t23_source_ccm_last_ct >= result.ct ?
                regtrace_t23_source_ccm_last_ct - result.ct :
                result.ct - regtrace_t23_source_ccm_last_ct;

            if (delta > 0x20U)
                regtrace_t23_source_ccm_commit(
                    result.ct, regtrace_t23_ae_ev_q10());
        }
        if (regtrace_t23_source_lsc_events &&
            regtrace_t23_source_lsc_tuning_init &&
            regtrace_t23_source_lsc_tables_initialized &&
            result.ct >= ((uint32_t *)(void *)lsc_ct_points)[0] &&
            result.ct <= 10000U) {
            uint32_t delta = regtrace_t23_source_lsc_last_ct >= result.ct ?
                regtrace_t23_source_lsc_last_ct - result.ct :
                result.ct - regtrace_t23_source_lsc_last_ct;

            if (delta > 0x20U) {
                tisp_lsc_ct_update(result.ct);
                if (!tisp_lsc_write_lut_datas()) {
                    regtrace_t23_source_lsc_last_ct = result.ct;
                    regtrace_t23_source_lsc_event_count++;
                }
            }
        }
        if (regtrace_t23_source_bcsh_events &&
            result.ct >= 2000U && result.ct <= 10000U) {
            uint32_t delta = regtrace_t23_source_bcsh_last_ct >= result.ct ?
                regtrace_t23_source_bcsh_last_ct - result.ct :
                result.ct - regtrace_t23_source_bcsh_last_ct;

            if (delta > 0x20U) {
                tisp_bcsh_ct_update(0, result.ct);
                regtrace_t23_source_bcsh_last_ct = result.ct;
                regtrace_t23_source_bcsh_ct_events++;
            }
        }
        if (regtrace_t23_source_clm_events &&
            regtrace_t23_source_clm_tuning_init &&
            result.ct >= 1000U && result.ct <= 10000U)
            tisp_clm_ct_update(0, result.ct);
        if (!ACCESS_ONCE(awb_frz) &&
            ((gain_rg > regtrace_t23_source_awb_last_rgain ?
             gain_rg - regtrace_t23_source_awb_last_rgain :
             regtrace_t23_source_awb_last_rgain - gain_rg) > 4U ||
            (gain_bg > regtrace_t23_source_awb_last_bgain ?
             gain_bg - regtrace_t23_source_awb_last_bgain :
             regtrace_t23_source_awb_last_bgain - gain_bg) > 4U)) {
            regtrace_t23_source_awb_apply_gains(gain_rg, gain_bg);
            regtrace_t23_source_awb_hlil_updates++;
        }

        if (regtrace_t23_source_awb_hlil_runs <= 8U ||
            !(regtrace_t23_source_awb_hlil_runs &
              (regtrace_t23_source_awb_hlil_runs - 1U)))
            printk(KERN_INFO
                   "t23: source AWB HLIL run=%u snapshot=%u bank=%u zones=%u lights=%u ev=%u target=%u/%u ct=%u mode=%u mf=%u/%u gain=0x%x/0x%x updates=%u\n",
                   regtrace_t23_source_awb_hlil_runs,
                   regtrace_t23_awb_hlil_snapshot_data.snapshot,
                   regtrace_t23_awb_hlil_snapshot_data.bank,
                   result.active_zones, result.light_source_zones,
                   regtrace_t23_ae_ev_q10(),
                   result.rg, result.bg, result.ct, wb_mode,
                   mf_rg, mf_bg, gain_rg, gain_bg,
                   regtrace_t23_source_awb_hlil_updates);
    } else if (ret == -ENODATA) {
        /*
         * No zone inside the CT weight mesh: expected while the AE is
         * still converging after a stream start, and under IR (night)
         * light. Not an error; note it only if it lasts.
         */
        if (regtrace_t23_source_awb_hlil_runs >= 64U &&
            !(regtrace_t23_source_awb_hlil_runs &
              (regtrace_t23_source_awb_hlil_runs - 1U)))
            printk(KERN_INFO
                   "t23: source AWB HLIL run=%u snapshot=%u: no usable zone yet, gains held\n",
                   regtrace_t23_source_awb_hlil_runs,
                   regtrace_t23_awb_hlil_snapshot_data.snapshot);
    } else if (regtrace_t23_source_awb_hlil_runs <= 8U) {
        printk(KERN_WARNING
               "t23: source AWB HLIL run=%u snapshot=%u failed ret=%d\n",
               regtrace_t23_source_awb_hlil_runs,
               regtrace_t23_awb_hlil_snapshot_data.snapshot, ret);
    }

    spin_lock_irqsave(&regtrace_t23_awb_hlil_lock, flags);
    regtrace_t23_awb_hlil_pending = false;
    spin_unlock_irqrestore(&regtrace_t23_awb_hlil_lock, flags);
}

static void regtrace_t23_source_awb_hlil_capture(const uint32_t *words,
                                                 uint32_t bank,
                                                 uint32_t snapshot)
{
    unsigned long flags;
    unsigned int zone;
    unsigned int populated = 0;

    if (!regtrace_t23_source_awb_hlil)
        return;
    /* the first snapshot after a stream start is used at once */
    if (regtrace_t23_source_awb_hlil_interval && snapshot != 1U &&
        snapshot % regtrace_t23_source_awb_hlil_interval)
        return;

    spin_lock_irqsave(&regtrace_t23_awb_hlil_lock, flags);
    if (regtrace_t23_awb_hlil_pending || regtrace_t23_awb_hlil_paused) {
        regtrace_t23_source_awb_hlil_drops++;
        spin_unlock_irqrestore(&regtrace_t23_awb_hlil_lock, flags);
        return;
    }

    for (zone = 0; zone < REGTRACE_T23_AWB_HLIL_ZONES;
         ++zone, words += 4) {
        uint32_t w0 = words[0];
        uint32_t w1 = words[1];
        uint32_t w2 = words[2];
        uint32_t w3 = words[3];

        regtrace_t23_awb_hlil_snapshot_data.r[zone] = w0 & 0x1fffffU;
        regtrace_t23_awb_hlil_snapshot_data.g[zone] =
            ((w1 & 0x3ffU) << 11) | (w0 >> 21);
        regtrace_t23_awb_hlil_snapshot_data.b[zone] =
            (w1 & 0x7ffffc00U) >> 10;
        regtrace_t23_awb_hlil_snapshot_data.pixels[zone] =
            ((w3 & 1U) << 12) | (w2 >> 20);
        if (regtrace_t23_awb_hlil_snapshot_data.pixels[zone])
            populated++;
    }
    /*
     * The first statistics interrupt after a stream start can come before
     * a complete statistics frame (seen 17 ms after STREAMON with one of
     * 225 zones written).  Do not use such a partial bank at once; the
     * next scheduled snapshot follows a few frames later.
     */
    if (snapshot == 1U &&
        populated < REGTRACE_T23_AWB_HLIL_ZONES / 2U) {
        regtrace_t23_source_awb_hlil_drops++;
        spin_unlock_irqrestore(&regtrace_t23_awb_hlil_lock, flags);
        return;
    }
    regtrace_t23_awb_hlil_snapshot_data.bank = bank;
    regtrace_t23_awb_hlil_snapshot_data.snapshot = snapshot;
    regtrace_t23_awb_hlil_snapshot_data.stamp = jiffies | 1UL;
    regtrace_t23_awb_hlil_pending = true;
    spin_unlock_irqrestore(&regtrace_t23_awb_hlil_lock, flags);
    schedule_work(&regtrace_t23_source_awb_hlil_work_item);
}

static void regtrace_t23_source_awb_hlil_reset(void)
{
    unsigned long flags;

    cancel_work_sync(&regtrace_t23_source_awb_hlil_work_item);
    spin_lock_irqsave(&regtrace_t23_awb_hlil_lock, flags);
    regtrace_t23_awb_hlil_pending = false;
    /* a stream restart keeps the white balance history (see
     * regtrace_t23_source_awb_kept); only the first start begins empty */
    if (!regtrace_t23_source_awb_kept)
        regtrace_t23_awb_hlil_history_count = 0;
    spin_unlock_irqrestore(&regtrace_t23_awb_hlil_lock, flags);
    regtrace_t23_awb_tol_valid = false;
    regtrace_t23_source_awb_hlil_runs = 0;
    regtrace_t23_source_awb_hlil_updates = 0;
    regtrace_t23_source_awb_hlil_drops = 0;
    regtrace_t23_source_awb_hlil_status = 0;
    if (!regtrace_t23_source_awb_kept) {
        regtrace_t23_source_awb_hlil_rg = 0;
        regtrace_t23_source_awb_hlil_bg = 0;
        regtrace_t23_source_awb_hlil_ct = REGTRACE_T23_AWB_HLIL_STARTUP_CT;
    }
    regtrace_t23_source_ccm_event_count = 0;
    regtrace_t23_source_ccm_last_ct = regtrace_t23_source_ccm_runtime_ct;
    regtrace_t23_source_lsc_event_count = 0;
    regtrace_t23_source_lsc_last_ct = regtrace_t23_source_lsc_runtime_ct;
    regtrace_t23_source_lsc_update_pending = false;
    regtrace_t23_source_bcsh_ct_events = 0;
    regtrace_t23_source_bcsh_last_ct = 3187U;
    printk(KERN_WARNING
           "t23: source AWB HLIL reset ev=%u ct=%u q=%u mf=%u/%u interval=%u enabled=%u\n",
           REGTRACE_T23_AWB_HLIL_STARTUP_EV,
           REGTRACE_T23_AWB_HLIL_STARTUP_CT,
           REGTRACE_T23_AWB_HLIL_POINT_POSITION,
           regtrace_t23_awb_hlil_mf_parameters[4],
           regtrace_t23_awb_hlil_mf_parameters[5],
           regtrace_t23_source_awb_hlil_interval,
           regtrace_t23_source_awb_hlil ? 1U : 0U);
}
