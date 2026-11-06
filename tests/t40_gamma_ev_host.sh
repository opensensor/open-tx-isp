#!/bin/sh
# t40_gamma_ev_host.sh: driver/t40/tx_isp_t40_gamma_ev.h (gamma EV follow-up, #204) against the OEM instructions of
# tisp_gamma_interp_by_ev / tisp_gamma_strength_transform / tisp_gamma_ev_update (Unicorn, tools/ko_emu/diff_gamma_ev.py),
# plus one-token mutations of the header that must be detected.  Needs T40_OEM_KO and python3 unicorn + pyelftools, else SKIP.
H=$(cd "$(dirname "$0")" && pwd); f=$H/../driver/t40/tx_isp_t40_gamma_ev.h
if [ ! -r "${T40_OEM_KO:-}" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_gamma_ev_host: SKIP (T40_OEM_KO / python3 unicorn+pyelftools missing)"; [ -z "${T40_ORACLE_STRICT:-}" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
run() {	# $1 = header, $2 = cases
	cc -O1 -Wall -Werror -DGAMMA_EV_H="\"$1\"" -o "$W/h" "$H/t40_gamma_ev/harness.c" || return 2
	python3 "$H/../tools/ko_emu/diff_gamma_ev.py" "$T40_OEM_KO" "$W/h" --n "$2"
}
run "$f" ${N:-3000} || { echo "t40_gamma_ev_host: FAIL"; exit 1; }
nm=0; fail=0
while IFS='@' read -r a b; do
	[ -n "$a" ] || continue
	python3 - "$a" "$b" "$f" "$W/m.h" <<'PY' || { echo "t40_gamma_ev_host: mutation text not found: $a"; fail=1; continue; }
import sys
a, b, src, dst = sys.argv[1:5]; t = open(src).read()
if a not in t: sys.exit(1)
open(dst, "w").write(t.replace(a, b, 1))
PY
	if run "$W/m.h" ${NMUT:-600} > /dev/null; then echo "t40_gamma_ev_host: mutation NOT detected: $a => $b"; fail=1; else nm=$((nm + 1)); fi
done <<'MUT'
s = str[0];@s = str[1];
+ (d >> 1)) / d;@ + (d >> 2)) / d;
(uint32_t)str[i - 1U] * (d - k)@(uint32_t)str[i] * (d - k)
s = str[9];@s = str[8];
if (*cur != s || force) {@if (*cur != s) {
uint32_t k = (s >> 7) + s@uint32_t k = (s >> 8) + s
step = 8192U - (k << 5)@step = 8192U - (k << 4)
((v >> 7) & 1U)@((v >> 6) & 1U)
out[128] = 4095U;@out[128] = 4094U;
e = 0xffffffffU;@e = 0xfffffffeU;
if (ev_hi >> 10)@if (ev_hi >> 11)
if (*saved + freq < fnum) {@if (*saved + freq <= fnum) {
*ev_saved = ev;@*ev_saved = ev + 1;
MUT
[ $fail = 0 ] && echo "t40_gamma_ev_host: ok ($nm/13 mutations detected)"
exit $fail
