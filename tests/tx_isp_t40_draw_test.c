/* Host test of driver/t40/tx_isp_t40_draw.h (T40 ISP draw / privacy mask, Lu-Fi/openimp#186 #187). */
#include <assert.h>
#include <stdio.h>
#include <string.h>

#include "../driver/t40/tx_isp_t40_draw.h"

struct wr { u32 v[256], a[256]; unsigned n; };

static void sink(void *c, u32 v, u32 a)
{
	struct wr *w = c;

	w->v[w->n] = v;
	w->a[w->n++] = a;
}

static void put16(u8 *p, u16 v) { memcpy(p, &v, 2); }
static void put32(u8 *p, u32 v) { memcpy(p, &v, 4); }

int main(void)
{
	static u8 st[2 * 1860], user[896];
	u8 *s1 = st + 1860;
	struct wr w;
	unsigned bad, i;

	/* tisp_s_draw_attr: output channel 1, unit 0, window (type 2), green, 4 px, alpha 7 */
	memset(user, 0, sizeof user);
	put32(user + 448, 2);
	user[448 + 8] = 1;
	put16(user + 448 + 10, 200);
	put16(user + 448 + 12, 100);
	put16(user + 448 + 14, 400);
	put16(user + 448 + 16, 200);
	user[448 + 21] = 0x12; user[448 + 22] = 0x34; user[448 + 23] = 0x56;
	user[448 + 24] = 4; user[448 + 25] = 7;
	memset(st, 0, sizeof st);
	t40_draw_set_state(st, user);
	assert(st[616 + 100] == 2 && st[616 + 104] == 1);
	assert(t40_dr_u16(st + 616 + 106) == 200 && t40_dr_u16(st + 616 + 108) == 100);
	assert(t40_dr_u16(st + 616 + 110) == 400 && t40_dr_u16(st + 616 + 112) == 200);
	assert(t40_dr_u32(st + 616 + 116) == 0x123456u && st[616 + 120] == 4 && st[616 + 121] == 7);
	assert(st[100] == 0 && st[104] == 0);            /* channel 0 untouched, no doubled offsets */
	assert(st[200] == 0);

	/* register sequence of that window: 4 pairs at 0x16400.. for the channel (reg = vin*0x1000 + ch*0x100) */
	memset(&w, 0, sizeof w);
	bad = t40_line_chx_emit(st + 616, 0x100, sink, &w);
	assert(bad == 0);
	assert(w.a[0] == 0x100 + 0x16400 && w.v[0] == (200u << 16 | 100u));
	assert(w.a[1] == 0x100 + 0x16404 && w.v[1] == (400u << 16 | 200u));
	assert(w.a[2] == 0x100 + 0x16408 && w.v[2] == (0x123456u | 4u << 24));
	assert(w.a[3] == 0x100 + 0x1640c && w.v[3] == (1u | 7u << 8));
	/* disabled unit of type 0 still emits its 4 pairs (OEM writes all 16 units), unit 1 starts at +0x10 */
	assert(w.n == 16 * 4 && w.a[4] == 0x100 + 0x10 + 0x16400);

	/* line type, diagonal with positive slope, dx > dy: code 0, slope = (dy << 8) / dx */
	memset(st, 0, sizeof st);
	{
		u8 *u = s1;
		u[100] = 0; u[104] = 1;
		put16(u + 106, 100); put16(u + 108, 100); put16(u + 110, 300); put16(u + 112, 200);
		put32(u + 116, 0xabcdef); u[120] = 2; u[121] = 5;
	}
	memset(&w, 0, sizeof w);
	assert(t40_line_chx_emit(s1, 0, sink, &w) == 0);
	assert(w.v[0] == (100u << 16 | 100u));
	assert(w.v[1] == (200u << 16 | 100u));
	assert(w.v[3] == (1u | 0x20 | 5u << 8 | ((0u << 9 | ((100u << 8) / 200u)) << 16)));
	/* dx < dy: code 2 */
	put16(s1 + 110, 150); put16(s1 + 112, 300);
	memset(&w, 0, sizeof w);
	t40_line_chx_emit(s1, 0, sink, &w);
	assert(((w.v[3] >> 16) >> 9) == 2u && ((w.v[3] >> 16) & 0x1ff) == ((50u << 8) / 200u));
	/* line from lower right to upper left (both coordinates decrease): flipped, still positive */
	put16(s1 + 106, 300); put16(s1 + 108, 300); put16(s1 + 110, 100); put16(s1 + 112, 200);
	memset(&w, 0, sizeof w);
	t40_line_chx_emit(s1, 0, sink, &w);
	assert(w.v[0] == (100u << 16 | 200u) && w.v[1] == (200u << 16 | 100u));
	assert(((w.v[3] >> 16) >> 9) == 0u);
	/* horizontal line (dy == 0): size = |dx| << 16 | line width, plain word */
	put16(s1 + 106, 10); put16(s1 + 108, 50); put16(s1 + 110, 110); put16(s1 + 112, 50);
	memset(&w, 0, sizeof w);
	t40_line_chx_emit(s1, 0, sink, &w);
	assert(w.v[0] == (10u << 16 | 50u) && w.v[1] == (100u << 16 | 2u) && w.v[3] == (1u | 5u << 8));
	/* unit 8 and beyond refuse an enabled slanted line, unknown types are refused */
	memset(st, 0, sizeof st);
	{
		u8 *u = s1 + 8 * 24;
		u[100] = 0; u[104] = 1;
		put16(u + 106, 0); put16(u + 108, 0); put16(u + 110, 50); put16(u + 112, 20);
		s1[100] = 9;
	}
	memset(&w, 0, sizeof w);
	bad = t40_line_chx_emit(s1, 0, sink, &w);
	assert(bad == 2 && w.n == 14 * 4);
	/* type 1 (range) carries the extra half word */
	memset(st, 0, sizeof st);
	s1[100] = 1; s1[104] = 1; put16(s1 + 122, 0x77); s1[121] = 3;
	memset(&w, 0, sizeof w);
	t40_line_chx_emit(s1, 0, sink, &w);
	assert(w.v[3] == (1u << 4 | 3u << 8 | 1u | 0x77u << 16));

	/* privacy mask enable word: BYTE enables per output channel, position fields do not leak in */
	memset(st, 0, sizeof st);
	assert(t40_mask_en_word(st) == 0);
	st[616 + 0x24] = 1; put16(st + 616 + 0x26, 0x1234); put16(st + 616 + 0x28, 0x5678);
	assert(t40_mask_en_word(st) == 2u);
	st[0x24 + 2 * 16] = 1;
	st[1232 + 0x24 + 3 * 16] = 1;
	assert(t40_mask_en_word(st) == 7u);
	for (i = 0; i < 1860; i++)
		st[i] = 0;
	put16(st + 0x26, 0xffff);                      /* position bits of a disabled unit */
	assert(t40_mask_en_word(st) == 0);
	puts("tx_isp_t40_draw_test: ok");
	return 0;
}
