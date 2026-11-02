/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T41 vendor AE (t41_vendor_ae=1): runtime for the mechanically translated
 * H20250310a AE chain in tx_isp_t41_vae_gen.inc.
 *
 * tools/t41_vae/gen.sh (asm2c.py) turns every OEM instruction of tisp_ae_calc_process
 * and its callees into one C statement on 32-bit register variables, so the
 * lifter defect classes (64-bit pairs, lhu/lw, pointer scaling, lost tail
 * calls, unbound args, wrong .bss/.rodata anchors) cannot occur: relocations
 * are resolved by symbol name against the driver's own objects.
 *
 * Every load/store/call goes through a guard: an address outside the kernel
 * map (NULL + offset, unrelocated table entries) is recorded as a fault and
 * skipped instead of oopsing.  Included at the end of tx_isp_t41_recovered.c.
 */
#ifndef TX_ISP_T41_VAE_H
#define TX_ISP_T41_VAE_H

typedef u64 (*vae_fn_t)(u32, u32, u32, u32, u32);

static u32 vae_faults;
static u32 vae_fault_addr, vae_fault_pc;
static u32 vae_calls;
static u32 vae_tisp_ae_hist[2104 / 4];
static u32 vae_ta_custom_en[2];
/* custom AE library (#76): last values tisp_ae_algo_handle applied (event push only on a change), per channel */
static u32 vae_ta_custom_again[2], vae_ta_custom_ev[2], vae_ta_custom_ev_short[2], vae_ta_custom_tgain[2], vae_ta_custom_tgain_short[2];
static u32 vae_ae_ceguang[320 / 4];
static u32 vae_slock[4];
static const char vae_str[] = "t41-vae";

static noinline void vae_fault_note(u32 addr, u32 pc)
{
	if (!vae_faults++) {
		vae_fault_addr = addr;
		vae_fault_pc = (u32)(uintptr_t)__builtin_return_address(0);
	}
	if (vae_faults <= 8)
		printk(KERN_WARNING "t41: vendor AE guard addr=%#x off=%#x from=%pS\n",
		       addr, pc, __builtin_return_address(0));
}

static inline bool vae_ok(u32 a, u32 align)
{
	return a >= 0x80000000U && a < 0xfffff000U && !(a & align);
}

#define VAE_LD(name, type, align) \
static noinline u32 vae_##name(u32 a, u32 pc) \
{ \
	if (unlikely(!vae_ok(a, align))) { vae_fault_note(a, pc); return 0; } \
	return (u32)*(volatile type *)(uintptr_t)a; \
}
VAE_LD(lw, u32, 3)
VAE_LD(lhu, u16, 1)
VAE_LD(lbu, u8, 0)
static inline u32 vae_lh(u32 a, u32 pc) { return (u32)(s32)(s16)vae_lhu(a, pc); }
static inline u32 vae_lb(u32 a, u32 pc) { return (u32)(s32)(signed char)vae_lbu(a, pc); }

#define VAE_ST(name, type, align) \
static noinline void vae_##name(u32 a, u32 v, u32 pc) \
{ \
	if (unlikely(!vae_ok(a, align))) { vae_fault_note(a, pc); return; } \
	*(volatile type *)(uintptr_t)a = (type)v; \
}
VAE_ST(sw, u32, 3)
VAE_ST(sh, u16, 1)
VAE_ST(sb, u8, 0)

/* Accesses to the function's own frame array vframe[] (generated "sp + N"):
 * always a valid, aligned kernel stack address, so no guard (same result as
 * the guarded access, which could never fault there). */
#define vf_lw(a)  (*(volatile u32 *)(uintptr_t)(a))
#define vf_lhu(a) ((u32)*(volatile u16 *)(uintptr_t)(a))
#define vf_lbu(a) ((u32)*(volatile u8 *)(uintptr_t)(a))
#define vf_lh(a)  ((u32)(s32)*(volatile s16 *)(uintptr_t)(a))
#define vf_lb(a)  ((u32)(s32)*(volatile s8 *)(uintptr_t)(a))
#define vf_sw(a, v) (*(volatile u32 *)(uintptr_t)(a) = (u32)(v))
#define vf_sh(a, v) (*(volatile u16 *)(uintptr_t)(a) = (u16)(v))
#define vf_sb(a, v) (*(volatile u8 *)(uintptr_t)(a) = (u8)(v))

/* hi:lo as one u64 (hi in the upper word); x/0 leaves 0 instead of trapping */
static inline u64 vae_divu(u32 x, u32 y, u32 pc)
{
	if (unlikely(!y)) { vae_fault_note(0, pc); return 0; }
	return ((u64)(x % y) << 32) | (x / y);
}
static inline u64 vae_divs(u32 x, u32 y, u32 pc)
{
	s32 a = (s32)x, b = (s32)y;
	if (unlikely(!b || (a == INT_MIN && b == -1))) { vae_fault_note(0, pc); return 0; }
	return ((u64)(u32)(a % b) << 32) | (u32)(a / b);
}

static inline void vae_fn_enter(void) { vae_calls++; }

static inline u64 vae_call(u32 tg, u32 a0, u32 a1, u32 a2, u32 a3, u32 sp, u32 pc)
{
	if (unlikely(tg < 0x80000000U || (tg & 3))) {
		vae_fault_note(tg, pc);
		return 0;
	}
	return ((vae_fn_t)(uintptr_t)tg)(a0, a1, a2, a3, sp);
}

/* ---- external leaves the OEM code calls (same ABI) ---- */
static u64 vae_x_memcpy(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	if (!vae_ok(a0, 0) || !vae_ok(a1, 0) || a2 > 0x10000) { vae_fault_note(a0, 1); return a0; }
	memcpy((void *)(uintptr_t)a0, (const void *)(uintptr_t)a1, a2);
	return a0;
}
static u64 vae_x_memset(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	if (!vae_ok(a0, 0) || a2 > 0x10000) { vae_fault_note(a0, 2); return a0; }
	memset((void *)(uintptr_t)a0, (int)a1, a2);
	return a0;
}
static u64 vae_x_private_complete(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	if (vae_ok(a0, 3))
		private_complete((struct completion *)(uintptr_t)a0);
	return 0;
}
/* T41 is single core: the OEM wrappers reduce to irq save/restore. */
static u64 vae_x___private_spin_lock_irqsave(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	unsigned long flags;

	local_irq_save(flags);
	vae_sw(a1, (u32)flags, 3);
	return 0;
}
static u64 vae_x_private_spin_unlock_irqrestore(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	local_irq_restore((unsigned long)a1);
	return 0;
}
static u64 vae_x_system_reg_write(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (u32)system_reg_write(a0, a1);
}
static u64 vae_x_isp_printf(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return 0;
}
/* Events the OEM AE pushes (6: EV update for the gain-indexed modules).
 * Their lifted consumers are not trusted yet: dropped unless enabled in
 * t41_vae_events (bit n = event n); the driver's own gain fanout runs
 * instead (t41_vae_calc_process). */
static unsigned int t41_vae_events;
module_param(t41_vae_events, uint, 0644);
MODULE_PARM_DESC(t41_vae_events, "vendor AE: forward OEM AE event ids (bitmask, default 0)");
static u32 vae_events_seen, vae_events_dropped;
static bool t41_dfg_event(u32 ch, u32 id, u32 ev);
static u64 vae_x_tisp_event_push(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u32 id = vae_lw(a1 + 8, 5);

	if (t41_dfg_event(a0, id, a1))
		return (u32)tisp_event_push(a0, a1);

	vae_events_seen |= id < 32 ? BIT(id) : BIT(31);
	if (id < 32 && (t41_vae_events & BIT(id)))
		return (u32)tisp_event_push(a0, a1);
	vae_events_dropped++;
	return 0;
}
static u64 vae_x___ashldi3(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (((u64)a1 << 32) | a0) << (a2 & 63);
}
static u64 vae_x___lshrdi3(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (((u64)a1 << 32) | a0) >> (a2 & 63);
}
static u64 vae_x___ashrdi3(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	return (u64)((s64)(((u64)a1 << 32) | a0) >> (a2 & 63));
}
static u64 vae_x___div64_32(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u64 n;
	u32 rem;

	if (!vae_ok(a0, 3) || !a1) { vae_fault_note(a0, 3); return 0; }
	n = *(u64 *)(uintptr_t)a0;
	rem = do_div(n, a1);
	*(u64 *)(uintptr_t)a0 = n;
	return rem;
}
static u64 vae_x_div64_u64(u32 a0, u32 a1, u32 a2, u32 a3, u32 csp)
{
	u64 b = ((u64)a3 << 32) | a2;

	if (!b) { vae_fault_note(0, 4); return 0; }
	return div64_u64(((u64)a1 << 32) | a0, b);
}

#include "tx_isp_t41_vae_gen.inc"

/* Sensor control callbacks (sensor_ctrl_main+324..) the OEM AE reaches. */
static void t41_vae_install_sensor_ctrl(void)
{
	unsigned char *s = sensor_ctrl_main_storage;

	*(void **)(s + 332) = vae_sensor_alloc_analog_gain;
	*(void **)(s + 336) = vae_sensor_alloc_analog_gain_short;
	*(void **)(s + 340) = vae_sensor_alloc_digital_gain;
	*(void **)(s + 348) = vae_sensor_alloc_integration_time;
	*(void **)(s + 352) = vae_sensor_alloc_integration_time_short;
	*(void **)(s + 356) = vae_sensor_set_integration_time;
	*(void **)(s + 360) = vae_sensor_set_integration_time_short;
	*(void **)(s + 364) = vae_sensor_start_changes;
	*(void **)(s + 368) = vae_sensor_end_changes;
	*(void **)(s + 372) = vae_sensor_set_analog_gain;
	*(void **)(s + 376) = vae_sensor_set_analog_gain_short;
	*(void **)(s + 380) = vae_sensor_set_digital_gain;
}

static u32 vae_frames;

int32_t t41_vae_calc_process(uint32_t channel)
{
	u32 argarea[8] __aligned(8) = { 0 };
	u32 *info, faults0;
	unsigned char *cache;
	u64 ret;

	if (channel >= ARRAY_SIZE(ae_info))
		return -EINVAL;
	info = (u32 *)(uintptr_t)ae_info[channel];
	if (!t41_kernel_data_ptr(info) || !t41_kernel_data_ptr((void *)(uintptr_t)info[0]) ||
	    !t41_kernel_data_ptr((void *)(uintptr_t)info[1]))
		return -ENODEV;
	if (!*(u32 *)(void *)(ae_cache + channel * 4))
		*(u32 *)(void *)(ae_cache + channel * 4) =
			(u32)(uintptr_t)(ae_cache_init + channel * 0x688);
	cache = (unsigned char *)(uintptr_t)*(u32 *)(void *)(ae_cache + channel * 4);
	if (*(void **)(sensor_ctrl_main_storage + 356) != vae_sensor_set_integration_time)
		t41_vae_install_sensor_ctrl();
	if (channel == 0 && READ_ONCE(t41_ratio_pending))
		t41_module_ratio_apply(0, xchg(&t41_ratio_pending, 0));
	/* zone bank copy in process context (OEM: hist/static IRQ pair) */
	tisp_ae_interrupt_static(channel);
	/* ROI-window ("ai") statistics, the face AE's luma source: OEM
	 * tisp_ae_ai_interrupt_static (ISP IRQ 61) copies 0x19060..0x19074 to
	 * AE state +7448..+7468, which tisp_ae_weight_mean divides by the ROI
	 * area.  The open dispatcher skips IRQ 61 and its recovered body is a
	 * guarded no-op (wrong table anchor), so these stayed 0: face AE metered
	 * luma 0 (division guards in fix_point_div_32, no face effect).  Read
	 * them here per frame in process context instead (issue 90). */
	if (channel == 0 && t41_ae_roi_stats > 0) {
		unsigned char *st = (unsigned char *)(uintptr_t)info[1];
		unsigned int i;

		for (i = 0; i < 6; ++i)
			*(u32 *)(void *)(st + 7448 + 4 * i) =
				system_reg_read(0x19060 + 4 * i);
	}
	{
		/* EV fixed-point precision of the calibration (AE params +0x6c0):
		 * the tone consumers need it to strip the shift again. */
		const unsigned char *ap = (const unsigned char *)(uintptr_t)info[0];
		unsigned int shift = ap[0x6c0] | (ap[0x6c1] << 8);

		if (shift && shift <= 16)
			WRITE_ONCE(t41_ae_ev_shift, shift);
	}
	faults0 = vae_faults;
	ret = vae_tisp_ae_calc_process(channel, 0, 0, 0, (u32)(uintptr_t)argarea);
	vae_frames++;
	if (channel < ARRAY_SIZE(t41_vae_hist_frames))
		WRITE_ONCE(t41_vae_hist_frames[channel], t41_vae_hist_frames[channel] + 1);
	{
		/* realized total gain (again * dgain, Q10 linear) -> log2 Q16,
		 * with the OEM's own tisp_log2_fixed_to_fixed */
		/* a custom AE library (#76) bypasses the EV allocation that refreshes ae_cache +576..: its answer is the
		 * realized exposure, tisp_ae_algo_handle keeps it in the AE state +8608.. (stock api_ae_get_exprinfo_attr reads it there) */
		const unsigned char *rz = vae_ta_custom_en[channel] ? (const unsigned char *)(uintptr_t)info[1] + 8608 : cache + 576;
		u32 it = *(u32 *)(rz + 0), ag = *(u32 *)(rz + 4);
		u32 dg = *(u32 *)(rz + 12), gain_q16;
		u64 total = (u64)ag * (dg ? dg : 1024) >> 10;

		if (total > 0x3ffffff)
			total = 0x3ffffff;
		gain_q16 = (u32)vae_tisp_log2_fixed_to_fixed((u32)total << 6, 16, 16, 0,
							(u32)(uintptr_t)argarea);
		/* proc/IMP getters report the safe AE state: mirror the
		 * realized vendor exposure there */
		t41_safe_ae[channel].integration = it;
		t41_safe_ae[channel].again = ag;
		t41_safe_ae[channel].frames++;
		t41_safe_ae[channel].last_mean_q8 = *(u32 *)(cache + 1520) << 8;
		t41_safe_ae_sensor[channel].log2_q16 = gain_q16;
		t41_safe_ae_integration = it;
		t41_safe_ae_gain_q16 = gain_q16;
		t41_tmo_exposure(it, gain_q16);
		if ((t41_safe_gain_fanout_mask & 0x3fU) &&
		    gain_q16 != t41_safe_gain_last_q16)
			t41_apply_safe_gain_fanout(channel, gain_q16,
						   t41_safe_gain_fanout_mask & 0x3fU);
	}
	if (vae_frames <= 30 || (t41_ae_diag == 1 && !(vae_frames % 25)) || t41_ae_diag >= 2 ||
	    (vae_faults != faults0 && vae_faults <= 8))
		printk(KERN_WARNING
		       "t41: vendor AE f=%u ret=%d it=%u ag=%u dg=%u ev=%u mean=%u g16=%u faults=%u ev-ids=%#x\n",
		       vae_frames, (int)ret, *(u32 *)(cache + 576), *(u32 *)(cache + 580),
		       *(u32 *)(cache + 588), *(u32 *)(cache + 1524),
		       *(u32 *)(cache + 1520), t41_safe_ae_gain_q16, vae_faults,
		       vae_events_seen);
	return (int32_t)ret;
}

/*
 * Custom AE algorithm library (IMP_ISP_SetAeAlgoFunc, #76).
 *
 * Stock tx_isp_unlocked_ioctl (T41 1.2.5 / 1.2.6 tx-isp-t41.ko, reference: the same module with symbols): libimp registers the user callbacks
 * in IMP_ISP_EnableSensor and runs one worker thread that loops
 *   0xc004541b  get handle   tx_isp_get_ae_algo_handle: wait for ae_algo_comp, fill the info block (statistics + exposure), copy 2002 bytes out
 *   0xc004541c  set handle   tisp_ae_algo_handle(channel, answer): the library's exposure goes to the sensor through sensor_ctrl_main
 * and registers / unregisters with
 *   0xc004541d  open         tx_isp_set_ae_algo_open: tisp_ae_algo_init(channel, 1, init attribute), allocate the info block, init ae_algo_comp
 *   0xc004541e  close        tisp_ae_algo_deinit + tisp_ae_algo_init(channel, 0, 0) + kfree(info block)
 * The stock module has ONE channel (one 16 byte completion, one info pointer); the second-sensor ioctl 0xc0045420 and the AWB ioctls
 * 0xc0045423..26 do not exist in the stock dispatcher (they answer -ENOTTY there as here).  While ta_custom_en is set the vendor AE
 * still computes the statistics (tisp_ae_algorithm), skips its own EV allocation and completes ae_algo_comp at the end of
 * tisp_ae_calc_process: that is how the library is woken (translated chain, vae_tisp_ae_calc_process).
 * tisp_ae_algo_init / tisp_ae_algo_handle / tisp_ae_algo_deinit_internal are translated from the stock module like the rest of the chain.
 * Differences: the info block is kzalloc'ed (stock: kmalloc-2048 cache) and cleared after close (stock leaves the freed pointer, a second close
 * freed it twice); a get/close race and a get without open answer -EINVAL (stock dereferences NULL); the interrupted wait returns the error
 * (stock carries on); the exposure words of the info block are the live ones (see t41_ae_algo_get).
 *
 * Extra beyond the vendor (Lu-Fi/openimp, "AE algorithm library released when its client dies"): the stock module has no tx_isp_release hook for
 * the library, a killed client leaves it registered and every later open answers EBUSY until the module is reloaded.  Here the file that
 * registered the library is remembered and tx_isp_release unregisters it (t41_ae_algo_release: the same steps as the close).  Locking protocol as
 * the T41 AWB library (tx_isp_t41_awb_algo.h): t41_ae_algo_lock guards the registration, open, close, result and the part of a get between its
 * wake-up and copy_to_user; a get without a registered library answers -EINVAL at once; the unregister wakes every waiter (complete_all), frees the
 * info block once and clears the pointer, so a close followed by the release (or the reverse) frees nothing twice; the completion is initialised
 * once.  Without a registered library nothing changes (vendor-identical).
 */
#define T41_AE_ALGO_COOKIE	0x336acU
#define T41_AE_ALGO_INFO_BYTES	2002U

#define T41_AE_ALGO_COMP	((struct completion *)(void *)ae_algo_comp_storage)

/* chain / hardware hooks, defined below the protocol block (the host test brings its own) */
static int t41_ae_algo_hw_precheck(const u32 *u);			/* no side effects: errors the open answers before it allocates */
static int t41_ae_algo_hw_register(u32 *u);				/* tisp_ae_algo_init(ch, 1, ...), the init attribute into u */
static void t41_ae_algo_hw_unregister(u32 ch);				/* tisp_ae_algo_deinit + tisp_ae_algo_init(ch, 0, 0) */
static int t41_ae_algo_hw_fill(unsigned char *info_blk);		/* statistics + exposure into the block, -EINVAL if the AE is gone */
static int t41_ae_algo_hw_set(u32 *u);					/* tisp_ae_algo_handle, -EINVAL if no custom AE is active */

/* T41-AE-ALGO-PROTOCOL-BEGIN */
static unsigned char *t41_ae_algo_info;		/* non-NULL = a library is registered */
static uintptr_t t41_ae_algo_owner;		/* the file that registered it (release hook) */
static bool t41_ae_algo_comp_ready;
static DEFINE_MUTEX(t41_ae_algo_lock);
static u32 t41_ae_algo_gets, t41_ae_algo_sets;

/* t41_ae_algo_lock held.  Unregister: stop the chain, free the info block once, wake every waiter. */
static void t41_ae_algo_unregister_locked(void)
{
	unsigned char *blk = t41_ae_algo_info;

	if (!blk)
		return;
	t41_ae_algo_hw_unregister(0);
	t41_ae_algo_info = NULL;
	t41_ae_algo_owner = 0;
	if (t41_ae_algo_comp_ready)
		complete_all(T41_AE_ALGO_COMP);	/* a get-handle waiting for the next frame leaves with -EINVAL */
	kfree(blk);
}

static int t41_ae_algo_open(uintptr_t file, u32 user)
{
	u32 u[34];
	unsigned char *info_blk;
	int ret;

	if (!user)
		return -EFAULT;
	if (private_copy_from_user(u, (const void __user *)(uintptr_t)user, sizeof(u)))
		return -EFAULT;
	ret = t41_ae_algo_hw_precheck(u);
	if (ret)
		return ret;
	info_blk = kzalloc(2048, GFP_KERNEL);
	if (!info_blk)
		return -ENOMEM;
	mutex_lock(&t41_ae_algo_lock);
	if (t41_ae_algo_info) {			/* already open: stock would leak the old block */
		mutex_unlock(&t41_ae_algo_lock);
		kfree(info_blk);
		return -EBUSY;
	}
	ret = t41_ae_algo_hw_register(u);
	if (ret) {
		mutex_unlock(&t41_ae_algo_lock);
		kfree(info_blk);
		return ret;
	}
	BUILD_BUG_ON(sizeof(struct completion) != 16U);
	if (!t41_ae_algo_comp_ready) {		/* once: a completion with a waiter must never be initialised again */
		init_completion(T41_AE_ALGO_COMP);
		t41_ae_algo_comp_ready = true;
	}
	T41_AE_ALGO_COMP->done = 0;		/* a new library starts without a pending frame */
	t41_ae_algo_gets = t41_ae_algo_sets = 0;
	t41_ae_algo_owner = file;
	t41_ae_algo_info = info_blk;
	if (private_copy_to_user((void __user *)(uintptr_t)user, u, sizeof(u))) {
		isp_printf(2, "[%s %d] [ %s:%d ] copy to user error\n", "tx_isp_set_ae_algo_open", 1627, "tx_isp_set_ae_algo_open", 1627);
		t41_ae_algo_unregister_locked();	/* the client never learns it is registered: do not keep the library */
		mutex_unlock(&t41_ae_algo_lock);
		return -EFAULT;
	}
	mutex_unlock(&t41_ae_algo_lock);
	return 0;
}

static int t41_ae_algo_close(u32 user)
{
	u32 u[2];

	if (!user || private_copy_from_user(u, (const void __user *)(uintptr_t)user, sizeof(u)))
		return -EFAULT;
	if (u[1] >= 1U)
		return -EINVAL;
	mutex_lock(&t41_ae_algo_lock);
	t41_ae_algo_unregister_locked();	/* a repeated close frees nothing */
	mutex_unlock(&t41_ae_algo_lock);
	return 0;
}

static int t41_ae_algo_get(u32 user)
{
	unsigned char *info_blk;
	int ret;

	if (!user)
		return -EFAULT;
	mutex_lock(&t41_ae_algo_lock);
	ret = t41_ae_algo_info ? 0 : -EINVAL;	/* no library registered: nothing would ever complete */
	mutex_unlock(&t41_ae_algo_lock);
	if (ret)
		return ret;
	ret = private_wait_for_completion_interruptible(T41_AE_ALGO_COMP);
	if (ret)
		return ret;
	mutex_lock(&t41_ae_algo_lock);
	info_blk = t41_ae_algo_info;
	if (!info_blk) {			/* closed while waiting */
		mutex_unlock(&t41_ae_algo_lock);
		return -EINVAL;
	}
	ret = t41_ae_algo_hw_fill(info_blk);
	if (ret) {
		mutex_unlock(&t41_ae_algo_lock);
		return ret;
	}
	t41_ae_algo_gets++;
	ret = private_copy_to_user((void __user *)(uintptr_t)user, info_blk, T41_AE_ALGO_INFO_BYTES) ? -EFAULT : 0;
	mutex_unlock(&t41_ae_algo_lock);
	return ret;
}

static int t41_ae_algo_set(u32 user)
{
	u32 u[14];
	int ret;

	if (!user || private_copy_from_user(u, (const void __user *)(uintptr_t)user, sizeof(u)))
		return -EFAULT;
	if (u[1] >= 1U)
		return -EINVAL;
	mutex_lock(&t41_ae_algo_lock);
	if (!t41_ae_algo_info) {		/* a late result after the close */
		mutex_unlock(&t41_ae_algo_lock);
		return -EINVAL;
	}
	ret = t41_ae_algo_hw_set(u);
	if (!ret)
		t41_ae_algo_sets++;
	mutex_unlock(&t41_ae_algo_lock);
	return ret;
}

/* tx_isp_release hook: the file that registered the library is going away (killed client) */
static void t41_ae_algo_release(uintptr_t file)
{
	mutex_lock(&t41_ae_algo_lock);
	if (t41_ae_algo_info && t41_ae_algo_owner == file)
		t41_ae_algo_unregister_locked();
	mutex_unlock(&t41_ae_algo_lock);
}

static int t41_ioctl_ae_algo(uintptr_t file, uint32_t cmd, uint32_t user_arg)
{
	switch (cmd) {
	case 0xc004541bU: return t41_ae_algo_get(user_arg);
	case 0xc004541cU: return t41_ae_algo_set(user_arg);
	case 0xc004541dU: return t41_ae_algo_open(file, user_arg);
	case 0xc004541eU: return t41_ae_algo_close(user_arg);
	}
	return -ENOTTY;
}
/* T41-AE-ALGO-PROTOCOL-END */

/* ---- chain side ---- */

static unsigned char *t41_ae_algo_core(void)
{
	unsigned char *core = (unsigned char *)(uintptr_t)*(u32 *)(void *)g_ispcore;

	if (!t41_kernel_data_ptr(core))
		core = (unsigned char *)(uintptr_t)ispcore_sd;
	return t41_kernel_data_ptr(core) ? core : NULL;
}

static unsigned char *t41_ae_algo_attr(unsigned char *core, u32 ch)
{
	unsigned char *attr = (unsigned char *)(uintptr_t)*(u32 *)(void *)(core + 360 + ch * 96);

	return t41_kernel_data_ptr(attr) ? attr : NULL;
}

static u32 t41_ae_algo_exp2(u32 v)
{
	u32 frame[8] __aligned(8) = { 0 };

	return (u32)vae_tisp_math_exp2(v, 16, 10, 0, (u32)(uintptr_t)frame);
}

static int t41_ae_algo_hw_precheck(const u32 *u)
{
	unsigned char *core, *attr;
	u32 ch, *aei;

	if (u[0] != T41_AE_ALGO_COOKIE) {
		isp_printf(2, "[%s %d] [ %s:%d ] Ae Algo Function register version error\n", "tx_isp_set_ae_algo_open", 1571, "tx_isp_set_ae_algo_open", 1571);
		return -EPERM;
	}
	ch = u[1];
	if (ch >= 1U)				/* the stock module has one channel */
		return -EINVAL;
	if (t41_vendor_ae <= 0)			/* the safe AE controller has no statistics event for a library */
		return -EOPNOTSUPP;
	core = t41_ae_algo_core();
	attr = core ? t41_ae_algo_attr(core, ch) : NULL;
	if (!core || !attr)
		return -EPERM;
	aei = (u32 *)(uintptr_t)ae_info[ch];
	if (!t41_kernel_data_ptr(aei) || !t41_kernel_data_ptr((void *)(uintptr_t)aei[0]) ||
	    !t41_kernel_data_ptr((void *)(uintptr_t)aei[1]))
		return -ENODEV;
	return 0;
}

/* t41_ae_algo_lock held, hw_precheck passed */
static int t41_ae_algo_hw_register(u32 *u)
{
	u32 frame[8] __aligned(8) = { 0 };
	unsigned char *core, *attr, *state;
	u32 ch = u[1], *aei;

	core = t41_ae_algo_core();
	attr = core ? t41_ae_algo_attr(core, ch) : NULL;
	aei = (u32 *)(uintptr_t)ae_info[ch];
	if (!core || !attr || !t41_kernel_data_ptr(aei) || !t41_kernel_data_ptr((void *)(uintptr_t)aei[1]))
		return -ENODEV;
	state = (unsigned char *)(uintptr_t)aei[1];
	{
		/* stock keeps the realized exposure in AE state +8608.. only while the internal AE runs (api_ae_get_exprinfo_attr
		 * copies ae_cache +576..+607 there); seed it so the first info block shows the live exposure */
		unsigned char *cache = (unsigned char *)(uintptr_t)*(u32 *)(void *)(ae_cache + ch * 4);

		if (t41_kernel_data_ptr(cache))
			memcpy(state + 8608, cache + 576, 32);
	}
	vae_tisp_ae_algo_init(ch, 1, (u32)(uintptr_t)u, 0, (u32)(uintptr_t)frame);
	u[27] = *(u32 *)(void *)(core + ch * 96 + 376);
	u[3] = *(u32 *)(void *)(attr + 176);
	u[4] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 160));
	u[5] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 164));
	u[15] = *(u32 *)(void *)(attr + 272);
	u[16] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 280));
	u[17] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 308));
	if (*(u32 *)(void *)(core + (ch + 118) * 4) != 0) {	/* WDR */
		u[6] = system_reg_read(8228) & 0xffff;
		u[18] = system_reg_read(8240) & 0xffff;
	} else {
		u[6] = system_reg_read(0x8000) & 0xffff;
	}
	return 0;
}

static void t41_ae_algo_hw_unregister(u32 ch)
{
	u32 frame[8] __aligned(8) = { 0 };

	vae_tisp_ae_algo_deinit_internal(ch, 0, 0, 0, (u32)(uintptr_t)frame);
	vae_tisp_ae_algo_init(ch, 0, 0, 0, (u32)(uintptr_t)frame);
}

/* t41_ae_algo_lock held, info_blk non-NULL */
static int t41_ae_algo_hw_fill(unsigned char *info_blk)
{
	u32 ei[16];
	unsigned char *core, *attr, *cache, *state;
	u32 *aei;
	int k;

	core = t41_ae_algo_core();
	attr = core ? t41_ae_algo_attr(core, 0) : NULL;
	aei = (u32 *)(uintptr_t)ae_info[0];
	if (!core || !attr || !t41_kernel_data_ptr(aei) || !t41_kernel_data_ptr((void *)(uintptr_t)aei[1]))
		return -EINVAL;
	state = (unsigned char *)(uintptr_t)aei[1];
	cache = (unsigned char *)(uintptr_t)*(u32 *)(void *)(ae_cache + 0);
	memset(info_blk + 8, 0, TX_ISP_TUNING_T41_AE_STATS_BYTES + 60U);
	t41_ae_stats_to(0, info_blk + 8, 0);
	/* exposure words: the library's last answer (state +8608.., stock api_ae_get_exprinfo_attr) while it controls the AE.  Until it has changed
	 * something the state is empty: the exposure the sensor runs with is used (below) */
	if (!*(u32 *)(void *)(state + 8608)) {		/* no exposure known yet (the library has not changed anything) */
		if (t41_kernel_data_ptr(cache) && *(u32 *)(void *)(cache + 576))
			memcpy(state + 8608, cache + 576, 32);
		else {
			/* the library registers before the first stream, so the internal AE never ran: the sensor runs on the exposure its driver
			 * started with (video attr +176 integration time, +160 / +164 the log2 gains: the values tisp_ae_algo_init hands the library) */
			u32 st[8] = { 0 };

			st[0] = *(u32 *)(void *)(attr + 176);
			st[1] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 160));
			st[2] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 164));
			st[3] = 1024;
			st[4] = *(u32 *)(void *)(attr + 272);
			st[5] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 280));
			st[6] = t41_ae_algo_exp2(*(u32 *)(void *)(attr + 308));
			st[7] = 1024;
			memcpy(state + 8608, st, 32);
		}
	}
	memcpy(ei, state + 8608, 32);
	{
		u32 w[14];

		w[0] = ei[0]; w[1] = ei[1]; w[2] = ei[2]; w[3] = ei[3];
		w[4] = ei[4]; w[5] = ei[5]; w[6] = ei[6]; w[7] = ei[7];
		w[8] = *(u32 *)(void *)(core + 472);
		w[9] = *(u16 *)(void *)(attr + 180);
		w[10] = *(u16 *)(void *)(attr + 182);
		w[11] = *(u32 *)(void *)(core + 376);
		w[12] = *(u32 *)(void *)(core + 368);
		w[13] = *(u32 *)(void *)(core + 372);
		for (k = 0; k < 14; k++)
			memcpy(info_blk + 1946 + 4 * k, &w[k], 4);
	}
	return 0;
}

/* t41_ae_algo_lock held, a library is registered */
static int t41_ae_algo_hw_set(u32 *u)
{
	u32 frame[8] __aligned(8) = { 0 };

	if (!vae_ta_custom_en[u[1]])
		return -EINVAL;
	vae_tisp_ae_algo_handle(u[1], (u32)(uintptr_t)u, 0, 0, (u32)(uintptr_t)frame);
	return 0;
}

#endif
