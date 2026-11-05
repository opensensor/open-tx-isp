/* T32 OEM 0x1e0: private_msleep; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_msleep(unsigned int msecs);
void private_msleep(unsigned int msecs)
{
    msleep(msecs);
}
