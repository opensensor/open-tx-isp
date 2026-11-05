/* T32 OEM 0xaf8c0: tisp_decmp_all_reg_refresh; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_decmp_ref_reg_cfg();
int32_t tisp_decmp_all_reg_refresh(int32_t arg1)
{
	return tisp_decmp_ref_reg_cfg(arg1);
}
