#!/usr/bin/env python3
"""diff_ae_leaf.py OEM.ko LEAF_EMU.o [--fac FACTORY.ko] [--n 1000] [--seed 7] [--fn NAME,...]

T40 AE leaf / parameter functions (issue #85, class A and B of audit/i85j/AE_LEFTOVERS.md): the OEM tisp_ae_g_luma, g_comp, get_state,
algo_deinit_internal, get_hist_bin, set_hist_bin, get_y_zone, g_scene_luma, s_comp, api_set_exp_list, tisp_s_ae_explist, tisp_g_ae_exprinfo_attr, tisp_ae_algo_init,
tisp_s_ae_exprinfo_attr, tisp_s_ae_scence_attr, tisp_g_ae_scence_attr of the vendor tx-isp-t40.ko and the C of
driver/t40/tx_isp_t40_ae_leaf.h (built for mipsel by tests/t40_ae_leaf/build_emu.sh into LEAF_EMU.o) run in Unicorn on the same random
universe: both AE contexts (0x164 bytes) with their pointer fields aimed at random buffers, the stM/SAeOuter blocks, ae_cache,
tparamsN, tisp_tattr, the hist-last arrays, ta_custom_en, plus the call arguments.  Compared: return value (where the OEM value is
defined), every byte of the whole heap and of the globals, and the sequence of calls to the functions outside the header
(tisp_ae_set_hardware_param, tisp_ae_par_calc, tisp_ae_set_exprinfo_attr, the AE locks).
tisp_ae_sensor_trig and tisp_ae_ev_start_set (and so tisp_s_ae_scence_attr, which calls it) differ between the two OEM builds (the vendor image moved the ae_cache fields and has an
extra store); the driver uses the factory layout, so they are compared with --fac (the factory Eufy module).
Class C (tisp_ae_roi_point, tisp_ae_sepc_area; system_reg_write and isp_printf are logged: register, value, message text and arguments): the
vendor image is the reference; roi_point_fac compares the valid-window path with the factory build, whose roi_point has no early return on a bad or too large
window (it prints and then writes the registers anyway).  The factory sepc_area is a different function body (other clamp/store
order, extra printk): the driver follows the vendor image, so it is not compared with it.
Not compared: OEM tisp_ae_g_luma with an empty geometry (divu by zero, undefined result; counted as skipped), the return value of
g_luma / g_comp / ev_start_set (the OEM leaves a stale register), channels >= 2 (the OEM indexes tables without a bound).
--mutate is done by the caller (tests/t40_ae_leaf_host.sh edits a copy of the header).  Nothing of the vendor module is stored here.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu, HEAP
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_SP, UC_MIPS_REG_A3, UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_V0, UC_MIPS_REG_PC, UC_MIPS_REG_RA

ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our"); ap.add_argument("--fac")
ap.add_argument("--n", type=int, default=1000); ap.add_argument("--seed", type=int, default=7)
ap.add_argument("--fn", default="g_luma,g_comp,get_state,sensor_trig,ev_start_set,algo_deinit,get_hist_bin,set_hist_bin,get_y_zone,"
                "g_scene_luma,s_comp,api_set_exp_list,s_explist,s_exprinfo,s_scence,g_scence,g_exprinfo,algo_init,roi_point,sepc_area,roi_point_fac")
a = ap.parse_args(); rnd = random.Random(a.seed); M32 = 0xffffffff
FAC_ONLY = ("sensor_trig", "ev_start_set", "s_scence", "roi_point_fac")
skip_case = {"v": False}

logs = {"ref": [], "our": []}

def lock_name(emu, addr):
    for n in ("main_slock_hist", "sec_slock_hist", "main_slock", "sec_slock"):
        if emu.symaddr.get(n) == addr: return n
    return "?%#x" % addr

def ctx_idx(emu, addr, oem):
    for i, n in enumerate(("pstMainAeOri", "pstSecAeOri") if oem else ("pstMainAeOri_storage", "pstSecAeOri_storage")):
        if emu.symaddr[n] == addr: return i
    return "?%#x" % addr

def build(path, tag, oem):
    L = logs[tag]; holder = {}
    def g(e, i): return e.get_reg((UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2)[i])
    def lock(e): L.append(("lock", lock_name(e, g(e, 0)))); return 0
    def unlock(e): L.append(("unlock", lock_name(e, g(e, 0)))); return 0
    def hw(e): L.append(("hw", ctx_idx(e, g(e, 0), oem), g(e, 1))); return 0
    def pc(e): L.append(("pc", g(e, 0), ctx_idx(e, g(e, 1), oem))); return 0
    def ei(e): L.append(("ei", g(e, 0), g(e, 1))); return 0
    def regw(e): L.append(("reg", g(e, 0), g(e, 1))); return 0
    def cstr(e, ad):
        s = b""
        while len(s) < 200:
            c = e.read(ad + len(s), 1)
            if c == b"\0": break
            s += c
        return s
    def prn(e):         # isp_printf(level, fmt, a2, a3, stack...): level, the text and the 4 word arguments
        sp = e.get_reg(UC_MIPS_REG_SP); f = cstr(e, g(e, 1))
        w = [g(e, 2), e.get_reg(UC_MIPS_REG_A3)] + list(struct.unpack("<II", e.read(sp + 16, 8)))
        L.append(("prn", g(e, 0), f, tuple(w[:f.count(b"%d")]))); return 0
    def fdiv(e):
        if g(e, 2) == 0: skip_case["v"] = True
        return holder["ref"].call("fix_point_div_32", g(e, 0), g(e, 1), g(e, 2)).v0
    def fmul(e): return holder["ref"].call("fix_point_mult2_32", g(e, 0), g(e, 1), g(e, 2)).v0
    def flog(e): return holder["ref"].call("tisp_log2_fixed_to_fixed", g(e, 0), g(e, 1), g(e, 2)).v0
    h = {"printk": lambda e: 0, "_printk": lambda e: 0, "fix_point_div_32": fdiv, "fix_point_mult2_32": fmul, "tisp_log2_fixed_to_fixed": flog}
    if not oem: h.update({"emu_lock": lock, "emu_unlock": unlock, "tisp_ae_set_hardware_param": hw, "tisp_ae_par_calc": pc, "tisp_ae_set_exprinfo_attr": ei, "system_reg_write": regw, "isp_printf": prn})
    e = KoEmu(path, hle=h, max_insns=2_000_000)
    if oem:
        for nm, f in (("tisp_ae_set_hardware_param", hw), ("tisp_ae_par_calc", pc), ("tisp_ae_set_exprinfo_attr", ei), ("system_reg_write", regw), ("isp_printf", prn),
                      ("__private_spin_lock_irqsave", lock), ("private_spin_unlock_irqrestore", unlock)):
            def mk(f):
                def _hook(uc, addr, size, ud):
                    rv = f(e); e.set_reg(UC_MIPS_REG_V0, rv & M32); e.set_reg(UC_MIPS_REG_PC, e.get_reg(UC_MIPS_REG_RA))
                return _hook
            ad = e.symaddr[nm]; e.uc.hook_add(UC_HOOK_CODE, mk(f), None, ad, ad)
    return e, holder

refs = {}
for key, path in (("vnd", a.oem), ("fac", a.fac)):
    if path:
        e, holder = build(path, "ref", True); holder["ref"] = e; refs[key] = e
our, oh = build(a.our, "our", False)
for h in [oh]: h["ref"] = refs["vnd"]            # forwarded fix_point helpers (identical in both OEM builds)
want = a.fn.split(",")
if "fac" not in refs:
    skipped_fac = [f for f in want if f in FAC_ONLY]; want = [f for f in want if f not in FAC_ONLY]
    if skipped_fac: print("NOTE: %s need --fac (factory Eufy module): not compared" % ",".join(skipped_fac))
if not refs["vnd"].symaddr.get("tisp_ae_g_luma"): sys.exit("no OEM symbols")

GL = ("stMainAeOuter", "stSecAeOuter", "tparamsN", "ta_custom_en", "tisp_ae_main_hist_last", "tisp_ae_sec_hist_last", "tisp_tattr")
GP = (("tisp_ae_main_ctrls", "tisp_ae_main_ctrls_storage", 164), ("tisp_ae_sec_ctrls", "tisp_ae_sec_ctrls_storage", 164), ("tisp_par_info", "tisp_par_info", 480))
def gsym(e, oem, i): return e.symaddr[GP[i][0] if oem else GP[i][1]]
def ctxs(e, oem, ch): return e.symaddr[("pstMainAeOri", "pstSecAeOri")[ch] if oem else ("pstMainAeOri_storage", "pstSecAeOri_storage")[ch]]
GSZ = {"stMainAeOuter": 4, "stSecAeOuter": 4, "tparamsN": 8, "ta_custom_en": 8, "tisp_ae_main_hist_last": 1052, "tisp_ae_sec_hist_last": 1052, "tisp_tattr": 4}

def r32(): return rnd.getrandbits(32)
def small(): return rnd.choice([0, 1, 2, 3, 7, 127, 128, 129, 255, 256, 1000, 4095, 65535, r32(), rnd.getrandbits(8), rnd.getrandbits(16), rnd.getrandbits(12)])
def rbytes(n): return rnd.randbytes(n)
def u16s(vals): return b"".join(struct.pack("<H", v & 0xffff) for v in vals)
def u32s(vals): return b"".join(struct.pack("<I", v & M32) for v in vals)
SLOT_SIZE = {104: 1040, 140: 912, 208: 272, 348: 272}          # default 96 bytes: the fields the functions touch are in the first 64
PTR_SLOTS = (4, 8, 12, 48, 52, 56, 60, 68, 72, 104, 140, 152, 160, 164, 172, 176, 184, 192, 208, 260, 264, 276, 284, 288, 312, 316, 320, 324, 328, 336, 340, 344, 348)

def slot_content(off):
    d = bytearray(rbytes(SLOT_SIZE.get(off, 96)))
    if off == 4: d[0:2] = u16s([rnd.choice([0, 1, 2, 5, 8, 10, 12, 16, 20, 23, 23, 24, 31, 40])])
    elif off == 60: d[0:4] = u16s([rnd.choice([0, 100, 199, 200, 640, 1280, 1920, 2560, 3840, rnd.getrandbits(12), rnd.getrandbits(16)]), rnd.choice([0, 100, 199, 200, 480, 720, 1080, 1440, 2160, rnd.getrandbits(12), rnd.getrandbits(16)])])
    elif off == 56: d[0:60] = u32s([rnd.choice([0, 1, 255, 1000, rnd.getrandbits(14), r32()]) for _ in range(15)])
    elif off == 104:
        mode = rnd.choice([0, 1, 2]); d[0:1024] = u32s([rnd.choice([0, 1, 5, rnd.getrandbits(8)]) if mode == 0 else rnd.getrandbits(18) if mode == 1 else
                                                         rnd.choice([r32(), rnd.getrandbits(12), 0xc0000000 | rnd.getrandbits(30), 0x40000000 | rnd.getrandbits(8), 0x80000000 | rnd.getrandbits(8)]) for _ in range(256)])
    elif off == 208: d[0:264] = u32s([rnd.choice([rnd.getrandbits(16), rnd.getrandbits(10), 1 << 12, r32(), 0]) for _ in range(66)])
    elif off == 284:
        v = [rnd.choice([rnd.randrange(1, 20), 0, 1, 0xffff, rnd.getrandbits(16), rnd.randrange(1, 8)]) if rnd.random() < 0.3 else rnd.randrange(1, 20) for _ in range(40)]
        d[0:80] = u16s(v)
    elif off == 288: d[20:22] = u16s([rnd.choice([rnd.randrange(0, 60), rnd.randrange(0, 60), 0, 1, 62, 63, 500, rnd.getrandbits(16)])])
    elif off == 260: d[0] = rnd.choice([0, 1, 1, 2, 255, rnd.getrandbits(8)])
    elif off == 276: d[0:4] = u32s([rnd.choice([128, 128, 0, 1, 127, 255, 256, rnd.getrandbits(8), r32()])])
    elif off == 320: d[0:36] = u32s([rnd.choice([0, 1, 2, 3, 4, r32()]), small(), small(), small(), small(), small(), small(), small(), small()])
    elif off == 324: d[0:16] = u16s([small() for _ in range(8)])
    return bytes(d)

def universe(refkey):
    """identical random state in the reference module and in the C object; returns the addresses of the call-argument buffers"""
    ref = refs[refkey]; E = (ref, our)
    for e in E:
        e.write(HEAP, bytes(max(e.heap_ptr - HEAP, 16))); e.heap_reset()       # no stale bytes between the objects
    def alloc(data):
        ads = [e.alloc(len(data), data) for e in E]; assert ads[0] == ads[1]; return ads[0]
    U = {"bufs": {}}
    pool = {}                                           # a few shared buffers for aliasing
    for ch in (0, 1):
        ctx = bytearray(rbytes(0x164)); ptrs = {}
        for off in PTR_SLOTS:
            if rnd.random() < 0.03 and pool: p = rnd.choice(list(pool.values()))      # aliasing with another field
            else: p = alloc(slot_content(off)); pool[(ch, off)] = p
            if rnd.random() < 0.02: p = p + 4 * rnd.randrange(1, 5)                  # offset pointer (never NULL: T40_AE_OK is off here)
            ptrs[off] = p; ctx[off:off + 4] = struct.pack("<I", p)
        for i, e in enumerate(E):
            e.write(ctxs(e, i == 0, ch), bytes(ctx))
        U["ctx%d" % ch] = ptrs
    def outer_blk():
        d = bytearray(rbytes(400))
        for o in (296, 298, 300): d[o:o + 2] = u16s([rnd.choice([0, 0, 1, 7, 0xffff, rnd.getrandbits(16)])])
        return alloc(bytes(d))
    outer = [outer_blk() for _ in (0, 1)]
    for i, e in enumerate(E):
        e.write(e.symaddr["stMainAeOuter"], struct.pack("<I", outer[0])); e.write(e.symaddr["stSecAeOuter"], struct.pack("<I", outer[1]))
    cb = [bytearray(rbytes(0x518 + 16)) for _ in (0, 1)]
    for b in cb: b[700:704] = u32s([rnd.choice([0, 1, 1, 2, r32()])])
    cache = [alloc(bytes(b)) for b in cb]; tp = [alloc(rbytes(2048)) for _ in (0, 1)]
    for p in tp:
        v = u16s([rnd.choice([0, 1, 100, 200, 1000, 4095, 0xffff, rnd.getrandbits(16)])])
        for e in E: e.write(p + 1024, v)
    tattr = alloc(rbytes(2 * 220 + 64))
    ae_cache = [e.symaddr["ae_cache"] for e in E]
    for e in E: e.write(e.symaddr["ae_cache"], u32s(cache))
    tce = u32s([rnd.choice([0, 1, 1, 2, r32()]), rnd.choice([0, 1, 1, 2, r32()])])
    for e in E:
        e.write(e.symaddr["tparamsN"], u32s(tp)); e.write(e.symaddr["tisp_tattr"], u32s([tattr]))
        e.write(e.symaddr["ta_custom_en"], tce)
    hl = [rbytes(1052), rbytes(1052)]
    for e in E:
        e.write(e.symaddr["tisp_ae_main_hist_last"], hl[0]); e.write(e.symaddr["tisp_ae_sec_hist_last"], hl[1])
    ctl = [rbytes(164), rbytes(164)]
    pinf = bytearray(rbytes(480))
    for ch in (0, 1):
        pinf[152 * ch + 44:152 * ch + 48] = u32s([rnd.choice([rnd.getrandbits(32), rnd.getrandbits(20), 0x10000 | rnd.getrandbits(8), 0x30000000 | rnd.getrandbits(16)])])
        pinf[152 * ch + 70:152 * ch + 72] = u16s([rnd.choice([rnd.getrandbits(16), 1, 0xffff, rnd.randrange(1000, 40000)])])
    for e in E:
        oem = e is ref
        e.write(gsym(e, oem, 0), ctl[0]); e.write(gsym(e, oem, 1), ctl[1]); e.write(gsym(e, oem, 2), bytes(pinf))
    # call-argument buffers
    U["dst"] = alloc(rbytes(1100)); U["src"] = alloc(rbytes(1100)); U["out"] = alloc(rbytes(256)); U["u"] = alloc(rbytes(200))
    lst = bytearray(rbytes(16 * 20 + 20)); U["list"] = alloc(bytes(lst))
    U["list4"] = alloc(u32s([rnd.choice([0, 1, 1, 2, r32()])]) + bytes(lst))               # s_explist block: mode word + entries
    sc = bytearray(rbytes(40)); sc[0:4] = u32s([rnd.choice([0, 1, 2, 3, 4, r32()])]); sc[8:12] = u32s([rnd.choice([0, 1, 2, 3, 4, r32()])])
    sc[16:20] = u32s([rnd.choice([0, 1, 2, 3, 4, r32()])]); sc[24:28] = u32s([rnd.choice([0, 1, 2, 3, r32()])]); sc[20:22] = u16s([small()])
    U["scene"] = alloc(bytes(sc))
    def c16(): return rnd.choice([0, 1, 99, 100, 101, 150, 199, 200, 201, 640, 1000, 1919, 1920, 2047, 2560, 3000, 3839, 3840, 4095, rnd.getrandbits(12), rnd.getrandbits(16), r32()])
    U["face"] = alloc(u32s([rnd.choice([0, 1, 1, 2, r32()]), c16(), c16(), c16(), c16(), rnd.choice([0, 5, 9, 10, 11, 100, 199, 200, 201, 5000, r32()])]))
    ex = bytearray(rbytes(180)); U["expo"] = alloc(bytes(ex))
    return U

def geo_zero(e, oem, ch):
    ctx = e.read(ctxs(e, oem, ch), 0x164); g = struct.unpack("<I", ctx[284:288])[0]
    v = [struct.unpack("<H", e.read(g + o, 2))[0] for o in (2, 6, 8, 38)]
    return (v[0] * v[1] * v[2] * v[3]) & M32 == 0

def dump(e, oem):
    out = [e.read(HEAP, e.heap_ptr - HEAP)]
    for ch in (0, 1): out.append(e.read(ctxs(e, oem, ch), 0x164))
    for n in GL: out.append(e.read(e.symaddr[n], GSZ[n]))
    out.append(e.read(e.symaddr["ae_cache"], 8))
    for i in range(len(GP)): out.append(e.read(gsym(e, oem, i), GP[i][2]))
    return out
LABEL = ["heap", "ctx0", "ctx1"] + list(GL) + ["ae_cache"] + [g[0] for g in GP]

stats = {}; bad = {}; skipped = {}
def rec(name, msg):
    bad[name] = bad.get(name, 0) + 1
    if bad[name] <= 3: print("MISMATCH", name, msg)

def run(name, fn, refkey, args_fn, cmp_ret=True, zero_geo=False, den_skip=False, mask=False):
    ref = refs[refkey]; U = universe(refkey)
    ch = rnd.choice([0, 1]); args = args_fn(U, ch)
    if zero_geo and (geo_zero(ref, True, ch) or geo_zero(our, False, ch)):
        skipped[name] = skipped.get(name, 0) + 1; return
    if den_skip:                                   # tisp_g_ae_exprinfo_attr: OEM divu by zero for an empty line time
        pi = ref.read(gsym(ref, True, 2) + 152 * ch, 152); p44 = struct.unpack_from("<I", pi, 44)[0]; p70 = struct.unpack_from("<H", pi, 70)[0]
        if ((p70 * p44) & M32) >> 16 == 0: skipped[name] = skipped.get(name, 0) + 1; return
    logs["ref"].clear(); logs["our"].clear(); skip_case["v"] = False
    sa = ()
    if name.startswith("roi_point"): args, sa = args[:4], args[4:]       # 5th argument (bottom) on the stack
    ro = ref.call(fn, *args, stack_args=sa); ru = our.call(fn, *args, stack_args=sa)
    if mask:                                       # tisp_ae_algo_init: 2 bytes at u+112+14 the OEM copies from uninitialised stack
        for e in (ref, our): e.write(args[2] + 126, b"\0\0")
    if skip_case["v"]:
        skipped[name] = skipped.get(name, 0) + 1; return
    if name.endswith("_fac") and any(x[0] == "prn" for x in logs["ref"] + logs["our"]):
        skipped[name] = skipped.get(name, 0) + 1; return          # the factory build has no early return on a bad window (see roi_point_fac)
    stats[name] = stats.get(name, 0) + 1
    for r, who in ((ro, "oem"), (ru, "our")):
        if r.stop: rec(name, "emulation stopped (%s): %s args %s" % (who, r.stop, [hex(x) for x in args])); return
    if cmp_ret and ro.v0 != ru.v0: rec(name, "return oem %#x our %#x args %s" % (ro.v0, ru.v0, [hex(x) for x in args])); return
    if logs["ref"] != logs["our"]: rec(name, "call log oem %s our %s args %s" % (logs["ref"][:4], logs["our"][:4], [hex(x) for x in args])); return
    do, du = dump(ref, True), dump(our, False)
    for k, lab in enumerate(LABEL):
        if do[k] != du[k]:
            i = next(j for j in range(len(do[k])) if do[k][j] != du[k][j])
            rec(name, "%s differs at +%#x (oem %02x our %02x) args %s ch %d" % (lab, i, do[k][i], du[k][i], [hex(x) for x in args], ch)); return

def roi_args():
    def c(): return rnd.choice([0, 1, 99, 100, 101, 200, 640, 1000, 1919, 1920, 2047, 2048, 4000, 4095, rnd.getrandbits(12), rnd.getrandbits(16), r32()])
    x0 = c(); y0 = c()
    if rnd.random() < 0.8: x1 = (x0 + c()) & M32 if rnd.random() < 0.5 else (x0 + rnd.getrandbits(11)) & M32; y1 = (y0 + rnd.getrandbits(11)) & M32
    else: x1 = c(); y1 = c()
    if rnd.random() < 0.1: y1 = r32()
    return x0, y0, x1, y1

ARGS = {
    "g_luma": ("tisp_ae_g_luma", "vnd", lambda U, ch: (ch, U["out"]), False, True),
    "g_comp": ("tisp_ae_g_comp", "vnd", lambda U, ch: (ch, U["out"]), False, False),
    "get_state": ("tisp_ae_get_state", "vnd", lambda U, ch: (ch, U["out"], U["out"] + 8, U["out"] + 16), True, False),
    "sensor_trig": ("tisp_ae_sensor_trig", "fac", lambda U, ch: (ch,), True, False),
    "ev_start_set": ("tisp_ae_ev_start_set", "fac", lambda U, ch: (ch, rnd.choice([0, 1, 1, 2, r32()]), r32()), False, False),
    "algo_deinit": ("tisp_ae_algo_deinit_internal", "vnd", lambda U, ch: (ch,), True, False),
    "get_hist_bin": ("tisp_ae_get_hist_bin", "vnd", lambda U, ch: (ch, U["dst"]), True, False),
    "set_hist_bin": ("tisp_ae_set_hist_bin", "vnd", lambda U, ch: (ch, U["src"]), True, False),
    "get_y_zone": ("tisp_ae_get_y_zone", "vnd", lambda U, ch: (ch, U["dst"]), True, False),
    "g_scene_luma": ("tisp_ae_g_scene_luma", "vnd", lambda U, ch: (ch, U["out"]), True, True),
    "s_comp": ("tisp_ae_s_comp", "vnd", lambda U, ch: (ch, rnd.choice([0, 1, 127, 128, 129, 200, 255, 256, 0x7ffffff, 0x1ffffff, 0x1999999a, 0xffffffff, r32(), rnd.getrandbits(8)])), True, False),
    "api_set_exp_list": ("tisp_ae_api_set_exp_list", "vnd", lambda U, ch: (ch, rnd.choice([0, 1, 1, 2, r32()]), U["list"]), True, False),
    "s_explist": ("tisp_s_ae_explist", "vnd", lambda U, ch: (ch, U["list4"]), True, False),
    "s_exprinfo": ("tisp_s_ae_exprinfo_attr", "vnd", lambda U, ch: (ch, U["expo"]), True, False),
    "s_scence": ("tisp_s_ae_scence_attr", "fac", lambda U, ch: (ch, U["scene"]), True, False),
    "g_scence": ("tisp_g_ae_scence_attr", "vnd", lambda U, ch: (ch, U["out"]), True, True),
    "g_exprinfo": ("tisp_g_ae_exprinfo_attr", "vnd", lambda U, ch: (ch, U["out"]), True, False, True),
    "roi_point": ("tisp_ae_roi_point", "vnd", lambda U, ch: (ch, *roi_args()), True, False),
    "sepc_area": ("tisp_ae_sepc_area", "vnd", lambda U, ch: (ch, U["face"]), False, False),
    "roi_point_fac": ("tisp_ae_roi_point", "fac", lambda U, ch: (ch, *roi_args()), True, False),
    "algo_init": ("tisp_ae_algo_init", "vnd", lambda U, ch: (ch, rnd.choice([0, 1, 1, 1, 2, r32()]), U["u"]), False, False, False, True),
}
for it in range(a.n):
    for name in want:
        fn, key, af, cr, zg, *rest = ARGS[name]
        if key == "fac" and "fac" not in refs: continue
        run(name, fn, key, af, cr, zg, *rest)
for k in sorted(stats):
    print("%-16s %6d calls  %d mismatches%s" % (k, stats[k], bad.get(k, 0), ("  (%d skipped: division by zero in the OEM or the factory build error path)" % skipped[k]) if k in skipped else ""))
sys.exit(1 if bad else 0)
