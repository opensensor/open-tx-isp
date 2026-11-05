/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_lsc_ring_itp(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, u32 arg14, u32 arg15)
{
    u32 stack[68] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[4];
    stack[8] = arg4;
    stack[9] = arg5;
    stack[10] = arg6;
    stack[11] = arg7;
    stack[12] = arg8;
    stack[13] = arg9;
    stack[14] = arg10;
    stack[15] = arg11;
    stack[16] = arg12;
    stack[17] = arg13;
    stack[18] = arg14;
    stack[19] = arg15;
L_43c6c:
    sp = sp + -16;
    v1 = *(volatile u8 *)(unsigned long)(sp + (44));
    a1 = a1 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (12)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (8)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s0;
    t7 = *(volatile u32 *)(unsigned long)(sp + (32));
    t8 = *(volatile u32 *)(unsigned long)(sp + (48));
    t5 = *(volatile u32 *)(unsigned long)(sp + (56));
    t9 = *(volatile u32 *)(unsigned long)(sp + (68));
    t6 = *(volatile u32 *)(unsigned long)(sp + (72));
    t4 = *(volatile u32 *)(unsigned long)(sp + (76));
    a3 = a3 & 0xff;
    t0 = *(volatile u8 *)(unsigned long)(sp + (36));
    v0 = *(volatile u8 *)(unsigned long)(sp + (52));
    branch = (a1 == v1); t1 = *(volatile u8 *)(unsigned long)(sp + (60));
    if (branch) goto L_43cd4;
    goto L_43cb0;
L_43cb0:
    t2 = (u32)v1 < (u32)(a1);
    if (t2 == 0) { a1 = v1 - a1; goto L_43cc8; }
    goto L_43cbc;
L_43cbc:
    a1 = a1 - v1;
    t3 = a1 & 0xff; goto L_43cd8;
L_43cc8:
    a1 = a1 & 0xff;
    t3 = 0; goto L_43cdc;
L_43cd4:
    t3 = 0;
L_43cd8:
    a1 = 0;
L_43cdc:
    branch = (a3 == v0); v1 = (u32)v0 < (u32)(a3);
    if (branch) goto L_43d04;
    goto L_43ce4;
L_43ce4:
    if (v1 == 0) { a3 = v0 - a3; goto L_43cf8; }
    goto L_43cec;
L_43cec:
    a3 = a3 - v0;
    t2 = a3 & 0xff; goto L_43d08;
L_43cf8:
    a3 = a3 & 0xff;
    t2 = 0; goto L_43d0c;
L_43d04:
    t2 = 0;
L_43d08:
    a3 = 0;
L_43d0c:
    branch = (t0 == t1); v0 = (u32)t1 < (u32)(t0);
    if (branch) goto L_43d34;
    goto L_43d14;
L_43d14:
    if (v0 == 0) { t1 = t1 - t0; goto L_43d28; }
    goto L_43d1c;
L_43d1c:
    t1 = t0 - t1;
    t0 = t1 & 0xff; goto L_43d38;
L_43d28:
    t1 = t1 & 0xff;
    t0 = 0; goto L_43d3c;
L_43d34:
    t0 = 0;
L_43d38:
    t1 = 0;
L_43d3c:
    v0 = 0;
    s0 = 1154;
L_43d44:
    v1 = a0 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    s2 = (s32)v1 >> (a1 & 31);
    v1 = *(volatile u32 *)(unsigned long)(sp + (64));
    s1 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (40));
    v1 = v1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v1 = (s32)v1 >> (t3 & 31);
    v1 = v1 - s2;
    v1 = v1 * t4;
    v1 = v1 >> (0xc & 31);
    v1 = v1 + s2;
    *(volatile u16 *)(unsigned long)(s1 + (0)) = v1;
    v1 = a2 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    s1 = t9 + v0;
    s2 = (s32)v1 >> (a3 & 31);
    v1 = t8 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v1 = (s32)v1 >> (t2 & 31);
    v1 = v1 - s2;
    v1 = v1 * t4;
    v1 = v1 >> (0xc & 31);
    v1 = v1 + s2;
    *(volatile u16 *)(unsigned long)(s1 + (0)) = v1;
    v1 = t7 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    s1 = t6 + v0;
    s2 = (s32)v1 >> (t1 & 31);
    v1 = t5 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v0 = v0 + 2;
    v1 = (s32)v1 >> (t0 & 31);
    v1 = v1 - s2;
    v1 = v1 * t4;
    v1 = v1 >> (0xc & 31);
    v1 = v1 + s2;
    branch = (v0 != s0); *(volatile u16 *)(unsigned long)(s1 + (0)) = v1;
    if (branch) goto L_43d44;
    goto L_43de4;
L_43de4:
    s2 = *(volatile u32 *)(unsigned long)(sp + (12));
    s1 = *(volatile u32 *)(unsigned long)(sp + (8));
    s0 = *(volatile u32 *)(unsigned long)(sp + (4));
    v0 = 0;
    sp = sp + 16;
    return ((u64)v1 << 32) | v0;
}
