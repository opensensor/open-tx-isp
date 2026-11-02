#!/bin/sh
# t40_algo_handle_host.sh [driver/t40] : host test of the T40 custom AE/AWB get-handle protocol (review 2026-11-03 H1), plus a
# mutation check: the test must fail when the close does not wake the waiters, when the NULL check after the wait or the
# early "not open" check is removed, or when the GET drops the lock before copy_to_user.
d=${1:-$(dirname "$0")/../driver/t40}; t=$(dirname "$0")/t40_algo
f=$d/tx_isp_t40_recovered.c
[ -f "$f" ] || { echo "usage: $0 [driver/t40]" >&2; exit 2; }
CC=${CC:-cc}; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
extract() { awk '/^static DEFINE_MUTEX\(t40_algo_mutex\);/{p=1} /^\/\* OEM 0x13128 \(ch 0\)/{p=0} p' "$1"; }
build_run() {   # $1 = source file, $2 = tag; returns the test exit code (124 = hang)
	extract "$1" > "$W/algo_block.inc"
	[ -s "$W/algo_block.inc" ] || { echo "t40_algo_handle_host: block not found" >&2; return 2; }
	$CC -std=gnu11 -O1 -Wall -Werror -Wno-unused-function -fno-pie -no-pie -I"$W" -o "$W/t" "$t/algo_handle_host.c" -lpthread || return 2
	timeout 20 "$W/t" > "$W/out.$2" 2>&1
}
build_run "$f" real; rc=$?
[ $rc = 0 ] || { echo "t40_algo_handle_host: FAIL (rc=$rc)"; cat "$W/out.real"; exit 1; }
cat "$W/out.real"
mut() {   # $1 = name, $2 = sed expression applied to the source
	sed "$2" "$f" > "$W/m.c"
	cmp -s "$f" "$W/m.c" && { echo "t40_algo_handle_host: mutation $1 did not apply"; return 1; }
	build_run "$W/m.c" "$1"; r=$?
	[ $r = 0 ] && { echo "t40_algo_handle_host: mutation $1 NOT detected"; return 1; }
	echo "t40_algo_handle_host: mutation $1 detected (rc=$r)"
}
fail=0
mut no-wake 's/^        complete_all(t40_algo_comp(awb, idx));/        (void)0;/' || fail=1
mut no-null-after-wait '/^    if (\*info == NULL) {                \/\* closed while waiting \*\//s/\*info == NULL/0/' || fail=1
mut no-open-check 's/^    ret = slot\[idx\] ? 0 : -EINVAL;      \/\* no library registered/    ret = 0;      \/\* no library registered/' || fail=1
mut unlocked-use '/^static void t40_algo_get_end(void)/,/^}/s/^    mutex_unlock(&t40_algo_mutex);/    (void)0;/; /^static int t40_algo_get_begin/,/^}/s/^    return 0;$/    mutex_unlock(\&t40_algo_mutex); return 0;/' || fail=1
mut result-unchecked 's/^    if (!t40_algo_slot(awb)\[ch\])$/    if (0)/' || fail=1
[ $fail = 0 ] && echo "t40_algo_handle_host: ok (5/5 mutations detected)"
exit $fail
