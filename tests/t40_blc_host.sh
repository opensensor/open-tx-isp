#!/bin/bash
# T40 BLC block (driver/t40/tx_isp_t40_blc.h: ag_interp, calc_digital_gain, write_reg, ag_long/short_frame_update, ae_write_dgain, init,
# dn_params_refresh and the gain-parameter entry of the blc_lit path) built for mipsel and run against the OEM instructions of the vendor
# tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_blc.py): identical return values, tool / hard blocks, gains, Bayer bytes and register accesses
# for both channels, plus one-token mutations of the header that must be detected (#85).
# BLC is gated by the bypass flag of the sensor bin (the Eufy sc830ai bypasses it): this oracle covers the code, the effect on a camera needs a
# sensor with BLC switched on.  Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_blc_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_blc/build_emu.sh" "$CC" $W/ok.o || { echo "t40_blc_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_blc.py" "$KO" $W/ok.o --n ${N:-1000} || { echo "t40_blc_host: FAIL"; exit 1; }
NM=0; NF=0
mut() {		# mut FUNCTIONS FROM TO : edit a copy of the header
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_blc.h" $W/d/
	python3 - "$2" "$3" $W/d/tx_isp_t40_blc.h <<'PY' || { echo "t40_blc_host: mutation text not found: $2"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_blc/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_blc_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_blc.py" "$KO" $W/m.o --n ${NMUT:-60} --fn $1 > /dev/null && { echo "t40_blc_host: FAIL mutation not detected: $2 => $3"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
mut ag_interp 'if ((mx >> 11) == 1U)' 'if ((mx >> 12) == 1U)'
mut ag_interp 'return (q >> 1) + (q & 1U);' 'return (q >> 1);'
mut ag_interp '& 0xffffU;
    return (q' '& 0x7fffU;
    return (q'
mut ag_interp 'regtrace_t40_tuning_intp16(gain, tool + 58U)' 'regtrace_t40_tuning_intp16(gain, tool + 60U)'
mut ag_interp 'regtrace_t40_tuning_intp16(gain, tool + 102U)' 'regtrace_t40_tuning_intp16(gain, tool + 100U)'
mut ag_interp 'if (!(d >> 10) && !force)' 'if (!(d >> 11) && !force)'
mut ag_interp 'if (!(d >> 10) && !force)' 'if (!(d >> 10))'
mut ag_interp 'rec->v[0] = e; rec->v[1] = c; rec->v[2] = b; rec->v[3] = a;' 'rec->v[0] = e; rec->v[1] = c; rec->v[2] = a; rec->v[3] = b;'
mut ag_interp 'rec->v[0] = b; rec->v[1] = a; rec->v[2] = e; rec->v[3] = c;' 'rec->v[0] = a; rec->v[1] = b; rec->v[2] = e; rec->v[3] = c;'
mut ag_interp 'rec->v[0] = c; rec->v[1] = e; rec->v[2] = a; rec->v[3] = b;' 'rec->v[0] = c; rec->v[1] = e; rec->v[2] = b; rec->v[3] = a;'
mut ag_interp 'if (c > mx)' 'if (c > mx + 8)'
mut ag_interp 'rec->mx = (uint16_t)mx;' 'rec->mx = (uint16_t)a;'
mut calc 'if ((mx >> 18) == 1U)' 'if ((mx >> 19) == 1U)'
mut calc 'm0 >> 15); rec->g[1] = (uint16_t)(m1 >> 15)' 'm0 >> 14); rec->g[1] = (uint16_t)(m1 >> 15)'
mut calc 'rec->code = 2;' 'rec->code = 3;'
mut calc 'rec->code = 1;' 'rec->code = 2;'
mut calc '(mx >> 15) == 1U' '(mx >> 15) != 0U'
mut calc 'else if (mx >> 10)' 'else if (mx >> 11)'
mut calc 'rec->g[0] = 1024; rec->g[1] = 1024; rec->g[2] = 1024;' 'rec->g[0] = 1024; rec->g[1] = 1024; rec->g[2] = 1023;'
mut calc 'if (t2 > mx)' 'if (t2 > mx + 4096)'
mut calc 'm2 = s * rec->p[2]' 'm2 = s * rec->p[1]'
mut write_reg 'uint32_t base = (ch + 64U) << 7;' 'uint32_t base = (ch + 65U) << 7;'
mut write_reg 'idx ? 20U : 4U' 'idx ? 16U : 4U'
mut write_reg 'idx ? 48U : 36U' 'idx ? 44U : 36U'
mut write_reg '& 0x0fff0000U) | (rec->v[0] & 0xfffU)' '& 0x0fff0000U) | (rec->v[0] & 0x7ffU)'
mut write_reg '& 0x0fff0000U) | (rec->v[2] & 0xfffU)' '& 0x07ff0000U) | (rec->v[2] & 0xfffU)'
mut write_reg '& 0x7fff0000U) | (rec->g[0] & 0x7fffU)' '& 0x3fff0000U) | (rec->g[0] & 0x7fffU)'
mut write_reg '(rec->g[2] & 0x7fffU) | 0x04000000U' '(rec->g[2] & 0x7fffU) | 0x02000000U'
mut write_reg 'rec->code & 3U' 'rec->code & 1U'
mut write_reg 'if (mode < 2U)' 'if (mode < 3U)'
mut write_reg 'if (mode == 0U || mode == 2U)' 'if (mode == 0U || mode == 1U)'
mut write_reg 'system_reg_write(base, 1);' 'system_reg_write(base, 3);'
mut long 'if (!t40_blc_ag_interp(ch, 0, gain, 0)) {' 'if (!t40_blc_ag_interp(ch, 0, gain, 1)) {'
mut long 't40_blc_write_reg(ch, 0, 1);' 't40_blc_write_reg(ch, 0, 0);'
mut short 't40_blc_calc_digital_gain(ch, 1);
        t40_blc_write_reg(ch, 1, 1);' 't40_blc_calc_digital_gain(ch, 0);
        t40_blc_write_reg(ch, 1, 1);'
mut short 't40_blc_write_reg(ch, 1, 1);' 't40_blc_write_reg(ch, 1, 2);'
mut ae_write_dgain 'rec->p[2] = a4 & 0x7fffU;' 'rec->p[2] = a4 & 0xffffU;'
mut ae_write_dgain 'rec->p[1] = a3 & 0x7fffU;' 'rec->p[1] = a2 & 0x7fffU;'
mut ae_write_dgain 't40_blc_write_reg(ch, idx, 2);' 't40_blc_write_reg(ch, idx, 0);'
mut init,update 'system_reg_write(base + 32U, 0);' 'system_reg_write(base + 36U, 0);'
mut init,update 'system_reg_write(base + 16U, 0);' 'system_reg_write(base + 20U, 0);'
mut refresh,update '(uintptr_t)tparamsN[ch]' '(uintptr_t)tparamsN[0]'
mut refresh,update 'bin + 0x2350U' 'bin + 0x2351U'
mut refresh,update '(system_reg_read((ch + 34U) << 2) & 3U)' '(system_reg_read((ch + 34U) << 2) & 1U)'
mut refresh,update 'memcpy(t40_blc_hard[c][1].p, p, 12);' 'memcpy(t40_blc_hard[c][1].p, p, 8);'
mut refresh,update 't40_blc_calc_digital_gain(ch, 1);
    if (init)' 't40_blc_calc_digital_gain(ch, 0);
    if (init)'
mut update 't40_blc_again[c * 2U + 1U] = gain;' 't40_blc_again[c * 2U + 1U] = gain + 1U;'
mut update 't40_blc_ag_interp(ch, 1, t40_blc_again[c * 2U + 1U], 1);' 't40_blc_ag_interp(ch, 1, t40_blc_again[c * 2U + 1U], 0);'
[ $NF = 0 ] || { echo "t40_blc_host: FAIL ($NF mutations not detected)"; exit 1; }
echo "t40_blc_host: ok (0 mismatches, $NM mutations detected)"
