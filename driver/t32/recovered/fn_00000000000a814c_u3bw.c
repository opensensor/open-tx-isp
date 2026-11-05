/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 u3bw(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_a814c:
    t0 = 0xffU << 16;
    t0 = t0 | 0xffff;
    v0 = 0;
    t1 = 0;
L_a815c:
    v1 = (u32)t1 < (u32)(a2);
    branch = (v1 == 0); a3 = a1 + t1;
    if (branch) goto L_a81a8;
    goto L_a8168;
L_a8168:
    v1 = *(volatile u32 *)(unsigned long)(a3 + (0));
    v0 = v1 & t0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
    v1 = v1 >> (0x18 & 31);
    v1 = (v1 & (0x00ffffffU >> (8 * ((a3 + (6)) & 3U)))) | (*(volatile u32 *)(unsigned long)((a3 + (6)) & ~3U) << (24 - 8 * ((a3 + (6)) & 3U)));
    v0 = v1 & t0;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v0;
    v1 = *(volatile u16 *)(unsigned long)(a3 + (6));
    v1 = (v1 & (0x00ffffffU >> (8 * ((a3 + (9)) & 3U)))) | (*(volatile u32 *)(unsigned long)((a3 + (9)) & ~3U) << (24 - 8 * ((a3 + (9)) & 3U)));
    v1 = v1 & t0;
    *(volatile u32 *)(unsigned long)(a0 + (8)) = v1;
    a3 = (a3 & (0xffffff00U << (24 - 8 * ((a3 + (9)) & 3U)))) | (*(volatile u32 *)(unsigned long)((a3 + (9)) & ~3U) >> (8 * ((a3 + (9)) & 3U)));
    *(volatile u32 *)(unsigned long)(a0 + (12)) = a3;
    a0 = a0 + 16;
    t1 = t1 + 12; goto L_a815c;
L_a81a8:
    ;
    return ((u64)v1 << 32) | v0;
}
