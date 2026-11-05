/* T32 OEM 0xb0cb8: tisp_get_brightness; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_bcsh_api_get_brightness();
int tisp_get_brightness(int arg1, char *arg2)
{
	return tisp_bcsh_api_get_brightness(arg1, arg2);
}
