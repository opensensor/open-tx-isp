/* SPDX-License-Identifier: GPL-2.0 */
#include <assert.h>
#include <stdio.h>
#include "../driver/t31/tx_isp_t31_wdr.h"

static void test_stats(void)
{
	static struct t31_wdr_stats stats;
	static u32 packed[T31_WDR_STATS_BYTES / 4];
	static u8 slot[T31_WDR_DMA_SLOT_BYTES];
	u32 i;

	/* G's high ten bits and low eleven bits cross the packed words. */
	packed[0] = 0xffffffff;
	packed[1] = 0xffffffff;
	packed[2] = 0x00200001;
	packed[3] = 0x00000801;
	packed[0x400] = 0x00600002;
	packed[0x401] = 0x00000402;
	packed[0x404] = 0x87654321;
	packed[0x405] = 0xfffffffe;
	packed[0x406] = 0x12345678;
	packed[0x407] = 0xffffffff;
	assert(t31_wdr_unpack_stats(&stats, packed, sizeof(packed) - 1) == -EINVAL);
	assert(t31_wdr_unpack_stats(&stats, packed, sizeof(packed)) == 0);
	assert(stats.rgb[0][0][0] == 0x1fffff);
	assert(stats.rgb[0][1][0] == 0x1fffff);
	assert(stats.rgb[0][2][0] == 0x1fffff);
	assert(stats.rgb[1][0][0] == 1);
	assert(stats.rgb[1][1][0] == 2049);
	assert(stats.rgb[1][2][0] == 2);
	assert(stats.count[0][0] == 2 && stats.count[0][1] == 4099);
	assert(stats.count[0][2] == 1);
	assert(stats.point_sum[0] == 0x87654321 && stats.point_sum_high[0] == 0);
	assert(stats.point_sum[1] == 0x12345678 && stats.point_sum_high[1] == 1);
	for (i = 0; i < 8; ++i)
		memset(slot + i * 0x400, (int)i + 1, 0x204);
	assert(t31_wdr_compact_stats((u8 *)packed, sizeof(packed), slot, sizeof(slot)) == 0);
	assert(((u8 *)packed)[0] == 1 && ((u8 *)packed)[0x203] == 1);
	assert(((u8 *)packed)[0x204] == 2 && ((u8 *)packed)[0x101f] == 8);
}

static void test_ae_blocks(void)
{
    u32 params[42] = {0}, packed[24] = {0}, out[225];
    u32 i;
    params[1] = 2;
    params[3] = 3;
    params[4] = 2;
    params[5] = 4;
    params[19] = 3;
    params[20] = 6;
    params[21] = 9;
    for (i = 0; i < 6; ++i)
        packed[i * 4] = 72;
    assert(t31_wdr_ae_blocks(out, packed, sizeof(packed), params) == 0);
    assert(out[0] == 12 && out[1] == 6 && out[2] == 6);
    assert(out[3] == 3 && out[4] == 4 && out[5] == 2 && out[224] == 0);
    params[21] = 0;
    assert(t31_wdr_ae_blocks(out, packed, sizeof(packed), params) == -EINVAL);
    params[3] = 16;
    assert(t31_wdr_ae_blocks(out, packed, sizeof(packed), params) == -EINVAL);
}

static void test_blocks_and_curves(void)
{
	u32 blocks[T31_WDR_BLOCKS] = {0};
	u32 curve[T31_WDR_CURVE_POINTS];
	u32 points[7] = {2, 6, 10, 10, 17, 12, 256};
	u32 i;

	/* The last block must participate; sorting must retain earlier maxima. */
	for (i = 0; i < 7; ++i)
		blocks[i * 31] = i + 1;
	blocks[224] = 100;
	assert(t31_wdr_bright_blocks(blocks, 4) == 29);
	assert(t31_wdr_bright_blocks(blocks, 8) == 16);
	assert(t31_wdr_bright_blocks(blocks, 0) == 29);
	assert(t31_wdr_slew(40, 20, 1, 5) == 35);
	assert(t31_wdr_slew(20, 40, 1, 5) == 25);
	assert(t31_wdr_fusion_curve(curve, points) == 0);
	assert(curve[2] == 10 && curve[3] == 12 && curve[4] == 14);
	assert(curve[5] == 16 && curve[6] == 17 && curve[7] == 15);
	assert(curve[8] == 14 && curve[9] == 13 && curve[10] == 12);
	assert(curve[32] == 256);
	points[1] = points[0];
	assert(t31_wdr_fusion_curve(curve, points) == -EINVAL);
}

int main(void)
{
	test_stats();
	test_ae_blocks();
	test_blocks_and_curves();
	puts("tx_isp_t31_wdr tests passed");
	return 0;
}
