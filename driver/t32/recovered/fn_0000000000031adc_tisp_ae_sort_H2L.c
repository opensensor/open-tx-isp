/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_ae_sort_H2L(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    a2 = a0 + 60;
    v0 = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
L_31ae8:
    if ((s32)v1 >= 0) { v0 = v0 + 4; goto L_31afc; }
    goto L_31af0;
L_31af0:
    v1 = -v1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = v0 + 4;
L_31afc:
    if (a2 != v0) { v1 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_31ae8; }
    goto L_31b04;
L_31b04:
    a2 = 14;
    t2 = -1;
    v1 = a1;
L_31b10:
    v0 = a0;
    a3 = 0;
L_31b18:
    t0 = (s32)a3 < (s32)(a2);
    if (t0 == 0) { a2 = a2 + -1; goto L_31b5c; }
    goto L_31b24;
L_31b24:
    t0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    t3 = (s32)t0 < (s32)(t1);
    branch = (t3 == 0); a3 = a3 + 1;
    if (branch) goto L_31b50;
    goto L_31b38;
L_31b38:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = t1;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(v1 + (4)) = t0;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = t1;
L_31b50:
    v0 = v0 + 4;
    v1 = v1 + 4; goto L_31b18;
L_31b5c:
    branch = (a2 != t2); v1 = a1;
    if (branch) goto L_31b10;
    goto L_31b64;
L_31b64:
    ;
    return ((u64)v1 << 32) | v0;
}
