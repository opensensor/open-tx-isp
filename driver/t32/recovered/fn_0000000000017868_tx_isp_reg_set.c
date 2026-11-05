/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tx_isp_reg_set(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_17868:
    a3 = a3 - a2;
    v0 = 0;
    v1 = 0;
    a3 = a3 + 1;
    t1 = 1;
L_1787c:
    t0 = (s32)v1 < (s32)(a3);
    branch = (t0 == 0); t0 = v1 + a2;
    if (branch) goto L_17898;
    goto L_17888;
L_17888:
    t0 = t1 << (t0 & 31);
    v0 = v0 + t0;
    v1 = v1 + 1; goto L_1787c;
L_17898:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (244));
    v0 = ~(0 | v0);
    a1 = v1 + a1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = v0 & v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a2 = v1 << (a2 & 31);
    v0 = a2 | v0;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
