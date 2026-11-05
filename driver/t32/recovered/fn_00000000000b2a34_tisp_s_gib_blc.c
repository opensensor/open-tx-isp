/* T32 OEM 0xb2a34: tisp_s_gib_blc; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_gib_api_set_blc();
int tisp_s_gib_blc(int arg1, int arg2)
{
	return tisp_gib_api_set_blc(arg1, arg2);
}
