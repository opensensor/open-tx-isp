/* T32 OEM 0x76018: tisp_cdns_all_reg_refresh; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_cdns_intp_reg_refresh();
int tisp_cdns_all_reg_refresh(int32_t arg1, int32_t arg2)
{
	return tisp_cdns_intp_reg_refresh(arg1, arg2);
}
