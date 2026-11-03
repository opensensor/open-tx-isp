/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 colour denoise (CDNS, block 0x12000) from the IQ bin at AddSensor (S4
 * step 5): tisp_cdns_init -> tisp_cdns_intp_reg_refresh (39 point tables
 * interpolated at the gain index 1.0 = 0x10000, tisp_cdns_reg_cfg and the
 * 0x12010 trigger).  There is no block id write.
 *
 * IQ bin section 18 (436 bytes): tables of 11 bytes from +6, a flag at +0x1a6.
 */
#ifndef TX_ISP_T32_CDNS_H
#define TX_ISP_T32_CDNS_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_CDNS		18
#define T32_CDNS_SEC_BYTES	436U
#define T32_CDNS_WRITES		16

/* { table offset in the section, output byte } of tisp_cdns_intp */
static const u16 t32_cdns_map[39][2] = {
	{0x4, 0}, {0xf, 1}, {0x1a, 2}, {0x25, 3}, {0x30, 4}, {0x3b, 5}, {0x46, 6}, {0x51, 7}, 
	{0x5c, 8}, {0x67, 9}, {0x72, 10}, {0x7d, 11}, {0x88, 12}, {0x93, 13}, {0x9e, 14}, {0xa9, 
	15}, {0xb4, 16}, {0xbf, 17}, {0xca, 18}, {0xd5, 19}, {0xe0, 20}, {0xeb, 21}, {0xf6, 22}, 
	{0x101, 23}, {0x10c, 24}, {0x117, 25}, {0x122, 26}, {0x12d, 27}, {0x138, 28}, {0x143, 
	29}, {0x14e, 30}, {0x159, 31}, {0x164, 32}, {0x16f, 33}, {0x17a, 34}, {0x185, 35}, 
	{0x190, 36}, {0x19b, 37}, {0x1a7, 38}
};

static inline int t32_cdns_init(const u8 *sec, struct t32_front_write *w)
{
	u8 o[39];
	unsigned int n = 0, k;

	for (k = 0; k < 39; k++)
		o[t32_cdns_map[k][1]] = t32_tp_intp_u8(1, 0, sec + t32_cdns_map[k][0]);
	T32_FWR(w, n, 0x12040, o[0] & 7U);
	for (k = 0; k < 8; k++)
		T32_FWR(w, n, 0x12050 + 4 * k, (u32)o[0xf + 3 * k] << 8 | (u32)o[0x10 + 3 * k] << 16 | o[0xe + 3 * k]);
	T32_FWR(w, n, 0x12070, (u32)o[4] << 24 | o[1] | (u32)(o[2] & 0x3f) << 8 | (u32)(o[3] & 0x3f) << 16);
	T32_FWR(w, n, 0x12074, (u32)(o[6] & 0x3f) << 8 | (u32)(o[7] & 0x3f) << 16 | (o[5] & 7U));
	T32_FWR(w, n, 0x12078, o[8] & 3U);
	T32_FWR(w, n, 0x1207c, (u32)(o[10] & 0xf) << 16 | o[9]);
	T32_FWR(w, n, 0x12080, (u32)(o[0xc] & 0x3f) << 8 | (u32)(o[0xd] & 0x3f) << 16 | (o[0xb] & 7U));
	T32_FWR(w, n, 0x12084, (sec[0x1a6] & 1U) | (u32)o[0x26] << 4);
	T32_FWR(w, n, 0x12010, 1);
	return (int)n;
}

#endif /* TX_ISP_T32_CDNS_H */
