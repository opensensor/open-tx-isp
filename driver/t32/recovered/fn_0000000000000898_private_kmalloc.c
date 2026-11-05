/* T32 OEM 0x898: private_kmalloc; recovery status: normalized_exact_match. */
#include "../compat.h"
void *private_kmalloc(size_t size, gfp_t flags);
void *private_kmalloc(size_t size, gfp_t flags)
{
    return kmalloc(size, flags);
}
