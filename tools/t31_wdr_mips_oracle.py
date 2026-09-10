# SPDX-License-Identifier: GPL-2.0
"""Offline MIPS ELF oracle. No firmware code is executed on a device."""

import struct
from elftools.elf.elffile import ELFFile
from unicorn import (
    Uc,
    UC_ARCH_MIPS,
    UC_MODE_MIPS32,
    UC_MODE_LITTLE_ENDIAN,
    UC_HOOK_CODE,
)
from unicorn.mips_const import (
    UC_MIPS_REG_A0,
    UC_MIPS_REG_A1,
    UC_MIPS_REG_A2,
    UC_MIPS_REG_A3,
    UC_MIPS_REG_SP,
    UC_MIPS_REG_RA,
    UC_MIPS_REG_PC,
    UC_MIPS_REG_V0,
)


def U32(b):
    return struct.unpack("<I", b)[0]


def PACK(v):
    return struct.pack("<I", v & 0xFFFFFFFF)


class Oracle:
    def __init__(self, path):
        self.uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        self.syms = {}
        self.mmio = {}
        self.writes = []
        self.ext = {}
        self.sections = {}
        self.uc.mem_map(0x1000000, 0x1000000)
        self.uc.mem_map(0x3000000, 0x100000)
        self.uc.mem_map(0x4000000, 0x200000)
        self.stack = 0x30F0000
        self.stop = 0x30FF000
        self.heap = 0x4000000
        with open(path, "rb") as f:
            e = ELFFile(f)
            tab = e.get_section_by_name(".symtab")
            for i, s in enumerate(e.iter_sections()):
                if s["sh_flags"] & 2:
                    addr = 0x1000000 + i * 0x40000
                    self.sections[i] = addr
                    if s["sh_type"] != "SHT_NOBITS":
                        self.uc.mem_write(addr, s.data())

            def symaddr(s):
                if s["st_shndx"] == "SHN_UNDEF":
                    if s.name not in self.ext:
                        self.ext[s.name] = 0x30E0000 + len(self.ext) * 16
                    return self.ext[s.name]
                if s["st_shndx"] == "SHN_ABS":
                    return s["st_value"]
                return self.sections.get(s["st_shndx"], 0) + s["st_value"]

            for s in tab.iter_symbols():
                if s.name and (
                    s["st_shndx"] in self.sections or s["st_shndx"] == "SHN_UNDEF"
                ):
                    self.syms[s.name] = (symaddr(s), s["st_size"])
            for section in e.iter_sections():
                if (
                    section["sh_type"] != "SHT_REL"
                    or section["sh_info"] not in self.sections
                ):
                    continue
                base = self.sections[section["sh_info"]]
                pending = []
                for r in section.iter_relocations():
                    addr = base + r["r_offset"]
                    word = U32(self.uc.mem_read(addr, 4))
                    s = tab.get_symbol(r["r_info_sym"])
                    target = symaddr(s)
                    kind = r["r_info_type"]
                    if kind == 2:
                        self.uc.mem_write(addr, PACK(word + target))
                    elif kind == 4:
                        self.uc.mem_write(
                            addr,
                            PACK(
                                (word & 0xFC000000)
                                | (((word & 0x3FFFFFF) + (target >> 2)) & 0x3FFFFFF)
                            ),
                        )
                    elif kind == 5:
                        pending.append((addr, word, r["r_info_sym"]))
                    elif kind == 6:
                        low = word & 0xFFFF
                        low = low - 0x10000 if low & 0x8000 else low
                        for hiaddr, hiword, si in pending:
                            if si == r["r_info_sym"]:
                                value = ((hiword & 0xFFFF) << 16) + low + target
                                self.uc.mem_write(
                                    hiaddr,
                                    PACK(
                                        (hiword & 0xFFFF0000)
                                        | (((value + 0x8000) >> 16) & 0xFFFF)
                                    ),
                                )
                        pending = [p for p in pending if p[2] != r["r_info_sym"]]
                        self.uc.mem_write(
                            addr, PACK((word & 0xFFFF0000) | ((target + low) & 0xFFFF))
                        )
                    elif kind == 0:
                        pass
                    else:
                        raise ValueError(("relocation", section.name, kind, hex(addr)))
                if pending:
                    raise ValueError(("unpaired HI16", section.name, pending[:2]))
        self.hooks = {}
        for name in [
            "memcpy",
            "memmove",
            "memset",
            "system_reg_write",
            "system_reg_read",
            "private_dma_cache_sync",
            "printk",
        ]:
            if name in self.syms:
                self.hooks[self.syms[name][0]] = name
        for address in self.hooks:
            self.uc.hook_add(UC_HOOK_CODE, self._hook, begin=address, end=address)
        self.uc.hook_add(UC_HOOK_CODE, self._hook, begin=0x30E0000, end=0x30EFFFF)

    def _hook(self, u, address, size, unused):
        if address == self.stop:
            u.emu_stop()
            return
        name = self.hooks.get(address)
        if name:
            a, b, c = [
                u.reg_read(r) for r in [UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2]
            ]
            if name in ["memcpy", "memmove"]:
                u.mem_write(a, bytes(u.mem_read(b, c)))
                v = a
            elif name == "memset":
                u.mem_write(a, bytes([b & 255]) * c)
                v = a
            elif name == "system_reg_write":
                self.mmio[a] = b
                self.writes.append((a, b))
                v = 0
            elif name == "system_reg_read":
                v = self.mmio.get(a, 0)
            else:
                v = 0
            u.reg_write(UC_MIPS_REG_V0, v)
            u.reg_write(UC_MIPS_REG_PC, u.reg_read(UC_MIPS_REG_RA))
        elif address in self.ext.values():
            raise RuntimeError(
                "Unhandled import "
                + next(n for n, a in self.ext.items() if a == address)
            )

    def alloc(self, data):
        addr = self.heap
        self.heap += (len(data) + 15) & ~15
        self.uc.mem_write(addr, data)
        return addr

    def put(self, name, values):
        if isinstance(values, int):
            values = [values]
        self.uc.mem_write(self.syms[name][0], b"".join(PACK(v) for v in values))

    def get(self, name, count=None):
        addr, size = self.syms[name]
        count = count or size // 4
        return list(struct.unpack("<" + "I" * count, self.uc.mem_read(addr, 4 * count)))

    def call(self, name, *args):
        for r in range(2, 32):
            self.uc.reg_write(r, 0)
        self.uc.reg_write(UC_MIPS_REG_SP, self.stack)
        self.uc.reg_write(UC_MIPS_REG_RA, self.stop)
        for reg, arg in zip(
            [UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3], args
        ):
            self.uc.reg_write(reg, arg)
        for i, arg in enumerate(args[4:]):
            self.uc.mem_write(self.stack + 16 + i * 4, PACK(arg))
        self.uc.emu_start(self.syms[name][0], self.stop, count=300000000)
        if self.uc.reg_read(UC_MIPS_REG_PC) != self.stop:
            raise RuntimeError("Instruction limit " + name)
        return self.uc.reg_read(UC_MIPS_REG_V0)
