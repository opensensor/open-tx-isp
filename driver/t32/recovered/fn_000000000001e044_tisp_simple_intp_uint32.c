/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_simple_intp_uint32(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_1e044:
    v0 = (u32)a0 < (u32)(10);
    branch = (v0 != 0); a0 = a0 << (0x2 & 31);
    if (branch) goto L_1e058;
    goto L_1e050;
L_1e050:
    v0 = *(volatile u32 *)(unsigned long)(a2 + (40));
    return ((u64)v1 << 32) | v0;
L_1e058:
    a2 = a2 + a0;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = *(volatile u32 *)(unsigned long)(a2 + (4));
    branch = (a3 == v0); v1 = (u32)a3 < (u32)(v0);
    if (branch) goto L_1e0a4;
    goto L_1e06c;
L_1e06c:
    if (v1 == 0) { v0 = a3 - v0; goto L_1e080; }
    goto L_1e074;
L_1e074:
    v0 = v0 - a3;
    a0 = 0; goto L_1e084;
L_1e080:
    a0 = 1;
L_1e084:
    a1 = v0 * a1;
    v1 = a1 >> (0x10 & 31);
    a1 = (a1 >> 0xf) & ((1U << 0x1) - 1);
    a1 = v1 + a1;
    v1 = a3 - a1;
    v0 = v1;
    a3 = a3 + a1;
    if (a0 == 0) v0 = a3;
L_1e0a4:
    ;
    return ((u64)v1 << 32) | v0;
}
