/* T32 OEM 0x760b8: tisp_cdns_refresh; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_cdns_par_refresh();
int tisp_cdns_refresh(int arg1, int arg2)
{
	return tisp_cdns_par_refresh(arg1, arg2, 256);
}
