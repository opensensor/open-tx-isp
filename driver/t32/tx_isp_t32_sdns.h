/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 chroma denoise (SDNS, block 0x13000) from the IQ bin at AddSensor (S4
 * step 5): tisp_sdns_init -> tisp_sdns_intp_reg_refresh (55 point tables
 * interpolated at the gain index 1.0 = 0x10000, tisp_sdns_write_all_reg, the
 * 0x13010 trigger) and the block id.
 *
 * IQ bin section 22 (628 bytes): +4 / +5 enable fields, tables of 11 bytes
 * from +6 (a few are 12 or 20 bytes apart), single bytes at +0xcc, +0xe3,
 * +0x147, +0x153, +0x16a.. +0x172, +0x189.
 */
#ifndef TX_ISP_T32_SDNS_H
#define TX_ISP_T32_SDNS_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_SDNS		22
#define T32_SDNS_SEC_BYTES	628U
#define T32_SDNS_ID		0x0134da11U
#define T32_SDNS_WRITES		27

/* { table offset in the section, output byte } of tisp_sdns_intp */
static const u16 t32_sdns_map[55][2] = {
	{0x6, 0}, {0x11, 1}, {0x1c, 2}, {0x27, 3}, {0x32, 4}, {0x3d, 5}, {0x48, 6}, {0x53, 7}, 
	{0x5e, 8}, {0x69, 9}, {0x74, 10}, {0x7f, 11}, {0x8a, 12}, {0x95, 13}, {0xa0, 14}, {0xab, 
	15}, {0xb6, 16}, {0xc1, 17}, {0xcd, 18}, {0xd8, 19}, {0xe4, 20}, {0xef, 21}, {0xfa, 22}, 
	{0x105, 23}, {0x110, 24}, {0x11b, 25}, {0x126, 26}, {0x131, 27}, {0x13c, 28}, {0x148, 
	29}, {0x154, 30}, {0x15f, 31}, {0x173, 32}, {0x17e, 33}, {0x18a, 34}, {0x195, 35}, 
	{0x1a0, 36}, {0x1ab, 37}, {0x1b6, 38}, {0x1c1, 39}, {0x1cc, 40}, {0x1d7, 41}, {0x1e2, 
	42}, {0x1ed, 43}, {0x1f8, 44}, {0x203, 45}, {0x20e, 46}, {0x219, 47}, {0x224, 48}, 
	{0x22f, 49}, {0x23a, 50}, {0x245, 51}, {0x250, 52}, {0x25b, 53}, {0x266, 54}
};

/* tisp_sdns_param_scale */
static inline u32 t32_sdns_scale(u32 v)
{
	if (v > 0x40) {
		if (v < 0x81)
			return (v - 0x30) * 4;
		if (v < 0xc1)
			return (v - 0x6c) * 0x10;
		if (v < 0x100) {
			v = (v - 0x96) * 0x20;
			return v > 0xbf4 ? 0xbf4 : (v & 0xffff);
		}
	}
	return v;
}

static inline int t32_sdns_init(const u8 *sec, struct t32_front_write *w)
{
	u8 o[55];
	unsigned int n = 0, k;
	u32 s[10];

	for (k = 0; k < 55; k++)
		o[t32_sdns_map[k][1]] = t32_tp_intp_u8(1, 0, sec + t32_sdns_map[k][0]);
	for (k = 0; k < 10; k++)
		s[k] = t32_sdns_scale(o[k]) & 0xfff;
	T32_FWR(w, n, 0x13020, sec[4] & 7U);
	T32_FWR(w, n, 0x13024, sec[5] & 7U);
	T32_FWR(w, n, 0x13028, s[1] << 16 | s[0]);
	T32_FWR(w, n, 0x1302c, s[3] << 16 | s[2]);
	T32_FWR(w, n, 0x13030, s[5] << 16 | s[4]);
	T32_FWR(w, n, 0x13034, s[7] << 16 | s[6]);
	T32_FWR(w, n, 0x13038, s[9] << 16 | s[8]);
	T32_FWR(w, n, 0x1303c, t32_front_le32(o + 10));
	T32_FWR(w, n, 0x13040, t32_front_le32(o + 0xe));
	T32_FWR(w, n, 0x13044, sec[0xcc] & 0x3fU);
	T32_FWR(w, n, 0x13048, t32_tp_le16(o + 0x12));
	T32_FWR(w, n, 0x1304c, (u32)(o[0x14] & 0x1f) << 8 | (sec[0xe3] & 0x3fU));
	T32_FWR(w, n, 0x13050, (u32)(o[0x16] & 0x7f) << 8 | (u32)(o[0x17] & 0x7f) << 16 |
		(o[0x15] & 0x7fU) | (u32)(o[0x18] & 0x7f) << 24);
	T32_FWR(w, n, 0x13054, (u32)(o[0x1a] & 0x7f) << 8 | (u32)(o[0x1b] & 0x7f) << 16 |
		(o[0x19] & 0x7fU) | (u32)(o[0x1c] & 0x7f) << 24);
	T32_FWR(w, n, 0x13058, (sec[0x147] & 0x3fU) | (u32)o[0x1d] << 8 | (u32)(sec[0x153] & 0x3f) << 16);
	T32_FWR(w, n, 0x1305c, (u32)(o[0x1f] & 0x7f) << 8 | (u32)(sec[0x16a] & 3) << 16 | (o[0x1e] & 0x7fU));
	T32_FWR(w, n, 0x13060, (u32)(sec[0x16c] & 7) << 8 | (u32)(sec[0x16d] & 7) << 12 | (sec[0x16b] & 0x1fU));
	T32_FWR(w, n, 0x13064, (u32)(sec[0x16f] & 7) << 4 | (u32)(sec[0x170] & 7) << 8 | (sec[0x16e] & 7U) |
		(u32)(sec[0x171] & 7) << 12 | (u32)(sec[0x172] & 0xf) << 16);
	T32_FWR(w, n, 0x13068, (u32)(o[0x21] & 0x1f) << 8 | (u32)(sec[0x189] & 3) << 16 | (o[0x20] & 0x1fU));
	T32_FWR(w, n, 0x1306c, (u32)(o[0x23] & 0x1f) << 8 | (u32)(o[0x24] & 0x1f) << 16 |
		(o[0x22] & 0x1fU) | (u32)(o[0x25] & 0x1f) << 24);
	T32_FWR(w, n, 0x13070, (u32)(o[0x27] & 0x1f) << 8 | (u32)(o[0x28] & 0x1f) << 16 |
		(o[0x26] & 0x1fU) | (u32)(o[0x29] & 0x1f) << 24);
	T32_FWR(w, n, 0x13074, (u32)o[0x2a] << 1);
	T32_FWR(w, n, 0x13078, t32_front_le32(o + 0x2b));
	T32_FWR(w, n, 0x1307c, t32_front_le32(o + 0x2f));
	T32_FWR(w, n, 0x13080, t32_front_le32(o + 0x33));
	T32_FWR(w, n, 0x13010, 1);
	T32_FWR(w, n, 0x13000, T32_SDNS_ID);
	return (int)n;
}

#endif /* TX_ISP_T32_SDNS_H */
