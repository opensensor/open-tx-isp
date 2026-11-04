/*
 * T30 ISP tuning controls (get/set) served through /dev/isp-m0-tuning.
 *
 * The lifted apical_isp_core_ops_g_ctrl()/s_ctrl() lost most of their switch
 * arms (inline jump-table cases came out as -ENOSYS or the default branch), so
 * the libimp getters and several controls never reached the firmware state.
 * This file holds clean C for the missing arms.  Each handler does what the
 * stock tx-isp-t30 tuning code does for the same control id: a firmware
 * command through apical_command(), a cached value in the tuning object, an
 * ISP register block, or nothing at all where the stock driver is a no-op.
 *
 * It is included into tx_isp_t30_recovered.c (it uses the file-local views of
 * the core device, the system table and the calibration manager).  Handlers
 * return TCTL_UNHANDLED for ids they do not serve; the caller then falls back
 * to the lifted switch.
 */
#ifndef TX_ISP_T30_TUNING_CTL_H
#define TX_ISP_T30_TUNING_CTL_H

#include "tx_isp_t30_tuning_math.h"
#include "../common/tx_isp_csc.h"

#define TCTL_UNHANDLED 0x7fff0001

/* Tuning object (image_tuning_vdrv_t) field offsets, layout-checked against
 * the stock structure (ctrls start at 4, whole object 0x40d8 bytes). */
#define TCTL_OFF_WB_MODE	0x0004
#define TCTL_OFF_VFLIP		0x0eac
#define TCTL_OFF_HFLIP		0x0eb0
#define TCTL_OFF_FREEZE		0x0f00
#define TCTL_OFF_FLICKER	0x0f04
#define TCTL_OFF_WDR		0x0ee4
#define TCTL_OFF_SHARPNESS	0x3f74
#define TCTL_OFF_CONTRAST	0x4094
#define TCTL_OFF_SATURATION	0x4098
#define TCTL_OFF_BRIGHTNESS	0x409c
#define TCTL_OFF_SCENE		0x40a0
#define TCTL_OFF_COLORFX	0x40a4
#define TCTL_OFF_FPS		0x40a8
#define TCTL_OFF_DAYNIGHT	0x40ac
#define TCTL_OFF_ANTIFOG	0x4090
#define TCTL_OFF_DRC_MODE	0x0ed4
#define TCTL_OFF_DRC_ATTR	0x0ed8	/* 12 bytes: mode, strength, slope max/min, black, white */

#define TCTL_U32(t, off)	(*(u32 *)((u8 *)(t) + (off)))

/* apical_command() types and ids */
#define TCTL_T_SYSTEM		1
#define TCTL_T_IMAGE		2
#define TCTL_T_ALGO		3
#define TCTL_T_SCENE		4
#define TCTL_T_CALIB		6
#define TCTL_DIR_SET		0
#define TCTL_DIR_GET		1

#define TCTL_SYS_MANUAL_INT_TIME	0x0f
#define TCTL_SYS_INT_TIME		0x22
#define TCTL_SYS_MANUAL_EXP_TIME	0x1d
#define TCTL_SYS_SENSOR_AGAIN		0x24
#define TCTL_SYS_MAX_SENSOR_AGAIN	0x25
#define TCTL_SYS_ISP_DGAIN		0x28
#define TCTL_SYS_MAX_ISP_DGAIN		0x29
#define TCTL_SYS_AWB_RED_GAIN		0x39
#define TCTL_SYS_AWB_BLUE_GAIN		0x3a
#define TCTL_IMG_SENSOR_FPS_MODE	0x40
#define TCTL_FPS25			0x08
#define TCTL_AE_SPLIT_PRESET		0x57
#define TCTL_AE_GAIN			0x58
#define TCTL_AE_EXPOSURE		0x59
#define TCTL_AE_ROI			0x5a
#define TCTL_AE_COMPENSATION		0x5b
#define TCTL_AWB_MODE			0x60
#define TCTL_SCENE_SATURATION		0x79
#define TCTL_SCENE_BRIGHTNESS		0x77
#define TCTL_SCENE_CONTRAST		0x78
#define TCTL_SCENE_SHARPENING		0x76
#define TCTL_SCENE_COLOR_MODE		0x72
#define TCTL_CAL_EXPOSURE_LOG2		0x80
#define TCTL_CAL_GAIN_LOG2		0x81

#define TCTL_CAL_AE_BALANCED_LINEAR	0x88	/* calibration id */
#define TCTL_TBL_AE_BALANCED_LINEAR	0x92	/* index into the table array */
#define TCTL_CAL_LIGHT_SRC		0x00
#define TCTL_TBL_LIGHT_SRC		0xef
#define TCTL_CAL_TEMPER_STRENGTH	0x84
#define TCTL_TBL_TEMPER_STRENGTH	0xcd
#define TCTL_CAL_SINTER_STRENGTH_LIN	0x6d
#define TCTL_TBL_SINTER_STRENGTH_LIN	0x2e
#define TCTL_CAL_DP_SLOPE_LINEAR	0x53
#define TCTL_TBL_DP_SLOPE_LINEAR	0x88

/* user ABI blocks (sizes checked below) */
struct tctl_wb_attr { u32 mode; u16 rgain; u16 bgain; };
struct tctl_rgb_coefft { u16 r, g, b; };
struct tctl_ev_attr { u32 ev, expr_us, ev_log2, again, dgain, gain_log2; };
struct tctl_weight { u8 weight[15][15]; };
struct tctl_ae_sta {
	u8 histhresh[4];
	u16 hist[5];
	u8 nodeh, nodev;
};
struct tctl_awb_sta {
	u16 r_gain, b_gain;
	u32 awb_sum;
	u32 stats_mode;
	u16 whitelevel, blacklevel;
	u16 cr_ref_max, cr_ref_min, cb_ref_max, cb_ref_min;
	u8 nodeh, nodev;
};
struct tctl_af_sta {
	u16 metrics, metrics_alt, thresh_read, intensity_read, intensity_zone;
	u32 total_pixels, counted_pixels;
	u8 metrics_shift;
	u16 thresh, thresh_alt;
	u8 nodeh, nodev, np_offset, intensity_mode;
	u8 skipx, offsetx, skipy, offsety, scale_top, scale_bottom;
};
struct tctl_expr_get { u32 mode; u16 it, it_min, it_max, one_line_us; };
struct tctl_expr_set { u32 mode; u32 unit; u16 time; };
struct tctl_table_info {
	u32 id, rows, cols, width, tsource;
	void *ptr;
};
struct tctl_gamma { u16 gamma[129]; };

static inline void tctl_check_abi(void)
{
	BUILD_BUG_ON(V4L2_COLORFX_NONE != 0 || V4L2_COLORFX_BW != 1 ||
		     V4L2_COLORFX_SEPIA != 2 || V4L2_COLORFX_NEGATIVE != 3 ||
		     V4L2_COLORFX_VIVID != 9);
	BUILD_BUG_ON(sizeof(struct tctl_wb_attr) != 8);
	BUILD_BUG_ON(sizeof(struct tctl_rgb_coefft) != 6);
	BUILD_BUG_ON(sizeof(struct tctl_ev_attr) != 0x18);
	BUILD_BUG_ON(sizeof(struct tctl_weight) != 0xe1);
	BUILD_BUG_ON(sizeof(struct tctl_ae_sta) != 0x10);
	BUILD_BUG_ON(sizeof(struct tctl_awb_sta) != 0x1c);
	BUILD_BUG_ON(sizeof(struct tctl_af_sta) != 0x24);
	BUILD_BUG_ON(sizeof(struct tctl_expr_get) != 0xc);
	BUILD_BUG_ON(sizeof(struct tctl_expr_set) != 0xc);
	BUILD_BUG_ON(sizeof(struct tctl_table_info) != 0x18);
	BUILD_BUG_ON(sizeof(struct tctl_gamma) != 0x102);
	BUILD_BUG_ON(offsetof(struct tx_isp_t30_core_tuning_view, param) != 0x19c);
	BUILD_BUG_ON(offsetof(struct tx_isp_t30_core_video_view, hflip_state) != 0x174);
	BUILD_BUG_ON(offsetof(struct tx_isp_t30_core_video_view, daynight_switch) != 0x17c);
}

static int tctl_cmd(u32 type, u32 id, u32 value, u32 dir, u32 *reason)
{
	u32 r = 0;
	int ret = apical_command(type, id, value, dir, &r);

	if (reason)
		*reason = r;
	return ret;
}

static void __user *tctl_uptr(int32_t value)
{
	return (void __user *)(uintptr_t)(u32)value;
}

/* Read-modify-write of a bit field in one ISP register. */
static void tctl_reg_field(u32 reg, u32 shift, u32 mask, u32 data)
{
	u32 cur = APICAL_READ_32(reg);

	APICAL_WRITE_32(reg, ((data & mask) << shift) | (cur & ~(mask << shift)));
}

static u32 tctl_reg_get(u32 reg, u32 shift, u32 mask)
{
	return (APICAL_READ_32(reg) >> shift) & mask;
}

/* 15x15 zone weights live byte-packed at a block base (stock accessors). */
static u8 tctl_zone_read(u32 base, u32 row, u32 col)
{
	u32 addr = base + row * 15 + col;

	return (u8)(APICAL_READ_32(addr & ~3U) >> ((addr & 3) << 3));
}

static void tctl_zone_write(u32 base, u32 row, u32 col, u8 data)
{
	u32 addr = base + row * 15 + col;
	u32 shift = (addr & 3) << 3;
	u32 cur = APICAL_READ_32(addr & ~3U);

	APICAL_WRITE_32(addr & ~3U,
			((u32)data << shift) | (cur & ~(0xffU << shift)));
}

#define TCTL_AEXP_WEIGHT	0x1e00
#define TCTL_AWB_WEIGHT		0x1f00

static int tctl_weight_get(u32 base, int32_t value)
{
	struct tctl_weight w;
	u32 row, col;

	for (row = 0; row < 15; row++)
		for (col = 0; col < 15; col++)
			w.weight[row][col] = tctl_zone_read(base, row, col);
	return copy_to_user(tctl_uptr(value), &w, sizeof(w)) ? -EFAULT : 0;
}

static int tctl_weight_set(u32 base, int32_t value)
{
	struct tctl_weight w;
	u32 row, col;

	if (copy_from_user(&w, tctl_uptr(value), sizeof(w)))
		return -EFAULT;
	for (row = 0; row < 15; row++)
		for (col = 0; col < 15; col++)
			tctl_zone_write(base, row, col, w.weight[row][col]);
	return 0;
}

static struct tx_isp_t30_param_manager *tctl_param(void *core)
{
	return ((struct tx_isp_t30_core_tuning_view *)core)->param;
}

/* first byte of calibration table idx of the day (0) / night (1) set */
static u8 tctl_lut_byte(void *core, u32 daynight, u32 idx)
{
	struct tx_isp_t30_param_manager *param = tctl_param(core);
	struct tx_isp_t30_lookup_table *t = param->isp_param[daynight ? 1 : 0].table[idx];

	return t && t->ptr ? *(u8 *)t->ptr : 0;
}

/* customer parameter block of day (0) or night (1) mode, 0xd0 bytes each */
static u8 *tctl_customer(void *core, u32 daynight)
{
	struct tx_isp_t30_param_manager *param = tctl_param(core);

	if (!param || !param->customer)
		return NULL;
	return (u8 *)param->customer + (daynight ? 1 : 0) * 0xd0;
}
#define TCTL_CU_SHARPNESS	0xb8
#define TCTL_CU_SATURATION	0xb9
#define TCTL_CU_BRIGHTNESS	0xba
#define TCTL_CU_CONTRAST	0xbb	/* unsigned char [10][2] */

/* sharpness/saturation/brightness: value around the customer mid node */
static int tctl_scene_level(void *tuning, void *core, u32 off, u32 cu_off,
			    u32 apical_id, int32_t in, bool yuv_skips)
{
	struct tx_isp_t30_core_video_view *vcore = core;
	u32 value, mid = 128;
	u8 *cu;

	if (yuv_skips && vcore->vin.mbus.code == V4L2_MBUS_FMT_YUYV8_1X16)
		return 0;
	TCTL_U32(tuning, off) = yuv_skips ? (u32)in & 0xff : (u32)in;
	value = TCTL_U32(tuning, off);
	cu = tctl_customer(core, TCTL_U32(tuning, TCTL_OFF_DAYNIGHT));
	if (cu) {
		mid = cu[cu_off];
		value = tctl_mid_scale(value, mid);
	}
	tctl_cmd(TCTL_T_SCENE, apical_id, value, TCTL_DIR_SET, NULL);
	return 0;
}

static int tctl_contrast_set(void *tuning, void *core, int32_t in)
{
	struct tx_isp_t30_core_video_view *vcore = core;
	const struct tx_isp_t30_system_gain_view *g = (void *)stab;
	u8 *cu;
	u32 value;

	if (vcore->vin.mbus.code == V4L2_MBUS_FMT_YUYV8_1X16)
		return 0;
	TCTL_U32(tuning, TCTL_OFF_CONTRAST) = (u32)in & 0xff;
	value = TCTL_U32(tuning, TCTL_OFF_CONTRAST);
	cu = tctl_customer(core, TCTL_U32(tuning, TCTL_OFF_DAYNIGHT));
	if (cu)
		/* gain is 27.5 fixed point; curve x values are in 1/32 octaves */
		value = tctl_contrast_value(value,
					    (const u8 (*)[2])(cu + TCTL_CU_CONTRAST),
					    math_exp2(g->sensor_analog_gain +
						      g->sensor_digital_gain +
						      g->isp_digital_gain, 5, 5));
	tctl_cmd(TCTL_T_SCENE, TCTL_SCENE_CONTRAST, value, TCTL_DIR_SET, NULL);
	return 0;
}

/* sensor events go through the core's sensor ops, as the stock driver does */
static int tctl_sensor_event(void *tuning, u32 event, void *data)
{
	void *sd = *(void **)tuning;	/* tuning->parent */

	return ispcore_sensor_ops_ioctl(sd, event, data);
}

static int tctl_vflip_set(void *tuning, void *core, u32 v)
{
	struct tx_isp_t30_core_video_view *vcore = core;
	int state;

	TCTL_U32(tuning, TCTL_OFF_VFLIP) = v;
	if (vcore->vflip_state != v) {
		vcore->vflip_state = v;
		vcore->vflip_change = 1;
	}
	state = vcore->vflip_state;
	return tctl_sensor_event(tuning, 0x0200000e, &state);
}

static int tctl_hflip_set(void *tuning, void *core, u32 v)
{
	struct tx_isp_t30_core_video_view *vcore = core;

	TCTL_U32(tuning, TCTL_OFF_HFLIP) = v;
	if (vcore->hflip_state != v) {
		vcore->hflip_state = v;
		vcore->hflip_change = 1;
	}
	return 0;
}

/* A calibration table of the current day/night set: rows*cols*width bytes. */
static struct tx_isp_t30_lookup_table *tctl_table(void *tuning, void *core,
						  u32 index)
{
	struct tx_isp_t30_param_manager *param = tctl_param(core);
	u32 dn = TCTL_U32(tuning, TCTL_OFF_DAYNIGHT);

	if (!param || dn > 1 || index >= TX_ISP_T30_CALIBRATION_COUNT)
		return NULL;
	return param->isp_param[dn].table[index];
}

/* Highlight depression = third element of the balanced AE calibration. */
static int tctl_hilight(void *tuning, void *core, struct v4l2_control *c,
			bool set)
{
	struct tx_isp_t30_lookup_table *t;
	u32 size, ret = 0;
	void *data;
	int err = 0;

	if (TCTL_U32(tuning, TCTL_OFF_WDR) == 1) {
		pr_err("err: wdr enabled\n");
		return -1;
	}
	t = tctl_table(tuning, core, TCTL_TBL_AE_BALANCED_LINEAR);
	if (!t || !t->ptr) {
		pr_err("err: param == NULL\n");
		return -1;
	}
	size = t->rows * t->cols * t->width;
	if (size < 3 * t->width ||
	    (t->width != 1 && t->width != 2 && t->width != 4)) {
		pr_err("err: %s(%d),format error !\n", __func__, __LINE__);
		return -1;
	}
	data = kzalloc(size, GFP_KERNEL);
	if (!data)
		return -1;
	if (set) {
		memcpy(data, t->ptr, size);
		if (t->width == 1)
			((u8 *)data)[2] = c->value;
		else if (t->width == 2)
			((u16 *)data)[2] = c->value;
		else
			((u32 *)data)[2] = c->value;
		apical_api_calibration(TCTL_CAL_AE_BALANCED_LINEAR, 0,
				       (uintptr_t)data, size, (uintptr_t)&ret);
		if (ret) {
			pr_err("err: %s,%d, ret = %u\n", __func__, __LINE__,
			       ret);
			err = -1;
		}
	} else {
		apical_api_calibration(TCTL_CAL_AE_BALANCED_LINEAR, 1,
				       (uintptr_t)data, size, (uintptr_t)&ret);
		if (ret)
			pr_err("err: %s,%d, ret = %u\n", __func__, __LINE__,
			       ret);
		if (t->width == 1)
			c->value = ((u8 *)data)[2];
		else if (t->width == 2)
			c->value = ((u16 *)data)[2];
		else
			c->value = ((u32 *)data)[2];
	}
	kfree(data);
	return err;
}

/* IMAGE_TUNING_CID_ISP_TABLE_ATTR get: size of a table and optionally its data */
static int tctl_table_get(void *tuning, void *core, int32_t value)
{
	struct tctl_table_info info;
	struct tx_isp_t30_lookup_table *t;
	u32 index, size;

	if (!tctl_param(core))
		return -1;
	if (copy_from_user(&info, tctl_uptr(value), sizeof(info)))
		return -EFAULT;
	switch (info.id) {
	case TCTL_CAL_TEMPER_STRENGTH:
		index = TCTL_TBL_TEMPER_STRENGTH;
		break;
	case TCTL_CAL_SINTER_STRENGTH_LIN:
		index = TCTL_TBL_SINTER_STRENGTH_LIN;
		break;
	case TCTL_CAL_DP_SLOPE_LINEAR:
		index = TCTL_TBL_DP_SLOPE_LINEAR;
		break;
	default:
		pr_err("%s,%d, err id: %u\n", __func__, __LINE__, info.id);
		return -EPERM;
	}
	t = tctl_table(tuning, core, index);
	if (!t || !t->ptr)
		return -1;
	info.rows = t->rows;
	info.cols = t->cols;
	info.width = t->width;
	size = info.rows * info.cols * info.width;
	if (info.ptr) {
		void *tmp = kzalloc(size, GFP_KERNEL);
		u32 ret = 0;

		if (!tmp)
			return -1;
		if (info.tsource == 0)
			apical_api_calibration(info.id, 1, (uintptr_t)tmp,
					       size, (uintptr_t)&ret);
		else
			memcpy(tmp, t->ptr, size);
		if (copy_to_user((void __user *)info.ptr, tmp, size)) {
			kfree(tmp);
			return -EFAULT;
		}
		kfree(tmp);
	}
	if (copy_to_user(tctl_uptr(value), &info, sizeof(info)))
		return -EFAULT;
	return 0;
}

/* IMAGE_TUNING_CID_ISP_TABLE_ATTR set: write a calibration table back */
static int tctl_table_set(void *core, int32_t value)
{
	struct tctl_table_info info;
	u32 size, ret = 0;
	void *data;

	if (!tctl_param(core))
		return -1;
	if (copy_from_user(&info, tctl_uptr(value), sizeof(info)))
		return -EFAULT;
	size = info.rows * info.cols * info.width;
	if (!info.ptr) {
		pr_err("%s,%d, param err\n", __func__, __LINE__);
		return 0;
	}
	if (!size || size > 0x10000)
		return -EINVAL;
	data = kzalloc(size, GFP_KERNEL);
	if (!data)
		return -1;
	if (copy_from_user(data, (const void __user *)info.ptr, size)) {
		kfree(data);
		return -EFAULT;
	}
	apical_api_calibration(info.id, 0, (uintptr_t)data, size, (uintptr_t)&ret);
	if (ret)
		pr_err("%s,%d, ret = %u\n", __func__, __LINE__, ret);
	kfree(data);
	return 0;
}

/* ---------------------------------------------------------------- get --- */
/*
 * Beyond vendor: CSC presets (0x80000a6, ../common/tx_isp_csc.h), as on T20.
 * The stock T30 s_ctrl rejects the id (-1) and libimp 1.0.5 has no API.
 * A preset is written into calibration table RGB2YUV_CONVERSION (API id
 * 139 = firmware table 276) with the vendor calibration API, the YUV matrix
 * is recomputed by re-setting the current saturation (276 is not in the
 * post-SET apply list), and the cs_conv clip registers of every channel get
 * the preset's range.  The UV clip is left alone at night (the day/night
 * reload pins it to 512 for mono); that reload also restores table 276 from
 * the tuning bin, so tx_isp_t30_csc_reapply() puts the preset back.  Until
 * CSC_ATTR is set nothing differs from stock.
 */
#define TCTL_CAL_RGB2YUV		139	/* API2FRM_IDX[139] = table 276 */

static DEFINE_MUTEX(tctl_csc_mutex);
static int tctl_csc_active;
static u16 tctl_csc_lut[12];
static u16 tctl_csc_clip[4];	/* Y min, Y max, UV min, UV max */

static void tctl_csc_write_clip(const u16 *clip, bool night)
{
	static const u32 base[] = { 0x578, 0x6b8, 0x7b8 };	/* fr, ds1, ds2 */
	int i;

	for (i = 0; i < ARRAY_SIZE(base); i++) {
		tctl_reg_field(base[i], 0, 0x3ff, clip[0]);
		tctl_reg_field(base[i] + 4, 0, 0x3ff, clip[1]);
		if (night)
			continue;
		tctl_reg_field(base[i] + 8, 0, 0x3ff, clip[2]);
		tctl_reg_field(base[i] + 12, 0, 0x3ff, clip[3]);
	}
}

/* caller holds tctl_csc_mutex */
static int tctl_csc_program(bool night)
{
	u32 ret = 0, sat = 0;

	apical_api_calibration(TCTL_CAL_RGB2YUV, TCTL_DIR_SET,
			       (uintptr_t)tctl_csc_lut, sizeof(tctl_csc_lut),
			       (uintptr_t)&ret);
	if (ret)
		return -EIO;
	tctl_csc_write_clip(tctl_csc_clip, night);
	if (!tctl_cmd(TCTL_T_SCENE, TCTL_SCENE_SATURATION, 0, TCTL_DIR_GET,
		      &sat))
		tctl_cmd(TCTL_T_SCENE, TCTL_SCENE_SATURATION, sat & 0xff,
			 TCTL_DIR_SET, NULL);
	return 0;
}

/* After the day/night table reload (tuning event 0x4000003). */
static void tx_isp_t30_csc_reapply(void *tuning)
{
	mutex_lock(&tctl_csc_mutex);
	if (tctl_csc_active &&
	    tctl_csc_program(TCTL_U32(tuning, TCTL_OFF_DAYNIGHT) != 0))
		pr_warn("tx-isp-t30: CSC preset not re-applied\n");
	mutex_unlock(&tctl_csc_mutex);
}

static int tctl_csc_ready(void *core)
{
	struct tx_isp_t30_core_video_view *vcore = core;

	if (vcore->vin.mbus.code == V4L2_MBUS_FMT_YUYV8_1X16)
		return -EPERM;	/* YUV sensor: cs_conv is not in the path */
	if (!tctl_param(core))
		return -EBUSY;
	return 0;
}

static int tctl_csc_set(void *tuning, void *core, int32_t value)
{
	u32 attr[TX_ISP_CSC_ATTR_WORDS];
	int32_t p[TX_ISP_CSC_WORDS];
	u16 old_lut[12], old_clip[4];
	int old_active, ret;

	if (copy_from_user(attr, tctl_uptr(value), sizeof(attr)))
		return -EFAULT;
	ret = tx_isp_csc_check(attr);
	if (!ret)
		ret = tctl_csc_ready(core);
	if (ret)
		return ret;
	tx_isp_csc_params(attr, p);

	mutex_lock(&tctl_csc_mutex);
	old_active = tctl_csc_active;
	memcpy(old_lut, tctl_csc_lut, sizeof(old_lut));
	memcpy(old_clip, tctl_csc_clip, sizeof(old_clip));
	tx_isp_csc_to_apical(p, tctl_csc_lut, tctl_csc_clip);
	tctl_csc_active = 1;
	ret = tctl_csc_program(TCTL_U32(tuning, TCTL_OFF_DAYNIGHT) != 0);
	if (ret) {
		/* table rejected: nothing was written, keep the old state */
		tctl_csc_active = old_active;
		memcpy(tctl_csc_lut, old_lut, sizeof(old_lut));
		memcpy(tctl_csc_clip, old_clip, sizeof(old_clip));
	}
	mutex_unlock(&tctl_csc_mutex);
	return ret;
}

static int tctl_csc_get(void *core, int32_t value)
{
	u32 attr[TX_ISP_CSC_ATTR_WORDS];
	u16 lut[12], clip[4];
	u32 ret = 0;
	int err;

	err = tctl_csc_ready(core);
	if (err)
		return err;
	mutex_lock(&tctl_csc_mutex);
	if (!tctl_csc_active) {
		/* vendor behaviour until a preset was set */
		mutex_unlock(&tctl_csc_mutex);
		return -1;
	}
	/* what is in effect: the firmware table and the day clip */
	apical_api_calibration(TCTL_CAL_RGB2YUV, TCTL_DIR_GET, (uintptr_t)lut,
			       sizeof(lut), (uintptr_t)&ret);
	memcpy(clip, tctl_csc_clip, sizeof(clip));
	mutex_unlock(&tctl_csc_mutex);
	if (ret)
		return -EIO;
	tx_isp_csc_from_apical(lut, clip, attr);
	return copy_to_user(tctl_uptr(value), attr, sizeof(attr)) ? -EFAULT : 0;
}

static int tx_isp_t30_tuning_ctl_get(void *tuning, void *core,
				     struct v4l2_control *c)
{
	struct tx_isp_t30_core_video_view *vcore = core;
	u32 r = 0;
	int ret = 0;

	tctl_check_abi();
	switch (c->id) {
	case 0x080000a0: {	/* RAW DRC attribute: OEM g_ctrl 0x8d34 (Iridix registers) */
		u8 *a = (u8 *)tuning + TCTL_OFF_DRC_ATTR;
		u32 v = APICAL_READ_32(0x3c8);

		a[4] = APICAL_READ_32(0x3c4);
		a[5] = v >> 8;
		a[6] = v >> 16;
		*(u16 *)(a + 8) = APICAL_READ_32(0x3d0) & 0xfff;
		*(u16 *)(a + 10) = APICAL_READ_32(0x3d4) & 0xfff;
		return copy_to_user(tctl_uptr(c->value), a, 12) ? -EFAULT : 0;
	}
	case V4L2_CID_POWER_LINE_FREQUENCY:
		c->value = TCTL_U32(tuning, TCTL_OFF_FLICKER);
		return 0;
	case V4L2_CID_HFLIP:
		c->value = TCTL_U32(tuning, TCTL_OFF_HFLIP);
		return 0;
	case V4L2_CID_VFLIP:
		c->value = TCTL_U32(tuning, TCTL_OFF_VFLIP);
		return 0;
	case V4L2_CID_SCENE_MODE:
		c->value = TCTL_U32(tuning, TCTL_OFF_SCENE);
		return 0;
	case V4L2_CID_COLORFX:
		c->value = TCTL_U32(tuning, TCTL_OFF_COLORFX);
		return 0;
	case V4L2_CID_SATURATION:
		c->value = TCTL_U32(tuning, TCTL_OFF_SATURATION);
		return 0;
	case V4L2_CID_BRIGHTNESS:
		c->value = TCTL_U32(tuning, TCTL_OFF_BRIGHTNESS);
		return 0;
	case V4L2_CID_CONTRAST:
		c->value = TCTL_U32(tuning, TCTL_OFF_CONTRAST);
		return 0;
	case V4L2_CID_SHARPNESS:
		c->value = TCTL_U32(tuning, TCTL_OFF_SHARPNESS);
		return 0;
	case 0x08000001: {	/* AWB_CWF_SHIFT: first two words of the light source table */
		struct tx_isp_t30_lookup_table *t = tctl_table(tuning, core,
							       TCTL_TBL_LIGHT_SRC);

		if (t && t->ptr) {
			u16 *w = t->ptr;

			c->value = (w[0] << 16) + w[1];
		}
		return 0;
	}
	case 0x08000004: {	/* WB_ATTR */
		struct tctl_wb_attr wb;
		int mode;

		if (tctl_cmd(TCTL_T_ALGO, TCTL_AWB_MODE, -1, TCTL_DIR_GET, &r))
			return -1;
		mode = tctl_wb_mode_from_apical(r);
		if (mode < 0) {
			pr_err("err: %s,%d isp wb mode :%d  \n", __func__,
			       __LINE__, mode);
			return -1;
		}
		wb.mode = mode;
		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_AWB_RED_GAIN, -1,
			     TCTL_DIR_GET, &r))
			return -1;
		wb.rgain = r;
		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_AWB_BLUE_GAIN, -1,
			     TCTL_DIR_GET, &r))
			return -1;
		wb.bgain = r;
		return copy_to_user(tctl_uptr(c->value), &wb, sizeof(wb)) ?
		       -EFAULT : 0;
	}
	case 0x08000005:	/* WB_STATIS_ATTR: awb red/blue gain statistics */
		c->value = (tctl_reg_get(0x858, 0, 0xfff) << 16) +
			   tctl_reg_get(0x85c, 0, 0xfff);
		return 0;
	case 0x08000006:	/* AWB_WEIGHT */
		return tctl_weight_get(TCTL_AWB_WEIGHT, c->value);
	case 0x08000007: {	/* AWB_HIST */
		struct tctl_awb_sta s;

		memset(&s, 0, sizeof(s));
		s.r_gain = tctl_reg_get(0x858, 0, 0xfff);
		s.b_gain = tctl_reg_get(0x85c, 0, 0xfff);
		s.awb_sum = APICAL_READ_32(0x860);
		s.stats_mode = tctl_reg_get(0x868, 0, 1) ? 1 : 0;
		s.whitelevel = tctl_reg_get(0x840, 0, 0x3ff);
		s.blacklevel = tctl_reg_get(0x844, 0, 0x3ff);
		s.cr_ref_max = tctl_reg_get(0x848, 0, 0xfff);
		s.cr_ref_min = tctl_reg_get(0x84c, 0, 0xfff);
		s.cb_ref_max = tctl_reg_get(0x850, 0, 0xfff);
		s.cb_ref_min = tctl_reg_get(0x854, 0, 0xfff);
		s.nodeh = tctl_reg_get(0x870, 0, 0xff);
		s.nodev = tctl_reg_get(0x870, 8, 0xff);
		return copy_to_user(tctl_uptr(c->value), &s, sizeof(s)) ?
		       -EFAULT : 0;
	}
	case 0x08000008: {	/* AWB_RGB_COEFFT_WB_ATTR */
		struct tctl_rgb_coefft k;

		k.r = tctl_reg_get(0x4a8, 0, 0xffff);
		k.g = tctl_reg_get(0x4ac, 0, 0xffff);
		k.b = tctl_reg_get(0x4b0, 0, 0xffff);
		return copy_to_user(tctl_uptr(c->value), &k, sizeof(k)) ?
		       -EFAULT : 0;
	}
	case 0x08000022:	/* AE_STRATEGY */
		tctl_cmd(TCTL_T_ALGO, TCTL_AE_SPLIT_PRESET, -1, TCTL_DIR_GET, &r);
		c->value = tctl_ae_strategy_from_apical(r);
		return 0;
	case 0x08000023:	/* AE_COMP */
		if (tctl_cmd(TCTL_T_ALGO, TCTL_AE_COMPENSATION, -1,
			     TCTL_DIR_GET, &r)) {
			pr_err("err: %s,%d apical_command err \n", __func__,
			       __LINE__);
			return -1;
		}
		c->value = r;
		return 0;
	case 0x08000024:	/* AE_ROI */
		ret = tctl_cmd(TCTL_T_ALGO, TCTL_AE_ROI, 0, TCTL_DIR_GET, &r);
		c->value = r;
		if (ret) {
			pr_err("err: %s,%d apical_command err \n", __func__,
			       __LINE__);
			return -1;
		}
		return 0;
	case 0x08000025: {	/* EXPR_ATTR */
		struct tx_isp_t30_sensor_attribute_view *attr = vcore->vin.attr;
		struct tctl_expr_get e;
		u32 mode, it;

		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MANUAL_INT_TIME, 0,
			     TCTL_DIR_GET, &mode) ||
		    tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_INT_TIME, 0,
			     TCTL_DIR_GET, &it)) {
			pr_err("err: %s,%d apical_command err \n", __func__,
			       __LINE__);
			return 0;
		}
		memset(&e, 0, sizeof(e));
		e.mode = mode ? 1 : 0;
		e.it = it;
		if (attr && !IS_ERR(attr)) {
			e.it_min = attr->min_integration_time;
			e.it_max = attr->max_integration_time;
			e.one_line_us = attr->one_line_expr_in_us;
		}
		return copy_to_user(tctl_uptr(c->value), &e, sizeof(e)) ?
		       -EFAULT : 0;
	}
	case 0x08000026: {	/* ISP_EV_ATTR */
		struct tctl_ev_attr ev;

		memset(&ev, 0, sizeof(ev));
		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MANUAL_EXP_TIME, -1,
			     TCTL_DIR_GET, &r))
			goto ev_err;
		ev.ev = r;
		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_SENSOR_AGAIN, -1,
			     TCTL_DIR_GET, &r))
			goto ev_err;
		ev.again = r;
		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_ISP_DGAIN, -1,
			     TCTL_DIR_GET, &r))
			goto ev_err;
		ev.dgain = r;
		if (tctl_cmd(TCTL_T_ALGO, TCTL_AE_EXPOSURE, -1, TCTL_DIR_GET, &r))
			goto ev_err;
		ev.expr_us = r;
		if (tctl_cmd(TCTL_T_CALIB, TCTL_CAL_EXPOSURE_LOG2, -1,
			     TCTL_DIR_GET, &r))
			goto ev_err;
		ev.ev_log2 = r;
		if (tctl_cmd(TCTL_T_CALIB, TCTL_CAL_GAIN_LOG2, -1, TCTL_DIR_GET,
			     &r))
			goto ev_err;
		ev.gain_log2 = r;
		return copy_to_user(tctl_uptr(c->value), &ev, sizeof(ev)) ?
		       -EFAULT : 0;
ev_err:
		pr_err("err: %s,%d apical_command err \n", __func__, __LINE__);
		return -1;
	}
	case 0x08000028:	/* MAX_AGAIN_ATTR */
		if (!tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MAX_SENSOR_AGAIN, -1,
			      TCTL_DIR_GET, &r))
			c->value = r;
		return 0;
	case 0x08000029:	/* MAX_DGAIN_ATTR */
		if (!tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MAX_ISP_DGAIN, -1,
			      TCTL_DIR_GET, &r))
			c->value = r;
		return 0;
	case 0x0800002a:	/* HILIGHT_DEPRESS_STRENGTH */
		return tctl_hilight(tuning, core, c, false);
	case 0x0800002b: {	/* GAMMA_ATTR */
		struct tctl_gamma g;
		u32 i;

		for (i = 0; i < 129; i++)
			g.gamma[i] = APICAL_READ_32(0x10400 + 4 * i);
		return copy_to_user(tctl_uptr(c->value), &g, sizeof(g)) ?
		       -EFAULT : 0;
	}
	case 0x0800002d:	/* AE_WEIGHT */
		return tctl_weight_get(TCTL_AEXP_WEIGHT, c->value);
	case 0x0800002e: {	/* AE_HIST */
		struct tctl_ae_sta s;

		memset(&s, 0, sizeof(s));
		s.histhresh[0] = tctl_reg_get(0x800, 0, 0xff);
		s.histhresh[1] = tctl_reg_get(0x804, 0, 0xff);
		s.histhresh[2] = tctl_reg_get(0x808, 0, 0xff);
		s.histhresh[3] = tctl_reg_get(0x80c, 0, 0xff);
		s.hist[0] = tctl_reg_get(0x820, 0, 0xffff);
		s.hist[1] = tctl_reg_get(0x824, 0, 0xffff);
		s.hist[3] = tctl_reg_get(0x828, 0, 0xffff);
		s.hist[4] = tctl_reg_get(0x82c, 0, 0xffff);
		s.hist[2] = 0xffff - s.hist[0] - s.hist[1] - s.hist[3] -
			    s.hist[4];
		s.nodeh = tctl_reg_get(0x830, 0, 0xff);
		s.nodev = tctl_reg_get(0x830, 8, 0xff);
		return copy_to_user(tctl_uptr(c->value), &s, sizeof(s)) ?
		       -EFAULT : 0;
	}
	case 0x08000042: {	/* AF_HIST */
		struct tctl_af_sta s;

		memset(&s, 0, sizeof(s));
		s.metrics = tctl_reg_get(0x880, 0, 0xffff);
		s.metrics_alt = tctl_reg_get(0x880, 16, 0xffff);
		s.thresh_read = tctl_reg_get(0x888, 0, 0xffff);
		s.intensity_read = tctl_reg_get(0x888, 16, 0xffff);
		s.intensity_zone = tctl_reg_get(0x89c, 0, 0xffff);
		s.total_pixels = APICAL_READ_32(0x8c8);
		s.counted_pixels = APICAL_READ_32(0x8cc);
		s.metrics_shift = tctl_reg_get(0x88c, 0, 0xf);
		s.thresh = tctl_reg_get(0x884, 0, 0xffff);
		s.thresh_alt = tctl_reg_get(0x884, 16, 0xffff);
		s.nodeh = tctl_reg_get(0x890, 0, 0xff);
		s.nodev = tctl_reg_get(0x890, 8, 0xff);
		s.np_offset = tctl_reg_get(0x894, 0, 0xff);
		s.intensity_mode = tctl_reg_get(0x898, 0, 7);
		s.skipx = tctl_reg_get(0x8c0, 0, 7);
		s.offsetx = tctl_reg_get(0x8c0, 3, 1);
		s.skipy = tctl_reg_get(0x8c0, 4, 7);
		s.offsety = tctl_reg_get(0x8c0, 7, 1);
		s.scale_top = tctl_reg_get(0x8c4, 4, 0xf);
		s.scale_bottom = tctl_reg_get(0x8c4, 0, 0xf);
		return copy_to_user(tctl_uptr(c->value), &s, sizeof(s)) ?
		       -EFAULT : 0;
	}
	case 0x08000161:	/* ISP_TABLE_ATTR */
		return tctl_table_get(tuning, core, c->value);
	case 0x080000a6:	/* CSC_ATTR, beyond vendor */
		return tctl_csc_get(core, c->value);
	}
	return TCTL_UNHANDLED;
}

/* ---------------------------------------------------------------- set --- */
static int tx_isp_t30_tuning_ctl_set(void *tuning, void *core,
				     struct v4l2_control *c)
{
	struct tx_isp_t30_core_video_view *vcore = core;
	struct tx_isp_t30_core_tuning_view *tcore = core;
	u32 r = 0;

	switch (c->id) {
	case V4L2_CID_POWER_LINE_FREQUENCY: {
		int ret = tx_isp_t30_tuning_set_antiflicker(c->value);

		if (!ret)
			TCTL_U32(tuning, TCTL_OFF_FLICKER) = c->value;
		return ret;
	}
	case V4L2_CID_HFLIP:
		return tctl_hflip_set(tuning, core, c->value);
	case V4L2_CID_VFLIP:
		return tctl_vflip_set(tuning, core, c->value);
	case V4L2_CID_SCENE_MODE:
		/*
		 * The stock handler returns before it touches anything (no
		 * firmware scene change, value never stored), so GetSceneMode
		 * keeps reading 0 as on the vendor stack (T30X b18/b19).
		 */
		return 0;
	case V4L2_CID_COLORFX:
		TCTL_U32(tuning, TCTL_OFF_COLORFX) = c->value;
		tctl_cmd(TCTL_T_SCENE, TCTL_SCENE_COLOR_MODE,
			 tctl_colorfx_to_apical(c->value), TCTL_DIR_SET, NULL);
		return 0;
	case V4L2_CID_SATURATION:
		return tctl_scene_level(tuning, core, TCTL_OFF_SATURATION,
					TCTL_CU_SATURATION, TCTL_SCENE_SATURATION,
					c->value, true);
	case V4L2_CID_BRIGHTNESS:
		return tctl_scene_level(tuning, core, TCTL_OFF_BRIGHTNESS,
					TCTL_CU_BRIGHTNESS, TCTL_SCENE_BRIGHTNESS,
					c->value, true);
	case V4L2_CID_CONTRAST:
		return tctl_contrast_set(tuning, core, c->value);
	case V4L2_CID_SHARPNESS:
		return tctl_scene_level(tuning, core, TCTL_OFF_SHARPNESS,
					TCTL_CU_SHARPNESS, TCTL_SCENE_SHARPENING,
					c->value, false);
	/*
	 * AWB_CWF_SHIFT (0x8000001) is only read here.  Writing the light source
	 * table back goes through apical_api_calibration(CALIBRATION_LIGHT_SRC), whose
	 * lifted calibration-update dispatch for table index 0xef reaches
	 * iridix_init_pre_post_gamma() with a garbage state pointer (oops in QEMU);
	 * the set stays with the lifted switch (-1) until that path is repaired.
	 */
	case 0x08000004: {	/* WB_ATTR */
		struct tctl_wb_attr wb;
		int mode;

		if (copy_from_user(&wb, tctl_uptr(c->value), sizeof(wb)))
			return -EFAULT;
		mode = tctl_wb_mode_to_apical(wb.mode);
		if (mode < 0) {
			pr_err("err: %s,%d mode = %d \n", __func__, __LINE__,
			       wb.mode);
			return -1;
		}
		if (tctl_cmd(TCTL_T_ALGO, TCTL_AWB_MODE, mode, TCTL_DIR_SET, &r)) {
			pr_err("err: %s,%d apical_command err \n", __func__,
			       __LINE__);
			return -1;
		}
		if (wb.mode == 1) {	/* manual */
			if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_AWB_RED_GAIN,
				     wb.rgain, TCTL_DIR_SET, &r) ||
			    tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_AWB_BLUE_GAIN,
				     wb.bgain, TCTL_DIR_SET, &r)) {
				pr_err("err: %s,%d apical_command err \n",
				       __func__, __LINE__);
				return -1;
			}
		}
		return 0;
	}
	case 0x08000006:	/* AWB_WEIGHT */
		return tctl_weight_set(TCTL_AWB_WEIGHT, c->value);
	case 0x08000007: {	/* AWB_HIST */
		struct tctl_awb_sta s;

		if (copy_from_user(&s, tctl_uptr(c->value), sizeof(s)))
			return -EFAULT;
		tctl_reg_field(0x868, 0, 1, s.stats_mode ? 1 : 0);
		tctl_reg_field(0x840, 0, 0x3ff, s.whitelevel);
		tctl_reg_field(0x844, 0, 0x3ff, s.blacklevel);
		tctl_reg_field(0x848, 0, 0xfff, s.cr_ref_max);
		tctl_reg_field(0x84c, 0, 0xfff, s.cr_ref_min);
		tctl_reg_field(0x850, 0, 0xfff, s.cb_ref_max);
		tctl_reg_field(0x854, 0, 0xfff, s.cb_ref_min);
		tctl_reg_field(0x870, 0, 0xff, s.nodeh);
		tctl_reg_field(0x870, 8, 0xff, s.nodev);
		return 0;
	}
	case 0x08000008: {	/* AWB_RGB_COEFFT_WB_ATTR */
		struct tctl_rgb_coefft k;

		if (copy_from_user(&k, tctl_uptr(c->value), sizeof(k)))
			return -EFAULT;
		tctl_reg_field(0x4a8, 0, 0xffff, k.r);
		tctl_reg_field(0x4ac, 0, 0xffff, k.g);
		tctl_reg_field(0x4b0, 0, 0xffff, k.b);
		return 0;
	}
	case 0x08000022:	/* AE_STRATEGY: 0 balanced (0x29), else integration priority (0x2a) */
		if (tctl_cmd(TCTL_T_ALGO, TCTL_AE_SPLIT_PRESET,
			     tctl_ae_strategy_to_apical(c->value), TCTL_DIR_SET, &r))
			pr_warn("Custom Set AE strategy failure!reture value is %d,reason is %u\n",
				-1, r);
		return 0;
	case 0x08000025: {	/* EXPR_ATTR */
		struct tx_isp_t30_sensor_attribute_view *attr = vcore->vin.attr;
		struct tctl_expr_set e;
		u32 mode, it = 0;

		if (copy_from_user(&e, tctl_uptr(c->value), sizeof(e)))
			return -EFAULT;
		mode = e.mode == 0 ? 0 : 1;	/* ISP_CORE_EXPR_MODE_AUTO */
		if (e.unit == 1 && mode) {	/* microseconds -> lines */
			if (!attr || IS_ERR(attr) ||
			    tctl_expr_us_to_lines(e.time, attr->one_line_expr_in_us, &it)) {
				pr_err("err: %s,%d one_line_expr_in_us = %d \n",
				       __func__, __LINE__,
				       attr && !IS_ERR(attr) ?
				       attr->one_line_expr_in_us : 0);
				return -1;
			}
		} else {
			it = e.time;
		}
		if (tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MANUAL_INT_TIME, mode,
			     TCTL_DIR_SET, &r)) {
			pr_err("err: %s,%d apical_command err \n", __func__,
			       __LINE__);
			return -1;
		}
		if (mode && tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_INT_TIME, it,
				     TCTL_DIR_SET, &r)) {
			pr_err("err: %s,%d apical_command err \n", __func__,
			       __LINE__);
			return -1;
		}
		return 0;
	}
	case 0x08000028:	/* MAX_AGAIN_ATTR */
		tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MAX_SENSOR_AGAIN, c->value,
			 TCTL_DIR_SET, &r);
		return 0;
	case 0x08000029:	/* MAX_DGAIN_ATTR */
		tctl_cmd(TCTL_T_SYSTEM, TCTL_SYS_MAX_ISP_DGAIN, c->value,
			 TCTL_DIR_SET, &r);
		return 0;
	case 0x0800002a:	/* HILIGHT_DEPRESS_STRENGTH */
		return tctl_hilight(tuning, core, c, true);
	case 0x0800002d:	/* AE_WEIGHT */
		return tctl_weight_set(TCTL_AEXP_WEIGHT, c->value);
	case 0x0800002e: {	/* AE_HIST */
		struct tctl_ae_sta s;

		if (copy_from_user(&s, tctl_uptr(c->value), sizeof(s)))
			return -EFAULT;
		tctl_reg_field(0x800, 0, 0xff, s.histhresh[0]);
		tctl_reg_field(0x804, 0, 0xff, s.histhresh[1]);
		tctl_reg_field(0x808, 0, 0xff, s.histhresh[2]);
		tctl_reg_field(0x80c, 0, 0xff, s.histhresh[3]);
		tctl_reg_field(0x830, 0, 0xff, s.nodeh);
		tctl_reg_field(0x830, 8, 0xff, s.nodev);
		return 0;
	}
	case 0x08000042: {	/* AF_HIST */
		struct tctl_af_sta s;

		if (copy_from_user(&s, tctl_uptr(c->value), sizeof(s)))
			return -EFAULT;
		tctl_reg_field(0x88c, 0, 0xf, s.metrics_shift);
		tctl_reg_field(0x884, 0, 0xffff, s.thresh);
		tctl_reg_field(0x884, 16, 0xffff, s.thresh_alt);
		tctl_reg_field(0x890, 0, 0xff, s.nodeh);
		tctl_reg_field(0x890, 8, 0xff, s.nodev);
		tctl_reg_field(0x894, 0, 0xff, s.np_offset);
		tctl_reg_field(0x898, 0, 7, s.intensity_mode);
		tctl_reg_field(0x8c0, 0, 7, s.skipx);
		tctl_reg_field(0x8c0, 3, 1, s.offsetx);
		tctl_reg_field(0x8c0, 4, 7, s.skipy);
		tctl_reg_field(0x8c0, 7, 1, s.offsety);
		tctl_reg_field(0x8c4, 4, 0xf, s.scale_top);
		tctl_reg_field(0x8c4, 0, 0xf, s.scale_bottom);
		return 0;
	}
	case 0x080000e0: {	/* CONTROL_FPS */
		u32 fps = c->value;
		int ret;

		if (fps == vcore->vin.fps)
			return 0;
		ret = tx_isp_notify(NULL, 0x02000008, &fps);
		if (ret) {
			pr_err("Failed to set fps!!!!\n");
			return ret;
		}
		tctl_cmd(TCTL_T_IMAGE, TCTL_IMG_SENSOR_FPS_MODE, TCTL_FPS25,
			 TCTL_DIR_SET, &r);
		TCTL_U32(tuning, TCTL_OFF_FPS) = fps;
		return 0;
	}
	case 0x080000e1: {	/* DAY_OR_NIGHT */
		if ((u32)c->value == TCTL_U32(tuning, TCTL_OFF_DAYNIGHT))
			return 0;
		if (!tcore->param) {
			pr_err("Can't get the parameters of isp tuning!\n");
			return -ENOENT;
		}
		if ((u32)c->value != TCTL_U32(tuning, TCTL_OFF_DAYNIGHT)) {
			TCTL_U32(tuning, TCTL_OFF_DAYNIGHT) = c->value;
			tcore->isp_daynight_switch = 1;
		}
		return 0;
	}
	case 0x08000161:	/* ISP_TABLE_ATTR */
		return tctl_table_set(core, c->value);
	case 0x080000a6:	/* CSC_ATTR, beyond vendor */
		return tctl_csc_set(tuning, core, c->value);
	case 0x08000168: {	/* DRC mode: OEM s_ctrl 0x7b90 */
		u32 m = c->value, dn = TCTL_U32(tuning, TCTL_OFF_DAYNIGHT);

		TCTL_U32(tuning, TCTL_OFF_DRC_MODE) = m;
		stab[9] = m == 0;			/* manual Iridix */
		if (tctl_param(core)) {
			if (m == 0) {
				stab[42] = 0;
				stab[41] = 0xff;
			} else {
				/* Iridix strength limits of the WDR mode in use */
				if (tctl_cmd(TCTL_T_IMAGE, 0x45, (u32)-1, TCTL_DIR_GET, &r))
					pr_err("tx-isp-t30: drc mode get ret err %u\n", r);
				if (r == 14)
					stab[41] = tctl_lut_byte(core, dn, 91);
				else if (r == 15)
					stab[41] = tctl_lut_byte(core, dn, 92);
				else
					pr_err("tx-isp-t30: drc: unknown wdr mode %u\n", r);
				stab[42] = tctl_lut_byte(core, dn, 210);
			}
		}
		tctl_reg_field(0x40, 15, 1, m == 5);	/* DISABLE: Iridix off */
		TCTL_U32(tuning, TCTL_OFF_DRC_ATTR) = m;
		return 0;
	}
	case 0x080000a0: {	/* RAW DRC attribute: OEM s_ctrl 0x7cc8 */
		u8 *a = (u8 *)tuning + TCTL_OFF_DRC_ATTR;

		if (copy_from_user(a, tctl_uptr(c->value), 12))
			return -EFAULT;
		tctl_cmd(TCTL_T_ALGO, 0x6a, a[4], TCTL_DIR_SET, NULL);	/* strength */
		return 0;
	}
	case 0x08000163: {	/* ANTIFOG: OEM s_ctrl 0x76d0 */
		u32 v = c->value;

		TCTL_U32(tuning, TCTL_OFF_ANTIFOG) = v;
		if (v) {	/* 1 strong, 2 medium, 3 weak -> preset 47/48/49 */
			tctl_cmd(TCTL_T_ALGO, 0x5f, v == 2 ? 48 : v == 3 ? 49 : 47,
				 TCTL_DIR_SET, NULL);
			tctl_cmd(TCTL_T_ALGO, 0x5e, 46, TCTL_DIR_SET, NULL);
		} else {
			tctl_cmd(TCTL_T_ALGO, 0x5e, 45, TCTL_DIR_SET, NULL);
		}
		return 0;
	}
	case 0x08000165:	/* CUSTOM_ISP_FREEZE */
		TCTL_U32(tuning, TCTL_OFF_FREEZE) = c->value;
		tctl_reg_field(0x40100, 0, 1, c->value);
		return 0;
	}
	return TCTL_UNHANDLED;
}

#endif /* TX_ISP_T30_TUNING_CTL_H */
