/* T32 OEM 0x1054c: system_reg_ldc_write; recovery status: normalized_exact_match. */
#include "../compat.h"
extern void *t32_data_d9944;

void *system_reg_ldc_write(int32_t arg1, int32_t arg2)
{
	void *result;

	result = *(volatile uint32_t *)((char *)t32_data_d9944 + 0xf4);
	*(volatile uint32_t *)((char *)result + arg1) = arg2;
	return result;
}
