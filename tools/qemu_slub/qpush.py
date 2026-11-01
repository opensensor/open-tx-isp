#!/usr/bin/env python3
"""qpush.py [-p PORT] LOCAL REMOTE -- copy a file into the QEMU guest over the console (gzip+base64, md5 verified, retries)."""
import socket, sys, time, gzip, base64, hashlib
port = 3341; a = sys.argv[1:]
if a[0] == '-p': a.pop(0); port = int(a.pop(0))
src, dst = a
data = open(src, 'rb').read(); md5 = hashlib.md5(data).hexdigest()
b64 = base64.encodebytes(gzip.compress(data, 9)).decode().splitlines()
s = socket.create_connection(("127.0.0.1", port)); s.settimeout(0.2)
def drain(t=0.3):
    b = b""; t0 = time.time()
    while time.time() - t0 < t:
        try: b += s.recv(65536)
        except socket.timeout: pass
    return b
def run(c, wait=15, tag=None):
    s.sendall((c + "\n").encode()); b = b""; t0 = time.time()
    while time.time() - t0 < wait:
        try: b += s.recv(65536)
        except socket.timeout: pass
        if tag and tag.encode() in b: break
    return b.decode(errors='replace')
drain(1); s.sendall(b"\n"); drain(0.5)
for attempt in range(4):
    run("stty -echo; rm -f /tmp/qp.b64", 3)
    s.sendall(b"cat > /tmp/qp.b64\n"); time.sleep(0.2)
    for i in range(0, len(b64), 40):
        s.sendall(("\n".join(b64[i:i+40]) + "\n").encode()); time.sleep(0.15 if len(b64) > 400 else 0.05); drain(0.0)
    s.sendall(b"\x04"); time.sleep(0.5); drain(0.5)
    out = run("base64 -d /tmp/qp.b64 | gunzip > %s && md5sum %s; echo QPDONE$?" % (dst, dst), 60, "QPDONE")
    if md5 in out: print("ok", dst, md5); sys.exit(0)
    print("retry", attempt, out[-200:])
sys.exit(1)
