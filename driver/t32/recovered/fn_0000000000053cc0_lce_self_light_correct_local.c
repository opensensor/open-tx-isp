/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d6b50[] __asm__("t32_data_d6b50");
u64 lce_self_light_correct_local(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_53cc4 = ((u32)(unsigned long)ref_t32_data_d6b50 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_53cc0:
    t6 = *(volatile u32 *)(unsigned long)(sp + (16));
    t2 = hi_53cc4;
    t4 = *(volatile u8 *)(unsigned long)(a2 + (8));
    t5 = *(volatile u8 *)(unsigned long)(a2 + (12));
    t2 = t2 - hi_53cc4 + (u32)(unsigned long)ref_t32_data_d6b50;
    a2 = 0;
    t3 = 20;
L_53cdc:
    v0 = t2 + a2;
    t1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = a0 + a2;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    t0 = v0 - t1;
    branch = ((s32)t0 <= 0); v0 = 0;
    if (branch) goto L_53d08;
    goto L_53cf8;
L_53cf8:
    branch = (t4 == 0); v1 = a1 + a2;
    if (branch) goto L_53d2c;
    goto L_53d00;
L_53d00:
    v0 = a3 + a2; goto L_53d1c;
L_53d08:
    branch = (t0 == 0); v1 = a1 + a2;
    if (branch) goto L_53d2c;
    goto L_53d10;
L_53d10:
    branch = (t5 == 0); v0 = t1 + v0;
    if (branch) goto L_53d30;
    goto L_53d18;
L_53d18:
    v0 = t6 + a2;
L_53d1c:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = v1 * t0;
    v0 = (s32)v0 >> (0x7 & 31);
    v1 = a1 + a2;
L_53d2c:
    v0 = t1 + v0;
L_53d30:
    a2 = a2 + 1;
    branch = (a2 != t3); *(volatile u8 *)(unsigned long)(v1 + (0)) = v0;
    if (branch) goto L_53cdc;
    goto L_53d3c;
L_53d3c:
    ;
    return ((u64)v1 << 32) | v0;
}
