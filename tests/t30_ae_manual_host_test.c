/* Host test: T30 compact AE manual items and AE compensation
 * (driver/t30/tx_isp_t30_ae_manual.h).  Vendor behaviour: ae_calculate_target
 * (item 53), ae_calculate_exposure (items 1, 16), cmos_alloc_integration_time
 * (items 3, 24), cmos_get_manual_*_log2 (items 4-6, 28-33). */
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int32_t s32;
#include "../driver/t30/tx_isp_t30_ae_manual.h"

#define CK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); bad++; } } while (0)

int main(void)
{
	u8 stab[60];
	struct t30_ae_manual m;
	s32 a, i;
	int bad = 0;

	memset(stab, 0, sizeof(stab));
	stab[53] = 0x80;
	stab[29] = 0x82;	/* max again 130 (Q5) */
	stab[33] = 125;
	t30_ae_manual_load(&m, stab);
	CK(!t30_ae_manual_active(&m));

	/* AE compensation: neutral 0x80, 1/32 stop per step */
	CK(t30_ae_comp_log2(0x80) == 0);
	CK(t30_ae_comp_log2(0x81) == 2048);
	CK(t30_ae_comp_log2(60) == -68 * 2048);
	CK(t30_ae_comp_log2(200) == 72 * 2048);
	CK(t30_ae_comp_log2(0) == -128 * 2048);
	stab[53] = 60;
	t30_ae_manual_load(&m, stab);
	CK(m.comp == 60);

	/* items are read at their table offsets, multi-byte little endian */
	stab[1] = 1; stab[3] = 1; stab[4] = 1; stab[6] = 1;
	stab[24] = 0x34; stab[25] = 0x12;
	stab[16] = 0x40; stab[17] = 0x01; stab[18] = 0; stab[19] = 0;
	stab[28] = 20; stab[32] = 10;
	t30_ae_manual_load(&m, stab);
	CK(m.exposure && m.integration && m.again && m.isp_dgain);
	CK(m.integration_time == 0x1234);
	CK(m.exposure_time_q6 == 0x140);
	CK(t30_ae_manual_active(&m));

	/* integration time: manual clamps to the sensor range, auto passes the AE value */
	CK(t30_ae_manual_integration(&m, 77, 3, 1916) == 1916);	/* 0x1234 > max */
	m.integration_time = 100;
	CK(t30_ae_manual_integration(&m, 77, 3, 1916) == 100);
	m.integration_time = 1;
	CK(t30_ae_manual_integration(&m, 77, 3, 1916) == 3);
	m.integration = 0;
	CK(t30_ae_manual_integration(&m, 77, 3, 1916) == 77);
	CK(t30_ae_manual_integration(&m, 5000, 3, 1916) == 1916);

	/* gains: min(value, max) << 11, clamped to the sensor / ISP limit */
	CK(t30_ae_manual_again_log2(&m, 1000000) == 20 << 11);
	m.again_q5 = 200;	/* above item 29 (130) */
	CK(t30_ae_manual_again_log2(&m, 1000000) == 130 << 11);
	CK(t30_ae_manual_again_log2(&m, 100 << 11) == 100 << 11);
	CK(t30_ae_manual_isp_log2(&m, 1000000) == 10 << 11);
	m.isp_q5 = 250;
	CK(t30_ae_manual_isp_log2(&m, 1000000) == 125 << 11);
	m.again_q5 = 20; m.isp_q5 = 10;

	/* fixed part only counts the manual gains */
	CK(t30_ae_manual_fixed_gain(&m, 1000000, 1000000) == (30 << 11));
	m.again = 0;
	CK(t30_ae_manual_fixed_gain(&m, 1000000, 1000000) == (10 << 11));
	m.isp_dgain = 0;
	CK(t30_ae_manual_fixed_gain(&m, 1000000, 1000000) == 0);

	/* split of the exposure: free gains take what the integration time leaves */
	m.again = 0; m.isp_dgain = 0; m.integration = 1;
	t30_ae_manual_gains(&m, 100000, 60000, 30000, 20000, &a, &i);
	CK(a == 30000 && i == 10000);			/* rest 40000: analog first, ISP the remainder */
	t30_ae_manual_gains(&m, 100000, 60000, 50000, 20000, &a, &i);
	CK(a == 40000 && i == 0);
	t30_ae_manual_gains(&m, 50000, 60000, 30000, 20000, &a, &i);
	CK(a == 0 && i == 0);				/* manual time above the demand: no gain */
	m.again = 1; m.again_q5 = 5;
	t30_ae_manual_gains(&m, 100000, 60000, 30000, 20000, &a, &i);
	CK(a == (5 << 11) && i == 20000);		/* manual analog, ISP takes the rest up to its cap */
	t30_ae_manual_gains(&m, 100000, 60000, 30000, 50000, &a, &i);
	CK(a == (5 << 11) && i == 40000 - (5 << 11));
	m.isp_dgain = 1; m.isp_q5 = 3;
	t30_ae_manual_gains(&m, 100000, 60000, 30000, 20000, &a, &i);
	CK(a == (5 << 11) && i == (3 << 11));		/* both fixed */
	m.again = 0;
	t30_ae_manual_gains(&m, 100000, 60000, 30000, 20000, &a, &i);
	CK(a == 30000 - 0 && i == (3 << 11));		/* free analog gets rest - fixed ISP, capped */

	if (bad) { printf("t30_ae_manual_host_test: %d FAILED\n", bad); return 1; }
	printf("t30_ae_manual_host_test: PASS\n");
	return 0;
}
