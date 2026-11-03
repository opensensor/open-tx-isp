#!/bin/bash
# T40 AE leaf / parameter functions (driver/t40/tx_isp_t40_ae_leaf.h: g_luma, g_comp, get_state, sensor_trig, ev_start_set, algo_deinit_internal,
# get/set_hist_bin, get_y_zone, g_scene_luma, s_comp, api_set_exp_list, s_explist, s_exprinfo_attr, s/g_scence_attr) built for mipsel and run against
# the OEM instructions of the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_ae_leaf.py): identical return values, identical bytes in the whole
# test heap and in the AE globals, identical calls to the functions outside the header, plus one-token mutations of the header that must be detected (#85).
# tisp_ae_sensor_trig / ev_start_set / s_scence_attr differ between the vendor image and the factory Eufy module (the driver uses the factory ae_cache
# layout): they are compared with the factory module, T40_OEM_KO_FAC.  Needs T40_OEM_KO, T40_CC and python3 unicorn + pyelftools, else SKIP;
# without T40_OEM_KO_FAC those three are not compared (a note is printed; with T40_ORACLE_STRICT=1 it is a failure).
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}; FAC=${T40_OEM_KO_FAC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_ae_leaf_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
[ -r "$FAC" ] || { echo "t40_ae_leaf_host: note: T40_OEM_KO_FAC (factory Eufy module) missing, sensor_trig / ev_start_set / s_scence not compared"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; FAC=; }
FACARG=; [ -z "$FAC" ] || FACARG="--fac $FAC"
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_ae_leaf/build_emu.sh" "$CC" $W/ok.o || { echo "t40_ae_leaf_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_ae_leaf.py" "$KO" $W/ok.o $FACARG --n ${N:-1000} || { echo "t40_ae_leaf_host: FAIL"; exit 1; }
NM=0; NF=0
mut() {		# mut FUNCTIONS FROM TO : edit a copy of the header
	case ",$1," in *,sensor_trig,*|*,ev_start_set,*|*,s_scence,*) [ -n "$FAC" ] || return;; esac
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_ae_leaf.h" $W/d/
	python3 - "$2" "$3" $W/d/tx_isp_t40_ae_leaf.h <<'PY' || { echo "t40_ae_leaf_host: mutation text not found: $2"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_ae_leaf/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_ae_leaf_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_ae_leaf.py" "$KO" $W/m.o $FACARG --n ${NMUT:-80} --fn $1 > /dev/null && { echo "t40_ae_leaf_host: FAIL mutation not detected: $2 => $3"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
mut g_luma 'acc += i * hist[i];' 'acc += (i + 1) * hist[i];'
mut g_luma 't40_ae_h(geo, 8) * t40_ae_h(geo, 38);' 't40_ae_h(geo, 8) * t40_ae_h(geo, 36);'
mut g_luma 'i < 256; i++)' 'i < 255; i++)'
mut g_comp '(uint8_t)*p : 0;' '(uint8_t)(*p >> 1) : 0;'
mut g_comp 't40_ae_p(ctx, 276);' 't40_ae_p(ctx, 272);'
mut get_state 't40_ae_h(p, 298) != 0' 't40_ae_h(p, 296) != 0'
mut get_state 'a0 ? stSecAeOuter : stMainAeOuter' 'a0 ? stMainAeOuter : stSecAeOuter'
mut get_state '*(uint32_t *)a2 = t40_ae_h(p, 296);' '*(uint32_t *)a2 = t40_ae_h(p, 300);'
mut sensor_trig 'cache[1292] = 1;' 'cache[1296] = 1;'
mut ev_start_set '*t40_ae_p(ctx, 260) = (uint8_t)a1;' '*t40_ae_p(ctx, 260) = (uint8_t)a2;'
mut ev_start_set '*t40_ae_p(ctx, 176) = (uint8_t)a1;' '*t40_ae_p(ctx, 184) = (uint8_t)a1;'
mut ev_start_set 'if (a1 == 1) {' 'if (a1 != 0) {'
mut algo_deinit 'ta_custom_en[arg1 ? 1 : 0] == 1' 'ta_custom_en[arg1 ? 1 : 0] == 2'
mut algo_deinit 'ta_custom_en[arg1 ? 1 : 0] = 0;' 'ta_custom_en[arg1 ? 1 : 0] = 1;'
mut get_hist_bin 'tisp_ae_main_hist_last, 1052' 'tisp_ae_main_hist_last, 1051'
mut get_hist_bin 'arg1 ? tisp_ae_sec_hist_last : tisp_ae_main_hist_last' 'arg1 ? tisp_ae_main_hist_last : tisp_ae_sec_hist_last'
mut set_hist_bin '+ 1044,' '+ 1040,'
mut get_y_zone 'memcpy((void *)(uintptr_t)a1, zone, 900);' 'memcpy((void *)(uintptr_t)a1, zone, 899);'
mut get_y_zone 'T40_AE_LOCK(a0 ? &sec_slock : &main_slock, &flags);' 'T40_AE_LOCK(a0 ? &main_slock : &sec_slock, &flags);'
mut get_y_zone 't40_ae_p(ctx, 140)' 't40_ae_p(ctx, 144)'
mut g_scene_luma 'for (i = 0; i < 14; i++)' 'for (i = 0; i < 13; i++)'
mut g_scene_luma ')) >> 2;' ')) >> 3;'
mut g_scene_luma 'acc /= 36;' 'acc /= 35;'
mut g_scene_luma 'idx = t40_ae_h(p_idx, 20);' 'idx = t40_ae_h(p_idx, 22);'
mut g_scene_luma 'hist[255] & 0x3fffffffU' 'hist[255] & 0x7fffffffU'
mut g_scene_luma 'area - hsum : 1;' 'area - hsum : 2;'
mut g_scene_luma 'acc += i * r[i - 1];' 'acc += i * r[i];'
mut s_comp '(int32_t)(base * a1) >> 7;' '(int32_t)(base * a1) >> 6;'
mut s_comp '/ 127 - 302;' '/ 127 - 301;'
mut s_comp '(int32_t)(a1 * 300U) / 127' '(int32_t)((a1 * 300U) / 127U)'
mut s_comp 'a1 < 129U' 'a1 < 130U'
mut s_comp '*t40_ae_p(ctx, 164) = 1;' '*t40_ae_p(ctx, 164) = 2;'
mut s_comp '*(uint32_t *)t40_ae_p(ctx, 276) = a1;' '*(uint32_t *)t40_ae_p(ctx, 276) = a1 + 1U;'
mut s_comp '(uint16_t *)(t40_ae_p(ctx, 328) + 4)' '(uint16_t *)(t40_ae_p(ctx, 328) + 6)'
mut api_set_exp_list 'src[5U * i + 2U]' 'src[5U * i + 3U]'
mut api_set_exp_list 'i < 16U' 'i < 15U'
mut api_set_exp_list '*t40_ae_p(ctx, 172) = 0;' '*t40_ae_p(ctx, 172) = 1;'
mut api_set_exp_list '(t40_ae_p(ctx, 4) + 6) = (uint16_t)a1;' '(t40_ae_p(ctx, 4) + 4) = (uint16_t)a1;'
mut api_set_exp_list 'tisp_ae_par_calc(a0 & 0xffU, (uintptr_t)ctx);' 'tisp_ae_par_calc(a0 & 0xffU, (uintptr_t)(ctx == pstMainAeOri_storage ? pstSecAeOri_storage : pstMainAeOri_storage));'
mut s_explist 'a1 + 4)' 'a1 + 8)'
mut s_exprinfo 'in[10 + i]' 'in[11 + i]'
mut s_exprinfo '= in[42];' '= in[41];'
mut s_exprinfo 'a0 * 220U' 'a0 * 224U'
mut s_exprinfo '(v + 16) = in[0];' '(v + 20) = in[0];'
mut s_exprinfo 'i < 7; i++)' 'i < 6; i++)'
mut s_scence 'c4[5] = (uint16_t)(in[4] + 1U);' 'c4[5] = (uint16_t)(in[4]);'
mut s_scence 'c0[7] = in[12] + 1U;' 'c0[7] = in[12] + 2U;'
mut s_scence 'else if (v - 2U < 2U)' 'else if (v - 2U < 3U)'
mut s_scence 'tisp_ae_s_comp(a0, 128);' 'tisp_ae_s_comp(a0, 127);'
mut s_scence 't40_ae_w(in, 24) == 1U ? 0U : 1U' 't40_ae_w(in, 24) == 1U ? 1U : 0U'
mut s_scence 'c0[6] = in[4] + 1U;' 'c0[6] = in[4];'
mut s_scence 'c4[4] = (uint16_t)(in[12] + 1U);' 'c4[4] = (uint16_t)(in[12] + 2U);'
mut g_scence 'out[12] = (uint8_t)(c4[8] - 1U);' 'out[12] = (uint8_t)(c4[9] - 1U);'
mut g_scence 'comp == 128 ? 1U : 3U' 'comp == 127 ? 1U : 3U'
mut g_scence '(uintptr_t)(out + 48)' '(uintptr_t)(out + 44)'
mut g_scence 'out[4] = (uint8_t)(c0[6] - 1U);' 'out[4] = (uint8_t)(c0[6]);'
mut g_scence '*(const uint32_t *)t40_ae_p(ctx, 264);' '*(const uint32_t *)t40_ae_p(ctx, 260);'
mut g_scence '*(uint32_t *)(out + 32) = lum;' '*(uint32_t *)(out + 32) = comp;'
mut g_exprinfo 'o[6] = T40_M(c[3]);' 'o[6] = T40_M(c[4]);'
mut g_exprinfo 'o[22] = T40_M(c[7]);' 'o[22] = c[7];'
mut g_exprinfo 'k = den ? ((p44 & 0xffffU) * 1000000U) / den : 0;' 'k = den ? ((p44 & 0xffffU) * 1000000U) / (den + 1U) : 0;'
mut g_exprinfo 'o[10 + i] = *(const uint32_t *)(t + 56 + 4 * i);' 'o[10 + i] = *(const uint32_t *)(t + 52 + 4 * i);'
mut g_exprinfo 'o[53] = c[9] >> 10;' 'o[53] = c[9] >> 9;'
mut g_exprinfo 'o[54] = (uint32_t)tisp_log2_fixed_to_fixed(c[9], 10, 16);' 'o[54] = (uint32_t)tisp_log2_fixed_to_fixed(c[9], 10, 15);'
mut g_exprinfo 'o[47] = T40_M(c[21]);' 'o[47] = T40_M(c[20]);'
mut g_exprinfo 'o[35 + i]' 'o[34 + i]'
mut algo_init 'u[15] = c[19];' 'u[15] = c[18];'
mut algo_init 't[13] = hist[1049];' 't[13] = hist[1048];'
mut algo_init 'memcpy(t + 20, hist + 1044, 4);' 'memcpy(t + 20, hist + 1048, 4);'
mut algo_init 't[0] = t[4] = t[8] = 1;' 't[0] = t[4] = 1;'
mut algo_init 'if (arg2 != 1 ||' 'if (arg2 == 0 ||'
mut algo_init 'const uint8_t *hist = arg1 ? tisp_ae_sec_hist_last : tisp_ae_main_hist_last;' 'const uint8_t *hist = arg1 ? tisp_ae_main_hist_last : tisp_ae_sec_hist_last;'
[ $NF = 0 ] || { echo "t40_ae_leaf_host: FAIL ($NF mutations not detected)"; exit 1; }
echo "t40_ae_leaf_host: ok (0 mismatches, $NM mutations detected)"
