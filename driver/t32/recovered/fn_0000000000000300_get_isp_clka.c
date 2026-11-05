/* T32 OEM 0x300: get_isp_clka; recovery status: diff_mismatch. */
#include "../compat.h"
extern uint32_t t32_data_ce220;

uint32_t get_isp_clka(void)
{
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Arithmetic */
    v0 = (uintptr_t)&t32_data_ce220;

    /* fragment 1: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 2: MemoryAccess */
    v0 = *(uint32_t *)((char *)&t32_data_ce220 + 32);

    return (uint32_t)v0;
}
