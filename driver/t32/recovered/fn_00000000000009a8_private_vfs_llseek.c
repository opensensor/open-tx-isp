/* T32 OEM 0x9a8: private_vfs_llseek; recovery status: normalized_exact_match. */
#include "../compat.h"
loff_t private_vfs_llseek(struct file *file, loff_t offset, int whence);
loff_t private_vfs_llseek(struct file *file, loff_t offset, int whence)
{
    return vfs_llseek(file, offset, whence);
}
