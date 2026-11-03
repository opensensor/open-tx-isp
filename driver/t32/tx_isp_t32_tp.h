/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Shared helpers of the T32 tisp init blocks (S4 step 5): the write record,
 * little endian readers and the vendor's table interpolation.
 *
 * The vendor addresses the IQ bin sections as tparams + offset; with the
 * bin's section table (tx_isp_t32_iq.h) the offset of section k is 8 plus the
 * sum of the lengths of the sections before it, each rounded up to 4.  The
 * blocks here take the section by index.
 */
#ifndef TX_ISP_T32_TP_H
#define TX_ISP_T32_TP_H

#include "tx_isp_t32_front.h"

#ifndef __KERNEL__
#ifndef T32_HOST_S16
#define T32_HOST_S16
typedef int16_t s16;
#endif
#ifndef T32_HOST_S8
#define T32_HOST_S8
typedef int8_t s8;
#endif
#endif

#ifdef __KERNEL__
#include <linux/math64.h>
#define t32_tp_div64(a, b)	div64_u64((a), (b))
#else
#define t32_tp_div64(a, b)	((a) / (b))
#endif

#ifndef T32_FWR
#define T32_FWR(w, n, r, v) do { (w)[(n)].reg = (r); (w)[(n)].val = (v); (n)++; } while (0)
#endif

static inline u32 t32_tp_le16(const u8 *p)
{
	return p[0] | (u32)p[1] << 8;
}

static inline u32 t32_tp_le24(const u8 *p)
{
	return p[0] | (u32)p[1] << 8 | (u32)p[2] << 16;
}

/* tisp_simple_intp_uint8: t[i] towards t[i + 1] by frac / 65536, rounded; t[10] from i >= 10 */
static inline u8 t32_tp_intp_u8(u32 i, u32 frac, const u8 *t)
{
	u32 a, b, d, v;

	if (i >= 10)
		return t[10];
	a = t[i];
	b = t[i + 1];
	if (a == b)
		return (u8)a;
	d = (a < b ? b - a : a - b) * frac;
	v = (d >> 16) + ((d >> 15) & 1);
	return (u8)(a < b ? a + v : a - v);
}

/* tisp_simple_intp_uint16: the same for 11 point tables of u16 */
static inline u16 t32_tp_intp_u16(u32 i, u32 frac, const u8 *t)
{
	u32 a, b, d, v;

	if (i >= 10)
		return (u16)t32_tp_le16(t + 20);
	a = t32_tp_le16(t + 2 * i);
	b = t32_tp_le16(t + 2 * i + 2);
	if (a == b)
		return (u16)a;
	d = (a < b ? b - a : a - b) * frac;
	v = (d >> 16) + ((d >> 15) & 1);
	return (u16)(a < b ? a + v : a - v);
}

static inline void t32_tp_put16(u8 *p, u32 v)
{
	p[0] = v & 0xff;
	p[1] = (v >> 8) & 0xff;
}

static inline void t32_tp_put32(u8 *p, u32 v)
{
	t32_tp_put16(p, v);
	t32_tp_put16(p + 2, v >> 16);
}

#endif /* TX_ISP_T32_TP_H */
