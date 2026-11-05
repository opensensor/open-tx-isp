/* T32 OEM 0x2d0: get_clkv_name; recovery status: diff_mismatch. */
#include "../compat.h"
char *get_clkv_name(void)
{
    extern char *t32_data_ce250;
    return t32_data_ce250;
}
