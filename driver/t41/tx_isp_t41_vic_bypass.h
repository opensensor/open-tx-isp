/* SPDX-License-Identifier: GPL-2.0 */
/*
 * Pure logic of the VIC frame-channel (MDMA) capture used by the ISP bypass
 * (isp_bypass_graph=1, issue 125; host-testable).  Oracle: the stock
 * vic_frame_channel_set_fmt / streamon / qbuf / vic_mdma_irq_function of
 * tx-isp-t41.ko 1.2.5.
 *
 * Frame-channel pixel formats that the VIC can write (isp_output_fmt index):
 * 0 NV12, 1 NV21, 6 RAW8 (BGGR), 7 RAW16 (BGGR).  streamon turns the index
 * into the VIC DMA mode word (0 RAW16, 1 RAW8, 6 NV21, 7 NV12) and the line
 * stride in bytes (RAW16 is two bytes per pixel).  The DMA address registers
 * of stream 0 are 0x318 (plane 0) / 0x32c (plane 1), of stream 1 0x340 /
 * 0x354, five words each.
 */
#ifndef TX_ISP_T41_VIC_BYPASS_H
#define TX_ISP_T41_VIC_BYPASS_H

#ifdef __KERNEL__
#include <linux/errno.h>
#include <linux/types.h>
#else
#include <errno.h>
#include <stdint.h>
#endif

#define T41_VIC_FMT_NV12	0U
#define T41_VIC_FMT_NV21	1U
#define T41_VIC_FMT_RAW8	6U
#define T41_VIC_FMT_RAW16	7U
#define T41_VIC_DMA_ENABLE	0x80000020U
#define T41_VIC_NODES		5U

/* bytes per line and per frame the frame channel reports for a RAW format */
static inline int t41_vic_raw_layout(uint32_t fmt, uint32_t width, uint32_t height,
				     uint32_t *bytesperline, uint32_t *sizeimage)
{
	uint32_t depth;

	if (fmt == T41_VIC_FMT_RAW16)
		depth = 16;
	else if (fmt == T41_VIC_FMT_RAW8)
		depth = 8;
	else
		return -EINVAL;
	*bytesperline = (((width + 31U) & ~31U) * depth) >> 3;
	*sizeimage = *bytesperline * height;
	return 0;
}

/* VIC DMA mode word and line stride of a frame-channel format, or -EINVAL */
static inline int t41_vic_dma_mode(uint32_t fmt, uint32_t width, uint32_t *mode,
				   uint32_t *stride)
{
	*stride = width;
	switch (fmt) {
	case T41_VIC_FMT_NV12:
		*mode = 7;
		return 0;
	case T41_VIC_FMT_NV21:
		*mode = 6;
		return 0;
	case T41_VIC_FMT_RAW8:
		*mode = 1;
		return 0;
	case T41_VIC_FMT_RAW16:
		*mode = 0;
		*stride = width << 1;
		return 0;
	}
	return -EINVAL;
}

/* DMA configuration register value that starts the transfer */
static inline uint32_t t41_vic_dma_config(uint32_t mode)
{
	return mode | T41_VIC_DMA_ENABLE;
}

/* register offset of the address word of node idx, stream 0/1, plane 0/1 */
static inline uint32_t t41_vic_addr_reg(unsigned int stream, unsigned int idx,
					unsigned int plane)
{
	static const uint16_t base[2][2] = { { 0x318, 0x32c }, { 0x340, 0x354 } };

	return base[stream ? 1 : 0][plane ? 1 : 0] + 4U * idx;
}

#endif
