/* T32 OEM 0xafef0: tisp_get_tuning; recovery status: normalized_exact_match. */
#include "../compat.h"
extern uint32_t t32_data_f0904;

uint32_t tisp_get_tuning(void)
{
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Arithmetic */
    v0 = (uintptr_t)&t32_data_f0904;

    /* fragment 1: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 2: MemoryAccess */
    v0 = *(uint32_t *)((char *)&t32_data_f0904 + 0);

    return (uint32_t)v0;
}
