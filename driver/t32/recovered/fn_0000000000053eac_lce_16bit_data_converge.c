/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 lce_16bit_data_converge(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_53eac:
    t2 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = a0 & 0xff;
    a1 = a1 & 0xff;
    a2 = a2 & 0xff;
    t3 = t2 + 20;
L_53ec0:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u8 *)(unsigned long)(t2 + (0));
    t1 = v1 + a1;
    t0 = (s32)t1 < (s32)(v0);
    branch = (t0 == 0); t0 = v0 + a1;
    if (branch) goto L_53f18;
    goto L_53ed8;
L_53ed8:
    v0 = v0 - v1;
    v0 = v0 * a0;
    t0 = (v0 >> 0x6) & ((1U << 0x1) - 1);
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = t0 + v0;
    t0 = (s32)v0 < (s32)(a1);
    branch = (t0 == 0); t0 = (s32)a2 < (s32)(v0);
    if (branch) goto L_53f00;
    goto L_53ef8;
L_53ef8:
    *(volatile u8 *)(unsigned long)(t2 + (0)) = t1; goto L_53f5c;
L_53f00:
    if (t0 == 0) { v0 = v1 + v0; goto L_53f10; }
    goto L_53f08;
L_53f08:
    v1 = v1 + a2; goto L_53f58;
L_53f10:
    *(volatile u8 *)(unsigned long)(t2 + (0)) = v0; goto L_53f5c;
L_53f18:
    t0 = (s32)t0 < (s32)(v1);
    if (t0 == 0) { t2 = t2 + 1; goto L_53f60; }
    goto L_53f24;
L_53f24:
    v0 = v1 - v0;
    v0 = v0 * a0;
    t0 = (v0 >> 0x6) & ((1U << 0x1) - 1);
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = t0 + v0;
    t0 = (s32)v0 < (s32)(a1);
    branch = (t0 == 0); t0 = (s32)a2 < (s32)(v0);
    if (branch) goto L_53f4c;
    goto L_53f44;
L_53f44:
    v1 = v1 - a1; goto L_53f58;
L_53f4c:
    if (t0 == 0) { v1 = v1 - v0; goto L_53f58; }
    goto L_53f54;
L_53f54:
    v1 = v1 - a2;
L_53f58:
    *(volatile u8 *)(unsigned long)(t2 + (0)) = v1;
L_53f5c:
    t2 = t2 + 1;
L_53f60:
    branch = (t2 != t3); a3 = a3 + 1;
    if (branch) goto L_53ec0;
    goto L_53f68;
L_53f68:
    ;
    return ((u64)v1 << 32) | v0;
}
