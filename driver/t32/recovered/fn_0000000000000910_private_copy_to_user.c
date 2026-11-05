/* T32 OEM 0x910: private_copy_to_user; recovery status: diff_mismatch. */
#include "../compat.h"
long private_copy_to_user(void __user *to, const void *from, long size);
long private_copy_to_user(void __user *to, const void *from, long size)
{
    return copy_to_user(to, from, size);
}
