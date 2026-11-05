/* T32 OEM 0xbcce0: init_module; recovery status: diff_mismatch. */
#include "../compat.h"
extern int tx_isp_init();
extern int tx_isp_sinfo_init();
int __init init_module(void)
{
	int ret;

	ret = tx_isp_init();
	if (ret == 0)
		tx_isp_sinfo_init();

	return ret;
}
