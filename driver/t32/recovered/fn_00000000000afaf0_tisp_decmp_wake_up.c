/* T32 OEM 0xafaf0: tisp_decmp_wake_up; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_decmp_ref_reg_cfg();
int tisp_decmp_wake_up(int arg1)
{
	return tisp_decmp_ref_reg_cfg(arg1);
}
