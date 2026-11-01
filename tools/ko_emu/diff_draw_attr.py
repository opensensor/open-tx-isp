#!/usr/bin/env python3
"""diff_draw_attr.py OEM.ko [--source driver/t40/tx_isp_t40_recovered.c] [--n 500] [--mutate 'old=>new']

State-based example for ko_emu: tisp_g_draw_attr (T40, issue #183).  The OEM function reads the
mscaler_s0/mscaler_s1 .bss blocks and fills a 2 x 448 byte user block.  Random state goes into the
OEM module's .bss (via ko_emu) and into the host copy of our C function; the output blocks must match."""
import argparse, ctypes, os, random, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
HERE = os.path.dirname(os.path.abspath(__file__))
ap = argparse.ArgumentParser(); ap.add_argument("ko"); ap.add_argument("--source", default=os.path.join(HERE, "../../driver/t40/tx_isp_t40_recovered.c"))
ap.add_argument("--n", type=int, default=500); ap.add_argument("--seed", type=int, default=3); ap.add_argument("--mutate", action="append", default=[])
a = ap.parse_args(); rnd = random.Random(a.seed)
src = open(a.source).read()
m = re.search(r"^int64_t tisp_g_draw_attr\(uint32_t a0, uintptr_t a1\)\n\{", src, re.M)
i = m.start(); depth = 0
for k in range(m.end() - 1, len(src)):
    depth += (src[k] == "{") - (src[k] == "}")
    if depth == 0: body = src[i:k + 1]; break
for mut in a.mutate:
    x, y = mut.split("=>", 1)
    if x not in body: raise SystemExit("mutation text not found: %r" % x)
    body = body.replace(x, y, 1)
c = "#include <stdint.h>\n#include <string.h>\nchar mscaler_s0[2048], mscaler_s1[2048];\n" + body + \
    "\nvoid w_set(int w, const char *p) { memcpy(w ? mscaler_s1 : mscaler_s0, p, 1232); }\n"
with tempfile.TemporaryDirectory(dir=os.environ.get("TMPDIR")) as td:
    open(td + "/d.c", "w").write(c)
    subprocess.check_call(["gcc", "-O2", "-shared", "-fPIC", "-w", "-o", td + "/d.so", td + "/d.c"])
    lib = ctypes.CDLL(td + "/d.so")
lib.tisp_g_draw_attr.argtypes = [ctypes.c_uint32, ctypes.c_void_p]; lib.tisp_g_draw_attr.restype = ctypes.c_int64
lib.w_set.argtypes = [ctypes.c_int, ctypes.c_char_p]
e = KoEmu(a.ko); s0 = e.addr("mscaler_s0"); s1 = e.addr("mscaler_s1"); bad = 0; shown = 0
for it in range(a.n):
    e.heap_reset()
    st = [bytes(rnd.getrandbits(8) if rnd.random() < 0.7 else rnd.choice([0, 1, 2]) for _ in range(1232)) for _ in range(2)]
    for w in (0, 1): lib.w_set(w, st[w])
    for w, base in ((0, s0), (1, s1)): e.write(base, st[w])
    for w in (0, 1):
        out = e.alloc(896, b"\xa5" * 896); co = (ctypes.c_char * 896).from_buffer_copy(b"\xa5" * 896)
        r = e.call("tisp_g_draw_attr", w, out)
        lib.tisp_g_draw_attr(w, ctypes.addressof(co))
        if r.stop or e.read(out, 896) != co.raw:
            bad += 1
            if shown < 2:
                shown += 1; o = e.read(out, 896); d = [j for j in range(896) if o[j] != co.raw[j]]
                print("MISMATCH state %d: stop=%s first diffs at out+%s (oem %s c %s)" % (w, r.stop, d[:6], [o[j] for j in d[:4]], [co.raw[j] for j in d[:4]]))
print("tisp_g_draw_attr: %d calls, %d mismatches" % (a.n * 2, bad)); sys.exit(1 if bad else 0)
