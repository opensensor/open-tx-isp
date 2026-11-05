/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_tmo_adr_interp1_short(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
    stack[5] = arg5;
L_9552c:
    t4 = *(volatile s16 *)(unsigned long)(sp + (16));
    t5 = *(volatile s16 *)(unsigned long)(sp + (20));
    t2 = 0x7fffU << 16;
    t3 = 0;
    t2 = t2 | 0xffff;
    t6 = 2;
L_95544:
    v0 = (s32)t3 < (s32)(t5);
    branch = (v0 == 0); v1 = a0 + 2;
    if (branch) goto L_95630;
    goto L_95550;
L_95550:
    t7 = 1;
L_95554:
    v0 = (s32)t7 < (s32)(t4);
    branch = (v0 == 0); ;
    if (branch) goto L_95608;
    goto L_95560;
L_95560:
    t1 = *(volatile s16 *)(unsigned long)(a2 + (0));
    v0 = *(volatile s16 *)(unsigned long)(a0 + (0));
    v0 = (s32)v0 < (s32)(t1);
    if (v0 != 0) { v1 = v1 + 2; goto L_95580; }
    goto L_95574;
L_95574:
    v0 = *(volatile s16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(a3 + (0)) = v0; goto L_95608;
L_95580:
    v0 = *(volatile s16 *)(unsigned long)(v1 + (-2));
    t0 = (s32)t1 < (s32)(v0);
    branch = (t0 == 0); t8 = t7 << (0x1 & 31);
    if (branch) goto L_95600;
    goto L_95590;
L_95590:
    t0 = t7 + t2;
    t0 = t0 << (0x1 & 31);
    v1 = a0 + t0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t8 = a1 + t8;
    t0 = a1 + t0;
    v0 = v0 - v1;
    v0 = (int16_t)v0;
    if (v0 == 0x80000000U && t6 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t6) { lo = (s32)v0 / (s32)t6; hi = (s32)v0 % (s32)t6; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t9 = *(volatile s16 *)(unsigned long)(t0 + (0));
    t0 = *(volatile u16 *)(unsigned long)(t8 + (0));
    t1 = t1 - v1;
    t1 = (int16_t)t1;
    t0 = t0 - t9;
    t0 = (int16_t)t0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)t1); lo = product; hi = product >> 32;
    v1 = lo;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = lo;
    v0 = v0 + t9;
    v0 = (int16_t)v0;
    *(volatile u16 *)(unsigned long)(a3 + (0)) = v0;
    v1 = *(volatile s16 *)(unsigned long)(t8 + (0));
    v0 = (s32)v1 < (s32)(v0);
    if (v0 != 0) { *(volatile u16 *)(unsigned long)(a3 + (0)) = v1; goto L_95608; }
    goto L_955f8;
L_955f8:
    ; goto L_95608;
L_95600:
    t7 = t7 + 1; goto L_95554;
L_95608:
    branch = (t7 != t4); t3 = t3 + 1;
    if (branch) goto L_95624;
    goto L_95610;
L_95610:
    v0 = t4 + t2;
    v0 = v0 << (0x1 & 31);
    v0 = a1 + v0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    *(volatile u16 *)(unsigned long)(a3 + (0)) = v0;
L_95624:
    a3 = a3 + 2;
    a2 = a2 + 2; goto L_95544;
L_95630:
    ;
    return ((u64)v1 << 32) | v0;
}
