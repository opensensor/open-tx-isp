/* T32 OEM 0xaf0: private_seq_printf; recovery status: diff_mismatch. */
#include "../compat.h"
int private_seq_printf(struct seq_file *m, const char *f, ...);
int private_seq_printf(struct seq_file *m, const char *f, ...)
{
    int ret;
    va_list args;
    va_start(args, f);
    ret = seq_vprintf(m, f, args);
    va_end(args);
    return ret;
}
