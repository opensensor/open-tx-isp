/* T32 OEM 0x9e0: private_getrawmonotonic; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_getrawmonotonic(struct timespec *ts);
void private_getrawmonotonic(struct timespec *ts)
{
    getrawmonotonic(ts);
}
