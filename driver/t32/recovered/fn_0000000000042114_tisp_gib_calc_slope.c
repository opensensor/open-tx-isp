/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_gib_calc_slope(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_42114:
    v0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a3 = *(volatile u16 *)(unsigned long)(a0 + (2));
    v1 = (u32)v0 < (u32)(a3);
    if (v1 != 0) { t1 = *(volatile u16 *)(unsigned long)(a1 + (0)); goto L_4215c; }
    goto L_42128;
L_42128:
    t0 = *(volatile u16 *)(unsigned long)(a0 + (4));
    v1 = (u32)a3 < (u32)(t0);
    if (v1 != 0) { t1 = *(volatile u16 *)(unsigned long)(a1 + (0)); goto L_4215c; }
    goto L_42138;
L_42138:
    v1 = *(volatile u16 *)(unsigned long)(a0 + (6));
    t0 = (u32)t0 < (u32)(v1);
    if (t0 != 0) { t1 = *(volatile u16 *)(unsigned long)(a1 + (0)); goto L_4215c; }
    goto L_42148;
L_42148:
    t0 = *(volatile u16 *)(unsigned long)(a0 + (8));
    t0 = (u32)v1 < (u32)(t0);
    if (t0 == 0) { *(volatile u16 *)(unsigned long)(a2 + (0)) = 0; goto L_421a0; }
    goto L_42158;
L_42158:
    t1 = *(volatile u16 *)(unsigned long)(a1 + (0));
L_4215c:
    v1 = *(volatile u16 *)(unsigned long)(a1 + (2));
    t0 = (u32)v1 < (u32)(t1);
    if (t0 != 0) { *(volatile u16 *)(unsigned long)(a2 + (0)) = 0; goto L_421a0; }
    goto L_4216c;
L_4216c:
    t0 = *(volatile u16 *)(unsigned long)(a1 + (4));
    t2 = (u32)t0 < (u32)(v1);
    if (t2 != 0) { *(volatile u16 *)(unsigned long)(a2 + (0)) = 0; goto L_421a0; }
    goto L_4217c;
L_4217c:
    t2 = *(volatile u16 *)(unsigned long)(a1 + (6));
    t0 = (u32)t2 < (u32)(t0);
    if (t0 != 0) { *(volatile u16 *)(unsigned long)(a2 + (0)) = 0; goto L_421a0; }
    goto L_4218c;
L_4218c:
    t0 = *(volatile u16 *)(unsigned long)(a1 + (8));
    t0 = (u32)t0 < (u32)(t2);
    if (t0 == 0) { v1 = v1 - t1; goto L_421b4; }
    goto L_4219c;
L_4219c:
    *(volatile u16 *)(unsigned long)(a2 + (0)) = 0;
L_421a0:
    *(volatile u16 *)(unsigned long)(a2 + (2)) = 0;
    *(volatile u16 *)(unsigned long)(a2 + (4)) = 0;
    *(volatile u16 *)(unsigned long)(a2 + (6)) = 0;
    v0 = -1;
    return ((u64)v1 << 32) | v0;
L_421b4:
    v0 = a3 - v0;
    v1 = v1 << (0x8 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = lo;
    v0 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = v0;
    t0 = *(volatile u16 *)(unsigned long)(a1 + (2));
    v1 = *(volatile u16 *)(unsigned long)(a1 + (4));
    a3 = *(volatile u16 *)(unsigned long)(a0 + (4));
    v1 = v1 - t0;
    t0 = *(volatile u16 *)(unsigned long)(a0 + (2));
    v1 = v1 << (0x8 & 31);
    t0 = a3 - t0;
    if (v1 == 0x80000000U && t0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t0) { lo = (s32)v1 / (s32)t0; hi = (s32)v1 % (s32)t0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    t0 = lo;
    t0 = t0 & 0xffff;
    *(volatile u16 *)(unsigned long)(a2 + (2)) = t0;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (6));
    a3 = *(volatile u16 *)(unsigned long)(a1 + (4));
    t1 = *(volatile u16 *)(unsigned long)(a0 + (4));
    a3 = v1 - a3;
    v1 = *(volatile u16 *)(unsigned long)(a0 + (6));
    a3 = a3 << (0x8 & 31);
    v1 = v1 - t1;
    if (a3 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a3 / (s32)v1; hi = (s32)a3 % (s32)v1; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    v1 = lo;
    v1 = v1 & 0xffff;
    *(volatile u16 *)(unsigned long)(a2 + (4)) = v1;
    a3 = *(volatile u16 *)(unsigned long)(a1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (6));
    a1 = a3 - a1;
    a3 = *(volatile u16 *)(unsigned long)(a0 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (6));
    a1 = a1 << (0x8 & 31);
    a0 = a3 - a0;
    if (a1 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)a1 / (s32)a0; hi = (s32)a1 % (s32)a0; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = v0;
    v0 = (u32)v0 < (u32)(4096);
    a0 = lo;
    branch = (v0 != 0); a0 = a0 & 0xffff;
    if (branch) goto L_4225c;
    goto L_42258;
L_42258:
    a1 = 4095;
L_4225c:
    v0 = t0;
    t0 = (u32)t0 < (u32)(4096);
    branch = (t0 != 0); *(volatile u16 *)(unsigned long)(a2 + (0)) = a1;
    if (branch) goto L_42270;
    goto L_4226c;
L_4226c:
    v0 = 4095;
L_42270:
    *(volatile u16 *)(unsigned long)(a2 + (2)) = v0;
    v0 = v1;
    v1 = (u32)v1 < (u32)(4096);
    if (v1 == 0) { v0 = 4095; goto L_42284; }
    goto L_42284;
L_42284:
    *(volatile u16 *)(unsigned long)(a2 + (4)) = v0;
    v0 = a0;
    a0 = (u32)a0 < (u32)(4096);
    if (a0 == 0) { v0 = 4095; goto L_42298; }
    goto L_42298;
L_42298:
    *(volatile u16 *)(unsigned long)(a2 + (6)) = v0;
    v0 = 1;
    return ((u64)v1 << 32) | v0;
}
