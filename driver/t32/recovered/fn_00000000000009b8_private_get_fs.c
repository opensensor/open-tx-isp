/* T32 OEM 0x9b8: private_get_fs; recovery status: normalized_exact_match. */
#include "../compat.h"
mm_segment_t private_get_fs(void);
mm_segment_t private_get_fs(void)
{
    return get_fs();
}
