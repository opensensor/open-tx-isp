/* Host test for the T20 IQ bin check before a reload (driver/t20/sdk/source/apical-isp/tx-isp-param-validate.h, #231 L6). */
#include <stdio.h>
#include <string.h>

#include "../driver/t20/sdk/source/apical-isp/tx-isp-param-validate.h"

static int failures;

#define CHECK(cond) do { \
	if (!(cond)) { \
		fprintf(stderr, "%s:%d: CHECK(%s) failed\n", __FILE__, __LINE__, #cond); \
		failures++; \
	} \
} while (0)

/* the loader's crc32 */
static const unsigned int crc_table[8] = {
	0x00000000u, 0x77073096u, 0xee0e612cu, 0x990951bau,
	0x076dc419u, 0x706af48fu, 0xe963a535u, 0x9e6495a3u,
};

static unsigned int crc(const unsigned int *p, unsigned int len)
{
	unsigned int c = 0, i;

	for (i = 0; i < len; i++) {
		c ^= p[i];
		c ^= crc_table[c & 7];
	}
	return c;
}

static unsigned int buf32[1024];
#define BUF ((char *)buf32)

static void w32(unsigned long off, unsigned int v) { memcpy(BUF + off, &v, 4); }
static void w16(unsigned long off, unsigned int v) { unsigned short s = v; memcpy(BUF + off, &s, 2); }

/* target LookupTable: ptr(4) rows cols width (2 each) + pad = 12 */
#define LT 12u
static const unsigned char used[3] = { 1, 0, 1 };

/* version | h0 | t0 day 2x2x2, night | t2 day 1x3x4, night | h1 + 8 customer bytes */
static unsigned long build(void)
{
	unsigned long off = 24, h0, h1;

	memset(buf32, 0, sizeof(buf32));
	memcpy(BUF, "VER1.0\0\0", 8);
	memcpy(BUF + 8, "header0\0", 8);
	h0 = off;
	w16(off + 4, 2); w16(off + 6, 2); w16(off + 8, 2); off += LT + 8;
	w16(off + 4, 2); w16(off + 6, 2); w16(off + 8, 2); off += LT + 8;
	w16(off + 4, 1); w16(off + 6, 3); w16(off + 8, 4); off += LT + 12;
	w16(off + 4, 1); w16(off + 6, 3); w16(off + 8, 4); off += LT + 12;
	w32(16, off - h0);
	w32(20, crc((const unsigned int *)(BUF + h0), (off - h0) / 4));
	memcpy(BUF + off, "header1\0", 8);
	h1 = off;
	w32(off + 8, 8);
	w32(off + 16, 0x11223344u); w32(off + 20, 0x55667788u);
	w32(off + 12, crc((const unsigned int *)(BUF + h1 + 16), 2));
	return h1 + 24;
}

int main(void)
{
	struct txp_validate v = {
		.version = "VER1.0", .flag0 = "header0", .flag1 = "header1",
		.used = used, .ntables = 3, .lt_size = LT, .lt_dims = 4,
		.fw_cap = 20, .crc = crc,
	};
	unsigned long n = build();

	CHECK(txp_param_validate(&v, BUF, n) == 0);
	/* wrong version, flags */
	BUF[3] = 'X'; CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	BUF[8] = 'X'; CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	BUF[n - 24] = 'X'; CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	/* CRC of header0 data / customer data */
	BUF[40] ^= 1; CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	BUF[n - 2] ^= 1; CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	/* truncated file (short read is caught before; here: size field too big) */
	CHECK(txp_param_validate(&v, BUF, n - 4) == -1);
	CHECK(txp_param_validate(&v, BUF, 20) == -1);
	/* header0 size beyond the file */
	w32(16, 0x10000); CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	/* a table larger than the rest of the file (dims 0xffff^3 must not wrap) */
	w16(24 + 4, 0xffff); w16(24 + 6, 0xffff); w16(24 + 8, 0xffff);
	CHECK(txp_param_validate(&v, BUF, n) == -1); n = build();
	/* fw table space too small for the day tables (8 + 12 = 20 bytes) */
	v.fw_cap = 19; CHECK(txp_param_validate(&v, BUF, n) == -1); v.fw_cap = 20;
	CHECK(txp_param_validate(&v, BUF, n) == 0);
	/* empty customer block: no CRC */
	w32(n - 16, 0); CHECK(txp_param_validate(&v, BUF, n) == 0);

	if (failures)
		fprintf(stderr, "%d failure(s)\n", failures);
	else
		printf("tx_isp_t20_param_validate_test: ok\n");
	return failures ? 1 : 0;
}
