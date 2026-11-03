#!/bin/bash
# T40 CT/EV event consumers (driver/t40/tx_isp_t40_ct_chain.h: tisp_ct_update TOP gating, CCM main ct/ev update,
# LSC/CLM frame cadence) built for mipsel and run against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn
# (tools/ko_emu/diff_ct_chain.py): identical memory, register writes and consumer calls, plus one-token mutations that
# must be detected (#85).  Needs T40_OEM_KO, T40_CC and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_ct_chain_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_ct/build_emu.sh" "$CC" $W/ok.o || { echo "t40_ct_chain_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_ct_chain.py" "$KO" $W/ok.o --n ${N:-1500} || { echo "t40_ct_chain_host: FAIL"; exit 1; }
mut() {
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE"/../driver/t40/tx_isp_t40_ct_chain.h "$HERE"/../driver/t40/tx_isp_t40_ccm_chain.h "$HERE"/../driver/t40/tx_isp_t40_ccm_conv.h $W/d/
	python3 - "$1" "$2" $W/d/tx_isp_t40_ct_chain.h <<'PY' || { echo "t40_ct_chain_host: mutation text not found: $1"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_ct/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_ct_chain_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_ct_chain.py" "$KO" $W/m.o --n ${NMUT:-300} > /dev/null && { echo "t40_ct_chain_host: FAIL mutation not detected: $1 => $2"; exit 1; }
}
mut 'T40_TOP_BYPASS_LSC  0x00002U' 'T40_TOP_BYPASS_LSC  0x00004U'
mut 'T40_TOP_BYPASS_CCM  0x00200U' 'T40_TOP_BYPASS_CCM  0x00100U'
mut 'T40_TOP_BYPASS_BCSH 0x08000U' 'T40_TOP_BYPASS_BCSH 0x04000U'
mut 'T40_TOP_BYPASS_CLM  0x10000U' 'T40_TOP_BYPASS_CLM  0x20000U'
mut 'T40_CT_LSC(ct, a1, fnum);' 'T40_CT_LSC(ct, 0, fnum);'
mut 'if (thr < d) {' 'if (thr <= d) {'
mut 'last < ct ? ct - last : last - ct' 'last < ct ? ct - last : ct - last'
mut 'CCM_U16(CCM_U32(ctx + 28)) = (uint16_t)ct;' 'CCM_U16(CCM_U32(ctx + 28)) = (uint16_t)ct + 1;'
mut 'hi << 22 | lo >> 10' 'hi << 21 | lo >> 10'
mut 'CCM_U32(CCM_U32(ctx + 16)) = ev;' 'CCM_U32(CCM_U32(ctx + 16)) = ev - 1;'
mut 'if (*saved + freq < fnum)' 'if (*saved + freq <= fnum)'
mut '*saved = fnum;' '*saved = fnum + 1;'
mut 'T40_LSC_INTERP(bank, ct, a3) == 0' 'T40_LSC_INTERP(bank, ct, a3) != 1'
mut 'return r;' 'return 0;'
echo "t40_ct_chain_host: ok (0 mismatches, 14 mutations detected)"
