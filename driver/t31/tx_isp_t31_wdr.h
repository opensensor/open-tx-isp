/* SPDX-License-Identifier: GPL-2.0 */
#ifndef TX_ISP_T31_WDR_H
#define TX_ISP_T31_WDR_H

/* T31 WDR arithmetic and statistics layouts. The register/algorithm
 * references below are offsets in the recovered T31 OEM text, as recorded
 * in tx-isp-t31.ko_hlil.txt. Keep these helpers usable by the host oracle. */
#ifdef __KERNEL__
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/string.h>
#else
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
typedef uint32_t u32;
typedef int32_t s32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef uint64_t u64;
#endif

#define T31_WDR_BINS 256
#define T31_WDR_BLOCKS 225
#define T31_WDR_MAP_POINTS 81
#define T31_WDR_THRESHOLDS 26
#define T31_WDR_CURVE_POINTS 33
#define T31_WDR_EV_POINTS 9
#define T31_WDR_DMA_SLOT_BYTES 0x2000
#define T31_WDR_STATS_BYTES 0x1020

struct t31_wdr_stats {
	u32 rgb[2][3][T31_WDR_BINS];
	u32 count[2][3];
	u32 point_sum[2];
	u32 point_sum_high[2];
};

/* OEM 0x5d114: each bin has two pairs of words. G straddles the
 * 21-bit R/B counters; bits 31 of the second words are padding. */
static inline void t31_wdr_unpack_triplet(const u32 *packed, u32 *r,
					u32 *g, u32 *b)
{
	*r = packed[0] & 0x1fffff;
	*g = (packed[0] >> 21) | ((packed[1] & 0x3ff) << 11);
	*b = (packed[1] >> 10) & 0x1fffff;
}

static inline int t31_wdr_unpack_stats(struct t31_wdr_stats *out,
				      const u32 *packed, size_t bytes)
{
	u32 i, exposure;

	if (!out || !packed || bytes < T31_WDR_STATS_BYTES)
		return -EINVAL;
	for (i = 0; i < T31_WDR_BINS; ++i)
		for (exposure = 0; exposure < 2; ++exposure)
			t31_wdr_unpack_triplet(packed + i * 4 + exposure * 2,
				&out->rgb[exposure][0][i],
				&out->rgb[exposure][1][i],
				&out->rgb[exposure][2][i]);
	for (exposure = 0; exposure < 2; ++exposure) {
		t31_wdr_unpack_triplet(packed + 0x400 + exposure * 2,
			&out->count[exposure][0], &out->count[exposure][1],
			&out->count[exposure][2]);
		out->point_sum[exposure] = packed[0x404 + exposure * 2];
		out->point_sum_high[exposure] = packed[0x405 + exposure * 2] & 1;
	}
	return 0;
}

/* OEM IRQ 0x5d2a0 compacts eight 0x204-byte payloads whose source
 * stride is 0x400. The result includes the 32-byte statistics footer.
 * Separate storage avoids altering a DMA slot while hardware owns it. */
static inline int t31_wdr_compact_stats(u8 *out, size_t out_bytes,
				       const u8 *slot, size_t slot_bytes)
{
	u32 i;

	if (!out || !slot || out_bytes < T31_WDR_STATS_BYTES ||
	    slot_bytes < T31_WDR_DMA_SLOT_BYTES)
		return -EINVAL;
	for (i = 0; i < 8; ++i)
		memcpy(out + i * 0x204, slot + i * 0x400, 0x204);
	return 0;
}

/* AE1's 15x15 DMA bank uses the same packed RGB triplet, with four words
 * per zone. OEM ae1_weight_mean2 divides the RGB sum by that zone's area. */
static inline int t31_wdr_ae_blocks(u32 *out, const u32 *packed, size_t bytes,
				   const u32 *params)
{
	u32 cols = params[1], rows = params[3], i, r, g, b, area;
	if (!cols || cols > 15 || !rows || rows > 15 || bytes < cols * rows * 16)
		return -EINVAL;
	for (i = 0; i < cols; ++i)
		if (!params[4 + i] || params[4 + i] > 4095)
			return -EINVAL;
	for (i = 0; i < rows; ++i)
		if (!params[19 + i] || params[19 + i] > 4095)
			return -EINVAL;
	memset(out, 0, T31_WDR_BLOCKS * sizeof(*out));
	for (i = 0; i < cols * rows; ++i) {
		t31_wdr_unpack_triplet(packed + i * 4, &r, &g, &b);
		area = params[4 + i % cols] * params[19 + i / cols];
		out[i] = (r + g + b) / area;
	}
	return 0;
}

/* OEM 0x5d760: sorted largest eight short-exposure blocks. */
static inline u32 t31_wdr_bright_blocks(const u32 block[T31_WDR_BLOCKS],
				       u32 count)
{
	u32 top[8] = {0};
	u32 i, j, k, sum = 0;

	if (count < 4)
		count = 4;
	if (count > 8)
		count = 8;
	for (i = 0; i < T31_WDR_BLOCKS; ++i)
		for (j = 0; j < 8; ++j) {
			if (block[i] <= top[j])
				continue;
			for (k = 7; k > j; --k)
				top[k] = top[k - 1];
			top[j] = block[i];
			break;
		}
	for (i = 0; i < count; ++i)
		sum += top[i];
	return sum / count;
}

static inline u32 t31_wdr_slew(u32 previous, u32 next, u32 enabled, u32 step)
{
	if (!enabled)
		return next;
	if (next > previous && next - previous > step)
		return previous + step;
	if (previous > next && previous - next > step)
		return previous - step;
	return next;
}

/* OEM interpolation uses a wrapped 32-bit unsigned product and truncates
 * toward the lower endpoint. Handle duplicate knots without division. */
static inline u32 t31_wdr_lerp(u32 x, u32 x0, u32 x1, u32 y0, u32 y1)
{
	u32 span, distance, step;

	if (x <= x0)
		return y0;
	if (x >= x1 || x1 <= x0)
		return y1;
	span = x1 - x0;
	distance = x - x0;
	if (y1 >= y0) {
		step = ((y1 - y0) * distance) / span;
		return y0 + step;
	}
	step = ((y0 - y1) * distance) / span;
	return y0 - step;
}

static inline u32 t31_wdr_ev_interp(u32 ev, const u32 *knots,
				   const u32 *values, u32 stride)
{
	u32 i;

	for (i = 0; i < T31_WDR_EV_POINTS; ++i)
		if (ev <= knots[i]) {
			if (!i)
				return values[0];
			return t31_wdr_lerp(ev, knots[i - 1], knots[i],
				values[(i - 1) * stride], values[i * stride]);
		}
	return values[(T31_WDR_EV_POINTS - 1) * stride];
}

/* OEM fusion curves (0x5c54c / 0x5aff0): distribute the signed remainder
 * over the FIRST steps, rather than rounding independently at each point. */
static inline void t31_wdr_curve_segment(u32 *out, u32 first, u32 last,
				       u32 first_y, u32 last_y)
{
	s32 delta = (s32)last_y - (s32)first_y;
	s32 width = (s32)(last - first);
	s32 quotient = delta / width;
	s32 remainder = delta % width;
	s32 direction = delta < 0 ? -1 : 1;
	u32 i, extra = remainder < 0 ? (u32)-remainder : (u32)remainder;

	out[first] = first_y;
	for (i = 0; i < (u32)width; ++i)
		out[first + i + 1] = (u32)((s32)out[first + i] + quotient +
			(i < extra ? direction : 0));
}

static inline int t31_wdr_fusion_curve(u32 out[T31_WDR_CURVE_POINTS],
				      const u32 points[7])
{
	u32 i;

	/* Three interior x coordinates followed by four y coordinates. */
	if (points[0] >= points[1] || points[1] >= points[2] || points[2] >= 32)
		return -EINVAL;
	for (i = 3; i < 7; ++i)
		if (points[i] > 65535)
			return -ERANGE;
	for (i = 0; i <= points[0]; ++i)
		out[i] = points[3];
	t31_wdr_curve_segment(out, points[0], points[1], points[3], points[4]);
	t31_wdr_curve_segment(out, points[1], points[2], points[4], points[5]);
	t31_wdr_curve_segment(out, points[2], 32, points[5], points[6]);
	for (i = 0; i < 33; ++i)
		if (out[i] > 256)
			out[i] = 256;
	return 0;
}

#endif
