/* T32 OEM 0xba4: private_schedule_hrtimeout; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_schedule_hrtimeout(ktime_t *expires, const enum hrtimer_mode mode);
int private_schedule_hrtimeout(ktime_t *expires, const enum hrtimer_mode mode)
{
    return schedule_hrtimeout(expires, mode);
}
