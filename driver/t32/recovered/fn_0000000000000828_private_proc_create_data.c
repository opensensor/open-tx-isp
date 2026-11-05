/* T32 OEM 0x828: private_proc_create_data; recovery status: normalized_exact_match. */
#include "../compat.h"
struct proc_dir_entry *private_proc_create_data(const char *name, umode_t mode, struct proc_dir_entry *parent, const struct file_operations *proc_fops, void *data);
struct proc_dir_entry *private_proc_create_data(const char *name, umode_t mode, struct proc_dir_entry *parent, const struct file_operations *proc_fops, void *data)
{
    return proc_create_data(name, mode, parent, proc_fops, data);
}
