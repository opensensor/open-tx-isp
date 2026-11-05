/* T32 OEM 0xad0: private_jz_proc_mkdir; recovery status: normalized_exact_match. */
#include "../compat.h"
struct proc_dir_entry *private_jz_proc_mkdir(char *s);
struct proc_dir_entry *private_jz_proc_mkdir(char *s)
{
    return jz_proc_mkdir(s);
}
