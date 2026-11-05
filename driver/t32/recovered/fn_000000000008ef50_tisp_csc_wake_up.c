/* T32 OEM 0x8ef50: tisp_csc_wake_up; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_csc_write_reg();


int32_t tisp_csc_wake_up(uint32_t a0)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_csc_write_reg(a0 & 255);

    return 0;
}
