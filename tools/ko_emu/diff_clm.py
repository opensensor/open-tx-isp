#!/usr/bin/env python3
"""diff_clm.py OEM.ko CLM_EMU.o [--n 300] [--seed 7] [--fn NAME,...]

T40 CLM block (issue #85): the OEM tisp_clm_init / ct_interp / write_csc_para / real_write_lut / prepare_write_lut /
get_wlut_times / dn_params_refresh / wdr_en / ct_update / deinit of the vendor tx-isp-t40.ko and the C of
driver/t40/tx_isp_t40_clm.h (+ the CLM step of tx_isp_t40_ct_chain.h; built for mipsel by tests/t40_clm/build_emu.sh into
CLM_EMU.o) run in Unicorn on the same random state: tuning-bank bytes (random tables, CT points around the zone limits),
context state (CT, threshold, zone, WDR flag), CSC block, write counters, saved frame numbers, TOP word.
Compared after every call: return value, every byte of the parameter copy, the LUT image, the state and the CSC block, the
table selection (OEM pointers relative to the parameter copy vs the C offsets), the write counters and saved frame numbers,
the order and values of the register writes and reads, and the get_wlut_times output.
Not kept from the OEM (and not compared): the printk the vendor ct_interp issues on every call.
Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=300); ap.add_argument("--seed", type=int, default=7)
ap.add_argument("--fn", default="init,interp,csc,write,prepare,times,refresh,wdr,ct_update,deinit")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
PAR, REAL, BINOFF, BIN = 18924, 3150, 65536 + 9132, 65536 + 9132 + 18924
READ = {"v": 0}
log = {"oem": [], "our": []}
def mk_hle(tag):
    L = log[tag]
    return {"system_reg_write": lambda e: (L.append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1],
            "system_reg_read": lambda e: (L.append(("r", e.get_reg(UC_MIPS_REG_A0))), READ["v"])[1],
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0,
            "private_kmalloc": lambda e: oem.alloc(e.get_reg(UC_MIPS_REG_A0), bytes(e.get_reg(UC_MIPS_REG_A0))),
            "__kmalloc": lambda e: oem.alloc(e.get_reg(UC_MIPS_REG_A0), bytes(e.get_reg(UC_MIPS_REG_A0))), "kfree": lambda e: 0,
            "emu_alloc": lambda e: our.alloc(e.get_reg(UC_MIPS_REG_A0), bytes(e.get_reg(UC_MIPS_REG_A0))),
            "private_kfree": lambda e: 0, "private_spin_lock_init": lambda e: 0}
oem = KoEmu(a.oem, hle=mk_hle("oem"), max_insns=4_000_000); our = KoEmu(a.our, hle=mk_hle("our"), max_insns=4_000_000)
E = (oem, our)
for nm in ("system_reg_write", "system_reg_read"):       # the OEM defines these itself: hook the entries
    def mk(nm):
        f = mk_hle("oem")[nm]
        def _hook(uc, addr, size, ud):
            rv = f(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
        return _hook
    ad = oem.symaddr[nm]; oem.uc.hook_add(UC_HOOK_CODE, mk(nm), None, ad, ad)
OS = {k: oem.symaddr[k] for k in ("clm_para", "clm_wlut_times", "clm_frame_num_saved", "clm_wlut_frequency", "tparamsN")}
US = {k: our.symaddr[k] for k in ("t40_clm_ctx", "t40_clm_wlut_times", "t40_clm_frame_saved", "t40_clm_wlut_frequency", "tparamsN")}
u32 = lambda e, ad: struct.unpack("<I", e.read(ad, 4))[0]

def r32(): return rnd.getrandbits(32)
def ctval(pts):
    """a CT near one of the zone limits (+-100 around the three points) or anywhere"""
    p = rnd.choice(pts); lim = rnd.choice([p - 100, p + 100, p])
    return rnd.choice([(lim + rnd.randrange(-3, 4)) & M32, rnd.randrange(1500, 12000), rnd.randrange(0, 0x10000), r32(), lim & M32, lim & M32])
def mk_bank():
    d = bytearray(random.Random(r32()).randbytes(PAR))
    for off in (18912, 18918):                              # CT points (linear / WDR set): mostly ordered high > mid > low
        if rnd.random() < 0.8:
            lo = rnd.randrange(2000, 3600); mid = lo + rnd.randrange(150, 2000); hi = mid + rnd.randrange(150, 3000)
            if rnd.random() < 0.1: mid = lo + rnd.randrange(0, 250)
            d[off:off + 6] = struct.pack("<3H", hi & 0xffff, mid & 0xffff, lo & 0xffff)
    return bytes(d)
def mk_csc():
    d = bytearray(random.Random(r32()).randbytes(92))
    for off in range(0, 92, 4):
        if rnd.random() < 0.5:
            v = rnd.choice([0, 1, -1, 32, 63, 64, -64, 127, 128, -128, 32768, -32768, rnd.randrange(-70000, 70000), r32() - (1 << 31)])
            d[off:off + 4] = struct.pack("<i", v)
    d[40] = rnd.choice([0, 1, 255, rnd.getrandbits(8)]); d[42] = rnd.choice([0, 0, 1, rnd.getrandbits(8)])
    return bytes(d)

def ctx_ptrs(e, which, b):
    if which == "oem":
        c = u32(e, OS["clm_para"] + 4 * b)
        if not c: return None
        return {"params": u32(e, c), "tab": u32(e, c + 4), "real": u32(e, c + 8), "st": u32(e, c + 12), "csc": u32(e, c + 16)}
    c = u32(e, US["t40_clm_ctx"] + 4 * b)
    if not c: return None
    return {"params": u32(e, c), "tab": c + 4, "real": u32(e, c + 36), "st": c + 40, "csc": c + 48}
def dump(e, which):
    S = OS if which == "oem" else US
    out = []
    for b in (0, 1):
        p = ctx_ptrs(e, which, b)
        if p is None: out.append(None); continue
        tab = struct.unpack("<8I", e.read(p["tab"], 32))
        if which == "oem": tab = tuple((t - p["params"]) & M32 for t in tab)
        out.append((e.read(p["params"], PAR), tab, e.read(p["real"], REAL), e.read(p["st"], 8), e.read(p["csc"], 92)))
    k = "clm_wlut_times" if which == "oem" else "t40_clm_wlut_times"; f = "clm_frame_num_saved" if which == "oem" else "t40_clm_frame_saved"
    return out, e.read(S[k], 2), e.read(S[f], 16)

def setup():
    for e in E: e.heap_reset()
    b = {}
    for i in (0, 1):
        ads = [e.alloc(BIN, bytes(BIN)) for e in E]; assert ads[0] == ads[1]; b[i] = ads[0]
    for i in (0, 1):
        oem.write(OS["tparamsN"] + 4 * i, struct.pack("<I", b[i])); our.write(US["tparamsN"] + 4 * i, struct.pack("<I", b[i]))
    for e, S in ((oem, OS), (our, US)):                      # fresh contexts (init allocates)
        k = "clm_para" if e is oem else "t40_clm_ctx"; e.write(S[k], bytes(8))
    return b
def fill_bank(b, i):
    d = mk_bank()
    for e in E: e.write(b[i] + BINOFF, d)
def init_both(bank):
    log["oem"].clear(); log["our"].clear()
    return oem.call("tisp_clm_init", bank), our.call("emu_init", bank)
def set_state(bank, ct=None, thr=None, zone=None, wdr=None, csc=None):
    po, pu = ctx_ptrs(oem, "oem", bank), ctx_ptrs(our, "our", bank)
    if po is None or pu is None: return
    for e, p in ((oem, po), (our, pu)):
        st = bytearray(e.read(p["st"], 8))
        if ct is not None: st[0:4] = struct.pack("<I", ct & M32)
        if thr is not None: st[4:6] = struct.pack("<H", thr & 0xffff)
        if zone is not None: st[6] = zone & 255
        if wdr is not None: st[7] = wdr & 255
        e.write(p["st"], bytes(st))
        if csc is not None: e.write(p["csc"], csc)
def set_counters(times, saved, freq):
    oem.write(OS["clm_wlut_times"], times); our.write(US["t40_clm_wlut_times"], times)
    oem.write(OS["clm_frame_num_saved"], saved); our.write(US["t40_clm_frame_saved"], saved)
    oem.write(OS["clm_wlut_frequency"], freq); our.write(US["t40_clm_wlut_frequency"], freq)

stats = {}; bad = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def compare(name, rs, ctx, extra=None):
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s %s" % ("oem" if i == 0 else "our", r.stop, ctx)); return False
    if rs[0].v0 != rs[1].v0: rec(name, "return oem %#x our %#x %s" % (rs[0].v0, rs[1].v0, ctx)); return False
    lo, lu = log["oem"], log["our"]
    if lo != lu:
        j = next((k for k in range(min(len(lo), len(lu))) if lo[k] != lu[k]), min(len(lo), len(lu)))
        rec(name, "register accesses differ at #%d (oem %d / our %d): oem %s our %s %s" % (j, len(lo), len(lu), [tuple(map(hex, x[1:])) for x in lo[j:j + 3]], [tuple(map(hex, x[1:])) for x in lu[j:j + 3]], ctx)); return False
    do, du = dump(oem, "oem"), dump(our, "our")
    for bk in (0, 1):
        x, y = do[0][bk], du[0][bk]
        if (x is None) != (y is None): rec(name, "context %d present oem %s our %s %s" % (bk, x is not None, y is not None, ctx)); return False
        if x is None: continue
        for k, lab in enumerate(("params", "table selection", "LUT image", "state", "csc")):
            if x[k] != y[k]:
                if k == 1: rec(name, "bank %d table selection oem %s our %s %s" % (bk, x[k], y[k], ctx)); return False
                i = next(j for j in range(len(x[k])) if x[k][j] != y[k][j])
                rec(name, "bank %d %s differ at +%d (oem %02x our %02x) %s" % (bk, lab, i, x[k][i], y[k][i], ctx)); return False
    if do[1] != du[1]: rec(name, "write counters oem %s our %s %s" % (do[1].hex(), du[1].hex(), ctx)); return False
    if do[2] != du[2]: rec(name, "saved frame numbers oem %s our %s %s" % (do[2].hex(), du[2].hex(), ctx)); return False
    if extra and extra[0] != extra[1]: rec(name, "output oem %s our %s %s" % (extra[0], extra[1], ctx)); return False
    return True

want = a.fn.split(",")
for it in range(a.n):
    b = setup()
    for name in want:
        b = setup(); bank = rnd.choice([0, 1, 0])
        fill_bank(b, 0); fill_bank(b, 1)
        READ["v"] = rnd.choice([0, 0x10000, 0x7fd0000d, 0x7fd9004d, r32()])
        set_counters(bytes([rnd.getrandbits(8), rnd.getrandbits(8)]), random.Random(r32()).randbytes(16), bytes([rnd.choice([0, 1, 5, 255]), rnd.choice([0, 5])]))
        if name == "init":
            compare(name, init_both(bank), "init bank %d" % bank); continue
        ri = init_both(bank)
        if not compare("init", ri, "pre-init bank %d" % bank): continue
        pts = list(struct.unpack("<3H", oem.read(b[bank] + BINOFF + 18912, 6)))
        set_state(bank, ct=ctval(pts), thr=rnd.choice([0, 64, 100, 0xffff, 0x8000, rnd.getrandbits(16)]), zone=rnd.choice([0, 1, 2, 3, 4, 5, rnd.getrandbits(8)]),
                  wdr=rnd.choice([0, 1]), csc=mk_csc() if rnd.random() < 0.5 else None)
        log["oem"].clear(); log["our"].clear()
        if name == "interp":
            ct = ctval(pts); f = rnd.choice([0, 0, 1])
            compare(name, (oem.call("tisp_clm_ct_interp", bank, ct, f), our.call("emu_interp", bank, ct, f)), "bank %d ct %d force %d pts %s" % (bank, ct, f, pts))
            if rnd.random() < 0.7:                          # a second, unforced call close to the first: same zone, threshold
                ct2 = (ct + rnd.choice([0, 1, -1, 63, 64, 65, -64, -65, rnd.randrange(-300, 300)])) & M32; log["oem"].clear(); log["our"].clear()
                compare(name, (oem.call("tisp_clm_ct_interp", bank, ct2, 0), our.call("emu_interp", bank, ct2, 0)), "bank %d ct %d->%d pts %s" % (bank, ct, ct2, pts))
        elif name == "csc": compare(name, (oem.call("tisp_clm_write_csc_para", bank), our.call("emu_csc", bank)), "bank %d" % bank)
        elif name == "write": compare(name, (oem.call("tisp_clm_real_write_lut", bank), our.call("emu_write", bank)), "bank %d" % bank)
        elif name == "prepare": compare(name, (oem.call("tisp_clm_prepare_write_lut", bank), our.call("emu_prepare", bank)), "bank %d" % bank)
        elif name == "times":
            outs = [e.alloc(4, struct.pack("<I", 0xdeadbeef)) for e in E]
            ro = oem.call("tisp_clm_get_wlut_times", bank, outs[0]); ru = our.call("emu_times", bank, outs[1])
            compare(name, (ro, ru), "bank %d read %#x" % (bank, READ["v"]), (oem.read(outs[0], 4), our.read(outs[1], 4)))
        elif name == "refresh":
            fill_bank(b, bank)
            compare(name, (oem.call("tisp_clm_dn_params_refresh", bank), our.call("emu_refresh", bank)), "bank %d" % bank)
        elif name == "wdr":
            en = rnd.choice([0, 1, 1, 2]); compare(name, (oem.call("tisp_clm_wdr_en", bank, en), our.call("emu_wdr", bank, en)), "bank %d en %d" % (bank, en))
        elif name == "ct_update":
            ct = ctval(pts); saved = struct.unpack("<Q", oem.read(OS["clm_frame_num_saved"] + 8 * bank, 8))[0]
            fn = rnd.choice([saved + rnd.randrange(0, 12), saved - 1, r32() | (r32() << 32), saved + (1 << 32), saved]) & ((1 << 64) - 1)
            j1, j2 = r32(), r32(); st = (fn & M32, fn >> 32)
            compare(name, (oem.call("tisp_clm_ct_update", bank, j1, ct, j2, stack_args=st), our.call("emu_ct_update", bank, j1, ct, j2, stack_args=st)),
                    "bank %d ct %d fnum %#x" % (bank, ct, fn))
        elif name == "deinit":
            compare(name, (oem.call("tisp_clm_deinit", bank), our.call("emu_deinit", bank)), "bank %d" % bank)
for k in sorted(stats): print("%-10s %6d calls  %d mismatches" % (k, stats[k], bad.get(k, 0)))
sys.exit(1 if bad or not stats else 0)
