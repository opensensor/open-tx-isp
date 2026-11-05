/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_wdr_get_lum_s(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_a52b8:
    t2 = *(volatile u32 *)(unsigned long)(sp + (16));
    t4 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v1 = a0 + 636;
    v0 = 159;
    t0 = 0;
    t3 = -1;
L_a52d0:
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t0 = t0 + t1;
    t0 = t0 & 0xffff;
    t1 = (u32)t0 < (u32)(t4);
    if (t1 != 0) { v0 = v0 + -1; goto L_a52fc; }
    goto L_a52e8;
L_a52e8:
    v1 = v0 << (0x1 & 31);
    v1 = t2 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    *(volatile u16 *)(unsigned long)(a2 + (0)) = v1; goto L_a5304;
L_a52fc:
    branch = (v0 != t3); v1 = v1 + -4;
    if (branch) goto L_a52d0;
    goto L_a5304;
L_a5304:
    t1 = v0 + -1;
    v0 = v0 << (0x2 & 31);
    v0 = a0 + v0;
L_a5310:
    branch = ((s32)t1 < 0); v1 = t1 + -1;
    if (branch) goto L_a5350;
    goto L_a5318;
L_a5318:
    t3 = *(volatile u32 *)(unsigned long)(v0 + (-4));
    t0 = t0 + t3;
    t3 = *(volatile u16 *)(unsigned long)(a1 + (2));
    t0 = t0 & 0xffff;
    t3 = (u32)t0 < (u32)(t3);
    branch = (t3 != 0); v0 = v0 + -4;
    if (branch) goto L_a5348;
    goto L_a5334;
L_a5334:
    v0 = t1 << (0x1 & 31);
    v0 = t2 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    *(volatile u16 *)(unsigned long)(a2 + (2)) = v0; goto L_a5350;
L_a5348:
    t1 = v1; goto L_a5310;
L_a5350:
    t1 = t1 << (0x2 & 31);
    v0 = v1;
    a0 = a0 + t1;
L_a535c:
    if ((s32)v0 < 0) { a1 = *(volatile u8 *)(unsigned long)(a3 + (1)); goto L_a53a0; }
    goto L_a5364;
L_a5364:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (-4));
    t0 = t0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (4));
    t0 = t0 & 0xffff;
    v1 = (u32)t0 < (u32)(v1);
    branch = (v1 != 0); a0 = a0 + -4;
    if (branch) goto L_a5394;
    goto L_a5380;
L_a5380:
    v0 = v0 << (0x1 & 31);
    v0 = t2 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    *(volatile u16 *)(unsigned long)(a2 + (4)) = v0; goto L_a539c;
L_a5394:
    v0 = v0 + -1; goto L_a535c;
L_a539c:
    a1 = *(volatile u8 *)(unsigned long)(a3 + (1));
L_a53a0:
    v1 = *(volatile u16 *)(unsigned long)(a2 + (2));
    a0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    product = (s64)(s32)a1 * (s32)v1; lo = product; hi = product >> 32;
    v1 = *(volatile u8 *)(unsigned long)(a3 + (2));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)v0); lo = product; hi = product >> 32;
    v0 = *(volatile u16 *)(unsigned long)(a2 + (4));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v0); lo = product; hi = product >> 32;
    v1 = 10;
    v0 = lo;
    v0 = v0 + 5;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a2 + (6)) = v0;
    return ((u64)v1 << 32) | v0;
}
