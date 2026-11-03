#include <assert.h>
#include <errno.h>
#include <stdio.h>
#include "../driver/t41/tx_isp_t41_vic_bypass.h"

int main(void)
{
	uint32_t bpl = 0, size = 0, mode = 99, stride = 0;

	/* RAW16: two bytes per pixel, line padded to 32 pixels */
	assert(t41_vic_raw_layout(T41_VIC_FMT_RAW16, 2560, 1440, &bpl, &size) == 0);
	assert(bpl == 5120 && size == 5120U * 1440U);
	assert(t41_vic_raw_layout(T41_VIC_FMT_RAW16, 2880, 1620, &bpl, &size) == 0);
	assert(bpl == 5760 && size == 5760U * 1620U);
	assert(t41_vic_raw_layout(T41_VIC_FMT_RAW16, 1000, 10, &bpl, &size) == 0);
	assert(bpl == 2048 && size == 20480);
	assert(t41_vic_raw_layout(T41_VIC_FMT_RAW8, 2560, 1440, &bpl, &size) == 0);
	assert(bpl == 2560 && size == 2560U * 1440U);
	assert(t41_vic_raw_layout(T41_VIC_FMT_NV12, 2560, 1440, &bpl, &size) == -EINVAL);
	assert(t41_vic_raw_layout(2, 2560, 1440, &bpl, &size) == -EINVAL);

	/* DMA mode word and stride */
	assert(t41_vic_dma_mode(T41_VIC_FMT_NV12, 2560, &mode, &stride) == 0 &&
	       mode == 7 && stride == 2560);
	assert(t41_vic_dma_mode(T41_VIC_FMT_NV21, 2560, &mode, &stride) == 0 &&
	       mode == 6 && stride == 2560);
	assert(t41_vic_dma_mode(T41_VIC_FMT_RAW8, 2560, &mode, &stride) == 0 &&
	       mode == 1 && stride == 2560);
	assert(t41_vic_dma_mode(T41_VIC_FMT_RAW16, 2560, &mode, &stride) == 0 &&
	       mode == 0 && stride == 5120);
	assert(t41_vic_dma_mode(3, 2560, &mode, &stride) == -EINVAL);
	assert(t41_vic_dma_mode(8, 2560, &mode, &stride) == -EINVAL);
	assert(t41_vic_dma_config(0) == 0x80000020U);
	assert(t41_vic_dma_config(7) == 0x80000027U);

	/* address register map: five words per plane and stream */
	assert(t41_vic_addr_reg(0, 0, 0) == 0x318 && t41_vic_addr_reg(0, 4, 0) == 0x328);
	assert(t41_vic_addr_reg(0, 0, 1) == 0x32c && t41_vic_addr_reg(0, 4, 1) == 0x33c);
	assert(t41_vic_addr_reg(1, 0, 0) == 0x340 && t41_vic_addr_reg(1, 4, 0) == 0x350);
	assert(t41_vic_addr_reg(1, 0, 1) == 0x354 && t41_vic_addr_reg(1, 4, 1) == 0x364);
	assert(T41_VIC_NODES == 5);
	puts("tx_isp_t41_vic_bypass_test: ok");
	return 0;
}
