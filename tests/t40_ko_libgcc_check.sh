#!/bin/sh
# t40_ko_libgcc_check.sh: the T40 module must not import a libgcc helper the kernel does not export (Eufy 1106k, 2026-11-06:
# a u64 "/" pulled __udivdi3, insmod failed "unknown symbol").  (1) driver/t40/Kbuild keeps the build-time guard (tx-isp-t40.libgcc);
# (2) every built driver/t40/*.ko (and T40_KO_CHECK="a.ko b.ko") is checked with nm (T40_NM, or ${T40_CC%gcc}nm); without nm or ko
# only (1) runs.  Allowed = the helpers the T40 kernel exports (arch/mips/lib, Module.symvers).
H=$(cd "$(dirname "$0")" && pwd); D=$H/../driver/t40
OK='__ashldi3|__ashrdi3|__lshrdi3|__cmpdi2|__ucmpdi2|__clzdi2|__ctzdi2|__clzsi2|__ctzsi2|__bswapsi2|__bswapdi2'
grep -q '^always += tx-isp-t40.libgcc' "$D/Kbuild" && grep -q 'NM) -u' "$D/Kbuild" || { echo "t40_ko_libgcc_check: FAIL (driver/t40/Kbuild lost the libgcc guard)"; exit 1; }
grep -q "$OK" "$D/Kbuild" || { echo "t40_ko_libgcc_check: FAIL (allowed list in Kbuild differs from this check)"; exit 1; }
NM=${T40_NM:-}; [ -z "$NM" ] && [ -n "${T40_CC:-}" ] && NM=${T40_CC%gcc}nm
n=0; fail=0
for k in $D/*.ko ${T40_KO_CHECK:-}; do
	[ -r "$k" ] || continue
	[ -n "$NM" ] && [ -x "$NM" ] || { echo "t40_ko_libgcc_check: no nm (T40_NM / T40_CC), $k not checked"; continue; }
	u=$("$NM" -u "$k" | awk '{print $NF}' | grep -E '^__[a-z]+(di|si|ti)[234]$' | grep -v -x -E "$OK" | tr '\n' ' ')
	n=$((n + 1))
	[ -n "$u" ] && { echo "t40_ko_libgcc_check: FAIL $k imports $u"; fail=1; }
done
[ $fail = 0 ] && echo "t40_ko_libgcc_check: ok (Kbuild guard present, $n module(s) checked)"
exit $fail
