/* T32 OEM 0x864: private_vfree; recovery status: diff_mismatch. */
#include "../compat.h"
void private_vfree(void *addr);
void private_vfree(void *addr)
{
    vfree(addr);
}
