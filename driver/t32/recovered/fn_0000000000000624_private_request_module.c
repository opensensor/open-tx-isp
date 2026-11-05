/* C wrapper checked against the T32 OEM calling convention. */
#include "../compat.h"
int private_request_module(bool wait, const char *fmt, ...)
{
    struct va_format vaf;
    va_list args;
    int ret;
    /* The OEM always requests synchronously, regardless of the first argument. */
    (void)wait;
    va_start(args, fmt);
    vaf.fmt = fmt;
    vaf.va = &args;
    ret = __request_module(true, "%pV", &vaf);
    va_end(args);
    return ret;
}
