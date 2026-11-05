/* T32 OEM 0xbb4: private_schedule_work; recovery status: normalized_exact_match. */
#include "../compat.h"
bool private_schedule_work(struct work_struct *work);
bool private_schedule_work(struct work_struct *work)
{
    return schedule_work(work);
}
