/* T32 OEM 0xb3380: lib_tisp_api_get_csccr_output; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int lib_tisp_csccr_dn_status();


int32_t lib_tisp_api_get_csccr_output(uint32_t a0)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return lib_tisp_csccr_dn_status(a0 & 255);

    return 0;
}
