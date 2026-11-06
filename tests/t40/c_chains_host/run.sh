#!/bin/sh
# T40 C chains vs the literal OEM chains on the host.
#   run.sh <chain> <sensor-t40.bin>...      chain: dpc
# The literal reference is taken from git (LIT_REF, the last commit that built it into the driver).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
REPO=$(cd "$HERE/../../.." && pwd)
LIT_REF=${LIT_REF:-6d63667b}
CHAIN=$1; shift
OUT=$(mktemp -d "${TMPDIR:-/tmp}/t40_c_chains.XXXXXX")
mkdir -p "$OUT/lit"
case "$CHAIN" in
dpc) git -C "$REPO" show "$LIT_REF:driver/t40/tx_isp_t40_dpc_lit.inc" | sed 's/regtrace_t40_dpc_on/lit_t40_dpc_on/g' > "$OUT/lit/dpc_lit.inc" ;;
lce) git -C "$REPO" show "$LIT_REF:driver/t40/tx_isp_t40_lce_lit.inc" | sed 's/regtrace_t40_lce_on/lit_t40_lce_on/g' > "$OUT/lit/lce_lit.inc" ;;
sdns) git -C "$REPO" show "$LIT_REF:driver/t40/tx_isp_t40_sdns_lit.inc" > "$OUT/lit/sdns_lit.inc" ;;
adr) git -C "$REPO" show "${LIT_REF_ADR:-7471ad73}:driver/t40/tx_isp_t40_adr_lit.inc" | sed 's/regtrace_t40_adr_on/lit_t40_adr_on/g' > "$OUT/lit/adr_lit.inc" ;;
defog) git -C "$REPO" show "${LIT_REF_DEFOG:-1bc9b8e2}:driver/t40/tx_isp_t40_defog_lit.inc" | sed 's/regtrace_t40_defog_on/lit_t40_defog_on/g' > "$OUT/lit/defog_lit.inc" ;;
cdns) git -C "$REPO" show "${LIT_REF_CDNS:-e96b92ea}:driver/t40/tx_isp_t40_cdns_lit.inc" | sed 's/regtrace_cdns_/lit_cdns_/g; s/regtrace_enable_cdns/lit_enable_cdns/g; s/regtrace_t40_cdns_top_bit/lit_t40_cdns_top_bit/g; s/lit_cdns_thresh = 0x10000U;/lit_cdns_thresh = 256U;/' > "$OUT/lit/cdns_lit.inc" ;;   # 2026-11-06: the OEM .data word gain_thres is 0x100 at load (not the 0x10000 of the old lift)
bcsh) git -C "$REPO" show "${LIT_REF_BCSH:-e96b92ea}:driver/t40/tx_isp_t40_bcsh_lit.inc" | sed 's/regtrace_bcsh_/lit_bcsh_/g; s/regtrace_enable_bcsh/lit_enable_bcsh/g' > "$OUT/lit/bcsh_lit.inc"
      git -C "$REPO" show "${LIT_REF_BCSH:-e96b92ea}:driver/t40/tx_isp_t40_recovered.c" | awk '/^static unsigned char __attribute__\(\(aligned\(4\)\)\) (au16|as32)BT/{p=1} p{print} p&&/^};/{p=0}' > "$OUT/lit/csc_tables.inc" ;;
*) echo "unknown chain $CHAIN"; exit 2 ;;
esac
# count inputs where the OEM code is undefined: divisions by zero (MIPS result unpredictable),
# LCE histogram knots past bin 31 (the OEM writes past its stack array)
sed -i -E 's/if \((r_[a-z0-9]+)\) \{ mips_lo =/if (!\1) lit_ub++; if (\1) { mips_lo =/' "$OUT/lit/"*.inc
[ "$CHAIN" = lce ] && sed -i -E '/^static int32_t lce_hist_method_lit\(uint32_t a0_in.*\)$/{n;s/^\{$/{ if (((uint32_t *)(uintptr_t)a2_in)[2] > 31) lit_ub++;/}' "$OUT/lit/lce_lit.inc"

cc -O0 -g -no-pie -fno-pie -w -pthread $XCFLAGS -I"$OUT" -o "$OUT/t" "$HERE/$CHAIN.c"
rc=0
"$OUT/t" "$@" || rc=1
[ -n "$KEEP" ] && echo "kept $OUT" || rm -rf "$OUT"
exit $rc
