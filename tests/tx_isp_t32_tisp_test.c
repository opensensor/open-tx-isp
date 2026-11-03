/* Host test: T32 tisp register init blocks built from the IQ bin
 * (driver/t32/tx_isp_t32_{gamma,...}.h).  With T32_IQ_BIN (cv8001-PRJ007-day.bin)
 * and T32_ADD_TRACE (the vendor's AddSensor writes of a QEMU run, local) each
 * block must equal the vendor's write sequence (3840x2160, SRGGB10). */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../driver/t32/tx_isp_t32_gamma.h"
#include "../driver/t32/tx_isp_t32_ydns.h"
#include "../driver/t32/tx_isp_t32_sdns.h"
#include "../driver/t32/tx_isp_t32_clm.h"
#include "../driver/t32/tx_isp_t32_cdns.h"
#include "../driver/t32/tx_isp_t32_dmsc.h"
#include "../driver/t32/tx_isp_t32_ysp.h"
#include "../driver/t32/tx_isp_t32_iq.h"
#include "t32_trace.h"

static int bad;
#define CHECK(c) do { if (!(c)) { bad++; printf("FAIL line %d: %s\n", __LINE__, #c); } } while (0)

static unsigned int covered_new;

static void vs_vendor(const char *what, const struct t32_front_write *w, int n)
{
	unsigned int reg[8192], val[8192], i;
	int at;

	if (!tr_n)
		return;
	CHECK(n > 0 && n <= 8192);
	if (n <= 0)
		return;
	for (i = 0; i < (unsigned int)n; i++) {
		reg[i] = w[i].reg;
		val[i] = w[i].val;
	}
	at = tr_find(reg, val, n);
	if (at < 0) {
		unsigned int s0, d = 0;

		bad++;
		printf("FAIL %s: %d writes not equal to a vendor sequence\n", what, n);
		for (s0 = 0; s0 < tr_n && !(tr[s0].reg == reg[0]); s0++)
			;
		for (i = 0; s0 + i < tr_n && i < (unsigned int)n && d < 12; i++)
			if (tr[s0 + i].reg != reg[i] || tr[s0 + i].val != val[i]) {
				printf("  #%u: %05x=%08x vendor %05x=%08x\n", i, reg[i], val[i], tr[s0 + i].reg, tr[s0 + i].val);
				d++;
			}
		return;
	}
	for (i = 0; i < (unsigned int)n; i++)
		tr[at + i].hit = 1;
	covered_new += n;
	printf("  %s: %d of %d writes equal the vendor's AddSensor writes (trace #%d)\n", what, n, n, at);
}

int main(void)
{
	const char *path = getenv("T32_IQ_BIN");
	FILE *f = path ? fopen(path, "rb") : NULL;
	static struct t32_front_write w[8192];

	if (getenv("T32_ADD_TRACE"))
		tr_load(getenv("T32_ADD_TRACE"));
	/* gamma: strength interpolation and refusals */
	{
		static u8 sec[T32_GAMMA_SEC_BYTES], lut[T32_GAMMA_CURVE_BYTES];
		unsigned int i;

		sec[0x5a] = 1;
		sec[0x48] = 0;
		CHECK(t32_gamma_strength(sec) == 0xff);
		sec[0x48] = 2;
		sec[0x49] = 77;
		CHECK(t32_gamma_strength(sec) == 77);
		sec[0x48] = 1;
		for (i = 0; i < 12; i++) {
			sec[0x18 + 4 * i] = 100 * (i + 1);
			sec[0x4a + i] = 10 * (i + 1);
		}
		CHECK(t32_gamma_strength(sec) == 10);	/* EV 0 is below the first knot */
		sec[0x18] = sec[0x19] = 0;		/* knots 0, 200, ...: interpolates 0 .. 200 at EV 0 */
		CHECK(t32_gamma_strength(sec) == 10);
		/* full strength keeps the curve, strength 0 gives the ramp */
		sec[0x48] = 0;
		for (i = 0; i < 129; i++) {
			lut[2 * i] = (i * 31) & 0xff;
			lut[2 * i + 1] = ((i * 31) >> 8) & 0xf;
		}
		CHECK(t32_gamma_init(sec, lut, sizeof(lut), w) == (int)T32_GAMMA_MAX_WRITES);
		CHECK(w[3].reg == 0x32044 && w[3].val == (u32)((31 << 12) | 0));
		sec[0x48] = 2;
		sec[0x49] = 0;
		CHECK(t32_gamma_init(sec, lut, sizeof(lut), w) == (int)T32_GAMMA_MAX_WRITES);
		CHECK(w[3].val == (u32)(32 << 12) && w[3 + 3 * 127].val == (u32)((4095 & 0xfff) << 12 | 4064));
		CHECK(t32_gamma_init(sec, lut, 100, w) == -1);
		sec[0] = 0x91; sec[1] = 0xff; sec[2] = 0x34; sec[3] = 0x01;
		CHECK(t32_gamma_init(sec, lut, sizeof(lut), w) == -1);
	}
	/* ydns: tables interpolated at index 1, enable bits */
	{
		static u8 sec[T32_YDNS_SEC_BYTES];
		unsigned int k;

		for (k = 0; k < 22; k++)
			sec[6 + 11 * k] = sec[7 + 11 * k] = k + 1;
		sec[4] = 1;
		sec[5] = 1;
		CHECK(t32_ydns_init(sec, w) == T32_YDNS_WRITES);
		CHECK(w[0].val == 0x11 && w[8].reg == 0xe050 && w[16].reg == 0xe000);
		CHECK(w[1].val == (u32)((4 & 3) << 8 | (5 & 3) << 12 | 3));	/* tables 2..4 */
	}
	/* sdns: parameter scale (piecewise) */
	CHECK(t32_sdns_scale(0x40) == 0x40 && t32_sdns_scale(0x41) == 0x44 && t32_sdns_scale(0x80) == 0x140);
	CHECK(t32_sdns_scale(0xc0) == 0x540 && t32_sdns_scale(0xff) == 0xbf4 && t32_sdns_scale(0x100) == 0x100);
	/* write counts of the blocks on an all-zero section with the block id */
	{
		static u8 d[T32_DMSC_SEC_BYTES], y[T32_YSP_SEC_BYTES], c[T32_CDNS_SEC_BYTES];

		d[0] = y[0] = 0x11; d[1] = y[1] = 0xda; d[2] = y[2] = 0x34; d[3] = y[3] = 0x01;
		CHECK(t32_dmsc_init(d, w) == T32_DMSC_WRITES);
		CHECK(t32_ysp_init(y, w) == T32_YSP_WRITES);
		CHECK(t32_cdns_init(c, w) == T32_CDNS_WRITES);
		d[0] = 0;
		CHECK(t32_dmsc_init(d, w) == -1);
	}
	/* CLM: inverse matrices of well-known primaries, ratio and shift, zone choice */
	{
		int m[9];
		u32 ratio, shift;
		static u8 sec[T32_CLM_SEC_BYTES], lut[3 * (T32_CLM_ZONE_BYTES + T32_CLM_TABLE)];
		static s16 tab[T32_CLM_TABLE];
		static u8 tb[T32_CLM_TABLE];
		unsigned int z, i;

		CHECK(t32_csc_inverse(0, m) == 0 && m[2] == 91881 && m[7] == 116130 && m[4] == -22553 && m[5] == -46802);
		CHECK(t32_csc_inverse(2, m) == 0 && m[2] == 103206 && m[7] == 121609);
		CHECK(t32_csc_inverse(6, m) == -1);
		t32_clm_ratio(2, &ratio, &shift);
		CHECK(ratio == 0x200 && shift == 0);
		t32_clm_ratio(1, &ratio, &shift);
		CHECK(ratio == 0 && shift == 0);
		t32_clm_ratio(255, &ratio, &shift);
		CHECK(shift == 7 && ratio == ((127 + 0x20000) / 255));
		t32_clm_ratio(5000, &ratio, &shift);
		CHECK(shift == 10);
		/* three zones with tags 3000 / 4000 / 6000, hysteresis 100: table value = zone number * 10 */
		sec[0x23] = 3;
		sec[0x24] = 100;
		for (z = 0; z < 3; z++) {
			int tag = z == 0 ? 3000 : z == 1 ? 4000 : 6000;

			lut[z * T32_CLM_ZONE_BYTES] = tag & 0xff;
			lut[z * T32_CLM_ZONE_BYTES + 1] = tag >> 8;
			for (i = 0; i < T32_CLM_TABLE; i++) {
				lut[z * T32_CLM_ZONE_BYTES + 2 + 2 * i] = 10 * (z + 1);
				lut[3 * T32_CLM_ZONE_BYTES + z * T32_CLM_TABLE + i] = 10 * (z + 1);
			}
		}
		CHECK(t32_clm_ct(sec, lut, sizeof(lut), 2000, tab, tb) == 0 && tab[0] == 10 && tb[0] == 10);
		CHECK(t32_clm_ct(sec, lut, sizeof(lut), 7000, tab, tb) == 0 && tab[5] == 30 && tb[5] == 30);
		CHECK(t32_clm_ct(sec, lut, sizeof(lut), 4050, tab, tb) == 0 && tab[1] == 20);	/* inside the hysteresis */
		CHECK(t32_clm_ct(sec, lut, sizeof(lut), 5050, tab, tb) == 0 && tab[1] == 25 && tb[1] == 25);	/* halfway 4100..5900 */
		CHECK(t32_clm_ct(sec, lut, 100, 5000, tab, tb) == -1);
	}
	if (f) {
		static u8 bin[0x40000];
		size_t len = fread(bin, 1, sizeof(bin), f);
		u32 l = 0, off;
		int r;

		fclose(f);
		CHECK(tr_n == 0 || tr_n > 1000);
		off = t32_iq_section(bin, len, T32_SEC_GAMMA, &l);
		CHECK(off && l == T32_GAMMA_SEC_BYTES);
		r = t32_gamma_init(bin + off, bin + off + l, (u32)len - off - l, w);
		CHECK(r == (int)T32_GAMMA_MAX_WRITES);
		vs_vendor("gamma", w, r);
		off = t32_iq_section(bin, len, T32_SEC_YDNS, &l);
		CHECK(off && l == T32_YDNS_SEC_BYTES);
		r = t32_ydns_init(bin + off, w);
		CHECK(r == T32_YDNS_WRITES);
		vs_vendor("ydns", w, r);
		off = t32_iq_section(bin, len, T32_SEC_SDNS, &l);
		CHECK(off && l == T32_SDNS_SEC_BYTES);
		r = t32_sdns_init(bin + off, w);
		CHECK(r == T32_SDNS_WRITES);
		vs_vendor("sdns", w, r);
		off = t32_iq_section(bin, len, T32_SEC_CDNS, &l);
		CHECK(off && l == T32_CDNS_SEC_BYTES);
		r = t32_cdns_init(bin + off, w);
		CHECK(r == T32_CDNS_WRITES);
		vs_vendor("cdns", w, r);
		{
			static u8 cp[T32_DMSC_SEC_BYTES];

			off = t32_iq_section(bin, len, T32_SEC_DMSC, &l);
			CHECK(off && l == T32_DMSC_SEC_BYTES);
			memcpy(cp, bin + off, sizeof(cp));
			r = t32_dmsc_init(cp, w);
			CHECK(r == T32_DMSC_WRITES);
			vs_vendor("dmsc", w, r);
		}
		{
			static u8 cp[T32_YSP_SEC_BYTES];

			off = t32_iq_section(bin, len, T32_SEC_YSP, &l);
			CHECK(off && l == T32_YSP_SEC_BYTES);
			memcpy(cp, bin + off, sizeof(cp));
			r = t32_ysp_init(cp, w);
			CHECK(r == T32_YSP_WRITES);
			vs_vendor("ysp", w, r);
		}
		{
			u32 cl = 0, co = t32_iq_section(bin, len, T32_IQ_SEC_CSC, &cl);
			u32 clo = t32_iq_section(bin, len, T32_SEC_CLM, &l);
			unsigned int mode = bin[co + 0x5b];

			CHECK(co && clo && l == T32_CLM_SEC_BYTES && mode < 6);
			r = t32_clm_init(bin + clo, bin + clo + l, (u32)len - clo - l, mode, t32_csc_modes[mode].m, w);
			CHECK(r == T32_CLM_WRITES);
			vs_vendor("clm", w, r);
		}
		if (tr_n)
			printf("tx_isp_t32_tisp_test: %u of %u vendor AddSensor writes covered by this test\n",
			       covered_new, tr_n);
	} else {
		printf("  (no T32_IQ_BIN: vendor comparison skipped)\n");
	}
	printf("tx_isp_t32_tisp_test: %s\n", bad ? "FAIL" : "PASS");
	return bad != 0;
}
