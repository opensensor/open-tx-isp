#!/usr/bin/env python3
"""uenv_edit.py FLASH.bin [--off 0x50000] [--size 0x10000] [--show] [KEY=VAL ...] [--del KEY]
Edit the U-Boot environment inside a raw SPI-NOR image (CRC32 + NUL-separated KEY=VAL, no redundancy flag)."""
import sys, zlib
a = sys.argv[1:]; fl = a.pop(0); off = 0x50000; size = 0x10000; show = False; dele = []; sets = []
while a:
    x = a.pop(0)
    if x == '--off': off = int(a.pop(0), 0)
    elif x == '--size': size = int(a.pop(0), 0)
    elif x == '--show': show = True
    elif x == '--del': dele.append(a.pop(0))
    else: k, v = x.split('=', 1); sets.append((k, v))
img = bytearray(open(fl, 'rb').read())
env = img[off:off + size]
assert int.from_bytes(env[:4], 'little') == zlib.crc32(bytes(env[4:])) & 0xffffffff, 'bad env CRC'
body = bytes(env[4:]); end = body.find(b'\0\0'); items = [i for i in body[:end].split(b'\0')]
d = {}; order = []
for i in items:
    k, v = i.split(b'=', 1); d[k.decode()] = v.decode(); order.append(k.decode())
for k in dele: d.pop(k, None); order = [o for o in order if o != k]
for k, v in sets:
    if k not in d: order.append(k)
    d[k] = v
if show:
    for k in order: print(k + '=' + d[k])
    sys.exit(0)
raw = b''.join((k + '=' + d[k]).encode() + b'\0' for k in order) + b'\0'
assert len(raw) <= size - 4, 'env too large'
raw = raw + b'\xff' * (size - 4 - len(raw))
img[off:off + size] = (zlib.crc32(raw) & 0xffffffff).to_bytes(4, 'little') + raw
open(fl, 'wb').write(img)
