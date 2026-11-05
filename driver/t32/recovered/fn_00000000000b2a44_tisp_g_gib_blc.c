/* T32 OEM 0xb2a44: tisp_g_gib_blc; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_gib_api_get_blc();
int tisp_g_gib_blc(int arg1, int arg2)
{
	return tisp_gib_api_get_blc(arg1, arg2);
}
