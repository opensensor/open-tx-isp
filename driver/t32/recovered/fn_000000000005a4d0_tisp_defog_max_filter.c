/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_defog_max_filter(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[116] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[52];
L_5a4d0:
    sp = sp + -208;
    v0 = 0;
    t8 = 9;
    *(volatile u32 *)(unsigned long)(sp + (204)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (200)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (196)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (192)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (188)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (184)) = s0;
    t2 = 18;
    t9 = 17;
    t7 = 10;
L_5a500:
    branch = (v0 == 0); t3 = v0 + -1;
    if (branch) goto L_5a518;
    goto L_5a508;
L_5a508:
    branch = (v0 != t8); t6 = 9;
    if (branch) goto L_5a51c;
    goto L_5a510;
L_5a510:
    s1 = t3 * t2; goto L_5a524;
L_5a518:
    t3 = 0;
L_5a51c:
    t6 = v0 + 1;
    s1 = t3 * t2;
L_5a524:
    v1 = 0;
    s0 = v0 * t2;
L_5a52c:
    branch = (v1 == 0); a2 = v1 + -1;
    if (branch) goto L_5a544;
    goto L_5a534;
L_5a534:
    branch = (v1 != t9); s3 = 17;
    if (branch) goto L_5a548;
    goto L_5a53c;
L_5a53c:
    s2 = s1 + a2; goto L_5a550;
L_5a544:
    a2 = 0;
L_5a548:
    s3 = v1 + 1;
    s2 = s1 + a2;
L_5a550:
    a2 = a2 - a0;
    t4 = t3;
    t1 = 0;
    t0 = 0;
    a3 = a2 - s2;
L_5a564:
    a2 = (s32)t6 < (s32)(t4);
    branch = (a2 != 0); a2 = s2 + t1;
    if (branch) goto L_5a5b0;
    goto L_5a570;
L_5a570:
    a2 = a0 + a2;
    s5 = a3 - t1;
L_5a578:
    t5 = s5 + a2;
    t5 = (s32)s3 < (s32)(t5);
    if (t5 != 0) { t4 = t4 + 1; goto L_5a5a8; }
    goto L_5a588;
L_5a588:
    t5 = *(volatile u8 *)(unsigned long)(a2 + (0));
    s4 = t5 & 0xff;
    s4 = (u32)s4 < (u32)(t0);
    if (s4 != 0) { t5 = t0; goto L_5a59c; }
    goto L_5a59c;
L_5a59c:
    t0 = t5 & 0xff;
    a2 = a2 + 1; goto L_5a578;
L_5a5a8:
    t1 = t1 + 18; goto L_5a564;
L_5a5b0:
    a2 = v1 + s0;
    a2 = sp + a2;
    v1 = v1 + 1;
    branch = (v1 != t2); *(volatile u8 *)(unsigned long)(a2 + (0)) = t0;
    if (branch) goto L_5a52c;
    goto L_5a5c4;
L_5a5c4:
    v0 = v0 + 1;
    branch = (v0 != t7); v1 = a1 + 180;
    if (branch) goto L_5a500;
    goto L_5a5d0;
L_5a5d0:
    v0 = sp;
L_5a5d4:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    a1 = a1 + 1;
    v0 = v0 + 1;
    branch = (a1 != v1); *(volatile u8 *)(unsigned long)(a1 + (-1)) = a0;
    if (branch) goto L_5a5d4;
    goto L_5a5e8;
L_5a5e8:
    s5 = *(volatile u32 *)(unsigned long)(sp + (204));
    s4 = *(volatile u32 *)(unsigned long)(sp + (200));
    s3 = *(volatile u32 *)(unsigned long)(sp + (196));
    s2 = *(volatile u32 *)(unsigned long)(sp + (192));
    s1 = *(volatile u32 *)(unsigned long)(sp + (188));
    s0 = *(volatile u32 *)(unsigned long)(sp + (184));
    sp = sp + 208;
    return ((u64)v1 << 32) | v0;
}
