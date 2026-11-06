/* Host test: T30 compact AE -> SC4236 analog gain path (Lu-Fi/openimp#202).
 *
 * Part 1 checks the OEM limits the compact AE now honours
 * (driver/t30/tx_isp_t30_ae_manual.h): item 29 again cap
 * (cmos_alloc_sensor_analog_gain 0x10260), anti-flicker only with item 13
 * (cmos_fsm_process_interrupt 0x10a0c / cmos_inttime_update 0x10fc4), item 26
 * integration-time cap (cmos_alloc_integration_time 0x101a0).
 *
 * Part 2 is a MODEL with a sensor mock, not the driver code: it reproduces the
 * message path of driver/t30/tx_isp_t30_recovered.c (sensor_set_analog_gain:
 * post only when the value differs from the attribute shadow attr->again;
 * ispcore_irq_thread_handle_body: deliver pending slot 0 (SDK TX_ISP_I2C_SET_AGAIN) as
 * TX_ISP_EVENT_SENSOR_AGAIN) and the SC4236 sensor driver (init table writes
 * 0x3e08/0x3e09 = 03/10, set_analog_gain writes 0x3e09 = v & 0xff,
 * 0x3e08 = (v >> 8 << 2) | 3).  It shows that a compact AE state kept across
 * an ISP re-init leaves the sensor at 1x (b22: 03/10 while dmesg says
 * code=0x71e), and that clearing it with the firmware state (apical_fw_init)
 * brings the gain back (1f/1e).  The real path needs a device proof. */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;
#include "../driver/t30/tx_isp_t30_ae_manual.h"
#include "t30_ae_item16_oracle.h"

#define CK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); bad++; } } while (0)

/* ---- model of the sensor side ---------------------------------------- */
struct mock {
	u8 r3e08, r3e09;	/* SC4236 gain registers */
	u32 attr_again;		/* tx_isp_sensor_attribute.again (static in the sensor ko) */
	u32 msg_pending, msg_value;	/* core i2c message slot 0 (AGAIN) */
	/* compact AE state (tx_isp_t30_simple_3a) */
	bool ae_init;
	u32 code;
};

static void sensor_init_table(struct mock *m)	/* sc4236 sensor_init(): write_array */
{
	m->r3e08 = 0x03;
	m->r3e09 = 0x10;
}

static void set_analog_gain(struct mock *m, u32 v)	/* open sensor_set_analog_gain */
{
	if (m->attr_again != v) {
		m->attr_again = v;
		m->msg_value = v;
		m->msg_pending = 1;
	}
}

static void irq_thread(struct mock *m)	/* ispcore_irq_thread_handle_body -> sensor ioctl */
{
	if (!m->msg_pending)
		return;
	m->msg_pending = 0;
	m->r3e09 = m->msg_value & 0xff;
	m->r3e08 = (u8)((m->msg_value >> 8 << 2) | 3);
}

/* compact AE in a dark scene: starts at 1x (code 0x10), then pins the maximum */
static void ae_frame(struct mock *m)
{
	if (!m->ae_init) {
		m->ae_init = true;
		m->code = 0x10;
	} else {
		m->code = 0x71e;
	}
	set_analog_gain(m, m->code);
	irq_thread(m);
}

static void isp_session(struct mock *m, bool reset_ae_on_init)
{
	int i;

	/* ispcore_core_ops_init(1): apical_init -> apical_fw_init, sensor init table */
	if (reset_ae_on_init) {
		m->ae_init = false;
		m->code = 0;
	}
	sensor_init_table(m);
	for (i = 0; i < 10; i++)
		ae_frame(m);
}

int main(void)
{
	u8 stab[60];
	struct mock m;
	int bad = 0;

	/* ---- part 1: OEM limits ---- */
	memset(stab, 0, sizeof(stab));
	stab[29] = 130;				/* bin: max sensor again Q5 */
	CK(t30_ae_auto_again_cap(stab, 256041) == 256041);	/* 130 << 11 = 266240 > sensor max */
	stab[29] = 117;				/* init_stab default */
	CK(t30_ae_auto_again_cap(stab, 256041) == 117 << 11);
	stab[29] = 1;				/* b22 "limits=1/1" case: OEM caps to 2048 */
	CK(t30_ae_auto_again_cap(stab, 256041) == 2048);

	stab[52] = 50;				/* init_stab: 50, item 13 = 0 */
	CK(t30_ae_antiflicker_hz(stab) == 0);	/* vendor base: 1915 lines, no quantisation */
	stab[13] = 1;
	CK(t30_ae_antiflicker_hz(stab) == 50);
	stab[52] = 60;
	CK(t30_ae_antiflicker_hz(stab) == 60);

	CK(t30_ae_max_integration(stab, 1916) == 1916);	/* item 26 unset */
	stab[26] = 0x7c; stab[27] = 0x07;	/* 1916 from SYNC_SENSOR_ATTR */
	CK(t30_ae_max_integration(stab, 1916) == 1916);
	stab[26] = 0xe8; stab[27] = 0x03;	/* libimp cap 1000 */
	CK(t30_ae_max_integration(stab, 1916) == 1000);
	stab[26] = 0x10; stab[27] = 0x27;	/* 10000 > sensor: sensor wins */
	CK(t30_ae_max_integration(stab, 1916) == 1916);

	/* ---- part 2: model of the gain message path ---- */
	/* old driver: AE state survives the re-init (raptor session, then apitest) */
	memset(&m, 0, sizeof(m));
	isp_session(&m, false);
	CK(m.r3e08 == 0x1f && m.r3e09 == 0x1e);	/* first session reaches the sensor */
	isp_session(&m, false);
	CK(m.code == 0x71e);			/* AE believes 15x ... */
	CK(m.r3e08 == 0x03 && m.r3e09 == 0x10);	/* ... sensor stays 1x: the b22 symptom */

	/* fixed driver: apical_fw_init clears the compact AE with the OEM FSMs */
	memset(&m, 0, sizeof(m));
	isp_session(&m, true);
	CK(m.r3e08 == 0x1f && m.r3e09 == 0x1e);
	isp_session(&m, true);
	CK(m.r3e08 == 0x1f && m.r3e09 == 0x1e);
	isp_session(&m, true);
	CK(m.r3e08 == 0x1f && m.r3e09 == 0x1e);

	/* Part 3: Iridix collection correction clamp as the OEM fw
	 * (iridix_hist_func.c.o 0x94 bltz -> 0x100, 0x9c slti 4096 / movz -> 0x1000) */
	CK(t30_iridix_collection_correction(0x100) == 0x100);
	CK(t30_iridix_collection_correction(0xfe) == 0xfe);
	CK(t30_iridix_collection_correction(0) == 0);
	CK(t30_iridix_collection_correction(0xfff) == 0xfff);
	CK(t30_iridix_collection_correction(0x1000) == 0x1000);
	CK(t30_iridix_collection_correction(0x7fffffff) == 0x1000);
	CK(t30_iridix_collection_correction(0x80000000u) == 0x100);	/* lift gave 0x1000 */
	CK(t30_iridix_collection_correction(0xffffff00u) == 0x100);

	/* Part 4 (#202): 0x3dc from the exposure ring pair (older, newer), values
	 * from the SDK-built vendor ko iridix_fsm_process_interrupt 0x27810 run in
	 * Unicorn (tools/ko_emu/diff_t30_iridix.py); pairs from the b26 open trace
	 * (audit/t30/b26/pic/start-dmesg.txt), where the open ko wrote 0 for every
	 * rising exposure (shared exp2 rejects a negative log2 input). */
	CK(t30_iridix_collection_ratio(131072, 131072) == 0x100);
	CK(t30_iridix_collection_ratio(131072, 697555) == 0);		/* 2^-8.64 */
	CK(t30_iridix_collection_ratio(697555, 717606) == 0xcf);	/* b26 open: 0 */
	CK(t30_iridix_collection_ratio(927346, 942502) == 0xda);	/* b26 open: 0 */
	CK(t30_iridix_collection_ratio(5, 6) == 0xff);
	CK(t30_iridix_collection_ratio(6, 5) == 0x100);
	CK(t30_iridix_collection_ratio(717606, 697555) == 0x13c);
	CK(t30_iridix_collection_ratio(942502, 927346) == 0x12c);
	CK((t30_iridix_collection_ratio(600000, 0) & 0xfff) == 0);	/* >= 0x1000 */
	CK((t30_iridix_collection_ratio(65536 * 8, 0) & 0xfff) == 0);
	CK(t30_iridix_collection_ratio(0, 65536 * 9) == 0);
	CK(t30_oem_math_exp2(0, 16, 8) == 0x100);
	CK(t30_oem_math_exp2(65536, 16, 8) == 0x200);
	CK(t30_oem_math_exp2((u32)-65536, 16, 8) == 0x80);

	/* Part 5 (#202): item 16 (GetEVAttr ev) as the vendor ae_calculate_exposure,
	 * table from tools/ko_emu/diff_t30_ae_exposure_item.py (SDK-built ko, Unicorn). */
	{
		unsigned int k, n = sizeof(t30_vendor_ae_item16) / sizeof(t30_vendor_ae_item16[0]);

		for (k = 0; k < n; k++)
			CK(t30_ae_exposure_time_item((s32)t30_vendor_ae_item16[k][0]) ==
			   t30_vendor_ae_item16[k][1]);
		CK(n >= 500);
		CK(t30_ae_exposure_time_item(-5) == 0x40);
		/* b9 vendor GetEVAttr ev 8314092 = 3195 lines x 40.66 total gain, Q6 */
		CK(t30_ae_exposure_time_item(1113268) / 64 > 129000 &&
		   t30_ae_exposure_time_item(1113268) / 64 < 131000);
	}

	if (bad) { printf("t30_ae_gain_host_test: %d FAILED\n", bad); return 1; }
	printf("t30_ae_gain_host_test: PASS\n");
	return 0;
}
