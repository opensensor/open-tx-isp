/* SPDX-License-Identifier: GPL-2.0 */
/*
 * T30 compact AE: the vendor system table controls the compact controller
 * (tx_isp_t30_simple_ae_update) has to honour (host-testable,
 * tests/t30_ae_manual_host_test.c).  Source of the behaviour: tx-isp-t30
 * H20190523a ae_calculate_target (item 53), ae_calculate_exposure (items 1, 16),
 * cmos_alloc_integration_time (items 3, 24), cmos_inttime_update and
 * cmos_get_manual_{again,dgain,isp_dgain}_log2 (items 4-6, 28-33): the
 * lifted OEM state machine is bypassed by the compact AE, so without this
 * the manual exposure, integration time and gain items and the AE
 * compensation were stored but never reached the sensor.
 *
 * All gains are Q16 log2 (system table gains are Q5: item << 11).
 */
#ifndef TX_ISP_T30_AE_MANUAL_H
#define TX_ISP_T30_AE_MANUAL_H

#include "../include/tx_isp/tx_isp_math.h"

struct t30_ae_manual {
	u8 exposure;		/* item 1: manual exposure (total exposure from item 16) */
	u8 integration;		/* item 3: manual integration time (item 24) */
	u8 again;		/* item 4: manual sensor analog gain (item 28) */
	u8 isp_dgain;		/* item 6: manual ISP digital gain (item 32) */
	u8 comp;		/* item 53: AE compensation, 0x80 neutral */
	u8 again_q5, max_again_q5;
	u8 isp_q5, max_isp_q5;
	u16 integration_time;	/* item 24, sensor lines */
	u32 exposure_time_q6;	/* item 16, exposure time in lines, 6 fraction bits */
};

static inline void t30_ae_manual_load(struct t30_ae_manual *m, const u8 *stab)
{
	m->exposure = stab[1];
	m->integration = stab[3];
	m->again = stab[4];
	m->isp_dgain = stab[6];
	m->comp = stab[53];
	m->again_q5 = stab[28];
	m->max_again_q5 = stab[29];
	m->isp_q5 = stab[32];
	m->max_isp_q5 = stab[33];
	memcpy(&m->integration_time, stab + 24, sizeof(m->integration_time));
	memcpy(&m->exposure_time_q6, stab + 16, sizeof(m->exposure_time_q6));
}

static inline s32 t30_ae_clamp(s32 v, s32 lo, s32 hi)
{
	return v < lo ? lo : v > hi ? hi : v;
}

/* ae_calculate_target: signed 1/32-stop offset of the log2 target around 0x80 */
static inline s32 t30_ae_comp_log2(u8 comp)
{
	return ((s32)comp - 0x80) << 11;
}

static inline bool t30_ae_manual_active(const struct t30_ae_manual *m)
{
	return m->exposure || m->integration || m->again || m->isp_dgain;
}

/* cmos_get_manual_again_log2: min(item 28, item 29) << 11 */
static inline s32 t30_ae_manual_again_log2(const struct t30_ae_manual *m,
					   s32 max_again)
{
	u8 q5 = m->again_q5 < m->max_again_q5 ? m->again_q5 : m->max_again_q5;

	return t30_ae_clamp((s32)q5 << 11, 0, max_again);
}

/* cmos_get_manual_isp_dgain_log2: min(item 32, item 33, ISP maximum) << 11 */
static inline s32 t30_ae_manual_isp_log2(const struct t30_ae_manual *m,
					 s32 max_isp)
{
	u8 q5 = m->isp_q5 < m->max_isp_q5 ? m->isp_q5 : m->max_isp_q5;

	return t30_ae_clamp((s32)q5 << 11, 0, max_isp);
}

/* gain part the operator fixed; the integration time partition gets the rest */
static inline s32 t30_ae_manual_fixed_gain(const struct t30_ae_manual *m,
					   s32 max_again, s32 max_isp)
{
	return (m->again ? t30_ae_manual_again_log2(m, max_again) : 0) +
	       (m->isp_dgain ? t30_ae_manual_isp_log2(m, max_isp) : 0);
}

/* cmos_alloc_integration_time: manual time clamped to the sensor range */
static inline u32 t30_ae_manual_integration(const struct t30_ae_manual *m,
					    u32 auto_time, u32 min_time,
					    u32 max_time)
{
	u32 t = m->integration ? m->integration_time : auto_time;

	return t < min_time ? min_time : t > max_time ? max_time : t;
}

/* gains for the chosen integration time (its Q16 log2 in it_log2) */
static inline void t30_ae_manual_gains(const struct t30_ae_manual *m,
				       s32 total_log2, s32 it_log2,
				       s32 max_again, s32 max_isp,
				       s32 *again_log2, s32 *isp_log2)
{
	s32 rest = total_log2 - it_log2;
	s32 fixed_isp = m->isp_dgain ? t30_ae_manual_isp_log2(m, max_isp) : 0;
	s32 a, i;

	if (rest < 0)
		rest = 0;
	a = m->again ? t30_ae_manual_again_log2(m, max_again) :
		t30_ae_clamp(rest - fixed_isp, 0, max_again);
	i = m->isp_dgain ? fixed_isp : t30_ae_clamp(rest - a, 0, max_isp);
	*again_log2 = a;
	*isp_log2 = i;
}

/*
 * cmos_alloc_sensor_analog_gain (libt30-firmware cmos_func.c.o 0x10260):
 * the automatic analog gain request is capped at item 29 (maximum sensor
 * analog gain, Q5) before the sensor's alloc_again quantises it; the part
 * above the cap is left to the ISP digital gain (cmos_digital_gain_update).
 */
static inline s32 t30_ae_auto_again_cap(const u8 *stab, s32 sensor_max)
{
	s32 item = (s32)stab[29] << 11;

	return item < sensor_max ? item : sensor_max;
}

/*
 * cmos_fsm_process_interrupt (0x10a0c, frame event 7) and cmos_inttime_update
 * (0x10fc4): the anti-flicker frequency (item 52) is only used while item 13
 * (global_antiflicker_enable) is set.  init_stab() leaves item 52 at 50 and
 * item 13 at 0, so a freshly initialised ISP runs without anti-flicker until
 * the tuning control enables it.
 */
static inline u32 t30_ae_antiflicker_hz(const u8 *stab)
{
	return stab[13] ? stab[52] : 0;
}

/*
 * cmos_alloc_integration_time (0x101a0): the automatic integration time is
 * limited by item 26 (maximum integration time, set from the sensor attribute
 * on SYNC_SENSOR_ATTR and by the libimp AE limits) as well as by the sensor.
 * An unset item (0) leaves the sensor limit.
 */
static inline u32 t30_ae_max_integration(const u8 *stab, u32 sensor_max)
{
	u16 item;

	memcpy(&item, stab + 26, sizeof(item));
	return item && item < sensor_max ? item : sensor_max;
}

/*
 * iridix_fsm_process_interrupt (OEM fw iridix_hist_func.c.o 0x94..0xa8): the
 * collection correction (ISP 0x3dc, Q8, default 0x100) is
 * math_exp2(previous - current exposure, 16, 8) clamped with SIGNED compares:
 * "bltz -> 0x100" and "slti 4096 / movz -> 0x1000" (0x1000 & 0xfff = 0 in the
 * register).  The lift compared a pointer-typed value (unsigned), so a
 * math_exp2 result with bit 31 set gave 0x1000 (register 0) where the vendor
 * writes 0x100.
 */
static inline u32 t30_iridix_collection_correction(u32 ratio_q8)
{
	if ((s32)ratio_q8 < 0)
		return 0x100;
	return (s32)ratio_q8 < 0x1000 ? ratio_q8 : 0x1000;
}

/*
 * OEM math_exp2 (SDK-built tx-isp-t30.ko 0x1d184, lift R math_exp2): no range
 * check, the final right shift is srlv by (30 - out - (value >> in)) & 31.
 * A negative log2 input (two's complement) therefore gives 2^value, e.g.
 * value = -0.31 (Q16) -> 0xcf in Q8.  The shared tx_isp_exp2_u32() (T30
 * math_exp2 via tx_isp_t30_math.c) rejects value >> in > 30 - out and returns
 * 0, i.e. 2^negative = 0.  The mantissa (table + interpolation) is the shared
 * one, only the shift differs.
 */
static inline u32 t30_oem_math_exp2(u32 value, u8 in, u8 out)
{
	u32 mant = tx_isp_exp2_u32(value & ((1U << (in & 31U)) - 1U), in, 30);

	return mant >> ((30U - out - (value >> (in & 31U))) & 31U);
}

/*
 * iridix_fsm_process_interrupt (SDK ko 0x27810..0x278bc): 0x3dc =
 * clamp(math_exp2(older - newer exposure log2, 16, 8)).  older / newer are
 * exposure ring slots (-1, 0), or (0, 1) with temper2 mode (0x2c0 bit 7).
 * While the exposure rises (older < newer) the vendor writes a ratio below
 * 0x100; the shared exp2 gave 0 (#202: 0x3dc = 0, 0x3c4 never updated).
 */
static inline u32 t30_iridix_collection_ratio(s32 older, s32 newer)
{
	return t30_iridix_collection_correction(
		t30_oem_math_exp2((u32)older - (u32)newer, 16, 8));
}

#endif /* TX_ISP_T30_AE_MANUAL_H */
