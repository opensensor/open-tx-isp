/* Host test: T30 system table item accessor (driver/t30/tx_isp_t30_system_item.h).
 * Vendor contract of every system_* function: *data = 0; flag 1 get, flag 0 set,
 * other flag returns 2 and touches nothing. */
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
#include "../driver/t30/tx_isp_t30_system_item.h"

#define CK(c) do { if (!(c)) { printf("FAIL line %d: %s\n", __LINE__, #c); bad++; } } while (0)

int main(void)
{
	u8 tab[60];
	int out, bad = 0;

	memset(tab, 0, sizeof(tab));
	/* 1 byte item */
	out = 0x77;
	CK(t30_system_item(tab + 3, 1, 0x5a, 0, &out) == 0 && out == 0 && tab[3] == 0x5a && tab[2] == 0 && tab[4] == 0);
	CK(t30_system_item(tab + 3, 1, 0, 1, &out) == 0 && out == 0x5a);
	/* a value wider than the item is truncated, neighbours untouched */
	CK(t30_system_item(tab + 4, 1, 0x1ff, 0, &out) == 0 && tab[4] == 0xff && tab[5] == 0);
	/* 2 byte item, little endian */
	CK(t30_system_item(tab + 24, 2, 0x1234, 0, &out) == 0 && tab[24] == 0x34 && tab[25] == 0x12 && tab[26] == 0);
	CK(t30_system_item(tab + 24, 2, 0, 1, &out) == 0 && out == 0x1234);
	/* 4 byte item */
	CK(t30_system_item(tab + 16, 4, 0x01020304u, 0, &out) == 0 && tab[16] == 4 && tab[19] == 1 && tab[20] == 0);
	CK(t30_system_item(tab + 16, 4, 0, 1, &out) == 0 && out == 0x01020304);
	/* any other flag: 2, item and output untouched except *data = 0 */
	tab[7] = 9;
	out = 0x77;
	CK(t30_system_item(tab + 7, 1, 0x33, 2, &out) == 2 && tab[7] == 9 && out == 0);
	CK(t30_system_item(tab + 7, 1, 0x33, 0xff, &out) == 2 && tab[7] == 9);
	/* a get never writes the table */
	tab[8] = 0xa5;
	CK(t30_system_item(tab + 8, 1, 0x11, 1, &out) == 0 && out == 0xa5 && tab[8] == 0xa5);

	if (bad) { printf("t30_system_item_host_test: %d FAILED\n", bad); return 1; }
	printf("t30_system_item_host_test: PASS\n");
	return 0;
}
