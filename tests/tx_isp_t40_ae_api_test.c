/* Host test of driver/t40/tx_isp_t40_ae_api.h (T40 AE API on the frame AE). */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../driver/t40/tx_isp_t40_ae_api.h"

/* Instruction-level transcription of the OEM 5-bin histogram
 * (Eufy tx-isp-t40.ko tisp_ae_main_long_process_api 0x296d0..0x29978). */
static void oracle_hist5(const u32 *h, const u8 *th, u32 *o)
{
	u32 a0, v1;
	u64 s6;
	int i;

	o[0] = o[1] = o[2] = o[3] = o[4] = 0;
	for (a0 = 0; a0 < th[0]; a0++)
		o[0] += h[a0];
	for (v1 = th[0]; v1 < th[1]; v1++)
		o[1] += h[v1];
	for (a0 = th[1]; a0 < th[2]; a0++)
		o[2] += h[a0];
	for (v1 = th[2]; v1 < th[3]; v1++)
		o[3] += h[v1];
	a0 = 0;
	do {
		o[4] += h[th[3] + a0];
		a0++;
	} while (th[3] + a0 < 256);
	s6 = (u64)o[4] + o[0] + o[1] + o[2] + o[3];
	if (!s6) {
		o[0] = 0xffff;
		o[1] = o[2] = o[3] = o[4] = 0;
		return;
	}
	for (i = 1; i < 5; i++)
		o[i] = (u32)(((u64)o[i] * 0xffff) / s6);
	o[0] = 0xffff - o[4] - (o[1] + o[2] + o[3]);
}

/* OEM tisp_ae_s_comp (0x28750): v1 = bin base (128), comp <= 128 ? v1 * comp >> 7 : v1 + comp * 300 / 127 - 302 */
static u32 oracle_comp(u32 base, u32 comp)
{
	if (comp < 129)
		return (base * comp) >> 7;
	return base + (u32)((int)(comp * 300) / 127) - 302;
}

static u32 rnd(void)
{
	static u32 x = 2463534242u;

	x ^= x << 13;
	x ^= x >> 17;
	x ^= x << 5;
	return x;
}

static void test_comp(void)
{
	u32 c;

	for (c = 0; c <= 255; c++)
		assert(t40_ae_comp_factor(c) == oracle_comp(128, c));
	assert(t40_ae_comp_factor(128) == 128);
	assert(t40_ae_comp_factor(255) == 428);
	assert(t40_ae_comp_target(122, 128, 8, 250) == 122);
	assert(t40_ae_comp_target(122, 60, 8, 250) == 57);
	assert(t40_ae_comp_target(122, 200, 8, 250) == 250);
	assert(t40_ae_comp_factor(140) == 156 && t40_ae_comp_target(122, 140, 8, 250) == 148);
	assert(t40_ae_comp_target(122, 0, 8, 250) == 8);
	assert(t40_ae_comp_target(122, 999, 8, 250) == 250);
}

static void test_scence(void)
{
	u8 in[T40_AE_SCENCE_BYTES], out[T40_AE_SCENCE_BYTES];
	struct t40_ae_scence s;

	t40_ae_scence_defaults(&s);
	memset(in, 0, sizeof(in));		/* all AUTO: nothing changes */
	assert(t40_ae_scence_parse(in, &s) == 0);
	assert(s.comp == 128 && s.hlc_en == T40_AE_SC_DISABLE && s.blc_en == T40_AE_SC_DISABLE);
	t40_ae_st32(in, 16, T40_AE_SC_GLOBAL);
	t40_ae_st32(in, 20, 60);
	assert(t40_ae_scence_parse(in, &s) == 0 && s.comp == 60);
	t40_ae_st32(in, 16, T40_AE_SC_AUTO);	/* AUTO keeps */
	t40_ae_st32(in, 20, 200);
	assert(t40_ae_scence_parse(in, &s) == 0 && s.comp == 60);
	t40_ae_st32(in, 16, T40_AE_SC_ROI);
	assert(t40_ae_scence_parse(in, &s) == 0 && s.comp == 200);
	t40_ae_st32(in, 16, T40_AE_SC_DISABLE);	/* DISABLE -> neutral */
	assert(t40_ae_scence_parse(in, &s) == 0 && s.comp == 128);
	/* HLC / BLC */
	t40_ae_st32(in, 0, T40_AE_SC_GLOBAL);
	in[4] = 10;
	t40_ae_st32(in, 8, T40_AE_SC_ROI);
	in[12] = 3;
	assert(t40_ae_scence_parse(in, &s) == 0);
	assert(s.hlc_en == 3 && s.hlc_str == 10 && s.blc_en == 2 && s.blc_str == 3);
	in[4] = 11;
	assert(t40_ae_scence_parse(in, &s) == -EINVAL && s.hlc_str == 10);
	in[4] = 10;
	t40_ae_st32(in, 16, 4);
	assert(t40_ae_scence_parse(in, &s) == -EINVAL);
	t40_ae_st32(in, 16, T40_AE_SC_GLOBAL);
	t40_ae_st32(in, 20, 256);
	assert(t40_ae_scence_parse(in, &s) == -EINVAL);
	t40_ae_st32(in, 20, 77);
	assert(t40_ae_scence_parse(in, &s) == 0 && s.comp == 77);
	/* readback: OEM reports 1 for 128 and 3 otherwise; read-only fields at 32..48 */
	t40_ae_scence_pack(out, &s, 120, 121, 1, 57, 119);
	assert(t40_ae_ld32(out, 16) == T40_AE_SC_GLOBAL && t40_ae_ld32(out, 20) == 77);
	assert(t40_ae_ld32(out, 0) == 3 && out[4] == 10 && t40_ae_ld32(out, 8) == 2 && out[12] == 3);
	assert(t40_ae_ld32(out, 32) == 120 && t40_ae_ld32(out, 36) == 121 && out[40] == 1 &&
	       t40_ae_ld32(out, 44) == 57 && t40_ae_ld32(out, 48) == 119);
	s.comp = 128;
	t40_ae_scence_pack(out, &s, 0, 0, 0, 0, 0);
	assert(t40_ae_ld32(out, 16) == T40_AE_SC_DISABLE && t40_ae_ld32(out, 20) == 128);
}

static void test_stats(void)
{
	static u32 hist[256], raw[256], o5[5];
	u8 thr[4] = { 13, 64, 144, 192 };
	u8 out[T40_AE_STATS_BYTES];
	u16 h5[5];
	u32 zones[T40_AE_ZONES], s0[T40_AE_ZONES], s1[T40_AE_ZONES], s2[T40_AE_ZONES];
	u16 rowh[15], colw[15];
	u64 sum;
	int it, i, k;

	/* scale: hardware bins << 2, bin 0 = rest of the frame */
	memset(raw, 0, sizeof(raw));
	raw[0] = 7;
	raw[10] = 100;
	raw[200] = 50;
	t40_ae_hist_scale(raw, 4, 1, 1000, hist);
	assert(hist[10] == 400 && hist[200] == 200 && hist[0] == 400);
	t40_ae_hist_scale(raw, 4, 1, 100, hist);	/* inconsistent total: bin 0 scaled */
	assert(hist[0] == 28);
	/* frame grid: n samples -> w*h pixels */
	memset(raw, 0, sizeof(raw));
	raw[120] = 9000;
	raw[30] = 1800;
	t40_ae_hist_scale(raw, 3840 * 2160, 10800, 3840 * 2160, hist);
	for (sum = 0, i = 0; i < 256; i++)
		sum += hist[i];
	assert(sum == 3840u * 2160u && hist[120] == 6912000 && hist[30] == 1382400);

	/* 5-bin histogram against the OEM transcription */
	for (it = 0; it < 2000; it++) {
		for (i = 0; i < 256; i++)
			hist[i] = (it & 1) ? (rnd() & 0x1fffff) : ((rnd() & 7) ? 0 : (rnd() & 0xffff));
		for (k = 0; k < 4; k++)
			thr[k] = (u8)rnd();
		if (it & 2) {	/* monotonic, as the tuning tools send them */
			u8 t;
			int a, b;

			for (a = 0; a < 4; a++)
				for (b = a + 1; b < 4; b++)
					if (thr[b] < thr[a]) {
						t = thr[a];
						thr[a] = thr[b];
						thr[b] = t;
					}
		}
		if (it == 5)
			memset(hist, 0, sizeof(hist));
		t40_ae_hist5(hist, thr, h5);
		oracle_hist5(hist, thr, o5);
		for (k = 0; k < 5; k++)
			assert(h5[k] == (u16)o5[k]);
	}
	memset(hist, 0, sizeof(hist));
	t40_ae_hist5(hist, thr, h5);
	assert(h5[0] == 0xffff && !h5[1] && !h5[2] && !h5[3] && !h5[4]);

	/* zone Y = (sum0 + sum1 + sum2) / (row height * column width) */
	for (i = 0; i < 15; i++) {
		rowh[i] = 72;
		colw[i] = 128;
	}
	for (i = 0; i < (int)T40_AE_ZONES; i++) {
		s0[i] = 72 * 128 * 40;
		s1[i] = 72 * 128 * 50;
		s2[i] = 72 * 128 * (i % 30);
	}
	t40_ae_hw_zones(s0, s1, s2, rowh, colw, 15, 15, zones);
	assert(zones[0] == 90 && zones[7 * 15 + 7] == 90 + (112 % 30) && zones[29] == 119);
	t40_ae_hw_zones(s0, s1, s2, rowh, colw, 3, 4, zones);
	assert(zones[0] == 90 && zones[4] == 0 && zones[3 * 15] == 0);

	/* wire: hist5 @0, hist256 @10, zones @1034 */
	for (i = 0; i < 256; i++)
		hist[i] = i;
	thr[0] = 13; thr[1] = 64; thr[2] = 144; thr[3] = 192;
	for (i = 0; i < (int)T40_AE_ZONES; i++)
		zones[i] = 1000 + i;
	t40_ae_stats_pack(out, hist, thr, zones);
	assert(t40_ae_ld32(out, 10 + 4 * 255) == 255 && t40_ae_ld32(out, 1034) == 1000 &&
	       t40_ae_ld32(out, 1034 + 4 * 224) == 1224);
	t40_ae_hist5(hist, thr, h5);
	for (i = 0; i < 5; i++) {
		u16 v;

		memcpy(&v, out + 2 * i, 2);
		assert(v == h5[i]);
	}
}

static void test_meter(void)
{
	u32 zm[T40_AE_ZONES];
	u8 w[T40_AE_ZONES];
	struct t40_ae_meter_in m;
	u32 plain, x0, x1, y0, y1;
	int i;

	/* backlit scene: dark centre 3x3 (luma 30), bright rest (luma 200) */
	for (i = 0; i < (int)T40_AE_ZONES; i++) {
		int x = i % 15, y = i / 15;

		zm[i] = (x >= 6 && x <= 8 && y >= 6 && y <= 8) ? 30 : 200;
	}
	memset(&m, 0, sizeof(m));
	m.zone_mean = zm;
	assert(t40_ae_meter(&m) == 0);		/* nothing configured: plain mean */
	memset(w, 1, sizeof(w));
	m.weight = w;
	plain = t40_ae_meter(&m);
	assert(plain == (216 * 200 + 9 * 30) / 225);
	m.blc_str = 10;				/* BLC: dark zones weigh 11x -> lower metered luma */
	assert(t40_ae_meter(&m) < plain - 30);
	m.blc_str = 0;
	m.hlc_str = 10;				/* HLC: bright zones weigh more -> higher metered luma */
	assert(t40_ae_meter(&m) > plain);
	m.hlc_str = 0;
	memset(w, 0, sizeof(w));		/* centre-only weights */
	w[7 * 15 + 7] = 8;
	assert(t40_ae_meter(&m) == 30);
	memset(w, 0, sizeof(w));		/* all zero weights: no metering */
	assert(t40_ae_meter(&m) == 0);
	m.weight = NULL;
	assert(t40_ae_face_zones(1700, 900, 2100, 1260, 3840, 2160, &x0, &x1, &y0, &y1) == 0);
	assert(x0 == 6 && x1 == 9 && y0 == 6 && y1 == 9);
	m.face_on = 1;
	m.fx0 = x0; m.fx1 = x1; m.fy0 = y0; m.fy1 = y1;
	assert(t40_ae_meter(&m) == 30);
	assert(t40_ae_face_zones(10, 10, 5, 20, 100, 100, &x0, &x1, &y0, &y1) == -EINVAL);
	assert(t40_ae_face_zones(10, 10, 101, 20, 100, 100, &x0, &x1, &y0, &y1) == -EINVAL);
	assert(t40_ae_face_zones(0, 0, 1, 1, 3840, 2160, &x0, &x1, &y0, &y1) == 0 && x1 == 1 && y1 == 1);
}

static void test_af_speed(void)
{
	/* sc830ai 2250 lines x 20 fps: 50 Hz -> 450 lines per 10 ms, 60 Hz -> 375 */
	assert(t40_ae_af_lines(45000, 50) == 450);
	assert(t40_ae_af_lines(45000, 60) == 375);
	assert(t40_ae_af_lines(0, 50) == 0 && t40_ae_af_lines(45000, 0) == 0);
	assert(t40_ae_af_floor(2241, 450) == 1800);
	assert(t40_ae_af_floor(300, 450) == 300);
	assert(t40_ae_af_floor(900, 450) == 900);
	assert(t40_ae_af_floor(5, 0) == 5);
	assert(t40_ae_speed_scale(100, 128) == 100);
	assert(t40_ae_speed_scale(100, 256) == 200);
	assert(t40_ae_speed_scale(100, 64) == 50);
	assert(t40_ae_speed_scale(100, 5000) == 800);
	assert(t40_ae_speed_scale(1, 1) == 1);
	assert(t40_ae_speed_scale(1, 0) == 1);
}

static void test_expr(void)
{
	u8 in[T40_AE_EXPR_BYTES], out[T40_AE_EXPR_BYTES + 16];
	struct t40_ae_expr e;
	struct t40_ae_expr_live l;

	memset(in, 0, sizeof(in));
	assert(t40_ae_expr_parse(in, &e) == 0 && !e.freeze && !e.max_it_mode);
	t40_ae_st32(in, 4, 1);			/* AeMode freeze */
	t40_ae_st32(in, 8, 1);			/* manual IT 500 lines */
	t40_ae_st32(in, 24, 500);
	t40_ae_st32(in, 12, 1);			/* manual again 4x */
	t40_ae_st32(in, 28, 4096);
	t40_ae_st32(in, 44, 1);			/* min again 2x */
	t40_ae_st32(in, 76, 2048);
	t40_ae_st32(in, 56, 1);			/* max IT 280 */
	t40_ae_st32(in, 88, 280);
	t40_ae_st32(in, 60, 1);			/* max again 8x */
	t40_ae_st32(in, 92, 8192);
	assert(t40_ae_expr_parse(in, &e) == 0);
	assert(e.freeze == 1 && e.it_manual == 1 && e.it == 500 && e.again_manual && e.again == 4096);
	assert(e.min_again_mode && e.min_again == 2048 && e.max_it_mode && e.max_it == 280 &&
	       e.max_again_mode && e.max_again == 8192);
	t40_ae_st32(in, 92, 1024);		/* min above max */
	assert(t40_ae_expr_parse(in, &e) == -EINVAL && e.max_again == 8192);
	t40_ae_st32(in, 92, 8192);
	t40_ae_st32(in, 28, 512);		/* manual gain below 1x */
	assert(t40_ae_expr_parse(in, &e) == -EINVAL);
	t40_ae_st32(in, 28, 4096);
	t40_ae_st32(in, 12, 2);			/* bad mode word */
	assert(t40_ae_expr_parse(in, &e) == -EINVAL);
	t40_ae_st32(in, 12, 1);
	t40_ae_st32(in, 0, 2);			/* bad unit */
	assert(t40_ae_expr_parse(in, &e) == -EINVAL);
	t40_ae_st32(in, 0, 0);
	t40_ae_st32(in, 24, 0);			/* manual IT 0 */
	assert(t40_ae_expr_parse(in, &e) == -EINVAL);
	t40_ae_st32(in, 24, 500);
	assert(t40_ae_expr_parse(in, &e) == 0);

	/* GET: 220 bytes, nothing written past it; TotalGainDb @204, ExposureValue @212, EVLog2 @216 */
	memset(&l, 0, sizeof(l));
	l.it = 500; l.again = 4096; l.dgain = 1024; l.ispdgain = 1024;
	l.min_it = 64; l.min_again = 2048; l.max_it = 280; l.max_again = 8192;
	l.max_dgain = 1024; l.max_ispdgain = 4096;
	l.total_gain_db = 131070; l.exposure_value = 2000; l.ev_log2 = 0xaf6a0;
	memset(out, 0x5a, sizeof(out));
	t40_ae_expr_pack(out, &e, &l);
	for (int i = T40_AE_EXPR_BYTES; i < (int)sizeof(out); i++)
		assert(out[i] == 0x5a);
	assert(t40_ae_ld32(out, 4) == 1 && t40_ae_ld32(out, 8) == 1 && t40_ae_ld32(out, 12) == 1);
	assert(t40_ae_ld32(out, 24) == 500 && t40_ae_ld32(out, 28) == 4096 && t40_ae_ld32(out, 32) == 1024 &&
	       t40_ae_ld32(out, 36) == 1024);
	assert(t40_ae_ld32(out, 44) == 1 && t40_ae_ld32(out, 56) == 1 && t40_ae_ld32(out, 60) == 1);
	assert(t40_ae_ld32(out, 72) == 64 && t40_ae_ld32(out, 76) == 2048 && t40_ae_ld32(out, 88) == 280 &&
	       t40_ae_ld32(out, 92) == 8192 && t40_ae_ld32(out, 100) == 4096);
	assert(t40_ae_ld32(out, 204) == 131070 && t40_ae_ld32(out, 212) == 2000 &&
	       t40_ae_ld32(out, 216) == 0xaf6a0);
}

/* ---------------- #211 antiflicker rung flip-flop ---------------- */

/* regtrace_gc4653_again_log2_gain (tx_isp_t40_recovered.c): log2 16.16 per gain index */
static const u32 gc_lut[26] = {
	0U, 14995U, 31177U, 47704U, 65535U, 81158U, 97241U,
	113239U, 131070U, 147006U, 162776U, 178774U, 196605U,
	212541U, 228311U, 244420U, 262140U, 278154U, 293912U,
	309955U, 327675U, 343689U, 359480U, 375518U, 393210U,
	409243U,
};

static u32 t_log2_gain(u32 i)
{
	return gc_lut[i > 25U ? 25U : i];
}

static struct t40_ae_gain_cache *t_cache;
static u32 t_cache_get(u32 idx)
{
	return t40_ae_gain_cache_get(t_cache, idx);
}

static double t_exp2(double x)
{
	double r = 1.0, term = 1.0, f;
	int i, n = (int)x;

	f = (x - n) * 0.69314718055994531;
	for (i = 1; i < 16; i++) {
		term *= f / i;
		r += term;
	}
	for (i = 0; i < n; i++)
		r *= 2.0;
	return r;
}

struct af_sim {
	u32 it, ag;
};

/*
 * One frame-3A AE sample of the antiflicker branch of the T40-AE-API loop
 * (tx_isp_t40_recovered.c, regtrace_frame_3a_sample) with the ISP dgain
 * fixed at 1x, nothing manual, no highlight guard.  legacy = the rules of
 * origin/next d09dc553 (rung up while the prediction stays inside
 * target + again_band, rung down at target + deadband, no gain trade).
 * Eufy T40XP run: 50 Hz rung 450 lines, cap 1350, deadband 4.
 */
static void af_sim_step(struct af_sim *s, u32 luma, u32 target, int legacy)
{
	const u32 deadband = 4, step = 450, cap = 1350, max_ag = 25, min_ag = 0;
	u32 band = legacy ? target * 9U / 100U : (target * 9U + 99U) / 100U;
	unsigned int moves = (luma * 2U < target || luma > target * 2U) ? 2U : 1U, n;

	if (band < deadband)
		band = deadband;
	for (n = 0; n < moves; n++) {
		if (luma + deadband < target) {
			u32 nit = s->it, nag = s->ag;

			if (s->it < cap) {
				u32 up = s->it + step > cap ? cap : s->it + step;

				if (legacy) {
					if ((u64)luma * up <= (u64)(target + band) * s->it)
						nit = up;
				} else {
					u32 uag = t40_ae_af_trade_again(s->it, up, s->ag, min_ag, max_ag, t_log2_gain);
					u32 ev = t40_ae_af_trade_log2(s->it, up, s->ag, uag, t_log2_gain);

					if (ev <= t40_ae_log2_ratio(target + band, luma)) {
						nit = up;
						nag = uag;
					}
				}
			}
			if (nit != s->it) {
				s->it = nit;
				s->ag = nag;
				break;
			} else if (s->ag < max_ag && luma + band < target) {
				s->ag++;
			} else {
				break;
			}
		} else if (luma > target + deadband) {
			if (s->ag > min_ag && luma > target + band) {
				s->ag--;
			} else if (s->ag > min_ag || s->it <= step) {
				break;
			} else {
				u32 dn = s->it - step;

				if (!legacy) {
					if (luma <= target + band)
						break;
					s->ag = t40_ae_af_trade_again(s->it, dn, s->ag, min_ag, max_ag, t_log2_gain);
				}
				s->it = dn;
				break;
			}
		} else {
			break;
		}
	}
}

/*
 * Plant: frame luma linear in the exposure (it x analog gain), scaled by
 * luma_per_line, plus a repeating noise pattern of +-amp levels.  Runs 300
 * samples from 450 lines / 1x (lag 1: the sample sees the previous
 * sample's exposure) and reports the exposure spread (max/min) and
 * the integration time range of the last 150.
 */
static double af_sim_run(double luma_per_line, u32 target, int amp, int lag, int legacy,
			 u32 *it_lo, u32 *it_hi)
{
	double ev_prev = 450.0;
	static const int pat[8] = { 0, 1, -1, 1, 0, -1, 1, -1 };
	struct af_sim s = { 450U, 0U };
	double ev_lo = 1e30, ev_hi = 0;
	int k;

	*it_lo = ~0U;
	*it_hi = 0;
	for (k = 0; k < 300; k++) {
		double ev = s.it * t_exp2(t_log2_gain(s.ag) / 65536.0);
		int l = (int)(luma_per_line * (lag ? ev_prev : ev) + 0.5) + pat[k & 7] * amp;

		ev_prev = ev;

		if (k >= 150) {
			if (ev < ev_lo)
				ev_lo = ev;
			if (ev > ev_hi)
				ev_hi = ev;
			if (s.it < *it_lo)
				*it_lo = s.it;
			if (s.it > *it_hi)
				*it_hi = s.it;
		}
		af_sim_step(&s, l < 1 ? 1U : (u32)l, target, legacy);
	}
	return ev_hi / ev_lo;
}

/* #219 C1: a sensor whose own gain table is coarser than the GC4653 ladder (floors to 29491 / 65536 log2 = 1.366x steps,
 * with one non-monotonic glitch) and the cached per-index gain the frame AE trades with */
static u32 coarse_calls;
static u32 t_coarse_log2(u32 i)
{
	u32 g = t_log2_gain(i);

	coarse_calls++;
	if (i == 7U)
		return 0;	/* glitch: the cache keeps it monotonic */
	return g / 29491U * 29491U;
}

static void test_gain_cache(void)
{
	struct t40_ae_gain_cache c;
	u32 i, room = t40_ae_log2_ratio(1350, 900);

	memset(&c, 0, sizeof(c));
	t40_ae_gain_cache_sync(&c, 5, 4, t_coarse_log2);
	assert(coarse_calls == 26U && c.valid && c.key == 5U);
	for (i = 1; i <= 25U; i++)
		assert(c.g[i] >= c.g[i - 1U]);
	assert(c.g[7] == c.g[6] && c.g[2] == 29491U && c.g[3] == 29491U && c.g[4] == 58982U);
	assert(t40_ae_gain_cache_get(&c, 99) == c.g[25]);
	t40_ae_gain_cache_sync(&c, 5, 4, t_coarse_log2);	/* same key, 1 use < 4: no refill */
	assert(coarse_calls == 26U);
	t40_ae_gain_cache_sync(&c, 6, 4, t_coarse_log2);	/* new sensor key: refill */
	assert(coarse_calls == 52U);
	for (i = 0; i < 4U; i++)
		(void)t40_ae_gain_cache_get(&c, i);
	t40_ae_gain_cache_sync(&c, 6, 4, t_coarse_log2);	/* period reached: refill */
	assert(coarse_calls == 78U && c.uses == 0);
	/*
	 * rung down 1350 -> 900 at idx 0 (room 0.585 stop): the GC4653 ladder trade gives idx 2 (1.39x modelled) but this
	 * sensor applies only 29491 there; traded with the sensor gains the index goes to 3 (still 29491 <= room, idx 4 =
	 * 58982 > room) and the modelled exposure change is the real one.
	 */
	{
		/* function-pointer adapter over the cache, like t40_ae_trade_log2_gain in the driver */
		u32 ag_gc = t40_ae_af_trade_again(1350, 900, 0, 0, 25, t_log2_gain);
		u32 (*fn)(u32) = t_cache_get;
		u32 ag_s, d;

		t_cache = &c;
		ag_s = t40_ae_af_trade_again(1350, 900, 0, 0, 25, fn);
		assert(ag_gc == 2 && ag_s == 3);
		d = t40_ae_af_trade_log2(1350, 900, 0, ag_s, fn);
		assert(d == room - 29491U);
	}
	printf("gain_cache: ok (sensor trade idx 3 vs ladder 2, real exposure change %u)\n", room - 29491U);
}

static void test_af_trade(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	/* comp 58 on the default target 122 (regtrace_frame_3a_target): 55 */
	const u32 t58 = t40_ae_comp_target(122, 58, 8, 250);
	/* logged comp 48 point (b84-open-T40-1105c expose step 1): IT 900, AeAGain 1200 at target 45 */
	const double c48 = (double)t40_ae_comp_target(122, 48, 8, 250) / (900.0 * 1200.0 / 1024.0);
	u32 lo, hi;
	double r;

	assert(t58 == 55);
	assert(t40_ae_log2_ratio(2, 1) == 65536U);
	assert(t40_ae_log2_ratio(1350, 900) >= 38335U && t40_ae_log2_ratio(1350, 900) <= 38339U);
	assert(t40_ae_log2_ratio(900, 900) == 0 && t40_ae_log2_ratio(5, 0) == 0);
	/* rung down 1350 -> 900 at 1x: two gain indices (1.39x, exposure 1251 of 1350) */
	assert(t40_ae_af_trade_again(1350, 900, 0, 0, 25, t_log2_gain) == 2);
	/* Opus review C3: an unclamped hi must not run past the 26-index ladder */
	assert(t40_ae_af_trade_again(1350, 900, 0, 0, 0x7fffffffU, t_log2_gain) <= 25U);
	assert(t40_ae_af_trade_again(1350, 900, 100, 0, 0x7fffffffU, t_log2_gain) <= 25U);
	/* 900 -> 450: four indices (exactly 2x, 65535 <= 65536) */
	assert(t40_ae_af_trade_again(900, 450, 0, 0, 25, t_log2_gain) == 4);
	/* rung up 900 -> 1350 from index 1 (the logged 1350 / AGain 1200 state) and 3 */
	assert(t40_ae_af_trade_again(900, 1350, 1, 0, 25, t_log2_gain) == 0);
	assert(t40_ae_af_trade_again(900, 1350, 3, 0, 25, t_log2_gain) == 1);
	assert(t40_ae_af_trade_again(900, 1350, 0, 0, 25, t_log2_gain) == 0);
	assert(t40_ae_af_trade_again(1350, 900, 24, 0, 25, t_log2_gain) == 25);	/* capped */
	assert(t40_ae_af_trade_log2(900, 1350, 0, 0, t_log2_gain) == t40_ae_log2_ratio(1350, 900));
	assert(t40_ae_af_trade_log2(1350, 900, 0, 2, t_log2_gain) ==
	       t40_ae_log2_ratio(1350, 900) - 31177U);

	/* default target 122, luma 128 at 1350 / 1x (in (T+deadband, T+band]): legacy flips 900 <-> 1350 */
	r = af_sim_run(128.0 / 1350.0, 122, 0, 0, 1, &lo, &hi);
	printf("af211 T122 noise0 legacy: ev spread %.3f it %u..%u\n", r, lo, hi);
	assert(lo == 900 && hi == 1350 && r >= 1.49);
	r = af_sim_run(128.0 / 1350.0, 122, 0, 0, 0, &lo, &hi);
	printf("af211 T122 noise0 fixed:  ev spread %.3f it %u..%u\n", r, lo, hi);
	assert(lo == hi && r < 1.0001);

	/*
	 * comp 58 with the plant calibrated on the logged comp 48 point (1350 / 1x -> luma 58) and a
	 * one-sample statistics lag: legacy hunts 900 <-> 1350 (the logged 1350 / AGain 1200 state,
	 * exposure 1582 vs 900) and with +-2 noise also 450 lines; the traded loop holds one exposure.
	 */
	r = af_sim_run(c48, t58, 0, 1, 1, &lo, &hi);
	printf("af211 T55 lag1 noise0 legacy: ev spread %.3f it %u..%u\n", r, lo, hi);
	assert(lo == 900 && hi == 1350 && r >= 1.75);
	r = af_sim_run(c48, t58, 2, 1, 1, &lo, &hi);
	printf("af211 T55 lag1 noise2 legacy: ev spread %.3f it %u..%u\n", r, lo, hi);
	assert(lo == 450 && hi == 1350 && r >= 3.0);
	r = af_sim_run(c48, t58, 0, 1, 0, &lo, &hi);
	assert(lo == hi && r < 1.0001);
	r = af_sim_run(c48, t58, 2, 1, 0, &lo, &hi);
	assert(lo == hi && r < 1.0001);
	{
		int amp, lag;

		/* any lag / noise up to +-4: at most one traded rung (exposure 1251 <-> 1350) */
		for (lag = 0; lag < 2; lag++)
			for (amp = 0; amp < 5; amp++) {
				r = af_sim_run(c48, t58, amp, lag, 0, &lo, &hi);
				printf("af211 T55 lag%d noise%d fixed: ev spread %.3f it %u..%u\n",
				       lag, amp, r, lo, hi);
				assert(r <= 1.08 && lo >= 900);
			}
	}
}


/* ---------------- #84 OEM exposure split ---------------- */

/*
 * Transcription of the OEM split (vendor tx-isp-t40.ko tisp_ae_long_tune2 0x35b58, deflicker ladder branch,
 * audit/issue84/decomp_ae_split/vendor_tisp_ae_long_tune2.c l.699-729 with l.613-626), minimum gains 1x:
 * ladder entries k * step above max_it + 20 are dropped (l.703), R = highest entry <= EV / min gain
 * (l.711-718), IT = min(R, max_it) (l.719-721), again = EV / IT (l.722); again <= max_again: dgain 1x
 * (l.723 -> l.615), else again = max_again, dgain = rest clamped to max_dgain (l.724-728).
 */
struct oem_split {
	double it, ag, dg;
};

static struct oem_split oracle_oem_split(double ev, u32 max_it, u32 step, double max_ag, double max_dg)
{
	struct oem_split o;
	u32 top = step, r = step;

	while (top + step <= max_it + 20U)
		top += step;
	while (r + step <= top && r + step <= ev)
		r += step;
	o.it = r < max_it ? r : max_it;
	o.ag = ev / o.it;
	o.dg = 1.0;
	if (o.ag > max_ag) {
		o.dg = o.ag / max_ag;
		o.ag = max_ag;
		if (o.dg > max_dg)
			o.dg = max_dg;
	}
	return o;
}

static double t_gain(u32 ag, u32 dg)
{
	return t_exp2(t_log2_gain(ag) / 65536.0) * dg / 1024.0;
}

/* re-split until the state is the OEM one; returns the number of moves */
static int split_fix(u32 *it, u32 *ag, u32 *dg, u32 step, u32 max_it, u32 max_ag, u32 dg_max)
{
	int n = 0;

	while (t40_ae_oem_split(it, ag, dg, step, max_it, 0, max_ag, dg_max, true, t_log2_gain))
		assert(++n < 40);
	return n;
}

/*
 * One frame-3A AE sample of the T40-AE-API loop (tx_isp_t40_recovered.c regtrace_frame_3a_sample, the
 * regtrace_enable_ae_sensor_apply block) with antiflicker NORMAL (it_floor = rung), nothing manual, no
 * highlight guard, neutral speed: IT steps (trade), again / ISP dgain gain bands, then (oem) the #84 split.
 */
struct ae_sim {
	u32 it, ag, dg;
};

static void ae_sim_step(struct ae_sim *s, u32 luma, u32 target, int oem)
{
	const u32 deadband = 4, step = 450, max_it = 2241, max_ag = 20, min_ag = 0, dg_max = 4096;
	u32 it_cap = oem ? t40_ae_af_it_cap(max_it, step) : t40_ae_af_floor(max_it, step);
	u32 again_band = (target * 9U + 99U) / 100U, dgain_band = target * 5U / 100U;
	unsigned int moves = (luma * 2U < target || luma > target * 2U) ? 2U : 1U, n;
	u32 it = s->it, again = s->ag, dgain = s->dg;
	int it_down = 0;

	if (again_band < deadband)
		again_band = deadband;
	if (dgain_band < deadband)
		dgain_band = deadband;
	if (it > it_cap)
		it = it_cap;
	if (it > step && it % step && it != it_cap)
		it = t40_ae_af_floor(it, step);
	if (it < step)
		it = step;
	for (n = 0; n < moves; n++) {
		if (luma + deadband < target) {
			u32 next_it = it, next_ag = again;

			if (it < it_cap) {
				u32 up_it = it + step < it_cap ? it + step : it_cap;
				u32 up_ag = t40_ae_af_trade_again(it, up_it, again, min_ag, max_ag, t_log2_gain);
				u32 ev_up = t40_ae_af_trade_log2(it, up_it, again, up_ag, t_log2_gain);

				next_it = up_it;
				next_ag = up_ag;
				if (ev_up > t40_ae_log2_ratio(target + again_band, luma ? luma : 1U) &&
				    ((again < max_ag || dgain < dg_max) ||
				     ev_up > t40_ae_log2_ratio(2U * target - luma, luma ? luma : 1U))) {
					next_it = it;
					next_ag = again;
				}
			}
			if (next_it != it) {
				it = next_it;
				again = next_ag;
				break;
			} else if (again < max_ag && luma + again_band < target) {
				again++;
			} else if (dgain < dg_max && luma + dgain_band < target) {
				dgain = dgain + dgain / 12U < dg_max ? dgain + dgain / 12U : dg_max;
			} else {
				break;
			}
		} else if (luma > target + deadband) {
			if (dgain > 1024U && luma > target + dgain_band) {
				dgain = dgain - dgain / 13U > 1024U ? dgain - dgain / 13U : 1024U;
			} else if (again > min_ag && luma > target + again_band) {
				again--;
			} else if (dgain > 1024U || again > min_ag) {
				break;
			} else if (it > step) {
				u32 dn = it % step ? t40_ae_af_floor(it, step) : it - step;

				if (dn < step)
					dn = step;
				if (luma <= target + again_band)
					break;
				again = t40_ae_af_trade_again(it, dn, again, min_ag, max_ag, t_log2_gain);
				it = dn;
				it_down = 1;
				break;
			} else {
				break;
			}
		} else {
			break;
		}
	}
	if (oem)
		(void)t40_ae_oem_split(&it, &again, &dgain, step, max_it, min_ag, max_ag, dg_max, !it_down,
				       t_log2_gain);
	s->it = it;
	s->ag = again;
	s->dg = dgain;
}

/* plant: luma = 255 * (k * exposure)^0.45 (gamma), one-sample statistics lag; returns the last luma */
static double ae_sim_lo, ae_sim_hi;	/* exposure range of the second half of a run */

static u32 ae_sim_runn(struct ae_sim *s, double k, u32 target, int oem, int samples, int amp)
{
	static const int pat[8] = { 0, 1, -1, 1, 0, -1, 1, -1 };
	double ev_prev = s->it * t_gain(s->ag, s->dg);
	u32 l = 0;
	int i;

	ae_sim_lo = 1e30;
	ae_sim_hi = 0;
	for (i = 0; i < samples; i++) {
		double ev = s->it * t_gain(s->ag, s->dg), x = k * ev_prev;
		int v;

		ev_prev = ev;
		if (i >= samples / 2) {
			ae_sim_lo = ev < ae_sim_lo ? ev : ae_sim_lo;
			ae_sim_hi = ev > ae_sim_hi ? ev : ae_sim_hi;
		}
		v = (x >= 1.0 ? 255 : (int)(255.0 * exp(0.45 * log(x)) + 0.5)) + pat[i & 7] * amp;
		l = v < 1 ? 1U : (u32)v;
		ae_sim_step(s, l, target, oem);
	}
	return l;
}

static u32 ae_sim_run(struct ae_sim *s, double k, u32 target, int oem, int samples)
{
	return ae_sim_runn(s, k, target, oem, samples, 0);
}

static void test_oem_split(void)
{
	u32 it, ag, dg, d;
	int oem, n;

	/* OEM ceiling: 50 Hz rung 450, max_it 2241 -> 2250 kept, clamped 2241; 60 Hz rung 375 -> 2250 -> 2241 */
	assert(t40_ae_af_it_cap(2241, 450) == 2241 && t40_ae_af_it_cap(2241, 375) == 2241);
	assert(t40_ae_af_it_cap(2000, 450) == 1800 && t40_ae_af_it_cap(2241, 0) == 2241);
	assert(t40_ae_af_it_cap(300, 450) == 300 && t40_ae_af_it_cap(2230, 450) == 2230);
	/* exp2 inverse of log2_ratio */
	assert(t40_ae_q10_exp2_floor(0) == 1024 && t40_ae_q10_exp2_floor(65536) == 2048);
	assert(t40_ae_q10_exp2_floor(10U << 16) == 32767);
	for (d = 1024; d < 32768; d += 7) {
		u32 l = t40_ae_log2_ratio(d, 1024), e = t40_ae_q10_exp2_floor(l);

		assert(e >= d && t40_ae_log2_ratio(e, 1024) == l);
		assert(e == 32767 || t40_ae_log2_ratio(e + 1, 1024) > l);
	}

	/* Eufy 1106a run1 (OPUS_AE_SPLIT.md Q1): IT 1800, AeAGain idx 5, ISP dgain step 10 (2275), EV 9435 */
	it = 1800, ag = 5, dg = 2275;
	{
		double ev0 = it * t_gain(ag, dg);
		struct oem_split o = oracle_oem_split(ev0, 2241, 450, 32.0, 4.0);

		n = split_fix(&it, &ag, &dg, 450, 2241, 20, 4096);
		printf("oem84 run1 1800/5/2275 (EV %.0f) -> %u/%u/%u in %d moves; OEM IT %.0f again %.3f dgain %.2f\n",
		       ev0, it, ag, dg, n, o.it, o.ag, o.dg);
		assert(it == 2241 && o.it == 2241);
		assert(ag == 8 && dg < 1024U + 1024U * 17U / 100U);		/* 4.0 x 1.05 = OEM 4.21x analog */
		assert(fabs(t_gain(ag, dg) / o.ag - 1.0) < 0.002);
		assert(fabs(it * t_gain(ag, dg) / ev0 - 1.0) < 0.002);	/* exposure-neutral */
	}
	/* run3: IT 1800, idx 10, dgain step 1 (1109): the same rule, same kind of point */
	it = 1800, ag = 10, dg = 1109;
	(void)split_fix(&it, &ag, &dg, 450, 2241, 20, 4096);
	assert(it == 2241 && ag == 9);
	/* vendor pass (1105e): EV 3511 at IT 2241 -> again 1.57x (OEM AGain 1600); open: idx 2 (1.39x) + dgain 1.13x */
	it = 1800, ag = 1, dg = 1024U * 3511U / 1800U * 1024U / 1200U;
	(void)split_fix(&it, &ag, &dg, 450, 2241, 20, 4096);
	assert(it == 2241 && ag == 2);
	/* canonical states are left alone (no register churn): gain at min, sub-step dgain */
	it = 1800, ag = 0, dg = 1024;
	assert(!t40_ae_oem_split(&it, &ag, &dg, 450, 2241, 0, 20, 4096, true, t_log2_gain));
	it = 2241, ag = 3, dg = 1100;
	assert(!t40_ae_oem_split(&it, &ag, &dg, 450, 2241, 0, 20, 4096, true, t_log2_gain));
	/* IT above the OEM point (2241 at 1x: OEM 1800 + 1.245x) stays: never moved down, less gain */
	it = 2241, ag = 0, dg = 1024;
	assert(!t40_ae_oem_split(&it, &ag, &dg, 450, 2241, 0, 20, 4096, true, t_log2_gain));
	/* IT not free (manual or stepped down this sample): only dgain -> again */
	it = 900, ag = 0, dg = 2275;
	assert(t40_ae_oem_split(&it, &ag, &dg, 450, 2241, 0, 20, 4096, false, t_log2_gain) && it == 900 && ag == 1);
	/* above max_again: analog at max, dgain the rest (OEM l.724-728) */
	it = 2241, ag = 19, dg = 3000;
	assert(t40_ae_oem_split(&it, &ag, &dg, 450, 2241, 0, 20, 4096, true, t_log2_gain) && ag == 20);
	assert(!t40_ae_oem_split(&it, &ag, &dg, 450, 2241, 0, 20, 4096, true, t_log2_gain));
	/* no antiflicker: only the gain part */
	it = 1000, ag = 2, dg = 2048;
	(void)split_fix(&it, &ag, &dg, 0, 2241, 20, 4096);
	assert(it == 1000 && ag == 5);	/* 2 + 1 EV = 96713 -> idx 5 (81158) */

	/*
	 * Against the OEM transcription: any path state (IT on a rung, any analog index, any dgain up to 4x)
	 * re-split equals the OEM point of its exposure whenever the OEM IT is not below the state's IT:
	 * same IT, total gain within rounding, dgain below one analog step while the analog gain is below max.
	 */
	{
		static const u32 rungs[] = { 450, 900, 1350, 1800, 2241 };
		unsigned int seed = 84, cnt = 0, kept = 0;
		int k;

		for (k = 0; k < 20000; k++) {
			u32 i0, a0, d0;
			double ev0;
			struct oem_split o;

			seed = seed * 1103515245U + 12345U;
			i0 = rungs[(seed >> 16) % 5];
			seed = seed * 1103515245U + 12345U;
			a0 = (seed >> 16) % 21;
			seed = seed * 1103515245U + 12345U;
			d0 = 1024U + (seed >> 12) % 3072U;
			it = i0, ag = a0, dg = d0;
			ev0 = i0 * t_gain(a0, d0);
			o = oracle_oem_split(ev0, 2241, 450, t_exp2(t_log2_gain(20) / 65536.0), 4.0);
			n = split_fix(&it, &ag, &dg, 450, 2241, 20, 4096);
			/* never more exposure; each move loses < 1/1024 (Q10 dgain rounded down) */
			assert(it * t_gain(ag, dg) <= ev0 * 1.0001 && it * t_gain(ag, dg) >= ev0 * (1.0 - 0.0011 * n));
			if (o.it < i0) {			/* IT only moves up: less gain than the OEM */
				assert(it == i0);
				kept++;
				continue;
			}
			assert(it == (u32)o.it);
			assert(fabs(t_gain(ag, dg) / (o.ag * o.dg) - 1.0) < 0.0011 * n + 0.0001);
			if (ag < 20)
				assert(t40_ae_log2_ratio(dg, 1024) < t_log2_gain(ag + 1) - t_log2_gain(ag));
			cnt++;
		}
		printf("oem84 oracle: %u states equal to the OEM split, %u above it kept (less gain)\n", cnt, kept);
		assert(cnt > 15000);
	}

	/*
	 * Path dependence (OPUS_AE_SPLIT.md Q1): one scene, three histories - (a) from dark (450 lines / 1x),
	 * (b) from bright (max exposure), (c) low target first (comp 28: target 27) then the default 122,
	 * (d) the logged run1 point (IT 1800, idx 5, ISP dgain 2275) as the start.
	 * Legacy: the operating points differ and run1 is a fixed point; OEM split: one point, the OEM one.
	 */
	for (oem = 0; oem < 2; oem++) {
		const double k = 0.1941 / 9435.0;	/* run1: EV 9435 -> luma 122 (gamma 0.45) */
		struct ae_sim h[4] = { { 450, 0, 1024 }, { 2241, 20, 4096 }, { 450, 0, 1024 }, { 1800, 5, 2275 } };
		u32 l[4];
		int j, differ = 0;

		l[0] = ae_sim_run(&h[0], k, 122, oem, 400);
		l[1] = ae_sim_run(&h[1], k, 122, oem, 400);
		(void)ae_sim_run(&h[2], k, t40_ae_comp_target(122, 28, 8, 250), oem, 200);
		l[2] = ae_sim_run(&h[2], k, 122, oem, 400);
		l[3] = ae_sim_run(&h[3], k, 122, oem, 400);
		for (j = 0; j < 4; j++)
			printf("oem84 %s history %c: IT %u again %u dgain %u luma %u EV %.0f\n", oem ? "oem   " : "legacy",
			       'a' + j, h[j].it, h[j].ag, h[j].dg, l[j], h[j].it * t_gain(h[j].ag, h[j].dg));
		/* the split is a function of the exposure (the AE window around the target still allows several EVs) */
		for (j = 0; j < 4; j++) {
			struct oem_split o = oracle_oem_split(h[j].it * t_gain(h[j].ag, h[j].dg), 2241, 450,
							      t_exp2(t_log2_gain(20) / 65536.0), 4.0);
			int eq = h[j].it == (u32)o.it &&
				 t40_ae_log2_ratio(h[j].dg, 1024) < t_log2_gain(h[j].ag + 1) - t_log2_gain(h[j].ag);

			differ += !eq;
			assert(l[j] + 11 >= 122 && l[j] <= 122 + 11);
		}
		if (!oem) {
			assert(differ == 4);	/* IT 1800 everywhere (OEM 2241), run1 keeps its 2.22x ISP dgain */
			assert(h[3].it == 1800 && h[3].ag == 5 && h[3].dg == 2275);
		} else {
			assert(!differ);
		}
	}
	/* the OEM loop holds one exposure (no hunting) at a steady scene: 200 more samples, no change */
	{
		struct ae_sim s = { 450, 0, 1024 }, s0;
		int j;

		(void)ae_sim_run(&s, 0.1941 / 9435.0, 122, 1, 400);
		s0 = s;
		for (j = 0; j < 200; j++)
			(void)ae_sim_run(&s, 0.1941 / 9435.0, 122, 1, 1);
		assert(s.it == s0.it && s.ag == s0.ag && s.dg == s0.dg);
	}
	/* statistics noise up to +-4 levels: no more exposure spread than the legacy loop, at most one gain step */
	{
		int amp;

		for (amp = 0; amp <= 4; amp++) {
			struct ae_sim s = { 450, 0, 1024 }, s2 = { 450, 0, 1024 };
			double r_oem, r_leg;

			(void)ae_sim_runn(&s, 0.1941 / 9435.0, 122, 1, 600, amp);
			r_oem = ae_sim_hi / ae_sim_lo;
			(void)ae_sim_runn(&s2, 0.1941 / 9435.0, 122, 0, 600, amp);
			r_leg = ae_sim_hi / ae_sim_lo;
			printf("oem84 noise %d: exposure spread oem %.3f legacy %.3f\n", amp, r_oem, r_leg);
			assert(r_oem <= 1.18 && r_oem <= r_leg + 0.001);
		}
	}
}

int main(void)
{
	test_comp();
	test_scence();
	test_stats();
	test_meter();
	test_af_speed();
	test_expr();
	test_af_trade();
	test_gain_cache();
	test_oem_split();
	puts("tx_isp_t40_ae_api tests passed");
	return 0;
}
