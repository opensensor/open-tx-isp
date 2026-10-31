#!/bin/sh
# check_ko_zerobase.sh <objdump> <module.ko>   (#161)
#
# Lifted code that lost a base register compiles to loads/stores relative to $zero ("sw v0,268(zero)"): a kernel
# NULL-page access, an oops as soon as the path runs (same bug class as #139).  The T40 build must not contain
# any, except the functions listed in tests/ko_zerobase_baseline.txt (empty since the last three were fixed, #161).
# Exit 0 = none new, 1 = new ones (listed), 2 = usage/tool error.
[ $# -eq 2 ] && [ -f "$2" ] || { echo "usage: $0 <objdump> <module.ko>" >&2; exit 2; }
out=$("$1" -d "$2" 2>/dev/null) || { echo "check_ko_zerobase: objdump failed" >&2; exit 2; }
base=$(dirname "$0")/ko_zerobase_baseline.txt
hits=$(printf '%s\n' "$out" | awk '/^[0-9a-f]+ <.*>:$/ {fn=$2} $3 ~ /^(lw|lh|lhu|lb|lbu|sw|sh|sb)$/ && $4 ~ /,-?[0-9]+\(zero\)$/ {c[fn]++} END {for (f in c) print f}' | sort)
known=
if [ -f "$base" ] && [ -n "$hits" ]; then
	known=$(printf '%s\n' "$hits" | grep -x -F -f "$base" || true)
	hits=$(printf '%s\n' "$hits" | grep -v -x -F -f "$base" || true)
fi
[ -n "$known" ] && { echo "check_ko_zerobase: $(basename "$2"): known (baseline):"; printf '%s\n' "$known"; }
if [ -n "$hits" ]; then
	echo "check_ko_zerobase: $(basename "$2"): NULL-based loads/stores in:"
	printf '%s\n' "$hits"
	exit 1
fi
echo "check_ko_zerobase: $(basename "$2"): no new NULL-based accesses"
