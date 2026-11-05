/* T32 OEM 0x540: private_raw_mutex_init; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_raw_mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key);
void private_raw_mutex_init(struct mutex *lock, const char *name, struct lock_class_key *key)
{
    __mutex_init(lock, name, key);
}
