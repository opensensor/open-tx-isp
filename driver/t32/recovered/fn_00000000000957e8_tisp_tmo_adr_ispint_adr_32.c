/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_tmo_adr_ispint_adr_32(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_957e8:
    v0 = a3 << (0x1 & 31);
    v0 = a2 + v0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (-2));
    t1 = a1;
    v1 = 0;
L_957fc:
    t0 = (s32)v1 < (s32)(a3);
    branch = (t0 == 0); t1 = t1 + 4;
    if (branch) goto L_95874;
    goto L_95808;
L_95808:
    t0 = *(volatile u32 *)(unsigned long)(t1 + (-4));
    t2 = (s32)t0 < (s32)(a0);
    if (t2 != 0) { v1 = v1 + 1; goto L_957fc; }
    goto L_95818;
L_95818:
    if (v1 != 0) { v0 = v1 << (0x2 & 31); goto L_95828; }
    goto L_95820;
L_95820:
    v0 = *(volatile s16 *)(unsigned long)(a2 + (0));
    return ((u64)v1 << 32) | v0;
L_95828:
    a1 = a1 + v0;
    a1 = *(volatile u32 *)(unsigned long)(a1 + (-4));
    branch = (t0 != a1); v1 = v1 << (0x1 & 31);
    if (branch) goto L_95844;
    goto L_95838;
L_95838:
    v1 = a2 + v1;
    v0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    return ((u64)v1 << 32) | v0;
L_95844:
    v1 = a2 + v1;
    a2 = *(volatile s16 *)(unsigned long)(v1 + (-2));
    v1 = *(volatile s16 *)(unsigned long)(v1 + (0));
    a0 = a0 - a1;
    v0 = t0 - a1;
    v1 = v1 - a2;
    a3 = v1 * a0;
    a1 = (s32)v0 >> (0x1 & 31);
    a0 = a3 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = lo;
    v0 = v0 + a2;
L_95874:
    ;
    return ((u64)v1 << 32) | v0;
}
