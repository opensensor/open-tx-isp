/* T32 OEM 0x1db00: fix_point_add_32; recovery status: normalized_exact_match. */
#include "../compat.h"
int32_t fix_point_add_32(uint32_t a0, uint32_t a1, uint32_t a2)
{
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 1: Arithmetic */
    v0 = a1 + a2;

    return (int32_t)v0;
}
