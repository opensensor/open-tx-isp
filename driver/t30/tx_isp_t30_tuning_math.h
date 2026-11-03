/*
 * T30 tuning controls: the arithmetic and the id mappings that do not need
 * the driver (host-testable, tests/t30_tuning_ctl_host_test.c).  Behaviour is
 * that of the stock tx-isp-t30 tuning handlers.
 */
#ifndef TX_ISP_T30_TUNING_MATH_H
#define TX_ISP_T30_TUNING_MATH_H

/* Firmware fps ids 6..11 (IMAGE set_sensor_fps) -> frames per second. */
static const u32 tctl_fps_by_id[6] = { 5, 15, 25, 30, 50, 60 };

/* Value around a customer mid node: 0..127 scales below, 128..255 above. */
static inline u32 tctl_mid_scale(u32 value, u32 mid)
{
	return value < 128 ? value * mid / 128 :
			     mid + (0xff - mid) * (value - 128) / 128;
}

/*
 * Contrast: the customer parameter file carries up to 10 (gain, mid node)
 * pairs.  gain is in 1/32 octave units of the 27.5 total gain; the mid node
 * is interpolated between the two curve points around the current gain.
 * curves[0][0] == 0xff marks the curve unused (value passes unchanged).
 */
static inline u32 tctl_contrast_value(u32 value, const u8 curves[][2],
				      u32 total_gain)
{
	int i, x1, x2;

	if (curves[0][0] == 0xff)
		return value;
	for (i = 0; i < 10; i++)
		if (curves[i][0] == 0xff ||
		    ((u32)curves[i][0] << 5) >= total_gain)
			break;
	if (i == 10 || curves[i][0] == 0xff) {
		x1 = x2 = i - 1;
	} else {
		x2 = i;
		x1 = x2 - 1 < 0 ? 0 : x2 - 1;
	}
	if (x1 == x2)
		return tctl_mid_scale(value, curves[x1][1]);
	{
		u32 v1 = tctl_mid_scale(value, curves[x1][1]);
		u32 v2 = tctl_mid_scale(value, curves[x2][1]);
		int gx1 = (int)curves[x1][0] << 5;
		int gx2 = (int)curves[x2][0] << 5;

		return ((total_gain - gx1) * v2 + (gx2 - total_gain) * v1) /
		       (gx2 - gx1);
	}
}

/* AWB mode: ISP_CORE_WB_MODE_* (0..8) <-> firmware AWB_* (0x32..0x3a). */
static inline int tctl_wb_mode_to_apical(u32 mode)
{
	return mode <= 8 ? (int)(0x32 + mode) : -1;
}

static inline int tctl_wb_mode_from_apical(u32 mode)
{
	return (mode >= 0x32 && mode <= 0x3a) ? (int)(mode - 0x32) : -1;
}

/* AE strategy: user 0 balanced, 1 integration priority <-> firmware 0x29/0x2a. */
static inline u32 tctl_ae_strategy_to_apical(int32_t user)
{
	return user ? 0x2a : 0x29;
}

static inline u32 tctl_ae_strategy_from_apical(u32 fw)
{
	return fw == 0x29 ? 0 : fw == 0x2a ? 1 : 2;
}

/* V4L2_COLORFX_{NONE,BW,SEPIA,NEGATIVE,VIVID} -> firmware color mode; -1 else. */
static inline int tctl_colorfx_to_apical(u32 v4l2)
{
	switch (v4l2) {
	case 0: return 0x4f;	/* NORMAL */
	case 1: return 0x50;	/* BLACK_AND_WHITE */
	case 2: return 0x52;	/* SEPIA */
	case 3: return 0x51;	/* NEGATIVE */
	case 9: return 0x53;	/* VIVID */
	}
	return -22;		/* -EINVAL, as the stock mapper */
}

/* Expression time: microseconds -> sensor lines (0 when the line time is unknown). */
static inline int tctl_expr_us_to_lines(u32 us, u32 one_line_us, u32 *lines)
{
	if (!one_line_us)
		return -1;
	*lines = us / one_line_us;
	return 0;
}

#endif /* TX_ISP_T30_TUNING_MATH_H */
