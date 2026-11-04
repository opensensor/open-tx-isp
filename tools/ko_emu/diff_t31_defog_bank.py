#!/usr/bin/env python3
"""diff_t31_defog_bank.py OEM.ko TX_ISP_TUNING.c BIN [BIN...]   (Unicorn oracle, T31)

Runs the vendor tiziano_defog_params_refresh() of tx-isp-t31.ko in Unicorn with the day and the night block of each T31
tuning bin in the vendor active bank (last 0x137f0 bytes of `tparams`) and compares every defog table the vendor produced with
bin[bank offset : +len], where offset and length come from defog_bank_items[] / defog_bank_lut_items[] of our
driver/t31/tx_isp_tuning.c (the table that tiziano_defog_load_bank() copies).  The vendor symbol of each C array is
found by name (defog_x -> defog_x or param_defog_x).  Also checks: lengths equal the vendor symbol sizes, and the
table covers every table the vendor copies (29 items + 7 LUT items for rgbra == 1).
With OEM.ko = "-" only the static checks run (no vendor module, no Unicorn): the items lie inside the 0x137f0 byte bank,
do not overlap, and their lengths equal the declared array sizes.
Exit 0 = all equal.  Nothing of the vendor module is stored here.
"""
import os, re, struct, sys
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

HDR, BS = 0x18, 0x137f0
oem_path, src_path, bins = sys.argv[1], sys.argv[2], sys.argv[3:]
src = open(src_path).read()

def table(name):
    m = re.search(r"%s\[\] = \{(.*?)\n\};" % name, src, re.S)
    assert m, name
    return [(a, int(o, 16)) for a, o in re.findall(r"DEFOG_BANK\((\w+),\s*(0x[0-9a-f]+)\)", m.group(1))]

main_t, lut_t = table("defog_bank_items"), table("defog_bank_lut_items")
rg = int(re.search(r"TISP_DEFOG_BANK_RGBRA\s+(0x[0-9a-f]+)", src).group(1), 16)
assert len(main_t) == 29 and len(lut_t) == 7, (len(main_t), len(lut_t))

csize = {n: int(sz, 16) for n, sz in re.findall(r"static uint8_t (\w+)\[(0x[0-9a-f]+)\]", src)}
end = int(re.search(r"TISP_DEFOG_BANK_END\s+(0x[0-9a-f]+)", src).group(1), 16)
spans = sorted((off, off + csize[n], n) for n, off in main_t + lut_t)
sbad = 0
for (a0, a1, n0), (b0, b1, n1) in zip(spans, spans[1:]):
    if a1 > b0: print("OVERLAP %s/%s" % (n0, n1)); sbad += 1
if spans[-1][1] != end or end > BS: print("END %#x != table end %#x or beyond bank" % (end, spans[-1][1])); sbad += 1
if sbad or oem_path == "-":
    print("static: FAIL %d" % sbad if sbad else "static: OK (%d items, end %#x < %#x)" % (len(spans), end, BS))
    sys.exit(1 if sbad else 0)

from ko_emu import KoEmu

def hle():
    def memcpy(e):
        from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_V0
        d, s, n = e.get_reg(UC_MIPS_REG_A0), e.get_reg(UC_MIPS_REG_A1), e.get_reg(UC_MIPS_REG_A2)
        e.write(d, e.read(s, n)); return d
    return {"memcpy": memcpy}

emu = KoEmu(oem_path, hle=hle(), max_insns=2_000_000)
def vsym(n):
    for c in (n, "param_" + n):
        if c in emu.symaddr: return emu.symaddr[c]
    raise SystemExit("no vendor symbol for " + n)
def vlen(n):
    for c in (n, "param_" + n):
        for s in emu.elf.get_section_by_name(".symtab").iter_symbols():
            if s.name == c and s["st_size"]: return s["st_size"]
    raise SystemExit("no size for " + n)

bad = 0
for n, off in main_t + lut_t:
    if csize[n] != vlen(n):
        print("SIZE MISMATCH %s: ours %#x vendor %#x" % (n, csize[n], vlen(n))); bad += 1

# `tparams` (0x249b0 bytes) ends with the active 0x137f0 byte bank (0x94fc0 in tisp_day_or_night_s_ctrl, memcpy'd from tparams_day/night)
tp = emu.symaddr["tparams"] + 0x249b0 - BS
for path in bins:
    d = open(path, "rb").read()
    if len(d) < HDR + 2 * BS: print("SKIP short", path); continue
    for tag, base in (("day", HDR), ("night", 0x13808)):
        bank = d[base:base + BS]
        emu.write(tp, bank)
        for n, off in main_t + lut_t:
            emu.write(vsym(n), bytes(csize[n]))
        r = emu.call("tiziano_defog_params_refresh")
        rgbra = struct.unpack_from("<I", bank, rg)[0]
        if r.stop or (rgbra > 1) != (r.v0 == 0xffffffff):
            print("vendor run problem", path, tag, r.stop, hex(r.v0)); bad += 1; continue
        if rgbra > 1:
            print("%s %s: rgbra %d (vendor returns -1, our loader falls back to built-in)" % (os.path.basename(path), tag, rgbra)); continue
        items = main_t + (lut_t if rgbra == 1 else [])
        for n, off in items:
            got = emu.read(vsym(n), csize[n]); want = bank[off:off + csize[n]]
            if got != want:
                print("DIFF %s %s %s off %#x" % (os.path.basename(path), tag, n, off)); bad += 1
    print("%s: checked" % os.path.basename(path))
print("FAIL %d" % bad if bad else "OK: %d bins, vendor refresh == bank table" % len(bins))
sys.exit(1 if bad else 0)
