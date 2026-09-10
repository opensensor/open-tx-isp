/* SPDX-License-Identifier: GPL-2.0 */
/* T31 WDR integration. Arithmetic is shared with the host oracle tests. */

struct t31_wdr_param {
	u32 *data;
	u32 bytes;
	u32 offset;
};
#define WDR_PARAM(array, offset) { array, sizeof(array), offset }
static const struct t31_wdr_param wdr_parameters[] = {
#include "tx_isp_t31_wdr_params.inc"
};
#undef WDR_PARAM

static const u32 *const wdr_fusion_tables[5] = {
	param_wdr_weightLUT20_array, param_wdr_weightLUT02_array,
	param_wdr_weightLUT12_array, param_wdr_weightLUT22_array,
	param_wdr_weightLUT21_array
};

static struct t31_wdr_fpga wdr_fpga = {
	.model = param_computerModle_software_in_array,
	.deviation = param_deviationPara_software_in_array,
	.ratio = param_ratioPara_software_in_array,
	.x = param_x_thr_software_in_array,
	.y = param_y_thr_software_in_array,
	.threshold = param_thrPara_software_in_array,
	.xy = param_xy_pix_low_software_in_array,
	.motion = param_motionThrPara_software_in_array,
	.normal = param_d_thr_normal_software_in_array,
	.normal1 = param_d_thr_normal1_software_in_array,
	.normal2 = param_d_thr_normal2_software_in_array,
	.minimum = param_d_thr_normal_min_software_in_array,
	.secondary = param_d_thr_2_software_in_array,
	.low = param_multiValueLow_software_in_array,
	.high = param_multiValueHigh_software_in_array,
	.hist = {{wdr_stats.rgb[0][0], wdr_stats.rgb[0][1], wdr_stats.rgb[0][2]},
		 {wdr_stats.rgb[1][0], wdr_stats.rgb[1][1], wdr_stats.rgb[1][2]}},
	.map = {wdr_mapR_software_out, wdr_mapG_software_out, wdr_mapB_software_out},
	.labels = param_wdr_thrLable_array,
	.label_bits = wdr_thrLableN_software_out,
	.all = wdr_thrAll_software_out,
	.range = wdr_thrRangeK_software_out,
	.detail_in = param_wdr_detial_para_software_in_array,
	.detail = wdr_detial_para_software_out
};

static void wdr_write(void *context, u32 reg, u32 value)
{
	(void)context;
	system_reg_write(reg, value);
}

static int t31_wdr_param_get(int id, void *buf, int *size)
{
	const struct t31_wdr_param *p;
	if (((u32)id - 0x3ff) >= ARRAY_SIZE(wdr_parameters) || !buf || !size)
		return -EINVAL;
	p = &wdr_parameters[id - 0x3ff];
	mutex_lock(&wdr_control_lock);
	memcpy(buf, p->data, p->bytes);
	*size = p->bytes;
	mutex_unlock(&wdr_control_lock);
	return 0;
}

static int t31_wdr_param_set(int id, const void *buf, int *size)
{
	const struct t31_wdr_param *p;
	int ret = 0;
	if (((u32)id - 0x3ff) >= ARRAY_SIZE(wdr_parameters) || !buf || !size)
		return -EINVAL;
	p = &wdr_parameters[id - 0x3ff];
	mutex_lock(&wdr_control_lock);
	memcpy(p->data, buf, p->bytes);
	*size = p->bytes; /* OEM ABI: size is an output, not buffer capacity. */
	wdr_ev.changed = 1;
	if (wdr_ready)
		ret = tiziano_wdr_params_init();
	mutex_unlock(&wdr_control_lock);
	return ret;
}

static int tiziano_wdr_gamma_refresh(void)
{
	u16 gamma[129];
	int size = 0;
	u32 i;
	int ret = tisp_gamma_param_array_get(0x3d, gamma, &size);
	if (ret || size != sizeof(gamma))
		return -EINVAL;
	for (i = 0; i < 33; ++i) {
		wdr_gam_y33_array[i] = gamma[i * 4];
		if (param_wdr_tool_control_array[7] == 0)
			param_wdr_gam_y_array_def[i] = gamma[i * 4];
		else if (param_wdr_tool_control_array[7] == 1)
			param_wdr_gam_y_array_def[i] = i == 32 ? 4095 : i * 128;
	}
	return 0;
}

static int tiziano_wdr_params_refresh(void)
{
	const u8 *bank = tparams_active ? tparams_active : tparams_day;
	u32 area = param_wdr_tool_control_array[2], i;
	if (!bank)
		return -ENODATA;
	for (i = 0; i < ARRAY_SIZE(wdr_parameters); ++i) {
		const struct t31_wdr_param *p = &wdr_parameters[i];
		if (p->offset + p->bytes > TISP_PARAM_BLOCK_SIZE)
			return -EINVAL;
		memcpy(p->data, bank + p->offset, p->bytes);
	}
	param_wdr_tool_control_array[2] = area;
	wdr_ev.changed = 1;
	return tiziano_wdr_gamma_refresh();
}

static int tiziano_wdr_5x5_param(void)
{
	return t31_wdr_spatial(param_wdr_weight_lut_def,
		param_centre5x5_w_distance_array_def, width_wdr_def,
		height_wdr_def, param_wdr_tool_control_array[2], &wdr_scratch.spatial);
}

static int tiziano_wdr_params_init(void)
{
	u32 *tool = param_wdr_tool_control_array, *top = param_wdr_para_array;
	u32 *deg = param_wdr_degost_para_array, *detail = param_wdr_detail_th_w_array;
	u32 *point = param_wdr_w_point_weight_pow_array;
	u32 *stat = param_wdr_stat_para_array;
	u32 i, mode = tool[0];
	s32 step;
	/* OEM debug fusion ramp; the final sample is explicitly saturated. */
	if (mode == 1 || mode == 2 || mode == 3 || mode == 8 || mode == 9) {
		param_wdr_gam_y_array[0] = 0;
		top[1] = mode == 2 ? 2 : mode < 4 ? 3 : 0;
		detail[5] = mode == 8;
		if (mode < 4)
			for (i = 0; i < 33; ++i)
				param_fusion1_cure_y_array[i] = 256;
		else
			for (i = 0; i < 33; ++i)
				param_fusion1_cure_y_array[i] = i < 11 ? 0 : min((i - 10) * 12, 256U);
		if (mode == 1)
			deg[12] = 0;
		if (mode == 1 || mode == 8) {
			param_xy_pix_low_software_in_array[12] = 0;
			param_xy_pix_low_software_in_array[13] = 0;
			param_xy_pix_low_software_in_array[16] = 0;
			param_xy_pix_low_software_in_array[17] = 0;
		}
	}
	if (tool[4] == 1) {
		step = ((s32)tool[6] - (s32)tool[5]) / 33;
		for (i = 0; i < 33; ++i)
			param_fusion1_cure_y_array[i] = tool[5] + i * step;
	} else if (tool[4] == 9)
		for (i = 0; i < 33; ++i)
			param_fusion1_cure_y_array[i] = i < 11 ? 0 : min((i - 10) * 12, 256U);
	if (tiziano_wdr_gamma_refresh())
		return -EINVAL;
	t31_wdr_write_pairs(wdr_write, NULL, 0x2030, deg + 5, 2, 0xfff);
	system_reg_write(0x2034, (deg[7] & 0xfff) | ((deg[8] & 0xff) << 16));
	system_reg_write(0x2038, (deg[9] & 0x1ff) | ((deg[10] & 0x3ff) << 16));
	system_reg_write(0x203c, (deg[0] & 0x3f) | ((deg[4] & 0x3f) << 8));
	system_reg_write(0x236c, deg[11] & 0xff);
	t31_wdr_write_pairs(wdr_write, NULL, 0x223c, param_wdr_thrLable_array, 27, 0xfff);
	t31_wdr_write_pairs(wdr_write, NULL, 0x234c, param_wdr_darkLable_array, 5, 0xff);
	t31_wdr_write_pairs(wdr_write, NULL, 0x2358, param_wdr_darkLableN_array, 4, 7);
	t31_wdr_write_pairs(wdr_write, NULL, 0x2360, param_wdr_darkWeight_array, 5, 0x1f);
	t31_wdr_write_pairs(wdr_write, NULL, 0x244c, param_wdr_gam_y_array_def, 33, 0xfff);
	t31_wdr_write_pairs(wdr_write, NULL, 0x2490, param_wdr_w_point_weight_x_array, 4, 0x1fff);
	t31_wdr_write_pairs(wdr_write, NULL, 0x2498, param_wdr_w_point_weight_y_array, 4, 0x7fff);
	system_reg_write(0x24a0, (point[0] & 15) | ((point[1] & 15) << 8) | ((point[2] & 15) << 16));
	for (i = 0; i < 5; i += 2)
		system_reg_write(0x24f4 + i * 2, (param_wdr_contrast_t_y_mux_array[i] & 0xffff) |
			(i < 4 ? param_wdr_contrast_t_y_mux_array[i + 1] << 16 : 0));
	t31_wdr_write_pairs(wdr_write, NULL, 0x2630, param_wdr_ct_cl_para_array, 4, 0xfff);
	system_reg_write(0x2600, (top[0] & 1) | ((top[1] & 3) << 4) | ((top[3] & 1) << 8) |
		((top[8] & 1) << 12) | ((top[2] & 0xfff) << 16));
	system_reg_write(0x260c, top[9] & 0xfff);
	system_reg_write(0x2610, (detail[5] & 1) | (detail[6] << 16));
	t31_wdr_write_pairs(wdr_write, NULL, 0x2650, stat + 1, 3, 0xfff);
	t31_wdr_write_pairs(wdr_write, NULL, 0x2658, stat + 4, 3, 0xfff);
	system_reg_write(0x2684, (param_wdr_dbg_out_array[0] & 0x1fff) |
		((param_wdr_dbg_out_array[1] & 0x1fff) << 4));
	return 0;
}

int tisp_wdr_expTime_updata(void)
{
	/* AE control gains are Q10. Do not replace a valid calibration ratio
	 * with zero while the short-exposure AE controller is starting. */
	if (!tisp_ae_ctrls[19] || !tisp_ae_ctrls[18] || !tisp_ae_ctrls[3] || !tisp_ae_ctrls[1])
		return -EAGAIN;
	param_ratioPara_software_in_array[0] = (tisp_ae_ctrls[19] * tisp_ae_ctrls[18] + 512) >> 10;
	param_ratioPara_software_in_array[1] = (tisp_ae_ctrls[3] * tisp_ae_ctrls[1] + 512) >> 10;
	return param_ratioPara_software_in_array[0] ? 0 : -EAGAIN;
}

int tisp_wdr_ev_update(u32 low, u32 high)
{
	unsigned long flags;
	spin_lock_irqsave(&wdr_stats_lock, flags);
	wdr_ev_low = low;
	wdr_ev_high = high;
	wdr_ev_pending = true;
	spin_unlock_irqrestore(&wdr_stats_lock, flags);
	return 0;
}

int tiziano_wdr_fusion1_curve(void)
{
	return t31_wdr_fusion_ev(param_fusion1_cure_y_array, wdr_ev.old,
		wdr_ev_list, param_wdr_gam_y_array, wdr_fusion_tables,
		param_wdr_para_array, param_wdr_tool_control_array[13]);
}

int tiziano_wdr_fusion1_curve_block_mean1(void)
{
	return t31_wdr_fusion_table(param_fusion1_cure_y_array,
		wdr_block_mean1_end_old, param_centre5x5_w_distance_array,
		wdr_fusion_tables);
}

int tisp_wdr_ev_calculate(void)
{
	const u32 *const values[7] = {wdr_detail_w_in0_list, wdr_detail_w_in1_list,
		wdr_detail_w_in2_list, wdr_detail_w_in3_list, wdr_detail_w_in4_list,
		wdr_weight_b_in_list, wdr_weight_p_in_list};
	int ret = 0;
	param_wdr_degost_para_array[12] = t31_wdr_deghost_weight(&wdr_ev,
		tisp_ae_ctrls[19], param_xy_pix_low_software_in_array,
		wdr_ev_list_deghost, wdr_weight_in_list_deghost);
	t31_wdr_ev_calculate(&wdr_ev, wdr_ev_list, values,
		param_wdr_detail_th_w_array, param_wdr_para_array);
	if (wdr_ev.changed)
		ret = tiziano_wdr_fusion1_curve();
	if (!ret)
		wdr_ev.changed = 0;
	return ret;
}

/* Public OEM ABI, including all twenty-six stack arguments. */
int Tiziano_wdr_fpga(u32 *a1, u32 *a2, u32 *a3, u32 *a4, u32 *a5,
	u32 *a6, u32 *a7, u32 *a8, u32 *a9, u32 *a10, u32 *a11, u32 *a12,
	u32 *a13, u32 *a14, u32 *a15, u32 *a16, u32 *a17, u32 *a18,
	u32 *a19, u32 *a20, u32 *a21, u32 *a22, u32 *a23, u32 *a24,
	u32 *a25, u32 *a26, u32 *a27, u32 *a28, u32 *a29, u32 *a30)
{
	struct t31_wdr_fpga p = {
		.model=a1, .deviation=a2, .ratio=a3, .x=a4, .y=a5, .threshold=a6,
		.xy=a7, .motion=a8, .normal=a9, .normal1=a10, .normal2=a11,
		.minimum=a12, .secondary=a13, .low=a14, .high=a15,
		.hist={{a16,a17,a18},{a19,a20,a21}}, .map={a22,a24,a23},
		.labels=a25, .label_bits=a26, .all=a27, .range=a28,
		.detail_in=a29, .detail=a30
	};
	int ret;
	/* External callers share the instance scratch with the frame worker. */
	mutex_lock(&wdr_control_lock);
	ret = t31_wdr_fpga_calculate(&p, &wdr_scratch);
	mutex_unlock(&wdr_control_lock);
	return ret;
}

int tiziano_wdr_soft_para_out(void)
{
	t31_wdr_write_result(wdr_write, NULL, &wdr_fpga, param_wdr_para_array,
		param_wdr_detail_th_w_array, param_fusion1_cure_y_array,
		param_wdr_degost_para_array);
	return 0;
}

static int tiziano_wdr_algorithm(void)
{
	u32 i, ratio, count;
	int ret = tisp_wdr_expTime_updata();
	if (ret)
		return ret;
	ret = tisp_wdr_ev_calculate();
	if (ret)
		return ret;
	for (i = 0; i < 27; ++i)
		wdr_thrAll_software_out[i] = t31_wdr_lerp(wdr_ev.now,
			wdr_ev_list_deghost[0], wdr_ev_list_deghost[4],
			param_multiValueLow_software_in_array[min(i, 25U)],
			param_multiValueHigh_software_in_array[min(i, 25U)]);
	param_xy_pix_low_software_in_array[14] = param_wdr_degost_para_array[12];
	ret = t31_wdr_fpga_calculate(&wdr_fpga, &wdr_scratch);
	if (ret)
		return ret;
	if (param_wdr_tool_control_array[0] == 1)
		param_wdr_degost_para_array[12] = 0;
	ratio = (param_ratioPara_software_in_array[1] << 12) /
		(param_ratioPara_software_in_array[0] + 1);
	param_wdr_tool_control_array[10] = ratio;
	if (param_wdr_tool_control_array[12] == 1)
		ratio = wdr_ev.short_to_long;
	param_wdr_tool_control_array[11] = ratio;
	if (param_wdr_tool_control_array[8] == 1)
		ratio -= param_wdr_tool_control_array[9];
	for (i = 0; i < 3; ++i) {
		wdr_detial_para_software_out[i * 3] = 0;
		wdr_detial_para_software_out[i * 3 + 1] = 0;
		wdr_detial_para_software_out[i * 3 + 2] = ratio;
	}
	count = clamp(param_wdr_weightLUT21_array[31], 4U, 8U);
	param_wdr_weightLUT21_array[31] = count;
	wdr_block_mean1_end = t31_wdr_bright_blocks(wdr_blocks_snapshot, count);
	param_wdr_gam_y_array[30] = wdr_block_mean1_end;
	wdr_block_mean1_end_old = t31_wdr_slew(wdr_block_mean1_end_old,
		wdr_block_mean1_end, param_wdr_weightLUT21_array[28] == 1,
		param_wdr_weightLUT21_array[29]);
	if (param_wdr_gam_y_array[0] == 2 && param_wdr_tool_control_array[13] == 1)
		return tiziano_wdr_fusion1_curve_block_mean1();
	return 0;
}

static int tiziano_wdr_get_data(void *buf)
{
	return t31_wdr_unpack_stats(&wdr_stats, buf, T31_WDR_STATS_BYTES);
}

static void t31_wdr_work(struct work_struct *work)
{
	unsigned long flags;
	int ret;
	(void)work;
	mutex_lock(&wdr_control_lock);
	if (!wdr_ready)
		goto done;
	spin_lock_irqsave(&wdr_stats_lock, flags);
	if (!wdr_stats_pending) {
		spin_unlock_irqrestore(&wdr_stats_lock, flags);
		goto done;
	}
	memcpy(wdr_packed, wdr_pending, sizeof(wdr_packed));
	memcpy(wdr_blocks_snapshot, wdr_block_mean1, sizeof(wdr_blocks_snapshot));
	wdr_stats_pending = false;
	if (wdr_ev_pending) {
		t31_wdr_ev_update(&wdr_ev, wdr_ev_low, wdr_ev_high);
		wdr_ev_pending = false;
	}
	spin_unlock_irqrestore(&wdr_stats_lock, flags);
	ret = tiziano_wdr_get_data(wdr_packed);
	if (!ret)
		ret = tiziano_wdr_algorithm();
	if (!ret) {
		tiziano_wdr_soft_para_out();
		wdr_frame = (wdr_frame + 1) % 30;
	} else if (ret != -EAGAIN)
		pr_warn_ratelimited("T31 WDR: invalid calibration, keeping previous registers (%d)\n", ret);
done:
	mutex_unlock(&wdr_control_lock);
}

int tisp_wdr_process(void)
{
	/* The ISP event dispatcher holds IRQs off. Histogram matching belongs
	 * on a worker: no allocation, mutex, or long calculation in that context. */
	if (ACCESS_ONCE(wdr_ready))
		schedule_work(&wdr_work);
	return 0;
}
EXPORT_SYMBOL(tisp_wdr_process);

static irqreturn_t wdr_interrupt_wrapper(int irq, void *context)
{
	(void)irq;
	(void)context;
	return tiziano_wdr_interrupt_static() ? IRQ_HANDLED : IRQ_NONE;
}

int tisp_wdr_init(void)
{
	memset(&wdr_ev, 0, sizeof(wdr_ev));
	memset(&wdr_stats, 0, sizeof(wdr_stats));
	wdr_block_mean1_end = wdr_block_mean1_end_old = 0;
	wdr_frame = 0;
	wdr_stats_pending = wdr_ev_pending = false;
	return tiziano_wdr_params_refresh();
}

static u32 wdr_area_reciprocal(u32 area, u32 scale)
{
	u32 divisor = (area + 2) >> 2;
	return divisor ? (((area + 2) / 8 + scale) / divisor) & 0xfff : 0;
}

int tiziano_wdr_init(u32 width, u32 height)
{
	u32 bw = ((width + 8) / 16) & ~1U;
	u32 bh = ((height + 5) / 10) & ~1U;
	u32 last_w, last_h, scale = 0, shift = 0, i, j, v;
	u32 coordinates[17];
	int ret;
	if (!bw || !bh || width > 4095 || height > 4095 ||
	    15 * bw >= width || 9 * bh >= height || !wdr_dma_buffer)
		return -EINVAL;
	ACCESS_ONCE(wdr_ready) = false;
	cancel_work_sync(&wdr_work);
	mutex_lock(&wdr_control_lock);
	width_wdr_def = width;
	height_wdr_def = height;
	ret = tisp_wdr_init();
	if (ret)
		goto done;
	param_wdr_tool_control_array[2] = (min((bw + 1) / 2, (bh + 1) / 2) * 3 + 1) / 2;
	ret = tiziano_wdr_5x5_param();
	if (ret)
		goto done;
	for (i = 0; i < 5; ++i)
		for (j = 0; j < 32; j += 4) {
			const u32 *p = &param_wdr_weight_lut_def[i][j];
			v = (p[0] & 31) | ((p[1] & 31) << 8) |
				((p[2] & 31) << 16) | ((p[3] & 31) << 24);
			system_reg_write(0x23ac + i * 32 + j, v);
		}
	t31_wdr_write_pairs(wdr_write, NULL, 0x2500,
		param_centre5x5_w_distance_array_def, 31, 0xffff);
	ret = tiziano_wdr_params_init();
	if (ret)
		goto done;
	/* A unity map provides valid endpoints before the first DMA result. */
	for (i = 0; i < 81; ++i) {
		v = i == 0 ? 0 : i <= 16 ? i * 16 - 1 : i <= 24 ? i * 32 - 257 : i * 64 - 1025;
		wdr_mapR_software_out[i] = v;
		wdr_mapG_software_out[i] = v;
		wdr_mapB_software_out[i] = v;
	}
	for (i = 0; i < 26; ++i)
		wdr_thrLableN_software_out[i] = t31_wdr_log2(param_wdr_thrLable_array[i + 1] - param_wdr_thrLable_array[i]);
	for (i = 0; i < 27; ++i)
		wdr_thrRangeK_software_out[i] = wdr_thrAll_software_out[i] ?
			(wdr_thrAll_software_out[i] / 2 + param_motionThrPara_software_in_array[1] * 16384) / wdr_thrAll_software_out[i] : 65536;
	tiziano_wdr_soft_para_out();
	for (i = 0; i < 10; ++i)
		coordinates[i] = i * bh;
	coordinates[10] = height;
	t31_wdr_write_pairs(wdr_write, NULL, 0x2370, coordinates, 11, 0xfff);
	for (i = 0; i < 16; ++i)
		coordinates[i] = i * bw;
	coordinates[16] = width;
	t31_wdr_write_pairs(wdr_write, NULL, 0x2388, coordinates, 17, 0xfff);
	for (i = 0; i < 10; ++i)
		if (bw * bh / 4 + 1 < (1U << i) * 256) {
			scale = 1U << (i + 18);
			shift = i + 18;
			break;
		}
	last_w = width - 15 * bw;
	last_h = height - 9 * bh;
	system_reg_write(0x2640, wdr_area_reciprocal(bw * bh, scale) |
		(wdr_area_reciprocal(bw * last_h, scale) << 16));
	system_reg_write(0x2644, wdr_area_reciprocal(bh * last_w, scale) |
		(wdr_area_reciprocal(last_w * last_h, scale) << 16));
	system_reg_write(0x2648, shift);
	system_irq_func_set(11, wdr_interrupt_wrapper);
	tisp_event_set_cb(11, tisp_wdr_process);
	t31_wdr_ev_update(&wdr_ev, data_9a454, 0);
	ACCESS_ONCE(wdr_ready) = true;
done:
	mutex_unlock(&wdr_control_lock);
	return ret;
}
EXPORT_SYMBOL(tiziano_wdr_init);

static int tiziano_wdr_dn_params_refresh(void)
{
	int ret;
	if (!wdr_ready)
		return 0;
	mutex_lock(&wdr_control_lock);
	ret = tiziano_wdr_params_refresh();
	if (!ret)
		ret = tiziano_wdr_params_init();
	mutex_unlock(&wdr_control_lock);
	return ret;
}
