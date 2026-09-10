/* SPDX-License-Identifier: GPL-2.0 */
#ifndef TX_ISP_T31_WDR_MATH_H
#define TX_ISP_T31_WDR_MATH_H

#include "tx_isp_t31_wdr.h"

/* The OEM routine takes thirty pointers in the MIPS o32 ABI. Keep the
 * complete contract explicit instead of depending on adjacent globals. */
struct t31_wdr_fpga {
	u32 *model, *deviation, *ratio, *x, *y, *threshold, *xy, *motion;
	u32 *normal, *normal1, *normal2, *minimum, *secondary, *low, *high;
	const u32 *hist[2][3];
	u32 *map[3], *labels, *label_bits, *all, *range, *detail_in, *detail;
};

/* Scratch is owned by the WDR instance, never allocated on the kernel's
 * small stack or aliased to another algorithm's statistics. */
struct t31_wdr_spatial_workspace {
	u32 count[3][32], sum[5][32];
};

struct t31_wdr_scratch {
	union {
		u32 cdf[2][3][256];
		struct t31_wdr_spatial_workspace spatial;
	};
	u32 index[3][256];
	u32 dense[3][256];
	u32 old[3][81];
};

static inline s32 t31_wdr_min(s32 a, s32 b) { return a < b ? a : b; }
static inline s32 t31_wdr_max(s32 a, s32 b) { return a > b ? a : b; }
static inline s32 t31_wdr_abs(s32 a) { return a < 0 ? -a : a; }
static inline s32 t31_wdr_clip(s32 v, s32 lo, s32 hi)
{
	return t31_wdr_min(t31_wdr_max(v, lo), hi);
}

/* MIPS consumes the low product word before signed division. Express the
 * wrap in unsigned C so overflow has the same result under optimization. */
static inline s32 t31_wdr_mad(s32 a, s32 b, s32 c, s32 d, s32 round)
{
	return (s32)((u32)a * (u32)b + (u32)c * (u32)d + (u32)round);
}

static inline s32 t31_wdr_lerp_signed(s32 x, s32 x0, s32 x1, s32 y0, s32 y1)
{
	s32 span = x1 - x0;
	if (!span)
		return y1;
	return t31_wdr_mad(y0, span, y1 - y0, x - x0, span / 2) / span;
}

static inline u32 t31_wdr_log2(u32 value)
{
	u32 bits = 0;
	while (bits < 11 && value > (1U << bits))
		++bits;
	return bits;
}

/* OEM 0x1f5e0: variance of the centered map derivative below code 200. */
static inline s32 t31_wdr_variance(const u32 *map)
{
	s32 count = 0, sum = 0, variance = 0, center, delta;
	u32 i;
	for (i = 1; i < 255; ++i) {
		if (map[i] >= 200 || map[i + 1] >= 200)
			continue;
		sum += ((s32)map[i + 1] - (s32)map[i - 1] + 1) / 2;
		++count;
	}
	if (!count)
		return 0;
	for (i = 1; i <= (u32)count; ++i) {
		center = ((s32)map[i + 1] - (s32)map[i - 1] + 1) / 2;
		delta = center * 10 - (sum * 10 + count / 2) / count;
		variance = t31_wdr_mad(delta, delta, 1, variance, 0);
	}
	return (variance + count / 2) / count;
}

static inline int t31_wdr_detail(u32 *out, const u32 *p, const u32 *map)
{
	s32 means[2][2], begin, end, sample, mapped, sum_x, sum_y, count, span;
	u32 n, i;
	for (n = 0; n < 2; ++n) {
		begin = (s32)p[n * 3] - (s32)p[n * 3 + 2];
		end = (s32)p[n * 3] + (s32)p[n * 3 + 1];
		if (begin < 0 || end > 4095 || begin > end)
			return -ERANGE;
		sum_x = sum_y = 0;
		count = end - begin + 1;
		for (sample = begin; sample <= end; ++sample) {
			mapped = map[255];
			for (i = 1; i < 256; ++i) {
				s32 x = (i + 1) * 16 - 1;
				if (sample < x) {
					s32 difference = (s32)map[i] - (s32)map[i - 1];
					s32 product = t31_wdr_mad(difference * 4096,
						x - sample, 0, 0, 8);
					mapped = ((s32)(map[i] * 4096) - product / 16 + 2048) / 4096;
					break;
				}
			}
			sum_x += sample;
			sum_y += mapped;
		}
		means[n][0] = (sum_x + count / 2) / count;
		means[n][1] = (sum_y + count / 2) / count;
	}
	span = means[1][0] - means[0][0];
	if (!span)
		return -EINVAL;
	out[0] = means[0][0];
	out[1] = means[0][1];
	out[2] = t31_wdr_mad(means[1][1] - means[0][1], 4096, 0, 0, span / 2) / span;
	return 0;
}

static inline void t31_wdr_histogram_map(struct t31_wdr_fpga *p,
				       struct t31_wdr_scratch *s, u32 channel)
{
	u32 i, j, exposure, selected, distance, best;
	for (exposure = 0; exposure < 2; ++exposure) {
		u32 sum = 0;
		for (i = 0; i < 256; ++i) {
			sum += p->hist[exposure][channel][i];
			s->cdf[exposure][channel][i] = sum;
		}
	}
	for (i = 0; i < 256; ++i) {
		const u32 *long_cdf = s->cdf[0][channel];
		u32 target = s->cdf[1][channel][i];
		selected = i + 1;
		if (p->model[0]) {
			best = t31_wdr_abs((s32)long_cdf[i] - (s32)target);
			for (j = 1; j < 256; ++j) {
				distance = t31_wdr_abs((s32)long_cdf[j] - (s32)target);
				if (distance < best) {
					best = distance;
					selected = t31_wdr_max(j + 1, i + 1);
				}
			}
		} else {
			for (j = 0; j < 255; ++j)
				if (long_cdf[j] < target && long_cdf[j + 1] >= target) {
					selected = t31_wdr_max(j + 1, i + 1);
					break;
				}
		}
		s->index[channel][i] = selected;
		s->dense[channel][i] = selected * 16 - 1;
	}
	memcpy(s->old[channel], p->map[channel], sizeof(s->old[channel]));
	p->map[channel][1] = s->dense[channel][0];
	for (i = 1; i < 80; ++i) {
		j = i < 16 ? i : (i < 24 ? 2 * i - 15 : 4 * i - 61);
		p->map[channel][i + 1] = s->dense[channel][j];
	}
}

/* OEM 0x1f894. Malformed calibration must not cause a kernel divide trap
 * or an unbounded histogram walk. The caller commits registers only on success. */
static inline int t31_wdr_fpga_calculate(struct t31_wdr_fpga *p,
				       struct t31_wdr_scratch *s)
{
	s32 *d = (s32 *)p->deviation, *r = (s32 *)p->ratio;
	s32 *x = (s32 *)p->x, *y = (s32 *)p->y, *t = (s32 *)p->threshold;
	s32 *xy = (s32 *)p->xy, *m = (s32 *)p->motion;
	s32 variance = 0, blend = 0, deviation, max_deviation = d[0];
	s32 flag = 0, ratio, sign, base, limit, dark, shape, a, b, value;
	u32 c, i;
	if (r[0] <= 0 || x[0] >= x[1] || x[1] >= x[2] || x[2] >= x[3] ||
	    !t[1] || !t[3] || !t[7] || !t[13] || !m[9] || !m[11] ||
	    xy[0] == xy[1] || d[1] < 1 || d[1] > 127 || d[2] > 128 ||
	    m[12] > 26 || (p->model[1] == 1 && m[15] == m[16]))
		return -EINVAL;
	for (i = 0; i < 26; ++i)
		if (p->labels[i + 1] <= p->labels[i])
			return -EINVAL;
	for (c = 0; c < 3; ++c) {
		t31_wdr_histogram_map(p, s, c);
		if (t31_wdr_detail(p->detail + c * 3, p->detail_in, s->dense[c]))
			return -EINVAL;
		variance += t31_wdr_variance(s->index[c]);
	}
	variance /= 3;
	if (xy[12] == 1 && variance >= xy[4]) {
		/* The OEM's lower interpolation ordinate is xy[5], not xy[6]. */
		blend = variance >= xy[5] ? xy[7] :
			t31_wdr_lerp_signed(variance, xy[4], xy[5], xy[5], xy[5] + xy[7] - xy[6]);
		for (c = 0; c < 3; ++c)
			for (i = 1; i < 81; ++i)
				p->map[c][i] = t31_wdr_mad(16 - blend, p->map[c][i],
					blend, s->old[c][i], 8) / 16;
	}
	if (xy[13] == 1 && variance >= xy[8])
		xy[14] = variance >= xy[9] ? xy[11] :
			t31_wdr_lerp_signed(variance, xy[8], xy[9], xy[10], xy[11]);
	for (c = 0; c < 3; ++c)
		p->map[c][0] = t31_wdr_max(0, t31_wdr_mad(p->map[c][2] - p->map[c][1],
			-15, p->map[c][1], 16, 8) / 16);
	for (i = 1; i < (u32)d[2]; ++i) {
		for (c = 0; c < 3; ++c)
			if (s->index[c][i] > (u32)xy[15])
				goto deviation_done;
		a = t31_wdr_max(0, (s32)i - d[1]);
		b = t31_wdr_min(255, i + d[1]);
		while (b > (s32)i && (s->index[0][b] > (u32)xy[15] ||
		       s->index[1][b] > (u32)xy[15] || s->index[2][b] > (u32)xy[15]))
			--b;
		for (c = 0; c < 3; ++c) {
			value = t31_wdr_lerp_signed(i, a, b, s->index[c][a], s->index[c][b]);
			deviation = t31_wdr_abs((s32)s->index[c][i] - value);
			if (deviation > d[3])
				flag = 1;
			max_deviation = t31_wdr_max(max_deviation, deviation);
		}
	}
deviation_done:
	ratio = t31_wdr_mad(r[1], 128, 0, 0, r[0] / 2) / r[0];
	sign = ratio >= r[2] ? 1 : -1;
	if (ratio < r[3])
		flag = 2;
	if (xy[12] == 1 && blend >= 9)
		flag = 0;
	base = t[16];
	if (r[0] <= x[1]) {
		value = t31_wdr_lerp_signed(r[0], x[0], x[1], y[0], y[1]);
		base = (t31_wdr_mad((t[0] * 8 - r[0]) * 4, ratio, 0, 0,
			t[1] / 2) / t[1] + value * 4096 + 4) / 8;
	} else if (r[0] <= x[2]) {
		value = t31_wdr_lerp_signed(r[0], x[1], x[2], y[1], y[2]);
		base = (t31_wdr_mad(-3 * x[1] + t[2] * 16 + r[0], ratio * 4,
			0, 0, t[3] / 2) / t[3] + value * 8192 + 8) / 16;
	} else if (r[0] <= t[14]) {
		value = t31_wdr_lerp_signed(r[0], x[2], x[3], y[2], y[3]);
		base = t31_wdr_mad(ratio * 4, t[4], value, 512, 0);
	} else if (r[0] <= t[15]) {
		value = (r[0] - t[6] + t[7] / 2) / t[7] + t[5];
		base = t31_wdr_mad(t[11] * 4, ratio, value, 512, 0);
	}
	if (p->model[3] >= 2) {
		for (i = 0; i < 27; ++i)
			p->range[i] = p->all[i] ? ((s32)p->all[i] / 2 + m[1] * 16384) / (s32)p->all[i] : 65536;
		return 0;
	}
	if (p->model[3] == 1) {
		for (i = 0; i < 26; ++i) {
			value = p->labels[i + 1] - p->labels[i];
			p->normal[i] = p->minimum[i] = p->low[i] = p->high[i] = value;
			p->secondary[i] = t31_wdr_mad(m[10], value, 0, 0, m[11] / 2) / m[11];
			if (i >= 2 && i < (u32)m[12])
				p->high[i] = t31_wdr_mad(m[8], value, 0, 0, m[9] / 2) / m[9];
		}
		p->low[0] = p->low[1] = m[6];
		p->high[0] = p->high[1] = m[7];
	}
	for (i = 0; i < 26; ++i) {
		if (p->model[1] == 1)
			p->normal[i] = r[0] <= m[15] ? p->normal1[i] : r[0] > m[16] ? p->normal2[i] :
				(u32)t31_wdr_lerp_signed(r[0], m[15], m[16], p->normal1[i], p->normal2[i]);
		else if (p->model[1] == 2)
			p->normal[i] = p->minimum[i];
	}
	base = t31_wdr_max(0, (t31_wdr_mad(sign * 4,
		t31_wdr_abs(ratio - t[13] * 128), 0, 0, t[13] / 2) / t[13] + base + 64) / 128);
	value = (s->cdf[1][1][0] + s->cdf[1][1][1] + s->cdf[1][1][2] + s->cdf[1][1][3] + 1024) / 2048;
	dark = t31_wdr_min(m[0], t31_wdr_lerp_signed(value, xy[0], xy[1], xy[2], xy[3]));
	limit = base < m[2] ? m[3] : m[4];
	shape = m[5] + (ratio <= r[5] ? (ratio > r[4] ? 2 : 0) : (ratio <= r[6] ? 1 : 0));
	for (i = 0; i < 26; ++i) {
		if (i < 2)
			value = t31_wdr_clip(base - (3 - i) * dark, 0, 1200);
		else if (!p->model[2])
			value = t31_wdr_min(p->all[i] + p->normal[i], i < 4 ? 1200 : limit);
		else if (i <= (u32)m[13])
			value = t31_wdr_min((t[17] + 1 + i) * i + base, 1200);
		else if (i <= (u32)m[14])
			value = t31_wdr_min(t[18] - t[17] + base + t[17] + 1 + i, limit);
		else {
			a = (1 - shape + i) * t[19];
			value = t31_wdr_min((a + 4) * (a - 1) + base, limit);
		}
		p->all[i + 1] = value;
	}
	p->normal[0] = p->all[1];
	for (i = 1; i < 26; ++i)
		p->normal[i] = p->all[i + 1] - p->all[i];
	for (i = 0; i < 26; ++i) {
		if (flag == 1) {
			value = p->high[i];
			if (max_deviation < d[4]) {
				value = t31_wdr_lerp_signed(max_deviation, d[3], d[4], p->low[i], p->high[i]);
				p->minimum[i] = value;
			}
			value = i < 2 ? t31_wdr_min(base + (i + 1) * value, 1200) :
				t31_wdr_min(p->all[i] + value, limit);
		} else if (i < 2)
			value = t31_wdr_clip(base - (3 - i) * dark, 0, 1200);
		else
			value = t31_wdr_min(p->all[i] + (flag ? p->secondary[i] : p->normal[i]), limit);
		p->all[i + 1] = value;
		p->range[i + 1] = value ? (value / 2 + m[1] * 16384) / value : 65536;
		p->label_bits[i] = t31_wdr_log2(p->labels[i + 1] - p->labels[i]);
	}
	a = p->labels[2] - p->labels[1];
	p->all[0] = t31_wdr_max(0, t31_wdr_mad(p->all[1], a,
		-(s32)(p->all[2] - p->all[1]), p->labels[1], a / 2) / a);
	p->range[0] = t31_wdr_min(65536, t31_wdr_mad(p->range[1], a,
		-(s32)(p->range[2] - p->range[1]), p->labels[1], a / 2) / a);
	return 0;
}

#endif
