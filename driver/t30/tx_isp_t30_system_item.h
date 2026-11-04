/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T30 APICAL "system" API items (apical_command type 1, ids 8..0x3e).
 *
 * Every vendor system_* function (tx-isp-t30 H20190523a, system_freeze_firmware
 * .. system_calibrate_bad_pixels) is the same accessor over one item of the
 * 60-byte system table `stab` (tx_isp_t30_stab.h):
 *
 *	*data = 0;
 *	flag 1: *data = item        (get)
 *	flag 0: item  = value       (set)
 *	other:  return 2
 *
 * The lifted copies had lost the set arm of 21 of them (manual exposure,
 * manual integration time/gains/sharpening/AWB/saturation, dark/bright
 * target, max exposure ratio and integration time, directional sharpening,
 * iridix, sinter and temper limits, anti-flicker, bad pixels) or answered
 * the get with the wrong value, so every manual AE/AWB control written
 * through apical_command was dropped.  Host test:
 * tests/t30_system_item_host_test.c, guard: tests/check_t30_system_items.sh.
 */
#ifndef TX_ISP_T30_SYSTEM_ITEM_H
#define TX_ISP_T30_SYSTEM_ITEM_H

/* item: address of the item inside the table, size 1, 2 or 4 bytes (little endian) */
static inline int t30_system_item(u8 *item, unsigned int size, u32 value,
				  u8 flag, int *data)
{
	*data = 0;
	if (flag == 1) {
		u32 v = 0;

		memcpy(&v, item, size);
		*data = (int)v;
		return 0;
	}
	if (flag != 0)
		return 2;
	memcpy(item, &value, size);
	return 0;
}

#endif /* TX_ISP_T30_SYSTEM_ITEM_H */
