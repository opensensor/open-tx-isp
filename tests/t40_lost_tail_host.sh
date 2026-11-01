#!/bin/sh
# Host test of the #189 lost-tail-call fixes in the lifted T40 code (see t40_lost_tail_host.c): cuts the functions out of
# tx_isp_t40_recovered.c and runs them against callee stubs.
set -e
HERE=$(cd "$(dirname "$0")" && pwd)
W=$(mktemp -d); trap 'rm -rf $W' EXIT
python3 - "$HERE/../driver/t40/tx_isp_t40_recovered.c" "$W/t40_lost_tail_fn.inc" <<'PY'
import re, sys
src = open(sys.argv[1], errors="replace").read().split("\n")
out = ["#include <stdint.h>"]
for fn in ("system_reg_write_af", "tisp_s_module_control", "tisp_ae_s_comp"):
    idx = [i for i, l in enumerate(src) if re.match(r"^[A-Za-z_][\w \*]*?[ \*]" + fn + r"\([^;]*\)\s*$", l) and src[i + 1] == "{"]
    assert idx, fn
    i = idx[-1]
    j = i
    while src[j] != "}":
        j += 1
    body = src[i:j + 1]
    if fn == "tisp_s_module_control":   # 32-bit target: `-1` compared with a zero-extended 32-bit OR of the status words
        body = [l.replace("v1 = -1;", "v1 = 0xffffffffu;") for l in body]
    out += body + [""]
open(sys.argv[2], "w").write("\n".join(out) + "\n")
PY
cc -std=gnu11 -O1 -w -Wno-error=int-conversion -Wno-error=incompatible-pointer-types -fpermissive -I"$W" -o "$W/t" "$HERE/t40_lost_tail_host.c"
"$W/t"
