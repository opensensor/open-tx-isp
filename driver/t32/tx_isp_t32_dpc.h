/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T32 defective pixel correction (DPC, blocks 0x2000 and 0x29000) from the IQ
 * bin at AddSensor (S4 step 6): tisp_dpc_init -> tisp_dpc_gain_interp (the
 * long exposure values, then the short exposure values) and
 * tisp_dpc_write_reg (tisp_dpc_write_reg_long, _short, _other), then the
 * block id.
 *
 * IQ bin section 5 (2304 bytes).  The interpolation reads point tables (u8 or
 * u16, 11 entries) of the section at the first gain index (the vendor's
 * state is all zero at init) into a 0xb4 byte value block; the register
 * functions combine section bytes and values.  A mechanical transcription of
 * the vendor's flow; the tables come from the bin.  "wide" selects the extra
 * 0x29144.. words of the short exposure (the vendor tests the ISP top
 * format register, bit field above 4).
 */
#ifndef TX_ISP_T32_DPC_H
#define TX_ISP_T32_DPC_H

#include "tx_isp_t32_tp.h"

#define T32_SEC_DPC		5
#define T32_DPC_SEC_BYTES	2304U
#define T32_DPC_VALUES		0xb4U
#define T32_DPC_ID		0x0134da11U
#define T32_DPC_MAX_WRITES	160

/* { kind (8: u8, 16: u16), table offset in the section, byte offset in the value block } */
static const u16 t32_dpc_map[106][3] = {
	{16, 0x6, 0x0}, {16, 0x1c, 0x2}, {8, 0x38a, 0x4}, {16, 0x32, 0x6}, {16, 0x48, 0x8}, {16, 0x5e, 0xa},
	{16, 0x74, 0xc}, {16, 0x8a, 0xe}, {16, 0xa0, 0x10}, {16, 0xb6, 0x12}, {16, 0xcc, 0x14}, {16, 0xe2, 0x16},
	{16, 0xf8, 0x18}, {16, 0x10e, 0x1a}, {16, 0x124, 0x1c}, {16, 0x13a, 0x1e}, {16, 0x150, 0x20}, {16, 0x166, 0x22},
	{16, 0x17c, 0x24}, {16, 0x192, 0x26}, {16, 0x1a8, 0x28}, {8, 0x3bc, 0x2a}, {8, 0x3c7, 0x2b}, {16, 0x1be, 0x2c},
	{16, 0x1d4, 0x2e}, {16, 0x1ea, 0x30}, {16, 0x200, 0x32}, {16, 0x216, 0x34}, {16, 0x22c, 0x36}, {8, 0x3d2, 0x71},
	{8, 0x3dd, 0x72}, {8, 0x3e8, 0x73}, {8, 0x3f3, 0x74}, {16, 0x24a, 0x76}, {16, 0x260, 0x78}, {16, 0x276, 0x7a},
	{16, 0x28c, 0x7c}, {16, 0x2a2, 0x7e}, {16, 0x2b8, 0x80}, {16, 0x2ce, 0x82}, {16, 0x2e4, 0x84}, {8, 0x3fe, 0x86},
	{8, 0x409, 0x87}, {8, 0x414, 0x88}, {8, 0x41f, 0x89}, {8, 0x42a, 0x8a}, {8, 0x435, 0x8b}, {8, 0x440, 0x8c},
	{8, 0x44b, 0x8d}, {8, 0x456, 0x8e}, {8, 0x461, 0x8f}, {8, 0x46c, 0x90}, {8, 0x477, 0x91}, {16, 0x484, 0x38},
	{16, 0x49a, 0x3a}, {8, 0x808, 0x3c}, {16, 0x4b0, 0x3e}, {16, 0x4c6, 0x40}, {16, 0x4dc, 0x42}, {16, 0x4f2, 0x44},
	{16, 0x508, 0x46}, {16, 0x51e, 0x48}, {16, 0x534, 0x4a}, {16, 0x54a, 0x4c}, {16, 0x560, 0x4e}, {16, 0x576, 0x50},
	{16, 0x58c, 0x52}, {16, 0x5a2, 0x54}, {16, 0x5b8, 0x56}, {16, 0x5ce, 0x58}, {16, 0x5e4, 0x5a}, {16, 0x5fa, 0x5c},
	{16, 0x610, 0x5e}, {16, 0x626, 0x60}, {8, 0x83a, 0x62}, {8, 0x845, 0x63}, {16, 0x63c, 0x64}, {16, 0x652, 0x66},
	{16, 0x668, 0x68}, {16, 0x67e, 0x6a}, {16, 0x694, 0x6c}, {16, 0x6aa, 0x6e}, {8, 0x850, 0x93}, {8, 0x85b, 0x94},
	{8, 0x866, 0x95}, {8, 0x871, 0x96}, {16, 0x6c8, 0x98}, {16, 0x6de, 0x9a}, {16, 0x6f4, 0x9c}, {16, 0x70a, 0x9e},
	{16, 0x720, 0xa0}, {16, 0x736, 0xa2}, {16, 0x74c, 0xa4}, {16, 0x762, 0xa6}, {8, 0x87c, 0xa8}, {8, 0x887, 0xa9},
	{8, 0x892, 0xaa}, {8, 0x89d, 0xab}, {8, 0x8a8, 0xac}, {8, 0x8b3, 0xad}, {8, 0x8be, 0xae}, {8, 0x8c9, 0xaf},
	{8, 0x8d4, 0xb0}, {8, 0x8df, 0xb1}, {8, 0x8ea, 0xb2}, {8, 0x8f5, 0xb3}
};

/* The expressions below keep the operator precedence of the transcribed code. */
#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wparentheses"
#endif

/* tisp_dpc_write_reg_long: register writes */
static inline void t32_dpc_long(const u8 *sec, const u8 *o, struct t32_front_write *w, unsigned int *np)
{
	unsigned int n = *np;
	s8 cVar1;
	u32 uVar3;
	u32 uVar4;
	int iVar5;
	u32 uVar6;

		T32_FWR(w, n, 0x2078, t32_front_le32(o + 0));
		uVar3 = (u32)t32_tp_le16(o + 2) + (u32)t32_tp_le16(o + 46);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x205c, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0) - (u32)t32_tp_le16(o + 44));
		cVar1 = (char)t32_tp_le16(o + 4);
		if (cVar1 == '\0') {
			uVar3 = 0;
			uVar6 = 0;
			iVar5 = 0;
			uVar4 = 0;
		}
		else {
			if (cVar1 == '\x01') {
				uVar3 = 0;
				uVar6 = 0;
				iVar5 = 0;
			}
			else {
				if (cVar1 == '\x02') {
					uVar3 = 0;
				}
				else {
					uVar3 = (u32)(cVar1 != '\x03');
				}
				uVar6 = (u32)(cVar1 != '\x02');
				iVar5 = 1;
			}
			uVar4 = 1;
		}
		T32_FWR(w, n, 0x204c, iVar5 << 1 | uVar6 << 2 | uVar4 | uVar3 << 3 | iVar5 << 4 |
				uVar6 << 5 | uVar3 << 6 | uVar6 << 8 | uVar3 << 9 | uVar3 << 0xc |
				uVar4 << 0x10 | iVar5 << 0x11 | uVar6 << 0x12 | uVar3 << 0x13 |
				iVar5 << 0x14 | uVar6 << 0x15 | uVar3 << 0x16 | uVar6 << 0x18 |
				uVar3 << 0x19 | uVar3 << 0x1c);
		T32_FWR(w, n, 0x207c, ((u32)(u16)(t32_tp_le16(o + 6)) << 16 |
				(u16)(t32_tp_le16(o + 8))));
		uVar3 = (u32)t32_tp_le16(o + 6) + (u32)t32_tp_le16(o + 50);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x2060, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 8) - (u32)t32_tp_le16(o + 48));
		T32_FWR(w, n, 0x2080, t32_front_le32(o + 10));
		uVar3 = (u32)t32_tp_le16(o + 12) + (u32)t32_tp_le16(o + 50);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x2064, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 10) - (u32)t32_tp_le16(o + 48));
		T32_FWR(w, n, 0x2084, t32_front_le32(o + 14));
		uVar3 = (u32)t32_tp_le16(o + 16) + (u32)t32_tp_le16(o + 50);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x2068, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 14) - (u32)t32_tp_le16(o + 48));
		T32_FWR(w, n, 0x2088, t32_front_le32(o + 18));
		uVar3 = (u32)t32_tp_le16(o + 20) + (u32)t32_tp_le16(o + 50);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x206c, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 18) - (u32)t32_tp_le16(o + 48));
		T32_FWR(w, n, 0x208c, t32_front_le32(o + 22));
		uVar3 = (u32)t32_tp_le16(o + 24) + (u32)t32_tp_le16(o + 50);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x2070, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 22) - (u32)t32_tp_le16(o + 48));
		T32_FWR(w, n, 0x2090, t32_front_le32(o + 26));
		uVar3 = 0xfff;
		if ((u32)t32_tp_le16(o + 28) + (u32)t32_tp_le16(o + 54) < 0x1000) {
			uVar3 = (u32)t32_tp_le16(o + 28) + (u32)t32_tp_le16(o + 54);
		}
		T32_FWR(w, n, 0x2074, uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 26) - (u32)t32_tp_le16(o + 52));
		T32_FWR(w, n, 0x2094, (u32)t32_tp_le16(o + 30) << 0x10 | (u32)sec[0x395]);
		T32_FWR(w, n, 0x2098, (u32)sec[0x397] << 8 | (u32)t32_tp_le16(o + 32) << 0x10 |
				(u32)sec[0x396]);
		T32_FWR(w, n, 0x20a0, t32_front_le32(o + 34));
		T32_FWR(w, n, 0x216c, ((u32)(u8)t32_tp_le16(o + 42) << 16 | (u16)t32_tp_le16(o + 38)));
		T32_FWR(w, n, 0x2170, (u32)t32_tp_le16(o + 40) << 0x10 | (u32)o[0x2b]);
		T32_FWR(w, n, 0x20c8, t32_front_le32(o + 0x71));
		T32_FWR(w, n, 0x2160, t32_front_le32(o + 134));
		T32_FWR(w, n, 0x2164, t32_front_le32(o + 138));
		T32_FWR(w, n, 0x2168, t32_front_le32(o + 142));
		T32_FWR(w, n, 0x20dc, (t32_tp_le16(o + 120) & 0xfff) << 0x10 |
				t32_tp_le16(o + 118) & 0xfff);
		T32_FWR(w, n, 0x20e0, (t32_tp_le16(o + 124) & 0xfff) << 0x10 |
				t32_tp_le16(o + 122) & 0xfff);
		T32_FWR(w, n, 0x20e4, (t32_tp_le16(o + 128) & 0x3ff) << 0x10 |
				t32_tp_le16(o + 126) & 0x3ff);
		T32_FWR(w, n, 0x20e8, (t32_tp_le16(o + 132) & 0x3ff) << 0x10 |
				t32_tp_le16(o + 130) & 0x3ff);
		T32_FWR(w, n, 0x2010, 1);
	*np = n;
}

/* tisp_dpc_write_reg_short: register writes */
static inline void t32_dpc_short(const u8 *sec, const u8 *o, struct t32_front_write *w, unsigned int *np)
{
	unsigned int n = *np;
	s8 cVar1;
	u32 uVar3;
	u32 uVar4;
	int iVar5;
	u32 uVar6;

		T32_FWR(w, n, 0x29078,t32_front_le32(o + 0x38));
		uVar3 = (u32)t32_tp_le16(o + 0x3a) + (u32)t32_tp_le16(o + 0x66);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x2905c,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x38) - (u32)t32_tp_le16(o + 100));
		cVar1 = ((s8)o[0x3c]);
		if (cVar1 == '\0') {
			uVar3 = 0;
			uVar6 = 0;
			iVar5 = 0;
			uVar4 = 0;
		}
		else {
			if (cVar1 == '\x01') {
				uVar3 = 0;
				uVar6 = 0;
				iVar5 = 0;
			}
			else {
				if (cVar1 == '\x02') {
					uVar3 = 0;
				}
				else {
					uVar3 = (u32)(cVar1 != '\x03');
				}
				uVar6 = (u32)(cVar1 != '\x02');
				iVar5 = 1;
			}
			uVar4 = 1;
		}
		T32_FWR(w, n, 0x2904c,iVar5 << 1 | uVar6 << 2 | uVar4 | uVar3 << 3 | iVar5 << 4 |
				uVar6 << 5 | uVar3 << 6 | uVar6 << 8 | uVar3 << 9 | uVar3 << 0xc |
				uVar4 << 0x10 | iVar5 << 0x11 | uVar6 << 0x12 | uVar3 << 0x13 |
				iVar5 << 0x14 | uVar6 << 0x15 | uVar3 << 0x16 | uVar6 << 0x18 |
				uVar3 << 0x19 | uVar3 << 0x1c);
		T32_FWR(w, n, 0x2907c,((u32)(u16)(t32_tp_le16(o + 0x3e)) << 16 |
				(u16)(t32_tp_le16(o + 0x40))));
		uVar3 = (u32)t32_tp_le16(o + 0x3e) + (u32)t32_tp_le16(o + 0x6a);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x29060,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x40) - (u32)t32_tp_le16(o + 0x68));
		T32_FWR(w, n, 0x29080,t32_front_le32(o + 0x42));
		uVar3 = (u32)t32_tp_le16(o + 0x44) + (u32)t32_tp_le16(o + 0x6a);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x29064,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x42) - (u32)t32_tp_le16(o + 0x68));
		T32_FWR(w, n, 0x29084,t32_front_le32(o + 0x46));
		uVar3 = (u32)t32_tp_le16(o + 0x48) + (u32)t32_tp_le16(o + 0x6a);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x29068,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x46) - (u32)t32_tp_le16(o + 0x68));
		T32_FWR(w, n, 0x29088,t32_front_le32(o + 0x4a));
		uVar3 = (u32)t32_tp_le16(o + 0x4c) + (u32)t32_tp_le16(o + 0x6a);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x2906c,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x4a) - (u32)t32_tp_le16(o + 0x68));
		T32_FWR(w, n, 0x2908c,t32_front_le32(o + 0x4e));
		uVar3 = (u32)t32_tp_le16(o + 0x50) + (u32)t32_tp_le16(o + 0x6a);
		if (0xfff < uVar3) {
			uVar3 = 0xfff;
		}
		T32_FWR(w, n, 0x29070,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x4e) - (u32)t32_tp_le16(o + 0x68));
		T32_FWR(w, n, 0x29090,t32_front_le32(o + 0x52));
		uVar6 = (u32)t32_tp_le16(o + 0x54) + (u32)t32_tp_le16(o + 0x6e);
		uVar3 = 0xfff;
		if (uVar6 < 0x1000) {
			uVar3 = uVar6;
		}
		T32_FWR(w, n, 0x29074,uVar3 << 0x10 |
				(u32)t32_tp_le16(o + 0x52) - (u32)t32_tp_le16(o + 0x6c));
		T32_FWR(w, n, 0x29094,(u32)t32_tp_le16(o + 0x56) << 0x10 | (u32)sec[0x813]);
		T32_FWR(w, n, 0x29098,(u32)sec[0x815] << 8 | (u32)t32_tp_le16(o + 0x58) << 0x10 |
				(u32)sec[0x814]);
		T32_FWR(w, n, 0x290a0,t32_front_le32(o + 0x5a));
		T32_FWR(w, n, 0x2916c,(u32)((u32)(u8)(o[0x62]) << 16 |
				(u16)(t32_tp_le16(o + 0x5e))));
		T32_FWR(w, n, 0x29170,(u32)t32_tp_le16(o + 0x60) << 0x10 | (u32)o[99]);
		T32_FWR(w, n, 0x290c8,t32_front_le32(o + 0x93));
		T32_FWR(w, n, 0x29160,t32_front_le32(o + 0xa8));
		T32_FWR(w, n, 0x29164,t32_front_le32(o + 0xac));
		T32_FWR(w, n, 0x29168,t32_front_le32(o + 0xb0));
		T32_FWR(w, n, 0x290dc,(t32_tp_le16(o + 0x9a) & 0xfff) << 0x10 |
				t32_tp_le16(o + 0x98) & 0xfff);
		T32_FWR(w, n, 0x290e0,(t32_tp_le16(o + 0x9e) & 0xfff) << 0x10 |
				t32_tp_le16(o + 0x9c) & 0xfff);
		T32_FWR(w, n, 0x290e4,(t32_tp_le16(o + 0xa2) & 0x3ff) << 0x10 |
				t32_tp_le16(o + 0xa0) & 0x3ff);
		T32_FWR(w, n, 0x290e8,(t32_tp_le16(o + 0xa6) & 0x3ff) << 0x10 |
				t32_tp_le16(o + 0xa4) & 0x3ff);
		T32_FWR(w, n, 0x29010,1);
	*np = n;
}

/* tisp_dpc_write_reg_other: register writes */
static inline void t32_dpc_other(const u8 *sec, int wide, struct t32_front_write *w, unsigned int *np)
{
	unsigned int n = *np;
	u32 uVar3;

		T32_FWR(w, n, 0x2040, (u32)sec[0x388] << 8 | (u32)sec[0x389] << 0xc |
				(u32)sec[0x386] | (u32)t32_tp_le16(sec + 4) << 0x10);
		T32_FWR(w, n, 0x2044, (u32)sec[899] << 8 | (u32)sec[900] << 0x10 |
				(u32)sec[0x387] | (u32)sec[0x385] << 0x18);
		T32_FWR(w, n, 0x2048, (u32)sec[0x375] << 8 | (u32)sec[0x376] << 0x10 |
				(u32)sec[0x374] | (u32)sec[0x37a] << 0x18);
		T32_FWR(w, n, 0x2050, (u32)sec[0x37f] << 8 | (u32)sec[0x380] << 0x10 |
				(u32)sec[0x37e] | (u32)sec[0x381] << 0x14 |
				(u32)sec[0x382] << 0x18);
		T32_FWR(w, n, 0x2054, (u32)sec[0x37c] << 0x10 | (u32)sec[0x37d] << 0x18 |
				(u32)sec[0x378]);
		T32_FWR(w, n, 0x2058, (u32)sec[0x37b] << 0x10 | (u32)sec[0x379]);
		T32_FWR(w, n, 0x209c, (u32)sec[0x399] << 8 | (u32)sec[0x39a] << 0x10 |
				(u32)sec[0x398]);
		T32_FWR(w, n, 0x20a4, t32_front_le32(sec + 0x39c));
		T32_FWR(w, n, 0x20a8, t32_front_le32(sec + 0x3a0));
		T32_FWR(w, n, 0x20ac, t32_front_le32(sec + 0x3a4));
		T32_FWR(w, n, 0x20b0, t32_front_le32(sec + 0x3a8));
		T32_FWR(w, n, 0x20b4, t32_front_le32(sec + 0x3ac));
		T32_FWR(w, n, 0x20b8, t32_front_le32(sec + 0x3b0));
		T32_FWR(w, n, 0x20bc, t32_front_le32(sec + 0x3b4));
		T32_FWR(w, n, 0x20c0, t32_front_le32(sec + 0x3b8));
		T32_FWR(w, n, 0x2010, 1);
		T32_FWR(w, n, 0x29040,(u32)sec[0x806] << 8 | (u32)sec[0x807] << 0xc |
				(u32)sec[0x804] | (u32)t32_tp_le16(sec + 0x482) << 0x10);
		T32_FWR(w, n, 0x29044,(u32)sec[0x801] << 8 | (u32)sec[0x802] << 0x10 |
				(u32)sec[0x805] | (u32)sec[0x803] << 0x18);
		T32_FWR(w, n, 0x29048,(u32)sec[0x7f3] << 8 | (u32)sec[0x7f4] << 0x10 |
				(u32)sec[0x7f2] | (u32)sec[0x7f8] << 0x18);
		T32_FWR(w, n, 0x29050,(u32)sec[0x7fd] << 8 | (u32)sec[0x7fe] << 0x10 |
				(u32)sec[0x7fc] | (u32)sec[0x7ff] << 0x14 |
				(u32)sec[0x800] << 0x18);
		T32_FWR(w, n, 0x29054,(u32)sec[0x7fa] << 0x10 | (u32)sec[0x7fb] << 0x18 |
				(u32)sec[0x7f6]);
		T32_FWR(w, n, 0x29058,(u32)sec[0x7f9] << 0x10 | (u32)sec[0x7f7]);
		T32_FWR(w, n, 0x2909c,(u32)sec[0x817] << 8 | (u32)sec[0x818] << 0x10 |
				(u32)sec[0x816]);
		T32_FWR(w, n, 0x290a4,t32_front_le32(sec + 0x81a));
		T32_FWR(w, n, 0x290a8,t32_front_le32(sec + 0x81e));
		T32_FWR(w, n, 0x290ac,t32_front_le32(sec + 0x822));
		T32_FWR(w, n, 0x290b0,t32_front_le32(sec + 0x826));
		T32_FWR(w, n, 0x290b4,t32_front_le32(sec + 0x82a));
		T32_FWR(w, n, 0x290b8,t32_front_le32(sec + 0x82e));
		T32_FWR(w, n, 0x290bc,t32_front_le32(sec + 0x832));
		T32_FWR(w, n, 0x290c0,t32_front_le32(sec + 0x836));
		T32_FWR(w, n, 0x29010,1);
		T32_FWR(w, n, 0x20c4, sec[0x36b] & 7);
		T32_FWR(w, n, 0x20cc, (sec[0x36d] & 3) << 8 | (sec[0x36e] & 3) << 0x10 |
				sec[0x36c] & 3 | (sec[0x36f] & 3) << 0x18);
		T32_FWR(w, n, 0x20d0, (sec[0x370] & 1) << 4 | (sec[0x371] & 1) << 8 |
				sec[0x36a] & 1 | (sec[0x372] & 1) << 0xc |
				(sec[0x373] & 1) << 0x10);
		T32_FWR(w, n, 0x20d4, (t32_tp_le16(sec + 0x244) & 0xfff) << 0x10 |
				t32_tp_le16(sec + 0x242) & 0xfff);
		uVar3 = t32_tp_le16(sec + 0x242) & 0xfff;
		T32_FWR(w, n, 0x20d8, uVar3 << 0x10 | uVar3);
		T32_FWR(w, n, 0x20ec, (t32_tp_le16(sec + 0x2fc) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x2fa) & 0x7ff);
		T32_FWR(w, n, 0x20f0, (t32_tp_le16(sec + 0x300) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x2fe) & 0x7ff);
		T32_FWR(w, n, 0x20f4, (t32_tp_le16(sec + 0x304) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x302) & 0x7ff);
		T32_FWR(w, n, 0x20f8, (t32_tp_le16(sec + 0x308) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x306) & 0x7ff);
		T32_FWR(w, n, 0x20fc, (t32_tp_le16(sec + 0x30c) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x30a) & 0x7ff);
		T32_FWR(w, n, 0x2100, (t32_tp_le16(sec + 0x310) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x30e) & 0x7ff);
		T32_FWR(w, n, 0x2104, (t32_tp_le16(sec + 0x314) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x312) & 0x7ff);
		T32_FWR(w, n, 0x2108, (t32_tp_le16(sec + 0x318) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x316) & 0x7ff);
		T32_FWR(w, n, 0x210c, (t32_tp_le16(sec + 0x31c) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x31a) & 0x7ff);
		T32_FWR(w, n, 0x2110, (t32_tp_le16(sec + 800) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x31e) & 0x7ff);
		T32_FWR(w, n, 0x2114, (t32_tp_le16(sec + 0x324) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x322) & 0x7ff);
		T32_FWR(w, n, 0x211c, (t32_tp_le16(sec + 0x328) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x326) & 0x7ff);
		T32_FWR(w, n, 0x2120, (t32_tp_le16(sec + 0x32c) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x32a) & 0x7ff);
		T32_FWR(w, n, 0x2124, (t32_tp_le16(sec + 0x330) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x32e) & 0x7ff);
		T32_FWR(w, n, 0x2128, (t32_tp_le16(sec + 0x334) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x332) & 0x7ff);
		T32_FWR(w, n, 0x212c, (t32_tp_le16(sec + 0x338) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x336) & 0x7ff);
		T32_FWR(w, n, 0x2130, (t32_tp_le16(sec + 0x33c) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x33a) & 0x7ff);
		T32_FWR(w, n, 0x2134, (t32_tp_le16(sec + 0x340) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x33e) & 0x7ff);
		T32_FWR(w, n, 0x2138, (t32_tp_le16(sec + 0x344) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x342) & 0x7ff);
		T32_FWR(w, n, 0x213c, (t32_tp_le16(sec + 0x348) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x346) & 0x7ff);
		T32_FWR(w, n, 0x2140, (t32_tp_le16(sec + 0x34c) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x34a) & 0x7ff);
		if (wide) {
			T32_FWR(w, n, 0x2144, (t32_tp_le16(sec + 0x350) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x34e) & 0x7ff);
			T32_FWR(w, n, 0x2148, (t32_tp_le16(sec + 0x354) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x352) & 0x7ff);
			T32_FWR(w, n, 0x214c, (t32_tp_le16(sec + 0x358) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x356) & 0x7ff);
			T32_FWR(w, n, 0x2150, (t32_tp_le16(sec + 0x35c) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x35a) & 0x7ff);
			T32_FWR(w, n, 0x2154, (t32_tp_le16(sec + 0x360) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x35e) & 0x7ff);
			T32_FWR(w, n, 0x2158, (t32_tp_le16(sec + 0x364) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x362) & 0x7ff);
			T32_FWR(w, n, 0x215c, (t32_tp_le16(sec + 0x368) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x366) & 0x7ff);
		}
		T32_FWR(w, n, 0x2010, 1);
		T32_FWR(w, n, 0x290c4,sec[0x7e9] & 7);
		T32_FWR(w, n, 0x290cc,(sec[0x7eb] & 3) << 8 | (sec[0x7ec] & 3) << 0x10 |
				sec[0x7ea] & 3 | (sec[0x7ed] & 3) << 0x18);
		T32_FWR(w, n, 0x290d0,(sec[0x7ee] & 1) << 4 | (sec[0x7ef] & 1) << 8 |
				sec[0x7e8] & 1 | (sec[0x7f0] & 1) << 0xc |
				(sec[0x7f1] & 1) << 0x10);
		T32_FWR(w, n, 0x290d4,(t32_tp_le16(sec + 0x6c2) & 0xfff) << 0x10 |
				t32_tp_le16(sec + 0x6c0) & 0xfff);
		uVar3 = t32_tp_le16(sec + 0x6c0) & 0xfff;
		T32_FWR(w, n, 0x290d8,uVar3 << 0x10 | uVar3);
		T32_FWR(w, n, 0x290ec,(t32_tp_le16(sec + 0x77a) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x778) & 0x7ff);
		T32_FWR(w, n, 0x290f0,(t32_tp_le16(sec + 0x77e) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x77c) & 0x7ff);
		T32_FWR(w, n, 0x290f4,(t32_tp_le16(sec + 0x782) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x780) & 0x7ff);
		T32_FWR(w, n, 0x290f8,(t32_tp_le16(sec + 0x786) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x784) & 0x7ff);
		T32_FWR(w, n, 0x290fc,(t32_tp_le16(sec + 0x78a) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x788) & 0x7ff);
		T32_FWR(w, n, 0x29100,(t32_tp_le16(sec + 0x78e) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x78c) & 0x7ff);
		T32_FWR(w, n, 0x29104,(t32_tp_le16(sec + 0x792) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x790) & 0x7ff);
		T32_FWR(w, n, 0x29108,(t32_tp_le16(sec + 0x796) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x794) & 0x7ff);
		T32_FWR(w, n, 0x2910c,(t32_tp_le16(sec + 0x79a) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x798) & 0x7ff);
		T32_FWR(w, n, 0x29110,(t32_tp_le16(sec + 0x79e) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x79c) & 0x7ff);
		T32_FWR(w, n, 0x29114,(t32_tp_le16(sec + 0x7a2) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7a0) & 0x7ff);
		T32_FWR(w, n, 0x2911c,(t32_tp_le16(sec + 0x7a6) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7a4) & 0x7ff);
		T32_FWR(w, n, 0x29120,(t32_tp_le16(sec + 0x7aa) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7a8) & 0x7ff);
		T32_FWR(w, n, 0x29124,(t32_tp_le16(sec + 0x7ae) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7ac) & 0x7ff);
		T32_FWR(w, n, 0x29128,(t32_tp_le16(sec + 0x7b2) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7b0) & 0x7ff);
		T32_FWR(w, n, 0x2912c,(t32_tp_le16(sec + 0x7b6) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7b4) & 0x7ff);
		T32_FWR(w, n, 0x29130,(t32_tp_le16(sec + 0x7ba) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7b8) & 0x7ff);
		T32_FWR(w, n, 0x29134,(t32_tp_le16(sec + 0x7be) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7bc) & 0x7ff);
		T32_FWR(w, n, 0x29138,(t32_tp_le16(sec + 0x7c2) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7c0) & 0x7ff);
		T32_FWR(w, n, 0x2913c,(t32_tp_le16(sec + 0x7c6) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7c4) & 0x7ff);
		T32_FWR(w, n, 0x29140,(t32_tp_le16(sec + 0x7ca) & 0x7ff) << 0x10 |
				t32_tp_le16(sec + 0x7c8) & 0x7ff);
		if (wide) {
			T32_FWR(w, n, 0x29144,(t32_tp_le16(sec + 0x7ce) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x7cc) & 0x7ff);
			T32_FWR(w, n, 0x29148,(t32_tp_le16(sec + 0x7d2) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 2000) & 0x7ff);
			T32_FWR(w, n, 0x2914c,(t32_tp_le16(sec + 0x7d6) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x7d4) & 0x7ff);
			T32_FWR(w, n, 0x29150,(t32_tp_le16(sec + 0x7da) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x7d8) & 0x7ff);
			T32_FWR(w, n, 0x29154,(t32_tp_le16(sec + 0x7de) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x7dc) & 0x7ff);
			T32_FWR(w, n, 0x29158,(t32_tp_le16(sec + 0x7e2) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x7e0) & 0x7ff);
			T32_FWR(w, n, 0x2915c,(t32_tp_le16(sec + 0x7e6) & 0x7ff) << 0x10 |
					t32_tp_le16(sec + 0x7e4) & 0x7ff);
		}
		T32_FWR(w, n, 0x29010,1);
	*np = n;
}

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*
 * sec: section 5 (T32_DPC_SEC_BYTES, read only); wide: see above; the writes
 * go to w (T32_DPC_MAX_WRITES entries).  Returns their number.
 */
static inline int t32_dpc_init(const u8 *sec, int wide, struct t32_front_write *w)
{
	u8 o[T32_DPC_VALUES];
	unsigned int n = 0, k;

	for (k = 0; k < T32_DPC_VALUES; k++)
		o[k] = 0;
	for (k = 0; k < 106; k++) {
		if (t32_dpc_map[k][0] == 16)
			t32_tp_put16(o + t32_dpc_map[k][2], t32_tp_intp_u16(0, 0, sec + t32_dpc_map[k][1]));
		else
			o[t32_dpc_map[k][2]] = t32_tp_intp_u8(0, 0, sec + t32_dpc_map[k][1]);
	}
	t32_dpc_long(sec, o, w, &n);
	t32_dpc_short(sec, o, w, &n);
	t32_dpc_other(sec, wide, w, &n);
	T32_FWR(w, n, 0x2000, T32_DPC_ID);
	return (int)n;
}

#endif /* TX_ISP_T32_DPC_H */
