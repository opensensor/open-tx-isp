/* T32 OEM 0xb0c00: tisp_get_fps; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ae_api_get_fps();


int32_t tisp_get_fps(uint32_t a0, uintptr_t a1)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_ae_api_get_fps(a0 & 255);

    return 0;
}
