#!/bin/bash
# Host run of the generated T40 vendor AWB: tests/t40_vawb_host.sh <tuning.bin> <oem data.bin> R G B [frames] [trace]
# (oem data.bin = objcopy -O binary --only-section=.data of the OEM tx-isp-t40.ko)
#   tests/t40_vawb_host.sh replay <device dump> [trace]     (REPS=n [CONSEC=1]: time per process)
# CTD_REF=<git ref>: tisp_awb_ct_detect C (tx_isp_t40_awb_ctd.inc) vs the translated OEM code of that
# ref (the last one that generated it, e.g. f2c180f7) on every call; FUZZ=seed / FUZZM=seed vary
# the statistics / tuning switches; FUZZT=seed generates valid zone geometry plus synthetic ct_detect tables (no vendor
# data), FUZZG=seed only the geometry (issue 133, #163). T40_DRV_DIR=<dir>: use that copy of driver/t40 (mutation check).
# LA_REF=<git ref>: tisp_awb_long_alogrithm C (tx_isp_t40_awb_long.inc) vs the translated OEM code of
# that ref (the last one that generated it, e.g. 316259cb) on every call; FUZZL=seed varies its state.
# (Not together with FUZZ: that one re-randomises the ct_detect inputs on each of the two calls.)
# GR_REF=<git ref>: the C gain / threshold chain (tx_isp_t40_awb_gain.inc: set_gain, set_regional_threshold, set_lum_th_freq,
# tgain_update, simple_intp, set_awb_trig, AE mean; tx_isp_t40_awb_stats.inc: get_statistics, sat_weight) vs the translated OEM code of that ref (the last one that generated it,
# e.g. 308cfe4b) on every call, register writes + state + faults compared; FUZZP=seed [FUZZN=calls] runs the fuzz loop.
set -e
HERE=$(cd "$(dirname "$0")" && pwd); D=${T40_DRV_DIR:-$HERE/../driver/t40}; W=$(mktemp -d); trap 'rm -rf $W' EXIT
sed -n '/^#include "tx_isp_t40_vawb_gen.inc"/q;p' $D/tx_isp_t40_vawb.h > $W/top.h
sed -i -e 's/a >= 0x80000000U \&\& a < 0xfffff000U \&\& !(a \& align)/harness_ok(a, align)/' \
       -e 's/tg < 0x80000000U || (tg \& 3)/tg < 0x1000U || (tg \& 3)/' \
       -e "s/vawb_tbuf\[256\]/vawb_tbuf[65536]/" -e 's/^\(static u8 vawb_wide_tele_para\[144\]\)/\1 VD/' -e 's/^\(static u32 vawb_argarea\[16\]\)/\1 VD/' \
       -e 's/^\(static u32 vawb_tawb_custom_en\[2\]\);/\1 VD;/' -e 's/^static u32 vawb_awb_num;/static u32 vawb_awb_num VD;/' \
       -e 's/^static u32 vawb_peter_test_count\[2\];/static u32 vawb_peter_test_count[2] VD;/' \
       -e 's/^static u32 vawb_converge_tele_gain = /static u32 vawb_converge_tele_gain VD = /' \
       -e 's/^static u32 vawb_wide_tele_awb_gain\[3\] = /static u32 vawb_wide_tele_awb_gain[3] VD = /' $W/top.h
echo '#endif' >> $W/top.h
if [ -n "$LA_REF" ]; then
	# reference: the translated OEM long_alogrithm closure of $LA_REF, renamed vlref_* (ct_detect: the C one)
	FNS="tisp_awb_long_alogrithm tisp_awb_sat_weight fix_point_div fix_point_mult2_32"
	git -C $HERE/.. show $LA_REF:driver/t40/tx_isp_t40_vawb_gen.inc > $W/laref_all.inc
	: > $W/laref.inc
	for f in $FNS; do echo "u64 vlref_$f(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);" >> $W/laref.inc; done
	for f in $FNS; do awk -v f="$f" '!p && $0 ~ "^u64 noinline vawb_" f "\\(" {p=1} p {print} p && /^}/ {exit}' $W/laref_all.inc; done > $W/laref_fns.inc
	SED=; for f in $FNS; do SED="$SED -e s/\\bvawb_$f\\b/vlref_$f/g"; done
	sed $SED $W/laref_fns.inc >> $W/laref.inc
	grep -q "^u64 noinline vlref_tisp_awb_long_alogrithm" $W/laref.inc || { echo "LA_REF $LA_REF has no translated long_alogrithm"; exit 2; }
fi
if [ -n "$GR_REF" ]; then
	# reference: the translated OEM gain / threshold closure of $GR_REF, renamed vgr_*
	FNS="tisp_awb_set_gain tisp_awb_gain_reg fix_point_mult2_32 tisp_awb_calc_tele_gain tisp_awb_calc_div_sqrt_distance
	     tisp_awb_set_regional_threshold tisp_awb_set_lum_th_freq tisp_awb_tgain_update tisp_simple_intp_int16
	     tisp_ae_main_mean_update tisp_ae_sec_mean_update system_reg_set_awb_trig tisp_awb_get_statistics tisp_awb_sat_weight"
	git -C $HERE/.. show $GR_REF:driver/t40/tx_isp_t40_vawb_gen.inc > $W/grref_all.inc
	: > $W/grref.inc
	for f in $FNS; do echo "u64 vgr_$f(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);" >> $W/grref.inc; done
	for f in $FNS; do awk -v f="$f" '!p && $0 ~ "^u64 noinline vawb_" f "\\(" {p=1} p {print} p && /^}/ {exit}' $W/grref_all.inc; done > $W/grref_fns.inc
	SED=; for f in $FNS; do SED="$SED -e s/\\bvawb_$f\\b/vgr_$f/g"; done
	sed $SED $W/grref_fns.inc >> $W/grref.inc
	grep -q "^u64 noinline vgr_tisp_awb_set_gain" $W/grref.inc || { echo "GR_REF $GR_REF has no translated set_gain"; exit 2; }
	XDEFG="-DGR_REF_INC=\"$W/grref.inc\""
fi
# the C fix-point helpers of the driver (used by tx_isp_t40_awb_ctd.inc)
for f in fix_point_div_32 fix_point_div fix_point_mult2_32 fix_point_mult3_32; do
	awk -v f="$f" '!p && $0 ~ "^int(32|64)_t " f "\\(" && $0 !~ /;$/ {p=1} p {print} p && /^}/ {exit}' $D/tx_isp_t40_recovered.c
done > $W/cfix.inc
XDEF=
[ -n "$LA_REF" ] && XDEF="-DLA_REF_INC=\"$W/laref.inc\""
if [ -n "$CTD_REF" ]; then
	# reference: the translated OEM ct_detect closure of $CTD_REF, renamed vref_*
	FNS="tisp_awb_ct_detect ISPAWBInterpolation1 ISPAWBInterpolation2 Tiziano_Awb_Ct_Cal Tiziano_Awb_Ct_Detect_GrayWorld
	     Tiziano_Awb_Ct_Detect_GrayWorld_mode func_zone_ct_weight fix_point_div_32 fix_point_div_64 fix_point_mult3_32 fix_point_div"
	git -C $HERE/.. show $CTD_REF:driver/t40/tx_isp_t40_vawb_gen.inc > $W/ref_all.inc
	: > $W/ref.inc
	for f in $FNS; do echo "u64 vref_$f(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);" >> $W/ref.inc; done
	for f in $FNS; do awk -v f="$f" '!p && $0 ~ "^u64 noinline vawb_" f "\\(" {p=1} p {print} p && /^}/ {exit}' $W/ref_all.inc; done > $W/ref_fns.inc
	SED=; for f in $FNS; do SED="$SED -e s/\\bvawb_$f\\b/vref_$f/g"; done
	sed $SED $W/ref_fns.inc >> $W/ref.inc
	sed -i 's/^static u64 vawb_s_tisp_awb_ct_detect(/static u64 vawb_s_ctd_c(/' $W/top.h
	XDEF="$XDEF -DCTD_REF_INC=\"$W/ref.inc\""
fi
sed -e 's/^static const u8 vawb_rodata\(\[[0-9]*\]\) __aligned(8)/static u8 vawb_rodata\1 __aligned(8) VD/' ${GEN:-$D/tx_isp_t40_vawb_gen.inc} > $W/gen.inc
XDEF="$XDEF $XDEFG"
${VCC:-gcc} ${VOPT:--O1} ${XCFLAGS:--g0} -falign-functions=16 ${VPIE--no-pie -fno-pie} -w -fno-strict-aliasing ${VLD--Wl,--section-start=.vdata=0x30000000} \
	-DVAWB_TOP="\"$W/top.h\"" -DVAWB_INC="\"$W/gen.inc\"" -DCFIX_INC="\"$W/cfix.inc\"" \
	-DCTD_INC="\"$D/tx_isp_t40_awb_ctd.inc\"" -I$D $XDEF $HERE/t40_vawb/vawb_host.c -o $W/vawb_host
[ -n "$KEEPBIN" ] && cp $W/vawb_host $KEEPBIN
[ -n "$NORUN" ] && exit 0
$W/vawb_host "$@"
