#!/usr/bin/env python3
"""diff_lsc.py OEM.ko LSC_EMU.o [--n 400] [--seed 11] [--fn NAME,...]

T40 LSC chain (issue #85): the OEM tisp_lsc_lut_valid_judge / tisp_lsc_interp_by_ct / tisp_lsc_interp_by_gain / tisp_lsc_write_reg /
tisp_lsc_real_write_lut of the vendor tx-isp-t40.ko and the hand-written C of driver/t40/tx_isp_t40_lsc_lit.inc (cut out and built for mipsel
by tests/t40_lsc/build_emu.sh into LSC_EMU.o) run in Unicorn on the same random tuning state.  The OEM works on a pointer record
("awdr para": mode, count, pointers to the cell size / mesh X / mesh Y / gain tables / CT breakpoints / three LUTs) that tisp_lsc_tool_to_awdr
fills from the 0xa324-byte tool block; here that record is built from the same tool block in the way the OEM does (linear or WDR tables).
Compared: return value, the tool and real blocks, last gain / last CT / zone, and the order and values of the register writes.
--mutate is done by the caller (tests/t40_lsc_host.sh edits a copy of the driver source).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=400); ap.add_argument("--seed", type=int, default=11)
ap.add_argument("--fn", default="valid_judge,interp_by_ct,interp_by_gain,write_reg,real_write_lut")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
TOOL, REAL = 0xa324, 27656
log = {"oem": [], "our": []}
def mk_hle(tag):
    L = log[tag]
    return {"system_reg_write": lambda e: (L.append((e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1],
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0,
            "__private_spin_lock_irqsave": lambda e: 0, "private_spin_unlock_irqrestore": lambda e: 0,
            "_raw_spin_lock_irqsave": lambda e: 0, "_raw_spin_unlock_irqrestore": lambda e: 0}
oem = KoEmu(a.oem, hle=mk_hle("oem"), max_insns=4_000_000); our = KoEmu(a.our, hle=mk_hle("our"), max_insns=4_000_000)
E = (oem, our)
ad = oem.symaddr["system_reg_write"]
def _hook(uc, addr, size, ud):
    log["oem"].append((oem.get_reg(UC_MIPS_REG_A0), oem.get_reg(UC_MIPS_REG_A1)))
    oem.set_reg(UC_MIPS_REG_V0, 0); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
oem.uc.hook_add(UC_HOOK_CODE, _hook, None, ad, ad)
OS = {k: oem.symaddr[k] for k in ("lsc_main_real_para", "lsc_seco_real_para", "lsc_main_awdr_para", "lsc_seco_awdr_para", "lsc_gain", "lsc_ct", "lsc_ct_flag")}
BANKS = our.symaddr["lsc_lit_banks"]

def r32(): return rnd.getrandbits(32)
def u16(v): return struct.pack("<H", v & 0xffff)
def mk_tool(wide=False):
    d = bytearray(rnd.getrandbits(8) for _ in range(TOOL))
    mode = rnd.choice([0, 1, 2, 3, r32() & 0xffff]); count = rnd.choice([rnd.randrange(1, 40), rnd.getrandbits(10), 0])
    d[0:2] = u16(mode); d[2:4] = u16(count)
    d[4:6] = u16(rnd.choice([16, 20, 24, 28, 32, 36, 40, 48, 64, 80, rnd.getrandbits(8)])); d[6:8] = u16(rnd.choice([16, 20, 24, 28, 32, 36, 40, 48, 64, 80, rnd.getrandbits(8)]))
    for off in (8, 16):                                  # mesh {flag, start, end, step}
        st = rnd.randrange(0, 40); en = st + rnd.choice([0, 1, 2, 3, 8, 20, 31, 64, 200]) if rnd.random() < 0.9 else rnd.getrandbits(16)
        d[off:off + 8] = u16(rnd.choice([0, 1, 0xffff])) + u16(st) + u16(en & 0xffff) + u16(rnd.getrandbits(16))
    for off in (24, 46, 72, 94):                         # gain tables (11 x u16)
        vals = [rnd.choice([rnd.randrange(0, 0x400), rnd.getrandbits(16)]) for _ in range(11)]
        if rnd.random() < 0.2: vals = [vals[0]] * 11
        d[off:off + 22] = b"".join(u16(v) for v in vals)
    words = rnd.choice([3 * rnd.randrange(1, 1153), 3 * rnd.randrange(1, 60), 3 * 1152, 0, 3 * rnd.randrange(1, 1153) + 1])
    d[120:122] = u16(words)
    bp = sorted(rnd.choice([rnd.randrange(1500, 9000), rnd.getrandbits(16)]) for _ in range(4))
    if rnd.random() < 0.2: bp[1] = bp[0]
    if rnd.random() < 0.2: bp[3] = bp[2]
    if rnd.random() < 0.1: bp = bp[::-1]
    d[122:130] = b"".join(u16(v) for v in bp)
    return bytes(d)
def mk_real():
    d = bytearray(rnd.getrandbits(8) for _ in range(REAL))
    d[13828:13830] = u16(rnd.choice([rnd.randrange(0, 1153), 1, 0, 1152, rnd.getrandbits(10)]))
    return bytes(d)
def fill_words(buf, nwords_max=3456):
    return buf
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("tool0", TOOL), ("tool1", TOOL), ("real0", REAL), ("real1", REAL), ("awdr0", 64), ("awdr1", 64)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    return b
def wr(addr, data): [e.write(addr, data) for e in E]
def prepare(b):
    st = {"wdr": [rnd.choice([0, 1]), rnd.choice([0, 1])], "tool": [mk_tool(), mk_tool()], "real": [mk_real(), mk_real()]}
    st["gain"] = [rnd.choice([r32(), rnd.getrandbits(18), 0]), rnd.choice([r32(), rnd.getrandbits(18)])]
    st["ct"] = [rnd.choice([rnd.getrandbits(16), rnd.randrange(1500, 9000)]), rnd.choice([rnd.getrandbits(16), rnd.randrange(1500, 9000)])]
    st["zone"] = [rnd.randrange(0, 5), rnd.randrange(0, 5)]
    for i in range(2):
        T = b["tool%d" % i]; w = st["wdr"][i]; tl = st["tool"][i]
        wr(T, tl); wr(b["real%d" % i], st["real"][i])
        words = struct.unpack_from("<H", tl, 120)[0]
        # OEM awdr record (tisp_lsc_tool_to_awdr): mode, count, pointers into the tool block
        aw = struct.pack("<HH", *struct.unpack_from("<HH", tl, 0)) + struct.pack("<IIIII", T + 4, T + 8, T + 16, T + (72 if w else 24), T + (94 if w else 46)) \
            + struct.pack("<I", T + (116 if w else 68)) + struct.pack("<H", words) + b"\0\0" + struct.pack("<IIII", T + 122, T + 292, T + 14116, T + 27940)
        wr(b["awdr%d" % i], aw)
    for e, kind in ((oem, "oem"), (our, "our")):
        if kind == "oem":
            for nm, k in (("lsc_main_real_para", "real0"), ("lsc_seco_real_para", "real1"), ("lsc_main_awdr_para", "awdr0"), ("lsc_seco_awdr_para", "awdr1")):
                e.write(OS[nm], struct.pack("<I", b[k]))
            e.write(OS["lsc_gain"], struct.pack("<II", *st["gain"])); e.write(OS["lsc_ct"], u16(st["ct"][0]) + u16(st["ct"][1]))
            e.write(OS["lsc_ct_flag"], bytes(st["zone"]))
        else:
            for i in range(2):
                e.write(BANKS + 24 * i, struct.pack("<II", b["tool%d" % i], b["real%d" % i]))
                e.write(BANKS + 24 * i + 12, struct.pack("<IHBB", st["gain"][i], st["ct"][i], st["zone"][i], st["wdr"][i]))
    return st
def dump(e, kind, b):
    blocks = e.read(b["tool0"], TOOL) + e.read(b["tool1"], TOOL) + e.read(b["real0"], REAL) + e.read(b["real1"], REAL)
    if kind == "oem": gz = (e.read(OS["lsc_gain"], 8), e.read(OS["lsc_ct"], 2) [:2] + e.read(OS["lsc_ct"] + 2, 2), e.read(OS["lsc_ct_flag"], 2))
    else:
        g = [e.read(BANKS + 24 * i + 12, 8) for i in range(2)]
        gz = (g[0][:4] + g[1][:4], g[0][4:6] + g[1][4:6], bytes([g[0][6], g[1][6]]))
    return blocks, gz

stats = {}; bad = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
FN = {"valid_judge": ("tisp_lsc_lut_valid_judge", "emu_valid"), "interp_by_ct": ("tisp_lsc_interp_by_ct", "emu_by_ct"),
      "interp_by_gain": ("tisp_lsc_interp_by_gain", "emu_by_gain"), "write_reg": ("tisp_lsc_write_reg", "emu_write_reg"),
      "real_write_lut": ("tisp_lsc_real_write_lut", "emu_write_lut")}
def call(name, b, oargs, uargs, ostack=(), cmp_state=True, ctx="", ustack=()):
    rs = []
    for i, e in enumerate(E):
        log["oem" if i == 0 else "our"].clear()
        rs.append(e.call(FN[name][i], *(oargs if i == 0 else uargs), stack_args=ostack if i == 0 else ustack))
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s %s" % ("oem" if i == 0 else "our", r.stop, ctx)); return False
    if name != "write_reg" and name != "real_write_lut" and (rs[0].v0 & M32) != (rs[1].v0 & M32): rec(name, "return oem %#x our %#x %s" % (rs[0].v0, rs[1].v0, ctx)); return False
    if log["oem"] != log["our"]:
        lo, lu = log["oem"], log["our"]; j = next((k for k in range(min(len(lo), len(lu))) if lo[k] != lu[k]), min(len(lo), len(lu)))
        rec(name, "register writes differ at #%d (oem %d / our %d): oem %s our %s %s" % (j, len(lo), len(lu), [tuple(map(hex, x)) for x in lo[j:j + 3]], [tuple(map(hex, x)) for x in lu[j:j + 3]], ctx)); return False
    if cmp_state:
        do, du = dump(oem, "oem", b), dump(our, "our", b)
        if do[0] != du[0]:
            i = next(j for j in range(len(do[0])) if do[0][j] != du[0][j])
            blk = ("tool0", "tool1", "real0", "real1")[0 if i < TOOL else 1 if i < 2 * TOOL else 2 if i < 2 * TOOL + REAL else 3]
            off = i - {"tool0": 0, "tool1": TOOL, "real0": 2 * TOOL, "real1": 2 * TOOL + REAL}[blk]
            rec(name, "%s differs at +%d (oem %02x our %02x) %s" % (blk, off, do[0][i], du[0][i], ctx)); return False
        for k, lab in ((0, "last gain"), (1, "last ct"), (2, "zone")):
            if do[1][k] != du[1][k]: rec(name, "%s oem %s our %s %s" % (lab, do[1][k].hex(), du[1][k].hex(), ctx)); return False
    return True

want = a.fn.split(",")
CELLS = [16, 20, 24, 28, 32, 36, 40, 48, 64, 80]
for it in range(a.n):
    b = setup()
    bank = rnd.choice([0, 1])
    if "valid_judge" in want:
        h, w = rnd.choice([2160, 1080, 720, rnd.randrange(1, 4200)]), rnd.choice([3840, 1920, 1280, rnd.randrange(1, 4200)])
        ch, cw = rnd.choice([rnd.choice(CELLS), rnd.choice(CELLS), rnd.getrandbits(8), 0, 81]), rnd.choice([rnd.choice(CELLS), rnd.choice(CELLS), rnd.getrandbits(8), 0, 81])
        if rnd.random() < 0.6 and ch and cw:       # count that fits the geometry, or off by one
            cols = (w // cw) + (2 if w % cw else 1); cols += cols & 1
            cnt = (cols // 2 + rnd.choice([0, 0, 0, 1, -1])) & 0xffff
            if rnd.random() < 0.5 and cnt:         # rows * count right at the limit of 1152 nodes
                R = rnd.choice([1152 // cnt, 1152 // cnt + 1, 1153 // cnt, 1153 // cnt + 1, 1151 // cnt]) or 1
                h = (R - 1) * ch if rnd.random() < 0.5 else max(1, (R - 2) * ch + rnd.randrange(1, max(2, ch)))
        else: cnt = rnd.choice([rnd.getrandbits(8), rnd.getrandbits(16), 0])
        if rnd.random() < 0.3:                      # exact node limit: rows * count = 1152 (valid) or one row more (too large)
            ch, cw = rnd.choice(CELLS), rnd.choice(CELLS); cnt = rnd.choice([24, 32, 36, 48, 64, 72]); R = 1152 // cnt
            w = cw * (2 * cnt - 1); h = rnd.choice([(R - 1) * ch, (R - 1) * ch + rnd.randrange(1, max(2, ch)), (R - 2) * ch + rnd.randrange(1, max(2, ch))])
        prepare(b)
        call("valid_judge", b, (h, w, ch, cw), (h, w, ch, cw), ostack=(cnt,), ustack=(cnt,), cmp_state=False, ctx="h=%d w=%d cell %dx%d count=%d" % (h, w, cw, ch, cnt))
    if "interp_by_ct" in want:
        st = prepare(b)
        seq = [(rnd.choice([rnd.randrange(1500, 9000), rnd.getrandbits(16)]), 1)] + [(rnd.choice([rnd.randrange(1500, 9000), rnd.getrandbits(16)]), rnd.choice([0, 0, 1])) for _ in range(rnd.randrange(1, 4))]
        bp = struct.unpack_from("<4H", st["tool"][bank], 122)
        prev = st["ct"][bank]
        for ct, force in seq:
            if rnd.random() < 0.25: ct = (prev + rnd.choice([63, 64, 65, -63, -64, -65])) & 0xffff
            elif rnd.random() < 0.5: ct = (rnd.choice(bp) + rnd.choice([-1, 0, 0, 0, 1])) & 0xffff             # on / next to a breakpoint
            elif rnd.random() < 0.4: ct = (rnd.choice(bp) + rnd.choice([-65, -64, -63, 63, 64, 65])) & 0xffff
            if not call("interp_by_ct", b, (bank, 0, ct, 0), (bank, ct, force), ostack=(force,), ctx="bank=%d ct=%d force=%d bp=%s zone/ct before" % (bank, ct, force, bp)): break
            prev = ct
    if "interp_by_gain" in want:
        st = prepare(b)
        pg = st["gain"][bank]
        for _ in range(2):
            g = rnd.choice([r32(), rnd.getrandbits(20), (rnd.randrange(0, 12) << 16) | rnd.getrandbits(16), (pg + rnd.choice([255, 256, 257, -255, -256, -257, 1, -1])) & M32]); force = rnd.choice([0, 1])
            pg = g
            if not call("interp_by_gain", b, (bank, 0, g, 0), (bank, g, force), ostack=(force,), ctx="bank=%d gain=%#x force=%d" % (bank, g, force)): break
    if "write_reg" in want:
        prepare(b); call("write_reg", b, (bank,), (bank,), ctx="bank=%d" % bank)
    if "real_write_lut" in want:
        prepare(b); call("real_write_lut", b, (bank,), (bank,), cmp_state=False, ctx="bank=%d" % bank)
for k in sorted(stats): print("%-16s %6d calls  %d mismatches" % (k, stats[k], bad.get(k, 0)))
sys.exit(1 if bad else 0)
