/* Host test: T30 tuning controls (driver/t30/tx_isp_t30_tuning_math.h,
 * Lu-Fi/openimp#177).  The arithmetic and id mappings of the controls the
 * lifted switch had lost: fps ids, mid-node scaling, contrast curve, AWB mode,
 * AE strategy, colour effect, exposure us -> lines. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint32_t u32;
typedef uint8_t u8;
#ifndef TUNING_MATH_HDR
#define TUNING_MATH_HDR "../driver/t30/tx_isp_t30_tuning_math.h"
#endif
#include TUNING_MATH_HDR

#define CK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); bad++; } } while (0)

int main(void)
{
	/* firmware fps ids 6..11 and the get-side inverse (5->6 15->7 25->8 30->9 50->10 60->11) */
	static const u32 inv_fps[6] = { 5, 15, 25, 30, 50, 60 };
	u8 unused[10][2], one[10][2], two[10][2];
	u32 i, lines = 99;
	int bad = 0;

	for (i = 0; i < 6; i++)
		CK(tctl_fps_by_id[i] == inv_fps[i]);

	/* below 128 the mid node 128 is the identity; above it the integer slope
	 * (255 - mid) / 128 applies; 0 stays 0, 128 hits the mid node */
	for (i = 0; i < 128; i++)
		CK(tctl_mid_scale(i, 128) == i);
	for (i = 128; i < 256; i++)
		CK(tctl_mid_scale(i, 128) == 128 + 127 * (i - 128) / 128);
	CK(tctl_mid_scale(255, 128) == 128 + 127 * 127 / 128);
	CK(tctl_mid_scale(0, 90) == 0);
	CK(tctl_mid_scale(255, 90) == 90 + 165 * 127 / 128);
	CK(tctl_mid_scale(128, 90) == 90);
	CK(tctl_mid_scale(64, 100) == 50);
	CK(tctl_mid_scale(192, 100) == 100 + (255 - 100) * 64 / 128);

	/* contrast: unused curve (first x 0xff) passes the value */
	memset(unused, 0xff, sizeof(unused));
	CK(tctl_contrast_value(77, unused, 4000) == 77);
	/* one point at x=2 (gain 64): below it the single node is used (x1 == x2 path
	 * needs a terminator right after) */
	memset(one, 0xff, sizeof(one));
	one[0][0] = 2; one[0][1] = 100;
	CK(tctl_contrast_value(64, one, 1000) == tctl_mid_scale(64, 100));	/* 1000 <= 64? no: gain above, past the end */
	CK(tctl_contrast_value(64, one, 10) == tctl_mid_scale(64, 100));	/* gain below the first point */
	/* two points: x=2 -> mid 100, x=6 -> mid 160; gain 128 is halfway between 64 and 192 */
	memset(two, 0xff, sizeof(two));
	two[0][0] = 2; two[0][1] = 100;
	two[1][0] = 6; two[1][1] = 160;
	CK(tctl_contrast_value(200, two, 128) ==
	   ((128 - 64) * tctl_mid_scale(200, 160) + (192 - 128) * tctl_mid_scale(200, 100)) / (192 - 64));
	CK(tctl_contrast_value(200, two, 192) == tctl_mid_scale(200, 160));
	CK(tctl_contrast_value(200, two, 5000) == tctl_mid_scale(200, 160));	/* past the last point */

	/* AWB modes */
	for (i = 0; i < 9; i++) {
		CK(tctl_wb_mode_to_apical(i) == (int)(0x32 + i));
		CK(tctl_wb_mode_from_apical(0x32 + i) == (int)i);
	}
	CK(tctl_wb_mode_to_apical(9) == -1);
	CK(tctl_wb_mode_from_apical(0x31) == -1);
	CK(tctl_wb_mode_from_apical(0x3b) == -1);

	/* AE strategy: 0 -> balanced 0x29, anything else -> integration priority 0x2a */
	CK(tctl_ae_strategy_to_apical(0) == 0x29);
	CK(tctl_ae_strategy_to_apical(1) == 0x2a);
	CK(tctl_ae_strategy_to_apical(-1) == 0x2a);
	CK(tctl_ae_strategy_from_apical(0x29) == 0);
	CK(tctl_ae_strategy_from_apical(0x2a) == 1);
	CK(tctl_ae_strategy_from_apical(0x30) == 2);

	/* colour effect */
	CK(tctl_colorfx_to_apical(0) == 0x4f);
	CK(tctl_colorfx_to_apical(1) == 0x50);
	CK(tctl_colorfx_to_apical(2) == 0x52);
	CK(tctl_colorfx_to_apical(3) == 0x51);
	CK(tctl_colorfx_to_apical(9) == 0x53);
	CK(tctl_colorfx_to_apical(4) == -22);

	/* exposure us -> lines */
	CK(tctl_expr_us_to_lines(1000, 33, &lines) == 0 && lines == 30);
	CK(tctl_expr_us_to_lines(1000, 0, &lines) == -1);

	if (bad)
		return 1;
	printf("t30_tuning_ctl_host_test: ok\n");
	return 0;
}
