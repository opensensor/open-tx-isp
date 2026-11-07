/* host side of tests/t40_ae_target_host.sh: driver/t40/tx_isp_t40_ae_target.h on stdin cases (see diff_ae_target.py) */
#include <stdint.h>
#include <stdio.h>
#include AE_TARGET_H

static uint32_t rd(void)
{
	unsigned long v = 0;

	if (scanf("%lu", &v) != 1)
		return 0;
	return (uint32_t)v;
}

int main(void)
{
	char m;
	unsigned int i;

	while (scanf(" %c", &m) == 1) {
		if (m == 'T') {		/* T ev evl[10] tgl[10] q */
			uint32_t ev = rd(), e[10], t[10], q;

			for (i = 0; i < 10; i++)
				e[i] = rd();
			for (i = 0; i < 10; i++)
				t[i] = rd();
			q = rd();
			printf("%u\n", t40_ae_long_target(ev, e, t, q));
		} else if (m == 'W') {	/* W p3 p4 p10 rows cols rowh[15] colw[15] w[225] s0 s1 s2 c0 c2 [225 each] */
			static uint32_t s0[225], s1[225], s2[225], c0[225], c2[225];
			static uint8_t w[225];
			uint16_t rowh[15], colw[15];
			uint32_t p3 = rd(), p4 = rd(), p10 = rd(), rows = rd(), cols = rd();

			for (i = 0; i < 15; i++)
				rowh[i] = (uint16_t)rd();
			for (i = 0; i < 15; i++)
				colw[i] = (uint16_t)rd();
			for (i = 0; i < 225; i++)
				w[i] = (uint8_t)rd();
			for (i = 0; i < 225; i++)
				s0[i] = rd();
			for (i = 0; i < 225; i++)
				s1[i] = rd();
			for (i = 0; i < 225; i++)
				s2[i] = rd();
			for (i = 0; i < 225; i++)
				c0[i] = rd();
			for (i = 0; i < 225; i++)
				c2[i] = rd();
			printf("%u\n", t40_aet_wmean(s0, s1, s2, c0, c2, rowh, colw, rows, cols, w, p3, p4, p10 & 0xffffU));
		} else if (m == 'A') {	/* A luma mode scene thr mp4 mp5 mp6 hl5..hl10 npix hist[256] -> p3 p4 p10 luma' */
			static uint32_t hist[256];
			struct t40_aet_bank b = { { 0 } };
			uint32_t luma = rd(), p3, p4, p10, scene, npix;

			b.hl[0] = rd();
			scene = rd();
			b.zone[35] = (uint16_t)rd();
			b.mp[4] = (uint16_t)rd();
			b.mp[5] = (uint16_t)rd();
			b.mp[6] = (uint16_t)rd();
			for (i = 5; i < 11; i++)
				b.hl[i] = rd();
			npix = rd();
			for (i = 0; i < 256; i++)
				hist[i] = rd();
			t40_aet_band_params(&b, scene, &p3, &p4, &p10);
			if (b.hl[0] == 1U)
				luma = t40_aet_hl_boost(luma, hist, b.zone[35], p4, p10, npix);
			printf("%u %u %u %u\n", p3, p4, p10, luma);
		} else if (m == 'G') {	/* G it ag dg luma t0 sc0 sc1 scword ev[10] tgt[10] scw[10] -> ev0 aim ev'[10] tgt'[10] */
			struct t40_aet_bank b = { { 0 } };
			uint32_t it = rd(), ag = rd(), dg = rd(), luma = rd(), t0 = rd(), e[10], t[10], ev0;
			uint16_t scword;

			b.sc[0] = (uint16_t)rd();
			b.sc[1] = (uint16_t)rd();
			scword = (uint16_t)rd();
			for (i = 0; i < 10; i++)
				b.ev[i] = rd();
			for (i = 0; i < 10; i++)
				b.tgt[i] = (uint16_t)rd();
			for (i = 0; i < 10; i++)
				b.scw[i] = (uint16_t)rd();
			t40_aet_lists(&b, scword, e, t);
			ev0 = t40_aet_ev_q10(it, ag, dg);
			printf("%u %u", ev0, t40_aet_aim(ev0, t0, luma ? luma : 1U));
			for (i = 0; i < 10; i++)
				printf(" %u", e[i]);
			for (i = 0; i < 10; i++)
				printf(" %u", t[i]);
			printf("\n");
		} else if (m == 'I') {	/* I curve[129] -> bad: values whose inverse does not land on their output run, or not nearest */
			uint16_t g[129];
			uint8_t inv[256];
			uint32_t bad = 0, v, l;

			for (i = 0; i < 129; i++)
				g[i] = (uint16_t)rd();
			if (t40_aet_ginv_build(g, inv)) {
				printf("invalid\n");
				continue;
			}
			for (v = 0; v < 256U; v++) {
				uint32_t best = 999, d;

				for (l = 0; l < 256U; l++) {
					d = t40_aet_gamma8(g, l) > v ? t40_aet_gamma8(g, l) - v : v - t40_aet_gamma8(g, l);
					if (d < best)
						best = d;
				}
				d = t40_aet_gamma8(g, inv[v]) > v ? t40_aet_gamma8(g, inv[v]) - v : v - t40_aet_gamma8(g, inv[v]);
				if (d != best)
					bad++;
			}
			for (l = 0; l < 256U; l++)	/* a value the curve produces maps back into its own run */
				if (t40_aet_gamma8(g, inv[t40_aet_gamma8(g, l)]) != t40_aet_gamma8(g, l))
					bad++;
			printf("%u\n", bad);
		} else if (m == 'K') {	/* K curve[129] base comp -> t40_aet_comp_out(curve, base, comp_word(128, comp)) */
			uint16_t g[129];
			uint32_t base, comp;

			for (i = 0; i < 129; i++)
				g[i] = (uint16_t)rd();
			base = rd();
			comp = rd();
			printf("%u\n", t40_aet_comp_out(g, base, t40_aet_comp_word(128U, comp)));
		} else if (m == 'C') {	/* C bin comp -> word */
			uint32_t bin = rd(), comp = rd();

			printf("%u\n", t40_aet_comp_word((uint16_t)bin, comp));
		}
	}
	return 0;
}
