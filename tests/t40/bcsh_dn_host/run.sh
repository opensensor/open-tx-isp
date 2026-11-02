#!/bin/sh
# T40 day/night: BCSH day registers after day->night(saturation 0)->day x3 must equal the boot day ones.
# run.sh [<sensor-t40.bin> [ev]]
# Without a bin: T40_TUNING_BIN, else the pinned SDK submodule's sensor-iq/t40/gc2053.bin, else SKIP (make check).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
if [ $# -eq 0 ]; then
	BIN=${T40_TUNING_BIN:-$HERE/../../../external/ingenic-sdk/sensor-iq/t40/gc2053.bin}
	[ -r "$BIN" ] || { echo "t40_bcsh_dn_host: SKIP (no T40 tuning bin: set T40_TUNING_BIN or init external/ingenic-sdk)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; }
	set -- "$BIN"
fi
OUT=${TMPDIR:-/tmp}/t40_bcsh_dn_host.$$
mkdir -p "$OUT"
cc -O0 -no-pie -fno-pie -w -pthread -o "$OUT/t" "$HERE/main.c"
rc=0
"$OUT/t" "$@" || rc=1
rm -rf "$OUT"
exit $rc
