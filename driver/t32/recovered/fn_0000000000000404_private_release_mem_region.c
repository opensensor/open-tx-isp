/* T32 OEM 0x404: private_release_mem_region; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_release_mem_region(resource_size_t start, resource_size_t n);
void private_release_mem_region(resource_size_t start, resource_size_t n)
{
    release_mem_region(start, n);
}
