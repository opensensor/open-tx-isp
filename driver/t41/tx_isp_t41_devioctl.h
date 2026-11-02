/* SPDX-License-Identifier: GPL-2.0 */
/*
 * ISP-device ioctls of the T41 stock dispatcher that only store a word
 * or have no handler (pure logic, host-testable).  Oracle: the stock
 * tx_isp_unlocked_ioctl of tx-isp-t41.ko 1.2.5.
 *
 * StartNightMode 0xc004542e: stock copies a 4-byte vinum and stores 10 at
 * core + 0x1d4 + 4 * vinum, unchecked.  core + 0x1d4 is the VIC frame
 * counter that the next isp_core_tunning_open consumes: when it reads 10 it
 * sets tuning + 0x18 = 1 ("night start") and clears the word.  Here vinum
 * is limited to the three counter words (0..2), else -EINVAL.
 *
 * WDR_OPEN 0xc004548d: stock copies 8 bytes {vinum, mode} and stores the
 * mode byte at core + 0x364 (the WDR buffer mode: 1 = line, 2 = frame; read
 * by the WDR enable/disable and WDR_GET_BUF paths).  mode 0 is answered
 * -EFAULT after a "copy from user error" log, as stock does.
 *
 * LDC 0xc0045479..7b and GPIO 0xc004548e/f: stock has no handler and
 * answers 0 without any effect.  Vendor no-op, no function.
 */
#ifndef TX_ISP_T41_DEVIOCTL_H
#define TX_ISP_T41_DEVIOCTL_H

#ifdef __KERNEL__
#include <linux/errno.h>
#include <linux/types.h>
#else
#include <errno.h>
#include <stdint.h>
#endif

#define T41_NIGHT_START_MAGIC	10U
#define T41_NIGHT_WORDS		3U

/* Index of the counter word to set to 10, or -EINVAL. */
static inline int t41_night_start_word(uint32_t vinum)
{
	return vinum < T41_NIGHT_WORDS ? (int)vinum : -EINVAL;
}

/* Returns 0 and the byte to store, or -EFAULT (stock answer for mode 0). */
static inline int t41_wdr_open_mode(uint32_t mode, uint8_t *store)
{
	if (!mode)
		return -EFAULT;
	*store = (uint8_t)mode;
	return 0;
}

/* Commands the stock module answers 0 for without doing anything. */
static inline int t41_devioctl_is_vendor_noop(uint32_t cmd)
{
	return (cmd >= 0xc0045479U && cmd <= 0xc004547bU) ||
	       cmd == 0xc004548eU || cmd == 0xc004548fU;
}

#endif
