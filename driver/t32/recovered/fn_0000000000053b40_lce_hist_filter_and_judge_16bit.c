/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 lce_hist_filter_and_judge_16bit(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_53b40:
    v1 = 0;
    v0 = 0;
    a1 = 32;
L_53b4c:
    a2 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = v1 + a2;
    a2 = (u32)v1 < (u32)(16385);
    if (a2 != 0) { v0 = v0 + 1; goto L_53b68; }
    goto L_53b60;
L_53b60:
    v0 = v0 & 0xff; goto L_53b74;
L_53b68:
    branch = (v0 != a1); a0 = a0 + 2;
    if (branch) goto L_53b4c;
    goto L_53b70;
L_53b70:
    v0 = 0;
L_53b74:
    *(volatile u8 *)(unsigned long)(a3 + (0)) = v0;
    return ((u64)v1 << 32) | v0;
}
