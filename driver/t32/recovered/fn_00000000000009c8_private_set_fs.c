/* T32 OEM 0x9c8: private_set_fs; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_set_fs(mm_segment_t val);
void private_set_fs(mm_segment_t val)
{
    set_fs(val);
}
