/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_itp_bv(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_5733c:
    v1 = (u32)a2 < (u32)(a1);
    branch = (v1 == 0); v0 = a3;
    if (branch) goto L_57384;
    goto L_57348;
L_57348:
    v1 = (u32)a0 < (u32)(a1);
    branch = (v1 == 0); v1 = (u32)a2 < (u32)(a0);
    if (branch) goto L_57384;
    goto L_57354;
L_57354:
    branch = (v1 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (branch) goto L_57384;
    goto L_5735c;
L_5735c:
    v1 = a1 - a2;
    a1 = a1 - a0;
    product = (s64)(s32)a1 * (s32)v0; lo = product; hi = product >> 32;
    a2 = a0 - a2;
    v0 = v1 >> (0x1 & 31);
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)a3); lo = product; hi = product >> 32;
    a2 = lo;
    v0 = a2 + v0;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v0 = lo;
L_57384:
    ;
    return ((u64)v1 << 32) | v0;
}
