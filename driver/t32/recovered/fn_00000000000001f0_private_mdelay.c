/* T32 OEM 0x1f0: private_mdelay; recovery status: diff_mismatch. */
#include "../compat.h"
void __udelay(unsigned long count);

void private_mdelay(int32_t arg1)
{
	void (*delay_p)(unsigned long) = __udelay;
	int32_t i = arg1;

	while (i != 0) {
		i -= 1;
		delay_p(1000);
	}
}
