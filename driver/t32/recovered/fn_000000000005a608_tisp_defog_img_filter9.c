/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_defog_img_filter9(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[120] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[56];
L_5a608:
    sp = sp + -224;
    v0 = 0;
    t6 = 18;
    *(volatile u32 *)(unsigned long)(sp + (220)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (216)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (212)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (208)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (204)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (200)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (196)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (192)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (188)) = s0;
    t0 = (u32)0 < (u32)(v0);
L_5a63c:
    t9 = -t0;
    t0 = v0 - t0;
    t0 = t0 * t6;
    t8 = v0 ^ 0x9;
    t5 = t9 << (0x1 & 31);
    t8 = (u32)0 < (u32)(t8);
    t5 = t5 + t9;
    v1 = 0;
    s5 = v0 * t6;
L_5a660:
    a3 = (u32)0 < (u32)(v1);
    t3 = -a3;
    s2 = t0 + v1;
    s1 = v1 ^ 0x11;
    s2 = s2 - a3;
    s6 = t5 - a3;
    t3 = t3 - a2;
    a3 = a3 - t5;
    t3 = t3 + a3;
    s1 = (u32)0 < (u32)(s1);
    s0 = t9;
    t2 = 0;
    a3 = 0;
    t7 = 0;
L_5a698:
    t4 = 6;
    t1 = s6 + t2;
    s3 = t2 * t4;
    t1 = a2 + t1;
    s7 = t3 - t2;
    t4 = s3 + s2;
    t4 = a0 + t4;
L_5a6b4:
    s3 = *(volatile u8 *)(unsigned long)(t1 + (4));
    s8 = *(volatile u8 *)(unsigned long)(t4 + (0));
    t1 = t1 + 1;
    a3 = a3 + s3;
    s4 = s8 * s3;
    s3 = t1 + s7;
    s3 = (s32)s1 < (s32)(s3);
    t4 = t4 + 1;
    branch = (s3 == 0); t7 = s4 + t7;
    if (branch) goto L_5a6b4;
    goto L_5a6dc;
L_5a6dc:
    s0 = s0 + 1;
    t1 = (s32)t8 < (s32)(s0);
    branch = (t1 == 0); t2 = t2 + 3;
    if (branch) goto L_5a698;
    goto L_5a6ec;
L_5a6ec:
    t1 = a3 >> (0x1 & 31);
    t7 = t1 + t7;
    if (a3) { lo = t7 / a3; hi = t7 % a3; } else { lo = ~0U; hi = t7; }
    t2 = v1 + s5;
    t2 = sp + t2;
    v1 = v1 + 1;
    t7 = lo;
    branch = (v1 != t6); *(volatile u8 *)(unsigned long)(t2 + (0)) = t7;
    if (branch) goto L_5a660;
    goto L_5a710;
L_5a710:
    v0 = v0 + 1;
    v1 = 10;
    if (v0 != v1) { t0 = (u32)0 < (u32)(v0); goto L_5a63c; }
    goto L_5a720;
L_5a720:
    v0 = sp;
    v1 = a1 + 180;
L_5a728:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    a1 = a1 + 1;
    v0 = v0 + 1;
    branch = (v1 != a1); *(volatile u8 *)(unsigned long)(a1 + (-1)) = a0;
    if (branch) goto L_5a728;
    goto L_5a73c;
L_5a73c:
    s8 = *(volatile u32 *)(unsigned long)(sp + (220));
    s7 = *(volatile u32 *)(unsigned long)(sp + (216));
    s6 = *(volatile u32 *)(unsigned long)(sp + (212));
    s5 = *(volatile u32 *)(unsigned long)(sp + (208));
    s4 = *(volatile u32 *)(unsigned long)(sp + (204));
    s3 = *(volatile u32 *)(unsigned long)(sp + (200));
    s2 = *(volatile u32 *)(unsigned long)(sp + (196));
    s1 = *(volatile u32 *)(unsigned long)(sp + (192));
    s0 = *(volatile u32 *)(unsigned long)(sp + (188));
    sp = sp + 224;
    return ((u64)v1 << 32) | v0;
}
