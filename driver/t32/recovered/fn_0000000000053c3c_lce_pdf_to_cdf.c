/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 lce_pdf_to_cdf(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_53c3c:
    a2 = a1;
    v1 = a0;
    a3 = a0 + 32;
    v0 = 0;
    t1 = 32767;
L_53c50:
    t0 = v0 >> (0xf & 31);
    if (t0 != 0) v0 = t1;
    t0 = v0 >> (0x7 & 31);
    *(volatile u8 *)(unsigned long)(a2 + (0)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v1 + 4;
    a2 = a2 + 1;
    branch = (a3 != v1); v0 = v0 + t0;
    if (branch) goto L_53c50;
    goto L_53c74;
L_53c74:
    a2 = 0;
    t1 = 32767;
    t0 = 12;
L_53c80:
    v1 = v0 >> (0xf & 31);
    if (v1 != 0) v0 = t1;
    a3 = v0 >> (0x7 & 31);
    v1 = a1 + a2;
    *(volatile u8 *)(unsigned long)(v1 + (8)) = a3;
    v1 = a2 << (0x3 & 31);
    v1 = v1 + 32;
    v1 = a0 + v1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = a2 + 1;
    v1 = a3 + v1;
    branch = (a2 != t0); v0 = v0 + v1;
    if (branch) goto L_53c80;
    goto L_53cb8;
L_53cb8:
    ;
    return ((u64)v1 << 32) | v0;
}
