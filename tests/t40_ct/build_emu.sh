#!/bin/bash
# tests/t40_ct/build_emu.sh <mipsel-linux-gcc> <out.o> [header-dir] : the C CT/EV consumers (tx_isp_t40_ct_chain.h) as a mipsel relocatable object (ct_emu.c)
set -e
HERE=$(cd "$(dirname "$0")" && pwd); D=${3:-$HERE/../../driver/t40}; W=$(mktemp -d); trap 'rm -rf $W' EXIT
for f in fix_point_mult2_32; do
	awk -v f="$f" '!p && $0 ~ "^int(32|64)_t " f "\\(" && $0 !~ /;$/ {p=1} p {print} p && /^}/ {exit}' $HERE/../../driver/t40/tx_isp_t40_recovered.c
done > $W/cfix.inc
$1 -O1 -g0 -march=mips32r2 -msoft-float -fno-pic -mno-abicalls -G0 -mno-shared -mlong-calls -fno-strict-aliasing -Wall -Werror -Wno-unused-function \
	-DCFIX_INC="\"$W/cfix.inc\"" -I$D $HERE/ct_emu.c -c -o $2
