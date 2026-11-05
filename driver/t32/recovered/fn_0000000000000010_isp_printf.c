/* C wrapper checked against the T32 OEM calling convention. */
#include "../compat.h"
extern int t32_data_ce260;
int isp_printf(int level, const char *fmt, ...)
{
    struct va_format vaf;
    va_list args;
    int ret;
    if ((unsigned int)level < (unsigned int)t32_data_ce260)
        return 0;
    va_start(args, fmt);
    vaf.fmt = fmt;
    vaf.va = &args;
    ret = printk("%pV", &vaf);
    va_end(args);
    if ((unsigned int)level >= 2)
        dump_stack();
    return ret;
}
