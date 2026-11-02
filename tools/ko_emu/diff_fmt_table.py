#!/usr/bin/env python3
"""diff_fmt_table.py OEM.ko OUR.o -- byte compare of the OEM isp_output_fmt (.data, 9 x 44 bytes) with our t40_isp_output_fmt (#189)."""
import os, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from ko_emu import KoEmu
oem = KoEmu(sys.argv[1], hooks=False); our = KoEmu(sys.argv[2], hooks=False)
a = oem.read(oem.addr("isp_output_fmt"), 396); b = our.read(our.addr("t40_isp_output_fmt"), 396)
print("isp_output_fmt: %d bytes, %s" % (len(a), "identical" if a == b else "DIFFERENT at %s" % [i for i in range(396) if a[i] != b[i]][:8]))
sys.exit(0 if a == b else 1)
