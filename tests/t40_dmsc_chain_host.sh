#!/bin/bash
# T40 DMSC chain (driver/t40/tx_isp_t40_dmsc_chain.h: tisp_dmsc_wdr_en pointer table, intp, noref_reg_cfg, ref_reg_cfg, reg_trig) built for mipsel
# and run against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_dmsc_chain.py): identical memory, register
# writes and interpolation calls, plus one-token mutations that must be detected (#85).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_dmsc_chain_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_dmsc/build_emu.sh" "$CC" $W/ok.o || { echo "t40_dmsc_chain_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_dmsc_chain.py" "$KO" $W/ok.o --n ${N:-300} || { echo "t40_dmsc_chain_host: FAIL"; exit 1; }
# mutations of the header text: every one must be reported as a difference
NM=0
mut() {
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_dmsc_chain.h" $W/d/
	python3 - "$1" "$2" $W/d/tx_isp_t40_dmsc_chain.h <<'PY' || { echo "t40_dmsc_chain_host: mutation text not found: $1"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_dmsc/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_dmsc_chain_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_dmsc_chain.py" "$KO" $W/m.o --n ${NMUT:-150} > /dev/null && { echo "t40_dmsc_chain_host: FAIL mutation not detected: $1 => $2"; exit 1; }
	NM=$((NM + 1))
}
mut 'wdr != 0]' 'wdr == 0]'
mut '0x0032, 0x003d' '0x0032, 0x003e'
mut '0x0780, 0x078e' '0x0780, 0x078f'
mut '{ 2, 0x002, 0x004 }' '{ 3, 0x002, 0x004 }'
mut '{ 1, 0x01a, 0x124 }' '{ 0, 0x01a, 0x124 }'
mut '{ 0, 0x001, 0x027 }' '{ 0, 0x001, 0x028 }'
mut 'i < 232; i++' 'i < 231; i++'
mut 'DMSC_U8(DMSC_U32(comb) + 1) == 0' 'DMSC_U8(DMSC_U32(comb) + 1) != 0'
mut 'DMSC_U16(par + 0x27e) = 0' 'DMSC_U16(par + 0x27e) = 1'
mut 'rb + 0x6c,' 'rb + 0x68,'
mut 'DMSC_BE16P(par + 0x577, par + 0x578)' 'DMSC_BE16P(par + 0x578, par + 0x577)'
mut 'DMSC_U8(intp + 0x89) = 8;' 'DMSC_U8(intp + 0x89) = 9;'
mut '(f[1] << 6)' '(f[1] << 7)'
mut 'DMSC_U8(intp + 0xa9 + 2 * i) << 20' 'DMSC_U8(intp + 0xa9 + 2 * i) << 21'
mut '+ 0x19c, 1)' '+ 0x19c, 2)'
mut 'DMSC_U8(DMSC_U32(comb) + 4) == 0' 'DMSC_U8(DMSC_U32(comb) + 5) == 0'
mut '(uint32_t)DMSC_U8((a) + 3) << 24' '(uint32_t)DMSC_U8((a) + 3) << 23'
mut 'DMSC_U32U(intp + 0xf8 + 4 * i)' 'DMSC_U32U(intp + 0xf8 + 2 * i)'
echo "t40_dmsc_chain_host: ok (0 mismatches, $NM mutations detected)"
