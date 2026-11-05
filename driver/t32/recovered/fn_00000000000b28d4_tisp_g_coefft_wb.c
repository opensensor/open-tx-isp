/* T32 OEM 0xb28d4: tisp_g_coefft_wb; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_bcsh_api_get_offset_rgb();
int tisp_g_coefft_wb(int arg1, int arg2)
{
	return tisp_bcsh_api_get_offset_rgb(arg1, arg2);
}
