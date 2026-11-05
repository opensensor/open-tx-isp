/* T32 OEM 0x9abb0: tisp_tmo_adr_params_refresh; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_tmo_adr_gamma_refresh();
int tisp_tmo_adr_params_refresh(int32_t arg1)
{
	return tisp_tmo_adr_gamma_refresh(arg1);
}
