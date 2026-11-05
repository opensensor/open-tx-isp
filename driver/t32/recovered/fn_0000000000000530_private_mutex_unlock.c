/* T32 OEM 0x530: private_mutex_unlock; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_mutex_unlock(struct mutex *lock);
void private_mutex_unlock(struct mutex *lock)
{
    mutex_unlock(lock);
}
