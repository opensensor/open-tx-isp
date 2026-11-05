/* T32 OEM 0x604: private_sched_clock; recovery status: normalized_exact_match. */
#include "../compat.h"
unsigned long long private_sched_clock(void);
unsigned long long private_sched_clock(void)
{
    return sched_clock();
}
