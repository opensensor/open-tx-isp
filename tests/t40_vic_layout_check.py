#!/usr/bin/env python3
"""T40 #189 layout class: the two OEM .bss/.data objects the lifted code used to reach through stray anchors.

1. isp_vic_interrupt_service_routine: the 75 VIC interrupt counters (OEM .bss vic_err, 3 instances x 25) are the real object
   vic_irq_cnt[3][25].  Every counter is bumped exactly once, no `&isp_memopt` / `&vic_err` anchor is left in the function, each
   bump sits behind the OEM status-bit test (derived from the OEM instruction stream, `andi` for bits 9..15, `ext` for bits
   16..30 which the lift had dropped, `bgez` for bit 31, second status word bits 2/3 for the DMA ovf counters), the status
   registers are integers (a typed pointer scaled `v0 + 1` by 4) and every exit returns 1 like the OEM.
2. ispcore_core_ops_init reads the 44-byte output format descriptors from the real table t40_isp_output_fmt (OEM isp_output_fmt,
   9 entries: name[32], id, bits per pixel, 0), not from `&sclk_name - 7384`.
Run with the vendor module against the compiled functions: tools/ko_emu/diff_vic_isr.py and diff_fmt_table.py.
Usage: t40_vic_layout_check.py [driver.c]"""
import os, re, sys
src = sys.argv[1] if len(sys.argv) > 1 else os.path.join(os.path.dirname(os.path.abspath(__file__)), "../driver/t40/tx_isp_t40_recovered.c")
text = open(src, encoding="utf-8", errors="replace").read()
bad = []

def func(name_sig):
    m = re.search(r"^" + re.escape(name_sig) + r"\n\{", text, re.M)
    if not m:
        bad.append("%s not found" % name_sig); return None
    i = m.start(); end = text.index("\n}\n", m.end()) + 2
    return text[i:end]

isr = func("int64_t isp_vic_interrupt_service_routine(uintptr_t a0, uint32_t a1)")
if isr:
    for stray in ("isp_memopt", "&vic_err", "sclk_name"):
        if stray in isr: bad.append("ISR still reaches the stray anchor %s" % stray)
    if re.search(r"^\s*uintptr_t\s*\*\s*[vV][01]\b", isr, re.M): bad.append("ISR: v0/v1 are typed pointers again (counter steps would be scaled by 4)")
    lines = isr.split("\n"); seen = {}
    for i, l in enumerate(lines):
        m = re.match(r"\s+vic_irq_cnt\[(\d)\]\[(\d+)\]\+\+;", l)
        if not m: continue
        g, b = int(m.group(1)), int(m.group(2))
        if (g, b) in seen: bad.append("counter [%d][%d] bumped twice" % (g, b))
        seen[(g, b)] = i
        ctx = "\n".join(lines[max(0, i - 14):i])
        if b <= 6:        # status bit 9..15: andi mask
            want = [r"&\s*%d;" % (1 << (b + 9))]
        elif b <= 21:     # bit 16..30: ext v0,v0,bit,1
            want = [r">> %d\) & 1;" % (b + 9)]
        elif b == 22:     # bit 31: bgez
            want = [r"\(int32_t\)v0 >= 0;"]
        elif b == 23: want = [r"&\s*4;"]      # second word: dma arb trans done ovf
        else:         want = [r"&\s*8;"]      # dma chid ovf
        # b 23/24 of group 1 sit behind the shared tail (the lift put the two bumps after the printf); accept the nearest test
        last = None
        for mm in re.finditer(r"(&\s*\d+;|>> \d+\) & 1;|\(int32_t\)v0 >= 0;)", ctx): last = mm.group(1)
        if last is None or not re.search(want[0], last):
            # the b == 22 test is on the `int _bc_v0_N = ` line and b 23/24 follow their mask line; look at the whole context
            if not re.search(want[0], ctx): bad.append("counter [%d][%d]: no matching OEM status-bit test (%s) before it" % (g, b, want[0]))
    miss = [(g, b) for g in range(3) for b in range(25) if (g, b) not in seen]
    if miss: bad.append("counters never bumped: %s" % miss)
    for lab in ("0x534", "0x538"):
        mm = re.search(r"isp_vic_interrupt_service_routine" + lab + r":\n(?:\s*/\*[^\n]*\*/\n)*\s*return ([^;]+);", isr)
        if not mm or mm.group(1).strip() != "1": bad.append("ISR exit %s does not return 1 (OEM: every exit returns 1)" % lab)

core = func("int64_t ispcore_core_ops_init(uintptr_t a0, uintptr_t a1)")
if core:
    if re.search(r"v1 = v1 - 7384;", core): bad.append("ispcore_core_ops_init still reads the format table through &sclk_name - 7384")
    if "t40_isp_output_fmt" not in core: bad.append("ispcore_core_ops_init does not use t40_isp_output_fmt")
OEM_FMT = [("YUV 4:2:0 semi planar, Y/CbCr", 0, 12), ("YUV 4:2:0 semi planar, Y/CrCb", 1, 12), ("YUV 4:2:2 semi planar, Y/CrCb", 2, 16),
           ("YUV 4:2:2 semi planar, Y/CbCr", 3, 16), ("YUV 4:2:2 semi planar, CrCb/Y", 4, 16), ("YUV 4:2:2 semi planar, CbCr/Y", 5, 16),
           ("RAW8, BGGR", 6, 8), ("RAW16, BGGR", 7, 16), ("undetermine", 0, 0)]
m = re.search(r"static const struct t40_isp_output_fmt t40_isp_output_fmt\[(\d+)\][^=]*=\s*\{(.*?)\n\};", text, re.S)
if not m: bad.append("t40_isp_output_fmt not found")
else:
    ents = re.findall(r'\{\s*"([^"]*)",\s*(\d+),\s*(\d+),\s*0\s*\}', m.group(2))
    got = [(n, int(i), int(b)) for n, i, b in ents]
    if m.group(1) != "9" or got != OEM_FMT: bad.append("t40_isp_output_fmt differs from the OEM isp_output_fmt: %s" % got)
    if not re.search(r"struct t40_isp_output_fmt \{\s*char name\[32\];\s*uint32_t id;\s*uint32_t bits;\s*uint32_t reserved;\s*\};", text):
        bad.append("struct t40_isp_output_fmt is not the OEM 44 byte entry")
if bad:
    print("t40_vic_layout_check: FAIL"); [print("  " + b) for b in bad]; sys.exit(1)
print("t40_vic_layout_check: ok (75 VIC counters, 9 format descriptors)")
