/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T40 AWB colour-temperature detector.  Hand translation of the Eufy OEM module (tx-isp-t40.ko):
 *   tisp_awb_ct_detect                   0x1893c (8260 B)
 *   ISPAWBInterpolation1 / 2             0x17c00 / 0x17cb4
 *   func_zone_ct_weight                  0x17d5c
 *   Tiziano_Awb_Ct_Cal                   0x17e04
 *   Tiziano_Awb_Ct_Detect_GrayWorld      0x1888c  -> Tiziano_Awb_Ct_Detect_GrayWorld_mode 0x1813c
 *
 * out = pstMainAwbCtDetectOri, the 34 pointers published by tisp_awb_long_par_update (ctx = pstMainAwbOri):
 *   out[0]  ctx[10]  outer+176   include centres u16 (r,b) pairs; u16 at +38 = cluster-count blend weight (Q8)
 *   out[1]  ctx[48]  inter+13508 u8 [0] include count, [1] exclude count
 *   out[2]  inter+14636          4 knots for the zone-CT prior (low, outer_low, high, outer_high)
 *   out[3]  inter+14652          [0] prior enable, [1] prior floor (Q precision)
 *   out[4]  ctx[31]/[32] outer   15x15 u32 surface weight table (day/night by EV)
 *   out[5]  ctx[0]   outer+0     u16 rows at +2, cols at +6, zone width +8, zone height +38
 *   out[6]  ctx[13]  outer+260   u32 x[15] R/G knots       out[7] ctx[14] outer+320 u32 y[15] B/G knots
 *   out[8]  ctx[33]  outer+2476  15x15 u32 mired table
 *   out[9]  ctx[35]  outer+4404  u8 spatial weights, stride 15
 *   out[10] ctx[20]  outer+444   u32 [0] refine enable (byte), [1] refine upper, [2] refine lower
 *   out[11] ctx[7]   outer+160   u32 colour temperature (result)
 *   out[12] ctx[57]  inter+13600 u16 distance LUT [514]
 *   out[13] ctx[3]   outer+108   u16 precision, fraction
 *   out[14] ctx[26]  outer+572   u16 [0] gray-world 0 enable, [1] gray-world 1 enable (2 = force fallback),
 *                                    [2] gray-world distance refine, [3] gray-world only
 *   out[15] ctx[24]  outer+528   u16 saturation-weight mode (1/2 active)
 *   out[16] ctx[25]  outer+540   u32 [0] cluster mode, [1] shift radius^2, [2] merge radius^2, [3] member radius^2,
 *                                    [4] convergence step, [5] iteration limit
 *   out[17] ctx[11]  outer+216   exclude centres u16 pairs
 *   out[18] ctx[51]  inter+13534 u8 special-light modes [10]       out[19] ctx[28] outer+596 u32 radius [10]
 *   out[20] ctx[52]  inter+13536 u16 special red centres [10]      out[21] ctx[53] inter+13546 u16 special blue [10]
 *   out[22] ctx[43]  inter+5400  u32 ratios: red[z], blue[z + 225] (rows*cols dense, 15x15 on the T40)
 *   out[23] ctx[44]  inter+7200  u32 zone counts
 *   out[24] ctx[45]  inter+10800 u32 saturation plane, stride 15
 *   out[25] ctx[107] inter+50872 u16 14x14 bin histogram [196]
 *   out[26] ctx[108] inter+51264 u32 [36] bin maxima: col[12], row[12], max[12]
 *   out[27] ctx[109] inter+51408 u32 cluster candidates: red[60], blue[60], count[60]
 *   out[28] ctx[110] inter+52128 u32 clusters: red[60], blue[60], count[60], sum[60]
 *   out[30] ctx[112] inter+53988 u32 zone weight plane, stride 15
 *   out[31] ctx[113] inter+54888 u32 refine distance plane, stride 15
 *   out[32] ctx[114] inter+55788 u32 refined weight plane, stride 15
 *   out[33] ctx[115] inter+56688 u32 count-weight plane, stride 15
 * a1 = gains[2] (Q precision, result), a2 = flags[2] (1 = estimate failed).
 * Zone planes use the hardware stride 15 (w = r*15+c); the ratio/count arrays are dense (z = r*cols+c) in the
 * clamp, weight, sum and refine passes and stride 15 (blue at +225) in the cluster and gray-world passes - as in
 * the OEM, identical for the 15x15 zone grid.
 */

static uint32_t t40_awb_ctd_mul2(uint32_t p, uint32_t a, uint32_t b)
{
    return (uint32_t)fix_point_mult2_32((int32_t)p, (int32_t)a, (int32_t)b);
}

static uint32_t t40_awb_ctd_mul3(uint32_t p, uint32_t a, uint32_t b, uint32_t c)
{
    return (uint32_t)fix_point_mult3_32(p, a, b, c);
}

static uint32_t t40_awb_ctd_div(uint32_t p, uint32_t a, uint32_t b)
{
    return (uint32_t)fix_point_div_32((int32_t)p, (int32_t)a, (int32_t)b);
}

static uint32_t t40_awb_ctd_div64(uint32_t p, uint64_t num, uint64_t den)
{
    return (uint32_t)fix_point_div((int32_t)p, 0, (int32_t)(uint32_t)num, (int32_t)(uint32_t)(num >> 32),
                                   (int32_t)(uint32_t)den, (int32_t)(uint32_t)(den >> 32));
}

/* ISPAWBInterpolation1 (OEM 0x17c00): linear interpolation of raw table values s0/s1 (shifted by fraction here)
 * between the raw knots x0/x1 for the Q(fraction) position v.  Result is Q(fraction). */
int64_t ISPAWBInterpolation1(uint32_t p, uint32_t f, uint32_t v, uint32_t x0, uint32_t x1, uint32_t s0, uint32_t s1)
{
    uint32_t dx = (x1 - x0) << f, dv = v - (x0 << f), r;
    if (s1 >= s0) {
        r = t40_awb_ctd_div(p, t40_awb_ctd_mul2(p, (s1 - s0) << f, dv), dx);
        return (s0 << f) + r;
    }
    r = t40_awb_ctd_div(p, t40_awb_ctd_mul2(p, (s0 - s1) << f, dv), dx);
    return (s0 << f) - r;
}

/* ISPAWBInterpolation2 (OEM 0x17cb4): same, but w0/w1 are already Q(fraction) values. */
int64_t ISPAWBInterpolation2(uint32_t p, uint32_t f, uint32_t v, uint32_t y0, uint32_t y1, uint32_t w0, uint32_t w1)
{
    uint32_t dy = (y1 - y0) << f, dv = v - (y0 << f), r;
    if (w1 >= w0) {
        r = t40_awb_ctd_div(p, t40_awb_ctd_mul2(p, w1 - w0, dv), dy);
        return w0 + r;
    }
    r = t40_awb_ctd_div(p, t40_awb_ctd_mul2(p, w0 - w1, dv), dy);
    return w0 - r;
}

/* func_zone_ct_weight (OEM 0x17d5c): temperature prior.  knots = {low, outer_low, high, outer_high}, prm[1] = floor.
 * Unity plateau between low and high, linear ramps to the floor at the outer knots, floor outside. */
int32_t func_zone_ct_weight(uint32_t ct, const uint32_t *knots, const uint32_t *prm, uint32_t p, uint32_t weight)
{
    uint32_t low = knots[0], outer_low = knots[1], high = knots[2], outer_high = knots[3];
    uint32_t floor_ = prm[1], unity = 1U << p, factor = floor_, span;
    if (ct < outer_high && outer_low < ct) {
        if (high < ct) {
            span = outer_high - high;
            factor = span ? (floor_ * span + (outer_high - ct) * (unity - floor_) + (span >> 1)) / span : floor_;
        } else if (ct < low) {
            span = low - outer_low;
            factor = span ? (floor_ * span + (span >> 1) + (ct - outer_low) * (unity - floor_)) / span : floor_;
        } else {
            factor = unity;
        }
    }
    return (int32_t)t40_awb_ctd_mul2(p, weight, factor);
}

/* Bin index of a clamped Q(fraction) ratio in a 15-knot table: 0 below t[0], 15 at t[14], else i+1 with
 * t[i] <= v < t[i+1] (OEM 0x18e8c / 0x17eac search loops). */
static uint32_t t40_awb_ctd_bin(uint32_t v, const uint32_t *t, uint32_t f)
{
    uint32_t i;
    if (v < (t[0] << f)) return 0;
    if (v == (t[14] << f)) return 15;
    for (i = 0; i < 14; i++)
        if (v < (t[i + 1] << f)) return i + 1;
    return 15;
}

/* Bilinear lookup in a 15x15 table for bin indices ix, iy in 1..15 (OEM 0x19058..0x1951c and Tiziano_Awb_Ct_Cal
 * 0x17f28..0x180e4).  Result Q(fraction); the (15,15) corner is tbl[14][14] << f. */
static uint32_t t40_awb_ctd_surface(uint32_t p, uint32_t f, uint32_t r, uint32_t b, uint32_t ix, uint32_t iy,
                                    const uint32_t *x, const uint32_t *y, const uint32_t *tbl)
{
    uint32_t a, c;
    if (ix == 15 && iy == 15)
        return tbl[14 * 15 + 14] << f;
    if (ix == 15)
        return (uint32_t)ISPAWBInterpolation1(p, f, b, y[iy - 1], y[iy], tbl[(iy - 1) * 15 + 14], tbl[iy * 15 + 14]);
    if (iy == 15)
        return (uint32_t)ISPAWBInterpolation1(p, f, r, x[ix - 1], x[ix], tbl[14 * 15 + ix - 1], tbl[14 * 15 + ix]);
    a = (uint32_t)ISPAWBInterpolation1(p, f, r, x[ix - 1], x[ix], tbl[(iy - 1) * 15 + ix - 1], tbl[(iy - 1) * 15 + ix]);
    c = (uint32_t)ISPAWBInterpolation1(p, f, r, x[ix - 1], x[ix], tbl[iy * 15 + ix - 1], tbl[iy * 15 + ix]);
    return (uint32_t)ISPAWBInterpolation2(p, f, b, y[iy - 1], y[iy], a, c);
}

static uint32_t t40_awb_ctd_mired_to_ct(uint32_t f, uint32_t mired_q)
{
    if (!mired_q) return 5000;
    return ((1U << (f - 1)) + t40_awb_ctd_div(f, 1000000U << f, mired_q)) >> f;
}

/* Tiziano_Awb_Ct_Cal (OEM 0x17e04): CT from the mired surface for the Q(fraction) means r, b; writes *out[11]. */
int64_t Tiziano_Awb_Ct_Cal(uintptr_t a0, uint32_t r, uint32_t b)
{
    const uint32_t *out = (const uint32_t *)a0;
    const uint16_t *pf = (const uint16_t *)(uintptr_t)out[13];
    const uint32_t *x = (const uint32_t *)(uintptr_t)out[6], *y = (const uint32_t *)(uintptr_t)out[7];
    const uint32_t *mired = (const uint32_t *)(uintptr_t)out[8];
    uint32_t p = pf[0], f = pf[1], ix, iy, ct;
    if (r < (x[0] << f)) r = x[0] << f;
    if (r > (x[14] << f)) r = x[14] << f;
    if (b < (y[0] << f)) b = y[0] << f;
    if (b > (y[14] << f)) b = y[14] << f;
    ix = t40_awb_ctd_bin(r, x, f); iy = t40_awb_ctd_bin(b, y, f);
    if (!ix) ix = 1;
    if (!iy) iy = 1;
    ct = t40_awb_ctd_mired_to_ct(f, t40_awb_ctd_surface(p, f, r, b, ix, iy, x, y, mired));
    *(uint32_t *)(uintptr_t)out[11] = ct;
    return ct;
}

static uint32_t t40_awb_ctd_dist(uint32_t r, uint32_t b, uint32_t cr, uint32_t cb)
{
    uint32_t dr = r > cr ? r - cr : cr - r, db = b > cb ? b - cb : cb - b;
    return dr * dr + db * db;
}

/* OEM 0x19594 ladder: LUT below 514, then 5/4/3/2/1 steps, 0 from 818. */
static uint32_t t40_awb_ctd_lut(const uint16_t *lut, uint32_t d)
{
    if (d < 514) return lut[d];
    if (d < 540) return 5;
    if (d < 572) return 4;
    if (d < 615) return 3;
    if (d < 679) return 2;
    return d < 818;
}

/* Tiziano_Awb_Ct_Detect_GrayWorld_mode (OEM 0x1813c): gray-world estimate over the ratio half `mode`
 * (0 = first, 1 = second, 225 words apart per plane).  Runs only while flags[0] == 1 and out[14][mode] == 1. */
int64_t Tiziano_Awb_Ct_Detect_GrayWorld_mode(uintptr_t a0, uint32_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4, uint32_t mode)
{
    const uint32_t *ratios = (const uint32_t *)a0, *out = (const uint32_t *)a2;
    uint32_t *gains = (uint32_t *)a3, *flags = (uint32_t *)a4;
    const uint16_t *modes = (const uint16_t *)(uintptr_t)out[14], *pf = (const uint16_t *)(uintptr_t)out[13];
    const uint16_t *o5 = (const uint16_t *)(uintptr_t)out[5];
    const uint32_t *x = (const uint32_t *)(uintptr_t)out[6], *y = (const uint32_t *)(uintptr_t)out[7];
    const uint8_t *spatial = (const uint8_t *)(uintptr_t)out[9];
    const uint16_t *lut = (const uint16_t *)(uintptr_t)out[12];
    uint32_t *wt = (uint32_t *)(uintptr_t)out[30];
    uint32_t p = pf[0], f = pf[1], rows = o5[1], cols = o5[3], unity = 1U << p, round = 1U << (f - 1);
    uint32_t min_r = x[0] << f, max_r = x[14] << f, min_b = y[0] << f, max_b = y[14] << f;
    const uint32_t *red = ratios + mode * 450, *blue = red + 225;
    uint64_t sum_r = 0, sum_b = 0, sum_w = 0;
    uint32_t r, c, mean_r, mean_b;
    (void)a1;
    if (mode > 1 || modes[mode] != 1 || flags[0] != 1) return 0;
    for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
        uint32_t w = r * 15 + c, sp = (uint32_t)spatial[w] << p;
        uint32_t wgt = (red[w] >= min_r && red[w] <= max_r && blue[w] >= min_b && blue[w] <= max_b) ? 4U << p : unity;
        sum_r += t40_awb_ctd_mul3(p, red[w], sp, wgt);
        sum_b += t40_awb_ctd_mul3(p, blue[w], sp, wgt);
        sum_w += t40_awb_ctd_mul2(p, sp, wgt);
    }
    if (!sum_w || !sum_r || !sum_b) {
        flags[0] = 1; *(uint32_t *)(uintptr_t)out[11] = 5000; gains[0] = gains[1] = unity;
        return 0;
    }
    flags[0] = 0;
    mean_r = t40_awb_ctd_div64(p, sum_r, sum_w);
    mean_b = t40_awb_ctd_div64(p, sum_b, sum_w);
    if (modes[2] == 1) {                        /* 0x184f0: distance refine around the mean */
        uint32_t cr = (round + mean_r) >> f, cb = (round + mean_b) >> f;
        uint64_t s2r = 0, s2b = 0, s2w = 0;
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t w = r * 15 + c;
            uint32_t d = t40_awb_ctd_dist((round + red[w]) >> f, (round + blue[w]) >> f, cr, cb);
            wt[w] = t40_awb_ctd_lut(lut, d) << f;
        }
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t w = r * 15 + c, sp = (uint32_t)spatial[w] << p;
            s2r += t40_awb_ctd_mul3(p, red[w], sp, wt[w]);
            s2b += t40_awb_ctd_mul3(p, blue[w], sp, wt[w]);
            s2w += t40_awb_ctd_mul2(p, sp, wt[w]);
        }
        if (!s2w || !s2r || !s2b) {             /* 0x187ec: failed refinement keeps the first mean below */
            flags[0] = 1; *(uint32_t *)(uintptr_t)out[11] = 5000; gains[0] = gains[1] = unity;
        } else {
            mean_r = t40_awb_ctd_div64(p, s2r, s2w);
            mean_b = t40_awb_ctd_div64(p, s2b, s2w);
        }
    }
    (void)Tiziano_Awb_Ct_Cal((uintptr_t)out, mean_r, mean_b);
    gains[0] = mean_r; gains[1] = mean_b;
    return 0;
}

/* Tiziano_Awb_Ct_Detect_GrayWorld (OEM 0x1888c): gray-world 0 then 1, each gated by out[14][0]/[1] == 1. */
uint32_t Tiziano_Awb_Ct_Detect_GrayWorld(uintptr_t a0, uint32_t a1, uintptr_t a2, uintptr_t a3, uintptr_t a4)
{
    const uint32_t *out = (const uint32_t *)a2;
    const uint16_t *modes = (const uint16_t *)(uintptr_t)out[14];
    if (modes[0] == 1) (void)Tiziano_Awb_Ct_Detect_GrayWorld_mode(a0, a1, a2, a3, a4, 0);
    if (modes[1] == 1) (void)Tiziano_Awb_Ct_Detect_GrayWorld_mode(a0, a1, a2, a3, a4, 1);
    return 0;
}

static void t40_awb_ctd_fallback(uint32_t *out, uint32_t *gains, uint32_t *flags, uint32_t p)
{
    flags[0] = flags[1] = 1;
    *(uint32_t *)(uintptr_t)out[11] = 5000;
    gains[0] = gains[1] = 1U << p;
    (void)Tiziano_Awb_Ct_Detect_GrayWorld(out[22], out[23], (uintptr_t)out, (uintptr_t)gains, (uintptr_t)flags);
}

/*
 * Zone search window for the distance tests of (d) and (f) (#133): the zone
 * coordinates (round + ratio) >> f once per call, the zones sorted by the red
 * coordinate, and per centre only the zones with |zr - cr| <= isqrt(limit)
 * tested (dr * dr > limit excludes the rest).  The sums are integer and the
 * counts order-free, so the result equals the full scan; with coordinates or
 * centres >= 32768 (dr * dr + db * db could wrap) the full scan runs.
 */
struct t40_awb_ctd_win {
	uint32_t zr[225], zb[225];
	uint16_t idx[225];
	uint32_t n;
	bool ok;
};
static struct t40_awb_ctd_win t40_awb_ctd_w;

static uint32_t t40_awb_ctd_isqrt(uint32_t v)
{
	uint32_t r = 0, b = 1U << 30;

	while (b > v)
		b >>= 2;
	while (b) {
		if (v >= r + b) {
			v -= r + b;
			r = (r >> 1) + b;
		} else {
			r >>= 1;
		}
		b >>= 2;
	}
	return r;
}

static void t40_awb_ctd_win_init(struct t40_awb_ctd_win *wn, const uint32_t *ratio, uint32_t rows, uint32_t cols,
				 uint32_t f, uint32_t round)
{
	uint32_t r, c, k;

	wn->n = 0;
	wn->ok = rows <= 15 && cols <= 15;
	for (r = 0; r < rows && r < 15; r++)
		for (c = 0; c < cols && c < 15; c++) {
			uint32_t w = r * 15 + c, v;

			wn->zr[w] = (round + ratio[w]) >> f;
			wn->zb[w] = (round + ratio[225 + w]) >> f;
			if (wn->zr[w] >= 32768 || wn->zb[w] >= 32768)
				wn->ok = false;
			/* insertion by zr */
			v = wn->zr[w];
			for (k = wn->n; k > 0 && wn->zr[wn->idx[k - 1]] > v; k--)
				wn->idx[k] = wn->idx[k - 1];
			wn->idx[k] = (uint16_t)w;
			wn->n++;
		}
}

/* first sorted position with zr >= v */
static uint32_t t40_awb_ctd_win_lb(const struct t40_awb_ctd_win *wn, uint32_t v)
{
	uint32_t lo = 0, hi = wn->n;

	while (lo < hi) {
		uint32_t m = (lo + hi) >> 1;

		if (wn->zr[wn->idx[m]] < v)
			lo = m + 1;
		else
			hi = m;
	}
	return lo;
}

/* OEM 0x19844..0x1a048: cluster mode 1.  H = 14x14 histogram, B = bin maxima, C = candidates, D = clusters. */
static void t40_awb_ctd_clusters(const uint32_t *out, uint32_t rows, uint32_t cols, uint32_t f, uint32_t round)
{
    uint16_t *H = (uint16_t *)(uintptr_t)out[25];
    uint32_t *B = (uint32_t *)(uintptr_t)out[26], *C = (uint32_t *)(uintptr_t)out[27], *D = (uint32_t *)(uintptr_t)out[28];
    const uint32_t *x = (const uint32_t *)(uintptr_t)out[6], *y = (const uint32_t *)(uintptr_t)out[7];
    const uint32_t *ratio = (const uint32_t *)(uintptr_t)out[22], *prm = (const uint32_t *)(uintptr_t)out[16];
    const uint32_t *wt = (const uint32_t *)(uintptr_t)out[30];
    uint32_t *wtw = (uint32_t *)(uintptr_t)out[30];
    uint32_t blend = *(const uint16_t *)((uintptr_t)out[0] + 38);
    uint32_t k, i, j, r, c, maxsum = 0, maxc = 0;
    struct t40_awb_ctd_win *wn = &t40_awb_ctd_w;
    /* (a) the 12 largest bins, each removed from the histogram once taken */
    for (k = 0; k < 12; k++) {
        for (r = 0; r < 14; r++) for (c = 0; c < 14; c++) {
            uint32_t v = H[r * 14 + c];
            if (v && B[24 + k] < v) { B[k] = c; B[12 + k] = r; B[24 + k] = v; }
        }
        H[B[12 + k] * 14 + B[k]] = 0;
    }
    /* (b) five candidate centres per bin: corners and middle, in raw knot units */
    for (k = 0; k < 12; k++) {
        uint32_t col = B[k], row = B[12 + k], *cr = C + k * 5, *cb = C + 60 + k * 5;
        if (col > 13) col = 13;
        if (row > 13) row = 13;
        cr[0] = x[col];     cb[0] = y[row];
        cr[1] = x[col];     cb[1] = y[row + 1];
        cr[2] = (x[col] + 1 + x[col + 1]) >> 1; cb[2] = (y[row] + 1 + y[row + 1]) >> 1;
        cr[3] = x[col + 1]; cb[3] = y[row];
        cr[4] = x[col + 1]; cb[4] = y[row + 1];
    }
    /* (c) drop duplicates */
    for (i = 0; i < 60; i++) {
        if (!C[i] || !C[60 + i]) continue;
        for (j = i + 1; j < 60; j++)
            if (C[j] == C[i] && C[60 + j] == C[60 + i]) { C[j] = 0; C[60 + j] = 0; }
    }
    /* (d) mean shift of every candidate over the zones within prm[1] */
    t40_awb_ctd_win_init(wn, ratio, rows, cols, f, round);
    for (i = 0; i < 60; i++) {
        uint32_t iter = 0;
        if (!C[i] || !C[60 + i]) continue;
        for (;;) {
            uint32_t sr = 0, sb = 0, n = 0, nr, nb, dr, db;
            iter++;
            if (wn->ok && C[i] < 32768 && C[60 + i] < 32768) {
                uint32_t rad = t40_awb_ctd_isqrt(prm[1]), q, hi = C[i] + rad;

                for (q = t40_awb_ctd_win_lb(wn, C[i] > rad ? C[i] - rad : 0); q < wn->n; q++) {
                    uint32_t w = wn->idx[q];

                    if (wn->zr[w] > hi)
                        break;
                    if (t40_awb_ctd_dist(wn->zr[w], wn->zb[w], C[i], C[60 + i]) <= prm[1]) { sr += ratio[w]; sb += ratio[225 + w]; n++; }
                }
            } else {
                for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
                    uint32_t w = r * 15 + c;
                    uint32_t d = t40_awb_ctd_dist((round + ratio[w]) >> f, (round + ratio[225 + w]) >> f, C[i], C[60 + i]);
                    if (d <= prm[1]) { sr += ratio[w]; sb += ratio[225 + w]; n++; }
                }
            }
            if (!n) break;
            nr = (((n >> 1) + sr) / n) >> f; nb = (((n >> 1) + sb) / n) >> f;
            dr = C[i] > nr ? C[i] - nr : nr - C[i];
            db = C[60 + i] > nb ? C[60 + i] - nb : nb - C[60 + i];
            if (dr <= prm[4] && db <= prm[4]) break;
            if (prm[5] < iter) break;
            C[i] = nr; C[60 + i] = nb; C[120 + i] = n;
        }
    }
    /* (e) take the heaviest remaining candidate into D[i], absorb all candidates within prm[2] */
    for (i = 0; i < 60; i++) {
        uint32_t tot = 0, sr = 0, sb = 0;
        for (j = 0; j < 60; j++)
            if (C[120 + j] && D[120 + i] < C[120 + j]) { D[i] = C[j]; D[60 + i] = C[60 + j]; D[120 + i] = C[120 + j]; }
        if (!D[120 + i]) continue;
        for (j = 0; j < 60; j++) {
            if (!C[120 + j]) continue;
            if (t40_awb_ctd_dist(D[i], D[60 + i], C[j], C[60 + j]) <= prm[2]) {
                tot += C[120 + j]; sr += C[120 + j] * C[j]; sb += C[120 + j] * C[60 + j]; C[120 + j] = 0;
            }
        }
        if (tot) { D[120 + i] = 0; D[i] = ((tot >> 1) + sr) / tot; D[60 + i] = ((tot >> 1) + sb) / tot; }
    }
    /* (f) members and weight sums per cluster within prm[3] */
    for (i = 0; i < 60; i++) {
        if (!D[i] || !D[60 + i]) continue;
        D[120 + i] = 0; D[180 + i] = 0;
        if (wn->ok && D[i] < 32768 && D[60 + i] < 32768) {
            uint32_t rad = t40_awb_ctd_isqrt(prm[3]), q, hi = D[i] + rad;

            for (q = t40_awb_ctd_win_lb(wn, D[i] > rad ? D[i] - rad : 0); q < wn->n; q++) {
                uint32_t w = wn->idx[q];

                if (wn->zr[w] > hi)
                    break;
                if (!wt[w]) continue;
                if (t40_awb_ctd_dist(wn->zr[w], wn->zb[w], D[i], D[60 + i]) <= prm[3]) {
                    D[120 + i]++; D[180 + i] += wt[w];
                }
            }
            continue;
        }
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t w = r * 15 + c;
            if (!wt[w]) continue;
            if (t40_awb_ctd_dist((round + ratio[w]) >> f, (round + ratio[225 + w]) >> f, D[i], D[60 + i]) <= prm[3]) {
                D[120 + i]++; D[180 + i] += wt[w];
            }
        }
    }
    /* (g)..(i) mean weight per cluster, scale the counts by it, blend with the previous counts */
    for (i = 0; i < 60; i++)
        if (D[120 + i]) D[180 + i] = (D[180 + i] + (D[120 + i] >> 1)) / D[120 + i];
    for (i = 0; i < 60; i++)
        if (D[180 + i] > maxsum) maxsum = D[180 + i];
    for (i = 0; i < 60; i++) {
        uint32_t old = D[120 + i];
        if (maxsum && old) D[120 + i] = (old * D[180 + i] + (maxsum >> 1)) / maxsum;
        D[120 + i] = (blend * old + (256 - blend) * D[120 + i]) >> 8;
    }
    /* (j) zone weights relative to the strongest cluster they belong to */
    for (i = 0; i < 60; i++)
        if (D[120 + i] > maxc) maxc = D[120 + i];
    if (!maxc) return;
    for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
        uint32_t w = r * 15 + c, best = 0;
        uint32_t zr = (round + ratio[w]) >> f, zb = (round + ratio[225 + w]) >> f;
        for (i = 0; i < 60; i++) {
            if (!D[i] || !D[60 + i]) continue;
            if (t40_awb_ctd_dist(zr, zb, D[i], D[60 + i]) > prm[3]) continue;
            if (!best || D[120 + best - 1] < D[120 + i]) best = i + 1;
        }
        wtw[w] = best ? (wt[w] * D[120 + best - 1] + (maxc >> 1)) / maxc : (wt[w] + (maxc >> 1)) / maxc;
    }
}

static unsigned int regtrace_t40_awb_ctd_calls, regtrace_t40_awb_ctd_valid;

int64_t tisp_awb_ct_detect(uintptr_t a0, uintptr_t a1, uint32_t a2)
{
    uint32_t *out = (uint32_t *)a0, *gains = (uint32_t *)a1, *flags = (uint32_t *)(uintptr_t)a2;
    const uint16_t *modes, *pf, *o5, *inc, *exc, *lut, *sred, *sblue;
    const uint32_t *x, *y, *surf, *mired, *knots, *prior, *refp, *cprm, *radius, *sat, *cnt;
    const uint8_t *spatial, *ncent, *smode;
    uint32_t *ratio, *cw, *wt, *dpl, *rw;
    uint16_t *H;
    uint32_t p, f, rows, cols, count, den, round, i, r, c, maxcnt = 0, maxsat = 0, wsum = 0, clusters = 0, few;
    uint32_t cluster_mode, mean_r, mean_b, ct, k;
    uint64_t sum_r = 0, sum_b = 0, sum_w = 0;
    uint32_t st[5] = { 0, 0, 0, 0, 0 };
    unsigned int n = regtrace_t40_awb_ctd_calls++;
    int diag = n < 10 || (regtrace_enable_isp_3a_diag && (n % 300) == 0);	/* issue 133: per frame with t40_vawb, periodic lines only with enable_isp_3a_diag */

    if (!regtrace_is_kernel_ptr(out) || !regtrace_is_kernel_ptr(gains) || !regtrace_is_kernel_ptr(flags)) return 0;
    for (i = 0; i < 34; i++)
        if (i != 29 && !regtrace_is_kernel_ptr_any((void *)(uintptr_t)out[i])) {
            if (diag) printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD out[%u]=0x%x not a kernel pointer - skipped\n", i, out[i]);
            return 0;
        }
    modes = (const uint16_t *)(uintptr_t)out[14]; pf = (const uint16_t *)(uintptr_t)out[13];
    o5 = (const uint16_t *)(uintptr_t)out[5];
    inc = (const uint16_t *)(uintptr_t)out[0]; exc = (const uint16_t *)(uintptr_t)out[17];
    ncent = (const uint8_t *)(uintptr_t)out[1]; lut = (const uint16_t *)(uintptr_t)out[12];
    x = (const uint32_t *)(uintptr_t)out[6]; y = (const uint32_t *)(uintptr_t)out[7];
    surf = (const uint32_t *)(uintptr_t)out[4]; mired = (const uint32_t *)(uintptr_t)out[8];
    knots = (const uint32_t *)(uintptr_t)out[2]; prior = (const uint32_t *)(uintptr_t)out[3];
    refp = (const uint32_t *)(uintptr_t)out[10]; cprm = (const uint32_t *)(uintptr_t)out[16];
    radius = (const uint32_t *)(uintptr_t)out[19]; smode = (const uint8_t *)(uintptr_t)out[18];
    sred = (const uint16_t *)(uintptr_t)out[20]; sblue = (const uint16_t *)(uintptr_t)out[21];
    spatial = (const uint8_t *)(uintptr_t)out[9]; sat = (const uint32_t *)(uintptr_t)out[24];
    ratio = (uint32_t *)(uintptr_t)out[22]; cnt = (const uint32_t *)(uintptr_t)out[23];
    H = (uint16_t *)(uintptr_t)out[25];
    wt = (uint32_t *)(uintptr_t)out[30]; dpl = (uint32_t *)(uintptr_t)out[31]; rw = (uint32_t *)(uintptr_t)out[32];
    cw = (uint32_t *)(uintptr_t)out[33];
    p = pf[0]; f = pf[1]; rows = o5[1]; cols = o5[3]; count = rows * cols; den = (uint32_t)o5[4] * o5[19];
    if (!rows || rows > 15 || !cols || cols > 15 || p > 30 || !f || f > 30 || ncent[0] > 10 || ncent[1] > 10) {
        if (diag) printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD bad geometry rows=%u cols=%u p=%u f=%u inc=%u exc=%u - skipped\n",
                         rows, cols, p, f, ncent[0], ncent[1]);
        return 0;
    }
    round = 1U << (f - 1);
    cluster_mode = cprm[0];
    if (modes[3] == 1) {                                         /* 0x18998: gray-world only */
        t40_awb_ctd_fallback(out, gains, flags, p);
        if (diag) printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD gray-world only ct=%u gains=%u/%u flags=%u/%u\n",
                         *(uint32_t *)(uintptr_t)out[11], gains[0], gains[1], flags[0], flags[1]);
        return 0;
    }
    for (i = 0; i < count; i++)
        if (cnt[i] > maxcnt) maxcnt = cnt[i];
    if (modes[1] == 2 || !maxcnt || !den) {                      /* 0x18bf4: forced or empty -> fallback */
        cw[0] = 0;
        t40_awb_ctd_fallback(out, gains, flags, p);
        if (diag) printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD fallback(empty) maxcnt=%u den=%u mode1=%u ct=%u gains=%u/%u\n",
                         maxcnt, den, modes[1], *(uint32_t *)(uintptr_t)out[11], gains[0], gains[1]);
        return 0;
    }
    for (r = 0; r < rows; r++) for (c = 0; c < cols; c++)
        cw[r * 15 + c] = (cnt[r * cols + c] << p) / den;
    regtrace_t40_awb_ctd_valid++;
    /* 0x18de8: clamp the ratios to the calibration box */
    for (i = 0; i < count; i++) {
        if (ratio[i] < (x[0] << f)) ratio[i] = x[0] << f;
        if (ratio[i] > (x[14] << f)) ratio[i] = x[14] << f;
        if (ratio[count + i] < (y[0] << f)) ratio[count + i] = y[0] << f;
        if (ratio[count + i] > (y[14] << f)) ratio[count + i] = y[14] << f;
    }
    /* 0x18e8c: histogram, surface weight, temperature prior */
    for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
        uint32_t z = r * cols + c, w = r * 15 + c, red = ratio[z], blue = ratio[count + z];
        uint32_t ix = t40_awb_ctd_bin(red, x, f), iy = t40_awb_ctd_bin(blue, y, f), weight;
        if (ix && iy) {
            uint32_t bx = (ix == 15 ? 14 : ix) - 1, by = (iy == 15 ? 14 : iy) - 1;
            H[by * 14 + bx]++;
        }
        if (!ix || !iy) { wt[w] = 0; continue; }
        weight = t40_awb_ctd_surface(p, f, red, blue, ix, iy, x, y, surf);
        if (prior[0] == 1) {
            if (ix == 15 && iy == 15) ct = mired[224] ? 1000000U / mired[224] : 0;
            else ct = (t40_awb_ctd_div(f, 1000000U << f, t40_awb_ctd_surface(p, f, red, blue, ix, iy, x, y, mired)) + round) >> f;
            weight = (uint32_t)func_zone_ct_weight(ct, knots, prior, p, weight);
        }
        wt[w] = weight;
    }
    for (i = 0; i < 225; i++) st[0] += wt[i];
    /* 0x1953c / 0x1966c: include and exclude centres */
    for (i = 0; i < ncent[0]; i++)
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t z = r * cols + c, w = r * 15 + c;
            uint32_t d = t40_awb_ctd_dist((ratio[z] + round) >> f, (ratio[count + z] + round) >> f, inc[2 * i], inc[2 * i + 1]);
            uint32_t v = t40_awb_ctd_lut(lut, d) << f;
            if (wt[w] < v) wt[w] = v;
        }
    for (i = 0; i < ncent[1]; i++)
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t z = r * cols + c, w = r * 15 + c;
            uint32_t d = t40_awb_ctd_dist((ratio[z] + round) >> f, (ratio[count + z] + round) >> f, exc[2 * i], exc[2 * i + 1]);
            uint32_t v = (256 - t40_awb_ctd_lut(lut, d)) << f;
            if (v < wt[w]) wt[w] = v;
        }
    for (i = 0; i < 225; i++) st[1] += wt[i];
    /* 0x18d70: saturation weighting */
    if (*(const uint16_t *)(uintptr_t)out[15] == 1 || *(const uint16_t *)(uintptr_t)out[15] == 2) {
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++)
            if (sat[r * 15 + c] > maxsat) maxsat = sat[r * 15 + c];
        if (maxsat >= 2)
            for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
                uint32_t w = r * 15 + c;
                wt[w] = t40_awb_ctd_div(p, t40_awb_ctd_mul2(p, wt[w], sat[w]), maxsat);
            }
    }
    for (i = 0; i < 225; i++) st[2] += wt[i];
    if (cluster_mode == 1)
        t40_awb_ctd_clusters(out, rows, cols, f, round);
    for (i = 0; i < 225; i++) st[3] += wt[i];
    for (i = 0; i < 60; i++)
        clusters += ((const uint32_t *)(uintptr_t)out[28])[120 + i] >= 5;	/* OEM: the cluster counts (out[28]), not the candidates */
    few = clusters < 2;
    /* 0x1a094: special light centres */
    for (i = 0; i < 10; i++) {
        if (smode[i] != 2) continue;
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t z = r * cols + c, w = r * 15 + c, v;
            uint32_t d = t40_awb_ctd_dist((ratio[z] + round) >> f, (ratio[count + z] + round) >> f, sred[i], sblue[i]);
            if (d >= 615) v = 0;
            else if (d >= 572) v = 3;
            else if (d >= 540) v = 4;
            else if (d >= 514) v = 5;
            else if (d < radius[i] * radius[i] && (cluster_mode == 0 || (cluster_mode == 1 && !few))) v = 256;
            else v = lut[d];
            v = (256 - v) << f;
            if (v < wt[w]) wt[w] = v;
        }
    }
    for (r = 0; r < rows; r++) for (c = 0; c < cols; c++)
        wsum += wt[r * 15 + c];
    if (diag) {                                 /* stage sums of the weight plane + zone (7,7) inputs */
        uint32_t z = 7 * cols + 7, w = 7 * 15 + 7;
        printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD #%u stages surf=%u incexc=%u sat=%u clus=%u spec=%u p=%u f=%u x=%u..%u y=%u..%u z112 r/b=%u/%u ix/iy=%u/%u surf=%u cw=%u cnt=%u maxcnt=%u den=%u prior=%u/%u knots=%u/%u/%u/%u cmode=%u modes=%u/%u/%u/%u sat=%u inc=%u exc=%u smode=%u%u%u%u%u%u%u%u%u%u\n",
               n, st[0], st[1], st[2], st[3], wsum, p, f, x[0], x[14], y[0], y[14], ratio[z], ratio[count + z],
               t40_awb_ctd_bin(ratio[z], x, f), t40_awb_ctd_bin(ratio[count + z], y, f), surf[w], cw[w], cnt[z], maxcnt, den,
               prior[0], prior[1], knots[0], knots[1], knots[2], knots[3], cluster_mode, modes[0], modes[1], modes[2], modes[3],
               *(const uint16_t *)(uintptr_t)out[15], ncent[0], ncent[1], smode[0], smode[1], smode[2], smode[3], smode[4],
               smode[5], smode[6], smode[7], smode[8], smode[9]);
    }
    if (!wsum) {
        t40_awb_ctd_fallback(out, gains, flags, p);
        if (diag) printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD fallback(no weight) maxcnt=%u ct=%u gains=%u/%u flags=%u\n",
                         maxcnt, *(uint32_t *)(uintptr_t)out[11], gains[0], gains[1], flags[0]);
        return 0;
    }
    /* 0x1a264: weighted 64-bit sums */
    flags[0] = 0;
    for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
        uint32_t z = r * cols + c, w = r * 15 + c;
        uint32_t w3 = t40_awb_ctd_mul3(p, wt[w], cw[w], (uint32_t)spatial[w] << p);
        sum_r += t40_awb_ctd_mul2(p, ratio[z], w3);
        sum_b += t40_awb_ctd_mul2(p, ratio[count + z], w3);
        sum_w += w3;
    }
    if (!sum_w) {
        t40_awb_ctd_fallback(out, gains, flags, p);
        if (diag) printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD fallback(zero sum) wsum=%u ct=%u gains=%u/%u\n",
                         wsum, *(uint32_t *)(uintptr_t)out[11], gains[0], gains[1]);
        return 0;
    }
    mean_r = t40_awb_ctd_div64(p, sum_r, sum_w);
    mean_b = t40_awb_ctd_div64(p, sum_b, sum_w);
    /* 0x1a430: refine around the mean */
    if ((refp[0] & 0xffU) == 1) {
        uint32_t acc = 0, variance, upper = refp[1], lower = refp[2];
        for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
            uint32_t z = r * cols + c, w = r * 15 + c;
            uint32_t dr = ratio[z] > mean_r ? ratio[z] - mean_r : mean_r - ratio[z];
            uint32_t db = ratio[count + z] > mean_b ? ratio[count + z] - mean_b : mean_b - ratio[count + z];
            uint32_t d = t40_awb_ctd_mul2(p, dr, dr) + t40_awb_ctd_mul2(p, db, db);
            dpl[w] = d;
            if (cw[w] && wt[w] && spatial[w])
                acc += t40_awb_ctd_mul2(p, t40_awb_ctd_mul3(p, d, wt[w], cw[w]), (uint32_t)spatial[w] << p);
        }
        variance = t40_awb_ctd_div(p, acc, (uint32_t)sum_w);
        if (variance) {
            uint64_t s2r = 0, s2b = 0, s2w = 0;
            for (r = 0; r < rows; r++) for (c = 0; c < cols; c++) {
                uint32_t z = r * cols + c, w = r * 15 + c, nw, w3;
                uint32_t norm = t40_awb_ctd_div(p, dpl[w], variance);
                if (upper < norm) nw = 0;
                else if (norm < lower) nw = wt[w];
                else nw = t40_awb_ctd_mul2(p, wt[w], (1U << p) - t40_awb_ctd_div(p, norm - lower, upper - lower));
                rw[w] = nw;
                w3 = t40_awb_ctd_mul3(p, nw, cw[w], (uint32_t)spatial[w] << p);
                s2r += t40_awb_ctd_mul2(p, ratio[z], w3);
                s2b += t40_awb_ctd_mul2(p, ratio[count + z], w3);
                s2w += w3;
            }
            if (s2w) {
                mean_r = t40_awb_ctd_div64(p, s2r, s2w);
                mean_b = t40_awb_ctd_div64(p, s2b, s2w);
            }
        }
    }
    ct = (uint32_t)Tiziano_Awb_Ct_Cal(a0, mean_r, mean_b);
    gains[0] = mean_r; gains[1] = mean_b;
    flags[0] = flags[1] = 0;
    for (k = 0, i = 0; i < count; i++) k += cnt[i] != 0;
    if (diag)
        printk(KERN_INFO "tx_isp_t40_recovered: AWBCTD #%u ct=%u mean=%u/%u p=%u f=%u rows=%u cols=%u zones=%u maxcnt=%u wsum=%u clusters=%u cmode=%u prior=%u refine=%u sat=%u inc=%u exc=%u modes=%u/%u/%u/%u\n",
               n, ct, mean_r, mean_b, p, f, rows, cols, k, maxcnt, wsum, clusters, cluster_mode, prior[0], refp[0] & 0xffU,
               *(const uint16_t *)(uintptr_t)out[15], ncent[0], ncent[1], modes[0], modes[1], modes[2], modes[3]);
    return 0;
}
