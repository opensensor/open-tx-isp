#!/usr/bin/env python3
"""qc.py [-p PORT] [-t SECS] 'shell cmd' ...  -- run commands on the QEMU guest console (tcp), print output of each; a marker line ends a command."""
import socket, sys, time, uuid
port = 3341; tmo = 120; a = sys.argv[1:]
while a and a[0] in ('-p', '-t'):
    o = a.pop(0); v = a.pop(0)
    if o == '-p': port = int(v)
    else: tmo = float(v)
s = socket.create_connection(("127.0.0.1", port)); s.settimeout(0.5)
def rd(until=None, t=tmo):
    buf = b""; t0 = time.time()
    while time.time() - t0 < t:
        try:
            d = s.recv(65536)
            if d: buf += d
            elif not d: break
        except socket.timeout:
            if until is None and buf: break
        if until and until in buf: break
    return buf
s.sendall(b"\n"); rd(None, 1)
for c in a:
    m = "QCEND" + uuid.uuid4().hex[:8]
    s.sendall((c + "; echo " + m + "$?\n").encode())
    out = rd(m.encode() + b"0", tmo)
    if m.encode() + b"0" not in out and m.encode() not in out: print("[timeout]")
    print(out.decode(errors="replace").replace(m, "<rc>"), end="")
