/* T32 OEM 0x680: private_init_completion; recovery status: diff_mismatch. */
#include "../compat.h"
void private_init_completion(struct completion *x);
void private_init_completion(struct completion *x)
{
    init_completion(x);
}
