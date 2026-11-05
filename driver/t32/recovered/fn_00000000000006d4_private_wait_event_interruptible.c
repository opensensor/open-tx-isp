/* T32 OEM 0x6d4: private_wait_event_interruptible; recovery status: diff_mismatch. */
#include "../compat.h"
int private_wait_event_interruptible(wait_queue_head_t *q, int (*state)(void *), void *data);
int private_wait_event_interruptible(wait_queue_head_t *q, int (*state)(void *), void *data)
{
    return wait_event_interruptible(*q, state(data));
}
