/* T32 OEM 0xafb00: lib_tisp_func_stop_reset; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_func_stop_reset();
int lib_tisp_func_stop_reset(void)
{
	return tisp_func_stop_reset();
}
