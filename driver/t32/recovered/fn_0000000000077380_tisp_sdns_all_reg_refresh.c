/* T32 OEM 0x77380: tisp_sdns_all_reg_refresh; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_sdns_intp_reg_refresh();
int tisp_sdns_all_reg_refresh(int arg1, int arg2)
{
	return tisp_sdns_intp_reg_refresh(arg1, arg2);
}
