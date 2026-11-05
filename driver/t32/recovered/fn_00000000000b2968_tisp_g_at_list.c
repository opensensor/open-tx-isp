/* T32 OEM 0xb2968: tisp_g_at_list; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_ae_get_at_list();


int32_t tisp_g_at_list(uint32_t a0, uintptr_t a1)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_ae_get_at_list(a0 & 255);

    return 0;
}
