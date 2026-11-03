#!/usr/bin/env python3
"""oem_data_by_symbol.py OEM.ko OUT.bin

The generated OEM init (vct_init_gen.inc) addresses 26 objects of the OEM .data by their offsets in the
module it was generated from (factory Eufy T8416 tx-isp-t40.ko, .data 0x2e640 = 190016 bytes).  Other
vendor builds (thingino vendor image 189632, Ingenic SDK 1.3.1 images 189600 / 189616) hold the same objects
at other offsets.  This script writes a 190016-byte image with every one of those objects copied by symbol
name from OEM.ko to its generation offset (the rest stays zero), so tests/t40_vct_host.sh runs with any
vendor module that has a symbol table.  The colour-chain functions themselves are instruction-identical
in the factory and the thingino vendor build (tests/README.oracles.md).  Nothing of the vendor module is
stored in this repository: only names and offsets.
"""
import sys
from elftools.elf.elffile import ELFFile

SIZE = 0x2e640
# name -> offset in the .data of the generation module (sizes come from OEM.ko)
OBJ = {
    "as32BT709LimitedMinvMatrix": 183112, "as32BT709LimitedMMatrix": 183148, "au16BT709LimitedClip2": 183184,
    "au16BT709LimitedClip1": 183192, "au16BT709LimitedClip0": 183200, "au16BT709LimitedOffsetYUVy": 183208,
    "as32BT709FullMinvMatrix": 183212, "as32BT709FullMMatrix": 183248, "au16BT709FullClip2": 183284,
    "au16BT709FullClip1": 183292, "au16BT709FullClip0": 183300, "au16BT709FullOffsetYUVy": 183308,
    "as32BT601LimitedMinvMatrix": 183312, "as32BT601LimitedMMatrix": 183348, "au16BT601LimitedClip2": 183384,
    "au16BT601LimitedClip1": 183392, "au16BT601LimitedClip0": 183400, "au16BT601LimitedOffsetYUVy": 183408,
    "as32BT601FullMinvMatrix": 183412, "as32BT601FullMMatrix": 183448, "au16BT601FullClip2": 183484,
    "au16BT601FullClip1": 183492, "au16BT601FullClip0": 183500, "au16BT601FullOffsetYUVy": 183508,
    "stMainBcshInterOri": 183972, "stMainCcmInterOri": 184796,
}


def main():
    with open(sys.argv[1], "rb") as f:
        elf = ELFFile(f)
        data = elf.get_section_by_name(".data")
        if data is None:
            sys.exit("no .data in %s" % sys.argv[1])
        dsec = elf.get_section_index(".data")
        raw = data.data()
        found = {}
        for sym in elf.get_section_by_name(".symtab").iter_symbols():
            if sym.name in OBJ and sym["st_shndx"] == dsec:
                found[sym.name] = (sym["st_value"], sym["st_size"])
    missing = sorted(set(OBJ) - set(found))
    if missing:
        sys.exit("OEM module lacks %s" % ", ".join(missing))
    out = bytearray(SIZE)
    for name, off in OBJ.items():
        a, n = found[name]
        out[off:off + n] = raw[a:a + n]
    with open(sys.argv[2], "wb") as f:
        f.write(out)


if __name__ == "__main__":
    main()
