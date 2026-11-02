#!/bin/bash
# T40 CCM leaf converters (driver/t40/tx_isp_t40_ccm_conv.h) vs the OEM instructions of the vendor tx-isp-t40.ko in Unicorn
# (tools/ko_emu/diff_ccm_conv.py), plus a one-character mutation that must be detected (#85).
# Needs the vendor module (T40_OEM_KO) and python3 unicorn, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}
if [ ! -r "$KO" ] || ! python3 -c "import unicorn" 2>/dev/null; then echo "t40_ccm_conv_host: SKIP (T40_OEM_KO / python3 unicorn missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
python3 "$HERE/../tools/ko_emu/diff_ccm_conv.py" "$KO" --n ${N:-2000} || { echo "t40_ccm_conv_host: FAIL"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_ccm_conv.py" "$KO" --n 300 --mutate 'v >= 8192U=>v > 8192U' > /dev/null && { echo "t40_ccm_conv_host: FAIL mutation not detected"; exit 1; }
echo "t40_ccm_conv_host: ok (0 mismatches, mutation detected)"
