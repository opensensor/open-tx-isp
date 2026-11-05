/* T32 OEM 0xb64: private_ktime_set; recovery status: normalized_exact_match. */
#include "../compat.h"
ktime_t private_ktime_set(const long secs, const unsigned long nsecs);
ktime_t private_ktime_set(const long secs, const unsigned long nsecs)
{
    return ktime_set(secs, nsecs);
}
