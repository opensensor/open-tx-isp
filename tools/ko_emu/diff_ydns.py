#!/usr/bin/env python3
"""diff_ydns.py OEM.ko YDNS_EMU.o [--n 1000] [--seed 5] [--fn reg_cfg,reg_trig,intp,wdr_en,all_reg,intp_reg,par_refresh,params,refresh]

T40 YDNS (luma denoise) functions (issue #85): the OEM tisp_ydns_reg_cfg / reg_trig / intp / wdr_en / all_reg_refresh / intp_reg_refresh / par_refresh /
params_refresh / refresh of the vendor tx-isp-t40.ko and the hand-written C of driver/t40/tx_isp_t40_recovered.c (cut out and built for mipsel by
tests/t40_ydns/build_emu.sh into YDNS_EMU.o) run in Unicorn on the same random state (parameter record 465 bytes, pointer table 80, interpolated
block 22 per channel, WDR flags, the remembered gain, the tuning-bin pointer).  Compared: return value, every byte of the three blocks per channel,
flags, gain, and the order and values of the register writes and interpolation helper calls (tisp_simple_intp_int8 is replaced by a deterministic
function of its arguments and of the 64 table bytes behind the pointer in both emulators).
Not compared: the return value of intp / wdr_en / params_refresh and of par_refresh when it skips (the OEM returns a stale register, the C 0) and the channel numbers >= 2 of par_refresh / refresh (the C answers -EINVAL, the OEM would index past its gain array; no caller passes them).
Mutations are done by the caller (tests/t40_ydns_host.sh edits a copy of the driver source).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys, zlib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=1000); ap.add_argument("--seed", type=int, default=5)
ap.add_argument("--fn", default="reg_cfg,reg_trig,intp,wdr_en,all_reg,intp_reg,par_refresh,params,refresh")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
PAR, COMB, INTP, BIN = 465 + 64, 80, 22, 0x119ba + 465
FN = {"reg_cfg": "tisp_ydns_reg_cfg", "reg_trig": "tisp_ydns_reg_trig", "intp": "tisp_ydns_intp", "wdr_en": "tisp_ydns_wdr_en",
      "all_reg": "tisp_ydns_all_reg_refresh", "intp_reg": "tisp_ydns_intp_reg_refresh", "par_refresh": "tisp_ydns_par_refresh",
      "params": "tisp_ydns_params_refresh", "refresh": "tisp_ydns_refresh"}
log = {"oem": [], "our": []}
def h_write(tag): return lambda e: (log[tag].append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1]
def h_intp(tag):
    def f(e):
        x, y, p = e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1), e.get_reg(UC_MIPS_REG_A2)
        t = e.read(p, 64); log[tag].append(("i8", x, y, p, t)); return zlib.crc32(struct.pack("<II", x, y) + t) & M32
    return f
def hle(tag): return {"system_reg_write": h_write(tag), "tisp_simple_intp_int8": h_intp(tag), "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0}
oem = KoEmu(a.oem, hle=hle("oem"), max_insns=2_000_000); our = KoEmu(a.our, hle=hle("our"), max_insns=2_000_000); E = (oem, our)
for nm in ("system_reg_write", "tisp_simple_intp_int8"):      # the OEM defines these itself: hook the entries
    def mk(nm):
        f = hle("oem")[nm]
        def _hook(uc, addr, size, ud):
            rv = f(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
        return _hook
    ad = oem.symaddr[nm]; oem.uc.hook_add(UC_HOOK_CODE, mk(nm), None, ad, ad)
dsec = next(i for i, s in oem.elf.iter_sections() if False) if False else next(i for i, s in enumerate(oem.elf.iter_sections()) if s.name == ".data")
OS = {k: oem.symaddr[k] for k in ("main_ydns", "main_ydns_comb", "main_ydns_intp", "sec_ydns", "sec_ydns_comb", "sec_ydns_intp", "tparamsN")}
OS["flags"] = oem.symaddr["ydns_wdr_en"]; OS["gain"] = oem.secbase[dsec] + 0x2c8e0       # par_refresh: lui 3 / addiu -14112 on .data
US = {k: our.symaddr[k] for k in ("main_ydns", "main_ydns_comb", "main_ydns_intp", "sec_ydns", "sec_ydns_comb", "sec_ydns_intp", "tparamsN")}
US["flags"] = our.symaddr["regtrace_ydns_wdr_flag"]; US["gain"] = our.symaddr["regtrace_ydns_gain_old"]

def r32(): return rnd.getrandbits(32)
def rbytes(n): return bytes(0 if (r := rnd.random()) < 0.15 else 255 if r < 0.3 else rnd.getrandbits(8) for _ in range(n))
def gain(): return rnd.choice([r32(), rnd.getrandbits(20), (rnd.randrange(0, 12) << 16) | rnd.getrandbits(16), 0x10000, 0, 0xffffffff, 0x9ffff, 0xa0000, 0x7fffffff, 0x80000000])
def wr(addr, data): [e.write(addr, data) for e in E]
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("par0", PAR), ("comb0", COMB), ("intp0", INTP), ("par1", PAR), ("comb1", COMB), ("intp1", INTP), ("bin0", BIN), ("bin1", BIN)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    for e, sy in ((oem, OS), (our, US)):
        for k in ("main_ydns", "main_ydns_comb", "main_ydns_intp", "sec_ydns", "sec_ydns_comb", "sec_ydns_intp"):
            nm = k.replace("main_", "").replace("sec_", "")
            src = {"ydns": "par", "ydns_comb": "comb", "ydns_intp": "intp"}[nm] + ("0" if k.startswith("main") else "1")
            e.write(sy[k], struct.pack("<I", b[src]))
        e.write(sy["tparamsN"], struct.pack("<II", b["bin0"], b["bin1"]))
    for c in (0, 1):
        wr(b["par%d" % c], rbytes(PAR)); wr(b["intp%d" % c], rbytes(INTP)); wr(b["bin%d" % c], rbytes(BIN))
    st = struct.pack("<II", *[rnd.choice([r32(), 0xffffffff, 0xffffffff, 0x10000, rnd.getrandbits(20)]) for _ in range(2)]); fl = struct.pack("<II", r32() & 0xff, r32() & 0xff)
    for e, sy in ((oem, OS), (our, US)): e.write(sy["gain"], st); e.write(sy["flags"], fl)
    return b
stats = {}; bad = {}; nlog = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def dump(e, sy, b): return b"".join(e.read(b[k], n) for k, n in (("par0", 465), ("comb0", COMB), ("intp0", INTP), ("par1", 465), ("comb1", COMB), ("intp1", INTP))) + e.read(sy["gain"], 8) + e.read(sy["flags"], 8)
def sync_comb(b, ch):
    """give both a valid pointer table (what wdr_en makes of it): run the OEM wdr_en, copy to ours"""
    for c in (0, 1):
        oem.call("tisp_ydns_wdr_en", c, rnd.choice([0, 1])); our.write(b["comb%d" % c], oem.read(b["comb%d" % c], COMB))
        fl = oem.read(OS["flags"], 8); our.write(US["flags"], fl)
def call(name, b, args):
    log["oem"].clear(); log["our"].clear()
    ro = oem.call(FN[name if name in FN else name], *args); ru = our.call(FN[name], *args)
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate((ro, ru)):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return
    if name not in ("intp", "wdr_en", "params") and not (name == "par_refresh" and not log["oem"]) and ro.v0 != ru.v0: rec(name, "return oem %#x our %#x args %s" % (ro.v0, ru.v0, [hex(x) for x in args])); return
    if log["oem"] != log["our"]:
        o, c = log["oem"], log["our"]; k = next((j for j in range(min(len(o), len(c))) if o[j] != c[j]), min(len(o), len(c)))
        rec(name, "call/write log differs at #%d (oem %d entries, our %d): oem %s our %s args %s" % (k, len(o), len(c), (o[k][:3] if k < len(o) else None), (c[k][:3] if k < len(c) else None), [hex(x) for x in args])); return
    nlog[name] = nlog.get(name, 0) + len(log["oem"])
    do, du = dump(oem, OS, b), dump(our, US, b)
    if do != du:
        i = next(j for j in range(len(do)) if do[j] != du[j]); rec(name, "state differs at byte %d of the dump (oem %02x our %02x) args %s" % (i, do[i], du[i], [hex(x) for x in args]))
want = a.fn.split(",")
for it in range(a.n):
    b = setup(); ch = rnd.choice([0, 1, 1, 0, 2, 5]) if it % 5 == 0 else rnd.choice([0, 1]); sync_comb(b, ch); g = gain()
    for name in want:
        if name in ("reg_cfg", "reg_trig"): args = (ch,)
        elif name == "wdr_en": args = (ch, rnd.choice([0, 1, 2, 0xff, r32()]))
        elif name == "params": args = (rnd.choice([0, 1]),)
        elif name in ("par_refresh", "refresh"):
            old = struct.unpack("<I", oem.read(OS["gain"] + 4 * (ch & 1), 4))[0]
            if rnd.random() < 0.6: g = (old + rnd.choice([-257, -256, -255, -1, 1, 255, 256, 257, 0])) & M32       # on and next to the 256 step of refresh / the threshold
            if name == "par_refresh": args = (ch, g, rnd.choice([0, 1, 256, 0x10000, r32(), rnd.getrandbits(12), (g - old) & M32, (old - g) & M32, ((g - old) & M32) + 1, ((old - g) & M32) + 1]) & M32)
            else: args = (ch, g)
        else: args = (ch, g)
        if name == "wdr_en": ch2 = ch if ch < 2 else 0; args = (ch2,) + args[1:]       # the C guards against channels >= 2 for the table; the OEM would index out of the block set
        if name in ("reg_cfg", "reg_trig", "intp", "all_reg", "intp_reg", "par_refresh", "refresh") and ch >= 2: args = (rnd.choice([0, 1]),) + args[1:]
        call(name, b, args)
for k in sorted(stats): print("%-12s %6d calls  %8d writes/helper calls compared  %d mismatches" % (k, stats[k], nlog.get(k, 0), bad.get(k, 0)))
sys.exit(1 if bad else 0)
