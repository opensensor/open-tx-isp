CC ?= cc
.DEFAULT_GOAL := all
CFLAGS ?= -O2
CFLAGS += -std=c99 -Wall -Wextra -Werror

.PHONY: all check check-oracles clean t40_vic_layout_check t40_lost_tail_host lifted_ptr_scale_check t40_hardcoded_anchor_check t30_storage_audit t30_fw_irq_gate t30_fmt5c_check t30_tuning_ctl_check t30_callarg_check t40_af_stats_host t40_bcsh_dn_host t40_tstp_host t40_ccm_conv_host t40_ccm_chain_host t40_ct_chain_host t40_dmsc_chain_host t40_mdns_chain_host t40_ysp_chain_host t40_ydns_host t40_gib_host t40_lsc_host t40_blc_host t40_clm_host t40_ae_leaf_host t40_bitexact_host t40_callarg_check t41_sensor_barrier_check t40_hardcoded_anchor_check t40_clk_teardown_check t40_tstp_init_check t40_custom_algo_wake_check t41_custom_ae_check t41_custom_awb_check t41_awb_algo_host t41_af_gate_check lifted_ptr_scale_check t40_algo_handle_host t40_wdr_log2_host t23_bypass_host

# Every host test binary.  A new test is registered with "TESTS += name"
# (plus its build rule); `check` builds and runs all of them, keeps going
# past failures and fails at the end if anything failed.  `check` also
# fails for a tests/*_test.c that is neither in TESTS nor in TARGET_TESTS,
# so a test cannot be added and then silently never run.
TESTS :=
# Further check steps, run as "$(MAKE) <target>" after the binaries.
CHECK_TARGETS := t40_vic_layout_check t30_storage_audit t30_fw_irq_gate t30_fmt5c_check t30_tuning_ctl_check t30_callarg_check t41_dfg_host t40_af_stats_host t40_bcsh_dn_host t40_tstp_host t40_ccm_conv_host t40_ccm_chain_host t40_ct_chain_host t40_dmsc_chain_host t40_mdns_chain_host t40_ysp_chain_host t40_ydns_host t40_gib_host t40_lsc_host t40_blc_host t40_clm_host t40_ae_leaf_host t40_bitexact_host t40_callarg_check t41_sensor_barrier_check t40_hardcoded_anchor_check t40_clk_teardown_check t40_tstp_init_check t40_custom_algo_wake_check t41_custom_ae_check t41_custom_awb_check t41_awb_algo_host t41_af_gate_check lifted_ptr_scale_check t40_lost_tail_host t40_algo_handle_host t40_wdr_log2_host t23_bypass_host
# Sources that only run on the camera (not built on the host).
TARGET_TESTS := $(basename $(wildcard t41_v4l2_*_test.c)) t41_antiflicker_ioctl_test
TEST_TIMEOUT ?= 600

TESTS += tx_isp_t41_ysp_test
TESTS += tx_isp_t41_switchbin_test
TESTS += tx_isp_t41_tuning_open_test
TESTS += tx_isp_t41_devioctl_test
TESTS += tx_isp_t41_vic_bypass_test

tx_isp_t41_vic_bypass_test: tx_isp_t41_vic_bypass_test.c ../driver/t41/tx_isp_t41_vic_bypass.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_devioctl_test: tx_isp_t41_devioctl_test.c ../driver/t41/tx_isp_t41_devioctl.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_tuning_open_test: tx_isp_t41_tuning_open_test.c ../driver/t41/tx_isp_t41_tuning_open.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_switchbin_test: tx_isp_t41_switchbin_test.c ../driver/t41/tx_isp_t41_switchbin.h
	$(CC) $(CFLAGS) -o $@ $<
TESTS += tx_isp_t41_tuning_ctl_test
TESTS += tx_isp_t41_msca_shadow_test
TESTS += tx_isp_t41_msca_start_test
TESTS += tx_isp_t41_msca_ctl_test
TESTS += tx_isp_t41_osd_test
TESTS += tx_isp_t41_isp_extra_test

tx_isp_t41_osd_test: tx_isp_t41_osd_test.c ../driver/t41/tx_isp_t41_osd.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_isp_extra_test: tx_isp_t41_isp_extra_test.c ../driver/t41/tx_isp_t41_isp_extra.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_msca_ctl_test: tx_isp_t41_msca_ctl_test.c ../driver/t41/tx_isp_t41_msca_ctl.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_msca_shadow_test: tx_isp_t41_msca_shadow_test.c ../driver/t41/tx_isp_t41_msca_shadow.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_msca_start_test: tx_isp_t41_msca_start_test.c ../driver/t41/tx_isp_t41_msca_shadow.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_tuning_ctl_test: tx_isp_t41_tuning_ctl_test.c ../driver/t41/tx_isp_t41_tuning_ctl.h ../driver/t41/tx_isp_t41_tmo.h ../driver/t41/tx_isp_t41_ae.h
	$(CC) $(CFLAGS) -o $@ $<
TESTS += tx_isp_t31_wdr_test tx_isp_t31_wdr_runtime_test
TESTS += tx_isp_t21_open_test
TESTS += tx_isp_t23_tuning_ext_test
TESTS += tx_isp_t23_osd_test

tx_isp_t23_osd_test: tx_isp_t23_osd_test.c ../driver/t23/tx_isp_t23_osd.h ../driver/t23/tx_isp_t23_tuning_ext.h
	$(CC) $(CFLAGS) -o $@ $<
TESTS += tx_isp_t23_awb_cluster_test
TESTS += tx_isp_t31_autozoom_test
TESTS += tx_isp_t31_af_test
TESTS += tx_isp_t31_framedrop_test
TESTS += tx_isp_t40_ae_api_test
TESTS += tx_isp_t40_osd_slot_test
TESTS += tx_isp_t40_draw_test

tx_isp_t40_draw_test: tx_isp_t40_draw_test.c ../driver/t40/tx_isp_t40_draw.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t40_osd_slot_test: tx_isp_t40_osd_slot_test.c ../driver/t40/tx_isp_t40_osd_slot.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t40_ae_api_test: tx_isp_t40_ae_api_test.c ../driver/t40/tx_isp_t40_ae_api.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t31_framedrop_test: tx_isp_t31_framedrop_test.c ../driver/t31/tx_isp_t31_framedrop.h
	$(CC) $(CFLAGS) -o $@ $<
TESTS += tx_isp_t31_fcrop_test

tx_isp_t31_fcrop_test: tx_isp_t31_fcrop_test.c ../driver/t31/tx_isp_t31_fcrop.h
	$(CC) $(CFLAGS) -o $@ $<
TESTS += tx_isp_t23_af_test
TESTS += tx_isp_t23_crumbs_test
TESTS += tx_isp_t23_scratch_test
TESTS += tx_isp_t23_bypass_test
TESTS += tx_isp_t23_mdns_hold_test
TESTS += tx_isp_t32_mem_rcfg_test
TESTS += tx_isp_t32_msca_curve_test
TESTS += tx_isp_t32_lsc_test
TESTS += tx_isp_t32_stats_test
TESTS += tx_isp_t32_front_test
TESTS += tx_isp_t32_tisp_test

tx_isp_t32_tisp_test: tx_isp_t32_tisp_test.c t32_trace.h $(wildcard ../driver/t32/tx_isp_t32_*.h)
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t32_stats_test: tx_isp_t32_stats_test.c ../driver/t32/tx_isp_t32_stats.h ../driver/t32/tx_isp_t32_iq.h ../driver/t32/tx_isp_t32_lsc.h
	$(CC) $(CFLAGS) -o $@ $<


tx_isp_t32_front_test: tx_isp_t32_front_test.c ../driver/t32/tx_isp_t32_front.h ../driver/t32/tx_isp_t32_iq.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t32_lsc_test: tx_isp_t32_lsc_test.c ../driver/t32/tx_isp_t32_lsc.h ../driver/t32/tx_isp_t32_rcfg.h
	$(CC) $(CFLAGS) -o $@ $<


tx_isp_t32_msca_curve_test: tx_isp_t32_msca_curve_test.c ../driver/t32/tx_isp_t32_msca_curve.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += tx_isp_t32_vic_test

tx_isp_t32_mem_rcfg_test: tx_isp_t32_mem_rcfg_test.c ../driver/t32/tx_isp_t32_mem.h ../driver/t32/tx_isp_t32_rcfg.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t32_vic_test: tx_isp_t32_vic_test.c ../driver/t32/tx_isp_t32_vic.h ../driver/t32/tx_isp_t32_abi_attr.h ../driver/t32/tx_isp_t32_msca.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += tx_isp_t23_msca_geom_test
TESTS += tx_isp_t23_core_ioctl_test

tx_isp_t23_core_ioctl_test: tx_isp_t23_core_ioctl_test.c ../driver/t23/tx_isp_t23_core_ioctl.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_msca_geom_test: tx_isp_t23_msca_geom_test.c ../driver/t23/tx_isp_t23_msca_geom.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_scratch_test: tx_isp_t23_scratch_test.c ../driver/t23/tx_isp_t23_scratch.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_bypass_test: tx_isp_t23_bypass_test.c ../driver/t23/tx_isp_t23_bypass.h
	$(CC) $(CFLAGS) -o $@ $<

# T23 bypass graph VIC bank ring: mutation check (Lu-Fi/openimp#129)
t23_bypass_host:
	sh ./t23_bypass_host.sh

tx_isp_t23_mdns_hold_test: tx_isp_t23_mdns_hold_test.c ../driver/t23/tx_isp_t23_mdns_hold.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_crumbs_test: tx_isp_t23_crumbs_test.c ../driver/t23/tx_isp_t23_crumbs.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_af_test: tx_isp_t23_af_test.c ../driver/t23/tx_isp_t23_af.h ../driver/t31/tx_isp_t31_af.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t31_af_test: tx_isp_t31_af_test.c ../driver/t31/tx_isp_t31_af.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t31_autozoom_test: tx_isp_t31_autozoom_test.c ../driver/t31/tx_isp_t31_autozoom.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_tuning_ext_test: tx_isp_t23_tuning_ext_test.c ../driver/t23/tx_isp_t23_tuning_ext.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t23_awb_cluster_test: tx_isp_t23_awb_cluster_test.c ../driver/t23/tx_isp_t23_awb_cluster.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t21_open_test: tx_isp_t21_open_test.c ../driver/t21/tx_isp_t21_open.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t31_wdr_test: tx_isp_t31_wdr_test.c ../driver/t31/tx_isp_t31_wdr.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t31_wdr_runtime_test: tx_isp_t31_wdr_runtime_test.c t31_wdr_fixture.h t31_wdr_oracle_expected.h \
	../driver/t31/tx_isp_t31_wdr_runtime.inc ../driver/t31/tx_isp_t31_wdr_params.inc \
	../driver/t31/tx_isp_t31_wdr_control.h ../driver/t31/tx_isp_t31_wdr_math.h ../driver/t31/tx_isp_t31_wdr.h
	$(CC) $(CFLAGS) -o $@ $<
TESTS += tx_isp_t41_cdns_test
TESTS += tx_isp_t41_mdns_test
TESTS += tx_isp_t41_lce_test
TESTS += tx_isp_t41_adr_test
TESTS += tx_isp_t41_lsc_test
TESTS += tx_isp_t41_lsc_runtime_test
TESTS += tx_isp_t41_awb_stats_test
TESTS += tx_isp_t41_awb_long_test
TESTS += tx_isp_t41_awb_detect_test
TESTS += tx_isp_t41_awb_frame_test
TESTS += tx_isp_t41_awb_control_test
TESTS += tx_isp_t41_awb_runtime_test
tx_isp_t41_awb_runtime_test: tx_isp_t41_awb_runtime_test.c ../driver/t41/tx_isp_t41_awb_runtime.inc ../driver/t41/tx_isp_t41_awb_frame.h ../driver/t41/tx_isp_t41_awb_control.h ../driver/t41/tx_isp_t41_awb.h ../driver/t41/tx_isp_t41_awb_detect.h ../driver/t41/tx_isp_t41_awb_cluster.h ../driver/t41/tx_isp_t41_awb_gray.h ../driver/t41/tx_isp_t41_awb_long.h ../driver/t41/tx_isp_t41_awb_prior.h ../driver/t41/tx_isp_t41_awb_special.h ../driver/t41/tx_isp_t41_awb_stats.h ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_awb_ct.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -no-pie -o $@ $<

tx_isp_t41_awb_frame_test: ../driver/t41/tx_isp_t41_awb_frame.h ../driver/t41/tx_isp_t41_awb_control.h ../driver/t41/tx_isp_t41_awb.h
tx_isp_t41_awb_control_test: tx_isp_t41_awb_control_test.c t41_awb_control_oracle_check.c ../driver/t41/tx_isp_t41_awb_control.h ../driver/t41/tx_isp_t41_awb.h ../driver/t41/tx_isp_t41_awb_gray.h ../driver/t41/tx_isp_t41_awb_ct.h ../driver/t41/tx_isp_t41_awb_prior.h ../driver/t41/tx_isp_t41_awb_stats.h ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_awb_frame_test: tx_isp_t41_awb_frame_test.c t41_awb_frame_oracle_check.c ../driver/t41/tx_isp_t41_awb_long.h ../driver/t41/tx_isp_t41_awb_special.h ../driver/t41/tx_isp_t41_awb_detect.h ../driver/t41/tx_isp_t41_awb_cluster.h ../driver/t41/tx_isp_t41_awb_gray.h ../driver/t41/tx_isp_t41_awb_prior.h ../driver/t41/tx_isp_t41_awb_stats.h ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_awb_ct.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_awb_detect_test: tx_isp_t41_awb_detect_test.c t41_awb_detect_oracle_check.c ../driver/t41/tx_isp_t41_awb_detect.h ../driver/t41/tx_isp_t41_awb_cluster.h ../driver/t41/tx_isp_t41_awb_gray.h ../driver/t41/tx_isp_t41_awb_prior.h ../driver/t41/tx_isp_t41_awb_stats.h ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_awb_ct.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_awb_long_test: tx_isp_t41_awb_long_test.c ../driver/t41/tx_isp_t41_awb_long.h ../driver/t41/tx_isp_t41_awb_prior.h ../driver/t41/tx_isp_t41_awb_stats.h ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_awb_stats_test: ../driver/t41/tx_isp_t41_awb_gray.h

tx_isp_t41_awb_stats_test: tx_isp_t41_awb_stats_test.c ../driver/t41/tx_isp_t41_awb_stats.h ../driver/t41/tx_isp_t41_awb_prior.h ../driver/t41/tx_isp_t41_awb_special.h ../driver/t41/tx_isp_t41_awb_ct.h ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_lsc_runtime_test: tx_isp_t41_lsc_runtime_test.c ../driver/t41/tx_isp_t41_lsc_runtime.inc ../driver/t41/tx_isp_t41_lsc.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -no-pie -o $@ $<

tx_isp_t41_lsc_test: tx_isp_t41_lsc_test.c ../driver/t41/tx_isp_t41_lsc.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_adr_test: tx_isp_t41_adr_test.c ../driver/t41/tx_isp_t41_adr.h ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_lce_test: tx_isp_t41_lce_test.c ../driver/t41/tx_isp_t41_lce.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_mdns_test: tx_isp_t41_mdns_test.c ../driver/t41/tx_isp_t41_mdns.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_cdns_test: tx_isp_t41_cdns_test.c ../driver/t41/tx_isp_t41_cdns.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_ysp_test: tx_isp_t41_ysp_test.c ../driver/t41/tx_isp_t41_ysp.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += tx_isp_t41_modctl_test tx_isp_t41_drc_ratio_test tx_isp_t41_dpc_ratio_test tx_isp_t41_csc_ctl_test tx_isp_t41_ccm_manual_test tx_isp_t41_gamma_ctl_test tx_isp_t41_gib_test tx_isp_t41_awb_gain_test tx_isp_t41_sensor_gain_test tx_isp_t41_gamma_test tx_isp_t41_dpc_test tx_isp_t41_dmsc_test tx_isp_t41_sdns_test tx_isp_t41_ydns_test

tx_isp_t41_ydns_test: tx_isp_t41_ydns_test.c ../driver/t41/tx_isp_t41_ydns.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_sdns_test: tx_isp_t41_sdns_test.c ../driver/t41/tx_isp_t41_sdns.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_dmsc_test: tx_isp_t41_dmsc_test.c ../driver/t41/tx_isp_t41_dmsc.h ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_dpc_test: tx_isp_t41_dpc_test.c ../driver/t41/tx_isp_t41_dpc.h ../driver/t41/tx_isp_t41_tmo.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_gamma_test: tx_isp_t41_gamma_test.c ../driver/t41/tx_isp_t41_gamma.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_sensor_gain_test: tx_isp_t41_sensor_gain_test.c ../driver/t41/tx_isp_t41_sensor_gain.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_awb_gain_test: tx_isp_t41_awb_gain_test.c ../driver/t41/tx_isp_t41_awb_gain.h ../driver/t41/tx_isp_t41_ae.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_gib_test: tx_isp_t41_gib_test.c ../driver/t41/tx_isp_t41_gib.h
	$(CC) $(CFLAGS) -o $@ $<

# T41 AF block (#179): header vs OEM decompile oracle
TESTS += tx_isp_t41_af_test
tx_isp_t41_af_test: tx_isp_t41_af_test.c ../driver/t41/tx_isp_t41_af.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_color_route_test: tx_isp_t41_color_route_test.c ../driver/t41/tx_isp_t41_exposure.c ../driver/t41/tx_isp_t41_exposure.h ../driver/include/tx_isp/tx_isp_top.h
	$(CC) $(CFLAGS) -o $@ $< ../driver/t41/tx_isp_t41_exposure.c

TESTS += tx_isp_math_test tx_isp_modulation_test tx_isp_daynight_test tx_isp_awb_mesh_test tx_isp_t41_tmo_test tx_isp_t41_awb_test tx_isp_t41_tmo_map_test tx_isp_t41_ccm_test tx_isp_t41_bcsh_test tx_isp_t41_ae_test tx_isp_t41_color_route_test \
	tx_isp_subdev_abi_test tx_isp_subdev_test \
	tx_isp_remote_event_test \
	tx_isp_state_test \
	tx_isp_sinfo_abi_test \
	tx_isp_sensor_format_test \
	tx_isp_reg_profile_test \
	tx_isp_callback_plan_test tx_isp_tuning_abi_test \
	tx_isp_frame_abi_test tx_isp_frame_channel_test \
	tx_isp_frame_format_test \
		tx_isp_frame_layout_test \
		tx_isp_video_queue_test \
		tx_isp_region_allocator_test \
	tx_isp_exposure_test tx_isp_t31_adr_test tx_isp_t31_mdns_test \
	tx_isp_t31_sensor_policy_test \
	tx_isp_scaler_test tx_isp_t41_capture_gate_test

tx_isp_t41_capture_gate_test: tx_isp_t41_capture_gate_test.c \
		../driver/t41/tx_isp_t41_capture_gate.c \
		../driver/t41/tx_isp_t41_capture_gate.h
	$(CC) $(CFLAGS) -pthread -o $@ $< ../driver/t41/tx_isp_t41_capture_gate.c

tx_isp_t31_mdns_test: tx_isp_t31_mdns_test.c \
		../driver/t31/tx_isp_t31_mdns.c \
		../driver/t31/tx_isp_t31_mdns.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_t31_mdns_test.c ../driver/t31/tx_isp_t31_mdns.c

tx_isp_t31_sensor_policy_test: tx_isp_t31_sensor_policy_test.c \
		../driver/t31/tx_isp_t31_sensor_policy.c \
		../driver/t31/tx_isp_t31_sensor_policy.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_t31_sensor_policy_test.c \
		../driver/t31/tx_isp_t31_sensor_policy.c

tx_isp_math_test: tx_isp_math_test.c ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_t41_tmo_test: tx_isp_t41_tmo_test.c ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_gamma_ctl_test: tx_isp_t41_gamma_ctl_test.c ../driver/t41/tx_isp_t41_gamma_ctl.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_csc_ctl_test: tx_isp_t41_csc_ctl_test.c ../driver/t41/tx_isp_t41_csc_ctl.h ../driver/t41/tx_isp_t41_ccm.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_ccm_manual_test: tx_isp_t41_ccm_manual_test.c ../driver/t41/tx_isp_t41_ccm_manual.h ../driver/t41/tx_isp_t41_ccm.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_dpc_ratio_test: tx_isp_t41_dpc_ratio_test.c ../driver/t41/tx_isp_t41_dpc_ratio.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_drc_ratio_test: tx_isp_t41_drc_ratio_test.c ../driver/t41/tx_isp_t41_drc_ratio.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_modctl_test: tx_isp_t41_modctl_test.c ../driver/t41/tx_isp_t41_modctl.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_ccm_test: tx_isp_t41_ccm_test.c ../driver/t41/tx_isp_t41_ccm.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += tx_isp_t41_hvflip_test
tx_isp_t41_hvflip_test: tx_isp_t41_hvflip_test.c ../driver/t41/tx_isp_t41_hvflip.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_bcsh_test: tx_isp_t41_bcsh_test.c ../driver/t41/tx_isp_t41_bcsh.h ../driver/t41/tx_isp_t41_ccm.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_ae_test: tx_isp_t41_ae_test.c ../driver/t41/tx_isp_t41_ae.h ../driver/t41/tx_isp_t41_ae_alloc.h ../driver/t41/tx_isp_t41_tmo.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_tmo_map_test: tx_isp_t41_tmo_map_test.c ../driver/t41/tx_isp_t41_tmo_map.h \
		../driver/t41/tx_isp_t41_tmo.h ../driver/t41/tx_isp_t41_tmo_kernels.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_t41_awb_test: tx_isp_t41_awb_test.c ../driver/t41/tx_isp_t41_awb.h ../driver/include/tx_isp/tx_isp_math.h
	$(CC) $(CFLAGS) -o $@ $<

tx_isp_awb_mesh_test: tx_isp_awb_mesh_test.c ../driver/common/tx_isp_awb_mesh.c \
		../driver/include/tx_isp/tx_isp_awb_mesh.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_awb_mesh_test.c ../driver/common/tx_isp_awb_mesh.c

tx_isp_modulation_test: tx_isp_modulation_test.c \
		../driver/include/tx_isp/tx_isp_modulation.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_daynight_test: tx_isp_daynight_test.c \
		../driver/common/tx_isp_daynight.c \
		../driver/include/tx_isp/tx_isp_daynight.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_daynight_test.c ../driver/common/tx_isp_daynight.c

tx_isp_subdev_abi_test: tx_isp_subdev_abi_test.c \
		../driver/common/tx_isp_subdev.c \
		../driver/include/tx_isp/tx_isp_subdev_abi.h \
		../driver/include/tx_isp/tx_isp_subdev.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_subdev_abi_test.c ../driver/common/tx_isp_subdev.c

tx_isp_subdev_test: tx_isp_subdev_test.c \
		../driver/common/tx_isp_subdev.c \
		../driver/include/tx_isp/tx_isp_subdev.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_subdev_test.c ../driver/common/tx_isp_subdev.c

tx_isp_remote_event_test: tx_isp_remote_event_test.c \
		../driver/common/tx_isp_remote_event.c \
		../driver/include/tx_isp/tx_isp_remote_event.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_remote_event_test.c ../driver/common/tx_isp_remote_event.c

tx_isp_state_test: tx_isp_state_test.c \
		../driver/common/tx_isp_state.c \
		../driver/include/tx_isp/tx_isp_state.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_state_test.c ../driver/common/tx_isp_state.c

tx_isp_sinfo_abi_test: tx_isp_sinfo_abi_test.c \
		../driver/include/tx_isp/tx_isp_sinfo.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_sensor_format_test: tx_isp_sensor_format_test.c \
		../driver/include/tx_isp/tx_isp_sensor_format.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_reg_profile_test: tx_isp_reg_profile_test.c \
		../driver/common/tx_isp_reg_profile.c \
		../driver/include/tx_isp/tx_isp_reg_profile.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_reg_profile_test.c ../driver/common/tx_isp_reg_profile.c

tx_isp_callback_plan_test: tx_isp_callback_plan_test.c \
		../driver/common/tx_isp_callback_plan.c \
		../driver/include/tx_isp/tx_isp_callback_plan.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_callback_plan_test.c ../driver/common/tx_isp_callback_plan.c

tx_isp_tuning_abi_test: tx_isp_tuning_abi_test.c \
		../driver/common/tx_isp_tuning_abi.c \
		../driver/include/tx_isp/tx_isp_tuning_abi.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_tuning_abi_test.c ../driver/common/tx_isp_tuning_abi.c

tx_isp_frame_abi_test: tx_isp_frame_abi_test.c \
		../driver/include/tx_isp/tx_isp_frame_abi.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_frame_channel_test: tx_isp_frame_channel_test.c \
		../driver/include/tx_isp/tx_isp_frame_channel.h \
		../driver/include/tx_isp/tx_isp_frame_abi.h \
		../driver/include/tx_isp/tx_isp_frame_format.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_frame_format_test: tx_isp_frame_format_test.c \
		../driver/include/tx_isp/tx_isp_frame_format.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<

tx_isp_frame_layout_test: tx_isp_frame_layout_test.c \
		../driver/common/tx_isp_frame_layout.c \
		../driver/include/tx_isp/tx_isp_frame_layout.h \
		../driver/include/tx_isp/tx_isp_frame_abi.h \
		../driver/include/tx_isp/tx_isp_frame_format.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_frame_layout_test.c ../driver/common/tx_isp_frame_layout.c

tx_isp_video_queue_test: tx_isp_video_queue_test.c \
		../driver/common/tx_isp_video_queue.c \
		../driver/include/tx_isp/tx_isp_video_queue.h \
		../driver/include/tx_isp/tx_isp_frame_channel.h \
		../driver/include/tx_isp/tx_isp_frame_abi.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_video_queue_test.c ../driver/common/tx_isp_video_queue.c

tx_isp_region_allocator_test: tx_isp_region_allocator_test.c \
		../driver/common/tx_isp_region_allocator.c \
		../driver/include/tx_isp/tx_isp_region_allocator.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_region_allocator_test.c \
		../driver/common/tx_isp_region_allocator.c

tx_isp_exposure_test: tx_isp_exposure_test.c \
		../driver/t31/tx_isp_t31_exposure.c \
		../driver/t31/tx_isp_t31_exposure.h \
		../driver/common/tx_isp_exposure.c \
		../driver/include/tx_isp/tx_isp_exposure.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_exposure_test.c ../driver/common/tx_isp_exposure.c \
		../driver/t31/tx_isp_t31_exposure.c

tx_isp_t31_adr_test: tx_isp_t31_adr_test.c \
		../driver/t31/tx_isp_t31_adr.c \
		../driver/t31/tx_isp_t31_adr.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_t31_adr_test.c ../driver/t31/tx_isp_t31_adr.c

tx_isp_scaler_test: tx_isp_scaler_test.c \
		../driver/t23/tx_isp_t23_scaler.c \
		../driver/t23/tx_isp_t23_scaler.h \
		../driver/t41/tx_isp_t41_scaler.c \
		../driver/t41/tx_isp_t41_scaler.h \
		../driver/common/tx_isp_scaler.c \
		../driver/include/tx_isp/tx_isp_scaler.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ \
		tx_isp_scaler_test.c ../driver/common/tx_isp_scaler.c \
		../driver/t23/tx_isp_t23_scaler.c \
		../driver/t41/tx_isp_t41_scaler.c

TESTS += tx_isp_isr_enable_test

tx_isp_isr_enable_test: tx_isp_isr_enable_test.c ../driver/common/tx_isp_isr_enable.h
	$(CC) $(CFLAGS) -I../driver/common -o $@ $<

TESTS += tx_isp_csc_test

tx_isp_csc_test: tx_isp_csc_test.c ../driver/common/tx_isp_csc.h
	$(CC) $(CFLAGS) -I../driver/common -o $@ $<

TESTS += scene_colorfx_host_test

scene_colorfx_host_test: scene_colorfx_host_test.c ../driver/common/tx_isp_scene_colorfx.h
	$(CC) $(CFLAGS) -I../driver/common -o $@ $<

TESTS += t31_sharpness_host_test

t31_sharpness_host_test: t31_sharpness_host_test.c ../driver/t31/tx_isp_t31_sharpness.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t21_sepia_host_test

t21_sepia_host_test: t21_sepia_host_test.c ../driver/t21/tx_isp_t21_tuning_ctl.h ../driver/common/tx_isp_csc.h
	$(CC) $(CFLAGS) -Wno-unused-variable -I../driver/common -o $@ $<

TESTS += t30_stab_host_test

t30_stab_host_test: t30_stab_host_test.c ../driver/t30/tx_isp_t30_stab.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t30_fmt5c_host_test

t30_fmt5c_host_test: t30_fmt5c_host_test.c ../driver/t30/tx_isp_t30_fmt5c.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t30_tuning_ctl_host_test

t30_tuning_ctl_host_test: t30_tuning_ctl_host_test.c ../driver/t30/tx_isp_t30_tuning_math.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t20_expr_time_host_test

t20_expr_time_host_test: t20_expr_time_host_test.c ../driver/t20/sdk/tx-isp-expr-time.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t21_it_block_host_test

t21_it_block_host_test: t21_it_block_host_test.c ../driver/t21/tx_isp_t21_tuning_ctl.h ../driver/common/tx_isp_csc.h
	$(CC) $(CFLAGS) -Wno-unused-variable -Wno-unused-function -I../driver/common -o $@ $<

TESTS += t21_night_reinit_host_test

t21_night_reinit_host_test: t21_night_reinit_host_test.c ../driver/t21/tx_isp_t21_recovered.c
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t21_ae_comp_host_test

t21_ae_comp_host_test: t21_ae_comp_host_test.c ../driver/t21/tx_isp_t21_ae_comp.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += sinfo_vendor_host_test

sinfo_vendor_host_test: sinfo_vendor_host_test.c ../driver/common/tx_isp_sinfo_vendor.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t31_ae_step_host_test

t31_ae_step_host_test: t31_ae_step_host_test.c ../driver/t31/tx_isp_t31_ae_step.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t20_ae_max_host_test

t20_ae_max_host_test: t20_ae_max_host_test.c ../driver/t20/tx_isp_t20_ae_max.h
	$(CC) $(CFLAGS) -o $@ $<

TESTS += t31_awb_simd_host_test

# the detection code is taken from the real driver source, not copied
t31_awb_defs.inc: ../driver/t31/tx_isp_tuning.c
	sed -n '/T31_AWB_HOST_DEFS_BEGIN/,/T31_AWB_HOST_DEFS_END/p' $< > $@

t31_awb_region.inc: ../driver/t31/tx_isp_tuning.c
	{ sed -n '/^static uint32_t ISPAWBInterpolation1/,/^static uint32_t __maybe_unused awb_ratio_u8/p' $< | sed '$$d'; \
	  sed -n '/^\/\* OEM func_zone_ct_weight/,/T31_AWB_HOST_END/p' $< ; } > $@

t31_awb_simd_host_test: t31_awb_simd_host_test.c t31_awb_defs.inc t31_awb_region.inc ../driver/t31/tx_isp_t31_awb_simd.h
	$(CC) $(CFLAGS) -O2 -Wno-unused-function -Wno-unused-variable -Wno-unused-but-set-variable -o $@ $<

all: $(TESTS)

# "all check: foo_test" (old style, e.g. on older branches) still works:
# such prerequisites of check are run as well.
CHECK_TESTS = $(sort $(TESTS) $(filter %_test,$^))

check:
	@$(MAKE) --no-print-directory -k $(CHECK_TESTS) >/dev/null 2>&1; \
	to=; command -v timeout >/dev/null && to="timeout $(TEST_TIMEOUT)"; \
	pass=; fail=; \
	for t in $(CHECK_TESTS); do \
		if ! $(MAKE) --no-print-directory -q $$t 2>/dev/null; then \
			echo "=== $$t: BUILD FAILED"; \
			$(MAKE) --no-print-directory $$t 2>&1 | tail -n 20; \
			fail="$$fail $$t(build)"; continue; \
		fi; \
		echo "=== $$t"; \
		$$to ./$$t; rc=$$?; \
		if [ $$rc -eq 0 ]; then pass="$$pass $$t"; \
		else echo "=== $$t: FAILED rc=$$rc"; fail="$$fail $$t(rc=$$rc)"; fi; \
	done; \
	skip=; so=$$(mktemp); \
	for c in $(CHECK_TARGETS); do \
		echo "=== $$c"; \
		if $(MAKE) --no-print-directory $$c >$$so 2>&1; then pass="$$pass $$c"; cat $$so; \
		else cat $$so; echo "=== $$c: FAILED"; fail="$$fail $$c"; fi; \
		if grep -q ': SKIP (' $$so; then skip="$$skip $$c"; fi; \
	done; rm -f $$so; \
	for f in *_test.c; do \
		b=$${f%.c}; \
		case " $(CHECK_TESTS) $(TARGET_TESTS) " in *" $$b "*) ;; \
		*) echo "=== $$b: NOT REGISTERED (add TESTS += $$b)"; \
		   fail="$$fail $$b(unregistered)";; esac; \
	done; \
	np=$$(echo $$pass | wc -w); nf=$$(echo $$fail | wc -w); \
	echo; echo "==== check summary: $$np passed, $$nf failed"; \
	echo "passed:$$pass" | fold -s -w 100; \
	ns=$$(echo $$skip | wc -w); \
	if [ $$ns -ne 0 ]; then \
		echo; echo "!!!! $$ns oracles SKIPPED (set T40_OEM_KO/T40_CC, T40_TUNING_BIN; they count as passed above but did NOT run):"; \
		echo "skipped:$$skip" | fold -s -w 100; \
		echo "!!!! run them with: make -C tests check-oracles (see tests/README.oracles.md)"; \
	fi; \
	if [ $$nf -ne 0 ]; then echo "FAILED:$$fail" | fold -s -w 100; exit 1; fi

# The Unicorn / vendor-data oracles.  They SKIP (exit 0) in a plain `make check` when the vendor inputs are not
# configured; here a SKIP is a failure, so a green `check-oracles` means every oracle really ran.
# Inputs (see README.oracles.md): T40_OEM_KO, T40_CC, T40_TUNING_BIN, T40_OEM_DATA.
ORACLES := t40_clm_host t40_bcsh_dn_host t40_ccm_conv_host t40_ccm_chain_host t40_ct_chain_host t40_dmsc_chain_host t40_mdns_chain_host t40_ysp_chain_host t40_ydns_host t40_gib_host t40_lsc_host t40_blc_host t40_ae_leaf_host t40_wdr_log2_host
check-oracles:
	@fail=; for c in $(ORACLES); do \
		echo "=== $$c"; \
		if T40_ORACLE_STRICT=1 $(MAKE) --no-print-directory $$c; then :; else echo "=== $$c: FAILED or SKIPPED (strict)"; fail="$$fail $$c"; fi; \
	done; \
	n=$$(echo $(ORACLES) | wc -w); nf=$$(echo $$fail | wc -w); \
	echo; echo "==== oracle summary: $$((n-nf)) of $$n ran and passed, $$nf failed/skipped"; \
	if [ $$nf -ne 0 ]; then echo "FAILED/SKIPPED:$$fail"; exit 1; fi

t30_storage_audit:
	../driver/t30/check_storage.sh

t30_fw_irq_gate:
	sh ./check_t30_fw_irq_gate.sh ../driver/t30

# T30 0x5c-byte format ioctl of the vendor libimp: conversion host test with mutation check (Lu-Fi/openimp#178)
t30_fmt5c_check:
	sh ./check_t30_fmt5c.sh ../driver/t30

# T30 tuning controls the lifted switch had lost: host test + mutations + arm/dispatch guard (Lu-Fi/openimp#177)
t30_tuning_ctl_check:
	sh ./check_t30_tuning_ctl.sh ../driver/t30

# T30 lifted calls with dropped arguments (gamma s_ctrl wrote its status through NULL): only new findings fail
t30_callarg_check:
	python3 ../tools/check_ioctl_ptr_scale.py ../driver/t30/tx_isp_t30_recovered.c --call-args --baseline t30_callarg_baseline.txt

t41_dfg_host:
	./t41_dfg_host.sh

# AF statistics unpack + metrics (driver/t40/tx_isp_t40_af.h)
t40_af_stats_host:
	./t40/af_stats_host/run.sh

# T40 BCSH day -> night -> day (C chain, needs a T40 tuning bin, else SKIP)
t40_bcsh_dn_host:
	./t40/bcsh_dn_host/run.sh

# T40 tisp_tstp_reg_cfg (driver/t40/tx_isp_t40_tstp.h) vs the OEM register writes (#142)
t40_tstp_host:
	./t40/tstp_host/run.sh

# T40 CCM leaf converters vs the OEM instructions (Unicorn, needs T40_OEM_KO, else SKIP)
t40_ccm_conv_host:
	./t40_ccm_conv_host.sh

# T40 CCM chain (driver/t40/tx_isp_t40_ccm_chain.h, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_ccm_chain_host:
	./t40_ccm_chain_host.sh

t40_ct_chain_host:
	./t40_ct_chain_host.sh

# T40 DMSC chain (driver/t40/tx_isp_t40_dmsc_chain.h, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_dmsc_chain_host:
	./t40_dmsc_chain_host.sh

# T40 MDNS chain (driver/t40/tx_isp_t40_mdns_chain.h, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_mdns_chain_host:
	./t40_mdns_chain_host.sh

# T40 YSP chain (driver/t40/tx_isp_t40_ysp_chain.h, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_ysp_chain_host:
	./t40_ysp_chain_host.sh

# T40 YDNS block (hand-written C of tx_isp_t40_recovered.c, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_ydns_host:
	./t40_ydns_host.sh

# T40 GIB block (hand-written C of tx_isp_t40_recovered.c, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_gib_host:
	./t40_gib_host.sh

# T40 BLC block (tx_isp_t40_blc.h, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_blc_host:
	./t40_blc_host.sh

# T40 AE leaf / parameter functions (tx_isp_t40_ae_leaf.h, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO, T40_CC and T40_OEM_KO_FAC, else SKIP)
t40_ae_leaf_host:
	./t40_ae_leaf_host.sh

# T40 CLM block vs the OEM instructions in Unicorn (driver/t40/tx_isp_t40_clm.h; T40_OEM_KO + T40_CC, else SKIP)
t40_clm_host:
	./t40_clm_host.sh

# T40 LSC chain (hand-written C of tx_isp_t40_lsc_lit.inc, built for mipsel) vs the OEM instructions (Unicorn, needs T40_OEM_KO and T40_CC, else SKIP)
t40_lsc_host:
	./t40_lsc_host.sh

# T40 ADR C chain vs literal OEM + AWB long_alogrithm/ct_detect C vs translated OEM (needs T40_TUNING_BIN
# [+ T40_OEM_DATA, T40_AWB_DUMPS], else SKIP)
t40_bitexact_host:
	./t40_bitexact_host.sh

# Lifted T40 calls: typed-pointer-scaled call arguments and dropped arguments (agg50/agg51).
# Known findings in dead or audited code are in t40_callarg_baseline.txt; a new one fails.
t40_callarg_check:
	python3 ../tools/check_ioctl_ptr_scale.py ../driver/t40/tx_isp_t40_recovered.c --call-args --baseline t40_callarg_baseline.txt

# T41 user sensor register ioctl must run under the #134 sensor-release barrier mutex (#162)
t41_sensor_barrier_check:
	python3 ./t41_sensor_barrier_check.py

# T40 lifted pointers must not be bare integer literals; AWB algo deinit uses awb_algo_enable (#173)
t40_hardcoded_anchor_check:
	python3 ./t40_hardcoded_anchor_check.py

# Typed-pointer scaling in the lifted T40/T41 drivers (#186/#187 bug class): new findings fail, reviewed ones live in the baseline
lifted_ptr_scale_check:
	python3 ./lifted_ptr_scale_check.py --selftest
	python3 ./lifted_ptr_scale_check.py --baseline lifted_ptr_scale_baseline.txt
	python3 ./lifted_ptr_scale_check.py --expect-clean t41:tx_isp_suspend t41:tx_isp_resume t41:vic_frame_channel_streamon t41:vic_frame_channel_streamoff \
		t41:vic_frame_channel_qbuf t41:vic_frame_channel_set_fmt t41:isp_frame_done_wakeup t41:tisp_s_wdr_en t41:tx_isp_vic_start t41:isp_info_show_isra_6 \
		t41:isp_mbus_to_bayer_isra_1 t41:ivdc_core_ops_init t41:tisp_lce_clr_ram_part_0 t41:tx_isp_set_ae_algo_open_isra_23 t41:tx_isp_vin_suspend_module \
		t41:tx_isp_vin_resume_module t41:fs_resume_module t41:ispcore_suspend_module t41:vic_core_ops_init t41:tx_isp_switch_bin_isra_78 t41:tisp_switch_bin \
		t41:frame_channel_unlocked_ioctl t41:tx_isp_unlocked_ioctl t41:__fill_tisp_buffer
	@# #189 postret: OEM `jr ra` delay-slot statements restored in front of the return (class postret only)
	python3 ./lifted_ptr_scale_check.py --expect-clean t40:pop_buffer_fifo:postret t40:tisp_ae_main_mean_update:postret \
		t40:tisp_ae_params_transmit:postret t40:tisp_ae_sec_mean_update:postret t40:tisp_awb_set_statis_localtion:postret \
		t41:api_ae_set_exprinfo_attr:postret t41:tisp_msca_ch_curve_write:postret t41:tisp_wdr_get_lum_s:postret t41:vic_core_ops_init:postret \
		t40:tisp_ae_ir_en_update:postret t40:tisp_af_set_attr_refresh:postret t40:tisp_awb_get_frz:postret t40:tisp_defog_wdr_choose_para:postret \
		t40:tisp_sdns_wdr_en:postret t40:tisp_wdr_get_lum_s:postret t41:tisp_ae_api_get_antiflick:postret t41:tisp_awb_ev_update_Ywgt:postret
	@# #189 tailcall / argc: lost `jr t9` tail calls and one-argument system_reg_write calls restored (vendor41 compared)
	python3 ./lifted_ptr_scale_check.py --expect-clean t41:tisp_msca_ir_init:tailcall t41:tisp_msca_addr_ir_fifo_write:tailcall t41:system_reg_set_ae_trig:tailcall \
		t41:tisp_tstp_reg_cfg:tailcall t41:tisp_tstp_reg_cfg:argc t41:tisp_lce_clr_ram_part_0:tailcall t41:tisp_lce_clr_ram_part_0:argc \
		t41:tisp_gib_write_reg:argc t41:tisp_csc_yuv_dmo:tailcall t41:tisp_csccr_default_mode:tailcall t41:tisp_csccr_range_stretch_mode:tailcall \
		t41:tisp_csccr_range_compress_mode:tailcall t41:tisp_raw_rdma_fd_interrupt
	@# #189 pass 4 (T40, vendor T40 module + libt40-firmware compared): restored tail calls / the lost module-control mask
	python3 ./lifted_ptr_scale_check.py --expect-clean t40:system_reg_write_af:tailcall t40:tisp_s_module_control:tailcall		t40:tisp_csc_set_attr:tailcall
	@# #189 T40 layout pass: the VIC ISR has no typed-pointer finding left in any class
	python3 ./lifted_ptr_scale_check.py --expect-clean t40:isp_vic_interrupt_service_routine
	@# #189 pass 5 (T23, vendor tx-isp-t23.ko 1.3.0 compared): typed-pointer byte arithmetic restored in the live T23 functions
	python3 ./lifted_ptr_scale_check.py --expect-clean t23:ispcore_core_ops_ioctl t23:jz_isp_ccm t23:tisp_ae_mean_update
	@# #193 (from #140): lost call arguments (class arity, scanner = cast call with fewer parameters than the prototype), compared with the vendor tx-isp-t40.ko
	python3 ./lifted_ptr_scale_check.py --expect-clean t40:tisp_get_antiflicker_step:arity t40:subdev_sensor_ops_ioctl:arity t40:csi_sensor_ops_ioctl:arity \
		t40:tx_isp_vin_slake_subdev:arity t40:isp_main_pre_frame_dequeue:arity

# T40 VIC interrupt counter block and output format table are real objects, not stray anchors (#189 layout class)
t40_vic_layout_check:
	python3 ./t40_vic_layout_check.py

# T40 lost tail calls / ALU restored in lifted code, run against callee stubs (#189)
t40_lost_tail_host:
	sh ./t40_lost_tail_host.sh

# T40 module exit gates the ISP/CSI clocks it enabled (#152)
t40_clk_teardown_check:
	sh ./check_t40_clk_teardown.sh

# T40 tisp_main_init shim runs the OEM tstp init: pipeline-top block cleared (#150)
t40_tstp_init_check:
	sh ./check_t40_tstp_init.sh

# T40 custom AE/AWB algorithm workers are woken like the vendor does (#65)
t40_custom_algo_wake_check:
	sh ./check_t40_custom_algo_wake.sh

# T40 custom AE/AWB get-handle protocol: NULL / close race / interrupted wait (review 2026-11-03 H1), with mutation check
t40_algo_handle_host:
	sh ./t40_algo_handle_host.sh

# T40 tisp_wdr_log2 against the OEM instructions (unicorn; SKIP without T40_OEM_KO / T40_CC), with mutation check
t40_wdr_log2_host:
	sh ./t40_wdr_log2_host.sh

# T41 custom AE library path (#76)
t41_custom_ae_check:
	sh ./check_t41_custom_ae.sh

t41_custom_awb_check:
	sh ./check_t41_custom_awb.sh

t41_awb_algo_host:
	sh ./t41_awb_algo_host.sh

t41_ae_algo_host:
	sh ./t41_ae_algo_host.sh

# T41 AF block stays off unless t41_af=1 (#179)
t41_af_gate_check:
	sh ./check_t41_af_gate.sh

clean:
	$(RM) $(TESTS)
	$(MAKE) -C t20_fw clean
	$(RM) tx_isp_t31_wdr_test tx_isp_t31_wdr_runtime_test
	$(RM) tx_isp_t41_awb_frame_test
	$(RM) tx_isp_t41_awb_control_test
	$(RM) tx_isp_t41_awb_runtime_test
	$(RM) tx_isp_t41_awb_detect_test
	$(RM) tx_isp_t41_awb_long_test
	$(RM) t30_tuning_ctl_host_test t31_awb_simd_host_test t31_awb_defs.inc t31_awb_region.inc tx_isp_t41_tuning_ctl_test t21_sepia_host_test t21_it_block_host_test t30_stab_host_test t20_expr_time_host_test t31_sharpness_host_test t31_ae_step_host_test sinfo_vendor_host_test
	$(RM) tx_isp_t41_awb_stats_test
	$(RM) tx_isp_math_test tx_isp_modulation_test \
		tx_isp_awb_mesh_test \
		tx_isp_t41_tmo_test \
		tx_isp_t41_tmo_map_test \
		tx_isp_t41_awb_test \
		tx_isp_t41_modctl_test tx_isp_t41_drc_ratio_test tx_isp_t41_dpc_ratio_test tx_isp_t41_csc_ctl_test tx_isp_t41_ccm_manual_test tx_isp_t41_gamma_ctl_test tx_isp_t41_ccm_test tx_isp_t41_bcsh_test tx_isp_t41_hvflip_test tx_isp_t41_ae_test tx_isp_t41_gib_test tx_isp_t41_awb_gain_test tx_isp_t41_sensor_gain_test \
		tx_isp_t41_color_route_test \
		tx_isp_daynight_test \
		tx_isp_subdev_abi_test tx_isp_subdev_test \
		tx_isp_remote_event_test \
		tx_isp_state_test \
		tx_isp_sinfo_abi_test \
		tx_isp_sensor_format_test \
		tx_isp_reg_profile_test \
		tx_isp_callback_plan_test tx_isp_tuning_abi_test \
		tx_isp_frame_abi_test tx_isp_frame_channel_test \
		tx_isp_frame_format_test \
		tx_isp_frame_layout_test \
		tx_isp_video_queue_test \
		tx_isp_region_allocator_test \
		tx_isp_exposure_test tx_isp_t31_adr_test tx_isp_scaler_test \
		tx_isp_t31_mdns_test tx_isp_t31_sensor_policy_test tx_isp_t41_capture_gate_test

# T23/T31 GetAwbZone block: stock scaling and freshness (tx_isp_awb_zone.h)
TESTS += tx_isp_awb_zone_test
tx_isp_awb_zone_test: tx_isp_awb_zone_test.c \
		../driver/include/tx_isp/tx_isp_awb_zone.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<
clean: clean-awb-zone
.PHONY: clean-awb-zone
clean-awb-zone:
	$(RM) tx_isp_awb_zone_test

# T41 GetAwbStatistics planes: freshness contract (tx_isp_t41_awb_zone_report.h)
TESTS += tx_isp_t41_awb_zone_report_test
tx_isp_t41_awb_zone_report_test: tx_isp_t41_awb_zone_report_test.c \
		../driver/t41/tx_isp_t41_awb_zone_report.h ../driver/include/tx_isp/tx_isp_awb_zone.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<
clean: clean-t41-awb-zone-report
.PHONY: clean-t41-awb-zone-report
clean-t41-awb-zone-report:
	$(RM) tx_isp_t41_awb_zone_report_test

# T10/T20 GetAwbZone (driver/t20 tuning, T2X_CID_AWB_ZONE)
TESTS += tx_isp_t2x_awb_zone_test
tx_isp_t2x_awb_zone_test: tx_isp_t2x_awb_zone_test.c \
		../driver/include/tx_isp/tx_isp_t2x_awb_zone.h
	$(CC) $(CFLAGS) -I../driver/include -o $@ $<
clean: clean-t2x-awb-zone
.PHONY: clean-t2x-awb-zone
clean-t2x-awb-zone:
	$(RM) tx_isp_t2x_awb_zone_test
