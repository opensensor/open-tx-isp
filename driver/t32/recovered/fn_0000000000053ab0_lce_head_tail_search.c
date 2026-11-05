/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 lce_head_tail_search(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_53ab0:
    a1 = a1 & 0xff;
    a2 = a2 & 0xff;
    a1 = a1 << (0x6 & 31);
    a2 = a2 << (0x6 & 31);
    v1 = a0;
    t0 = 0;
    v0 = 0;
    t1 = 32;
L_53ad0:
    t2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t0 = t0 + t2;
    t2 = (u32)a1 < (u32)(t0);
    if (t2 == 0) { v0 = v0 + 1; goto L_53aec; }
    goto L_53ae4;
L_53ae4:
    v0 = v0 & 0xff; goto L_53af8;
L_53aec:
    branch = (v0 != t1); v1 = v1 + 4;
    if (branch) goto L_53ad0;
    goto L_53af4;
L_53af4:
    v0 = 0;
L_53af8:
    a0 = a0 + 124;
    a1 = 0;
    v1 = 31;
L_53b04:
    t0 = (s32)v1 < (s32)(v0);
    if (t0 != 0) { v1 = 31; goto L_53b34; }
    goto L_53b10;
L_53b10:
    t0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = a1 + t0;
    t0 = (u32)a2 < (u32)(a1);
    branch = (t0 == 0); a0 = a0 + -4;
    if (branch) goto L_53b2c;
    goto L_53b24;
L_53b24:
    v1 = v1 & 0xff; goto L_53b34;
L_53b2c:
    v1 = v1 + -1; goto L_53b04;
L_53b34:
    *(volatile u32 *)(unsigned long)(a3 + (0)) = v0;
    *(volatile u32 *)(unsigned long)(a3 + (4)) = v1;
    return ((u64)v1 << 32) | v0;
}
