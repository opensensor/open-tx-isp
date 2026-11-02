#!/bin/bash
# Host run of the translated T40 OEM colour chains (t40_ct_chains):
#   tests/t40_vct_host.sh <tuning.bin> <oem data.bin> [verbose]
# (oem data.bin = objcopy -O binary --only-section=.data of the OEM tx-isp-t40.ko)
# Without arguments: T40_TUNING_BIN / T40_OEM_DATA from the environment, SKIP when absent (make check).
set -e
HERE=$(cd "$(dirname "$0")" && pwd); D=$HERE/../driver/t40
BIN=${1:-$T40_TUNING_BIN}; DAT=${2:-$T40_OEM_DATA}
if [ ! -r "$BIN" ] || [ ! -r "$DAT" ]; then echo "t40_vct_host: SKIP (no tuning bin / OEM .data: set T40_TUNING_BIN and T40_OEM_DATA)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
# the generated init code addresses the OEM .data by fixed offsets: only the .data of the exact build it was lifted from (190016 bytes) fits
if [ "$(stat -c %s "$DAT")" != 190016 ]; then echo "t40_vct_host: SKIP (OEM .data is $(stat -c %s "$DAT") bytes, the harness needs the 190016-byte .data of the vendor build it was lifted from; see tests/README.oracles.md)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
sed -n '/^#include "tx_isp_t40_vawb_gen.inc"/q;p' $D/tx_isp_t40_vawb.h > $W/top.h
sed -i -E -e 's/a >= 0x80000000U \&\& a < 0xfffff000U \&\& !\(a \& align\)/harness_ok(a, align)/' \
       -e 's/tg < 0x80000000U \|\| \(tg \& 3\)/tg < 0x1000U || (tg \& 3)/' \
       -e 's/^(static u8 vawb_wide_tele_para\[144\])/\1 VD/' -e 's/^(static u32 vawb_argarea\[16\])/\1 VD/' \
       -e 's/^(static u32 vawb_tawb_custom_en\[2\]);/\1 VD;/' -e 's/^static u32 vawb_awb_num;/static u32 vawb_awb_num VD;/' \
       -e 's/^(static u32 vawb_peter_test_count\[2\]);/\1 VD;/' \
       -e 's/^static u32 vawb_converge_tele_gain = /static u32 vawb_converge_tele_gain VD = /' \
       -e 's/^static u32 vawb_wide_tele_awb_gain\[3\] = /static u32 vawb_wide_tele_awb_gain[3] VD = /' \
       -e 's/^(static (u8|u16|u32|u64) vct_[a-z_]+(\[[0-9]+\])?(, vct_[a-z_]+(\[[0-9]+\])?)*)( = |;)/\1 VD\6/' $W/top.h
echo '#endif' >> $W/top.h
sed -e 's/^static const u8 vawb_rodata\(\[[0-9]*\]\) __aligned(8)/static u8 vawb_rodata\1 __aligned(8) VD/' $D/tx_isp_t40_vawb_gen.inc > $W/gen.inc
# the C fix-point helpers of the driver (used by tx_isp_t40_awb_long.inc / _ctd.inc)
for f in fix_point_div_32 fix_point_div fix_point_mult2_32 fix_point_mult3_32; do
	awk -v f="$f" '!p && $0 ~ "^int(32|64)_t " f "\\(" && $0 !~ /;$/ {p=1} p {print} p && /^}/ {exit}' $D/tx_isp_t40_recovered.c
done > $W/cfix.inc
gcc -O1 -g0 -I"$D" -DCFIX_INC="\"$W/cfix.inc\"" -falign-functions=16 -no-pie -fno-pie -w -fno-strict-aliasing -Wl,--section-start=.vdata=0x30000000 \
	-DVAWB_TOP="\"$W/top.h\"" -DVAWB_INC="\"$W/gen.inc\"" -DVAWB_INIT="\"$HERE/t40_vct/vct_init_gen.inc\"" \
	$HERE/t40_vct/vct_host.c -o $W/vct_host
$W/vct_host "$BIN" "$DAT" ${3:-0}
