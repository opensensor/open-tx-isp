/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_defog_img_filter25(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[120] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[56];
L_5a768:
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
    v1 = (s32)v0 < (s32)(2);
L_5a79c:
    branch = (v1 != 0); a3 = -v0;
    if (branch) goto L_5a7bc;
    goto L_5a7a4;
L_5a7a4:
    v1 = (s32)v0 < (s32)(8);
    branch = (v1 != 0); a3 = -2;
    if (branch) goto L_5a7bc;
    goto L_5a7b0;
L_5a7b0:
    v1 = 9;
    t8 = v1 - v0; goto L_5a7c0;
L_5a7bc:
    t8 = 2;
L_5a7c0:
    v1 = -5;
    s1 = a3 * v1;
    t9 = v0 + a3;
    s0 = a3 << (0x2 & 31);
    s0 = s0 + a3;
    v1 = 0;
    t9 = t9 * t6;
    s1 = s1 - a2;
    s6 = v0 * t6;
L_5a7e4:
    t0 = (s32)v1 < (s32)(2);
    branch = (t0 == 0); t0 = 17;
    if (branch) goto L_5a7fc;
    goto L_5a7f0;
L_5a7f0:
    t4 = -v1;
    t1 = 2; goto L_5a814;
L_5a7fc:
    t2 = (s32)v1 < (s32)(16);
    t0 = t0 - v1;
    t3 = 2;
    if (t2 == 0) t3 = t0;
    t4 = -2;
    t1 = t3;
L_5a814:
    t0 = t9 + v1;
    t0 = t0 + t4;
    t0 = a0 + t0;
    t4 = t4 + s0;
    s2 = a3;
    t5 = 0;
    t2 = 0;
    t7 = 0;
L_5a834:
    t3 = t5 + t4;
    t3 = a2 + t3;
    s7 = s1 - t5;
    s3 = t0;
L_5a844:
    s4 = *(volatile u8 *)(unsigned long)(t3 + (12));
    s8 = *(volatile u8 *)(unsigned long)(s3 + (0));
    t3 = t3 + 1;
    t2 = t2 + s4;
    s5 = s8 * s4;
    s4 = t3 + s7;
    s4 = (s32)t1 < (s32)(s4);
    s3 = s3 + 1;
    branch = (s4 == 0); t7 = s5 + t7;
    if (branch) goto L_5a844;
    goto L_5a86c;
L_5a86c:
    s2 = s2 + 1;
    t3 = (s32)t8 < (s32)(s2);
    t5 = t5 + 5;
    branch = (t3 == 0); t0 = t0 + 18;
    if (branch) goto L_5a834;
    goto L_5a880;
L_5a880:
    t0 = t2 >> (0x1 & 31);
    t7 = t0 + t7;
    if (t2) { lo = t7 / t2; hi = t7 % t2; } else { lo = ~0U; hi = t7; }
    t1 = v1 + s6;
    t1 = sp + t1;
    v1 = v1 + 1;
    t7 = lo;
    branch = (v1 != t6); *(volatile u8 *)(unsigned long)(t1 + (0)) = t7;
    if (branch) goto L_5a7e4;
    goto L_5a8a4;
L_5a8a4:
    v0 = v0 + 1;
    v1 = 10;
    branch = (v0 != v1); v1 = (s32)v0 < (s32)(2);
    if (branch) goto L_5a79c;
    goto L_5a8b4;
L_5a8b4:
    v0 = sp;
    v1 = a1 + 180;
L_5a8bc:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    a1 = a1 + 1;
    v0 = v0 + 1;
    branch = (v1 != a1); *(volatile u8 *)(unsigned long)(a1 + (-1)) = a0;
    if (branch) goto L_5a8bc;
    goto L_5a8d0;
L_5a8d0:
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
