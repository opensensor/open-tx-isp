#!/usr/bin/env python3
"""diff_adr_helpers.py OEM.ko [--header driver/t40/tx_isp_t40_adr.h] [--n 3000] [--seed 1] [--mutate 'old=>new']

Differential test: the OEM arithmetic/table helpers of the T40 ADR block, executed instruction by
instruction from the vendor module in Unicorn (ko_emu.py), against our C versions from
tx_isp_t40_adr.h compiled into a host shared library.  Compares return value and the output buffers
of func_interp1_short.  --mutate patches the extracted C source (proof that a change is caught).
"""
import argparse, ctypes, os, random, re, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu

HERE = os.path.dirname(os.path.abspath(__file__))
DEF_HDR = os.path.join(HERE, "../../driver/t40/tx_isp_t40_adr.h")
FUNCS = ["t40_adr_div32", "t40_adr_mul32", "t40_adr_exp2", "t40_adr_int16", "t40_adr_int32", "t40_adr_interp1"]
TABLES = ["t40_adr_pow2_lut"]

def extract(src, name, table=False):
    """return the text of  static ... name(...) { ... }  (or the const table) including the leading comment line"""
    m = re.search(r"^static [^\n;{]*\b%s\b[^\n;]*(?:\[\d+\] = \{|\n?\{|$)" % re.escape(name), src, re.M)
    if not m: raise SystemExit("function %s not found in header" % name)
    i = m.start()
    if table:
        j = src.index("};", i) + 2; return src[i:j]
    j = src.index("{", m.end() - 1 if src[m.end() - 1] == "{" else m.end()); depth = 0
    for k in range(j, len(src)):
        depth += (src[k] == "{") - (src[k] == "}")
        if depth == 0: return src[i:k + 1]

def build_lib(hdr, mutate, outdir):
    src = open(hdr).read()
    body = "\n".join(extract(src, t, True) for t in TABLES) + "\n" + "\n".join(extract(src, f) for f in FUNCS)
    for mut in mutate:
        a, b = mut.split("=>", 1)
        if a not in body: raise SystemExit("mutation text not found: %r" % a)
        body = body.replace(a, b, 1)
    c = "#include <stdint.h>\n#define div64_u64(a,b) ((uint64_t)(a)/(uint64_t)(b))\n" + body + "\n"
    for f in FUNCS: pass
    c += """
uint32_t w_div32(uint32_t n, uint32_t x, uint32_t y) { return t40_adr_div32(n, x, y); }
uint32_t w_mul32(uint32_t n, uint32_t a, uint32_t b) { return t40_adr_mul32(n, a, b); }
uint32_t w_exp2(uint32_t x, uint32_t f, uint32_t o) { return t40_adr_exp2(x, f, o); }
int32_t w_int16(int32_t x, const int16_t *xs, const int16_t *ys, int32_t n) { return t40_adr_int16(x, xs, ys, n); }
int32_t w_int32(int32_t x, const int32_t *xs, const int16_t *ys, int32_t n) { return t40_adr_int32(x, xs, ys, n); }
void w_interp1(const int16_t *xs, const int16_t *ys, const int16_t *xq, int16_t *o, int32_t n, int32_t nq) { t40_adr_interp1(xs, ys, xq, o, n, nq); }
"""
    cf = os.path.join(outdir, "adrh.c"); so = os.path.join(outdir, "adrh.so")
    open(cf, "w").write(c)
    subprocess.check_call(["gcc", "-O2", "-shared", "-fPIC", "-w", "-o", so, cf])
    return ctypes.CDLL(so)

def main():
    ap = argparse.ArgumentParser(); ap.add_argument("ko"); ap.add_argument("--header", default=DEF_HDR)
    ap.add_argument("--n", type=int, default=3000); ap.add_argument("--seed", type=int, default=1)
    ap.add_argument("--mutate", action="append", default=[]); a = ap.parse_args()
    rnd = random.Random(a.seed)
    with tempfile.TemporaryDirectory(dir=os.environ.get("TMPDIR")) as td:
        lib = build_lib(a.header, a.mutate, td)
    e = KoEmu(a.ko)
    u32 = lambda: rnd.choice([rnd.getrandbits(rnd.randint(1, 32)), rnd.getrandbits(32), rnd.randint(0, 5000)])
    bad = {}; seen = {}
    def rec(k, msg):
        bad[k] = bad.get(k, 0) + 1
        if bad[k] <= 2: print("MISMATCH", k, msg)
    for it in range(a.n):
        e.heap_reset()
        n = rnd.randint(0, 33); x = u32(); y = u32() or 1
        r = e.call("fix_point_div_32", n, x, y)
        lib.w_div32.restype = ctypes.c_uint32; lib.w_div32.argtypes = [ctypes.c_uint32] * 3
        c = lib.w_div32(n, x, y); seen["div32"] = seen.get("div32", 0) + 1
        if r.stop or r.v0 != c: rec("div32", "n=%d x=%#x y=%#x oem=%#x c=%#x stop=%s" % (n, x, y, r.v0, c, r.stop))
        n = rnd.randint(0, 31); x = u32(); y = u32()
        r = e.call("fix_point_mult2_32", n, x, y)
        lib.w_mul32.restype = ctypes.c_uint32; lib.w_mul32.argtypes = [ctypes.c_uint32] * 3
        c = lib.w_mul32(n, x, y); seen["mul32"] = seen.get("mul32", 0) + 1
        if r.stop or r.v0 != c: rec("mul32", "n=%d a=%#x b=%#x oem=%#x c=%#x" % (n, x, y, r.v0, c))
        fb = rnd.randint(0, 16); ob = rnd.randint(0, 30); x = rnd.randint(0, (16 << fb) - 1)
        r = e.call("tisp_math_exp2", x, fb, ob)
        lib.w_exp2.restype = ctypes.c_uint32; lib.w_exp2.argtypes = [ctypes.c_uint32] * 3
        c = lib.w_exp2(x, fb, ob); seen["exp2"] = seen.get("exp2", 0) + 1
        if r.stop or r.v0 != c: rec("exp2", "x=%d fb=%d ob=%d oem=%#x c=%#x" % (x, fb, ob, r.v0, c))
        # table helpers: sorted knots
        cnt = rnd.randint(1, 20)
        xs = sorted(rnd.choice([rnd.randint(-3000, 3000), rnd.randint(-30000, 30000)]) for _ in range(cnt))
        ys = [rnd.randint(-32768, 32767) for _ in range(cnt)]
        q = rnd.randint(-33000, 33000)
        bx = e.alloc(2 * cnt, b"".join(v.to_bytes(2, "little", signed=True) for v in xs)); by = e.alloc(2 * cnt, b"".join(v.to_bytes(2, "little", signed=True) for v in ys))
        cx = (ctypes.c_int16 * cnt)(*xs); cy = (ctypes.c_int16 * cnt)(*ys)
        r = e.call("ispint_adr_16", q & 0xffffffff, bx, by, cnt)
        lib.w_int16.restype = ctypes.c_int32; lib.w_int16.argtypes = [ctypes.c_int32, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int32]
        c = lib.w_int16(q, ctypes.addressof(cx), ctypes.addressof(cy), cnt) & 0xffffffff; seen["int16"] = seen.get("int16", 0) + 1
        if r.stop or r.v0 != c: rec("int16", "q=%d n=%d oem=%#x c=%#x" % (q, cnt, r.v0, c))
        xs32 = sorted(rnd.randint(-2**31, 2**31 - 1) >> rnd.randint(0, 28) for _ in range(cnt))
        b32 = e.alloc(4 * cnt, b"".join(v.to_bytes(4, "little", signed=True) for v in xs32)); c32 = (ctypes.c_int32 * cnt)(*xs32)
        q = rnd.choice([rnd.randint(-2**31, 2**31 - 1) >> rnd.randint(0, 28), rnd.choice(xs32)])
        r = e.call("ispint_adr_32", q & 0xffffffff, b32, by, cnt)
        lib.w_int32.restype = ctypes.c_int32; lib.w_int32.argtypes = [ctypes.c_int32, ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int32]
        c = lib.w_int32(q, ctypes.addressof(c32), ctypes.addressof(cy), cnt) & 0xffffffff; seen["int32"] = seen.get("int32", 0) + 1
        if r.stop or r.v0 != c: rec("int32", "q=%d n=%d oem=%#x c=%#x" % (q, cnt, r.v0, c))
        # interp1: writes nq shorts
        if cnt < 2 or len(set(xs)) != cnt: continue       # interp1: strictly rising knots (dx = 0 traps/undefined in the OEM)
        nq = rnd.randint(1, 24); xq = sorted(rnd.randint(-3000, 3000) for _ in range(nq))
        bq = e.alloc(2 * nq, b"".join(v.to_bytes(2, "little", signed=True) for v in xq)); bo = e.alloc(2 * nq, b"\xaa" * (2 * nq))
        cq = (ctypes.c_int16 * nq)(*xq); co = (ctypes.c_int16 * nq)(*([-21846] * nq))
        # o32: args 5 and 6 (n, nq) go on the stack
        r = e.call("func_interp1_short", bx, by, bq, bo, stack_args=(cnt, nq))
        lib.w_interp1.restype = None; lib.w_interp1.argtypes = [ctypes.c_void_p] * 4 + [ctypes.c_int32] * 2
        lib.w_interp1(ctypes.addressof(cx), ctypes.addressof(cy), ctypes.addressof(cq), ctypes.addressof(co), cnt, nq); seen["interp1"] = seen.get("interp1", 0) + 1
        oem = e.read(bo, 2 * nq); cc = bytes(bytearray(ctypes.string_at(ctypes.addressof(co), 2 * nq)))
        if r.stop or oem != cc: rec("interp1", "n=%d nq=%d stop=%s insns=%d oem=%s c=%s" % (cnt, nq, r.stop, r.insns, oem.hex(), cc.hex()))
    for k in seen: print("%-8s %6d calls  %d mismatches" % (k, seen[k], bad.get(k, 0)))
    sys.exit(1 if bad else 0)
main()
