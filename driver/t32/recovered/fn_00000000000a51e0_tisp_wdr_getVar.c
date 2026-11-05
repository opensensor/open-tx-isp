/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_wdr_getVar(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_a51e0:
    v0 = a0 + 2;
    t1 = a0 + 512;
    a2 = 0;
    a1 = 1;
    t0 = 2;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
L_a51f8:
    a3 = (u32)v1 < (u32)(200);
    if (a3 == 0) { v0 = v0 + 2; goto L_a5234; }
    goto L_a5204;
L_a5204:
    a3 = *(volatile u16 *)(unsigned long)(v0 + (2));
    a3 = (u32)a3 < (u32)(200);
    if (a3 == 0) { v0 = v0 + 2; goto L_a5234; }
    goto L_a5214;
L_a5214:
    a3 = *(volatile u16 *)(unsigned long)(v0 + (-2));
    a1 = a1 + 1;
    v1 = v1 - a3;
    v1 = v1 + 1;
    if (v1 == 0x80000000U && t0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t0) { lo = (s32)v1 / (s32)t0; hi = (s32)v1 % (s32)t0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    a2 = a2 + v1;
    v0 = v0 + 2;
L_a5234:
    if (t1 != v0) { v1 = *(volatile u16 *)(unsigned long)(v0 + (0)); goto L_a51f8; }
    goto L_a523c;
L_a523c:
    v0 = 10;
    v1 = a2 * v0;
    t0 = (s32)a1 >> (0x1 & 31);
    a0 = a0 + 4;
    a3 = 1;
    v0 = 0;
    t2 = a1 + 1;
    t1 = 2;
    t3 = 10;
    a2 = v1 + t0;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a2 = lo;
L_a526c:
    v1 = (s32)a3 < (s32)(t2);
    branch = (v1 == 0); a3 = a3 + 1;
    if (branch) goto L_a52a8;
    goto L_a5278;
L_a5278:
    t4 = *(volatile u16 *)(unsigned long)(a0 + (-4));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = a0 + 2;
    v1 = v1 - t4;
    v1 = v1 + 1;
    if (v1 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)v1 / (s32)t1; hi = (s32)v1 % (s32)t1; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = v1 * t3;
    v1 = v1 - a2;
    t4 = v1 * v1;
    v0 = t4 + v0; goto L_a526c;
L_a52a8:
    v0 = v0 + t0;
    if (a1) { lo = v0 / a1; hi = v0 % a1; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    return ((u64)v1 << 32) | v0;
}
