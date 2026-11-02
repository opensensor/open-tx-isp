#!/bin/sh
# T40 night lift: runs the driver's DMSC chain (plain C) (tx_isp_t40_dmsc.inc) on the host against
# a tuning bin and prints the DMSC registers per bank and total gain. With a register dump it compares
# 0xa000..0xa27c: run.sh <bin> [<dump> <bank 0|1> <total gain 16.16 log2>]
# (vendor .184 night dump vs night bank at 458752: only the status/trigger words 0xa18c..0xa19c differ).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
OUT=${TMPDIR:-/tmp}/t40_dmsc_night_host.$$
mkdir -p "$OUT"
cc -O0 -no-pie -fno-pie -w -pthread -o "$OUT/t" "$HERE/main.c"
rc=0
"$OUT/t" "$@" || rc=1
rm -rf "$OUT"
exit $rc
