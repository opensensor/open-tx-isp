/* host side of tests/t40_gamma_ev_host.sh: driver/t40/tx_isp_t40_gamma_ev.h on stdin cases (see diff_gamma_ev.py) */
#include <stdint.h>
#include <stdio.h>
#include GAMMA_EV_H

int main(void)
{
	char m;
	unsigned int i;

	while (scanf(" %c", &m) == 1) {
		uint32_t node[10], cur, evs, a, b, c;
		unsigned int str[10], curve[128];
		uint8_t s8[10];
		uint16_t cv[128], out[129];
		unsigned long long fnum, saved;
		unsigned int man, freq;
		int r;

		if (m == 'L') {		/* L s curve[128] */
			scanf("%u", &a);
			for (i = 0; i < 128; i++) { scanf("%u", &curve[i]); cv[i] = (uint16_t)curve[i]; }
			t40_gamma_strength_lut(cv, a, out);
			for (i = 0; i < 129; i++) printf("%u ", out[i]);
			printf("\n");
			continue;
		}
		for (i = 0; i < 10; i++) scanf("%u", &node[i]);
		for (i = 0; i < 10; i++) { scanf("%u", &str[i]); s8[i] = (uint8_t)str[i]; }
		scanf("%u %u", &cur, &evs);
		if (m == 'I') {		/* I node str cur evs ev skip force */
			scanf("%u %u %u", &a, &b, &c);
			r = t40_gamma_interp_by_ev(node, s8, &cur, &evs, a, b, (uint8_t)c);
			printf("%d %u %u\n", r, cur, evs);
		} else {		/* E node str cur evs ev_lo ev_hi manual freq fnum saved curve[128] */
			scanf("%u %u %u %u %llu %llu", &a, &b, &man, &freq, &fnum, &saved);
			for (i = 0; i < 128; i++) { scanf("%u", &curve[i]); cv[i] = (uint16_t)curve[i]; }
			r = t40_gamma_ev_due(node, s8, &cur, &evs, a, b, (uint8_t)man, (uint8_t)freq, fnum, (uint64_t *)&saved);
			printf("%d %u %u %llu", r, cur, evs, saved);
			if (r) {
				t40_gamma_strength_lut(cv, cur, out);
				for (i = 0; i < 129; i++) printf(" %u", out[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
