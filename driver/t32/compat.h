#ifndef T32_RECOVERY_COMPAT_H
#define T32_RECOVERY_COMPAT_H

#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/string.h>
#include <linux/fs.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>
#include <linux/poll.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/miscdevice.h>
#include <linux/slab.h>
#include <linux/dma-mapping.h>
#include <linux/interrupt.h>
#include <linux/completion.h>
#include <linux/spinlock.h>
#include <linux/workqueue.h>
#include <linux/hrtimer.h>
#include <linux/wait.h>
#include <linux/sched.h>
#include <linux/kthread.h>
#include <linux/capability.h>
#include <linux/gpio.h>
#include <linux/clk.h>
#include <linux/delay.h>
#include <linux/i2c.h>
#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <linux/firmware.h>
#include <linux/io.h>
#include <linux/mutex.h>
#include <linux/bug.h>
#include <linux/file.h>
#include <linux/time.h>
#include <linux/netlink.h>
#ifdef __has_include
#if __has_include(<linux/skbuff.h>)
#include <linux/skbuff.h>
#endif
#if __has_include(<linux/netdevice.h>)
#include <linux/netdevice.h>
#endif
#if __has_include(<net/checksum.h>)
#include <net/checksum.h>
#elif __has_include(<asm/checksum.h>)
#include <asm/checksum.h>
#endif
#if __has_include(<linux/gpio/consumer.h>)
#include <linux/gpio/consumer.h>
#endif
#if __has_include(<net/net_namespace.h>)
#include <net/net_namespace.h>
#endif
#endif
#include <asm/uaccess.h>

typedef s8 int8_t;
typedef u8 uint8_t;
typedef s16 int16_t;
typedef u16 uint16_t;
typedef s32 int32_t;
typedef u32 uint32_t;
typedef s64 int64_t;
typedef u64 uint64_t;
typedef void *void_ptr;
typedef const char *const_char_ptr;
typedef char *char_ptr;
typedef void void__iomem;
typedef void __iomem *void_iomem_ptr;
typedef void __iomem *void_ioimem_ptr;
typedef void *void_p;
typedef const char __user *const_char_user_ptr;

#ifndef __pgprot
#define __pgprot(x) ((pgprot_t)(x))
#endif
#ifndef pgprot_val
#define pgprot_val(x) ((unsigned long)(x))
#endif
#ifndef REGTRACE_IOREMAP_UNCACHED
#ifdef _CACHE_UNCACHED
#define REGTRACE_IOREMAP_UNCACHED _CACHE_UNCACHED
#else
#define REGTRACE_IOREMAP_UNCACHED 0
#endif
#endif
#ifndef REGTRACE_IOREMAP_CACHED
#ifdef _CACHE_CACHABLE_NONCOHERENT
#define REGTRACE_IOREMAP_CACHED _CACHE_CACHABLE_NONCOHERENT
#else
#define REGTRACE_IOREMAP_CACHED 0
#endif
#endif
#ifndef IOREMAP_NORMAL
#define IOREMAP_NORMAL REGTRACE_IOREMAP_UNCACHED
#endif
#ifndef IOREMAP_NOCACHE
#define IOREMAP_NOCACHE REGTRACE_IOREMAP_UNCACHED
#endif
#ifndef IOREMAP_CACHE
#define IOREMAP_CACHE REGTRACE_IOREMAP_CACHED
#endif
#ifndef IOREMAP_WC
#define IOREMAP_WC REGTRACE_IOREMAP_UNCACHED
#endif
#ifndef IOREMAP_WT
#define IOREMAP_WT REGTRACE_IOREMAP_UNCACHED
#endif

#ifndef SLAB_HWCACHE_ALIGN
#define SLAB_HWCACHE_ALIGN 0x00002000UL
#endif
#ifndef EPERM
#define EPERM 1
#endif
#ifndef ENOMEM
#define ENOMEM 12
#endif
#ifndef EIO
#define EIO 5
#endif
#ifndef EFAULT
#define EFAULT 14
#endif
#ifndef EINVAL
#define EINVAL 22
#endif
#ifndef ENOTTY
#define ENOTTY 25
#endif
#ifndef ENODEV
#define ENODEV 19
#endif
#ifndef ENXIO
#define ENXIO 6
#endif
#ifndef EBUSY
#define EBUSY 16
#endif
#ifndef EEXIST
#define EEXIST 17
#endif
#ifndef EAGAIN
#define EAGAIN 11
#endif
#ifndef ENOSYS
#define ENOSYS 38
#endif

#define get_gp() ((void *)current_thread_info())
static inline uint32_t __wsbh(uint32_t value) { return ((value & 0x00ff00ffU) << 8) | ((value & 0xff00ff00U) >> 8); }
#ifndef __ror
static inline uint32_t __ror(uint32_t value, unsigned int shift) { shift &= 31U; return (value >> shift) | (value << ((32U - shift) & 31U)); }
#endif
#ifndef ror_d
#define ror_d(value, shift) __ror((uint32_t)(value), (shift))
#endif

#endif
