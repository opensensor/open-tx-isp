/* T32 OEM 0x8a8: private_kfree; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_kfree(void *p);
void private_kfree(void *p)
{
    kfree(p);
}
