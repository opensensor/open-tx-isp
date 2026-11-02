#!/bin/bash
# T40 LSC chain (hand-written C of driver/t40/tx_isp_t40_lsc_lit.inc: valid_judge, interp_by_ct / interp_by_gain, write_reg, real_write_lut, built for
# mipsel by tests/t40_lsc/build_emu.sh) against the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_lsc.py): identical
# return values, tool / real blocks, last gain / CT / zone and register writes, plus one-token mutations of the source that must be detected (#85).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_lsc_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_lsc/build_emu.sh" "$CC" $W/ok.o || { echo "t40_lsc_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_lsc.py" "$KO" $W/ok.o --n ${N:-120} || { echo "t40_lsc_host: FAIL"; exit 1; }
SRC="$HERE/../driver/t40/tx_isp_t40_lsc_lit.inc"; NM=0; NF=0
mut() {		# mut FUNCTIONS FROM TO : edit a copy of the LSC source
	python3 - "$2" "$3" "$SRC" $W/src.inc <<'PY' || { echo "t40_lsc_host: mutation text not found: $2"; exit 1; }
import sys
a, b, src, dst = sys.argv[1:5]; t = open(src).read()
if a not in t: sys.exit(1)
open(dst, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_lsc/build_emu.sh" "$CC" $W/m.o $W/src.inc || { echo "t40_lsc_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_lsc.py" "$KO" $W/m.o --n ${NMUT:-80} --fn $1 > $W/m.out 2>&1
	grep -q '^MISMATCH' $W/m.out || { echo "t40_lsc_host: FAIL mutation not detected: $2 => $3"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
mut interp_by_gain 'if (!(delta >> 8) && !force)' 'if (!(delta >> 9) && !force)'
mut interp_by_gain 'idx = gain >> 16;' 'idx = gain >> 15;'
mut interp_by_gain 'frac = gain & 0xffff;' 'frac = gain & 0x7fff;'
mut interp_by_gain 'b->last_gain = gain;' 'b->last_gain = gain + 1;'
mut interp_by_gain 'lsc_lit_intp_u16(idx, frac, lsc_lit_gain_tab(b, 1))' 'lsc_lit_intp_u16(idx, frac, lsc_lit_gain_tab(b, 0))'
mut interp_by_gain 'if (idx >= 10)' 'if (idx >= 9)'
mut interp_by_gain 'adj = (adj >> 16) + ((adj >> 15) & 1);' 'adj = (adj >> 16) + ((adj >> 14) & 1);'
mut interp_by_gain 'return (lo < hi) ? ((lo + adj) & 0xffff) : ((lo - adj) & 0xffff);' 'return (lo < hi) ? ((lo + adj) & 0xffff) : ((lo - adj - 1) & 0xffff);'
mut interp_by_gain 'b->wdr ? LSC_LIT_T_GAIN0_WDR : LSC_LIT_T_GAIN0_LIN' 'b->wdr ? LSC_LIT_T_GAIN0_LIN : LSC_LIT_T_GAIN0_WDR'
mut valid_judge '0x28, 0x30, 0x40, 0x50' '0x28, 0x30, 0x40, 0x51'
mut valid_judge 'if (!found_h && !found_w)' 'if (!found_h || !found_w)'
mut valid_judge '((height % cell_h) ? 2 : 1)' '((height % cell_h) ? 1 : 1)'
mut valid_judge '((width / cell_w) & 0xffff) + ((width % cell_w) ? 2 : 1)' '((width / cell_w) & 0xffff) + ((width % cell_w) ? 3 : 1)'
mut valid_judge 'if (cols & 1)' 'if (cols & 2)'
mut valid_judge 'cols != count * 2' 'cols != count * 2 + 1'
mut valid_judge '>= 1153' '>= 1152'
mut valid_judge 'if (!cell_h || !cell_w)' 'if (!cell_h)'
mut interp_by_ct 'delta < 64 && !force' 'delta < 65 && !force'
mut interp_by_ct 'if (ct < bp[0])' 'if (ct <= bp[0])'
mut interp_by_ct '} else if (ct < bp[1]) {' '} else if (ct <= bp[1]) {'
mut interp_by_ct '} else if (ct < bp[2]) {' '} else if (ct <= bp[2]) {'
mut interp_by_ct '} else if (ct < bp[3]) {' '} else if (ct <= bp[3]) {'
mut interp_by_ct 'if (!force && b->zone == 0)' 'if (!force && b->zone == 1)'
mut interp_by_ct 'if (!force && b->zone == 2)' 'if (!force && b->zone == 3)'
mut interp_by_ct 'if (!force && b->zone == 4)' 'if (b->zone == 4)'
mut interp_by_ct 'b->last_ct = ct;' 'b->last_ct = ct + 1;'
mut interp_by_ct 'int span = (int)bp[1] - (int)bp[0];' 'int span = (int)bp[1] - (int)bp[0] + 1;'
mut interp_by_ct 'span - (ct - bp[2]), ct - bp[2], span, words' 'span - (ct - bp[2]) + 1, ct - bp[2], span, words'
mut interp_by_ct 'b->zone = 3;' 'b->zone = 2;'
mut interp_by_ct 'memcpy(b->real + LSC_LIT_R_INTER, b->tool + LSC_LIT_T_LUT1, words * 4)' 'memcpy(b->real + LSC_LIT_R_INTER, b->tool + LSC_LIT_T_LUT2, words * 4)'
mut interp_by_ct 'memcpy(b->real + LSC_LIT_R_INTER, b->tool + LSC_LIT_T_LUT0, words * 4)' 'memcpy(b->real + LSC_LIT_R_INTER, b->tool + LSC_LIT_T_LUT0, words * 3)'
mut interp_by_ct 'dst[0] = (in1 << 24) | (in0 & 0xffffff);' 'dst[0] = (in1 << 23) | (in0 & 0xffffff);'
mut interp_by_ct 'dst[1] = ((in1 >> 8) & 0xffff) | (in2 << 16);' 'dst[1] = ((in1 >> 9) & 0xffff) | (in2 << 16);'
mut interp_by_ct 'dst[2] = (in2 >> 16) & 0xff;' 'dst[2] = (in2 >> 16) & 0x7f;'
mut interp_by_ct 'uint32_t hi = ((((va >> 12) & 0xfff) * w_a +' 'uint32_t hi = ((((va >> 12) & 0x7ff) * w_a +'
mut interp_by_ct '((vb >> 12) & 0xfff) * frac) / span) << 12;' '((vb >> 12) & 0xfff) * frac) / span) << 11;'
mut interp_by_ct '(vb & 0xfff) * frac) / span) & 0xfff;' '(vb & 0xfff) * frac) / span) & 0x7ff;'
mut interp_by_ct 'for (i = 0; i < words; i += 3) {' 'for (i = 0; i + 3 < words; i += 3) {'
mut write_reg 'mesh->end >= (uint32_t)mesh->start + 2' 'mesh->end >= (uint32_t)mesh->start + 1'
mut write_reg 'uint32_t step = 1024 / (mesh->end - mesh->start);' 'uint32_t step = 1023 / (mesh->end - mesh->start);'
mut write_reg 'mesh->step = (uint16_t)step;' 'mesh->step = (uint16_t)(step + 1);'
mut write_reg 'val = 0x2000200;' 'val = 0x2000201;'
mut write_reg '((uint32_t)mesh->flag << 31)' '((uint32_t)mesh->flag << 30)'
mut write_reg '(((uint32_t)mesh->end << 8) & 0xff00)' '(((uint32_t)mesh->end << 8) & 0x7f00)'
mut write_reg '(((uint32_t)lsc_lit_t16(b, LSC_LIT_T_CELL_H) << 16) & 0xff0000)' '(((uint32_t)lsc_lit_t16(b, LSC_LIT_T_CELL_H) << 16) & 0x7f0000)'
mut write_reg '(lsc_lit_t16(b, LSC_LIT_T_MODE) & 3)' '(lsc_lit_t16(b, LSC_LIT_T_MODE) & 1)'
mut write_reg '(((uint32_t)msb[0] << 15) & 0xffff)' '(((uint32_t)msb[0] << 14) & 0xffff)'
mut write_reg 'b->wdr ? LSC_LIT_T_MSB_WDR : LSC_LIT_T_MSB_LIN' 'b->wdr ? LSC_LIT_T_MSB_LIN : LSC_LIT_T_MSB_WDR'
mut write_reg '(((uint32_t)lsc_lit_t16(b, LSC_LIT_T_COUNT) << 16) & 0x3ff0000)' '(((uint32_t)lsc_lit_t16(b, LSC_LIT_T_COUNT) << 16) & 0x1ff0000)'
mut write_reg '*(uint8_t *)(b->real + LSC_LIT_R_GAIN0));' '*(uint8_t *)(b->real + LSC_LIT_R_GAIN1));'
mut real_write_lut 'uint32_t ctrl = bank ? 0x50030 : 0x50020;' 'uint32_t ctrl = bank ? 0x50020 : 0x50030;'
mut real_write_lut 'system_reg_write(ctrl, 0x101)' 'system_reg_write(ctrl, 0x100)'
mut real_write_lut '((nodes - 1) << 16) | 0x102' '((nodes - 1) << 16) | 0x103'
mut real_write_lut 'i < nodes * 3' 'i + 1 < nodes * 3'
mut real_write_lut 'system_reg_write(ctrl + 4, src[i])' 'system_reg_write(ctrl + 4, src[i] & 0xffffff)'
[ $NF = 0 ] || { echo "t40_lsc_host: FAIL ($NF mutations not detected)"; exit 1; }
echo "t40_lsc_host: ok (0 mismatches, $NM mutations detected)"
