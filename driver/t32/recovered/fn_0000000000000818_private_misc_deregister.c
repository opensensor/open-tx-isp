/* T32 OEM 0x818: private_misc_deregister; recovery status: diff_mismatch. */
#include "../compat.h"
int private_misc_deregister(struct miscdevice *mdev);
int private_misc_deregister(struct miscdevice *mdev)
{
    misc_deregister(mdev);
    return 0;
}
