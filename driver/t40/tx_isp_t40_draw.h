/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 ISP draw / privacy-mask shadow helpers, plain data (Lu-Fi/openimp#186, #187), host test
 * tests/tx_isp_t40_draw_test.c.  Written from the OEM tx-isp-t40.ko (Eufy build):
 *
 *  - t40_draw_set_state: OEM tisp_s_draw_attr.  User block 2 output channels x 16 units x 28 bytes,
 *    state 616 bytes per output channel, 24 bytes per unit starting at +100 (type +100, enable +104,
 *    u16 left/top/width/height +106..+112, colour u32 +116, line width +120, alpha +121, u16 +122).
 *    The lift wrote 8-byte words at doubled offsets and never left its loop.
 *  - t40_mask_en_word: the enable word of Tzn_Msca_Shd_mask (register 0x16014 + vin * 0x1000).  The OEM
 *    ORs the BYTE enables of the four units of an output channel; the lift ORed 32-bit words, which
 *    pulled the u16 position fields (+0x26) into the register value.
 *  - t40_line_chx_emit: the per-unit register writes of Tzn_Msca_Shd_line_chx.  The lift read the u16
 *    state fields as unaligned 32-bit words and always took the "negative slope" branch of the line
 *    quantiser.
 */
#ifndef TX_ISP_T40_DRAW_H
#define TX_ISP_T40_DRAW_H

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
#include <stddef.h>
#include <string.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int16_t s16;
typedef int32_t s32;
#endif

#define T40_DRAW_CH_BYTES 616
#define T40_DRAW_UNIT_BYTES 24
#define T40_DRAW_USER_UNIT 28
#define T40_DRAW_USER_CH 448

static inline u16 t40_dr_u16(const u8 *p) { u16 v; memcpy(&v, p, sizeof(v)); return v; }
static inline u32 t40_dr_u32(const u8 *p) { u32 v; memcpy(&v, p, sizeof(v)); return v; }
static inline void t40_dr_w16(u8 *p, u16 v) { memcpy(p, &v, sizeof(v)); }
static inline void t40_dr_w32(u8 *p, u32 v) { memcpy(p, &v, sizeof(v)); }

/* OEM tisp_s_draw_attr(vin, user): 'state' is mscaler_s0 or mscaler_s1 */
static inline void t40_draw_set_state(u8 *state, const u8 *user)
{
	unsigned ch, unit;

	for (ch = 0; ch < 2; ch++, state += T40_DRAW_CH_BYTES, user += T40_DRAW_USER_CH) {
		for (unit = 0; unit < 16; unit++) {
			const u8 *d = user + unit * T40_DRAW_USER_UNIT;
			u8 *s = state + unit * T40_DRAW_UNIT_BYTES;
			u32 type = t40_dr_u32(d);

			s[100] = (u8)type;
			if (type > 2)
				continue;
			s[104] = d[8];
			if (!d[8])
				continue;
			t40_dr_w16(s + 106, t40_dr_u16(d + 10));
			t40_dr_w16(s + 108, t40_dr_u16(d + 12));
			t40_dr_w16(s + 110, t40_dr_u16(d + 14));
			t40_dr_w16(s + 112, t40_dr_u16(d + 16));
			t40_dr_w32(s + 116, (u32)d[21] << 16 | (u32)d[22] << 8 | d[23]);
			s[120] = d[24];
			s[121] = d[25];
			if (type == 1)
				t40_dr_w16(s + 122, t40_dr_u16(d + 26));
		}
	}
}

/* enable word of Tzn_Msca_Shd_mask: bit 0..2 = output channel 0..2 has an enabled unit (BYTE enables) */
static inline u32 t40_mask_en_word(const u8 *state)
{
	u32 w = 0;
	unsigned ch, unit;

	for (ch = 0; ch < 3; ch++) {
		u8 any = 0;

		for (unit = 0; unit < 4; unit++)
			any |= state[ch * 616 + 0x24 + unit * 16];
		w |= (u32)any << ch;
	}
	return w;
}

/* OEM tisp_s_mscaler_mask_attr (state part): the lift stepped its pointers in words of their pointer type (+96 instead of
 * +24 per unit, +2464 instead of +616 per channel), so only unit 0 of output channel 0 was stored and the others hit
 * the memory behind the state.  User block 3 channels x 4 units x 24 bytes (enable +0, u16 +2/+4/+6/+8, y u v +19..+21). */
static inline void t40_mask_set_state(u8 *state, const u8 *user)
{
	unsigned ch, unit;

	for (ch = 0; ch < 3; ch++, state += T40_DRAW_CH_BYTES, user += 96) {
		for (unit = 0; unit < 4; unit++) {
			const u8 *d = user + unit * 24;
			u8 *s = state + unit * 16;

			if (d[0] == 1) {
				s[36] = 1;
				t40_dr_w16(s + 40, t40_dr_u16(d + 2));
				t40_dr_w16(s + 38, t40_dr_u16(d + 4));
				t40_dr_w16(s + 42, t40_dr_u16(d + 6));
				t40_dr_w16(s + 44, t40_dr_u16(d + 8));
				t40_dr_w32(s + 48, (u32)d[19] << 16 | (u32)d[20] << 8 | d[21]);
			} else {
				s[36] = 0;
			}
		}
	}
}

/* OEM tisp_g_mscaler_mask_attr: 3 output channels x 4 units; state unit = 16 bytes at +36 (enable), +38 top... */
static inline void t40_mask_get_state(const u8 *state, u8 *user)
{
	unsigned ch, unit;

	for (ch = 0; ch < 3; ch++, state += T40_DRAW_CH_BYTES, user += 96) {
		for (unit = 0; unit < 4; unit++) {
			const u8 *s = state + unit * 16;
			u8 *d = user + unit * 24;

			if (s[36] == 1) {
				u32 c = t40_dr_u32(s + 48);

				d[0] = 1;
				t40_dr_w16(d + 2, t40_dr_u16(s + 40));
				t40_dr_w16(d + 4, t40_dr_u16(s + 38));
				t40_dr_w16(d + 6, t40_dr_u16(s + 42));
				t40_dr_w16(d + 8, t40_dr_u16(s + 44));
				d[0x13] = (u8)(c >> 16);
				d[0x14] = (u8)(c >> 8);
				d[0x15] = (u8)c;
			} else {
				d[0] = 0;
				t40_dr_w16(d + 2, 0);
				t40_dr_w16(d + 4, 0);
				t40_dr_w16(d + 6, 0);
				t40_dr_w16(d + 8, 0);
				d[0x13] = d[0x14] = d[0x15] = 0;
			}
		}
	}
}

typedef void (*t40_draw_sink)(void *ctx, u32 value, u32 addr);

static inline s32 t40_dr_abs16(s32 v)
{
	s16 m = (s16)((s16)v >> 15);

	return (s16)(((s16)v ^ m) - m);
}

/*
 * Register writes of one output channel (state = start of the channel, reg = vin * 0x1000 + ch * 0x100),
 * 16 units, each a (value, address) pair set 0x16400..0x1640c + unit * 0x10.  Returns the number of
 * units refused ("type not supported" / line type with an enabled unit beyond 8).
 */
static inline unsigned t40_line_chx_emit(const u8 *chan, u32 reg, t40_draw_sink wr, void *ctx)
{
	unsigned bad = 0, i;

	for (i = 0; i < 16; i++, reg += 0x10) {
		const u8 *u = chan + i * T40_DRAW_UNIT_BYTES;
		u32 type = u[100], tail;
		u32 x0 = t40_dr_u16(u + 106), y0 = t40_dr_u16(u + 108);
		u32 x1 = t40_dr_u16(u + 110), y1 = t40_dr_u16(u + 112);
		u32 color = (t40_dr_u32(u + 116) & 0xffffffu) | (u32)u[120] << 24;
		u32 word, size;

		if (type == 2) {
			wr(ctx, x0 << 16 | y0, reg + 0x16400);
			size = x1 << 16 | y1;
			word = (u32)u[104] | (u32)u[121] << 8;
		} else if (type == 1) {
			wr(ctx, x0 << 16 | y0, reg + 0x16400);
			size = x1 << 16 | y1;
			word = (u32)u[100] << 4 | (u32)u[121] << 8 | u[104] | (u32)t40_dr_u16(u + 122) << 16;
		} else if (type == 0) {
			s32 dx = (s16)(u16)(x1 - x0), dy = (s16)(u16)(y1 - y0);
			u32 minx = x1 < x0 ? x1 : x0, miny = y1 < y0 ? y1 : y0;
			u32 en = u[104], code = 0, slope = 0;
			u32 ax, ay;

			if (!dx || !dy) {
				ax = (u32)t40_dr_abs16(dx);
				ay = (u32)t40_dr_abs16(dy);
				if (!ax)
					ax = u[120];
				if (!ay)
					ay = u[120];
				wr(ctx, minx << 16 | miny, reg + 0x16400);
				size = ax << 16 | ay;
				word = (u32)u[104] | (u32)u[121] << 8;
				goto emit_tail;
			}
			if (i < 8) {
				if (x1 < x0 && y1 < y0) {
					dx = (s16)(u16)(x0 - x1);
					dy = (s16)(u16)(y0 - y1);
				}
				if (en) {
					if (dy < 0 || dx < 0) {
						dx = t40_dr_abs16(dx);
						dy = t40_dr_abs16(dy);
						if (dx < dy) {
							code = 3;
							slope = (u32)((dx << 8) / dy) & 0xffff;
						} else {
							code = 1;
							slope = (u32)((dy << 8) / dx) & 0xffff;
						}
					} else if (dx < dy) {
						code = 2;
						slope = (u32)((dx << 8) / dy) & 0xffff;
					} else {
						code = 0;
						slope = (u32)((dy << 8) / dx) & 0xffff;
					}
				}
			} else {
				if (en) {
					bad++;
					continue;
				}
				if (x1 < x0 && y1 < y0) {
					dx = (s16)(u16)(x0 - x1);
					dy = (s16)(u16)(y0 - y1);
				}
			}
			wr(ctx, minx << 16 | miny, reg + 0x16400);
			size = (u32)dx << 16 | (u32)dy;
			word = (u32)u[104] | 0x20 | (u32)u[121] << 8 | (code << 9 | slope) << 16;
		} else {
			bad++;
			continue;
		}
emit_tail:
		tail = word;
		wr(ctx, size, reg + 0x16404);
		wr(ctx, color, reg + 0x16408);
		wr(ctx, tail, reg + 0x1640c);
	}
	return bad;
}

/* OEM Tzn_Msca_init_cfg (state part): memset 1860, u16 [0] = width, [1] = height, then per output channel (3 x 616 bytes
 * from +10) u16 +0 = height, +2 = width, +14 = width, +16 = height, +22 = width, +24 = height; the spin lock follows at +1856
 * (the caller inits it).  The lift stepped `uintptr_t *` pointers (+10 became +40, +616 became +2464, the lock +7424). */
static inline void t40_msca_init_state(u8 *state, u32 width, u32 height)
{
	unsigned off;

	memset(state, 0, 1860);
	t40_dr_w16(state + 0, (u16)width);
	t40_dr_w16(state + 2, (u16)height);
	for (off = 10; off != 1858; off += 616) {
		t40_dr_w16(state + off + 0, (u16)height);
		t40_dr_w16(state + off + 2, (u16)width);
		t40_dr_w16(state + off + 14, (u16)width);
		t40_dr_w16(state + off + 16, (u16)height);
		t40_dr_w16(state + off + 22, (u16)width);
		t40_dr_w16(state + off + 24, (u16)height);
	}
}

#endif
