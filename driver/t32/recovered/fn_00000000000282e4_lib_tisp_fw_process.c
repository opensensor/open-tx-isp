/* T32 OEM 0x282e4: lib_tisp_fw_process; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int tisp_event_process();


int32_t lib_tisp_fw_process(uint32_t a0)
{
    uint32_t t9 = 0;

    /* fragment 0: ConstantLoad */
    t9 = 0x0;

    /* fragment 1: IndirectTailCall */
    return tisp_event_process(a0 & 255);

    return 0;
}
