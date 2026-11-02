#!/usr/bin/env python3
"""diff_ysp_chain.py OEM.ko YSP_EMU.o [--n 400] [--seed 7] [--fn wdr_en,intp,noref,ref,reg_trig]

T40 YSP chain (issue #85): the OEM tisp_ysp_wdr_en / tisp_ysp_intp / tisp_ysp_noref_reg_cfg / tisp_ysp_ref_reg_cfg / tisp_ysp_reg_trig of
the vendor tx-isp-t40.ko and the C versions (driver/t40/tx_isp_t40_ysp_chain.h, built for mipsel by tests/t40_ysp/build_emu.sh into
YSP_EMU.o) run in Unicorn on the same random state.  The OEM reads its three blocks (parameter record, pointer table, interpolated block)
from the module variables main_ysp* / sec_ysp* (channel 0 / 1), the C takes them as arguments.  Compared: every byte of the three blocks,
the order and values of the register writes, and the arguments of the interpolation helper calls (tisp_simple_intp_int8/16 are replaced by
a deterministic function of their arguments and of the 64 table bytes behind the pointer, in both emulators).
--mutate is done by the caller (tests/t40_ysp_chain_host.sh edits a copy of the header).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys, zlib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=400); ap.add_argument("--seed", type=int, default=7)
ap.add_argument("--fn", default="wdr_en,intp,noref,ref,reg_trig")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
PAR, COMB, INTP = 3432 + 64, 420, 146

log = {"oem": [], "our": []}
def h_write(tag):
    return lambda e: (log[tag].append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1]
def h_intp(tag, name):
    def f(e):
        x, y, p = e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1), e.get_reg(UC_MIPS_REG_A2)
        t = e.read(p, 64); log[tag].append((name, x, y, p, t))
        return zlib.crc32(struct.pack("<II", x, y) + t + name.encode()) & M32
    return f
def hle(tag):
    return {"system_reg_write": h_write(tag), "tisp_simple_intp_int8": h_intp(tag, "i8"), "tisp_simple_intp_int16": h_intp(tag, "i16"),
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0}
oem = KoEmu(a.oem, hle=hle("oem"), max_insns=2_000_000); our = KoEmu(a.our, hle=hle("our"), max_insns=2_000_000)
E = (oem, our)
# the OEM defines these three itself: hook the entries (the callbacks do what the HLE does for an undefined symbol)
for nm in ("system_reg_write", "tisp_simple_intp_int8", "tisp_simple_intp_int16"):
    def mk(nm):
        f = hle("oem")[nm]
        def _hook(uc, addr, size, ud):
            rv = f(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
        return _hook
    ad = oem.symaddr[nm]; oem.uc.hook_add(UC_HOOK_CODE, mk(nm), None, ad, ad)
SYM = {k: oem.symaddr[k] for k in ("main_ysp", "main_ysp_comb", "main_ysp_intp", "sec_ysp", "sec_ysp_comb", "sec_ysp_intp")}

def r32(): return rnd.getrandbits(32)
def rbytes(n, pz=0.3, pf=0.1): return bytes(0 if (r := rnd.random()) < pz else 255 if r < pz + pf else 128 if r < pz + pf + 0.05 else rnd.getrandbits(8) for _ in range(n))
def wr(addr, data): [e.write(addr, data) for e in E]
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("par0", PAR), ("comb0", COMB), ("intp0", INTP), ("par1", PAR), ("comb1", COMB), ("intp1", INTP)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    for k, nm in (("par0", "main_ysp"), ("comb0", "main_ysp_comb"), ("intp0", "main_ysp_intp"), ("par1", "sec_ysp"), ("comb1", "sec_ysp_comb"), ("intp1", "sec_ysp_intp")):
        oem.write(SYM[nm], struct.pack("<I", b[k]))
    return b
def fill_par():
    return rbytes(PAR, rnd.choice([0.05, 0.2, 0.4]), rnd.choice([0.02, 0.1, 0.3]))
stats = {}; bad = {}; nlog = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def call(name, ofn, args_oem, args_our, efn, retcmp=False):
    rs = []
    log["oem"].clear(); log["our"].clear()
    rs.append(oem.call(ofn, *args_oem)); rs.append(our.call(efn, *args_our))
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return None
    if retcmp and rs[0].v0 != rs[1].v0:
        rec(name, "return value oem %#x our %#x" % (rs[0].v0, rs[1].v0)); return None
    if log["oem"] != log["our"]:
        o, c = log["oem"], log["our"]; k = next((j for j in range(min(len(o), len(c))) if o[j] != c[j]), min(len(o), len(c)))
        rec(name, "call/write log differs at #%d (oem %d entries, our %d): oem %s our %s" % (k, len(o), len(c), (o[k][:3] if k < len(o) else None), (c[k][:3] if k < len(c) else None))); return None
    nlog[name] = nlog.get(name, 0) + len(log["oem"])
    return rs
def cmp_mem(name, b, ch, extra=""):
    for k, n in (("par", PAR), ("comb", COMB), ("intp", INTP)):
        for c in (0, 1):
            ad = b["%s%d" % (k, c)]; o, u = oem.read(ad, n), our.read(ad, n)
            if o != u:
                i = next(j for j in range(n) if o[j] != u[j]); rec(name, "%s%d differs at +%#x (oem %02x our %02x) ch=%d %s" % (k, c, i, o[i], u[i], ch, extra)); return False
    return True

want = a.fn.split(",")
for it in range(a.n):
    b = setup(); wdr = rnd.choice([0, 0, 1, rnd.getrandbits(8), 0x100, 0xffffffff]); ch = rnd.choice([0, 1])
    for c in (0, 1):
        wr(b["par%d" % c], fill_par()); wr(b["intp%d" % c], rbytes(INTP, 0.2))
    # the pointer table is what the OEM wdr_en makes of it (its own test is `wdr_en`)
    for c in (0, 1): wr(b["comb%d" % c], rbytes(COMB))
    if "wdr_en" in want:
        if call("wdr_en", "tisp_ysp_wdr_en", (ch, wdr), (b["par%d" % ch], b["comb%d" % ch], wdr), "emu_wdr_en"): cmp_mem("wdr_en", b, ch, "wdr=%d" % wdr)
    for c in (0, 1):
        r = oem.call("tisp_ysp_wdr_en", c, wdr); assert not r.stop
        our.write(b["comb%d" % c], oem.read(b["comb%d" % c], COMB))
    P, C_, I = b["par%d" % ch], b["comb%d" % ch], b["intp%d" % ch]
    if "intp" in want:
        gain = rnd.choice([r32(), r32() & 0xffffff, 0, 0x10000, 0x3fffff, 0xffffffff])
        if call("intp", "tisp_ysp_intp", (ch, gain), (C_, I, gain), "emu_intp"): cmp_mem("intp", b, ch, "gain=%#x" % gain)
    if "noref" in want:
        if call("noref", "tisp_ysp_noref_reg_cfg", (ch,), (ch, P, C_), "emu_noref", True): cmp_mem("noref", b, ch, "wdr=%d" % wdr)
    if "ref" in want:
        if call("ref", "tisp_ysp_ref_reg_cfg", (ch,), (ch, P, C_, I), "emu_ref", True): cmp_mem("ref", b, ch, "wdr=%d" % wdr)
    if "reg_trig" in want:
        call("reg_trig", "tisp_ysp_reg_trig", (ch,), (ch,), "emu_reg_trig", True)
for k in sorted(stats): print("%-9s %6d calls  %7d writes/helper calls compared  %d mismatches" % (k, stats[k], nlog.get(k, 0), bad.get(k, 0)))
sys.exit(1 if bad else 0)
