/* SPDX-License-Identifier: GPL-2.0 */
/* Host adapter for the actual driver integration; hardware and scheduling are mocked. */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "../driver/t31/tx_isp_t31_wdr_control.h"
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define TISP_PARAM_BLOCK_SIZE 0x137f0
#define min(a,b) ((a)<(b)?(a):(b))
#define clamp(v,lo,hi) ((v)<(lo)?(lo):((v)>(hi)?(hi):(v)))
#define ACCESS_ONCE(v) (v)
#define mutex_lock(p) ((void)(p))
#define mutex_unlock(p) ((void)(p))
#define spin_lock_irqsave(p,f) do { (void)(p); (f)=0; } while(0)
#define spin_unlock_irqrestore(p,f) do { (void)(p); (void)(f); } while(0)
#define cancel_work_sync(p) ((void)(p))
#define schedule_work(p) ((void)(p))
#define EXPORT_SYMBOL(n)
#define pr_warn_ratelimited(...) ((void)0)
#define IRQ_HANDLED 1
#define IRQ_NONE 0
typedef int irqreturn_t;
struct work_struct { int pending; };
static struct work_struct wdr_work;
static int wdr_control_lock,wdr_stats_lock;
static u32 registers[0x2700/4];
static u32 register_log[2048][2],register_count;
static u16 test_gamma[129];
static u32 tisp_ae_ctrls[38];
static u32 data_9a454;
static void *tparams_day,*tparams_active;
static void *wdr_dma_buffer=(void*)1;
static struct t31_wdr_ev wdr_ev;
static struct t31_wdr_stats wdr_stats;
static struct t31_wdr_scratch wdr_scratch;
static bool wdr_ready,wdr_stats_pending,wdr_ev_pending;
static u32 wdr_ev_low,wdr_ev_high,width_wdr_def,height_wdr_def,wdr_frame;
static u32 wdr_pending[T31_WDR_STATS_BYTES/4],wdr_packed[T31_WDR_STATS_BYTES/4];
static u32 wdr_block_mean1[225],wdr_blocks_snapshot[225];
static u32 wdr_block_mean1_end,wdr_block_mean1_end_old;
static u32 wdr_mapR_software_out[81],wdr_mapG_software_out[81],wdr_mapB_software_out[81];
static u32 wdr_thrLableN_software_out[26],wdr_thrRangeK_software_out[27],wdr_detial_para_software_out[9];
static u32 param_wdr_weight_lut_def[5][32],param_centre5x5_w_distance_array_def[31];
static u32 wdr_gam_y33_array[33],param_wdr_gam_y_array_def[33];
static int tiziano_wdr_params_init(void);
static int system_reg_write(u32 reg,u32 value) {
 assert(reg<sizeof(registers)); assert(register_count<ARRAY_SIZE(register_log));
 registers[reg/4]=value;register_log[register_count][0]=reg;
 register_log[register_count++][1]=value;return 0;
}
static int tisp_gamma_param_array_get(int id,void*buf,int*size) {
 assert(id==0x3d);memcpy(buf,test_gamma,sizeof(test_gamma));*size=sizeof(test_gamma);return 0;
}
static int tiziano_wdr_interrupt_static(void){return 1;}
static int system_irq_func_set(int id,irqreturn_t(*fn)(int,void*)) {(void)fn;assert(id==11);return 0;}
static int tisp_event_set_cb(int id,void*fn){(void)fn;assert(id==11);return 0;}
static u32 param_wdr_para_array[10];
static u32 param_wdr_weightLUT20_array[32];
static u32 param_wdr_weightLUT02_array[32];
static u32 param_wdr_weightLUT12_array[32];
static u32 param_wdr_weightLUT22_array[32];
static u32 param_wdr_weightLUT21_array[32];
static u32 param_wdr_gam_y_array[33];
static u32 param_wdr_w_point_weight_x_array[4];
static u32 param_wdr_w_point_weight_y_array[4];
static u32 param_wdr_w_point_weight_pow_array[3];
static u32 param_fusion1_cure_y_array[33];
static u32 param_wdr_detail_th_w_array[7];
static u32 param_wdr_contrast_t_y_mux_array[5];
static u32 param_wdr_ct_cl_para_array[4];
static u32 param_centre5x5_w_distance_array[31];
static u32 param_wdr_stat_para_array[7];
static u32 param_wdr_degost_para_array[13];
static u32 param_wdr_darkLable_array[5];
static u32 param_wdr_darkLableN_array[4];
static u32 param_wdr_darkWeight_array[5];
static u32 param_wdr_thrLable_array[27];
static u32 param_computerModle_software_in_array[4];
static u32 param_deviationPara_software_in_array[5];
static u32 param_ratioPara_software_in_array[7];
static u32 param_x_thr_software_in_array[4];
static u32 param_y_thr_software_in_array[4];
static u32 param_thrPara_software_in_array[20];
static u32 param_xy_pix_low_software_in_array[22];
static u32 param_motionThrPara_software_in_array[17];
static u32 param_d_thr_normal_software_in_array[26];
static u32 param_d_thr_normal1_software_in_array[26];
static u32 param_d_thr_normal2_software_in_array[26];
static u32 param_d_thr_normal_min_software_in_array[26];
static u32 param_multiValueLow_software_in_array[26];
static u32 param_multiValueHigh_software_in_array[26];
static u32 param_d_thr_2_software_in_array[26];
static u32 param_wdr_detial_para_software_in_array[8];
static u32 wdr_thrAll_software_out[27];
static u32 param_wdr_dbg_out_array[2];
static u32 wdr_ev_list[9];
static u32 wdr_weight_b_in_list[9];
static u32 wdr_weight_p_in_list[9];
static u32 wdr_ev_list_deghost[9];
static u32 wdr_weight_in_list_deghost[9];
static u32 wdr_detail_w_in0_list[9];
static u32 wdr_detail_w_in1_list[9];
static u32 wdr_detail_w_in2_list[9];
static u32 wdr_detail_w_in3_list[9];
static u32 wdr_detail_w_in4_list[9];
static u32 param_wdr_priv_array[16];
static u32 param_wdr_tool_control_array[14];
#include "../driver/t31/tx_isp_t31_wdr_runtime.inc"
/* Exposed only by the host shared library used by the offline oracle. */
u32 *test_param(unsigned index){return index<ARRAY_SIZE(wdr_parameters)?wdr_parameters[index].data:NULL;}
u32 test_param_size(unsigned index){return wdr_parameters[index].bytes;}
void test_reset_log(void){register_count=0;}
u32 *test_log(void){return &register_log[0][0];}
u32 test_log_count(void){return register_count;}
u16 *test_gamma_data(void){return test_gamma;}
int test_param_init(void){return tiziano_wdr_params_init();}
void test_set_bank(void *bank){tparams_active=bank;}
int test_refresh(void){return tiziano_wdr_params_refresh();}
void test_run_work(void){t31_wdr_work(&wdr_work);}

#include "t31_wdr_fixture.h"
static const u32 fpga_sizes[30] = {
	4,5,7,4,4,20,22,17,26,26,26,26,26,26,26,
	256,256,256,256,256,256,81,81,81,27,26,27,27,8,9
};
static u32 *const fpga_arguments[30] = {
	param_computerModle_software_in_array, param_deviationPara_software_in_array,
	param_ratioPara_software_in_array, param_x_thr_software_in_array,
	param_y_thr_software_in_array, param_thrPara_software_in_array,
	param_xy_pix_low_software_in_array, param_motionThrPara_software_in_array,
	param_d_thr_normal_software_in_array, param_d_thr_normal1_software_in_array,
	param_d_thr_normal2_software_in_array, param_d_thr_normal_min_software_in_array,
	param_d_thr_2_software_in_array, param_multiValueLow_software_in_array,
	param_multiValueHigh_software_in_array,
	wdr_stats.rgb[0][0], wdr_stats.rgb[0][1], wdr_stats.rgb[0][2],
	wdr_stats.rgb[1][0], wdr_stats.rgb[1][1], wdr_stats.rgb[1][2],
	wdr_mapR_software_out, wdr_mapB_software_out, wdr_mapG_software_out,
	param_wdr_thrLable_array, wdr_thrLableN_software_out,
	wdr_thrAll_software_out, wdr_thrRangeK_software_out,
	param_wdr_detial_para_software_in_array, wdr_detial_para_software_out
};

u32 *test_fpga_arg(u32 index) { return fpga_arguments[index]; }
u32 test_fpga_size(u32 index) { return fpga_sizes[index]; }
struct t31_wdr_ev *test_ev_state(void) { return &wdr_ev; }
u32 *test_ae_controls(void) { return tisp_ae_ctrls; }

static u32 fixture_random(u32 *state)
{
	u32 v = *state;
	v ^= v << 13;
	v ^= v >> 17;
	v ^= v << 5;
	return *state = v;
}

static u32 hash_words(u32 hash, const u32 *words, u32 count)
{
	u32 i, byte;
	for (i = 0; i < count; ++i)
		for (byte = 0; byte < 4; ++byte) {
			hash ^= (words[i] >> (byte * 8)) & 255;
			hash *= 16777619U;
		}
	return hash;
}

void test_fixture_reset(void)
{
	u32 i;
	for (i = 0; i < ARRAY_SIZE(wdr_parameters); ++i)
		memcpy(wdr_parameters[i].data, wdr_fixture_params[i], wdr_parameters[i].bytes);
	for (i = 0; i < 129; ++i)
		test_gamma[i] = i * 4095 / 128;
	memset(&wdr_stats, 0, sizeof(wdr_stats));
	memset(&wdr_ev, 0, sizeof(wdr_ev));
	memset(wdr_thrLableN_software_out, 0, sizeof(wdr_thrLableN_software_out));
	memset(wdr_thrRangeK_software_out, 0, sizeof(wdr_thrRangeK_software_out));
	memset(wdr_detial_para_software_out, 0, sizeof(wdr_detial_para_software_out));
	for (i = 0; i < 81; ++i)
		wdr_mapR_software_out[i] = wdr_mapG_software_out[i] = wdr_mapB_software_out[i] = i * 49;
	wdr_ready = wdr_ev_pending = wdr_stats_pending = false;
	register_count = 0;
}

void test_fpga_prepare(u32 test_case)
{
	static const u32 short_time[12] = {10,50,96,97,200,240,400,800,801,1346,2048,3000};
	u32 seed = test_case + 0x31000, c, i, value, shape = (test_case / 36) % 6;
	test_fixture_reset();
	param_computerModle_software_in_array[0] = test_case % 2;
	param_computerModle_software_in_array[1] = (test_case / 2) % 3;
	param_computerModle_software_in_array[2] = (test_case / 6) % 2;
	param_computerModle_software_in_array[3] = (test_case / 12) % 3;
	param_ratioPara_software_in_array[0] = short_time[test_case % 12];
	param_ratioPara_software_in_array[1] = short_time[test_case % 12] * (test_case % 8 + 1);
	if (test_case % 4) {
		param_deviationPara_software_in_array[3] = test_case % 10;
		param_deviationPara_software_in_array[4] = 30;
		param_xy_pix_low_software_in_array[4] = 1;
		param_xy_pix_low_software_in_array[8] = 1;
	}
	param_xy_pix_low_software_in_array[12] = test_case % 3 != 0;
	for (c = 0; c < 6; ++c)
		for (i = 0; i < 256; ++i) {
			value = 100 + fixture_random(&seed) % 900;
			if (shape == 1)
				value = i < (c < 3 ? 130 : 45) ? value * 8 : value;
			else if (shape == 2)
				value = i > (c < 3 ? 160 : 80) ? value * 10 : value;
			else if (shape == 3)
				value = i == (c < 3 ? 75 : 25) ? 100000 : value;
			else if (shape == 4)
				value = (i + 1) * (c < 3 ? 13 : 7) + value;
			else if (shape == 5)
				value = (256 - i) * (c < 3 ? 9 : 15) + value;
			wdr_stats.rgb[c / 3][c % 3][i] = value;
		}
}

int test_fpga_calculate(void) { return t31_wdr_fpga_calculate(&wdr_fpga, &wdr_scratch); }
u32 test_fpga_hash(void)
{
	u32 i, hash = 2166136261U;
	for (i = 0; i < 30; ++i)
		hash = hash_words(hash, fpga_arguments[i], fpga_sizes[i]);
	return hash;
}

void test_init_prepare(u32 test_case)
{
	static const u32 modes[6] = {0,1,2,3,8,9};
	static const u32 overrides[3] = {0,1,9};
	u32 i, j;
	test_fixture_reset();
	if (test_case >= 36)
		for (i = 0; i < 50; ++i)
			for (j = 0; j < wdr_parameters[i].bytes / 4; ++j)
				wdr_parameters[i].data[j] = j * 0xabcdeU + 0x12345678U;
	param_wdr_tool_control_array[0] = modes[(test_case / 6) % 6];
	param_wdr_tool_control_array[4] = overrides[(test_case / 2) % 3];
	param_wdr_tool_control_array[5] = 245;
	param_wdr_tool_control_array[6] = 12;
	param_wdr_tool_control_array[7] = test_case % 2;
}

u32 test_log_hash(void) { return hash_words(2166136261U, &register_log[0][0], register_count * 2); }

void test_output_prepare(u32 test_case)
{
	u32 i, j;
	test_init_prepare(test_case);
	for (i = 21; i < 30; ++i)
		for (j = 0; j < fpga_sizes[i]; ++j)
			fpga_arguments[i][j] = test_case >= 36 ? 0x12345678U + j * 0xabcdeU : j * 49 + i;
}

u32 test_spatial_case(u32 test_case)
{
	static const u32 cases[5][3] = {
		{64,40,8},{1920,1080,90},{2048,1536,96},{640,480,30},{1281,721,60}
	};
	u32 hash;
	assert(test_case < 5);
	assert(t31_wdr_spatial(param_wdr_weight_lut_def,
		param_centre5x5_w_distance_array_def, cases[test_case][0],
		cases[test_case][1], cases[test_case][2], &wdr_scratch.spatial) == 0);
	hash = hash_words(2166136261U, &param_wdr_weight_lut_def[0][0], 160);
	return hash_words(hash, param_centre5x5_w_distance_array_def, 31);
}

void test_ev_prepare(u32 test_case)
{
	u32 i, j, seed = test_case + 0xe031;
	const u32 *values[7] = {wdr_detail_w_in0_list,wdr_detail_w_in1_list,wdr_detail_w_in2_list,
		wdr_detail_w_in3_list,wdr_detail_w_in4_list,wdr_weight_b_in_list,wdr_weight_p_in_list};
	test_fixture_reset();
	wdr_ev.now = wdr_ev.old = test_case * 13;
	wdr_ev.changed = test_case % 4 != 0;
	wdr_ev.delta = (test_case % 40) * 40;
	for (i = 0; i < 9; ++i) {
		wdr_ev_list[i] = wdr_ev_list_deghost[i] = i * 100;
		wdr_weight_in_list_deghost[i] = fixture_random(&seed) % 33;
		for (j = 0; j < 7; ++j)
			((u32 *)values[j])[i] = fixture_random(&seed) % (j < 5 ? 128 : 40000);
		for (j = 0; j < 7; ++j)
			((u32 *)wdr_fusion_tables[i / 2])[i % 2 * 8 + j + 1] =
				j < 3 ? j * 10 + 2 + fixture_random(&seed) % 5 : fixture_random(&seed) % 257;
		param_wdr_gam_y_array[i * 3 + 1] = fixture_random(&seed) % 30 + 1;
		param_wdr_gam_y_array[i * 3 + 2] = 256;
		param_wdr_gam_y_array[i * 3 + 3] = fixture_random(&seed) % 100;
	}
	for (i = 0; i < 7; ++i)
		wdr_ev.output[i] = i * 11;
	param_wdr_gam_y_array[0] = test_case % 3;
	param_wdr_gam_y_array[31] = 100;
	param_wdr_tool_control_array[13] = test_case % 2;
	tisp_ae_ctrls[19] = 75 + test_case % 80;
	param_xy_pix_low_software_in_array[16] = test_case % 2;
	param_xy_pix_low_software_in_array[17] = (test_case / 2) % 2;
}

u32 test_ev_hash(void)
{
	u32 hash = hash_words(2166136261U, (const u32 *)&wdr_ev, sizeof(wdr_ev) / 4);
	hash = hash_words(hash, param_wdr_para_array, 10);
	hash = hash_words(hash, param_wdr_detail_th_w_array, 7);
	hash = hash_words(hash, param_wdr_degost_para_array, 13);
	return hash_words(hash, param_fusion1_cure_y_array, 33);
}

#ifndef T31_WDR_ORACLE_LIBRARY
#include "t31_wdr_oracle_expected.h"

static void test_parameter_bank(void)
{
	static u32 bank[TISP_PARAM_BLOCK_SIZE / 4];
	u32 out[33], i, j, saved = 91;
	int size;
	for (i = 0; i < ARRAY_SIZE(bank); ++i)
		bank[i] = i * 17 + 1;
	test_set_bank(bank);
	param_wdr_tool_control_array[2] = saved;
	assert(test_refresh() == 0);
	for (i = 0; i < 51; ++i) {
		assert(t31_wdr_param_get(0x3ff + i, out, &size) == 0);
		assert(size == (int)wdr_parameters[i].bytes);
		for (j = 0; j < (u32)size / 4; ++j)
			assert(out[j] == (i == 50 && j == 2 ? saved : bank[wdr_parameters[i].offset / 4 + j]));
	}
	assert(t31_wdr_param_get(0x3fe, out, &size) == -EINVAL);
	assert(t31_wdr_param_set(0x432, out, &size) == -EINVAL);
	assert(t31_wdr_param_get(0x3ff, NULL, &size) == -EINVAL);
	assert(t31_wdr_param_set(0x3ff, out, NULL) == -EINVAL);
	test_set_bank(NULL);
	assert(test_refresh() == -ENODATA);
}

int main(void)
{
	u32 i;
	test_parameter_bank();
	for (i = 0; i < ARRAY_SIZE(wdr_fpga_expected); ++i) {
		test_fpga_prepare(i);
		assert(test_fpga_calculate() == 0);
		assert(test_fpga_hash() == wdr_fpga_expected[i]);
	}
	for (i = 0; i < ARRAY_SIZE(wdr_init_expected); ++i) {
		test_init_prepare(i);
		assert(test_param_init() == 0);
		assert(test_log_hash() == wdr_init_expected[i]);
	}
	for (i = 0; i < ARRAY_SIZE(wdr_ev_expected); ++i) {
		test_ev_prepare(i);
		assert(tisp_wdr_ev_calculate() == 0);
		assert(test_ev_hash() == wdr_ev_expected[i]);
	}
	for (i = 0; i < ARRAY_SIZE(wdr_output_expected); ++i) {
		test_output_prepare(i);
		assert(tiziano_wdr_soft_para_out() == 0);
		assert(test_log_hash() == wdr_output_expected[i]);
	}
	for (i = 0; i < ARRAY_SIZE(wdr_spatial_expected); ++i)
		assert(test_spatial_case(i) == wdr_spatial_expected[i]);
	/* Invalid knots/exposure must not read outside any map or divide by zero. */
	test_fpga_prepare(0);
	param_ratioPara_software_in_array[0] = 0;
	assert(test_fpga_calculate() == -EINVAL);
	param_ratioPara_software_in_array[0] = 100;
	param_wdr_thrLable_array[2] = param_wdr_thrLable_array[1];
	assert(test_fpga_calculate() == -EINVAL);
	test_fixture_reset();
	tisp_ae_ctrls[19] = 0;
	assert(tisp_wdr_expTime_updata() == -EAGAIN);
	assert(tiziano_wdr_dn_params_refresh() == 0);
	puts("T31 WDR: parameter bank, 432 FPGA, 144 register, 240 EV, 5 spatial oracle cases passed");
	return 0;
}
#endif
