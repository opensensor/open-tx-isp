#!/bin/sh
# t40_ae_target_host.sh: driver/t40/tx_isp_t40_ae_target.h (AE target / metering like the OEM, #84) against the OEM instructions of
# tisp_ae_long_target, tisp_ae_long_weight_mean2, tisp_ae_long_alogrithm (band parameters, highlight term), tisp_ae_long_tune2 (target lists,
# EV at both target lookups) and tisp_ae_s_comp (Unicorn, tools/ko_emu/diff_ae_target.py), plus one-token mutations of the header that must
# be detected.  Needs T40_OEM_KO and python3 unicorn + pyelftools, else SKIP.
H=$(cd "$(dirname "$0")" && pwd); f=$H/../driver/t40/tx_isp_t40_ae_target.h
# host part (no vendor file): the inverse gamma (t40_aet_ginv_build) is the nearest inverse of t40_aet_gamma8 on an identity,
# a gamma-0.45-like, a flat-stretch and the open built-in curve; a falling curve is refused
W0=$(mktemp -d); cc -O1 -Wall -Werror -DAE_TARGET_H="\"$f\"" -o "$W0/h" "$H/t40_ae_target/harness.c" || { rm -rf "$W0"; echo "t40_ae_target_host: FAIL (build)"; exit 1; }
r=$(python3 - <<'PY' | "$W0/h"
c1 = [min(4095, 32 * i) for i in range(129)]
c2 = [round(4095 * (i / 128) ** 0.45) for i in range(129)]
c3 = [min(4095, 32 * i) if i < 40 or i > 60 else 1280 for i in range(129)]; c3 = [max(c3[:k + 1]) for k in range(129)]
c4 = [0, 144, 288, 412, 526, 625, 714, 796] + [min(4095, 796 + 27 * k) for k in range(1, 122)]
c5 = list(reversed(c1))
for c in (c1, c2, c3, c4, c5): print("I " + " ".join(map(str, c)))
PY
)
rm -rf "$W0"
[ "$(echo $r)" = "0 0 0 0 invalid" ] || { echo "t40_ae_target_host: FAIL (inverse gamma: $r)"; exit 1; }
if [ ! -r "${T40_OEM_KO:-}" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_ae_target_host: SKIP (T40_OEM_KO / python3 unicorn+pyelftools missing)"; [ -z "${T40_ORACLE_STRICT:-}" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
run() {	# $1 = header, $2 = cases
	cc -O1 -Wall -Werror -DAE_TARGET_H="\"$1\"" -o "$W/h" "$H/t40_ae_target/harness.c" || return 2
	python3 "$H/../tools/ko_emu/diff_ae_target.py" "$T40_OEM_KO" "$W/h" --n "$2"
}
run "$f" ${N:-1000} || { echo "t40_ae_target_host: FAIL"; exit 1; }
nm=0; fail=0; tot=0
while IFS='@' read -r a b; do
	[ -n "$a" ] || continue
	tot=$((tot + 1))
	python3 - "$a" "$b" "$f" "$W/m.h" <<'PY' || { echo "t40_ae_target_host: mutation text not found: $a"; fail=1; continue; }
import sys
a, b, src, dst = sys.argv[1:5]; t = open(src).read()
if a not in t: sys.exit(1)
open(dst, "w").write(t.replace(a, b, 1))
PY
	if run "$W/m.h" ${NMUT:-150} > /dev/null; then echo "t40_ae_target_host: mutation NOT detected: $a => $b"; fail=1; else nm=$((nm + 1)); fi
done <<'MUT'
if (ev <= evl[0] << q)@if (ev < evl[0] << q)
return tgl[9];@return tgl[8];
if (i == 9U)@if (i == 8U)
return ta - d * (ta - tb) / span;@return ta - d * (ta - tb) / span + 1U;
ev >>= q;@ev >>= q + 1U;
return (uint16_t)((int32_t)((uint32_t)bin * comp) >> 7);@return (uint16_t)((int32_t)((uint32_t)bin * comp) >> 6);
- 0x12eU);@- 0x12dU);
evl[i] = (uint32_t)p->sc[1] * evl[i] >> 7;@evl[i] = (uint32_t)p->sc[1] * evl[i] >> 6;
* p->scw[i] * sc_word >> 14;@* p->scw[i] * sc_word >> 13;
if (!tgl[i])@if (!evl[i])
(t0 & 0xffffU) << T40_AET_Q@t0 << T40_AET_Q
} else if (p->hl[0] != 1U && scene > 2U) {@} else if (p->hl[0] != 1U && scene > 3U) {
a = scene == 2U ? p->hl[5]@a = scene == 2U ? p->hl[7]
*p10 = p->mp[6] ? p->mp[6] : 1U;@*p10 = p->mp[6] ? p->mp[6] : 2U;
uint32_t hi = (p4 - 1U) * c2[z] / p10 + wt * c2[z];@uint32_t hi = p4 * c2[z] / p10 + wt * c2[z];
den += (uint32_t)(wt * (area - (c0[z] + c2[z])) + hi + lo);@den += (uint64_t)wt * (area - (c0[z] + c2[z])) + hi + lo;
(p4 - 1U) * s2[z] / p10);@(p4 - 1U) * s1[z] / p10);
b0 = ((thr_hi << 1) / 3U) & 0xffffU;@b0 = ((thr_hi << 1) / 3U + 1U) & 0xffffU;
k = t40_aet_div32(16, (p4 - 1U) << 16, p10 << 16) & 0xffffU;@k = t40_aet_div32(16, (p4 - 1U) << 16, p10 << 16);
sum += t40_aet_mul32(5, hist[b0 + i] << 5, x >> 11) >> 5;@sum += t40_aet_mul32(5, hist[b0 + i] << 5, x >> 10) >> 5;
return (npix + sum) * luma / npix;@return (npix + sum) * luma / (npix + 1U);
MUT
[ $fail = 0 ] && echo "t40_ae_target_host: ok ($nm/$tot mutations detected)"
exit $fail
