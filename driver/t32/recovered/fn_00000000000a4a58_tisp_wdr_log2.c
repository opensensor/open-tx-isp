/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_wdr_log2(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_a4a58:
    v0 = 1;
    a3 = 16;
L_a4a60:
    v1 = 1;
    a2 = 1;
    a1 = v0 + 1;
L_a4a6c:
    t0 = (s32)a2 < (s32)(a1);
    branch = (t0 == 0); a2 = a2 + 1;
    if (branch) goto L_a4a80;
    goto L_a4a78;
L_a4a78:
    v1 = v1 << (0x1 & 31); goto L_a4a6c;
L_a4a80:
    v1 = (s32)v1 < (s32)(a0);
    branch = (v1 == 0); ;
    if (branch) goto L_a4a9c;
    goto L_a4a8c;
L_a4a8c:
    if (a1 == a3) { v0 = 15; goto L_a4a9c; }
    goto L_a4a94;
L_a4a94:
    v0 = a1; goto L_a4a60;
L_a4a9c:
    ;
    return ((u64)v1 << 32) | v0;
}
