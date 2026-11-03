#!/usr/bin/env python3
"""diff_ct_chain.py OEM.ko CT_EMU.o [--n 2000] [--seed 7] [--fn NAME,...]

T40 colour-temperature / EV event consumers (issue #85): the OEM tisp_ct_update, tisp_ccm_main_ct_update,
tisp_ccm_main_ev_update, tisp_lsc_ct_update and tisp_clm_ct_update of the vendor tx-isp-t40.ko and the C versions
(driver/t40/tx_isp_t40_ct_chain.h, built for mipsel by tests/t40_ct/build_emu.sh into CT_EMU.o) run in Unicorn on the
same random state.  Compared: return value, every byte of the CCM pointer table / outer / inter blocks, the frame
numbers saved per bank, the LUT write counters, the register writes, and the calls into the consumers with their
arguments (the OEM functions behind the hooks are skipped on both sides; the CCM ev_ct_update underneath the
CCM main updates runs for real on both sides: tools/ko_emu/diff_ccm_chain.py checks it).  Nothing of the vendor
module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import (UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3, UC_MIPS_REG_V0,
                                UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_SP)

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=2000); ap.add_argument("--seed", type=int, default=7)
ap.add_argument("--fn", default="ct_update,ccm_main_ct,ccm_main_ev,lsc_ct,clm_ct")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff

log = {"oem": [], "our": []}
ret = {}          # name -> return value of a skipped consumer (same for both sides)
top = [0]
def r32(): return rnd.getrandbits(32)
def rbytes(n): return bytes(rnd.getrandbits(8) for _ in range(n))
def stack(e, k): return struct.unpack("<I", e.read(e.get_reg(UC_MIPS_REG_SP) + 16 + 4 * k, 4))[0]

# what each consumer is recorded with (registers that carry an argument the OEM really passes)
REC = {
    "tisp_ccm_main_ct_update": lambda e: (e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1)),
    "tisp_bcsh_main_ct_update": lambda e: (e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1)),
    "tisp_lsc_ct_update": lambda e: (e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A2), e.get_reg(UC_MIPS_REG_A3), stack(e, 0), stack(e, 1)),
    "tisp_clm_ct_update": lambda e: (e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A2), e.get_reg(UC_MIPS_REG_A3), stack(e, 0), stack(e, 1)),
    "tisp_lsc_interp_by_ct": lambda e: (e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A2) & 0xffff, e.get_reg(UC_MIPS_REG_A3), stack(e, 0) & 0xff),
    "tisp_clm_ct_interp": lambda e: (e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1), e.get_reg(UC_MIPS_REG_A2)),
    "tisp_lsc_prepare_write_lut": lambda e: (e.get_reg(UC_MIPS_REG_A0),),
    "tisp_clm_prepare_write_lut": lambda e: (e.get_reg(UC_MIPS_REG_A0),),
}
def mk_hle(tag):
    L = log[tag]
    h = {"system_reg_write": lambda e: (L.append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))), 0)[1],
         "system_reg_read": lambda e: (L.append(("r", e.get_reg(UC_MIPS_REG_A0))), top[0] if e.get_reg(UC_MIPS_REG_A0) == 0x40 else 0)[1],
         "printk": lambda e: 0, "_printk": lambda e: 0, "isp_printf": lambda e: 0}
    for n, f in REC.items():
        h[n] = (lambda n, f: lambda e: (L.append((n,) + f(e)), ret.get(n, 0))[1])(n, f)
    return h
oem = KoEmu(a.oem, hle=mk_hle("oem"), max_insns=2_000_000); our = KoEmu(a.our, hle=mk_hle("our"), max_insns=2_000_000)
E = (oem, our)
# the OEM defines the consumers itself: hook their entries (record, return like the HLE does for an undefined symbol)
live = set()      # OEM functions under test right now: their entry hook stays passive
def skip_hook(name):
    ad = oem.symaddr[name]; f = oem.hle[name]
    def _hook(uc, addr, size, ud):
        if name in live: return
        v = f(oem); oem.set_reg(UC_MIPS_REG_V0, v & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
    oem.uc.hook_add(UC_HOOK_CODE, _hook, None, ad, ad)
for n in ("system_reg_write", "system_reg_read", "tisp_ccm_main_ct_update", "tisp_bcsh_main_ct_update", "tisp_lsc_ct_update",
          "tisp_clm_ct_update", "tisp_lsc_interp_by_ct", "tisp_clm_ct_interp"):
    skip_hook(n)
# prepare_write_lut runs for real in the OEM (write_times[bank]++, v1 untouched: the OEM caller relies on it); record its entry
for n in ("tisp_lsc_prepare_write_lut", "tisp_clm_prepare_write_lut"):
    ad = oem.symaddr[n]
    oem.uc.hook_add(UC_HOOK_CODE, (lambda n: lambda uc, addr, size, ud: log["oem"].append((n,) + REC[n](oem)))(n), None, ad, ad)
OEM_G = {k: oem.symaddr[k] for k in ("fnum", "pstMainCcmOri", "lsc_frm_num_saved", "lsc_wlut_frequency", "lsc_lut_write_times",
                                      "clm_frame_num_saved", "clm_wlut_frequency", "clm_wlut_times")}

def wr(addr, data): [e.write(addr, data) for e in E]
CTX, OUTER, INTER = 128, 0x200, 0x100
def setup():
    for e in E: e.heap_reset()
    b = {}
    for k, n in (("ctx", CTX), ("outer", OUTER), ("inter", INTER), ("lsc_saved", 16), ("lsc_freq", 4), ("lsc_wt", 4), ("clm_saved", 16), ("clm_freq", 4), ("clm_wt", 4)):
        ads = [e.alloc(n, bytes(n)) for e in E]; assert ads[0] == ads[1]; b[k] = ads[0]
    for k in ("lsc_saved", "clm_saved", "lsc_freq", "clm_freq"):
        our.write(our.symaddr["emu_" + k], struct.pack("<I", b[k]))
    return b
def fill_inter():
    d = bytearray(rbytes(INTER))
    d[0] = rnd.choice([0, 0, 1, 2]); d[0xd8] = rnd.choice([0, 1]); d[0xb0] = rnd.choice([0, 1, 1, 2]); d[0xb1] = rnd.choice([0, 1])
    for off in (4, 8):
        struct.pack_into("<I", d, off, rnd.choice([r32(), r32() & 0xfffff, 100, 400, 1000, 0, M32]))
    struct.pack_into("<I", d, 0xc, rnd.choice([0, 1, 50, 500, r32() & 0xffff, M32, r32()]))
    for off in (0x10, 0x12):
        struct.pack_into("<H", d, off, rnd.choice([rnd.randrange(1500, 15000), 0, 0xffff, rnd.getrandbits(16)]))
    struct.pack_into("<H", d, 0x14, rnd.choice([0, 1, 100, 300, 0xffff, rnd.getrandbits(16)]))
    return bytes(d)
def fill_outer():
    d = bytearray(rbytes(OUTER))
    struct.pack_into("<3H", d, 0xe4, *sorted([rnd.randrange(1500, 15000) for _ in range(3)], reverse=True))
    ev = sorted(rnd.randrange(0, 0x40000) for _ in range(9))
    for k in range(9):
        struct.pack_into("<I", d, 0xec + 4 * k, ev[k]); struct.pack_into("<I", d, 0x110 + 4 * k, rnd.randrange(0, 512))
    return bytes(d)
def ctx_from_oem(b):
    wr(b["inter"], fill_inter()); wr(b["outer"], fill_outer())
    r = oem.call("tisp_ccm_params_transmit", b["ctx"], b["outer"], b["inter"]); assert not r.stop, r.stop
    wr(b["ctx"], oem.read(b["ctx"], CTX))
def u64pair(): return rnd.choice([r32(), 0, 1, 5, 6, M32, rnd.getrandbits(8)]), rnd.choice([0, 0, 0, 1, M32, r32()])
def rand_ct(): return rnd.choice([rnd.randrange(1500, 15000), 0, 1, 0xffff, 0x10000, 0x12345, M32, r32()])

stats = {}; bad = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)
def call(name, oem_fn, our_fn, args, stack_args=()):
    rs = []
    for i, (e, fn) in enumerate(((oem, oem_fn), (our, our_fn))):
        log["oem" if i == 0 else "our"].clear()
        rs.append(e.call(fn, *args, stack_args=stack_args))
    stats[name] = stats.get(name, 0) + 1
    for i, r in enumerate(rs):
        if r.stop: rec(name, "emulation stopped (%s): %s" % ("oem" if i == 0 else "our", r.stop)); return None
    if log["oem"] != log["our"]:
        rec(name, "calls/register writes differ: oem %s our %s" % (log["oem"][:6], log["our"][:6])); return None
    if rs[0].v0 != rs[1].v0:
        rec(name, "return oem %#x our %#x" % (rs[0].v0, rs[1].v0)); return None
    return rs
def same(name, pairs, extra=""):
    for k, ao, ac, n in pairs:
        o, c = oem.read(ao, n), our.read(ac, n)
        if o != c:
            i = next(j for j in range(n) if o[j] != c[j])
            rec(name, "%s differs at +%#x (oem %02x our %02x) %s" % (k, i, o[i], c[i], extra)); return False
    return True

want = a.fn.split(",")
for it in range(a.n):
    b = setup()
    live.clear()
    if "ct_update" in want:
        top[0] = rnd.choice([r32(), 0, M32, 0xffd00005, 0xffd90005, 0xffd90007, 0xffff48e0, 0x7fd0000d]) ^ (rnd.getrandbits(1) << rnd.choice([1, 9, 15, 16]))
        f = u64pair(); oem.write(OEM_G["fnum"], struct.pack("<II", *f) + rbytes(8))
        for k in ("tisp_ccm_main_ct_update", "tisp_bcsh_main_ct_update", "tisp_lsc_ct_update", "tisp_clm_ct_update"): ret[k] = r32()
        call("ct_update", "tisp_ct_update", "emu_ct_update", (rand_ct(), r32(), f[0], f[1]))
    # CCM main updates: the OEM uses its global pointer table pstMainCcmOri, ours takes the table as first argument
    live.clear(); live.update(("tisp_ccm_main_ct_update",))
    if "ccm_main_ct" in want:
        ctx_from_oem(b); oem.write(OEM_G["pstMainCcmOri"], oem.read(b["ctx"], 104))
        ct = rand_ct()
        rs = []
        for i, e in enumerate(E):
            log["oem" if i == 0 else "our"].clear()
            rs.append(e.call("tisp_ccm_main_ct_update", ct) if i == 0 else e.call("emu_ccm_main_ct", b["ctx"], ct))
        stats["ccm_main_ct"] = stats.get("ccm_main_ct", 0) + 1
        if any(r.stop for r in rs): rec("ccm_main_ct", "stopped %s" % [r.stop for r in rs])
        elif log["oem"] != log["our"]: rec("ccm_main_ct", "register writes differ")
        elif rs[0].v0 != rs[1].v0: rec("ccm_main_ct", "return differs")
        else: same("ccm_main_ct", [(k, b[k], b[k], n) for k, n in (("ctx", CTX), ("outer", OUTER), ("inter", INTER))], "ct=%#x" % ct)
    if "ccm_main_ev" in want:
        ctx_from_oem(b); oem.write(OEM_G["pstMainCcmOri"], oem.read(b["ctx"], 104))
        lo, hi = r32(), rnd.choice([0, 0, 1, r32(), M32])
        if rnd.random() < 0.3:      # around the stored EV and the threshold
            last = struct.unpack("<I", oem.read(struct.unpack("<I", oem.read(b["ctx"] + 16, 4))[0], 4))[0]
            thr = struct.unpack("<I", oem.read(struct.unpack("<I", oem.read(b["ctx"] + 20, 4))[0], 4))[0]
            lo, hi = (((last + rnd.choice([thr, thr + 1, -thr, -thr - 1, 0])) & 0x3fffff) << 10) | rnd.getrandbits(10), 0
        rs = []
        for i, e in enumerate(E):
            log["oem" if i == 0 else "our"].clear()
            rs.append(e.call("tisp_ccm_main_ev_update", lo, hi) if i == 0 else e.call("emu_ccm_main_ev", b["ctx"], lo, hi))
        stats["ccm_main_ev"] = stats.get("ccm_main_ev", 0) + 1
        if any(r.stop for r in rs): rec("ccm_main_ev", "stopped %s" % [r.stop for r in rs])
        elif log["oem"] != log["our"]: rec("ccm_main_ev", "register writes differ")
        elif rs[0].v0 != rs[1].v0: rec("ccm_main_ev", "return differs")
        else: same("ccm_main_ev", [(k, b[k], b[k], n) for k, n in (("ctx", CTX), ("outer", OUTER), ("inter", INTER))], "ev=%#x:%#x" % (hi, lo))
    for kind in ("lsc", "clm"):
        if kind + "_ct" not in want: continue
        sv, fq, wt = (("lsc_frm_num_saved", "lsc_wlut_frequency", "lsc_lut_write_times") if kind == "lsc"
                      else ("clm_frame_num_saved", "clm_wlut_frequency", "clm_wlut_times"))
        saved = b"".join(struct.pack("<II", *u64pair()) for _ in range(2)); freq = bytes(rnd.choice([0, 1, 5, 255, rnd.getrandbits(8)]) for _ in range(2))
        times = rbytes(2)
        bank = rnd.choice([0, 1]); f = u64pair(); live.clear(); live.add("tisp_%s_ct_update" % kind)
        if rnd.random() < 0.4:      # fnum right at saved + freq (+-1)
            s = struct.unpack_from("<Q", saved, 8 * bank)[0] + freq[bank] + rnd.choice([-1, 0, 1]); f = (s & M32, (s >> 32) & M32)
        oem.write(OEM_G[sv], saved); oem.write(OEM_G[fq], freq); oem.write(OEM_G[wt], times)
        our.write(b[kind + "_saved"], saved); our.write(b[kind + "_freq"], freq)
        ret["tisp_lsc_interp_by_ct" if kind == "lsc" else "tisp_clm_ct_interp"] = rnd.choice([0, 0, 1, M32, r32()])
        ct = rand_ct(); a3 = r32()
        rs = []
        for i, e in enumerate(E):
            log["oem" if i == 0 else "our"].clear()
            if i == 0: rs.append(e.call("tisp_%s_ct_update" % kind, bank, r32(), ct, a3, stack_args=f))
            elif kind == "lsc": rs.append(e.call("emu_lsc_ct", bank, ct, a3, f[0], stack_args=(f[1],)))
            else: rs.append(e.call("emu_clm_ct", bank, ct, f[0], f[1]))
        name = kind + "_ct"; stats[name] = stats.get(name, 0) + 1
        if any(r.stop for r in rs): rec(name, "stopped %s" % [r.stop for r in rs]); continue
        if log["oem"] != log["our"]: rec(name, "calls differ: oem %s our %s saved=%s freq=%s bank=%d f=%s" % (log["oem"], log["our"], saved.hex(), freq.hex(), bank, f)); continue
        if rs[0].v0 != rs[1].v0: rec(name, "return oem %#x our %#x" % (rs[0].v0, rs[1].v0)); continue
        if oem.read(OEM_G[sv], 16) != our.read(b[kind + "_saved"], 16): rec(name, "saved frame numbers differ"); continue
        # write_times: the OEM increments its byte; ours is a recorded prepare call (compared in the call log)
        n_prep = sum(1 for x in log["our"] if x[0].endswith("prepare_write_lut"))
        exp = bytearray(times); exp[bank] = (exp[bank] + n_prep) & 0xff
        if oem.read(OEM_G[wt], 2) != bytes(exp): rec(name, "write_times oem %s expected %s" % (oem.read(OEM_G[wt], 2).hex(), bytes(exp).hex()))
for k in sorted(stats): print("%-12s %6d calls  %d mismatches" % (k, stats[k], bad.get(k, 0)))
sys.exit(1 if bad else 0)
