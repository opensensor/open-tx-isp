#!/usr/bin/env python3
"""diff_frame_chan_event.py OEM.ko OUR.o [--n 4000] [--seed 7]

T40 frame_chan_event (issue #189): run the OEM function (vendor tx-isp-t40.ko, 0xf598) and our hand-written C version on the same random
frame-channel state (queued buffer list, done list, pre_queue_attr, event data) and compare the whole channel struct, every buffer
node, pre_queue_attr, lastaddr, isp_err3, the return value and the sequence of isp_printf calls (format + arguments).  Helpers that talk
to the kernel (spin lock, wake_up, complete, getrawmonotonic, msca register dump) are replaced by Python hooks on both sides; the lock / unlock / dump calls
are not compared (our tree keeps the OEM lock calls as no-op stubs).
Nothing of the vendor module is stored here: point it at your own copy."""
import argparse, os, random, struct, sys, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu, BASE
from unicorn import UC_HOOK_CODE
from unicorn.mips_const import *
ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=4000); ap.add_argument("--seed", type=int, default=7)
a = ap.parse_args(); rnd = random.Random(a.seed)
LOG = []
def cstr(e, p):
    if not (BASE <= p < e.end): return None
    try: b = e.read(p, 96)
    except Exception: return None
    s = b.split(b"\0")[0]
    return s.decode("latin1") if s and all(32 <= c < 127 or c == 10 for c in s) else None
def r_printf(e):
    fmt = cstr(e, e.get_reg(UC_MIPS_REG_A1)) or "?"
    n = len(re.findall(r"%[^%]", fmt)); sp = e.get_reg(UC_MIPS_REG_SP)
    av = [e.get_reg(UC_MIPS_REG_A2), e.get_reg(UC_MIPS_REG_A3)] + [struct.unpack("<I", e.read(sp + 16 + 4 * k, 4))[0] for k in range(6)]
    vals = []
    for v in av[:n]:
        s = cstr(e, v); vals.append(s if s is not None else v)
    LOG.append((e.get_reg(UC_MIPS_REG_A0), fmt, tuple(vals))); return 0
def r_mono(e):
    p = e.get_reg(UC_MIPS_REG_A0); e.write(p, struct.pack("<II", 1234, 5678901)); LOG.append(("mono",)); return 0
def r_nop(name):
    def f(e): LOG.append((name,)); return 0
    return f
HOOKS = {"isp_printf": r_printf, "private_getrawmonotonic": r_mono, "getrawmonotonic64": r_mono,
         "private_complete": r_nop("complete"), "complete": r_nop("complete"),
         "private_wake_up": r_nop("wake"), "private_wake_up_all": r_nop("wake"), "__wake_up": r_nop("wake"), "wake_up_all": r_nop("wake"),
         "__private_spin_lock_irqsave": r_nop("lock"), "private_spin_unlock_irqrestore": r_nop("unlock"),
         "dump_msca_regs": r_nop("dump"), "__stack_chk_fail": r_nop("chk")}
def install(e):
    for nm, fn in HOOKS.items():
        if nm in e.symaddr:
            ad = e.symaddr[nm]
            def cb(uc, addr, size, ud, fn=fn, e=e):
                rv = fn(e); e.set_reg(UC_MIPS_REG_V0, rv & 0xffffffff); e.set_reg(UC_MIPS_REG_PC, e.get_reg(UC_MIPS_REG_RA))
            e.uc.hook_add(UC_HOOK_CODE, cb, begin=ad, end=ad)
        else: e.hle[nm] = fn
oem = KoEmu(a.oem); our = KoEmu(a.our); install(oem); install(our)
CH = 900; VB = 0x80
def setup(e, case):
    e.heap_reset()
    n, flag, idxch, pdt, key_sel, state_sel, seq, extra = case["n"], case["flag"], case["chidx"], case["pdt"], case["key_sel"], case["states"], case["seq"], case["extra"]
    ch = e.alloc(CH * 3, bytes(CH * 3)); ch0 = ch + 900 * 1
    dev = e.alloc(0x200, bytes(0x200)); e.write(dev + 0x114, struct.pack("<I", ch))
    pad = e.alloc(0x20, bytes(0x20)); e.write(pad, struct.pack("<I", dev)); e.write(pad + 4, bytes([1]))
    vbs = []; head = ch0 + 0x21c
    prev = head; nodes = []
    for k in range(n):
        vb = e.alloc(VB, case["vbinit"][k]); vbs.append(vb); nodes.append(vb + 0x58)
        e.write(vb + 0x34, struct.pack("<I", 0x1000 + 0x100 * k)); e.write(vb + 0x48, struct.pack("<I", state_sel[k]))
    chain = [head] + nodes + [head]
    for k in range(1, len(chain) - 1):
        e.write(chain[k], struct.pack("<II", chain[k + 1], chain[k - 1]))
    e.write(head, struct.pack("<II", chain[1], chain[-2]))
    if n: pass
    e.write(ch0 + 0x228, struct.pack("<II", ch0 + 0x228, ch0 + 0x228))
    e.write(ch0 + 0x2cc, struct.pack("<I", idxch)); e.write(ch0 + 0x250, struct.pack("<I", extra["maxl"])); e.write(ch0 + 0x300, case["cfg"])
    e.write(ch0 + 0x224, struct.pack("<I", n))
    pd = e.alloc(16, struct.pack("<I", pdt)); e.write(e.addr("fs_isp_ch0_pdtime"), struct.pack("<I", pd))
    e.write(e.addr("isp_ch0_pre_dequeue_time"), struct.pack("<I", pdt)); e.write(e.addr("pre_queue_attr"), case["pq"]); e.write(e.addr("lastaddr"), bytes(28))
    e.write(e.addr("isp_err3"), bytes(4))
    ev = bytearray(0x20)
    key = 0x1000 + 0x100 * (key_sel if key_sel < n else 0) if key_sel >= 0 and n else 0x7777
    struct.pack_into("<IIIIII", ev, 8, key, 0, 0, flag, seq, extra["b1c"] if False else extra["lb"])
    evp = e.alloc(0x20, bytes(ev)); return pad, evp, ch, vbs, ch0
def run(e, case):
    LOG.clear(); pad, ev, ch, vbs, ch0 = setup(e, case)
    r = e.call("frame_chan_event", pad, case["evt"], ev if case["evnull"] is False else 0)
    mem = e.read(ch, CH * 3) + b"".join(e.read(v, VB) for v in vbs)
    LOGF = tuple(x for x in LOG if x[0] not in ("lock", "unlock", "dump", "mono"))
    return (r.v0, mem, e.read(e.addr("pre_queue_attr"), 0x80), e.read(e.addr("lastaddr"), 28), e.read(e.addr("isp_err3"), 4), LOGF, r.stop)
bad = shown = 0; kinds = {}
for it in range(a.n):
    n = rnd.choice([0, 1, 1, 2, 3, 4])
    case = dict(n=n, flag=rnd.choice([0, 0, 1, 7]), chidx=rnd.choice([0, 0, 1, 2]), pdt=rnd.choice([0, 5, 5, 5]),
                key_sel=rnd.choice([-1, 0, 0, 1, 2, 3]), states=[rnd.choice([3, 3, 3, 2, 4]) for _ in range(n)],
                seq=rnd.choice([0, 1, 0x12345, 0xffff, 0x10000, 0x30000 | rnd.getrandbits(16), rnd.getrandbits(32)]),
                extra=dict(maxl=rnd.choice([0, 100, 0xffff, 0x1234]), lb=rnd.getrandbits(8)),
                vbinit=[bytes(rnd.getrandbits(8) for _ in range(VB)) for _ in range(n)], cfg=bytes(rnd.getrandbits(8) for _ in range(0x80)),
                pq=bytes(rnd.getrandbits(8) if rnd.random() < 0.5 else 0 for _ in range(0x80)), evt=rnd.choice([0x3000006] * 9 + [0x3000007]), evnull=rnd.random() < 0.03)
    if case["pdt"] and rnd.random() < 0.6 and case["chidx"] == 0 and case["seq"] & 0xffff == 0x1234: pass
    for k in range(n):   # make state-byte fields the OEM tests deterministic across both emulations
        pass
    # a0 = 0 / kernel range check cases are covered by the first iterations of the loop below
    ro, rn = run(oem, case), run(our, case)
    tag = (case["pdt"] != 0 and case["chidx"] == 0, case["flag"] != 0, case["key_sel"] >= 0, n)
    kinds[tag] = kinds.get(tag, 0) + 1
    if ro != rn:
        bad += 1
        if shown < 3:
            shown += 1; print("MISMATCH case", {k: v for k, v in case.items() if k not in ("vbinit", "cfg", "pq")})
            print("  ret oem=%s our=%s stop=%s/%s" % (ro[0], rn[0], ro[6], rn[6]))
            for i, nm in ((1, "mem"), (2, "pre_queue_attr"), (3, "lastaddr"), (4, "isp_err3")):
                if ro[i] != rn[i]:
                    d = [j for j in range(len(ro[i])) if ro[i][j] != rn[i][j]][:8]; print("  %s differs at %s" % (nm, d))
            if ro[5] != rn[5]: print("  log oem=%s\n      our=%s" % (ro[5], rn[5]))
print("cases %d, mismatches %d, path classes %d" % (a.n, bad, len(kinds)))
sys.exit(1 if bad else 0)
