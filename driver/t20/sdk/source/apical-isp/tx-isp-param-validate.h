/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T20 sensor IQ bin check before a (re)load replaces the tables in use
 * (Lu-Fi/openimp#231 L6).  Plain C, no kernel headers: host-tested by
 * tests/tx_isp_t20_param_validate_test.c.
 *
 * Layout (tx-isp-load-parameters.c): version[8] | header0 {flag[8], size,
 * crc} | per used calibration: LookupTable + day data, LookupTable + night
 * data of the same size | header1 {flag[8], size, crc} [| customer data].
 * crc is the loader's crc32 over size / 4 words after the header.
 * lt_size / lt_dims: sizeof(LookupTable) and offsetof(rows) of the target.
 */
#ifndef TX_ISP_PARAM_VALIDATE_H
#define TX_ISP_PARAM_VALIDATE_H

struct txp_validate {
	const char *version;		/* 8 bytes */
	const char *flag0, *flag1;	/* 8 bytes each */
	const unsigned char *used;	/* calibration index used (has a default table) */
	int ntables;
	unsigned long lt_size, lt_dims;
	unsigned long fw_cap;		/* bytes of fw table space for the day tables */
	unsigned int (*crc)(const unsigned int *p, unsigned int words);
};

static inline unsigned int txp_rd32(const char *p)
{
	const unsigned char *b = (const unsigned char *)p;

	return b[0] | b[1] << 8 | b[2] << 16 | (unsigned int)b[3] << 24;
}

static inline unsigned int txp_rd16(const char *p)
{
	const unsigned char *b = (const unsigned char *)p;

	return b[0] | b[1] << 8;
}

static inline int txp_strneq(const char *a, const char *b, unsigned long n)
{
	unsigned long i;

	for (i = 0; i < n; i++) {
		if (a[i] != b[i])
			return 0;
		if (!a[i])
			break;
	}
	return 1;
}

/* 0 = the bin can replace the tables in use; -1 = reject, nothing touched */
static inline int txp_param_validate(const struct txp_validate *v, const char *buf,
				     unsigned long end)
{
	unsigned long off, size, fw = 0, half;
	unsigned int hsize;
	int i;

	if (end < 8 + 16 || !txp_strneq(v->version, buf, 8))
		return -1;
	off = 8;
	if (!txp_strneq(v->flag0, buf + off, 8))
		return -1;
	hsize = txp_rd32(buf + off + 8);
	if (hsize > end - off - 16 ||
	    txp_rd32(buf + off + 12) != v->crc((const unsigned int *)(buf + off + 16), hsize / 4))
		return -1;
	off += 16;
	for (i = 0; i < v->ntables; i++) {
		if (!v->used[i])
			continue;
		half = (end - off) / 2;
		if (half < v->lt_size)
			return -1;
		size = (unsigned long)txp_rd16(buf + off + v->lt_dims) *
		       txp_rd16(buf + off + v->lt_dims + 2) *
		       txp_rd16(buf + off + v->lt_dims + 4);
		if (size > half - v->lt_size)
			return -1;
		off += 2 * (size + v->lt_size);
		fw += size;
	}
	if (fw > v->fw_cap || end - off < 16 || !txp_strneq(v->flag1, buf + off, 8))
		return -1;
	hsize = txp_rd32(buf + off + 8);
	if (hsize) {
		if (hsize > end - off - 16 ||
		    txp_rd32(buf + off + 12) != v->crc((const unsigned int *)(buf + off + 16), hsize / 4))
			return -1;
	}
	return 0;
}

#endif
