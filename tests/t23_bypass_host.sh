#!/bin/sh
# t23_bypass_host.sh : mutation check of the T23 bypass graph VIC bank ring (driver/t23/tx_isp_t23_bypass.h, Lu-Fi/openimp#129).
# tx_isp_t23_bypass_test must pass on the real header and fail on every one-token mutation below.
d=$(dirname "$0"); h=$d/../driver/t23/tx_isp_t23_bypass.h; t=$d/tx_isp_t23_bypass_test.c
CC=${CC:-cc}; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
build_run() {	# $1 = header
	$CC -std=c99 -O1 -Wall -Wextra -Wno-maybe-uninitialized -DBYPASS_H="\"$1\"" -o "$W/t" "$t" 2>"$W/cc.err" || { cat "$W/cc.err" >&2; return 2; }
	timeout 10 "$W/t" >/dev/null 2>&1
}
build_run "$h" || { echo "t23_bypass_host: FAIL on the real header"; "$W/t"; exit 1; }
fail=0
mut() {		# $1 = name, $2 = sed expression
	sed "$2" "$h" > "$W/m.h"
	cmp -s "$h" "$W/m.h" && { echo "t23_bypass_host: mutation $1 did not apply"; fail=1; return; }
	build_run "$W/m.h"; r=$?
	if [ $r = 0 ]; then echo "t23_bypass_host: mutation $1 NOT detected"; fail=1
	elif [ $r = 2 ]; then echo "t23_bypass_host: mutation $1 does not build"; fail=1
	else echo "t23_bypass_host: mutation $1 detected"; fi
}
mut qbuf-no-zero-check 's/^\tif (!addr)$/\tif (0)/'
mut queue-limit 's/if (r->q_n >= T23_BP_QUEUE)/if (r->q_n > T23_BP_QUEUE)/'
mut queue-order 's/r->queue\[(r->q_head + r->q_n) % T23_BP_QUEUE\] = addr;/r->queue[r->q_head] = addr;/'
mut pending-count 's/^\treturn r->busy_n;$/\treturn r->free_n;/'
mut start-streaming 's/^\tr->streaming = 1;$/\t(void)0;/'
mut start-empty 's/^\tif (!r->busy_n)$/\tif (0)/'
mut done-only-head 's/if (addr == cur)/if (1)/'
mut done-no-lost-irq 's/if (!r->busy_n) {/if (0) {/'
mut done-not-streaming 's/if (!r->streaming || !r->busy_n)/if (!r->busy_n)/'
mut done-stale-ignored 's/if (r->bank_addr\[r->free_q\[i\]\] == cur) {/if (0) {/'
mut done-no-refill 's/while (r->free_n \&\& r->q_n \&\& nl < T23_BP_BANKS)/while (0)/'
mut done-no-free 's/^\t\tt23_bp_free_push(r, bank);$/\t\t(void)bank;/'
mut done-deliver-count 's/^\t\tr->delivered++;$/\t\t(void)0;/'
mut free-fifo 's/u8 bank = r->free_q\[0\];/u8 bank = r->free_q[r->free_n - 1];/'
mut init-free 's/^\tr->free_n = T23_BP_BANKS;$/\tr->free_n = T23_BP_BANKS - 1;/'
exit $fail
