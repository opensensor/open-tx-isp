/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AE API on the frame-3A AE (2026-10-26, T40-AE-API).
 *
 * Exposure on T40 is the driver's frame-3A AE (regtrace_frame_3a_sample, the
 * ae_soft_* state); the lifted OEM AE is gone (next 5250c218).  This header
 * holds the plain-data part of the vendor T40 1.3.1 AE tuning calls so the
 * driver serves them from that AE and the host test (tests/
 * tx_isp_t40_ae_api_test.c) checks them:
 *
 *   wire layouts (MIPS o32, vendor imp_isp.h 1.3.1):
 *     IMPISPAEExprInfo 220 bytes   TotalGainDb @204, ExposureValue @212 (u32),
 *                                  EVLog2 @216 (the T41 1.2 layout is 232
 *                                  bytes with a u64 exposure @216; packing
 *                                  that one overran the T40 caller by 12)
 *     IMPISPAEScenceAttr 52 bytes  luma @32, luma_scence @36, stable @40 (u8),
 *                                  target @44, ae_mean @48
 *     IMPISPAEStatisInfo 1934 bytes hist5 u16[5] @0, hist256 u32[256] @10,
 *                                  zones u32[15][15] @1034
 *     IMPISPAEWeightAttr 460, IMPISPFaceAttr 24, IMPISPAeSpeedAttr 4,
 *     IMPISPAeExpListAttr 324, IMPISPStatisConfig 124 (AE histThresh @20)
 *
 *   OEM arithmetic (Eufy tx-isp-t40.ko, SDK 1.3.1 libt40-firmware.a):
 *     tisp_ae_main_long_process_api: 256-bin histogram = hardware bins << 2
 *       (bins count 2x2 quads), bin 0 = width * height - sum of bins 1..255;
 *       5-bin histogram over the four histThresh limits, bins 1..4 =
 *       count * 65535 / total, bin 0 = 65535 - (bins 1..4), all-zero input
 *       gives {65535, 0, 0, 0, 0};
 *     tisp_ae_long_weight_mean2: zone Y = (sum0 + sum1 + sum2) / (row height
 *       * column width) of the 15x15 AE zone statistics;
 *     tisp_ae_s_comp: target factor (128 = 1.0) = comp for comp <= 128,
 *       else 128 + comp * 300 / 127 - 302 (255 -> 3.34x);
 *     tisp_s_ae_scence_attr / tisp_g_ae_scence_attr: AeTargetCompEn 1
 *       (DISABLE) resets the compensation to 128, 2/3 (ROI/GLOBAL) set it,
 *       0 (AUTO) keeps it; the getter reports 1 for 128 and 3 otherwise.
 */
#ifndef TX_ISP_T40_AE_API_H
#define TX_ISP_T40_AE_API_H

#ifdef __KERNEL__
#include <linux/types.h>
#include <linux/errno.h>
#include <linux/string.h>
#include <linux/math64.h>
#define t40_ae_div64(a, b) div64_u64((a), (b))
#else
#include <stdint.h>
#include <stdbool.h>
#include <errno.h>
#include <string.h>
typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
#define t40_ae_div64(a, b) ((u64)(a) / (u64)(b))
#endif

#define T40_AE_EXPR_BYTES	220U
#define T40_AE_SCENCE_BYTES	52U
#define T40_AE_STATS_BYTES	1934U
#define T40_AE_STATS_HIST5	0U
#define T40_AE_STATS_HIST256	10U
#define T40_AE_STATS_ZONES	1034U
#define T40_AE_BINS		256U
#define T40_AE_ZONE_N		15U
#define T40_AE_ZONES		225U
#define T40_AE_WEIGHT_BYTES	460U
#define T40_AE_FACE_BYTES	24U
#define T40_AE_SPEED_BYTES	4U
#define T40_AE_EXPLIST_BYTES	324U
#define T40_AE_COMP_NEUTRAL	128U
#define T40_AE_SPEED_NEUTRAL	128U

/* IMPISPAEScenceMode / IMPISPTuningOpsType values */
#define T40_AE_SC_AUTO		0U
#define T40_AE_SC_DISABLE	1U
#define T40_AE_SC_ROI		2U
#define T40_AE_SC_GLOBAL	3U
#define T40_OPS_AUTO		0U
#define T40_OPS_MANUAL		1U

static inline u32 t40_ae_ld32(const u8 *b, unsigned int off)
{
	u32 v;

	memcpy(&v, b + off, sizeof(v));
	return v;
}

static inline void t40_ae_st32(u8 *b, unsigned int off, u32 v)
{
	memcpy(b + off, &v, sizeof(v));
}

static inline void t40_ae_st16(u8 *b, unsigned int off, u16 v)
{
	memcpy(b + off, &v, sizeof(v));
}

/* ---------------- AeTargetComp (OEM tisp_ae_s_comp) ---------------- */

/* Target factor, 128 = 1.0. */
static inline u32 t40_ae_comp_factor(u32 comp)
{
	if (comp > 255U)
		comp = 255U;
	if (comp <= 128U)
		return comp;
	return 128U + comp * 300U / 127U - 302U;
}

/* Luma target for the frame AE: base * factor / 128, clamped to [lo, hi]. */
static inline u32 t40_ae_comp_target(u32 base, u32 comp, u32 lo, u32 hi)
{
	u32 t = (u32)(((u64)base * t40_ae_comp_factor(comp)) >> 7);

	if (t < lo)
		t = lo;
	if (t > hi)
		t = hi;
	return t;
}

/* ---------------- IMPISPAEScenceAttr ---------------- */

struct t40_ae_scence {
	u32 hlc_en, hlc_str;		/* AeHLCEn, AeHLCStrength 0..10 */
	u32 blc_en, blc_str;		/* AeBLCEn, AeBLCStrength 0..10 */
	u32 comp;			/* AeTargetComp now in effect, 128 neutral */
	u32 start_en, start_ev;		/* AeStartEn, AeStartEv (stored) */
};

static inline void t40_ae_scence_defaults(struct t40_ae_scence *s)
{
	memset(s, 0, sizeof(*s));
	s->hlc_en = T40_AE_SC_DISABLE;
	s->blc_en = T40_AE_SC_DISABLE;
	s->comp = T40_AE_COMP_NEUTRAL;
	s->start_en = T40_AE_SC_DISABLE;
}

/*
 * SET.  Modes >= IMP_ISP_AE_SCENCE_BUTT and strengths > 10 are rejected
 * (-EINVAL, nothing changed).  HLC / BLC: AUTO keeps the current setting,
 * DISABLE switches off, ROI / GLOBAL switch on with the strength.
 * AeTargetComp as the OEM: DISABLE -> 128, ROI / GLOBAL -> comp (0..255),
 * AUTO -> unchanged.
 */
static inline int t40_ae_scence_parse(const u8 *in, struct t40_ae_scence *s)
{
	u32 hlc = t40_ae_ld32(in, 0), blc = t40_ae_ld32(in, 8);
	u32 cen = t40_ae_ld32(in, 16), comp = t40_ae_ld32(in, 20);
	u32 sen = t40_ae_ld32(in, 24);
	u8 hs = in[4], bs = in[12];

	if (hlc > T40_AE_SC_GLOBAL || blc > T40_AE_SC_GLOBAL ||
	    cen > T40_AE_SC_GLOBAL || sen > T40_AE_SC_GLOBAL)
		return -EINVAL;
	if ((hlc >= T40_AE_SC_ROI && hs > 10U) ||
	    (blc >= T40_AE_SC_ROI && bs > 10U) ||
	    (cen >= T40_AE_SC_ROI && comp > 255U))
		return -EINVAL;
	if (hlc != T40_AE_SC_AUTO) {
		s->hlc_en = hlc;
		s->hlc_str = hlc >= T40_AE_SC_ROI ? hs : 0U;
	}
	if (blc != T40_AE_SC_AUTO) {
		s->blc_en = blc;
		s->blc_str = blc >= T40_AE_SC_ROI ? bs : 0U;
	}
	if (cen == T40_AE_SC_DISABLE)
		s->comp = T40_AE_COMP_NEUTRAL;
	else if (cen >= T40_AE_SC_ROI)
		s->comp = comp;
	if (sen != T40_AE_SC_AUTO) {
		s->start_en = sen;
		s->start_ev = t40_ae_ld32(in, 28);
	}
	return 0;
}

static inline void t40_ae_scence_pack(u8 *out, const struct t40_ae_scence *s,
				      u32 luma, u32 luma_scence, u32 stable,
				      u32 target, u32 ae_mean)
{
	memset(out, 0, T40_AE_SCENCE_BYTES);
	t40_ae_st32(out, 0, s->hlc_en);
	out[4] = (u8)s->hlc_str;
	t40_ae_st32(out, 8, s->blc_en);
	out[12] = (u8)s->blc_str;
	t40_ae_st32(out, 16, s->comp == T40_AE_COMP_NEUTRAL ?
		    T40_AE_SC_DISABLE : T40_AE_SC_GLOBAL);
	t40_ae_st32(out, 20, s->comp);
	t40_ae_st32(out, 24, s->start_en);
	t40_ae_st32(out, 28, s->start_ev);
	t40_ae_st32(out, 32, luma);
	t40_ae_st32(out, 36, luma_scence);
	out[40] = stable ? 1U : 0U;
	t40_ae_st32(out, 44, target);
	t40_ae_st32(out, 48, ae_mean);
}

/* ---------------- IMPISPAEStatisInfo ---------------- */

/*
 * Histogram scaled to pixels: out[i] = raw[i] * mul / div for i >= 1,
 * out[0] = total - sum(out[1..255]) (raw[0] * mul / div when that would be
 * negative or total is 0).  Hardware bins: mul 4, div 1 (OEM << 2).
 */
static inline void t40_ae_hist_scale(const u32 *raw, u32 mul, u32 div,
				     u32 total, u32 *out)
{
	u64 sum = 0;
	unsigned int i;

	if (!div)
		div = 1;
	for (i = 1; i < T40_AE_BINS; i++) {
		out[i] = (u32)t40_ae_div64((u64)raw[i] * mul, div);
		sum += out[i];
	}
	if (total && sum <= total)
		out[0] = total - (u32)sum;
	else
		out[0] = (u32)t40_ae_div64((u64)raw[0] * mul, div);
}

static inline u64 t40_ae_hist_range(const u32 *hist, u32 lo, u32 hi)
{
	u64 sum = 0;

	for (; lo < hi && lo < T40_AE_BINS; lo++)
		sum += hist[lo];
	return sum;
}

/*
 * OEM 5-bin histogram: bin k sums [thr[k-1], thr[k]) (thr[-1] = 0, thr[4] =
 * 256; a limit below the previous one leaves that bin empty, as the OEM
 * loops do), normalised to 65535.
 */
static inline void t40_ae_hist5(const u32 *hist, const u8 *thr, u16 *out5)
{
	u64 b[5];
	u64 total;
	u32 rest;
	unsigned int k;

	b[0] = t40_ae_hist_range(hist, 0, thr[0]);
	b[1] = t40_ae_hist_range(hist, thr[0], thr[1]);
	b[2] = t40_ae_hist_range(hist, thr[1], thr[2]);
	b[3] = t40_ae_hist_range(hist, thr[2], thr[3]);
	b[4] = t40_ae_hist_range(hist, thr[3], T40_AE_BINS);
	total = b[0] + b[1] + b[2] + b[3] + b[4];
	if (!total) {
		out5[0] = 0xffffU;
		out5[1] = out5[2] = out5[3] = out5[4] = 0;
		return;
	}
	rest = 0xffffU;
	for (k = 1; k < 5; k++) {
		u32 v = (u32)t40_ae_div64(b[k] * 0xffffU, total);

		out5[k] = (u16)v;
		rest -= v;
	}
	out5[0] = (u16)rest;
}

static inline void t40_ae_stats_pack(u8 *out, const u32 *hist256,
				     const u8 *thr, const u32 *zones)
{
	u16 h5[5];
	unsigned int i;

	memset(out, 0, T40_AE_STATS_BYTES);
	t40_ae_hist5(hist256, thr, h5);
	for (i = 0; i < 5; i++)
		t40_ae_st16(out, T40_AE_STATS_HIST5 + 2U * i, h5[i]);
	for (i = 0; i < T40_AE_BINS; i++)
		t40_ae_st32(out, T40_AE_STATS_HIST256 + 4U * i, hist256[i]);
	for (i = 0; i < T40_AE_ZONES; i++)
		t40_ae_st32(out, T40_AE_STATS_ZONES + 4U * i, zones[i]);
}

/*
 * Zone Y of the hardware AE statistics (OEM tisp_ae_long_weight_mean2):
 * s0/s1/s2 are the three sum planes (u32, 15-word row stride), rowh[r] and
 * colw[c] the zone geometry (u16 at table +38 and +8).
 */
static inline void t40_ae_hw_zones(const u32 *s0, const u32 *s1, const u32 *s2,
				   const u16 *rowh, const u16 *colw,
				   u32 rows, u32 cols, u32 *zones)
{
	u32 r, c;

	memset(zones, 0, T40_AE_ZONES * sizeof(u32));
	if (rows > T40_AE_ZONE_N)
		rows = T40_AE_ZONE_N;
	if (cols > T40_AE_ZONE_N)
		cols = T40_AE_ZONE_N;
	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			u32 z = r * T40_AE_ZONE_N + c;
			u32 area = (u32)rowh[r] * colw[c];
			u64 s = (u64)s0[z] + s1[z] + s2[z];

			zones[z] = area ? (u32)t40_ae_div64(s, area) : 0U;
		}
}

/* ---------------- metering ---------------- */

struct t40_ae_meter_in {
	const u32 *zone_mean;		/* 225 zone means of the sampled frame */
	const u8 *weight;		/* 225 user weights 0..8, NULL = none */
	u32 hlc_str, blc_str;		/* 0 = off */
	u32 face_on;			/* face zones [fx0, fx1) x [fy0, fy1) */
	u32 fx0, fx1, fy0, fy1;
};

/*
 * Metered luma for the frame AE.  Returns 0 when nothing is configured (the
 * caller keeps the plain sampled mean, i.e. the tuned default behaviour).
 * Face AE meters the face zones only; user weights scale each zone; BLC
 * adds strength x weight to zones darker than the weighted mean (the AE
 * brightens a dark subject), HLC to zones brighter than it (the AE darkens
 * highlights).  Strength 10 = 11x weight of the selected zones.
 */
static inline u32 t40_ae_meter(const struct t40_ae_meter_in *m)
{
	u32 w[T40_AE_ZONES];
	u64 sw = 0, swm = 0;
	u32 mean, z;

	if (!m->zone_mean ||
	    (!m->weight && !m->hlc_str && !m->blc_str && !m->face_on))
		return 0;
	for (z = 0; z < T40_AE_ZONES; z++) {
		u32 x = z % T40_AE_ZONE_N, y = z / T40_AE_ZONE_N;

		w[z] = m->weight ? m->weight[z] : 1U;
		if (m->face_on && (x < m->fx0 || x >= m->fx1 ||
				   y < m->fy0 || y >= m->fy1))
			w[z] = 0;
		sw += w[z];
		swm += (u64)w[z] * m->zone_mean[z];
	}
	if (!sw)
		return 0;
	mean = (u32)t40_ae_div64(swm, sw);
	if (m->hlc_str || m->blc_str) {
		sw = 0;
		swm = 0;
		for (z = 0; z < T40_AE_ZONES; z++) {
			u32 v = m->zone_mean[z], ww = w[z];

			if (m->blc_str && v < mean)
				ww += ww * m->blc_str;
			if (m->hlc_str && v > mean)
				ww += ww * m->hlc_str;
			sw += ww;
			swm += (u64)ww * v;
		}
		if (sw)
			mean = (u32)t40_ae_div64(swm, sw);
	}
	return mean ? mean : 1U;
}

/* Face rectangle (pixels of a width x height frame) -> zone bounds. */
static inline int t40_ae_face_zones(u32 left, u32 top, u32 right, u32 bottom,
				    u32 width, u32 height,
				    u32 *x0, u32 *x1, u32 *y0, u32 *y1)
{
	if (!width || !height || right <= left || bottom <= top ||
	    right > width || bottom > height)
		return -EINVAL;
	*x0 = left * T40_AE_ZONE_N / width;
	*y0 = top * T40_AE_ZONE_N / height;
	*x1 = (right * T40_AE_ZONE_N + width - 1U) / width;
	*y1 = (bottom * T40_AE_ZONE_N + height - 1U) / height;
	if (*x1 <= *x0)
		*x1 = *x0 + 1U;
	if (*y1 <= *y0)
		*y1 = *y0 + 1U;
	return 0;
}

/* ---------------- antiflicker ---------------- */

/* Integration lines of one half mains period (0 = antiflicker unusable). */
static inline u32 t40_ae_af_lines(u32 lines_per_s, u32 freq)
{
	if (!freq || !lines_per_s)
		return 0;
	return lines_per_s / (2U * freq);
}

/* Highest multiple of the flicker step not above it (it when it < step). */
static inline u32 t40_ae_af_floor(u32 it, u32 step)
{
	if (!step || it < step)
		return it;
	return it - it % step;
}

/* log2(num / den) in 16.16 for num >= den > 0 (0 otherwise). */
static inline u32 t40_ae_log2_ratio(u32 num, u32 den)
{
	u64 x;
	u32 r = 0, bit;

	if (!den || num <= den)
		return 0;
	x = t40_ae_div64((u64)num << 30, den);	/* Q30 */
	while (x >= (2ULL << 30)) {
		x >>= 1;
		r += 1U << 16;
	}
	for (bit = 1U << 15; bit; bit >>= 1) {
		x = (x * x) >> 30;		/* x < 2^31: no overflow */
		if (x >= (2ULL << 30)) {
			x >>= 1;
			r |= bit;
		}
	}
	return r;
}

/*
 * #211: an antiflicker integration step traded against the sensor analog
 * gain.  The OEM allocator (vendor tx-isp-t40.ko tisp_ae_long_tune2
 * 0x35b58, deflicker ladder branch) sets the integration time to the
 * highest ladder entry not above the wanted exposure and the analog gain to
 * exposure / time, so a move to another rung keeps the exposure value
 * continuous and the gain fills the remainder.  The frame AE moves one rung
 * per sample; this returns the gain index that keeps the exposure as close
 * as whole gain indices allow without crossing the old value: new_it < it
 * raises the gain by at most it / new_it (exposure ends <= old), new_it > it
 * lowers it by at most new_it / it (exposure ends >= old).  log2_gain gives
 * the 16.16 log2 gain of an index; lo / hi bound the index.
 */
#define T40_AE_AGAIN_LADDER_MAX	25U

static inline u32 t40_ae_af_trade_again(u32 it, u32 new_it, u32 again,
					u32 lo, u32 hi,
					u32 (*log2_gain)(u32 idx))
{
	u32 room, g0;

	if (!it || !new_it || it == new_it || !log2_gain)
		return again;
	/* Opus review C3 (2026-11-06): the gain ladder has 26 indices (0..25) and log2_gain()
	 * clamps above it, so an unclamped hi (module parameter) would let the loop run to hi. */
	if (hi > T40_AE_AGAIN_LADDER_MAX)
		hi = T40_AE_AGAIN_LADDER_MAX;
	if (again > hi)
		again = hi;
	g0 = log2_gain(again);
	if (new_it < it) {
		room = t40_ae_log2_ratio(it, new_it);
		while (again < hi && log2_gain(again + 1U) - g0 <= room)
			again++;
	} else {
		room = t40_ae_log2_ratio(new_it, it);
		while (again > lo && g0 - log2_gain(again - 1U) <= room)
			again--;
	}
	return again;
}

/*
 * #219 C1: the per-index log2 gain the SENSOR applies (its alloc_again floors the ladder value to its own table; the
 * OEM AE likewise works with the gain alloc_again returns, tisp_ae_long_tune2 l.722 + the sensor allocation), cached
 * for the frame AE: refilled when key (alloc_again pointer / enable) changes or after `period` lookups, so a rung
 * trade costs array reads, not up to 26 alloc_again table walks.  sensor_log2 must be monotonic in idx like the
 * ladder (a floor of a rising ladder is).
 */
struct t40_ae_gain_cache {
	u32 key, uses, valid;
	u32 g[T40_AE_AGAIN_LADDER_MAX + 1U];
};

static inline void t40_ae_gain_cache_sync(struct t40_ae_gain_cache *c, u32 key, u32 period,
					  u32 (*sensor_log2)(u32 idx))
{
	u32 i;

	if (c->valid && c->key == key && c->uses < period)
		return;
	for (i = 0; i <= T40_AE_AGAIN_LADDER_MAX; i++)
		c->g[i] = sensor_log2(i);
	for (i = 1; i <= T40_AE_AGAIN_LADDER_MAX; i++)	/* keep it monotonic for the trade loops */
		if (c->g[i] < c->g[i - 1U])
			c->g[i] = c->g[i - 1U];
	c->key = key;
	c->uses = 0;
	c->valid = 1;
}

static inline u32 t40_ae_gain_cache_get(struct t40_ae_gain_cache *c, u32 idx)
{
	c->uses++;
	return c->g[idx > T40_AE_AGAIN_LADDER_MAX ? T40_AE_AGAIN_LADDER_MAX : idx];
}

/*
 * 16.16 log2 of the exposure change of a rung move (it, again) ->
 * (new_it, new_again) traded as above: its magnitude (up for new_it > it,
 * down otherwise).
 */
static inline u32 t40_ae_af_trade_log2(u32 it, u32 new_it, u32 again,
				       u32 new_again,
				       u32 (*log2_gain)(u32 idx))
{
	u32 g = log2_gain ? log2_gain(again) : 0;
	u32 ng = log2_gain ? log2_gain(new_again) : 0;
	u32 l, d;

	if (new_it >= it) {
		l = t40_ae_log2_ratio(new_it, it);
		d = g > ng ? g - ng : 0;
	} else {
		l = t40_ae_log2_ratio(it, new_it);
		d = ng > g ? ng - g : 0;
	}
	return l > d ? l - d : 0;
}

/*
 * Largest Q10 gain d in [1024, 32767] with log2(d / 1024) <= l (16.16):
 * the inverse of t40_ae_log2_ratio (monotonic), rounded down.
 */
static inline u32 t40_ae_q10_exp2_floor(u32 l)
{
	u32 lo = 1024U, hi = 32767U;

	if (l >= 5U << 16)
		return hi;
	while (lo < hi) {
		u32 mid = lo + (hi - lo + 1U) / 2U;

		if (t40_ae_log2_ratio(mid, 1024U) <= l)
			lo = mid;
		else
			hi = mid - 1U;
	}
	return lo;
}

/*
 * #84: the integration ceiling of the OEM deflicker ladder (vendor
 * tx-isp-t40.ko tisp_ae_long_tune2 0x35b58, decomp l.699-721): ladder entries
 * above max_it + 20 lines are dropped, the highest remaining rung is clamped
 * to max_it.  Eufy T40XP 50 Hz: rung 450, max_it 2241 -> 2250 kept -> 2241
 * (the pre-#84 open cap was the rung below max_it, 1800).
 */
#define T40_AE_AF_TOP_SLACK	20U

static inline u32 t40_ae_af_it_cap(u32 max_it, u32 step)
{
	u32 top;

	if (!step || max_it < step)
		return max_it;
	top = t40_ae_af_floor(max_it + T40_AE_AF_TOP_SLACK, step);
	return top < max_it ? top : max_it;
}

/*
 * #84: OEM exposure split, applied exposure-neutral after the frame AE step.
 * The vendor recomputes (integration, analog gain, digital gain) from the
 * exposure value on every change (tisp_ae_long_tune2, deflicker ladder
 * branch l.699-729 and l.613-626): IT = min(highest rung R <= max_it + 20
 * with R <= EV / min gain, max_it), analog gain = EV / IT, digital gain 1x
 * until the analog gain is at its maximum, then the rest clamped.  The open
 * frame AE moves one stage per sample and never rebalanced, so the split
 * depended on the path (Eufy 1106a: IT 1800 / again idx 5 / ISP dgain 2.22x
 * vs idx 10 / 1.08x at one scene, OPUS_AE_SPLIT.md Q1).
 *
 * Here: the exposure above the minimum gain (gl, 16.16 log2) is re-split
 * with the OEM priority.  IT only moves UP to the OEM rung (the loop lowers
 * gains before IT, so a move down is never needed for the OEM order; IT
 * fixed or a rung-down this sample: it_free = false), the analog gain index
 * is the highest one the exposure covers, and the ISP dgain keeps only the
 * remainder below one analog step (the OEM analog gain is continuous, this
 * ladder has 1.17x steps) or the rest above max_again, clamped to dgain_max.
 * Nothing is changed when IT and the gain index are already the OEM ones
 * (the dgain bits stay as they are); the gain index rises at most one
 * step per call (the rest stays in the dgain).  The split never raises the exposure;
 * rounding loses < 1/1024.  Returns true when *it / *again / *dgain changed.
 */
static inline bool t40_ae_oem_split(u32 *it, u32 *again, u32 *dgain,
				    u32 af_step, u32 max_it, u32 lo, u32 hi,
				    u32 dgain_max, bool it_free,
				    u32 (*log2_gain)(u32 idx))
{
	u32 i = *it, a = *again, d = *dgain, ni = i, na, gl, g0;

	if (!log2_gain || !i || d < 1024U)
		return false;
	if (hi > T40_AE_AGAIN_LADDER_MAX)
		hi = T40_AE_AGAIN_LADDER_MAX;
	if (lo > hi || a < lo || a > hi)
		return false;
	if (dgain_max < 1024U)
		dgain_max = 1024U;
	g0 = log2_gain(lo);
	gl = log2_gain(a) - g0 + t40_ae_log2_ratio(d, 1024U);
	if (it_free && af_step && max_it >= af_step && gl) {
		u32 top = t40_ae_af_floor(max_it + T40_AE_AF_TOP_SLACK, af_step);
		u64 want = ((u64)i * t40_ae_q10_exp2_floor(gl)) >> 10;
		u32 r = want >= top ? top : t40_ae_af_floor((u32)want, af_step);

		/* want is rounded down: one rung more if it still fits exactly */
		if (r >= af_step && r + af_step <= top &&
		    (r + af_step <= i || t40_ae_log2_ratio(r + af_step, i) <= gl))
			r += af_step;
		while (r > i && r >= af_step && t40_ae_log2_ratio(r, i) > gl)
			r -= af_step;
		if (r >= af_step) {
			u32 c = r < max_it ? r : max_it;

			if (c > i) {
				gl -= t40_ae_log2_ratio(c, i);
				ni = c;
			}
		}
	}
	na = lo;
	while (na < hi && log2_gain(na + 1U) - g0 <= gl)
		na++;
	/*
	 * At most one analog index up per sample: the ISP dgain
	 * acts on the next frame, the sensor gain 1-2 frames later, so a big
	 * dgain -> again move would show as a dark frame; one 1.17x step is
	 * no larger than a normal AE gain step.
	 */
	if (na > a + 1U)
		na = a + 1U;
	if (ni == i && na == a)
		return false;
	d = t40_ae_q10_exp2_floor(gl - (log2_gain(na) - g0));
	*it = ni;
	*again = na;
	*dgain = d < dgain_max ? d : dgain_max;
	return true;
}

/* ---------------- IMPISPAEExprInfo ---------------- */

struct t40_ae_expr {
	u32 unit;			/* 0 lines, 1 us */
	u32 freeze;			/* AeMode MANUAL */
	u32 it_manual, again_manual, dgain_manual, ispdgain_manual;
	u32 it, again, dgain, ispdgain;	/* manual values (unit / x1024) */
	u32 min_again_mode, min_again;	/* x1024 */
	u32 max_it_mode, max_again_mode, max_dgain_mode, max_ispdgain_mode;
	u32 max_it, max_again, max_dgain, max_ispdgain;
};

/*
 * SET.  Mode words must be AUTO or MANUAL (-EINVAL otherwise); manual
 * gains below 1x (1024) and caps below the minimum are rejected (-EINVAL).
 * Reserved minimum modes (integration time, digital gains) are ignored like
 * the vendor; short-frame (WDR) words are ignored in linear mode.
 */
static inline int t40_ae_expr_parse(const u8 *in, struct t40_ae_expr *e)
{
	struct t40_ae_expr n;
	unsigned int i;

	memset(&n, 0, sizeof(n));
	for (i = 1; i <= 5; i++)
		if (t40_ae_ld32(in, 4U * i) > T40_OPS_MANUAL)
			return -EINVAL;
	for (i = 10; i <= 17; i++)
		if (t40_ae_ld32(in, 4U * i) > T40_OPS_MANUAL)
			return -EINVAL;
	if (t40_ae_ld32(in, 0) > 1U)
		return -EINVAL;
	n.unit = t40_ae_ld32(in, 0);
	n.freeze = t40_ae_ld32(in, 4);
	n.it_manual = t40_ae_ld32(in, 8);
	n.again_manual = t40_ae_ld32(in, 12);
	n.dgain_manual = t40_ae_ld32(in, 16);
	n.ispdgain_manual = t40_ae_ld32(in, 20);
	n.it = t40_ae_ld32(in, 24);
	n.again = t40_ae_ld32(in, 28);
	n.dgain = t40_ae_ld32(in, 32);
	n.ispdgain = t40_ae_ld32(in, 36);
	n.min_again_mode = t40_ae_ld32(in, 44);
	n.min_again = t40_ae_ld32(in, 76);
	n.max_it_mode = t40_ae_ld32(in, 56);
	n.max_again_mode = t40_ae_ld32(in, 60);
	n.max_dgain_mode = t40_ae_ld32(in, 64);
	n.max_ispdgain_mode = t40_ae_ld32(in, 68);
	n.max_it = t40_ae_ld32(in, 88);
	n.max_again = t40_ae_ld32(in, 92);
	n.max_dgain = t40_ae_ld32(in, 96);
	n.max_ispdgain = t40_ae_ld32(in, 100);
	if ((n.it_manual && !n.it) ||
	    (n.again_manual && n.again < 1024U) ||
	    (n.dgain_manual && n.dgain < 1024U) ||
	    (n.ispdgain_manual && n.ispdgain < 1024U) ||
	    (n.min_again_mode && n.min_again < 1024U) ||
	    (n.max_it_mode && !n.max_it) ||
	    (n.max_again_mode && n.max_again < 1024U) ||
	    (n.max_dgain_mode && n.max_dgain < 1024U) ||
	    (n.max_ispdgain_mode && n.max_ispdgain < 1024U) ||
	    (n.min_again_mode && n.max_again_mode && n.min_again > n.max_again))
		return -EINVAL;
	*e = n;
	return 0;
}

/* Live values reported by GET (integration times in the caller's unit). */
struct t40_ae_expr_live {
	u32 it, again, dgain, ispdgain;
	u32 min_it, min_again;
	u32 max_it, max_again, max_dgain, max_ispdgain;
	u32 total_gain_db, exposure_value, ev_log2;
};

static inline void t40_ae_expr_pack(u8 *out, const struct t40_ae_expr *e,
				    const struct t40_ae_expr_live *l)
{
	memset(out, 0, T40_AE_EXPR_BYTES);
	t40_ae_st32(out, 0, e->unit);
	t40_ae_st32(out, 4, e->freeze);
	t40_ae_st32(out, 8, e->it_manual);
	t40_ae_st32(out, 12, e->again_manual);
	t40_ae_st32(out, 16, e->dgain_manual);
	t40_ae_st32(out, 20, e->ispdgain_manual);
	t40_ae_st32(out, 24, l->it);
	t40_ae_st32(out, 28, l->again);
	t40_ae_st32(out, 32, l->dgain);
	t40_ae_st32(out, 36, l->ispdgain);
	t40_ae_st32(out, 44, e->min_again_mode);
	t40_ae_st32(out, 56, e->max_it_mode);
	t40_ae_st32(out, 60, e->max_again_mode);
	t40_ae_st32(out, 64, e->max_dgain_mode);
	t40_ae_st32(out, 68, e->max_ispdgain_mode);
	t40_ae_st32(out, 72, l->min_it);
	t40_ae_st32(out, 76, l->min_again);
	t40_ae_st32(out, 80, 1024U);
	t40_ae_st32(out, 84, 1024U);
	t40_ae_st32(out, 88, l->max_it);
	t40_ae_st32(out, 92, l->max_again);
	t40_ae_st32(out, 96, l->max_dgain);
	t40_ae_st32(out, 100, l->max_ispdgain);
	t40_ae_st32(out, 204, l->total_gain_db);
	t40_ae_st32(out, 212, l->exposure_value);
	t40_ae_st32(out, 216, l->ev_log2);
}

/* ---------------- IMPISPAeSpeedAttr ---------------- */

/* Step limit scaled by a speed value (128 = default AE speed, 1/8x..8x). */
static inline u32 t40_ae_speed_scale(u32 step, u32 speed)
{
	u64 s;

	if (!speed)
		speed = 1U;
	if (speed > 8U * T40_AE_SPEED_NEUTRAL)
		speed = 8U * T40_AE_SPEED_NEUTRAL;
	s = ((u64)step * speed) >> 7;	/* / T40_AE_SPEED_NEUTRAL */
	return s ? (u32)s : 1U;
}

#endif
