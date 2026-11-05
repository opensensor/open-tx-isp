/* T32 OEM 0xa80: private_kthread_stop; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_kthread_stop(struct task_struct *k);
int private_kthread_stop(struct task_struct *k)
{
    return kthread_stop(k);
}
