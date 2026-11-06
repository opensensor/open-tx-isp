#ifndef _TX_ISP_DEBUG_H_
#define _TX_ISP_DEBUG_H_

#include <linux/hrtimer.h>
#include <linux/dma-mapping.h>
#include <linux/printk.h>
#include <txx_funcs.h>

/*
 * t31_runtime_trace is defined in tx_isp_tuning.c as a writable module
 * parameter (default 0). The recovered T31 driver logs a bring-up firehose at
 * info level - over a thousand pr_info calls across init, per-frame AE/AWB/ADR
 * and DMA paths. Route them through the trace flag so a production boot is
 * quiet; "tx-isp-t31 t31_runtime_trace=1" (or the sysfs param) restores the
 * trace. Warnings and errors are untouched.
 */
extern int t31_runtime_trace;

#undef pr_info
#undef pr_info_ratelimited

/*
 * The 3.10 no_printk() is an inline function: a dropped pr_info()/pr_debug()
 * still evaluates its arguments, i.e. every readl()/system_reg_read() in a
 * trace line is still executed (MMIO in the per-frame paths).  This form
 * keeps the format check but evaluates nothing.
 */
#define TX_ISP_NO_PRINTK(fmt, ...) \
	({ if (0) printk(fmt, ##__VA_ARGS__); 0; })

#if !defined(DEBUG) && !defined(CONFIG_DYNAMIC_DEBUG)
#undef pr_debug
#define pr_debug(fmt, ...) TX_ISP_NO_PRINTK(KERN_DEBUG pr_fmt(fmt), ##__VA_ARGS__)
#endif

#if defined(TX_ISP_T31_NO_TRACE)
/* Production build (Kbuild TX_ISP_T31_TRACE=n): drop the trace and its
 * strings (~100 KB of module memory); t31_runtime_trace has no effect. */
#define pr_info(fmt, ...) TX_ISP_NO_PRINTK(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__)
#define pr_info_ratelimited(fmt, ...) TX_ISP_NO_PRINTK(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__)
#else
#define pr_info(fmt, ...) \
	do { if (t31_runtime_trace) printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__); } while (0)
#define pr_info_ratelimited(fmt, ...) \
	do { if (t31_runtime_trace) printk(KERN_INFO pr_fmt(fmt), ##__VA_ARGS__); } while (0)
#endif

/* =================== switchs ================== */

/**
 * default debug level, if just switch ISP_WARNING
 * or ISP_INFO, this not effect DEBUG_REWRITE and
 * DEBUG_TIME_WRITE/READ
 **/
/* =================== print tools ================== */

#define ISP_INFO_LEVEL		0x0
#define ISP_WARN_LEVEL	0x1
#define ISP_ERROR_LEVEL		0x2
#define ISP_PRINT(level, format, ...)			\
	isp_printf(level, format, ##__VA_ARGS__)
#define ISP_INFO(...) ISP_PRINT(ISP_INFO_LEVEL, __VA_ARGS__)
#define ISP_WARNING(...) ISP_PRINT(ISP_WARN_LEVEL, __VA_ARGS__)
#define ISP_ERROR(...) ISP_PRINT(ISP_ERROR_LEVEL, __VA_ARGS__)

/*
 * Per-event/per-frame diagnostics. Not part of a release log: with
 * TX_ISP_T31_NO_TRACE the strings are compiled out, and in a trace build
 * they still need t31_runtime_trace=1 and print_level=0.
 */
#if defined(TX_ISP_T31_NO_TRACE)
#define ISP_DEBUG(fmt, ...) no_printk(KERN_DEBUG "tx-isp: DEBUG: " fmt, ##__VA_ARGS__)
#else
#define ISP_DEBUG(fmt, ...) \
	do { if (t31_runtime_trace) ISP_PRINT(ISP_INFO_LEVEL, "DEBUG: " fmt, ##__VA_ARGS__); } while (0)
#endif

//extern unsigned int isp_print_level;
/*int isp_debug_init(void);*/
/*int isp_debug_deinit(void);*/
int isp_printf(unsigned int level, unsigned char *fmt, ...);
int get_isp_clk(void);
void *private_vmalloc(unsigned long size);
void private_vfree(const void *addr);

ktime_t private_ktime_set(const long secs, const unsigned long nsecs);
void private_set_current_state(unsigned int state);
int private_schedule_hrtimeout(ktime_t *ex, const enum hrtimer_mode mode);
bool private_schedule_work(struct work_struct *work);
void private_do_gettimeofday(struct timeval *tv);
void private_dma_sync_single_for_device(struct device *dev,
							      dma_addr_t addr, size_t size, enum dma_data_direction dir);
__must_check int private_get_driver_interface(struct jz_driver_common_interfaces **pfaces);
#endif /* _ISP_DEBUG_H_ */
