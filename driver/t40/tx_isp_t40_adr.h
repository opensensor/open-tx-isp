/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 ADR (adaptive dynamic range / local tone mapping, TOP bit 7) in plain C.
 *
 * Rebuilt from the flow of the OEM tisp_adr_* / tiziano_adr_* / Tiziano_adr_fpga
 * functions (tiziano-adr.c in the sc830ai tx-isp-t40.ko).  The arithmetic
 * helpers keep the OEM fixed-point semantics (long division bit by bit,
 * 32-bit wrap, unsigned 64-bit division of signed products) so the register
 * values stay bit-exact.
 *
 * This replaces the literal mips2c chain (tx_isp_t40_adr_lit.inc up to
 * open-tx-isp next 7471ad73); tests/t40/c_chains_host compares both.
 * Only the main channel (sensor 0) exists here.
 */
#ifndef TX_ISP_T40_ADR_H
#define TX_ISP_T40_ADR_H

/* ---- OEM fixed-point helpers ---- */

/* x * 2^n / y by long division (OEM fix_point_div_32): quotient << n | n fraction bits */
static uint32_t t40_adr_div32(uint32_t n, uint32_t x, uint32_t y)
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

/* 64-bit version (OEM fix_point_div) */
static uint64_t t40_adr_div64(uint32_t n, uint64_t x, uint64_t y)
{
	uint64_t q, r, f = 0;
	uint32_t i;

	if (!y)
		return 0;	/* OEM: undefined */
	q = div64_u64(x, y);
	r = x - q * y;
	for (i = 0; i < n; i++) {
		r <<= 1;
		f <<= 1;
		if (y < r) {
			f |= 1;
			r -= y;
		} else if (y == r) {
			f = (f | 1) << ((n - 1 - i) & 63);
			break;
		}
	}
	return (q << (n & 63)) | f;
}

/* a * b >> n in pieces (OEM fix_point_mult2_32, 32-bit wrap) */
static uint32_t t40_adr_mul32(uint32_t n, uint32_t a, uint32_t b)
{
	uint32_t m = 0xffffffffU >> ((0U - n) & 31), ah = a >> (n & 31), bh = b >> (n & 31), al = a & m, bl = b & m;

	return ((ah * bh) << (n & 31)) + al * bh + ah * bl + ((al * bl) >> (n & 31));
}

/* 2^(x / 2^fb) scaled (OEM tisp_math_exp2 with the 33-entry table) */
static const uint32_t t40_adr_pow2_lut[33] = {
	0x40000000, 0x4166c34c, 0x42d561b4, 0x444c0740, 0x45cae0f2, 0x47521cc6, 0x48e1e9ba, 0x4a7a77d4,
	0x4c1bf829, 0x4dc69cdd, 0x4f7a9930, 0x51382182, 0x52ff6b55, 0x54d0ad5a, 0x56ac1f75, 0x5891fac1,
	0x5a82799a, 0x5c7dd7a4, 0x5e8451d0, 0x60962665, 0x62b39509, 0x64dcdec3, 0x6712460b, 0x69540ec9,
	0x6ba27e65, 0x6dfddbcc, 0x70666f76, 0x72dc8374, 0x75606374, 0x77f25cce, 0x7a92be8b, 0x7d41d96e,
	0x80000000
};
static uint32_t t40_adr_exp2(uint32_t x, uint32_t fb, uint32_t ob)
{
	uint32_t f = x & ((1U << fb) - 1), sh = 30 - ob - (x >> fb), v;

	if (fb < 6) {
		v = t40_adr_pow2_lut[f << (5 - fb)];
	} else {
		uint32_t s = fb - 5, i = f >> s;

		v = t40_adr_pow2_lut[i] + (uint32_t)(((uint64_t)(t40_adr_pow2_lut[i + 1] - t40_adr_pow2_lut[i]) *
						      (f & ((1U << s) - 1))) >> s);
	}
	return v >> (sh & 31);
}

/* table interpolation, s16 knots (OEM ispint_adr_16) */
static int32_t t40_adr_int16(int32_t x, const int16_t *xs, const int16_t *ys, int32_t n)
{
	int32_t i;

	for (i = 0; i < n; i++) {
		if (xs[i] < x)
			continue;
		if (!i)
			return ys[0];
		if (xs[i] == xs[i - 1])
			return ys[i];
		return (int16_t)((int32_t)((uint32_t)(ys[i] - ys[i - 1]) * (uint32_t)(x - xs[i - 1]) +
					   (uint32_t)((xs[i] - xs[i - 1]) >> 1)) / (xs[i] - xs[i - 1]) + ys[i - 1]);
	}
	return ys[n - 1];
}

/* same with s32 knots (OEM ispint_adr_32) */
static int32_t t40_adr_int32(int32_t x, const int32_t *xs, const int16_t *ys, int32_t n)
{
	int32_t i;

	for (i = 0; i < n; i++) {
		if (xs[i] < x)
			continue;
		if (!i)
			return ys[0];
		if (xs[i] == xs[i - 1])
			return ys[i];
		return (int32_t)((uint32_t)(ys[i] - ys[i - 1]) * (uint32_t)(x - xs[i - 1]) +
				 (uint32_t)((xs[i] - xs[i - 1]) >> 1)) / (xs[i] - xs[i - 1]) + ys[i - 1];
	}
	return ys[n - 1];
}

/* piecewise-linear resampling of nq points, result capped by the right knot (OEM func_interp1_short) */
static void t40_adr_interp1(const int16_t *xs, const int16_t *ys, const int16_t *xq, int16_t *out, int32_t n, int32_t nq)
{
	int32_t q, i;

	for (q = 0; q < nq; q++) {
		int32_t x = xq[q];

		for (i = 1; i < n; i++) {
			if (!(xs[0] < x)) {
				out[q] = ys[0];
				goto next;
			}
			if (x < xs[i]) {
				int32_t dx = (int16_t)(xs[i] - (uint16_t)xs[i - 1]);
				int32_t dy = (int16_t)((uint16_t)ys[i] - ys[i - 1]);
				int32_t t = (int16_t)(x - (uint16_t)xs[i - 1]);
				int32_t v = (int32_t)((uint32_t)(dx / 2) + (uint32_t)(dy * t));

				out[q] = (int16_t)(v / dx + ys[i - 1]);	/* OEM: dx = 0 undefined */
				if (ys[i] < out[q])
					out[q] = ys[i];
				goto next;
			}
		}
		if (i == n)
			out[q] = ys[n - 1];
next:		;
	}
}

/* inverse table lookup: first knot above t, linear between it and the one before
 * (OEM: reads xs[-1]/ys[-1] when t is below the first knot, kept) */
static const int16_t *t40_adr_sorted_xs[2];	/* knot tables checked non-decreasing this frame (issue 133) */
static const int16_t *t40_adr_check_sorted16(const int16_t *xs)
{
	int32_t j;

	for (j = 1; j < 129; j++)
		if (xs[j] < xs[j - 1])
			return NULL;
	return xs;
}
static int32_t t40_adr_lookup(int32_t t, const int16_t *xs, const int16_t *ys, uint32_t sh, int32_t rnd)
{
	int32_t j, d;

	j = 0;
	if (xs == t40_adr_sorted_xs[0] || xs == t40_adr_sorted_xs[1]) {
		int32_t b = 129;	/* first knot above t, as the scan below finds it */

		while (j < b) {
			int32_t mid = (j + b) >> 1;

			if (t < xs[mid])
				b = mid;
			else
				j = mid + 1;
		}
	}
	for (; j < 129; j++)
		if (t < xs[j]) {
			d = t40_adr_mul32(sh, t40_adr_div32(sh, (uint32_t)(ys[j] - ys[j - 1]) << sh,
							    (uint32_t)(xs[j] - xs[j - 1]) << sh),
					  (uint32_t)(xs[j] - t) << sh);
			return ys[j] - ((int32_t)(d + rnd) >> sh);
		}
	return ys[128];
}

/*
 * Issue 133: the 512-entry nearest-value scan of subsection_map ran 6 x 24 times per
 * frame (~80 % of the ADR event).  The table is the cumulative histogram, so it is
 * normally non-decreasing: t40_adr_fpga checks that once per frame (and that no
 * distance can overflow) and then the nearest entries are found by binary search.
 * In a sorted table the entries at the minimum distance are one contiguous run
 * (value x - d just below the first entry >= x, value x + d from it on), so count
 * and index sum are the same as the scan's.  Any other table takes the scan.
 */
static const int32_t *t40_adr_sorted_tab;
#define T40_ADR_TAB_LIM 0x3fffffff
static const int32_t *t40_adr_check_sorted(const int32_t *tab)
{
	int32_t i;

	if (tab[0] < 0 || tab[511] > T40_ADR_TAB_LIM)
		return NULL;
	for (i = 1; i < 512; i++)
		if (tab[i] < tab[i - 1])
			return NULL;
	return tab;
}
/* nearest entries of a sorted tab: run [lo, hi] of the values at the minimum distance (<= 10000) */
static void t40_adr_nearest_sorted(int32_t x, const int32_t *tab, int32_t *cnt, int32_t *sum)
{
	int32_t a = 0, b = 512, lo, hi, dl, dr, best;

	while (a < b) {		/* first index with tab[] >= x */
		int32_t mid = (a + b) >> 1;

		if (tab[mid] < x)
			a = mid + 1;
		else
			b = mid;
	}
	dl = a > 0 ? x - tab[a - 1] : 0x7fffffff;
	dr = a < 512 ? tab[a] - x : 0x7fffffff;
	best = dl < dr ? dl : dr;
	*cnt = 0;
	*sum = 0;
	if (best > 10000)	/* the scan starts at best = 10000 and counts ties with it */
		return;
	lo = a;
	hi = a - 1;
	if (dl == best) {	/* run of tab[a - 1] */
		lo = a - 1;
		while (lo > 0 && tab[lo - 1] == tab[a - 1])
			lo--;
	}
	if (dr == best) {	/* run of tab[a] */
		hi = a;
		while (hi < 511 && tab[hi + 1] == tab[a])
			hi++;
	}
	*cnt = hi - lo + 1;
	*sum = (lo + hi) * (hi - lo + 1) / 2;
}

/* one knee from the histogram target (OEM subsection_map): the mean index of
 * the table entries nearest to x, mapped through xs->ys, moved by strength */
static int32_t t40_adr_subsection_map(int32_t x, int32_t c6, int32_t c2, const int16_t *xs, const int16_t *ys,
				      const int32_t *tab, int32_t m, uint32_t shf, uint32_t sh, int32_t mode)
{
	int32_t best = 10000, cnt = 0, sum = 0, i, d, half, y;
	uint32_t q;

	if (tab == t40_adr_sorted_tab && x >= -T40_ADR_TAB_LIM && x <= T40_ADR_TAB_LIM) {
		t40_adr_nearest_sorted(x, tab, &cnt, &sum);
	} else {
		for (i = 0; i < 512; i++) {
			d = x < tab[i] ? tab[i] - x : x - tab[i];
			if (d < best) {
				cnt = 1;
				sum = i;
				best = d;
			} else if (d == best) {
				cnt++;
				sum += i;
			}
		}
	}
	if (cnt <= 0)
		cnt = 1;
	if (sum <= 0)
		sum = 1;
	q = t40_adr_div32(sh, (uint32_t)sum << sh, (uint32_t)cnt << sh);
	half = (int32_t)(1U << sh) / 2;
	y = t40_adr_lookup(((int32_t)(q + half) >> sh) * m - 1, xs, ys, sh, half);
	if (mode == 1 || y <= c6)
		q = (uint32_t)c6 * 100 + (uint32_t)(y - c6) * (uint32_t)c2;
	else
		q = (uint32_t)c6 * 100;
	q = t40_adr_div32(shf, q << shf, 100U << shf);
	return (int32_t)(q + (int32_t)(1U << shf) / 2) >> shf;
}

/* the eleven knee points of the global curve (OEM subsection_up): six histogram
 * targets, each found by subsection_map and mapped back xs<-ys */
static void t40_adr_subsection_up(int32_t *out, int32_t c2, const int16_t *p, const int16_t *q, const int32_t *tab,
				  int32_t m, uint32_t sh, uint32_t sh2, int32_t mode)
{
#define SU_H(x) ((int32_t)(t40_adr_div32(sh, (uint32_t)(x) << sh, 2U << sh) + 0x200) >> sh)
#define SU_G(y) (tab[(int32_t)(t40_adr_div32(sh, (uint32_t)(y) << sh, (uint32_t)m << sh) + 0x200) >> sh])
#define SU_M(x, c6) t40_adr_subsection_map(x, c6, c2, p, q, tab, m, sh, sh2, mode)
#define SU_L(t) t40_adr_lookup(t, q, p, sh, 0x200)
	int32_t r1, r2, r3, r4, r5, r6;

	out[10] = 4095;
	out[0] = 0;
	r1 = SU_M(5000, SU_H(4095));
	out[6] = SU_L(r1);
	r2 = SU_M(SU_G(out[6]) / 2, SU_H(r1));
	out[4] = SU_L(r2);
	r3 = SU_M(SU_G(out[4]) / 2, SU_H(r2));
	out[2] = SU_L(r3);
	r4 = SU_M((SU_G(out[6]) + SU_G(out[4])) / 2, SU_H(r1 + r2));
	out[5] = SU_L(r4);
	r5 = SU_M(SU_G(out[2]) / 2, SU_H(r3));
	out[1] = SU_L(r5);
	r6 = SU_M((SU_G(out[4]) + SU_G(out[2])) / 2, SU_H(r2 + r3));
	out[3] = SU_L(r6);
	out[7] = out[6] + 1;
	out[8] = out[6] + 2;
	out[9] = out[6] + 3;
	if (out[9] >= 4095) {
		out[6] = 4091;
		out[7] = 4092;
		out[8] = 4093;
		out[9] = 4094;
	}
	if (out[10] >= 4096)
		out[10] = 4095;
#undef SU_H
#undef SU_G
#undef SU_M
#undef SU_L
}

/* 1/ln 2 in Q16 (OEM: fix_point_div_32(16, 14427 << 16, 10000 << 16)) */
static uint32_t t40_adr_inv_ln2(void)
{
	return t40_adr_div32(16, 0x385b0000U, 0x27100000U);
}

/* e^(-d2 / den) in 1/10000 (d2 clipped to 0x3ffffc) */
static int32_t t40_adr_gauss(int32_t d2, int32_t lim, int32_t den, uint32_t inv_ln2)
{
	uint32_t t;

	if (d2 >= lim + 1)
		d2 = lim;
	t = t40_adr_mul32(16, t40_adr_div32(10, (uint32_t)d2 << 10, (uint32_t)den << 10) << 6, inv_ln2);
	if ((int32_t)t >= 0xf0000)
		t = 0xeffff;
	return (int32_t)t40_adr_exp2(t, 16, 16);
}

/* local light weight (OEM func_local_info): Gaussian fall-off of v away from the
 * centre e (sigma c below, d above), result in percent */
static int32_t t40_adr_local_info(int32_t v, int32_t b, int32_t c, int32_t d, int32_t e)
{
	uint32_t il = t40_adr_inv_ln2(), s0 = (uint32_t)v << 16;
	int32_t r, ex;

	if (e <= 0)
		e = 1;
	if (b < e) {
		ex = t40_adr_gauss((e - b) * (e - b), 0x3ffffc, 2 * d * d, il);
		r = (int32_t)t40_adr_div32(16, s0, ex) >> 16;
	} else {
		ex = t40_adr_gauss((b - e) * (b - e), 0x3ffffc, 2 * c * c, il);
		r = ((int32_t)(s0 - t40_adr_div32(16, s0, ex)) >> 16) + v;
	}
	if (r >= 10001)
		r = 10000;
	return (int32_t)(t40_adr_div32(10, (uint32_t)r << 10, 0x19000) + 0x200) >> 10;
}

/* in 1/10000: (dy * 10000 + dx / 2) / dx, the OEM adds the quotient of dx / 2 */
static inline int32_t t40_adr_slope(int32_t dy, int32_t dx)
{
	if (!dx)
		return 0;	/* OEM: undefined */
	return (int32_t)((uint32_t)(dx / 2) + (uint32_t)dy * 10000U) / dx;
}

/* three-tap Gauss-Seidel pass over the inner slopes, returns the new sum */
static int64_t t40_adr_smooth3(int32_t *sl, int32_t cnt)
{
	int64_t sum = sl[0];
	int32_t i;

	for (i = 1; i < cnt - 1; i++) {
		sl[i] = (int32_t)((uint32_t)sl[i - 1] + sl[i] + sl[i + 1] + 1) / 3;
		sum += sl[i];
	}
	return sum + sl[cnt - 1];
}

/* slope * sum0 / sum, rounded, unsigned 64-bit as in the OEM */
static inline int32_t t40_adr_renorm(int32_t sl, int64_t sum0, int64_t sum)
{
	return (int32_t)t40_adr_div64(0, (uint64_t)((int64_t)sl * sum0) + ((uint64_t)sum >> 1), (uint64_t)sum);
}

/* smooth the 16-knot map curve (OEM func_map_y_filter): knots past `limit`
 * head straight for 4095 */
static void t40_adr_map_filter(int16_t *map, int32_t *vals, int32_t iters, int32_t limit)
{
	int32_t a[16], sl[15], i, it;
	int64_t sum0 = 0, sum;

	map[15] = 4095;
	a[0] = 0;
	a[15] = 4095;
	for (i = 1; i < 15; i++)
		a[i] = vals[i - 1];
	for (i = 0; i < 15; i++) {
		sl[i] = t40_adr_slope(a[i + 1] - a[i], map[i + 1] - map[i]);
		sum0 += sl[i];
	}
	for (it = 0; it < iters; it++) {
		sum = t40_adr_smooth3(sl, 15);
		for (i = 1; i < 16; i++) {
			int32_t dx = map[i] - map[i - 1], v;

			if (i > limit)
				sl[i - 1] = t40_adr_slope(4095 - a[i - 1], 4095 - map[i - 1]);
			else
				sl[i - 1] = t40_adr_renorm(sl[i - 1], sum0, sum);
			v = a[i - 1] + (int32_t)((uint32_t)dx * sl[i - 1] + 5000) / 10000;
			a[i] = v < 4096 ? v : 4095;
		}
	}
	for (i = 0; i < 14; i++)
		vals[i] = a[i + 1];
}

/* the same on 33 evenly spaced points (OEM func_map_y_filter_sp) */
static const int16_t t40_adr_x33[33] = {
	0, 128, 256, 384, 512, 640, 768, 896, 1024, 1152, 1280, 1408, 1536, 1664, 1792, 1920,
	2048, 2176, 2304, 2432, 2560, 2688, 2816, 2944, 3072, 3200, 3328, 3456, 3584, 3712, 3840, 3968, 4095
};
static void t40_adr_map_filter_sp(int16_t *map, int32_t *vals, int32_t iters)
{
	int16_t y16[16], y33[33];
	int32_t sl[32], i, it;
	int64_t sum0 = 0, sum;

	y16[0] = 0;
	y16[15] = 4095;
	map[15] = 4095;
	for (i = 1; i < 15; i++)
		y16[i] = (int16_t)vals[i - 1];
	t40_adr_interp1(map, y16, t40_adr_x33, y33, 16, 33);
	for (i = 0; i < 32; i++) {
		sl[i] = t40_adr_slope(y33[i + 1] - y33[i], t40_adr_x33[i + 1] - t40_adr_x33[i]);
		sum0 += sl[i];
	}
	for (it = 0; it < iters; it++) {
		sum = t40_adr_smooth3(sl, 32);
		for (i = 0; i < 32; i++) {
			int32_t v;

			sl[i] = t40_adr_renorm(sl[i], sum0, sum);
			v = (int32_t)((uint32_t)(t40_adr_x33[i + 1] - t40_adr_x33[i]) * sl[i] + 5000) / 10000 +
			    (uint16_t)y33[i];
			y33[i + 1] = (int16_t)v < 4096 ? v : 4095;
		}
	}
	t40_adr_interp1(t40_adr_x33, y33, map, y16, 33, 16);
	for (i = 0; i < 14; i++)
		vals[i] = y16[i + 1];
}

/* 24 local-light Gaussian weights (OEM func_gauss_local), normalised to the
 * largest of the four centre ones; recomputed only when the parameters change */
static const int32_t t40_adr_gl_x[24] = {
	-250, -250, -250, -250, -150, -150, -150, -150, -50, -50, -50, -50,
	50, 50, 50, 50, 150, 150, 150, 150, 250, 250, 250, 250
};
static const int16_t t40_adr_gl_y[4] = { 150, 50, -50, -150 };	/* scaled by 10/12/14/16 tenths */
static void t40_adr_gauss_local(int32_t *out, int16_t *old, const int16_t *prm)
{
	int32_t sigma = prm[6] + 80, cx = prm[7], cy = prm[8], mode = prm[9], m, k, ymul, ycen;
	uint32_t il;

	if (sigma < 80)
		sigma = 80;
	if (sigma >= 1105)
		sigma = 1104;
	cx = cx < 0 ? 0 : cx > 200 ? 200 : cx;
	cy = cy < 0 ? 0 : cy > 320 ? 320 : cy;
	m = mode < 0 ? 0 : mode > 5 ? 5 : mode;
	if (old[0] == sigma && old[1] == cx && old[2] == cy && old[3] == m)
		return;
	old[0] = sigma;
	old[1] = cx;
	old[2] = cy;
	old[3] = m;
	il = t40_adr_inv_ln2();
	/* OEM: the raw mode picks the vertical table (<= 0: x1.0, 1 or >= 4: x1.2, 2: x1.4, 3: x1.6) */
	ymul = mode <= 0 ? 10 : mode == 2 ? 14 : mode == 3 ? 16 : 12;
	ycen = cy - 10 * ymul;
	for (k = 0; k < 24; k++) {
		int32_t dx = t40_adr_gl_x[k] - (cx - 100), dy = t40_adr_gl_y[k & 3] * ymul / 10 - ycen;
		int32_t e = t40_adr_gauss((int32_t)((uint32_t)dy * dy + (uint32_t)dx * dx), 500000, 2 * sigma * sigma, il);

		out[k] = (int32_t)t40_adr_div32(16, 0x27100000U, e) >> 16;
	}
	m = out[9] >= out[10] ? out[9] : out[10];
	if (m < 0)
		m = 0;
	if (out[11] >= m)
		m = out[11];
	if (out[12] >= m)
		m = out[12];
	for (k = 0; k < 24; k++)
		out[k] = m ? (int32_t)(10000U * out[k]) / m : 0;	/* OEM: m = 0 undefined */
}

/* ADR curve shape table (OEM .data ai_curve1_y) */
static const int32_t t40_adr_curve1_y[256] = {
	2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
	34, 36, 38, 40, 42, 44, 46, 48, 50, 52, 54, 56, 58, 60, 62, 64,
	66, 68, 70, 72, 74, 76, 78, 80, 82, 84, 86, 88, 90, 92, 94, 96,
	98, 100, 102, 104, 106, 108, 111, 113, 115, 117, 119, 121, 123, 125, 127, 129,
	131, 133, 135, 137, 139, 142, 144, 146, 148, 150, 152, 155, 157, 159, 161, 163,
	166, 168, 170, 173, 175, 178, 180, 183, 185, 188, 191, 194, 197, 200, 203, 206,
	210, 214, 218, 222, 226, 231, 237, 243, 250, 258, 267, 277, 289, 304, 321, 343,
	370, 404, 448, 507, 588, 702, 867, 1119, 1523, 2212, 3496, 6184, 12868, 34878, 160568, 4328775,
	-4328775, -160568, -34878, -12868, -6184, -3496, -2212, -1523, -1119, -867, -702, -588, -507, -448, -404, -370,
	-343, -321, -304, -289, -277, -267, -258, -250, -243, -237, -231, -226, -222, -218, -214, -210,
	-206, -203, -200, -197, -194, -191, -188, -185, -183, -180, -178, -175, -173, -170, -168, -166,
	-163, -161, -159, -157, -155, -152, -150, -148, -146, -144, -142, -139, -137, -135, -133, -131,
	-129, -127, -125, -123, -121, -119, -117, -115, -113, -111, -108, -106, -104, -102, -100, -98,
	-96, -94, -92, -90, -88, -86, -84, -82, -80, -78, -76, -74, -72, -70, -68, -66,
	-64, -62, -60, -58, -56, -54, -52, -50, -48, -46, -44, -42, -40, -38, -36, -34,
	-32, -30, -28, -26, -24, -22, -20, -18, -16, -14, -12, -10, -8, -6, -4, -2
};

/* 14 knots of the shaped curve (OEM func_adr_map_curve1) */
static void t40_adr_map_curve1(int32_t *out, int32_t idx, int32_t k)
{
	int32_t t[33], c, j;
	int64_t k4;
	int32_t k3;

	k = k < 0 ? 0 : k > 255 ? 255 : k;
	idx = idx < 0 ? 0 : idx > 255 ? 255 : idx;
	c = t40_adr_curve1_y[idx];
	k4 = (int64_t)(k * k) * (k * k);
	k3 = k * k * k;
	for (j = 0; j < 33; j++) {
		int32_t x = 8 * (c >= 0 ? j : 32 - j), u = 256 - x - k, a, w;
		uint64_t num, den, r;

		if (c >= 0) {
			a = (c + 256) * x;
			w = c + x;
		} else {
			a = (256 - c) * x;
			w = x - c;
		}
		num = ((uint64_t)((int64_t)u * u * (256 - k) * u) + (uint64_t)k4) * (uint64_t)(int64_t)a;
		den = (uint64_t)((int64_t)w * k3);
		r = t40_adr_div64(0, num, den);
		if (r >= 0x10001)
			r = 0x10000;
		t[j] = c >= 0 ? (int32_t)r : 0x10000 - (int32_t)r;
	}
	out[0] = (int32_t)((uint32_t)(15 * t[0] + t[1]) * 4095) / 0xffff0;
	out[1] = (int32_t)((uint32_t)(7 * t[0] + t[1]) * 4095) / 0x7fff8;
	out[2] = (int32_t)((uint32_t)(3 * t[0] + t[1]) * 4095) / 0x3fffc;
	out[3] = (int32_t)((uint32_t)(t[0] + t[1]) * 4095) / 0x1fffe;
	out[4] = (int32_t)((uint32_t)t[1] * 4095) / 65535;
	out[5] = (int32_t)((uint32_t)(t[1] + t[2]) * 4095) / 0x1fffe;
	out[6] = (int32_t)((uint32_t)t[2] * 4095) / 65535;
	out[7] = (int32_t)((uint32_t)t[3] * 4095) / 65535;
	out[8] = (int32_t)((uint32_t)t[4] * 4095) / 65535;
	out[9] = (int32_t)((uint32_t)t[6] * 4095) / 65535;
	out[10] = (int32_t)((uint32_t)t[8] * 4095) / 65535;
	out[11] = (int32_t)((uint32_t)t[12] * 4095) / 65535;
	out[12] = (int32_t)((uint32_t)t[16] * 4095) / 65535;
	out[13] = (int32_t)((uint32_t)t[24] * 4095) / 65535;
}

/* ---- OEM tables ---- */

/* parameter pointers of tiziano_adr_wal_para_refresh: offsets into the parameter block, linear and WDR */
static const uint16_t t40_adr_wal_lin[71] = {
	0x5dc, 0x5f4, 0x5f8, 0x600, 0x608, 0x618, 0x644, 0x65a, 0x670, 0x686, 0x69c, 0x6b2,
	0x6c8, 0x6de, 0x6f4, 0x70a, 0x720, 0x736, 0x74c, 0x762, 0x778, 0x78e, 0x7a4, 0x7ba,
	0x7d0, 0x7e6, 0x7fc, 0x812, 0x828, 0x83e, 0x854, 0x86a, 0x880, 0x896, 0x8ac, 0x8c2,
	0x8d8, 0x8ee, 0x904, 0x91a, 0x930, 0x946, 0x95c, 0x972, 0x988, 0x99e, 0x9b4, 0x9ca,
	0x9d2, 0x9e2, 0xa02, 0xb04, 0xb1a, 0xb30, 0xb70, 0xb98, 0xbc0, 0xbd6, 0xbec, 0xc02,
	0xc2a, 0xc40, 0xc54, 0xc68, 0xc7c, 0xc90, 0xca0, 0xcaa, 0xcb2, 0xcca, 0xcd2
};
static const uint16_t t40_adr_wal_wdr[71] = {
	0xce6, 0xcfe, 0xd02, 0xd0a, 0xd12, 0xd24, 0xd50, 0xd66, 0xd7c, 0xd92, 0xda8, 0xdbe,
	0xdd4, 0xdea, 0xe00, 0xe16, 0xe2c, 0xe42, 0xe58, 0xe6e, 0xe84, 0xe9a, 0xeb0, 0xec6,
	0xedc, 0xef2, 0xf08, 0xf1e, 0xf34, 0xf4a, 0xf60, 0xf76, 0xf8c, 0xfa2, 0xfb8, 0xfce,
	0xfe4, 0xffa, 0x1010, 0x1026, 0x103c, 0x1052, 0x1068, 0x107e, 0x1094, 0x10aa, 0x10c0, 0x10d6,
	0x10de, 0x10ee, 0x110e, 0x1210, 0x1226, 0x123c, 0x127c, 0x12a4, 0x12cc, 0x12e2, 0x12f8, 0x130e,
	0x1336, 0x134c, 0x1360, 0x1374, 0x1388, 0x139c, 0x13ac, 0x13b6, 0x13be, 0x13d6, 0x13de
};
static const int32_t t40_adr_img_dr_w[128] = {
	255, 255, 255, 255, 254, 254, 253, 253, 252, 251, 250, 249, 248, 247, 245, 244,
	242, 241, 239, 237, 235, 233, 231, 229, 227, 225, 223, 220, 218, 216, 213, 210,
	208, 205, 202, 200, 197, 194, 191, 188, 185, 182, 179, 176, 173, 170, 167, 164,
	161, 158, 155, 152, 148, 145, 142, 139, 136, 133, 130, 127, 124, 121, 118, 115,
	112, 110, 107, 104, 101, 98, 96, 93, 90, 88, 85, 83, 80, 78, 76, 73,
	71, 69, 66, 64, 62, 60, 58, 56, 54, 52, 50, 49, 47, 45, 44, 42,
	40, 39, 37, 36, 35, 33, 32, 31, 29, 28, 27, 26, 25, 24, 23, 22,
	21, 20, 19, 18, 17, 17, 16, 15, 14, 14, 13, 12, 12, 11, 11, 10
};
#define T40_ADR_IMG_DR_SUM 15934
static const int32_t t40_adr_5x5_in2[31] = {
	33809, 24810, 20625, 17869, 15810, 14166, 12797, 11625, 10600, 9689, 8869, 8124, 7440, 6810, 6225, 5678,
	5166, 4684, 4229, 3798, 3388, 2998, 2625, 2269, 1928, 1600, 1285, 981, 689, 406, 133
};
static const int16_t t40_adr_ctc1_x[23] = {
	0, 8, 16, 32, 64, 96, 128, 256, 384, 512, 640, 768, 896, 1024, 1280, 1536,
	1792, 2048, 2304, 2560, 3072, 3584, 4096
};
/* [0]: the OEM lookups read one entry before the table (there: 0) */
static const int16_t t40_adr_top_gam_xm[130] = {
	0,
	0, 32, 64, 96, 128, 160, 192, 224, 256, 288, 320, 352, 384, 416, 448, 480,
	512, 544, 576, 608, 640, 672, 704, 736, 768, 800, 832, 864, 896, 928, 960, 992,
	1024, 1056, 1088, 1120, 1152, 1184, 1216, 1248, 1280, 1312, 1344, 1376, 1408, 1440, 1472, 1504,
	1536, 1568, 1600, 1632, 1664, 1696, 1728, 1760, 1792, 1824, 1856, 1888, 1920, 1952, 1984, 2016,
	2048, 2080, 2112, 2144, 2176, 2208, 2240, 2272, 2304, 2336, 2368, 2400, 2432, 2464, 2496, 2528,
	2560, 2592, 2624, 2656, 2688, 2720, 2752, 2784, 2816, 2848, 2880, 2912, 2944, 2976, 3008, 3040,
	3072, 3104, 3136, 3168, 3200, 3232, 3264, 3296, 3328, 3360, 3392, 3424, 3456, 3488, 3520, 3552,
	3584, 3616, 3648, 3680, 3712, 3744, 3776, 3808, 3840, 3872, 3904, 3936, 3968, 4000, 4032, 4064,
	4095
};
#define t40_adr_top_gam_x (t40_adr_top_gam_xm + 1)
static const int16_t t40_adr_knee_diff[15] = {
	8, 8, 16, 32, 64, 64, 64, 128, 128, 256, 256, 512, 512, 1024, 1024
};
static const int16_t t40_adr_light_b_in[17] = {
	16, 64, 128, 192, 256, 384, 512, 640, 768, 1024, 1280, 1536, 2048, 2560, 3072, 3584, 4095
};
static const int16_t t40_adr_knee_x_init[16] = {
	0, 8, 16, 32, 64, 128, 192, 256, 384, 512, 768, 1024, 1536, 2048, 3072, 4096
};

/* ---- state ---- */

#define T40_ADR_PAR_OFFSET	0xd978U		/* ADR section inside a tuning bank */
#define T40_ADR_PAR_BYTES	5108U
#define T40_ADR_GAMMA_OFFSET	0x106ecU	/* gamma section (258 x u16 linear + WDR) */
#define T40_ADR_STAT_BYTES	10056U
#define T40_ADR_BLOCKS		24U		/* 6 x 4 statistics blocks */

/* statistics (OEM adr_main_stat_info, same layout) */
#define ADR_S_HIST	0	/* u32[512] luma histogram */
#define ADR_S_BLK	2048	/* u32[24][20] block histograms */
#define ADR_S_BLKN	3968	/* s32[24][14] block histograms in 1/10000 of the block */
#define ADR_S_A		5312	/* u32[24] per-block sums */
#define ADR_S_B		5408
#define ADR_S_C		5504
#define ADR_S_D		5600
#define ADR_S_CDF	5696	/* s32[512] cumulative histogram in 1/10000 */
#define ADR_S_AN	9664	/* A / block pixels */
#define ADR_S_BN	9760
#define ADR_S_C2	9856
#define ADR_S_D2	9952
#define ADR_S_MEAN	10048	/* sum A, sum B / pixels */

struct t40_adr_ctx {
	uint8_t par[T40_ADR_PAR_BYTES];		/* OEM main_adr_paras: bank copy, modified in place */
	int16_t gamma[258];			/* OEM main_adr_gamma */
	int16_t map_y_old[T40_ADR_BLOCKS][14];	/* last block curves (rate limit) */
	int16_t ctc1_y_tmp[23];
	/* read as s32/u32 (ADR_S32): 4-byte aligned, otherwise every access is an
	 * address-error exception fixed up by the kernel (~1 us each on XBurst2) */
	uint8_t stat[T40_ADR_STAT_BYTES] __attribute__((aligned(8)));
	uint8_t lut20[32], lut02[32], lut12[32], lut22[32], lut21[32];	/* computed weight tables, restored after a bank refresh */
	int16_t dis5x5[31], coord_m[5], coord_n[7];
	int16_t light[8][11];			/* OEM adr_local_b_light3..10 */
	/* OEM pointer tables (wal/top/soft/hard_para/hard_base) into par and the tables above */
	uint8_t *wal[71], *top[50], *soft[37], *hp[15], *hb[8];
};

static struct t40_adr_ctx *t40_adr T40C2;
static int16_t t40_adr_knee_x[16] T40C2;	/* OEM .data adr_kneepoint_x: the curve filters set [15] = 4095 */
static uint8_t t40_adr_knee_x_set T40C2;
static int32_t t40_adr_gauss_w[24] T40C2;	/* OEM adr_gauss_local */
static int16_t t40_adr_gauss_old[4] T40C2;
static int32_t t40_adr_cut[11] T40C2;		/* OEM adr_cut_base_up */
static uint16_t t40_adr_ctc1_changed T40C2;	/* OEM adr_ctc1_y_change[0] */
static uint16_t t40_adr_ev_changed T40C2, t40_adr_tgain_changed T40C2;
static uint32_t t40_adr_ev_top T40C2, t40_adr_ev T40C2, t40_adr_tgain_top T40C2, t40_adr_tg_f_top T40C2;
static uint32_t t40_adr_width T40C2, t40_adr_height T40C2, t40_adr_frames T40C2;
static uint32_t t40_adr_wdr T40C2;		/* OEM wdr_en_adr: nothing sets it on this driver */
static DEFINE_MUTEX(t40_adr_lock);

#ifdef TX_ISP_LOAD_STATS
/*
 * #133 profile: CP0 Count ticks per step of event 2 (stat_calc, ev_func,
 * algorithm, write_curves, whole event) and of the IRQ 9 statistics read,
 * summed; t40_adr_lowmem=1 makes the next ADR init take the state from
 * kmalloc (unmapped kseg0) instead of vmalloc (TLB-mapped) for an A/B.
 */
static unsigned int t40_adr_cyc[6], t40_adr_cyc_num = 6;
module_param_array_named(t40_adr_cyc, t40_adr_cyc, uint, &t40_adr_cyc_num, 0444);
static bool t40_adr_lowmem;
module_param_named(t40_adr_lowmem, t40_adr_lowmem, bool, 0644);
static bool t40_adr_ctx_low;
#define ADR_PROF_T(v)		((v) = read_c0_count())
#define ADR_PROF_ADD(i, t0)	(t40_adr_cyc[i] += read_c0_count() - (t0))
#else
#define ADR_PROF_T(v)		((v) = 0)
#define ADR_PROF_ADD(i, t0)	((void)(t0))
#endif

static void t40_adr_free(struct t40_adr_ctx *c)
{
#ifdef TX_ISP_LOAD_STATS
	if (t40_adr_ctx_low) {
		kfree(c);
		return;
	}
#endif
	vfree(c);
}

#define ADR_P16(p) ((int16_t *)(void *)(p))

/* OEM tiziano_adr_*_para_refresh: bank copy and the pointer tables */
static void t40_adr_refresh(struct t40_adr_ctx *c)
{
	const uint8_t *bank = (const uint8_t *)(uintptr_t)tparamsN[0];
	const uint16_t *wo = t40_adr_wdr ? t40_adr_wal_wdr : t40_adr_wal_lin;
	uint8_t *p = c->par;
	unsigned int i;

	memcpy(c->par, bank + T40_ADR_PAR_OFFSET, T40_ADR_PAR_BYTES);
	memcpy(c->gamma, bank + T40_ADR_GAMMA_OFFSET, sizeof(c->gamma));
	memcpy(p + 0xa02, c->gamma, 258);
	memcpy(p + 0x110e, (uint8_t *)c->gamma + 0x102, 258);
	for (i = 0; i < 71; i++)
		c->wal[i] = p + wo[i];
	for (i = 0; i < 47; i++)
		c->top[i] = c->wal[i];
	c->top[47] = c->wal[50];
	c->top[48] = c->wal[69];
	c->top[49] = c->wal[70];
	{
		static const uint16_t so[] = { 0, 8, 0x18, 0x38, 0x4c, 0x60, 0x74, 0x88 };
		static const uint16_t so2[] = { 0x9c, 0xb0, 0xc4, 0xd8 };
		static const uint16_t so3[] = { 0xec, 0x100, 0x114 };

		c->soft[0] = c->top[6];
		c->soft[1] = c->top[7];
		c->soft[2] = c->top[28];
		c->soft[3] = c->top[29];
		for (i = 0; i < 3; i++)
			c->soft[4 + i] = c->wal[47 + i];
		for (i = 0; i < 8; i++)
			c->soft[7 + i] = p + so[i];
		c->soft[15] = c->wal[51];
		c->soft[16] = c->wal[52];
		for (i = 0; i < 4; i++)
			c->soft[17 + i] = p + so2[i];
		for (i = 0; i < 3; i++)
			c->soft[21 + i] = c->wal[53 + i];
		for (i = 0; i < 3; i++)
			c->soft[24 + i] = p + so3[i];
		for (i = 0; i < 10; i++)
			c->soft[27 + i] = c->wal[56 + i];
	}
	{
		static const uint16_t ho[] = { 0x128, 0x13c, 0x1fc, 0x21c, 0x246, 0x262, 0x502, 0x51a, 0x532, 0x54a, 0x562 };
		static const uint16_t bo[] = { 0x144, 0x14e, 0x15c, 0x17c, 0x19c, 0x1bc, 0x1dc, 0x59e };

		for (i = 0; i < 11; i++)
			c->hp[i] = p + ho[i];
		c->hp[11] = c->wal[66];
		c->hp[12] = p + 0x57a;
		c->hp[13] = c->wal[67];
		c->hp[14] = c->wal[68];
		for (i = 0; i < 8; i++)
			c->hb[i] = p + bo[i];
	}
}

/* distance class of a pixel to a block centre (OEM tiziano_adr_5x5_out): squared
 * distance in 8-pixel units against the 31 thresholds, 0 = beyond the last */
static int32_t t40_adr_5x5_class(int32_t x, int32_t y, int32_t x0, int32_t y0, const int16_t *tab)
{
	uint32_t dx = (uint32_t)(x0 < x ? x - x0 : x0 - x) >> 3, dy = (uint32_t)(y0 < y ? y - y0 : y0 - y) >> 3;
	int32_t d = (int32_t)(dy * dy + dx * dx), i;

	for (i = 30; i >= 0; i--)
		if (!(tab[i] < d))
			return i + 1;
	return 0;
}

/* the five neighbour weight tables of the 6 x 4 block grid (OEM tiziano_adr_5x5_init):
 * per distance class the mean class to the other block centres */
static int t40_adr_5x5_init(struct t40_adr_ctx *c, int32_t w, int32_t h, const int16_t *tab)
{
	uint32_t (*a)[32] = vzalloc(8 * 32 * sizeof(uint32_t));
	int32_t cw = (w + 3) / 6, ch = (h + 2) / 4, hx = (cw + 1) / 2, hy = (ch + 1) / 2;
	int32_t x0 = hx, x1 = cw + hx, x2 = 2 * cw + hx, y0 = hy, y1 = ch + hy, y2 = 2 * ch + hy, x, y, i;
	uint8_t o[5][32];

	if (!a)
		return -ENOMEM;
	/* a[0..2]: counts per class to (x1,y1) / (x1,y2) / (x2,y1); a[3..7]: class sums */
	for (y = 2 * ch; y <= 3 * ch; y++)
		for (x = 2 * cw; x <= 3 * cw; x++) {
			int32_t k = t40_adr_5x5_class(y, x, y1, x1, tab);

			a[0][k]++;
			a[3][k] += t40_adr_5x5_class(y, x, y0, x0, tab);
			a[4][k] += t40_adr_5x5_class(y, x, y1, x0, tab);
			a[6][k] += t40_adr_5x5_class(y, x, y0, x1, tab);
			k = t40_adr_5x5_class(y, x, y2, x1, tab);
			a[1][k]++;
			a[5][k] += t40_adr_5x5_class(y, x, y2, x0, tab);
			k = t40_adr_5x5_class(y, x, y1, x2, tab);
			a[2][k]++;
			a[7][k] += t40_adr_5x5_class(y, x, y0, x2, tab);
		}
	/* empty classes repeat the one before (class 0: 0) */
	for (i = 0; i < 32; i++) {
		uint32_t n;

		n = a[0][i];
		if (!n) {
			o[2][i] = i ? o[2][i - 1] : 0;
			o[3][i] = i ? o[3][i - 1] : 0;
			o[4][i] = i ? o[4][i - 1] : 0;
		} else {
			o[2][i] = ((int32_t)n / 2 + (int32_t)a[4][i]) / (int32_t)n;
			o[3][i] = ((int32_t)n / 2 + (int32_t)a[3][i]) / (int32_t)n;
			o[4][i] = ((int32_t)n / 2 + (int32_t)a[6][i]) / (int32_t)n;
		}
		n = a[1][i];
		o[1][i] = n ? ((int32_t)n / 2 + (int32_t)a[5][i]) / (int32_t)n : i ? o[1][i - 1] : 0;
		n = a[2][i];
		o[0][i] = n ? ((int32_t)n / 2 + (int32_t)a[7][i]) / (int32_t)n : i ? o[0][i - 1] : 0;
	}
	for (i = 0; i < 5; i++)
		memcpy(c->hb[2 + i], o[i], 32);
	vfree(a);
	return 0;
}

/* block grid and distance thresholds for the frame size (OEM tiziano_adr_base_pars) */
static int t40_adr_base_pars(struct t40_adr_ctx *c, int32_t w, int32_t h)
{
	int32_t bw = w / 6, bh = h / 4, a, b, v, i;
	int16_t m[5], n[7], t[31];
	int64_t v2;

	if (bh & 1)
		bh--;
	if (bw & 1)
		bw--;
	n[0] = 0;
	for (i = 1; i < 6; i++)
		n[i] = i * bw;
	n[6] = w;
	for (i = 0; i < 4; i++)
		m[i] = i * bh;
	m[4] = h;
	memcpy(c->hb[0], m, sizeof(m));
	memcpy(c->hb[1], n, sizeof(n));
	a = (bw + 1) / 2;
	b = (bh + 1) / 2;
	v = (3 * (b < a ? b : a) + 1) / 2;
	v2 = (int64_t)v * v;
	for (i = 0; i < 31; i++)
		t[i] = (uint16_t)((uint64_t)(v2 * t40_adr_5x5_in2[i] + 0x20000) >> 18);
	memcpy(c->hb[7], t, sizeof(t));
	return t40_adr_5x5_init(c, w, h, t);
}

/* ---- statistics ---- */

#define ADR_S32(c, o) ((int32_t *)(void *)((c)->stat + (o)))

/* one 4 KiB statistics slot (OEM tiziano_adr_read_data): 512 x 21-bit histogram,
 * 24 blocks x (20 x 18-bit histogram + four 29/12-bit sums) */
static void t40_adr_read_data(struct t40_adr_ctx *c, const uint8_t *buf)
{
	uint32_t *s = (uint32_t *)(void *)c->stat;
	int r, cc, j, k;

	for (r = 0; r < 4; r++)
		for (cc = 0; cc < 6; cc++) {
			const uint8_t *b = buf + 8 + 336 * r + 56 * cc;
			uint32_t w[14], *h = s + ADR_S_BLK / 4 + (cc * 4 + r) * 20;
			uint64_t acc;
			int bits, kk;

			for (k = 0; k < 14; k++)
				w[k] = (uint32_t)b[4 * k] | (uint32_t)b[4 * k + 1] << 8 | (uint32_t)b[4 * k + 2] << 16 |
				       (uint32_t)b[4 * k + 3] << 24;
			/* 20 x 18 bits from the start of the block */
			acc = 0;
			bits = 0;
			kk = 0;
			for (j = 0; j < 20; j++) {
				while (bits < 18) {
					acc |= (uint64_t)w[kk++] << bits;
					bits += 32;
				}
				h[j] = (uint32_t)acc & 0x3ffff;
				acc >>= 18;
				bits -= 18;
			}
			s[ADR_S_C / 4 + cc * 4 + r] = w[11] >> 8 & 0xfff;
			s[ADR_S_D / 4 + cc * 4 + r] = w[11] >> 20;
			s[ADR_S_A / 4 + cc * 4 + r] = w[12] & 0x1fffffff;
			s[ADR_S_B / 4 + cc * 4 + r] = w[13] & 0x1fffffff;
		}
	for (k = 0; k < 171; k++) {
		const uint8_t *b = buf + 0x548 + 8 * k;
		uint32_t lo = (uint32_t)b[0] | (uint32_t)b[1] << 8 | (uint32_t)b[2] << 16 | (uint32_t)b[3] << 24;
		uint32_t hi = (uint32_t)b[4] | (uint32_t)b[5] << 8 | (uint32_t)b[6] << 16 | (uint32_t)b[7] << 24;

		s[3 * k] = lo & 0x1fffff;
		s[3 * k + 1] = ((hi << 11) & 0x1ff800) | lo >> 21;
		if (k < 170)
			s[3 * k + 2] = hi >> 10 & 0x1fffff;
	}
}

/* normalisation of the statistics (OEM tiziano_adr_stat_calc) */
static void t40_adr_stat_calc(struct t40_adr_ctx *c)
{
	int32_t n = (int32_t)(t40_adr_width * t40_adr_height) / 4, nb, acc = 0, i, b;
	uint32_t sa = 0, sb = 0;
	int32_t *s = ADR_S32(c, 0);
	static const uint8_t pairs[14][2] = { { 0, 0 }, { 1, 1 }, { 2, 3 }, { 4, 5 }, { 6, 7 }, { 8, 8 }, { 9, 9 },
					      { 10, 11 }, { 12, 12 }, { 13, 14 }, { 15, 15 }, { 16, 17 }, { 18, 18 }, { 19, 19 } };

	if (n < 5120)
		n = 5120;
	nb = n / 24;
	for (i = 0; i < 24; i++) {
		int32_t a = s[ADR_S_A / 4 + i], bb = s[ADR_S_B / 4 + i];


		sa += a;
		sb += bb;
		s[ADR_S_C2 / 4 + i] = s[ADR_S_C / 4 + i];
		s[ADR_S_D2 / 4 + i] = s[ADR_S_D / 4 + i];
		s[ADR_S_AN / 4 + i] = a / nb;
		s[ADR_S_BN / 4 + i] = bb / nb;
	}
	s[ADR_S_MEAN / 4] = (int32_t)sa / n;
	s[ADR_S_MEAN / 4 + 1] = (int32_t)sb / n;
	for (i = 0; i < 512; i++) {
		acc += s[ADR_S_HIST / 4 + i];
		if (acc >= n)
			acc = n;
		s[ADR_S_CDF / 4 + i] = (int32_t)((uint32_t)((acc << 8) / (n >> 8)) * 10000U) / 0x10000;
	}
	for (b = 0; b < 24; b++) {
		const int32_t *h = s + ADR_S_BLK / 4 + 20 * b;

		for (i = 0; i < 14; i++) {
			int32_t v = h[pairs[i][0]] + (pairs[i][1] != pairs[i][0] ? h[pairs[i][1]] : 0);

			s[ADR_S_BLKN / 4 + 14 * b + i] = (int32_t)((uint32_t)v * 10000U) / nb;
		}
	}
}
/* ---- register writers ---- */

static inline uint32_t t40_adr_pair(const uint8_t *p, uint32_t m)
{
	const uint16_t *v = (const uint16_t *)(const void *)p;

	return (v[0] & m) | (uint32_t)(v[1] & m) << 16;
}
static void t40_adr_write_pairs(uint32_t reg, const uint8_t *p, unsigned int n, uint32_t m)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		system_reg_write(reg + 4 * i, t40_adr_pair(p + 4 * i, m));
}

/* block grid (OEM func_adr_reg_write_one) */
static void t40_adr_write_grid(const struct t40_adr_ctx *c)
{
	t40_adr_write_pairs(0x9030, c->hb[0], 2, 0x1fff);
	system_reg_write(0x9038, ADR_P16(c->hb[0])[4] & 0x1fff);
	t40_adr_write_pairs(0x903c, c->hb[1], 3, 0x1fff);
	system_reg_write(0x9048, ADR_P16(c->hb[1])[6] & 0x1fff);
}

/* neighbour weights and distance thresholds (OEM func_adr_reg_write_5x5) */
static void t40_adr_write_5x5(const struct t40_adr_ctx *c)
{
	unsigned int t, i;

	for (t = 0; t < 5; t++)
		for (i = 0; i < 8; i++) {
			const uint8_t *b = c->hb[2 + t] + 4 * i;

			system_reg_write(0x904c + 32 * t + 4 * i, (b[0] & 0x1f) | (b[1] & 0x1f) << 8 | (b[2] & 0x1f) << 16 |
					 (uint32_t)(b[3] & 0x1f) << 24);
		}
	for (i = 0; i < 15; i++)
		system_reg_write(0x949c + 4 * i, t40_adr_pair(c->hb[7] + 4 * i, 0xffff));
	system_reg_write(0x94d8, (uint16_t)ADR_P16(c->hb[7])[30]);
}

/* control, curve and limit registers (OEM func_adr_reg_write_sometimes) */
static void t40_adr_write_ctl(const struct t40_adr_ctx *c)
{
	const uint8_t *h0 = c->hp[0], *h1 = c->hp[1], *h13 = c->hp[13], *h14 = c->hp[14];
	unsigned int i;

	system_reg_write(0x9014, (uint16_t)ADR_P16(h0)[0]);
	t40_adr_write_pairs(0x94dc, h0 + 2, 2, 0xfff);
	system_reg_write(0x901c, h0[10]);
	system_reg_write(0x9018, h0[12]);
	system_reg_write(0x901c, h0[14]);
	system_reg_write(0x9010, t40_adr_pair(h0 + 16, 0xfff));
	system_reg_write(0x9008, (h1[0] & 1) | (h1[1] & 1) << 4 | (h1[2] & 1) << 8 | (h1[3] & 1) << 12 |
			 (h1[4] & 1) << 16 | (h1[5] & 1) << 20 | (uint32_t)(h1[6] & 1) << 24);
	system_reg_write(0x9020, (ADR_P16(h13)[0] & 1) | (ADR_P16(h13)[1] & 1) << 1);
	system_reg_write(0x9024, t40_adr_pair(h13 + 4, 0xfff));
	system_reg_write(0x9028, ADR_P16(h14)[0] & 1);
	t40_adr_write_pairs(0x94e8, h14 + 2, 2, 0xfff);
	system_reg_write(0x94f0, ((uint32_t)ADR_P16(h14)[6] << 16 & 0xff0000) | h14[10]);
	system_reg_write(0x94f4, ((uint32_t)ADR_P16(h14)[8] << 16 & 0xff0000) | h14[14]);
	system_reg_write(0x94f8, t40_adr_pair(h14 + 18, 0xf));
	system_reg_write(0x94fc, ADR_P16(h14)[11] & 0xf);
	for (i = 0; i < 5; i++)
		t40_adr_write_pairs(0x93f4 + 24 * i, c->hp[6 + i], 6, 0x3fff);
	t40_adr_write_pairs(0x946c, c->hp[11], 2, 0xfff);
	system_reg_write(0x9474, ADR_P16(c->hp[11])[4] & 0xfff);
	t40_adr_write_pairs(0x9478, c->hp[12], 9, 0xfff);
}

/* per-frame curves (OEM func_adr_reg_write_every) */
static void t40_adr_write_curves(const struct t40_adr_ctx *c)
{
	t40_adr_write_pairs(0x90ec, c->hp[2], 8, 0xfff);
	t40_adr_write_pairs(0x910c, c->hp[3], 10, 0xfff);
	system_reg_write(0x9134, ADR_P16(c->hp[3])[20] & 0xfff);
	t40_adr_write_pairs(0x9138, c->hp[4], 7, 0xfff);
	t40_adr_write_pairs(0x9154, c->hp[5], 168, 0xfff);
}

/* ---- per-frame algorithm ---- */

/* the 44 inputs of Tiziano_adr_fpga (OEM adr_main_fpga_para), by index: f<n> = entry n.
 * hp2..hp5: register images written every frame; f6: debug/mode word, f7: readout,
 * f8: gauss enable, f16: brightness readout, f23: local light mode, f24: envelope,
 * f29: tone curve, f30: luma gains, f31: curve filter, f34: curve mix, f35: rate limit/fade,
 * f36..f43: strength, segment gains and the gamma (top parameters) */
struct t40_adr_fpga_in {
	int16_t *hp2, *hp3, *hp4, *hp5;
	int16_t *f6, *f7, *f8, *f16, *f23, *f24, *f29, *f30, *f31, *f34, *f35;
	int16_t *f36, *f37, *f38, *f39, *f40, *f41, *f43;
	const int32_t *blkn, *cdf, *an, *bn, *means;
};

static void t40_adr_fpga(struct t40_adr_ctx *c, const struct t40_adr_fpga_in *f)
{
	static const int16_t x13[13] = { 0, 32, 64, 128, 256, 512, 1024, 1536, 2048, 2560, 3072, 3584, 4095 };
	static const int16_t x9[9] = { 8, 16, 32, 64, 128, 256, 512, 1024, 2048 };
	int16_t *knx = t40_adr_knee_x, t17[17], m16[16], y13[13], g13[13], c13[13], i13[13];
	int32_t w[24], r14[14], q14[14], v14[14], z14[14], o14[14], acc, i, j, b, lo, hi;
	int32_t p34_0 = f->f34[0], p34_1 = f->f34[1], p34_2 = f->f34[2], p34_5 = f->f34[5];
	int32_t p34_6 = f->f34[6], p34_7 = f->f34[7], p34_8 = f->f34[8], wsum;
	int32_t t6_0 = f->f36[0];

	/* brightness readout: cdf increments weighted by imgDR_w, partial sums at 16/32/64/96 */
	for (acc = 0, i = 0; i < 128; i++) {
		int32_t d = i ? f->cdf[i] - f->cdf[i - 1] : f->cdf[0];

		acc += (int32_t)((uint32_t)d * (uint32_t)t40_adr_img_dr_w[i]);
		if (i == 16)
			f->f16[1] = acc / T40_ADR_IMG_DR_SUM;
		else if (i == 32)
			f->f16[2] = acc / T40_ADR_IMG_DR_SUM;
		else if (i == 64)
			f->f16[3] = acc / T40_ADR_IMG_DR_SUM;
		else if (i == 96)
			f->f16[4] = acc / T40_ADR_IMG_DR_SUM;
	}
	f->f16[0] = acc / T40_ADR_IMG_DR_SUM;

	/* local strength per block from its brightness */
	lo = 4095;
	hi = 0;
	for (b = 0; b < 24; b++) {
		int32_t a = f->an[b], v, d;

		if (hi < a)
			hi = a;
		if (a < lo)
			lo = a;
		if (f->f23[0] == 3) {
			v = (int32_t)((uint32_t)f->f23[(b & 3) * 6 + (b >> 2) + 5] * (uint32_t)t6_0) / 51200;
		} else if (f->f23[0] == 2) {
			for (i = 0; i < 17; i++) {
				int16_t t = i < 3 ? f->f36[i + 1] : i < 11 ? f->f39[i] : 0;

				t17[i] = t < 0 ? 0 : t > 1024 ? 1024 : t;
			}
			v = (int32_t)((uint32_t)t40_adr_int16((int16_t)a, t40_adr_light_b_in, t17, 17) * (uint32_t)t6_0) / 51200;
		} else {
			v = t40_adr_local_info(t6_0, f->f36[1], f->f36[2], f->f36[3], a);
		}
		w[b] = f->f8[15] == 1 ? (int32_t)((uint32_t)v * (uint32_t)t40_adr_gauss_w[b]) / 10000 : v;
		/* debug readout of one quantity, 8 blocks at a time */
		d = f->f6[0] == 2 ? v : f->f6[0] == 3 ? a : f->f6[0] == 4 ? f->bn[b] :
		    f->f6[0] == 5 ? t40_adr_gauss_w[b] : 0;
		if (b < 8 ? f->f6[1] == 0 : b < 16 ? f->f6[1] == 1 : f->f6[1] == 2)
			f->f7[b % 8 + 2] = d;
	}
	if (f->f6[0] == 0) {
		f->f7[2] = f->means[0];
		f->f7[3] = f->means[1];
	}
	if (f->f6[0] == 1) {
		f->f7[2] = lo;
		f->f7[3] = hi;
	}

	/* knee curve shape (14 knots between identity and the shaped curve) */
	if (p34_0 == 1) {
		int32_t k = p34_2 + 155, s = p34_1 < 0 ? 0 : p34_1 > 100 ? 100 : p34_1;

		if (k < 155)
			k = 155;
		if (k > 255)
			k = 255;
		t40_adr_map_curve1(v14, 30, k);
		for (j = 0; j < 14; j++)
			f->hp4[j] = (int32_t)((uint32_t)knx[j + 1] * 100U + (uint32_t)(v14[j] - knx[j + 1]) * (uint32_t)s + 50) / 100;
	} else {
		for (j = 0; j < 14; j++)
			f->hp4[j] = knx[j + 1];
	}
	/* luma-dependent gains */
	if (f->f30[10] == 1) {
		int16_t t9[9];

		for (i = 0; i < 9; i++) {
			int32_t v = f->f30[i] < 0 ? 0 : f->f30[i] > 800 ? 800 : f->f30[i];

			t9[i] = (v << 10) / 100;
		}
		for (i = 0; i < 16; i++)
			f->hp2[i] = t40_adr_int16(knx[i], x9, t9, 9);
	} else {
		for (i = 0; i < 16; i++)
			f->hp2[i] = 1024;
	}
	/* colour-tone curve through the gamma (only when its table changed) */
	if (t40_adr_ctc1_changed == 1) {
		t40_adr_ctc1_changed = 0;
		y13[0] = 0;
		y13[12] = 4095;
		for (i = 0; i < 11; i++)
			y13[i + 1] = f->f29[i];
		if (f->f29[19] == 1) {
			t40_adr_interp1(t40_adr_top_gam_x, f->f43, x13, g13, 129, 13);
			t40_adr_interp1(x13, y13, g13, c13, 13, 13);
			t40_adr_interp1(f->f43, t40_adr_top_gam_x, c13, i13, 129, 13);
			t40_adr_interp1(x13, i13, t40_adr_ctc1_x, c->ctc1_y_tmp, 13, 23);
			for (i = 0; i < 21; i++)
				f->hp3[i] = c->ctc1_y_tmp[i + 1];
		} else {
			for (i = 0; i < 21; i++)
				f->hp3[i] = t40_adr_ctc1_x[i + 1];
		}
	}

	/* one 14-knot curve per block */
	t40_adr_sorted_tab = t40_adr_check_sorted(f->cdf);
	t40_adr_sorted_xs[0] = t40_adr_check_sorted16(t40_adr_top_gam_x);
	t40_adr_sorted_xs[1] = t40_adr_check_sorted16(f->f43);
	wsum = p34_6 + p34_7 + p34_8;
	if (wsum <= 0)
		wsum = 1;
	for (b = 0; b < 24; b++) {
		int16_t a8[8], b8[8], *row = f->hp5 + 14 * b;
		const int32_t *bh = f->blkn + 14 * b;
		int32_t s = w[b];

		/* global curve knees for this block's strength */
		t40_adr_subsection_up(t40_adr_cut, s, t40_adr_top_gam_x, f->f43, f->cdf, 8, 10, 16, 1);
		if (t40_adr_cut[0] <= 0)
			t40_adr_cut[0] = 1;
		for (i = 0; i < 10; i++)
			if (!(t40_adr_cut[i] < t40_adr_cut[i + 1]))
				t40_adr_cut[i + 1] = t40_adr_cut[i] + 1;
		a8[0] = 0;
		a8[7] = 4095;
		for (i = 0; i < 7; i++)
			b8[i] = t40_adr_cut[i];
		b8[7] = t40_adr_cut[10];
		for (j = 0; j < 6; j++) {
			int16_t g = f->f37[j] >= 251 ? 250 : f->f37[j], v, d;

			f->f37[j] = g;
			v = (int16_t)(((int32_t)f->f41[j] * g + 50) / 100);
			d = (int16_t)(b8[j + 1] - b8[j]);
			a8[j + 1] = a8[j] + (v < d ? d : v);
			f->f40[j] = v;
		}
		f->f40[9] = f->f40[4];
		f->f40[10] = f->f40[5];
		f->f40[7] = f->f40[0] + f->f40[1];
		f->f40[8] = f->f40[2] + f->f40[3];
		t40_adr_interp1(b8, a8, knx, m16, 8, 16);
		for (i = 0; i < 14; i++)
			r14[i] = m16[i + 1];
		/* histogram equalisation curve, clipped per segment */
		for (j = 0; j < 14; j++) {
			int32_t kd = t40_adr_knee_diff[j], lim = (int32_t)((uint32_t)bh[j] * 4095U + 5000) / 10000, v, inc;

			v = j < 11 ? f->f38[j] : f->f39[j - 11];
			v = (int32_t)((uint32_t)v * (uint32_t)kd + 32) / 64;
			if (v < lim)
				inc = v;
			else if (!(lim < kd))
				inc = lim;
			else
				inc = (int32_t)((uint32_t)(j ? 4095 - q14[j - 1] : 4095) * (uint32_t)(knx[j + 1] - knx[j])) /
				      (4095 - knx[j]);
			q14[j] = j ? q14[j - 1] + inc : inc;
			if (q14[j] >= 4096)
				q14[j] = 4095;
		}
		for (j = 0; j < 14; j++) {
			int32_t k = knx[j + 1];

			if (q14[j] < k)
				q14[j] = k;
			q14[j] = (int32_t)((uint32_t)k * (uint32_t)(100 - s) + (uint32_t)s * (uint32_t)q14[j] + 50) / 100;
		}
		t40_adr_map_curve1(v14, f->f36[4], f->f36[5]);
		for (j = 0; j < 14; j++) {
			int32_t k = knx[j + 1];

			if (v14[j] < k)
				v14[j] = k;
			v14[j] = (int32_t)((uint32_t)k * (uint32_t)(100 - s) + (uint32_t)s * (uint32_t)v14[j] + 50) / 100;
		}
		for (j = 0; j < 14; j++)
			z14[j] = (int32_t)((uint32_t)p34_7 * q14[j] + (uint32_t)p34_6 * r14[j] + (uint32_t)p34_8 * v14[j]) / wsum;
		for (j = 0; j < 14; j++)
			o14[j] = p34_5 == 0 ? r14[j] : p34_5 == 1 ? q14[j] : p34_5 == 2 ? v14[j] : p34_5 == 3 ? z14[j] : knx[j + 1];
		if (f->f31[9] == 1)
			t40_adr_map_filter_sp(knx, o14, 3);
		else if (f->f31[9] == 2)
			t40_adr_map_filter_sp(knx, o14, f->f31[8]);
		else if (f->f31[9] == 3)
			t40_adr_map_filter(knx, o14, f->f31[8], f->f31[7]);
		for (j = 0; j < 14; j++)
			row[j] = o14[j];
	}

	t40_adr_sorted_tab = NULL;
	t40_adr_sorted_xs[0] = t40_adr_sorted_xs[1] = NULL;

	/* rate limit against the last frame */
	if (f->f35[0] != 1) {
		memcpy(c->map_y_old, f->hp5, sizeof(c->map_y_old));
	} else {
		int32_t lim = f->f35[1] < 513 ? f->f35[1] : 512;

		if (f->f35[2] != 9 && lim <= 0)
			lim = 1;
		for (b = 0; b < 24; b++) {
			int16_t *row = f->hp5 + 14 * b, *old = c->map_y_old[b];
			int32_t md = 0, k;

			for (j = 0; j < 14; j++) {
				int32_t d = old[j] < row[j] ? row[j] - old[j] : old[j] - row[j];

				if (md < d)
					md = d;
			}
			if (!(lim < md)) {
				for (j = 0; j < 14; j++) {
					int16_t v = row[j] > 4082 + j ? 4082 + j : row[j];

					row[j] = old[j] = v;
				}
				continue;
			}
			k = (int32_t)((uint32_t)lim << 21) / md;
			for (j = 0; j < 14; j++) {
				int32_t o = old[j], n = row[j];
				int16_t v;

				if (o < n)
					v = (uint16_t)o + ((int32_t)((uint32_t)(n - o) * (uint32_t)k + 0x100000) >> 21);
				else
					v = (uint16_t)o - ((int32_t)((uint32_t)(o - n) * (uint32_t)k + 0x100000) >> 21);
				if (v > 4082 + j)
					v = 4082 + j;
				row[j] = old[j] = v;
			}
		}
	}
	/* lower envelope */
	if (f->f24[0] == 1) {
		for (b = 0; b < 24; b++) {
			int16_t *row = f->hp5 + 14 * b;
			int32_t v = 0;

			for (j = 0; j < 14; j++) {
				int32_t dk = knx[j + 1] - knx[j];

				if (!dk)
					dk = 1;
				v += (int32_t)((uint32_t)f->f24[j + 1] * (uint32_t)dk + 50) / 100;
				if (row[j] < v)
					v = row[j];
				v = (int16_t)v;
				row[j] = v;
			}
		}
	}
	/* fade to identity for bright frames */
	if (f->f35[4] == 1) {
		int32_t idx = f->f35[7] < 0 ? 0 : f->f35[7], v, l = f->f35[5], h = f->f35[6];

		if ((int16_t)idx >= 512)
			idx = 511;
		v = (int16_t)f->cdf[(int16_t)idx];
		if (v < l)
			return;
		for (b = 0; b < 24; b++) {
			int16_t *row = f->hp5 + 14 * b;

			for (j = 0; j < 14; j++)
				row[j] = h < v ? knx[j + 1] :
					 row[j] - (int32_t)((uint32_t)(row[j] - knx[j + 1]) * (uint32_t)(v - l)) / (h - l);
		}
	}
}

#define ADR_T16(c, i) ADR_P16((c)->top[i])
#define ADR_F16(c, i) ADR_P16((c)->soft[i])

/* OEM tiziano_adr_algorithm: gamma segment slopes, then the curve computation */
static void t40_adr_algorithm(struct t40_adr_ctx *c)
{
	static const int16_t xq7[7] = { 0, 256, 512, 768, 1024, 1536, 2048 };
	struct t40_adr_fpga_in f;
	int16_t g7[7], *d = ADR_T16(c, 26);
	int i;

	t40_adr_interp1(ADR_T16(c, 47), t40_adr_top_gam_x, xq7, g7, 129, 7);	/* inverse gamma */
	for (i = 0; i < 6; i++)
		d[i] = g7[i + 1] - g7[i];
	d[9] = d[4];
	d[10] = d[5];
	d[7] = d[0] + d[1];
	d[8] = d[2] + d[3];
	f.hp2 = ADR_P16(c->hp[2]);
	f.hp3 = ADR_P16(c->hp[3]);
	f.hp4 = ADR_P16(c->hp[4]);
	f.hp5 = ADR_P16(c->hp[5]);
	f.f6 = ADR_F16(c, 12);
	f.f7 = ADR_F16(c, 13);
	f.f8 = ADR_F16(c, 6);
	f.blkn = ADR_S32(c, ADR_S_BLKN);
	f.cdf = ADR_S32(c, ADR_S_CDF);
	f.an = ADR_S32(c, ADR_S_AN);
	f.bn = ADR_S32(c, ADR_S_BN);
	f.means = ADR_S32(c, ADR_S_MEAN);
	f.f16 = ADR_F16(c, 14);
	f.f23 = ADR_F16(c, 21);
	f.f24 = ADR_F16(c, 22);
	f.f29 = ADR_F16(c, 30);
	f.f30 = ADR_F16(c, 31);
	f.f31 = ADR_F16(c, 32);
	f.f34 = ADR_F16(c, 35);
	f.f35 = ADR_F16(c, 36);
	f.f36 = ADR_T16(c, 6);
	f.f37 = ADR_T16(c, 7);
	f.f38 = ADR_T16(c, 28);
	f.f39 = ADR_T16(c, 29);
	f.f40 = ADR_T16(c, 25);
	f.f41 = ADR_T16(c, 26);
	f.f43 = ADR_T16(c, 47);
	t40_adr_fpga(c, &f);
}

/* EV-dependent parameters, after an EV change (OEM tiziano_adr_ev_func) */
static void t40_adr_ev_func(struct t40_adr_ctx *c)
{
	const int32_t *ek = (const int32_t *)(const void *)c->top[5];
	int16_t *o0 = ADR_F16(c, 0), *o1 = ADR_F16(c, 1), *o2 = ADR_F16(c, 2), *o3 = ADR_F16(c, 3);
	int16_t *m21 = ADR_F16(c, 21), *m32 = ADR_F16(c, 32), *m33 = ADR_F16(c, 33), *m34 = ADR_F16(c, 34), *m6 = ADR_F16(c, 6);
	int32_t ev = (int32_t)t40_adr_ev_top;
	int i;

#define EVI(ys) ((int16_t)t40_adr_int32(ev, ek, (ys), 11))
	t40_adr_ev = t40_adr_ev_top;
	if (t40_adr_ev_changed != 1)
		return;
	t40_adr_ev_changed = 0;
	for (i = 3; i <= 10; i++)
		o3[i] = 0;
	if (m21[0] == 2) {
		for (i = 0; i < 11; i++) {
			c->light[0][i] = ADR_T16(c, 0)[i];
			c->light[1][i] = i < 4 ? ADR_T16(c, 3)[i] : ADR_T16(c, 4)[i - 4];
			c->light[2][i] = ADR_T16(c, 27)[i];
			c->light[3][i] = ADR_T16(c, 46)[i];
			c->light[4][i] = i < 4 ? ADR_F16(c, 4)[i] : ADR_F16(c, 5)[i - 4];
			c->light[5][i] = ADR_F16(c, 15)[i];
			c->light[6][i] = ADR_F16(c, 16)[i];
			c->light[7][i] = ADR_F16(c, 23)[i];
		}
		for (i = 0; i < 4; i++)
			o0[i] = EVI(ADR_T16(c, 8 + i));
		for (i = 0; i < 8; i++)
			o3[3 + i] = EVI(c->light[i]);
	} else if (m21[0] == 0) {
		for (i = 0; i < 4; i++)
			o0[i] = EVI(ADR_T16(c, 8 + i));
	} else {
		for (i = 0; i < 4; i++)
			o0[i] = m21[1 + i];
	}
	if (!m32[0]) {
		o0[4] = EVI(ADR_T16(c, 44));
		o0[5] = EVI(ADR_T16(c, 45));
	} else {
		o0[4] = m32[1];
		o0[5] = m32[2];
	}
	if (!m34[5]) {
		for (i = 0; i < 11; i++)
			o1[i] = EVI(ADR_T16(c, 12 + i));
		o0[7] = EVI(ADR_T16(c, 23));
		o0[8] = EVI(ADR_T16(c, 24));
	} else {
		for (i = 0; i < 10; i++)
			o1[i] = m33[i];
		o1[10] = m34[0];
		o0[7] = m34[1];
		o0[8] = m34[2];
	}
	o0[9] = 0;
	o0[10] = 0;
	if (!m6[14]) {
		for (i = 0; i < 11; i++)
			o2[i] = EVI(ADR_T16(c, 30 + i));
		for (i = 0; i < 3; i++)
			o3[i] = EVI(ADR_T16(c, 41 + i));
	} else {
		for (i = 0; i < 11; i++)
			o2[i] = m6[i];
		for (i = 0; i < 3; i++)
			o3[i] = m6[11 + i];
	}
#undef EVI
}

/* ---- driver hooks ---- */

static bool regtrace_t40_adr_on = true;
module_param_named(t40_adr_on, regtrace_t40_adr_on, bool, 0644);
MODULE_PARM_DESC(t40_adr_on, "1 (with t40_gates_oem_offset=1) runs the ADR chain and clears TOP bit 7 after a successful init (default 1)");
static bool regtrace_t40_adr_active T40C2;
static unsigned int t40_adr_blocked T40C2;	/* forced statistics fan-out calls not run (ADR runs on its own bit 9) */
t40_bringup_param_named(adr_forced_blocked, t40_adr_blocked, uint, 0444);

/* statistics IRQ 9 (OEM tiziano_adr_main_interrupt_static) */
static int32_t t40_adr_isr(void)
{
	struct t40_adr_ctx *c = t40_adr;
	uint32_t at = system_reg_read(0x9540), phys = *(uint32_t *)(tispinfo + 52), ev[12];
	unsigned int slot;

	for (slot = 0; slot < 4; slot++) {
		uint8_t *b;

		if (at != phys + slot * 0x1000U)
			continue;
		b = (uint8_t *)(uintptr_t)*(uint32_t *)(tispinfo + 48);
		if (!b || !c)
			continue;
		b += slot * 0x1000U;
		dma_cache_sync(NULL, b, 0x1000, (enum dma_data_direction)0);
		{
			uint32_t t0;

			ADR_PROF_T(t0);
			t40_adr_read_data(c, b);
			ADR_PROF_ADD(5, t0);
		}
	}
	memset(ev, 0, sizeof(ev));
	ev[2] = 2;
	tisp_event_push(0, (uintptr_t)ev);
	return 1;
}

/* event 2 (OEM tisp_adr_main_process) */
static int32_t t40_adr_process(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4)
{
	struct t40_adr_ctx *c = t40_adr;
	uint32_t t0, t1;

	(void)a0; (void)a1; (void)a2; (void)a3; (void)a4;
	if (!c)
		return 0;
	mutex_lock(&t40_adr_lock);
	ADR_PROF_T(t0);
	if (t40_adr_frames < 0x10000)
		t40_adr_frames++;
	ADR_PROF_T(t1);
	t40_adr_stat_calc(c);
	ADR_PROF_ADD(0, t1);
	ADR_PROF_T(t1);
	t40_adr_ev_func(c);
	ADR_PROF_ADD(1, t1);
	if (t40_adr_tgain_changed == 1)	/* OEM tiziano_adr_tgain_func: nothing uses the gain yet */
		t40_adr_tgain_changed = 0;
	ADR_PROF_T(t1);
	t40_adr_algorithm(c);
	ADR_PROF_ADD(2, t1);
	ADR_PROF_T(t1);
	t40_adr_write_curves(c);
	ADR_PROF_ADD(3, t1);
	ADR_PROF_ADD(4, t0);
	mutex_unlock(&t40_adr_lock);
	return 0;
}

static void t40_adr_cleanup(void);

/* OEM tisp_main_init -> tisp_adr_main_init(width, height) */
static int t40_adr_init(uint32_t width, uint32_t height)
{
	struct t40_adr_ctx *c;
	int16_t *wh;
	int ret = -ENOMEM, i;

	/* OEM: tisp_deinit -> tisp_adr_main_deinit at every session end */
	if (regtrace_t40_adr_active)
		t40_adr_cleanup();
	if (!tparamsN[0]) {
		ret = -EINVAL;
		goto out;
	}
	if (!t40_adr_knee_x_set) {
		memcpy(t40_adr_knee_x, t40_adr_knee_x_init, sizeof(t40_adr_knee_x));
		t40_adr_knee_x_set = 1;
	}
#ifdef TX_ISP_LOAD_STATS
	t40_adr_ctx_low = t40_adr_lowmem;
	c = t40_adr_ctx_low ? kzalloc(sizeof(*c), GFP_KERNEL) : vzalloc(sizeof(*c));
#else
	c = vzalloc(sizeof(*c));
#endif
	if (!c)
		goto out;
	t40_adr_height = height;
	t40_adr_width = width;
	t40_adr_ctc1_changed = 1;
	for (i = 0; i < (int)T40_ADR_BLOCKS; i++)
		memcpy(c->map_y_old[i], t40_adr_knee_x, 28);
	t40_adr_refresh(c);
	wh = ADR_F16(c, 13);
	if (wh[0] != (int32_t)width || wh[1] != (int32_t)height) {
		wh[0] = width;
		wh[1] = height;
		ret = t40_adr_base_pars(c, width, height);
		if (ret) {
			t40_adr_free(c);
			goto out;
		}
	}
	memcpy(c->lut20, c->hb[2], 32);
	memcpy(c->lut02, c->hb[3], 32);
	memcpy(c->lut12, c->hb[4], 32);
	memcpy(c->lut22, c->hb[5], 32);
	memcpy(c->lut21, c->hb[6], 32);
	memcpy(c->coord_m, c->hb[0], sizeof(c->coord_m));
	memcpy(c->coord_n, c->hb[1], sizeof(c->coord_n));
	memcpy(c->dis5x5, c->hb[7], sizeof(c->dis5x5));
	t40_adr_gauss_local(t40_adr_gauss_w, t40_adr_gauss_old, ADR_F16(c, 34));
	t40_adr_write_grid(c);
	t40_adr_write_5x5(c);
	t40_adr_write_ctl(c);
	t40_adr_write_curves(c);
	t40_adr = c;
	system_irq_func_set(9, (int32_t)(uintptr_t)t40_adr_isr);
	tisp_event_set_cb(0, 2, (int32_t)(uintptr_t)t40_adr_process);
	ret = 0;
out:
	regtrace_t40_adr_active = !ret;
	if (ret)	/* KERN_INFO lines of this driver are dropped (t40_printk) */
		printk(KERN_ERR "tx_isp_t40_recovered: adr init %ux%u failed (%d), TOP bit 7 stays bypassed\n",
		       width, height, ret);
	return ret;
}

/* OEM tisp_day_or_night_s_ctrl -> tisp_adr_dn_params_refresh(sensor 0) */
static int t40_adr_dn_refresh(void)
{
	struct t40_adr_ctx *c = t40_adr;
	int16_t *wh;

	if (!regtrace_t40_adr_active || !c || !tparamsN[0])
		return 0;
	t40_adr_refresh(c);
	wh = ADR_F16(c, 13);
	if (wh[0] != (int32_t)t40_adr_width || wh[1] != (int32_t)t40_adr_height) {
		/* the bank tables are for another size: put the computed ones back */
		wh[0] = t40_adr_width;
		wh[1] = t40_adr_height;
		memcpy(c->hb[2], c->lut20, 32);
		memcpy(c->hb[3], c->lut02, 32);
		memcpy(c->hb[4], c->lut12, 32);
		memcpy(c->hb[5], c->lut22, 32);
		memcpy(c->hb[6], c->lut21, 32);
		memcpy(c->hb[0], c->coord_m, sizeof(c->coord_m));
		memcpy(c->hb[1], c->coord_n, sizeof(c->coord_n));
		memcpy(c->hb[7], c->dis5x5, sizeof(c->dis5x5));
	}
	t40_adr_gauss_local(t40_adr_gauss_w, t40_adr_gauss_old, ADR_F16(c, 34));
	t40_adr_write_grid(c);
	t40_adr_write_5x5(c);
	t40_adr_write_ctl(c);
	t40_adr_write_curves(c);
	return 0;
}

/* OEM tisp_main_long_ev_update -> tisp_adr_ev_update: ev = IT x gain (Q10), kept >> 10 */
static void t40_adr_ev_update(uint64_t ev_q10)
{
	uint32_t ev = (uint32_t)(ev_q10 >> 32) << 22 | (uint32_t)ev_q10 >> 10;

	if (!regtrace_t40_adr_active || t40_adr_ev_top == ev)
		return;
	t40_adr_ev_changed = 1;
	t40_adr_ev_top = ev;
}

/* OEM tisp_main_long_tgain_update -> tisp_adr_tgain_update (16.16) */
static void t40_adr_tgain_update(uint32_t tgain)
{
	if (!regtrace_t40_adr_active ||
	    (t40_adr_tgain_top == tgain >> 16 && t40_adr_tg_f_top == (tgain & 0xffffU)))
		return;
	t40_adr_tgain_changed = 1;
	t40_adr_tgain_top = tgain >> 16;
	t40_adr_tg_f_top = tgain & 0xffffU;
}

/* SetModule_Ratio (DRC), OEM tisp_s_drc_ratio: the strength (tuning +848 enable, +852
 * ratio) scales seven 11-knot tables of the bank, applied with the next EV pass */
static int t40_adr_drc_ratio(void)
{
	static const uint8_t tab[7] = { 12, 13, 14, 15, 16, 17, 8 };
	static const int16_t lim[7] = { 400, 500, 600, 600, 600, 600, 7000 };
	struct t40_adr_ctx *c = t40_adr;
	const uint8_t *bank = (const uint8_t *)(uintptr_t)tparamsN[0];
	uint8_t *tune = (uint8_t *)(uintptr_t)tisp_get_tuning();
	const uint16_t *wo = t40_adr_wdr ? t40_adr_wal_wdr : t40_adr_wal_lin;
	uint32_t s = 128;
	int t, i;

	if (!regtrace_t40_adr_active || !c || !bank)
		return -ENODEV;
	if (tune && *(uint32_t *)(tune + 848))
		s = tune[852];
	for (i = 0; i < 11; i++)
		for (t = 0; t < 7; t++) {
			int32_t v = ((const int16_t *)(const void *)(bank + T40_ADR_PAR_OFFSET + wo[tab[t]]))[i];

			if (s < 129)
				v = v * (int32_t)s / 128;
			else
				v += (int32_t)((s - 128) * (uint32_t)(v < lim[t] ? lim[t] - v : 0)) >> 7;
			ADR_P16(c->wal[tab[t]])[i] = v;
		}
	t40_adr_ev_changed = 1;
	/* OEM: tiziano_adr_top_para_refresh, the top table points at the same parameters */
	return 0;
}

/* module exit / session end: unhook IRQ 9 and event 2, free the state */
static void t40_adr_cleanup(void)
{
	struct t40_adr_ctx *c = t40_adr;

	if (!regtrace_t40_adr_active)
		return;
	regtrace_t40_adr_active = false;
	system_irq_func_set(9, 0);
	tisp_event_set_cb(0, 2, 0);
	mutex_lock(&t40_adr_lock);
	t40_adr = NULL;
	mutex_unlock(&t40_adr_lock);
	t40_adr_free(c);
}

#endif
