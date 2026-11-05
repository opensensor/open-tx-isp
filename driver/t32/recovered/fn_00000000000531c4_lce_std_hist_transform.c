/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 lce_std_hist_transform(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_531c4:
    v0 = a1;
    t4 = a1 + 128;
    v1 = a1;
    a0 = 0;
L_531d4:
    t9 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t8 = *(volatile u32 *)(unsigned long)(v1 + (4));
    t7 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t6 = *(volatile u32 *)(unsigned long)(v1 + (12));
    t9 = t9 * a2;
    t5 = *(volatile u32 *)(unsigned long)(v1 + (16));
    t3 = *(volatile u32 *)(unsigned long)(v1 + (20));
    t2 = *(volatile u32 *)(unsigned long)(v1 + (24));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (28));
    v1 = v1 + 32;
    t8 = t8 * a2;
    t9 = t9 >> (a3 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (-32)) = t9;
    t7 = t7 * a2;
    t8 = t8 >> (a3 & 31);
    t0 = t9 + t8;
    a0 = t0 + a0;
    *(volatile u32 *)(unsigned long)(v1 + (-28)) = t8;
    t6 = t6 * a2;
    t7 = t7 >> (a3 & 31);
    a0 = a0 + t7;
    *(volatile u32 *)(unsigned long)(v1 + (-24)) = t7;
    t5 = t5 * a2;
    t6 = t6 >> (a3 & 31);
    a0 = a0 + t6;
    *(volatile u32 *)(unsigned long)(v1 + (-20)) = t6;
    t3 = t3 * a2;
    t5 = t5 >> (a3 & 31);
    a0 = a0 + t5;
    *(volatile u32 *)(unsigned long)(v1 + (-16)) = t5;
    t2 = t2 * a2;
    t3 = t3 >> (a3 & 31);
    a0 = a0 + t3;
    *(volatile u32 *)(unsigned long)(v1 + (-12)) = t3;
    t1 = t1 * a2;
    t2 = t2 >> (a3 & 31);
    a0 = a0 + t2;
    *(volatile u32 *)(unsigned long)(v1 + (-8)) = t2;
    t1 = t1 >> (a3 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (-4)) = t1;
    branch = (v1 != t4); a0 = a0 + t1;
    if (branch) goto L_531d4;
    goto L_5327c;
L_5327c:
    v1 = 0x8000;
    a2 = (s32)a0 < (s32)(v1);
    branch = (a2 == 0); a0 = v1 - a0;
    if (branch) goto L_5331c;
    goto L_5328c;
L_5328c:
    v1 = (s32)a0 >> (0x5 & 31);
    a2 = 0;
    a0 = a0 & 0x1f;
L_53298:
    branch = (a2 == a0); a2 = a2 + 1;
    if (branch) goto L_532b4;
    goto L_532a0;
L_532a0:
    a3 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a1 = a1 + 4;
    a3 = a3 + 1;
    *(volatile u32 *)(unsigned long)(a1 + (-4)) = a3; goto L_53298;
L_532b4:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + 32;
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-32)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-28));
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-28)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-24));
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-24)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-20));
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-20)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-16));
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-16)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-12));
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-12)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-8));
    a0 = a0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (-8)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-4));
    a0 = a0 + v1;
    branch = (t4 != v0); *(volatile u32 *)(unsigned long)(v0 + (-4)) = a0;
    if (branch) goto L_532b4;
    goto L_5331c;
L_5331c:
    ;
    return ((u64)v1 << 32) | v0;
}
