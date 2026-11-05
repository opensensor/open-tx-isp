/* T32 OEM 0xaa0: private_seq_lseek; recovery status: normalized_exact_match. */
#include "../compat.h"
loff_t private_seq_lseek(struct file *file, loff_t offset, int whence);
loff_t private_seq_lseek(struct file *file, loff_t offset, int whence)
{
    return seq_lseek(file, offset, whence);
}
