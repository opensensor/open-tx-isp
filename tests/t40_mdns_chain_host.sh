#!/bin/bash
# T40 MDNS chain (driver/t40/tx_isp_t40_mdns_chain.h: ramps, pointer table, intp, func_en, reg_cfg, start/trig, refresh wrappers) built for mipsel
# and run against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_mdns_chain.py): identical memory, register
# writes, interpolation calls, ramps, last gain, plus one-token mutations that must be detected (#85).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_mdns_chain_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_mdns/build_emu.sh" "$CC" $W/ok.o || { echo "t40_mdns_chain_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_mdns_chain.py" "$KO" $W/ok.o --n ${N:-60} || { echo "t40_mdns_chain_host: FAIL"; exit 1; }
# mutations of the header text: every one must be reported as a difference by the functions it can reach
NM=0
mut() {		# mut FUNCTIONS FROM TO
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_mdns_chain.h" $W/d/
	python3 - "$2" "$3" $W/d/tx_isp_t40_mdns_chain.h <<'PY' || { echo "t40_mdns_chain_host: mutation text not found: $2"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_mdns/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_mdns_chain_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_mdns_chain.py" "$KO" $W/m.o --n ${NMUT:-60} --fn $1 > /dev/null && { echo "t40_mdns_chain_host: FAIL mutation not detected: $2 => $3"; exit 1; }
	NM=$((NM + 1))
}
mut wdr_en 'if (!wdr) {' 'if (wdr) {'
mut wdr_en '10, 21, 32, 109' '10, 21, 33, 109'
mut wdr_en 'par + 1518 + i * 11' 'par + 1518 + i * 12'
mut wdr_en 'MDNS_U32(comb + 4 * 83) = (uint32_t)(par + 2387)' 'MDNS_U32(comb + 4 * 83) = (uint32_t)(par + 2388)'
mut wdr_en 'MDNS_U32(comb + 4 * 27) = (uint32_t)(par + 825)' 'MDNS_U32(comb + 4 * 27) = (uint32_t)(par + 826)'
mut intp '0x8000, 0x8001, 0x8002, 0x002b' '0x8000, 0x8001, 0x8002, 0x002c'
mut intp '0x0036, 0x0041' '0x0036, 0x0042'
mut intp '(s & 0x8000) ?' '(s & 0x4000) ?'
mut intp 'gain & 0xffff' 'gain & 0x7fff'
mut intp '(int32_t)gain >> 16' '(int32_t)gain >> 15'
mut func_en 'nib - 1 < 2' 'nib - 1 < 1'
mut func_en 'nib == 1 ? 0xfffffffeU : 0xfcU' 'nib == 1 ? 0xfffffffeU : 0xfdU'
mut func_en '(MDNS_U8(par + 1) << 4) & 0x10' '(MDNS_U8(par + 1) << 3) & 0x10'
mut func_en '(MDNS_U8(par + 8) << 24) & 0x1000000' '(MDNS_U8(par + 8) << 23) & 0x1000000'
mut func_en 'rb + 0x24, v' 'rb + 0x28, v'
mut start 'return t40_mdns_reg_write(((ch + 0x1e) << 11) + 8, 1)' 'return t40_mdns_reg_write(((ch + 0x1e) << 11) + 8, 2)'
mut reg_trig '+ 4, 1);' '+ 4, 3);'
mut smp 'to = 7;' 'to = 6;'
mut smp 'first = (sel >= 0 && sel <= 5) ? sel : 6' 'first = (sel >= 0 && sel <= 4) ? sel : 6'
mut smp 'int32_t k = sel < 7 ? sel : 6' 'int32_t k = sel < 5 ? sel : 6'
mut smp 'diff > 0 ? !(y[i] < y7) : !(y7 < y[i])' 'diff > 0 ? (y[i] < y7) : !(y7 < y[i])'
mut dif ', 8192);' ', 4096);'
mut dif '*cut = k;' '*cut = sel;'
mut dif 'sel != 0xff ? sel : 254' 'sel != 0xff ? sel : 253'
mut dif 'shifted = diff << 13' 'shifted = diff << 12'
mut dif 'yend < y[i]' 'yend > y[i]'
mut reg_cfg '(w & 0xf) != 0' '(w & 0x1f) != 0'
mut reg_cfg ') >> 1);
	W(0x100' ') >> 2);
	W(0x100'
mut reg_cfg '(I(7) << 8) & 0x300' '(I(7) << 8) & 0x700'
mut reg_cfg '| 0x14)' '| 0x15)'
mut reg_cfg 'I(132) < 129 ? I(132) : 128' 'I(132) < 130 ? I(132) : 128'
mut reg_cfg 'hi1 += 8;' 'hi1 += 7;'
mut reg_cfg 't40_mdns_div(1024, (int32_t)(hi2 - lo2))' 't40_mdns_div(2048, (int32_t)(hi2 - lo2))'
mut reg_cfg 'W(0xc, (P(9) & 0x3f) | 0x40)' 'W(0xc, (P(9) & 0x3f) | 0x41)'
mut reg_cfg '(uint32_t)(y)[7] << 24' '(uint32_t)(y)[7] << 23'
mut reg_cfg 'W(0x2a4, IU32(128))' 'W(0x2a4, IU32(129))'
mut reg_cfg '((uint32_t)(x / 2) & 0xff)' '((uint32_t)(x / 3) & 0xff)'
mut par_refresh '< thresh)' '<= thresh)'
mut par_refresh '(void)t40_mdns_start(c->ch);' ''
mut refresh 'par_refresh(c, gain, 256, memopt)' 'par_refresh(c, gain, 255, memopt)'
mut refresh 'all_reg_refresh(c, *c->gain_old)' 'all_reg_refresh(c, gain)'
mut params 'MDNS_PARAM_OFF 0x1105cU' 'MDNS_PARAM_OFF 0x1105dU'
mut params 'MDNS_PAR_SIZE);' '(MDNS_PAR_SIZE - 1));'
echo "t40_mdns_chain_host: ok (0 mismatches, $NM mutations detected)"
