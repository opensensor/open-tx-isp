/* T32 OEM 0xb28c4: tisp_s_coefft_wb; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_bcsh_api_set_offset_rgb();
int tisp_s_coefft_wb(int arg1, int arg2)
{
	return tisp_bcsh_api_set_offset_rgb(arg1, arg2);
}
