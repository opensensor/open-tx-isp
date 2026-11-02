#!/usr/bin/env python3
"""diff_awb_chain.py OEM.ko AWB_EMU.o [--n 300] [--seed 7] [--fn NAME,...]

T40 AWB init / EV / process chain (issue #85): run the OEM functions of the vendor tx-isp-t40.ko and the C versions
(tx_isp_t40_awb_init.inc / _main.inc, built for mipsel by tests/t40_vawb/build_emu.sh into AWB_EMU.o) in Unicorn on the same random state
and compare (1) every byte of the state the functions can reach (both channels' inter / outer blocks, both context pointer tables, the
colour-temperature detection argument block, the AE contexts, awb_num, the custom-algorithm flags and completion), (2) the order and values
of the register writes and reads, the events pushed and the completions signalled.  Register reads return a deterministic random
sequence (the same for both).  Both emulators place their blocks at the same guest addresses, so the pointer tables compare as plain words.
Functions: params_transmit params_refresh set_hardware_param dn_params_refresh main_ev_update ev_update_Ywgt long_par_update
spec_calculate (default), main_process (--fn main_process: needs a realistic state; on random state the OEM divides by zero inside
long_alogrithm, which Unicorn does not trap, and this OEM build counts awb_num to 100 and has no peter_test_count).
Known differences of the OEM build used here against the earlier build the translation was generated from: see MASK / _skip_tail below.
Nothing of the vendor module is stored here: point it at your own copy.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_SP, UC_MIPS_REG_SP

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=300); ap.add_argument("--seed", type=int, default=7)
ap.add_argument("--fn", default="params_transmit,params_refresh,set_hardware_param,dn_params_refresh,main_ev_update,ev_update_Ywgt,long_par_update,spec_calculate")
a = ap.parse_args(); rnd = random.Random(a.seed)
M32 = 0xffffffff
FN = {  # name -> (OEM symbol, our symbol)
    "params_transmit": ("tisp_awb_params_transmit", "emu_params_transmit"), "params_refresh": ("tisp_awb_params_refresh", "emu_params_refresh"),
    "set_hardware_param": ("tisp_awb_set_hardware_param", "emu_set_hardware_param"), "dn_params_refresh": ("tisp_awb_dn_params_refresh", "emu_dn_params_refresh"),
    "main_ev_update": ("tisp_awb_main_ev_update", "emu_main_ev_update"), "ev_update_Ywgt": ("tisp_awb_ev_update_Ywgt", "emu_ev_update_Ywgt"),
    "long_par_update": ("tisp_awb_long_par_update", "emu_long_par_update"), "spec_calculate": ("tisp_awb_spec_calculate", "emu_spec_calculate"),
    "main_process": ("tisp_awb_main_process", "emu_main_process")}
# state symbols: role -> (OEM name, our name, size)
SYM = {"mctx": ("pstMainAwbOri", "pstMainAwbOri", 512), "sctx": ("pstSecAwbOri", "pstSecAwbOri", 512),
       "mct": ("pstMainAwbCtDetectOri", "pstMainAwbCtDetectOri", 136),
       "mae": ("pstMainAeOri", "pstMainAeOri_storage", 0x164), "sae": ("pstSecAeOri", "pstSecAeOri_storage", 0x164),
       "num": ("awb_num", "vawb_awb_num", 1), "cust": ("tawb_custom_en", "emu_algo_enable", 8), "comp": ("awb_algo_comp", "awb_algo_comp", 32)}
PTR = {"mi": ("stMainAwbInter", "stMainAwbInter"), "mo": ("stMainAwbOuter", "stMainAwbOuter"), "si": ("stSecAwbInter", "stSecAwbInter"),
       "so": ("stSecAwbOuter", "stSecAwbOuter")}

log = {}
def mk_hle(tag):
    L = log[tag] = []
    st = {"x": 1}
    def rd(e):
        a0 = e.get_reg(UC_MIPS_REG_A0)
        x = st["x"]; x ^= (x << 13) & M32; x ^= x >> 17; x ^= (x << 5) & M32; st["x"] = x
        v = 0 if (x & 7) == 0 else (x & 0xff if x & 8 else x >> 4)
        L.append(("r", a0, v)); return v
    def wr(e):
        L.append(("w", e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1))); return 0
    def ev(e):
        p = e.get_reg(UC_MIPS_REG_A1); w = struct.unpack("<6I", e.read(p, 24))
        L.append(("e", e.get_reg(UC_MIPS_REG_A0), w[2], w[4], w[5])); return 0
    def comp(e):
        L.append(("c", e.get_reg(UC_MIPS_REG_A0))); return 0
    return st, {"system_reg_read": rd, "system_reg_write": wr, "tisp_event_push": ev, "private_complete": comp,
                "div64_u64": lambda e: (lambda a, b: ((a // b if b else 0) & M32, ((a // b if b else 0) >> 32) & M32))(
                    e.get_reg(UC_MIPS_REG_A0) | e.get_reg(UC_MIPS_REG_A1) << 32, e.get_reg(UC_MIPS_REG_A2) | e.get_reg(UC_MIPS_REG_A3) << 32),
                "isp_printf": lambda e: 0, "printk": lambda e: 0, "_printk": lambda e: 0, "__udivdi3": None, "__umoddi3": None}
st_o, h_o = mk_hle("oem"); st_c, h_c = mk_hle("our")
for h in (h_o, h_c):
    for k in [k for k, v in h.items() if v is None]: del h[k]
oem = KoEmu(a.oem, hle=h_o, max_insns=3_000_000); our = KoEmu(a.our, hle=h_c, max_insns=3_000_000)
# the functions the OEM module defines itself: hook their entry (the callback does what the HLE does for an undefined symbol)
for name in ("system_reg_read", "system_reg_write", "tisp_event_push", "private_complete"):
    ad = oem.symaddr[name]; cb = h_o[name]
    def hook(uc, addr, size, ud, cb=cb):
        rv = cb(oem); oem.set_reg(UC_MIPS_REG_V0, rv & M32); oem.set_reg(UC_MIPS_REG_PC, oem.get_reg(UC_MIPS_REG_RA))
    oem.uc.hook_add(UC_HOOK_CODE, hook, None, ad, ad)
# Known differences of this OEM build (the translation tx_isp_t40_vawb_gen.inc was generated from an earlier Eufy build, the C follows that one):
#  - tisp_awb_main_ev_update additionally calls tisp_awb_set_lum_th_freq(ctx, 0) after the Y weights: the hook skips that tail call
#  - tisp_awb_params_refresh of the second channel also copies outer +456 (36 B) and +492 (20 B): those 56 bytes of the second outer block are not compared
import re
_ev = oem.symaddr["tisp_awb_main_ev_update"]
def _skip_tail(uc, addr, size, ud):
    sp = oem.get_reg(UC_MIPS_REG_SP); ra = struct.unpack("<I", oem.read(sp + 20, 4))[0]
    oem.set_reg(UC_MIPS_REG_SP, sp + 24); oem.set_reg(UC_MIPS_REG_V0, 0); oem.set_reg(UC_MIPS_REG_PC, ra)
    if ra == 0x70000000: uc.emu_stop()      # returning to the call sentinel
# the `lw ra,20(sp)` after the Ywgt call is the first instruction following the jalr (delay slot included): find it by its encoding
_w = [struct.unpack("<I", oem.read(_ev + o, 4))[0] for o in range(0, 0x60, 4)]
_i = next(k for k, w in enumerate(_w) if w == 0x8fbf0014)        # lw ra,20(sp)
oem.uc.hook_add(UC_HOOK_CODE, _skip_tail, None, _ev + 4 * _i, _ev + 4 * _i)
MASK = {"so": [(456, 512)]}
E = (oem, our)
def symaddr(e, k, which): return e.addr(k[which])
def both(fn): return [fn(e, i) for i, e in enumerate(E)]
def wr_all(addr, data): [e.write(addr, data) for e in E]
def wr32(addr, v): wr_all(addr, struct.pack("<I", v & M32))
def sym(i, role): return E[i].addr(SYM[role][i])
ROLES = [r for r in SYM if all(SYM[r][i] in E[i].symaddr for i in (0, 1))]      # state both sides have (an object without the process chain has no awb_num)
def ptr(i, role): return E[i].addr(PTR[role][i])
def fill(n, mode=0):
    return bytes(rnd.getrandbits(8) for _ in range(n))
def small(n): return rnd.randrange(n) if n > 0 else 0
def r32(): return rnd.getrandbits(32)
def u16le(v): return struct.pack("<H", v & 0xffff)

INTER, OUTER = 0x10000, 0x2000
def setup_blocks():
    """allocate identical blocks in both emulators, point the OEM / our globals at them, run params_transmit of each channel"""
    for e in E: e.heap_reset()
    blk = {}
    for k, n in (("mi", INTER), ("mo", OUTER), ("si", INTER), ("so", OUTER), ("b0", 0x2000), ("b1", 0x2000), ("geo", 64), ("sum", 2 * 1024), ("ev", 32), ("out", 16),
                 ("geo2", 64), ("sum2", 2 * 1024), ("ev2", 32), ("out2", 16)):
        ad = [e.alloc(n, bytes(n)) for e in E]; assert ad[0] == ad[1]; blk[k] = ad[0]
    for i, e in enumerate(E):
        for k in ("mi", "mo", "si", "so"): e.write(e.addr(PTR[k][i]), struct.pack("<I", blk[k]))
        tp = e.addr("tparamsN"); e.write(tp, struct.pack("<II", blk["b0"], blk["b1"]))
    return blk

def run(name, ev_fn, args):
    """run one function in both emulators; returns the per-emulator (result, log)"""
    out = []
    seed = r32() | 1
    for i, e in enumerate(E):
        L = log["oem" if i == 0 else "our"]; L.clear()
        (st_o if i == 0 else st_c)["x"] = seed
        sym_name = FN[name][i]
        r = e.call(sym_name, *args(i))
        out.append((r, list(L)))
    return out

def snapshot(i, blk):
    e = E[i]; parts = []
    for k, n in (("mi", INTER), ("mo", OUTER), ("si", INTER), ("so", OUTER), ("geo", 64), ("sum", 2048), ("ev", 32), ("out", 16)):
        parts.append((k, e.read(blk[k], n)))
    for role in ROLES: parts.append((role, e.read(sym(i, role), SYM[role][2])))
    return parts

def fuzz_state(blk, sensor):
    """random state with the interesting values over-represented (same distributions as tests/t40_vawb/vawb_host.c pr_fuzz)"""
    ctx = [struct.unpack("<128I", E[0].read(sym(0, "sctx" if sensor else "mctx"), 512))]
    c = ctx[0]
    src = blk["b1" if sensor else "b0"] + 4288
    wr_all(blk["si" if sensor else "mi"], fill(60328)); wr_all(blk["so" if sensor else "mo"], fill(4752)); wr_all(src, fill(4752))
    def w16(ad, v): wr_all(ad, u16le(v))
    def w8(ad, v): wr_all(ad, bytes([v & 255]))
    def w32l(ad, v): wr32(ad, v)
    for k in range(4): w16(src + 2 * k, small(40) if k % 2 == 0 else small(16))
    for k in range(4): w16(c[0] + 2 * k, small(40) if k % 2 == 0 else small(16))
    w16(c[49], small(4000)); w16(c[49] + 2, small(3000))
    w8(c[100], small(3) == 0); w8(c[101], small(3) == 0); w8(c[118], small(3) == 0); w8(c[119], small(4) == 0); w8(c[54], rnd.getrandbits(8))
    lo = small(3000) if small(4) else small(10)
    hi = lo + 3 + (small(3) if small(6) == 0 else small(600))      # (hi - lo) / 3 == 0 divides by zero: the OEM traps there
    if small(16) == 0: hi = lo + 3 + small(3000) if small(2) else 3 + small(3000) if lo > 3000 else hi
    if small(20) == 0:
        lo = 0x7fffff00 + small(256); hi = lo + 3 + small(256)
    w32l(c[6], lo); w32l(c[6] + 4, hi)
    d3 = ((hi - lo) & M32); d3 = (d3 - (1 << 32) if d3 >> 31 else d3); d3 = int(d3 / 3) & M32
    pick = small(16)
    ev = [lo, hi, lo + d3, hi + d3, lo - 1, hi - 1, hi + d3 - 1, lo + d3 - 1, r32(), 0, hi + small(d3 + 1) if d3 < (1 << 31) else hi][pick] if pick < 11 else \
        lo + small(((hi - lo) & M32) + 1) + small(2 * d3 + 3)
    w32l(c[116], ev & M32)
    t = small(100); thr = []
    for i in range(9):
        thr.append(t); t += 0 if small(8) == 0 else small(2000)
    if small(8) == 0: thr = [r32() for _ in range(9)]
    for i in range(9): w32l(c[21] + 4 * i, thr[i])
    if small(3) == 0: w32l(c[116], (thr[small(9)] + small(3) - 1) & M32)
    if small(8) == 0: w32l(c[116], r32() if small(4) else thr[8] + 1)
    for i in range(9): w16(c[22] + 2 * i, rnd.getrandbits(16))
    w16(c[3] + 2, small(16))
    w32l(c[18], small(3) if small(2) else r32()); w32l(c[19], small(3) if small(2) else r32())
    for i in range(4):
        w32l(c[15] + 4 * i, small(5000) if small(2) else r32()); w32l(c[16] + 4 * i, small(5000)); w32l(c[17] + 4 * i, small(5000) if small(2) else r32())
    w32l(c[18] + 4, small(70000) if small(2) else r32()); w32l(c[19] + 4, small(70000) if small(2) else r32())
    flags = bytes(((small(3) if small(8) < 6 else rnd.getrandbits(8)) if (i == 0 or i >= 5) else rnd.getrandbits(8)) for i in range(10))
    wr_all(c[27], flags)
    wr_all(c[50], bytes([small(3) if small(4) else rnd.getrandbits(8), small(4) if small(4) else rnd.getrandbits(8)]))
    w32l(c[9], small(5000) if small(2) else r32()); w32l(c[9] + 4, small(5000) if small(2) else r32())
    for i in range(32): w16(c[29] + 2 * i, small(900) if small(4) else rnd.getrandbits(16))
    for i in range(32): w16(c[30] + 2 * i, small(900) if small(4) else rnd.getrandbits(16))
    w32l(c[7], 1500 + small(14000) if small(4) else r32())
    # the same custom-algorithm flags in both: draw once
    cu = struct.pack("<II", int(small(3) == 0), int(small(3) == 0))
    if "cust" in ROLES:
        for i in range(2): E[i].write(sym(i, "cust"), cu)
    num = small(52) if small(4) else rnd.getrandbits(8)
    if "num" in ROLES:
        for i in range(2): E[i].write(sym(i, "num"), bytes([num]))
    # AE contexts: geometry / sums / exposure value pointers like gr_ae_setup()
    for k, (role, g, s, ev_, o) in enumerate((("mae", "geo", "sum", "ev", "out"), ("sae", "geo2", "sum2", "ev2", "out2"))):
        ae = bytearray(E[0].read(sym(0, role), 0x164))
        struct.pack_into("<I", ae, 71 * 4, blk[g]); struct.pack_into("<I", ae, 34 * 4, blk[s]); struct.pack_into("<I", ae, 11 * 4, blk[ev_]); struct.pack_into("<I", ae, 68 * 4, blk[o])
        for i in range(2): E[i].write(sym(i, role), bytes(ae))
        wr_all(blk[g], struct.pack("<4H", 0, 1 + small(16), 0, 1 + small(15)))      # rows / columns > 0 (zero divides: the OEM traps)
        wr_all(blk[s], b"".join(struct.pack("<I", (1 << small(28)) if small(8) else 0) for _ in range(256)))
        wr_all(blk[ev_], struct.pack("<4I", 0, 0, (1 << small(20)) if small(8) else 1, 0))
        wr_all(blk[o], struct.pack("<2I", r32(), 0))
    return c

bad = 0; shown = 0; skipped = 0; calls = {}
names = [n for n in a.fn.split(",") if FN[n][1] in our.symaddr]
blk = setup_blocks()
# the context pointer tables of both channels: params_transmit of the OEM module, then the same call in our object, compared below
for sensor in (0, 1):
    for i, e in enumerate(E):
        e.call(FN["params_transmit"][i], sym(i, "sctx" if sensor else "mctx"), sensor)
    assert E[0].read(sym(0, "sctx" if sensor else "mctx"), 512) == E[1].read(sym(1, "sctx" if sensor else "mctx"), 512), "params_transmit tables differ"
for it in range(a.n):
    for name in names:
        sensor = int(small(5) == 0)
        # restore valid pointer tables, then fuzz
        for i, e in enumerate(E):
            e.call(FN["params_transmit"][i], sym(i, "sctx" if sensor else "mctx"), sensor); e.call(FN["params_transmit"][i], sym(i, "mctx"), 0)
        log["oem"].clear(); log["our"].clear()
        c = fuzz_state(blk, sensor)
        if name == "params_transmit":
            junk = fill(512)
            for i in range(2): E[i].write(sym(i, "sctx" if sensor else "mctx"), junk)
        args = {"params_transmit": lambda i: (sym(i, "sctx" if sensor else "mctx"), sensor), "params_refresh": lambda i: (sym(i, "sctx" if sensor else "mctx"), sensor, blk["b1" if sensor else "b0"] + 4288),
                "set_hardware_param": lambda i: (sym(i, "sctx" if sensor else "mctx"), sensor), "dn_params_refresh": lambda i: (sensor,),
                "main_ev_update": lambda i: (r32() >> small(20),), "ev_update_Ywgt": lambda i: (sym(i, "mctx"),),
                "long_par_update": lambda i: (sym(i, "mctx"), sym(i, "mct"), blk["mi"]), "spec_calculate": lambda i, ch=small(2): (sym(i, "mctx"), ch),
                "main_process": lambda i: ()}[name]
        if name == "main_ev_update":
            evv = r32() >> small(20); args = lambda i, evv=evv: (evv,)
        snap0 = snapshot(0, blk)
        # same initial state in our emulator is guaranteed by wr_all; run
        res = run(name, None, args)
        (ro, lo_), (rn, ln_) = res
        calls[name] = calls.get(name, 0) + 1
        if ro.stop or rn.stop:
            skipped += 1
            if os.environ.get("DBG"): print("STOP", name, ro.stop, rn.stop, ro.insns, rn.insns)
            continue
        so, sn = snapshot(0, blk), snapshot(1, blk)
        def masked(k, x):
            x = bytearray(x)
            for lo_m, hi_m in MASK.get(k, ()): x[lo_m:hi_m] = bytes(hi_m - lo_m)
            return bytes(x)
        diff = [k for (k, x), (_, y) in zip(so, sn) if masked(k, x) != masked(k, y)]
        if diff or lo_ != ln_:
            bad += 1
            if shown < 6:
                shown += 1; print("MISMATCH %s (sensor %d): state differs in %s; log oem %d entries, our %d" % (name, sensor, ",".join(diff) or "-", len(lo_), len(ln_)))
                for k in diff[:2]:
                    x = dict(so)[k]; y = dict(sn)[k]
                    d = [j for j in range(0, len(x), 4) if x[j:j + 4] != y[j:j + 4]][:4]
                    print("  %s +%s oem=%s our=%s" % (k, ",".join("%#x" % j for j in d), ",".join(x[j:j + 4].hex() for j in d), ",".join(y[j:j + 4].hex() for j in d)))
                if lo_ != ln_:
                    for j, (p, q) in enumerate(zip(lo_, ln_)):
                        if p != q: print("  log[%d] oem=%s our=%s" % (j, p, q)); break
print("awb chain OEM vs C: %s  mismatches %d, skipped (stopped) %d" % (" ".join("%s=%d" % kv for kv in calls.items()), bad, skipped))
sys.exit(1 if bad else 0)
