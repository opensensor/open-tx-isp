#!/usr/bin/env python3
"""diff_gib.py OEM.ko GIB_EMU.o [--n 1500] [--seed 3] [--fn NAME,...]

T40 GIB block (issue #85): the OEM tisp_gib_tool_2_real / interp_by_gain / blc_value_to_self_gain / calc_digital_gain / interp_by_ir /
write_reg / a_gian_update / ir_update / dn_params_refresh of the vendor tx-isp-t40.ko and the hand-written C of driver/t40/tx_isp_t40_recovered.c
(cut out and built for mipsel by tests/t40_gib/build_emu.sh into GIB_EMU.o) run in Unicorn on the same random state: tool and real parameter
blocks, the gain / IR state (gib_AG, gib_IR, IR-mode byte), the descriptor words the bayer type is read from, both channels.  Compared: return
value, every byte of the two blocks and of the state, and the order and values of the register writes (and reads).
Known intended differences: none (the NULL guards of the C are not exercised: the blocks are always present).
--mutate is done by the caller (tests/t40_gib_host.sh edits a copy of the driver source).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=1500); ap.add_argument("--seed", type=int, default=3)
ap.add_argument("--fn", default="tool_2_real,interp_by_gain,self_gain,calc_digital_gain,interp_by_ir,write_reg,a_gian_update,ir_update,dn_params_refresh")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
FN = {"tool_2_real": "tisp_gib_tool_2_real", "interp_by_gain": "tisp_gib_interp_by_gain", "self_gain": "tisp_gib_blc_value_to_self_gain",
      "calc_digital_gain": "tisp_gib_calc_digital_gain", "interp_by_ir": "tisp_gib_interp_by_ir", "write_reg": "tisp_gib_write_reg",
      "a_gian_update": "tisp_gib_a_gian_update", "ir_update": "tisp_gib_ir_update", "dn_params_refresh": "tisp_gib_dn_params_refresh"}
TOOL, REAL = 872, 284
READ_VAL = [0x0, 0x5, 0x1f, 0x14, 0x2]

log = {"oem": [], "our": []}
def mk_hle(tag):
    L = log[tag]
    return {"system_reg_write": lambda e: (L.append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1],
            "system_reg_read": lambda e: (L.append(("r", e.get_reg(UC_MIPS_REG_A0))), READ_VAL[e.get_reg(UC_MIPS_REG_A0) & 3])[1],
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0}
oem = KoEmu(a.oem, hle=mk_hle("oem"), max_insns=2_000_000); our = KoEmu(a.our, hle=mk_hle("our"), max_insns=2_000_000)
E = (oem, our)
for nm in ("system_reg_write", "system_reg_read"):       # the OEM defines these itself: hook the entries
    def mk(nm):
        f = mk_hle("oem")[nm]
        def _hook(uc, addr, size, ud):
            rv = f(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
        return _hook
    ad = oem.symaddr[nm]; oem.uc.hook_add(UC_HOOK_CODE, mk(nm), None, ad, ad)
OS = {k: oem.symaddr[k] for k in ("gib_main_tool_para", "gib_seco_tool_para", "gib_main_real_para", "gib_seco_real_para", "gib_AG", "gib_IR",
                                  "GIB_IR_MODE", "tisp_par_info", "tparamsN")}
US = {"gib_main_tool_para": our.symaddr["gib_main_tool_para"], "gib_seco_tool_para": our.symaddr["gib_seco_tool_para"],
      "gib_main_real_para": our.symaddr["gib_main_real_para"], "gib_seco_real_para": our.symaddr["gib_seco_real_para"],
      "gib_AG": our.symaddr["t40_gib_AG"], "gib_IR": our.symaddr["gib_IR"], "GIB_IR_MODE": our.symaddr["t40_gib_ir_mode"],
      "tisp_par_info": our.symaddr["tisp_par_info"], "tparamsN": our.symaddr["tparamsN"]}

def r32(): return rnd.getrandbits(32)
def rbytes(n): return bytes(rnd.getrandbits(8) for _ in range(n))
def u16s(vals): return b"".join(struct.pack("<H", v & 0xffff) for v in vals)
def edge16(): return rnd.choice([0, 1, 0xfff, 0x1000, 0x7ff, 0x800, 0xffff, 0x8000, rnd.getrandbits(12), rnd.getrandbits(16), rnd.getrandbits(10)])
def gain():
    return rnd.choice([r32(), rnd.getrandbits(20), (rnd.randrange(0, 12) << 16) | rnd.getrandbits(16), 1024, 0x10000, 0, 0xffffffff, 0x9ffff, 0xa0000])
def mk_tool():
    d = bytearray(rbytes(TOOL))
    for k in range(5):                                  # gain tables: 11 x u16, mostly sorted-ish blc values
        base = 40 + 22 * k; vals = [edge16() if rnd.random() < 0.3 else rnd.randrange(0, 0x1000) for _ in range(11)]
        if rnd.random() < 0.3: vals = [vals[0]] * 11
        d[base:base + 22] = u16s(vals)
    th = sorted(rnd.randrange(0, 2000) for _ in range(4))
    if rnd.random() < 0.15: th[2] = th[1]
    if rnd.random() < 0.15: th[1] = th[0]
    d[150:158] = u16s(th)
    for off in (188, 254, 320, 386, 452, 518, 584, 650, 716, 782, 812, 842):   # matrix sets (the part the mix reads)
        pass
    for off in range(188, 872, 2):
        if rnd.random() < 0.5: d[off:off + 2] = u16s([edge16()])
    return bytes(d)
def mk_real():
    d = bytearray(rbytes(REAL))
    d[26] = rnd.choice([0, 1]); d[27] = rnd.randrange(0, 4)
    for k in range(5): d[4 + 2 * k:6 + 2 * k] = u16s([edge16()])
    d[30:32] = u16s([rnd.choice([rnd.randrange(4096, 8192), edge16(), 8192, 4096])])
    d[28:30] = u16s([edge16()])
    for k in range(4): d[32 + 4 * k:36 + 4 * k] = struct.pack("<I", rnd.choice([1024, r32() & 0xfffff, r32() & 0x3fffff, r32(), 0, 0x10000]))
    for off in range(14, 26, 2): d[off:off + 2] = u16s([rnd.choice([0, 1, edge16()])])
    return bytes(d)
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("tool0", TOOL), ("tool1", TOOL), ("real0", REAL), ("real1", REAL), ("bin0", 0xd610 + TOOL), ("bin1", 0xd610 + TOOL)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    return b
def wr(addr, data): [e.write(addr, data) for e in E]
def sym_w(e, sy, name, data): e.write(sy[name], data)
def prepare(b):
    """identical random state in both emulators (blocks, gain / IR state, bayer descriptor words, bin pointers)"""
    st = {}
    for e, sy in ((oem, OS), (our, US)):
        for nm, k in (("gib_main_tool_para", "tool0"), ("gib_seco_tool_para", "tool1"), ("gib_main_real_para", "real0"), ("gib_seco_real_para", "real1")):
            e.write(sy[nm], struct.pack("<I", b[k]))
        for i in range(2): e.write(sy["tparamsN"] + 4 * i, struct.pack("<I", b["bin%d" % i]))
    st["tool"] = [mk_tool(), mk_tool()]; st["real"] = [mk_real(), mk_real()]
    st["ag"] = struct.pack("<II", gain(), gain()); st["ir"] = struct.pack("<II", *[rnd.choice([r32(), rnd.getrandbits(12), 0, 1024, 800]) for _ in range(2)])
    st["mode"] = bytes(rnd.choice([0, 1, 1, 2, 3]) for _ in range(2))
    st["par"] = bytes(rnd.choice([0, 1, 4, 5, 8, 19, 20, 31, 0x37]) if (o % 152) == 8 else rnd.getrandbits(8) for o in range(480))
    st["bin"] = [bytes(0xd610) + mk_tool(), bytes(0xd610) + mk_tool()]
    for i in range(2):
        wr(b["tool%d" % i], st["tool"][i]); wr(b["real%d" % i], st["real"][i]); wr(b["bin%d" % i], st["bin"][i])
    for e, sy in ((oem, OS), (our, US)):
        e.write(sy["gib_AG"], st["ag"]); e.write(sy["gib_IR"], st["ir"]); e.write(sy["GIB_IR_MODE"], st["mode"]); e.write(sy["tisp_par_info"], st["par"])
    return st
def ir_arg(st, s):
    """IR level: often exactly on / next to one of the four thresholds of the tool block (tool +150..+156)"""
    th = struct.unpack_from("<4H", st["tool"][s], 150)
    if rnd.random() < 0.15: return struct.unpack_from("<I", st["ir"], 4 * s)[0]    # same level as the stored one
    return rnd.choice([rnd.getrandbits(11), r32() & 0xffff, rnd.getrandbits(12), rnd.choice(th), rnd.choice(th), (rnd.choice(th) + rnd.choice([-1, 1])) & 0xffff])
def dump(e, sy, b):
    return (e.read(b["tool0"], TOOL) + e.read(b["tool1"], TOOL) + e.read(b["real0"], REAL) + e.read(b["real1"], REAL), e.read(sy["gib_AG"], 8),
            e.read(sy["gib_IR"], 8), e.read(sy["GIB_IR_MODE"], 2))

stats = {}; bad = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def call(name, b, args, stack=()):
    rs = []
    for i, e in enumerate(E):
        log["oem" if i == 0 else "our"].clear()
        rs.append(e.call(FN[name], *args, stack_args=stack))
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return
    ctx = "args %s" % [hex(x) for x in args + tuple(stack)]
    if rs[0].v0 != rs[1].v0: rec(name, "return oem %#x our %#x %s" % (rs[0].v0, rs[1].v0, ctx)); return
    if log["oem"] != log["our"]:
        lo, lu = log["oem"], log["our"]; j = next((k for k in range(min(len(lo), len(lu))) if lo[k] != lu[k]), min(len(lo), len(lu)))
        rec(name, "register accesses differ at #%d (oem %d / our %d accesses): oem %s our %s %s" % (j, len(lo), len(lu), [tuple(map(hex, x[1:])) for x in lo[j:j + 3]], [tuple(map(hex, x[1:])) for x in lu[j:j + 3]], ctx)); return
    do, du = dump(oem, OS, b), dump(our, US, b)
    for k, lab in enumerate(("blocks", "gib_AG", "gib_IR", "ir_mode")):
        if do[k] != du[k]:
            i = next(j for j in range(len(do[k])) if do[k][j] != du[k][j])
            rec(name, "%s differ at +%d (oem %02x our %02x) %s" % (lab, i, do[k][i], du[k][i], ctx)); return

want = a.fn.split(",")
for it in range(a.n):
    b = setup()
    s = rnd.choice([0, 1])
    for name in want:
        st = prepare(b)
        if name == "tool_2_real": call(name, b, (s,))
        elif name == "interp_by_gain": call(name, b, (s, gain(), rnd.choice([0, 1])))
        elif name == "self_gain": call(name, b, (s,))
        elif name == "calc_digital_gain": call(name, b, (s,))
        elif name == "interp_by_ir": call(name, b, (s, r32(), ir_arg(st, s), r32()), (rnd.choice([0, 1]),))
        elif name == "write_reg": call(name, b, (s, rnd.choice([0, 1, 2, 3, 4, 5])))
        elif name == "a_gian_update": call(name, b, (s, gain()))
        elif name == "ir_update": call(name, b, (s, r32(), ir_arg(st, s), r32()))
        elif name == "dn_params_refresh": call(name, b, (s,))
for k in sorted(stats): print("%-18s %6d calls  %d mismatches" % (k, stats[k], bad.get(k, 0)))
sys.exit(1 if bad else 0)
