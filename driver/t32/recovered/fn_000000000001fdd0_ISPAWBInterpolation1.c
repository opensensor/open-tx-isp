/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 ISPAWBInterpolation1(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
    stack[5] = arg5;
    stack[6] = arg6;
L_1fdd0:
    t1 = *(volatile u32 *)(unsigned long)(sp + (20));
    t2 = *(volatile u32 *)(unsigned long)(sp + (24));
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = a3 << (a1 & 31);
    t0 = (u32)t2 < (u32)(t1);
    v1 = v1 - a3;
    v0 = t1 << (a1 & 31);
    branch = (t0 != 0); v1 = v1 << (a1 & 31);
    if (branch) goto L_1fe1c;
    goto L_1fdf4;
L_1fdf4:
    t1 = t2 - t1;
    a1 = t1 << (a1 & 31);
    a2 = a2 - a0;
    a0 = a1 * a2;
    t0 = v1 >> (0x1 & 31);
    t0 = a0 + t0;
    if (v1) { lo = t0 / v1; hi = t0 % v1; } else { lo = ~0U; hi = t0; }
    v1 = lo;
    v0 = v1 + v0;
    return ((u64)v1 << 32) | v0;
L_1fe1c:
    t1 = t1 - t2;
    a2 = a2 - a0;
    a1 = t1 << (a1 & 31);
    a3 = a1 * a2;
    a0 = v1 >> (0x1 & 31);
    a0 = a3 + a0;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    v1 = lo;
    v0 = v0 - v1;
    return ((u64)v1 << 32) | v0;
}
