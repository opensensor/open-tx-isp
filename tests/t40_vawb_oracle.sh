#!/bin/bash
# T40 AWB init / EV / process chain and gain / threshold chain (driver/t40/tx_isp_t40_awb_init.inc, _main.inc, _gain.inc, built for mipsel
# by tests/t40_vawb/build_emu.sh) against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_awb_chain.py):
# 12 functions on the same random state, every byte of the reachable state, register reads / writes, events and completions compared,
# plus one-token mutations that must be detected (#84: luma thresholds by exposure value, main_ev_update tail call).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_vawb_oracle: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_vawb/build_emu.sh" "$CC" $W/ok.o || { echo "t40_vawb_oracle: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_awb_chain.py" "$KO" $W/ok.o --n ${N:-100} || { echo "t40_vawb_oracle: FAIL"; exit 1; }
NM=0; NF=0
mut() {		# mut FILE FUNCTIONS FROM TO : edit a copy of driver/t40
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE"/../driver/t40/*.inc "$HERE"/../driver/t40/*.h "$HERE"/../driver/t40/tx_isp_t40_recovered.c $W/d/
	python3 - "$3" "$4" $W/d/$1 <<'PY' || { echo "t40_vawb_oracle: mutation text not found: $3"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	T40_DRV_DIR=$W/d "$HERE/t40_vawb/build_emu.sh" "$CC" $W/m.o || { echo "t40_vawb_oracle: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_awb_chain.py" "$KO" $W/m.o --n ${NMUT:-40} --fn $2 > /dev/null && { echo "t40_vawb_oracle: FAIL mutation not detected: $3 => $4"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
G=tx_isp_t40_awb_gain.inc
mut $G set_lum_th_freq,tgain_update 'if (T40_AG_P16(11)[19] == 1)' 'if (T40_AG_P16(11)[19] == 2)'
mut $G set_lum_th_freq,tgain_update 'if (!(zones[0] < ev))' 'if (!(zones[0] <= ev))'
mut $G set_lum_th_freq,tgain_update 'if (zones[8] < ev)' 'if (zones[8] <= ev)'
mut $G set_lum_th_freq,tgain_update 'cfg[42 + k] = tbl[98 + 11 * k];' 'cfg[42 + k] = tbl[97 + 11 * k];'
mut $G set_lum_th_freq,tgain_update '(u16)(a - t40_ag_divu((a - b) * (ev - z0), d' '(u16)(a - t40_ag_divu((a - b) * (ev - z1), d'
mut $G set_lum_th_freq,tgain_update '(u16)(a + t40_ag_divu((b - a) * (ev - z0), d' '(u16)(a + t40_ag_divu((b - a) * (ev - z0 + 1), d'
# (z0 == z1 keeps knot i: equivalent, a later segment with zones[i + 1] < ev always overwrites it, as in the OEM)
mut tx_isp_t40_awb_init.inc main_ev_update 'vawb_s_tisp_awb_set_lum_th_freq((u32)(uintptr_t)ctx, 0, 0, 0, 0);
}' 'vawb_s_tisp_awb_set_lum_th_freq((u32)(uintptr_t)ctx, 1, 0, 0, 0);
}'
[ $NF = 0 ] || { echo "t40_vawb_oracle: FAIL ($NF mutations not detected)"; exit 1; }
echo "t40_vawb_oracle: ok (0 mismatches, $NM mutations detected)"
