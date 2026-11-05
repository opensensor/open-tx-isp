/* T32 OEM 0xb25f0: tisp_g_ae_explist; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ae_api_get_exp_list();
int32_t tisp_g_ae_explist(int32_t arg1, int32_t *arg2)
{
	return tisp_ae_api_get_exp_list(arg1, (int32_t)arg2, (int32_t)&arg2[1]);
}
