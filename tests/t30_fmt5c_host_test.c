/* Host test: T30 frame-format ioctl, 0x5c-byte form of the vendor libimp
 * (tx_isp_t30_fmt5c.h, Lu-Fi/openimp#178).  Every word of the 0x5c object
 * gets a distinct value; the conversion to the 0x4c object of the driver and
 * back must carry each field, drop nothing but the four extra pix words and
 * leave those untouched on the way back. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef uint32_t u32;
#ifndef FMT5C_HDR
#define FMT5C_HDR "../driver/t30/tx_isp_t30_fmt5c.h"
#endif
#include FMT5C_HDR

#define CK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); bad++; } } while (0)

int main(void)
{
	struct tx_isp_t30_fmt5c w, back;
	struct tx_isp_t30_fmt4c n;
	uint32_t *pw = (uint32_t *)&w, *pb = (uint32_t *)&back, *pn = (uint32_t *)&n;
	int i, bad = 0;

	CK(sizeof(w) == 0x5c);
	CK(sizeof(n) == 0x4c);
	CK(TX_ISP_T30_FRAME_IOCTL_SET_FORMAT_5C == 0xc05c56c3U);
	CK(TX_ISP_T30_FRAME_IOCTL_GET_FORMAT_5C == 0x405c56c4U);
	CK(offsetof(struct tx_isp_t30_fmt5c, flags) == 0x24);
	CK(offsetof(struct tx_isp_t30_fmt5c, crop_enable) == 0x34);
	CK(offsetof(struct tx_isp_t30_fmt5c, scaler_enable) == 0x48);
	CK(offsetof(struct tx_isp_t30_fmt5c, rate_mask) == 0x58);
	CK(offsetof(struct tx_isp_t30_fmt4c, crop_enable) == 0x24);
	CK(offsetof(struct tx_isp_t30_fmt4c, rate_mask) == 0x48);

	for (i = 0; i < 23; i++)
		pw[i] = 0x1000 + i;
	memset(&n, 0xee, sizeof(n));
	tx_isp_t30_fmt5c_to_4c(&w, &n);
	/* words 0..8 (type, pix header) keep their place, 9..12 are dropped,
	 * 13..22 move down by four words */
	for (i = 0; i < 9; i++)
		CK(pn[i] == 0x1000u + i);
	for (i = 9; i < 19; i++)
		CK(pn[i] == 0x1000u + i + 4);

	/* the driver changes some answer fields; the extra words stay */
	n.sizeimage = 0x2fd000;
	n.bytesperline = 1920;
	n.width = 1920;
	memset(&back, 0, sizeof(back));
	for (i = 9; i < 13; i++)
		pb[i] = 0x7700u + i;
	tx_isp_t30_fmt4c_to_5c(&n, &back);
	CK(back.sizeimage == 0x2fd000 && back.bytesperline == 1920 && back.width == 1920);
	for (i = 0; i < 9; i++)
		if (i != 1 && i != 5 && i != 6)
			CK(pb[i] == 0x1000u + i);
	for (i = 9; i < 13; i++)
		CK(pb[i] == 0x7700u + i);
	for (i = 13; i < 23; i++)
		CK(pb[i] == 0x1000u + i);

	if (!bad)
		puts("t30_fmt5c_host_test: ok");
	return bad != 0;
}
