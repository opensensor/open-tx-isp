/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_wdr_paixu(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_a54c0:
    a2 = a2 & 0xff;
    branch = (a2 == 0); a1 = a1 & 0xff;
    if (branch) goto L_a54d8;
    goto L_a54cc;
L_a54cc:
    a2 = a0;
    v0 = 0; goto L_a5560;
L_a54d8:
    a2 = a0;
    v0 = 0;
L_a54e0:
    branch = (a1 == v0); v0 = v0 + 1;
    if (branch) goto L_a5574;
    goto L_a54e8;
L_a54e8:
    v0 = v0 & 0xff;
    v1 = v0;
L_a54f0:
    a3 = (u32)v1 < (u32)(225);
    branch = (a3 == 0); a3 = v1 << (0x1 & 31);
    if (branch) goto L_a5524;
    goto L_a54fc;
L_a54fc:
    a3 = a0 + a3;
    t1 = *(volatile u16 *)(unsigned long)(a3 + (0));
    t0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    t2 = (u32)t0 < (u32)(t1);
    branch = (t2 == 0); v1 = v1 + 1;
    if (branch) goto L_a551c;
    goto L_a5514;
L_a5514:
    *(volatile u16 *)(unsigned long)(a2 + (0)) = t1;
    *(volatile u16 *)(unsigned long)(a3 + (0)) = t0;
L_a551c:
    v1 = v1 & 0xff; goto L_a54f0;
L_a5524:
    a2 = a2 + 2; goto L_a54e0;
L_a552c:
    a3 = a0 + a3;
    t1 = *(volatile u16 *)(unsigned long)(a3 + (0));
    t0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    t2 = (u32)t1 < (u32)(t0);
    branch = (t2 == 0); v1 = v1 + 1;
    if (branch) goto L_a554c;
    goto L_a5544;
L_a5544:
    *(volatile u16 *)(unsigned long)(a2 + (0)) = t1;
    *(volatile u16 *)(unsigned long)(a3 + (0)) = t0;
L_a554c:
    v1 = v1 & 0xff;
L_a5550:
    a3 = (u32)v1 < (u32)(225);
    branch = (a3 != 0); a3 = v1 << (0x1 & 31);
    if (branch) goto L_a552c;
    goto L_a555c;
L_a555c:
    a2 = a2 + 2;
L_a5560:
    branch = (v0 == a1); v0 = v0 + 1;
    if (branch) goto L_a5574;
    goto L_a5568;
L_a5568:
    v0 = v0 & 0xff;
    v1 = v0; goto L_a5550;
L_a5574:
    ;
    return ((u64)v1 << 32) | v0;
}
