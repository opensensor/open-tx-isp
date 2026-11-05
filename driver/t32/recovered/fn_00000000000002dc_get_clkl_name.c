/* T32 OEM 0x2dc: get_clkl_name; recovery status: diff_mismatch. */
#include "../compat.h"
extern char const __clkl_name_data[] __asm__(".data");

char const (*get_clkl_name(void))[0x5]
{
	return (char const (*)[0x5])__clkl_name_data + 0x2c / 0x5;
}
