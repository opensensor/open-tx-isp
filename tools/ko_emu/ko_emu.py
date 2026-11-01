#!/usr/bin/env python3
"""ko_emu.py -- run single functions of a MIPS32 little-endian kernel module (.ko, ET_REL) in Unicorn.

The module is laid out section by section in a flat address space, REL relocations are applied
(R_MIPS_32/26/HI16/LO16/PC16), calls to undefined symbols stop at a stub (or run a Python hook).
Used to compare OEM functions (vendor tx-isp-t40.ko) with our C versions: same inputs, then
compare return values and every memory write.  No vendor data is stored here; point it at your own .ko.

    from ko_emu import KoEmu
    e = KoEmu("/path/to/tx-isp-t40.ko")
    r = e.call("fix_point_div_32", 8, 1000, 7)        # -> Result(v0, v1, writes, insns)
    buf = e.alloc(64, b"\\x01\\x00" * 32)               # guest buffer for pointer args
    r = e.call("ispint_adr_16", 100, xs, ys, 8)
    e.read(buf, 64)
"""
import struct, sys
from collections import namedtuple
from elftools.elf.elffile import ELFFile
from elftools.elf.relocation import RelocationSection
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN, UC_HOOK_MEM_WRITE, UC_HOOK_CODE, UC_HOOK_MEM_READ_UNMAPPED, UC_HOOK_MEM_WRITE_UNMAPPED, UcError
from unicorn.mips_const import *

R_MIPS_32, R_MIPS_26, R_MIPS_HI16, R_MIPS_LO16, R_MIPS_PC16 = 2, 4, 5, 6, 10
Result = namedtuple("Result", "v0 v1 writes insns stop")
BASE, STACK_TOP, STACK_SZ, HEAP, HEAP_SZ, STUB = 0x10000000, 0x7f000000, 0x100000, 0x60000000, 0x1000000, 0x70000000
PAGE = 0x1000
def pg(x): return (x + PAGE - 1) & ~(PAGE - 1)

M32 = 0xffffffff
def _q(e): return (e.get_reg(UC_MIPS_REG_A0) | e.get_reg(UC_MIPS_REG_A1) << 32)
def _s64(x): return x - (1 << 64) if x >> 63 else x
def _s(x): return x - (1 << 32) if x >> 31 else x
def _ret64(v): v &= (1 << 64) - 1; return (v & M32, v >> 32)
def _arg64b(e): return e.get_reg(UC_MIPS_REG_A2) | e.get_reg(UC_MIPS_REG_A3) << 32
# libgcc / libc helpers an OEM function may call; value = fn(emu) -> v0 or (v0, v1)
DEFAULT_HLE = {
    "__ashldi3": lambda e: _ret64(_q(e) << (e.get_reg(UC_MIPS_REG_A2) & 63)),
    "__lshrdi3": lambda e: _ret64(_q(e) >> (e.get_reg(UC_MIPS_REG_A2) & 63)),
    "__ashrdi3": lambda e: _ret64(_s64(_q(e)) >> (e.get_reg(UC_MIPS_REG_A2) & 63)),
    "__muldi3": lambda e: _ret64(_q(e) * _arg64b(e)),
    "__udivdi3": lambda e: _ret64(_q(e) // _arg64b(e) if _arg64b(e) else 0),
    "__umoddi3": lambda e: _ret64(_q(e) % _arg64b(e) if _arg64b(e) else 0),
    "__divdi3": lambda e: _ret64(int(_s64(_q(e)) / _s64(_arg64b(e))) if _arg64b(e) else 0),
    "memcpy": lambda e: (e.write(e.get_reg(UC_MIPS_REG_A0), e.read(e.get_reg(UC_MIPS_REG_A1), e.get_reg(UC_MIPS_REG_A2))), e.get_reg(UC_MIPS_REG_A0))[1],
    "memset": lambda e: (e.write(e.get_reg(UC_MIPS_REG_A0), bytes([e.get_reg(UC_MIPS_REG_A1) & 255]) * e.get_reg(UC_MIPS_REG_A2)), e.get_reg(UC_MIPS_REG_A0))[1],
}

class KoEmu:
    def __init__(self, path, hle=None, max_insns=5_000_000, hooks=True):
        self.f = open(path, "rb"); self.elf = ELFFile(self.f)
        self.uc = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 | UC_MODE_LITTLE_ENDIAN)
        self.hle = dict(DEFAULT_HLE); self.hle.update(hle or {})            # undefined symbol name -> python callable(emu) -> v0
        self.max_insns = max_insns; self.watch_module_data = False; self.watch = []
        self.secbase = {}; self.symaddr = {}; self.stubs = {}; self.stubname = {}
        self._layout(); self._symbols(); self._relocate(); self._map_stubs()
        self.uc.mem_map(STACK_TOP - STACK_SZ, STACK_SZ); self.uc.mem_map(HEAP, HEAP_SZ); self.heap_ptr = HEAP
        self.writes = []; self.insns = 0
        # NOTE: no UC_HOOK_MEM_WRITE.  With a write hook Unicorn 2.1 re-executes stores in branch delay
        # slots (loop counters advance twice).  Writes are found by diffing memory snapshots instead.
        if hooks:
            self.uc.hook_add(UC_HOOK_CODE, self._on_code)
            self.uc.hook_add(UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED, self._on_unmapped)
        self.unmapped = None

    # ---- loading ----
    def _layout(self):
        addr = BASE
        for i, s in enumerate(self.elf.iter_sections()):
            if not (s["sh_flags"] & 2) or s["sh_size"] == 0:   # SHF_ALLOC
                continue
            a = max(s["sh_addralign"], 16); addr = (addr + a - 1) & ~(a - 1)
            self.secbase[i] = addr; self.secname = getattr(self, "secname", {}); self.secname[i] = s.name
            addr += s["sh_size"]
        self.end = pg(addr + 0x1000)
        self.uc.mem_map(BASE, self.end - BASE)
        for i, s in enumerate(self.elf.iter_sections()):
            if i in self.secbase and s["sh_type"] != 8:        # not NOBITS
                self.uc.mem_write(self.secbase[i], s.data())

    def _symbols(self):
        st = self.elf.get_section_by_name(".symtab"); self.syms = []
        for idx, sym in enumerate(st.iter_symbols()):
            sh = sym["st_shndx"]
            if sh == "SHN_UNDEF": a = None
            elif sh == "SHN_ABS": a = sym["st_value"]
            elif sh == "SHN_COMMON": a = None
            else: a = self.secbase.get(sh, None); a = None if a is None else a + sym["st_value"]
            if sym["st_info"]["type"] == "STT_SECTION" and isinstance(sh, int): a = self.secbase.get(sh)
            self.syms.append((sym.name, a))
            if sym.name and a is not None and sym["st_info"]["type"] != "STT_SECTION": self.symaddr.setdefault(sym.name, a)

    def _stub(self, name):
        if name not in self.stubs:
            self.stubs[name] = 0x70000000 + 0x10 * (len(self.stubs) + 1); self.stubname[self.stubs[name]] = name
        return self.stubs[name]

    def _relocate(self):
        for sec in self.elf.iter_sections():
            if not isinstance(sec, RelocationSection): continue
            tgt = sec["sh_info"]
            if tgt not in self.secbase: continue
            base = self.secbase[tgt]; pend = []
            for r in sec.iter_relocations():
                t = r["r_info_type"]; off = base + r["r_offset"]
                name, S = self.syms[r["r_info_sym"]]
                if S is None: S = self._stub(name) if name else 0
                w = struct.unpack("<I", self.uc.mem_read(off, 4))[0]
                if t == R_MIPS_32: v = (w + S) & 0xffffffff
                elif t == R_MIPS_26: v = (w & 0xfc000000) | ((((w & 0x3ffffff) << 2) + S >> 2) & 0x3ffffff)
                elif t == R_MIPS_HI16: pend.append((off, S)); continue
                elif t == R_MIPS_LO16:
                    lo = w & 0xffff; slo = lo - 0x10000 if lo & 0x8000 else lo
                    # resolve pending HI16 relocations of the same symbol
                    for hoff, hS in pend:
                        hw = struct.unpack("<I", self.uc.mem_read(hoff, 4))[0]
                        ahl = ((hw & 0xffff) << 16) + slo; val = (ahl + hS) & 0xffffffff
                        self.uc.mem_write(hoff, struct.pack("<I", (hw & 0xffff0000) | (((val + 0x8000) >> 16) & 0xffff)))
                    pend = []
                    v = (w & 0xffff0000) | (((slo + S) & 0xffffffff) & 0xffff)
                elif t == R_MIPS_PC16: continue
                elif t == 0: continue
                else: raise RuntimeError("unhandled reloc type %d at %#x" % (t, off))
                self.uc.mem_write(off, struct.pack("<I", v))
    def _map_stubs(self):
        # stub page: address 0x70000000 is the return sentinel, 0x70000010.. one slot per undefined symbol
        self.uc.mem_map(STUB, pg(0x10 * (len(self.stubs) + 2)))

    # ---- helpers ----
    def addr(self, name): return self.symaddr[name]
    def heap_reset(self): self.heap_ptr = HEAP
    def alloc(self, n, data=None, align=16):
        self.heap_ptr = (self.heap_ptr + align - 1) & ~(align - 1); a = self.heap_ptr; self.heap_ptr += n
        if data is not None: self.uc.mem_write(a, bytes(data))
        return a
    def read(self, a, n): return bytes(self.uc.mem_read(a, n))
    def write(self, a, d): self.uc.mem_write(a, bytes(d))
    def where(self, a):
        """map an address back to  section+offset  /  nearest symbol"""
        for i, b in self.secbase.items():
            sz = self.elf.get_section(i)["sh_size"]
            if b <= a < b + sz: return "%s+%#x" % (self.secname[i], a - b)
        if STACK_TOP - STACK_SZ <= a < STACK_TOP: return "stack-%#x" % (STACK_TOP - a)
        if HEAP <= a < HEAP + HEAP_SZ: return "heap+%#x" % (a - HEAP)
        return "%#x" % a

    # ---- hooks ----
    def _on_write(self, uc, access, addr, size, value, ud):
        self.writes.append((addr, size, value & ((1 << (8 * size)) - 1)))
    def _on_code(self, uc, addr, size, ud):
        self.insns += 1
        if addr in self.stubname:
            name = self.stubname[addr]; self.stop = name
            h = self.hle.get(name)
            if h is None: uc.emu_stop(); return
            rv = h(self); rv = rv if isinstance(rv, tuple) else (rv, 0)
            self.set_reg(UC_MIPS_REG_V0, rv[0] & 0xffffffff); self.set_reg(UC_MIPS_REG_V1, rv[1] & 0xffffffff); self.set_reg(UC_MIPS_REG_PC, self.get_reg(UC_MIPS_REG_RA)); self.stop = None
            return
        if self.insns > self.max_insns: self.stop = "max_insns"; uc.emu_stop()
    def _on_unmapped(self, uc, access, addr, size, value, ud):
        self.unmapped = (access, addr); self.stop = "unmapped %#x" % addr; return False
    def get_reg(self, r): return self.uc.reg_read(r)
    def set_reg(self, r, v): self.uc.reg_write(r, v)

    def _regions(self):
        r = []
        if self.watch_module_data:      # .data/.bss of the module: slow (~200 KB per call), off by default
            for i, b in self.secbase.items():
                sh = self.elf.get_section(i)
                if sh["sh_flags"] & 1: r.append((b, sh["sh_size"]))      # SHF_WRITE
        r.extend(self.watch)            # extra (addr, len) ranges
        r.append((STACK_TOP - 0x2000, 0x2000)); r.append((HEAP, max(self.heap_ptr - HEAP, 16)))
        return r
    def call(self, name_or_addr, *args, stack_args=(), sp_off=0):
        pc = self.symaddr[name_or_addr] if isinstance(name_or_addr, str) else name_or_addr
        sentinel = STUB
        sp = STACK_TOP - 0x1000 - sp_off
        for k, v in enumerate(stack_args): self.uc.mem_write(sp + 16 + 4 * k, struct.pack("<I", v & 0xffffffff))
        for r in range(UC_MIPS_REG_0, UC_MIPS_REG_31 + 1): self.uc.reg_write(r, 0)
        for r, v in zip((UC_MIPS_REG_A0, UC_MIPS_REG_A1, UC_MIPS_REG_A2, UC_MIPS_REG_A3), args): self.set_reg(r, v & 0xffffffff)
        self.set_reg(UC_MIPS_REG_SP, sp); self.set_reg(UC_MIPS_REG_RA, sentinel); self.set_reg(UC_MIPS_REG_T9, pc)
        self.writes = []; self.insns = 0; self.stop = None; self.unmapped = None
        regions = self._regions(); before = [bytes(self.uc.mem_read(a, n)) for a, n in regions]
        try:
            self.uc.emu_start(pc, sentinel, count=self.max_insns)
        except UcError as ex:
            self.stop = self.stop or str(ex)
        for (a, n), old in zip(regions, before):
            new = bytes(self.uc.mem_read(a, n)); i = 0
            while i < n:
                if old[i] != new[i]:
                    j = i
                    while j < n and old[j] != new[j]: j += 1
                    self.writes.append((a + i, j - i, int.from_bytes(new[i:j], "little"))); i = j
                else: i += 1
        return Result(self.get_reg(UC_MIPS_REG_V0), self.get_reg(UC_MIPS_REG_V1), list(self.writes), self.insns, self.stop)

if __name__ == "__main__":
    e = KoEmu(sys.argv[1]); fn = sys.argv[2]; a = [int(x, 0) for x in sys.argv[3:]]
    r = e.call(fn, *a); print("v0=%#x v1=%#x insns=%d stop=%s" % (r.v0, r.v1, r.insns, r.stop))
    for w in r.writes[:40]: print("  write %s size %d = %#x" % (e.where(w[0]), w[1], w[2]))
