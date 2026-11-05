/* T32 OEM 0x868bc: tisp_msca_get_shdram_flag; recovery status: normalized_exact_match. */
#include "../compat.h"
extern int system_reg_read();


uint32_t tisp_msca_get_shdram_flag(void)
{
    uint32_t local_14 = 0;
    uint32_t a0 = 0;
    uint32_t ra = 0;
    uintptr_t v0 = 0;

    /* fragment 0: Prologue */
    /* function prologue: stack frame and callee-saved register setup */

    /* fragment 1: CallSetup */
    v0 = (uintptr_t)((uintptr_t (*)(uintptr_t))(uintptr_t)system_reg_read)(983040 + 2528); /* jalr target resolved by relocation */

    /* fragment 2: Epilogue */
    /* function epilogue: restore registers and return */

    /* fragment 3: Arithmetic */
    v0 = v0 >> 16;

    /* fragment 4: Epilogue */
    /* function epilogue: restore registers and return */

    return (uint32_t)v0;
}
