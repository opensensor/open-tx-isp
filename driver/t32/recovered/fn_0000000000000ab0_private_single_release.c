/* T32 OEM 0xab0: private_single_release; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_single_release(struct inode *inode, struct file *file);
int private_single_release(struct inode *inode, struct file *file)
{
    return single_release(inode, file);
}
