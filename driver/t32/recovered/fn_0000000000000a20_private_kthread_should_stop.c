/* T32 OEM 0xa20: private_kthread_should_stop; recovery status: normalized_exact_match. */
#include "../compat.h"
bool private_kthread_should_stop(void);
bool private_kthread_should_stop(void)
{
    return kthread_should_stop();
}
