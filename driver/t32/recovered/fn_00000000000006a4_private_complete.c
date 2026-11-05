/* T32 OEM 0x6a4: private_complete; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_complete(struct completion *x);
void private_complete(struct completion *x)
{
    complete(x);
}
