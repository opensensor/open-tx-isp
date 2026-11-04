# Unicorn oracles (T40)

Host checks that compare our C code with the instructions of the vendor module under the Unicorn
emulator:
`t40_ccm_conv_host t40_ccm_chain_host t40_ct_chain_host t40_dmsc_chain_host t40_mdns_chain_host t40_ysp_chain_host t40_ydns_host t40_gib_host t40_lsc_host t40_blc_host t40_ae_leaf_host t40_clm_host`
(need `T40_OEM_KO`, and `T40_CC` for the chain ones), and
`t40_bcsh_dn_host` (`T40_TUNING_BIN`, or the initialised `external/ingenic-sdk` submodule).

In a plain `make -C tests check` they print `SKIP` and exit 0 when the inputs are missing (the default flow
stays usable without vendor files). Such a SKIP counts as passed, so `check` ends with a line
`!!!! N oracles SKIPPED (...)` naming them. Do not read a green `check` as "oracles ran" when that line is there.

`make -C tests check-oracles` runs only the oracles with `T40_ORACLE_STRICT=1`: a SKIP is a failure.
Required before a merge that touches the T40 colour/denoise/GIB/LSC chains.

Inputs (vendor files are never part of the repository):

    export T40_OEM_KO=<tx-isp-t40.ko of a vendor firmware of the same ISP generation>
    export T40_CC=<mipsel-linux-gcc of any thingino toolchain>
    export T40_OEM_KO_FAC=<tx-isp-t40.ko of the factory Eufy firmware>   # t40_ae_leaf_host only (3 functions, see below)
    export T40_TUNING_BIN=<a T40 sensor tuning bin, e.g. external/ingenic-sdk/sensor-iq/t40/gc2053.bin>
    python3 -m pip install unicorn pyelftools   # if missing
    make -C tests check-oracles

## Which vendor module (2026-11-03, #85)

Two Eufy T8416 vendor builds of `tx-isp-t40.ko` exist (both `20220601a`, both with symbols):
- the thingino vendor image build (`ingenic-sdk` prebuilt, `.data` 189632 bytes): what the camera runs as the vendor
  stack in every vendor-vs-open comparison. This is the reference (`T40_OEM_KO`) for all oracles.
- the factory Eufy firmware module (`.data` 190016 bytes): the one the old mechanical translation of the CT/EV colour chain
  came from (removed 2026-11-03, #85: the chain is the checked C of `tx_isp_t40_ct_chain.h`).

Function-level diff (instructions with relocations compared by symbol, `jr`/`jr.hb` and trailing `nop` ignored):
974 functions identical, 186 differ, 26 only in the factory build, 29 only in the vendor image build.
- Identical in both: every function of the CT/EV colour chains and their init (`tisp_ct_update`, `tisp_ccm_main_ct_update`,
  `tisp_ccm_main_ev_update`, `tisp_ccm_ev_ct_update`, `tisp_lsc_ct_update`, `tisp_lsc_real_write_lut`, `tisp_bcsh_main_ct_update`,
  `tisp_bcsh_main_ev_update`, `tisp_ccm_main_init`, `tisp_bcsh_main_init`, `tisp_lsc_init`, `tisp_clm_ct_update`) and the 26 `.data`
  objects that init reads (CSC tables, `stMainBcshInterOri`, `stMainCcmInterOri`).
- Different, used by an oracle: `tisp_awb_main_process`, `tisp_awb_params_refresh`, `tisp_awb_main_ev_update` (factory: wide/tele
  dual-sensor AWB; `tisp_awb_calc_tele_gain`, `tisp_awb_set_wide_tele`, `awb_wide_tele_para*` exist only there), `tisp_mdns_func_en`,
  `tisp_g_draw_attr`, `isp_vic_interrupt_service_routine`. All oracles pass with the vendor image build; see the #85 comment of
  2026-11-03 for the run with the factory module.
- Different elsewhere: AE (25 functions, flicker detect / AE step API only in one build each), CLM parameter get/set and `ct_interp`,
  GIB/BLC print helpers, MSCA, VIC/ISP core glue.

## t40_bcsh_dn_host

- `t40_vct_host` (host run of the mechanically translated CT/EV chain) was removed on 2026-11-03 together with that translation
  (#85); `t40_ct_chain_host` checks the C chain against the OEM instructions.
- `t40_bcsh_dn_host` is not a mismatch: the strict run failed because the `external/ingenic-sdk` submodule is not initialised, so the
  default tuning bin is missing. With any T40 tuning bin it passes (0 words differ), e.g. the Ingenic T40 SDK `resource/sensor_settings_t40/gc2053-t40.bin`
  (also sc200ai, os08a10, gc4653: all PASS): `T40_TUNING_BIN=<bin> make -C tests t40_bcsh_dn_host`.

## BLC (2026-11-03)

`t40_blc_host` covers `driver/t40/tx_isp_t40_blc.h`: `ag_interp`, `calc_digital_gain`, `write_reg`, `ag_long/short_frame_update`,
`ae_write_dgain`, `init`, `dn_params_refresh` and the gain-parameter entry the `enable_blc_lit` path uses (1000 calls per function, both
channels, black-level values at 0/0x7ff/0x800/0xfff/0x1000/0xffff, gains on the 1024 hysteresis step and on the 16.16 index limits, digital-gain
terms on the shift-ladder boundaries, Bayer types 0-3 and out-of-range, 48 source mutations that must be detected). The OEM divides by
zero for a maximum black level of exactly 4096 (undefined result): those calls are counted as skipped, the C returns 8192 there.
BLC is gated by the bypass flag of the sensor bin (the Eufy sc830ai bypasses it): the oracle proves the code, the effect on a picture needs a
sensor with BLC switched on.

## AE leaf and parameter functions (2026-11-03, #85 class A/B)

`t40_ae_leaf_host` covers `driver/t40/tx_isp_t40_ae_leaf.h`: `tisp_ae_g_luma`, `g_comp`, `get_state`, `sensor_trig`, `ev_start_set`,
`algo_deinit_internal`, `get_hist_bin`, `set_hist_bin`, `get_y_zone`, `g_scene_luma`, `s_comp`, `api_set_exp_list`, `tisp_s_ae_explist`,
`tisp_s_ae_exprinfo_attr`, `tisp_s_ae_scence_attr`, `tisp_g_ae_scence_attr` (1000 calls per function on a random universe: both 0x164-byte AE contexts
with their pointer fields aimed at random buffers, the stM/SAeOuter blocks, ae_cache, tparamsN, tisp_tattr, hist-last arrays; every byte of the test heap
and of the globals, the return value and the calls to the not-converted callees and the AE locks are compared; 60 source mutations that must be detected).
`tisp_ae_sensor_trig`, `ev_start_set` and (through it) `s_scence_attr` differ between the two Eufy builds: the vendor image moved the ae_cache fields (trigger flag
at +1296 instead of +1292) and stores `ae_cache[ch] + 1297` in ev_start_set. The driver uses the factory layout, so those three are compared with the factory module
(`T40_OEM_KO_FAC`); without it they are not compared (a note, a failure with `T40_ORACLE_STRICT=1`). Skipped calls: an empty zone geometry (OEM `divu` by zero).

Class C (2026-11-04, #204 part 2): `tisp_ae_roi_point` and `tisp_ae_sepc_area` (vendor image `0x3175c` / `0x39c98`) are in the same header and oracle; `system_reg_write` and
`isp_printf` are logged on both sides (register, value, message text, arguments), 19 more mutations. The vendor image is the reference. The factory build differs: its
`tisp_ae_roi_point` has no early return on a bad or too large window (it prints and then writes the registers anyway; `roi_point_fac` compares only the valid-window
path with it) and its `tisp_ae_sepc_area` is another body (other clamp/store order, extra `printk`), so that one is not compared with it. Skipped calls: a zero frame size
(OEM division by zero in `fix_point_div_32`).
