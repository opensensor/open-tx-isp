/* T32 OEM 0x518: private_spin_lock_init; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_spin_lock_init(spinlock_t *lock);
void private_spin_lock_init(spinlock_t *lock)
{
    spin_lock_init(lock);
}
