/* Host test: T32 front end (CSC, CSCCR, ISP top) initialisation, driver/t32/tx_isp_t32_front.h.
 * With T32_IQ_BIN (cv8001-PRJ007-day.bin) the writes are compared with the vendor's
 * (QEMU run v1, AddSensor, 3840x2160, SRGGB10). */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../driver/t32/tx_isp_t32_front.h"
#include "../driver/t32/tx_isp_t32_iq.h"

static int bad;
#define CHECK(c) do { if (!(c)) { bad++; printf("FAIL line %d: %s\n", __LINE__, #c); } } while (0)

static const struct t32_front_write csc_vendor[] = {
	{ 0xb040, 0 }, { 0xb044, 0 }, { 0xb048, 0x04ab70da }, { 0xb04c, 0x20062c75 },
	{ 0xb050, 0x02f74600 }, { 0xb054, 0x00008000 }, { 0xb058, 0xff00ff00 },
	{ 0xb010, 0xffffffff }, { 0xb000, 0x0134da11 },
};
static const struct t32_front_write csccr_vendor[] = {
	{ 0x14040, 0x400 }, { 0x14044, 0xff00 }, { 0x14050, 0x400 }, { 0x14054, 0x007f0180 },
	{ 0x14010, 0xffffffff }, { 0x14000, 0x0134da11 },
};
static const struct t32_front_write top_vendor[] = {
	{ 0x70, 0x0f000870 }, { 0x80, 0x0f000870 }, { 0x78, 0x100 }, { 0x88, 0x100 },
	{ 0x48, 0xffffffff }, { 0x48, 0xfff7ffff }, { 0x100, 4 },
	{ 0x40, 0x00704100 }, { 0x60, 0x1f }, { 0x6c, 0x12 },
};

static void compare(const char *what, const struct t32_front_write *got, unsigned int n,
		    const struct t32_front_write *want, unsigned int m)
{
	unsigned int i, diff = 0;

	CHECK(n == m);
	for (i = 0; i < n && i < m; i++)
		if (got[i].reg != want[i].reg || got[i].val != want[i].val) {
			diff++;
			printf("  %s #%u: %05x=%08x, vendor %05x=%08x\n", what, i, got[i].reg, got[i].val,
			       want[i].reg, want[i].val);
		}
	CHECK(diff == 0);
	printf("  %s: %u writes, %u differ\n", what, n, diff);
}

int main(void)
{
	const char *path = getenv("T32_IQ_BIN");
	FILE *f = path ? fopen(path, "rb") : NULL;
	struct t32_front_write w[T32_FRONT_MAX_WRITES];

	/* isp_mbus_to_bayer */
	CHECK(t32_mbus_to_bayer(0x5207) == (1 << 16 | 0));	/* SRGGB10 */
	CHECK(t32_mbus_to_bayer(0x5204) == (1 << 16 | 1));	/* SBGGR10 */
	CHECK(t32_mbus_to_bayer(0x5205) == (1 << 16 | 3));
	CHECK(t32_mbus_to_bayer(0x5206) == (1 << 16 | 2));
	CHECK(t32_mbus_to_bayer(0x5203) == 0 && t32_mbus_to_bayer(0x5200) == 1);
	CHECK(t32_mbus_to_bayer(0x520b) == (2 << 16 | 0));
	CHECK(t32_mbus_to_bayer(0x520c) == -1 && t32_mbus_to_bayer(0x51ff) == -1);
	/* round6: half up on the arithmetic shift */
	CHECK(t32_front_round6(32) == 1 && t32_front_round6(31) == 0 && t32_front_round6(-32) == 0 &&
	      t32_front_round6(-33) == -1 && t32_front_round6(64) == 1);
	/* modes not built are refused */
	{
		static u8 sec[T32_CSCCR_BYTES], csc[T32_CSC_BYTES];

		sec[4] = 3;
		CHECK(t32_csccr_init(sec, w) == -1);
		sec[4] = 1;
		CHECK(t32_csccr_init(sec, w) == 6 && w[0].val == (255 * 1024 + 109) / 219);
		csc[0x5b] = 6;
		CHECK(t32_csc_init(csc, w) == 0);
	}
	if (f) {
		static u8 bin[0x40000];
		size_t len = fread(bin, 1, sizeof(bin), f);
		u32 l = 0, off;
		unsigned int n;
		int r;

		fclose(f);
		off = t32_iq_section(bin, len, T32_IQ_SEC_CSC, &l);
		CHECK(off && l == T32_CSC_BYTES);
		n = t32_csc_init(bin + off, w);
		compare("CSC", w, n, csc_vendor, sizeof(csc_vendor) / sizeof(csc_vendor[0]));
		off = t32_iq_section(bin, len, T32_IQ_SEC_CSCCR, &l);
		CHECK(off && l == T32_CSCCR_BYTES);
		r = t32_csccr_init(bin + off, w);
		CHECK(r > 0);
		compare("CSCCR", w, r > 0 ? (unsigned int)r : 0, csccr_vendor, sizeof(csccr_vendor) / sizeof(csccr_vendor[0]));
		off = t32_iq_section(bin, len, T32_IQ_SEC_TOP, &l);
		CHECK(off && l == T32_TOP_BYTES);
		n = t32_top_init(bin + off, 3840, 2160, (u32)t32_mbus_to_bayer(0x5207), w);
		compare("TOP", w, n, top_vendor, sizeof(top_vendor) / sizeof(top_vendor[0]));
	} else {
		printf("  (no T32_IQ_BIN: vendor comparison skipped)\n");
	}
	printf("tx_isp_t32_front_test: %s\n", bad ? "FAIL" : "PASS");
	return bad != 0;
}
