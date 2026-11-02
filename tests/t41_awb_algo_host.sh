#!/bin/sh
# t41_awb_algo_host.sh [driver/t41] : host test of the T41 custom AWB library protocol (Lu-Fi/openimp#195), plus a mutation check: the test
# must fail when the close does not wake the waiters, the NULL check after the wait / the "not registered" check of GET and SET is removed,
# the GET drops the lock while it uses the block, the close does not restore the white balance, the release hook ignores the owner or the
# gain limit is removed.
d=${1:-$(dirname "$0")/../driver/t41}; t=$(dirname "$0")/t41_algo
f=$d/tx_isp_t41_awb_algo.h
[ -f "$f" ] || { echo "usage: $0 [driver/t41]" >&2; exit 2; }
CC=${CC:-cc}; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
extract() { awk '/T41-AWB-ALGO-PROTOCOL-BEGIN/{p=1;next} /T41-AWB-ALGO-PROTOCOL-END/{p=0} p' "$1"; }
build_run() {   # $1 = source file, $2 = tag; returns the test exit code (124 = hang)
	{ echo '#define T41_AWB_ALGO_COOKIE 0x336acU'; echo '#define T41_AWB_ALGO_INFO_BYTES 2732U'; echo '#define T41_AWB_ALGO_GAIN_MIN 0x200U'; echo '#define T41_AWB_ALGO_GAIN_MAX 0x1800U'
	  echo 'static void t41_awb_algo_init_attr(u32 attr[5]); static void t41_awb_algo_fill_info(unsigned char *info); static int t41_awb_algo_apply(u32 r, u32 b); static void t41_awb_algo_restore(void);'
	  extract "$1"; } > "$W/awb_block.inc"
	grep -q t41_awb_algo_lock "$W/awb_block.inc" || { echo "t41_awb_algo_host: block not found" >&2; return 2; }
	$CC -std=gnu11 -O1 -Wall -Werror -Wno-unused-function -Wno-unused-variable -fno-pie -no-pie -I"$W" -o "$W/t" "$t/awb_algo_host.c" -lpthread || return 2
	( timeout 30 "$W/t" > "$W/out.$2" 2>&1 ) 2>/dev/null
}
build_run "$f" real; rc=$?
[ $rc = 0 ] || { echo "t41_awb_algo_host: FAIL (rc=$rc)"; cat "$W/out.real"; exit 1; }
cat "$W/out.real"
mut() {   # $1 = name, $2 = sed expression applied to the source
	sed "$2" "$f" > "$W/m.h"
	cmp -s "$f" "$W/m.h" && { echo "t41_awb_algo_host: mutation $1 did not apply"; return 1; }
	build_run "$W/m.h" "$1" 2>/dev/null; r=$?
	[ $r = 0 ] && { echo "t41_awb_algo_host: mutation $1 NOT detected"; return 1; }
	echo "t41_awb_algo_host: mutation $1 detected (rc=$r)"
}
fail=0
mut no-wake 's/^\tif (t41_awb_algo_comp_ready)$/\tif (0)/' || fail=1
mut no-null-after-wait 's/^\tif (!info) {\t\t\t\t\/\* closed while waiting \*\//\tif (0) {/' || fail=1
mut no-open-check 's/^\tret = t41_awb_algo_info ? 0 : -EINVAL;/\tret = 0;/' || fail=1
mut unlocked-use 's/^\tt41_awb_algo_fill_info(info + 8);/\tmutex_unlock(\&t41_awb_algo_lock); t41_awb_algo_fill_info(info + 8); mutex_lock(\&t41_awb_algo_lock);/' || fail=1
mut result-unchecked 's/^\tif (!t41_awb_algo_info) {\t\t\/\* a late result/\tif (0) {\t\t\/* a late result/' || fail=1
mut no-restore 's/^\t\tt41_awb_algo_restore();/\t\t(void)0;/' || fail=1
mut release-any-file 's/t41_awb_algo_owner == file/1/' || fail=1
mut no-gain-limit 's/ && u\[3\] >= T41_AWB_ALGO_GAIN_MIN && u\[3\] <= T41_AWB_ALGO_GAIN_MAX && u\[4\] >= T41_AWB_ALGO_GAIN_MIN && u\[4\] <= T41_AWB_ALGO_GAIN_MAX//' || fail=1
mut no-gain-min 's/u\[3\] >= T41_AWB_ALGO_GAIN_MIN \&\& //' || fail=1
mut reinit-completion 's/^\tif (!t41_awb_algo_comp_ready) {/\tif (1) {/' || fail=1
mut double-wake 's/ && !READ_ONCE(t41_awb_algo_comp.done)//' || fail=1
[ $fail = 0 ] && echo "t41_awb_algo_host: ok (11/11 mutations detected)"
exit $fail
