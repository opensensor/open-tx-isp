/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_bcsh_itp(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_7bcf8:
    v1 = (u32)a1 < (u32)(a2);
    branch = (v1 == 0); v0 = a3;
    if (branch) goto L_7bd40;
    goto L_7bd04;
L_7bd04:
    v1 = (u32)a1 < (u32)(a0);
    branch = (v1 == 0); v1 = (u32)a0 < (u32)(a2);
    if (branch) goto L_7bd40;
    goto L_7bd10;
L_7bd10:
    branch = (v1 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (branch) goto L_7bd40;
    goto L_7bd18;
L_7bd18:
    v1 = a2 - a1;
    a2 = a2 - a0;
    t1 = a2 * a3;
    a0 = a0 - a1;
    t0 = v1 >> (0x1 & 31);
    a1 = a0 * v0;
    a2 = t1 + t0;
    a2 = a1 + a2;
    if (v1) { lo = a2 / v1; hi = a2 % v1; } else { lo = ~0U; hi = a2; }
    v0 = lo;
L_7bd40:
    ;
    return ((u64)v1 << 32) | v0;
}
