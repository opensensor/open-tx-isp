/* T32 OEM 0x8d688: tisp_ccm_wake_up; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ccm_write_reg();
int tisp_ccm_wake_up(int arg1)
{
	return tisp_ccm_write_reg(arg1, 0);
}
