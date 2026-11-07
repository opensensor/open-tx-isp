#!/bin/bash
# T23 per-interrupt AWB luminance threshold 0xb038 (driver/t23/tx_isp_t23_awb_runtime.inc t23x_awb_set_lum_th_freq,
# tx_isp_t23_ae_oem_glue.inc t23_aelift_mean_update) vs the vendor tiziano_awb_set_lum_th_freq / tisp_ae_mean_update,
# both in the T23 MIPS emulator (driver/t23/audit/awb_lum_emu.py, Lu-Fi/openimp#231 L3).
# Needs T23_OEM_KO (vendor tx-isp-t23.ko) and T23_OBJ (driver/t23/tx-isp-t23.o of a built module, not the .ko:
# the module link drops local symbols), else SKIP.  A mutated wmean start value must be detected.
HERE=$(cd "$(dirname "$0")" && pwd); PY=$HERE/../driver/t23/audit/awb_lum_emu.py
KO=${T23_OEM_KO:-}; OBJ=${T23_OBJ:-$HERE/../driver/t23/tx-isp-t23.o}
if [ ! -r "$KO" ] || [ ! -r "$OBJ" ]; then
	echo "t23_awb_lum_oracle: SKIP (T23_OEM_KO / T23_OBJ missing)"
	[ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0
fi
python3 -I "$PY" "$KO" "$OBJ" || { echo "t23_awb_lum_oracle: FAIL"; exit 1; }
W=$(mktemp -d); trap 'rm -rf "$W"' EXIT
# mutation: the stock .data start value of wmean_new (0x400) replaced in the built object
python3 -I - "$OBJ" "$W/m.o" <<'PY' || { echo "t23_awb_lum_oracle: FAIL (mutation not built)"; exit 1; }
import struct, sys
d = bytearray(open(sys.argv[1], 'rb').read())
shoff, = struct.unpack_from('<I', d, 0x20); ent, num, stri = struct.unpack_from('<HHH', d, 0x2e)
sh = [struct.unpack_from('<IIIIIIIIII', d, shoff + i * ent) for i in range(num)]
st = [s for s in sh if s[1] == 2][0]; strt = sh[st[6]]
for k in range(st[5] // 16):
    n, val, size, info, oth, shndx = struct.unpack_from('<IIIBBH', d, st[4] + k * 16)
    o = strt[4] + n
    if d[o:d.index(b'\0', o)] == b't23_aelift_wmean_new':
        struct.pack_into('<I', d, sh[shndx][4] + val, 0x401)
        open(sys.argv[2], 'wb').write(d); sys.exit(0)
sys.exit(1)
PY
python3 -I "$PY" "$KO" "$W/m.o" >/dev/null && { echo "t23_awb_lum_oracle: FAIL (wmean mutation not detected)"; exit 1; }
echo "t23_awb_lum_oracle: ok (0xb038 and wmean_new == vendor, mutation detected)"
