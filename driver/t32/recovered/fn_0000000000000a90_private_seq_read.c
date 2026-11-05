/* T32 OEM 0xa90: private_seq_read; recovery status: normalized_exact_match. */
#include "../compat.h"
ssize_t private_seq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos);
ssize_t private_seq_read(struct file *file, char __user *buf, size_t size, loff_t *ppos)
{
    return seq_read(file, buf, size, ppos);
}
