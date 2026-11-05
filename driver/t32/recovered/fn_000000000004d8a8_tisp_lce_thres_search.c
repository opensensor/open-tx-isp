/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_lce_thres_search(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_4d8a8:
    t2 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a3 = a0;
    v1 = 0;
    v0 = 0;
    t1 = 32;
L_4d8bc:
    t0 = *(volatile u16 *)(unsigned long)(a3 + (0));
    v1 = v1 + t0;
    v1 = v1 & 0xffff;
    t0 = (u32)v1 < (u32)(t2);
    if (t0 != 0) { v0 = v0 + 1; goto L_4d8e8; }
    goto L_4d8d4;
L_4d8d4:
    a3 = v0 << (0x1 & 31);
    t1 = v0 & 0xff;
    a3 = a0 + a3;
    t2 = 32; goto L_4d90c;
L_4d8e8:
    branch = (v0 != t1); a3 = a3 + 2;
    if (branch) goto L_4d8bc;
    goto L_4d8f0;
L_4d8f0:
    t1 = 8; goto L_4d970;
L_4d8f8:
    t0 = *(volatile u16 *)(unsigned long)(a3 + (0));
    v0 = v0 + 1;
    v1 = v1 + t0;
    branch = (v0 == t2); v1 = v1 & 0xffff;
    if (branch) goto L_4d970;
    goto L_4d90c;
L_4d90c:
    t0 = *(volatile u16 *)(unsigned long)(a1 + (2));
    t0 = (u32)v1 < (u32)(t0);
    branch = (t0 != 0); a3 = a3 + 2;
    if (branch) goto L_4d8f8;
    goto L_4d91c;
L_4d91c:
    t3 = *(volatile u16 *)(unsigned long)(a1 + (4));
    a1 = v0 << (0x1 & 31);
    a0 = a0 + a1;
    t0 = v0 & 0xff;
    a1 = 24;
    t4 = 31;
    t2 = 32; goto L_4d95c;
L_4d93c:
    if (v0 == t4) { a1 = 31; goto L_4d950; }
    goto L_4d944;
L_4d944:
    a3 = *(volatile u16 *)(unsigned long)(a0 + (2));
    v1 = v1 + a3;
    v1 = v1 & 0xffff;
L_4d950:
    v0 = v0 + 1;
    branch = (v0 == t2); a0 = a0 + 2;
    if (branch) goto L_4d978;
    goto L_4d95c;
L_4d95c:
    a3 = (u32)v1 < (u32)(t3);
    branch = (a3 != 0); ;
    if (branch) goto L_4d93c;
    goto L_4d968;
L_4d968:
    a1 = v0 & 0xff; goto L_4d978;
L_4d970:
    t0 = 16;
    a1 = 24;
L_4d978:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = t1;
    *(volatile u8 *)(unsigned long)(a2 + (1)) = t0;
    *(volatile u8 *)(unsigned long)(a2 + (2)) = a1;
    return ((u64)v1 << 32) | v0;
}
