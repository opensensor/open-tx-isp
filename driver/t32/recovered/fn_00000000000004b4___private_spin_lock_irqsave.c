/* T32 OEM 0x4b4: __private_spin_lock_irqsave; recovery status: diff_mismatch. */
#include "../compat.h"
void __private_spin_lock_irqsave(spinlock_t *lock, unsigned long *flags);
void __private_spin_lock_irqsave(spinlock_t *lock, unsigned long *flags)
{
    unsigned long local_flags = 0;
    spin_lock_irqsave(lock, local_flags);
    if (flags) {
        *flags = local_flags;
    }
}
