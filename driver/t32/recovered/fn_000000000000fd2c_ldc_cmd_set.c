/* T32 OEM 0xfd2c: ldc_cmd_set; recovery status: normalized_exact_match. */
#include "../compat.h"
int32_t ldc_cmd_set(uint32_t a0, uint32_t a1, uint32_t a2)
{
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 1: Arithmetic */
    v0 = a2;

    return (int32_t)v0;
}
