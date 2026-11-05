/* T32 OEM 0xa4a48: tisp_wdr_maxFun; recovery status: normalized_exact_match. */
#include "../compat.h"
int32_t tisp_wdr_maxFun(int32_t arg1, int32_t arg2)
{
	return (arg1 >= arg2) ? arg1 : arg2;
}
