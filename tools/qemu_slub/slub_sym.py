#!/usr/bin/env python3
"""slub_sym.py DMESG.txt --vmlinux VMLINUX [--module BASE=FILE.ko ...] [--cross PREFIX]
Resolve raw kernel / module text addresses in a dmesg dump from a kernel without KALLSYMS
(slub_debug 'Allocated in 0x...', 'Freed in 0x...', '[<8001d67c>] 0x8001d67c' stack lines).
BASE is the module load address from /proc/modules inside the guest (e.g. 0xc0360000)."""
import re, subprocess, sys, argparse, bisect
ap = argparse.ArgumentParser(); ap.add_argument("dmesg"); ap.add_argument("--vmlinux", required=True)
ap.add_argument("--module", action="append", default=[]); ap.add_argument("--cross", default="mipsel-linux-")
a = ap.parse_args()
def nm(f):
    out = subprocess.check_output([a.cross + "nm", "-n", f], text=True)
    return sorted((int(l.split()[0], 16), l.split()[2]) for l in out.splitlines() if len(l.split()) == 3 and l.split()[1] in "tTwW")
def a2l(f, addr):
    return subprocess.check_output([a.cross + "addr2line", "-f", "-e", f, hex(addr)], text=True).split("\n")[:2]
mods = []
for m in a.module:
    b, f = m.split("=", 1); mods.append((int(b, 0), f, nm(f)))
kern = None
def sym(addr):
    for base, f, syms in mods:
        if base <= addr < base + 0x400000:
            off = addr - base; i = bisect.bisect_right([s[0] for s in syms], off) - 1
            return "%s+%#x [%s]" % (syms[i][1], off - syms[i][0], f.split("/")[-1])
    if addr >= 0x80000000 and addr < 0xa0000000:
        fn, loc = a2l(a.vmlinux, addr); return "%s (%s)" % (fn, loc)
    return "?"
for line in open(a.dmesg, errors="replace"):
    line = line.rstrip("\n")
    hit = re.findall(r"(?:Allocated in|Freed in) (0x[0-9a-f]{8})|\[<([0-9a-f]{8})>\]", line)
    if hit:
        for h in hit:
            ad = int(h[0] or h[1], 16); print("%s    => %s" % (line, sym(ad)))
    elif re.search(r"BUG |INFO:|Redzone|Poison|Padding", line): print(line)
