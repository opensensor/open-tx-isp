/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_wdr_degweight_ev(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_a4aa4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = *(volatile u16 *)(unsigned long)(a0 + (8));
    a3 = a3 & 0xffff;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (12));
    t0 = *(volatile u16 *)(unsigned long)(a0 + (4));
    t2 = *(volatile u16 *)(unsigned long)(a0 + (6));
    v0 = (u32)v0 < (u32)(t1);
    branch = (v0 != 0); t4 = 0;
    if (branch) goto L_a4acc;
    goto L_a4ac8;
L_a4ac8:
    t4 = *(volatile u16 *)(unsigned long)(a2 + (0));
L_a4acc:
    t3 = *(volatile u16 *)(unsigned long)(a0 + (0));
    t1 = 1;
    branch = (t3 != t1); v0 = t4;
    if (branch) goto L_a4b88;
    goto L_a4adc;
L_a4adc:
    v1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = (u32)v0 < (u32)(v1);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(a1 + (28)); goto L_a4af8; }
    goto L_a4af0;
L_a4af0:
    v0 = *(volatile u16 *)(unsigned long)(a2 + (0)); goto L_a4b80;
L_a4af8:
    v0 = (u32)v0 < (u32)(v1);
    if (v0 == 0) { t1 = 0; goto L_a4b0c; }
    goto L_a4b04;
L_a4b04:
    v0 = *(volatile u16 *)(unsigned long)(a2 + (14)); goto L_a4b80;
L_a4b0c:
    t6 = 7;
L_a4b10:
    t5 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = (u32)t5 < (u32)(v1);
    branch = (v0 == 0); t3 = t1 + 1;
    if (branch) goto L_a4b70;
    goto L_a4b20;
L_a4b20:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    t7 = (u32)v0 < (u32)(v1);
    if (t7 != 0) { t1 = t3; goto L_a4b74; }
    goto L_a4b30;
L_a4b30:
    t3 = t3 << (0x1 & 31);
    t1 = t1 << (0x1 & 31);
    t1 = a2 + t1;
    a2 = a2 + t3;
    t1 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = v1 - t5;
    v0 = v0 - t5;
    a1 = a1 - t1;
    t3 = a1 * v1;
    a2 = v0 >> (0x1 & 31);
    v1 = t3 + a2;
    if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; }
    v0 = lo;
    v0 = v0 + t1; goto L_a4b80;
L_a4b70:
    t1 = t3;
L_a4b74:
    branch = (t3 != t6); a1 = a1 + 4;
    if (branch) goto L_a4b10;
    goto L_a4b7c;
L_a4b7c:
    v0 = 0;
L_a4b80:
    a1 = (u32)v0 < (u32)(t4);
    if (a1 == 0) v0 = t4;
L_a4b88:
    a0 = *(volatile u16 *)(unsigned long)(a0 + (2));
    v1 = 1;
    branch = (a0 != v1); v1 = (u32)a3 < (u32)(t0);
    if (branch) goto L_a4bd0;
    goto L_a4b98;
L_a4b98:
    branch = (v1 == 0); a0 = 0;
    if (branch) goto L_a4bc8;
    goto L_a4ba0;
L_a4ba0:
    v1 = (u32)a3 < (u32)(t2);
    branch = (v1 != 0); a0 = 32;
    if (branch) goto L_a4bc8;
    goto L_a4bac;
L_a4bac:
    v1 = t0 - t2;
    t0 = t0 - a3;
    a3 = t0 << (0x5 & 31);
    t0 = v1 >> (0x1 & 31);
    t0 = a3 + t0;
    if (v1) { lo = t0 / v1; hi = t0 % v1; } else { lo = ~0U; hi = t0; }
    a0 = lo;
L_a4bc8:
    v1 = (u32)a0 < (u32)(v0);
    if (v1 != 0) v0 = a0;
L_a4bd0:
    ;
    return ((u64)v1 << 32) | v0;
}
