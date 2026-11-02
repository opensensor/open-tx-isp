/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T30 frame channel format ioctls, 0x5c-byte form (Lu-Fi/openimp#178).
 *
 * The vendor libimp of the T30 sends the format as 0xc05c56c3 (set) and
 * 0x405c56c4 (get): a type word, the 48-byte v4l2_pix_format of a 4.x kernel
 * (width .. priv plus flags, ycbcr_enc, quantization, xfer_func), then
 * crop, scaler and rate words.  The kernel 3.10 driver works on the 0x4c-byte
 * form (32-byte pix, no extra words).  The two forms differ only by the four
 * extra pix words, so the 0x5c form is converted to the 0x4c form on entry and
 * back on exit; the extra words are never interpreted by the hardware layer.
 */
#ifndef TX_ISP_T30_FMT5C_H
#define TX_ISP_T30_FMT5C_H

#define TX_ISP_T30_FRAME_IOCTL_SET_FORMAT_5C 0xc05c56c3U
#define TX_ISP_T30_FRAME_IOCTL_GET_FORMAT_5C 0x405c56c4U

/* 0x5c-byte wire form (all words 32 bit) */
struct tx_isp_t30_fmt5c {
	u32 type;
	u32 width, height, pixelformat, field, bytesperline, sizeimage;
	u32 colorspace, priv;
	u32 flags, ycbcr_enc, quantization, xfer_func;	/* 4.x pix words */
	u32 crop_enable, crop_top, crop_left, crop_width, crop_height;
	u32 scaler_enable, scaler_out_width, scaler_out_height;
	u32 rate_bits, rate_mask;
};

/* 0x4c-byte wire form (the layout of struct tx_isp_t30_frame_image_format) */
struct tx_isp_t30_fmt4c {
	u32 type;
	u32 width, height, pixelformat, field, bytesperline, sizeimage;
	u32 colorspace, priv;
	u32 crop_enable, crop_top, crop_left, crop_width, crop_height;
	u32 scaler_enable, scaler_out_width, scaler_out_height;
	u32 rate_bits, rate_mask;
};

#define TX_ISP_T30_FMT5C_SIZE 0x5cU
#define TX_ISP_T30_FMT4C_SIZE 0x4cU

static inline void tx_isp_t30_fmt5c_to_4c(const struct tx_isp_t30_fmt5c *w,
					  struct tx_isp_t30_fmt4c *o)
{
	o->type = w->type;
	o->width = w->width;
	o->height = w->height;
	o->pixelformat = w->pixelformat;
	o->field = w->field;
	o->bytesperline = w->bytesperline;
	o->sizeimage = w->sizeimage;
	o->colorspace = w->colorspace;
	o->priv = w->priv;
	o->crop_enable = w->crop_enable;
	o->crop_top = w->crop_top;
	o->crop_left = w->crop_left;
	o->crop_width = w->crop_width;
	o->crop_height = w->crop_height;
	o->scaler_enable = w->scaler_enable;
	o->scaler_out_width = w->scaler_out_width;
	o->scaler_out_height = w->scaler_out_height;
	o->rate_bits = w->rate_bits;
	o->rate_mask = w->rate_mask;
}

/* Result of the driver back into the user's 0x5c object; the four extra pix
 * words stay as the caller sent them. */
static inline void tx_isp_t30_fmt4c_to_5c(const struct tx_isp_t30_fmt4c *o,
					  struct tx_isp_t30_fmt5c *w)
{
	w->type = o->type;
	w->width = o->width;
	w->height = o->height;
	w->pixelformat = o->pixelformat;
	w->field = o->field;
	w->bytesperline = o->bytesperline;
	w->sizeimage = o->sizeimage;
	w->colorspace = o->colorspace;
	w->priv = o->priv;
	w->crop_enable = o->crop_enable;
	w->crop_top = o->crop_top;
	w->crop_left = o->crop_left;
	w->crop_width = o->crop_width;
	w->crop_height = o->crop_height;
	w->scaler_enable = o->scaler_enable;
	w->scaler_out_width = o->scaler_out_width;
	w->scaler_out_height = o->scaler_out_height;
	w->rate_bits = o->rate_bits;
	w->rate_mask = o->rate_mask;
}

#endif
