#!/usr/bin/env python3
"""diff_ccm_conv.py OEM.ko [--header driver/t40/tx_isp_t40_ccm_conv.h] [--n 3000] [--seed 1] [--mutate 'old=>new']

Differential test: the OEM tisp_ccm_reg2par / tisp_ccm_para2reg / tisp_ccm_parameter_convert executed
instruction by instruction from the vendor module in Unicorn (ko_emu.py), against the C versions in
tx_isp_t40_ccm_conv.h compiled into a host shared library.  Compares the return value and the
destination matrices.  --mutate patches the header text (proof that a change is caught).
"""
import argparse, ctypes, os, random, subprocess, sys, tempfile
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu

HERE = os.path.dirname(os.path.abspath(__file__))
DEF_HDR = os.path.join(HERE, "../../driver/t40/tx_isp_t40_ccm_conv.h")

def build_lib(hdr, mutate, outdir):
    src = open(hdr).read()
    for mut in mutate:
        a, b = mut.split("=>", 1)
        if a not in src: raise SystemExit("mutation text not found: %r" % a)
        src = src.replace(a, b, 1)
    c = "#include <stdint.h>\nstatic uint32_t *tbl[6];\n#define T40_CCM_PTR(ctx, off) tbl[*(const uint32_t *)((ctx) + (off))]\n" + src + """
uint32_t w_reg2par(uint32_t *d, const uint32_t *s) { return t40_ccm_reg2par(d, s); }
uint32_t w_para2reg(uint32_t *d, const uint32_t *s) { return t40_ccm_para2reg(d, s); }
void w_tbl(int i, uint32_t *p) { tbl[i] = p; }
uint32_t w_convert(uint32_t *ctx) { return t40_ccm_parameter_convert((uintptr_t)ctx); }
"""
    cf = os.path.join(outdir, "ccm.c"); so = os.path.join(outdir, "ccm.so")
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
    def word():
        return rnd.choice([rnd.getrandbits(32), rnd.getrandbits(15), rnd.getrandbits(14), 0x1fff, 0x2000, 0x3fff, 0x4000,
                           0x7fffffff, 0x80000000, 0xffffffff, 0xffffc000, 0, rnd.getrandbits(rnd.randint(1, 32))])
    bad = {}; seen = {}
    def rec(k, msg):
        bad[k] = bad.get(k, 0) + 1
        if bad[k] <= 2: print("MISMATCH", k, msg)
    P = ctypes.POINTER(ctypes.c_uint32)
    for it in range(a.n):
        e.heap_reset()
        src = [word() for _ in range(9)]
        cs = (ctypes.c_uint32 * 9)(*src)
        for kind, oem_fn, cfn in (("reg2par", "tisp_ccm_reg2par", lib.w_reg2par), ("para2reg", "tisp_ccm_para2reg", lib.w_para2reg)):
            bs = e.alloc(36, b"".join(v.to_bytes(4, "little") for v in src)); bd = e.alloc(36, b"\xaa" * 36)
            r = e.call(oem_fn, bd, bs)
            cd = (ctypes.c_uint32 * 9)(*([0xaaaaaaaa] * 9))
            cfn.restype = ctypes.c_uint32; cfn.argtypes = [P, P]
            c = cfn(cd, cs); seen[kind] = seen.get(kind, 0) + 1
            if r.stop or r.v0 != c or e.read(bd, 36) != ctypes.string_at(cd, 36):
                rec(kind, "src=%s oem=%#x c=%#x stop=%s" % ([hex(x) for x in src], r.v0, c, r.stop))
        # parameter_convert: ctx with dst pointers at +48/+52/+56, src pointers at +80/+84/+88
        srcs = [[word() for _ in range(9)] for _ in range(3)]
        ctx = e.alloc(128, b"\0" * 128); bsrc = [e.alloc(36, b"".join(v.to_bytes(4, "little") for v in m)) for m in srcs]
        bdst = [e.alloc(36, b"\xaa" * 36) for _ in range(3)]
        for k in range(3):
            e.write(ctx + 48 + 4 * k, bdst[k].to_bytes(4, "little")); e.write(ctx + 80 + 4 * k, bsrc[k].to_bytes(4, "little"))
        r = e.call("tisp_ccm_parameter_convert", ctx)
        oem = [e.read(b, 36) for b in bdst]
        # host: the context holds table handles instead of 32-bit addresses
        hs = [(ctypes.c_uint32 * 9)(*m) for m in srcs]; hd = [(ctypes.c_uint32 * 9)(*([0xaaaaaaaa] * 9)) for _ in range(3)]
        hctx = (ctypes.c_uint32 * 32)()
        lib.w_tbl.argtypes = [ctypes.c_int, P]
        for k in range(3):
            lib.w_tbl(k, ctypes.cast(hd[k], P)); lib.w_tbl(3 + k, ctypes.cast(hs[k], P))
            hctx[12 + k] = k; hctx[20 + k] = 3 + k
        lib.w_convert.restype = ctypes.c_uint32; lib.w_convert.argtypes = [P]
        c = lib.w_convert(ctypes.cast(hctx, P)); seen["convert"] = seen.get("convert", 0) + 1
        cc = [ctypes.string_at(hd[k], 36) for k in range(3)]
        if r.stop or r.v0 != c or oem != cc: rec("convert", "oem=%#x c=%#x stop=%s" % (r.v0, c, r.stop))
    for k in seen: print("%-8s %6d calls  %d mismatches" % (k, seen[k], bad.get(k, 0)))
    sys.exit(1 if bad else 0)
main()
