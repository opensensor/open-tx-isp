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
static u32 reg4004, reg4008;
static void private_complete(u32 c) { }
static int system_reg_write(u32 a, u32 v)
{
	nreg++;
	if (a == 0x4004) reg4004 = v;
	if (a == 0x4008) reg4008 = v;
	return 0;
}
static int system_reg_read(u32 a) { return 0; }
static int tisp_event_push(u32 a, u32 b) { return 0; }
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
#include VAWB_TOP
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
#define VAWB_TOP() (vawb_loop_n = 0)
static ucontext_t mainctx, runctx;
static int g_frames = 50, g_trace;
static u32 g_r, g_g, g_b;
static void run(void)
{
	u32 *c = pstMainAwbOri, f, i;

	vawb_tisp_awb_params_transmit((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	*(u16 *)(uintptr_t)c[49] = 3840; *(u16 *)((uintptr_t)c[49] + 2) = 2160;
	vawb_tisp_awb_params_refresh((u32)(uintptr_t)c, 0, tparamsN[0] + 4288, 0, VAWB_CSP);
	vawb_tisp_awb_set_hardware_param((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	vawb_tisp_awb_set_gain((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
	printf("init faults=%u ct=%u g9=%u,%u reg=%#x,%#x frz=%u\n", vawb_faults, *(u32 *)(uintptr_t)c[7],
	       ((u32 *)(uintptr_t)c[9])[0], ((u32 *)(uintptr_t)c[9])[1], reg4004, reg4008, *(u8 *)(uintptr_t)c[119]);
	vawb_tisp_awb_main_ev_update(3000U << 10, 0, 0, 0, VAWB_CSP);
	for (i = 0; i < sizeof(stats) / 16; i++) {	/* 5 x 22-bit fields per 16-byte zone record */
		u32 *w = (u32 *)(stats + i * 16), n = 200;
		w[0] = (g_r & 0x3fffff) | (g_g << 22);
		w[1] = ((g_g >> 10) & 0xfff) | (g_b << 12);
		w[2] = ((g_b >> 20) & 3) | (0 << 2) | (n << 24);
		w[3] = (n >> 8) & 0x3fff;
	}
	for (f = 0; f < (u32)g_frames; f++) {
		VAWB_TOP();
		vawb_tisp_awb_get_statistics((u32)(uintptr_t)stats, (u32)(uintptr_t)c, 0, 0, VAWB_CSP);
		if (g_trace && f == 0) { vawb_tn = 0; vawb_tarmed = 1; }
		VAWB_TOP();
		vawb_tisp_awb_main_process(0, 0, 0, 0, VAWB_CSP);
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
}

#define VAWB_ONE (64 + 60328 + 4752 + 512 + 136 + 356)
/* replay of a device dump (/proc/t40_vawb_dump) */
static u8 *g_dump;
static void replay(void)
{
	u32 *c = pstMainAwbOri, *h = (u32 *)g_dump, i, d_in = 0, d_out = 0, first = ~0U;
	u8 *d = g_dump + 64;
	u32 *dctx = (u32 *)(d + 60328 + 4752);

	vawb_tisp_awb_params_transmit((u32)(uintptr_t)c, 0, 0, 0, VAWB_CSP);
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
	vawb_tisp_awb_main_process(0, 0, 0, 0, VAWB_CSP);
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
			vawb_tisp_awb_main_process(0, 0, 0, 0, VAWB_CSP);
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
		memcpy(vawb_wide_tele_para, vawb_wide_tele_para_t8416, 144); vawb_wide_tele_para[0] = 0;
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
	memcpy(vawb_wide_tele_para, vawb_wide_tele_para_t8416, 144); vawb_wide_tele_para[0] = 0;
	stk_lo = mmap(NULL, 0x40000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
	getcontext(&runctx);
	runctx.uc_stack.ss_sp = stk_lo; runctx.uc_stack.ss_size = 0x40000; runctx.uc_link = &mainctx;
	makecontext(&runctx, run, 0);
	swapcontext(&mainctx, &runctx);
	return 0;
}
