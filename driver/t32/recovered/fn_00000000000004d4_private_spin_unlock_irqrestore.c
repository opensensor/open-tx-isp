/* T32 OEM 0x4d4: private_spin_unlock_irqrestore; recovery status: diff_mismatch. */
#include "../compat.h"
void private_spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags);
void private_spin_unlock_irqrestore(spinlock_t *lock, unsigned long flags)
{
    spin_unlock_irqrestore(lock, flags);
}
