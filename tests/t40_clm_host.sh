#!/bin/bash
# T40 CLM block (driver/t40/tx_isp_t40_clm.h: init, ct_interp, write_csc_para, real_write_lut, prepare_write_lut, get_wlut_times,
# dn_params_refresh, wdr_en, deinit, and the CLM step of tx_isp_t40_ct_chain.h) built for mipsel and run against the OEM instructions of
# the vendor tx-isp-t40.ko in Unicorn (tools/ko_emu/diff_clm.py): identical return values, parameter copy, LUT image, state, CSC block,
# table selection, counters and register accesses, plus one-token mutations of the header that must be detected (#85).
# Needs the vendor module (T40_OEM_KO), a mipsel-linux-gcc (T40_CC) and python3 unicorn + pyelftools, else SKIP.
HERE=$(cd "$(dirname "$0")" && pwd)
KO=${T40_OEM_KO:-}; CC=${T40_CC:-}
if [ ! -r "$KO" ] || [ ! -x "$CC" ] || ! python3 -c "import unicorn, elftools" 2>/dev/null; then echo "t40_clm_host: SKIP (T40_OEM_KO / T40_CC / python3 unicorn+pyelftools missing)"; [ -z "$T40_ORACLE_STRICT" ] || exit 1; exit 0; fi
W=$(mktemp -d); trap 'rm -rf $W' EXIT
"$HERE/t40_clm/build_emu.sh" "$CC" $W/ok.o || { echo "t40_clm_host: FAIL build"; exit 1; }
python3 "$HERE/../tools/ko_emu/diff_clm.py" "$KO" $W/ok.o --n ${N:-100} || { echo "t40_clm_host: FAIL"; exit 1; }
NM=0; NF=0
mut() {		# mut FUNCTIONS FROM TO : edit a copy of the header
	rm -rf $W/d; mkdir -p $W/d; cp "$HERE/../driver/t40/tx_isp_t40_clm.h" "$HERE/../driver/t40/tx_isp_t40_ct_chain.h" $W/d/
	python3 - "$2" "$3" $W/d/tx_isp_t40_clm.h <<'PY' || { echo "t40_clm_host: mutation text not found: $2"; exit 1; }
import sys
a, b, p = sys.argv[1:4]; t = open(p).read()
if a not in t: sys.exit(1)
open(p, "w").write(t.replace(a, b, 1))
PY
	"$HERE/t40_clm/build_emu.sh" "$CC" $W/m.o $W/d || { echo "t40_clm_host: FAIL mutation build"; exit 1; }
	python3 "$HERE/../tools/ko_emu/diff_clm.py" "$KO" $W/m.o --n ${NMUT:-25} --fn $1 > /dev/null && { echo "t40_clm_host: FAIL mutation not detected: $2 => $3"; NF=$((NF + 1)); return; }
	NM=$((NM + 1))
}
mut interp 'return (x >> n) + ((x >> (n - 1U)) & 1);' 'return (x >> n);'
mut interp 'uint32_t m_lo = (ct1 - 100U) & 0xffffU' 'uint32_t m_lo = (ct1 - 99U) & 0xffffU'
mut interp 'm_hi = (ct1 + 100U) & 0xffffU' 'm_hi = (ct1 + 101U) & 0xffffU'
mut interp 'l_hi = (ct2 + 100U) & 0xffffU' 'l_hi = (ct2 + 100U) & 0x7fffU'
mut interp 'zone = ct >= h_lo ? 4U : 3U;' 'zone = ct > h_lo ? 4U : 3U;'
mut interp 'if (c->zone == zone && !(zone & 1U))' 'if (c->zone == zone)'
mut interp 'if (!((int32_t)c->thr < (int32_t)d))' 'if (!(c->thr < d))'
mut interp 't40_clm_copy(c, c->tab[3], c->tab[6]);' 't40_clm_copy(c, c->tab[3], c->tab[5]);'
mut interp 't40_clm_copy(c, c->tab[1], c->tab[4]);' 't40_clm_copy(c, c->tab[2], c->tab[4]);'
mut interp 'c->tab[3], c->tab[2], c->tab[6], c->tab[5], ((ct - l_hi) << 12)' 'c->tab[2], c->tab[3], c->tab[6], c->tab[5], ((ct - l_hi) << 12)'
mut interp 'c->tab[2], c->tab[1], c->tab[5], c->tab[4], ((ct - m_hi) << 12)' 'c->tab[2], c->tab[1], c->tab[5], c->tab[4], ((ct - m_hi) << 11)'
mut interp 'd8[i] = (uint8_t)t40_clm_itp((int8_t)p[lo8 + i], (int8_t)p[hi8 + i], w);' 'd8[i] = (uint8_t)t40_clm_itp(p[lo8 + i], (int8_t)p[hi8 + i], w);'
mut csc 'w0 = ((t40_clm_csc_mag(s, 76, 6) << 16) & 0x0fff0000U)' 'w0 = ((t40_clm_csc_mag(s, 76, 7) << 16) & 0x0fff0000U)'
mut csc '(t40_clm_csc_mag(s, 64, 6) & 0x3ffU)' '(t40_clm_csc_mag(s, 64, 6) & 0x1ffU)'
mut csc '((uint32_t)(s[42] != 0) << 8) | s[40]' '((uint32_t)s[42] << 8) | s[40]'
mut csc 'return (lo ^ s) - s;' 'return (lo ^ s) + s;'
mut csc 'system_reg_write(base + 20U, w3);' 'system_reg_write(base + 24U, w3);'
mut write 'uint32_t w2 = (b[4] >> 4) & 7U;' 'uint32_t w2 = (b[4] >> 4) & 15U;'
mut write '((b[2] << 14) & 0x1fc000U)' '((b[2] << 14) & 0x3fc000U)'
mut write '((t40_clm_u16(h + 6) >> 5) & 0xfU)' '((t40_clm_u16(h + 6) >> 4) & 0xfU)'
mut write 'system_reg_write(port + 100U, w4);' 'system_reg_write(port + 96U, w4);'
mut write 'system_reg_write(port + 32U * k, 0xd10102);' 'system_reg_write(port + 32U * k, 0xd10101);'
mut write 'uint32_t port = bank == 1U ? 0x500d0U : 0x500c0U' 'uint32_t port = bank ? 0x500c0U : 0x500c0U'
mut write '& 0x7ffU);' '& 0xfffU);'
mut times '>> 16) & 1U ? 0U' '>> 15) & 1U ? 0U'
mut prepare 't40_clm_wlut_times[bank]++;' 't40_clm_wlut_times[bank] = 1;'
mut init 'c->thr = 64;' 'c->thr = 63;'
mut init,refresh 'T40_CLM_BIN_OFF  (65536U + 9132U)' 'T40_CLM_BIN_OFF  (65536U + 9134U)'
mut init,wdr 'static const uint32_t t40_clm_tab_linear[8] = { 0, 6,' 'static const uint32_t t40_clm_tab_linear[8] = { 0, 8,'
mut wdr '{ 3156, 3162, 12612' '{ 3156, 3162, 12614'
mut wdr 'en == 1U ? t40_clm_tab_wdr' 'en ? t40_clm_tab_wdr'
mut refresh 't40_clm_ct_interp(bank, c->ct, 1);
	t40_clm_prepare_write_lut(bank);
	return 0;
}

/* OEM tisp_clm_wdr_en' 't40_clm_ct_interp(bank, c->ct, 0);
	t40_clm_prepare_write_lut(bank);
	return 0;
}

/* OEM tisp_clm_wdr_en'
mut ct_update 'static uint8_t t40_clm_wlut_frequency[2] = { 5, 5 };' 'static uint8_t t40_clm_wlut_frequency[2] = { 5, 4 };'
mut deinit 't40_clm_ctx[bank] = NULL;
	T40_CLM_FREE(c->params);' 'T40_CLM_FREE(c->params);'
[ $NF = 0 ] || { echo "t40_clm_host: FAIL ($NF mutations not detected)"; exit 1; }
echo "t40_clm_host: ok (0 mismatches, $NM mutations detected)"
