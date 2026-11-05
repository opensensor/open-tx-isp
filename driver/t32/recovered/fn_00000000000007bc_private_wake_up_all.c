/* T32 OEM 0x7bc: private_wake_up_all; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_wake_up_all(wait_queue_head_t *q);
void private_wake_up_all(wait_queue_head_t *q)
{
    wake_up_all(q);
}
