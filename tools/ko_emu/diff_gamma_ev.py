#!/usr/bin/env python3
"""diff_gamma_ev.py OEM_KO HOST_BIN [--n N] [--seed S]: OEM tisp_gamma_interp_by_ev / tisp_gamma_strength_transform /
tisp_gamma_ev_update (vendor tx-isp-t40.ko, Unicorn) against driver/t40/tx_isp_t40_gamma_ev.h (HOST_BIN, built from
tests/t40_gamma_ev/harness.c) on the same random cases; compares return value, strength, stored EV, saved frame number,
whether the LUT write was armed and the 129-entry LUT.  Exit 1 on any difference (#204)."""
import argparse, os, random, struct, subprocess, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import UC_MIPS_REG_PC, UC_MIPS_REG_RA, UC_MIPS_REG_V0

ap = argparse.ArgumentParser(); ap.add_argument("ko"); ap.add_argument("host")
ap.add_argument("--n", type=int, default=2000); ap.add_argument("--seed", type=int, default=204)
a = ap.parse_args(); rnd = random.Random(a.seed)
e = KoEmu(a.ko)
armed = []
def on_prep(uc, addr, size, ud):
    armed.append(1); uc.reg_write(UC_MIPS_REG_V0, 0); uc.reg_write(UC_MIPS_REG_PC, uc.reg_read(UC_MIPS_REG_RA))
pw = e.addr("tisp_gamma_prepare_write_lut"); e.uc.hook_add(UC_HOOK_CODE, on_prep, begin=pw, end=pw)
GP, FREQ, SAVED = e.addr("gamma_para"), e.addr("gamma_wlut_frequency"), e.addr("gamma_frame_num_saved")

def tables():
    k = rnd.random()
    if k < 0.15: node = [rnd.getrandbits(32) for _ in range(10)]                 # unsorted
    else:
        node, v = [], rnd.choice([0, 20, rnd.getrandbits(16)])
        for _ in range(10):
            v = min(v + (0 if rnd.random() < 0.08 else rnd.choice([1, 10, 180, 1800, 20000, 120000, rnd.getrandbits(20)])), 0xffffffff)
            node.append(v)
    if rnd.random() < 0.3: node = [20, 200, 2000, 20000, 80000, 160000, 320000, 640000, 880000, 1000000]   # sc830 / gc2053 day bin
    strs = [rnd.choice([255, 255, 160, 0, rnd.getrandbits(8)]) for _ in range(10)]
    return node, strs

def pick_ev(node):
    r = rnd.random()
    if r < 0.5: x = rnd.choice(node) + rnd.choice([-1, 0, 1, rnd.getrandbits(8)])
    elif r < 0.8: x = rnd.getrandbits(rnd.choice([8, 16, 20, 24, 32]))
    else: x = rnd.choice([0, 0xffffffff, 0x7fffffff])
    return x & 0xffffffff

def curve():
    c, v = [], 0
    for i in range(128):
        v = min(v + rnd.getrandbits(6), 4095) if rnd.random() < 0.9 else rnd.getrandbits(16)
        c.append(v)
    return c

def setup(node, strs, cur, evs, cv, manual):
    e.heap_reset()
    p0 = e.alloc(0x26c, b"\0" * 0x26c)
    e.write(p0, struct.pack("<128H", *cv)); e.write(p0 + 0x204, struct.pack("<10I", *node)); e.write(p0 + 0x22c, bytes(strs))
    p4 = e.alloc(12, struct.pack("<3I", p0 + 0x204, p0, p0 + 0x22c))
    p8 = e.alloc(0x108, struct.pack("<I", cur) + b"\0" * 0x104)
    p12 = e.alloc(0x108, b"\0" * 0x108)
    p16 = e.alloc(8, struct.pack("<IBBH", evs, 0, manual, 0))
    ctx = e.alloc(0x18, struct.pack("<6I", p0, p4, p8, p12, p16, 0))
    e.write(GP, struct.pack("<I", ctx))
    return p8, p16

cases, oem = [], []
for n in range(a.n):
    node, strs = tables(); cur = rnd.choice([255, 160, 0, rnd.getrandbits(8), rnd.getrandbits(32)]); evs = rnd.getrandbits(32)
    kind = n % 3
    if kind == 0:   # interp_by_ev with skip / force
        ev, skip, force = pick_ev(node), rnd.choice([0, 0, 0, 1, rnd.getrandbits(32)]), rnd.choice([0, 0, 1, rnd.getrandbits(8)])
        p8, p16 = setup(node, strs, cur, evs, [0] * 128, 0)
        r = e.call("tisp_gamma_interp_by_ev", 0, 0, ev, skip, stack_args=(force,))   # force is the 5th (stack) argument, read as a byte
        assert r.stop is None, r.stop
        oem.append("%d %u %u" % (r.v0 if r.v0 < 1 << 31 else r.v0 - (1 << 32), struct.unpack("<I", e.read(p8, 4))[0], struct.unpack("<I", e.read(p16, 4))[0]))
        cases.append("I " + " ".join(map(str, node + strs + [cur, evs, ev, skip, force])))
    elif kind == 1:  # strength_transform
        s, cv = rnd.choice([255, 160, 0, 128, 127, 1, rnd.getrandbits(8), rnd.randrange(256, 300)]), curve()
        p8, _ = setup(node, strs, s, evs, cv, 0)
        r = e.call("tisp_gamma_strength_transform", 0)
        assert r.stop is None, r.stop
        oem.append(" ".join(map(str, struct.unpack("<129H", e.read(p8 + 4, 258)))))
        cases.append("L %u " % s + " ".join(map(str, cv)))
    else:            # ev_update gate + transform + armed write
        cv = curve(); ev = pick_ev(node); hi = rnd.choice([0, 0, 0, 1, 0x3ff, 0x400, rnd.getrandbits(32)])
        lo = rnd.choice([(ev << 10) & 0xffffffff, rnd.getrandbits(32)])
        man = rnd.choice([0, 0, 0, 1, 2]); freq = rnd.choice([5, 0, 1, 255, rnd.getrandbits(8)])
        fnum = rnd.choice([rnd.getrandbits(16), rnd.getrandbits(64), 0])
        saved = rnd.choice([fnum - freq - 1, fnum - freq, fnum, rnd.getrandbits(64), 0]) & (2 ** 64 - 1)
        p8, p16 = setup(node, strs, cur, evs, cv, man)
        e.write(FREQ, bytes([freq])); e.write(SAVED, struct.pack("<Q", saved))
        armed.clear()
        r = e.call("tisp_gamma_ev_update", 0, 0, lo, hi, stack_args=(fnum & 0xffffffff, fnum >> 32))
        assert r.stop is None, r.stop
        s = "%d %u %u %u" % (1 if armed else 0, struct.unpack("<I", e.read(p8, 4))[0], struct.unpack("<I", e.read(p16, 4))[0],
                             struct.unpack("<Q", e.read(SAVED, 8))[0])
        if armed: s += " " + " ".join(map(str, struct.unpack("<129H", e.read(p8 + 4, 258))))
        oem.append(s)
        cases.append("E " + " ".join(map(str, node + strs + [cur, evs, lo, hi, man, freq, fnum, saved] + cv)))

out = subprocess.run([a.host], input="\n".join(cases) + "\n", capture_output=True, text=True).stdout.strip().split("\n")
bad = 0; cnt = {"I": 0, "L": 0, "E": 0}; arm = 0
for c, o, h in zip(cases, oem, out):
    cnt[c[0]] += 1; arm += c[0] == "E" and o.startswith("1")
    if o.split() != h.split():
        bad += 1
        if bad <= 5: print("diff_gamma_ev: %s\n  OEM  %s\n  open %s" % (c[:120], o[:160], h[:160]))
if len(out) != len(cases): print("diff_gamma_ev: host gave %d lines for %d cases" % (len(out), len(cases))); bad += 1
print("diff_gamma_ev: interp %d, transform %d, ev_update %d (%d armed): %d differences" % (cnt["I"], cnt["L"], cnt["E"], arm, bad))
sys.exit(1 if bad else 0)
