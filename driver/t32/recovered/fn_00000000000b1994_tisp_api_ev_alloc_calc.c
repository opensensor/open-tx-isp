/* T32 OEM 0xb1994: tisp_api_ev_alloc_calc; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ae_api_ev_alloc_calc();


int32_t tisp_api_ev_alloc_calc(uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_ae_api_ev_alloc_calc(a0 & 255);

    return 0;
}
