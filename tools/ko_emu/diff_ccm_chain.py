#!/usr/bin/env python3
"""diff_ccm_chain.py OEM.ko CCM_EMU.o [--n 1500] [--seed 5] [--fn NAME,...]

T40 CCM chain (issue #85): the OEM tisp_ccm_params_transmit / params_refresh / tisp_ct_ccm_interpolation / cm_control /
tisp_ccm_lut_parameter / tisp_ccm_ev_ct_update of the vendor tx-isp-t40.ko and the C versions (driver/t40/tx_isp_t40_ccm_chain.h, built
for mipsel by tests/t40_ccm/build_emu.sh into CCM_EMU.o) run in Unicorn on the same random state.  Compared: every byte of the pointer
table, the outer and inter blocks and the output buffers, and the order and values of the register writes.  Both emulators place the blocks
at the same guest addresses, so the pointer tables compare as plain words.  The one known intended difference is the manual-matrix copy of
tisp_ccm_params_refresh (T40-CCM-SET: 36 bytes instead of the OEM's 4); the OEM instruction `li a2,4` is patched to 36 in the OEM image.
--mutate is done by the caller (tests/t40_ccm_chain_host.sh edits a copy of the header).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=1500); ap.add_argument("--seed", type=int, default=5)
ap.add_argument("--fn", default="transmit,refresh,ct_interpolation,cm_control,lut_parameter,ev_ct_update")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
FN = {"transmit": ("tisp_ccm_params_transmit", "emu_transmit"), "refresh": ("tisp_ccm_params_refresh", "emu_refresh"),
      "ct_interpolation": ("tisp_ct_ccm_interpolation", "emu_ct_interpolation"), "cm_control": ("cm_control", "emu_cm_control"),
      "lut_parameter": ("tisp_ccm_lut_parameter", "emu_lut_parameter"), "ev_ct_update": ("tisp_ccm_ev_ct_update", "emu_ev_ct_update")}

log = {"oem": [], "our": []}
def mk_hle(tag):
    L = log[tag]
    return {"system_reg_write": lambda e: (L.append((e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1],
            "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0}
oem = KoEmu(a.oem, hle=mk_hle("oem"), max_insns=2_000_000); our = KoEmu(a.our, hle=mk_hle("our"), max_insns=2_000_000)
E = (oem, our)
# the OEM defines system_reg_write itself: hook its entry (the callback does what the HLE does for an undefined symbol)
ad = oem.symaddr["system_reg_write"]
def _hook(uc, addr, size, ud):
    mk = log["oem"].append((oem.get_reg(UC_MIPS_REG_A0), oem.get_reg(UC_MIPS_REG_A1)))
    oem.set_reg(UC_MIPS_REG_V0, 0); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
oem.uc.hook_add(UC_HOOK_CODE, _hook, None, ad, ad)
# T40-CCM-SET: the OEM refresh copies 4 bytes of the manual matrix per CT matrix (`li a2,4`), ours 36: patch those immediates
rf = oem.symaddr["tisp_ccm_params_refresh"]; code = oem.read(rf, 0x208); npatch = 0
for off in range(0, len(code) - 3, 4):
    if struct.unpack("<I", code[off:off + 4])[0] == 0x24060004:        # addiu a2,zero,4
        oem.write(rf + off, struct.pack("<I", 0x24060024)); npatch += 1
assert npatch == 6, "expected 6 `li a2,4` in the OEM refresh, found %d" % npatch

def r32(): return rnd.getrandbits(32)
def rbytes(n): return bytes(rnd.getrandbits(8) for _ in range(n))
def edge32():
    return rnd.choice([0, 1, 0xffffffff, 0x80000000, 0x7fffffff, 256, 0xffffff00, r32(), rnd.getrandbits(14), rnd.getrandbits(16), (-rnd.getrandbits(14)) & M32, rnd.getrandbits(8)])
def wr(addr, data): [e.write(addr, data) for e in E]
CTX, OUTER, INTER = 128, 0x200, 0x100
def setup(sec_sets=None):
    """identical blocks in both emulators; ctx filled by the OEM transmit (its own test is the `transmit` function)"""
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("ctx", CTX), ("outer", OUTER), ("inter", INTER), ("src", OUTER), ("m_in", 36), ("m_out", 36), ("m_reg", 36), ("tmp", 64)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    return b
def fill_inter(b, outer=None):
    """inter block: random with plausible values in the fields the chain reads; ct now is often exactly on / next to a zone boundary"""
    d = bytearray(rbytes(INTER))
    d[0] = rnd.choice([0, 0, 1, 2]); d[0xd8] = rnd.choice([0, 1]); d[0xb0] = rnd.choice([0, 1, 1, 2]); d[0xb1] = rnd.choice([0, 1])
    struct.pack_into("<I", d, 4, rnd.choice([r32() & 0xfffff, 100, 400, 1000]))                  # ev now
    struct.pack_into("<I", d, 8, rnd.choice([r32() & 0xfffff, 100, 400, 1000]))                  # ev last
    struct.pack_into("<I", d, 0xc, rnd.choice([0, 1, 50, 500, r32() & 0xffff]))                  # ev threshold
    ct = rnd.choice([rnd.randrange(1500, 15000), 2800, 4500, 6500, rnd.getrandbits(16)])
    hyst = rnd.choice([0, 1, 100, 300, rnd.getrandbits(16), rnd.randrange(0, 600)])
    if outer is not None and rnd.random() < 0.6:       # on or next to a boundary: anchor +- hysteresis (+-1)
        an = struct.unpack_from("<3H", outer, 0xe4)
        ct = (rnd.choice([an[0] + hyst, an[1] + hyst, an[1] - hyst, an[2] - hyst]) + rnd.choice([-1, 0, 0, 1])) & 0xffff
    struct.pack_into("<H", d, 0x10, ct)                                                           # ct now
    struct.pack_into("<H", d, 0x12, rnd.choice([ct, rnd.randrange(1500, 15000), rnd.getrandbits(16)]))   # ct last
    struct.pack_into("<H", d, 0x14, hyst)                                                         # ct threshold / hysteresis
    struct.pack_into("<H", d, 0x16, rnd.getrandbits(3)); struct.pack_into("<H", d, 0x18, rnd.getrandbits(3))   # zone, last zone
    return bytes(d)
def fill_outer():
    d = bytearray(rbytes(OUTER))
    anc = sorted([rnd.randrange(1500, 15000) for _ in range(3)], reverse=rnd.random() < 0.8)
    if rnd.random() < 0.15: anc[1] = anc[0]
    if rnd.random() < 0.15: anc[2] = anc[1]
    struct.pack_into("<3H", d, 0xe4, *anc)
    if rnd.random() < 0.5:      # outer u16 triple read by lut_parameter: often a small difference (32 / |b - a|)
        b0 = rnd.getrandbits(16); struct.pack_into("<3H", d, 0, rnd.getrandbits(4), b0, (b0 + rnd.choice([-40, -33, -32, -17, -1, 0, 1, 2, 5, 16, 31, 33, 40])) & 0xffff)
    # ev table (outer+0xec, 9 words, ascending mostly) and saturation per ev (outer+0x110)
    ev = sorted(rnd.randrange(0, 0x40000) for _ in range(9))
    if rnd.random() < 0.3: ev[rnd.randrange(1, 9)] = ev[rnd.randrange(0, 8)]
    for k in range(9):
        struct.pack_into("<I", d, 0xec + 4 * k, ev[k]); struct.pack_into("<I", d, 0x110 + 4 * k, rnd.choice([rnd.randrange(0, 512), r32() & 0x1ff, 256]))
        struct.pack_into("<I", d, 0x158 + 4 * k, ev[k]); struct.pack_into("<I", d, 0x17c + 4 * k, rnd.randrange(0, 512))
    # CT matrices (register-ish small signed values)
    for off in (0xc, 0x30, 0x54, 0x78, 0x9c, 0xc0, 0x134, 0x1a0):
        for k in range(9): struct.pack_into("<I", d, off + 4 * k, rnd.choice([rnd.randrange(0, 0x600), (-rnd.randrange(0, 0x300)) & M32, edge32()]))
    return bytes(d)
def snapshot(b):
    return {k: [e.read(b[k], n) for e in E] for k, n in (("ctx", CTX), ("outer", OUTER), ("inter", INTER), ("m_out", 36), ("m_reg", 36), ("src", OUTER))}

stats = {}; bad = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def call(name, args):
    rs = []
    for i, e in enumerate(E):
        log["oem" if i == 0 else "our"].clear()
        rs.append(e.call(FN[name][i], *args))
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return None
    if log["oem"] != log["our"]:
        rec(name, "register writes differ: oem %s our %s" % ([(hex(x), hex(y)) for x, y in log["oem"][:8]], [(hex(x), hex(y)) for x, y in log["our"][:8]])); return None
    return rs
def cmp_mem(name, b, keys, extra=""):
    s = snapshot(b)
    for k in keys:
        if s[k][0] != s[k][1]:
            o, c = s[k]; i = next(j for j in range(len(o)) if o[j] != c[j])
            rec(name, "%s differs at +%#x (oem %02x our %02x) %s" % (k, i, o[i], c[i], extra)); return False
    return True
def ctx_from_oem(b, inter, outer):
    """ctx = what the OEM tisp_ccm_params_transmit makes of (outer, inter)"""
    wr(b["inter"], inter); wr(b["outer"], outer)
    r = oem.call("tisp_ccm_params_transmit", b["ctx"], b["outer"], b["inter"]); assert not r.stop
    wr(b["ctx"], oem.read(b["ctx"], CTX))

want = a.fn.split(",")
for it in range(a.n):
    b = setup(); outer = fill_outer(); inter = fill_inter(b, outer)
    if "transmit" in want:
        wr(b["inter"], inter); wr(b["outer"], outer); wr(b["ctx"], rbytes(CTX))
        if call("transmit", (b["ctx"], b["outer"], b["inter"])): cmp_mem("transmit", b, ("ctx", "outer", "inter"))
    if "refresh" in want:
        src = fill_outer(); wr(b["src"], src)
        ctx_from_oem(b, inter, outer)
        # manual path reads the manual matrix from inter+0xb4 through ctx[18]
        if call("refresh", (b["ctx"], b["outer"], b["src"])): cmp_mem("refresh", b, ("ctx", "outer", "inter", "src"), "manual=%d" % inter[0xb0])
    if "ct_interpolation" in want:
        ctx_from_oem(b, inter, outer)
        # reference matrices live in the inter block (ctx[12..14]), result goes to ctx[15]
        if call("ct_interpolation", (b["ctx"],)): cmp_mem("ct_interpolation", b, ("ctx", "outer", "inter"), "mode=%d zone/last=%d/%d ct=%d" % (inter[0], inter[0x16], inter[0x18], struct.unpack_from("<H", inter, 0x10)[0]))
    if "cm_control" in want:
        m = b"".join(struct.pack("<I", edge32()) for _ in range(9)); wr(b["m_in"], m); wr(b["m_out"], b"\xaa" * 36)
        sat = rnd.choice([0, 1, 256, 128, 511, r32() & 0x3ff, r32() & 0xffff, r32()])
        if call("cm_control", (b["m_in"], sat, b["m_out"])): cmp_mem("cm_control", b, ("m_out",), "sat=%#x" % sat)
    if "lut_parameter" in want:
        ctx_from_oem(b, inter, outer)
        wr(b["m_reg"], b"".join(struct.pack("<I", r32() if rnd.random() < 0.5 else rnd.getrandbits(14)) for _ in range(9)))
        sec = rnd.choice([0, 1])
        if call("lut_parameter", (b["ctx"], b["m_reg"], sec)): cmp_mem("lut_parameter", b, ("ctx", "outer", "inter", "m_reg"))
    if "ev_ct_update" in want:
        ctx_from_oem(b, inter, outer)
        sec = rnd.choice([0, 1])
        if call("ev_ct_update", (b["ctx"], sec)): cmp_mem("ev_ct_update", b, ("ctx", "outer", "inter", "m_out"), "mode=%d" % inter[0])
for k in sorted(stats): print("%-17s %6d calls  %d mismatches" % (k, stats[k], bad.get(k, 0)))
sys.exit(1 if bad else 0)
