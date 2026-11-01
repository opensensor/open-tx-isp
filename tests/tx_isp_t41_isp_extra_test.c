/* SPDX-License-Identifier: MIT */
/*
 * T41 issue #171 controls: CSC colour range (0x08000097) register plan and
 * ISP draw units (0x080000a0) request decoding and MSCA shadow-port image,
 * against the OEM tx-isp-t41.ko 1.2.5 tisp_csccr_api_set and its presets,
 * tisp_s/g_draw_block_attr and tisp_msca_set_line.
 */
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "../driver/t41/tx_isp_t41_isp_extra.h"

struct pair { unsigned int value, reg; };
struct log { struct pair p[128]; int n; int fail_at; };

static int rec(void *ctx, unsigned int value, unsigned int reg)
{
	struct log *l = ctx;

	if (l->n == l->fail_at)
		return -5;
	assert(l->n < 128);
	l->p[l->n].value = value;
	l->p[l->n].reg = reg;
	l->n++;
	return 0;
}

static void csccr_req(unsigned char *r, unsigned int mode, const unsigned char v[8])
{
	r[0] = (unsigned char)mode;
	r[1] = r[2] = r[3] = 0;
	memcpy(r + 4, v, 8);
}

static void test_csccr(void)
{
	static const unsigned char ident[8] = { 0, 255, 0, 255, 0, 255, 0, 255 };
	static const unsigned char tv[8] = { 16, 235, 0, 255, 16, 240, 0, 255 };
	static const unsigned char bad[8] = { 200, 100, 0, 255, 0, 255, 0, 255 };
	static const unsigned char flat[8] = { 50, 50, 0, 255, 0, 255, 0, 255 };
	unsigned char r[T41_CSCCR_BYTES];
	unsigned int reg[5], val[5];
	struct t41_csccr_state st;
	int store;

	t41_csccr_init(&st);
	assert(st.info[0] == 0 && st.info[5] == 0xff && st.info[11] == 0xff);

	/* presets: OEM tisp_csccr_default/_range_stretch/_range_compress_mode */
	csccr_req(r, 0, ident);
	assert(t41_csccr_plan(r, reg, val, &store) == 5 && !store);
	assert(reg[0] == 0xf08e0 && val[0] == 0x04000400 && val[1] == 0xff00 &&
	       val[2] == 0x7f0180);
	assert(reg[3] == 0xf08ec && val[3] == 1 && reg[4] == 0xf0010 && val[4] == 1);
	csccr_req(r, 1, ident);
	assert(t41_csccr_plan(r, reg, val, &store) == 5 && !store);
	assert(val[0] == 0x048e04a8 && val[1] == 0xff10 && val[2] == 0x7f0180);
	csccr_req(r, 2, ident);
	assert(t41_csccr_plan(r, reg, val, &store) == 5 && !store);
	assert(val[0] == 0x0384036f && val[1] == 0x10db00 && val[2] == 0x700190);

	/* custom identity range reproduces the default preset */
	csccr_req(r, 3, ident);
	assert(t41_csccr_plan(r, reg, val, &store) == 5 && store);
	assert(val[0] == 0x04000400 && val[1] == 0xff00 && val[2] == 0x7f0180);

	/* custom 16..235 / 16..240 in, full out (stretch-like):
	 * ky = (255*1024 + 109) / 219 = 1192 (0x4a8), kuv = (255*1024+112)/224 = 1166 (0x48e) */
	csccr_req(r, 3, tv);
	assert(t41_csccr_plan(r, reg, val, &store) == 5 && store);
	assert(val[0] == (0x48eU << 16 | 0x4a8U));
	assert(val[1] == (0xff00U | 16U));	/* y_out_min 0 << 16 | y_in_min 16 */
	assert(val[2] == 0x7f0180);

	/* min > max: stock -1 with nothing written */
	csccr_req(r, 3, bad);
	assert(t41_csccr_plan(r, reg, val, &store) == -T41_CSCCR_EINVAL && !store);
	/* empty input range: stock divides by zero; refused */
	csccr_req(r, 3, flat);
	assert(t41_csccr_plan(r, reg, val, &store) == -T41_CSCCR_EINVAL);
	/* unknown mode: stock returns 0, nothing written */
	csccr_req(r, 4, ident);
	assert(t41_csccr_plan(r, reg, val, &store) == 0 && !store);
}

static void draw_req(unsigned char *r, int n, int type, int en, int a, int b,
		     int c, int d, int y, int u, int v, int width, int alpha,
		     int extend)
{
	memset(r, 0xee, T41_DRAW_BYTES);
	r[0] = (unsigned char)n;
	r[4] = (unsigned char)type; r[5] = r[6] = r[7] = 0;
	r[8] = 1; r[9] = r[10] = r[11] = 0;
	r[12] = (unsigned char)en;
	t41_draw_wr16(r + 14, (unsigned int)a);
	t41_draw_wr16(r + 16, (unsigned int)b);
	t41_draw_wr16(r + 18, (unsigned int)c);
	t41_draw_wr16(r + 20, (unsigned int)d);
	r[25] = (unsigned char)y; r[26] = (unsigned char)u; r[27] = (unsigned char)v;
	r[28] = (unsigned char)width;
	r[29] = (unsigned char)alpha;
	t41_draw_wr16(r + 30, (unsigned int)extend);
}

static void test_draw(void)
{
	struct t41_draw_state s;
	struct log l;
	unsigned char r[T41_DRAW_BYTES], g[T41_DRAW_BYTES];
	unsigned int skipped = 0;

	memset(&s, 0, sizeof(s));
	memset(&l, 0, sizeof(l));
	l.fail_at = -1;

	/* nothing dirty: nothing written */
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 0 && l.n == 0);

	/* type 0, unit 3 */
	draw_req(r, 3, 0, 1, 100, 50, 200, 120, 235, 128, 128, 24, 7, 0x1234);
	assert(t41_draw_set(&s, r) == 0 && s.dirty == 1U << 3);
	assert(s.unit[3].extend == 0);	/* type 0 keeps the old extend */
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4 && l.n == 4 && !s.dirty);
	assert(l.p[0].reg == 0xf0430 && l.p[0].value == (100U << 16 | 50U));
	assert(l.p[1].reg == 0xf0434 && l.p[1].value == (200U << 16 | 120U));
	assert(l.p[2].reg == 0xf0438 && l.p[2].value == (24U << 24 | 235U << 16 | 128U << 8 | 128U));
	assert(l.p[3].reg == 0xf043c && l.p[3].value == (7U << 8 | 1U));

	/* GET: unit from the request, YUV back at +25/+26/+27 */
	memset(g, 0, sizeof(g));
	g[0] = 3;
	assert(t41_draw_get(&s, g) == 0);
	assert(g[4] == 0 && g[12] == 1 && t41_draw_rd16(g + 14) == 100 &&
	       t41_draw_rd16(g + 16) == 50 && t41_draw_rd16(g + 18) == 200 &&
	       t41_draw_rd16(g + 20) == 120);
	assert(g[25] == 235 && g[26] == 128 && g[27] == 128 && g[28] == 24 && g[29] == 7);
	assert(t41_draw_rd16(g + 30) == 0);	/* extend only for type 1 */

	/* type 1 with extend */
	l.n = 0;
	draw_req(r, 0, 1, 1, 10, 20, 30, 40, 16, 1, 2, 4, 3, 0x55);
	assert(t41_draw_set(&s, r) == 0);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[0].reg == 0xf0400 && l.p[3].reg == 0xf040c);
	assert(l.p[3].value == (0x55U << 16 | 3U << 8 | 0x10U | 1U));
	memset(g, 0, sizeof(g));
	g[0] = 0;
	assert(t41_draw_get(&s, g) == 0 && g[4] == 1 && t41_draw_rd16(g + 30) == 0x55);

	/* type 2 horizontal line right-to-left: x0 = min, zero height -> width */
	l.n = 0;
	draw_req(r, 1, 2, 1, 300, 80, 100, 80, 16, 128, 128, 6, 7, 0);
	assert(t41_draw_set(&s, r) == 0);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[0].value == (100U << 16 | 80U));
	assert(l.p[1].value == (200U << 16 | 6U));
	assert(l.p[3].value == (7U << 8 | 1U));

	/* type 2 sloped, shallow down-right: octant 0, slope = dy*256/dx */
	l.n = 0;
	draw_req(r, 2, 2, 1, 0, 0, 200, 100, 16, 128, 128, 2, 7, 0);
	assert(t41_draw_set(&s, r) == 0);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[1].value == (202U << 16 | 102U));
	assert(l.p[3].value == (1U | 0x20U | 7U << 8 | (0U << 9 | 128U) << 16));
	/* steep down-right: octant 2, slope = dx*256/dy */
	l.n = 0;
	draw_req(r, 2, 2, 1, 0, 0, 100, 200, 16, 128, 128, 2, 7, 0);
	t41_draw_set(&s, r);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[3].value == (1U | 0x20U | 7U << 8 | (2U << 9 | 128U) << 16));
	/* up-right (dy < 0): shallow octant 1, steep octant 3, size uses |dy| */
	l.n = 0;
	draw_req(r, 2, 2, 1, 0, 100, 200, 0, 16, 128, 128, 2, 7, 0);
	t41_draw_set(&s, r);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[0].value == (0U << 16 | 0U));
	assert(l.p[1].value == (202U << 16 | 102U));
	assert(l.p[3].value == (1U | 0x20U | 7U << 8 | (1U << 9 | 128U) << 16));
	l.n = 0;
	draw_req(r, 2, 2, 1, 0, 200, 100, 0, 16, 128, 128, 2, 7, 0);
	t41_draw_set(&s, r);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[3].value == (1U | 0x20U | 7U << 8 | (3U << 9 | 128U) << 16));

	/* enabled sloped line on unit >= 8: skipped (stock "not use line") */
	l.n = 0;
	skipped = 0;
	draw_req(r, 9, 2, 1, 0, 0, 200, 100, 16, 128, 128, 2, 7, 0);
	t41_draw_set(&s, r);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 0 && l.n == 0);
	assert(skipped == 1U << 9 && !s.dirty);
	/* disabled sloped line on unit >= 8 is written (enable 0) */
	l.n = 0;
	draw_req(r, 9, 2, 0, 0, 0, 200, 100, 16, 128, 128, 2, 7, 0);
	t41_draw_set(&s, r);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4);
	assert(l.p[0].reg == 0xf0490 && l.p[3].value == (0x20U | 7U << 8));

	/* unknown type: stored and dirty, nothing written, fields kept */
	l.n = 0;
	draw_req(r, 3, 5, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0);
	assert(t41_draw_set(&s, r) == 0 && s.unit[3].a == 100);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 0 && !s.dirty);
	memset(g, 0, sizeof(g));
	g[0] = 3;
	assert(t41_draw_get(&s, g) == 0 && g[4] == 5 && g[12] == 0);

	/* unit >= 20 refused (stock writes past its table) */
	draw_req(r, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	assert(t41_draw_set(&s, r) == -T41_DRAW_EINVAL);
	g[0] = 20;
	assert(t41_draw_get(&s, g) == -T41_DRAW_EINVAL);

	/* write error: the unit stays dirty for the next frame */
	l.n = 0;
	l.fail_at = 2;
	draw_req(r, 4, 0, 1, 1, 2, 3, 4, 0, 0, 0, 1, 1, 0);
	t41_draw_set(&s, r);
	assert(t41_draw_emit(&s, rec, &l, &skipped) == -5 && (s.dirty & (1U << 4)));
	l.fail_at = -1;
	l.n = 0;
	assert(t41_draw_emit(&s, rec, &l, &skipped) == 4 && !s.dirty);
}

int main(void)
{
	test_csccr();
	test_draw();
	printf("tx_isp_t41_isp_extra_test: ok\n");
	return 0;
}
