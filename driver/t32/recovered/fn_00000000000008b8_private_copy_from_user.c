/* T32 OEM 0x8b8: private_copy_from_user; recovery status: diff_mismatch. */
#include "../compat.h"
long private_copy_from_user(void *to, const void __user *from, long size);
long private_copy_from_user(void *to, const void __user *from, long size)
{
    return copy_from_user(to, from, size);
}
