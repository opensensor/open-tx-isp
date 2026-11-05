/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_tmo_log2(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_909ac:
    a0 = a0 & 0xffff;
    a1 = a1 & 0xffff;
    v1 = (u32)a0 < (u32)(a1);
    branch = (v1 == 0); v0 = 0;
    if (branch) goto L_909f0;
    goto L_909c0;
L_909c0:
    v1 = 1;
    a3 = 17;
    v1 = v1 << (0x1 & 31);
L_909cc:
    v1 = v1 & 0xffff;
    a2 = a0 + v1;
    a2 = a2 & 0xffff;
    v0 = v0 + 1;
    a2 = (u32)a2 < (u32)(a1);
    branch = (a2 == 0); v0 = v0 & 0xff;
    if (branch) goto L_909f0;
    goto L_909e8;
L_909e8:
    branch = (v0 != a3); v1 = v1 << (0x1 & 31);
    if (branch) goto L_909cc;
    goto L_909f0;
L_909f0:
    ;
    return ((u64)v1 << 32) | v0;
}
