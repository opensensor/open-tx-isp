/* T32 OEM 0xae0: private_proc_remove; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_proc_remove(struct proc_dir_entry *de);
void private_proc_remove(struct proc_dir_entry *de)
{
    proc_remove(de);
}
