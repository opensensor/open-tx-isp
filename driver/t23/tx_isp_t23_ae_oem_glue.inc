/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Stock T23 AE0 chain lifted instruction for instruction from tx-isp-t23.ko
 * (audit/dolift_ae.py -> tx_isp_t23_ae_oem.inc), with the glue it needs in
 * this driver.  On by default (source_ae_oem=1); with source_ae_oem=0 nothing
 * here runs and the HLIL substitute in tx_isp_t23_ae_runtime.inc is in
 * charge.
 *
 * The lifted code keeps private copies of every stock object it touches
 * (oem_*), only tparams (the active IQ bank, same layout) is shared.  The
 * stock side effects are routed here:
 *  - system_reg_write/read: the ISP registers, unchanged;
 *  - sensor_ctrl callbacks (oem_sensor_ctrl, filled like stock sensor_init):
 *    alloc_* call the sensor attribute allocators, set_* only latch the new
 *    integration time / analog gain like stock does, the latched pair is
 *    sent to the sensor after the AE run (stock: next frame interrupt);
 *  - tisp_event_push: event 1 (AE0 histogram ready) schedules the AE run,
 *    the gain events the AE run emits are applied after it.
 *
 * Verified in the MIPS emulator (register writes, events and sensor calls
 * identical to stock for the scene set in audit/aelift_emu.py) and on
 * cam-B (sc2336): startup, AE comp / backlight / highlight, day/night and
 * stream restarts.
 */

module_param_named(source_ae_oem, regtrace_t23_source_ae_oem, bool, 0444);
MODULE_PARM_DESC(source_ae_oem,
		 "run the stock AE0 algorithm lifted from the OEM module (default 1); 0 = the HLIL AE substitute (needs reload)");

static bool t23_aelift_debug;
module_param_named(ae_oem_debug, t23_aelift_debug, bool, 0644);
MODULE_PARM_DESC(ae_oem_debug, "log the lifted stock AE0's exposure and gain changes");

static noinline __attribute__((noipa)) uint32_t t23_aelift_event_push(uint32_t channel, uint32_t event);
static void *t23_aelift_buf;

/* lifted entry: the caller's outgoing argument area (stock 16(sp)..) */
#define T23_AELIFT_CALL(fn, a0, a1, a2, a3) ({			\
	uint32_t stk_[8] = { 0 };				\
	fn((a0), (a1), (a2), (a3), (uint32_t)(uintptr_t)stk_);	\
})

static noinline __attribute__((noipa)) void *t23_aelift_kmalloc(uint32_t size)
{
	/* only tiziano_ae_init allocates (0x3580 bytes); keep one buffer */
	if (!t23_aelift_buf)
		t23_aelift_buf = kzalloc(size, GFP_KERNEL);
	return t23_aelift_buf;
}

static noinline __attribute__((noipa)) void t23_aelift_reg_write(uint32_t reg, uint32_t value)
{
	if (t23_aelift_debug) {
		static uint32_t regs[32], vals[32];
		static unsigned int used;
		unsigned int i;

		for (i = 0; i < used && regs[i] != reg; i++)
			;
		if (i == used && used < ARRAY_SIZE(regs))
			regs[used++] = reg;
		if (i < ARRAY_SIZE(regs) && vals[i] != value) {
			vals[i] = value;
			printk_ratelimited(KERN_WARNING
			       "t23: ae-oem reg 0x%x=0x%x\n",
			       reg, value);
		}
	}
	system_reg_write(reg, value);
}

static noinline __attribute__((noipa)) uint32_t t23_aelift_reg_read(uint32_t reg)
{
	return (uint32_t)system_reg_read(reg);
}

/* stock code calling through a function pointer that is not lifted code */
static uint64_t t23_aelift_call(uint32_t fn, uint32_t a0, uint32_t a1,
				uint32_t a2, uint32_t a3)
{
	if (!fn) {
		WARN_ONCE(1, "aelift: NULL call\n");
		return 0;
	}
	return ((uint32_t (*)(uint32_t, uint32_t, uint32_t, uint32_t))
		(uintptr_t)fn)(a0, a1, a2, a3);
}

/* only their addresses appear in the lifted code (calls go to the glue) */
int tisp_event_set_cb(uint32_t channel, uint32_t event_id, void *callback);
int32_t tisp_event_push(uint32_t channel, const void *event);
int32_t system_irq_func_set(int32_t arg1, int32_t arg2, int32_t arg3);

#include "tx_isp_t23_ae_oem.inc"

/* ---- runtime (source_ae_oem=1) ---------------------------------------- */

#define T23_AELIFT_EVENTS 16U
struct t23_aelift_event {
	uint32_t id;
	uint32_t args[8];
};
static DEFINE_SPINLOCK(t23_aelift_ev_lock);
static struct t23_aelift_event t23_aelift_ev[T23_AELIFT_EVENTS];
static unsigned int t23_aelift_ev_count;
static bool t23_aelift_ready;
static uint32_t t23_aelift_it, t23_aelift_again;   /* latched by set_* */
static bool t23_aelift_expo_dirty;

static void t23_aelift_work_fn(struct work_struct *work);
TX_LS_TIMED_WORK(t23_aelift_work_timed, t23_aelift_work_fn, T23_LS_WORK_AE_LIFT)
static DECLARE_WORK(t23_aelift_work, t23_aelift_work_timed);
/*
 * Process-context users of the lifted AE state: the AE work
 * (tisp_ae0_process), stream start (tiziano_ae_init, state copy), the
 * setters (max gain, anti-flicker, compensation), the day/night refresh and
 * the read-backs.  Stock has the same two contexts unlocked (ioctl vs the
 * event thread); here a setter can no longer tear a LUT the process run is
 * reading.  The interrupt-side statistics copy is not under it (as stock).
 */
static DEFINE_MUTEX(t23_aelift_mutex);
/*
 * Review2 L1: the AE0 statistics handlers run in the core ISR; the day/night
 * refresh and the anti-flicker rewrite (process context, under the mutex)
 * take them off with this busy flag, as the ADR/defog lift does.
 */
static DEFINE_SPINLOCK(t23_aelift_irq_lock);
static bool t23_aelift_busy;

static void t23_aelift_set_busy(bool busy)
{
	unsigned long flags;

	spin_lock_irqsave(&t23_aelift_irq_lock, flags);
	t23_aelift_busy = busy;
	spin_unlock_irqrestore(&t23_aelift_irq_lock, flags);
}

static noinline __attribute__((noipa)) uint32_t t23_aelift_event_push(uint32_t channel, uint32_t event)
{
	const uint32_t *rec = (const uint32_t *)(uintptr_t)event;
	unsigned long flags;

	(void)channel;
	if (!rec)
		return (uint32_t)-EINVAL;
	/* stock record: id at +8, arguments from +0x10 */
	if (rec[2] == 1U) {
		if (t23_aelift_ready)
			schedule_work(&t23_aelift_work);
		return 0;
	}
	spin_lock_irqsave(&t23_aelift_ev_lock, flags);
	if (t23_aelift_ev_count < T23_AELIFT_EVENTS) {
		struct t23_aelift_event *e = &t23_aelift_ev[t23_aelift_ev_count++];

		e->id = rec[2];
		memcpy(e->args, &rec[4], sizeof(e->args));
	}
	spin_unlock_irqrestore(&t23_aelift_ev_lock, flags);
	return 0;
}

static unsigned char *t23_aelift_attr(void)
{
	return regtrace_t23_sensor_owned_attr();
}

typedef uint32_t (*t23_aelift_alloc_fn)(uint32_t value, uint32_t shift,
					 uint32_t *sensor_value);

static uint32_t t23_aelift_alloc(unsigned int attr_off, uint32_t value,
				 uint32_t shift, uint16_t *out)
{
	unsigned char *attr = t23_aelift_attr();
	t23_aelift_alloc_fn fn;
	uint32_t sensor_value = 0;
	uint32_t ret;

	fn = attr ? *(t23_aelift_alloc_fn *)(void *)(attr + attr_off) : NULL;
	if (!fn) {
		*out = (uint16_t)value;
		return value;
	}
	ret = fn(value, shift, &sensor_value);
	*out = (uint16_t)sensor_value;
	return ret;
}

/* stock sensor_alloc_* write the sensor code into the struct at a1 */
static uint32_t t23_aelift_alloc_again(uint32_t v, uint32_t p, uint32_t a2, uint32_t a3)
{
	return t23_aelift_alloc(0xc4, v, 16, (uint16_t *)(uintptr_t)p);
}

static uint32_t t23_aelift_alloc_dgain(uint32_t v, uint32_t p, uint32_t a2, uint32_t a3)
{
	return t23_aelift_alloc(0xcc, v, 16, (uint16_t *)(uintptr_t)(p + 2));
}

static uint32_t t23_aelift_alloc_it(uint32_t v, uint32_t p, uint32_t a2, uint32_t a3)
{
	return t23_aelift_alloc(0xd4, v, 0, (uint16_t *)(uintptr_t)(p + 16));
}

static uint32_t t23_aelift_set_it(uint32_t v, uint32_t a1, uint32_t a2, uint32_t a3)
{
	v &= 0xffffU;
	if (v != t23_aelift_it) {
		t23_aelift_it = v;
		t23_aelift_expo_dirty = true;
	}
	return 0;
}

static uint32_t t23_aelift_set_again(uint32_t v, uint32_t a1, uint32_t a2, uint32_t a3)
{
	v &= 0xffffU;
	if (v != t23_aelift_again) {
		t23_aelift_again = v;
		t23_aelift_expo_dirty = true;
	}
	return 0;
}

static uint32_t t23_aelift_nop(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
	return 0;
}

static void t23_aelift_put(unsigned int off, const void *fn)
{
	*(uint32_t *)(void *)(oem_sensor_ctrl + off) = (uint32_t)(uintptr_t)fn;
}

/* stock sensor_init(&sensor_ctrl) */
static int t23_aelift_sensor_init(void)
{
	unsigned char *attr = t23_aelift_attr();
	unsigned char *sc = oem_sensor_ctrl;
	unsigned int off;

	if (!attr)
		return -ENODEV;
	*(uint32_t *)(void *)(sc + 0x20) = regtrace_t23_get_le32(attr + 152);
	*(uint32_t *)(void *)(sc + 0x24) = regtrace_t23_get_le32(attr + 156);
	sc[0x3a] = attr[186];
	sc[0x3b] = attr[188];
	sc[0x3c] = attr[190];
	*(uint32_t *)(void *)(sc + 0x28) = *(uint16_t *)(void *)(attr + 168);
	*(uint32_t *)(void *)(sc + 0x2c) = *(uint16_t *)(void *)(attr + 184);
	*(uint32_t *)(void *)(sc + 0x50) = *(uint16_t *)(void *)(attr + 220);
	*(uint32_t *)(void *)(sc + 0x54) = *(uint16_t *)(void *)(attr + 222);
	*(uint32_t *)(void *)(sc + 0x58) = regtrace_t23_get_le32(attr + 228);
	for (off = 0x5c; off <= 0xb0; off += 4)
		t23_aelift_put(off, t23_aelift_nop);
	t23_aelift_put(0x64, t23_aelift_alloc_again);
	t23_aelift_put(0x6c, t23_aelift_alloc_dgain);
	t23_aelift_put(0x70, t23_aelift_alloc_it);
	t23_aelift_put(0x78, t23_aelift_set_it);
	t23_aelift_put(0x88, t23_aelift_set_again);
	return 0;
}

/*
 * Stock ispcore_core_ops_init builds the 156-byte tisp_init argument that
 * tisp_init copies into sensor_info; the AE reads its sensor fields
 * (deflicker: +0x30 fps, +0x48/+0x4a; ae_init: +0x3c).  Same fields here.
 */
static void t23_aelift_fill_sensor_info(unsigned char *attr, uint32_t width,
					uint32_t height, uint32_t fps)
{
	unsigned char *si = oem_sensor_info;
	static const unsigned short u16map[][2] = {
		{ 0x3c, 168 }, { 0x3e, 170 }, { 0x40, 172 }, { 0x42, 174 },
		{ 0x48, 180 }, { 0x4a, 182 }, { 0x4c, 184 }, { 0x4e, 186 },
		{ 0x50, 188 }, { 0x52, 190 }, { 0x56, 220 }, { 0x58, 222 },
	};
	static const unsigned short u32map[][2] = {
		{ 0x20, 152 }, { 0x24, 156 }, { 0x28, 160 }, { 0x2c, 164 },
		{ 0x44, 176 }, { 0x5c, 224 }, { 0x60, 228 }, { 0x64, 232 },
	};
	unsigned int i;
	uint32_t vts = *(uint16_t *)(void *)(attr + 182);

	memset(si, 0, 156);
	*(uint32_t *)(void *)(si + 0x00) = width;
	*(uint32_t *)(void *)(si + 0x04) = height;
	*(uint32_t *)(void *)(si + 0x30) = fps;
	for (i = 0; i < ARRAY_SIZE(u16map); i++)
		*(uint16_t *)(void *)(si + u16map[i][0]) =
			*(uint16_t *)(void *)(attr + u16map[i][1]);
	for (i = 0; i < ARRAY_SIZE(u32map); i++)
		*(uint32_t *)(void *)(si + u32map[i][0]) =
			regtrace_t23_get_le32(attr + u32map[i][1]);
	/* stock: line time, 1000000 * (fps & 0xffff) / (fps >> 16) / vts (u16) */
	if ((fps >> 16) && vts)
		*(uint16_t *)(void *)(si + 0x54) = (uint16_t)
			(((fps & 0xffffU) * 1000000U / (fps >> 16)) / vts);
}

/*
 * Process context, after the AE statistics grid is programmed and tparams
 * holds the active bank.  Stock tisp_init calls
 * tiziano_ae_init(tispinfo[1], tispinfo[0], u16 sensor_info+0x3c, ...);
 * only the third argument is used (stored as the first IspAeExp word).
 */
static uint32_t regtrace_t23_sensor_held_fps(void);

static int t23_aelift_init(uint32_t width, uint32_t height, uint32_t fps)
{
	uint32_t *info = (uint32_t *)(void *)oem_tispinfo;
	unsigned char *attr = t23_aelift_attr();
	int ret;

	t23_aelift_ready = false;
	if (!regtrace_t23_core_dma_bufs[0].virt || !attr)
		return -ENODEV;
	ret = t23_aelift_sensor_init();
	if (ret)
		return ret;
	/* stock tisp_init: AE0 statistics ring, then the histogram ring */
	info[3] = (uint32_t)(uintptr_t)regtrace_t23_core_dma_bufs[0].virt;
	info[6] = info[3] + 0x4000U;
	t23_aelift_fill_sensor_info(attr, width, height, fps);
	T23_AELIFT_CALL(LA_tiziano_ae_init, 0, 0,
			*(uint16_t *)(void *)(oem_sensor_info + 0x3c), 0);
	t23_aelift_ready = true;
	return 0;
}

/*
 * Stream restarts.  The stock module runs tiziano_ae_init once in tisp_init
 * and keeps the AE state and the sensor exposure across FrameSource
 * restarts; this driver starts the core (and calls t23_aelift_init) at
 * every stream start.  So a restart with the same picture size and frame
 * rate keeps the AE: the lifted state (every writable stock object but the
 * sensor callbacks, the sensor info and the DMA ring pointers, and the AE
 * buffer tiziano_ae_init allocates) is taken before tiziano_ae_init writes
 * the AE hardware registers again and is put back afterwards, then the
 * last exposure and total gain go to the sensor and the ISP at once.
 * Without it the first pictures after a restart are taken at the
 * tiziano_ae_init start exposure (measured on cam-B at night: mean luma 1
 * instead of 19 in the first snapshot).
 */
static const struct {
	void *p;
	size_t n;
} t23_aelift_state[] = {
	{ oem_EffectCount0, sizeof(oem_EffectCount0) },
	{ oem_EffectFrame, sizeof(oem_EffectFrame) },
	{ oem_IspAe0WmeanParam, sizeof(oem_IspAe0WmeanParam) },
	{ oem_IspAe1WmeanParam, sizeof(oem_IspAe1WmeanParam) },
	{ oem_IspAeExp, sizeof(oem_IspAeExp) },
	{ oem_IspAeFlag, sizeof(oem_IspAeFlag) },
	{ oem_IspAeStatic, sizeof(oem_IspAeStatic) },
	{ oem_IspAeTuneParam, sizeof(oem_IspAeTuneParam) },
	{ oem__AePointPos, sizeof(oem__AePointPos) },
	{ oem__ae_ev, sizeof(oem__ae_ev) },
	{ oem__ae_parameter, sizeof(oem__ae_parameter) },
	{ oem__ae_reg, sizeof(oem__ae_reg) },
	{ oem__ae_result, sizeof(oem__ae_result) },
	{ oem__ae_stat, sizeof(oem__ae_stat) },
	{ oem__ae_wm_q, sizeof(oem__ae_wm_q) },
	{ oem__ae_zone_weight, sizeof(oem__ae_zone_weight) },
	{ oem__at_list, sizeof(oem__at_list) },
	{ oem__at_list_wdr, sizeof(oem__at_list_wdr) },
	{ oem__deflick_lut, sizeof(oem__deflick_lut) },
	{ oem__deflicker_para, sizeof(oem__deflicker_para) },
	{ oem__exp_parameter, sizeof(oem__exp_parameter) },
	{ oem__flicker_t, sizeof(oem__flicker_t) },
	{ oem__log2_lut, sizeof(oem__log2_lut) },
	{ oem__lum_list, sizeof(oem__lum_list) },
	{ oem__lum_list_wdr, sizeof(oem__lum_list_wdr) },
	{ oem__nodes_num, sizeof(oem__nodes_num) },
	{ oem__scene_para, sizeof(oem__scene_para) },
	{ oem__scene_para_wdr, sizeof(oem__scene_para_wdr) },
	{ oem__scene_roi_weight, sizeof(oem__scene_roi_weight) },
	{ oem__scene_roui_weight, sizeof(oem__scene_roui_weight) },
	{ oem__weight_lut, sizeof(oem__weight_lut) },
	{ oem_ad0_cache, sizeof(oem_ad0_cache) },
	{ oem_ae0_ev_list, sizeof(oem_ae0_ev_list) },
	{ oem_ae0_ev_list_wdr, sizeof(oem_ae0_ev_list_wdr) },
	{ oem_ae1_comp_ev_list, sizeof(oem_ae1_comp_ev_list) },
	{ oem_ae1_ev_list, sizeof(oem_ae1_ev_list) },
	{ oem_ae_algo_comp, sizeof(oem_ae_algo_comp) },
	{ oem_ae_comp_at_list, sizeof(oem_ae_comp_at_list) },
	{ oem_ae_comp_default, sizeof(oem_ae_comp_default) },
	{ oem_ae_comp_ev_list, sizeof(oem_ae_comp_ev_list) },
	{ oem_ae_comp_param, sizeof(oem_ae_comp_param) },
	{ oem_ae_comp_param_wdr, sizeof(oem_ae_comp_param_wdr) },
	{ oem_ae_comp_x, sizeof(oem_ae_comp_x) },
	{ oem_ae_ctrls, sizeof(oem_ae_ctrls) },
	{ oem_ae_ev_init_en, sizeof(oem_ae_ev_init_en) },
	{ oem_ae_ev_init_strict, sizeof(oem_ae_ev_init_strict) },
	{ oem_ae_ev_step, sizeof(oem_ae_ev_step) },
	{ oem_ae_exp_th, sizeof(oem_ae_exp_th) },
	{ oem_ae_extra_at_list, sizeof(oem_ae_extra_at_list) },
	{ oem_ae_extra_at_list_wdr, sizeof(oem_ae_extra_at_list_wdr) },
	{ oem_ae_scene_mode_th, sizeof(oem_ae_scene_mode_th) },
	{ oem_ae_scene_mode_th_wdr, sizeof(oem_ae_scene_mode_th_wdr) },
	{ oem_ae_show_info, sizeof(oem_ae_show_info) },
	{ oem_ae_stable_tol, sizeof(oem_ae_stable_tol) },
	{ oem_ag0_cache, sizeof(oem_ag0_cache) },
	{ oem_ag_new, sizeof(oem_ag_new) },
	{ oem_again_new, sizeof(oem_again_new) },
	{ oem_again_old, sizeof(oem_again_old) },
	{ oem_dg0_cache, sizeof(oem_dg0_cache) },
	{ oem_dg_new, sizeof(oem_dg_new) },
	{ oem_ev0_cache, sizeof(oem_ev0_cache) },
	{ oem_frameNum, sizeof(oem_frameNum) },
	{ oem_frame_cunt, sizeof(oem_frame_cunt) },
	{ oem_ftune_wmeans_36425, sizeof(oem_ftune_wmeans_36425) },
	{ oem_scene_luma_old, sizeof(oem_scene_luma_old) },
	{ oem_scene_luma_weight, sizeof(oem_scene_luma_weight) },
	{ oem_scene_luma_wmean, sizeof(oem_scene_luma_wmean) },
	{ oem_ta_custom_en, sizeof(oem_ta_custom_en) },
	{ oem_tisp_ae_ctrls, sizeof(oem_tisp_ae_ctrls) },
	{ oem_tisp_ae_hist, sizeof(oem_tisp_ae_hist) },
	{ oem_tisp_ae_hist_last, sizeof(oem_tisp_ae_hist_last) },
	{ oem_total_gain_new, sizeof(oem_total_gain_new) },
	{ oem_total_gain_old, sizeof(oem_total_gain_old) },
};
#define T23_AELIFT_BUF_SIZE 0x3580U
#define T23_AELIFT_STATE_BYTES (37752U)
static uint8_t *t23_aelift_saved;
static bool t23_aelift_inited;
static uint32_t t23_aelift_init_w, t23_aelift_init_h, t23_aelift_init_fps;
static uint32_t t23_aelift_tgain;		/* last event-4 total gain, Q16 */
static uint32_t t23_aelift_ev_q10;		/* last event-6 scene EV, Q10 */
static uint32_t t23_aelift_ev_hi;
static bool t23_aelift_ev_seen;

/*
 * Scene EV for AWB (indoor/outdoor weights) and the CCM saturation.  Stock
 * gets it from AE event 6 (tisp_long_ev_update -> tisp_awb_ev_update,
 * tisp_ccm_ev_update); with the HLIL substitute it is its rung EV.
 */
static uint32_t regtrace_t23_ae_ev_q10(void)
{
	if (regtrace_t23_source_ae_oem && t23_aelift_ev_seen)
		return t23_aelift_ev_q10;
	return regtrace_t23_source_ae_hlil_ev;
}

static void t23_aelift_state_copy(bool save)
{
	uint8_t *q = t23_aelift_saved;
	unsigned int i;

	for (i = 0; i < ARRAY_SIZE(t23_aelift_state); i++) {
		if (save)
			memcpy(q, t23_aelift_state[i].p, t23_aelift_state[i].n);
		else
			memcpy(t23_aelift_state[i].p, q, t23_aelift_state[i].n);
		q += t23_aelift_state[i].n;
	}
	if (t23_aelift_buf) {
		if (save)
			memcpy(q, t23_aelift_buf, T23_AELIFT_BUF_SIZE);
		else
			memcpy(t23_aelift_buf, q, T23_AELIFT_BUF_SIZE);
	}
}

static void t23_aelift_s_max_gain_locked(unsigned int slot,
					 unsigned int flag_off, uint32_t value);
static int t23_aelift_s_antiflick_locked(uint32_t hz);
static uint32_t t23_aelift_max_set[4];	/* value + 1 per slot, 0 = unset */

static void t23_aelift_start(void)
{
	uint32_t fps = regtrace_t23_sensor_held_fps();
	uint32_t width = regtrace_t23_source_sensor_width;
	uint32_t height = regtrace_t23_source_sensor_height;
	uint32_t it = t23_aelift_it, again = t23_aelift_again;
	unsigned long flags;
	bool resume;
	int ret;

	if (!regtrace_t23_source_ae_oem)
		return;
	/* no AE run of the previous stream is left over */
	flush_work(&t23_aelift_work);
	if (!t23_aelift_saved)
		t23_aelift_saved = kmalloc(T23_AELIFT_STATE_BYTES, GFP_KERNEL);
	resume = t23_aelift_inited && t23_aelift_saved && it && again &&
		 width == t23_aelift_init_w && height == t23_aelift_init_h &&
		 fps == t23_aelift_init_fps;
	mutex_lock(&t23_aelift_mutex);
	if (resume)
		t23_aelift_state_copy(true);
	ret = t23_aelift_init(width, height, fps);
	if (!ret) {
		t23_aelift_inited = true;
		t23_aelift_init_w = width;
		t23_aelift_init_h = height;
		t23_aelift_init_fps = fps;
	}
	if (!ret && resume)
		t23_aelift_state_copy(false);
	mutex_unlock(&t23_aelift_mutex);
	if (!ret && resume) {
		spin_lock_irqsave(&t23_aelift_ev_lock, flags);
		t23_aelift_ev_count = 0;	/* tiziano_ae_init's start gain */
		spin_unlock_irqrestore(&t23_aelift_ev_lock, flags);
		t23_aelift_it = it;
		t23_aelift_again = again;
		t23_aelift_expo_dirty = false;
		regtrace_t23_call_sensor_exposure((again << 16) | it,
						  "ae-oem-resume");
		if (t23_aelift_tgain)
			regtrace_t23_source_apply_total_gain_value(
				t23_aelift_tgain, 0, false, false);
		printk(KERN_WARNING
		       "t23: stock AE0 resumed it=%u again=%u tgain=0x%x\n",
		       it, again, t23_aelift_tgain);
	}
	/* maximum gains set before the lift ran (fresh start only: a resumed
	 * state already holds them) */
	mutex_lock(&t23_aelift_mutex);
	if (!ret && !resume) {
		if (t23_aelift_max_set[1])
			t23_aelift_s_max_gain_locked(1U, 0x14U,
						     t23_aelift_max_set[1] - 1U);
		if (t23_aelift_max_set[3])
			t23_aelift_s_max_gain_locked(3U, 0x1cU,
						     t23_aelift_max_set[3] - 1U);
	}
	/* an anti-flicker mode set before the lift ran (fresh start only) */
	if (!ret && !resume && regtrace_t23_ae_flicker_mode)
		t23_aelift_s_antiflick_locked(
			regtrace_t23_ae_flicker_mode == 1U ? 50U : 60U);
	/* an AE compensation set before the lift ran (it is stored only) */
	if (!ret && regtrace_t23_source_ae_compensation != 128U)
		T23_AELIFT_CALL(LA_tisp_ae_s_comp,
				regtrace_t23_source_ae_compensation, 0, 0, 0);
	mutex_unlock(&t23_aelift_mutex);
	printk(KERN_WARNING
	       "t23: stock AE0 (lifted) %s ret=%d fps=0x%x\n",
	       ret ? "NOT started" : "active", ret, fps);
}

/*
 * Stock tiziano_ae_s_max_again / tiziano_ae_s_max_isp_dgain on the lifted
 * copies: the reload flag in ae_extra_at_list_wdr (+0x14 again, +0x1c ISP
 * dgain), ae_exp_th[slot] = 2^(value/32) in Q10, IspAeFlag[7] = 0.  The
 * values are kept across a stream restart's tiziano_ae_init by the state
 * copy (t23_aelift_start).
 */
static void t23_aelift_s_max_gain_locked(unsigned int slot,
					 unsigned int flag_off, uint32_t value)
{
	if (!regtrace_t23_source_ae_oem)
		return;
	t23_aelift_max_set[slot & 3U] = value + 1U;
	*(uint32_t *)(void *)(oem_ae_extra_at_list_wdr + flag_off) = 1;
	((uint32_t *)(void *)oem_ae_exp_th)[slot] =
		tisp_math_exp2(value, 5, 10);
	((uint32_t *)(void *)oem_IspAeFlag)[7] = 0;
}

static void t23_aelift_s_max_gain(unsigned int slot, unsigned int flag_off,
				  uint32_t value)
{
	mutex_lock(&t23_aelift_mutex);
	t23_aelift_s_max_gain_locked(slot, flag_off, value);
	mutex_unlock(&t23_aelift_mutex);
}

/*
 * Stock tisp_s_antiflick (0x658c4) for the lifted AE.  hz is 0 (off), 50 or
 * 60 (the 0x980918 power line control maps 0/1/2 through the same table).
 * The deflicker parameters (12 bytes, word 0 = enable) and the flicker
 * timing (24 bytes: hz, fps, VTS, sensor+0x48) come from the active bank
 * (tparams+0x13348/+0x13354); tiziano_deflicker_expt_tune rebuilds the
 * deflicker LUT for hz; both blocks go back into tparams and the day and
 * night banks (+584/+596, so a day/night refresh keeps them), into the AE's
 * copies with the reload flags (tisp_api_ae_deflick_para_set /
 * tisp_api_ae_flick_t_set) and tisp_ae_trig reloads the AE hardware
 * parameters.  Off keeps the last frequency, as stock.
 */
static uint32_t t23_aelift_flicker_hz;

static int t23_aelift_s_antiflick_locked(uint32_t hz)
{
	uint32_t *flags = (uint32_t *)(void *)oem_IspAeFlag;
	uint32_t para[3];
	uint32_t ft[6];
	uint32_t stk[8] = { 0 };
	uint32_t fps;
	uint32_t vts;
	uint32_t u48;

	if (hz != 0 && hz != 50U && hz != 60U)
		return -EINVAL;
	if (hz)
		t23_aelift_flicker_hz = hz;
	if (!t23_aelift_ready)
		return 0;	/* t23_aelift_start replays it */
	memcpy(para, tparams + 0x13348, sizeof(para));
	memcpy(ft, tparams + 0x13354, sizeof(ft));
	para[0] = hz ? 1U : 0U;
	fps = *(uint32_t *)(void *)(oem_sensor_info + 0x30);
	vts = *(uint16_t *)(void *)(oem_sensor_info + 0x4a);
	u48 = *(uint16_t *)(void *)(oem_sensor_info + 0x48);
	/* stock outgoing argument area: 16(sp) LUT, 20(sp) node count */
	stk[4] = (uint32_t)(uintptr_t)oem__deflick_lut;
	stk[5] = (uint32_t)(uintptr_t)oem__nodes_num;
	LA_tiziano_deflicker_expt(t23_aelift_flicker_hz, fps, vts, u48,
				  (uint32_t)(uintptr_t)stk);
	ft[0] = t23_aelift_flicker_hz;
	ft[1] = fps;
	ft[2] = vts;
	ft[3] = u48;
	memcpy(tparams + 0x13348, para, sizeof(para));
	memcpy(oem__deflicker_para, para, sizeof(para));
	memcpy(tparams + 0x13354, ft, sizeof(ft));
	memcpy(oem__flicker_t, ft, sizeof(ft));
	if (tparams_day) {
		memcpy((void *)(tparams_day + 584), para, sizeof(para));
		memcpy((void *)(tparams_day + 596), ft, sizeof(ft));
	}
	if (tparams_night) {
		memcpy((void *)(tparams_night + 584), para, sizeof(para));
		memcpy((void *)(tparams_night + 596), ft, sizeof(ft));
	}
	/* tisp_ae_trig on the lifted copies */
	flags[4] = 1;
	flags[5] = 1;
	flags[6] = 1;
	flags[7] = 0;
	T23_AELIFT_CALL(LA_tiziano_ae_set_hardware_param, 0,
			(uint32_t)(uintptr_t)oem__ae_parameter, 1, 0);
	printk(KERN_INFO
	       "t23: stock AE0 antiflicker %u Hz (enable %u) fps=0x%x vts=%u\n",
	       t23_aelift_flicker_hz, para[0], fps, vts);
	return 0;
}

static int t23_aelift_s_antiflick(uint32_t hz)
{
	int ret;

	mutex_lock(&t23_aelift_mutex);
	t23_aelift_set_busy(true);
	ret = t23_aelift_s_antiflick_locked(hz);
	t23_aelift_set_busy(false);
	mutex_unlock(&t23_aelift_mutex);
	return ret;
}

/* Sensor stream on: the exposure the lifted AE set last (0 = none yet). */
static uint32_t t23_aelift_stream_packed(void)
{
	if (!t23_aelift_ready || !t23_aelift_it || !t23_aelift_again)
		return 0;
	return (t23_aelift_again << 16) | t23_aelift_it;
}

/* core interrupt: status bits 26 (AE0 statistics) and 27 (histogram) */
static bool t23_aelift_irq(uint32_t status)
{
	if (!regtrace_t23_source_ae_oem || !t23_aelift_ready)
		return false;
	spin_lock(&t23_aelift_irq_lock);
	if (!t23_aelift_busy) {
		if (status & BIT(26))
			T23_AELIFT_CALL(LA_ae0_interrupt_static, 0, 0, 0, 0);
		if (status & BIT(27))
			T23_AELIFT_CALL(LA_ae0_interrupt_hist, 0, 0, 0, 0);
	}
	spin_unlock(&t23_aelift_irq_lock);
	return true;
}

/*
 * Stock tisp_ae_mean_update (tiziano_awb_set_lum_th_freq, hard IRQ) on the
 * objects of the running stock AE: the AE0 zone means behind
 * IspAe0WmeanParam +0x1c (stock tiziano_ae_para_addr: IspAeStatic +0x32ac),
 * the zone grid _ae_parameter u16 +4 (rows) and u16 +12 (columns), _ae_reg
 * +8.  As stock, the sum starts from the last wmean_new (stock .data 0x400)
 * and a frame without zones keeps it.  False (no update, the caller keeps
 * its register) when the AE is not running, the zone pointer is not inside
 * IspAeStatic, or _ae_reg +8 is still 0 (stock would divide by it).
 */
static uint32_t t23_aelift_wmean_new = 0x400U;

static noinline bool t23_aelift_mean_update(uint32_t *mean, uint32_t *scale)
{
	const uint32_t *zones;
	uint32_t rows, cols, div, sum, r, c;
	uintptr_t z, base = (uintptr_t)oem_IspAeStatic;
	bool any = false;

	if (!regtrace_t23_source_ae_oem || !t23_aelift_ready)
		return false;
	spin_lock(&t23_aelift_irq_lock);
	if (t23_aelift_busy) {
		spin_unlock(&t23_aelift_irq_lock);
		return false;
	}
	rows = *(const uint16_t *)(oem__ae_parameter + 4);
	cols = *(const uint16_t *)(oem__ae_parameter + 12);
	div = *(const uint32_t *)(oem__ae_reg + 8);
	z = *(const uint32_t *)(oem_IspAe0WmeanParam + 0x1c);
	if (!div || !rows || !cols || rows > 15U || cols > 15U ||
	    z < base || z + rows * 60U > base + sizeof(oem_IspAeStatic)) {
		spin_unlock(&t23_aelift_irq_lock);
		return false;
	}
	sum = t23_aelift_wmean_new;
	for (r = 0; r < rows; r++) {
		zones = (const uint32_t *)(z + r * 60U);
		for (c = 0; c < cols; c++) {
			sum += zones[c];
			any = true;
		}
	}
	if (any)
		t23_aelift_wmean_new = sum;
	t23_aelift_wmean_new = ((t23_aelift_wmean_new / (rows * cols)) << 10) / div;
	*mean = t23_aelift_wmean_new;
	*scale = div;
	spin_unlock(&t23_aelift_irq_lock);
	return true;
}

static void t23_aelift_work_fn(struct work_struct *work)
{
	struct t23_aelift_event ev[T23_AELIFT_EVENTS];
	unsigned long flags;
	unsigned int n, i;

	mutex_lock(&t23_aelift_mutex);
	if (!t23_aelift_ready) {
		mutex_unlock(&t23_aelift_mutex);
		return;
	}
	T23_AELIFT_CALL(LA_tisp_ae0_process, 0, 0, 0, 0);
	mutex_unlock(&t23_aelift_mutex);
	if (t23_aelift_expo_dirty) {
		t23_aelift_expo_dirty = false;
		if (t23_aelift_debug)
			printk(KERN_WARNING
			       "t23: ae-oem exposure it=%u again=%u\n",
			       t23_aelift_it, t23_aelift_again);
		regtrace_t23_call_sensor_exposure(
			(t23_aelift_again << 16) | t23_aelift_it, "ae-oem");
	}
	spin_lock_irqsave(&t23_aelift_ev_lock, flags);
	n = t23_aelift_ev_count;
	memcpy(ev, t23_aelift_ev, n * sizeof(ev[0]));
	t23_aelift_ev_count = 0;
	spin_unlock_irqrestore(&t23_aelift_ev_lock, flags);
	for (i = 0; i < n; i++) {
		/*
		 * stock tisp_long_ev_update: arg0/arg1 = scene EV, Q10, low/high
		 * word; nothing happens unless it changed.  Then, in stock
		 * order: AWB takes it as is (tisp_awb_ev_update); the CCM is
		 * recomputed when its EV-dependent saturation moves (stock
		 * jz_isp_ccm on an EV step; the HLIL substitute does the same
		 * on a rung change); ADR and defog when not bypassed
		 * (regtrace_t23_ae_ev_adr_defog); BCSH gets
		 * tisp_bcsh_ev_update(ev, hi), gated like the HLIL
		 * substitute's call.
		 */
		if (ev[i].id == 6U) {
			bool changed = !t23_aelift_ev_seen ||
				       ev[i].args[0] != t23_aelift_ev_q10 ||
				       ev[i].args[1] != t23_aelift_ev_hi;

			t23_aelift_ev_q10 = ev[i].args[0];
			t23_aelift_ev_hi = ev[i].args[1];
			t23_aelift_ev_seen = true;
			if (changed && regtrace_t23_source_ccm_events &&
			    regtrace_t23_source_ccm_tuning_init &&
			    regtrace_t23_ccm_saturation(t23_aelift_ev_q10) !=
			    regtrace_t23_source_ccm_last_saturation)
				regtrace_t23_source_ccm_commit(
					regtrace_t23_source_ccm_runtime_ct,
					t23_aelift_ev_q10);
			if (changed)
				regtrace_t23_ae_ev_adr_defog(t23_aelift_ev_q10,
							     t23_aelift_ev_hi);
			if (changed && regtrace_t23_source_bcsh_events) {
				tisp_bcsh_ev_update(t23_aelift_ev_q10,
						    t23_aelift_ev_hi);
				regtrace_t23_source_bcsh_ev_events++;
			}
		}
		/* stock tisp_long_tgain_update: arg0 = log2 total gain, Q16 */
		if (ev[i].id == 4U) {
			t23_aelift_tgain = tisp_math_exp2(ev[i].args[0], 16, 16);
			if (t23_aelift_debug)
				printk(KERN_WARNING
				       "t23: ae-oem total gain 0x%x\n",
				       t23_aelift_tgain);
			regtrace_t23_source_apply_total_gain_value(
				t23_aelift_tgain, 0, false, false);
		}
	}
}

/*
 * Core stop / statistics DMA free (any context): no new runs; a run that is
 * already queued sees !ready and returns before touching any state.
 */
static void t23_aelift_halt(void)
{
	t23_aelift_ready = false;
}

/*
 * Process context, before the statistics ring or the module go: no new
 * run, wait for a running one, drop a queued one.
 */
static void t23_aelift_sync(void)
{
	t23_aelift_halt();
	cancel_work_sync(&t23_aelift_work);
}

/* module exit, after t23_aelift_sync */
static void t23_aelift_free(void)
{
	kfree(t23_aelift_buf);
	t23_aelift_buf = NULL;
	kfree(t23_aelift_saved);
	t23_aelift_saved = NULL;
	t23_aelift_inited = false;
}

/*
 * Stock tisp_g_ev_attr on the lifted copies (tisp_ae_ctrls, sensor_info),
 * same arithmetic through the lifted helpers.  The stock block (0x8c bytes,
 * word 1 and 0x40..0x77 left alone):
 *   w0 it (lines)  w2/w3 EV (64 bit Q10 >> 10)  w4/w5 exposure us
 *   w6 log2 EV Q16  w7 again  w8 ISP dgain (log2 Q5)  w9 tgain dB (u16)
 *   w10 total gain [24.8]  w11 max again  w12 max ISP dgain  w13 sensor
 *   dgain  w14 max sensor dgain  w15 AE manual  u16 0x78/0x7a it min/max
 *   u16 0x88 one line in us
 */
static noinline __used uint32_t t23_aelift_g_ev_attr(uint32_t *w)
{
	const uint32_t *c = (const uint32_t *)(void *)oem_tisp_ae_ctrls;
	uint32_t fps = *(uint32_t *)(void *)(oem_sensor_info + 0x30);
	uint32_t vts = *(uint16_t *)(void *)(oem_sensor_info + 0x4a);
	uint32_t stk[8] = { 0 };
	uint64_t num;

#define T23_AELIFT_LOG2(v, in, out) \
	((uint32_t)LA_tisp_log2_fixed_to_fixed((v), (in), (out), 0, \
					       (uint32_t)(uintptr_t)stk))
	w[0] = c[3];
	w[2] = (c[11] << 22) | (c[10] >> 10);
	w[3] = c[11] >> 10;
	w[6] = T23_AELIFT_LOG2(c[10], 10, 16);
	num = (uint64_t)(w[0] * 1000000U) * (fps & 0xffffU);
	stk[4] = (fps >> 16) * vts;
	stk[5] = 0;
	w[4] = (uint32_t)LA_fix_point_div_64(0, 0, (uint32_t)num,
					     (uint32_t)(num >> 32),
					     (uint32_t)(uintptr_t)stk);
	w[5] = 0;
	w[7] = T23_AELIFT_LOG2(c[1], 10, 5);
	w[8] = T23_AELIFT_LOG2(c[4], 10, 5);
	w[9] = *(const uint16_t *)(const void *)(oem_tisp_ae_ctrls + 0x32);
	w[10] = (uint32_t)LA_fix_point_mult2_32(10, c[1], c[4], 0,
						(uint32_t)(uintptr_t)stk) >> 2;
	w[11] = T23_AELIFT_LOG2(c[5] + 4U, 10, 5);
	w[12] = T23_AELIFT_LOG2(c[8] + 4U, 10, 5);
	w[13] = T23_AELIFT_LOG2(c[2], 10, 5);
	w[14] = T23_AELIFT_LOG2(c[6], 10, 5);
#undef T23_AELIFT_LOG2
	*(uint16_t *)(void *)((uint8_t *)w + 0x78) = (uint16_t)c[32];
	*(uint16_t *)(void *)((uint8_t *)w + 0x7a) = (uint16_t)c[7];
	/* stock divides unchecked (no trap on MIPS divu) */
	*(uint16_t *)(void *)((uint8_t *)w + 0x88) = (uint16_t)
		(((fps >> 16) && vts) ?
		 (fps & 0xffffU) * 1000000U / (fps >> 16) / vts : 0U);
	w[15] = c[15];
	return 0;
}

/*
 * Read-back for GetExpr / GetEVAttr / GetTotalGain / MAX_AGAIN / MAX_DGAIN
 * and /proc/jz/isp/isp-m0 while the lifted AE runs: its live state, as the
 * stock getters report it (apical_isp_expr_g_ctrl, apical_isp_ev_g_attr,
 * the 0x8000027 total gain, apical_isp_max_*_g_ctrl, isp_info_show all take
 * tisp_g_ev_attr).  The exposure word this driver sends to the sensor is no
 * rung of the HLIL ladder, so the substitute's read-back would report unity
 * gain.  false: the lifted AE is not in charge (or never initialised); the
 * caller keeps its own read-back.
 */
static bool t23_aelift_ev_info(struct regtrace_t23_ev_info *info)
{
	uint32_t w[36];

	if (!regtrace_t23_source_ae_oem || !t23_aelift_inited)
		return false;
	memset(w, 0, sizeof(w));
	mutex_lock(&t23_aelift_mutex);
	t23_aelift_g_ev_attr(w);
	mutex_unlock(&t23_aelift_mutex);
	info->valid = w[0] != 0;
	info->manual = w[15] ? 1U : 0U;
	info->it = w[0];
	info->ev = w[2];
	info->expr_us = w[4];
	info->ev_log2 = w[6];
	info->again = w[7];
	info->isp_dgain = w[8];
	info->tgain_log2 = w[9];
	info->total_gain = w[10];
	info->max_again = w[11];
	info->max_isp_dgain = w[12];
	info->sensor_dgain = w[13];
	info->max_sensor_dgain = w[14];
	info->it_min = *(uint16_t *)(void *)((uint8_t *)w + 0x78);
	info->it_max = *(uint16_t *)(void *)((uint8_t *)w + 0x7a);
	info->line_us = *(uint16_t *)(void *)((uint8_t *)w + 0x88);
	return true;
}

/*
 * MAX_AGAIN / MAX_DGAIN read-back while the lifted AE runs: stock
 * apical_isp_max_again_g_ctrl / _max_dgain_g_ctrl return tisp_g_ev_attr
 * word 11 / 12 (the live limit from tisp_ae_ctrls, log2 Q5).
 */
static bool t23_aelift_g_max(unsigned int word, uint32_t *value)
{
	uint32_t w[36];

	if (!regtrace_t23_source_ae_oem || !t23_aelift_inited)
		return false;
	memset(w, 0, sizeof(w));
	mutex_lock(&t23_aelift_mutex);
	t23_aelift_g_ev_attr(w);
	mutex_unlock(&t23_aelift_mutex);
	*value = w[word];
	return true;
}

/*
 * Emulator entry points (audit/aelift_emu.py drives these against the
 * stock functions of the same name); unused in the kernel.
 */
static noinline __used uint32_t t23_aelift_emu_init(uint32_t w, uint32_t h,
						     uint32_t fps)
{
	return (uint32_t)T23_AELIFT_CALL(LA_tiziano_ae_init, w, h, fps, 0);
}

static noinline __used uint32_t t23_aelift_emu_static(void)
{
	return (uint32_t)T23_AELIFT_CALL(LA_ae0_interrupt_static, 0, 0, 0, 0);
}

static noinline __used uint32_t t23_aelift_emu_hist(void)
{
	return (uint32_t)T23_AELIFT_CALL(LA_ae0_interrupt_hist, 0, 0, 0, 0);
}

static noinline __used uint32_t t23_aelift_emu_process(void)
{
	return (uint32_t)T23_AELIFT_CALL(LA_tisp_ae0_process, 0, 0, 0, 0);
}

static noinline __used uint32_t t23_aelift_emu_g_ev_attr(uint32_t a0, uint32_t a1)
{
	(void)a0;
	return t23_aelift_g_ev_attr((uint32_t *)(uintptr_t)a1);
}

static noinline __used uint32_t t23_aelift_emu_dn(uint32_t a0)
{
	return (uint32_t)T23_AELIFT_CALL(LA_tiziano_ae_dn_params_refresh, a0, 0, 0, 0);
}
