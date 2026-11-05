/* T32 OEM 0x7d4: private_wake_up; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_wake_up(wait_queue_head_t *q);
void private_wake_up(wait_queue_head_t *q)
{
    wake_up(q);
}
