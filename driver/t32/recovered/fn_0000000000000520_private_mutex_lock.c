/* T32 OEM 0x520: private_mutex_lock; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_mutex_lock(struct mutex *lock);
void private_mutex_lock(struct mutex *lock)
{
    mutex_lock(lock);
}
