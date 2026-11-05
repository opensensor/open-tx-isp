/* T32 OEM 0xac0: private_single_open_size; recovery status: normalized_exact_match. */
#include "../compat.h"
int private_single_open_size(struct file *file, int (*show)(struct seq_file *, void *), void *data, size_t size);
int private_single_open_size(struct file *file, int (*show)(struct seq_file *, void *), void *data, size_t size)
{
    return single_open_size(file, show, data, size);
}
