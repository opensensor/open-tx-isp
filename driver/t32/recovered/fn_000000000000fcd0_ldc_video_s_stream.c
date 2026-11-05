/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 ldc_video_s_stream(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_fcd0:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    v1 = *(volatile u32 *)(unsigned long)(a0 + (280));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = v0 << (0x2 & 31);
    branch = (a0 == 0); v0 = v1 + v0;
    if (branch) goto L_fd00;
    goto L_fce8;
L_fce8:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (288));
    v1 = 3;
    branch = (a0 != v1); v1 = 4;
    if (branch) goto L_fd14;
    goto L_fcf8;
L_fcf8:
    *(volatile u32 *)(unsigned long)(v0 + (288)) = v1; goto L_fd14;
L_fd00:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (288));
    v1 = 4;
    branch = (a0 != v1); v1 = 3;
    if (branch) goto L_fd14;
    goto L_fd10;
L_fd10:
    *(volatile u32 *)(unsigned long)(v0 + (288)) = v1;
L_fd14:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
