#!/bin/sh
# t40_wdr_log2_host.sh: tisp_wdr_log2 of the open T40 driver against the OEM instructions (unicorn), plus a mutation check.
# Needs T40_OEM_KO (vendor tx-isp-t40.ko) and T40_CC (its toolchain's gcc, for objdump); SKIP without them (make check).
H=$(cd "$(dirname "$0")" && pwd); f=$H/../driver/t40/tx_isp_t40_recovered.c
[ -r "${T40_OEM_KO:-}" ] && [ -x "${T40_CC:-}" ] || { echo "t40_wdr_log2_host: SKIP (set T40_OEM_KO and T40_CC)"; exit 0; }
OD=${T40_CC%gcc}objdump; W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
run() {   # $1 = source
	{ echo '#include <stdint.h>'; echo '#include <stdio.h>'
	  awk '/^int32_t tisp_wdr_log2\(uint32_t a0\)$/{p=1} p{print} p&&/^}$/{exit}' "$1"
	  echo 'int main(void){unsigned long long x; while(scanf("%llu",&x)==1) printf("%llu %d\n",x,tisp_wdr_log2((uint32_t)x)); return 0;}'; } > "$W/l.c"
	cc -O1 -Wall -Werror -o "$W/l" "$W/l.c" || return 2
	python3 "$H/t40_wdr/wdr_log2_oracle.py" "$T40_OEM_KO" "$OD" "$W/l"
}
run "$f" || { echo "t40_wdr_log2_host: FAIL"; exit 1; }
fail=0
for m in 's/^    for (k = 1; k < 16; k++) {$/    for (k = 0; k < 16; k++) {/' 's/if (!((int32_t)(1U << k) < (int32_t)a0))/if (!((1U << k) < a0))/' 's/^    return 15;$/    return 0;/'; do
	sed "$m" "$f" > "$W/m.c"; cmp -s "$f" "$W/m.c" && { echo "t40_wdr_log2_host: mutation did not apply: $m"; fail=1; continue; }
	run "$W/m.c" > /dev/null && { echo "t40_wdr_log2_host: mutation NOT detected: $m"; fail=1; }
done
[ $fail = 0 ] && echo "t40_wdr_log2_host: ok (3/3 mutations detected)"
exit $fail
