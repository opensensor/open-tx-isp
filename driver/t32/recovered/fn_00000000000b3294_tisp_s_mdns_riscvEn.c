/* T32 OEM 0xb3294: tisp_s_mdns_riscvEn; recovery status: normalized_exact_match. */
#include "../compat.h"
extern uint32_t t32_data_e2150;

int32_t tisp_s_mdns_riscvEn(uint32_t a0)
{
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Arithmetic */
    v0 = (uintptr_t)&t32_data_e2150;

    /* fragment 1: MemoryAccess */
    *(uint8_t *)((char *)&t32_data_e2150 + 0) = a0;

    /* fragment 2: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 3: Arithmetic */
    v0 = 0;

    return (int32_t)v0;
}
