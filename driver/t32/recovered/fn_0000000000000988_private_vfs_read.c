/* T32 OEM 0x988: private_vfs_read; recovery status: normalized_exact_match. */
#include "../compat.h"
ssize_t private_vfs_read(struct file *file, char __user *buf, size_t count, loff_t *pos);
ssize_t private_vfs_read(struct file *file, char __user *buf, size_t count, loff_t *pos)
{
    return vfs_read(file, buf, count, pos);
}
