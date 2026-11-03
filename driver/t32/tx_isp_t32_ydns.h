/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 luma denoise (YDNS, block 0xe000) from the IQ bin at AddSensor (S4
 * step 5): tisp_ydns_init -> tisp_ydns_refresh (parameter refresh and
 * tisp_ydns_intp_reg_refresh, each interpolating the bin's 11 point tables
 * at the gain index 1.0 = 0x10000 and writing the block through
 * tisp_ydns_reg_cfg plus the 0xe010 trigger) and the block id.
 *
 * IQ bin section 17 (248 bytes): +4 / +5 enable bits, then 22 tables of 11
 * bytes from +6, 11 bytes apart (table k at +6 + 11 k).
 */
#ifndef TX_ISP_T32_YDNS_H
#define TX_ISP_T32_YDNS_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_YDNS		17
#define T32_YDNS_SEC_BYTES	248U
#define T32_YDNS_ID		0x0134da11U
#define T32_YDNS_WRITES		17

static inline int t32_ydns_init(const u8 *sec, struct t32_front_write *w)
{
	/* output byte of table k: the vendor's tisp_ydns_intp assignment */
	static const u8 dst[22] = { 12, 13, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 14, 15, 16, 17, 18, 19, 20, 21 };
	u8 o[22];
	unsigned int n = 0, k, pass;

	for (k = 0; k < 22; k++)
		o[dst[k]] = t32_tp_intp_u8(1, 0, sec + 6 + 11 * k);
	for (pass = 0; pass < 2; pass++) {
		T32_FWR(w, n, 0xe050, (u32)(sec[5] & 1) << 4 | (sec[4] & 1U));
		T32_FWR(w, n, 0xe060, (u32)(o[1] & 3) << 8 | (u32)(o[2] & 3) << 12 | o[0]);
		T32_FWR(w, n, 0xe064, t32_front_le32(o + 3));
		T32_FWR(w, n, 0xe068, t32_front_le32(o + 7));
		T32_FWR(w, n, 0xe070, (u32)o[0xc] << 8 | (u32)o[0xd] << 16 | o[0xb]);
		T32_FWR(w, n, 0xe074, t32_front_le32(o + 0xe));
		T32_FWR(w, n, 0xe078, t32_front_le32(o + 0x12));
		T32_FWR(w, n, 0xe010, 1);
	}
	T32_FWR(w, n, 0xe000, T32_YDNS_ID);
	return (int)n;
}

#endif /* TX_ISP_T32_YDNS_H */
