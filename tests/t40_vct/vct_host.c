/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Host run of the translated T40 OEM colour chains (t40_ct_chains): the OEM CCM / BCSH / LSC init
 * (tests/t40_vct/vct_init_gen.inc, host-only) builds the contexts from a real tuning bin exactly
 * like tisp_main_init, then tisp_ct_update / ccm+bcsh ev_update run a CT and EV sweep.  Checks:
 * no guard faults / loop trips, CCM + BCSH register writes change with CT and EV and are
 * idempotent for a repeated CT, the LSC LUT re-interpolates and (with the frame number
 * advanced) streams nodes*3 words through the 0x50020/0x50024 port exactly like the OEM
 * real_write_lut.  64-bit non-PIE build, data below 4 GB (.vdata at 0x30000000).
 *   vct_host <tuning.bin> <oem data.bin> [verbose]
 * (oem data.bin = objcopy -O binary --only-section=.data of the OEM tx-isp-t40.ko)
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
/* bring-up-only parameters of the driver (Kbuild TX_ISP_T40_BRINGUP_PARAMS) */
#define t40_bringup_param(...)
#define t40_bringup_param_named(...)
#define t40_bringup_param_array_named(...)
#define t40_bringup_param_cb(...)
#define t40_bringup_parm_desc(...)
#define scnprintf snprintf
#define printk(...) (harness_verbose ? printf(__VA_ARGS__) : 0)
#define div64_u64(a, b) ((a) / (b))
struct kernel_param { int x; };
struct kernel_param_ops { int (*get)(char *, const struct kernel_param *); };
static int harness_verbose;
#define VD __attribute__((section(".vdata")))
#define in_interrupt() 0
/* AWB objects the shared runtime references (unused here) */
static u32 pstMainAwbOri[128] VD, pstSecAwbOri[128] VD, pstMainAwbCtDetectOri[34] VD;
static u32 stMainAwbInter VD, stMainAwbOuter VD, stSecAwbInter VD, stSecAwbOuter VD;
static u8 pstMainAeOri_storage[0x164] VD, pstSecAeOri_storage[0x164] VD;
static u32 tparamsN[4] VD, awb_algo_comp[64] VD;
static u8 tispinfo[64] VD;
/* colour contexts: OEM layout, in the driver owned by the literal chains */
static u32 pstMainCcmOri_lit[26] VD, pstMainBcshOri_lit[72] VD;
static u32 stMainCcmOuter_lit VD, stMainBcshOuter_lit VD;
static u8 s_bcsh_mjpeg_mode_lit[2] VD, s_bcsh_mjpeg_y_range_low_lit[2] VD;
static u8 s_bcsh_mjpeg_y_range_high_lit[16] VD = { 0xff, 0xff };
/* names of the BCSH context in the driver since the C BCSH chain (tx_isp_t40_bcsh.h): same OEM layout */
#define t40_bcsh_oem_ctx pstMainBcshOri_lit
static const struct { u8 *mjpeg_mode, *mjpeg_y_low, *mjpeg_y_high; } t40_bcsh = {
	s_bcsh_mjpeg_mode_lit, s_bcsh_mjpeg_y_range_low_lit, s_bcsh_mjpeg_y_range_high_lit };
/* the AWB chain's ct_detect is the driver's C code (issue 133); the colour chains never call it */
static int64_t tisp_awb_ct_detect(uintptr_t a0, uintptr_t a1, uint32_t a2) { abort(); }
/* host-only objects of the OEM LSC init */
static u32 vct_lsc_tool_para[2] VD, vct_lsc_gain[2] VD, vct_lsc_width[2] VD, vct_lsc_height[2] VD;
static u16 vct_lsc_wdr_en VD;
static u8 h_oem_data[0x2e640] __aligned(16) VD;	/* whole OEM .data section */
static u8 bank[0x19000] __aligned(16) VD;
static u8 h_pool[0x40000] __aligned(16) VD;
static u32 h_pool_used;
/* register write log */
static u32 nreg, nreg_ccm, nreg_bcsh, nreg_lsc_data, reg_last[0x40000 / 4];
static u32 lsc_ctrl_seq[8], lsc_ctrl_n, lsc_words_between;
static u32 ccm_sig, bcsh_sig;
static void private_complete(u32 c) { }
static int system_reg_write(u32 a, u32 v)
{
	nreg++;
	if (a < sizeof(reg_last)) reg_last[a / 4] = v;
	if (a >= 0xb000 && a < 0xb100) { nreg_ccm++; ccm_sig = ccm_sig * 31 + v + a; }	/* CCM matrix block */
	if (a >= 0x11000 && a < 0x11100) { nreg_bcsh++; bcsh_sig = bcsh_sig * 31 + v + a; }	/* BCSH block */
	if (a == 0x50020 && lsc_ctrl_n < ARRAY_SIZE(lsc_ctrl_seq)) lsc_ctrl_seq[lsc_ctrl_n++] = v;
	if (a == 0x50024) { nreg_lsc_data++; if (lsc_ctrl_n == 1) lsc_words_between++; }
	if (harness_verbose > 1) printf("    reg %#x = %#x\n", a, v);
	return 0;
}
static u32 harness_top40 = 0x7fd0000dU;	/* vendor TOP (a14 regs2_V): CCM/LSC/BCSH/CLM enabled */
static int system_reg_read(u32 a) { return a == 0x40 ? (int)harness_top40 : 0; }
static int tisp_event_push(u32 a, u32 b) { return 0; }
static int tisp_awb_main_interrupt_static(void) { return 0; }
static long tisp_awb_main_process(void) { return 0; }
static u8 *stk_lo;
static u32 harness_ok(u32 a, u32 align)
{
	if (a & align) return 0;
	if (a >= (u32)(uintptr_t)stk_lo && a < (u32)(uintptr_t)stk_lo + 0x40000) return 1;
	return a >= 0x30000000U && a < 0x30400000U;
}
/* driver C helpers used by tx_isp_t40_awb_*.inc (included from the top part); bodies from CFIX_INC below */
static int regtrace_is_kernel_ptr(const void *p) { return p != 0; }
static int regtrace_is_kernel_ptr_any(const void *p) { return p != 0; }
static bool regtrace_enable_isp_3a_diag;
int32_t fix_point_div_32(int32_t, int32_t, int32_t);
int64_t fix_point_div(int32_t, int32_t, int32_t, int32_t, int32_t, int32_t);
int32_t fix_point_mult2_32(int32_t, int32_t, int32_t);
int32_t fix_point_mult3_32(uint32_t, uint32_t, uint32_t, uint32_t);
#include VAWB_TOP
#include CFIX_INC
static u64 vawb_x___private_spin_lock_irqsave(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { vawb_sw(a1, 0, 6); return 0; }
static u64 vawb_x_private_spin_unlock_irqrestore(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return 0; }
static u64 vawb_x_private_spin_lock_init(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return 0; }
static u32 clm_calls;
static u64 vawb_s_tisp_clm_ct_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { clm_calls++; return 0; }
static u64 vawb_x_private_vmalloc(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 p = (u32)(uintptr_t)h_pool + h_pool_used;

	if (h_pool_used + a0 + 16 > sizeof(h_pool)) { printf("pool exhausted\n"); exit(2); }
	h_pool_used += (a0 + 15) & ~15U;
	return p;
}
static u64 vawb_x_private_kmalloc(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp) { return vawb_x_private_vmalloc(a0, 0, 0, 0, 0); }
static u64 vawb_x___div64_32(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u64 *n = (u64 *)(uintptr_t)a0; u64 r = *n % a1;
	*n /= a1;
	return r;
}
#include VAWB_INC
#include VAWB_INIT

#define VAWB_CSP ((u32)(uintptr_t)vawb_argarea)
#define VAWB_TOP() (vawb_loop_n = 0)
static ucontext_t mainctx, runctx;
static int fails;
#define CHECK(c, ...) do { if (!(c)) { fails++; printf("FAIL: " __VA_ARGS__); printf("\n"); } } while (0)

static void ct_update(u32 ct)
{
	VAWB_TOP();
	vawb_tisp_ct_update(ct, 0, 0, 0, VAWB_CSP);
	if (vct_lsc_lut_write_times[0]) {	/* OEM tisp_hardware_reg_refresh */
		VAWB_TOP();
		vawb_tisp_lsc_real_write_lut(0, 0, 0, 0, VAWB_CSP);
	}
}
static void ev_update(u32 ev)
{
	VAWB_TOP();
	vawb_tisp_ccm_main_ev_update(ev, 0, 0, 0, VAWB_CSP);
	VAWB_TOP();
	vawb_tisp_bcsh_main_ev_update(ev, 0, 0, 0, VAWB_CSP);
}
static u16 lsc_nodes(void) { return *(u16 *)(uintptr_t)(vct_lsc_real_para[0] + 13828); }
static u32 lsc_lut_sig(void)
{
	u32 i, s = 0, *p = (u32 *)(uintptr_t)(vct_lsc_real_para[0] + 13832);

	for (i = 0; i < lsc_nodes() * 3U; i++) s = s * 31 + p[i];
	return s;
}
static void run(void)
{
	static const u32 cts[] = { 2800, 4000, 5000, 5000, 6500, 8000, 4000 };
	u32 i, sig_prev = 0, bsig_prev = 0, lut_prev, n0, n1, nodes;
	u32 ccm_sigs[ARRAY_SIZE(cts)], bcsh_sigs[ARRAY_SIZE(cts)], lut_sigs[ARRAY_SIZE(cts)];

	/* OEM tisp_main_init order: tisp_lsc_init(0, w, h), tisp_bcsh_main_init(2), tisp_ccm_main_init() */
	VAWB_TOP(); vawb_tisp_lsc_init(0, 3840, 2160, 0, VAWB_CSP);
	VAWB_TOP(); vawb_tisp_bcsh_main_init(2, 0, 0, 0, VAWB_CSP);
	VAWB_TOP(); vawb_tisp_ccm_main_init(0, 0, 0, 0, VAWB_CSP);
	nodes = lsc_nodes();
	printf("init: faults=%u loops=%u regs=%u ccm=%u bcsh=%u lsc nodes=%u lscdata=%u ccm_ori[6..8]=%u,%u,%u bcsh[41..43]=%u,%u,%u\n",
	       vawb_faults, vawb_loop_trips, nreg, nreg_ccm, nreg_bcsh, nodes, nreg_lsc_data,
	       *(u16 *)(uintptr_t)pstMainCcmOri_lit[6], *(u16 *)(uintptr_t)pstMainCcmOri_lit[7], *(u16 *)(uintptr_t)pstMainCcmOri_lit[8],
	       *(u16 *)(uintptr_t)pstMainBcshOri_lit[41], *(u16 *)(uintptr_t)pstMainBcshOri_lit[42], *(u16 *)(uintptr_t)pstMainBcshOri_lit[43]);
	CHECK(vawb_faults == 0, "init faults %u", vawb_faults);
	CHECK(stMainCcmOuter_lit && stMainBcshOuter_lit && vct_lsc_real_para[0] && vct_lsc_awdr_para[0], "contexts not built");
	CHECK(nodes && nodes <= 1152 && nreg_lsc_data == nodes * 3U, "lsc init wrote %u words for %u nodes", nreg_lsc_data, nodes);
	CHECK(lsc_ctrl_n == 2 && lsc_ctrl_seq[0] == 0x101 && lsc_ctrl_seq[1] == (((u32)nodes - 1) << 16 | 0x102),
	      "lsc port protocol %#x %#x", lsc_ctrl_seq[0], lsc_ctrl_seq[1]);
	CHECK(nreg_ccm > 0 && nreg_bcsh > 0, "init ccm=%u bcsh=%u writes", nreg_ccm, nreg_bcsh);
	ev_update(3000U << 10);
	/* CT sweep, vendor behaviour (fnum never advances: the LSC LUT re-interpolates, no port write) */
	lut_prev = lsc_lut_sig();
	for (i = 0; i < ARRAY_SIZE(cts); i++) {
		n0 = nreg_lsc_data; nreg_ccm = nreg_bcsh = 0;
		ct_update(cts[i]);
		ccm_sigs[i] = ccm_sig; bcsh_sigs[i] = bcsh_sig; lut_sigs[i] = lsc_lut_sig();
		printf("ct %5u: ccm writes=%u sig=%08x bcsh writes=%u sig=%08x lsc ct=%u flag=%u lut sig=%08x wt=%u port=%u faults=%u loops=%u\n",
		       cts[i], nreg_ccm, ccm_sig, nreg_bcsh, bcsh_sig, vct_lsc_ct, vct_lsc_ct_flag[0], lut_sigs[i],
		       vct_lsc_lut_write_times[0], nreg_lsc_data - n0, vawb_faults, vawb_loop_trips);
		CHECK(nreg_lsc_data == n0, "vendor mode wrote the LSC port at ct %u", cts[i]);
		(void)sig_prev; (void)bsig_prev; (void)lut_prev;
	}
	CHECK(ccm_sigs[0] != ccm_sigs[5], "CCM does not change with CT (2800 vs 8000)");
	CHECK(ccm_sigs[2] == ccm_sigs[3], "CCM not idempotent for a repeated CT");
	CHECK(bcsh_sigs[0] != bcsh_sigs[5], "BCSH does not change with CT");
	CHECK(lut_sigs[0] != lut_sigs[5], "LSC LUT does not change with CT");
	CHECK(lut_sigs[1] == lut_sigs[6], "LSC LUT not reproducible for the same CT");
	CHECK(vct_lsc_lut_write_times[0] == 0, "vendor mode armed an LSC write (fnum stuck at 0)");
	/* EV sweep */
	for (i = 0; i < 4; i++) {
		static const u32 evs[] = { 200U << 10, 3000U << 10, 60000U << 10, 3000U << 10 };

		nreg_ccm = nreg_bcsh = 0;
		ev_update(evs[i]);
		printf("ev %6u: ccm writes=%u sig=%08x bcsh writes=%u sig=%08x faults=%u\n", evs[i] >> 10, nreg_ccm, ccm_sig, nreg_bcsh, bcsh_sig, vawb_faults);
		if (i == 0) { sig_prev = ccm_sig; bsig_prev = bcsh_sig; }
	}
	CHECK(sig_prev != ccm_sig || bsig_prev != bcsh_sig, "neither CCM nor BCSH reacts to EV");
	/* t40_ct_fnum_tick: the frame number advances -> OEM deferral fires, LUT streamed once */
	n0 = nreg_lsc_data; lsc_ctrl_n = 0;
	for (i = 0; i < 8; i++) {
		vct_fnum[0]++;
		ct_update(i & 1 ? 2800 : 8000);
	}
	n1 = nreg_lsc_data - n0;
	printf("fnum tick: lsc port words=%u (%u per LUT) wt=%u frm_saved=%llu faults=%u loops=%u clm=%u\n",
	       n1, nodes * 3U, vct_lsc_lut_write_times[0], (unsigned long long)vct_lsc_frm_num_saved[0], vawb_faults, vawb_loop_trips, clm_calls);
	CHECK(n1 && n1 % (nodes * 3U) == 0, "deferred LSC write streamed %u words", n1);
	CHECK(vawb_faults == 0 && vawb_loop_trips == 0, "faults=%u loops=%u", vawb_faults, vawb_loop_trips);
	printf("%s\n", fails ? "RESULT: FAIL" : "RESULT: PASS");
}
static void load(const char *fn, u8 *dst, long off, u32 n)
{
	FILE *f = fopen(fn, "rb");

	if (!f || fseek(f, off, SEEK_SET) || fread(dst, 1, n, f) != n) { printf("read %s failed (need %u bytes at offset %ld: the OEM .data of the vendor module this test was written for)\n", fn, n, off); exit(2); }
	fclose(f);
}

int main(int argc, char **argv)
{
	if (argc < 3) return 2;
	setvbuf(stdout, NULL, _IONBF, 0);
	load(argv[1], bank, 16, 0x18ff4);		/* day bank */
	load(argv[2], h_oem_data, 0, sizeof(h_oem_data));	/* OEM .data (stMainCcmInterOri, stMainBcshInterOri, BT709 tables) */
	if (argc > 3) harness_verbose = atoi(argv[3]);
	tparamsN[0] = (u32)(uintptr_t)bank;
	stk_lo = mmap(NULL, 0x40000, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_32BIT, -1, 0);
	getcontext(&runctx);
	runctx.uc_stack.ss_sp = stk_lo; runctx.uc_stack.ss_size = 0x40000; runctx.uc_link = &mainctx;
	makecontext(&runctx, run, 0);
	swapcontext(&mainctx, &runctx);
	return fails ? 1 : 0;
}
