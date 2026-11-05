/* T32 OEM 0x7ec: private_init_waitqueue_head; recovery status: diff_mismatch. */
#include "../compat.h"
void private_init_waitqueue_head(wait_queue_head_t *q);
void private_init_waitqueue_head(wait_queue_head_t *q)
{
    init_waitqueue_head(q);
}
