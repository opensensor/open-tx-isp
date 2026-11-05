/* T32 OEM 0xb22ec: tisp_get_ae_tgain; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int api_ae_get_tgain();
int tisp_get_ae_tgain(int arg1, int *arg2)
{
	return api_ae_get_tgain(arg1, arg2);
}
