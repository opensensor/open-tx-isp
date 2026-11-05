/* T32 OEM 0x998: private_vfs_write; recovery status: normalized_exact_match. */
#include "../compat.h"
ssize_t private_vfs_write(struct file *file, const char __user *buf, size_t count, loff_t *pos);
ssize_t private_vfs_write(struct file *file, const char __user *buf, size_t count, loff_t *pos)
{
    return vfs_write(file, buf, count, pos);
}
