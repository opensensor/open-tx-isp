/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_da760[] __asm__("t32_data_da760");
u64 sensor_early_init(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1563c = ((u32)(unsigned long)ref_t32_data_da760 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_15634:
    branch = (a0 == 0); v0 = -22;
    if (branch) goto L_15650;
    goto L_1563c;
L_1563c:
    v1 = hi_1563c;
L_15640:
    a1 = *(volatile u32 *)(unsigned long)(v1 - hi_1563c + (u32)(unsigned long)ref_t32_data_da760);
    branch = (a1 != 0); v0 = 0;
    if (branch) goto L_15650;
    goto L_1564c;
L_1564c:
    *(volatile u32 *)(unsigned long)(v1 - hi_1563c + (u32)(unsigned long)ref_t32_data_da760) = a0;
L_15650:
    ;
    return ((u64)v1 << 32) | v0;
}
