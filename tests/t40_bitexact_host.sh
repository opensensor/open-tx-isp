# make check guard for the T40 bit-exact / alignment claims (review-week-1030 M5, #133, #163):
#  1. c_chains_host, every chain (adr dpc lce sdns defog cdns bcsh): the C chain vs the literal OEM chain (from
#     git), all register writes and chain state compared. Inputs are the deterministic generated tuning bins
#     "fuzz:1" "fuzz:2" (xorshift bytes, no fixture files; ~25 s per seed in total, ADR 13 s of it) plus, when
#     T40_TUNING_BIN is set, that real bin (the real-bin runs are what proves the shipped sensor tunings);
#  2. ADR once more with -fsanitize=alignment (ALIGN_TRAP): no unaligned access in the aligned-statistics C chain;
#  3. needs real data (vendor tuning bin + OEM .data, not in git), else SKIP with a message:
#     t40_vawb_host LA_REF=316259cb FUZZL=1 / CTD_REF=f2c180f7 FUZZ=1: the C tisp_awb_long_alogrithm and
#     tisp_awb_ct_detect (tx_isp_t40_awb_long.inc / _ctd.inc) against the translated OEM code on every call
#     (T40_OEM_DATA = objcopy -O binary --only-section=.data of the OEM tx-isp-t40.ko);
#  4. optional: T40_AWB_DUMPS="<device dump>..." replayed with both references (0 differ, 0 B vs device).
# The AWB harness cannot run on generated data (random tables send the translated OEM code out of its arrays).
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
BIN=${T40_TUNING_BIN:-}; DAT=${T40_OEM_DATA:-}; rc=0
SEEDS="fuzz:1 fuzz:2"; [ -r "$BIN" ] && SEEDS="$SEEDS $BIN"
for c in adr dpc lce sdns defog cdns bcsh; do
	out=$("$HERE/t40/c_chains_host/run.sh" $c $SEEDS 2>&1) || { echo "$out" | tail -5; rc=1; }
	echo "$out" | grep -q " 0 differences" || { echo "t40_bitexact_host: FAIL $c"; rc=1; }
	echo "$(echo "$out" | grep " differences" | tail -1)"
done
out=$(XCFLAGS="-DALIGN_TRAP -fsanitize=alignment -fsanitize-trap=alignment" "$HERE/t40/c_chains_host/run.sh" adr fuzz:1 2>&1) || rc=1
if echo "$out" | grep -qE '^0x[0-9a-f]+ [0-9]+'; then echo "$out" | grep -E '^0x'; echo "t40_bitexact_host: FAIL adr alignment"; rc=1
else echo "adr alignment trap: 0 unaligned accesses"; fi
if [ -r "$DAT" ] && [ -r "$BIN" ]; then
	for v in "LA_REF=316259cb FUZZL=1" "CTD_REF=f2c180f7 FUZZ=1"; do
		out=$(env $v "$HERE/t40_vawb_host.sh" "$BIN" "$DAT" 128 128 128 50 2>&1) || rc=1
		n=$(echo "$out" | grep -c "DIFF" || true); f=$(echo "$out" | grep -c "^f[0-9]* faults" || true)
		echo "vawb $v: $f frames, $n DIFF lines"
		[ "$n" = 0 ] && [ "$f" -gt 0 ] || { echo "t40_bitexact_host: FAIL vawb $v"; rc=1; }
	done
	for d in $T40_AWB_DUMPS; do
		out=$(LA_REF=316259cb CTD_REF=f2c180f7 "$HERE/t40_vawb_host.sh" replay "$d" 2>&1) || rc=1
		echo "$out" | grep -E "differ|diff vs device" | sed "s|^|$(basename "$d"): |"
		echo "$out" | grep -E "differ" | grep -vq " 0 differ" && rc=1
		echo "$out" | grep -q "inter 0 B" || rc=1
	done
else
	echo "t40_bitexact_host: vawb part SKIP (needs T40_TUNING_BIN + T40_OEM_DATA, vendor data not in git)"
fi
[ $rc = 0 ] && echo "t40_bitexact_host: PASS" || echo "t40_bitexact_host: FAIL"
exit $rc
