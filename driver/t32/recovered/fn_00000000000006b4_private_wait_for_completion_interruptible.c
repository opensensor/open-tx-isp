/* T32 OEM 0x6b4: private_wait_for_completion_interruptible; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_wait_for_completion_interruptible(struct completion *x);
int private_wait_for_completion_interruptible(struct completion *x)
{
    return wait_for_completion_interruptible(x);
}
