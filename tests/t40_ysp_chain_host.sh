#!/bin/bash
# T40 YSP chain (driver/t40/tx_isp_t40_ysp_chain.h: tisp_ysp_wdr_en pointer table, intp, noref_reg_cfg, ref_reg_cfg, reg_trig) built for mipsel
# and run against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_ysp_chain.py): identical memory, register
# writes and interpolation calls, plus one-token mutations that must be detected (#85).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_ysp_chain_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_ysp/build_emu.sh" "$CC" $W/ok.o || { echo "t40_ysp_chain_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_ysp_chain.py" "$KO" $W/ok.o --n ${N:-1000} || { echo "t40_ysp_chain_host: FAIL"; exit 1; }
# mutations of the header text: every one must be reported as a difference
NM=0
mut() {
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_ysp_chain.h" $W/d/
	python3 - "$1" "$2" $W/d/tx_isp_t40_ysp_chain.h <<'PY' || { echo "t40_ysp_chain_host: mutation text not found: $1"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_ysp/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_ysp_chain_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_ysp_chain.py" "$KO" $W/m.o --n ${NMUT:-80} > /dev/null && { echo "t40_ysp_chain_host: FAIL mutation not detected: $1 => $2"; exit 1; }
	NM=$((NM + 1))
}
mut 'wdr != 0]' 'wdr == 0]'
mut '0x000b, 0x0016' '0x000b, 0x0017'
mut 'i < 105; i++' 'i < 104; i++'
mut '{ 97, 0, 8 }' '{ 97, 0, 16 }'
mut '{ 7, 2, 16 }' '{ 7, 2, 8 }'
mut '(int32_t)gain >> 16' '(int32_t)gain >> 15'
mut 'gain & 0xffffU' 'gain & 0x7fffU'
mut '+ 0x78U, 1)' '+ 0x78U, 2)'
mut 'W(0x4, (((P(111) << 16)' 'W(0x4, (((P(111) << 17)'
mut 'YSP_CB(74, 6) << 8' 'YSP_CB(74, 6) << 9'
mut 'W(0x80, PW(472))' 'W(0x80, PW(473))'
mut 'YSP_CW(94, 28)' 'YSP_CW(94, 24)'
mut 'P(1160) << 24' 'P(1160) << 23'
mut 'YSP_CB(95, 9) << 24' 'YSP_CB(95, 9) << 25'
mut 'I(15) + (int32_t)YSP_CB(6, 1) - 0x80, 255)' 'I(15) + (int32_t)YSP_CB(6, 1) - 0x81, 255)'
mut 'I(15) + (int32_t)YSP_CB(6, 3) - 0x80, 0)' 'I(15) + (int32_t)YSP_CB(6, 3) - 0x80, 255)'
mut 'I(42 + 3 * i), 128, 0, 0)' 'I(42 + 3 * i), 127, 0, 0)'
mut '!(e < cap + 1)' '!(e < cap + 40)'
mut 'if (neg && e_floor && e < 0)' 'if (neg && e_floor && e < -100)'
mut 'r = x[3] + step;' 'r = x[3] + step + 1;'
mut '(k == 0 && !clamp0)' '(k == 0)'
mut '(neg ? (r < e ? e : r) : (e < r ? e : r))' '(neg ? (e < r ? e : r) : (r < e ? e : r))'
mut 'RAMP_IP(130, 678)' 'RAMP_IP(130, 679)'
mut 'I((is) + 1) + (int32_t)P((ps) + 1) - 0x100' 'I((is) + 1) + (int32_t)P((ps) + 1) - 0xff'
mut 'W(0x10c, ((X[3] << 18) & YSP_M18)' 'W(0x10c, ((X[3] << 17) & YSP_M18)'
mut 'W(0xf4, (X[3] << 18) | (X[2] << 2))' 'W(0xf4, (X[3] << 18) | (X[2] << 3))'
mut '(IU(91 + 2 * i) << 18)' '(IU(91 + 2 * i) << 17)'
mut '* 4, 1023) << 16)' '* 4, 1022) << 16)'
mut 'W(0x1dc, (IU(144) << 25)' 'W(0x1dc, (IU(144) << 24)'
mut 'W(0x188 + 4 * i, IW(50 + 4 * i))' 'W(0x18c + 4 * i, IW(50 + 4 * i))'
mut 'IW(98 + 4 * i)' 'IW(99 + 4 * i)'
mut 'b = 0x160; RAMP_I(136)' 'b = 0x160; RAMP_I(137)'
mut '((X[2] << 16) & 0xff0000U)' '((X[2] << 16) & 0xff00U)'
mut 'W(0x118 + 4 * i, (IU(83 + 2 * i) << 16)' 'W(0x118 + 4 * i, (IU(83 + 2 * i) << 17)'
mut 'W(0x7c, (P(1638) << 8)' 'W(0x7c, (P(1638) << 9)'
echo "t40_ysp_chain_host: ok (0 mismatches, $NM mutations detected)"
