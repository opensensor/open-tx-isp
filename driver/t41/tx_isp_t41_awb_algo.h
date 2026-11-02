/*
 * Custom AWB algorithm library (IMP_ISP_SetAwbAlgoFunc), a documented extra beyond the vendor (Lu-Fi/openimp#195, follow-up of #76).
 *
 * The stock T41 module (1.2.5 / 1.2.6) has no AWB library path at all: its dispatcher answers 0xc0045423..26 with -ENOTTY, libimp registers the
 * record in IMP_ISP_EnableSensor, the open fails and the library is never called ("vendor is a no-op").  This file serves the same user-space
 * protocol the T40 module and libimp use (libimp: src/t40/openimp_p1_algo.c, one worker thread per registered library):
 *   0xc0045425  open   {cookie 0x336ac, channel} -> 28 bytes: the init attribute (IMPISPAwbInitAttr, 20 bytes) behind the 8 byte header
 *   0xc0045423  get    {cookie, channel}         -> 2732 bytes {cookie, channel, IMPISPAwbInfo}: waits for the next AWB statistics frame
 *   0xc0045424  set    {cookie, channel, change, r_gain, b_gain, ct}: the library's result
 *   0xc0045426  close  {cookie, channel}
 * Statistics come from the native AWB (t41_native_awb_control: global and zone statistics; the current gains are the ones in the WB registers),
 * the wake-up is the end of the native AWB frame work (t41_awb_algo_wake).  A result with change == 1 and gains in 0x200..0x1800 (hardware unit,
 * 1024 = 1.0, the range of IMP_ISP_Tuning_SetWB) switches the AWB to manual hardware gains, the same control plane as the SetWB / OPEN_AWB_CONTROL
 * route (t41_native_awb_compat); the close gives the application's state (mode, freeze, manual gains, CT, registers) back.  The colour temperature
 * of the result is ignored.
 *
 * Locking (same protocol as the T40 review fix H1 and the T41 AE library): t41_awb_algo_lock guards the registration (info block pointer),
 * the open, close, result and the part of a get between its wake-up and copy_to_user; the lock order is t41_awb_algo_lock -> t41_native_awb_lock,
 * the AWB frame work only takes t41_native_awb_lock and completes the (statically initialised once) completion.
 *   - a get without a registered library answers -EINVAL at once (nothing would ever wake it), a get woken by the close -EINVAL,
 *     an interrupted wait returns the wait error (-ERESTARTSYS), the close wakes every waiter (complete_all);
 *   - a second open of a registered library answers -EBUSY, the close of an unregistered one is a no-op, the info block is freed once;
 *   - the release of the file that registered the library unregisters it (a crashed streamer cannot leave the module with a registered
 *     library nobody serves);
 *   - the result ioctl answers 0 for values it ignores (the libimp worker leaves its loop on any error).
 * Without a registered library nothing changes: the vendor-identical default (no library path, the AWB runs on its own).
 */
#ifndef TX_ISP_T41_AWB_ALGO_H
#define TX_ISP_T41_AWB_ALGO_H

#define T41_AWB_ALGO_COOKIE	0x336acU
#define T41_AWB_ALGO_INFO_BYTES	2732U		/* 8 byte header + sizeof(IMPISPAwbInfo) = 2724 */
#define T41_AWB_ALGO_GAIN_MIN	0x200U		/* hardware WB gain, 1024 = 1.0: the range of IMP_ISP_Tuning_SetWB */
#define T41_AWB_ALGO_GAIN_MAX	0x1800U

/* hardware / white balance hooks, defined below the protocol block (the host test brings its own) */
static void t41_awb_algo_init_attr(u32 attr[5]);
static void t41_awb_algo_fill_info(unsigned char *info);		/* info = IMPISPAwbInfo (behind the 8 byte header) */
static int t41_awb_algo_apply(u32 r, u32 b);				/* manual white balance with the library's gains */
static void t41_awb_algo_restore(void);					/* give the application's white balance back */

/* T41-AWB-ALGO-PROTOCOL-BEGIN */
static DEFINE_MUTEX(t41_awb_algo_lock);
static unsigned char *t41_awb_algo_info;	/* non-NULL = a library is registered */
static uintptr_t t41_awb_algo_owner;		/* the file that registered it (release hook) */
static struct completion t41_awb_algo_comp;
static bool t41_awb_algo_comp_ready;
static int t41_awb_algo_on;			/* read by the AWB frame work without the lock */
static bool t41_awb_algo_manual;		/* a result switched the AWB to manual gains (restored at the close) */
static u32 t41_awb_algo_gets, t41_awb_algo_sets;

/* end of the native AWB frame work: one wake-up per processed frame (not more than one pending) */
static void t41_awb_algo_wake(void)
{
	if (READ_ONCE(t41_awb_algo_on) && !READ_ONCE(t41_awb_algo_comp.done))
		complete(&t41_awb_algo_comp);
}

/* t41_awb_algo_lock held.  Unregister: stop the wake-ups, give the white balance back, free the info block once, wake the waiters. */
static void t41_awb_algo_unregister_locked(void)
{
	unsigned char *blk = t41_awb_algo_info;

	if (!blk)
		return;
	WRITE_ONCE(t41_awb_algo_on, 0);
	if (t41_awb_algo_manual) {
		t41_awb_algo_restore();
		t41_awb_algo_manual = false;
	}
	t41_awb_algo_info = NULL;
	t41_awb_algo_owner = 0;
	if (t41_awb_algo_comp_ready)
		complete_all(&t41_awb_algo_comp);
	kfree(blk);
}

static int t41_awb_algo_open(uintptr_t file, u32 user)
{
	u32 u[7] = { 0 };
	unsigned char *blk;

	if (!user)
		return -EFAULT;
	if (private_copy_from_user(u, (const void __user *)(uintptr_t)user, 8))
		return -EFAULT;
	if (u[0] != T41_AWB_ALGO_COOKIE) {
		isp_printf(2, "[%s %d] [ %s:%d ] Awb Algo Function register version error\n", "tx_isp_set_awb_algo_open", 1, "tx_isp_set_awb_algo_open", 1);
		return -EPERM;
	}
	if (u[1] != 0)				/* ONE channel, as the AE library of this module */
		return -EINVAL;
	blk = kzalloc(T41_AWB_ALGO_INFO_BYTES, GFP_KERNEL);
	if (!blk)
		return -ENOMEM;
	mutex_lock(&t41_awb_algo_lock);
	if (t41_awb_algo_info) {		/* registered already: keep the first library */
		mutex_unlock(&t41_awb_algo_lock);
		kfree(blk);
		return -EBUSY;
	}
	t41_awb_algo_init_attr(&u[2]);
	if (private_copy_to_user((void __user *)(uintptr_t)user, u, sizeof(u))) {
		mutex_unlock(&t41_awb_algo_lock);
		kfree(blk);
		return -EFAULT;
	}
	if (!t41_awb_algo_comp_ready) {		/* once: a completion with a waiter must never be initialised again */
		init_completion(&t41_awb_algo_comp);
		t41_awb_algo_comp_ready = true;
	}
	t41_awb_algo_comp.done = 0;		/* a new library starts without a pending frame */
	t41_awb_algo_manual = false;
	t41_awb_algo_gets = t41_awb_algo_sets = 0;
	t41_awb_algo_owner = file;
	t41_awb_algo_info = blk;
	WRITE_ONCE(t41_awb_algo_on, 1);
	mutex_unlock(&t41_awb_algo_lock);
	return 0;
}

static int t41_awb_algo_close(u32 user)
{
	u32 u[2];

	if (!user || private_copy_from_user(u, (const void __user *)(uintptr_t)user, sizeof(u)))
		return -EFAULT;
	if (u[1] != 0)
		return -EINVAL;
	mutex_lock(&t41_awb_algo_lock);
	t41_awb_algo_unregister_locked();	/* a repeated close frees nothing */
	mutex_unlock(&t41_awb_algo_lock);
	return 0;
}

static int t41_awb_algo_get(u32 user)
{
	u32 u[2];
	unsigned char *info;
	int ret;

	if (!user || private_copy_from_user(u, (const void __user *)(uintptr_t)user, sizeof(u)))
		return -EFAULT;
	if (u[1] != 0)
		return -EINVAL;
	mutex_lock(&t41_awb_algo_lock);
	ret = t41_awb_algo_info ? 0 : -EINVAL;	/* no library registered: nothing would ever complete */
	mutex_unlock(&t41_awb_algo_lock);
	if (ret)
		return ret;
	ret = private_wait_for_completion_interruptible(&t41_awb_algo_comp);
	if (ret)
		return ret;
	mutex_lock(&t41_awb_algo_lock);
	info = t41_awb_algo_info;
	if (!info) {				/* closed while waiting */
		mutex_unlock(&t41_awb_algo_lock);
		return -EINVAL;
	}
	memset(info, 0, T41_AWB_ALGO_INFO_BYTES);
	memcpy(info, &(u32){ T41_AWB_ALGO_COOKIE }, 4);
	t41_awb_algo_fill_info(info + 8);
	t41_awb_algo_gets++;
	ret = private_copy_to_user((void __user *)(uintptr_t)user, info, T41_AWB_ALGO_INFO_BYTES) ? -EFAULT : 0;
	mutex_unlock(&t41_awb_algo_lock);
	return ret;
}

static int t41_awb_algo_set(u32 user)
{
	u32 u[6];

	if (!user || private_copy_from_user(u, (const void __user *)(uintptr_t)user, sizeof(u)))
		return -EFAULT;
	if (u[1] != 0)
		return -EINVAL;
	mutex_lock(&t41_awb_algo_lock);
	if (!t41_awb_algo_info) {		/* a late result after the close must not take the white balance over again */
		mutex_unlock(&t41_awb_algo_lock);
		return -EINVAL;
	}
	if (u[2] == 1 && u[3] >= T41_AWB_ALGO_GAIN_MIN && u[3] <= T41_AWB_ALGO_GAIN_MAX && u[4] >= T41_AWB_ALGO_GAIN_MIN && u[4] <= T41_AWB_ALGO_GAIN_MAX) {
		if (t41_awb_algo_apply(u[3], u[4]))
			pr_warn_once("t41: custom AWB result not applied (AWB not running)\n");
	}
	t41_awb_algo_sets++;
	mutex_unlock(&t41_awb_algo_lock);
	return 0;
}

/* tx_isp_release hook: the file that registered the library is going away */
static void t41_awb_algo_release(uintptr_t file)
{
	mutex_lock(&t41_awb_algo_lock);
	if (t41_awb_algo_info && t41_awb_algo_owner == file)
		t41_awb_algo_unregister_locked();
	mutex_unlock(&t41_awb_algo_lock);
}

static int t41_ioctl_awb_algo(uintptr_t file, uint32_t cmd, uint32_t user_arg)
{
	switch (cmd) {
	case 0xc0045423U: return t41_awb_algo_get(user_arg);
	case 0xc0045424U: return t41_awb_algo_set(user_arg);
	case 0xc0045425U: return t41_awb_algo_open(file, user_arg);
	case 0xc0045426U: return t41_awb_algo_close(user_arg);
	}
	return -ENOTTY;
}
/* T41-AWB-ALGO-PROTOCOL-END */

/* ---- hardware side: the native AWB (tx_isp_t41_awb_runtime.inc) ---- */

/* Gains of the library are the hardware white-balance gains in the unit of IMP_ISP_Tuning_SetWB / the OPEN_AWB_CONTROL route (1024 = 1.0, accepted
 * range 0x200..0x1800): the same value is what the info block reports as the current gain (the last gain written to the WB registers, automatic or
 * not), so a library that answers with what it was given changes nothing.  A result takes the white balance manually (t41_native_awb_compat: frozen
 * hardware gains), the close gives the application's state back. */
struct t41_awb_algo_snap {
	u32 mode, freeze, ct, public_freeze, ctl[3];
	u16 r16, b16;
	u32 hw_r, hw_b;
};
static struct t41_awb_algo_snap t41_awb_algo_snap;

/* IMPISPAwbInitAttr: {awb_sta_en, start_h, start_v, node_h, node_v (bytes), mode} from the zone grid the native AWB runs with */
static void t41_awb_algo_init_attr(u32 attr[5])
{
	struct t41_awb_runtime *s;
	unsigned char *a = (unsigned char *)attr;

	memset(attr, 0, 5 * sizeof(u32));
	attr[0] = 1;				/* statistics enabled */
	attr[4] = 1;				/* limited statistics (as the T40 registration) */
	mutex_lock(&t41_native_awb_lock);
	s = t41_native_awb_object(0);
	if (s) {
		attr[1] = t41_tmo_le16(s->saved.p + 0xc70);
		attr[2] = t41_tmo_le16(s->saved.p + 0xc6c);
		a[12] = (unsigned char)t41_tmo_le16(s->saved.p + 0xc72);
		a[13] = (unsigned char)t41_tmo_le16(s->saved.p + 0xc6e);
	}
	mutex_unlock(&t41_native_awb_lock);
}

/* IMPISPAwbInfo: current gains (the gains in the WB registers), global statistics (the three-word order of the T40 info block), zone statistics
 * (2700 bytes, left zero when no fresh frame) */
static void t41_awb_algo_fill_info(unsigned char *info)
{
	u32 gl[4], cur[2] = { READ_ONCE(t41_awb_last_rgain), READ_ONCE(t41_awb_last_bgain) };

	memcpy(info + 0, &cur[0], 4);			/* cur_r_gain */
	memcpy(info + 4, &cur[1], 4);			/* cur_b_gain */
	if (!t41_native_awb_control(0, T41_AWB_GLOBAL, gl, sizeof(gl), 1)) {
		memcpy(info + 8, &gl[2], 4);		/* r_gain_statis */
		memcpy(info + 12, &gl[3], 4);		/* b_gain_statis */
		memcpy(info + 16, &gl[0], 4);		/* r_gain_wei_statis */
		memcpy(info + 20, &gl[1], 4);		/* b_gain_wei_statis */
	}
	t41_native_awb_control(0, T41_AWB_ZONE, info + 24, 2700, 1);	/* -EAGAIN (no fresh frame): stays zero */
}

/* manual white balance with the library's gains.  The first answer remembers the application's state (mode, freeze, manual gains, CT, WB registers). */
static int t41_awb_algo_apply(u32 r, u32 b)
{
	struct t41_awb_runtime *s;
	struct t41_awb_algo_snap *p = &t41_awb_algo_snap;

	mutex_lock(&t41_native_awb_lock);
	s = t41_native_awb_object(0);
	if (!s) {
		mutex_unlock(&t41_native_awb_lock);
		return -ENODEV;
	}
	if (!t41_awb_algo_manual) {
		p->mode = s->saved.s[0xeaa2];
		p->freeze = s->saved.s[0xeaa1];
		p->ct = t41_tmo_le32(s->saved.s + 0xeaa4);
		p->r16 = t41_tmo_le16(s->saved.s + 0xeaa8);
		p->b16 = t41_tmo_le16(s->saved.s + 0xeaaa);
		p->public_freeze = s->saved.public_freeze;
		memcpy(p->ctl, s->saved.control, sizeof(p->ctl));
		p->hw_r = READ_ONCE(t41_awb_last_rgain);
		p->hw_b = READ_ONCE(t41_awb_last_bgain);
	} else if (s->saved.s[0xeaa1] == 1 && s->saved.public_freeze == 1 &&
		   READ_ONCE(t41_awb_last_rgain) == r && READ_ONCE(t41_awb_last_bgain) == b) {
		mutex_unlock(&t41_native_awb_lock);	/* already what the library asked for: no work */
		return 0;
	}
	mutex_unlock(&t41_native_awb_lock);
	if (t41_native_awb_compat(0, r, b, 0, NULL))	/* manual: registers of both banks, frozen */
		return -EINVAL;
	t41_awb_algo_manual = true;
	return 0;
}

/* the application's state: its registers, mode, freeze flag, manual gains and CT (a candidate copy published like every other control) */
static void t41_awb_algo_restore(void)
{
	struct t41_awb_algo_snap *p = &t41_awb_algo_snap;
	struct t41_awb_runtime *s;
	struct t41_awb_register words[10];
	unsigned int gains[2] = { p->hw_r, p->hw_b }, wb[2], bank, i, n = 0;

	mutex_lock(&t41_native_awb_lock);
	s = t41_native_awb_object(0);
	if (!s) {
		mutex_unlock(&t41_native_awb_lock);
		return;
	}
	memcpy(&s->candidate, &s->saved, sizeof(s->candidate));
	s->candidate.s[0xeaa2] = p->mode;
	s->candidate.s[0xeaa1] = p->freeze;
	s->candidate.s[0xeaa0] = 1;
	t41_ae_put32(s->candidate.s + 0xeaa4, p->ct);
	t41_awb_gain_put16(s->candidate.s + 0xeaa8, p->r16);
	t41_awb_gain_put16(s->candidate.s + 0xeaaa, p->b16);
	memcpy(s->candidate.control, p->ctl, sizeof(p->ctl));
	s->candidate.public_freeze = p->public_freeze;
	if (p->hw_r >= 0x200U && p->hw_r <= 0x1800U && p->hw_b >= 0x200U && p->hw_b <= 0x1800U) {
		t41_awb_gain_pack(gains, wb);		/* the WB registers show the gains the application had */
		for (bank = 0; bank < 2; ++bank) {
			for (i = 0; i < 4; ++i) {
				words[n].address = 0x4004 + bank * 0x1000 + i * 4;
				words[n++].value = wb[i & 1];
			}
			words[n].address = 0x4000 + bank * 0x1000;
			words[n++].value = 1;
		}
	}
	t41_native_awb_emit(words, n);
	t41_native_awb_save(s);
	mutex_unlock(&t41_native_awb_lock);
}

#endif
