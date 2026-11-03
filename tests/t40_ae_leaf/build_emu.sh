#!/bin/bash
# tests/t40_ae_leaf/build_emu.sh <mipsel-linux-gcc> <out.o> [header-dir] : the C AE leaf block as a mipsel relocatable object (ae_leaf_emu.c)
set -e
HERE=$(cd "$(dirname "$0")" && pwd); D=${3:-$HERE/../../driver/t40}
$1 -O1 -g0 -march=mips32r2 -msoft-float -fno-pic -mno-abicalls -G0 -mno-shared -mlong-calls -fno-strict-aliasing -Wall -Werror \
	-I$D $HERE/ae_leaf_emu.c -c -o $2
