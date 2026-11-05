/* T32 OEM 0xb1804: tisp_g_osd_block_attr; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_msca_api_get_osd_out_cfg();


int32_t tisp_g_osd_block_attr(uint32_t a0, uintptr_t a1)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_msca_api_get_osd_out_cfg(a0 & 255);

    return 0;
}
