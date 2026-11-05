/* T32 OEM 0x808: private_misc_register; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_misc_register(struct miscdevice *mdev);
int private_misc_register(struct miscdevice *mdev)
{
    return misc_register(mdev);
}
