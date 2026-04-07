/*
 * mdns_intp_generated.c - Generated MDNS interpolation code
 *
 * This file contains:
 *   A) Static global declarations for all _intp variables
 *   B) The full tisp_mdns_intp() function body
 *   C) Rewritten param_cfg functions using _intp globals
 *
 * Integration: paste sections into tx_isp_tuning.c at the indicated locations.
 */

/* ====================================================================
 * SECTION A: Static global declarations for _intp variables
 *
 * PLACEMENT: After the existing mdns_y_ass_wei_adj_value1_intp[16] and
 *            mdns_c_false_edg_thres1_intp[16] declarations (around line 1112).
 *
 * NOTE: The two array-type _intp variables already exist at line 1111-1112:
 *   static uint32_t mdns_y_ass_wei_adj_value1_intp[16];
 *   static uint32_t mdns_c_false_edg_thres1_intp[16];
 * Those are DIFFERENT variables (array types used elsewhere). The scalar
 * _intp globals below are new and separate.
 * ====================================================================
 */

/* --- Y-channel SAD/STA parameters --- */
static u32 mdns_y_sad_win_opt_intp;
static u32 mdns_y_sad_ave_thres_intp;
static u32 mdns_y_sad_ave_slope_intp;
static u32 mdns_y_sad_dtb_thres_intp;
static u32 mdns_y_sad_ass_thres_intp;
static u32 mdns_y_sta_blk_size_intp;
static u32 mdns_y_sta_win_opt_intp;
static u32 mdns_y_sta_ave_thres_intp;
static u32 mdns_y_sta_dtb_thres_intp;
static u32 mdns_y_sta_ass_thres_intp;
static u32 mdns_y_sta_motion_thres_intp;

/* --- Y-channel ref_wei parameters --- */
static u32 mdns_y_ref_wei_mv_intp;
static u32 mdns_y_ref_wei_fake_intp;
static u32 mdns_y_ref_wei_sta_fs_opt_intp;
static u32 mdns_y_ref_wei_psn_fs_opt_intp;
static u32 mdns_y_ref_wei_f_max_intp;
static u32 mdns_y_ref_wei_f_min_intp;
static u32 mdns_y_ref_wei_b_max_intp;
static u32 mdns_y_ref_wei_b_min_intp;
static u32 mdns_y_ref_wei_r_max_intp;
static u32 mdns_y_ref_wei_r_min_intp;
static u32 mdns_y_ref_wei_increase_intp;

/* --- Y-channel corner parameters --- */
static u32 mdns_y_corner_length_t_intp;
static u32 mdns_y_corner_length_b_intp;
static u32 mdns_y_corner_length_l_intp;
static u32 mdns_y_corner_length_r_intp;

/* --- Y-channel edge parameters --- */
static u32 mdns_y_edge_win_opt_intp;
static u32 mdns_y_edge_div_opt_intp;
static u32 mdns_y_edge_type_opt_intp;

/* --- Y-channel luma parameters --- */
static u32 mdns_y_luma_win_opt_intp;

/* --- Y-channel dtb parameters --- */
static u32 mdns_y_dtb_div_opt_intp;
static u32 mdns_y_dtb_squ_en_intp;
static u32 mdns_y_dtb_squ_div_opt_intp;

/* --- Y-channel ass parameters --- */
static u32 mdns_y_ass_win_opt_intp;
static u32 mdns_y_ass_div_opt_intp;

/* --- Y-channel hist parameters --- */
static u32 mdns_y_hist_sad_en_intp;
static u32 mdns_y_hist_sta_en_intp;
static u32 mdns_y_hist_num_thres_intp;
static u32 mdns_y_hist_cmp_thres0_intp;
static u32 mdns_y_hist_cmp_thres1_intp;
static u32 mdns_y_hist_cmp_thres2_intp;
static u32 mdns_y_hist_cmp_thres3_intp;
static u32 mdns_y_hist_thres0_intp;
static u32 mdns_y_hist_thres1_intp;
static u32 mdns_y_hist_thres2_intp;
static u32 mdns_y_hist_thres3_intp;

/* --- Y-channel thr_adj_seg parameters --- */
static u32 mdns_y_edge_thr_adj_seg_intp;
static u32 mdns_y_luma_thr_adj_seg_intp;
static u32 mdns_y_dtb_thr_adj_seg_intp;
static u32 mdns_y_ass_thr_adj_seg_intp;

/* --- Y-channel corner/edge/luma/dtb/ass thr_adj_value parameters --- */
static u32 mdns_y_corner_thr_adj_value_intp;
static u32 mdns_y_edge_thr_adj_value0_intp;
static u32 mdns_y_edge_thr_adj_value1_intp;
static u32 mdns_y_edge_thr_adj_value2_intp;
static u32 mdns_y_edge_thr_adj_value3_intp;
static u32 mdns_y_edge_thr_adj_value4_intp;
static u32 mdns_y_edge_thr_adj_value5_intp;
static u32 mdns_y_luma_thr_adj_value0_intp;
static u32 mdns_y_luma_thr_adj_value1_intp;
static u32 mdns_y_luma_thr_adj_value2_intp;
static u32 mdns_y_luma_thr_adj_value3_intp;
static u32 mdns_y_luma_thr_adj_value4_intp;
static u32 mdns_y_luma_thr_adj_value5_intp;
static u32 mdns_y_dtb_thr_adj_value0_intp;
static u32 mdns_y_dtb_thr_adj_value1_intp;
static u32 mdns_y_dtb_thr_adj_value2_intp;
static u32 mdns_y_dtb_thr_adj_value3_intp;
static u32 mdns_y_dtb_thr_adj_value4_intp;
static u32 mdns_y_dtb_thr_adj_value5_intp;
static u32 mdns_y_ass_thr_adj_value0_intp;
static u32 mdns_y_ass_thr_adj_value1_intp;
static u32 mdns_y_ass_thr_adj_value2_intp;
static u32 mdns_y_ass_thr_adj_value3_intp;
static u32 mdns_y_ass_thr_adj_value4_intp;
static u32 mdns_y_ass_thr_adj_value5_intp;

/* --- Y-channel wei_adj_seg parameters --- */
static u32 mdns_y_edge_wei_adj_seg_intp;
static u32 mdns_y_luma_wei_adj_seg_intp;
static u32 mdns_y_dtb_wei_adj_seg_intp;
static u32 mdns_y_ass_wei_adj_seg_intp;
static u32 mdns_y_sad_wei_adj_seg_intp;

/* --- Y-channel corner/edge/luma/dtb/ass/sad wei_adj_value parameters --- */
static u32 mdns_y_corner_wei_adj_value_intp;
static u32 mdns_y_edge_wei_adj_value0_intp;
static u32 mdns_y_edge_wei_adj_value1_intp;
static u32 mdns_y_edge_wei_adj_value2_intp;
static u32 mdns_y_edge_wei_adj_value3_intp;
static u32 mdns_y_edge_wei_adj_value4_intp;
static u32 mdns_y_edge_wei_adj_value5_intp;
static u32 mdns_y_luma_wei_adj_value0_intp;
static u32 mdns_y_luma_wei_adj_value1_intp;
static u32 mdns_y_luma_wei_adj_value2_intp;
static u32 mdns_y_luma_wei_adj_value3_intp;
static u32 mdns_y_luma_wei_adj_value4_intp;
static u32 mdns_y_luma_wei_adj_value5_intp;
static u32 mdns_y_dtb_wei_adj_value0_intp;
static u32 mdns_y_dtb_wei_adj_value1_intp;
static u32 mdns_y_dtb_wei_adj_value2_intp;
static u32 mdns_y_dtb_wei_adj_value3_intp;
static u32 mdns_y_dtb_wei_adj_value4_intp;
static u32 mdns_y_dtb_wei_adj_value5_intp;
static u32 mdns_y_ass_wei_adj_value0_intp;
static u32 mdns_y_ass_wei_adj_value1_intp_scalar; /* NOTE: _scalar suffix to avoid collision with existing array */
static u32 mdns_y_ass_wei_adj_value2_intp;
static u32 mdns_y_ass_wei_adj_value3_intp;
static u32 mdns_y_ass_wei_adj_value4_intp;
static u32 mdns_y_ass_wei_adj_value5_intp;
static u32 mdns_y_sad_wei_adj_value0_intp;
static u32 mdns_y_sad_wei_adj_value1_intp;
static u32 mdns_y_sad_wei_adj_value2_intp;
static u32 mdns_y_sad_wei_adj_value3_intp;
static u32 mdns_y_sad_wei_adj_value4_intp;
static u32 mdns_y_sad_wei_adj_value5_intp;

/* --- Y-channel 2D pspa parameters --- */
static u32 mdns_y_pspa_cur_median_win_opt_intp;
static u32 mdns_y_pspa_cur_bi_thres_intp;
static u32 mdns_y_pspa_cur_bi_wei_seg_intp;
static u32 mdns_y_pspa_cur_bi_wei0_intp;
static u32 mdns_y_pspa_cur_bi_wei1_intp;
static u32 mdns_y_pspa_cur_bi_wei2_intp;
static u32 mdns_y_pspa_cur_bi_wei3_intp;
static u32 mdns_y_pspa_cur_bi_wei4_intp;
static u32 mdns_y_pspa_cur_lmt_op_en_intp;
static u32 mdns_y_pspa_cur_lmt_wei_intp;
static u32 mdns_y_pspa_ref_median_win_opt_intp;
static u32 mdns_y_pspa_ref_bi_thres_intp;
static u32 mdns_y_pspa_ref_bi_wei_seg_intp;
static u32 mdns_y_pspa_ref_bi_wei0_intp;
static u32 mdns_y_pspa_ref_bi_wei1_intp;
static u32 mdns_y_pspa_ref_bi_wei2_intp;
static u32 mdns_y_pspa_ref_bi_wei3_intp;
static u32 mdns_y_pspa_ref_bi_wei4_intp;
static u32 mdns_y_pspa_ref_lmt_op_en_intp;
static u32 mdns_y_pspa_ref_lmt_wei_intp;

/* --- Y-channel 2D piir parameters --- */
static u32 mdns_y_piir_edge_thres0_intp;
static u32 mdns_y_piir_edge_thres1_intp;
static u32 mdns_y_piir_edge_thres2_intp;
static u32 mdns_y_piir_edge_wei0_intp;
static u32 mdns_y_piir_edge_wei1_intp;
static u32 mdns_y_piir_edge_wei2_intp;
static u32 mdns_y_piir_edge_wei3_intp;
static u32 mdns_y_piir_cur_fs_wei_intp;
static u32 mdns_y_piir_ref_fs_wei_intp;

/* --- Y-channel 2D pspa fnl parameters --- */
static u32 mdns_y_pspa_fnl_fus_thres_intp;
static u32 mdns_y_pspa_fnl_fus_swei_intp;
static u32 mdns_y_pspa_fnl_fus_dwei_intp;

/* --- Y-channel 2D fspa cur parameters --- */
static u32 mdns_y_fspa_cur_fus_seg_intp;
static u32 mdns_y_fspa_cur_fus_wei_0_intp;
static u32 mdns_y_fspa_cur_fus_wei_16_intp;
static u32 mdns_y_fspa_cur_fus_wei_32_intp;
static u32 mdns_y_fspa_cur_fus_wei_48_intp;
static u32 mdns_y_fspa_cur_fus_wei_64_intp;
static u32 mdns_y_fspa_cur_fus_wei_80_intp;
static u32 mdns_y_fspa_cur_fus_wei_96_intp;
static u32 mdns_y_fspa_cur_fus_wei_112_intp;
static u32 mdns_y_fspa_cur_fus_wei_128_intp;
static u32 mdns_y_fspa_cur_fus_wei_144_intp;
static u32 mdns_y_fspa_cur_fus_wei_160_intp;
static u32 mdns_y_fspa_cur_fus_wei_176_intp;
static u32 mdns_y_fspa_cur_fus_wei_192_intp;
static u32 mdns_y_fspa_cur_fus_wei_208_intp;
static u32 mdns_y_fspa_cur_fus_wei_224_intp;
static u32 mdns_y_fspa_cur_fus_wei_240_intp;

/* --- Y-channel 2D fspa ref parameters --- */
static u32 mdns_y_fspa_ref_fus_seg_intp;
static u32 mdns_y_fspa_ref_fus_wei_0_intp;
static u32 mdns_y_fspa_ref_fus_wei_16_intp;
static u32 mdns_y_fspa_ref_fus_wei_32_intp;
static u32 mdns_y_fspa_ref_fus_wei_48_intp;
static u32 mdns_y_fspa_ref_fus_wei_64_intp;
static u32 mdns_y_fspa_ref_fus_wei_80_intp;
static u32 mdns_y_fspa_ref_fus_wei_96_intp;
static u32 mdns_y_fspa_ref_fus_wei_112_intp;
static u32 mdns_y_fspa_ref_fus_wei_128_intp;
static u32 mdns_y_fspa_ref_fus_wei_144_intp;
static u32 mdns_y_fspa_ref_fus_wei_160_intp;
static u32 mdns_y_fspa_ref_fus_wei_176_intp;
static u32 mdns_y_fspa_ref_fus_wei_192_intp;
static u32 mdns_y_fspa_ref_fus_wei_208_intp;
static u32 mdns_y_fspa_ref_fus_wei_224_intp;
static u32 mdns_y_fspa_ref_fus_wei_240_intp;

/* --- Y-channel 2D fiir parameters --- */
static u32 mdns_y_fiir_edge_thres0_intp;
static u32 mdns_y_fiir_edge_thres1_intp;
static u32 mdns_y_fiir_edge_thres2_intp;
static u32 mdns_y_fiir_edge_wei0_intp;
static u32 mdns_y_fiir_edge_wei1_intp;
static u32 mdns_y_fiir_edge_wei2_intp;
static u32 mdns_y_fiir_edge_wei3_intp;
static u32 mdns_y_fiir_fus_seg_intp;
static u32 mdns_y_fiir_fus_wei0_intp;
static u32 mdns_y_fiir_fus_wei1_intp;
static u32 mdns_y_fiir_fus_wei2_intp;
static u32 mdns_y_fiir_fus_wei3_intp;
static u32 mdns_y_fiir_fus_wei4_intp;
static u32 mdns_y_fiir_fus_wei5_intp;
static u32 mdns_y_fiir_fus_wei6_intp;
static u32 mdns_y_fiir_fus_wei7_intp;
static u32 mdns_y_fiir_fus_wei8_intp;

/* --- Y-channel contrast parameters --- */
static u32 mdns_y_con_thres_intp;
static u32 mdns_y_con_stren_intp;

/* --- C-channel SAD/STA parameters --- */
static u32 mdns_c_sad_win_opt_intp;
static u32 mdns_c_sad_ave_thres_intp;
static u32 mdns_c_sad_ave_slope_intp;
static u32 mdns_c_sad_dtb_thres_intp;
static u32 mdns_c_sad_ass_thres_intp;

/* --- C-channel ref_wei parameters --- */
static u32 mdns_c_ref_wei_mv_intp;
static u32 mdns_c_ref_wei_fake_intp;
static u32 mdns_c_ref_wei_f_max_intp;
static u32 mdns_c_ref_wei_f_min_intp;
static u32 mdns_c_ref_wei_b_max_intp;
static u32 mdns_c_ref_wei_b_min_intp;
static u32 mdns_c_ref_wei_r_max_intp;
static u32 mdns_c_ref_wei_r_min_intp;
static u32 mdns_c_ref_wei_increase_intp;

/* --- C-channel thr_adj_seg parameters --- */
static u32 mdns_c_edge_thr_adj_seg_intp;
static u32 mdns_c_luma_thr_adj_seg_intp;
static u32 mdns_c_dtb_thr_adj_seg_intp;
static u32 mdns_c_ass_thr_adj_seg_intp;

/* --- C-channel corner/edge/luma/dtb/ass thr_adj_value parameters --- */
static u32 mdns_c_corner_thr_adj_value_intp;
static u32 mdns_c_edge_thr_adj_value0_intp;
static u32 mdns_c_edge_thr_adj_value1_intp;
static u32 mdns_c_edge_thr_adj_value2_intp;
static u32 mdns_c_edge_thr_adj_value3_intp;
static u32 mdns_c_edge_thr_adj_value4_intp;
static u32 mdns_c_edge_thr_adj_value5_intp;
static u32 mdns_c_luma_thr_adj_value0_intp;
static u32 mdns_c_luma_thr_adj_value1_intp;
static u32 mdns_c_luma_thr_adj_value2_intp;
static u32 mdns_c_luma_thr_adj_value3_intp;
static u32 mdns_c_luma_thr_adj_value4_intp;
static u32 mdns_c_luma_thr_adj_value5_intp;
static u32 mdns_c_dtb_thr_adj_value0_intp;
static u32 mdns_c_dtb_thr_adj_value1_intp;
static u32 mdns_c_dtb_thr_adj_value2_intp;
static u32 mdns_c_dtb_thr_adj_value3_intp;
static u32 mdns_c_dtb_thr_adj_value4_intp;
static u32 mdns_c_dtb_thr_adj_value5_intp;
static u32 mdns_c_ass_thr_adj_value0_intp;
static u32 mdns_c_ass_thr_adj_value1_intp;
static u32 mdns_c_ass_thr_adj_value2_intp;
static u32 mdns_c_ass_thr_adj_value3_intp;
static u32 mdns_c_ass_thr_adj_value4_intp;
static u32 mdns_c_ass_thr_adj_value5_intp;

/* --- C-channel wei_adj_seg parameters --- */
static u32 mdns_c_edge_wei_adj_seg_intp;
static u32 mdns_c_luma_wei_adj_seg_intp;
static u32 mdns_c_dtb_wei_adj_seg_intp;
static u32 mdns_c_ass_wei_adj_seg_intp;
static u32 mdns_c_sad_wei_adj_seg_intp;

/* --- C-channel corner/edge/luma/dtb/ass/sad wei_adj_value parameters --- */
static u32 mdns_c_corner_wei_adj_value_intp;
static u32 mdns_c_edge_wei_adj_value0_intp;
static u32 mdns_c_edge_wei_adj_value1_intp;
static u32 mdns_c_edge_wei_adj_value2_intp;
static u32 mdns_c_edge_wei_adj_value3_intp;
static u32 mdns_c_edge_wei_adj_value4_intp;
static u32 mdns_c_edge_wei_adj_value5_intp;
static u32 mdns_c_luma_wei_adj_value0_intp;
static u32 mdns_c_luma_wei_adj_value1_intp;
static u32 mdns_c_luma_wei_adj_value2_intp;
static u32 mdns_c_luma_wei_adj_value3_intp;
static u32 mdns_c_luma_wei_adj_value4_intp;
static u32 mdns_c_luma_wei_adj_value5_intp;
static u32 mdns_c_dtb_wei_adj_value0_intp;
static u32 mdns_c_dtb_wei_adj_value1_intp;
static u32 mdns_c_dtb_wei_adj_value2_intp;
static u32 mdns_c_dtb_wei_adj_value3_intp;
static u32 mdns_c_dtb_wei_adj_value4_intp;
static u32 mdns_c_dtb_wei_adj_value5_intp;
static u32 mdns_c_ass_wei_adj_value0_intp;
static u32 mdns_c_ass_wei_adj_value1_intp;
static u32 mdns_c_ass_wei_adj_value2_intp;
static u32 mdns_c_ass_wei_adj_value3_intp;
static u32 mdns_c_ass_wei_adj_value4_intp;
static u32 mdns_c_ass_wei_adj_value5_intp;
static u32 mdns_c_sad_wei_adj_value0_intp;
static u32 mdns_c_sad_wei_adj_value1_intp;
static u32 mdns_c_sad_wei_adj_value2_intp;
static u32 mdns_c_sad_wei_adj_value3_intp;
static u32 mdns_c_sad_wei_adj_value4_intp;
static u32 mdns_c_sad_wei_adj_value5_intp;

/* --- C-channel median parameters --- */
static u32 mdns_c_median_smj_thres_intp;
static u32 mdns_c_median_edg_thres_intp;
static u32 mdns_c_median_cur_lmt_op_en_intp;
static u32 mdns_c_median_cur_lmt_wei_intp;
static u32 mdns_c_median_cur_ss_wei_intp;
static u32 mdns_c_median_cur_se_wei_intp;
static u32 mdns_c_median_cur_ms_wei_intp;
static u32 mdns_c_median_cur_me_wei_intp;
static u32 mdns_c_median_ref_lmt_op_en_intp;
static u32 mdns_c_median_ref_lmt_wei_intp;
static u32 mdns_c_median_ref_ss_wei_intp;
static u32 mdns_c_median_ref_se_wei_intp;
static u32 mdns_c_median_ref_ms_wei_intp;
static u32 mdns_c_median_ref_me_wei_intp;

/* --- C-channel bgm parameters --- */
static u32 mdns_c_bgm_win_opt_intp;
static u32 mdns_c_bgm_cur_src_intp;
static u32 mdns_c_bgm_ref_src_intp;
static u32 mdns_c_bgm_false_thres_intp;
static u32 mdns_c_bgm_false_step_intp;

/* --- C-channel piir parameters --- */
static u32 mdns_c_piir_edge_thres0_intp;
static u32 mdns_c_piir_edge_thres1_intp;
static u32 mdns_c_piir_edge_thres2_intp;
static u32 mdns_c_piir_edge_wei0_intp;
static u32 mdns_c_piir_edge_wei1_intp;
static u32 mdns_c_piir_edge_wei2_intp;
static u32 mdns_c_piir_edge_wei3_intp;
static u32 mdns_c_piir_cur_fs_wei_intp;
static u32 mdns_c_piir_ref_fs_wei_intp;

/* --- C-channel fspa cur parameters --- */
static u32 mdns_c_fspa_cur_fus_seg_intp;
static u32 mdns_c_fspa_cur_fus_wei_0_intp;
static u32 mdns_c_fspa_cur_fus_wei_16_intp;
static u32 mdns_c_fspa_cur_fus_wei_32_intp;
static u32 mdns_c_fspa_cur_fus_wei_48_intp;
static u32 mdns_c_fspa_cur_fus_wei_64_intp;
static u32 mdns_c_fspa_cur_fus_wei_80_intp;
static u32 mdns_c_fspa_cur_fus_wei_96_intp;
static u32 mdns_c_fspa_cur_fus_wei_112_intp;
static u32 mdns_c_fspa_cur_fus_wei_128_intp;
static u32 mdns_c_fspa_cur_fus_wei_144_intp;
static u32 mdns_c_fspa_cur_fus_wei_160_intp;
static u32 mdns_c_fspa_cur_fus_wei_176_intp;
static u32 mdns_c_fspa_cur_fus_wei_192_intp;
static u32 mdns_c_fspa_cur_fus_wei_208_intp;
static u32 mdns_c_fspa_cur_fus_wei_224_intp;
static u32 mdns_c_fspa_cur_fus_wei_240_intp;

/* --- C-channel fspa ref parameters --- */
static u32 mdns_c_fspa_ref_fus_seg_intp;
static u32 mdns_c_fspa_ref_fus_wei_0_intp;
static u32 mdns_c_fspa_ref_fus_wei_16_intp;
static u32 mdns_c_fspa_ref_fus_wei_32_intp;
static u32 mdns_c_fspa_ref_fus_wei_48_intp;
static u32 mdns_c_fspa_ref_fus_wei_64_intp;
static u32 mdns_c_fspa_ref_fus_wei_80_intp;
static u32 mdns_c_fspa_ref_fus_wei_96_intp;
static u32 mdns_c_fspa_ref_fus_wei_112_intp;
static u32 mdns_c_fspa_ref_fus_wei_128_intp;
static u32 mdns_c_fspa_ref_fus_wei_144_intp;
static u32 mdns_c_fspa_ref_fus_wei_160_intp;
static u32 mdns_c_fspa_ref_fus_wei_176_intp;
static u32 mdns_c_fspa_ref_fus_wei_192_intp;
static u32 mdns_c_fspa_ref_fus_wei_208_intp;
static u32 mdns_c_fspa_ref_fus_wei_224_intp;
static u32 mdns_c_fspa_ref_fus_wei_240_intp;

/* --- C-channel fiir parameters --- */
static u32 mdns_c_fiir_edge_thres0_intp;
static u32 mdns_c_fiir_edge_thres1_intp;
static u32 mdns_c_fiir_edge_thres2_intp;
static u32 mdns_c_fiir_edge_wei0_intp;
static u32 mdns_c_fiir_edge_wei1_intp;
static u32 mdns_c_fiir_edge_wei2_intp;
static u32 mdns_c_fiir_edge_wei3_intp;
static u32 mdns_c_fiir_fus_seg_intp;
static u32 mdns_c_fiir_fus_wei0_intp;
static u32 mdns_c_fiir_fus_wei1_intp;
static u32 mdns_c_fiir_fus_wei2_intp;
static u32 mdns_c_fiir_fus_wei3_intp;
static u32 mdns_c_fiir_fus_wei4_intp;
static u32 mdns_c_fiir_fus_wei5_intp;
static u32 mdns_c_fiir_fus_wei6_intp;
static u32 mdns_c_fiir_fus_wei7_intp;
static u32 mdns_c_fiir_fus_wei8_intp;

/* --- C-channel false color parameters --- */
static u32 mdns_c_false_smj_thres_intp;
static u32 mdns_c_false_edg_thres0_intp;
static u32 mdns_c_false_edg_thres1_intp_scalar; /* NOTE: _scalar suffix to avoid collision with existing array */
static u32 mdns_c_false_edg_thres2_intp;
static u32 mdns_c_false_thres_s0_intp;
static u32 mdns_c_false_thres_s1_intp;
static u32 mdns_c_false_thres_s2_intp;
static u32 mdns_c_false_thres_s3_intp;
static u32 mdns_c_false_step_s0_intp;
static u32 mdns_c_false_step_s1_intp;
static u32 mdns_c_false_step_s2_intp;
static u32 mdns_c_false_step_s3_intp;
static u32 mdns_c_false_thres_m0_intp;
static u32 mdns_c_false_thres_m1_intp;
static u32 mdns_c_false_thres_m2_intp;
static u32 mdns_c_false_thres_m3_intp;
static u32 mdns_c_false_step_m0_intp;
static u32 mdns_c_false_step_m1_intp;
static u32 mdns_c_false_step_m2_intp;
static u32 mdns_c_false_step_m3_intp;

/* --- C-channel saturation parameters --- */
static u32 mdns_c_sat_lmt_thres_intp;
static u32 mdns_c_sat_lmt_stren_intp;
static u32 mdns_c_sat_nml_stren_intp;


/* ====================================================================
 * SECTION A2: Missing _now pointer declarations
 *
 * PLACEMENT: After existing _now pointers (around line 1996).
 * These are Y-channel _now pointers referenced by the OEM HLIL
 * that are not yet declared in the source.
 * ====================================================================
 */

static uint32_t *mdns_y_sta_motion_thres_array_now = NULL;
static uint32_t *mdns_y_ref_wei_b_max_array_now = NULL;
static uint32_t *mdns_y_pspa_cur_median_win_opt_array_now = NULL;
static uint32_t *mdns_y_pspa_cur_bi_thres_array_now = NULL;
static uint32_t *mdns_y_pspa_cur_bi_wei0_array_now = NULL;
static uint32_t *mdns_y_pspa_ref_median_win_opt_array_now = NULL;
static uint32_t *mdns_y_pspa_ref_bi_thres_array_now = NULL;
static uint32_t *mdns_y_pspa_ref_bi_wei0_array_now = NULL;
static uint32_t *mdns_y_piir_cur_fs_wei_array_now = NULL;
static uint32_t *mdns_y_piir_ref_fs_wei_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_144_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_160_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_176_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_192_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_208_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_224_array_now = NULL;
static uint32_t *mdns_y_fspa_cur_fus_wei_240_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_144_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_160_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_176_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_192_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_208_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_224_array_now = NULL;
static uint32_t *mdns_y_fspa_ref_fus_wei_240_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei0_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei1_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei2_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei3_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei4_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei5_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei6_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei7_array_now = NULL;
static uint32_t *mdns_y_fiir_fus_wei8_array_now = NULL;

/* C-channel missing _now pointers */
static uint32_t *mdns_c_fspa_cur_fus_wei_224_array_now = NULL;
static uint32_t *mdns_c_fspa_cur_fus_wei_240_array_now = NULL;
static uint32_t *mdns_c_fspa_ref_fus_wei_224_array_now = NULL;
static uint32_t *mdns_c_fspa_ref_fus_wei_240_array_now = NULL;


/* ====================================================================
 * SECTION B: Full tisp_mdns_intp() function body
 *
 * PLACEMENT: Replace the existing stub at ~line 25520.
 *
 * OEM address: 0x349e0 in tx-isp-t31.ko
 * Translated from HLIL lines 29376-29961.
 *
 * For arrays with & prefix in HLIL: use array directly (always valid).
 * For _now pointers (no & prefix): NULL-check, return 0 if NULL.
 * ====================================================================
 */

#define INTP(var, arr)  var = tisp_simple_intp(hi, lo, arr)
#define INTP_NULL(var, ptr)  var = (ptr) ? tisp_simple_intp(hi, lo, ptr) : 0

static void tisp_mdns_intp(uint32_t interp_key)
{
    int hi = interp_key >> 16;
    int lo = interp_key & 0xffff;

    data_9a9d0 = interp_key;

    /* ---- Y-channel 3D: SAD/STA ---- */
    INTP(mdns_y_sad_win_opt_intp, mdns_y_sad_win_opt_array);
    INTP_NULL(mdns_y_sad_ave_thres_intp, mdns_y_sad_ave_thres_array_now);
    INTP(mdns_y_sad_ave_slope_intp, mdns_y_sad_ave_slope_array);
    INTP(mdns_y_sad_dtb_thres_intp, mdns_y_sad_dtb_thres_array);
    INTP_NULL(mdns_y_sad_ass_thres_intp, mdns_y_sad_ass_thres_array_now);
    INTP(mdns_y_sta_blk_size_intp, mdns_y_sta_blk_size_array);
    INTP(mdns_y_sta_win_opt_intp, mdns_y_sta_win_opt_array);
    INTP_NULL(mdns_y_sta_ave_thres_intp, mdns_y_sta_ave_thres_array_now);
    INTP(mdns_y_sta_dtb_thres_intp, mdns_y_sta_dtb_thres_array);
    INTP_NULL(mdns_y_sta_ass_thres_intp, mdns_y_sta_ass_thres_array_now);
    INTP_NULL(mdns_y_sta_motion_thres_intp, mdns_y_sta_motion_thres_array_now);

    /* ---- Y-channel 3D: ref_wei ---- */
    INTP(mdns_y_ref_wei_mv_intp, mdns_y_ref_wei_mv_array);
    INTP(mdns_y_ref_wei_fake_intp, mdns_y_ref_wei_fake_array);
    INTP(mdns_y_ref_wei_sta_fs_opt_intp, mdns_y_ref_wei_sta_fs_opt_array);
    INTP(mdns_y_ref_wei_psn_fs_opt_intp, mdns_y_ref_wei_psn_fs_opt_array);
    INTP(mdns_y_ref_wei_f_max_intp, mdns_y_ref_wei_f_max_array);
    INTP(mdns_y_ref_wei_f_min_intp, mdns_y_ref_wei_f_min_array);
    INTP_NULL(mdns_y_ref_wei_b_max_intp, mdns_y_ref_wei_b_max_array_now);
    INTP_NULL(mdns_y_ref_wei_b_min_intp, mdns_y_ref_wei_b_min_array_now);
    INTP(mdns_y_ref_wei_r_max_intp, mdns_y_ref_wei_r_max_array);
    INTP(mdns_y_ref_wei_r_min_intp, mdns_y_ref_wei_r_min_array);
    INTP(mdns_y_ref_wei_increase_intp, mdns_y_ref_wei_increase_array);

    /* ---- Y-channel 3D: corner ---- */
    INTP(mdns_y_corner_length_t_intp, mdns_y_corner_length_t_array);
    INTP(mdns_y_corner_length_b_intp, mdns_y_corner_length_b_array);
    INTP(mdns_y_corner_length_l_intp, mdns_y_corner_length_l_array);
    INTP(mdns_y_corner_length_r_intp, mdns_y_corner_length_r_array);

    /* ---- Y-channel 3D: edge ---- */
    INTP(mdns_y_edge_win_opt_intp, mdns_y_edge_win_opt_array);
    INTP(mdns_y_edge_div_opt_intp, mdns_y_edge_div_opt_array);
    INTP(mdns_y_edge_type_opt_intp, mdns_y_edge_type_opt_array);

    /* ---- Y-channel 3D: luma ---- */
    INTP(mdns_y_luma_win_opt_intp, mdns_y_luma_win_opt_array);

    /* ---- Y-channel 3D: dtb ---- */
    INTP(mdns_y_dtb_div_opt_intp, mdns_y_dtb_div_opt_array);
    INTP(mdns_y_dtb_squ_en_intp, mdns_y_dtb_squ_en_array);
    INTP(mdns_y_dtb_squ_div_opt_intp, mdns_y_dtb_squ_div_opt_array);

    /* ---- Y-channel 3D: ass ---- */
    INTP(mdns_y_ass_win_opt_intp, mdns_y_ass_win_opt_array);
    INTP(mdns_y_ass_div_opt_intp, mdns_y_ass_div_opt_array);

    /* ---- Y-channel 3D: hist ---- */
    INTP(mdns_y_hist_sad_en_intp, mdns_y_hist_sad_en_array);
    INTP(mdns_y_hist_sta_en_intp, mdns_y_hist_sta_en_array);
    INTP(mdns_y_hist_num_thres_intp, mdns_y_hist_num_thres_array);
    INTP(mdns_y_hist_cmp_thres0_intp, mdns_y_hist_cmp_thres0_array);
    INTP(mdns_y_hist_cmp_thres1_intp, mdns_y_hist_cmp_thres1_array);
    INTP(mdns_y_hist_cmp_thres2_intp, mdns_y_hist_cmp_thres2_array);
    INTP(mdns_y_hist_cmp_thres3_intp, mdns_y_hist_cmp_thres3_array);
    INTP(mdns_y_hist_thres0_intp, mdns_y_hist_thres0_array);
    INTP(mdns_y_hist_thres1_intp, mdns_y_hist_thres1_array);
    INTP(mdns_y_hist_thres2_intp, mdns_y_hist_thres2_array);
    INTP(mdns_y_hist_thres3_intp, mdns_y_hist_thres3_array);

    /* ---- Y-channel 3D: thr_adj_seg ---- */
    INTP(mdns_y_edge_thr_adj_seg_intp, mdns_y_edge_thr_adj_seg_array);
    INTP(mdns_y_luma_thr_adj_seg_intp, mdns_y_luma_thr_adj_seg_array);
    INTP(mdns_y_dtb_thr_adj_seg_intp, mdns_y_dtb_thr_adj_seg_array);
    INTP(mdns_y_ass_thr_adj_seg_intp, mdns_y_ass_thr_adj_seg_array);

    /* ---- Y-channel 3D: thr_adj_value ---- */
    INTP(mdns_y_corner_thr_adj_value_intp, mdns_y_corner_thr_adj_value_array);
    INTP(mdns_y_edge_thr_adj_value0_intp, mdns_y_edge_thr_adj_value0_array);
    INTP(mdns_y_edge_thr_adj_value1_intp, mdns_y_edge_thr_adj_value1_array);
    INTP(mdns_y_edge_thr_adj_value2_intp, mdns_y_edge_thr_adj_value2_array);
    INTP(mdns_y_edge_thr_adj_value3_intp, mdns_y_edge_thr_adj_value3_array);
    INTP(mdns_y_edge_thr_adj_value4_intp, mdns_y_edge_thr_adj_value4_array);
    INTP(mdns_y_edge_thr_adj_value5_intp, mdns_y_edge_thr_adj_value5_array);
    INTP(mdns_y_luma_thr_adj_value0_intp, mdns_y_luma_thr_adj_value0_array);
    INTP(mdns_y_luma_thr_adj_value1_intp, mdns_y_luma_thr_adj_value1_array);
    INTP(mdns_y_luma_thr_adj_value2_intp, mdns_y_luma_thr_adj_value2_array);
    INTP(mdns_y_luma_thr_adj_value3_intp, mdns_y_luma_thr_adj_value3_array);
    INTP(mdns_y_luma_thr_adj_value4_intp, mdns_y_luma_thr_adj_value4_array);
    INTP(mdns_y_luma_thr_adj_value5_intp, mdns_y_luma_thr_adj_value5_array);
    INTP(mdns_y_dtb_thr_adj_value0_intp, mdns_y_dtb_thr_adj_value0_array);
    INTP(mdns_y_dtb_thr_adj_value1_intp, mdns_y_dtb_thr_adj_value1_array);
    INTP(mdns_y_dtb_thr_adj_value2_intp, mdns_y_dtb_thr_adj_value2_array);
    INTP(mdns_y_dtb_thr_adj_value3_intp, mdns_y_dtb_thr_adj_value3_array);
    INTP(mdns_y_dtb_thr_adj_value4_intp, mdns_y_dtb_thr_adj_value4_array);
    INTP(mdns_y_dtb_thr_adj_value5_intp, mdns_y_dtb_thr_adj_value5_array);
    INTP(mdns_y_ass_thr_adj_value0_intp, mdns_y_ass_thr_adj_value0_array);
    INTP(mdns_y_ass_thr_adj_value1_intp, mdns_y_ass_thr_adj_value1_array);
    INTP(mdns_y_ass_thr_adj_value2_intp, mdns_y_ass_thr_adj_value2_array);
    INTP(mdns_y_ass_thr_adj_value3_intp, mdns_y_ass_thr_adj_value3_array);
    INTP(mdns_y_ass_thr_adj_value4_intp, mdns_y_ass_thr_adj_value4_array);
    INTP(mdns_y_ass_thr_adj_value5_intp, mdns_y_ass_thr_adj_value5_array);

    /* ---- Y-channel 3D: wei_adj_seg ---- */
    INTP(mdns_y_edge_wei_adj_seg_intp, mdns_y_edge_wei_adj_seg_array);
    INTP(mdns_y_luma_wei_adj_seg_intp, mdns_y_luma_wei_adj_seg_array);
    INTP(mdns_y_dtb_wei_adj_seg_intp, mdns_y_dtb_wei_adj_seg_array);
    INTP(mdns_y_ass_wei_adj_seg_intp, mdns_y_ass_wei_adj_seg_array);
    INTP(mdns_y_sad_wei_adj_seg_intp, mdns_y_sad_wei_adj_seg_array);

    /* ---- Y-channel 3D: wei_adj_value ---- */
    INTP(mdns_y_corner_wei_adj_value_intp, mdns_y_corner_wei_adj_value_array);
    INTP(mdns_y_edge_wei_adj_value0_intp, mdns_y_edge_wei_adj_value0_array);
    INTP(mdns_y_edge_wei_adj_value1_intp, mdns_y_edge_wei_adj_value1_array);
    INTP(mdns_y_edge_wei_adj_value2_intp, mdns_y_edge_wei_adj_value2_array);
    INTP(mdns_y_edge_wei_adj_value3_intp, mdns_y_edge_wei_adj_value3_array);
    INTP(mdns_y_edge_wei_adj_value4_intp, mdns_y_edge_wei_adj_value4_array);
    INTP(mdns_y_edge_wei_adj_value5_intp, mdns_y_edge_wei_adj_value5_array);
    INTP(mdns_y_luma_wei_adj_value0_intp, mdns_y_luma_wei_adj_value0_array);
    INTP(mdns_y_luma_wei_adj_value1_intp, mdns_y_luma_wei_adj_value1_array);
    INTP(mdns_y_luma_wei_adj_value2_intp, mdns_y_luma_wei_adj_value2_array);
    INTP(mdns_y_luma_wei_adj_value3_intp, mdns_y_luma_wei_adj_value3_array);
    INTP(mdns_y_luma_wei_adj_value4_intp, mdns_y_luma_wei_adj_value4_array);
    INTP(mdns_y_luma_wei_adj_value5_intp, mdns_y_luma_wei_adj_value5_array);
    INTP(mdns_y_dtb_wei_adj_value0_intp, mdns_y_dtb_wei_adj_value0_array);
    INTP(mdns_y_dtb_wei_adj_value1_intp, mdns_y_dtb_wei_adj_value1_array);
    INTP(mdns_y_dtb_wei_adj_value2_intp, mdns_y_dtb_wei_adj_value2_array);
    INTP(mdns_y_dtb_wei_adj_value3_intp, mdns_y_dtb_wei_adj_value3_array);
    INTP(mdns_y_dtb_wei_adj_value4_intp, mdns_y_dtb_wei_adj_value4_array);
    INTP(mdns_y_dtb_wei_adj_value5_intp, mdns_y_dtb_wei_adj_value5_array);
    INTP(mdns_y_ass_wei_adj_value0_intp, mdns_y_ass_wei_adj_value0_array);
    INTP(mdns_y_ass_wei_adj_value1_intp_scalar, mdns_y_ass_wei_adj_value1_array);
    INTP(mdns_y_ass_wei_adj_value2_intp, mdns_y_ass_wei_adj_value2_array);
    INTP(mdns_y_ass_wei_adj_value3_intp, mdns_y_ass_wei_adj_value3_array);
    INTP(mdns_y_ass_wei_adj_value4_intp, mdns_y_ass_wei_adj_value4_array);
    INTP(mdns_y_ass_wei_adj_value5_intp, mdns_y_ass_wei_adj_value5_array);
    INTP(mdns_y_sad_wei_adj_value0_intp, mdns_y_sad_wei_adj_value0_array);
    INTP(mdns_y_sad_wei_adj_value1_intp, mdns_y_sad_wei_adj_value1_array);
    INTP(mdns_y_sad_wei_adj_value2_intp, mdns_y_sad_wei_adj_value2_array);
    INTP(mdns_y_sad_wei_adj_value3_intp, mdns_y_sad_wei_adj_value3_array);
    INTP(mdns_y_sad_wei_adj_value4_intp, mdns_y_sad_wei_adj_value4_array);
    INTP(mdns_y_sad_wei_adj_value5_intp, mdns_y_sad_wei_adj_value5_array);

    /* ---- Y-channel 2D: pspa cur ---- */
    INTP_NULL(mdns_y_pspa_cur_median_win_opt_intp, mdns_y_pspa_cur_median_win_opt_array_now);
    INTP_NULL(mdns_y_pspa_cur_bi_thres_intp, mdns_y_pspa_cur_bi_thres_array_now);
    INTP(mdns_y_pspa_cur_bi_wei_seg_intp, mdns_y_pspa_cur_bi_wei_seg_array);
    INTP_NULL(mdns_y_pspa_cur_bi_wei0_intp, mdns_y_pspa_cur_bi_wei0_array_now);
    INTP(mdns_y_pspa_cur_bi_wei1_intp, mdns_y_pspa_cur_bi_wei1_array);
    INTP(mdns_y_pspa_cur_bi_wei2_intp, mdns_y_pspa_cur_bi_wei2_array);
    INTP(mdns_y_pspa_cur_bi_wei3_intp, mdns_y_pspa_cur_bi_wei3_array);
    INTP(mdns_y_pspa_cur_bi_wei4_intp, mdns_y_pspa_cur_bi_wei4_array);
    INTP(mdns_y_pspa_cur_lmt_op_en_intp, mdns_y_pspa_cur_lmt_op_en_array);
    INTP(mdns_y_pspa_cur_lmt_wei_intp, mdns_y_pspa_cur_lmt_wei_array);

    /* ---- Y-channel 2D: pspa ref ---- */
    INTP_NULL(mdns_y_pspa_ref_median_win_opt_intp, mdns_y_pspa_ref_median_win_opt_array_now);
    INTP_NULL(mdns_y_pspa_ref_bi_thres_intp, mdns_y_pspa_ref_bi_thres_array_now);
    INTP(mdns_y_pspa_ref_bi_wei_seg_intp, mdns_y_pspa_ref_bi_wei_seg_array);
    INTP_NULL(mdns_y_pspa_ref_bi_wei0_intp, mdns_y_pspa_ref_bi_wei0_array_now);
    INTP(mdns_y_pspa_ref_bi_wei1_intp, mdns_y_pspa_ref_bi_wei1_array);
    INTP(mdns_y_pspa_ref_bi_wei2_intp, mdns_y_pspa_ref_bi_wei2_array);
    INTP(mdns_y_pspa_ref_bi_wei3_intp, mdns_y_pspa_ref_bi_wei3_array);
    INTP(mdns_y_pspa_ref_bi_wei4_intp, mdns_y_pspa_ref_bi_wei4_array);
    INTP(mdns_y_pspa_ref_lmt_op_en_intp, mdns_y_pspa_ref_lmt_op_en_array);
    INTP(mdns_y_pspa_ref_lmt_wei_intp, mdns_y_pspa_ref_lmt_wei_array);

    /* ---- Y-channel 2D: piir ---- */
    INTP(mdns_y_piir_edge_thres0_intp, mdns_y_piir_edge_thres0_array);
    INTP(mdns_y_piir_edge_thres1_intp, mdns_y_piir_edge_thres1_array);
    INTP(mdns_y_piir_edge_thres2_intp, mdns_y_piir_edge_thres2_array);
    INTP(mdns_y_piir_edge_wei0_intp, mdns_y_piir_edge_wei0_array);
    INTP(mdns_y_piir_edge_wei1_intp, mdns_y_piir_edge_wei1_array);
    INTP(mdns_y_piir_edge_wei2_intp, mdns_y_piir_edge_wei2_array);
    INTP(mdns_y_piir_edge_wei3_intp, mdns_y_piir_edge_wei3_array);
    INTP_NULL(mdns_y_piir_cur_fs_wei_intp, mdns_y_piir_cur_fs_wei_array_now);
    INTP_NULL(mdns_y_piir_ref_fs_wei_intp, mdns_y_piir_ref_fs_wei_array_now);

    /* ---- Y-channel 2D: pspa fnl ---- */
    INTP(mdns_y_pspa_fnl_fus_thres_intp, mdns_y_pspa_fnl_fus_thres_array);
    INTP(mdns_y_pspa_fnl_fus_swei_intp, mdns_y_pspa_fnl_fus_swei_array);
    INTP(mdns_y_pspa_fnl_fus_dwei_intp, mdns_y_pspa_fnl_fus_dwei_array);

    /* ---- Y-channel 2D: fspa cur ---- */
    INTP(mdns_y_fspa_cur_fus_seg_intp, mdns_y_fspa_cur_fus_seg_array);
    INTP(mdns_y_fspa_cur_fus_wei_0_intp, mdns_y_fspa_cur_fus_wei_0_array);
    INTP(mdns_y_fspa_cur_fus_wei_16_intp, mdns_y_fspa_cur_fus_wei_16_array);
    INTP(mdns_y_fspa_cur_fus_wei_32_intp, mdns_y_fspa_cur_fus_wei_32_array);
    INTP(mdns_y_fspa_cur_fus_wei_48_intp, mdns_y_fspa_cur_fus_wei_48_array);
    INTP(mdns_y_fspa_cur_fus_wei_64_intp, mdns_y_fspa_cur_fus_wei_64_array);
    INTP(mdns_y_fspa_cur_fus_wei_80_intp, mdns_y_fspa_cur_fus_wei_80_array);
    INTP(mdns_y_fspa_cur_fus_wei_96_intp, mdns_y_fspa_cur_fus_wei_96_array);
    INTP(mdns_y_fspa_cur_fus_wei_112_intp, mdns_y_fspa_cur_fus_wei_112_array);
    INTP(mdns_y_fspa_cur_fus_wei_128_intp, mdns_y_fspa_cur_fus_wei_128_array);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_144_intp, mdns_y_fspa_cur_fus_wei_144_array_now);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_160_intp, mdns_y_fspa_cur_fus_wei_160_array_now);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_176_intp, mdns_y_fspa_cur_fus_wei_176_array_now);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_192_intp, mdns_y_fspa_cur_fus_wei_192_array_now);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_208_intp, mdns_y_fspa_cur_fus_wei_208_array_now);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_224_intp, mdns_y_fspa_cur_fus_wei_224_array_now);
    INTP_NULL(mdns_y_fspa_cur_fus_wei_240_intp, mdns_y_fspa_cur_fus_wei_240_array_now);

    /* ---- Y-channel 2D: fspa ref ---- */
    INTP(mdns_y_fspa_ref_fus_seg_intp, mdns_y_fspa_ref_fus_seg_array);
    INTP(mdns_y_fspa_ref_fus_wei_0_intp, mdns_y_fspa_ref_fus_wei_0_array);
    INTP(mdns_y_fspa_ref_fus_wei_16_intp, mdns_y_fspa_ref_fus_wei_16_array);
    INTP(mdns_y_fspa_ref_fus_wei_32_intp, mdns_y_fspa_ref_fus_wei_32_array);
    INTP(mdns_y_fspa_ref_fus_wei_48_intp, mdns_y_fspa_ref_fus_wei_48_array);
    INTP(mdns_y_fspa_ref_fus_wei_64_intp, mdns_y_fspa_ref_fus_wei_64_array);
    INTP(mdns_y_fspa_ref_fus_wei_80_intp, mdns_y_fspa_ref_fus_wei_80_array);
    INTP(mdns_y_fspa_ref_fus_wei_96_intp, mdns_y_fspa_ref_fus_wei_96_array);
    INTP(mdns_y_fspa_ref_fus_wei_112_intp, mdns_y_fspa_ref_fus_wei_112_array);
    INTP(mdns_y_fspa_ref_fus_wei_128_intp, mdns_y_fspa_ref_fus_wei_128_array);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_144_intp, mdns_y_fspa_ref_fus_wei_144_array_now);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_160_intp, mdns_y_fspa_ref_fus_wei_160_array_now);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_176_intp, mdns_y_fspa_ref_fus_wei_176_array_now);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_192_intp, mdns_y_fspa_ref_fus_wei_192_array_now);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_208_intp, mdns_y_fspa_ref_fus_wei_208_array_now);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_224_intp, mdns_y_fspa_ref_fus_wei_224_array_now);
    INTP_NULL(mdns_y_fspa_ref_fus_wei_240_intp, mdns_y_fspa_ref_fus_wei_240_array_now);

    /* ---- Y-channel 2D: fiir ---- */
    INTP(mdns_y_fiir_edge_thres0_intp, mdns_y_fiir_edge_thres0_array);
    INTP(mdns_y_fiir_edge_thres1_intp, mdns_y_fiir_edge_thres1_array);
    INTP(mdns_y_fiir_edge_thres2_intp, mdns_y_fiir_edge_thres2_array);
    INTP(mdns_y_fiir_edge_wei0_intp, mdns_y_fiir_edge_wei0_array);
    INTP(mdns_y_fiir_edge_wei1_intp, mdns_y_fiir_edge_wei1_array);
    INTP(mdns_y_fiir_edge_wei2_intp, mdns_y_fiir_edge_wei2_array);
    INTP(mdns_y_fiir_edge_wei3_intp, mdns_y_fiir_edge_wei3_array);
    INTP(mdns_y_fiir_fus_seg_intp, mdns_y_fiir_fus_seg_array);
    INTP_NULL(mdns_y_fiir_fus_wei0_intp, mdns_y_fiir_fus_wei0_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei1_intp, mdns_y_fiir_fus_wei1_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei2_intp, mdns_y_fiir_fus_wei2_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei3_intp, mdns_y_fiir_fus_wei3_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei4_intp, mdns_y_fiir_fus_wei4_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei5_intp, mdns_y_fiir_fus_wei5_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei6_intp, mdns_y_fiir_fus_wei6_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei7_intp, mdns_y_fiir_fus_wei7_array_now);
    INTP_NULL(mdns_y_fiir_fus_wei8_intp, mdns_y_fiir_fus_wei8_array_now);

    /* ---- Y-channel contrast ---- */
    INTP(mdns_y_con_thres_intp, mdns_y_con_thres_array);
    INTP(mdns_y_con_stren_intp, mdns_y_con_stren_array);

    /* ================================================================
     * C-channel
     * ================================================================ */

    /* ---- C-channel 3D: SAD ---- */
    INTP(mdns_c_sad_win_opt_intp, mdns_c_sad_win_opt_array);
    INTP_NULL(mdns_c_sad_ave_thres_intp, mdns_c_sad_ave_thres_array_now);
    INTP(mdns_c_sad_ave_slope_intp, mdns_c_sad_ave_slope_array);
    INTP(mdns_c_sad_dtb_thres_intp, mdns_c_sad_dtb_thres_array);
    INTP_NULL(mdns_c_sad_ass_thres_intp, mdns_c_sad_ass_thres_array_now);

    /* ---- C-channel 3D: ref_wei ---- */
    INTP(mdns_c_ref_wei_mv_intp, mdns_c_ref_wei_mv_array);
    INTP(mdns_c_ref_wei_fake_intp, mdns_c_ref_wei_fake_array);
    INTP(mdns_c_ref_wei_f_max_intp, mdns_c_ref_wei_f_max_array);
    INTP(mdns_c_ref_wei_f_min_intp, mdns_c_ref_wei_f_min_array);
    INTP_NULL(mdns_c_ref_wei_b_max_intp, mdns_c_ref_wei_b_max_array_now);
    INTP_NULL(mdns_c_ref_wei_b_min_intp, mdns_c_ref_wei_b_min_array_now);
    INTP(mdns_c_ref_wei_r_max_intp, mdns_c_ref_wei_r_max_array);
    INTP(mdns_c_ref_wei_r_min_intp, mdns_c_ref_wei_r_min_array);
    INTP(mdns_c_ref_wei_increase_intp, mdns_c_ref_wei_increase_array);

    /* ---- C-channel 3D: thr_adj_seg ---- */
    INTP(mdns_c_edge_thr_adj_seg_intp, mdns_c_edge_thr_adj_seg_array);
    INTP(mdns_c_luma_thr_adj_seg_intp, mdns_c_luma_thr_adj_seg_array);
    INTP(mdns_c_dtb_thr_adj_seg_intp, mdns_c_dtb_thr_adj_seg_array);
    INTP(mdns_c_ass_thr_adj_seg_intp, mdns_c_ass_thr_adj_seg_array);

    /* ---- C-channel 3D: thr_adj_value ---- */
    INTP(mdns_c_corner_thr_adj_value_intp, mdns_c_corner_thr_adj_value_array);
    INTP(mdns_c_edge_thr_adj_value0_intp, mdns_c_edge_thr_adj_value0_array);
    INTP(mdns_c_edge_thr_adj_value1_intp, mdns_c_edge_thr_adj_value1_array);
    INTP(mdns_c_edge_thr_adj_value2_intp, mdns_c_edge_thr_adj_value2_array);
    INTP(mdns_c_edge_thr_adj_value3_intp, mdns_c_edge_thr_adj_value3_array);
    INTP(mdns_c_edge_thr_adj_value4_intp, mdns_c_edge_thr_adj_value4_array);
    INTP(mdns_c_edge_thr_adj_value5_intp, mdns_c_edge_thr_adj_value5_array);
    INTP(mdns_c_luma_thr_adj_value0_intp, mdns_c_luma_thr_adj_value0_array);
    INTP(mdns_c_luma_thr_adj_value1_intp, mdns_c_luma_thr_adj_value1_array);
    INTP(mdns_c_luma_thr_adj_value2_intp, mdns_c_luma_thr_adj_value2_array);
    INTP(mdns_c_luma_thr_adj_value3_intp, mdns_c_luma_thr_adj_value3_array);
    INTP(mdns_c_luma_thr_adj_value4_intp, mdns_c_luma_thr_adj_value4_array);
    INTP(mdns_c_luma_thr_adj_value5_intp, mdns_c_luma_thr_adj_value5_array);
    INTP(mdns_c_dtb_thr_adj_value0_intp, mdns_c_dtb_thr_adj_value0_array);
    INTP(mdns_c_dtb_thr_adj_value1_intp, mdns_c_dtb_thr_adj_value1_array);
    INTP(mdns_c_dtb_thr_adj_value2_intp, mdns_c_dtb_thr_adj_value2_array);
    INTP(mdns_c_dtb_thr_adj_value3_intp, mdns_c_dtb_thr_adj_value3_array);
    INTP(mdns_c_dtb_thr_adj_value4_intp, mdns_c_dtb_thr_adj_value4_array);
    INTP(mdns_c_dtb_thr_adj_value5_intp, mdns_c_dtb_thr_adj_value5_array);
    INTP(mdns_c_ass_thr_adj_value0_intp, mdns_c_ass_thr_adj_value0_array);
    INTP(mdns_c_ass_thr_adj_value1_intp, mdns_c_ass_thr_adj_value1_array);
    INTP(mdns_c_ass_thr_adj_value2_intp, mdns_c_ass_thr_adj_value2_array);
    INTP(mdns_c_ass_thr_adj_value3_intp, mdns_c_ass_thr_adj_value3_array);
    INTP(mdns_c_ass_thr_adj_value4_intp, mdns_c_ass_thr_adj_value4_array);
    INTP(mdns_c_ass_thr_adj_value5_intp, mdns_c_ass_thr_adj_value5_array);

    /* ---- C-channel 3D: wei_adj_seg ---- */
    INTP(mdns_c_edge_wei_adj_seg_intp, mdns_c_edge_wei_adj_seg_array);
    INTP(mdns_c_luma_wei_adj_seg_intp, mdns_c_luma_wei_adj_seg_array);
    INTP(mdns_c_dtb_wei_adj_seg_intp, mdns_c_dtb_wei_adj_seg_array);
    INTP(mdns_c_ass_wei_adj_seg_intp, mdns_c_ass_wei_adj_seg_array);
    INTP(mdns_c_sad_wei_adj_seg_intp, mdns_c_sad_wei_adj_seg_array);

    /* ---- C-channel 3D: wei_adj_value ---- */
    INTP(mdns_c_corner_wei_adj_value_intp, mdns_c_corner_wei_adj_value_array);
    INTP(mdns_c_edge_wei_adj_value0_intp, mdns_c_edge_wei_adj_value0_array);
    INTP(mdns_c_edge_wei_adj_value1_intp, mdns_c_edge_wei_adj_value1_array);
    INTP(mdns_c_edge_wei_adj_value2_intp, mdns_c_edge_wei_adj_value2_array);
    INTP(mdns_c_edge_wei_adj_value3_intp, mdns_c_edge_wei_adj_value3_array);
    INTP(mdns_c_edge_wei_adj_value4_intp, mdns_c_edge_wei_adj_value4_array);
    INTP(mdns_c_edge_wei_adj_value5_intp, mdns_c_edge_wei_adj_value5_array);
    INTP(mdns_c_luma_wei_adj_value0_intp, mdns_c_luma_wei_adj_value0_array);
    INTP(mdns_c_luma_wei_adj_value1_intp, mdns_c_luma_wei_adj_value1_array);
    INTP(mdns_c_luma_wei_adj_value2_intp, mdns_c_luma_wei_adj_value2_array);
    INTP(mdns_c_luma_wei_adj_value3_intp, mdns_c_luma_wei_adj_value3_array);
    INTP(mdns_c_luma_wei_adj_value4_intp, mdns_c_luma_wei_adj_value4_array);
    INTP(mdns_c_luma_wei_adj_value5_intp, mdns_c_luma_wei_adj_value5_array);
    INTP(mdns_c_dtb_wei_adj_value0_intp, mdns_c_dtb_wei_adj_value0_array);
    INTP(mdns_c_dtb_wei_adj_value1_intp, mdns_c_dtb_wei_adj_value1_array);
    INTP(mdns_c_dtb_wei_adj_value2_intp, mdns_c_dtb_wei_adj_value2_array);
    INTP(mdns_c_dtb_wei_adj_value3_intp, mdns_c_dtb_wei_adj_value3_array);
    INTP(mdns_c_dtb_wei_adj_value4_intp, mdns_c_dtb_wei_adj_value4_array);
    INTP(mdns_c_dtb_wei_adj_value5_intp, mdns_c_dtb_wei_adj_value5_array);
    INTP(mdns_c_ass_wei_adj_value0_intp, mdns_c_ass_wei_adj_value0_array);
    INTP(mdns_c_ass_wei_adj_value1_intp, mdns_c_ass_wei_adj_value1_array);
    INTP(mdns_c_ass_wei_adj_value2_intp, mdns_c_ass_wei_adj_value2_array);
    INTP(mdns_c_ass_wei_adj_value3_intp, mdns_c_ass_wei_adj_value3_array);
    INTP(mdns_c_ass_wei_adj_value4_intp, mdns_c_ass_wei_adj_value4_array);
    INTP(mdns_c_ass_wei_adj_value5_intp, mdns_c_ass_wei_adj_value5_array);
    INTP(mdns_c_sad_wei_adj_value0_intp, mdns_c_sad_wei_adj_value0_array);
    INTP(mdns_c_sad_wei_adj_value1_intp, mdns_c_sad_wei_adj_value1_array);
    INTP(mdns_c_sad_wei_adj_value2_intp, mdns_c_sad_wei_adj_value2_array);
    INTP(mdns_c_sad_wei_adj_value3_intp, mdns_c_sad_wei_adj_value3_array);
    INTP(mdns_c_sad_wei_adj_value4_intp, mdns_c_sad_wei_adj_value4_array);
    INTP(mdns_c_sad_wei_adj_value5_intp, mdns_c_sad_wei_adj_value5_array);

    /* ---- C-channel 2D: median ---- */
    INTP(mdns_c_median_smj_thres_intp, mdns_c_median_smj_thres_array);
    INTP(mdns_c_median_edg_thres_intp, mdns_c_median_edg_thres_array);
    INTP(mdns_c_median_cur_lmt_op_en_intp, mdns_c_median_cur_lmt_op_en_array);
    INTP(mdns_c_median_cur_lmt_wei_intp, mdns_c_median_cur_lmt_wei_array);
    INTP_NULL(mdns_c_median_cur_ss_wei_intp, mdns_c_median_cur_ss_wei_array_now);
    INTP_NULL(mdns_c_median_cur_se_wei_intp, mdns_c_median_cur_se_wei_array_now);
    INTP_NULL(mdns_c_median_cur_ms_wei_intp, mdns_c_median_cur_ms_wei_array_now);
    INTP_NULL(mdns_c_median_cur_me_wei_intp, mdns_c_median_cur_me_wei_array_now);
    INTP(mdns_c_median_ref_lmt_op_en_intp, mdns_c_median_ref_lmt_op_en_array);
    INTP(mdns_c_median_ref_lmt_wei_intp, mdns_c_median_ref_lmt_wei_array);
    INTP_NULL(mdns_c_median_ref_ss_wei_intp, mdns_c_median_ref_ss_wei_array_now);
    INTP_NULL(mdns_c_median_ref_se_wei_intp, mdns_c_median_ref_se_wei_array_now);
    INTP_NULL(mdns_c_median_ref_ms_wei_intp, mdns_c_median_ref_ms_wei_array_now);
    INTP_NULL(mdns_c_median_ref_me_wei_intp, mdns_c_median_ref_me_wei_array_now);

    /* ---- C-channel 2D: bgm ---- */
    INTP(mdns_c_bgm_win_opt_intp, mdns_c_bgm_win_opt_array);
    INTP(mdns_c_bgm_cur_src_intp, mdns_c_bgm_cur_src_array);
    INTP(mdns_c_bgm_ref_src_intp, mdns_c_bgm_ref_src_array);
    INTP(mdns_c_bgm_false_thres_intp, mdns_c_bgm_false_thres_array);
    INTP(mdns_c_bgm_false_step_intp, mdns_c_bgm_false_step_array);

    /* ---- C-channel 2D: piir ---- */
    INTP(mdns_c_piir_edge_thres0_intp, mdns_c_piir_edge_thres0_array);
    INTP(mdns_c_piir_edge_thres1_intp, mdns_c_piir_edge_thres1_array);
    INTP(mdns_c_piir_edge_thres2_intp, mdns_c_piir_edge_thres2_array);
    INTP(mdns_c_piir_edge_wei0_intp, mdns_c_piir_edge_wei0_array);
    INTP(mdns_c_piir_edge_wei1_intp, mdns_c_piir_edge_wei1_array);
    INTP(mdns_c_piir_edge_wei2_intp, mdns_c_piir_edge_wei2_array);
    INTP(mdns_c_piir_edge_wei3_intp, mdns_c_piir_edge_wei3_array);
    INTP_NULL(mdns_c_piir_cur_fs_wei_intp, mdns_c_piir_cur_fs_wei_array_now);
    INTP_NULL(mdns_c_piir_ref_fs_wei_intp, mdns_c_piir_ref_fs_wei_array_now);

    /* ---- C-channel 2D: fspa cur ---- */
    INTP(mdns_c_fspa_cur_fus_seg_intp, mdns_c_fspa_cur_fus_seg_array);
    INTP(mdns_c_fspa_cur_fus_wei_0_intp, mdns_c_fspa_cur_fus_wei_0_array);
    INTP(mdns_c_fspa_cur_fus_wei_16_intp, mdns_c_fspa_cur_fus_wei_16_array);
    INTP(mdns_c_fspa_cur_fus_wei_32_intp, mdns_c_fspa_cur_fus_wei_32_array);
    INTP(mdns_c_fspa_cur_fus_wei_48_intp, mdns_c_fspa_cur_fus_wei_48_array);
    INTP(mdns_c_fspa_cur_fus_wei_64_intp, mdns_c_fspa_cur_fus_wei_64_array);
    INTP(mdns_c_fspa_cur_fus_wei_80_intp, mdns_c_fspa_cur_fus_wei_80_array);
    INTP(mdns_c_fspa_cur_fus_wei_96_intp, mdns_c_fspa_cur_fus_wei_96_array);
    INTP(mdns_c_fspa_cur_fus_wei_112_intp, mdns_c_fspa_cur_fus_wei_112_array);
    INTP(mdns_c_fspa_cur_fus_wei_128_intp, mdns_c_fspa_cur_fus_wei_128_array);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_144_intp, mdns_c_fspa_cur_fus_wei_144_array_now);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_160_intp, mdns_c_fspa_cur_fus_wei_160_array_now);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_176_intp, mdns_c_fspa_cur_fus_wei_176_array_now);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_192_intp, mdns_c_fspa_cur_fus_wei_192_array_now);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_208_intp, mdns_c_fspa_cur_fus_wei_208_array_now);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_224_intp, mdns_c_fspa_cur_fus_wei_224_array_now);
    INTP_NULL(mdns_c_fspa_cur_fus_wei_240_intp, mdns_c_fspa_cur_fus_wei_240_array_now);

    /* ---- C-channel 2D: fspa ref ---- */
    INTP(mdns_c_fspa_ref_fus_seg_intp, mdns_c_fspa_ref_fus_seg_array);
    INTP(mdns_c_fspa_ref_fus_wei_0_intp, mdns_c_fspa_ref_fus_wei_0_array);
    INTP(mdns_c_fspa_ref_fus_wei_16_intp, mdns_c_fspa_ref_fus_wei_16_array);
    INTP(mdns_c_fspa_ref_fus_wei_32_intp, mdns_c_fspa_ref_fus_wei_32_array);
    INTP(mdns_c_fspa_ref_fus_wei_48_intp, mdns_c_fspa_ref_fus_wei_48_array);
    INTP(mdns_c_fspa_ref_fus_wei_64_intp, mdns_c_fspa_ref_fus_wei_64_array);
    INTP(mdns_c_fspa_ref_fus_wei_80_intp, mdns_c_fspa_ref_fus_wei_80_array);
    INTP(mdns_c_fspa_ref_fus_wei_96_intp, mdns_c_fspa_ref_fus_wei_96_array);
    INTP(mdns_c_fspa_ref_fus_wei_112_intp, mdns_c_fspa_ref_fus_wei_112_array);
    INTP(mdns_c_fspa_ref_fus_wei_128_intp, mdns_c_fspa_ref_fus_wei_128_array);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_144_intp, mdns_c_fspa_ref_fus_wei_144_array_now);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_160_intp, mdns_c_fspa_ref_fus_wei_160_array_now);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_176_intp, mdns_c_fspa_ref_fus_wei_176_array_now);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_192_intp, mdns_c_fspa_ref_fus_wei_192_array_now);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_208_intp, mdns_c_fspa_ref_fus_wei_208_array_now);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_224_intp, mdns_c_fspa_ref_fus_wei_224_array_now);
    INTP_NULL(mdns_c_fspa_ref_fus_wei_240_intp, mdns_c_fspa_ref_fus_wei_240_array_now);

    /* ---- C-channel 2D: fiir ---- */
    INTP(mdns_c_fiir_edge_thres0_intp, mdns_c_fiir_edge_thres0_array);
    INTP(mdns_c_fiir_edge_thres1_intp, mdns_c_fiir_edge_thres1_array);
    INTP(mdns_c_fiir_edge_thres2_intp, mdns_c_fiir_edge_thres2_array);
    INTP(mdns_c_fiir_edge_wei0_intp, mdns_c_fiir_edge_wei0_array);
    INTP(mdns_c_fiir_edge_wei1_intp, mdns_c_fiir_edge_wei1_array);
    INTP(mdns_c_fiir_edge_wei2_intp, mdns_c_fiir_edge_wei2_array);
    INTP(mdns_c_fiir_edge_wei3_intp, mdns_c_fiir_edge_wei3_array);
    INTP(mdns_c_fiir_fus_seg_intp, mdns_c_fiir_fus_seg_array);
    INTP_NULL(mdns_c_fiir_fus_wei0_intp, mdns_c_fiir_fus_wei0_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei1_intp, mdns_c_fiir_fus_wei1_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei2_intp, mdns_c_fiir_fus_wei2_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei3_intp, mdns_c_fiir_fus_wei3_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei4_intp, mdns_c_fiir_fus_wei4_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei5_intp, mdns_c_fiir_fus_wei5_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei6_intp, mdns_c_fiir_fus_wei6_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei7_intp, mdns_c_fiir_fus_wei7_array_now);
    INTP_NULL(mdns_c_fiir_fus_wei8_intp, mdns_c_fiir_fus_wei8_array_now);

    /* ---- C-channel 2D: false color ---- */
    INTP(mdns_c_false_smj_thres_intp, mdns_c_false_smj_thres_array);
    INTP(mdns_c_false_edg_thres0_intp, mdns_c_false_edg_thres0_array);
    INTP(mdns_c_false_edg_thres1_intp_scalar, mdns_c_false_edg_thres1_array);
    INTP(mdns_c_false_edg_thres2_intp, mdns_c_false_edg_thres2_array);
    INTP(mdns_c_false_thres_s0_intp, mdns_c_false_thres_s0_array);
    INTP(mdns_c_false_thres_s1_intp, mdns_c_false_thres_s1_array);
    INTP(mdns_c_false_thres_s2_intp, mdns_c_false_thres_s2_array);
    INTP(mdns_c_false_thres_s3_intp, mdns_c_false_thres_s3_array);
    INTP(mdns_c_false_step_s0_intp, mdns_c_false_step_s0_array);
    INTP(mdns_c_false_step_s1_intp, mdns_c_false_step_s1_array);
    INTP(mdns_c_false_step_s2_intp, mdns_c_false_step_s2_array);
    INTP(mdns_c_false_step_s3_intp, mdns_c_false_step_s3_array);
    INTP(mdns_c_false_thres_m0_intp, mdns_c_false_thres_m0_array);
    INTP(mdns_c_false_thres_m1_intp, mdns_c_false_thres_m1_array);
    INTP(mdns_c_false_thres_m2_intp, mdns_c_false_thres_m2_array);
    INTP(mdns_c_false_thres_m3_intp, mdns_c_false_thres_m3_array);
    INTP(mdns_c_false_step_m0_intp, mdns_c_false_step_m0_array);
    INTP(mdns_c_false_step_m1_intp, mdns_c_false_step_m1_array);
    INTP(mdns_c_false_step_m2_intp, mdns_c_false_step_m2_array);
    INTP(mdns_c_false_step_m3_intp, mdns_c_false_step_m3_array);

    /* ---- C-channel 2D: saturation ---- */
    INTP(mdns_c_sat_lmt_thres_intp, mdns_c_sat_lmt_thres_array);
    INTP(mdns_c_sat_lmt_stren_intp, mdns_c_sat_lmt_stren_array);
    INTP(mdns_c_sat_nml_stren_intp, mdns_c_sat_nml_stren_array);
}

#undef INTP
#undef INTP_NULL


/* ====================================================================
 * SECTION C: Rewritten param_cfg functions using _intp globals
 *
 * PLACEMENT: Replace existing tisp_mdns_y_3d_param_cfg,
 *            tisp_mdns_y_2d_param_cfg, tisp_mdns_c_3d_param_cfg,
 *            tisp_mdns_c_2d_param_cfg, tisp_mdns_top_func_cfg
 *            (lines ~24883 through ~25569).
 *
 * These read from the pre-computed _intp globals set by tisp_mdns_intp()
 * instead of calling tisp_mdns_intp_table() at register-write time.
 * ====================================================================
 */

/* OEM: 0x32c00 - tisp_mdns_y_3d_param_cfg */
static int tisp_mdns_y_3d_param_cfg(void)
{
    u32 blk = mdns_y_sta_blk_size_intp;
    u32 width = mdns_frame_width;
    u32 height = mdns_frame_height;
    u32 half;
    u32 width_half;
    u32 height_half;
    u32 width_cnt;
    u32 height_cnt;
    u32 width_half_cnt;
    u32 height_half_cnt;
    u32 width_rem;
    u32 height_rem;
    u32 width_half_rem;
    u32 height_half_rem;
    u32 blk_pair;
    u32 sta_cfg;
    u32 hist_sta_en;
    u32 edge_wei5;
    u32 edge_thr5;
    u32 luma_wei5;
    u32 luma_thr5;
    u32 dtb_wei5;
    u32 dtb_thr5;
    u32 ass_wei5;
    u32 ass_thr5;
    u32 sad_wei5;

    /* OEM: round up blk to multiple of 4, min 0x10 */
    if (blk & 3)
        blk = ((blk >> 2) + 1) << 2;
    if (blk < 0x10)
        blk = 0x10;

    half = blk >> 1;
    width_half = (width > half) ? (width - half) : 0;
    height_half = (height > half) ? (height - half) : 0;

    width_rem = width % blk;
    height_rem = height % blk;
    width_half_rem = width_half % blk;
    height_half_rem = height_half % blk;

    width_cnt = tisp_mdns_div_round_up(width, blk);
    height_cnt = tisp_mdns_div_round_up(height, blk);
    width_half_cnt = tisp_mdns_div_round_up(width_half, blk);
    height_half_cnt = tisp_mdns_div_round_up(height_half, blk);
    blk_pair = (blk << 8) | blk;

    /* STA grid config - 4 quadrants */
    system_reg_write(0x7870, ((height_rem ? 1 : 0) << 1) | (width_rem ? 1 : 0));
    system_reg_write(0x7888, ((height_half_rem ? 1 : 0) << 1) | (width_rem ? 1 : 0));
    system_reg_write(0x78a0, ((height_rem ? 1 : 0) << 1) | (width_half_rem ? 1 : 0));
    system_reg_write(0x78b8, ((height_half_rem ? 1 : 0) << 1) | (width_half_rem ? 1 : 0));

    system_reg_write(0x7874, (width_cnt << 24) | blk_pair | (height_cnt << 16));
    system_reg_write(0x788c, (width_cnt << 24) | blk_pair | (height_half_cnt << 16));
    system_reg_write(0x78a4, (width_half_cnt << 24) | blk_pair | (height_cnt << 16));
    system_reg_write(0x78bc, (width_half_cnt << 24) | blk_pair | (height_half_cnt << 16));
    system_reg_write(0x7880, half << 16);
    system_reg_write(0x7898, half);
    system_reg_write(0x78b0, half | (half << 16));
    system_reg_write(0x7884, width | (height_half << 16));
    system_reg_write(0x789c, width_half | (height << 16));
    system_reg_write(0x78b4, width_half | (height_half << 16));

    /* STA motion config - same for all 4 quadrants */
    sta_cfg = mdns_sta_inter_en_array |
              (mdns_sta_max_num_array << 4) |
              (mdns_y_sta_motion_thres_intp << 8);
    system_reg_write(0x7878, sta_cfg);
    system_reg_write(0x7890, sta_cfg);
    system_reg_write(0x78a8, sta_cfg);
    system_reg_write(0x78c0, sta_cfg);

    /* STA thresholds - same for all 4 quadrants */
    {
        u32 sta_thr = mdns_y_sta_win_opt_intp |
                      (mdns_y_sta_ave_thres_intp << 4) |
                      (mdns_y_sta_ass_thres_intp << 16) |
                      (mdns_y_sta_dtb_thres_intp << 24);
        system_reg_write(0x787c, sta_thr);
        system_reg_write(0x7894, sta_thr);
        system_reg_write(0x78ac, sta_thr);
        system_reg_write(0x78c4, sta_thr);
    }

    /* SAD config */
    system_reg_write(0x7944,
                     mdns_y_sad_win_opt_intp |
                     (mdns_y_sad_ave_thres_intp << 3) |
                     (mdns_y_sad_ave_slope_intp << 12) |
                     (mdns_y_sad_ass_thres_intp << 16) |
                     (mdns_y_sad_dtb_thres_intp << 24));

    /* ref_wei_sta pack4 registers - NOT interpolated, read directly from arrays */
    system_reg_write(0x7948, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 0));
    system_reg_write(0x7958, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 0));
    system_reg_write(0x7968, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 0));
    system_reg_write(0x7978, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 0));
    system_reg_write(0x794c, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 4));
    system_reg_write(0x795c, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 4));
    system_reg_write(0x796c, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 4));
    system_reg_write(0x797c, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 4));
    system_reg_write(0x7950, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 8));
    system_reg_write(0x7960, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 8));
    system_reg_write(0x7970, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 8));
    system_reg_write(0x7980, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 8));
    system_reg_write(0x7954, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 12));
    system_reg_write(0x7964, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 12));
    system_reg_write(0x7974, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 12));
    system_reg_write(0x7984, tisp_mdns_pack4(mdns_y_ref_wei_sta_array, 12));

    /* ref_wei_psn pack4 registers - NOT interpolated */
    system_reg_write(0x7988, tisp_mdns_pack4(mdns_y_ref_wei_psn_array, 0));
    system_reg_write(0x798c, tisp_mdns_pack4(mdns_y_ref_wei_psn_array, 4));
    system_reg_write(0x7990, tisp_mdns_pack4(mdns_y_ref_wei_psn_array, 8));
    system_reg_write(0x7994, tisp_mdns_pack4(mdns_y_ref_wei_psn_array, 12));

    /* ref_wei scalar params */
    system_reg_write(0x7998,
                     mdns_y_ref_wei_psn_fs_opt_intp |
                     (mdns_y_ref_wei_sta_fs_opt_intp << 4) |
                     (mdns_y_ref_wei_fake_intp << 8) |
                     (mdns_y_ref_wei_mv_intp << 16));
    system_reg_write(0x799c,
                     mdns_y_ref_wei_f_max_intp |
                     (mdns_y_ref_wei_f_min_intp << 8) |
                     (mdns_y_ref_wei_b_max_intp << 16) |
                     (mdns_y_ref_wei_b_min_intp << 24));
    system_reg_write(0x79a0,
                     mdns_y_ref_wei_r_max_intp |
                     (mdns_y_ref_wei_r_min_intp << 8) |
                     (mdns_y_ref_wei_increase_intp << 16));

    /* Histogram config */
    hist_sta_en = mdns_y_hist_sta_en_intp;
    system_reg_write(0x78c8,
                     mdns_y_hist_sad_en_intp |
                     (hist_sta_en << 1) |
                     (hist_sta_en << 2) |
                     (hist_sta_en << 3) |
                     (hist_sta_en << 4));
    system_reg_write(0x78d4,
                     mdns_y_hist_thres0_intp |
                     (mdns_y_hist_thres1_intp << 16));
    system_reg_write(0x78d8,
                     mdns_y_hist_thres2_intp |
                     (mdns_y_hist_thres3_intp << 16));
    system_reg_write(0x78cc,
                     mdns_y_hist_cmp_thres0_intp |
                     (mdns_y_hist_cmp_thres1_intp << 16));
    system_reg_write(0x78d0,
                     mdns_y_hist_cmp_thres2_intp |
                     (mdns_y_hist_cmp_thres3_intp << 16));

    /* Corner */
    system_reg_write(0x78e0,
                     mdns_y_corner_length_t_intp |
                     (mdns_y_corner_length_b_intp << 8) |
                     (mdns_y_corner_length_l_intp << 16) |
                     (mdns_y_corner_length_r_intp << 24));
    system_reg_write(0x78e4,
                     mdns_y_corner_wei_adj_value_intp |
                     (mdns_y_corner_thr_adj_value_intp << 8));

    /* Edge */
    system_reg_write(0x78e8,
                     mdns_y_edge_win_opt_intp |
                     (mdns_y_edge_div_opt_intp << 2) |
                     (mdns_y_edge_type_opt_intp << 4) |
                     (mdns_y_edge_wei_adj_seg_intp << 8) |
                     (mdns_y_edge_thr_adj_seg_intp << 10));
    system_reg_write(0x78ec,
                     mdns_y_edge_wei_adj_value0_intp |
                     (mdns_y_edge_wei_adj_value1_intp << 8) |
                     (mdns_y_edge_wei_adj_value2_intp << 16) |
                     (mdns_y_edge_wei_adj_value3_intp << 24));
    edge_wei5 = mdns_y_edge_wei_adj_value5_intp;
    system_reg_write(0x78f0,
                     mdns_y_edge_wei_adj_value4_intp |
                     (edge_wei5 << 8) | (edge_wei5 << 16) | (edge_wei5 << 24));
    system_reg_write(0x78f4,
                     mdns_y_edge_thr_adj_value0_intp |
                     (mdns_y_edge_thr_adj_value1_intp << 8) |
                     (mdns_y_edge_thr_adj_value2_intp << 16) |
                     (mdns_y_edge_thr_adj_value3_intp << 24));
    edge_thr5 = mdns_y_edge_thr_adj_value5_intp;
    system_reg_write(0x78f8,
                     mdns_y_edge_thr_adj_value4_intp |
                     (edge_thr5 << 8) | (edge_thr5 << 16) | (edge_thr5 << 24));

    /* Luma */
    system_reg_write(0x78fc,
                     mdns_y_luma_win_opt_intp |
                     (mdns_y_luma_wei_adj_seg_intp << 8) |
                     (mdns_y_luma_thr_adj_seg_intp << 10));
    system_reg_write(0x7900,
                     mdns_y_luma_wei_adj_value0_intp |
                     (mdns_y_luma_wei_adj_value1_intp << 8) |
                     (mdns_y_luma_wei_adj_value2_intp << 16) |
                     (mdns_y_luma_wei_adj_value3_intp << 24));
    luma_wei5 = mdns_y_luma_wei_adj_value5_intp;
    system_reg_write(0x7904,
                     mdns_y_luma_wei_adj_value4_intp |
                     (luma_wei5 << 8) | (luma_wei5 << 16) | (luma_wei5 << 24));
    system_reg_write(0x7908,
                     mdns_y_luma_thr_adj_value0_intp |
                     (mdns_y_luma_thr_adj_value1_intp << 8) |
                     (mdns_y_luma_thr_adj_value2_intp << 16) |
                     (mdns_y_luma_thr_adj_value3_intp << 24));
    luma_thr5 = mdns_y_luma_thr_adj_value5_intp;
    system_reg_write(0x790c,
                     mdns_y_luma_thr_adj_value4_intp |
                     (luma_thr5 << 8) | (luma_thr5 << 16) | (luma_thr5 << 24));

    /* DTB */
    system_reg_write(0x7910,
                     mdns_y_dtb_squ_div_opt_intp |
                     (mdns_y_dtb_div_opt_intp << 2) |
                     (mdns_y_dtb_squ_en_intp << 4) |
                     (mdns_y_dtb_wei_adj_seg_intp << 8) |
                     (mdns_y_dtb_thr_adj_seg_intp << 10));
    system_reg_write(0x7914,
                     mdns_y_dtb_wei_adj_value0_intp |
                     (mdns_y_dtb_wei_adj_value1_intp << 8) |
                     (mdns_y_dtb_wei_adj_value2_intp << 16) |
                     (mdns_y_dtb_wei_adj_value3_intp << 24));
    dtb_wei5 = mdns_y_dtb_wei_adj_value5_intp;
    system_reg_write(0x7918,
                     mdns_y_dtb_wei_adj_value4_intp |
                     (dtb_wei5 << 8) | (dtb_wei5 << 16) | (dtb_wei5 << 24));
    system_reg_write(0x791c,
                     mdns_y_dtb_thr_adj_value0_intp |
                     (mdns_y_dtb_thr_adj_value1_intp << 8) |
                     (mdns_y_dtb_thr_adj_value2_intp << 16) |
                     (mdns_y_dtb_thr_adj_value3_intp << 24));
    dtb_thr5 = mdns_y_dtb_thr_adj_value5_intp;
    system_reg_write(0x7920,
                     mdns_y_dtb_thr_adj_value4_intp |
                     (dtb_thr5 << 8) | (dtb_thr5 << 16) | (dtb_thr5 << 24));

    /* ASS */
    system_reg_write(0x7924,
                     mdns_y_ass_div_opt_intp |
                     (mdns_y_ass_win_opt_intp << 4) |
                     (mdns_y_ass_wei_adj_seg_intp << 8) |
                     (mdns_y_ass_thr_adj_seg_intp << 10));
    system_reg_write(0x7928,
                     mdns_y_ass_wei_adj_value0_intp |
                     (mdns_y_ass_wei_adj_value1_intp_scalar << 8) |
                     (mdns_y_ass_wei_adj_value2_intp << 16) |
                     (mdns_y_ass_wei_adj_value3_intp << 24));
    ass_wei5 = mdns_y_ass_wei_adj_value5_intp;
    system_reg_write(0x792c,
                     mdns_y_ass_wei_adj_value4_intp |
                     (ass_wei5 << 8) | (ass_wei5 << 16) | (ass_wei5 << 24));
    system_reg_write(0x7930,
                     mdns_y_ass_thr_adj_value0_intp |
                     (mdns_y_ass_thr_adj_value1_intp << 8) |
                     (mdns_y_ass_thr_adj_value2_intp << 16) |
                     (mdns_y_ass_thr_adj_value3_intp << 24));
    ass_thr5 = mdns_y_ass_thr_adj_value5_intp;
    system_reg_write(0x7934,
                     mdns_y_ass_thr_adj_value4_intp |
                     (ass_thr5 << 8) | (ass_thr5 << 16) | (ass_thr5 << 24));

    /* SAD weight */
    system_reg_write(0x7938, mdns_y_sad_wei_adj_seg_intp);
    system_reg_write(0x793c,
                     mdns_y_sad_wei_adj_value0_intp |
                     (mdns_y_sad_wei_adj_value1_intp << 8) |
                     (mdns_y_sad_wei_adj_value2_intp << 16) |
                     (mdns_y_sad_wei_adj_value3_intp << 24));
    sad_wei5 = mdns_y_sad_wei_adj_value5_intp;
    system_reg_write(0x7940,
                     mdns_y_sad_wei_adj_value4_intp |
                     (sad_wei5 << 8) | (sad_wei5 << 16) | (sad_wei5 << 24));

    return 0;
}

/* OEM: 0x338bc - tisp_mdns_y_2d_param_cfg */
static int tisp_mdns_y_2d_param_cfg(void)
{
    u32 cur_bi_wei0 = mdns_y_pspa_cur_bi_wei0_intp;
    u32 ref_bi_wei0 = mdns_y_pspa_ref_bi_wei0_intp;
    u32 cur_fus0 = mdns_y_fspa_cur_fus_wei_0_intp;
    u32 ref_fus0 = mdns_y_fspa_ref_fus_wei_0_intp;
    u32 fiir_fus0 = mdns_y_fiir_fus_wei0_intp;
    u32 bi_rep_cur = cur_bi_wei0 | (cur_bi_wei0 << 4) | (cur_bi_wei0 << 8) |
                     (cur_bi_wei0 << 12) | (cur_bi_wei0 << 16) | (cur_bi_wei0 << 20);
    u32 bi_rep_ref = ref_bi_wei0 | (ref_bi_wei0 << 4) | (ref_bi_wei0 << 8) |
                     (ref_bi_wei0 << 12) | (ref_bi_wei0 << 16) | (ref_bi_wei0 << 20);
    u32 fus0_rep = cur_fus0 | (cur_fus0 << 8) | (cur_fus0 << 16) | (cur_fus0 << 24);
    u32 ref0_rep = ref_fus0 | (ref_fus0 << 8) | (ref_fus0 << 16) | (ref_fus0 << 24);
    u32 fiir0_rep = fiir_fus0 | (fiir_fus0 << 8) | (fiir_fus0 << 16) | (fiir_fus0 << 24);

    /* PSPA cur config */
    system_reg_write(0x79a4,
                     mdns_y_pspa_cur_bi_thres_intp |
                     (mdns_y_pspa_cur_bi_wei_seg_intp << 8) |
                     (mdns_y_pspa_cur_lmt_op_en_intp << 10));
    system_reg_write(0x79a8, bi_rep_cur);

    /* PSPA ref config */
    system_reg_write(0x79ac,
                     mdns_y_pspa_ref_bi_thres_intp |
                     (mdns_y_pspa_ref_bi_wei_seg_intp << 8) |
                     (mdns_y_pspa_ref_lmt_op_en_intp << 10));
    system_reg_write(0x79b0, bi_rep_ref);

    /* PSPA/FSPA combined config */
    system_reg_write(0x79b4,
                     mdns_y_pspa_cur_median_win_opt_intp |
                     (mdns_y_pspa_ref_median_win_opt_intp << 1) |
                     (mdns_y_fspa_cur_fus_seg_intp << 4) |
                     (mdns_y_fspa_ref_fus_seg_intp << 8) |
                     (mdns_y_pspa_fnl_fus_thres_intp << 16) |
                     (mdns_y_pspa_fnl_fus_dwei_intp << 24) |
                     (mdns_y_pspa_fnl_fus_swei_intp << 28));

    /* FSPA cur weight registers */
    system_reg_write(0x79b8, fus0_rep);
    system_reg_write(0x79bc, fus0_rep);
    system_reg_write(0x79c0,
                     cur_fus0 |
                     (cur_fus0 << 8) |
                     (cur_fus0 << 16) |
                     (mdns_y_fspa_cur_fus_wei_144_intp << 24));
    system_reg_write(0x79c4,
                     mdns_y_fspa_cur_fus_wei_160_intp |
                     (mdns_y_fspa_cur_fus_wei_176_intp << 8) |
                     (mdns_y_fspa_cur_fus_wei_192_intp << 16) |
                     (mdns_y_fspa_cur_fus_wei_208_intp << 24));

    /* FSPA ref weight registers */
    system_reg_write(0x79c8, ref0_rep);
    system_reg_write(0x79cc, ref0_rep);
    system_reg_write(0x79d0,
                     ref_fus0 |
                     (ref_fus0 << 8) |
                     (ref_fus0 << 16) |
                     (mdns_y_fspa_ref_fus_wei_144_intp << 24));
    system_reg_write(0x79d4,
                     mdns_y_fspa_ref_fus_wei_160_intp |
                     (mdns_y_fspa_ref_fus_wei_176_intp << 8) |
                     (mdns_y_fspa_ref_fus_wei_192_intp << 16) |
                     (mdns_y_fspa_ref_fus_wei_208_intp << 24));

    /* PIIR edge config - written twice (OEM exact) */
    system_reg_write(0x79d8,
                     mdns_y_piir_edge_thres0_intp |
                     (mdns_y_piir_edge_thres1_intp << 8) |
                     (mdns_y_piir_edge_thres2_intp << 16));
    system_reg_write(0x79dc,
                     mdns_y_piir_edge_wei0_intp |
                     (mdns_y_piir_edge_wei1_intp << 8) |
                     (mdns_y_piir_edge_wei2_intp << 16) |
                     (mdns_y_piir_edge_wei3_intp << 24));
    system_reg_write(0x79e0,
                     mdns_y_piir_cur_fs_wei_intp |
                     (mdns_y_piir_ref_fs_wei_intp << 8));
    system_reg_write(0x79e4,
                     mdns_y_piir_edge_thres0_intp |
                     (mdns_y_piir_edge_thres1_intp << 8) |
                     (mdns_y_piir_edge_thres2_intp << 16));
    system_reg_write(0x79e8,
                     mdns_y_piir_edge_wei0_intp |
                     (mdns_y_piir_edge_wei1_intp << 8) |
                     (mdns_y_piir_edge_wei2_intp << 16) |
                     (mdns_y_piir_edge_wei3_intp << 24));

    /* FIIR config */
    system_reg_write(0x79ec, mdns_y_fiir_fus_seg_intp);
    system_reg_write(0x79f0, fiir0_rep);
    system_reg_write(0x79f4, fiir0_rep);
    system_reg_write(0x79f8,
                     mdns_y_fiir_fus_wei1_intp |
                     (mdns_y_fiir_fus_wei2_intp << 8) |
                     (mdns_y_fiir_fus_wei3_intp << 16) |
                     (mdns_y_fiir_fus_wei4_intp << 24));
    system_reg_write(0x79fc,
                     mdns_y_fiir_fus_wei5_intp |
                     (mdns_y_fiir_fus_wei6_intp << 8) |
                     (mdns_y_fiir_fus_wei7_intp << 16) |
                     (mdns_y_fiir_fus_wei8_intp << 24));

    /* Contrast strength */
    system_reg_write(0x7a00, mdns_y_con_stren_intp << 8);

    return 0;
}

/* OEM: 0x33d8c - tisp_mdns_c_3d_param_cfg */
static int tisp_mdns_c_3d_param_cfg(void)
{
    u32 edge_wei5 = mdns_c_edge_wei_adj_value5_intp;
    u32 edge_thr5 = mdns_c_edge_thr_adj_value5_intp;
    u32 luma_wei5 = mdns_c_luma_wei_adj_value5_intp;
    u32 luma_thr5 = mdns_c_luma_thr_adj_value5_intp;
    u32 dtb_wei5 = mdns_c_dtb_wei_adj_value5_intp;
    u32 dtb_thr5 = mdns_c_dtb_thr_adj_value5_intp;
    u32 ass_wei5 = mdns_c_ass_wei_adj_value5_intp;
    u32 ass_thr5 = mdns_c_ass_thr_adj_value5_intp;
    u32 sad_wei5 = mdns_c_sad_wei_adj_value5_intp;

    /* SAD config */
    system_reg_write(0x7a64,
                     mdns_c_sad_win_opt_intp |
                     (mdns_c_sad_ave_thres_intp << 3) |
                     (mdns_c_sad_ave_slope_intp << 12) |
                     (mdns_c_sad_ass_thres_intp << 16) |
                     (mdns_c_sad_dtb_thres_intp << 24));

    /* Ref weight */
    system_reg_write(0x7a68,
                     (mdns_c_ref_wei_fake_intp << 8) |
                     (mdns_c_ref_wei_mv_intp << 16));
    system_reg_write(0x7a6c,
                     mdns_c_ref_wei_f_max_intp |
                     (mdns_c_ref_wei_f_min_intp << 8) |
                     (mdns_c_ref_wei_b_max_intp << 16) |
                     (mdns_c_ref_wei_b_min_intp << 24));
    system_reg_write(0x7a70,
                     mdns_c_ref_wei_r_max_intp |
                     (mdns_c_ref_wei_r_min_intp << 8) |
                     (mdns_c_ref_wei_increase_intp << 16));

    /* Corner */
    system_reg_write(0x7a04,
                     mdns_c_corner_wei_adj_value_intp |
                     (mdns_c_corner_thr_adj_value_intp << 8));

    /* Edge */
    system_reg_write(0x7a08,
                     (mdns_c_edge_wei_adj_seg_intp << 8) |
                     (mdns_c_edge_thr_adj_seg_intp << 10));
    system_reg_write(0x7a0c,
                     mdns_c_edge_wei_adj_value0_intp |
                     (mdns_c_edge_wei_adj_value1_intp << 8) |
                     (mdns_c_edge_wei_adj_value2_intp << 16) |
                     (mdns_c_edge_wei_adj_value3_intp << 24));
    system_reg_write(0x7a10,
                     mdns_c_edge_wei_adj_value4_intp |
                     (edge_wei5 << 8) | (edge_wei5 << 16) | (edge_wei5 << 24));
    system_reg_write(0x7a14,
                     mdns_c_edge_thr_adj_value0_intp |
                     (mdns_c_edge_thr_adj_value1_intp << 8) |
                     (mdns_c_edge_thr_adj_value2_intp << 16) |
                     (mdns_c_edge_thr_adj_value3_intp << 24));
    system_reg_write(0x7a18,
                     mdns_c_edge_thr_adj_value4_intp |
                     (edge_thr5 << 8) | (edge_thr5 << 16) | (edge_thr5 << 24));

    /* Luma */
    system_reg_write(0x7a1c,
                     (mdns_c_luma_wei_adj_seg_intp << 8) |
                     (mdns_c_luma_thr_adj_seg_intp << 10));
    system_reg_write(0x7a20,
                     mdns_c_luma_wei_adj_value0_intp |
                     (mdns_c_luma_wei_adj_value1_intp << 8) |
                     (mdns_c_luma_wei_adj_value2_intp << 16) |
                     (mdns_c_luma_wei_adj_value3_intp << 24));
    system_reg_write(0x7a24,
                     mdns_c_luma_wei_adj_value4_intp |
                     (luma_wei5 << 8) | (luma_wei5 << 16) | (luma_wei5 << 24));
    system_reg_write(0x7a28,
                     mdns_c_luma_thr_adj_value0_intp |
                     (mdns_c_luma_thr_adj_value1_intp << 8) |
                     (mdns_c_luma_thr_adj_value2_intp << 16) |
                     (mdns_c_luma_thr_adj_value3_intp << 24));
    system_reg_write(0x7a2c,
                     mdns_c_luma_thr_adj_value4_intp |
                     (luma_thr5 << 8) | (luma_thr5 << 16) | (luma_thr5 << 24));

    /* DTB */
    system_reg_write(0x7a30,
                     (mdns_c_dtb_wei_adj_seg_intp << 8) |
                     (mdns_c_dtb_thr_adj_seg_intp << 10));
    system_reg_write(0x7a34,
                     mdns_c_dtb_wei_adj_value0_intp |
                     (mdns_c_dtb_wei_adj_value1_intp << 8) |
                     (mdns_c_dtb_wei_adj_value2_intp << 16) |
                     (mdns_c_dtb_wei_adj_value3_intp << 24));
    system_reg_write(0x7a38,
                     mdns_c_dtb_wei_adj_value4_intp |
                     (dtb_wei5 << 8) | (dtb_wei5 << 16) | (dtb_wei5 << 24));
    system_reg_write(0x7a3c,
                     mdns_c_dtb_thr_adj_value0_intp |
                     (mdns_c_dtb_thr_adj_value1_intp << 8) |
                     (mdns_c_dtb_thr_adj_value2_intp << 16) |
                     (mdns_c_dtb_thr_adj_value3_intp << 24));
    system_reg_write(0x7a40,
                     mdns_c_dtb_thr_adj_value4_intp |
                     (dtb_thr5 << 8) | (dtb_thr5 << 16) | (dtb_thr5 << 24));

    /* ASS */
    system_reg_write(0x7a44,
                     (mdns_c_ass_wei_adj_seg_intp << 8) |
                     (mdns_c_ass_thr_adj_seg_intp << 10));
    system_reg_write(0x7a48,
                     mdns_c_ass_wei_adj_value0_intp |
                     (mdns_c_ass_wei_adj_value1_intp << 8) |
                     (mdns_c_ass_wei_adj_value2_intp << 16) |
                     (mdns_c_ass_wei_adj_value3_intp << 24));
    system_reg_write(0x7a4c,
                     mdns_c_ass_wei_adj_value4_intp |
                     (ass_wei5 << 8) | (ass_wei5 << 16) | (ass_wei5 << 24));
    system_reg_write(0x7a50,
                     mdns_c_ass_thr_adj_value0_intp |
                     (mdns_c_ass_thr_adj_value1_intp << 8) |
                     (mdns_c_ass_thr_adj_value2_intp << 16) |
                     (mdns_c_ass_thr_adj_value3_intp << 24));
    system_reg_write(0x7a54,
                     mdns_c_ass_thr_adj_value4_intp |
                     (ass_thr5 << 8) | (ass_thr5 << 16) | (ass_thr5 << 24));

    /* SAD weight */
    system_reg_write(0x7a58, mdns_c_sad_wei_adj_seg_intp);
    system_reg_write(0x7a5c,
                     mdns_c_sad_wei_adj_value0_intp |
                     (mdns_c_sad_wei_adj_value1_intp << 8) |
                     (mdns_c_sad_wei_adj_value2_intp << 16) |
                     (mdns_c_sad_wei_adj_value3_intp << 24));
    system_reg_write(0x7a60,
                     mdns_c_sad_wei_adj_value4_intp |
                     (sad_wei5 << 8) | (sad_wei5 << 16) | (sad_wei5 << 24));

    return 0;
}

/* OEM: 0x34348 - tisp_mdns_c_2d_param_cfg */
static int tisp_mdns_c_2d_param_cfg(void)
{
    u32 half_w = mdns_frame_width / 2;
    u32 half_h = mdns_frame_height / 2;
    u32 half_w_pad = (half_w & 0xf) ? ((half_w % 0x10) / 2) : 0;
    u32 half_h_pad = (half_h & 0xf) ? ((half_h % 0x10) / 2) : 0;
    u32 cur0 = mdns_c_fspa_cur_fus_wei_0_intp;
    u32 ref0 = mdns_c_fspa_ref_fus_wei_0_intp;
    u32 fiir0 = mdns_c_fiir_fus_wei0_intp;
    u32 cur0_rep = cur0 | (cur0 << 8) | (cur0 << 16) | (cur0 << 24);
    u32 ref0_rep = ref0 | (ref0 << 8) | (ref0 << 16) | (ref0 << 24);
    u32 fiir0_rep = fiir0 | (fiir0 << 8) | (fiir0 << 16) | (fiir0 << 24);

    /* Median config */
    system_reg_write(0x7a74,
                     mdns_c_median_smj_thres_intp |
                     (mdns_c_median_edg_thres_intp << 8) |
                     (mdns_c_median_cur_lmt_op_en_intp << 16) |
                     (mdns_c_median_cur_lmt_wei_intp << 17) |
                     (mdns_c_median_ref_lmt_op_en_intp << 24) |
                     (mdns_c_median_ref_lmt_wei_intp << 25));
    system_reg_write(0x7a78,
                     mdns_c_median_cur_ss_wei_intp |
                     (mdns_c_median_cur_se_wei_intp << 4) |
                     (mdns_c_median_cur_ms_wei_intp << 8) |
                     (mdns_c_median_cur_me_wei_intp << 12));
    system_reg_write(0x7a7c,
                     mdns_c_median_ref_ss_wei_intp |
                     (mdns_c_median_ref_se_wei_intp << 4) |
                     (mdns_c_median_ref_ms_wei_intp << 8) |
                     (mdns_c_median_ref_me_wei_intp << 12));

    /* BGM config */
    system_reg_write(0x7a80,
                     mdns_bgm_inter_en_array |
                     (mdns_c_bgm_cur_src_intp << 4) |
                     (mdns_c_bgm_ref_src_intp << 6) |
                     (mdns_c_bgm_false_thres_intp << 8) |
                     (mdns_c_bgm_false_step_intp << 16) |
                     (mdns_c_bgm_win_opt_intp << 20));
    system_reg_write(0x7a84, (half_h_pad << 16) | half_w_pad);
    system_reg_write(0x7a88,
                     ((half_h - (half_h_pad << 1)) << 16) |
                     (half_w - (half_w_pad << 1)));

    /* FSPA seg config */
    system_reg_write(0x7a8c,
                     (mdns_c_fspa_cur_fus_seg_intp << 4) |
                     (mdns_c_fspa_ref_fus_seg_intp << 8));

    /* FSPA cur weight registers */
    system_reg_write(0x7a90, cur0_rep);
    system_reg_write(0x7a94, cur0_rep);
    system_reg_write(0x7a98,
                     cur0 |
                     (cur0 << 8) |
                     (cur0 << 16) |
                     (mdns_c_fspa_cur_fus_wei_144_intp << 24));
    system_reg_write(0x7a9c,
                     mdns_c_fspa_cur_fus_wei_160_intp |
                     (mdns_c_fspa_cur_fus_wei_176_intp << 8) |
                     (mdns_c_fspa_cur_fus_wei_192_intp << 16) |
                     (mdns_c_fspa_cur_fus_wei_208_intp << 24));

    /* FSPA ref weight registers */
    system_reg_write(0x7aa0, ref0_rep);
    system_reg_write(0x7aa4, ref0_rep);
    system_reg_write(0x7aa8,
                     ref0 |
                     (ref0 << 8) |
                     (ref0 << 16) |
                     (mdns_c_fspa_ref_fus_wei_144_intp << 24));
    system_reg_write(0x7aac,
                     mdns_c_fspa_ref_fus_wei_160_intp |
                     (mdns_c_fspa_ref_fus_wei_176_intp << 8) |
                     (mdns_c_fspa_ref_fus_wei_192_intp << 16) |
                     (mdns_c_fspa_ref_fus_wei_208_intp << 24));

    /* PIIR edge config - written twice (OEM exact) */
    system_reg_write(0x7ab0,
                     mdns_c_piir_edge_thres0_intp |
                     (mdns_c_piir_edge_thres1_intp << 8) |
                     (mdns_c_piir_edge_thres2_intp << 16));
    system_reg_write(0x7ab4,
                     mdns_c_piir_edge_wei0_intp |
                     (mdns_c_piir_edge_wei1_intp << 8) |
                     (mdns_c_piir_edge_wei2_intp << 16) |
                     (mdns_c_piir_edge_wei3_intp << 24));
    system_reg_write(0x7ab8,
                     mdns_c_piir_cur_fs_wei_intp |
                     (mdns_c_piir_ref_fs_wei_intp << 8));
    system_reg_write(0x7abc,
                     mdns_c_piir_edge_thres0_intp |
                     (mdns_c_piir_edge_thres1_intp << 8) |
                     (mdns_c_piir_edge_thres2_intp << 16));
    system_reg_write(0x7ac0,
                     mdns_c_piir_edge_wei0_intp |
                     (mdns_c_piir_edge_wei1_intp << 8) |
                     (mdns_c_piir_edge_wei2_intp << 16) |
                     (mdns_c_piir_edge_wei3_intp << 24));

    /* FIIR config */
    system_reg_write(0x7ac4, mdns_c_fiir_fus_seg_intp);
    system_reg_write(0x7ac8, fiir0_rep);
    system_reg_write(0x7acc, fiir0_rep);
    system_reg_write(0x7ad0,
                     mdns_c_fiir_fus_wei1_intp |
                     (mdns_c_fiir_fus_wei2_intp << 8) |
                     (mdns_c_fiir_fus_wei3_intp << 16) |
                     (mdns_c_fiir_fus_wei4_intp << 24));
    system_reg_write(0x7ad4,
                     mdns_c_fiir_fus_wei5_intp |
                     (mdns_c_fiir_fus_wei6_intp << 8) |
                     (mdns_c_fiir_fus_wei7_intp << 16) |
                     (mdns_c_fiir_fus_wei8_intp << 24));

    /* False color suppression */
    system_reg_write(0x7ad8,
                     mdns_c_false_smj_thres_intp |
                     (mdns_c_false_edg_thres0_intp << 8) |
                     (mdns_c_false_edg_thres1_intp_scalar << 16) |
                     (mdns_c_false_edg_thres2_intp << 24));
    system_reg_write(0x7adc,
                     mdns_c_false_thres_s0_intp |
                     (mdns_c_false_step_s0_intp << 8) |
                     (mdns_c_false_thres_s0_intp << 16) |
                     (mdns_c_false_step_s0_intp << 24));
    system_reg_write(0x7ae0,
                     mdns_c_false_thres_s0_intp |
                     (mdns_c_false_step_s0_intp << 8) |
                     (mdns_c_false_thres_s0_intp << 16) |
                     (mdns_c_false_step_s0_intp << 24));
    system_reg_write(0x7ae4,
                     mdns_c_false_thres_m0_intp |
                     (mdns_c_false_step_m0_intp << 8) |
                     (mdns_c_false_thres_m0_intp << 16) |
                     (mdns_c_false_step_m0_intp << 24));
    system_reg_write(0x7ae8,
                     mdns_c_false_thres_m0_intp |
                     (mdns_c_false_step_m0_intp << 8) |
                     (mdns_c_false_thres_m0_intp << 16) |
                     (mdns_c_false_step_m0_intp << 24));

    /* Saturation */
    system_reg_write(0x7aec,
                     mdns_c_sat_nml_stren_intp |
                     (mdns_c_sat_lmt_thres_intp << 8) |
                     (mdns_c_sat_lmt_stren_intp << 16));

    return 0;
}

/* OEM: 0x32ae0 - tisp_mdns_top_func_cfg */
static int tisp_mdns_top_func_cfg(int enable)
{
    u32 ctrl = 0x101;
    u32 top1;

    if (enable) {
        ctrl = 0x10001 |
               (mdns_y_sf_cur_en_array << 4) |
               (mdns_y_sf_ref_en_array << 8) |
               (mdns_y_filter_en_array << 12) |
               (mdns_uv_sf_cur_en_array << 20) |
               (mdns_uv_sf_ref_en_array << 24) |
               (mdns_uv_filter_en_array << 28);
    }

    system_reg_write(0x7810, ctrl);

    /* OEM reads mdns_y_con_thres_intp (pre-computed global) */
    top1 = mdns_y_con_thres_intp |
           (mdns_bgm_enable_array << 4) |
           (mdns_ref_wei_byps_array << 8) |
           (mdns_sta_group_num_array << 12) |
           (mdns_psn_enable_array << 16) |
           (mdns_psn_max_num_array << 20);
    system_reg_write(0x7814, top1);
    system_reg_write(0x7808, (mdns_uv_debug_array << 5) | mdns_y_debug_array);
    return 0;
}
