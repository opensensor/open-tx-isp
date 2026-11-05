/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c7c08[] __asm__("t32_data_c7c08");
extern unsigned char ref_t32_data_c7c28[] __asm__("t32_data_c7c28");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_bef30[] __asm__("t32_data_bef30");
extern unsigned char ref_t32_data_dada8[] __asm__("t32_data_dada8");
extern unsigned char ref___copy_user[] __asm__("__copy_user");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_c7c48[] __asm__("t32_data_c7c48");
extern unsigned char ref_t32_data_dada4[] __asm__("t32_data_dada4");
extern unsigned char ref_t32_data_bef54[] __asm__("t32_data_bef54");
extern unsigned char ref_tisp_top_param_array_get[] __asm__("tisp_top_param_array_get");
extern unsigned char ref_tisp_lsc_param_array_get[] __asm__("tisp_lsc_param_array_get");
extern unsigned char ref_tisp_tmo_param_array_get[] __asm__("tisp_tmo_param_array_get");
extern unsigned char ref_tisp_wdr_param_array_get[] __asm__("tisp_wdr_param_array_get");
extern unsigned char ref_tisp_dpc_param_array_get[] __asm__("tisp_dpc_param_array_get");
extern unsigned char ref_tisp_gib_param_array_get[] __asm__("tisp_gib_param_array_get");
extern unsigned char ref_tisp_dmsc_param_array_get[] __asm__("tisp_dmsc_param_array_get");
extern unsigned char ref_tisp_gamma_param_array_get[] __asm__("tisp_gamma_param_array_get");
extern unsigned char ref_tisp_defog_param_array_get[] __asm__("tisp_defog_param_array_get");
extern unsigned char ref_tisp_lce_param_array_get[] __asm__("tisp_lce_param_array_get");
extern unsigned char ref_tisp_mdns_param_array_get[] __asm__("tisp_mdns_param_array_get");
extern unsigned char ref_tisp_ydns_param_array_get[] __asm__("tisp_ydns_param_array_get");
extern unsigned char ref_tisp_cdns_param_array_get[] __asm__("tisp_cdns_param_array_get");
extern unsigned char ref_tisp_bcsh_param_array_get[] __asm__("tisp_bcsh_param_array_get");
extern unsigned char ref_tisp_ysp_param_array_get[] __asm__("tisp_ysp_param_array_get");
extern unsigned char ref_tisp_sdns_param_array_get[] __asm__("tisp_sdns_param_array_get");
extern unsigned char ref_tisp_af_param_array_get[] __asm__("tisp_af_param_array_get");
extern unsigned char ref_tisp_ldc_param_array_get[] __asm__("tisp_ldc_param_array_get");
extern unsigned char ref_tisp_ae_param_array_get[] __asm__("tisp_ae_param_array_get");
extern unsigned char ref_tisp_clm_param_array_get[] __asm__("tisp_clm_param_array_get");
extern unsigned char ref_tisp_ccm_param_array_get[] __asm__("tisp_ccm_param_array_get");
extern unsigned char ref_tisp_awb_param_array_get[] __asm__("tisp_awb_param_array_get");
extern unsigned char ref_tisp_tstp_param_array_get[] __asm__("tisp_tstp_param_array_get");
extern unsigned char ref_tisp_msca_param_array_get[] __asm__("tisp_msca_param_array_get");
extern unsigned char ref_tisp_reg_map_get[] __asm__("tisp_reg_map_get");
extern unsigned char ref_tisp_comn_param_array_get[] __asm__("tisp_comn_param_array_get");
extern unsigned char ref_tisp_csc_param_array_get[] __asm__("tisp_csc_param_array_get");
extern unsigned char ref_tisp_csccr_param_array_get[] __asm__("tisp_csccr_param_array_get");
extern unsigned char ref_tisp_rdns_param_array_get[] __asm__("tisp_rdns_param_array_get");
extern unsigned char ref_tisp_api_param_array_get[] __asm__("tisp_api_param_array_get");
extern unsigned char ref_tisp_dma_param_array_get[] __asm__("tisp_dma_param_array_get");
extern unsigned char ref_tisp_decmp_param_array_get[] __asm__("tisp_decmp_param_array_get");
extern unsigned char ref_tisp_version_param_array_get[] __asm__("tisp_version_param_array_get");
extern unsigned char ref_t32_data_bf0fc[] __asm__("t32_data_bf0fc");
extern unsigned char ref_t32_data_c7c70[] __asm__("t32_data_c7c70");
extern unsigned char ref_t32_data_bf008[] __asm__("t32_data_bf008");
extern unsigned char ref_tisp_top_param_array_set[] __asm__("tisp_top_param_array_set");
extern unsigned char ref_tisp_lsc_param_array_set[] __asm__("tisp_lsc_param_array_set");
extern unsigned char ref_tisp_tmo_param_array_set[] __asm__("tisp_tmo_param_array_set");
extern unsigned char ref_tisp_wdr_param_array_set[] __asm__("tisp_wdr_param_array_set");
extern unsigned char ref_tisp_dpc_param_array_set[] __asm__("tisp_dpc_param_array_set");
extern unsigned char ref_tisp_gib_param_array_set[] __asm__("tisp_gib_param_array_set");
extern unsigned char ref_tisp_dmsc_param_array_set[] __asm__("tisp_dmsc_param_array_set");
extern unsigned char ref_tisp_gamma_param_array_set[] __asm__("tisp_gamma_param_array_set");
extern unsigned char ref_tisp_defog_param_array_set[] __asm__("tisp_defog_param_array_set");
extern unsigned char ref_tisp_lce_param_array_set[] __asm__("tisp_lce_param_array_set");
extern unsigned char ref_tisp_mdns_param_array_set[] __asm__("tisp_mdns_param_array_set");
extern unsigned char ref_tisp_ydns_param_array_set[] __asm__("tisp_ydns_param_array_set");
extern unsigned char ref_tisp_cdns_param_array_set[] __asm__("tisp_cdns_param_array_set");
extern unsigned char ref_tisp_bcsh_param_array_set[] __asm__("tisp_bcsh_param_array_set");
extern unsigned char ref_tisp_ysp_param_array_set[] __asm__("tisp_ysp_param_array_set");
extern unsigned char ref_tisp_sdns_param_array_set[] __asm__("tisp_sdns_param_array_set");
extern unsigned char ref_tisp_af_param_array_set[] __asm__("tisp_af_param_array_set");
extern unsigned char ref_tisp_ldc_param_array_set[] __asm__("tisp_ldc_param_array_set");
extern unsigned char ref_tisp_clm_param_array_set[] __asm__("tisp_clm_param_array_set");
extern unsigned char ref_tisp_ccm_param_array_set[] __asm__("tisp_ccm_param_array_set");
extern unsigned char ref_tisp_ae_param_array_set[] __asm__("tisp_ae_param_array_set");
extern unsigned char ref_tisp_awb_param_array_set[] __asm__("tisp_awb_param_array_set");
extern unsigned char ref_tisp_tstp_param_array_set[] __asm__("tisp_tstp_param_array_set");
extern unsigned char ref_tisp_msca_param_array_set[] __asm__("tisp_msca_param_array_set");
extern unsigned char ref_tisp_reg_map_set[] __asm__("tisp_reg_map_set");
extern unsigned char ref_t32_data_c7c90[] __asm__("t32_data_c7c90");
extern unsigned char ref_tisp_csc_param_array_set[] __asm__("tisp_csc_param_array_set");
extern unsigned char ref_tisp_csccr_param_array_set[] __asm__("tisp_csccr_param_array_set");
extern unsigned char ref_tisp_rdns_param_array_set[] __asm__("tisp_rdns_param_array_set");
extern unsigned char ref_tisp_api_param_array_set[] __asm__("tisp_api_param_array_set");
extern unsigned char ref_tisp_dma_param_array_set[] __asm__("tisp_dma_param_array_set");
extern unsigned char ref_tisp_decmp_param_array_set[] __asm__("tisp_decmp_param_array_set");
extern unsigned char ref_t32_data_bf0e4[] __asm__("t32_data_bf0e4");
extern unsigned char ref_t32_data_c7ca8[] __asm__("t32_data_c7ca8");
extern unsigned char ref_t32_data_c7cb4[] __asm__("t32_data_c7cb4");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tisp_set_ae_info[] __asm__("tisp_set_ae_info");
extern unsigned char ref_tisp_get_awb_info[] __asm__("tisp_get_awb_info");
extern unsigned char ref_tisp_set_awb_info[] __asm__("tisp_set_awb_info");
extern unsigned char ref_t32_data_bf114[] __asm__("t32_data_bf114");
extern unsigned char ref_t32_data_c7cc4[] __asm__("t32_data_c7cc4");
extern unsigned char ref_tisp_set_ae_minmax[] __asm__("tisp_set_ae_minmax");
u64 tisp_code_tuning_ioctl(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1f134 = ((u32)(unsigned long)ref_t32_data_c7c08 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f154 = ((u32)(unsigned long)ref_t32_data_c7c28 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f15c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_1f188 = ((u32)(unsigned long)ref_t32_data_bef30 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f1a0 = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f1c8 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f1fc = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f210 = ((u32)(unsigned long)ref_t32_data_c7c48 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f214 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_1f1dc = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f234 = ((u32)(unsigned long)ref_t32_data_dada4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f258 = ((u32)(unsigned long)ref_t32_data_bef54 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f278 = ((u32)(unsigned long)ref_tisp_top_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f28c = ((u32)(unsigned long)ref_tisp_lsc_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f2a0 = ((u32)(unsigned long)ref_tisp_tmo_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f2b4 = ((u32)(unsigned long)ref_tisp_wdr_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f2c8 = ((u32)(unsigned long)ref_tisp_dpc_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f2dc = ((u32)(unsigned long)ref_tisp_gib_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f2f0 = ((u32)(unsigned long)ref_tisp_dmsc_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f304 = ((u32)(unsigned long)ref_tisp_gamma_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f318 = ((u32)(unsigned long)ref_tisp_defog_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f32c = ((u32)(unsigned long)ref_tisp_lce_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f344 = ((u32)(unsigned long)ref_tisp_mdns_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f364 = ((u32)(unsigned long)ref_tisp_ydns_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f378 = ((u32)(unsigned long)ref_tisp_cdns_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f38c = ((u32)(unsigned long)ref_tisp_bcsh_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f3a0 = ((u32)(unsigned long)ref_tisp_ysp_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f3b4 = ((u32)(unsigned long)ref_tisp_sdns_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f3c8 = ((u32)(unsigned long)ref_tisp_af_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f3dc = ((u32)(unsigned long)ref_tisp_ldc_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f3f0 = ((u32)(unsigned long)ref_tisp_ae_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f404 = ((u32)(unsigned long)ref_tisp_clm_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f418 = ((u32)(unsigned long)ref_tisp_ccm_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f42c = ((u32)(unsigned long)ref_tisp_awb_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f440 = ((u32)(unsigned long)ref_tisp_tstp_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f460 = ((u32)(unsigned long)ref_tisp_msca_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f478 = ((u32)(unsigned long)ref_tisp_reg_map_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f4a4 = ((u32)(unsigned long)ref_tisp_comn_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f4c4 = ((u32)(unsigned long)ref_tisp_csc_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f4d8 = ((u32)(unsigned long)ref_tisp_csccr_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f4ec = ((u32)(unsigned long)ref_tisp_rdns_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f504 = ((u32)(unsigned long)ref_tisp_api_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f524 = ((u32)(unsigned long)ref_tisp_dma_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f538 = ((u32)(unsigned long)ref_tisp_decmp_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f558 = ((u32)(unsigned long)ref_tisp_version_param_array_get + 0x8000U) & 0xffff0000U;
    const u32 hi_1f578 = ((u32)(unsigned long)ref_t32_data_bf0fc + 0x8000U) & 0xffff0000U;
    const u32 hi_1f574 = ((u32)(unsigned long)ref_t32_data_c7c70 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f57c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_1f5a8 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f5c0 = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f5c8 = ((u32)(unsigned long)ref_t32_data_dada4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f5e8 = ((u32)(unsigned long)ref_t32_data_bf008 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f600 = ((u32)(unsigned long)ref_tisp_top_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f610 = ((u32)(unsigned long)ref_tisp_lsc_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f624 = ((u32)(unsigned long)ref_tisp_tmo_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f634 = ((u32)(unsigned long)ref_tisp_wdr_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f644 = ((u32)(unsigned long)ref_tisp_dpc_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f654 = ((u32)(unsigned long)ref_tisp_gib_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f664 = ((u32)(unsigned long)ref_tisp_dmsc_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f674 = ((u32)(unsigned long)ref_tisp_gamma_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f684 = ((u32)(unsigned long)ref_tisp_defog_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f694 = ((u32)(unsigned long)ref_tisp_lce_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f6ac = ((u32)(unsigned long)ref_tisp_mdns_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f6c4 = ((u32)(unsigned long)ref_tisp_ydns_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f6d4 = ((u32)(unsigned long)ref_tisp_cdns_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f6e4 = ((u32)(unsigned long)ref_tisp_bcsh_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f6f4 = ((u32)(unsigned long)ref_tisp_ysp_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f704 = ((u32)(unsigned long)ref_tisp_sdns_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f714 = ((u32)(unsigned long)ref_tisp_af_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f724 = ((u32)(unsigned long)ref_tisp_ldc_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f734 = ((u32)(unsigned long)ref_tisp_clm_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f744 = ((u32)(unsigned long)ref_tisp_ccm_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f754 = ((u32)(unsigned long)ref_tisp_ae_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f764 = ((u32)(unsigned long)ref_tisp_awb_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f774 = ((u32)(unsigned long)ref_tisp_tstp_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f78c = ((u32)(unsigned long)ref_tisp_msca_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f79c = ((u32)(unsigned long)ref_tisp_reg_map_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f7b4 = ((u32)(unsigned long)ref_t32_data_c7c90 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f7b8 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_1f7cc = ((u32)(unsigned long)ref_tisp_csc_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f7dc = ((u32)(unsigned long)ref_tisp_csccr_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f7ec = ((u32)(unsigned long)ref_tisp_rdns_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f800 = ((u32)(unsigned long)ref_tisp_api_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f818 = ((u32)(unsigned long)ref_tisp_dma_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f828 = ((u32)(unsigned long)ref_tisp_decmp_param_array_set + 0x8000U) & 0xffff0000U;
    const u32 hi_1f84c = ((u32)(unsigned long)ref_t32_data_bf0e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f848 = ((u32)(unsigned long)ref_t32_data_c7c70 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f850 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_1f894 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f87c = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f8b0 = ((u32)(unsigned long)ref_t32_data_c7ca8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f8e4 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f8cc = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f900 = ((u32)(unsigned long)ref_t32_data_c7cb4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f910 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f954 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f974 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1f968 = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f994 = ((u32)(unsigned long)ref_tisp_set_ae_info + 0x8000U) & 0xffff0000U;
    const u32 hi_1f9a0 = ((u32)(unsigned long)ref_tisp_get_awb_info + 0x8000U) & 0xffff0000U;
    const u32 hi_1f9cc = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa08 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa28 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa1c = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa48 = ((u32)(unsigned long)ref_tisp_set_awb_info + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa70 = (((u32)(unsigned long)ref___copy_user + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa90 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1faa8 = ((u32)(unsigned long)ref_t32_data_bf114 + 0x8000U) & 0xffff0000U;
    const u32 hi_1faac = ((u32)(unsigned long)ref_t32_data_c7cc4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1fab0 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_1fa84 = ((u32)(unsigned long)ref_t32_data_dada8 + 0x8000U) & 0xffff0000U;
    const u32 hi_1fad4 = ((u32)(unsigned long)ref_tisp_set_ae_minmax + 0x8000U) & 0xffff0000U;
    const u32 hi_1f1e4 = ((u32)(unsigned long)ref_t32_data_c7c48 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f5bc = ((u32)(unsigned long)ref_t32_data_c7c48 + 0x8000U) & 0xffff0000U;
    const u32 hi_1f9e8 = ((u32)(unsigned long)ref_t32_data_c7c48 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_1f10c:
    sp = sp + -48;
    v1 = (a1 >> 0x8) & ((1U << 0x8) - 1);
    v0 = 116;
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s1;
    branch = (v1 == v0); *(volatile u32 *)(unsigned long)(sp + (28)) = s0;
    if (branch) goto L_1f140;
    goto L_1f130;
L_1f130:
    a2 = a1;
    a1 = hi_1f134;
    a1 = a1 - hi_1f134 + (u32)(unsigned long)ref_t32_data_c7c08; goto L_1f15c;
L_1f140:
    v0 = a1 & 0xff;
    v0 = (u32)v0 < (u32)(51);
    if (v0 != 0) { v0 = 0xdfffU << 16; goto L_1f174; }
    goto L_1f150;
L_1f150:
    a2 = a1;
    a1 = hi_1f154;
    a1 = a1 - hi_1f154 + (u32)(unsigned long)ref_t32_data_c7c28;
L_1f15c:
    v0 = hi_1f15c;
    v0 = v0 - hi_1f15c + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f16c;
L_1f16c:
    v0 = -22; goto L_1fae8;
L_1f174:
    v0 = v0 | 0x8c00;
    a1 = a1 + v0;
    v1 = (u32)a1 < (u32)(9);
    branch = (v1 == 0); v0 = -22;
    if (branch) goto L_1fae8;
    goto L_1f188;
L_1f188:
    v0 = hi_1f188;
    v0 = v0 - hi_1f188 + (u32)(unsigned long)ref_t32_data_bef30;
    a1 = a1 << (0x2 & 31);
    a1 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    s1 = a2;
    s2 = hi_1f1a0;
    callee = v0; s0 = a2 + 20508;
    switch (callee) { case 0x1f10c: goto L_1f10c; case 0x1f1ac: goto L_1f1ac; case 0x1f1e8: goto L_1f1e8; case 0x1f270: goto L_1f270; case 0x1f284: goto L_1f284; case 0x1f298: goto L_1f298; case 0x1f2ac: goto L_1f2ac; case 0x1f2c0: goto L_1f2c0; case 0x1f2d4: goto L_1f2d4; case 0x1f2e8: goto L_1f2e8; case 0x1f2fc: goto L_1f2fc; case 0x1f310: goto L_1f310; case 0x1f324: goto L_1f324; case 0x1f338: goto L_1f338; case 0x1f35c: goto L_1f35c; case 0x1f370: goto L_1f370; case 0x1f384: goto L_1f384; case 0x1f398: goto L_1f398; case 0x1f3ac: goto L_1f3ac; case 0x1f3c0: goto L_1f3c0; case 0x1f3d4: goto L_1f3d4; case 0x1f3e8: goto L_1f3e8; case 0x1f3fc: goto L_1f3fc; case 0x1f410: goto L_1f410; case 0x1f424: goto L_1f424; case 0x1f438: goto L_1f438; case 0x1f458: goto L_1f458; case 0x1f46c: goto L_1f46c; case 0x1f490: goto L_1f490; case 0x1f49c: goto L_1f49c; case 0x1f4bc: goto L_1f4bc; case 0x1f4d0: goto L_1f4d0; case 0x1f4e4: goto L_1f4e4; case 0x1f4f8: goto L_1f4f8; case 0x1f51c: goto L_1f51c; case 0x1f530: goto L_1f530; case 0x1f550: goto L_1f550; case 0x1f570: goto L_1f570; case 0x1f598: goto L_1f598; case 0x1f600: goto L_1f600; case 0x1f610: goto L_1f610; case 0x1f624: goto L_1f624; case 0x1f634: goto L_1f634; case 0x1f644: goto L_1f644; case 0x1f654: goto L_1f654; case 0x1f664: goto L_1f664; case 0x1f674: goto L_1f674; case 0x1f684: goto L_1f684; case 0x1f694: goto L_1f694; case 0x1f6a4: goto L_1f6a4; case 0x1f6c4: goto L_1f6c4; case 0x1f6d4: goto L_1f6d4; case 0x1f6e4: goto L_1f6e4; case 0x1f6f4: goto L_1f6f4; case 0x1f704: goto L_1f704; case 0x1f714: goto L_1f714; case 0x1f724: goto L_1f724; case 0x1f734: goto L_1f734; case 0x1f744: goto L_1f744; case 0x1f754: goto L_1f754; case 0x1f764: goto L_1f764; case 0x1f774: goto L_1f774; case 0x1f78c: goto L_1f78c; case 0x1f79c: goto L_1f79c; case 0x1f7b4: goto L_1f7b4; case 0x1f7cc: goto L_1f7cc; case 0x1f7dc: goto L_1f7dc; case 0x1f7ec: goto L_1f7ec; case 0x1f7fc: goto L_1f7fc; case 0x1f818: goto L_1f818; case 0x1f828: goto L_1f828; case 0x1f844: goto L_1f844; case 0x1f874: goto L_1f874; case 0x1f8c4: goto L_1f8c4; case 0x1f928: goto L_1f928; case 0x1f938: goto L_1f938; case 0x1f9a0: goto L_1f9a0; case 0x1f9ec: goto L_1f9ec; case 0x1fa54: goto L_1fa54; case 0x1fae4: goto L_1fae4; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_1f1ac:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    v0 = s0 & v0;
    branch = (v0 != 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f1fc;
    goto L_1f1c0;
L_1f1c0:
    a1 = a2;
    a2 = 20508;
    at = hi_1f1c8;
    at = at - hi_1f1c8 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f1d8;
L_1f1d8:
    if (a2 == 0) { v0 = hi_1f1dc; goto L_1f230; }
    goto L_1f1e0;
L_1f1e0:
    a1 = hi_1f1e4; goto L_1f214;
L_1f1e8:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    s0 = s0 & v0;
    branch = (s0 == 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f5a0;
    goto L_1f1fc;
L_1f1fc:
    v0 = hi_1f1fc;
    a2 = 20508;
    v0 = v0 - hi_1f1fc + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f210;
L_1f210:
    a1 = hi_1f210;
L_1f214:
    v0 = hi_1f214;
    a1 = a1 - hi_1f210 + (u32)(unsigned long)ref_t32_data_c7c48;
    v0 = v0 - hi_1f214 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f228;
L_1f228:
    v0 = -14; goto L_1fae8;
L_1f230:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_1f1dc + (u32)(unsigned long)ref_t32_data_dada8);
    v1 = hi_1f234;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (26));
    *(volatile u8 *)(unsigned long)(v1 - hi_1f234 + (u32)(unsigned long)ref_t32_data_dada4) = a0;
    v1 = a2 + -1;
    a1 = (u32)v1 < (u32)(45);
    if (a1 == 0) { *(volatile u32 *)(unsigned long)(sp + (16)) = a2; goto L_1f574; }
    goto L_1f254;
L_1f254:
    a1 = v1 << (0x2 & 31);
    v1 = hi_1f258;
    v1 = v1 - hi_1f258 + (u32)(unsigned long)ref_t32_data_bef54;
    v1 = v1 + a1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    callee = v1; ;
    switch (callee) { case 0x1f10c: goto L_1f10c; case 0x1f1ac: goto L_1f1ac; case 0x1f1e8: goto L_1f1e8; case 0x1f270: goto L_1f270; case 0x1f284: goto L_1f284; case 0x1f298: goto L_1f298; case 0x1f2ac: goto L_1f2ac; case 0x1f2c0: goto L_1f2c0; case 0x1f2d4: goto L_1f2d4; case 0x1f2e8: goto L_1f2e8; case 0x1f2fc: goto L_1f2fc; case 0x1f310: goto L_1f310; case 0x1f324: goto L_1f324; case 0x1f338: goto L_1f338; case 0x1f35c: goto L_1f35c; case 0x1f370: goto L_1f370; case 0x1f384: goto L_1f384; case 0x1f398: goto L_1f398; case 0x1f3ac: goto L_1f3ac; case 0x1f3c0: goto L_1f3c0; case 0x1f3d4: goto L_1f3d4; case 0x1f3e8: goto L_1f3e8; case 0x1f3fc: goto L_1f3fc; case 0x1f410: goto L_1f410; case 0x1f424: goto L_1f424; case 0x1f438: goto L_1f438; case 0x1f458: goto L_1f458; case 0x1f46c: goto L_1f46c; case 0x1f490: goto L_1f490; case 0x1f49c: goto L_1f49c; case 0x1f4bc: goto L_1f4bc; case 0x1f4d0: goto L_1f4d0; case 0x1f4e4: goto L_1f4e4; case 0x1f4f8: goto L_1f4f8; case 0x1f51c: goto L_1f51c; case 0x1f530: goto L_1f530; case 0x1f550: goto L_1f550; case 0x1f570: goto L_1f570; case 0x1f598: goto L_1f598; case 0x1f600: goto L_1f600; case 0x1f610: goto L_1f610; case 0x1f624: goto L_1f624; case 0x1f634: goto L_1f634; case 0x1f644: goto L_1f644; case 0x1f654: goto L_1f654; case 0x1f664: goto L_1f664; case 0x1f674: goto L_1f674; case 0x1f684: goto L_1f684; case 0x1f694: goto L_1f694; case 0x1f6a4: goto L_1f6a4; case 0x1f6c4: goto L_1f6c4; case 0x1f6d4: goto L_1f6d4; case 0x1f6e4: goto L_1f6e4; case 0x1f6f4: goto L_1f6f4; case 0x1f704: goto L_1f704; case 0x1f714: goto L_1f714; case 0x1f724: goto L_1f724; case 0x1f734: goto L_1f734; case 0x1f744: goto L_1f744; case 0x1f754: goto L_1f754; case 0x1f764: goto L_1f764; case 0x1f774: goto L_1f774; case 0x1f78c: goto L_1f78c; case 0x1f79c: goto L_1f79c; case 0x1f7b4: goto L_1f7b4; case 0x1f7cc: goto L_1f7cc; case 0x1f7dc: goto L_1f7dc; case 0x1f7ec: goto L_1f7ec; case 0x1f7fc: goto L_1f7fc; case 0x1f818: goto L_1f818; case 0x1f828: goto L_1f828; case 0x1f844: goto L_1f844; case 0x1f874: goto L_1f874; case 0x1f8c4: goto L_1f8c4; case 0x1f928: goto L_1f928; case 0x1f938: goto L_1f938; case 0x1f9a0: goto L_1f9a0; case 0x1f9ec: goto L_1f9ec; case 0x1fa54: goto L_1fa54; case 0x1fae4: goto L_1fae4; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_1f270:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f278;
    v0 = v0 - hi_1f278 + (u32)(unsigned long)ref_tisp_top_param_array_get; goto L_1f540;
L_1f284:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f28c;
    v0 = v0 - hi_1f28c + (u32)(unsigned long)ref_tisp_lsc_param_array_get; goto L_1f540;
L_1f298:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f2a0;
    v0 = v0 - hi_1f2a0 + (u32)(unsigned long)ref_tisp_tmo_param_array_get; goto L_1f540;
L_1f2ac:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f2b4;
    v0 = v0 - hi_1f2b4 + (u32)(unsigned long)ref_tisp_wdr_param_array_get; goto L_1f540;
L_1f2c0:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f2c8;
    v0 = v0 - hi_1f2c8 + (u32)(unsigned long)ref_tisp_dpc_param_array_get; goto L_1f540;
L_1f2d4:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f2dc;
    v0 = v0 - hi_1f2dc + (u32)(unsigned long)ref_tisp_gib_param_array_get; goto L_1f540;
L_1f2e8:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f2f0;
    v0 = v0 - hi_1f2f0 + (u32)(unsigned long)ref_tisp_dmsc_param_array_get; goto L_1f540;
L_1f2fc:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f304;
    v0 = v0 - hi_1f304 + (u32)(unsigned long)ref_tisp_gamma_param_array_get; goto L_1f540;
L_1f310:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f318;
    v0 = v0 - hi_1f318 + (u32)(unsigned long)ref_tisp_defog_param_array_get; goto L_1f540;
L_1f324:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f32c;
    v0 = v0 - hi_1f32c + (u32)(unsigned long)ref_tisp_lce_param_array_get; goto L_1f540;
L_1f338:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a3 = v0 + 4;
    a2 = v0 + 27;
    v0 = hi_1f344;
    v0 = v0 - hi_1f344 + (u32)(unsigned long)ref_tisp_mdns_param_array_get;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f354;
L_1f354:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f35c:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f364;
    v0 = v0 - hi_1f364 + (u32)(unsigned long)ref_tisp_ydns_param_array_get; goto L_1f540;
L_1f370:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f378;
    v0 = v0 - hi_1f378 + (u32)(unsigned long)ref_tisp_cdns_param_array_get; goto L_1f540;
L_1f384:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f38c;
    v0 = v0 - hi_1f38c + (u32)(unsigned long)ref_tisp_bcsh_param_array_get; goto L_1f540;
L_1f398:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f3a0;
    v0 = v0 - hi_1f3a0 + (u32)(unsigned long)ref_tisp_ysp_param_array_get; goto L_1f540;
L_1f3ac:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f3b4;
    v0 = v0 - hi_1f3b4 + (u32)(unsigned long)ref_tisp_sdns_param_array_get; goto L_1f540;
L_1f3c0:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f3c8;
    v0 = v0 - hi_1f3c8 + (u32)(unsigned long)ref_tisp_af_param_array_get; goto L_1f540;
L_1f3d4:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f3dc;
    v0 = v0 - hi_1f3dc + (u32)(unsigned long)ref_tisp_ldc_param_array_get; goto L_1f540;
L_1f3e8:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f3f0;
    v0 = v0 - hi_1f3f0 + (u32)(unsigned long)ref_tisp_ae_param_array_get; goto L_1f540;
L_1f3fc:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f404;
    v0 = v0 - hi_1f404 + (u32)(unsigned long)ref_tisp_clm_param_array_get; goto L_1f540;
L_1f410:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f418;
    v0 = v0 - hi_1f418 + (u32)(unsigned long)ref_tisp_ccm_param_array_get; goto L_1f540;
L_1f424:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f42c;
    v0 = v0 - hi_1f42c + (u32)(unsigned long)ref_tisp_awb_param_array_get; goto L_1f540;
L_1f438:
    a1 = v0 + 4;
    a0 = v0 + 27;
    v0 = hi_1f440;
    v0 = v0 - hi_1f440 + (u32)(unsigned long)ref_tisp_tstp_param_array_get;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f450;
L_1f450:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f458:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f460;
    v0 = v0 - hi_1f460 + (u32)(unsigned long)ref_tisp_msca_param_array_get; goto L_1f540;
L_1f46c:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a3 = v0 + 4;
    a2 = v0;
    v0 = hi_1f478;
    v0 = v0 - hi_1f478 + (u32)(unsigned long)ref_tisp_reg_map_get;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f488;
L_1f488:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f490:
    v1 = 4;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1; goto L_1f598;
L_1f49c:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f4a4;
    v0 = v0 - hi_1f4a4 + (u32)(unsigned long)ref_tisp_comn_param_array_get;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f4b4;
L_1f4b4:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f4bc:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f4c4;
    v0 = v0 - hi_1f4c4 + (u32)(unsigned long)ref_tisp_csc_param_array_get; goto L_1f540;
L_1f4d0:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f4d8;
    v0 = v0 - hi_1f4d8 + (u32)(unsigned long)ref_tisp_csccr_param_array_get; goto L_1f540;
L_1f4e4:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f4ec;
    v0 = v0 - hi_1f4ec + (u32)(unsigned long)ref_tisp_rdns_param_array_get; goto L_1f540;
L_1f4f8:
    a3 = *(volatile u16 *)(unsigned long)(v0 + (8));
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f504;
    v0 = v0 - hi_1f504 + (u32)(unsigned long)ref_tisp_api_param_array_get;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f514;
L_1f514:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f51c:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f524;
    v0 = v0 - hi_1f524 + (u32)(unsigned long)ref_tisp_dma_param_array_get; goto L_1f540;
L_1f530:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f538;
    v0 = v0 - hi_1f538 + (u32)(unsigned long)ref_tisp_decmp_param_array_get;
L_1f540:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f548;
L_1f548:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f550:
    a2 = v0 + 4;
    a1 = v0 + 27;
    v0 = hi_1f558;
    v0 = v0 - hi_1f558 + (u32)(unsigned long)ref_tisp_version_param_array_get;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f568;
L_1f568:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f570:
    *(volatile u32 *)(unsigned long)(sp + (16)) = a2;
L_1f574:
    a1 = hi_1f574;
    a2 = hi_1f578;
    v0 = hi_1f57c;
    a3 = 404;
    a2 = a2 - hi_1f578 + (u32)(unsigned long)ref_t32_data_bf0fc;
    a1 = a1 - hi_1f574 + (u32)(unsigned long)ref_t32_data_c7c70;
    v0 = v0 - hi_1f57c + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f598;
L_1f598:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f5a0:
    a1 = a2;
    a2 = 20508;
    at = hi_1f5a8;
    at = at - hi_1f5a8 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f5b8;
L_1f5b8:
    branch = (a2 != 0); a1 = hi_1f5bc;
    if (branch) goto L_1f214;
    goto L_1f5c0;
L_1f5c0:
    v0 = hi_1f5c0;
    a1 = *(volatile u32 *)(unsigned long)(v0 - hi_1f5c0 + (u32)(unsigned long)ref_t32_data_dada8);
    v0 = hi_1f5c8;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a1 + (26));
    *(volatile u8 *)(unsigned long)(v0 - hi_1f5c8 + (u32)(unsigned long)ref_t32_data_dada4) = a0;
    v0 = a2 + -1;
    v1 = (u32)v0 < (u32)(44);
    branch = (v1 == 0); v1 = v0 << (0x2 & 31);
    if (branch) goto L_1f844;
    goto L_1f5e8;
L_1f5e8:
    v0 = hi_1f5e8;
    v0 = v0 - hi_1f5e8 + (u32)(unsigned long)ref_t32_data_bf008;
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    callee = v0; ;
    switch (callee) { case 0x1f10c: goto L_1f10c; case 0x1f1ac: goto L_1f1ac; case 0x1f1e8: goto L_1f1e8; case 0x1f270: goto L_1f270; case 0x1f284: goto L_1f284; case 0x1f298: goto L_1f298; case 0x1f2ac: goto L_1f2ac; case 0x1f2c0: goto L_1f2c0; case 0x1f2d4: goto L_1f2d4; case 0x1f2e8: goto L_1f2e8; case 0x1f2fc: goto L_1f2fc; case 0x1f310: goto L_1f310; case 0x1f324: goto L_1f324; case 0x1f338: goto L_1f338; case 0x1f35c: goto L_1f35c; case 0x1f370: goto L_1f370; case 0x1f384: goto L_1f384; case 0x1f398: goto L_1f398; case 0x1f3ac: goto L_1f3ac; case 0x1f3c0: goto L_1f3c0; case 0x1f3d4: goto L_1f3d4; case 0x1f3e8: goto L_1f3e8; case 0x1f3fc: goto L_1f3fc; case 0x1f410: goto L_1f410; case 0x1f424: goto L_1f424; case 0x1f438: goto L_1f438; case 0x1f458: goto L_1f458; case 0x1f46c: goto L_1f46c; case 0x1f490: goto L_1f490; case 0x1f49c: goto L_1f49c; case 0x1f4bc: goto L_1f4bc; case 0x1f4d0: goto L_1f4d0; case 0x1f4e4: goto L_1f4e4; case 0x1f4f8: goto L_1f4f8; case 0x1f51c: goto L_1f51c; case 0x1f530: goto L_1f530; case 0x1f550: goto L_1f550; case 0x1f570: goto L_1f570; case 0x1f598: goto L_1f598; case 0x1f600: goto L_1f600; case 0x1f610: goto L_1f610; case 0x1f624: goto L_1f624; case 0x1f634: goto L_1f634; case 0x1f644: goto L_1f644; case 0x1f654: goto L_1f654; case 0x1f664: goto L_1f664; case 0x1f674: goto L_1f674; case 0x1f684: goto L_1f684; case 0x1f694: goto L_1f694; case 0x1f6a4: goto L_1f6a4; case 0x1f6c4: goto L_1f6c4; case 0x1f6d4: goto L_1f6d4; case 0x1f6e4: goto L_1f6e4; case 0x1f6f4: goto L_1f6f4; case 0x1f704: goto L_1f704; case 0x1f714: goto L_1f714; case 0x1f724: goto L_1f724; case 0x1f734: goto L_1f734; case 0x1f744: goto L_1f744; case 0x1f754: goto L_1f754; case 0x1f764: goto L_1f764; case 0x1f774: goto L_1f774; case 0x1f78c: goto L_1f78c; case 0x1f79c: goto L_1f79c; case 0x1f7b4: goto L_1f7b4; case 0x1f7cc: goto L_1f7cc; case 0x1f7dc: goto L_1f7dc; case 0x1f7ec: goto L_1f7ec; case 0x1f7fc: goto L_1f7fc; case 0x1f818: goto L_1f818; case 0x1f828: goto L_1f828; case 0x1f844: goto L_1f844; case 0x1f874: goto L_1f874; case 0x1f8c4: goto L_1f8c4; case 0x1f928: goto L_1f928; case 0x1f938: goto L_1f938; case 0x1f9a0: goto L_1f9a0; case 0x1f9ec: goto L_1f9ec; case 0x1fa54: goto L_1fa54; case 0x1fae4: goto L_1fae4; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_1f600:
    v0 = hi_1f600;
    a1 = a1 + 27;
    v0 = v0 - hi_1f600 + (u32)(unsigned long)ref_tisp_top_param_array_set; goto L_1f834;
L_1f610:
    v0 = hi_1f610;
    a2 = a1 + 27;
    v0 = v0 - hi_1f610 + (u32)(unsigned long)ref_tisp_lsc_param_array_set;
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8)); goto L_1f6b4;
L_1f624:
    v0 = hi_1f624;
    a1 = a1 + 27;
    v0 = v0 - hi_1f624 + (u32)(unsigned long)ref_tisp_tmo_param_array_set; goto L_1f834;
L_1f634:
    v0 = hi_1f634;
    a1 = a1 + 27;
    v0 = v0 - hi_1f634 + (u32)(unsigned long)ref_tisp_wdr_param_array_set; goto L_1f834;
L_1f644:
    v0 = hi_1f644;
    a1 = a1 + 27;
    v0 = v0 - hi_1f644 + (u32)(unsigned long)ref_tisp_dpc_param_array_set; goto L_1f834;
L_1f654:
    v0 = hi_1f654;
    a1 = a1 + 27;
    v0 = v0 - hi_1f654 + (u32)(unsigned long)ref_tisp_gib_param_array_set; goto L_1f834;
L_1f664:
    v0 = hi_1f664;
    a1 = a1 + 27;
    v0 = v0 - hi_1f664 + (u32)(unsigned long)ref_tisp_dmsc_param_array_set; goto L_1f834;
L_1f674:
    v0 = hi_1f674;
    a1 = a1 + 27;
    v0 = v0 - hi_1f674 + (u32)(unsigned long)ref_tisp_gamma_param_array_set; goto L_1f834;
L_1f684:
    v0 = hi_1f684;
    a1 = a1 + 27;
    v0 = v0 - hi_1f684 + (u32)(unsigned long)ref_tisp_defog_param_array_set; goto L_1f834;
L_1f694:
    v0 = hi_1f694;
    a1 = a1 + 27;
    v0 = v0 - hi_1f694 + (u32)(unsigned long)ref_tisp_lce_param_array_set; goto L_1f834;
L_1f6a4:
    a2 = a1 + 27;
    a1 = *(volatile u32 *)(unsigned long)(a1 + (8));
    v0 = hi_1f6ac;
    v0 = v0 - hi_1f6ac + (u32)(unsigned long)ref_tisp_mdns_param_array_set;
L_1f6b4:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f6bc;
L_1f6bc:
    v0 = 0; goto L_1fae8;
L_1f6c4:
    v0 = hi_1f6c4;
    a1 = a1 + 27;
    v0 = v0 - hi_1f6c4 + (u32)(unsigned long)ref_tisp_ydns_param_array_set; goto L_1f834;
L_1f6d4:
    v0 = hi_1f6d4;
    a1 = a1 + 27;
    v0 = v0 - hi_1f6d4 + (u32)(unsigned long)ref_tisp_cdns_param_array_set; goto L_1f834;
L_1f6e4:
    v0 = hi_1f6e4;
    a1 = a1 + 27;
    v0 = v0 - hi_1f6e4 + (u32)(unsigned long)ref_tisp_bcsh_param_array_set; goto L_1f834;
L_1f6f4:
    v0 = hi_1f6f4;
    a1 = a1 + 27;
    v0 = v0 - hi_1f6f4 + (u32)(unsigned long)ref_tisp_ysp_param_array_set; goto L_1f834;
L_1f704:
    v0 = hi_1f704;
    a1 = a1 + 27;
    v0 = v0 - hi_1f704 + (u32)(unsigned long)ref_tisp_sdns_param_array_set; goto L_1f834;
L_1f714:
    v0 = hi_1f714;
    a1 = a1 + 27;
    v0 = v0 - hi_1f714 + (u32)(unsigned long)ref_tisp_af_param_array_set; goto L_1f834;
L_1f724:
    v0 = hi_1f724;
    a1 = a1 + 27;
    v0 = v0 - hi_1f724 + (u32)(unsigned long)ref_tisp_ldc_param_array_set; goto L_1f834;
L_1f734:
    v0 = hi_1f734;
    a1 = a1 + 27;
    v0 = v0 - hi_1f734 + (u32)(unsigned long)ref_tisp_clm_param_array_set; goto L_1f834;
L_1f744:
    v0 = hi_1f744;
    a1 = a1 + 27;
    v0 = v0 - hi_1f744 + (u32)(unsigned long)ref_tisp_ccm_param_array_set; goto L_1f834;
L_1f754:
    v0 = hi_1f754;
    a1 = a1 + 27;
    v0 = v0 - hi_1f754 + (u32)(unsigned long)ref_tisp_ae_param_array_set; goto L_1f834;
L_1f764:
    v0 = hi_1f764;
    a1 = a1 + 27;
    v0 = v0 - hi_1f764 + (u32)(unsigned long)ref_tisp_awb_param_array_set; goto L_1f834;
L_1f774:
    v0 = hi_1f774;
    v0 = v0 - hi_1f774 + (u32)(unsigned long)ref_tisp_tstp_param_array_set;
    callee = v0; a0 = a1 + 27;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f784;
L_1f784:
    v0 = 0; goto L_1fae8;
L_1f78c:
    v0 = hi_1f78c;
    a1 = a1 + 27;
    v0 = v0 - hi_1f78c + (u32)(unsigned long)ref_tisp_msca_param_array_set; goto L_1f834;
L_1f79c:
    v0 = hi_1f79c;
    v0 = v0 - hi_1f79c + (u32)(unsigned long)ref_tisp_reg_map_set;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f7ac;
L_1f7ac:
    v0 = 0; goto L_1fae8;
L_1f7b4:
    a1 = hi_1f7b4;
    v0 = hi_1f7b8;
    a1 = a1 - hi_1f7b4 + (u32)(unsigned long)ref_t32_data_c7c90;
    a0 = 0;
    v0 = v0 - hi_1f7b8 + (u32)(unsigned long)ref_isp_printf; goto L_1f834;
L_1f7cc:
    v0 = hi_1f7cc;
    a1 = a1 + 27;
    v0 = v0 - hi_1f7cc + (u32)(unsigned long)ref_tisp_csc_param_array_set; goto L_1f834;
L_1f7dc:
    v0 = hi_1f7dc;
    a1 = a1 + 27;
    v0 = v0 - hi_1f7dc + (u32)(unsigned long)ref_tisp_csccr_param_array_set; goto L_1f834;
L_1f7ec:
    v0 = hi_1f7ec;
    a1 = a1 + 27;
    v0 = v0 - hi_1f7ec + (u32)(unsigned long)ref_tisp_rdns_param_array_set; goto L_1f834;
L_1f7fc:
    a2 = *(volatile u16 *)(unsigned long)(a1 + (8));
    v0 = hi_1f800;
    v0 = v0 - hi_1f800 + (u32)(unsigned long)ref_tisp_api_param_array_set;
    callee = v0; a1 = a1 + 27;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f810;
L_1f810:
    v0 = 0; goto L_1fae8;
L_1f818:
    v0 = hi_1f818;
    a1 = a1 + 27;
    v0 = v0 - hi_1f818 + (u32)(unsigned long)ref_tisp_dma_param_array_set; goto L_1f834;
L_1f828:
    v0 = hi_1f828;
    a1 = a1 + 27;
    v0 = v0 - hi_1f828 + (u32)(unsigned long)ref_tisp_decmp_param_array_set;
L_1f834:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f83c;
L_1f83c:
    v0 = 0; goto L_1fae8;
L_1f844:
    *(volatile u32 *)(unsigned long)(sp + (16)) = a2;
    a1 = hi_1f848;
    a2 = hi_1f84c;
    v0 = hi_1f850;
    a3 = 522;
    a2 = a2 - hi_1f84c + (u32)(unsigned long)ref_t32_data_bf0e4;
    a1 = a1 - hi_1f848 + (u32)(unsigned long)ref_t32_data_c7c70;
    v0 = v0 - hi_1f850 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f86c;
L_1f86c:
    v0 = 0; goto L_1fae8;
L_1f874:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    s3 = hi_1f87c;
    v0 = s0 & v0;
    branch = (v0 != 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f1fc;
    goto L_1f88c;
L_1f88c:
    a1 = a2;
    a2 = 20508;
    at = hi_1f894;
    at = at - hi_1f894 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f8a4;
L_1f8a4:
    branch = (a2 != 0); a0 = *(volatile u32 *)(unsigned long)(s3 - hi_1f87c + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f210;
    goto L_1f8ac;
L_1f8ac:
    v0 = 11;
    a1 = hi_1f8b0;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v0;
    a2 = 11;
    a1 = a1 - hi_1f8b0 + (u32)(unsigned long)ref_t32_data_c7ca8; goto L_1f910;
L_1f8c4:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    s3 = hi_1f8cc;
    v0 = s0 & v0;
    branch = (v0 != 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f1fc;
    goto L_1f8dc;
L_1f8dc:
    a1 = a2;
    a2 = 20508;
    at = hi_1f8e4;
    at = at - hi_1f8e4 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f8f4;
L_1f8f4:
    branch = (a2 != 0); a0 = *(volatile u32 *)(unsigned long)(s3 - hi_1f8cc + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f210;
    goto L_1f8fc;
L_1f8fc:
    v0 = 15;
    a1 = hi_1f900;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v0;
    a2 = 15;
    a1 = a1 - hi_1f900 + (u32)(unsigned long)ref_t32_data_c7cb4;
L_1f910:
    v0 = hi_1f910;
    v0 = v0 - hi_1f910 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = a0 + 27;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f920;
L_1f920:
    a1 = *(volatile u32 *)(unsigned long)(s3 - hi_1f8cc + (u32)(unsigned long)ref_t32_data_dada8); goto L_1f9b8;
L_1f928:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    v0 = 164;
    *(volatile u32 *)(unsigned long)(a1 + (4)) = v0; goto L_1f9b4;
L_1f938:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    s0 = s0 & v0;
    branch = (s0 != 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1f974;
    goto L_1f94c;
L_1f94c:
    a1 = a2;
    a2 = 20508;
    at = hi_1f954;
    at = at - hi_1f954 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f964;
L_1f964:
    if (a2 == 0) { v0 = hi_1f968; goto L_1f990; }
    goto L_1f96c;
L_1f96c:
    a3 = 617; goto L_1faa8;
L_1f974:
    v0 = hi_1f974;
    a2 = 20508;
    v0 = v0 - hi_1f974 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f988;
L_1f988:
    a3 = 617; goto L_1faa8;
L_1f990:
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_1f968 + (u32)(unsigned long)ref_t32_data_dada8);
    v0 = hi_1f994;
    v0 = v0 - hi_1f994 + (u32)(unsigned long)ref_tisp_set_ae_info; goto L_1fadc;
L_1f9a0:
    v0 = hi_1f9a0;
    v0 = v0 - hi_1f9a0 + (u32)(unsigned long)ref_tisp_get_awb_info;
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f9b0;
L_1f9b0:
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
L_1f9b4:
    s0 = s0 | s1;
L_1f9b8:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 & v0;
    branch = (s0 != 0); a0 = s1;
    if (branch) goto L_1f210;
    goto L_1f9c8;
L_1f9c8:
    a2 = 20508;
    at = hi_1f9cc;
    at = at - hi_1f9cc + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1f9dc;
L_1f9dc:
    if (a2 == 0) { v0 = 0; goto L_1fae8; }
    goto L_1f9e4;
L_1f9e4:
    a1 = hi_1f9e8; goto L_1f214;
L_1f9ec:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    s0 = s0 & v0;
    branch = (s0 != 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1fa28;
    goto L_1fa00;
L_1fa00:
    a1 = a2;
    a2 = 20508;
    at = hi_1fa08;
    at = at - hi_1fa08 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1fa18;
L_1fa18:
    if (a2 == 0) { v0 = hi_1fa1c; goto L_1fa44; }
    goto L_1fa20;
L_1fa20:
    a3 = 631; goto L_1faa8;
L_1fa28:
    v0 = hi_1fa28;
    a2 = 20508;
    v0 = v0 - hi_1fa28 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1fa3c;
L_1fa3c:
    a3 = 631; goto L_1faa8;
L_1fa44:
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_1fa1c + (u32)(unsigned long)ref_t32_data_dada8);
    v0 = hi_1fa48;
    v0 = v0 - hi_1fa48 + (u32)(unsigned long)ref_tisp_set_awb_info; goto L_1fadc;
L_1fa54:
    v0 = *(volatile u32 *)(unsigned long)(gp + (24));
    s0 = s0 | a2;
    s0 = s0 & v0;
    branch = (s0 != 0); a0 = *(volatile u32 *)(unsigned long)(s2 - hi_1f1a0 + (u32)(unsigned long)ref_t32_data_dada8);
    if (branch) goto L_1fa90;
    goto L_1fa68;
L_1fa68:
    a1 = a2;
    a2 = 20508;
    at = hi_1fa70;
    at = at - hi_1fa70 + ((u32)(unsigned long)ref___copy_user + (0));
    callee = at; at = a1 + a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1fa80;
L_1fa80:
    if (a2 == 0) { v0 = hi_1fa84; goto L_1fad0; }
    goto L_1fa88;
L_1fa88:
    a3 = 638; goto L_1faa8;
L_1fa90:
    v0 = hi_1fa90;
    a2 = 20508;
    v0 = v0 - hi_1fa90 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1faa4;
L_1faa4:
    a3 = 638;
L_1faa8:
    a2 = hi_1faa8;
    a1 = hi_1faac;
    v0 = hi_1fab0;
    a2 = a2 - hi_1faa8 + (u32)(unsigned long)ref_t32_data_bf114;
    a1 = a1 - hi_1faac + (u32)(unsigned long)ref_t32_data_c7cc4;
    v0 = v0 - hi_1fab0 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1fac8;
L_1fac8:
    v0 = -14; goto L_1fae8;
L_1fad0:
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_1fa84 + (u32)(unsigned long)ref_t32_data_dada8);
    v0 = hi_1fad4;
    v0 = v0 - hi_1fad4 + (u32)(unsigned long)ref_tisp_set_ae_minmax;
L_1fadc:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1fae4;
L_1fae4:
    v0 = 0;
L_1fae8:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s3 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (36));
    s1 = *(volatile u32 *)(unsigned long)(sp + (32));
    s0 = *(volatile u32 *)(unsigned long)(sp + (28));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
