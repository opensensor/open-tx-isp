#!/usr/bin/env python3
"""diff_vic_isr.py OEM.ko OUR.o [--n 300] [--seed 5] [--oem-block vic_err] [--our-block vic_irq_cnt]

T40 isp_vic_interrupt_service_routine (issue #189 layout): run the OEM function (vendor tx-isp-t40.ko) and our compiled lifted
function (tx-isp-t40.o of driver/t40, a relocatable object with local symbols) on the same random VIC register state and compare
(1) the 75-word interrupt counter block (OEM .bss vic_err / our vic_irq_cnt), (2) the VIC device counters (s0 +0x2c0..+0x310),
(3) the register block the ISR writes back, (4) the return value.  Status words are random; the second word of each group is
restricted to bits 2/3 (bits 0/1 would call vic_mdma_irq_function*, which needs real buffer lists).
Nothing of the vendor module is stored here: point it at your own copy.
"""
import argparse, os, random, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
ap = argparse.ArgumentParser(); ap.add_argument("oem"); ap.add_argument("our")
ap.add_argument("--n", type=int, default=300); ap.add_argument("--seed", type=int, default=5)
ap.add_argument("--oem-block", default="vic_err"); ap.add_argument("--our-block", default="vic_irq_cnt")
a = ap.parse_args(); rnd = random.Random(a.seed)
HLE = {"queue_work_on": lambda e: 1, "isp_printf": lambda e: 0, "printk": lambda e: 0, "_printk": lambda e: 0, "vprintk": lambda e: 0}
oem = KoEmu(a.oem, hle=HLE); our = KoEmu(a.our, hle=dict(HLE, **{"__stack_chk_fail": lambda e: 0}))
# our lift marks the frame ring in a reserved-memory window (regtrace_fr_mark): turn the helper into `jr ra; nop`
for nm in ("regtrace_fr_mark.isra.0", "regtrace_fr_mark"):
    if nm in our.symaddr: our.write(our.addr(nm), bytes.fromhex("0800e00300000000")); break
IRQ0, IRQ1 = 0x11, 0x22
REGS = 0x30400
def setup(e, blk, group, st1, st2):
    e.heap_reset()
    regs = bytearray(REGS)
    base = (0x0, 0x10000, 0x20000)[group]
    struct.pack_into("<IIII", regs, base + 0x1e0, st1, st2, 0, 0)      # raw0, raw1, mask0, mask1 (OEM reads 1e8/1ec as masks)
    regs_a = e.alloc(REGS, regs)
    s0 = e.alloc(0x800, bytes(0x800))
    e.write(s0 + 0xe8, struct.pack("<I", regs_a))
    dev = bytearray(0x300)
    struct.pack_into("<I", dev, 0x90, IRQ0); struct.pack_into("<I", dev, 0x94, IRQ1)
    struct.pack_into("<I", dev, 0xe8, regs_a); struct.pack_into("<I", dev, 0x10c, s0)
    dev_a = e.alloc(0x300, dev)
    e.write(e.addr(blk), bytes(300))
    return dev_a, regs_a, s0
def run(e, blk, group, st1, st2):
    dev, regs, s0 = setup(e, blk, group, st1, st2)
    irq = (IRQ0, IRQ1, 0x33)[group]
    r = e.call("isp_vic_interrupt_service_routine", dev, irq)
    return (r.v0, e.read(e.addr(blk), 300), e.read(s0 + 0x2c0, 0x54), e.read(regs, REGS), r.stop)
bad = 0; shown = 0; cnt = [0] * 75
for it in range(a.n):
    for g in range(3):
        st1 = rnd.getrandbits(32) if rnd.random() < 0.7 else rnd.choice([0, 1, 2, 4, 8, 0x200, 0x80000000, 0xfffffe00, 0xffffffff])
        st1 &= ~0x10 if rnd.random() < 0.5 else ~0      # bit 4 queues work: keep both paths
        st2 = rnd.choice([0, 4, 8, 12])
        ro, rn = run(oem, a.oem_block, g, st1, st2), run(our, a.our_block, g, st1, st2)
        for i in range(75): cnt[i] += struct.unpack_from("<I", ro[1], 4 * i)[0] != 0
        if ro != rn:
            bad += 1
            if shown < 4:
                shown += 1; print("MISMATCH group %d st1=%#x st2=%#x" % (g, st1, st2))
                for k, nm in ((0, "ret"), (4, "stop")): print("  %s oem=%s our=%s" % (nm, ro[k], rn[k]))
                for k, nm, w in ((1, "counter block", 4), (2, "vic counters", 4), (3, "regs", 4)):
                    if ro[k] != rn[k]:
                        d = [i for i in range(0, len(ro[k]), 4) if ro[k][i:i+4] != rn[k][i:i+4]][:6]
                        print("  %s differs at +%s" % (nm, ",".join("%#x" % (4 * (i // 4)) for i in d)))
print("cases %d, mismatches %d; counter words hit at least once: %d/75" % (a.n * 3, bad, sum(1 for c in cnt if c)))
sys.exit(1 if bad else 0)
