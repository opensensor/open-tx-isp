/* T32 OEM 0x2a1f4: lib_tisp_get_ipc_output_pos; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int system_reg_read();


int32_t lib_tisp_get_ipc_output_pos(void)
{
    uint32_t a0 = 0;
    uint32_t t9 = 0;

    /* fragment 0: Arithmetic */
    a0 = 196608;
    t9 = (uintptr_t)&system_reg_read;
    t9 = t9;

    /* fragment 1: IndirectTailCall */
    return system_reg_read(a0 + 512);

    return 0;
}
