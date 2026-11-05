/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_clip(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
    stack[5] = arg5;
L_1e52c:
    v1 = a1;
    a1 = (s32)a1 < (s32)(a3);
    t1 = *(volatile u32 *)(unsigned long)(sp + (16));
    t0 = *(volatile u32 *)(unsigned long)(sp + (20));
    branch = (a1 != 0); v0 = a0;
    if (branch) goto L_1e558;
    goto L_1e544;
L_1e544:
    if (a3 != v1) { a0 = (s32)t0 < (s32)(v1); goto L_1e564; }
    goto L_1e54c;
L_1e54c:
    a0 = (u32)a0 < (u32)(a2);
    branch = (a0 == 0); a0 = (s32)t0 < (s32)(v1);
    if (branch) goto L_1e564;
    goto L_1e558;
L_1e558:
    v0 = a2;
    v1 = a3;
    a0 = (s32)t0 < (s32)(v1);
L_1e564:
    if (a0 != 0) { v0 = t1; goto L_1e580; }
    goto L_1e56c;
L_1e56c:
    branch = (v1 != t0); a0 = (u32)t1 < (u32)(v0);
    if (branch) goto L_1e584;
    goto L_1e574;
L_1e574:
    branch = (a0 == 0); ;
    if (branch) goto L_1e584;
    goto L_1e57c;
L_1e57c:
    v0 = t1;
L_1e580:
    v1 = t0;
L_1e584:
    ;
    return ((u64)v1 << 32) | v0;
}
