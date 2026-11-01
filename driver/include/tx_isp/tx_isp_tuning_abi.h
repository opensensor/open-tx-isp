#ifndef TX_ISP_TUNING_ABI_H
#define TX_ISP_TUNING_ABI_H

#ifdef __KERNEL__
#include <linux/types.h>
#else
#include <stdint.h>
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#endif

/*
 * Proprietary libimp control IDs shared by the legacy T23/T31 generation.
 * T41 moved the startup frame-rate and running-mode controls, so those IDs
 * remain explicitly generation-qualified below.
 */
#define TX_ISP_TUNING_CMD_WB			0x08000004U
#define TX_ISP_TUNING_CMD_WB_STATS		0x08000005U
#define TX_ISP_TUNING_CMD_WB_GLOBAL_STATS	0x08000009U
#define TX_ISP_TUNING_CMD_AE_COMP		0x08000023U
#define TX_ISP_TUNING_CMD_AE_ROI		0x08000024U
#define TX_ISP_TUNING_CMD_EXPR			0x08000025U
#define TX_ISP_TUNING_CMD_EV_ATTR		0x08000026U
#define TX_ISP_TUNING_CMD_TOTAL_GAIN		0x08000027U
#define TX_ISP_TUNING_CMD_MAX_AGAIN		0x08000028U
#define TX_ISP_TUNING_CMD_MAX_DGAIN		0x08000029U
#define TX_ISP_TUNING_CMD_HIGHLIGHT		0x0800002aU
#define TX_ISP_TUNING_CMD_MOVE_STATE		0x0800002cU
#define TX_ISP_TUNING_CMD_AE_WEIGHT		0x0800002dU
#define TX_ISP_TUNING_CMD_AE_HIST		0x0800002eU
#define TX_ISP_TUNING_CMD_AE_MIN		0x0800002fU
#define TX_ISP_TUNING_CMD_AE_ZONE		0x08000030U
#define TX_ISP_TUNING_CMD_AE_HIST_ORIGIN	0x08000031U
#define TX_ISP_TUNING_CMD_AE_IT_MAX		0x08000032U
#define TX_ISP_TUNING_CMD_AE_LUMA		0x08000033U
#define TX_ISP_TUNING_CMD_AE_MANUAL		0x08000035U
#define TX_ISP_TUNING_CMD_BACKLIGHT		0x08000037U
#define TX_ISP_TUNING_CMD_DEFOG			0x08000039U
#define TX_ISP_TUNING_CMD_DPC			0x08000062U
#define TX_ISP_TUNING_CMD_TEMPER		0x08000085U
#define TX_ISP_TUNING_CMD_SINTER		0x08000086U
#define TX_ISP_TUNING_CMD_DRC			0x080000a2U
#define TX_ISP_TUNING_CMD_T31_SENSOR_FPS	0x080000e0U
#define TX_ISP_TUNING_CMD_T31_RUNNING_MODE	0x080000e1U
#define TX_ISP_TUNING_CMD_BCSH_HUE		0x08000101U

#define TX_ISP_TUNING_CMD_T41_SENSOR_FPS	0x08000070U
#define TX_ISP_TUNING_CMD_T41_RUNNING_MODE	0x08000071U
#define TX_ISP_TUNING_CMD_T41_HVFLIP		0x08000073U
#define TX_ISP_TUNING_CMD_T41_AWB_ATTR		0x08000010U
#define TX_ISP_TUNING_CMD_T41_AWB_STATS		0x08000011U
#define TX_ISP_TUNING_CMD_T41_AWB_WEIGHT	0x08000012U
#define TX_ISP_TUNING_CMD_T41_AWB_GLOBAL_STATS	0x08000013U
#define TX_ISP_TUNING_CMD_T41_AE_WEIGHT		0x08000021U
#define TX_ISP_TUNING_CMD_T41_AE_STATS		0x08000022U
#define TX_ISP_TUNING_CMD_T41_AE_EXPR_INFO	0x08000023U
#define TX_ISP_TUNING_CMD_T41_ANTIFLICKER	0x08000026U
#define TX_ISP_TUNING_CMD_T41_BCSH_HUE		0x08000081U
#define TX_ISP_TUNING_CMD_T41_BRIGHTNESS	0x08000092U
#define TX_ISP_TUNING_CMD_T41_SHARPNESS		0x08000093U
#define TX_ISP_TUNING_CMD_T41_SATURATION	0x08000094U
#define TX_ISP_TUNING_CMD_T41_CONTRAST		0x08000095U
#define TX_ISP_TUNING_CMD_T41_AWB_RGB_COEFFT	0x08000098U
#define TX_ISP_TUNING_CMD_T41_SENSOR_ATTR	0x08000033U
#define TX_ISP_TUNING_CMD_T41_MASK_BLOCK	0x08000074U
#define TX_ISP_TUNING_CMD_T41_SCALER_LV		0x080000a6U
/* T41 libimp 1.1.0/1.2.5 numbering (the one the 0x71/0x73 IDs above use). */
#define TX_ISP_TUNING_CMD_T41_AE_SCENCE		0x08000024U
#define TX_ISP_TUNING_CMD_T41_GAMMA		0x08000025U
#define TX_ISP_TUNING_CMD_T41_WDR_OUTPUT	0x08000054U
#define TX_ISP_TUNING_CMD_T41_MODULE_CONTROL	0x08000072U
#define TX_ISP_TUNING_CMD_T41_AUTOZOOM		0x08000077U
#define TX_ISP_TUNING_CMD_T41_CCM		0x08000080U
#define TX_ISP_TUNING_CMD_T41_CSC		0x08000096U
#define TX_ISP_TUNING_CMD_T41_MODULE_RATIO	0x080000a4U
/* IMP_ISP_Tuning_SwitchBin: IMPISPBinAttr {u32 enable; char bname[128]} (132 bytes), set only. */
#define TX_ISP_TUNING_CMD_T41_SWITCH_BIN	0x080000a5U
/* ISP-drawn OSD (T41 libimp 1.2.x): IMPISPOSDAttr (12 bytes), IMPISPOSDBlockAttr (20 bytes). */
#define TX_ISP_TUNING_CMD_T41_OSD_ATTR		0x080000a1U
#define TX_ISP_TUNING_CMD_T41_OSD_BLOCK		0x080000a2U
/* T41 issue #171 (OEM tx-isp-t41.ko 1.2.5 tx_isp_core_ops_s/g_ctrl):
 * IMPISPDrawBlockAttr (32 bytes), IMPISPCsccrModeAttr (12 bytes),
 * IMPISPFaceAeWeiget (12, get/set), IMPISPFaceAeLuma (8, get),
 * AE flicker flag (4, get) and AE BV (4, get; libimp 1.2.6). */
#define TX_ISP_TUNING_CMD_T41_DRAW_BLOCK	0x080000a0U
#define TX_ISP_TUNING_CMD_T41_CSCCR		0x08000097U
#define TX_ISP_TUNING_CMD_T41_FACE_AE_WEIGHT	0x08000036U
#define TX_ISP_TUNING_CMD_T41_FACE_AE_LUMA	0x08000037U
#define TX_ISP_TUNING_CMD_T41_AE_FLICKER_FLAG	0x0800003aU
#define TX_ISP_TUNING_CMD_T41_AE_BV		0x080000b3U
#define TX_ISP_TUNING_T41_SWITCH_BIN_BYTES	132U
/* T41 libimp: AF weight table (15x15 bytes); other SoCs use this ID for AE_IT_MAX. */
#define TX_ISP_TUNING_CMD_T41_AF_WEIGHT		0x08000032U
/* T41 AF statistics (#179): GetAfStatistics 6 x u32[15][15] (5400 bytes),
 * GetAFMetricesInfo {u32, u32, u8} (12 bytes); both get only, other SoCs use
 * these IDs for AE_HIST_ORIGIN / AE freeze. */
#define TX_ISP_TUNING_CMD_T41_AF_STATIS		0x08000031U
#define TX_ISP_TUNING_CMD_T41_AF_METRICS	0x08000034U
/* T41 libimp 1.2.6 (libimp + libt41-firmware 1.2.6 disassembly). */
#define TX_ISP_TUNING_CMD_T41_STATIS_CONFIG	0x08000000U
#define TX_ISP_TUNING_T41_STATIS_CONFIG_BYTES	72U
#define TX_ISP_TUNING_CMD_T41_AWB_CT_TREND	0x08000015U
#define TX_ISP_TUNING_CMD_T41_AWB_CONVERGE	0x08000016U
#define TX_ISP_TUNING_CMD_T41_AE_CONVERGE	0x08000028U
#define TX_ISP_TUNING_CMD_T41_AE_EV_LIST	0x08000038U
/* T41 libimp 1.2.6 IMP_ISP_Tuning_Set/GetFaceAe (IMPISPFaceAttr, 24 bytes) and
 * Set/GetAeExpList (IMPISPAeExpListAttr, 324 bytes); other SoCs use these IDs
 * for AE_MANUAL / TOTAL_GAIN. */
#define TX_ISP_TUNING_CMD_T41_FACE_AE		0x08000035U
#define TX_ISP_TUNING_CMD_T41_AE_EXP_LIST	0x08000027U
#define TX_ISP_TUNING_CMD_T41_AE_AT_LIST	0x08000039U
#define TX_ISP_TUNING_T41_AE_LIST_BYTES		128U
#define TX_ISP_TUNING_CMD_T41_TMO_CURVE		0x08000063U
#define TX_ISP_TUNING_T41_TMO_CURVE_BYTES	404U
/* T41 SetTmoFaceae (56 bytes, set only); other SoCs use this ID for DPC. */
#define TX_ISP_TUNING_CMD_T41_TMO_FACEAE	0x08000062U
#define TX_ISP_TUNING_T41_TMO_FACEAE_BYTES	56U
/* IMPISPWaitFrameAttr {u32 timeout; u64 cnt; u32 irqtype} (24 bytes), get only. */
#define TX_ISP_TUNING_CMD_T41_WAIT_FRAME_DONE	0x08000091U
#define TX_ISP_TUNING_T41_WAIT_FRAME_BYTES	24U

/* Open implementation extension.  Keep policy names in userspace: the
 * driver only owns the atomic auto/manual AWB transition and gain replay. */
#define TX_ISP_TUNING_CMD_OPEN_AWB_CONTROL	0x08ff0001U
#define TX_ISP_TUNING_CMD_OPEN_AE_TARGET	0x08ff0002U
#define TX_ISP_TUNING_CMD_OPEN_COLOR_MODEL	0x08ff0003U
#define TX_ISP_TUNING_CMD_OPEN_AWB_SCENE	0x08ff0004U
#define TX_ISP_TUNING_CMD_OPEN_AWB_TARGET	0x08ff0005U
#define TX_ISP_TUNING_CMD_OPEN_AWB_OWNER	0x08ff0006U
/* Explicit GET handshake; legacy kernels may silently acknowledge unknown IDs. */
#define TX_ISP_TUNING_AWB_OWNER_NATIVE	0x41574201U

#define TX_ISP_TUNING_AWB_MANUAL		0U
#define TX_ISP_TUNING_AWB_AUTO		1U

#define TX_ISP_TUNING_COLOR_MODEL_DAY		0U
#define TX_ISP_TUNING_COLOR_MODEL_LOW_LIGHT	1U
#define TX_ISP_TUNING_COLOR_MODEL_BRIGHT_DAY	2U

struct tx_isp_tuning_awb_scene {
	u32 raw_r_q10;
	u32 raw_b_q10;
};

/* Calibrated neutral-mesh estimate, already including sensor RGB bias.
 * ENODATA means hold the previous gains, never revert to whole-scene gray
 * world. Separate from AWB_SCENE, whose raw-ratio ABI remains unchanged. */
struct tx_isp_tuning_awb_target {
	u32 r_gain_q10;
	u32 b_gain_q10;
};

#define TX_ISP_TUNING_DIR_GET			0x01U
#define TX_ISP_TUNING_DIR_SET			0x02U

enum tx_isp_tuning_payload_kind {
	TX_ISP_TUNING_PAYLOAD_INLINE = 0,
	TX_ISP_TUNING_PAYLOAD_USER_PTR = 1,
};

/*
 * payload_size is the fixed wire size.  Zero is permitted for an opaque or
 * variable-size payload whose owner validates the size itself.
 */
struct tx_isp_tuning_cmd_desc {
	u32 id;
	u16 payload_size;
	u8 directions;
	u8 payload_kind;
};

/* Eight-byte G_CTRL/S_CTRL envelope used by T23 and T31. */
struct tx_isp_tuning_control {
	u32 id;
	u32 value_or_ptr;
};

/* Twelve-byte extended-control envelope used by T31. */
struct tx_isp_tuning_ext_control {
	u32 direction;
	u32 id;
	u32 value_or_ptr;
};

/* Sixteen-byte extended-control envelope used by T23. */
struct tx_isp_tuning_t23_ext_control {
	u32 count;
	u32 id;
	u32 value_or_ptr;
	u32 sensor;
};

/* Sixteen-byte startup-control envelope used by T41. */
struct tx_isp_tuning_t41_control {
	u32 channel;
	u32 is_get;
	u32 id;
	u32 value_or_ptr;
};

/* Gen3 IMPISPAntiflickerAttr: enum followed by uint8_t frequency. */
struct tx_isp_tuning_t41_antiflicker {
	u32 mode;
	u8 frequency;
	u8 reserved[3];
};

/* Eight-byte payload for TX_ISP_TUNING_CMD_OPEN_AWB_CONTROL.  Manual gains
 * use the ISP's Q10 convention (0x400 is unity).  For AUTO, they seed the
 * bounded controller so a live profile change has no color discontinuity. */
struct tx_isp_tuning_awb_control {
	u32 mode;
	u16 r_gain;
	u16 b_gain;
};

/* Exact libimp response layouts. */
struct tx_isp_tuning_expr {
	u32 mode;
	u16 integration_time;
	u16 integration_time_min;
	u16 integration_time_max;
	u16 one_line_expr_in_us;
};

struct tx_isp_tuning_ev_attr {
	u32 ev;
	u32 expr_us;
	u32 ev_log2;
	u32 again;
	u32 dgain;
	u32 gain_log2;
};

struct tx_isp_tuning_wb {
	u32 mode;
	u16 r_gain;
	u16 b_gain;
};

/* T40/T41 1.2 libimp packed response layouts. */
#define TX_ISP_TUNING_T41_AE_EXPR_BYTES		232U
#define TX_ISP_TUNING_T41_AE_EXPR_INTEGRATION	24U
#define TX_ISP_TUNING_T41_AE_EXPR_AGAIN		28U
#define TX_ISP_TUNING_T41_AE_EXPR_TOTAL_GAIN	204U
#define TX_ISP_TUNING_T41_AE_EXPR_EXPOSURE	216U
#define TX_ISP_TUNING_T41_AE_EXPR_EV_LOG2	224U

#define TX_ISP_TUNING_T41_AE_STATS_BYTES	1934U
#define TX_ISP_TUNING_T41_AE_STATS_HIST5		0U
#define TX_ISP_TUNING_T41_AE_STATS_HIST256	10U
#define TX_ISP_TUNING_T41_AE_STATS_ZONES	1034U
#define TX_ISP_TUNING_T41_AE_HIST_BINS		256U
#define TX_ISP_TUNING_T41_AE_ZONE_COUNT		225U

struct tx_isp_tuning_t41_ae_expr_values {
	u32 integration_time;
	u32 analog_gain_x1024;
	u32 min_integration_time;
	u32 max_integration_time;
	u32 max_analog_gain_x1024;
	u32 total_gain_db;
	u64 exposure_value;
	u32 ev_log2;
	/* Nonzero: the max limit is a caller cap (reported as MANUAL). */
	u32 max_integration_manual;
	u32 max_analog_gain_manual;
	/* user state reported back */
	u32 unit;
	u32 freeze;
	u32 it_manual;
	u32 again_manual;
	u32 max_dgain_manual;
	u32 max_dgain;
	u32 manual_integration;	/* in 'unit' */
	u32 manual_again_x1024;
};

/*
 * IMPISPAEExprInfo SET, linear mode.  Honoured: the AE maximum caps (max
 * integration time and max sensor analog gain, x1024), the AE freeze
 * (AeMode), manual integration time (lines or microseconds) and manual
 * sensor analog gain (x1024).  A sensor digital gain cap (AeMaxDgain, >= 1.0)
 * is accepted and reported back; the open AE allocates the sensor analog
 * gain only, so the cap is always met.  Zero means "no cap" (the sensor
 * limit).  Manual sensor/ISP digital gain, minimum caps and an ISP digital
 * gain cap below unity are rejected with -EOPNOTSUPP; an ISP digital gain cap
 * >= unity is a no-op because the open AE never applies ISP digital gain.
 * Short-frame (WDR) fields are ignored in linear mode.
 */
struct tx_isp_tuning_t41_ae_limits {
	u32 max_integration;	/* in 'unit' */
	u32 max_again_x1024;
	u32 unit;		/* 0 lines, 1 microseconds */
	u32 freeze;		/* AeMode manual */
	u32 it_manual, it_value;	/* in 'unit' */
	u32 again_manual, again_value;	/* x1024 */
	u32 max_dgain_manual, max_dgain;
};

/* IMPISPAEScenceAttr: enum, u8, enum, u8, enum, u32, enum, u32, then the
 * read-only luma, luma_scence, bool stable, target and ae_mean. */
#define TX_ISP_TUNING_T41_AE_SCENCE_BYTES	52U
#define TX_ISP_TUNING_T41_AE_SCENCE_AUTO	0U
#define TX_ISP_TUNING_T41_AE_SCENCE_DISABLE	1U
#define TX_ISP_TUNING_T41_AE_SCENCE_ROI		2U
#define TX_ISP_TUNING_T41_AE_SCENCE_GLOBAL	3U
#define TX_ISP_TUNING_T41_AE_COMP_NEUTRAL	128U

struct tx_isp_tuning_t41_ae_scence {
	u32 comp_en;	/* IMPISPAEScenceMode of AeTargetCompEn */
	u32 comp;	/* 0..255, 128 neutral */
	u32 luma;
	u32 stable;
	u32 target;
	u32 ae_mean;
};

/* IMPISPModuleRatioAttr: 16 x { IMPISPTuningOpsMode en; u8 ratio; }. */
#define TX_ISP_TUNING_T41_MODULE_RATIO_BYTES	128U
#define TX_ISP_TUNING_T41_MODULE_RATIO_UNITS	16U
#define TX_ISP_TUNING_T41_RATIO_SINTER		0U
#define TX_ISP_TUNING_T41_RATIO_TEMPER		1U
#define TX_ISP_TUNING_T41_RATIO_DRC		2U
#define TX_ISP_TUNING_T41_RATIO_DPC		3U
#define TX_ISP_TUNING_T41_RATIO_DEFOG		4U
#define TX_ISP_TUNING_T41_RATIO_MODULES		5U

struct tx_isp_tuning_t41_ratio_unit {
	u32 en;
	u32 ratio;
};

#define TX_ISP_TUNING_EV_SPARSE_BYTES		0x80U
#define TX_ISP_TUNING_EV_SPARSE_WORDS		0x20U
#define TX_ISP_TUNING_EV_EXPR_MIN_OFFSET	0x6cU
#define TX_ISP_TUNING_EV_EXPR_MAX_OFFSET	0x6eU
#define TX_ISP_TUNING_EV_LINE_US_OFFSET		0x7cU

const struct tx_isp_tuning_cmd_desc *
tx_isp_tuning_cmd_find(const struct tx_isp_tuning_cmd_desc *table,
		       unsigned int count, u32 id, u8 direction);

int tx_isp_tuning_cmd_table_validate(
	const struct tx_isp_tuning_cmd_desc *table, unsigned int count);

int tx_isp_tuning_expr_pack(struct tx_isp_tuning_expr *out, u32 mode,
			    u32 integration_time, u32 integration_time_min,
			    u32 integration_time_max, u32 one_line_expr_in_us);

int tx_isp_tuning_expr_from_sparse(struct tx_isp_tuning_expr *out,
				   const void *sparse,
				   unsigned int sparse_bytes);

int tx_isp_tuning_ev_pack(struct tx_isp_tuning_ev_attr *out, u32 ev,
			  u32 expr_us, u32 ev_log2, u32 again, u32 dgain,
			  u32 gain_log2);

int tx_isp_tuning_wb_pack(struct tx_isp_tuning_wb *out,
			  const u32 *words, u32 mode_count);

u32 tx_isp_tuning_wb_stats_pack(u32 r_gain, u32 b_gain);

int tx_isp_tuning_t41_ae_expr_pack(
	void *out, unsigned int out_bytes,
	const struct tx_isp_tuning_t41_ae_expr_values *values);

int tx_isp_tuning_t41_ae_stats_pack(void *out, unsigned int out_bytes,
				    const u32 *histogram,
				    unsigned int histogram_bins,
				    u32 *mean_q8);

int tx_isp_tuning_t41_ae_expr_parse(const void *in, unsigned int in_bytes,
				    struct tx_isp_tuning_t41_ae_limits *out);

int tx_isp_tuning_t41_ae_scence_parse(const void *in, unsigned int in_bytes,
				      u32 *comp_en, u32 *comp);

int tx_isp_tuning_t41_ae_scence_pack(void *out, unsigned int out_bytes,
	const struct tx_isp_tuning_t41_ae_scence *values);

u32 tx_isp_tuning_t41_ae_comp_target(u32 target_q8, u32 comp);

int tx_isp_tuning_t41_module_ratio_parse(const void *in, unsigned int in_bytes,
	struct tx_isp_tuning_t41_ratio_unit *units, unsigned int count);

int tx_isp_tuning_t41_module_ratio_pack(void *out, unsigned int out_bytes,
	const struct tx_isp_tuning_t41_ratio_unit *units, unsigned int count);

#endif /* TX_ISP_TUNING_ABI_H */
