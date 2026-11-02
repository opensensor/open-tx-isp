#!/bin/bash
# T40 YDNS functions (hand-written C of driver/t40/tx_isp_t40_recovered.c, built for mipsel by tests/t40_ydns/build_emu.sh) against the OEM
# instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_ydns.py): identical register writes, interpolation calls, parameter /
# pointer / interpolated blocks, flags and remembered gain, plus one-token mutations of the source that must be detected (#85).
# The first run of this oracle found two differences: the high bit of the gain (OEM sra, C used a logical shift) and tisp_ydns_intp_reg_refresh
# (OEM tail-jumps to all_reg_refresh, the C did nothing).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_ydns_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_ydns/build_emu.sh" "$CC" $W/ok.o || { echo "t40_ydns_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_ydns.py" "$KO" $W/ok.o --n ${N:-1000} || { echo "t40_ydns_host: FAIL"; exit 1; }
SRC="$HERE/../driver/t40/tx_isp_t40_recovered.c"; NM=0; NF=0
mut() {		# mut FUNCTIONS FROM TO : edit the YDNS block of a copy of the driver source
	python3 - "$2" "$3" "$SRC" $W/src.c <<'PY' || { echo "t40_ydns_host: mutation text not found: $2"; exit 1; }
import sys
a, b, src, dst = sys.argv[1:5]; t = open(src).read(); i = t.index("int32_t tisp_ydns_reg_cfg(uint32_t a0)\n{"); j = t.index("original=tisp_ydns_main_init", i)
blk = t[i:j]
if a not in blk: sys.exit(1)
open(dst, "w").write(t[:i] + blk.replace(a, b, 1) + t[j:])
PY
	"$HERE/t40_ydns/build_emu.sh" "$CC" $W/m.o $W/src.c || { echo "t40_ydns_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_ydns.py" "$KO" $W/m.o --n ${NMUT:-40} --fn $1 > $W/m.out 2>&1
	grep -q '^MISMATCH' $W/m.out || { echo "t40_ydns_host: FAIL mutation not detected: $2 => $3"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
mut reg_cfg,all_reg 'base + 0x08, par[0]' 'base + 0x0c, par[0]'
mut reg_cfg '((par[2] << 4) & 0x10U)' '((par[2] << 5) & 0x10U)'
mut reg_cfg '((w[2] << 12) & 0x3000U)' '((w[2] << 12) & 0x2000U)'
mut reg_cfg 'w[3] | (w[4] << 8)' 'w[2] | (w[4] << 8)'
mut reg_cfg 'base + 0x48' 'base + 0x4c'
mut reg_cfg '((uint32_t)w[13] << 16)' '((uint32_t)w[13] << 17)'
mut reg_trig ' + 4, 1)' ' + 4, 2)'
mut reg_trig '(arg1 + 0x100) << 8' '(arg1 + 0x100) << 9'
mut intp '(void *)(par + 135)' '(void *)(par + 136)'
mut intp '(void *)(par + 146)' '(void *)(par + 145)'
mut intp 'comb[12 + i]);' 'comb[13 + i]);'
mut intp 'i < 12; i++)
        out[i] = (uint8_t)tisp_simple_intp_int8(hi, lo,' 'i < 11; i++)
        out[i] = (uint8_t)tisp_simple_intp_int8(hi, lo,'
mut intp 'out[14 + i]' 'out[15 + i]'
mut intp '(int32_t)a1 >> 16' '(int32_t)(a1 >> 16)'
mut wdr_en 'par + 3 + 11 * i' 'par + 4 + 11 * i'
mut wdr_en 'par + 157 + 11 * i' 'par + 158 + 11 * i'
mut wdr_en 'comb[19] = (uint32_t)(uintptr_t)(par + 234)' 'comb[19] = (uint32_t)(uintptr_t)(par + 235)'
mut wdr_en 'par + 245 + 11 * i' 'par + 246 + 11 * i'
mut wdr_en 'par + 377 + 11 * i' 'par + 378 + 11 * i'
mut wdr_en 'par + 454' 'par + 455'
mut wdr_en 'if (arg2 == 0)' 'if (arg2 != 0)'
mut wdr_en 'arg1 < 2)' 'arg1 < 1)'
mut par_refresh,refresh 'if (delta < a2)' 'if (delta <= a2)'
mut par_refresh,refresh 'regtrace_ydns_gain_old[a0] = a1;' 'regtrace_ydns_gain_old[a0] = a1 + 1;'
mut par_refresh 'cached != 0xffffffffU' 'cached != 0xfffffffeU'
mut params '0x119baU' '0x119bbU'
mut params 'nbuf + 0x119baU), 465)' 'nbuf + 0x119baU), 464)'
mut params 'arg1 ? sec_ydns : main_ydns' 'arg1 ? main_ydns : sec_ydns'
mut refresh 'tisp_ydns_par_refresh(a0, a1, 256)' 'tisp_ydns_par_refresh(a0, a1, 255)'
mut refresh 'tisp_ydns_all_reg_refresh(a0, regtrace_ydns_gain_old[a0])' 'tisp_ydns_all_reg_refresh(a0, a1)'
mut all_reg 'return tisp_ydns_reg_trig((int32_t)a0)' 'return 0'
mut all_reg '(void)tisp_ydns_intp(a0, a1);' ''
mut intp_reg 'return tisp_ydns_all_reg_refresh(a0, a1);
}' 'return 0;
}'
[ $NF -eq 0 ] || exit 1
echo "t40_ydns_host: ok (0 mismatches, $NM mutations detected)"
