# make check guard for the T40 bit-exact / alignment claims (review-week-1030 M5, #133, #163):
#  1. c_chains_host, every chain (adr dpc lce sdns defog cdns bcsh): the C chain vs the literal OEM chain (from
#     git), all register writes and chain state compared. Inputs are the deterministic generated tuning bins
#     "fuzz:1" "fuzz:2" (xorshift bytes, no fixture files; ~25 s per seed in total, ADR 13 s of it) plus, when
#     T40_TUNING_BIN is set, that real bin (the real-bin runs are what proves the shipped sensor tunings);
#  2. ADR once more with -fsanitize=alignment (ALIGN_TRAP): no unaligned access in the aligned-statistics C chain;
#  3. AWB, generated inputs only (no vendor data; see below), always run:
#     t40_vawb_host LA_REF=316259cb FUZZL=1 / CTD_REF=f2c180f7 FUZZ=1: the C tisp_awb_long_alogrithm and
#     tisp_awb_ct_detect (tx_isp_t40_awb_long.inc / _ctd.inc) against the translated OEM code on every call
#     (synthetic bank + zero .data, several fuzz seeds; FUZZT = generated ct_detect tables), the gain / threshold chain
#     (tx_isp_t40_awb_gain.inc: set_gain, regional_threshold, lum_th_freq, tgain_update, simple_intp, set_awb_trig, AE mean)
#     and the statistics unpack / saturation weight (tx_isp_t40_awb_stats.inc) with GR_REF=308cfe4b FUZZP (register writes, state, faults), plus a one-character mutation of each C function that must be
#     detected; with T40_TUNING_BIN + T40_OEM_DATA (objcopy -O binary --only-section=.data of the OEM tx-isp-t40.ko)
#     the same replays also run on the real bin;
#  4. optional: T40_AWB_DUMPS="<device dump>..." replayed with both references (0 differ, 0 B vs device).
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
# AWB: generated inputs only. The synthetic "bank" is zeros plus an 88 B block of made-up frame-geometry words at
# bank+0x1122 (the only tuning bytes that steer the OEM init/ct_detect path on the host); the OEM .data is all zeros
# (verified: the real bin + zero .data gives the same flow). The statistics and state are fuzzed by the harness.
W=$(mktemp -d); trap 'rm -rf $W' EXIT
head -c 204800 /dev/zero > $W/bank.bin; head -c 190016 /dev/zero > $W/data.bin
printf "$(echo 01000000000001000000190000001900c20110000800040004000600000000000000000000000000000016010000ef00000016010000ef0000001400000096000000204e00006115000061150000e10500000a0800002001 | sed 's/../\\x&/g')" | dd of=$W/bank.bin bs=1 seek=$((16+0x1122)) conv=notrunc 2>/dev/null
awb_run() { # <driver dir or ""> <ref env> <seed env> <frames>
	T40_DRV_DIR=$1 env $2 $3 "$HERE/t40_vawb_host.sh" $W/bank.bin $W/data.bin 128 128 128 $4 2>&1 || true
}
awb_count() { n=$(echo "$1" | grep -c "DIFF" || true); f=$(echo "$1" | grep -c "^f[0-9]* faults" || true)
	calls=$(echo "$1" | sed -n 's/^[a-z_]* C vs OEM: \([0-9]*\) calls.*/\1/p' | head -1); calls=${calls:-0}; }
t0=$(date +%s)
for v in "LA_REF=316259cb FUZZL=1" "LA_REF=316259cb FUZZL=2" "LA_REF=316259cb FUZZL=3" "CTD_REF=f2c180f7 FUZZ=1 FUZZT=1" "CTD_REF=f2c180f7 FUZZ=2 FUZZM=2 FUZZT=2" "CTD_REF=f2c180f7 FUZZ=8 FUZZM=8 FUZZT=8" "CTD_REF=f2c180f7 FUZZ=10 FUZZM=10 FUZZT=10" "CTD_REF=f2c180f7 FUZZ=11 FUZZM=11 FUZZT=11" "GR_REF=308cfe4b FUZZP=1 FUZZN=30000" "GR_REF=308cfe4b FUZZP=2 FUZZN=30000" "GR_REF=308cfe4b FUZZP=3 FUZZN=30000"; do
	out=$(awb_run "" "$(echo $v | cut -d' ' -f1)" "$(echo $v | cut -s -d' ' -f2-)" 100); awb_count "$out"
	echo "vawb $v: $calls C-vs-OEM calls compared, $n DIFF lines"
	[ "$n" = 0 ] && [ "$calls" -ge 20 ] || { echo "t40_bitexact_host: FAIL vawb $v"; rc=1; }
done
# mutation check: one character in the C code of each AWB function must be detected
M=$W/mut; mkdir -p $M; cp "$HERE"/../driver/t40/*.inc "$HERE"/../driver/t40/*.h "$HERE"/../driver/t40/tx_isp_t40_recovered.c $M/
sed -i '0,/cnt1--/s//cnt1-=2/' $M/tx_isp_t40_awb_long.inc
sed -i '0,/for (i = 0; i < 14; i++)/s//for (i = 0; i < 13; i++)/' $M/tx_isp_t40_awb_ctd.inc
sed -i -e '0,/diff >= 200/s//diff >= 201/' -e '0,/cfg\[45\] << 24/s//cfg[45] << 23/' -e '0,/ov\[0\] + 64U/s//ov[0] + 63U/' -e '0,/q << 10/s//q << 9/' $M/tx_isp_t40_awb_gain.inc
sed -i -e '0,/0x3ffc00U/s//0x3ff800U/' -e '0,/a + b + n, 3,/s//a + b + n, 4,/' $M/tx_isp_t40_awb_stats.inc
cmp -s $M/tx_isp_t40_awb_long.inc "$HERE"/../driver/t40/tx_isp_t40_awb_long.inc && { echo "t40_bitexact_host: mutation 1 did not apply"; rc=1; }
cmp -s $M/tx_isp_t40_awb_ctd.inc "$HERE"/../driver/t40/tx_isp_t40_awb_ctd.inc && { echo "t40_bitexact_host: mutation 2 did not apply"; rc=1; }
cmp -s $M/tx_isp_t40_awb_gain.inc "$HERE"/../driver/t40/tx_isp_t40_awb_gain.inc && { echo "t40_bitexact_host: mutation 3 did not apply"; rc=1; }
cmp -s $M/tx_isp_t40_awb_stats.inc "$HERE"/../driver/t40/tx_isp_t40_awb_stats.inc && { echo "t40_bitexact_host: mutation 4 did not apply"; rc=1; }
out=$(awb_run $M LA_REF=316259cb FUZZL=1 100); awb_count "$out"
[ "$n" -gt 0 ] && echo "vawb mutation long_alogrithm: detected ($n DIFF lines)" || { echo "t40_bitexact_host: FAIL mutation long_alogrithm not detected"; rc=1; }
out=$(awb_run $M CTD_REF=f2c180f7 "FUZZ=2 FUZZM=2 FUZZT=2" 100); awb_count "$out"
[ "$n" -gt 0 ] && echo "vawb mutation ct_detect: detected ($n DIFF lines)" || { echo "t40_bitexact_host: FAIL mutation ct_detect not detected"; rc=1; }
out=$(awb_run $M GR_REF=308cfe4b "FUZZP=1 FUZZN=30000" 20); awb_count "$out"
[ "$n" -gt 0 ] && echo "vawb mutation gain chain: detected ($n DIFF lines)" || { echo "t40_bitexact_host: FAIL mutation gain chain not detected"; rc=1; }
echo "vawb generated-input part: $(( $(date +%s) - t0 )) s"
if [ -r "$DAT" ] && [ -r "$BIN" ]; then	# real vendor inputs (local only): same replays on the real tuning bin
	for v in "LA_REF=316259cb FUZZL=1" "CTD_REF=f2c180f7 FUZZ=1 FUZZT=1" "GR_REF=308cfe4b FUZZP=1 FUZZN=30000"; do
		out=$(env $v "$HERE/t40_vawb_host.sh" "$BIN" "$DAT" 128 128 128 50 2>&1) || rc=1
		awb_count "$out"; echo "vawb real bin $v: $f frames, $n DIFF lines"
		[ "$n" = 0 ] && [ "$f" -gt 0 ] || { echo "t40_bitexact_host: FAIL vawb real bin $v"; rc=1; }
	done
	for d in $T40_AWB_DUMPS; do
		out=$(LA_REF=316259cb CTD_REF=f2c180f7 "$HERE/t40_vawb_host.sh" replay "$d" 2>&1) || rc=1
		echo "$out" | grep -E "differ|diff vs device" | sed "s|^|$(basename "$d"): |"
		echo "$out" | grep -E "differ" | grep -vq " 0 differ" && rc=1
		echo "$out" | grep -q "inter 0 B" || rc=1
	done
fi
[ $rc = 0 ] && echo "t40_bitexact_host: PASS" || echo "t40_bitexact_host: FAIL"
exit $rc
