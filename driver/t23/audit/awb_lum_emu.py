#!/usr/bin/env python3
"""Emulator check: per-interrupt AWB luminance threshold (0xb038) of the
built driver vs. the stock tx-isp-t23.ko (awb_interrupt_static ->
tiziano_awb_set_lum_th_freq -> tisp_ae_mean_update).

usage: awb_lum_emu.py <stock tx-isp-t23.ko> <built driver/t23/tx-isp-t23.o>

The built .o (not the .ko: the module link drops local symbols with -x)
runs t23x_awb_set_lum_th_freq on the objects of the lifted stock AE
(oem__ae_parameter, oem__ae_reg, oem_IspAe0WmeanParam -> oem_IspAeStatic).
Stock runs tiziano_awb_set_lum_th_freq on its own objects.  Both get the
same AE0 zone means, zone grid, _ae_reg +8 and _awb_parameter +168/+172/+176,
for a sequence of frames (wmean_new carries over).  The 0xb038 value, the
0xb000 latch before it and wmean_new must be identical frame by frame.
Exit 0 = PASS.
"""
import os, random, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from memu import Mod, CPU, u32

OEM, OURS = sys.argv[1:3]
ZOFF = 0x32ac            # stock tiziano_ae_para_addr: IspAe0WmeanParam +0x1c


class Side:
    def __init__(self, path, stock):
        m = self.m = Mod(path); c = self.c = CPU(m)
        self.stock = stock
        if stock:
            self.ae_par, self.ae_reg = m.addr('_ae_parameter'), m.addr('_ae_reg')
            self.wm, self.static = m.addr('IspAe0WmeanParam'), m.addr('IspAeStatic')
            self.wmean = m.addr('wmean_new')
            self.fn = 'tiziano_awb_set_lum_th_freq'
        else:
            self.ae_par, self.ae_reg = m.addr('oem__ae_parameter'), m.addr('oem__ae_reg')
            self.wm, self.static = m.addr('oem_IspAe0WmeanParam'), m.addr('oem_IspAeStatic')
            self.wmean = m.addr('t23_aelift_wmean_new')
            self.fn = 't23x_awb_set_lum_th_freq'
            for n, v in (('regtrace_t23_source_ae_oem', 1), ('t23_aelift_ready', 1),
                         ('t23_aelift_busy', 0), ('t23x_awb_lum_th_en', 1),
                         ('t23x_awb_lum_par_valid', 1)):
                c.w8(m.addr(n), v)
        c.w32(self.wm + 0x1c, self.static + ZOFF)

    def set(self, rows, cols, div, par, zones):
        c, m = self.c, self.m
        c.w16(self.ae_par + 4, rows)
        c.w16(self.ae_par + 12, cols)
        c.w32(self.ae_reg + 8, div)
        if self.stock:
            a = m.addr('_awb_parameter')
            for k, v in enumerate(par):
                c.w32(a + 168 + 4 * k, v)
        else:
            a = m.addr('t23x_awb_lum_par')
            for k, v in enumerate(par):
                c.w32(a + 4 * k, v)
        for i, v in enumerate(zones):
            c.w32(self.static + ZOFF + 4 * i, v)

    def run(self):
        c = self.c
        c.writes = []
        c.call(self.fn)
        return [w for w in c.writes if w[0] in (0xb000, 0xb038)], c.r32(self.wmean)


def main():
    st, us = Side(OEM, True), Side(OURS, False)
    if st.c.r32(st.wmean) != us.c.r32(us.wmean):
        print('FAIL initial wmean_new stock=%#x ours=%#x' % (st.c.r32(st.wmean), us.c.r32(us.wmean)))
        return 1
    rnd = random.Random(231)
    cases = []
    # sc2336p IQ day / night words (cap, bits 15:8, bits 23:16)
    for par in ((10, 235, 1), (10, 240, 1), (0, 0, 0), (255, 255, 255)):
        for div in (0x400, 0x200, 0x1000, 7, 0xffffffff):
            for kind in ('dark', 'mid', 'bright', 'rand', 'huge'):
                cases.append((15, 15, div, par, kind))
    cases.append((1, 1, 0x400, (10, 235, 1), 'mid'))
    cases.append((15, 4, 0x400, (10, 235, 1), 'rand'))
    fails = 0
    for n, (rows, cols, div, par, kind) in enumerate(cases):
        if kind == 'dark':
            zones = [rnd.randrange(0, 4) for _ in range(225)]
        elif kind == 'mid':
            zones = [rnd.randrange(200, 3000) for _ in range(225)]
        elif kind == 'bright':
            zones = [rnd.randrange(30000, 65536) for _ in range(225)]
        elif kind == 'huge':
            zones = [rnd.randrange(0x1000000, 0x2000000) for _ in range(225)]
        else:
            zones = [rnd.randrange(0, 1 << 20) for _ in range(225)]
        for side in (st, us):
            side.set(rows, cols, div, par, zones)
        for frame in range(3):
            a, b = st.run(), us.run()
            if a != b:
                fails += 1
                if fails <= 10:
                    print('MISMATCH case %d frame %d rows=%d cols=%d div=%#x par=%s %s: stock=%s ours=%s'
                          % (n, frame, rows, cols, div, par, kind, a, b))
    print('%s: %d cases x 3 frames, %d mismatches' % ('PASS' if not fails else 'FAIL', len(cases), fails))
    return 1 if fails else 0


sys.exit(main())
