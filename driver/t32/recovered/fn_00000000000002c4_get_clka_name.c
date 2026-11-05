/* T32 OEM 0x2c4: get_clka_name; recovery status: diff_mismatch. */
#include "../compat.h"
char *get_clka_name(void)
{
    extern char t32_data_ce254[6];
    return t32_data_ce254;
}
