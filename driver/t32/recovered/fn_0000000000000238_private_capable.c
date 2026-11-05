/* T32 OEM 0x238: private_capable; recovery status: normalized_exact_match. */
#include "../compat.h"
bool private_capable(int cap);
bool private_capable(int cap)
{
    return capable(cap);
}
