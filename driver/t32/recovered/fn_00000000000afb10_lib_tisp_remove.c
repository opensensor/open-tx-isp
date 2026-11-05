/* T32 OEM 0xafb10: lib_tisp_remove; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_lce_remove();
int lib_tisp_remove(void)
{
	return tisp_lce_remove();
}
