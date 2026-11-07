/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AE target and metering like the OEM (#84 follow-up, 2026-11-06).
 *
 * The OEM AE (vendor image tx-isp-t40.ko, Ghidra addresses of the vendor project) does not regulate on a fixed
 * target.  Per AE sample:
 *   tisp_ae_long_alogrithm @0x37138: metering parameters by highlight mode (tuning bank +0x338 word 0), the
 *     zone-weighted mean of the AE zone statistics (tisp_ae_long_weight_mean2 @0x35310: bin zone weights, pixels of
 *     the dark band weighted (p3 - 1) / p10 more, pixels of the bright band (p4 - 1) / p10 more), then in highlight
 *     mode 1 the luma raised by a quadratic highlight term over the histogram bins >= 2/3 of the bright threshold;
 *   tisp_ae_long_tune2 @0x35b58 (l.185-246, l.304-374): the target is interpolated over the ten EV nodes / ten
 *     targets of the tuning bank (tisp_ae_long_target @0x35924) after the scene / AeTargetComp scale of the lists
 *     (bank +0x37c, +0x38c; the comp word is written by tisp_ae_s_comp @0x39ed4), at the current EV and again at
 *     the EV the step aims at (EV x target / luma).
 * Tuning bank layout: the OEM AE outer block is tparamsN + 0x80 (tisp_ae_main_init: tisp_ae_params_refresh(..,
 * tparamsN + 0x80)); pointers of the non-WDR case from tisp_ae_params_transmit @0x313a0.  Eufy sc830ai day: EV
 * nodes 50..320000, targets 72..40 (EV 3282 -> 63), night 10..162000 / 50..34.
 *
 * The OEM values are in the domain of the hardware AE statistics (before gamma).  The open frame AE samples the
 * output Y, so the caller maps each sample through the inverse of the bank's gamma curve (t40_aet_ginv_build)
 * before metering and maps metered luma and target back through the curve (t40_aet_gamma8) for its step logic.
 * Not ported: the histogram target factor (OEM stMainAeInterOri + 0x4560 = 0, off), the AE-cache manual target
 * (tisp_ae_cache + 0x1dd), Pweight (bank +0x288 word 9 = 0 on the T40 bins), highlight modes other than 0/1 use
 * the scene-0 parameters.
 *
 * Only stdint types and the two OEM fixed-point helpers below: also built for the host
 * (tests/t40_ae_target_host.sh, tools/ko_emu/diff_ae_target.py compare it with the OEM instructions).
 */
#ifndef TX_ISP_T40_AE_TARGET_H
#define TX_ISP_T40_AE_TARGET_H

/* 64-bit division: the kernel has no __udivdi3 for modules (1106k: "unknown symbol" at insmod) */
#ifdef __KERNEL__
#include <linux/math64.h>
#define t40_aet_div64(a, b) div64_u64((a), (b))
#else
#define t40_aet_div64(a, b) ((uint64_t)(a) / (uint64_t)(b))
#endif

#define T40_AET_OUTER		0x80U	/* tparams + 0x80 = OEM stMainAeOuter */
#define T40_AET_ZONE		0x000U	/* u16: [0] y0 [1] rows [2] x0 [3] cols [4..18] col w [19..33] row h [34] lo [35] hi */
#define T40_AET_MP48		0x288U	/* u16[11] (word 9: Pweight enable) */
#define T40_AET_AF		0x314U	/* u16[3]: antiflicker enable, mode NORMAL (1) / AUTO (0), - */
#define T40_AET_AFREQ		0x320U	/* u16: antiflicker frequency */
#define T40_AET_EV		0x2d8U	/* u32[10] EV nodes */
#define T40_AET_TGT		0x300U	/* u16[10] targets */
#define T40_AET_HL		0x338U	/* u32[11] highlight mode, -, -, -, -, scene p3/p4 pairs */
#define T40_AET_MP		0x364U	/* u16[12]: [4] p3 [5] p4 [6] p10 */
#define T40_AET_SC		0x37cU	/* u16[4]: scene enable, EV scale, target scale (AeTargetComp word) */
#define T40_AET_SCW		0x38cU	/* u16[10] per-node target scale */
#define T40_AET_WEIGHT		0x3a0U	/* u8[225] zone weights */
#define T40_AET_N		10U
#define T40_AET_ZN		15U
#define T40_AET_Q		10U	/* OEM AE fixed point (bank +0xf8 word 0) */

struct t40_aet_bank {
	uint32_t ev[T40_AET_N];
	uint16_t tgt[T40_AET_N];
	uint16_t zone[36];
	uint32_t hl[11];
	uint16_t mp[7];
	uint16_t sc[3];
	uint16_t scw[T40_AET_N];
	uint8_t w[T40_AET_ZN * T40_AET_ZN];
	uint16_t af[2], afreq;
};

static inline uint32_t t40_aet_ld32(const uint8_t *b, uint32_t off)
{
	return (uint32_t)b[off] | (uint32_t)b[off + 1] << 8 | (uint32_t)b[off + 2] << 16 | (uint32_t)b[off + 3] << 24;
}

static inline uint16_t t40_aet_ld16(const uint8_t *b, uint32_t off)
{
	return (uint16_t)(b[off] | b[off + 1] << 8);
}

/* bank = tparams (day, night or the live tparamsN).  0 = usable (EV nodes rising, a target, a zone grid). */
static inline int t40_aet_parse(const uint8_t *bank, struct t40_aet_bank *p)
{
	const uint8_t *o = bank + T40_AET_OUTER;
	unsigned int i;

	for (i = 0; i < T40_AET_N; i++) {
		p->ev[i] = t40_aet_ld32(o, T40_AET_EV + 4U * i);
		p->tgt[i] = t40_aet_ld16(o, T40_AET_TGT + 2U * i);
		p->scw[i] = t40_aet_ld16(o, T40_AET_SCW + 2U * i);
	}
	for (i = 0; i < 36U; i++)
		p->zone[i] = t40_aet_ld16(o, T40_AET_ZONE + 2U * i);
	for (i = 0; i < 11U; i++)
		p->hl[i] = t40_aet_ld32(o, T40_AET_HL + 4U * i);
	for (i = 0; i < 7U; i++)
		p->mp[i] = t40_aet_ld16(o, T40_AET_MP + 2U * i);
	for (i = 0; i < 3U; i++)
		p->sc[i] = t40_aet_ld16(o, T40_AET_SC + 2U * i);
	for (i = 0; i < T40_AET_ZN * T40_AET_ZN; i++)
		p->w[i] = o[T40_AET_WEIGHT + i];
	p->af[0] = t40_aet_ld16(o, T40_AET_AF);
	p->af[1] = t40_aet_ld16(o, T40_AET_AF + 2U);
	p->afreq = t40_aet_ld16(o, T40_AET_AFREQ);
	for (i = 1; i < T40_AET_N; i++)
		if (p->ev[i] < p->ev[i - 1U])
			return -1;
	if (!p->ev[T40_AET_N - 1U] || !p->tgt[0] || !p->zone[1] || !p->zone[3] ||
	    p->zone[1] > T40_AET_ZN || p->zone[3] > T40_AET_ZN)
		return -1;
	return 0;
}

/* ---- OEM fixed-point helpers (same as tx_isp_t40_adr.h t40_adr_div32 / t40_adr_mul32) ---- */

/* OEM fix_point_div_32: x * 2^n / y by long division */
static inline uint32_t t40_aet_div32(uint32_t n, uint32_t x, uint32_t y)
{
	uint32_t q, r, f = 0, i;

	if (!y)
		return 0;	/* OEM: undefined */
	q = x / y;
	r = x % y;
	for (i = 0; i < n; i++) {
		r <<= 1;
		f <<= 1;
		if (y < r) {
			f |= 1;
			r -= y;
		} else if (y == r) {
			f = (f | 1) << ((n - 1 - i) & 31);
			break;
		}
	}
	return (n < 32 ? q << n : 0) | f;
}

/* OEM fix_point_mult2_32: a * b >> n in pieces, 32-bit wrap */
static inline uint32_t t40_aet_mul32(uint32_t n, uint32_t a, uint32_t b)
{
	uint32_t m = 0xffffffffU >> ((0U - n) & 31), ah = a >> (n & 31), bh = b >> (n & 31), al = a & m, bl = b & m;

	return ((ah * bh) << (n & 31)) + al * bh + ah * bl + ((al * bl) >> (n & 31));
}

/*
 * OEM tisp_ae_long_target(ev, ev_list, target_list, q): target at ev (Q q) over ten (EV, target) nodes, the end
 * values outside, linear between the first node pair that brackets ev (pair 0 when none does: unsorted lists).
 */
static inline uint32_t t40_ae_long_target(uint32_t ev, const uint32_t *evl, const uint32_t *tgl, uint32_t q)
{
	uint32_t a, b, ta, tb, d, span;
	unsigned int i;

	q &= 31U;
	if (ev <= evl[0] << q)
		return tgl[0];
	if (evl[9] << q <= ev)
		return tgl[9];
	for (i = 0; i < 9U; i++)
		if (evl[i] << q <= ev && ev <= evl[i + 1U] << q)
			break;
	if (i == 9U)
		i = 0;
	a = evl[i];
	b = evl[i + 1U];
	ta = tgl[i];
	if (a == b)
		return ta;
	tb = tgl[i + 1U];
	ev >>= q;
	d = a < ev ? ev - a : a - ev;
	span = b < a ? a - b : b - a;
	if (tb < ta)
		return ta - d * (ta - tb) / span;
	return ta + d * (tb - ta) / span;
}

/* OEM tisp_ae_s_comp: the bank's target-scale word for AeTargetComp comp (128 = the bin value). */
static inline uint16_t t40_aet_comp_word(uint16_t bin, uint32_t comp)
{
	if (comp < 0x81U)
		return (uint16_t)((int32_t)((uint32_t)bin * comp) >> 7);
	return (uint16_t)(bin + (uint16_t)((int32_t)(comp * 300U) / 0x7f) - 0x12eU);
}

/*
 * OEM tisp_ae_long_tune2 l.185-246: the EV / target lists the target lookups use.  sc_word = the live
 * target-scale word (t40_aet_comp_word of the bin word and AeTargetComp).
 */
static inline void t40_aet_lists(const struct t40_aet_bank *p, uint16_t sc_word, uint32_t *evl, uint32_t *tgl)
{
	unsigned int i;

	for (i = 0; i < T40_AET_N; i++) {
		evl[i] = p->ev[i];
		tgl[i] = p->tgt[i];
		if (p->sc[0] == 1U) {
			evl[i] = (uint32_t)p->sc[1] * evl[i] >> 7;
			tgl[i] = ((uint32_t)p->sc[1] * tgl[i] >> 7) * p->scw[i] * sc_word >> 14;
			if (!evl[i])
				evl[i] = 1;
			if (!tgl[i])
				tgl[i] = 1;
		}
	}
}

/* OEM EV of the AE (local_dc): it x again x dgain, gains Q10, result Q10 (fix_point_mult3_32). */
static inline uint32_t t40_aet_ev_q10(uint32_t it, uint32_t again_q10, uint32_t dgain_q10)
{
	return t40_aet_mul32(T40_AET_Q, t40_aet_mul32(T40_AET_Q, again_q10, dgain_q10), it << T40_AET_Q);
}

/*
 * OEM tisp_ae_long_tune2 target: t0 at the current EV, then the target at the EV the step aims at
 * (EV x t0 / luma, l.304-374).  *ev_aim (optional) gets that EV (Q10).
 */
static inline uint32_t t40_aet_aim(uint32_t ev_q10, uint32_t t0, uint32_t luma)
{
	if (!luma)
		luma = 1;
	return t40_aet_mul32(T40_AET_Q, ev_q10, t40_aet_div32(T40_AET_Q, (t0 & 0xffffU) << T40_AET_Q, luma << T40_AET_Q));
}

static inline uint32_t t40_aet_target(const uint32_t *evl, const uint32_t *tgl, uint32_t ev_q10, uint32_t luma,
				      uint32_t *ev_aim)
{
	uint32_t t0 = t40_ae_long_target(ev_q10, evl, tgl, T40_AET_Q) & 0xffffU;
	uint32_t aim = t40_aet_aim(ev_q10, t0, luma);

	if (ev_aim)
		*ev_aim = aim;
	return t40_ae_long_target(aim, evl, tgl, T40_AET_Q) & 0xffffU;
}

/* OEM tisp_ae_long_alogrithm: band weights (p3 dark, p4 bright, p10 divisor) for highlight mode and scene 0..2. */
static inline void t40_aet_band_params(const struct t40_aet_bank *p, unsigned int scene,
				       uint32_t *p3, uint32_t *p4, uint32_t *p10)
{
	uint32_t a = p->mp[4], b = p->mp[5];

	if (p->hl[0] == 0) {
		a = 1;
		b = 1;
	} else if (p->hl[0] != 1U && scene > 2U) {
		a = 1;
		b = 1;
	} else if (p->hl[0] != 1U) {
		a = scene == 2U ? p->hl[5] & 0xffffU : scene == 1U ? p->hl[7] & 0xffffU : p->hl[9] & 0xffffU;
		b = scene == 2U ? p->hl[6] & 0xffffU : scene == 1U ? p->hl[8] & 0xffffU : p->hl[10] & 0xffffU;
	}
	*p3 = a ? a : 1U;
	*p4 = b ? b : 1U;
	*p10 = p->mp[6] ? p->mp[6] : 1U;
}

/*
 * OEM tisp_ae_long_weight_mean2 (metered luma, *param_5): per zone the three band sums s0 (dark), s1, s2 (bright),
 * the dark / bright pixel counts c0 / c2 and the zone area (row height x column width), zone weight w.
 * luma = sum(w * (s0 + s1 + s2) + (p3 - 1) * s0 / p10 + (p4 - 1) * s2 / p10) /
 *        sum(w * area + (p3 - 1) * c0 / p10 + (p4 - 1) * c2 / p10), 32-bit terms, 64-bit sums, 0 -> 1.
 * Arrays have the OEM 15-word row stride.
 */
static inline uint32_t t40_aet_wmean(const uint32_t *s0, const uint32_t *s1, const uint32_t *s2,
				     const uint32_t *c0, const uint32_t *c2, const uint16_t *rowh, const uint16_t *colw,
				     uint32_t rows, uint32_t cols, const uint8_t *w, uint32_t p3, uint32_t p4, uint32_t p10)
{
	uint64_t num = 0, den = 0;
	uint32_t r, c;

	if (!p10)
		return 1;	/* OEM: divide by zero (p10 is 1 or more from t40_aet_band_params) */
	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			uint32_t z = r * T40_AET_ZN + c;
			uint32_t area = (uint32_t)rowh[r] * colw[c];
			uint32_t wt = w[z];
			uint32_t hi = (p4 - 1U) * c2[z] / p10 + wt * c2[z];
			uint32_t lo = (p3 - 1U) * c0[z] / p10 + wt * c0[z];

			den += (uint32_t)(wt * (area - (c0[z] + c2[z])) + hi + lo);
			num += (uint32_t)(wt * s0[z] + (s1[z] + s2[z]) * wt + (p3 - 1U) * s0[z] / p10 +
					  (p4 - 1U) * s2[z] / p10);
		}
	if (!den)
		return 1;	/* OEM: divide by zero */
	num = t40_aet_div64(num, den);
	return (uint32_t)num ? (uint32_t)num : 1U;
}

/*
 * OEM tisp_ae_long_alogrithm highlight mode 1: luma x (npix + H) / npix with
 * H = sum over bins b >= b0 of hist[b] x frac((p4 - 1) / p10) x ((b - b0) / (256 - b0))^2 (Q16 / Q5 OEM arithmetic;
 * the OEM keeps only the low 16 bits of the Q16 weight), b0 = 2/3 of the bright threshold (255 when it is 255 or
 * more), npix = column width x row height x columns x rows.
 */
static inline uint32_t t40_aet_hl_boost(uint32_t luma, const uint32_t *hist, uint32_t thr_hi, uint32_t p4,
					uint32_t p10, uint32_t npix)
{
	uint32_t b0 = 0xffU, k, den, sum = 0, i;

	if (thr_hi < 0xffU)
		b0 = ((thr_hi << 1) / 3U) & 0xffffU;
	if (!p10 || !npix)
		return luma;	/* OEM: divide by zero */
	k = t40_aet_div32(16, (p4 - 1U) << 16, p10 << 16) & 0xffffU;
	den = (0x100U - b0) << 16;
	for (i = 0; b0 + i != 0x100U; i++) {
		uint32_t x = t40_aet_div32(16, i << 16, den);

		x = t40_aet_mul32(16, x, x);
		x = t40_aet_mul32(16, k, x);
		sum += t40_aet_mul32(5, hist[b0 + i] << 5, x >> 11) >> 5;
	}
	return (npix + sum) * luma / npix;
}

/* ---- output Y <-> AE statistics domain through the bank gamma (129 x u16, 12-bit, tparams + 0x106ec) ---- */

/* 8-bit output of the gamma curve for an 8-bit statistics value l (curve input l x 16) */
static inline uint32_t t40_aet_gamma8(const uint16_t *g, uint32_t l)
{
	uint32_t i, v;

	if (l > 255U)
		l = 255U;
	i = l >> 1;
	v = g[i];
	if (l & 1U)
		v += ((uint32_t)g[i + 1U] - g[i]) / 2U;
	v >>= 4;
	return v > 255U ? 255U : v;
}

/*
 * inv[v] = the statistics value whose gamma output is closest to v (the lower one on a tie; a flat curve stretch
 * maps to its middle).  Returns -1 for a curve that is not rising (the caller keeps the output domain).
 */
static inline int t40_aet_ginv_build(const uint16_t *g, uint8_t *inv)
{
	uint32_t l = 0, v;

	if (g[128] <= g[0])
		return -1;
	for (v = 1; v < 129U; v++)
		if (g[v] < g[v - 1U])
			return -1;
	for (v = 0; v < 256U; v++) {
		uint32_t lo, hi, a, b;

		while (l < 255U && t40_aet_gamma8(g, l + 1U) <= v)
			l++;
		/* l = last value with gamma8(l) <= v (or 0); the run of values with that output */
		lo = l;
		while (lo > 0U && t40_aet_gamma8(g, lo - 1U) == t40_aet_gamma8(g, l))
			lo--;
		a = t40_aet_gamma8(g, l);
		if (a == v) {
			inv[v] = (uint8_t)((lo + l) / 2U);
			continue;
		}
		hi = l < 255U ? l + 1U : l;
		b = t40_aet_gamma8(g, hi);
		if (a > v)	/* v below the curve start */
			inv[v] = (uint8_t)l;
		else
			inv[v] = (uint8_t)(b - v < v - a ? hi : l);
	}
	return 0;
}

/*
 * #232: AeTargetComp on an output-Y target like the OEM: the OEM scales the target in the statistics domain
 * (tisp_ae_s_comp 0x39ed4 word x tisp_ae_long_tune2 l.214-216: target x word / 128), so on the gamma'd output the
 * effect is far weaker than scaling the output target (Eufy c1 run, legacy path: comp 40 / 200 -> frame Y 39.8 / 239.7,
 * vendor 92.6 / 140.5).  Used where the frame AE keeps an output-domain target (HLC / BLC / face metering).  The
 * statistics value of base_out is the nearest gamma inverse; the scaled value is clamped to 255.
 */
static inline uint32_t t40_aet_comp_out(const uint16_t *g, uint32_t base_out, uint16_t word)
{
	uint32_t l, best = 0, bd = 0xffffffffU, d, v;

	for (l = 0; l < 256U; l++) {
		v = t40_aet_gamma8(g, l);
		d = v > base_out ? v - base_out : base_out - v;
		if (d < bd) {
			bd = d;
			best = l;
		}
	}
	v = best * word >> 7;
	return t40_aet_gamma8(g, v > 255U ? 255U : v);
}

#endif /* TX_ISP_T40_AE_TARGET_H */
