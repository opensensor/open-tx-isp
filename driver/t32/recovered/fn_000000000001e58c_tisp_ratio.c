/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_ratio(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_1e58c:
    a0 = a0 & 0xff;
    v0 = 128;
    if (a0 != v0) { v0 = (int8_t)a0; goto L_1e5a4; }
    goto L_1e59c;
L_1e59c:
    v0 = a1;
    return ((u64)v1 << 32) | v0;
L_1e5a4:
    if ((s32)v0 < 0) { a2 = a2 - a1; goto L_1e5b8; }
    goto L_1e5ac;
L_1e5ac:
    a0 = a0 * a1;
    v0 = a0 >> (0x7 & 31);
    return ((u64)v1 << 32) | v0;
L_1e5b8:
    a0 = a0 + -128;
    a0 = a0 * a2;
    a0 = a0 >> (0x7 & 31);
    v0 = a0 + a1;
    return ((u64)v1 << 32) | v0;
}
