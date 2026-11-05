/* T32 OEM 0xbe0: private_do_gettimeofday; recovery status: normalized_exact_match. */
#include "../compat.h"
void private_do_gettimeofday(struct timeval *tv);
void private_do_gettimeofday(struct timeval *tv)
{
    do_gettimeofday(tv);
}
