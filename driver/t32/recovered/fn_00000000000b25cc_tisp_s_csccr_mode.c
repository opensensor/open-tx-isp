/* T32 OEM 0xb25cc: tisp_s_csccr_mode; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_csccr_api_set();


int32_t tisp_s_csccr_mode(uint32_t a0, uintptr_t a1)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_csccr_api_set(a0 & 255);

    return 0;
}
