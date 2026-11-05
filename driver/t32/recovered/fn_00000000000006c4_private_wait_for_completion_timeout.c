/* T32 OEM 0x6c4: private_wait_for_completion_timeout; recovery status: normalized_exact_match. */
#include "../compat.h"
unsigned long private_wait_for_completion_timeout(struct completion *x, unsigned long timeout);
unsigned long private_wait_for_completion_timeout(struct completion *x, unsigned long timeout)
{
    return wait_for_completion_timeout(x, timeout);
}
