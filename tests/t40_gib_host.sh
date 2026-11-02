#!/bin/bash
# T40 GIB block (hand-written C of driver/t40/tx_isp_t40_recovered.c, built for mipsel by tests/t40_gib/build_emu.sh) against the OEM instructions
# of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_gib.py): identical return values, parameter blocks, gain / IR state and register
# writes, plus one-token mutations of the source that must be detected (#85).  The first run of this oracle found the swapped DEIR LUT
# base (main 0x50140, second 0x50170) of tisp_gib_write_reg.
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_gib_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_gib/build_emu.sh" "$CC" $W/ok.o || { echo "t40_gib_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_gib.py" "$KO" $W/ok.o --n ${N:-150} || { echo "t40_gib_host: FAIL"; exit 1; }
SRC="$HERE/../driver/t40/tx_isp_t40_recovered.c"; NM=0; NF=0
mut() {		# mut FUNCTIONS FROM TO : edit the GIB block of a copy of the driver source
	python3 - "$2" "$3" "$SRC" $W/src.c <<'PY' || { echo "t40_gib_host: mutation text not found: $2"; exit 1; }
import sys
a, b, src, dst = sys.argv[1:5]; t = open(src).read(); i = t.index("static uint32_t t40_gib_AG[2]"); j = t.index("/* OEM 0x36adc", i)
blk = t[i:j]
if a not in blk: sys.exit(1)
open(dst, "w").write(t[:i] + blk.replace(a, b, 1) + t[j:])
PY
	"$HERE/t40_gib/build_emu.sh" "$CC" $W/m.o $W/src.c || { echo "t40_gib_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_gib.py" "$KO" $W/m.o --n ${NMUT:-120} --fn $1 > $W/m.out 2>&1
	grep -q '^MISMATCH' $W/m.out || { echo "t40_gib_host: FAIL mutation not detected: $2 => $3"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
mut interp_by_gain,a_gian_update 'if (idx >= 10)' 'if (idx >= 9)'
mut interp_by_gain 'm = d * frac;' 'm = d * (frac + 1);'
mut interp_by_gain '(m >> 15) & 1U' '(m >> 14) & 1U'
mut interp_by_gain '(!(d >> 10) && !force)' '(!(d >> 11) && !force)'
mut interp_by_gain 't + 40 + 22 * k' 't + 40 + 21 * k'
mut interp_by_gain 'if (b >= 20)' 'if (b >= 19)'
mut interp_by_gain '(m >> (3 * k)) & 7U' '(m >> (3 * k)) & 3U'
mut interp_by_gain '0x4688, 0x4053' '0x4688, 0x4054'
mut interp_by_gain 'src < 5 ?' 'src < 4 ?'
mut tool_2_real 'T40_GIB_U16(r, 14 + 2 * i) = T40_GIB_U16(t, 24 + 2 * i)' 'T40_GIB_U16(r, 14 + 2 * i) = T40_GIB_U16(t, 26 + 2 * i)'
mut tool_2_real 'r[26] = (uint8_t)T40_GIB_U16(t, 8)' 'r[26] = (uint8_t)T40_GIB_U16(t, 10)'
mut tool_2_real 'for (i = 0; i < 4; i++)
		r[i] = t[i];' 'for (i = 0; i < 3; i++)
		r[i] = t[i];'
mut self_gain '(mx >> 11) == 1' '(mx >> 11) == 2'
mut self_gain '0x2000000 / den' '0x2000000 / (den + 1)'
mut self_gain '(sg >> 1) + (sg & 1U)' '(sg >> 1)'
mut self_gain 'T40_GIB_U16(r, 28) = (uint16_t)mx' 'T40_GIB_U16(r, 28) = (uint16_t)(mx + 1)'
mut calc_digital_gain 'sc[k] = p[k] >> 12' 'sc[k] = p[k] >> 13'
mut calc_digital_gain 't40_gib_ir_mode[s ? 1 : 0] == 1 && sc[3] > mx' 't40_gib_ir_mode[s ? 1 : 0] == 2 && sc[3] > mx'
mut calc_digital_gain 'sh = 15; bsft = 3;' 'sh = 15; bsft = 2;'
mut calc_digital_gain '(mx >> 16) == 1' '(mx >> 16) == 2'
mut calc_digital_gain 'else if (mx >> 10)' 'else if (mx >> 11)'
mut calc_digital_gain 'T40_GIB_U16(r, 48 + 2 * k) = 1024' 'T40_GIB_U16(r, 48 + 2 * k) = 1023'
mut calc_digital_gain 'r[27] = bsft' 'r[27] = bsft & 1'
mut interp_by_ir,ir_update 'C[4] = { 188, 254, 320, 782 }' 'C[4] = { 188, 254, 320, 783 }'
mut interp_by_ir 'B[4] = { 386, 452, 518, 812 }' 'B[4] = { 386, 452, 519, 812 }'
mut interp_by_ir 'A[4] = { 584, 650, 716, 842 }' 'A[4] = { 584, 650, 716, 841 }'
mut interp_by_ir 'if (t40_gib_ir_mode[i] == 0)' 'if (t40_gib_ir_mode[i] == 1)'
mut interp_by_ir 'if (!d && !force)' 'if (!d)'
mut interp_by_ir 'else if (t152 < ir)' 'else if (t152 <= ir)'
mut interp_by_ir 'memcpy(r + 188, t + m2, 66)' 'memcpy(r + 188, t + m2, 65)'
mut interp_by_ir 'memcpy(r + 254, t + prm, 30)' 'memcpy(r + 254, t + prm, 28)'
mut interp_by_ir 'T40_GIB_S16(t, up[3] + 2 * i) * w' 'T40_GIB_U16(t, up[3] + 2 * i) * w'
mut interp_by_ir 'for (i = 0; i < 33; i++)' 'for (i = 0; i < 32; i++)'
mut write_reg 'd = s ? 0x50170U : 0x50140U' 'd = s ? 0x50140U : 0x50170U'
mut write_reg '<< 8) & 0x100U' '<< 8) & 0x300U'
mut write_reg '<< 12) & 0x1000U' '<< 12) & 0x3000U'
mut write_reg 'system_reg_write(base + 60, r[27] & 3U)' 'system_reg_write(base + 60, r[27] & 1U)'
mut write_reg 'system_reg_write(base + 48, T40_GIB_U16(r, 4) & 0xfffU)' 'system_reg_write(base + 48, T40_GIB_U16(r, 4) & 0x7ffU)'
mut write_reg 'system_reg_write(base + 40, t40_gib_pair(r, 272, 262, 0xfff))' 'system_reg_write(base + 40, t40_gib_pair(r, 272, 264, 0xfff))'
mut write_reg 'system_reg_write(base + 64, 1)' 'system_reg_write(base + 64, 3)'
mut write_reg 'T40_GIB_U16(p, 134) << 12' 'T40_GIB_U16(p, 136) << 12'
mut write_reg '0x1f0102' '0x1f0103'
mut write_reg 'if (mode == 0 || mode == 3)' 'if (mode == 0 || mode == 4)'
mut a_gian_update 'tisp_gib_write_reg(s, 3);' 'tisp_gib_write_reg(s, 2);'
mut a_gian_update 'tisp_gib_blc_value_to_self_gain(s);
	tisp_gib_write_reg(s, 3)' 'tisp_gib_write_reg(s, 3)'
mut ir_update 'tisp_gib_write_reg(s, 4)' 'tisp_gib_write_reg(s, 3)'
mut dn_params_refresh 'memcpy(t, bin + 0xd610, 872)' 'memcpy(t, bin + 0xd610, 871)'
mut dn_params_refresh 't40_gib_ir_mode[s ? 1 : 0] = t40_gib_bayer(s) >= 4' 't40_gib_ir_mode[s ? 1 : 0] = t40_gib_bayer(s) >= 5'
mut dn_params_refresh 'tisp_gib_calc_digital_gain(s);
	if (t40_gib_ir_mode[i])' 'if (t40_gib_ir_mode[i])'
mut dn_params_refresh 'tisp_gib_interp_by_gain(s, t40_gib_AG[i], 1)' 'tisp_gib_interp_by_gain(s, t40_gib_AG[i], 0)'
[ $NF = 0 ] || { echo "t40_gib_host: FAIL ($NF mutations not detected)"; exit 1; }
echo "t40_gib_host: ok (0 mismatches, $NM mutations detected)"
