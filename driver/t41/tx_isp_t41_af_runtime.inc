/*
 * T41 AF statistics block (issue #179), included by tx_isp_t41_recovered.c.
 *
 * OEM 1.2.5 flow: tisp_af_init programs the block (tisp_af_set_hardware_param,
 * 0x1a000 = 1), the AF-done interrupt (status 0x40028 bit 6) unpacks the
 * finished 4 KB ring buffer (index 0x1a0e0) into the workspace and posts
 * event 15, whose handler runs tisp_af_alogrithm; GetAfStatistics (0x08000031)
 * and GetAFMetricesInfo (0x08000034) copy from there.  The arithmetic lives
 * in tx_isp_t41_af.h (host test tests/tx_isp_t41_af_test.c).
 *
 * Gate: t41_af=0 (default) keeps the previous behaviour exactly: block off
 * (0x1a000 = 0), interrupt bit 6 masked, both queries answer -EPERM.
 * t41_af=1 (load time) arms it at the next tisp_init.  Differences from the
 * OEM, for robustness only: geometry is checked before the block is armed,
 * the ring index is masked to 0..3, the buffer is cleared and written back
 * right after the read (the OEM clears it in the cache only), the per-frame
 * metric runs on the ordered tuning workqueue instead of the firmware
 * thread, and every access to the workspace holds t41_af_lock.
 */
#include "tx_isp_t41_af.h"

static int t41_af __attribute__((section(".data")));
module_param(t41_af, int, 0444);
MODULE_PARM_DESC(t41_af, "1 = arm the AF statistics block at ISP init (OEM tisp_af path: 0x1a000, IRQ bit 6, 4 x 4 KB DMA ring) and serve GetAfStatistics/GetAFMetricesInfo; 0 = AF off, both answer EPERM (default)");

static int t41_af_live __attribute__((section(".data")));
static unsigned int t41_af_irqs __attribute__((section(".data")));
static unsigned int t41_af_runs __attribute__((section(".data")));
static unsigned int t41_af_bad_index __attribute__((section(".data")));
module_param_named(af_live, t41_af_live, int, 0444);
module_param_named(af_irqs, t41_af_irqs, uint, 0444);
module_param_named(af_runs, t41_af_runs, uint, 0444);
module_param_named(af_bad_index, t41_af_bad_index, uint, 0444);

static DEFINE_SPINLOCK(t41_af_lock);
static uint8_t *t41_af_params;		/* tparamsP + 0x17be8 */
static uint8_t *t41_af_ws;		/* af_info[0]->workspace */
static uint8_t *t41_af_ring;		/* af_buf_info[0]->buffer, 4 x 4 KB */
/* OEM af_par_attr defaults (.data, 24 bytes per channel); [9] = metric shift. */
static uint8_t t41_af_par_attr[24] __attribute__((section(".data"))) = {
	0, 0, 0, 0, 0, 0, 0, 0, 0x01, 0x00, 0x2a, 0x00, 0x16, 0x00, 0xc8, 0x00,
	0x13, 0x00, 0x01, 0x03, 0x0f, 0x0f, 0x3a, 0x00,
};

static void t41_af_irq_mask_sync(void);	/* after t41_isr_enable_word() */

static void t41_af_workfn(struct work_struct *work)
{
	unsigned long flags;

	(void)work;
	spin_lock_irqsave(&t41_af_lock, flags);
	if (t41_af_live) {
		t41_af_algorithm(t41_af_params, t41_af_ws);
		t41_af_runs++;
	}
	spin_unlock_irqrestore(&t41_af_lock, flags);
}
static DECLARE_WORK(t41_af_work, t41_af_workfn);

/* Hard IRQ, status 0x40028 bit 6 (OEM tisp_af_interrupt_static). */
static void t41_af_irq(void)
{
	uint32_t index;
	uint8_t *buf;

	spin_lock(&t41_af_lock);
	if (!t41_af_live) {
		spin_unlock(&t41_af_lock);
		return;
	}
	index = (uint32_t)system_reg_read(0x1a0e0);
	if (index >= T41_AF_BUFS) {
		t41_af_bad_index++;
		index &= T41_AF_BUFS - 1U;
	}
	buf = t41_af_ring + index * T41_AF_BUF_BYTES;
	dma_cache_sync(NULL, buf, T41_AF_BUF_BYTES, DMA_FROM_DEVICE);
	t41_af_unpack(t41_af_params, t41_af_ws, (const uint32_t *)(void *)buf);
	*(uint32_t *)(void *)(t41_af_ws + T41_AF_WS_TAG) =
		(uint32_t)system_reg_read(0x1a120) & 0xffffU;
	memset(buf, 0, T41_AF_BUF_BYTES);
	dma_cache_sync(NULL, buf, T41_AF_BUF_BYTES, DMA_TO_DEVICE);
	t41_af_irqs++;
	spin_unlock(&t41_af_lock);
	queue_work(t41_tuning_wq(), &t41_af_work);
}

/*
 * Arm the block (tisp_af_init, channel 0, buffers already allocated).
 * Returns 0 when armed; otherwise the caller keeps the block off.
 */
static int t41_af_start(uint32_t channel, uint8_t *info)
{
	uint32_t regs[T41_AF_MAX_REGS][2];
	uint32_t *cfg;
	uint8_t *params, *ws, *ring;
	uint32_t width, height;
	unsigned int i, n;
	unsigned long flags;

	if (READ_ONCE(t41_af) <= 0 || channel != 0 || !t41_kernel_data_ptr(info))
		return -ENODEV;
	cfg = (uint32_t *)(uintptr_t)af_buf_info[0];
	params = (uint8_t *)(uintptr_t)*(uint32_t *)(void *)info;
	ws = (uint8_t *)(uintptr_t)*(uint32_t *)(void *)(info + 4);
	if (!t41_kernel_data_ptr(cfg) || !t41_kernel_data_ptr(params) ||
	    !t41_kernel_data_ptr(ws))
		return -ENODEV;
	ring = (uint8_t *)(uintptr_t)cfg[1];
	if (!t41_kernel_data_ptr(ring))
		return -ENODEV;
	width = *(uint16_t *)(void *)(info + 12);
	height = *(uint16_t *)(void *)(info + 14);
	if (!t41_af_geometry_ok(params, width, height)) {
		printk(KERN_WARNING
		       "t41: af-init geometry refused (%ux%u zones %ux%u start %u,%u), AF stays off\n",
		       width, height, t41_af_rd16(params, T41_AF_P_NX),
		       t41_af_rd16(params, T41_AF_P_NY),
		       t41_af_rd16(params, T41_AF_P_XSTART),
		       t41_af_rd16(params, T41_AF_P_YSTART));
		return -EINVAL;
	}
	memset(ring, 0, T41_AF_BUFS * T41_AF_BUF_BYTES);
	dma_cache_sync(NULL, ring, T41_AF_BUFS * T41_AF_BUF_BYTES, DMA_TO_DEVICE);

	spin_lock_irqsave(&t41_af_lock, flags);
	n = t41_af_hw_param(params, ws, width, height, regs);
	for (i = 0; i < n; i++)
		system_reg_write(regs[i][0], regs[i][1]);
	system_reg_write(0x308, 0x20220722);	/* OEM tisp_af_init */
	t41_af_params = params;
	t41_af_ws = ws;
	t41_af_ring = ring;
	WRITE_ONCE(t41_af_live, 1);
	spin_unlock_irqrestore(&t41_af_lock, flags);
	t41_af_irq_mask_sync();
	printk(KERN_WARNING
	       "t41: af-init armed %ux%u zones %ux%u start %u,%u regs %u\n",
	       width, height, t41_af_rd16(params, T41_AF_P_NX),
	       t41_af_rd16(params, T41_AF_P_NY),
	       t41_af_rd16(params, T41_AF_P_XSTART),
	       t41_af_rd16(params, T41_AF_P_YSTART), n);
	return 0;
}

/* Disarm before the buffers are freed (tisp_deinit / tisp_af_deinit). */
static void t41_af_stop(void)
{
	unsigned long flags;
	int was;

	spin_lock_irqsave(&t41_af_lock, flags);
	was = t41_af_live;
	WRITE_ONCE(t41_af_live, 0);
	t41_af_params = NULL;
	t41_af_ws = NULL;
	t41_af_ring = NULL;
	spin_unlock_irqrestore(&t41_af_lock, flags);
	if (!was)
		return;
	t41_af_irq_mask_sync();
	system_reg_write(0x1a000, 0);
	cancel_work_sync(&t41_af_work);
	printk(KERN_WARNING "t41: af disarmed irqs=%u runs=%u bad-index=%u\n",
	       t41_af_irqs, t41_af_runs, t41_af_bad_index);
}

/* GetAfStatistics (0x08000031): 6 x u32[15][15] (OEM tisp_af_api_get_statis_info). */
static int t41_tuning_af_statis(unsigned int channel, uintptr_t user_ptr)
{
	unsigned long flags;
	uint8_t *copy;
	int ret = 0;

	if (channel != 0 || !user_ptr)
		return -EINVAL;
	copy = kmalloc(T41_AF_STATIS_BYTES, GFP_KERNEL);
	if (!copy)
		return -ENOMEM;
	spin_lock_irqsave(&t41_af_lock, flags);
	if (t41_af_live)
		memcpy(copy, t41_af_ws, T41_AF_STATIS_BYTES);
	else
		ret = -EPERM;
	spin_unlock_irqrestore(&t41_af_lock, flags);
	if (!ret && private_copy_to_user((void __user *)user_ptr, copy,
					 T41_AF_STATIS_BYTES))
		ret = -EFAULT;
	kfree(copy);
	return ret;
}

/* GetAFMetricesInfo (0x08000034): { u32 metric, u32 metric_alt, u8 tag } (12 bytes). */
static int t41_tuning_af_metric(unsigned int channel, uintptr_t user_ptr)
{
	struct {
		uint32_t metric;
		uint32_t metric_alt;
		uint8_t tag;
		uint8_t pad[3];
	} out;
	uint32_t m[3];
	unsigned long flags;

	BUILD_BUG_ON(sizeof(out) != 12);
	if (channel != 0 || !user_ptr)
		return -EINVAL;
	spin_lock_irqsave(&t41_af_lock, flags);
	if (!t41_af_live) {
		spin_unlock_irqrestore(&t41_af_lock, flags);
		return -EPERM;
	}
	t41_af_metric(t41_af_params, t41_af_ws, t41_af_par_attr[9], m);
	spin_unlock_irqrestore(&t41_af_lock, flags);
	memset(&out, 0, sizeof(out));
	out.metric = m[0];
	out.metric_alt = m[1];
	out.tag = (uint8_t)m[2];
	return private_copy_to_user((void __user *)user_ptr, &out,
				    sizeof(out)) ? -EFAULT : 0;
}
