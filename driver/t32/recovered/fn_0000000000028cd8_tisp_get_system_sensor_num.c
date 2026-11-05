/* T32 OEM 0x28cd8: tisp_get_system_sensor_num; recovery status: normalized_exact_match. */
#include "../compat.h"
extern uint32_t t32_data_dc284;

uint32_t tisp_get_system_sensor_num(void)
{
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Arithmetic */
    v0 = (uintptr_t)&t32_data_dc284;

    /* fragment 1: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 2: MemoryAccess */
    v0 = *(uint8_t *)((char *)&t32_data_dc284 + 900);

    return (uint32_t)v0;
}
