/* SPDX-License-Identifier: GPL-2.0 */
#ifndef TX_ISP_T31_WDR_CONTROL_H
#define TX_ISP_T31_WDR_CONTROL_H
#include "tx_isp_t31_wdr_math.h"

struct t31_wdr_ev {
	u32 now, old, changed, delta, output[7], short_to_long;
};

static inline void t31_wdr_ev_update(struct t31_wdr_ev *ev, u32 low, u32 high)
{
	u32 next = (high << 22) | (low >> 10);
	ev->delta = next > ev->old ? next - ev->old : ev->old - next;
	ev->now = ev->old = next;
	ev->changed = 1;
}

/* LUTs have two eight-word rows each. They are independent arrays in C;
 * pointer arithmetic across their object boundaries is not permissible. */
static inline int t31_wdr_fusion_table(u32 *out, u32 value, const u32 *knots,
				      const u32 *const table[5])
{
	u32 rows[9], points[7], i, j;
	for (j = 0; j < 7; ++j) {
		for (i = 0; i < 9; ++i)
			rows[i] = table[i / 2][(i % 2) * 8 + 1 + j];
		points[j] = t31_wdr_ev_interp(value, knots, rows, 1);
	}
	return t31_wdr_fusion_curve(out, points);
}

static inline int t31_wdr_fusion_ev(u32 *out, u32 value, const u32 *knots,
		const u32 *gamma, const u32 *const table[5], u32 *top, u32 block_mode)
{
	u32 i, row = 8, x, start, step, next;
	if (gamma[0] == 2 && block_mode != 1)
		return t31_wdr_fusion_table(out, value, knots, table);
	if (gamma[0] != 1)
		return 0;
	for (i = 0; i < 9; ++i)
		if (value <= knots[i]) { row = i; break; }
	x = t31_wdr_ev_interp(value, knots, gamma + 1, 3);
	if (x >= 32)
		return -ERANGE;
	/* Only x is interpolated in mode 1; y uses the selected upper row. */
	start = gamma[row * 3 + 2];
	step = (start - gamma[row * 3 + 3]) / (32 - x);
	next = start;
	for (i = 0; i < 33; ++i) {
		if (i < x)
			next = gamma[31];
		else if (i == x)
			next = start;
		else
			next = out[i - 1] - step;
		out[i] = next > 256 ? 256 : next;
	}
	top[1] = 3;
	return 0;
}

static inline u32 t31_wdr_deghost_weight(struct t31_wdr_ev *ev,
			 u32 short_time, const u32 *xy, const u32 *knots, const u32 *weights)
{
	u32 weight = 0, by_ev, by_change, span, i;
	if (short_time <= xy[20]) {
		weight = weights[0];
		if (short_time > xy[21] && xy[20] > xy[21])
			weight -= (short_time - xy[21]) * weight / (xy[20] - xy[21]);
	}
	if (xy[16] == 1) {
		by_ev = weights[8];
		for (i = 0; i < 9; ++i) {
			if (ev->now > knots[i])
				continue;
			by_ev = weights[i];
			if (i && knots[i] > knots[i - 1]) {
				span = knots[i] - knots[i - 1];
				by_ev = ((weights[i] - weights[i - 1]) * (ev->now - knots[i - 1]) +
					weights[i - 1] * span + span / 2) / span;
			}
			break;
		}
		if (by_ev < weight)
			weight = by_ev;
	}
	if (xy[17] == 1) {
		if (!ev->changed)
			ev->delta = 0;
		by_change = 0;
		if (ev->delta < xy[18]) {
			by_change = 32;
			if (ev->delta >= xy[19] && xy[18] > xy[19]) {
				span = xy[18] - xy[19];
				by_change = ((xy[18] - ev->delta) * 32 + span / 2) / span;
			}
		}
		if (by_change < weight)
			weight = by_change;
	}
	return weight;
}

static inline void t31_wdr_ev_calculate(struct t31_wdr_ev *ev, const u32 *knots,
		const u32 *const values[7], u32 *detail, u32 *top)
{
	u32 i, weight;
	if (ev->changed) {
		for (i = 0; i < 7; ++i)
			ev->output[i] = t31_wdr_ev_interp(ev->old, knots, values[i], 1);
	}
	for (i = 0; i < 5; ++i)
		detail[i] = ev->output[i];
	ev->short_to_long = ev->output[5];
	weight = t31_wdr_max(1025, (s32)ev->output[6]);
	top[4] = 8190;
	top[5] = weight;
	top[6] = 2049;
	top[7] = t31_wdr_min(8191, (weight / 2 + 0x1000000) / weight);
}

/* OEM 0x5f308, descending distance thresholds. */
static inline u32 t31_wdr_distance(s32 x, s32 y, s32 center_x, s32 center_y,
				   const u32 *lut)
{
	s32 i, dx = t31_wdr_abs(x - center_x) / 4;
	s32 dy = t31_wdr_abs(y - center_y) / 4;
	u32 distance = dx * dx + dy * dy;
	for (i = 30; i >= 0; --i)
		if (lut[i] >= distance)
			return i + 1;
	return 0;
}

typedef void (*t31_wdr_reg_write)(void *context, u32 reg, u32 value);

static inline int t31_wdr_spatial(u32 output[5][32], u32 distance[31],
				u32 width, u32 height, u32 radius,
				struct t31_wdr_spatial_workspace *workspace)
{
	static const u32 distance_q16[31] = {
		33809, 24810, 20625, 17869, 15810, 14166, 12797, 11625,
		10600, 9689, 8869, 8124, 7440, 6810, 6225, 5678, 5166,
		4684, 4229, 3798, 3388, 2998, 2625, 2269, 1928, 1600,
		1285, 981, 689, 406, 133
	};
	u32 (*count)[32] = workspace->count, (*sum)[32] = workspace->sum;
	u32 bw = (width + 8) / 16, bh = (height + 5) / 10;
	u32 x, y, i, j, bin, n, group, index[8];
	s32 cx = bw + (bw + 1) / 2, cy = bh + (bh + 1) / 2;
	static const u32 groups[5] = {2, 1, 0, 0, 0};
	if (!bw || !bh || width > 4095 || height > 4095 || radius > 4095)
		return -ERANGE;
	memset(workspace, 0, sizeof(*workspace));
	for (i = 0; i < 31; ++i)
		distance[i] = ((u64)distance_q16[i] * radius * radius + 32768) >> 16;
	for (y = 2 * bh; y <= 3 * bh; ++y)
		for (x = 2 * bw; x <= 3 * bw; ++x) {
			index[0] = t31_wdr_distance(y, x, cy, cx, distance);
			index[1] = t31_wdr_distance(y, x, cy - bh, cx - bw, distance);
			index[2] = t31_wdr_distance(y, x, cy, cx - bw, distance);
			index[3] = t31_wdr_distance(y, x, cy - bh, cx, distance);
			index[4] = t31_wdr_distance(y, x, cy + bh, cx, distance);
			index[5] = t31_wdr_distance(y, x, cy + bh, cx - bw, distance);
			index[6] = t31_wdr_distance(y, x, cy, cx + bw, distance);
			index[7] = t31_wdr_distance(y, x, cy - bh, cx + bw, distance);
			++count[0][index[0]];
			++count[1][index[4]];
			++count[2][index[6]];
			sum[3][index[0]] += index[1];
			sum[2][index[0]] += index[2];
			sum[4][index[0]] += index[3];
			sum[1][index[4]] += index[5];
			sum[0][index[6]] += index[7];
		}
	for (j = 0; j < 5; ++j) {
		group = groups[j];
		for (bin = 0; bin < 32; ++bin) {
			n = count[group][bin];
			output[j][bin] = n ? (sum[j][bin] + n / 2) / n :
				(bin ? output[j][bin - 1] : 0);
		}
	}
	return 0;
}

static inline void t31_wdr_write_pairs(t31_wdr_reg_write write, void *context,
				 u32 base, const u32 *v, u32 count, u32 mask)
{
	u32 i, value;
	for (i = 0; i < count; i += 2) {
		value = v[i] & mask;
		if (i + 1 < count)
			value |= (v[i + 1] & mask) << 16;
		write(context, base + i * 2, value);
	}
}

/* OEM 0x5da6c: one complete software result, including all 81 RGB map
 * points and all 27 deghost thresholds. Register addresses are ISP offsets. */
static inline void t31_wdr_write_result(t31_wdr_reg_write write, void *context,
		const struct t31_wdr_fpga *p, const u32 *top, const u32 *detail_weight,
		const u32 *fusion, const u32 *deghost)
{
	u32 c, i;
	t31_wdr_write_pairs(write, context, 0x2604, top + 4, 2, 0x1fff);
	t31_wdr_write_pairs(write, context, 0x2608, top + 6, 2, 0x3fff);
	t31_wdr_write_pairs(write, context, 0x24e8, detail_weight, 5, 0x7f);
	t31_wdr_write_pairs(write, context, 0x24a4, fusion, 33, 0x1ff);
	write(context, 0x2040, (deghost[1] & 0xff) | ((deghost[2] & 0x1f) << 8) |
		((deghost[3] & 0xf) << 16) | ((deghost[12] & 0x3f) << 24));
	for (c = 0; c < 3; ++c)
		t31_wdr_write_pairs(write, context, 0x2050 + c * 0xa4, p->map[c], 81, 0xfff);
	t31_wdr_write_pairs(write, context, 0x2274, p->label_bits, 26, 0xf);
	t31_wdr_write_pairs(write, context, 0x22a8, p->all, 27, 0x7ff);
	for (i = 0; i < 27; ++i)
		write(context, 0x22e0 + i * 4, p->range[i] & 0x1ffff);
	for (c = 0; c < 3; ++c)
		t31_wdr_write_pairs(write, context, 0x2614 + c * 4, p->detail + c * 3, 2, 0xfff);
	for (c = 0; c < 3; ++c)
		write(context, 0x2620 + c * 4, p->detail[c * 3 + 2] & 0x7ffff);
}

#endif
