/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Host run of the generated T40 vendor AWB (tx_isp_t40_vawb.h top part + tx_isp_t40_vawb_gen.inc):
 * OEM init from a real tuning bin (day bank), then N frames of synthetic AWB statistics
 * (every zone the same R/G/B), prints the gains (ctx[9]), CT (*ctx[7]) and the register writes.
 * 64-bit non-PIE build, data below 4 GB (.vdata at 0x30000000), MAP_32BIT stack.
 *   vawb_host <tuning.bin> <inter_seed.bin> <R> <G> <B> [frames] [trace]
 *   vawb_host replay <dump> [trace]      device dump, result compared with the device
 * Replay environment: REPS=n times the process n times on the dump state (CONSEC=1: state
 * carried from call to call) and prints the time per process.  Built with CTD_REF (t40_vawb_host.sh),
 * every tisp_awb_ct_detect call runs both the driver's C translation and the translated OEM
 * code from that git ref on the same state and compares all outputs; FUZZ=seed replaces the
 * zone statistics, FUZZM=seed the ct_detect tuning switches before each call (issue 133).
 * Built with LA_REF, every tisp_awb_long_alogrithm call runs both the driver's C translation
 * (tx_isp_t40_awb_long.inc) and the translated OEM code of that ref on the same state and
 * compares inter/outer; FUZZL=seed randomises the state long_alogrithm reads before each call.
 */
#define _GNU_SOURCE
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <ucontext.h>
#include <sys/mman.h>
#ifndef MAP_32BIT
#define MAP_32BIT 0
#endif
#include <time.h>

typedef uint8_t u8; typedef uint16_t u16; typedef uint32_t u32; typedef uint64_t u64;
typedef int8_t s8; typedef int16_t s16; typedef int32_t s32; typedef int64_t s64;
#define noinline __attribute__((noinline))
#define __aligned(x) __attribute__((aligned(x)))
#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x) __builtin_expect(!!(x), 1)
#define KERN_WARNING ""
#define KERN_INFO ""
#define BIT(n) (1U << (n))
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define PAGE_SIZE 4096
#define THREAD_SIZE 8192
#define module_param(a, b, c)
/* bring-up-only parameters of the driver (Kbuild TX_ISP_T40_BRINGUP_PARAMS) */
#define t40_bringup_param(...)
#define t40_bringup_param_named(...)
#define t40_bringup_param_array_named(...)
#define t40_bringup_param_cb(...)
#define t40_bringup_parm_desc(...)
#define module_param_named(a, b, c, d)
#define module_param_cb(a, b, c, d)
#define MODULE_PARM_DESC(a, b)
#define scnprintf snprintf
#define printk(...) (harness_verbose ? printf(__VA_ARGS__) : 0)
#define div64_u64(a, b) ((a) / (b))
struct kernel_param { int x; };
struct kernel_param_ops { int (*get)(char *, const struct kernel_param *); };
static int harness_verbose = 1;
#define VD __attribute__((section(".vdata")))
#define in_interrupt() 0
static u32 pstMainAwbOri[128] VD, pstSecAwbOri[128] VD, pstMainAwbCtDetectOri[34] VD;
static u32 stMainAwbInter VD, stMainAwbOuter VD, stSecAwbInter VD, stSecAwbOuter VD;
static u8 pstMainAeOri_storage[0x164] VD, pstSecAeOri_storage[0x164] VD;
static u32 tparamsN[4] VD, awb_algo_comp[64] VD;
static u8 tispinfo[64] VD;
/* colour contexts of the CT chains (unused by the AWB run, referenced by the generated code) */
static u32 pstMainCcmOri_lit[26] VD, pstMainBcshOri_lit[72] VD;
static u32 t40_bcsh_oem_ctx[72] VD;
static struct { u8 mjpeg_mode[2], mjpeg_y_low[2], mjpeg_y_high[2]; } t40_bcsh VD;
static u8 s_bcsh_mjpeg_mode_lit[2] VD, s_bcsh_mjpeg_y_range_low_lit[2] VD, s_bcsh_mjpeg_y_range_high_lit[16] VD;
static u8 inter[0x10000] __aligned(16) VD, outer[0x2000] __aligned(16) VD, bank[0x19000] __aligned(16) VD;
static u8 stats[0x10000] __aligned(16) VD;
static u32 nreg;
struct reglog { u32 a, v; };
static struct reglog *reglog_p; static u32 reglog_n;	/* GR_REF: write log of the call under test */
static void reglog_add(u32 a, u32 v)
{
	if (reglog_p) { if (reglog_n < 64) { reglog_p[reglog_n].a = a; reglog_p[reglog_n].v = v; } reglog_n++; }
}
static u32 reg4004, reg4008;
static void private_complete(u32 c);
static int system_reg_write(u32 a, u32 v)
{
	nreg++;
	reglog_add(a, v);
	if (a == 0x4004) reg4004 = v;
	if (a == 0x4008) reg4008 = v;
	return 0;
}
/* register reads: a deterministic sequence per call under test (GR_REF resets it before each of the two runs), logged like writes */
static u32 rd_x = 1; static int rd_fuzz;
static int system_reg_read(u32 a)
{
	u32 v;

	if (!rd_fuzz) return 0;
	rd_x ^= rd_x << 13; rd_x ^= rd_x >> 17; rd_x ^= rd_x << 5;
	v = (rd_x & 7) == 0 ? 0 : (rd_x & 8) ? rd_x & 0xff : rd_x >> 4;
	reglog_add(0xA0000000U | a, v);
	return v;
}
static void private_complete(u32 c) { reglog_add(0xC0000000U, c); }
/* events: the fields the consumers read (id, payload) are logged */
static int tisp_event_push(u32 a, u32 b)
{
	const u32 *ev = (const u32 *)(uintptr_t)b;

	reglog_add(0xE0000000U | a, ev[2]); reglog_add(0xE1000000U, ev[4]); reglog_add(0xE2000000U, ev[5]);
	return 0;
}
static int tisp_awb_main_interrupt_static(void) { return 0; }
static long tisp_awb_main_process(void) { return 0; }
static u8 *stk_lo;
static u32 harness_ok(u32 a, u32 align)
{
	if (a & align) return 0;
	if (a >= (u32)(uintptr_t)stk_lo && a < (u32)(uintptr_t)stk_lo + 0x40000) return 1;
#ifdef VAWB_ANYADDR	/* 32-bit target build (mipsel): every user address fits */
	return a >= 0x1000U;
#endif
	return a >= 0x30000000U && a < 0x30400000U;
}
/* driver C code the generated chain calls: tisp_awb_ct_detect (tx_isp_t40_awb_ctd.inc) and its fix-point helpers */
static int regtrace_is_kernel_ptr(const void *p) { return p != 0; }
static int regtrace_is_kernel_ptr_any(const void *p) { return p != 0; }
static bool regtrace_enable_isp_3a_diag;
#include CFIX_INC
#include CTD_INC
#ifdef CTD_REF_INC
/* the C long_alogrithm calls tisp_awb_ct_detect directly: route that call through the both-versions comparison */
static int64_t (*const ctd_real)(uintptr_t, uintptr_t, uint32_t) = tisp_awb_ct_detect;
static u64 vawb_s_tisp_awb_ct_detect(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static noinline int64_t harness_ctd_call(uintptr_t a0, uintptr_t a1, uint32_t a2)
{
	return (int64_t)vawb_s_tisp_awb_ct_detect((u32)a0, (u32)a1, (u32)a2, 0, 0);
}
#define tisp_awb_ct_detect harness_ctd_call
#endif
#ifdef LA_REF_INC
#define vawb_s_tisp_awb_long_alogrithm vawb_s_la_c
#endif
#ifdef GR_REF_INC
#define vawb_s_tisp_awb_set_gain vgr_c_set_gain
#define vawb_s_tisp_awb_set_regional_threshold vgr_c_regional
#define vawb_s_tisp_awb_set_lum_th_freq vgr_c_lum
#define vawb_s_tisp_awb_tgain_update vgr_c_tgain
#define vawb_s_tisp_awb_get_statistics vgr_c_stats
#define vawb_s_tisp_awb_params_transmit vgr_c_ptrans
#define vawb_s_tisp_awb_params_refresh vgr_c_prefresh
#define vawb_s_tisp_awb_set_hardware_param vgr_c_hwparam
#define vawb_s_tisp_awb_dn_params_refresh vgr_c_dnrefresh
#define vawb_s_tisp_awb_main_ev_update vgr_c_mainev
#define vawb_s_tisp_awb_ev_update_Ywgt vgr_c_ywgt
#ifdef HAVE_AWB_MAIN
#define vawb_s_tisp_awb_long_par_update vgr_c_lparupd
#endif
#ifdef HAVE_AWB_MAIN
#define vawb_s_tisp_awb_spec_calculate vgr_c_speccalc
#endif
#ifdef HAVE_AWB_MAIN
#define vawb_s_tisp_awb_main_process vgr_c_mainproc
#endif
#endif
#include VAWB_TOP
#ifdef GR_REF_INC
#undef vawb_s_tisp_awb_set_gain
#undef vawb_s_tisp_awb_set_regional_threshold
#undef vawb_s_tisp_awb_set_lum_th_freq
#undef vawb_s_tisp_awb_tgain_update
#undef vawb_s_tisp_awb_get_statistics
#undef vawb_s_tisp_awb_params_transmit
#undef vawb_s_tisp_awb_params_refresh
#undef vawb_s_tisp_awb_set_hardware_param
#undef vawb_s_tisp_awb_dn_params_refresh
#undef vawb_s_tisp_awb_main_ev_update
#undef vawb_s_tisp_awb_ev_update_Ywgt
#ifdef HAVE_AWB_MAIN
#undef vawb_s_tisp_awb_long_par_update
#endif
#ifdef HAVE_AWB_MAIN
#undef vawb_s_tisp_awb_spec_calculate
#endif
#ifdef HAVE_AWB_MAIN
#undef vawb_s_tisp_awb_main_process
#endif
static u64 vawb_s_tisp_awb_set_gain(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_set_regional_threshold(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_set_lum_th_freq(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_tgain_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_params_transmit(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_set_hardware_param(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_dn_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_main_ev_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
static u64 vawb_s_tisp_awb_ev_update_Ywgt(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
#ifdef HAVE_AWB_MAIN
static u64 vawb_s_tisp_awb_long_par_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
#endif
#ifdef HAVE_AWB_MAIN
static u64 vawb_s_tisp_awb_spec_calculate(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
#endif
#ifdef HAVE_AWB_MAIN
static u64 vawb_s_tisp_awb_main_process(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
#endif
#ifndef TOP_HAS_TELE
static u8 vawb_wide_tele_para[144] VD; static u32 vawb_converge_tele_gain VD = 0x00010001U;
#endif
static u32 vawb_wide_tele_awb_gain[3] VD = { 0x04000400U, 0x04000400U, 0x04000400U };	/* the OEM state of the reference only */
#endif
#ifdef LA_REF_INC
#undef vawb_s_tisp_awb_long_alogrithm
static u64 vawb_s_tisp_awb_long_alogrithm(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp);
#endif
/* CT-chain externals (tx_isp_t40_vct.h on the device), unused by the AWB run */
static u64 vawb_x___private_spin_lock_irqsave(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return 0; }
static u64 vawb_x_private_spin_unlock_irqrestore(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return 0; }
static u64 vawb_s_tisp_clm_ct_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return 0; }
#include VAWB_INC
#ifdef CTD_REF_INC
#include CTD_REF_INC
static unsigned long ctd_n, ctd_bad;
static u8 ctd_si[60328], ctd_so[4752], ctd_ti[60328], ctd_to[4752];
static u32 fz_x, fz_y;
static u8 ctd_stk[0x4000] __aligned(16) VD;	/* frame area of the translated OEM ct_detect when the caller is C */
#define FZ(v) (v ^= v << 13, v ^= v >> 17, v ^= v << 5, v)
static void ctd_fuzz(u32 *o)
{
	if (getenv("FUZZ")) {	/* plausible zone statistics: scattered, one or two clusters, mostly empty */
		u32 *rat = (u32 *)(uintptr_t)o[22], *cnt = (u32 *)(uintptr_t)o[23], *sat = (u32 *)(uintptr_t)o[24], z, k, cr, cb, sp;
		if (!fz_x) fz_x = atoi(getenv("FUZZ")) | 1;
		k = FZ(fz_x) % 4; cr = 150 + FZ(fz_x) % 300; cb = 120 + FZ(fz_x) % 280; sp = 2 + FZ(fz_x) % 40;
		for (z = 0; z < 225; z++) {
			u32 r, b, c2 = (k == 2 && (FZ(fz_x) & 1)) ? 60 : 0;
			if (k == 0) { r = 80 + FZ(fz_x) % 520; b = 80 + FZ(fz_x) % 520; }
			else { r = cr + c2 + FZ(fz_x) % sp - sp / 2; b = cb + c2 + FZ(fz_x) % sp - sp / 2; }
			rat[z] = (r << 8) | (FZ(fz_x) & 255); rat[z + 225] = (b << 8) | (FZ(fz_x) & 255);
			cnt[z] = (k == 3 && FZ(fz_x) % 8) ? 0 : FZ(fz_x) % 1000;
			sat[z] = FZ(fz_x) % 1024;
		}
	}
	if (getenv("FUZZG") || getenv("FUZZT")) {	/* valid zone geometry and precision (the harness never runs the hardware setup that sets them) */
		static u32 fg_x;
		u16 *pf = (u16 *)(uintptr_t)o[13], *o5 = (u16 *)(uintptr_t)o[5];

		if (!fg_x) fg_x = atoi(getenv("FUZZG") ? getenv("FUZZG") : getenv("FUZZT")) * 7 + 1;
		pf[0] = 8 + FZ(fg_x) % 5; pf[1] = 8;	/* precision, fraction bits */
		o5[1] = o5[3] = 15; o5[4] = 1 + FZ(fg_x) % 64; o5[19] = 1 + FZ(fg_x) % 64;	/* rows, cols, zone width/height */
	}
	if (getenv("FUZZT")) {	/* synthetic ct_detect tables (generated, not vendor data): centres, knots, prior, weights, mired, LUT, radii */
		static u32 ft_x;
		u32 p = *(u16 *)(uintptr_t)o[13], i, z;
		u8 *cnt = (u8 *)(uintptr_t)o[1], *spw = (u8 *)(uintptr_t)o[9];
		u16 *inc = (u16 *)(uintptr_t)o[0], *exc = (u16 *)(uintptr_t)o[17], *lut = (u16 *)(uintptr_t)o[12];
		u16 *sr = (u16 *)(uintptr_t)o[20], *sb = (u16 *)(uintptr_t)o[21];
		u32 *kn = (u32 *)(uintptr_t)o[2], *pr = (u32 *)(uintptr_t)o[3], *wt = (u32 *)(uintptr_t)o[4], *xk = (u32 *)(uintptr_t)o[6];
		u32 *yk = (u32 *)(uintptr_t)o[7], *mi = (u32 *)(uintptr_t)o[8], *rf = (u32 *)(uintptr_t)o[10], *cp = (u32 *)(uintptr_t)o[16], *rad = (u32 *)(uintptr_t)o[19];

		if (!ft_x) ft_x = atoi(getenv("FUZZT")) | 1;
		u16 *pf = (u16 *)(uintptr_t)o[13], *o5 = (u16 *)(uintptr_t)o[5];

		p = 8 + FZ(ft_x) % 5; pf[0] = p; pf[1] = 8;	/* precision, fraction bits */
		o5[1] = o5[3] = 15; o5[4] = 1 + FZ(ft_x) % 64; o5[19] = 1 + FZ(ft_x) % 64;	/* rows, cols, zone width/height */
		cnt[0] = FZ(ft_x) % 5; cnt[1] = FZ(ft_x) % 5;
		for (i = 0; i < 8; i++) { inc[i] = 100 + FZ(ft_x) % 500; exc[i] = 100 + FZ(ft_x) % 500; }
		kn[0] = 2000 + FZ(ft_x) % 1500; kn[1] = kn[0] - FZ(ft_x) % 1500; kn[2] = kn[0] + FZ(ft_x) % 2500; kn[3] = kn[2] + FZ(ft_x) % 2500;
		pr[0] = FZ(ft_x) & 1; pr[1] = FZ(ft_x) % (1U << p);
		for (z = 0; z < 225; z++) { wt[z] = FZ(ft_x) % ((1U << p) + 1); mi[z] = 1500 + FZ(ft_x) % 9000; spw[z] = FZ(ft_x) % 17; }
		for (i = 0; i < 15; i++) { xk[i] = 60 + i * 40 + FZ(ft_x) % 30; yk[i] = 60 + i * 38 + FZ(ft_x) % 30; }
		for (i = 0; i < 514; i++) lut[i] = 256 - (256 * i / 513) + (FZ(ft_x) % 4 == 0 ? FZ(ft_x) % 3 : 0) > 256 ? 256 : 256 - (256 * i / 513);	/* weight 256..0 over the distance */
		for (i = 0; i < 10; i++) { sr[i] = 100 + FZ(ft_x) % 500; sb[i] = 100 + FZ(ft_x) % 500; rad[i] = FZ(ft_x) % 40; }
		rf[1] = FZ(ft_x) % 600; rf[2] = FZ(ft_x) % 600;
		cp[1] = FZ(ft_x) % 6000; cp[2] = FZ(ft_x) % 6000; cp[3] = FZ(ft_x) % 6000; cp[4] = 1 + FZ(ft_x) % 40; cp[5] = 1 + FZ(ft_x) % 20;
		*(u16 *)((uintptr_t)o[0] + 38) = FZ(ft_x) % 257;
	}
	if (getenv("FUZZM")) {	/* gray-world modes, saturation weight, cluster mode, prior, refine, special lights */
		static u16 m14[4], m15; static u32 m16[6], m3[2], m10; static u8 m18[10]; static int saved;
		u16 *gw = (u16 *)(uintptr_t)o[14], *sm = (u16 *)(uintptr_t)o[15];
		u32 *cp = (u32 *)(uintptr_t)o[16], *pr = (u32 *)(uintptr_t)o[3], *rf = (u32 *)(uintptr_t)o[10], i;
		u8 *sl = (u8 *)(uintptr_t)o[18];
		if (!saved) { memcpy(m14, gw, 8); m15 = *sm; memcpy(m16, cp, 24); memcpy(m3, pr, 8); m10 = rf[0]; memcpy(m18, sl, 10); saved = 1; }
		if (!fz_y) fz_y = atoi(getenv("FUZZM")) | 1;
		memcpy(gw, m14, 8); *sm = m15; memcpy(cp, m16, 24); memcpy(pr, m3, 8); rf[0] = m10; memcpy(sl, m18, 10);
		if (FZ(fz_y) & 1) { gw[0] = FZ(fz_y) % 2; gw[1] = FZ(fz_y) % 3; gw[2] = FZ(fz_y) % 2; gw[3] = FZ(fz_y) % 2; }
		if (FZ(fz_y) & 1) *sm = FZ(fz_y) % 3;
		if (FZ(fz_y) & 1) cp[0] = FZ(fz_y) % 3;
		if (FZ(fz_y) & 1) pr[0] = FZ(fz_y) % 2;
		if (FZ(fz_y) & 1) ((u8 *)rf)[0] = FZ(fz_y) % 2;
		if ((FZ(fz_y) & 3) == 0) for (i = 0; i < 10; i++) sl[i] = FZ(fz_y) % 3;
	}
}
/* both ct_detect versions on the same state: inter/outer images, gains and flags must match */
static u64 vawb_s_tisp_awb_ct_detect(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 g[4], f[4], tg[4], tf[4], di = 0, dout = 0, i, f0, fr;
	u64 rv;

	if (!csp) csp = (u32)(uintptr_t)(ctd_stk + sizeof(ctd_stk) - 64);
	ctd_fuzz((u32 *)(uintptr_t)a0);
	memcpy(ctd_si, inter, sizeof(ctd_si)); memcpy(ctd_so, outer, sizeof(ctd_so));
	memcpy(g, (void *)(uintptr_t)a1, 16); memcpy(f, (void *)(uintptr_t)a2, 16);
	f0 = vawb_faults;
	rv = vref_tisp_awb_ct_detect(a0, a1, a2, a3, csp);
	fr = vawb_faults - f0;
	memcpy(ctd_ti, inter, sizeof(ctd_ti)); memcpy(ctd_to, outer, sizeof(ctd_to));
	memcpy(tg, (void *)(uintptr_t)a1, 16); memcpy(tf, (void *)(uintptr_t)a2, 16);
	memcpy(inter, ctd_si, sizeof(ctd_si)); memcpy(outer, ctd_so, sizeof(ctd_so));
	memcpy((void *)(uintptr_t)a1, g, 16); memcpy((void *)(uintptr_t)a2, f, 16);
	(void)ctd_real(a0, a1, a2);
	ctd_n++;
	for (i = 0; i < sizeof(ctd_ti); i++) di += inter[i] != ctd_ti[i];
	for (i = 0; i < sizeof(ctd_to); i++) dout += outer[i] != ctd_to[i];
	if (di || dout || memcmp(tg, (void *)(uintptr_t)a1, 8) || memcmp(tf, (void *)(uintptr_t)a2, 8))
		if (ctd_bad++ < 10)
			printf("CTD DIFF call %lu (OEM faults %u): inter %u B outer %u B gains OEM %u/%u C %u/%u flags OEM %u/%u C %u/%u\n", ctd_n, fr, di, dout,
			       tg[0], tg[1], ((u32 *)(uintptr_t)a1)[0], ((u32 *)(uintptr_t)a1)[1], tf[0], tf[1], ((u32 *)(uintptr_t)a2)[0], ((u32 *)(uintptr_t)a2)[1]);
	return rv;
}
#endif

#ifdef LA_REF_INC
#include LA_REF_INC
static unsigned long la_n, la_bad;
static u8 la_si[60328], la_so[4752], la_ti[60328], la_to[4752];
static u32 fl_x;
#define FL(v) (v ^= v << 13, v ^= v >> 17, v ^= v << 5, v)
static u32 fl_val(void)	/* 0, small, or any width up to 2^27 */
{
	u32 k = FL(fl_x) % 8;
	return k == 0 ? 0 : k == 1 ? FL(fl_x) % 4 : FL(fl_x) & ((1U << (FL(fl_x) % 28)) - 1);
}
/* the state tisp_awb_long_alogrithm reads: statistics, weights, thresholds, precision, state machine, history, flags */
static void la_fuzz(u32 *c)
{
	u32 i, z;
	u16 *w23 = (u16 *)(uintptr_t)c[23], *w55 = (u16 *)(uintptr_t)c[55], *v4 = (u16 *)(uintptr_t)c[4], *p3 = (u16 *)(uintptr_t)c[3];
	u16 *g = (u16 *)(uintptr_t)c[123];
	u32 *s6 = (u32 *)(uintptr_t)c[5];

	if (!getenv("FUZZL")) return;
	if (!fl_x) fl_x = atoi(getenv("FUZZL")) | 1;
	for (i = 59; i <= 98; i++)
		for (z = 0; z < 225; z++) ((u32 *)(uintptr_t)c[i])[z] = fl_val();
	if (FL(fl_x) & 1) for (i = 0; i < 8; i++) w23[i] = FL(fl_x) % 17;
	if (FL(fl_x) & 1) for (i = 0; i < 4; i++) w55[i] = FL(fl_x) % 17;
	*(u16 *)((uintptr_t)c[22] + 18) = FL(fl_x) % 6;
	if (FL(fl_x) & 1) *(u32 *)(uintptr_t)c[1] = FL(fl_x) % 400;
	if ((FL(fl_x) & 3) == 0) { p3[0] = 10 + FL(fl_x) % 7; p3[1] = FL(fl_x) % 13; }
	if (FL(fl_x) & 1) { v4[0] = FL(fl_x) % 20; v4[1] = FL(fl_x) % 600; v4[2] = FL(fl_x) % 600; v4[3] = FL(fl_x) % 64; }
	if (FL(fl_x) & 1) { s6[0] = FL(fl_x) % 3; s6[1] = FL(fl_x) % 20; for (i = 2; i < 6; i++) s6[i] = FL(fl_x) % 2048; }
	if ((FL(fl_x) & 3) == 0) { s6[4] = s6[2]; s6[5] = s6[3]; }
	*(u8 *)(uintptr_t)c[100] = FL(fl_x) % 3; *(u8 *)(uintptr_t)c[103] = FL(fl_x) % 3;
	*(u8 *)(uintptr_t)c[118] = (FL(fl_x) & 3) == 0; *(u8 *)(uintptr_t)c[120] = (FL(fl_x) & 3) == 0;
	if (FL(fl_x) & 1) for (i = 0; i < 6; i++) g[i] = FL(fl_x) % 600;
	if (FL(fl_x) & 1)
		for (i = 104; i <= 106; i++)
			for (z = 0; z < 15; z++) ((u32 *)(uintptr_t)c[i])[z] = FL(fl_x) % 70000;
	if (FL(fl_x) & 1) { ((u32 *)(uintptr_t)c[104])[13] = ((u32 *)(uintptr_t)c[104])[14]; ((u32 *)(uintptr_t)c[105])[13] = ((u32 *)(uintptr_t)c[105])[14]; }
	if (FL(fl_x) & 1) { ((u32 *)(uintptr_t)c[9])[0] = FL(fl_x) % 4096; ((u32 *)(uintptr_t)c[9])[1] = FL(fl_x) % 4096; }
	*(u16 *)(uintptr_t)c[24] = FL(fl_x) % 4;
	if ((FL(fl_x) & 7) == 0) { *(u16 *)((uintptr_t)c[0] + 2) = 1 + FL(fl_x) % 15; *(u16 *)((uintptr_t)c[0] + 6) = 1 + FL(fl_x) % 15; }
	else { *(u16 *)((uintptr_t)c[0] + 2) = 15; *(u16 *)((uintptr_t)c[0] + 6) = 15; }
}
/* both long_alogrithm versions on the same state: inter and outer must match */
static u64 vawb_s_tisp_awb_long_alogrithm(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 di = 0, dout = 0, i, f0, fr, fc, first = ~0U;
	u64 rv;

	la_fuzz((u32 *)(uintptr_t)a0);
	memcpy(la_si, inter, sizeof(la_si)); memcpy(la_so, outer, sizeof(la_so));
	f0 = vawb_faults;
	rv = vlref_tisp_awb_long_alogrithm(a0, a1, a2, a3, csp);
	fr = vawb_faults - f0;
	memcpy(la_ti, inter, sizeof(la_ti)); memcpy(la_to, outer, sizeof(la_to));
	memcpy(inter, la_si, sizeof(la_si)); memcpy(outer, la_so, sizeof(la_so));
	f0 = vawb_faults;
	(void)vawb_s_la_c(a0, a1, a2, a3, csp);
	fc = vawb_faults - f0;
	la_n++;
	for (i = 0; i < sizeof(la_ti); i++) if (inter[i] != la_ti[i]) { di++; if (first == ~0U) first = i; }
	for (i = 0; i < sizeof(la_to); i++) dout += outer[i] != la_to[i];
	if (di || dout || fr != fc)
		if (la_bad++ < 10) {
			u32 k, own = ~0U, *c = pstMainAwbOri;
			for (k = 0; k < 128 && first != ~0U; k++)
				if (c[k] >= (u32)(uintptr_t)inter && c[k] - (u32)(uintptr_t)inter <= first && (own == ~0U || c[k] > c[own])) own = k;
			printf("LA DIFF call %lu: inter %u B (first +%#x ctx[%u]+%u OEM %#x C %#x) outer %u B faults OEM %u C %u\n", la_n, di, first, own,
			       own == ~0U ? 0 : first - (c[own] - (u32)(uintptr_t)inter), first == ~0U ? 0 : *(u32 *)(la_ti + (first & ~3U)),
			       first == ~0U ? 0 : *(u32 *)(inter + (first & ~3U)), dout, fr, fc);
		}
	return rv;
}
#endif

#define VAWB_CSP ((u32)(uintptr_t)vawb_argarea)
#ifdef HAVE_AWB_MAIN
#define MAINPROC vawb_s_tisp_awb_main_process
#else
#define MAINPROC vawb_tisp_awb_main_process
#endif
#define VAWB_TOP() (vawb_loop_n = 0)
#ifdef GR_REF_INC
/*
 * GR_REF: the C gain / threshold chain (tx_isp_t40_awb_gain.inc) against the translated OEM code of the git
 * ref on the same state.  Every call of set_gain / set_regional_threshold / set_lum_th_freq / tgain_update
 * (from the translated chain or from the fuzz loop) and the direct fuzz of simple_intp, set_awb_trig and the
 * AE mean run both versions; compared: the register write sequence, the fault counter and every byte of
 * the state the functions can reach (inter, outer, both context tables, both AE contexts and their buffers).
 * FUZZP=seed runs the fuzz loop (FUZZN calls of each, default 20000).
 */
#include GR_REF_INC
static unsigned long gr_n[20], gr_bad[20];
static u32 gr_x, rd_seed = 12345, gr_total;
#define GRR() (gr_x ^= gr_x << 13, gr_x ^= gr_x >> 17, gr_x ^= gr_x << 5, gr_x)
static u32 gr_ae_loc[2] VD;	/* the OEM mean update's two local outputs (*a0, *a1): the callers discard them, the C version does not compute them */
static u32 gr_ae_geo[2][4] __aligned(4) VD, gr_ae_sum[2][16 * 16] VD, gr_ae_ev[2][4] VD, gr_ae_out[2][2] VD;
#define GR_NREG 18
static struct { void *p; u32 n; } gr_reg[GR_NREG];
static u8 gr_s0[0x40000], gr_s1[0x40000], gr_s2[0x40000];
static u8 secinter[0x10000] __aligned(16) VD, secouter[0x2000] __aligned(16) VD, bank2[0x19000] __aligned(16) VD;
static struct reglog gr_l1[64], gr_l2[64], gr_lbuf[64];
static void gr_regions(void)
{
	gr_reg[0].p = inter; gr_reg[0].n = 60328;
	gr_reg[1].p = outer; gr_reg[1].n = 4752;
	gr_reg[2].p = pstMainAwbOri; gr_reg[2].n = 512;
	gr_reg[3].p = pstSecAwbOri; gr_reg[3].n = 512;
	gr_reg[4].p = pstMainAeOri_storage; gr_reg[4].n = 0x164;
	gr_reg[5].p = pstSecAeOri_storage; gr_reg[5].n = 0x164;
	gr_reg[6].p = gr_ae_geo; gr_reg[6].n = sizeof(gr_ae_geo);
	gr_reg[7].p = gr_ae_sum; gr_reg[7].n = sizeof(gr_ae_sum);
	gr_reg[8].p = gr_ae_ev; gr_reg[8].n = sizeof(gr_ae_ev);
	gr_reg[9].p = gr_ae_out; gr_reg[9].n = sizeof(gr_ae_out);
	gr_reg[10].p = secinter; gr_reg[10].n = 60328;
	gr_reg[11].p = secouter; gr_reg[11].n = 4752;
	gr_reg[12].p = pstMainAwbCtDetectOri; gr_reg[12].n = sizeof(pstMainAwbCtDetectOri);
	gr_reg[13].p = &vawb_awb_num; gr_reg[13].n = 1;
	gr_reg[14].p = vawb_peter_test_count; gr_reg[14].n = sizeof(vawb_peter_test_count);
	gr_reg[15].p = vawb_tawb_custom_en; gr_reg[15].n = 8;
	gr_reg[16].p = awb_algo_comp; gr_reg[16].n = sizeof(awb_algo_comp);
	gr_reg[17].p = &vawb_events_seen; gr_reg[17].n = sizeof(vawb_events_seen);
}
static void gr_save(u8 *d) { u32 i, o = 0; for (i = 0; i < GR_NREG; i++) { memcpy(d + o, gr_reg[i].p, gr_reg[i].n); o += gr_reg[i].n; } gr_total = o; }
static void gr_load(const u8 *d) { u32 i, o = 0; for (i = 0; i < GR_NREG; i++) { memcpy(gr_reg[i].p, d + o, gr_reg[i].n); o += gr_reg[i].n; } }
static void gr_ae_setup(void)
{
	u32 k;
	u8 *ae[2] = { pstMainAeOri_storage, pstSecAeOri_storage };

	for (k = 0; k < 2; k++) {
		u32 *a = (u32 *)ae[k];
		a[71] = (u32)(uintptr_t)gr_ae_geo[k]; a[34] = (u32)(uintptr_t)gr_ae_sum[k];
		a[11] = (u32)(uintptr_t)gr_ae_ev[k]; a[68] = (u32)(uintptr_t)gr_ae_out[k];
		((u16 *)gr_ae_geo[k])[1] = 3; ((u16 *)gr_ae_geo[k])[3] = 4; gr_ae_ev[k][2] = 1024 + 64 * k;
	}
}
/* run the reference and the C version on one state: fn_ref returns, fn_c is the C adapter */
typedef u64 (*gr_fn)(u32, u32, u32, u32, u32);
static u64 gr_cmp(int id, const char *name, gr_fn fn_ref, gr_fn fn_c, u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 f0, fr, fc, n1, n2, i, r, bad = 0, first = ~0U, at = 0;
	u64 rv;

	gr_regions();
	gr_save(gr_s0);
	rd_fuzz = 1; rd_seed ^= rd_seed << 13; rd_seed ^= rd_seed >> 17; rd_seed ^= rd_seed << 5;
	rd_x = rd_seed | 1;
	reglog_p = gr_l1; reglog_n = 0; f0 = vawb_faults;
	rv = fn_ref(a0, a1, a2, a3, csp);
	fr = vawb_faults - f0; n1 = reglog_n;
	gr_save(gr_s1);
	gr_load(gr_s0);
	rd_x = rd_seed | 1;
	reglog_p = gr_l2; reglog_n = 0; f0 = vawb_faults;
	(void)fn_c(a0, a1, a2, a3, csp);
	fc = vawb_faults - f0; n2 = reglog_n; reglog_p = 0;
	gr_save(gr_s2);
	gr_n[id]++;
	if (memcmp(gr_s1, gr_s2, gr_total))
		for (i = 0; i < gr_total; i++) if (gr_s1[i] != gr_s2[i]) { bad++; if (first == ~0U) first = i; }
	if (n1 != n2) bad++;
	else for (r = 0; r < n1 && r < 64; r++) if (gr_l1[r].a != gr_l2[r].a || gr_l1[r].v != gr_l2[r].v) { bad++; at = r; break; }
	if (fr != fc) bad++;
	if (bad) {
		if (gr_bad[id]++ < 10)
			printf("GR DIFF %s call %lu: state %u B (first %#x) regs ref %u C %u (first diff %u) faults ref %u C %u\n", name, gr_n[id], bad,
			       first, n1, n2, at, fr, fc);
		if (n1 == n2 && at < n1 && gr_bad[id] <= 10)
			printf("   reg %u: ref %#x=%#x C %#x=%#x\n", at, gr_l1[at].a, gr_l1[at].v, gr_l2[at].a, gr_l2[at].v);
	}
	return rv;
}
static u64 vawb_s_tisp_awb_set_gain(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return gr_cmp(0, "set_gain", vgr_tisp_awb_set_gain, vgr_c_set_gain, a0, a1, a2, a3, csp);
}
static u64 vawb_s_tisp_awb_set_regional_threshold(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return gr_cmp(1, "regional_threshold", vgr_tisp_awb_set_regional_threshold, vgr_c_regional, a0, a1, a2, a3, csp);
}
static u64 vawb_s_tisp_awb_set_lum_th_freq(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return gr_cmp(2, "lum_th_freq", vgr_tisp_awb_set_lum_th_freq, vgr_c_lum, a0, a1, a2, a3, csp);
}
static u64 vawb_s_tisp_awb_tgain_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return gr_cmp(3, "tgain_update", vgr_tisp_awb_tgain_update, vgr_c_tgain, a0, a1, a2, a3, csp);
}
static u64 vawb_s_tisp_awb_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return gr_cmp(8, "get_statistics", vgr_tisp_awb_get_statistics, vgr_c_stats, a0, a1, a2, a3, csp);
}
static u64 vawb_s_tisp_awb_params_transmit(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(10, "params_transmit", vgr_tisp_awb_params_transmit, vgr_c_ptrans, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(11, "params_refresh", vgr_tisp_awb_params_refresh, vgr_c_prefresh, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_set_hardware_param(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(12, "set_hardware_param", vgr_tisp_awb_set_hardware_param, vgr_c_hwparam, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_dn_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(13, "dn_params_refresh", vgr_tisp_awb_dn_params_refresh, vgr_c_dnrefresh, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_main_ev_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(14, "main_ev_update", vgr_tisp_awb_main_ev_update, vgr_c_mainev, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_ev_update_Ywgt(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(15, "ev_update_Ywgt", vgr_tisp_awb_ev_update_Ywgt, vgr_c_ywgt, a0, a1, a2, a3, csp); }
#ifdef HAVE_AWB_MAIN
static u64 vawb_s_tisp_awb_long_par_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(16, "long_par_update", vgr_tisp_awb_long_par_update, vgr_c_lparupd, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_spec_calculate(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(17, "spec_calculate", vgr_tisp_awb_spec_calculate, vgr_c_speccalc, a0, a1, a2, a3, csp); }
static u64 vawb_s_tisp_awb_main_process(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{ return gr_cmp(18, "main_process", vgr_tisp_awb_main_process, vgr_c_mainproc, a0, a1, a2, a3, csp); }
#endif
/* sat_weight has no shim in the driver (the C long_alogrithm calls it directly): o32 stack arguments sat plane, gain pair, ctx */
static u64 gr_c_sat(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	const u32 *arg = (const u32 *)(uintptr_t)csp;

	t40_awb_sat_weight((const u32 *)(uintptr_t)a0, (const u32 *)(uintptr_t)a1, (const u32 *)(uintptr_t)a2, (const u32 *)(uintptr_t)a3,
			   (u32 *)(uintptr_t)arg[4], (const u32 *)(uintptr_t)arg[5], (const u32 *)(uintptr_t)arg[6]);
	return 0;
}
static u32 gr_sat_area[8] VD, gr_sat_gain[2] VD;
/* adapters for the pieces without a shim of their own (direct comparison) */
static u64 gr_c_intp(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return t40_ag_intp(a0, a1, (const u16 *)(uintptr_t)a2); }
static u64 gr_c_trig(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { t40_ag_trig(a0, a1); return 0; }
static u64 gr_c_aemain(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { t40_ag_ae_mean(pstMainAeOri_storage); return 0; }
static u64 gr_c_aesec(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { t40_ag_ae_mean(pstSecAeOri_storage); return 0; }
static u64 gr_cmp_ret(int id, const char *name, gr_fn fn_ref, gr_fn fn_c, u32 a0, u32 a1, u32 a2)
{
	u64 r1 = gr_cmp(id, name, fn_ref, fn_c, a0, a1, a2, 0, VAWB_CSP), r2 = fn_c(a0, a1, a2, 0, VAWB_CSP);

	if (id == 4 && ((u32)r1 != (u32)r2) && gr_bad[id]++ < 10)
		printf("GR DIFF %s result: ref %#x C %#x\n", name, (u32)r1, (u32)r2);
	return r1;
}
static u32 gr_val(u32 mx) { u32 k = GRR() % 8; return k == 0 ? 0 : k == 1 ? mx : GRR() % (mx + 1); }
static void gr_fuzz_ctx(void)
{
	u32 *c = pstMainAwbOri, i, k;
	u16 *p3 = (u16 *)(uintptr_t)c[3], *tbl = (u16 *)(uintptr_t)c[34], *cfg = (u16 *)(uintptr_t)c[0], *ov = (u16 *)(uintptr_t)c[122];

	p3[0] = 8 + GRR() % 10; p3[1] = 1 + GRR() % 12;
	((u32 *)(uintptr_t)c[9])[0] = gr_val(8192); ((u32 *)(uintptr_t)c[9])[1] = gr_val(8192);
	((u32 *)(uintptr_t)c[5])[4] = gr_val(1U << (GRR() % 16)); ((u32 *)(uintptr_t)c[5])[5] = gr_val(1U << (GRR() % 16));
	for (i = 0; i < 8; i++) ((u32 *)(uintptr_t)c[36])[i] = gr_val(3000);
	if (GRR() & 1) ((u32 *)(uintptr_t)c[36])[6] = ((u32 *)(uintptr_t)c[36])[7];
	k = 1500 + GRR() % 14000;
	*(u32 *)(uintptr_t)c[7] = k;
	*(u32 *)(uintptr_t)c[56] = (GRR() & 1) ? k + GRR() % 500 - 250 : gr_val(16000);
	if ((GRR() & 7) == 0) *(u32 *)(uintptr_t)c[56] = k;
	((u32 *)(uintptr_t)c[58])[0] = gr_val(5000); ((u32 *)(uintptr_t)c[58])[1] = gr_val(5000);
	*(u8 *)(uintptr_t)c[118] = GRR() % 3 == 0; *(u8 *)(uintptr_t)c[119] = GRR() % 4 == 0;
	*(u8 *)(uintptr_t)c[120] = GRR() % 12; *(u32 *)(uintptr_t)c[121] = gr_val(16000);
	ov[0] = gr_val(0xffff); ov[1] = gr_val(0xffff);
	for (i = 0; i < 4; i++) ((u16 *)(uintptr_t)c[124])[i] = GRR();
	*(u32 *)(uintptr_t)c[117] = ((GRR() % 14) << 16) | (u32)gr_val(0xffff);
	for (i = 0; i < 121; i++) tbl[i] = (GRR() % 5 == 0 && i) ? tbl[i - 1] : gr_val(GRR() & 1 ? 0xffff : 4095);
	for (i = 34; i < 46; i++) cfg[i] = GRR();
	for (k = 0; k < 2; k++) {
		u16 *g = (u16 *)gr_ae_geo[k];
		u32 *e = gr_ae_ev[k];

		g[1] = GRR() % 17; g[3] = GRR() % 16;
		for (i = 0; i < 256; i++) gr_ae_sum[k][i] = gr_val(1U << (GRR() % 28));
		e[2] = gr_val(1U << (GRR() % 20)); gr_ae_out[k][0] = GRR();
		if ((GRR() & 15) == 0) g[1] = 0;
		if ((GRR() & 15) == 0) g[3] = 0;
	}
}
static void gr_fuzz_stats(void)
{
	u32 *c = pstMainAwbOri, i, k;
	u8 *cfg = (u8 *)(uintptr_t)c[0];

	cfg[94] = GRR() % 3 == 0; cfg[96] = GRR() % 6;
	*(u16 *)(cfg + 2) = 1 + GRR() % 15; *(u16 *)(cfg + 6) = 1 + GRR() % 15;
	for (i = 0; i < 0x10000 / 4; i++) ((u32 *)stats)[i] = GRR();
	for (k = 59; k <= 98; k++) for (i = 0; i < 225; i++) ((u32 *)(uintptr_t)c[k])[i] = GRR();
	for (k = 39; k <= 42; k++) for (i = 0; i < 225; i++) ((u32 *)(uintptr_t)c[k])[i] = (GRR() % 9 == 0) ? 0 : gr_val(GRR() & 1 ? 1U << 26 : 3000);
	for (i = 0; i < 225; i++) ((u32 *)(uintptr_t)c[45])[i] = GRR();
	*(u32 *)(uintptr_t)c[1] = gr_val(2000);
	*(u16 *)(uintptr_t)c[24] = GRR() % 4;
	((u16 *)(uintptr_t)c[3])[0] = 8 + GRR() % 10;
	gr_sat_gain[0] = gr_val(1U << (GRR() % 16)); gr_sat_gain[1] = gr_val(1U << (GRR() % 16));
	gr_sat_area[4] = c[45]; gr_sat_area[5] = (u32)(uintptr_t)gr_sat_gain; gr_sat_area[6] = (u32)(uintptr_t)c;
}

/*
 * Init / EV / process chain (tx_isp_t40_awb_init.inc, tx_isp_t40_awb_main.inc): FUZZQ=seed [FUZZN=calls].  Every field the
 * functions read is randomised with the interesting values (0, 1, 2, boundaries) over-represented; the context pointer
 * tables stay valid (params_transmit of each sensor restores them).
 */
#define PR_SRC(s) ((u8 *)(uintptr_t)(tparamsN[s] + 4288))
static void pr_fill(void *p, u32 n) { u32 i; for (i = 0; i < n; i++) ((u8 *)p)[i] = GRR(); }
static u32 pr_small(u32 n) { return n ? GRR() % n : 0; }
static u32 pr_flag(void) { u32 k = GRR() % 8; return k < 3 ? 0 : k < 6 ? 1 : k == 6 ? 2 : GRR() & 255; }
static void pr_fuzz(u32 sensor)
{
	u32 *c = sensor ? pstSecAwbOri : pstMainAwbOri, i, lo, hi;
	u16 *cfg;
	u8 *src = PR_SRC(sensor);

	pr_fill(sensor ? secinter : inter, 60328); pr_fill(sensor ? secouter : outer, 4752);
	pr_fill(src, 4752);
	/* parameter source: the statistics window rows / columns small, flags as the tuning writes them */
	((u16 *)src)[0] = pr_small(40); ((u16 *)src)[1] = pr_small(16); ((u16 *)src)[2] = pr_small(40); ((u16 *)src)[3] = pr_small(16);
	cfg = (u16 *)(uintptr_t)c[0];
	cfg[0] = pr_small(40); cfg[1] = pr_small(16); cfg[2] = pr_small(40); cfg[3] = pr_small(16);
	((u16 *)(uintptr_t)c[49])[0] = pr_small(4000); ((u16 *)(uintptr_t)c[49])[1] = pr_small(3000);
	*(u8 *)(uintptr_t)c[100] = pr_small(3) == 0; *(u8 *)(uintptr_t)c[101] = pr_small(3) == 0;
	*(u8 *)(uintptr_t)c[118] = pr_small(3) == 0; *(u8 *)(uintptr_t)c[119] = pr_small(4) == 0;
	*(u8 *)(uintptr_t)c[54] = GRR();
	/* exposure thresholds (ctx[6], ctx[21]) and values */
	lo = pr_small(4) ? pr_small(3000) : pr_small(10);
	hi = lo + (pr_small(6) == 0 ? pr_small(3) : pr_small(600));
	if (pr_small(16) == 0) hi = pr_small(3000);
	if (pr_small(20) == 0) { lo = 0x7fffff00U + pr_small(512); hi = 0x7fffff00U + pr_small(512); }	/* straddle the signed boundary */
	((u32 *)(uintptr_t)c[6])[0] = lo; ((u32 *)(uintptr_t)c[6])[1] = hi;
	{
		u32 *e = (u32 *)(uintptr_t)c[116], d3 = (hi - lo) / 3;
		u32 pick = pr_small(16);

		*e = pick == 0 ? lo : pick == 1 ? hi : pick == 2 ? lo + d3 : pick == 3 ? hi + d3 : pick == 4 ? lo - 1 : pick == 5 ? hi - 1 :
		     pick == 6 ? hi + d3 - 1 : pick == 7 ? lo + d3 - 1 : pick == 8 ? GRR() : pick == 9 ? 0 : pick == 10 ? hi + pr_small(d3 + 1) : lo + pr_small(hi - lo + 1) + pr_small(2 * d3 + 3);
	}
	{
		u32 *t = (u32 *)(uintptr_t)c[21], v = pr_small(100);

		for (i = 0; i < 9; i++) { t[i] = v; v += pr_small(8) == 0 ? 0 : pr_small(2000); }
		if (pr_small(8) == 0) for (i = 0; i < 9; i++) t[i] = GRR();
		if (pr_small(3) == 0) *(u32 *)(uintptr_t)c[116] = t[pr_small(9)] + pr_small(3) - 1;
		if (pr_small(8) == 0) *(u32 *)(uintptr_t)c[116] = pr_small(4) ? GRR() : t[8] + 1;
		for (i = 0; i < 9; i++) ((u16 *)(uintptr_t)c[22])[i] = pr_small(5) == 0 ? ((u16 *)(uintptr_t)c[22])[i ? i - 1 : 0] : GRR();
	}
	((u16 *)(uintptr_t)c[3])[1] = pr_small(16);
	((u32 *)(uintptr_t)c[18])[0] = pr_small(2) ? pr_small(3) : GRR(); ((u32 *)(uintptr_t)c[19])[0] = pr_small(2) ? pr_small(3) : GRR();
	for (i = 0; i < 4; i++) { ((u32 *)(uintptr_t)c[15])[i] = pr_small(2) ? pr_small(5000) : GRR(); ((u32 *)(uintptr_t)c[16])[i] = pr_small(5000);
				  ((u32 *)(uintptr_t)c[17])[i] = pr_small(2) ? pr_small(5000) : GRR(); }
	((u32 *)(uintptr_t)c[18])[1] = pr_small(2) ? pr_small(70000) : GRR(); ((u32 *)(uintptr_t)c[19])[1] = pr_small(2) ? pr_small(70000) : GRR();
	for (i = 0; i < 10; i++) ((u8 *)(uintptr_t)c[27])[i] = (i == 0 || i >= 5) ? pr_flag() : GRR();
	((u8 *)(uintptr_t)c[50])[0] = pr_small(4) ? pr_small(3) : GRR(); ((u8 *)(uintptr_t)c[50])[1] = pr_small(4) ? pr_small(4) : GRR();
	((u32 *)(uintptr_t)c[9])[0] = pr_small(2) ? pr_small(5000) : GRR(); ((u32 *)(uintptr_t)c[9])[1] = pr_small(2) ? pr_small(5000) : GRR();
	for (i = 0; i < 32; i++) ((u16 *)(uintptr_t)c[29])[i] = pr_small(4) ? pr_small(900) : GRR();
	for (i = 0; i < 32; i++) ((u16 *)(uintptr_t)c[30])[i] = pr_small(4) ? pr_small(900) : GRR();
	*(u32 *)(uintptr_t)c[7] = 1500 + pr_small(14000);
	if (pr_small(4) == 0) *(u32 *)(uintptr_t)c[7] = GRR();
	vawb_tawb_custom_en[0] = pr_small(3) == 0; vawb_tawb_custom_en[1] = pr_small(3) == 0;
	vawb_awb_num = pr_small(4) == 0 ? GRR() : pr_small(52);
	vawb_peter_test_count[0] = GRR();
}
static void pr_fuzz_ae(void)
{
	/* the AE side of the regional threshold calls: reuse the gain-chain generator */
	gr_fuzz_ctx();
}
static void pr_run(u32 n)
{
	u32 *cm = pstMainAwbOri, *cs = pstSecAwbOri, i, k;

	stSecAwbInter = (u32)(uintptr_t)secinter; stSecAwbOuter = (u32)(uintptr_t)secouter; tparamsN[1] = (u32)(uintptr_t)bank2;
	gr_ae_setup();
	vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)cm, 0, 0, 0, VAWB_CSP);
	vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)cs, 1, 0, 0, VAWB_CSP);
	for (i = 0; i < n; i++) {
		u32 sensor = GRR() % 5 == 0;
		u32 *c = sensor ? cs : cm;

		VAWB_TOP();
		pr_fuzz(sensor);
		if (!sensor || GRR() & 1) pr_fuzz_ae();
		switch (i % 9) {
		case 0:
			for (k = 0; k < 128; k++) c[k] = GRR();
			vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)c, sensor ? (GRR() | 1) : 0, 0, 0, VAWB_CSP);
			break;
		case 1: vawb_s_tisp_awb_params_refresh((u32)(uintptr_t)c, sensor, tparamsN[sensor] + 4288, 0, VAWB_CSP); break;
		case 2: vawb_s_tisp_awb_set_hardware_param((u32)(uintptr_t)c, sensor, 0, 0, VAWB_CSP); break;
		case 3: vawb_s_tisp_awb_dn_params_refresh(sensor, 0, 0, 0, VAWB_CSP); break;
		case 4: vawb_s_tisp_awb_main_ev_update(GRR() >> (GRR() % 20), 0, 0, 0, VAWB_CSP); break;
		case 5: vawb_s_tisp_awb_ev_update_Ywgt((u32)(uintptr_t)cm, 0, 0, 0, VAWB_CSP); break;
#ifdef HAVE_AWB_MAIN
		case 6: vawb_s_tisp_awb_long_par_update((u32)(uintptr_t)cm, (u32)(uintptr_t)pstMainAwbCtDetectOri, stMainAwbInter, 0, VAWB_CSP); break;
		case 7: vawb_s_tisp_awb_spec_calculate((u32)(uintptr_t)cm, GRR() & 1, 0, 0, VAWB_CSP); break;
		default: vawb_s_tisp_awb_main_process(0, 0, 0, 0, VAWB_CSP);
#else
		default: break;
#endif
		}
		if (sensor) {	/* a failed run of the pointer tables must not leak into the next call */
			vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)cs, 1, 0, 0, VAWB_CSP);
		}
		vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)cm, 0, 0, 0, VAWB_CSP);
	}
	{
		static const char *nm[] = { "transmit", "refresh", "hw_param", "dn_refresh", "main_ev", "ywgt", "long_par", "spec", "process" };
		unsigned long tn = 0, tb = 0;

		printf("init_process_chain C vs OEM:");
		for (k = 0; k < 9; k++) { tn += gr_n[10 + k]; tb += gr_bad[10 + k]; printf(" %s %lu/%lu", nm[k], gr_n[10 + k], gr_bad[10 + k]); }
		printf("\ninit_process_chain C vs OEM: %lu calls, %lu differ\n", tn, tb);
	}
}
/* fuzz loop: FUZZP=seed [FUZZN=calls] */
static void gr_direct(void)
{
	u32 *c = pstMainAwbOri, n = getenv("FUZZN") ? atoi(getenv("FUZZN")) : 20000, i;
	u16 *tbl;

	if (getenv("FUZZQ")) {
		gr_x = atoi(getenv("FUZZQ")) * 2654435761U | 1;
		pr_run(n);
		return;
	}
	if (getenv("FUZZP")) {
	gr_x = atoi(getenv("FUZZP")) * 2654435761U | 1;
	memcpy(pstSecAwbOri, pstMainAwbOri, 512);
	tbl = (u16 *)(uintptr_t)c[34];
	for (i = 0; i < n; i++) {
		VAWB_TOP();
		gr_fuzz_ctx();
		memcpy(pstSecAwbOri, pstMainAwbOri, 512);
		if (i % 11 == 8) gr_fuzz_stats();
		if (i % 11 == 8) { gr_cmp(8, "get_statistics", vgr_tisp_awb_get_statistics, vgr_c_stats, (u32)(uintptr_t)stats, (u32)(uintptr_t)c, 0, 0, VAWB_CSP); }
		if (i % 11 == 9) {
			gr_fuzz_stats();
			gr_cmp(9, "sat_weight", vgr_tisp_awb_sat_weight, gr_c_sat, c[39], c[40], c[41], c[42], (u32)(uintptr_t)gr_sat_area);
		}
		switch (i % 7) {
		case 0: vawb_s_tisp_awb_set_gain((u32)(uintptr_t)c, GRR() & 1, 0, 0, VAWB_CSP); break;
		case 1: vawb_s_tisp_awb_set_regional_threshold((u32)(uintptr_t)c, GRR() & 1, 0, 0, VAWB_CSP); break;
		case 2: vawb_s_tisp_awb_set_lum_th_freq((u32)(uintptr_t)c, GRR() & 1, 0, 0, VAWB_CSP); break;
		case 3: vawb_s_tisp_awb_tgain_update((GRR() % 6 == 0) ? 256 + (GRR() & 1) : GRR() & 1, GRR(), GRR() % 14 << 16 | (u32)gr_val(0xffff), 0, VAWB_CSP); break;
		case 4: gr_cmp_ret(4, "simple_intp", vgr_tisp_simple_intp_int16, gr_c_intp, GRR() % 14, gr_val(0xffff), (u32)(uintptr_t)(tbl + GRR() % 100)); break;
		case 5: gr_cmp(5, "set_awb_trig", vgr_system_reg_set_awb_trig, gr_c_trig, GRR() % 5, GRR() % 3, 0, 0, VAWB_CSP); break;
		default: if (GRR() & 1) gr_cmp(6, "ae_main_mean", vgr_tisp_ae_main_mean_update, gr_c_aemain, (u32)(uintptr_t)&gr_ae_loc[0], (u32)(uintptr_t)&gr_ae_loc[1], 0, 0, VAWB_CSP);
			else gr_cmp(7, "ae_sec_mean", vgr_tisp_ae_sec_mean_update, gr_c_aesec, (u32)(uintptr_t)&gr_ae_loc[0], (u32)(uintptr_t)&gr_ae_loc[1], 0, 0, VAWB_CSP);
		}
	}
	}
	printf("gain_chain C vs OEM: %lu calls, %lu differ (set_gain %lu/%lu regional %lu/%lu lum_th_freq %lu/%lu tgain %lu/%lu intp %lu/%lu trig %lu/%lu ae_mean %lu/%lu %lu/%lu statistics %lu/%lu sat_weight %lu/%lu)\n",
	       gr_n[0] + gr_n[1] + gr_n[2] + gr_n[3] + gr_n[4] + gr_n[5] + gr_n[6] + gr_n[7] + gr_n[8] + gr_n[9],
	       gr_bad[0] + gr_bad[1] + gr_bad[2] + gr_bad[3] + gr_bad[4] + gr_bad[5] + gr_bad[6] + gr_bad[7] + gr_bad[8] + gr_bad[9],
	       gr_n[0], gr_bad[0], gr_n[1], gr_bad[1], gr_n[2], gr_bad[2], gr_n[3], gr_bad[3], gr_n[4], gr_bad[4], gr_n[5], gr_bad[5],
	       gr_n[6], gr_bad[6], gr_n[7], gr_bad[7], gr_n[8], gr_bad[8], gr_n[9], gr_bad[9]);
}
#endif


static ucontext_t mainctx, runctx;
static int g_frames = 50, g_trace;
static u32 g_r, g_g, g_b;
static void run(void)
{
	u32 *c = pstMainAwbOri, f, i;

#ifdef GR_REF_INC
	gr_ae_setup();
#endif
	vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	*(u16 *)(uintptr_t)c[49] = 3840; *(u16 *)((uintptr_t)c[49] + 2) = 2160;
	vawb_s_tisp_awb_params_refresh((u32)(uintptr_t)c, 0, tparamsN[0] + 4288, 0, VAWB_CSP);
	vawb_s_tisp_awb_set_hardware_param((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	vawb_s_tisp_awb_set_gain((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	printf("init faults=%u ct=%u g9=%u,%u reg=%#x,%#x frz=%u\n", vawb_faults, *(u32 *)(uintptr_t)c[7],
	       ((u32 *)(uintptr_t)c[9])[0], ((u32 *)(uintptr_t)c[9])[1], reg4004, reg4008, *(u8 *)(uintptr_t)c[119]);
	vawb_s_tisp_awb_main_ev_update(3000U << 10, 0, 0, 0, VAWB_CSP);
	for (i = 0; i < sizeof(stats) / 16; i++) {	/* 5 x 22-bit fields per 16-byte zone record */
		u32 *w = (u32 *)(stats + i * 16), n = 200;
		w[0] = (g_r & 0x3fffff) | (g_g << 22);
		w[1] = ((g_g >> 10) & 0xfff) | (g_b << 12);
		w[2] = ((g_b >> 20) & 3) | (0 << 2) | (n << 24);
		w[3] = (n >> 8) & 0x3fff;
	}
	for (f = 0; f < (u32)g_frames; f++) {
		VAWB_TOP();
		vawb_s_tisp_awb_get_statistics((u32)(uintptr_t)stats, (u32)(uintptr_t)c, 0, 0, VAWB_CSP);
		if (g_trace && f == 0) { vawb_tn = 0; vawb_tarmed = 1; }
		VAWB_TOP();
		MAINPROC(0, 0, 0, 0, VAWB_CSP);
#ifdef LA_REF_INC	/* the C process calls its own long_alogrithm: run the comparing wrapper on the same context once per frame as well */
		vawb_s_tisp_awb_long_alogrithm((u32)(uintptr_t)c, (u32)(uintptr_t)pstMainAwbCtDetectOri, 0, 0, VAWB_CSP);
#endif
		vawb_tarmed = 0;
		if (f < 2) {
			u16 *s123 = (u16 *)(uintptr_t)c[123]; u16 *s4 = (u16 *)(uintptr_t)c[4];
			printf("  c123=%u,%u,%u,%u,%u,%u c100=%u c103=%u c118=%u c120=%u c4=%u,%u,%u,%u\n", s123[0], s123[1], s123[2], s123[3], s123[4], s123[5],
			       *(u8 *)(uintptr_t)c[100], *(u8 *)(uintptr_t)c[103], *(u8 *)(uintptr_t)c[118], *(u8 *)(uintptr_t)c[120], s4[0], s4[1], s4[2], s4[3]);
		}
		if (f < 3 || f % 10 == 9)
			printf("f%u faults=%u loops=%u ct=%u g9=%u,%u reg=%#x,%#x\n", f, vawb_faults, vawb_loop_trips,
			       *(u32 *)(uintptr_t)c[7], ((u32 *)(uintptr_t)c[9])[0], ((u32 *)(uintptr_t)c[9])[1], reg4004, reg4008);
	}
	if (g_trace) { printf("trace:"); for (i = 0; i < vawb_tn; i++) printf(" %x", vawb_tbuf[i]); printf("\n"); }
#ifdef CTD_REF_INC
	printf("ct_detect C vs OEM: %lu calls, %lu differ\n", ctd_n, ctd_bad);
#endif
#ifdef LA_REF_INC
	printf("long_alogrithm C vs OEM: %lu calls, %lu differ\n", la_n, la_bad);
#endif
#ifdef GR_REF_INC
	gr_direct();
#endif
}

#define VAWB_ONE (64 + 60328 + 4752 + 512 + 136 + 356)
/* replay of a device dump (/proc/t40_vawb_dump) */
static u8 *g_dump;
static void replay(void)
{
	u32 *c = pstMainAwbOri, *h = (u32 *)g_dump, i, d_in = 0, d_out = 0, first = ~0U;
	u8 *d = g_dump + 64;
	u32 *dctx = (u32 *)(d + 60328 + 4752);

	vawb_s_tisp_awb_params_transmit((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	for (i = 0; i < 128; i++) {	/* same layout: device ctx[i] - dev base == host ctx[i] - host base */
		u32 dv = dctx[i], hv = c[i], ok;
		if (dv >= h[1] && dv < h[1] + 60328) ok = hv - (u32)(uintptr_t)inter == dv - h[1];
		else if (dv >= h[2] && dv < h[2] + 4752) ok = hv - (u32)(uintptr_t)outer == dv - h[2];
		else ok = dv == 0 && hv == 0;
		if (!ok) printf("ctx[%u] dev %#x host %#x\n", i, dv, hv);
	}
	memcpy(inter, d, 60328); memcpy(outer, d + 60328, 4752);
	vawb_tn = 0; vawb_tarmed = g_trace;
	VAWB_TOP();
	MAINPROC(0, 0, 0, 0, VAWB_CSP);
	vawb_tarmed = 0;
	if (getenv("REPS")) {	/* time per process on this state (CONSEC=1: carried on), result restored afterwards */
		static u8 ri[60328], ro[4752];
		int r, n = atoi(getenv("REPS"));
		struct timespec t0, t1;

		memcpy(ri, inter, sizeof(ri)); memcpy(ro, outer, sizeof(ro));
		clock_gettime(CLOCK_MONOTONIC, &t0);
		for (r = 0; r < n; r++) {
			if (!getenv("CONSEC")) { memcpy(inter, d, 60328); memcpy(outer, d + 60328, 4752); }
			VAWB_TOP();
			MAINPROC(0, 0, 0, 0, VAWB_CSP);
		}
		clock_gettime(CLOCK_MONOTONIC, &t1);
		printf("REPS %d: %.1f us per process\n", n, ((t1.tv_sec - t0.tv_sec) * 1e9 + (t1.tv_nsec - t0.tv_nsec)) / 1e3 / n);
		memcpy(inter, ri, sizeof(ri)); memcpy(outer, ro, sizeof(ro));
	}
#ifdef CTD_REF_INC
	printf("ct_detect C vs OEM: %lu calls, %lu differ\n", ctd_n, ctd_bad);
#endif
#ifdef LA_REF_INC
	printf("long_alogrithm C vs OEM: %lu calls, %lu differ\n", la_n, la_bad);
#endif
	for (i = 0; i < 60328; i++) if (inter[i] != g_dump[VAWB_ONE + i]) { d_in++; if (first == ~0U) first = i; }
	for (i = 0; i < 60328; i += 4)	/* the differing words: host vs device, and the ctx slot that owns them */
		if (*(u32 *)(inter + i) != *(u32 *)(g_dump + VAWB_ONE + i)) {
			u32 k, own = ~0U;
			for (k = 0; k < 128; k++) if (c[k] >= (u32)(uintptr_t)inter && c[k] - (u32)(uintptr_t)inter <= i && (own == ~0U || c[k] > c[own])) own = k;
			printf("  inter+%#x host %#x device %#x (ctx[%u]+%u)\n", i, *(u32 *)(inter + i), *(u32 *)(g_dump + VAWB_ONE + i), own, own == ~0U ? 0 : i - (c[own] - (u32)(uintptr_t)inter));
		}
	for (i = 0; i < 4752; i++) if (outer[i] != g_dump[VAWB_ONE + 60328 + i]) d_out++;
	printf("replay frame %u: faults=%u loops=%u ct=%u g9=%u,%u reg=%#x,%#x  diff vs device: inter %u B (first %#x) outer %u B\n",
	       h[5], vawb_faults, vawb_loop_trips, *(u32 *)(uintptr_t)c[7], ((u32 *)(uintptr_t)c[9])[0],
	       ((u32 *)(uintptr_t)c[9])[1], reg4004, reg4008, d_in, first, d_out);
	for (i = 104; i <= 106; i++) {
		u32 k, *a = (u32 *)(uintptr_t)c[i];
		printf("ctx[%u]:", i);
		for (k = 0; k < 15; k++) printf(" %u", a[k]);
		printf("\n");
	}
	if (g_trace > 1) { printf("trace:"); for (i = 0; i < vawb_tn; i++) printf(" %x", vawb_tbuf[i]); printf("\n"); }
}
static void load(const char *fn, u8 *dst, long off, u32 n)
{
	FILE *f = fopen(fn, "rb");

	if (!f || fseek(f, off, SEEK_SET) || fread(dst, 1, n, f) != n) { printf("read %s failed\n", fn); exit(2); }
	fclose(f);
}

#ifdef ALIGN_TRAP	/* -fsanitize=alignment -fsanitize-trap=alignment: count trapping PCs, step over ud2 */
#include <signal.h>
#include <ucontext.h>
static uintptr_t at_pc[512]; static unsigned long at_n[512];
static void at_handler(int sig, siginfo_t *si, void *uc_)
{
	ucontext_t *uc = uc_; uintptr_t pc = uc->uc_mcontext.gregs[REG_RIP]; unsigned i;
	(void)sig; (void)si;
	for (i = 0; i < 512 && at_pc[i] && at_pc[i] != pc; i++) ;
	if (i < 512) { at_pc[i] = pc; at_n[i]++; }
	uc->uc_mcontext.gregs[REG_RIP] += 2;
}
static void at_report(void)
{
	unsigned i; FILE *f = fopen(getenv("ALIGN_TRAP_OUT") ? getenv("ALIGN_TRAP_OUT") : "/dev/stderr", "w");
	for (i = 0; i < 512 && at_pc[i]; i++) fprintf(f, "%#lx %lu\n", (unsigned long)at_pc[i], at_n[i]);
	fclose(f);
}
#endif
int main(int argc, char **argv)
{
#ifdef ALIGN_TRAP
	{ struct sigaction sa; memset(&sa, 0, sizeof(sa)); sa.sa_sigaction = at_handler; sa.sa_flags = SA_SIGINFO; sigaction(SIGILL, &sa, NULL); atexit(at_report); }
#endif
	if (argc >= 3 && !strcmp(argv[1], "replay")) {
		FILE *f = fopen(argv[2], "rb");
		static u8 buf[VAWB_ONE + 60328 + 4752];

		if (!f || fread(buf, 1, sizeof(buf), f) != sizeof(buf)) { printf("dump short\n"); return 2; }
		g_dump = buf; g_trace = argc > 3 ? atoi(argv[3]) : 0;
		stMainAwbInter = (u32)(uintptr_t)inter; stMainAwbOuter = (u32)(uintptr_t)outer;
		
		stk_lo = mmap(NULL, 0x40000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
		getcontext(&runctx);
		runctx.uc_stack.ss_sp = stk_lo; runctx.uc_stack.ss_size = 0x40000; runctx.uc_link = &mainctx;
		makecontext(&runctx, replay, 0);
		swapcontext(&mainctx, &runctx);
		return 0;
	}
	if (argc < 6) return 2;
	load(argv[1], bank, 16, 0x18ff4);		/* day bank */
	load(argv[2], inter, 0x1d36c, 0xeba8);		/* OEM .data stMainAwbInterOri */
	g_r = strtoul(argv[3], 0, 0); g_g = strtoul(argv[4], 0, 0); g_b = strtoul(argv[5], 0, 0);
	if (argc > 6) g_frames = atoi(argv[6]);
	if (argc > 7) g_trace = atoi(argv[7]);
	stMainAwbInter = (u32)(uintptr_t)inter; stMainAwbOuter = (u32)(uintptr_t)outer;
	tparamsN[0] = (u32)(uintptr_t)bank;
	
	stk_lo = mmap(NULL, 0x40000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
	getcontext(&runctx);
	runctx.uc_stack.ss_sp = stk_lo; runctx.uc_stack.ss_size = 0x40000; runctx.uc_link = &mainctx;
	makecontext(&runctx, run, 0);
	swapcontext(&mainctx, &runctx);
	return 0;
}
