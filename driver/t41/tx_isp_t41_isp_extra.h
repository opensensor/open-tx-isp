/* SPDX-License-Identifier: MIT */
/*
 * T41 tuning controls of issue #171 that have no other home, rebuilt as
 * plain C from the OEM tx-isp-t41.ko of SDK 1.2.5 (libt41-firmware 4494):
 *
 *  - CSC colour range (control 0x08000097, IMPISPCsccrModeAttr, 12 bytes):
 *    tx_isp_csccr_s_mode / tx_isp_csccr_g_mode -> tisp_s/g_csccr_mode ->
 *    tisp_csccr_api_set / tisp_csccr_api_get and the three presets
 *    tisp_csccr_default_mode, _range_stretch_mode, _range_compress_mode.
 *  - ISP draw units (control 0x080000a0, IMPISPDrawBlockAttr, 32 bytes):
 *    tx_isp_draw_block_s/g_attr -> tisp_s/g_draw_block_attr, drawn by
 *    tisp_msca_set_line from the per-frame tisp_msca_Shd_ctrl.
 *
 * Kept free of kernel state for the host test; the driver glue is in
 * tx_isp_t41_recovered.c (t41_tuning_csccr, t41_tuning_draw_block,
 * t41_msca_commit_frame_shadow).
 */
#ifndef TX_ISP_T41_ISP_EXTRA_H
#define TX_ISP_T41_ISP_EXTRA_H

/* ---- CSC colour range ---------------------------------------------------- */

#define T41_CSCCR_BYTES		12U
#define T41_CSCCR_WRITES	5U
#define T41_CSCCR_EINVAL	22

/*
 * Request: s32 mode (0 default, 1 stretch, 2 compress, 3 custom), then the
 * eight bytes input_y_min, input_y_max, output_y_min, output_y_max,
 * input_uv_min, input_uv_max, output_uv_min, output_uv_max.
 * Stock keeps the whole 12-byte request only for the custom mode (the
 * presets leave it alone, initial value { 0, 00 ff 00 ff 00 ff 00 ff });
 * GET copies that record back.
 */
struct t41_csccr_state {
	unsigned char info[T41_CSCCR_BYTES];
};

static inline void t41_csccr_init(struct t41_csccr_state *s)
{
	static const unsigned char init[T41_CSCCR_BYTES] = {
		0, 0, 0, 0, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff,
	};
	unsigned int i;

	for (i = 0; i < T41_CSCCR_BYTES; ++i)
		s->info[i] = init[i];
}

/*
 * Plan the register writes of tisp_csccr_api_set.  Fills reg/value with the
 * sequence 0xf08e0, 0xf08e4, 0xf08e8, 0xf08ec = 1, 0xf0010 = 1 and returns
 * the number of writes (5); 0 for an unknown mode (stock returns 0 and does
 * nothing); -T41_CSCCR_EINVAL for a custom range with min > max (stock -1)
 * or a zero-width input range (stock divides by it; refused here).  *store
 * is set when the request becomes the stored record (custom mode only).
 */
static inline int t41_csccr_plan(const unsigned char *req, unsigned int *reg,
				 unsigned int *value, int *store)
{
	unsigned int mode = (unsigned int)req[0] | ((unsigned int)req[1] << 8) |
			    ((unsigned int)req[2] << 16) |
			    ((unsigned int)req[3] << 24);
	int y_in_min = req[4], y_in_max = req[5];
	int y_out_min = req[6], y_out_max = req[7];
	int uv_in_min = req[8], uv_in_max = req[9];
	int uv_out_min = req[10], uv_out_max = req[11];
	int y_in, y_out, uv_in, ky, kuv;

	*store = 0;
	reg[0] = 0xf08e0U;
	reg[1] = 0xf08e4U;
	reg[2] = 0xf08e8U;
	reg[3] = 0xf08ecU;
	value[3] = 1U;
	reg[4] = 0xf0010U;
	value[4] = 1U;
	switch (mode) {
	case 0:
		value[0] = 0x04000400U;
		value[1] = 0x0000ff00U;
		value[2] = 0x007f0180U;
		return T41_CSCCR_WRITES;
	case 1:
		value[0] = 0x048e04a8U;
		value[1] = 0x0000ff10U;
		value[2] = 0x007f0180U;
		return T41_CSCCR_WRITES;
	case 2:
		value[0] = 0x0384036fU;
		value[1] = 0x0010db00U;
		value[2] = 0x00700190U;
		return T41_CSCCR_WRITES;
	case 3:
		break;
	default:
		return 0;
	}
	if (uv_in_max < uv_in_min || y_in_max < y_in_min ||
	    y_out_max < y_out_min || uv_out_max < uv_out_min)
		return -T41_CSCCR_EINVAL;
	y_in = y_in_max - y_in_min;
	y_out = y_out_max - y_out_min;
	uv_in = uv_in_max - uv_in_min;
	if (!y_in || !uv_in)
		return -T41_CSCCR_EINVAL;
	ky = (y_out * 0x400 + y_in / 2) / y_in;
	kuv = ((uv_out_max - uv_out_min) * 0x400 + uv_in / 2) / uv_in;
	if (ky > 0x7ff)
		ky = 0x7ff;
	if (kuv > 0x7ff)
		kuv = 0x7ff;
	value[0] = ((unsigned int)kuv & 0x7ffU) << 16 | ((unsigned int)ky & 0x7ffU);
	value[1] = ((unsigned int)(y_out * 0x100) & 0xffffU) |
		   (unsigned int)y_out_min << 16 | (unsigned int)y_in_min;
	value[2] = ((unsigned int)(uv_out_max - 0x80) * 0x10000U & 0x1ff0000U) |
		   ((unsigned int)(uv_out_min - 0x80) & 0x1ffU);
	*store = 1;
	return T41_CSCCR_WRITES;
}

/* ---- ISP draw units ------------------------------------------------------- */

#define T41_DRAW_BYTES		32U
#define T41_DRAW_UNITS		20U
#define T41_DRAW_SLOPE_UNITS	8U	/* sloped lines: units 0..7 only */
#define T41_DRAW_REG_BASE	0xf0400U	/* + 16 * unit */
#define T41_DRAW_EINVAL		22

/*
 * Request IMPISPDrawBlockAttr (32 bytes, little endian): u8 pinum (unit
 * 0..19); s32 type at +4; s32 color_type at +8 (libimp converts RGB to the
 * YUV triple before the call, the module ignores it); u8 enable at +12;
 * u16 at +14, +16, +18, +20 (left/top/width/height or startx/starty/endx/
 * endy); colour RGB at +22..24 (ignored), YUV at +25..27; u8 line width at
 * +28; u8 alpha at +29; u16 extend at +30 (type 1 only).
 *
 * Per unit the module keeps (stock 24-byte record): type (low byte),
 * enable, the four u16, colour y << 16 | u << 8 | v, width, alpha, extend.
 * Types as the OEM module draws them (tisp_msca_set_line): 0 plain unit,
 * 1 unit with extend (bit 4 and extend << 16 in the control word),
 * 2 line between two points (horizontal/vertical, or sloped on units 0..7).
 */
struct t41_draw_unit {
	unsigned int type, en;
	unsigned int a, b, c, d;	/* the four u16 of the request */
	unsigned int color;		/* y << 16 | u << 8 | v */
	unsigned int width, alpha, extend;
};

struct t41_draw_state {
	struct t41_draw_unit unit[T41_DRAW_UNITS];
	unsigned int dirty;	/* bit n: unit n not written yet */
};

static inline unsigned int t41_draw_rd16(const unsigned char *p)
{
	return (unsigned int)p[0] | ((unsigned int)p[1] << 8);
}

static inline void t41_draw_wr16(unsigned char *p, unsigned int v)
{
	p[0] = (unsigned char)v;
	p[1] = (unsigned char)(v >> 8);
}

/*
 * tisp_s_draw_block_attr.  The type is always stored and the unit marked
 * dirty; types 0 and 2 take the geometry, colour, width and alpha, type 1
 * also the extend; other types change nothing else.
 * Difference to stock: a unit >= 20 is refused (stock indexes past its
 * 20-entry table).
 */
static inline int t41_draw_set(struct t41_draw_state *s,
			       const unsigned char *req)
{
	unsigned int n = req[0];
	unsigned int type = t41_draw_rd16(req + 4) |
			    (t41_draw_rd16(req + 6) << 16);
	struct t41_draw_unit *u;

	if (n >= T41_DRAW_UNITS)
		return -T41_DRAW_EINVAL;
	u = &s->unit[n];
	u->type = type & 0xffU;
	if (type <= 2U) {
		u->en = req[12];
		u->a = t41_draw_rd16(req + 14);
		u->b = t41_draw_rd16(req + 16);
		u->c = t41_draw_rd16(req + 18);
		u->d = t41_draw_rd16(req + 20);
		u->color = (unsigned int)req[25] << 16 |
			   (unsigned int)req[26] << 8 | req[27];
		u->width = req[28];
		u->alpha = req[29];
		if (type == 1U)
			u->extend = t41_draw_rd16(req + 30);
	}
	s->dirty |= 1U << n;
	return 0;
}

/*
 * tisp_g_draw_block_attr: the stored type, and for types 0..2 the stored
 * fields (the extend for type 1 only).
 * Differences to stock: the unit number is taken from the caller's request
 * (stock reads it from an uninitialised kernel stack buffer), and the YUV
 * colour goes back to +25/+26/+27 (stock writes v over u and leaves +27).
 */
static inline int t41_draw_get(const struct t41_draw_state *s,
			       unsigned char *req)
{
	unsigned int n = req[0];
	const struct t41_draw_unit *u;

	if (n >= T41_DRAW_UNITS)
		return -T41_DRAW_EINVAL;
	u = &s->unit[n];
	t41_draw_wr16(req + 4, u->type);
	t41_draw_wr16(req + 6, 0);
	if (u->type > 2U)
		return 0;
	req[12] = (unsigned char)u->en;
	t41_draw_wr16(req + 14, u->a);
	t41_draw_wr16(req + 16, u->b);
	t41_draw_wr16(req + 18, u->c);
	t41_draw_wr16(req + 20, u->d);
	req[25] = (unsigned char)(u->color >> 16);
	req[26] = (unsigned char)(u->color >> 8);
	req[27] = (unsigned char)u->color;
	req[28] = (unsigned char)u->width;
	req[29] = (unsigned char)u->alpha;
	if (u->type == 1U)
		t41_draw_wr16(req + 30, u->extend);
	return 0;
}

typedef int (*t41_draw_pair_fn)(void *ctx, unsigned int value,
				unsigned int reg);

static inline int t41_draw_abs16(int v)
{
	short s = (short)v;

	return s < 0 ? -s : s;
}

/*
 * tisp_msca_set_line: per dirty unit n (the bit is cleared first) four
 * (value, register) pairs to 0xf0400 + 16 * n + 0/4/8/12:
 *   position, size, colour | width << 24, control word.
 * Type 0: a << 16 | b, c << 16 | d, control alpha << 8 | enable.
 * Type 1: as type 0, control also | 0x10 | extend << 16.
 * Type 2: x0 = min(a, c), y0 = min(b, d), dx = |c - a|, dy = (d - b) with
 *   the sign of the x direction; a horizontal or vertical line gets the
 *   length |dx| << 16 | |dy| (a zero length replaced by the width) and the
 *   type 0 control word; a sloped line (units 0..7) gets (dx + 2) << 16 |
 *   (dy + 2), control enable | 0x20 | alpha << 8 | (octant << 9 | slope)
 *   << 16 with slope = minor * 256 / major; an enabled sloped line on a
 *   unit >= 8 is skipped (stock logs "not use line").
 * Other types write nothing.  Returns the number of pairs, or a negative
 * write error (the unit's dirty bit stays set then).
 */
static inline int t41_draw_emit(struct t41_draw_state *s,
				t41_draw_pair_fn write, void *ctx,
				unsigned int *skipped)
{
	unsigned int n;
	int pairs = 0;
	int ret;

	for (n = 0; n < T41_DRAW_UNITS; ++n) {
		const struct t41_draw_unit *u = &s->unit[n];
		unsigned int reg = T41_DRAW_REG_BASE + 16U * n;
		unsigned int pos, size, ctl;
		unsigned int colour = (u->color & 0xffffffU) |
				      (u->width & 0xffU) << 24;

		if (!(s->dirty & (1U << n)))
			continue;
		if (u->type == 0U || u->type == 1U) {
			pos = u->a << 16 | (u->b & 0xffffU);
			size = u->c << 16 | (u->d & 0xffffU);
			ctl = (u->alpha & 0xffU) << 8 | (u->en & 0xffU);
			if (u->type == 1U)
				ctl |= 0x10U | u->extend << 16;
		} else if (u->type == 2U) {
			unsigned int x0 = u->a, y0 = u->d;
			int dx = (int)(short)(unsigned short)(u->c - u->a);
			int dy = (int)(short)(unsigned short)(u->d - u->b);

			if (u->c < u->a) {
				dx = (int)(short)(unsigned short)-dx;
				dy = (int)(short)(unsigned short)-dy;
				x0 = u->c;
			}
			if (u->b < u->d)
				y0 = u->b;
			pos = x0 << 16 | y0;
			if (!dx || !dy) {
				unsigned int lx = (unsigned int)t41_draw_abs16(dx);
				unsigned int ly = (unsigned int)t41_draw_abs16(dy);

				if (!ly)
					ly = u->width & 0xffU;
				if (!lx)
					lx = u->width & 0xffU;
				size = lx << 16 | ly;
				ctl = (u->alpha & 0xffU) << 8 | (u->en & 0xffU);
			} else {
				unsigned int octant = 0, slope = 0;

				if (n >= T41_DRAW_SLOPE_UNITS && u->en) {
					s->dirty &= ~(1U << n);
					if (skipped)
						*skipped |= 1U << n;
					continue;
				}
				if (n < T41_DRAW_SLOPE_UNITS && u->en) {
					if (dy < 0) {
						dy = -dy;
						if (dx < dy) {
							octant = 3;
							slope = (unsigned int)((dx << 8) / dy) & 0xffffU;
						} else {
							octant = 1;
							slope = (unsigned int)((dy << 8) / dx) & 0xffffU;
						}
					} else if (dx < dy) {
						octant = 2;
						slope = (unsigned int)((dx << 8) / dy) & 0xffffU;
					} else {
						slope = (unsigned int)((dy << 8) / dx) & 0xffffU;
					}
				}
				size = (unsigned int)(dx + 2) * 0x10000U |
				       (unsigned int)(dy + 2);
				ctl = (u->en & 0xffU) | 0x20U |
				      (u->alpha & 0xffU) << 8 |
				      (octant << 9 | slope) << 16;
			}
		} else {
			s->dirty &= ~(1U << n);
			continue;
		}
		ret = write(ctx, pos, reg);
		if (!ret)
			ret = write(ctx, size, reg + 4U);
		if (!ret)
			ret = write(ctx, colour, reg + 8U);
		if (!ret)
			ret = write(ctx, ctl, reg + 12U);
		if (ret)
			return ret;
		s->dirty &= ~(1U << n);
		pairs += 4;
	}
	return pairs;
}

#endif /* TX_ISP_T41_ISP_EXTRA_H */
