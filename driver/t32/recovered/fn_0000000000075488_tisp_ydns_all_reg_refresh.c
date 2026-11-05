/* T32 OEM 0x75488: tisp_ydns_all_reg_refresh; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ydns_intp_reg_refresh();
int tisp_ydns_all_reg_refresh(int arg1, int arg2)
{
	return tisp_ydns_intp_reg_refresh(arg1, arg2);
}
