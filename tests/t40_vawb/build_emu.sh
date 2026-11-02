#!/bin/bash
# tests/t40_vawb/build_emu.sh <mipsel-linux-gcc> <out.o> : the C AWB chain as a mipsel relocatable object (awb_emu.c) for tools/ko_emu/diff_awb_chain.py
set -e
HERE=$(cd "$(dirname "$0")" && pwd); D=${T40_DRV_DIR:-$HERE/../../driver/t40}; W=$(mktemp -d); trap 'rm -rf $W' EXIT
CC=$1; OUT=$2
sed -n '/^#include "tx_isp_t40_vawb_gen.inc"/q;p' $D/tx_isp_t40_vawb.h > $W/top.h
sed -i -e 's/a >= 0x80000000U \&\& a < 0xfffff000U \&\& !(a \& align)/(a >= 0x1000U \&\& !(a \& align))/' $W/top.h
echo '#endif' >> $W/top.h
for f in fix_point_div_32 fix_point_div fix_point_mult2_32 fix_point_mult3_32; do
	awk -v f="$f" '!p && $0 ~ "^int(32|64)_t " f "\\(" && $0 !~ /;$/ {p=1} p {print} p && /^}/ {exit}' $D/tx_isp_t40_recovered.c
done > $W/cfix.inc
$CC -O1 -g0 -march=mips32r2 -msoft-float -fno-pic -mno-abicalls -G0 -mno-shared -mlong-calls -fno-strict-aliasing -w -c \
	-DVAWB_TOP="\"$W/top.h\"" -DCFIX_INC="\"$W/cfix.inc\"" -DCTD_INC="\"$D/tx_isp_t40_awb_ctd.inc\"" $([ -r $D/tx_isp_t40_awb_main.inc ] && echo -DHAVE_AWB_MAIN) -I$D $HERE/awb_emu.c -o $OUT
