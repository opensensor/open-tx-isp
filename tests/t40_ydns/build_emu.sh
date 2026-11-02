#!/bin/bash
# tests/t40_ydns/build_emu.sh <mipsel-linux-gcc> <out.o> [recovered.c] : the hand-written C YDNS block of driver/t40/tx_isp_t40_recovered.c
# (tisp_ydns_reg_cfg up to the comment of tisp_ydns_main_init) as a mipsel relocatable object (ydns_emu.c); the block is cut out of the driver
# source, so the object is exactly what the module compiles (a mutated copy of the source can be passed as the 3rd argument)
set -e
HERE=$(cd "$(dirname "$0")" && pwd); SRC=${3:-$HERE/../../driver/t40/tx_isp_t40_recovered.c}; W=$(mktemp -d); trap 'rm -rf $W' EXIT
awk '/^int32_t tisp_ydns_reg_cfg\(uint32_t a0\)$/ {p=1} /original=tisp_ydns_main_init/ {p=0} p {print}' "$SRC" > $W/ydns.inc
test "$(wc -l < $W/ydns.inc)" -gt 150 || { echo "build_emu: YDNS block not found in $SRC" >&2; exit 1; }
$1 -O1 -g0 -march=mips32r2 -msoft-float -fno-pic -mno-abicalls -G0 -mno-shared -mlong-calls -fno-strict-aliasing -Wall -Wno-unused-variable -Werror \
	-DYDNS_INC="\"$W/ydns.inc\"" $HERE/ydns_emu.c -c -o $2
