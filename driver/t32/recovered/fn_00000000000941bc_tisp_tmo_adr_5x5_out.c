/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_tmo_adr_5x5_out(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_941bc:
    v0 = (s32)a2 < (s32)(a0);
    if (v0 == 0) { a2 = a2 - a0; goto L_941d8; }
    goto L_941c8;
L_941c8:
    a2 = a0 - a2;
    v0 = 8;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; } goto L_941e0;
L_941d8:
    a0 = 8;
    if (a2 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)a2 / (s32)a0; hi = (s32)a2 % (s32)a0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
L_941e0:
    v0 = (s32)a3 < (s32)(a1);
    branch = (v0 == 0); a2 = lo;
    if (branch) goto L_941fc;
    goto L_941ec;
L_941ec:
    a3 = a1 - a3;
    v0 = 8;
    if (a3 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a3 / (s32)v0; hi = (s32)a3 % (s32)v0; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; } goto L_94208;
L_941fc:
    a3 = a3 - a1;
    a1 = 8;
    if (a3 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a3 / (s32)a1; hi = (s32)a3 % (s32)a1; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
L_94208:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = -1;
    v1 = v1 + 60;
    v0 = lo;
    product = (s64)(s32)v0 * (s32)v0; lo = product; hi = product >> 32;
    v0 = 30;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)a2); lo = product; hi = product >> 32;
    a2 = lo;
L_94228:
    a0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    a0 = (s32)a0 < (s32)(a2);
    if (a0 != 0) { v0 = v0 + -1; goto L_94240; }
    goto L_94238;
L_94238:
    v0 = v0 + 1;
    return ((u64)v1 << 32) | v0;
L_94240:
    branch = (v0 != a1); v1 = v1 + -2;
    if (branch) goto L_94228;
    goto L_94248;
L_94248:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
