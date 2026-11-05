/* T32 OEM 0xbd0: private_flush_work; recovery status: diff_mismatch. */
#include "../compat.h"
int private_flush_work(struct work_struct *work)
{
	return flush_work(work);
}
