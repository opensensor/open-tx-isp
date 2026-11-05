/* T32 OEM 0x3cc: private_request_mem_region; recovery status: normalized_exact_match. */
#include "../compat.h"
struct resource *private_request_mem_region(resource_size_t start, resource_size_t n, const char *name);
struct resource *private_request_mem_region(resource_size_t start, resource_size_t n, const char *name)
{
    return request_mem_region(start, n, name);
}
