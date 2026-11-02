#!/bin/bash
# tests/t40_gib/build_emu.sh <mipsel-linux-gcc> <out.o> [recovered.c] : the hand-written C GIB block of driver/t40/tx_isp_t40_recovered.c
# (from `static uint32_t t40_gib_AG` up to tisp_gib_dn_params_refresh) as a mipsel relocatable object (gib_emu.c); the block is cut out
# of the driver source, so the object is exactly what the module compiles (a mutated copy of the source can be passed as the 3rd argument)
set -e
HERE=$(cd "$(dirname "$0")" && pwd); SRC=${3:-$HERE/../../driver/t40/tx_isp_t40_recovered.c}; W=$(mktemp -d); trap 'rm -rf $W' EXIT
awk '/^static uint32_t t40_gib_AG\[2\]/ {p=1} /^\/\* OEM 0x36adc/ {p=0} p {print}' "$SRC" > $W/gib.inc
test "$(wc -l < $W/gib.inc)" -gt 250 || { echo "build_emu: GIB block not found in $SRC" >&2; exit 1; }
$1 -O1 -g0 -march=mips32r2 -msoft-float -fno-pic -mno-abicalls -G0 -mno-shared -mlong-calls -fno-strict-aliasing -Wall -Wno-unused-variable -Werror \
	-DGIB_INC="\"$W/gib.inc\"" $HERE/gib_emu.c -c -o $2
