#!/bin/bash
# Regenerate driver/t40/tx_isp_t40_vawb_gen.inc (vendor AWB, t40_vawb=1, plus the CT/EV colour
# chains, t40_ct_chains=1) and tests/t40_vct/vct_init_gen.inc (host-only OEM CCM/BCSH/LSC init).
#   gen.sh <OEM tx-isp-t40.ko with symbols (Eufy T8416 firmware)> <mipsel-linux-objdump>
# The reference module is not part of this repository.
set -e
KO=$1; OBJDUMP=$2; OBJCOPY=${OBJDUMP%objdump}objcopy
HERE=$(cd "$(dirname "$0")" && pwd); W=$(mktemp -d)
$OBJDUMP -dr "$KO" > $W/sdk.dis
$OBJDUMP -t "$KO" | awk 'NF>=5 && $0 ~ /^[0-9a-f]{8}/ {sec=$(NF-2); if (sec ~ /^\.(bss|data|rodata|sbss)$/) print sec, $1, $(NF-1), $NF}' > $W/secmap.txt
$OBJCOPY -O binary --only-section=.rodata "$KO" $W/rodata.bin
$OBJDUMP -r -j .rodata "$KO" > $W/rodata.rel
OUT=$HERE/../../driver/t40/tx_isp_t40_vawb_gen.inc
ADAPT="system_reg_read div64_u64 __lshrdi3 __ashldi3"
# AWB chain (per frame) + the event-13/8 colour chains: tisp_ct_update (TOP-gated CCM/LSC/BCSH/CLM),
# ccm/bcsh main_ct/main_ev_update, lsc_ct_update + real_write_lut; tisp_clm_ct_update stays the
# driver's literal CLM (VAE_STOP -> vawb_s_ adapter).  tisp_awb_ct_detect (with its helpers ~65 % of
# the translated per-frame AWB work, issue 133) is the driver's C translation tx_isp_t40_awb_ctd.inc,
# bit-exact with the OEM code (tests/t40_vawb/vawb_host.c ctd mode).  tisp_awb_long_alogrithm (the
# per-frame zone pass that calls ct_detect) is the C translation tx_isp_t40_awb_long.inc (LA_REF mode,
# issue 133); its callee tisp_awb_sat_weight stays translated (root below).  tisp_awb_set_gain, tisp_awb_tgain_update,
# tisp_awb_set_regional_threshold and tisp_awb_set_lum_th_freq (with gain_reg, simple_intp, the AE mean update and
# system_reg_set_awb_trig) are the C translation tx_isp_t40_awb_gain.inc (GR_REF mode, issue 85); the OEM tele-gain
# branch of set_gain (single sensor: never taken) is gone.
VAE_IN=$W VAE_OUT=$W/gen.inc VAE_DATA=$HERE/data.json VAE_TRACE="${VAE_TRACE:-}" \
VAE_ADAPT="$ADAPT" VAE_STOP="tisp_clm_ct_update tisp_awb_ct_detect tisp_awb_long_alogrithm tisp_awb_set_gain tisp_awb_tgain_update tisp_awb_set_regional_threshold tisp_awb_set_lum_th_freq" python3 -I "$HERE/asm2c.py" \
	tisp_awb_main_process tisp_awb_get_statistics tisp_awb_params_transmit tisp_awb_params_refresh \
	tisp_awb_set_hardware_param tisp_awb_dn_params_refresh tisp_awb_main_ev_update \
	tisp_awb_sat_weight \
	tisp_ct_update tisp_ccm_main_ct_update tisp_ccm_main_ev_update tisp_ccm_ev_ct_update \
	tisp_lsc_ct_update tisp_lsc_real_write_lut tisp_bcsh_main_ct_update tisp_bcsh_main_ev_update \
	tisp_bcsh_ct_update tisp_bcsh_ev_update 2> $W/gen.err
cat $W/gen.err >&2
sed -e 's/\bvae_/vawb_/g' $W/gen.inc > $OUT
# host-only OEM init of the colour contexts (tests/t40_vct_host.sh); everything already in the
# device set is a VAE_STOP reference (vae_s_X -> vawb_X in the harness)
DONE=$(sed -n 's/^functions [0-9]*: //p' $W/gen.err)
VAE_IN=$W VAE_OUT=$W/init.inc VAE_DATA=$HERE/data.json VAE_ADAPT="$ADAPT private_vmalloc private_kmalloc private_spin_lock_init" VAE_DATA_BLOB=h_oem_data \
VAE_STOP="$DONE" python3 -I "$HERE/asm2c.py" tisp_ccm_main_init tisp_bcsh_main_init tisp_lsc_init
sed -e 's/\bvae_s_/vawb_/g' -e 's/\bvae_/vawb_/g' -e '/^static const u8 vawb_rodata/d' $W/init.inc > $HERE/../../tests/t40_vct/vct_init_gen.inc
rm -rf $W
