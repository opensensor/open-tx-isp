/* T32 OEM 0xb38: private_simple_strtoull; recovery status: normalized_exact_match. */
#include "../compat.h"
unsigned long long private_simple_strtoull(const char *cp, char **endp, unsigned int base);
unsigned long long private_simple_strtoull(const char *cp, char **endp, unsigned int base)
{
    return simple_strtoull(cp, endp, base);
}
