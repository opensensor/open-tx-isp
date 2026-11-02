#!/bin/bash
# tests/t40_lsc/build_emu.sh <mipsel-linux-gcc> <out.o> [lsc_lit.inc] : the hand-written C LSC chain of driver/t40/tx_isp_t40_lsc_lit.inc
# (bank state, valid_judge, interp_by_ct / interp_by_gain, write_reg, real_write_lut) as a mipsel relocatable object (lsc_emu.c); the block is
# cut out of the driver source, so the object is exactly what the module compiles (a mutated copy can be passed as the 3rd argument)
set -e
HERE=$(cd "$(dirname "$0")" && pwd); SRC=${3:-$HERE/../../driver/t40/tx_isp_t40_lsc_lit.inc}; W=$(mktemp -d); trap 'rm -rf $W' EXIT
awk '/^#define LSC_LIT_TOOL_BYTES/ {p=1} /OEM tisp_lsc_init\(bank, width, height\)/ {p=0} p {print}' "$SRC" | head -n -1 > $W/lsc.inc
test "$(wc -l < $W/lsc.inc)" -gt 250 || { echo "build_emu: LSC block not found in $SRC" >&2; exit 1; }
$1 -O1 -g0 -march=mips32r2 -msoft-float -fno-pic -mno-abicalls -G0 -mno-shared -mlong-calls -fno-strict-aliasing -Wall -Wno-unused-function -Werror \
	-DLSC_INC="\"$W/lsc.inc\"" $HERE/lsc_emu.c -c -o $2
