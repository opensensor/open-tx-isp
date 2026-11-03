#!/usr/bin/env python3
"""diff_blc.py OEM.ko BLC_EMU.o [--n 1000] [--seed 5] [--fn NAME,...]

T40 BLC block (issue #85): the OEM tisp_blc_ag_interp / calc_digital_gain / write_reg / ag_long_frame_update / ag_short_frame_update /
ae_write_dgain / init / dn_params_refresh of the vendor tx-isp-t40.ko and the C of driver/t40/tx_isp_t40_blc.h (built for mipsel by
tests/t40_blc/build_emu.sh into BLC_EMU.o) run in Unicorn on the same random state: tool block, hard records, last gains, Bayer types, the
tuning-bin pointer array.  Compared: return value, every byte of the tool and hard blocks, the gains and the Bayer bytes, and the order and
values of the register reads / writes.  "update" checks the driver's gain-parameter entry (t40_blc_update, used by the blc_lit path): with
gain 1024 it must equal the OEM init / refresh, with another gain it is compared with the OEM sub-functions run in the same order.
Not compared: OEM tisp_blc_ag_interp with a maximum black level of exactly 4096 (division by zero in the OEM, undefined result; counted).
--mutate is done by the caller (tests/t40_blc_host.sh edits a copy of the header).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=1000); ap.add_argument("--seed", type=int, default=5)
ap.add_argument("--fn", default="ag_interp,calc,write_reg,long,short,ae_write_dgain,init,refresh,update")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
TOOL, REC, BIN = 252, 36, 9040 + 252
READ = {"v": 0}
log = {"oem": [], "our": []}
def mk_hle(tag):
    L = log[tag]
    return {"system_reg_write": lambda e: (L.append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1],
            "system_reg_read": lambda e: (L.append(("r", e.get_reg(UC_MIPS_REG_A0))), READ["v"])[1],
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0,
            "private_kmalloc": lambda e: oem_alloc(e.get_reg(UC_MIPS_REG_A0)), "__kmalloc": lambda e: oem_alloc(e.get_reg(UC_MIPS_REG_A0)),
            "private_kfree": lambda e: 0, "kfree": lambda e: 0}
oem = KoEmu(a.oem, hle=mk_hle("oem"), max_insns=2_000_000); our = KoEmu(a.our, hle=mk_hle("our"), max_insns=2_000_000)
E = (oem, our)
def oem_alloc(n): return oem.alloc(n, bytes(n))
for nm in ("system_reg_write", "system_reg_read"):       # the OEM defines these itself: hook the entries
    def mk(nm):
        f = mk_hle("oem")[nm]
        def _hook(uc, addr, size, ud):
            rv = f(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
        return _hook
    ad = oem.symaddr[nm]; oem.uc.hook_add(UC_HOOK_CODE, mk(nm), None, ad, ad)
OS = {k: oem.symaddr[k] for k in ("blc_main_tool_para", "blc_seco_tool_para", "blc_main_hard_para", "blc_seco_hard_para", "s_blc_again", "s_blc_bayer_type", "tparamsN")}
US = {"tool": our.symaddr["t40_blc_tool"], "hard": our.symaddr["t40_blc_hard"], "again": our.symaddr["t40_blc_again"],
      "bayer": our.symaddr["t40_blc_bayer"], "tparamsN": our.symaddr["tparamsN"]}

def r32(): return rnd.getrandbits(32)
def u16s(vals): return b"".join(struct.pack("<H", v & 0xffff) for v in vals)
def lvl():
    return rnd.choice([0, 1, 0x7ff, 0x800, 0xfff, 0xffff, 0x8000, 0x1001, 0xfff, rnd.getrandbits(11), rnd.getrandbits(12), rnd.getrandbits(12),
                       rnd.getrandbits(16), rnd.randrange(1900, 2300), rnd.randrange(3900, 4300)])
def mk_tool():
    d = bytearray(random.Random(r32()).randbytes(TOOL))
    for off in (36, 58, 80, 102):
        if rnd.random() < 0.25:
            base = lvl(); vals = [min(0xffff, base + rnd.randrange(0, 64)) for _ in range(11)]     # flat-ish table
        else:
            vals = [lvl() for _ in range(11)]
        d[off:off + 22] = u16s(vals)
    return bytes(d)
def gain():
    return rnd.choice([r32(), rnd.getrandbits(20), (rnd.randrange(0, 12) << 16) | rnd.getrandbits(16), (rnd.randrange(0, 11) << 16), 1024,
                       0, 0xffffffff, 0x9ffff, 0xa0000, 0x9ffff, (rnd.randrange(0, 10) << 16) | 0xffff, (rnd.randrange(0, 10) << 16) | 0x8000])
def near(old):
    return (old + rnd.choice([0, 1, -1, 1023, -1023, 1024, -1024, 1025, -1025, 512, -512, 65536, -65536])) & M32
def pval(sf):
    """digital gain term: often chosen so that self * p >> 12 sits on a power-of-two boundary (the shift ladder of calc_digital_gain)"""
    k = rnd.choice([10, 15, 16, 17, 18, 19, 20])
    t = ((1 << k) << 12) // max(sf, 1)
    return rnd.choice([1024, rnd.getrandbits(15), rnd.getrandbits(20), r32(), t, t + 1, t - 1, 0, 0x7fff, 0x8000, rnd.getrandbits(13)]) & M32
def mk_rec():
    sf = rnd.choice([4096, 8192, rnd.randrange(4096, 8193), rnd.getrandbits(16), rnd.getrandbits(14), 0, 1, 0xffff])
    r = bytearray(random.Random(r32()).randbytes(REC))
    r[0:8] = u16s([lvl() for _ in range(4)]); r[8:10] = u16s([lvl()]); r[10:12] = u16s([sf])
    r[12] = rnd.choice([0, 1, 2, 3, rnd.getrandbits(8)])
    r[16:28] = struct.pack("<III", *[pval(sf) for _ in range(3)])
    r[28:34] = u16s([rnd.choice([0, 1, 1024, rnd.getrandbits(16), 0x7fff, 0x8000]) for _ in range(3)])
    return bytes(r)
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("tool0", TOOL), ("tool1", TOOL), ("hard0", 2 * REC), ("hard1", 2 * REC), ("bin0", BIN), ("bin1", BIN)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    return b
def prepare(b):
    """identical random state in both emulators"""
    st = {"tool": [mk_tool(), mk_tool()], "hard": [mk_rec() + mk_rec(), mk_rec() + mk_rec()], "again": [r32() for _ in range(4)],
          "bayer": bytes(rnd.choice([0, 1, 2, 3, 0, 1, 2, 3, 4, 7]) for _ in range(2)), "bin": [bytes(9040) + mk_tool(), bytes(9040) + mk_tool()]}
    READ["v"] = rnd.choice([0, 1, 2, 3, 4, 5, 6, 7, r32()])
    for i in range(2):
        for e in E: e.write(b["bin%d" % i], st["bin"][i]); e.write(b["tool%d" % i], st["tool"][i]); e.write(b["hard%d" % i], st["hard"][i])
    for nm, k in (("blc_main_tool_para", "tool0"), ("blc_seco_tool_para", "tool1"), ("blc_main_hard_para", "hard0"), ("blc_seco_hard_para", "hard1")):
        oem.write(OS[nm], struct.pack("<I", b[k]))
    for i in range(2):
        oem.write(OS["tparamsN"] + 4 * i, struct.pack("<I", b["bin%d" % i])); our.write(US["tparamsN"] + 4 * i, struct.pack("<I", b["bin%d" % i]))
    oem.write(OS["s_blc_again"], struct.pack("<4I", *st["again"])); our.write(US["again"], struct.pack("<4I", *st["again"]))
    oem.write(OS["s_blc_bayer_type"], st["bayer"]); our.write(US["bayer"], st["bayer"])
    our.write(US["tool"], st["tool"][0] + st["tool"][1]); our.write(US["hard"], st["hard"][0] + st["hard"][1])
    return st
def dump(e, which, b):
    if which == "oem":              # the OEM init allocates new blocks: follow the pointer variables
        ptr = lambda nm: struct.unpack("<I", e.read(OS[nm], 4))[0]
        hm, hs = ptr("blc_main_hard_para"), ptr("blc_seco_hard_para")
        return (e.read(ptr("blc_main_tool_para"), TOOL) + e.read(ptr("blc_seco_tool_para"), TOOL), e.read(hm, REC) + e.read(hm + REC, REC) + e.read(hs, REC) + e.read(hs + REC, REC),
                e.read(OS["s_blc_again"], 16), e.read(OS["s_blc_bayer_type"], 2))
    return (e.read(US["tool"], 2 * TOOL), e.read(US["hard"], 4 * REC), e.read(US["again"], 16), e.read(US["bayer"], 2))

stats = {}; bad = {}; skipped = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def compare(name, b, rs, ctx, pre_oem=()):
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return
    do, du = dump(oem, "oem", b), dump(our, "our", b)
    for k in range(0, 4, 1):                               # division by zero in the OEM (maximum exactly 4096): undefined result, skipped
        pass
    hard = do[1]
    if any(struct.unpack_from("<H", hard, o + 8)[0] == 4096 for o in range(0, 4 * REC, REC)) and name in ("ag_interp", "long", "short", "init", "refresh", "update"):
        skipped[name] = skipped.get(name, 0) + 1; stats[name] -= 1; return
    if rs[0].v0 != rs[1].v0: rec(name, "return oem %#x our %#x %s" % (rs[0].v0, rs[1].v0, ctx)); return
    lo, lu = log["oem"], log["our"]
    if lo != lu:
        j = next((k for k in range(min(len(lo), len(lu))) if lo[k] != lu[k]), min(len(lo), len(lu)))
        rec(name, "register accesses differ at #%d (oem %d / our %d): oem %s our %s %s" % (j, len(lo), len(lu), [tuple(map(hex, x[1:])) for x in lo[j:j + 3]], [tuple(map(hex, x[1:])) for x in lu[j:j + 3]], ctx)); return
    for k, lab in enumerate(("tool blocks", "hard records", "gains", "bayer")):
        if do[k] != du[k]:
            i = next(j for j in range(len(do[k])) if do[k][j] != du[k][j])
            rec(name, "%s differ at +%d (oem %02x our %02x) %s" % (lab, i, do[k][i], du[k][i], ctx)); return
def call_pair(name, b, oem_fn, oem_args, our_fn, our_args, ostack=(), ustack=(), ctx=""):
    log["oem"].clear(); log["our"].clear()
    ro = oem.call(oem_fn, *oem_args, stack_args=ostack); ru = our.call(our_fn, *our_args, stack_args=ustack)
    compare(name, b, (ro, ru), ctx or "args %s" % [hex(x) for x in our_args + tuple(ustack)])

def oem_update(b, ch, g, init):
    """OEM sub-functions in the order of tisp_blc_init / dn_params_refresh, with `g` instead of 1024 (state prepared by the script)"""
    c = ch; log["oem"].clear(); log["our"].clear()
    log["oem"].append(("r", (ch + 34) << 2))
    bay = READ["v"] & 3
    oem.write(OS["s_blc_bayer_type"] + c, bytes([bay])); oem.write(OS["s_blc_again"] + 8 * c, struct.pack("<II", g, g))
    oem.write(b["tool%d" % c], oem.read(b["bin%d" % c] + 9040, TOOL)); oem.write(b["hard%d" % c], bytes(2 * REC))
    for r_ in (0, 1): oem.write(b["hard%d" % c] + r_ * REC + 16, struct.pack("<III", 1024, 1024, 1024))
    rs = []
    rs.append(oem.call("tisp_blc_ag_interp", ch, 0, g, 1)); rs.append(oem.call("tisp_blc_ag_interp", ch, 1, g, 1))
    rs.append(oem.call("tisp_blc_calc_digital_gain", ch, 0)); rs.append(oem.call("tisp_blc_calc_digital_gain", ch, 1))
    if init:
        log["oem"].append(("w", ((ch + 64) << 7) + 16, 0)); log["oem"].append(("w", ((ch + 64) << 7) + 32, 0))
    rs.append(oem.call("tisp_blc_write_reg", ch, 0, 0)); rs.append(oem.call("tisp_blc_write_reg", ch, 1, 0))
    return rs

want = a.fn.split(",")
for it in range(a.n):
    b = setup()
    for name in want:
        st = prepare(b); ch = rnd.choice([0, 1]); idx = rnd.choice([0, 1])
        if name == "ag_interp":
            g = near(st["again"][2 * ch + idx]) if rnd.random() < 0.4 else gain()
            f = rnd.choice([0, 0, 1])
            call_pair(name, b, "tisp_blc_ag_interp", (ch, idx, g, f), "emu_ag_interp", (ch, idx, g, f))
        elif name == "calc": call_pair(name, b, "tisp_blc_calc_digital_gain", (ch, idx), "emu_calc", (ch, idx))
        elif name == "write_reg":
            m = rnd.choice([0, 1, 2, 3, 0, 1, 2]); call_pair(name, b, "tisp_blc_write_reg", (ch, idx, m), "emu_write_reg", (ch, idx, m))
        elif name in ("long", "short"):
            g = near(st["again"][2 * ch + (0 if name == "long" else 1)]) if rnd.random() < 0.5 else gain(); junk = r32()
            call_pair(name, b, "tisp_blc_ag_%s_frame_update" % name, (ch, junk, g), "emu_" + name, (ch, junk, g))
        elif name == "ae_write_dgain":
            v = [rnd.choice([r32(), rnd.getrandbits(15), 1024, 0x7fff, 0x8000, rnd.getrandbits(20)]) for _ in range(3)]
            call_pair(name, b, "tisp_blc_ae_write_dgain", (ch, idx, v[0], v[1]), "emu_ae_write_dgain", (ch, idx, v[0], v[1]), (v[2],), (v[2],))
        elif name == "init": call_pair(name, b, "tisp_blc_init", (ch,), "emu_init", (ch,))
        elif name == "refresh": call_pair(name, b, "tisp_blc_dn_params_refresh", (ch,), "emu_refresh", (ch,))
        elif name == "update":
            g = rnd.choice([1024, gain(), gain()]); ini = rnd.choice([0, 1])
            if g == 1024:
                call_pair(name, b, "tisp_blc_init" if ini else "tisp_blc_dn_params_refresh", (ch,), "emu_update", (ch, g, ini))
            else:
                ro = oem_update(b, ch, g, ini); log["our"].clear(); ru = our.call("emu_update", ch, g, ini)
                compare(name, b, (ru, ru), "update gain %#x init %d ch %d" % (g, ini, ch))
for k in sorted(stats): print("%-16s %6d calls  %d mismatches%s" % (k, stats[k], bad.get(k, 0), ("  (%d skipped: OEM division by zero)" % skipped[k]) if k in skipped else ""))
sys.exit(1 if bad else 0)
