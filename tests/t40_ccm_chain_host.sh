#!/bin/bash
# T40 CCM chain (driver/t40/tx_isp_t40_ccm_chain.h: params_transmit, params_refresh, ct interpolation, cm_control, lut_parameter, ev_ct_update)
# built for mipsel and run against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_ccm_chain.py):
# identical memory and register writes, plus one-token mutations that must be detected (#85).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_ccm_chain_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_ccm/build_emu.sh" "$CC" $W/ok.o || { echo "t40_ccm_chain_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_ccm_chain.py" "$KO" $W/ok.o --n ${N:-1500} || { echo "t40_ccm_chain_host: FAIL"; exit 1; }
# mutations of the header text: every one must be reported as a difference
mut() {
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_ccm_chain.h" "$HERE/../driver/t40/tx_isp_t40_ccm_conv.h" $W/d/
	python3 - "$1" "$2" $W/d/tx_isp_t40_ccm_chain.h <<'PY' || { echo "t40_ccm_chain_host: mutation text not found: $1"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_ccm/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_ccm_chain_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_ccm_chain.py" "$KO" $W/m.o --n ${NMUT:-500} > /dev/null && { echo "t40_ccm_chain_host: FAIL mutation not detected: $1 => $2"; exit 1; }
}
mut 'a2m < c)' 'a2m <= c)'
mut 'a1 < c)' 'a1 <= c)'
mut 'a0 < c)' 'a0 <= c)'
mut 'lz == 0 : z == 2' 'lz == 1 : z == 2'
mut '>> 8) + 19595U' '>> 9) + 19595U'
mut '(int32_t)32 / (int32_t)d' '(int32_t)33 / (int32_t)d'
mut 'i < 8; i += 2' 'i < 6; i += 2'
mut 'ct_th < (int32_t)t40_ccm_absdiff' 'ct_th <= (int32_t)t40_ccm_absdiff'
mut 'manual == 1 || t40_ccm_absdiff' 'manual == 2 || t40_ccm_absdiff'
mut 'if (e1 == e0)' 'if (e1 != e0)'
mut 'CCM_U8(inter + 216) != 0' 'CCM_U8(inter + 216) == 0'
mut '(src + 0x1a0U), 36)' '(src + 0x1a0U), 32)'
mut 'CCM_U32(outer + 0x17cU + 4 * i) = 256U' 'CCM_U32(outer + 0x17cU + 4 * i) = 255U'
mut 'case 3:' 'case 5:'
mut 'v >>= 6;' 'v >>= 5;'
mut 'as[3 * r + k] * bs' 'as[3 * r + k] + bs'
echo "t40_ccm_chain_host: ok (0 mismatches, 16 mutations detected)"
