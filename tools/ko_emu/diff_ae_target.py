#!/usr/bin/env python3
"""diff_ae_target.py OEM_KO HOST_BIN [--n N] [--seed S]: OEM AE target / metering (vendor tx-isp-t40.ko, Unicorn) against
driver/t40/tx_isp_t40_ae_target.h (HOST_BIN, built from tests/t40_ae_target/harness.c) on the same random cases (#84):
  T  tisp_ae_long_target                       (return value)
  W  tisp_ae_long_weight_mean2                 (metered luma *param_5; Pweight off, no AE-cache override)
  A  tisp_ae_long_alogrithm                    (band parameters handed to weight_mean2 and the luma handed to
                                                tisp_ae_long_tune2; weight_mean2 hooked to return a chosen luma)
  G  tisp_ae_long_tune2 up to the target calls (EV at both tisp_ae_long_target calls and the EV / target lists they get;
                                                tisp_ae_long_target hooked)
  C  tisp_ae_s_comp                            (the target-scale word it stores)
Exit 1 on any difference."""
import argparse, os, random, struct, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_V0, UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3, UC_MIPS_REG_SP

ap = argparse.ArgumentParser(); ap.add_argument("ko"); ap.add_argument("host")
ap.add_argument("--n", type=int, default=2000); ap.add_argument("--seed", type=int, default=84)
a = ap.parse_args(); rnd = random.Random(a.seed)
def _div64(em):
    x = em.get_reg(UC_MIPS_REG_A0) | em.get_reg(UC_MIPS_REG_A1) << 32; y = em.get_reg(UC_MIPS_REG_A2) | em.get_reg(UC_MIPS_REG_A3) << 32
    q = x // y if y else 0; return (q & 0xffffffff, q >> 32)
e = KoEmu(a.ko, hle={"div64_u64": _div64})
M = 0xffffffff
def u32(addr): return struct.unpack("<I", e.read(addr, 4))[0]
def reg(r): return e.get_reg(r)

# ---- hooks ----
hk = {"wm": None, "tune2": None, "tgt": [], "tret": [], "stop_tgt": None}
def ret(uc, v):
    uc.reg_write(UC_MIPS_REG_V0, v & M); uc.reg_write(UC_MIPS_REG_PC, uc.reg_read(UC_MIPS_REG_RA))
def on_wm(uc, addr, size, ud):
    if hk["wm"] is None: return
    sp = reg(UC_MIPS_REG_SP); p5 = u32(sp + 16); p10 = u32(sp + 36) & 0xffff
    hk["wm_args"] = (reg(UC_MIPS_REG_A2), reg(UC_MIPS_REG_A3), p10)
    for k in range(5): e.write(u32(sp + 16 + 4 * k), struct.pack("<I", 0))
    e.write(p5, struct.pack("<I", hk["wm"])); ret(uc, 0)
def on_tune2(uc, addr, size, ud):
    if hk["tune2"] is None: return
    hk["tune2"] = reg(UC_MIPS_REG_A3); uc.emu_stop()
def on_tgt(uc, addr, size, ud):
    if hk["stop_tgt"] is None: return
    ev, pe, pt = reg(UC_MIPS_REG_A0), reg(UC_MIPS_REG_A1), reg(UC_MIPS_REG_A2)
    hk["tgt"].append((ev, struct.unpack("<10I", e.read(pe, 40)), struct.unpack("<10I", e.read(pt, 40))))
    ret(uc, hk["tret"][len(hk["tgt"]) - 1] if len(hk["tgt"]) <= len(hk["tret"]) else 60)
    if len(hk["tgt"]) >= hk["stop_tgt"]: uc.emu_stop()
def on_stop(uc, addr, size, ud):
    if hk["stop_tgt"] is not None: uc.emu_stop()
for name, fn in (("tisp_ae_long_weight_mean2", on_wm), ("tisp_ae_long_tune2", on_tune2), ("tisp_ae_long_target", on_tgt),
                 ("tisp_ae_long_tune", on_stop), ("tisp_ae_ev_list_alloc_calc", on_stop)):
    ad = e.addr(name); e.uc.hook_add(UC_HOOK_CODE, fn, begin=ad, end=ad)
AE_CACHE, SHOWPAR, FTUNE, TPN, PST = e.addr("ae_cache"), e.addr("aeShowPar"), e.addr("ftune_wmeans.40861"), e.addr("tparamsN"), e.addr("pstMainAeOri")

def ctx():
    """an AE context: 0x58 pointer slots, each to its own zeroed 0x800-byte buffer"""
    e.heap_reset()
    slots = [e.alloc(0x800, b"\0" * 0x800) for _ in range(0x58)]
    c = e.alloc(0x58 * 4, struct.pack("<%dI" % 0x58, *slots))
    show = e.alloc(0x400, b"\0" * 0x400); e.write(SHOWPAR, struct.pack("<I", show))
    cache = u32(AE_CACHE); e.write(cache + 0x1dc, b"\0" * 0xd0)
    return c, slots

def lists():
    k = rnd.random()
    if k < 0.15: ev = [rnd.getrandbits(rnd.choice([8, 16, 22, 32])) for _ in range(10)]
    else:
        ev, v = [], rnd.choice([0, 10, 50, rnd.getrandbits(12)])
        for _ in range(10):
            v = min(v + (0 if rnd.random() < 0.08 else rnd.choice([1, 50, 150, 1300, 4500, 20000, rnd.getrandbits(18)])), M); ev.append(v)
    if rnd.random() < 0.3: ev = [50, 200, 1500, 6000, 8500, 15000, 35000, 80000, 140000, 320000]
    tg = [rnd.choice([72, 68, 64, 40, 0, 1, 0xffff, rnd.getrandbits(8), rnd.getrandbits(16)]) for _ in range(10)]
    if rnd.random() < 0.3: tg = [72, 68, 64, 60, 58, 55, 50, 45, 44, 40]
    return ev, tg

cases, oem = [], []
for n in range(a.n):
    kind = "TWAGC"[n % 5]
    if kind == "T":
        ev, tg = lists(); q = rnd.choice([10, 10, 10, 0, 4, 16]); x = rnd.choice([rnd.choice(ev) << q, (rnd.choice(ev) << q) + rnd.randrange(-2048, 2048), rnd.getrandbits(32)]) & M
        e.heap_reset(); pe = e.alloc(40, struct.pack("<10I", *ev)); pt = e.alloc(40, struct.pack("<10I", *tg))
        r = e.call("tisp_ae_long_target", x, pe, pt, q); assert r.stop is None, r.stop
        oem.append("%u" % r.v0); cases.append("T %u %s %s %u" % (x, " ".join(map(str, ev)), " ".join(map(str, tg)), q))
    elif kind == "W":
        c, s = ctx()
        rows, cols = rnd.choice([15, 15, 15, rnd.randint(1, 15)]), rnd.choice([15, 15, 15, rnd.randint(1, 15)])
        rowh = [rnd.choice([72, 36, rnd.getrandbits(8), rnd.getrandbits(16)]) for _ in range(15)]
        colw = [rnd.choice([128, 64, rnd.getrandbits(8), rnd.getrandbits(16)]) for _ in range(15)]
        zone = [0, rows, 0, cols] + colw + rowh + [30, 230]
        e.write(s[0x47], struct.pack("<36H", *zone)); e.write(s[1], struct.pack("<H", 10))
        e.write(s[0x12], struct.pack("<I", 1))     # skip the highlight-mode refresh timer
        w = [rnd.choice([1, 1, 2, 0, 8, rnd.getrandbits(8)]) for _ in range(225)]
        e.write(s[0x54], bytes(w))
        pl = []
        for k in range(5):
            if k < 3: v = [rnd.choice([0, rnd.getrandbits(12), rnd.getrandbits(20), rnd.getrandbits(28)]) for _ in range(225)]
            else: v = [rnd.choice([0, rnd.getrandbits(8), rnd.getrandbits(14), rnd.getrandbits(20)]) for _ in range(225)]
            pl.append(v); e.write(s[(0x14, 0x15, 0x16, 0x18, 0x19)[k]], struct.pack("<225I", *v))
        p3, p4, p10 = rnd.choice([1, 1, 6, 0, rnd.getrandbits(4)]), rnd.choice([1, 6, 8, 0, rnd.getrandbits(4)]), rnd.choice([3, 1, 2, rnd.randint(1, 255)])
        outs = [e.alloc(4, b"\0" * 4) for _ in range(5)]
        r = e.call("tisp_ae_long_weight_mean2", 0, c, p3, p4, stack_args=tuple(outs) + (p10,))
        assert r.stop is None, r.stop
        oem.append("%u" % u32(outs[0]))
        cases.append("W %u %u %u %u %u %s %s %s %s" % (p3, p4, p10, rows, cols, " ".join(map(str, rowh)), " ".join(map(str, colw)),
                                                     " ".join(map(str, w)), " ".join(" ".join(map(str, v)) for v in pl)))
    elif kind == "A":
        c, s = ctx()
        mode = rnd.choice([1, 1, 1, 0, 2, 3]); scene = rnd.choice([0, 1, 2, 3, 0xffff]); thr = rnd.choice([230, 230, 255, 300, 30, rnd.getrandbits(8)])
        colw, rowh, cols, rows = rnd.choice([128, 64, 7]), rnd.choice([72, 36, 5]), rnd.choice([15, 15, 3]), rnd.choice([15, 15, 2])
        zone = [0, rows, 0, cols] + [colw] * 15 + [rowh] * 15 + [30, thr]
        e.write(s[0x47], struct.pack("<36H", *zone))
        mp = [rnd.choice([1, 0, 6, rnd.getrandbits(4)]), rnd.choice([6, 8, 1, 0, rnd.getrandbits(4)]), rnd.choice([3, 1, 0, rnd.getrandbits(5)])]
        e.write(s[0x51], struct.pack("<12H", 2560, 2560, 2560, 2560, *mp, 0, 0, 0, 0, 0))
        hl = [mode, 230, 829440, 30, 829440] + [rnd.choice([1, 0, 6, rnd.getrandbits(4)]) for _ in range(6)]
        e.write(s[0x50], struct.pack("<11I", *hl))
        e.write(s[3], struct.pack("<5H", 0, 0, 0, scene, 0))
        npix = colw * rowh * cols * rows
        hist = [rnd.choice([0, 0, rnd.getrandbits(8), rnd.getrandbits(14)]) for _ in range(256)]
        if rnd.random() < 0.3: hist = [rnd.getrandbits(6)] * 256
        e.write(s[0x1a], struct.pack("<256I", *hist))
        luma = rnd.choice([1, 62, 200, rnd.getrandbits(8), rnd.getrandbits(12)])
        hk["wm"] = luma; hk["tune2"] = 0; hk["wm_args"] = None
        r = e.call("tisp_ae_long_alogrithm", 0, c, 0)
        got = hk["tune2"]; hk["wm"] = None; hk["tune2"] = None
        assert hk["wm_args"] is not None, r.stop
        mp4, mp5, mp6 = mp
        oem.append("%u %u %u %u" % (hk["wm_args"] + (got,)))
        cases.append("A %u %u %u %u %u %u %u %s %u %s" % (luma, mode, scene, thr, mp4, mp5, mp6, " ".join(map(str, hl[5:])), npix, " ".join(map(str, hist))))
    elif kind == "G":
        c, s = ctx()
        ev, tg = lists(); tg = [x & 0xffff for x in tg]
        scw = [rnd.choice([128, 128, 0, 64, 255, rnd.getrandbits(16)]) for _ in range(10)]
        sc0, sc1, scword = rnd.choice([1, 1, 0, 2]), rnd.choice([128, 128, 0, 64, 200, rnd.getrandbits(16)]), rnd.choice([128, 128, 0, 428, 64, rnd.getrandbits(16)])
        e.write(s[0x4c], struct.pack("<10I", *ev)); e.write(s[0x4d], struct.pack("<10H", *tg)); e.write(s[0x53], struct.pack("<10H", *scw))
        e.write(s[0x52], struct.pack("<4H", sc0, sc1, scword, 0))
        e.write(s[1], struct.pack("<H", 10))
        it, ag, dg = rnd.choice([2241, 450, 176, rnd.getrandbits(12)]), rnd.choice([1024, 1696, 32768, rnd.getrandbits(16)]), rnd.choice([1024, 1109, 5120, rnd.getrandbits(13)])
        e.write(s[2], struct.pack("<3I", it, ag, dg))
        e.write(s[0], struct.pack("<8I", 2241, 32768, 1024, 5120, 3, 1024, 1024, 1024))
        e.write(s[3], struct.pack("<5H", 62, 0, 0, 0, 0))                 # target store, not stable
        e.write(s[0x4a], struct.pack("<4H", 1150, 950, 1, 1))
        e.write(s[0x48], struct.pack("<11H", 1, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0))
        e.write(s[0x26], b"\x01"); e.write(s[0x29], b"\x01"); e.write(s[0x41], b"\x00")
        e.write(s[0x47], struct.pack("<36H", *([0, 15, 0, 15] + [128] * 15 + [72] * 15 + [30, 230])))
        luma = rnd.choice([1, 40, 62, 120, rnd.getrandbits(8), rnd.getrandbits(10)])
        t0 = rnd.choice([62, 0, 1, 72, rnd.getrandbits(16), rnd.getrandbits(32)])
        hk["tgt"] = []; hk["tret"] = [t0, 55]; hk["stop_tgt"] = 2
        r = e.call("tisp_ae_long_tune2", 0, c, 0, luma, stack_args=(0, 0, 0, 0, 0, 0, 0))
        hk["stop_tgt"] = None
        assert len(hk["tgt"]) == 2, (r.stop, len(hk["tgt"]))
        (ev0, el, tl), (ev1, _, _) = hk["tgt"]
        oem.append("%u %u %s %s" % (ev0, ev1, " ".join(map(str, el)), " ".join(map(str, tl))))
        cases.append("G %u %u %u %u %u %u %u %u %s %s %s" % (it, ag, dg, luma, t0, sc0, sc1, scword, " ".join(map(str, ev)), " ".join(map(str, tg)), " ".join(map(str, scw))))
    else:
        e.heap_reset()
        slots = [e.alloc(0x800, b"\0" * 0x800) for _ in range(0x58)]
        e.write(PST, struct.pack("<%dI" % 0x58, *slots))
        tp = e.alloc(0x800, b"\0" * 0x800); e.write(TPN, struct.pack("<I", tp))
        e.write(slots[0x47], struct.pack("<36H", *([0, 15, 0, 15] + [128] * 15 + [72] * 15 + [30, 230])))
        b = rnd.choice([128, 128, 0, 64, 300, rnd.getrandbits(16)]); comp = rnd.choice([128, 0, 1, 129, 200, 255, 256, rnd.getrandbits(8), rnd.getrandbits(16)])
        e.write(tp + 0x400, struct.pack("<H", b))
        r = e.call("tisp_ae_s_comp", 0, comp)     # stops at the first register write; the word is stored before
        oem.append("%u" % struct.unpack("<H", e.read(slots[0x52] + 4, 2))[0])
        cases.append("C %u %u" % (b, comp))

out = subprocess.run([a.host], input="\n".join(cases) + "\n", capture_output=True, text=True).stdout.strip().split("\n")
bad = 0; cnt = {}
for c, o, h in zip(cases, oem, out):
    cnt[c[0]] = cnt.get(c[0], 0) + 1
    if o.split() != h.split():
        bad += 1
        if bad <= 6: print("diff_ae_target: %s\n  OEM  %s\n  open %s" % (c[:140], o[:200], h[:200]))
if len(out) != len(cases): print("diff_ae_target: host gave %d lines for %d cases" % (len(out), len(cases))); bad += 1
print("diff_ae_target: %s: %d differences" % (", ".join("%s %d" % kv for kv in sorted(cnt.items())), bad))
sys.exit(1 if bad else 0)
