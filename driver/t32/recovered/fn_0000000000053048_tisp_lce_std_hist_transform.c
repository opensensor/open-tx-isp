/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_lce_std_hist_transform(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_53048:
    v0 = a1;
    t3 = a1 + 64;
    v1 = a1;
    a0 = 0;
L_53058:
    t9 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t8 = *(volatile u16 *)(unsigned long)(v1 + (2));
    t7 = *(volatile u16 *)(unsigned long)(v1 + (4));
    t6 = *(volatile u16 *)(unsigned long)(v1 + (6));
    t9 = t9 * a2;
    t5 = *(volatile u16 *)(unsigned long)(v1 + (8));
    t4 = *(volatile u16 *)(unsigned long)(v1 + (10));
    t2 = *(volatile u16 *)(unsigned long)(v1 + (12));
    t1 = *(volatile u16 *)(unsigned long)(v1 + (14));
    v1 = v1 + 16;
    t8 = t8 * a2;
    t9 = t9 >> (a3 & 31);
    *(volatile u16 *)(unsigned long)(v1 + (-16)) = t9;
    t7 = t7 * a2;
    t8 = t8 >> (a3 & 31);
    t0 = t9 + t8;
    a0 = t0 + a0;
    *(volatile u16 *)(unsigned long)(v1 + (-14)) = t8;
    t6 = t6 * a2;
    t7 = t7 >> (a3 & 31);
    a0 = a0 + t7;
    *(volatile u16 *)(unsigned long)(v1 + (-12)) = t7;
    t5 = t5 * a2;
    t6 = t6 >> (a3 & 31);
    a0 = a0 + t6;
    *(volatile u16 *)(unsigned long)(v1 + (-10)) = t6;
    t4 = t4 * a2;
    t5 = t5 >> (a3 & 31);
    a0 = a0 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (-8)) = t5;
    t2 = t2 * a2;
    t4 = t4 >> (a3 & 31);
    a0 = a0 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (-6)) = t4;
    t1 = t1 * a2;
    t2 = t2 >> (a3 & 31);
    a0 = a0 + t2;
    *(volatile u16 *)(unsigned long)(v1 + (-4)) = t2;
    t1 = t1 >> (a3 & 31);
    *(volatile u16 *)(unsigned long)(v1 + (-2)) = t1;
    branch = (v1 != t3); a0 = a0 + t1;
    if (branch) goto L_53058;
    goto L_53100;
L_53100:
    v1 = 0x8000;
    a2 = (s32)a0 < (s32)(v1);
    branch = (a2 == 0); a2 = 0;
    if (branch) goto L_531ac;
    goto L_53110;
L_53110:
    a0 = v1 - a0;
    v1 = (s32)a0 >> (0x5 & 31);
    a0 = a0 & 0x1f;
L_5311c:
    branch = (a2 == a0); a2 = a2 + 1;
    if (branch) goto L_53138;
    goto L_53124;
L_53124:
    a3 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a1 = a1 + 2;
    a3 = a3 + 1;
    *(volatile u16 *)(unsigned long)(a1 + (-2)) = a3; goto L_5311c;
L_53138:
    v1 = v1 & 0xffff;
L_5313c:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = v0 + 16;
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-16)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-14));
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-14)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-12));
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-12)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-10));
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-10)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-8));
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-8)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-6));
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-6)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-4));
    a0 = v1 + a0;
    *(volatile u16 *)(unsigned long)(v0 + (-4)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (-2));
    a0 = v1 + a0;
    branch = (t3 != v0); *(volatile u16 *)(unsigned long)(v0 + (-2)) = a0;
    if (branch) goto L_5313c;
    goto L_531a4;
L_531a4:
    ;
    return ((u64)v1 << 32) | v0;
L_531ac:
    branch = (a0 == v1); v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (branch) goto L_531a4;
    goto L_531b4;
L_531b4:
    a0 = a0 + -32768;
    *(volatile u16 *)(unsigned long)(v0 + (0)) = a0;
    ;
    return ((u64)v1 << 32) | v0;
}
