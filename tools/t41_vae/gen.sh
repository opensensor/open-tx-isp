#!/bin/bash
# Regenerate driver/t41/tx_isp_t41_vae_gen.inc (vendor AE, t41_vendor_ae=1).
#   gen.sh <tx-isp-t41.ko with symbols, H20250310a SDK build> <mipsel-linux-objdump>
# The reference module is the ingenic-sdk build of the same version as the
# lift; it is not part of this repository.
set -e
KO=$1; OBJDUMP=$2; OBJCOPY=${OBJDUMP%objdump}objcopy
HERE=$(cd "$(dirname "$0")" && pwd); W=$(mktemp -d)
$OBJDUMP -dr "$KO" > $W/sdk.dis
$OBJDUMP -t "$KO" | awk 'NF>=5 && $0 ~ /^[0-9a-f]{8}/ {sec=$(NF-2); if (sec ~ /^\.(bss|data|rodata|sbss)$/) print sec, $1, $(NF-1), $NF}' > $W/secmap.txt
$OBJCOPY -O binary --only-section=.rodata "$KO" $W/rodata.bin
$OBJDUMP -r -j .rodata "$KO" > $W/rodata.rel
VAE_IN=$W VAE_OUT=$HERE/../../driver/t41/tx_isp_t41_vae_gen.inc python3 -I "$HERE/asm2c.py" \
	tisp_ae_calc_process tisp_ae_roi_point \
	sensor_set_integration_time sensor_alloc_analog_gain sensor_set_analog_gain \
	sensor_alloc_integration_time sensor_start_changes sensor_end_changes \
	sensor_alloc_digital_gain sensor_set_digital_gain sensor_set_integration_time_short \
	sensor_alloc_analog_gain_short sensor_set_analog_gain_short sensor_alloc_integration_time_short \
	tisp_clm_write_csc_para tisp_clm_ct_interp tisp_clm_write_lut \
	tisp_ae_algo_init tisp_ae_algo_handle tisp_ae_algo_deinit_internal
rm -rf $W
