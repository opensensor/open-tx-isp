/* T32 OEM 0xbcd30: cleanup_module; recovery status: diff_mismatch. */
#include "../compat.h"
extern int tx_isp_exit();
extern int tx_isp_sinfo_exit();
void __exit cleanup_module(void)
{
	tx_isp_sinfo_exit();
	tx_isp_exit();
}
