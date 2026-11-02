#!/usr/bin/env python3
"""wdr_log2_oracle.py OEM_KO OBJDUMP HOST_BIN: run OEM tisp_wdr_log2 (vendor tx-isp-t40.ko) under unicorn and the C of the open
driver (HOST_BIN prints "a0 result" per input line) on the same inputs; exit 1 on any difference."""
import subprocess, sys
from unicorn import Uc, UC_ARCH_MIPS, UC_MODE_MIPS32, UC_MODE_LITTLE_ENDIAN
from unicorn.mips_const import UC_MIPS_REG_A0, UC_MIPS_REG_RA, UC_MIPS_REG_V0, UC_MIPS_REG_SP
ko, objdump, host = sys.argv[1:4]
dis = subprocess.run([objdump, '-d', '--no-show-raw-insn', ko], capture_output=True, text=True).stdout.splitlines()
start = None; code = []
raw = subprocess.run([objdump, '-d', ko, '--disassemble=tisp_wdr_log2'], capture_output=True, text=True).stdout.splitlines()
for l in raw:
    p = l.split()
    if l.endswith('<tisp_wdr_log2>:'): start = int(p[0], 16)
    elif start is not None and len(p) >= 2 and p[0].endswith(':') and len(p[1]) == 8:
        code.append(int(p[1], 16))
if start is None or not code: print('wdr_log2_oracle: tisp_wdr_log2 not found in the OEM module'); sys.exit(2)
blob = b''.join(w.to_bytes(4, 'little') for w in code)
BASE, RET = 0x10000, 0x20000
inputs = list(range(0, 70000)) + [0x7fffffff, 0x80000000, 0xffffffff, 0xfffffffe, 0x10000, 0x8000, 0x8001, 0x40000, 0x12345678]
inputs += [(1 << k) + d for k in range(32) for d in (-1, 0, 1)]
inputs = [x & 0xffffffff for x in inputs]
mu = Uc(UC_ARCH_MIPS, UC_MODE_MIPS32 + UC_MODE_LITTLE_ENDIAN)
mu.mem_map(BASE, 0x20000); mu.mem_write(BASE, blob); mu.mem_write(RET, b'\0' * 8)
oem = {}
for x in inputs:
    mu.reg_write(UC_MIPS_REG_A0, x); mu.reg_write(UC_MIPS_REG_RA, RET); mu.reg_write(UC_MIPS_REG_SP, BASE + 0x18000)
    mu.emu_start(BASE, RET, count=10000)
    oem[x] = mu.reg_read(UC_MIPS_REG_V0) & 0xffffffff
out = subprocess.run([host], input='\n'.join(str(x) for x in inputs), capture_output=True, text=True).stdout.split('\n')
bad = 0
for l in out:
    if not l.strip(): continue
    a, r = (int(v) for v in l.split())
    if oem[a] != (r & 0xffffffff):
        bad += 1
        if bad <= 5: print(f'wdr_log2_oracle: a0={a:#x} OEM {oem[a]} open {r}')
print(f'wdr_log2_oracle: {len(inputs)} inputs, {bad} differences (OEM 0x{start:x}, {len(code)} instructions)')
sys.exit(1 if bad else 0)
