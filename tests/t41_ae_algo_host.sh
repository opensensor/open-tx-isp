#!/bin/sh
# t41_ae_algo_host.sh [driver/t41] : host test of the T41 custom AE library protocol incl. the tx_isp_release hook (extra beyond the vendor), plus
# a mutation check: the test must fail when the unregister does not wake the waiters, the release ignores the owner or does nothing, the get does
# not check the registration, the NULL check after the wait is removed, the get drops the lock while it uses the block, the close does not clear
# the pointer / frees twice, the completion is initialised on every open or the late result is accepted.
d=${1:-$(dirname "$0")/../driver/t41}; t=$(dirname "$0")/t41_algo
f=$d/tx_isp_t41_vae.h
[ -f "$f" ] || { echo "usage: $0 [driver/t41]" >&2; exit 2; }
CC=${CC:-cc}; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
extract() { awk '/T41-AE-ALGO-PROTOCOL-BEGIN/{p=1;next} /T41-AE-ALGO-PROTOCOL-END/{p=0} p' "$1"; }
build_run() {   # $1 = source file, $2 = tag; returns the test exit code (124 = hang)
	{ echo '#define T41_AE_ALGO_COOKIE 0x336acU'; echo '#define T41_AE_ALGO_INFO_BYTES 2002U'
	  echo '#define T41_AE_ALGO_COMP ((struct completion *)(void *)ae_algo_comp_storage)'
	  echo 'static int t41_ae_algo_hw_precheck(const u32 *u); static int t41_ae_algo_hw_register(u32 *u); static void t41_ae_algo_hw_unregister(u32 ch); static int t41_ae_algo_hw_fill(unsigned char *b); static int t41_ae_algo_hw_set(u32 *u);'
	  extract "$1"; } > "$W/ae_block.inc"
	grep -q t41_ae_algo_lock "$W/ae_block.inc" || { echo "t41_ae_algo_host: block not found" >&2; return 2; }
	$CC -std=gnu11 -O1 -Wall -Werror -Wno-unused-function -Wno-unused-variable -fno-pie -no-pie -I"$W" -o "$W/t" "$t/ae_algo_host.c" -lpthread || return 2
	( timeout 30 "$W/t" > "$W/out.$2" 2>&1 ) 2>/dev/null
}
build_run "$f" real; rc=$?
[ $rc = 0 ] || { echo "t41_ae_algo_host: FAIL (rc=$rc)"; cat "$W/out.real"; exit 1; }
cat "$W/out.real"
mut() {   # $1 = name, $2 = sed expression applied to the source
	sed "$2" "$f" > "$W/m.h"
	cmp -s "$f" "$W/m.h" && { echo "t41_ae_algo_host: mutation $1 did not apply"; return 1; }
	build_run "$W/m.h" "$1" 2>/dev/null; r=$?
	[ $r = 0 ] && { echo "t41_ae_algo_host: mutation $1 NOT detected"; return 1; }
	echo "t41_ae_algo_host: mutation $1 detected (rc=$r)"
}
fail=0
mut no-wake 's/^\t\tcomplete_all(T41_AE_ALGO_COMP);.*/\t\t(void)0;/' || fail=1
mut single-wake 's/complete_all(T41_AE_ALGO_COMP)/complete(T41_AE_ALGO_COMP)/' || fail=1
mut no-null-after-wait 's/^\tif (!info_blk) {\t\t\t\/\* closed while waiting \*\//\tif (0) {/' || fail=1
mut no-registered-check 's/^\tret = t41_ae_algo_info ? 0 : -EINVAL;.*/\tret = 0;/' || fail=1
mut unlocked-use 's/^\tret = t41_ae_algo_hw_fill(info_blk);/\tmutex_unlock(\&t41_ae_algo_lock); ret = t41_ae_algo_hw_fill(info_blk); mutex_lock(\&t41_ae_algo_lock);/' || fail=1
mut late-result 's/^\tif (!t41_ae_algo_info) {\t\t\/\* a late result after the close \*\//\tif (0) {/' || fail=1
mut release-any-file 's/t41_ae_algo_owner == file/1/' || fail=1
mut release-noop 's/^\tif (t41_ae_algo_info \&\& t41_ae_algo_owner == file)/\tif (0)/' || fail=1
mut owner-not-set 's/^\tt41_ae_algo_owner = file;/\tt41_ae_algo_owner = 0;/' || fail=1
mut no-clear-pointer 's/^\tt41_ae_algo_info = NULL;/\t(void)0;/' || fail=1
mut double-free 's/^\tkfree(blk);/\tkfree(blk); if (!t41_ae_algo_info) kfree(blk);/' || fail=1
mut reinit-completion 's/^\tif (!t41_ae_algo_comp_ready) {/\tif (1) {/' || fail=1
mut stale-wake 's/^\tT41_AE_ALGO_COMP->done = 0;.*/\t(void)0;/' || fail=1
mut no-hw-off 's/^\tt41_ae_algo_hw_unregister(0);/\t(void)0;/' || fail=1
mut keep-on-copy-fail 's/^\t\tt41_ae_algo_unregister_locked();\t\/\* the client never.*/\t\t(void)0;/' || fail=1
[ $fail = 0 ] && echo "t41_ae_algo_host: ok (15/15 mutations detected)"
exit $fail
