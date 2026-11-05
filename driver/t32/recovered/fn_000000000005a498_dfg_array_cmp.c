/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 dfg_array_cmp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_5a498:
    v0 = a0;
L_5a49c:
    v1 = v0 - a0;
    v1 = (s32)v1 < (s32)(a2);
    branch = (v1 == 0); ;
    if (branch) goto L_5a4c8;
    goto L_5a4ac;
L_5a4ac:
    a3 = *(volatile int8_t *)(unsigned long)(v0 + (0));
    v1 = *(volatile int8_t *)(unsigned long)(a1 + (0));
    v0 = v0 + 1;
    branch = (a3 == v1); a1 = a1 + 1;
    if (branch) goto L_5a49c;
    goto L_5a4c0;
L_5a4c0:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
L_5a4c8:
    v0 = 1;
    return ((u64)v1 << 32) | v0;
}
