/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 vendor AWB: the OEM AWB chain as hand-translated C (tx_isp_t40_awb_*.inc).  Source module: Eufy T8416
 * OEM tx-isp-t40.ko (with symbols).
 *
 * C (bit-exact with the OEM, tests/t40_vawb_host.sh): tisp_awb_get_statistics (IRQ), tisp_awb_main_process
 * (long_par_update, spec_calculate, long_alogrithm -> ct_detect, sat_weight, set_gain, event 13), and for init /
 * day-night / EV: params_transmit, params_refresh, set_hardware_param, dn_params_refresh, main_ev_update,
 * ev_update_Ywgt, tgain_update (tx_isp_t40_awb_*.inc).  The CT/EV consumers of event 13 / 8 are the checked C
 * chain in tx_isp_t40_ct_chain.h; no OEM code is translated mechanically in the driver any more (#85).
 * The guarded load/store/call helpers below (vawb_lw, vawb_call, vf_*, ...) are the runtime of the old
 * mechanical translation.  The driver no longer uses them (the compiler drops them); tests/t40_vawb_host.sh
 * keeps them because its bit-exact modes (LA_REF / CTD_REF / GR_REF) run the translated OEM code of older
 * commits against the C.
 * Included at the end of tx_isp_t40_recovered.c.
 */
#ifndef TX_ISP_T40_VAWB_H
#define TX_ISP_T40_VAWB_H

typedef u64 (*vawb_fn_t)(u32, u32, u32, u32, u32);

static u32 vawb_faults;
static u32 vawb_calls, vawb_frames, vawb_irqs;
static const char vawb_str[] = "t40-vawb";
/* caller-saved register file across translated calls (OEM IPA-RA, see asm2c.py), one per context:
 * the AWB statistics run in the ISP IRQ while the process chain runs in the event thread */
static u32 vawb_rf_thr[32], vawb_rf_irq[32];
#define vawb_rf (in_interrupt() ? vawb_rf_irq : vawb_rf_thr)
module_param_named(t40_vawb_faults, vawb_faults, uint, 0444);
module_param_named(t40_vawb_frames, vawb_frames, uint, 0444);

/* OEM private state of the chain (not shared with other driver code) */
static u32 vawb_tawb_custom_en[2];   /* host harness copy (tests/t40_vawb_host.sh patches this line); the driver build aliases the real array below */
static u32 *const vawb_tawb_custom_en_host __attribute__((unused)) = vawb_tawb_custom_en;
/* #65: OEM tawb_custom_en[2] is ONE array: tisp_awb_algo_init (custom AWB library registered, ioctl 0xc0045425) writes it and
 * tisp_awb_main_process reads it to complete(awb_algo_comp) after the algorithm step.  The private copy used here before was never
 * written, so the user-space AWB worker (0xc0045423) never woke up: in the driver build alias the driver's array (awb_algo_enable). */
#ifdef awb_algo_enable
#define vawb_tawb_custom_en ((u32 *)awb_algo_enable)
#endif
/* tisp_awb_main_process: frame counter (0..50) and the OEM debug counter of finished process calls */
static u8 vawb_awb_num;
static u32 vawb_peter_test_count[2];

static noinline void vawb_fault_note(u32 addr, u32 pc)
{
	if (vawb_faults++ < 8)
		printk(KERN_WARNING "t40: vendor AWB guard addr=%#x off=%u from=%pS\n",
		       addr, pc, __builtin_return_address(0));
}

static inline bool vawb_ok(u32 a, u32 align)
{
	return a >= 0x80000000U && a < 0xfffff000U && !(a & align);
}

#define VAWB_LD(name, type, align) \
static noinline u32 vawb_##name(u32 a, u32 pc) \
{ \
	if (unlikely(!vawb_ok(a, align))) { vawb_fault_note(a, pc); return 0; } \
	return (u32)*(volatile type *)(uintptr_t)a; \
}
VAWB_LD(lw, u32, 3)
VAWB_LD(lhu, u16, 1)
VAWB_LD(lbu, u8, 0)
static inline u32 vawb_lh(u32 a, u32 pc) { return (u32)(s32)(s16)vawb_lhu(a, pc); }
static inline u32 vawb_lb(u32 a, u32 pc) { return (u32)(s32)(signed char)vawb_lbu(a, pc); }

static uint t40_vawb_debug;
static u32 vawb_argarea[16] __aligned(8);
static u32 vawb_wild;
static noinline bool vawb_st_wild(u32 a, u32 pc)
{
	u32 in = (u32)stMainAwbInter, out = (u32)stMainAwbOuter, sp = (u32)(uintptr_t)&in;

	if ((in && a - in < 60328U) || (out && a - out < 4752U) ||
	    a - (u32)(uintptr_t)pstMainAwbOri < sizeof(pstMainAwbOri) ||
	    a - (u32)(uintptr_t)pstMainAwbCtDetectOri < sizeof(pstMainAwbCtDetectOri) ||
	    (a & ~(THREAD_SIZE - 1)) == (sp & ~(THREAD_SIZE - 1)) ||
	    a - (u32)(uintptr_t)vawb_tawb_custom_en < 8U || a - (u32)(uintptr_t)&vawb_awb_num < 1U ||
	    a - (u32)(uintptr_t)vawb_peter_test_count < 8U ||
	    a - (u32)(uintptr_t)vawb_argarea < sizeof(vawb_argarea))
		return false;
	if (vawb_wild++ < 12)
		printk(KERN_WARNING "t40: vawb wild store %#x pc=%#x (skipped)\n", a, pc);
	return true;
}
#define VAWB_ST(name, type, align) \
static noinline void vawb_##name(u32 a, u32 v, u32 pc) \
{ \
	if (unlikely(!vawb_ok(a, align))) { vawb_fault_note(a, pc); return; } \
	if (unlikely(t40_vawb_debug >= 2) && vawb_st_wild(a, pc)) return; \
	*(volatile type *)(uintptr_t)a = (type)v; \
}
VAWB_ST(sw, u32, 3)
VAWB_ST(sh, u16, 1)
VAWB_ST(sb, u8, 0)

/* accesses to the function's own frame array vframe[] (generated "sp + N"): always valid and aligned */
#define vf_lw(a)  (*(volatile u32 *)(uintptr_t)(a))
#define vf_lhu(a) ((u32)*(volatile u16 *)(uintptr_t)(a))
#define vf_lbu(a) ((u32)*(volatile u8 *)(uintptr_t)(a))
#define vf_lh(a)  ((u32)(s32)*(volatile s16 *)(uintptr_t)(a))
#define vf_lb(a)  ((u32)(s32)*(volatile s8 *)(uintptr_t)(a))
#define vf_sw(a, v) (*(volatile u32 *)(uintptr_t)(a) = (u32)(v))
#define vf_sh(a, v) (*(volatile u16 *)(uintptr_t)(a) = (u16)(v))
#define vf_sb(a, v) (*(volatile u8 *)(uintptr_t)(a) = (u8)(v))

/* little-endian unaligned word access (lwl/lwr, swl/swr pairs) */
static inline u32 vawb_lwl(u32 a, u32 rt, u32 pc)
{
	u32 k = a & 3, w = vawb_lw(a & ~3U, pc);
	return (rt & (0x00ffffffU >> (8 * k))) | (w << (8 * (3 - k)));
}
static inline u32 vawb_lwr(u32 a, u32 rt, u32 pc)
{
	u32 k = a & 3, w = vawb_lw(a & ~3U, pc);
	return k ? (rt & (0xffffffffU << (8 * (4 - k)))) | (w >> (8 * k)) : w;
}
static inline void vawb_swl(u32 a, u32 rt, u32 pc)
{
	u32 k = a & 3, b = a & ~3U, i;
	for (i = 0; i <= k; i++)
		vawb_sb(b + i, rt >> (8 * (3 - k + i)), pc);
}
static inline void vawb_swr(u32 a, u32 rt, u32 pc)
{
	u32 k = a & 3, i;
	for (i = 0; i < 4 - k; i++)
		vawb_sb(a + i, rt >> (8 * i), pc);
}

/* hi:lo as one u64 (hi in the upper word); x/0 leaves 0 instead of trapping */
static noinline u64 vawb_divu(u32 x, u32 y, u32 pc)
{
	if (unlikely(!y)) { vawb_fault_note(0, pc); return 0; }
	return ((u64)(x % y) << 32) | (x / y);
}
static noinline u64 vawb_divs(u32 x, u32 y, u32 pc)
{
	s32 a = (s32)x, b = (s32)y;
	if (unlikely(!b || (a == INT_MIN && b == -1))) { vawb_fault_note(0, pc); return 0; }
	return ((u64)(u32)(a % b) << 32) | (u32)(a / b);
}

static inline void vawb_fn_enter(void) { vawb_calls++; }

/* label trace (gen.sh VAE_TRACE=<fns>): t40_vawb_trace=1 arms one process call, t40_vawb_tbuf reads it */
static uint t40_vawb_trace;
t40_bringup_param(t40_vawb_trace, uint, 0644);
static u32 vawb_tbuf[256], vawb_tn, vawb_tarmed;
static inline void vawb_trace(u32 pc)
{
	if (unlikely(vawb_tarmed) && vawb_tn < ARRAY_SIZE(vawb_tbuf))
		vawb_tbuf[vawb_tn++] = pc;
}
static int t40_vawb_tbuf_get(char *buf, const struct kernel_param *kp)
{
	int n = 0;
	u32 i;

	for (i = 0; i < vawb_tn && n < PAGE_SIZE - 16; i++)
		n += scnprintf(buf + n, PAGE_SIZE - n, "%x ", vawb_tbuf[i]);
	return n + scnprintf(buf + n, PAGE_SIZE - n, "\n");
}
static const struct kernel_param_ops t40_vawb_tbuf_ops = { .get = t40_vawb_tbuf_get };
module_param_cb(t40_vawb_tbuf, &t40_vawb_tbuf_ops, NULL, 0444);

/* backward-branch budget per top-level call: a loop bound built from a guarded (zeroed) load
 * must not spin the event thread / IRQ forever */
static u32 vawb_loop_n, vawb_loop_trips, vawb_loop_pc;
module_param_named(t40_vawb_loop_trips, vawb_loop_trips, uint, 0444);
t40_bringup_param_named(t40_vawb_loop_pc, vawb_loop_pc, uint, 0444);
#define VAWB_LOOP_LIMIT 2000000U
static noinline bool vawb_loop_trip(u32 pc)
{
	if (vawb_loop_n == VAWB_LOOP_LIMIT + 1U) {
		vawb_loop_pc = pc;
		if (vawb_loop_trips++ < 8)
			printk(KERN_WARNING "t40: vendor AWB loop budget exceeded at %#x\n", pc);
	}
	return true;
}
static inline bool vawb_loop_guard(u32 pc)
{
	return unlikely(++vawb_loop_n > VAWB_LOOP_LIMIT) && vawb_loop_trip(pc);
}
#define VAWB_TOP() (vawb_loop_n = 0)

static noinline u64 vawb_call(u32 tg, u32 a0, u32 a1, u32 a2, u32 a3, u32 sp, u32 pc)
{
	if (unlikely(tg < 0x80000000U || (tg & 3))) {
		vawb_fault_note(tg, pc);
		return 0;
	}
	{
		u64 rv = ((vawb_fn_t)(uintptr_t)tg)(a0, a1, a2, a3, sp);

		vawb_rf[3] = (u32)(rv >> 32);	/* v1 of a 64-bit result (also from the external leaves) */
		return rv;
	}
}

/* ---- external leaves the OEM code calls (same ABI) ---- */
static u64 vawb_x_memcpy(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	if (!vawb_ok(a0, 0) || !vawb_ok(a1, 0) || a2 > 0x10000) { vawb_fault_note(a0, 1); return a0; }
	memcpy((void *)(uintptr_t)a0, (const void *)(uintptr_t)a1, a2);
	return a0;
}
static u64 vawb_x_memset(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	if (!vawb_ok(a0, 0) || a2 > 0x10000) { vawb_fault_note(a0, 2); return a0; }
	memset((void *)(uintptr_t)a0, (int)a1, a2);
	return a0;
}
static u64 vawb_x_private_complete(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	if (vawb_ok(a0, 3))
		private_complete(a0);
	return 0;
}
static u64 vawb_x_system_reg_write(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (u32)system_reg_write(a0, a1);
}
static u64 vawb_x_system_reg_read(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (u32)system_reg_read(a0);
}
static u64 vawb_x_isp_printf(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return 0;
}
/* event 13 (CT -> CCM/LSC/BCSH/CLM) goes to the driver's dispatcher; the CT
 * consumers stay gated by t40_ct_update there */
static u32 vawb_events_seen;
static u64 vawb_x_tisp_event_push(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 id = vawb_lw(a1 + 8, 5);

	vawb_events_seen |= id < 32 ? BIT(id) : BIT(31);
	return (u32)tisp_event_push(a0, a1);
}
static u64 vawb_x___ashldi3(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (((u64)a1 << 32) | a0) << (a2 & 63);
}
static u64 vawb_x___lshrdi3(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (((u64)a1 << 32) | a0) >> (a2 & 63);
}
static u64 vawb_x_div64_u64(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u64 b = ((u64)a3 << 32) | a2;

	if (!b) { vawb_fault_note(0, 4); return 0; }
	return div64_u64(((u64)a1 << 32) | a0, b);
}

/*
 * Issue 133: OEM tisp_awb_ct_detect (2065 insns + six helpers, ~0.45 M OEM instructions per
 * frame) costs about 65 % of the translated AWB process, where every OEM load/store is a guarded
 * call.  The driver's C translation (tx_isp_t40_awb_ctd.inc, same results bit for bit:
 * tests/t40_vawb_host.sh ctd) runs in its place.  Same o32 arguments: a0 = pstMainAwbCtDetectOri,
 * a1 = gains[2], a2 = flags[2]; the caller does not use the return value.
 */
static u64 vawb_s_tisp_awb_ct_detect(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (u64)tisp_awb_ct_detect(a0, a1, a2);
}

#include "tx_isp_t40_awb_stats.inc"
#include "tx_isp_t40_awb_long.inc"
#include "tx_isp_t40_awb_gain.inc"
#include "tx_isp_t40_awb_init.inc"
#include "tx_isp_t40_awb_main.inc"
/* end of the host harness part (tests/t40_vawb_host.sh copies this file up to here) */


/* The translated frames are large (ct_detect + GrayWorld_mode alone ~3.3 KB, the process chain ~6 KB)
 * and the T40 kernel stack is 8 KB.  The per-frame process and the init/day-night refresh run on
 * their own 16 KB stacks: MIPS keeps thread_info in $28, not derived from $sp, so switching $sp
 * for a non-sleeping call is safe (IRQs taken meanwhile nest on this stack). */
#define VAWB_STACK 16384
static u8 *vawb_stk_proc, *vawb_stk_ctl;
static noinline u64 vawb_run_on(u8 *stk, vawb_fn_t fn, u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 *top;
	u64 ret;

	if (!stk)
		return fn(a0, a1, a2, a3, csp);
	top = (u32 *)(stk + VAWB_STACK - 64);
	top[4] = csp;			/* o32: 5th argument at 16($sp) */
	{
		register u32 ra0 asm("$4") = a0;
		register u32 ra1 asm("$5") = a1;
		register u32 ra2 asm("$6") = a2;
		register u32 ra3 asm("$7") = a3;
		register u32 rfn asm("$25") = (u32)(uintptr_t)fn;
		register u32 rv0 asm("$2");
		register u32 rv1 asm("$3");

		asm volatile(
			".set push\n\t.set noreorder\n\t"
			"move	$16, $29\n\t"
			"move	$29, %[top]\n\t"
			"jalr	$25\n\t"
			"nop\n\t"
			"move	$29, $16\n\t"
			".set pop"
			: "=r" (rv0), "=r" (rv1), "+r" (ra0), "+r" (ra1), "+r" (ra2), "+r" (ra3), "+r" (rfn)
			: [top] "r" (top)
			: "$1", "$8", "$9", "$10", "$11", "$12", "$13", "$14", "$15", "$16", "$24",
			  "$31", "hi", "lo", "memory");
		ret = ((u64)rv1 << 32) | rv0;
	}
	return ret;
}
static u8 *vawb_dump;
static void t40_vawb_cleanup(void)
{
	WRITE_ONCE(t40_vawb_live, false);
	if (vawb_dump) {
		remove_proc_entry("t40_vawb_dump", NULL);
		vfree(vawb_dump);
		vawb_dump = NULL;
	}
	if (vawb_stk_proc)
		free_pages((unsigned long)vawb_stk_proc, get_order(VAWB_STACK));
	if (vawb_stk_ctl)
		free_pages((unsigned long)vawb_stk_ctl, get_order(VAWB_STACK));
	vawb_stk_proc = vawb_stk_ctl = NULL;
}
static int vawb_stacks_alloc(void)
{
	/* unmapped (kseg0) pages like a kernel stack: exception entry must not take a TLB miss on $sp */
	if (!vawb_stk_proc)
		vawb_stk_proc = (u8 *)__get_free_pages(GFP_KERNEL, get_order(VAWB_STACK));
	if (!vawb_stk_ctl)
		vawb_stk_ctl = (u8 *)__get_free_pages(GFP_KERNEL, get_order(VAWB_STACK));
	return vawb_stk_proc && vawb_stk_ctl ? 0 : -ENOMEM;
}
#define VAWB_CTL(fn, a0, a1, a2) vawb_run_on(vawb_stk_ctl, fn, a0, a1, a2, 0, VAWB_CSP)
/* bring-up switches: t40_vawb_run bit0 = stats in the AWB IRQ, bit1 = per-frame process;
 * t40_vawb_debug = 1: init steps logged with a pause (kmsg capture before a hang) */
static uint t40_vawb_run = 3;
t40_bringup_param(t40_vawb_run, uint, 0644);
t40_bringup_param(t40_vawb_debug, uint, 0644);
#define VAWB_STEP(n) do { if (t40_vawb_debug) { printk(KERN_WARNING "t40: vawb init step %d faults=%u\n", n, vawb_faults); msleep(400); } } while (0)
#define VAWB_CSP ((u32)(uintptr_t)vawb_argarea)

/* OEM tisp_awb_main_init 0x31530 (frame of the open driver: inter seed =
 * stMainAwbInterOri, byte-identical with the Eufy OEM .data 0x1d36c). */
/* read-only diagnostics: frz byte (*ctx[119]), CT (*ctx[7]), algorithm gains ctx[9][0..1] (Q10),
 * ctx[36]/[37]/[38] words, stats zone 0 of ctx[5] */
static u32 vawb_plane_sum(u32 p)
{
	u32 i, sum = 0;

	if (!vawb_ok(p, 3))
		return 0xdead;
	for (i = 0; i < 225; i++)
		sum += ((u32 *)(uintptr_t)p)[i];
	return sum;
}
static u32 vawb_last_addr;
static int t40_vawb_diag_get(char *buf, const struct kernel_param *kp)
{
	u32 *c = pstMainAwbOri;
	int n;
#define VW(p, i) (vawb_ok((p), 3) ? ((u32 *)(uintptr_t)(p))[i] : 0xdeadU)
	n = scnprintf(buf, PAGE_SIZE, "planes64..68=%u %u %u %u %u 84..88=%u %u %u %u %u raw=%x %x %x %x flag94=%u,%u\n",
		vawb_plane_sum(c[64]), vawb_plane_sum(c[65]), vawb_plane_sum(c[66]), vawb_plane_sum(c[67]), vawb_plane_sum(c[68]),
		vawb_plane_sum(c[84]), vawb_plane_sum(c[85]), vawb_plane_sum(c[86]), vawb_plane_sum(c[87]), vawb_plane_sum(c[88]),
		VW(vawb_last_addr, 0), VW(vawb_last_addr, 1), VW(vawb_last_addr, 2), VW(vawb_last_addr, 3),
		vawb_ok(c[0], 0) ? *(u8 *)(uintptr_t)(c[0] + 94) : 0xdead, vawb_ok(c[0], 0) ? *(u8 *)(uintptr_t)(c[0] + 96) : 0xdead);
	return n + scnprintf(buf + n, PAGE_SIZE - n,
		"frz=%u ct=%u g9=%u,%u g36=%u,%u ctx5=%x,%x,%x,%x faults=%u loops=%u ev=%#x irqs=%u wild=%u\n",
		vawb_ok(c[119], 0) ? *(u8 *)(uintptr_t)c[119] : 0xdead, VW(c[7], 0), VW(c[9], 0), VW(c[9], 1),
		VW(c[36], 0), VW(c[36], 1), VW(c[5], 0), VW(c[5], 1), VW(c[5], 2), VW(c[5], 3),
		vawb_faults, vawb_loop_trips, vawb_events_seen, vawb_irqs, vawb_wild);
#undef VW
}
static const struct kernel_param_ops t40_vawb_diag_ops = { .get = t40_vawb_diag_get };
module_param_cb(t40_vawb_diag, &t40_vawb_diag_ops, NULL, 0444);

static int t40_vawb_main_init(uint32_t a0, uint32_t a1)
{
	uint32_t *ctx = pstMainAwbOri;
	void *outer;

	if (vawb_stacks_alloc())
		return -ENOMEM;
	if (!regtrace_awb_main_inter_alloc())
		return -ENOMEM;
	if (!stMainAwbOuter) {
		outer = (void *)(uintptr_t)((uintptr_t (*)(uintptr_t))(uintptr_t)private_vmalloc)(4752);
		if (!outer)
			return -ENOMEM;
		stMainAwbOuter = (uintptr_t)outer;
	}
	memset((void *)(uintptr_t)stMainAwbOuter, 0, 4752);
	VAWB_STEP(1);
	VAWB_TOP();
	VAWB_CTL(vawb_s_tisp_awb_params_transmit, (u32)(uintptr_t)ctx, 0, 0);
	if (!vawb_ok(ctx[49], 1) || !tparamsN[0])
		return -EFAULT;
	*(uint16_t *)(uintptr_t)ctx[49] = (uint16_t)a0;
	*(uint16_t *)((uintptr_t)ctx[49] + 2) = (uint16_t)a1;
	VAWB_STEP(2);
	VAWB_CTL(vawb_s_tisp_awb_params_refresh, (u32)(uintptr_t)ctx, 0, (u32)tparamsN[0] + 4288);
	VAWB_STEP(3);
	if (vawb_ok(ctx[119], 0) && !*(uint8_t *)(uintptr_t)ctx[119]) {
		VAWB_CTL(vawb_s_tisp_awb_set_hardware_param, (u32)(uintptr_t)ctx, 0, 0);
		VAWB_STEP(4);
		VAWB_CTL(vawb_s_tisp_awb_set_gain, (u32)(uintptr_t)ctx, 0, 0);
	}
	VAWB_STEP(5);
	(void)system_irq_func_set(3, (int32_t)(uintptr_t)&tisp_awb_main_interrupt_static);
	(void)tisp_event_set_cb(0, 14, (int32_t)(uintptr_t)&tisp_awb_main_process);
	printk(KERN_INFO "t40: vendor AWB init pi=%#x outer=%p inter=%p ctx7=%#x faults=%u\n",
	       a0, (void *)(uintptr_t)stMainAwbOuter, (void *)(uintptr_t)stMainAwbInter,
	       ctx[7], vawb_faults);
	return 0;
}

static void t40_vawb_get_statistics(uintptr_t addr)
{
	vawb_irqs++;
	if (!(t40_vawb_run & 1))
		return;
	if (t40_vawb_debug && vawb_irqs <= 2)
		printk(KERN_WARNING "t40: vawb stats irq %u\n", vawb_irqs);
	VAWB_TOP();
	vawb_last_addr = (u32)addr;
	vawb_s_tisp_awb_get_statistics((u32)addr, (u32)(uintptr_t)pstMainAwbOri, 0, 0, VAWB_CSP);
}

/* state dump for host replay (tests/t40_vawb_host.sh): echo 1 > t40_vawb_dump_req, then read
 * /proc/t40_vawb_dump = [hdr 64][inter 60328][outer 4752][ctx 512][ctdet 136][ae 356] taken right
 * before one process call, followed by [inter][outer] right after it. */
static u32 t40_vawb_ev, t40_vawb_ev_sent;
#define VAWB_DUMP_ONE (64 + 60328 + 4752 + 512 + 136 + 356)
#define VAWB_DUMP_BYTES (VAWB_DUMP_ONE + 60328 + 4752)
static uint t40_vawb_dump_req;
t40_bringup_param(t40_vawb_dump_req, uint, 0644);
static u32 vawb_dump_len;
static ssize_t vawb_dump_read(struct file *f, char __user *u, size_t n, loff_t *off)
{
	return vawb_dump ? simple_read_from_buffer(u, n, off, vawb_dump, vawb_dump_len) : 0;
}
static const struct file_operations vawb_dump_fops = { .owner = THIS_MODULE, .read = vawb_dump_read };
static void vawb_dump_take(int after)
{
	u8 *d;
	u32 *h;

	if (!vawb_dump) {
		vawb_dump = vzalloc(VAWB_DUMP_BYTES);
		if (!vawb_dump)
			return;
		proc_create("t40_vawb_dump", 0444, NULL, &vawb_dump_fops);
	}
	d = vawb_dump;
	if (after) {
		memcpy(d + VAWB_DUMP_ONE, (void *)(uintptr_t)stMainAwbInter, 60328);
		memcpy(d + VAWB_DUMP_ONE + 60328, (void *)(uintptr_t)stMainAwbOuter, 4752);
		vawb_dump_len = VAWB_DUMP_BYTES;
		return;
	}
	h = (u32 *)d;
	h[0] = 0x42574156; h[1] = (u32)stMainAwbInter; h[2] = (u32)stMainAwbOuter; h[3] = t40_vawb_ev_sent;
	h[4] = (u32)(uintptr_t)pstMainAeOri_storage; h[5] = vawb_frames;
	d += 64;
	memcpy(d, (void *)(uintptr_t)stMainAwbInter, 60328); d += 60328;
	memcpy(d, (void *)(uintptr_t)stMainAwbOuter, 4752); d += 4752;
	memcpy(d, pstMainAwbOri, 512); d += 512;
	memcpy(d, pstMainAwbCtDetectOri, 136); d += 136;
	memcpy(d, pstMainAeOri_storage, 356);
	vawb_dump_len = VAWB_DUMP_ONE;
}

static void t40_vawb_ct_follow(void);
static void t40_vawb_ct_follow_ct(u32 ct);
static uint64_t t40_ct_fnum;	/* OEM fnum[0]: frames, here AWB processes */
static int64_t t40_vawb_process(void)
{
	u32 argarea[16] __aligned(8) = { 0 };
	u32 f0 = vawb_faults;
	u64 ret;

	if (!(t40_vawb_run & 2))
		return 0;
	if (t40_vawb_debug && vawb_frames < 2)
		printk(KERN_WARNING "t40: vawb process enter %u\n", vawb_frames);
	VAWB_TOP();
	if (t40_vawb_trace) { t40_vawb_trace = 0; vawb_tn = 0; vawb_tarmed = 1; }
	{
		int dump = t40_vawb_dump_req && stMainAwbInter && stMainAwbOuter;

		if (dump)
			vawb_dump_take(0);
		u64 ls = tx_ls_work_begin();

		ret = vawb_run_on(vawb_stk_proc, vawb_s_tisp_awb_main_process, 0, 0, 0, 0, (u32)(uintptr_t)argarea);
		tx_ls_work_end(T40_LS_WORK_VAWB_PROC, ls);
		if (dump) {
			vawb_dump_take(1);
			t40_vawb_dump_req = 0;
		}
	}

	vawb_tarmed = 0;
	vawb_frames++;
	t40_ct_fnum++;
	/* OEM: event 13 (CT) after every process -> CCM/LSC/BCSH; EV (event 8) once per frame */
	t40_vawb_ct_follow();
	if (vawb_frames <= 4 || (vawb_faults != f0 && vawb_faults <= 8))
		printk(KERN_INFO "t40: vendor AWB f=%u ret=%d faults=%u ev=%#x\n",
		       vawb_frames, (int)ret, vawb_faults, vawb_events_seen);
	return (int64_t)ret;
}

/* CT consumers (OEM tisp_ct_update, event 13 after every AWB process: TOP-gated ccm/lsc/bcsh/clm
 * main_ct_update) on the CCM/LSC/BCSH chains of this driver: tx_isp_t40_ct_chain.h, checked against the
 * OEM instructions (tests/t40_ct_chain_host.sh).  CT = *ctx[7].  The OEM frame number (fnum[0], advanced
 * once per frame by the ISP interrupt) is counted here once per AWB process, i.e. once per frame. */
static uint32_t t40_vawb_ct;
t40_bringup_param_named(t40_vawb_ct, t40_vawb_ct, uint, 0444);
static uint64_t t40_lsc_frm_saved[2];
static uint32_t t40_ct_lsc_writes;
t40_bringup_param_named(t40_ct_lsc_writes, t40_ct_lsc_writes, uint, 0444);
static void t40_ct_ccm(u32 ct);
static int t40_ct_lsc_interp(u32 bank, u32 ct);
static void t40_ct_lsc_write(u32 bank);
#define T40_CT_TOP()              ((uint32_t)system_reg_read(0x40U))
#define T40_CT_CCM(ct, a1)        t40_ct_ccm(ct)
#define T40_CT_LSC(ct, a1, f)     t40_ctc_lsc_update(0, ct, a1, f, t40_lsc_frm_saved, lsc_wlut_frequency)
#define T40_CT_BCSH(ct, a1)       t40_bcsh_main_ct_update(ct)	/* OEM tisp_bcsh_main_ct_update 0x6ab68 */
#define T40_CT_CLM(ct, a1, f)     t40_clm_ct_update(0, ct, f)	/* OEM tisp_clm_ct_update 0x6eb5c (tx_isp_t40_clm.h) */
#define T40_CLM_INTERP(b, ct)     t40_clm_ct_interp(b, ct, 1)
#define T40_CLM_PREPARE(b)        t40_clm_prepare_write_lut(b)
#define T40_LSC_INTERP(b, ct, a3) t40_ct_lsc_interp(b, ct)
#define T40_LSC_PREPARE(b)        t40_ct_lsc_write(b)
#include "tx_isp_t40_ct_chain.h"
/* OEM tisp_clm_ct_update(sensor, -, ct, -, fnum): interpolation + frame cadence; the LUT write follows in t40_clm_hw_refresh */
static int32_t t40_clm_ct_update(uint32_t bank, uint32_t ct, uint64_t fnum)
{
	if (bank > 1U || !t40_clm_ctx[bank])
		return -1;
	return t40_ctc_clm_update(bank, ct, fnum, t40_clm_frame_saved, t40_clm_wlut_frequency);
}
static void t40_ct_ccm(u32 ct)
{
	if (!regtrace_enable_ccm || !regtrace_ccm_ct_track || !stMainCcmOuter_lit || !pstMainCcmOri_lit[6] ||
	    !pstMainCcmOri_lit[7] || !pstMainCcmOri_lit[8])
		return;
	regtrace_ccm_ct = ct;	/* the EV re-interpolation in the frame-done block uses it */
	t40_ccm_main_ct_update((uintptr_t)pstMainCcmOri_lit, ct);
	regtrace_ccm_ct_now = ct;
}
static int t40_ct_lsc_interp(u32 bank, u32 ct)
{
	if (!regtrace_enable_lsc_lit || !regtrace_lsc_lit_ct_track || !lsc_lit_banks[bank].alive)
		return 1;
	regtrace_lsc_lit_ct_now = ct;
	return lsc_lit_interp_by_ct(bank, ct, 0);
}
/* OEM: prepare_write_lut arms the write, tisp_hardware_reg_refresh streams it in the same frame-done pass */
static void t40_ct_lsc_write(u32 bank)
{
	t40_ct_lsc_writes++;
	lsc_lit_real_write_lut(bank);
}
/* EV like the OEM AE event 8 payload: integration time (lines) x total gain, Q10.  The open AE
 * does not push event 8, so AWB (Y weights / day-night EV gates), CCM and BCSH get it here. */
t40_bringup_param_named(t40_vawb_ev, t40_vawb_ev, uint, 0444);
static u32 t40_vawb_ev_now(void)
{
	u32 it, again_log2, again_x1024;

	if (READ_ONCE(t40_vendor_expo_count)) {
		it = READ_ONCE(t40_vendor_it_sensor) & 0xffffU;
		again_log2 = READ_ONCE(t40_vendor_again_log2);
	} else {
		it = READ_ONCE(regtrace_ae_soft_cur_it);
		again_log2 = regtrace_gc4653_again_log2_gain(min_t(uint32_t, READ_ONCE(regtrace_ae_soft_cur_again),
					READ_ONCE(regtrace_ae_sensor_apply_max_again_index)));
	}
	again_x1024 = tx_isp_exp2_u32(again_log2, 16, 10);
	if (!again_x1024)
		again_x1024 = 1024U;
	return (u32)min_t(u64, (u64)it * again_x1024, 0xffffffffULL);
}
static void t40_vawb_ev_follow(void)
{
	u32 ev = t40_vawb_ev_now(), e10 = ev >> 10;

	t40_vawb_ev = e10;
	if (!e10 || ev == t40_vawb_ev_sent)
		return;
	t40_vawb_ev_sent = ev;
	VAWB_TOP();
	t40_am_main_ev_update(ev);
	if (regtrace_enable_ccm && regtrace_ccm_ct_track)
		regtrace_ccm_ev = e10;	/* CCM by EV: the frame-done block below re-interpolates on change */
	/* OEM tisp_bcsh_main_ev_update 0x6aac0 */
	t40_bcsh_main_ev_update(e10);
}

static void t40_vawb_ct_follow(void)
{
	u32 ct = vawb_ok(pstMainAwbOri[7], 3) ? *(u32 *)(uintptr_t)pstMainAwbOri[7] : 0;
	u64 ls = tx_ls_work_begin();

	t40_vawb_ev_follow();
	tx_ls_work_end(T40_LS_WORK_VAWB_EV, ls);
	ls = tx_ls_work_begin();
	t40_vawb_ct_follow_ct(ct);
	tx_ls_work_end(T40_LS_WORK_VAWB_CT, ls);
}

static void t40_vawb_ct_follow_ct(u32 ct)
{

	if (ct < 1500U || ct > 15000U || READ_ONCE(regtrace_running_mode))
		return;
	t40_vawb_ct = ct;
	t40_ct_update(ct, 0, t40_ct_fnum);
	/* OEM tisp_hardware_reg_refresh, CLM step: write the armed LUT unless CLM is bypassed */
	(void)t40_clm_hw_refresh(0);
}

static uint32_t t40_vawb_dn_params_refresh(uint32_t a0)
{
	VAWB_TOP();
	return (uint32_t)VAWB_CTL(vawb_s_tisp_awb_dn_params_refresh, a0, 0, 0);
}
static int32_t t40_vawb_main_ev_update(uint32_t a0)
{
	VAWB_TOP();
	t40_am_main_ev_update(a0);
	return 0;
}
static int32_t t40_vawb_tgain_update(uint32_t a0, uint32_t a1, uint32_t a2)
{
	VAWB_TOP();
	return (int32_t)vawb_s_tisp_awb_tgain_update(a0, a1, a2, 0, VAWB_CSP);
}
#endif
