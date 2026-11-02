#!/bin/bash
# Host test of the translated T41 defog (t41_dfg/dfg_host_test.c).
#   t41_dfg_host.sh [tuning-bin]    (DFG_BIN as alternative)
set -e
HERE=$(cd "$(dirname "$0")" && pwd); REPO=$HERE/..; W=$(mktemp -d); [ -n "$KEEP" ] || trap "rm -rf $W" EXIT
BIN=${1:-${DFG_BIN:-}}
[ -r "$BIN" ] || { echo "t41_dfg_host: SKIP (set DFG_BIN=<sc5336-t41.bin> or pass the tuning bin as argument)"; exit 0; }
# vae.h up to the generated include = guards + external leaves; the guard
# range check becomes the harness one (host pointers are below 2 GB)
sed -n '/^#include "tx_isp_t41_vae_gen.inc"/q;p' $REPO/driver/t41/tx_isp_t41_vae.h > $W/top.h
sed -i -e 's/a >= 0x80000000U \&\& a < 0xfffff000U \&\& !(a \& align)/harness_ok(a, align)/' \
       -e 's/tg < 0x80000000U || (tg \& 3)/tg < 0x10000U || (tg \& 3)/' $W/top.h
echo '#endif' >> $W/top.h
grep -q harness_ok $W/top.h
# dfg.h: the host has no kernel pointer range either
sed -e 's/a >= 0x80000000U \&\& a < 0xfffff000U/a >= 0x10000U \&\& a < 0x80000000U/' \
    -e 's/^static u32 dfg_bss\[64\] __aligned(8);/u32 dfg_bss[64] __aligned(8);/' $REPO/driver/t41/tx_isp_t41_dfg.h > $W/tx_isp_t41_dfg.h
cp $REPO/driver/t41/tx_isp_t41_dfg_gen.inc $REPO/driver/t41/tx_isp_t41_dfg_rodata.inc $W/
grep '^static const u8 vae_rodata' $REPO/driver/t41/tx_isp_t41_vae_gen.inc > $W/rodata.h
gcc -O1 -g0 -falign-functions=16 -no-pie -fno-pie -w -fno-strict-aliasing -I$W -DVAE_TOP="\"$W/top.h\"" $HERE/t41_dfg/dfg_host_test.c -o $W/t
setarch -R $W/t "$BIN"
