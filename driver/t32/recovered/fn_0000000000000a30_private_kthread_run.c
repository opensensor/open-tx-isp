/* T32 OEM 0xa30: private_kthread_run; recovery status: diff_mismatch. */
#include "../compat.h"
struct task_struct *private_kthread_run(int (*threadfn)(void *data), void *data, const char namefmt[]);
struct task_struct *private_kthread_run(int (*threadfn)(void *data), void *data, const char namefmt[])
{
    return kthread_run(threadfn, data, "%s", namefmt ? namefmt : "");
}
