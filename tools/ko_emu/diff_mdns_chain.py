#!/usr/bin/env python3
"""diff_mdns_chain.py OEM.ko MDNS_EMU.o [--n 400] [--seed 7] [--fn smp,dif,wdr_en,intp,start,reg_trig,func_en,reg_cfg,all_reg,par_refresh,refresh,params] [--audit]

T40 MDNS chain (issue #85): the OEM tisp_mdns_* functions of the vendor tx-isp-t40.ko and the C versions (driver/t40/tx_isp_t40_mdns_chain.h, built for
mipsel by tests/t40_mdns/build_emu.sh into MDNS_EMU.o) run in Unicorn on the same random state.  The OEM reads its blocks (parameter record, pointer
table, interpolated block), frame size and last gain from module variables (main_mdns*, sec_mdns*, vin_width/height, gain_old, tparamsN), the C takes them
as arguments.  Compared: every byte of the blocks, the order and values of the register writes, the arguments of the interpolation helper calls
(tisp_simple_intp_int8 is replaced by a deterministic function of its arguments and of the 64 table bytes behind the pointer, in both emulators), the
ramp tables of the two equation functions (the OEM keeps them in module variables), the last gain, and the return values where they are defined.
Division by zero leaves LO/HI undefined on the CPU: the inputs are chosen so that no divisor is zero.
--audit lists the module data the OEM functions write (must be the documented state only).
Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys, zlib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=400); ap.add_argument("--seed", type=int, default=7)
ap.add_argument("--fn", default="smp,dif,wdr_en,intp,start,reg_trig,func_en,reg_cfg,all_reg,par_refresh,refresh,params")
ap.add_argument("--audit", action="store_true"); ap.add_argument("--first", type=int, default=0)
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
PAR, COMB, INTP, BANK = 2398 + 64, 336 + 16, 136 + 16, 0x1105c + 2398 + 64
PARSZ = 2398

log = {"oem": [], "our": []}
memopt = [0]
def h_write(tag):
    def f(e):
        r, v = e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1); log[tag].append(("w", r, v))
        return (r ^ ((v << 7 | v >> 25) & M32)) & 0x7fffffff
    return f
def h_intp(tag):
    def f(e):
        x, y, p = e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1), e.get_reg(UC_MIPS_REG_A2)
        t = e.read(p, 64); log[tag].append(("i8", x, y, p, t))
        return zlib.crc32(struct.pack("<II", x, y) + t) & 0xff
    return f
def h_memopt(tag):
    def f(e): return memopt[0]      # pure: not logged (the C reads it unconditionally, the OEM only on the first refresh)
    return f
def hle(tag):
    return {"system_reg_write": h_write(tag), "tisp_simple_intp_int8": h_intp(tag), "get_isp_memopt": h_memopt(tag),
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0}
oem = KoEmu(a.oem, hle=hle("oem"), max_insns=3_000_000); our = KoEmu(a.our, hle=hle("our"), max_insns=3_000_000)
E = (oem, our)
for nm in ("system_reg_write", "tisp_simple_intp_int8", "get_isp_memopt"):   # the OEM defines these itself: hook the entries
    def mk(nm):
        f = hle("oem")[nm]
        def _hook(uc, addr, size, ud):
            rv = f(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
        return _hook
    ad = oem.symaddr[nm]; oem.uc.hook_add(UC_HOOK_CODE, mk(nm), None, ad, ad)
S = oem.symaddr
DATA = next(b for i, b in oem.secbase.items() if oem.secname[i] == ".data")
# module variables that are file-local in the OEM (addresses taken from the relocated references of tisp_mdns_*)
VIN_H, VIN_W, GOLD = DATA + 0x2c8c0, DATA + 0x2c8c8, DATA + 0x2c8d0
for nm, ad in (("vin_height", VIN_H), ("vin_width", VIN_W)): assert S[nm] == ad, nm
assert S["mdns_equation_smp_yval0"] and S["tparamsN"]
def w32(v): return struct.pack("<I", v & M32)
def r32(): return rnd.getrandbits(32)
def rbytes(n, pz=0.2): return bytes(0 if rnd.random() < pz else rnd.getrandbits(8) for _ in range(n))
def wr(addr, data): [e.write(addr, data) for e in E]
def rd32(e, ad): return struct.unpack("<I", e.read(ad, 4))[0]
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("par0", PAR), ("comb0", COMB), ("intp0", INTP), ("par1", PAR), ("comb1", COMB), ("intp1", INTP), ("bank", BANK), ("gold", 16), ("ramp", 16 * 4), ("seg", 16), ("args", 64)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    for k, nm in (("par0", "main_mdns"), ("comb0", "main_mdns_comb"), ("intp0", "main_mdns_intp"), ("par1", "sec_mdns"), ("comb1", "sec_mdns_comb"), ("intp1", "sec_mdns_intp")):
        oem.write(S[nm], w32(b[k]))
    oem.write(S["tparamsN"], w32(b["bank"]) + w32(b["bank"]))
    return b
def fill_par():
    d = bytearray(rbytes(PAR, rnd.choice([0.05, 0.2, 0.5])))
    if rnd.random() < 0.5:                       # byte values that exercise the ramps (small selectors, ordered end points)
        for k in range(0, PARSZ - 4, 4):
            if rnd.random() < 0.3: d[k] = rnd.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 0xfe, 0xff])
    return bytes(d)
def fill_intp():
    d = bytearray(rbytes(INTP, rnd.choice([0.05, 0.2, 0.5])))
    for k in range(INTP):
        if rnd.random() < 0.25: d[k] = rnd.choice([0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 127, 128, 129, 0xfe, 0xff])
    d[4] = rnd.choice([1, 2, 4, 8, 16, 32, 64, rnd.randint(1, 255)])      # tile size: a divisor
    for hi, lo in ((133, 132), (135, 134)):                                  # 1024 / (hi - lo) at 0x2a8 / 0x2ac: no zero divisor
        while True:
            l = d[lo] if d[lo] < 129 else 128; h = d[hi]
            if ((h - l) + 8 if (h - l) < 8 else (h - l)) != 0: break
            d[hi] = (d[hi] + 1) & 0xff
    return bytes(d)
def sizes():
    w = rnd.choice([1920, 2560, 3840, 1280, 640, rnd.randint(1, 4096), rnd.randint(1, 4096), 0, 1, 15, 16, 17, 31, 32, 33, 0x7fffffff, 0xffffffff, 0x80000000, r32()])
    h = rnd.choice([1080, 1440, 2160, 720, 480, rnd.randint(1, 4096), rnd.randint(1, 4096), 0, 1, 15, 16, 17, 31, 32, 33, 0x7fffffff, 0xffffffff, 0x80000000, r32()])
    return w, h
def gains():
    return rnd.choice([r32(), r32() & 0xffffff, 0, 0x10000, 0x3fffff, 0xffffffff, 0x7fffffff, 0x80000000, rnd.randint(0, 0x30000), 0x20000 + rnd.randint(0, 0xffff)])

CUR_ARGS = [0]; CUR_INTP = [0]; CTX = [""]
stats = {}; bad = {}; nlog = {}; audit = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg, "| %s" % CTX[0])
def div_ok(intp):
    """False when reg_cfg would divide by zero for this interpolated block (LO/HI undefined on the CPU: not compared)"""
    if intp[4] == 0: return False
    for hi, lo in ((133, 132), (135, 134)):
        l = intp[lo] if intp[lo] < 129 else 128; v = intp[hi] - l
        if (v + 8 if v < 8 else v) == 0: return False
    return True
skipped = {}
def call(name, ofn, args_oem, efn, args_our, ret=True, divcheck=False):
    log["oem"].clear(); log["our"].clear()
    if a.audit: oem.watch_module_data = True
    ro = oem.call(ofn, *args_oem); oem.watch_module_data = False
    our.write(CUR_ARGS[0], b"".join(w32(x) for x in args_our)); ru = our.call(efn, CUR_ARGS[0])
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate((ro, ru)):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return None
    if divcheck and not div_ok(oem.read(CUR_INTP[0], 136)):
        skipped[name] = skipped.get(name, 0) + 1; return None
    if a.audit:
        for ad, n, v in ro.writes:
            w = oem.where(ad).split("+")[0]
            if w not in ("heap", "stack-" + ""): audit.setdefault(name, set()).add(oem.where(ad))
    if log["oem"] != log["our"]:
        o, c = log["oem"], log["our"]; k = next((j for j in range(min(len(o), len(c))) if o[j] != c[j]), min(len(o), len(c)))
        rec(name, "call/write log differs at #%d (oem %d entries, our %d): oem %s our %s" % (k, len(o), len(c), (o[k][:3] if k < len(o) else None), (c[k][:3] if k < len(c) else None))); return None
    if ret and ro.v0 != ru.v0: rec(name, "return value differs: oem %#x our %#x" % (ro.v0, ru.v0)); return None
    nlog[name] = nlog.get(name, 0) + len(log["oem"])
    return ro, ru
def cmp_mem(name, b, extra=""):
    for k, n in (("par", PAR), ("comb", COMB), ("intp", INTP)):
        for c in (0, 1):
            ad = b["%s%d" % (k, c)]; o, u = oem.read(ad, n), our.read(ad, n)
            if o != u:
                i = next(j for j in range(n) if o[j] != u[j]); rec(name, "%s%d differs at +%#x (oem %02x our %02x) %s" % (k, c, i, o[i], u[i], extra)); return False
    return True
def cmp_gold(name, b, ch, extra=""):
    o, u = rd32(oem, GOLD + 4 * ch), rd32(our, b["gold"])
    if o != u: rec(name, "gain_old oem %#x our %#x %s" % (o, u, extra)); return False
    return True

def ok_smp(k, m):
    kk = k if (k if k < 0x80000000 else k - (1 << 32)) < 7 else 6
    ks = kk if kk < 0x80000000 else kk - (1 << 32)
    ms = m if m < 0x80000000 else m - (1 << 32)
    to = ms if ks < ms else ks + 1
    if not to < 8: to = 7
    return ((to - ks) & M32) != 0
def ok_dif(k, m):
    ks = 254 if k == 0xff else (k if k < 0x80000000 else k - (1 << 32))
    ms = m if m < 0x80000000 else m - (1 << 32)
    to = ms if ks < ms else ks + 1
    return ((to - ks) & M32) != 0
def eqarg():
    return rnd.choice([rnd.getrandbits(8), rnd.getrandbits(8), rnd.getrandbits(3), 0, 255, 254, 7, 6, 5, 1, rnd.randint(-5, 300) & M32, r32(), 0x7fffffff, 0x80000000])

want = a.fn.split(",")
for it in range(a.first, a.first + a.n):
    rnd.seed(a.seed * 1000003 + it)       # per-iteration seed: a failing iteration is reproduced with --first IT --n 1 (any --fn)
    b = setup(); ch = rnd.choice([0, 1]); wdr = rnd.choice([0, 0, 1, rnd.getrandbits(8)]); mo = rnd.choice([0, 0x1, 0x2, 0x11, 0x22, 0x21, 0x12, 0x3, r32()]); memopt[0] = mo
    CUR_ARGS[0] = b["args"]
    P, C_, I = b["par%d" % ch], b["comb%d" % ch], b["intp%d" % ch]
    CUR_INTP[0] = I
    for c in (0, 1):
        wr(b["par%d" % c], fill_par()); wr(b["intp%d" % c], fill_intp()); wr(b["comb%d" % c], rbytes(COMB))
    w, h = sizes(); CTX[0] = "it=%d ch=%d w=%#x h=%#x intp[4:9]=%s gold=%#x" % (it, ch, w, h, oem.read(b["intp%d" % ch] + 4, 5).hex(), 0)
    for c in (0, 1):
        oem.write(VIN_W + 4 * c, w32(w)); oem.write(VIN_H + 4 * c, w32(h))
    gold = rnd.choice([0xffffffff, gains(), gains()]); oem.write(GOLD, w32(gold) * 2); our.write(b["gold"], w32(gold))
    oem.write(GOLD + 4 * (1 - ch), w32(0x12345678))
    # equation functions: the ramps are module variables in the OEM, an array in the C
    if "smp" in want:
        for _ in range(3):
            args = [eqarg() for _ in range(4)]
            if not ok_smp(args[0], args[1]): continue
            if call("smp", "tisp_mdns_reg_cfg_equation_smp", args, "emu_smp", (b["ramp"],) + tuple(args), ret=False):
                o = [rd32(oem, S["mdns_equation_smp_yval%d" % i]) for i in range(8)]; u = [rd32(our, b["ramp"] + 4 * i) for i in range(8)]
                if o != u: rec("smp", "ramp oem %s our %s args %s" % (o, u, [hex(x) for x in args]))
    if "dif" in want:
        for _ in range(3):
            args = [eqarg() for _ in range(4)]
            if not ok_dif(args[0], args[1]): continue
            if call("dif", "tisp_mdns_reg_cfg_equation_dif", args, "emu_dif", (b["ramp"], b["seg"]) + tuple(args), ret=False):
                o = [rd32(oem, S["mdns_equation_dif_yval%d" % i]) for i in range(8)] + [rd32(oem, S["mdns_equation_dif_cutval"]), rd32(oem, S["mdns_equation_dif_segopt"])]
                u = [rd32(our, b["ramp"] + 4 * i) for i in range(8)] + [rd32(our, b["seg"]), rd32(our, b["seg"] + 4)]
                if o != u: rec("dif", "ramp oem %s our %s args %s" % (o, u, [hex(x) for x in args]))
    if "wdr_en" in want:
        if call("wdr_en", "tisp_mdns_wdr_en", (ch, wdr), "emu_wdr_en", (P, C_, wdr), ret=False):
            cmp_mem("wdr_en", b, "wdr=%d" % wdr)
            fl = rd32(oem, S["mdns_wdr_en"] + 4 * ch)
            if fl != wdr: rec("wdr_en", "OEM flag mdns_wdr_en[%d] = %#x, wdr arg %#x" % (ch, fl, wdr))
    for c in (0, 1):                             # the pointer table is what the OEM wdr_en makes of it (its own test is `wdr_en`)
        r = oem.call("tisp_mdns_wdr_en", c, wdr); assert not r.stop
        our.write(b["comb%d" % c], oem.read(b["comb%d" % c], COMB))
    if "intp" in want:
        gain = gains()
        if call("intp", "tisp_mdns_intp", (ch, gain), "emu_intp", (P, C_, I, gain), ret=False): cmp_mem("intp", b, "gain=%#x ch=%d" % (gain, ch))
    if "start" in want: call("start", "tisp_mdns_start", (ch,), "emu_start", (ch,))
    if "reg_trig" in want: call("reg_trig", "tisp_mdns_reg_trig", (ch,), "emu_reg_trig", (ch,))
    if "func_en" in want:
        if call("func_en", "tisp_mdns_func_en", (ch,), "emu_func_en", (ch, P)): cmp_mem("func_en", b, "memopt=%#x ch=%d" % (mo, ch))
    if "reg_cfg" in want:
        if call("reg_cfg", "tisp_mdns_reg_cfg", (ch,), "emu_reg_cfg", (ch, P, I, w, h), divcheck=True): cmp_mem("reg_cfg", b, "ch=%d" % ch)
    gain = gains()
    if "all_reg" in want:
        if call("all_reg_refresh", "tisp_mdns_all_reg_refresh", (ch, gain), "emu_all_reg_refresh", (ch, gain, P, C_, I, w, h), divcheck=True): cmp_mem("all_reg_refresh", b, "gain=%#x ch=%d" % (gain, ch))
    if "par_refresh" in want:
        th = rnd.choice([256, 0, 1, rnd.randint(0, 0x2000), r32()])
        if rnd.random() < 0.8 and gold != 0xffffffff: gain = (gold + rnd.choice([rnd.randint(-300, 300), th, -th, th - 1, th + 1, 1 - th])) & M32     # incl. the threshold edge
        skip = gold != 0xffffffff and ((gold - gain if gain < gold else gain - gold) < th)
        if call("par_refresh", "tisp_mdns_par_refresh", (ch, gain, th), "emu_par_refresh", (ch, gain, th, P, C_, I, w, h, b["gold"]), ret=False, divcheck=True):
            cmp_mem("par_refresh", b, "gain=%#x old=%#x th=%#x" % (gain, gold, th)); cmp_gold("par_refresh", b, ch, "gain=%#x old=%#x th=%#x" % (gain, gold, th))
    oem.write(GOLD, w32(gold) * 2); our.write(b["gold"], w32(gold))
    if "refresh" in want:
        if gold != 0xffffffff and rnd.random() < 0.6: gain = (gold + rnd.choice([255, 256, 257, -255, -256, -257, rnd.randint(-300, 300)])) & M32     # threshold 256 edge
        if call("refresh", "tisp_mdns_refresh", (ch, gain), "emu_refresh", (ch, gain, P, C_, I, w, h, b["gold"]), divcheck=True):
            cmp_mem("refresh", b, "gain=%#x old=%#x" % (gain, gold)); cmp_gold("refresh", b, ch, "gain=%#x old=%#x" % (gain, gold))
    if "params" in want:
        bank = rbytes(BANK, 0.1); wr(b["bank"], bank)
        if call("params_refresh", "tisp_mdns_params_refresh", (ch,), "emu_params_refresh", (P, b["bank"]), ret=False): cmp_mem("params_refresh", b, "ch=%d" % ch)
for k in sorted(stats): print("%-16s %6d calls  %7d writes/helper calls compared  %d mismatches%s" % (k, stats[k], nlog.get(k, 0), bad.get(k, 0), ("  (%d skipped: zero divisor)" % skipped[k]) if k in skipped else ""))
if a.audit:
    for k in sorted(audit): print("AUDIT", k, sorted(audit[k]))
sys.exit(1 if bad else 0)
