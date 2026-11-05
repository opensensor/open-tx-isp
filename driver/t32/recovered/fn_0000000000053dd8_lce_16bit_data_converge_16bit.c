/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 lce_16bit_data_converge_16bit(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_53dd8:
    t0 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = (int8_t)a0;
    a1 = (int8_t)a1;
    a2 = (int8_t)a2;
    t2 = t0 + 20;
L_53dec:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u8 *)(unsigned long)(t0 + (0));
    t3 = v1 + a1;
    t1 = (s32)t3 < (s32)(v0);
    branch = (t1 == 0); t1 = a1 + v0;
    if (branch) goto L_53e4c;
    goto L_53e04;
L_53e04:
    v0 = v0 - v1;
    v0 = v0 & 0xffff;
    v0 = v0 * a0;
    t1 = (v0 >> 0x6) & ((1U << 0x1) - 1);
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = t1 + v0;
    v0 = v0 & 0xffff;
    t1 = (s32)v0 < (s32)(a1);
    branch = (t1 == 0); t1 = (s32)a2 < (s32)(v0);
    if (branch) goto L_53e34;
    goto L_53e2c;
L_53e2c:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = t3; goto L_53e98;
L_53e34:
    if (t1 == 0) { v0 = v1 + v0; goto L_53e44; }
    goto L_53e3c;
L_53e3c:
    v1 = v1 + a2; goto L_53e94;
L_53e44:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v0; goto L_53e98;
L_53e4c:
    t1 = (s32)t1 < (s32)(v1);
    if (t1 == 0) { t0 = t0 + 1; goto L_53e9c; }
    goto L_53e58;
L_53e58:
    v0 = v1 - v0;
    v0 = v0 & 0xffff;
    v0 = v0 * a0;
    t1 = (v0 >> 0x6) & ((1U << 0x1) - 1);
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = t1 + v0;
    v0 = v0 & 0xffff;
    t1 = (s32)v0 < (s32)(a1);
    branch = (t1 == 0); t1 = (s32)a2 < (s32)(v0);
    if (branch) goto L_53e88;
    goto L_53e80;
L_53e80:
    v1 = v1 - a1; goto L_53e94;
L_53e88:
    if (t1 == 0) { v1 = v1 - v0; goto L_53e94; }
    goto L_53e90;
L_53e90:
    v1 = v1 - a2;
L_53e94:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
L_53e98:
    t0 = t0 + 1;
L_53e9c:
    branch = (t0 != t2); a3 = a3 + 1;
    if (branch) goto L_53dec;
    goto L_53ea4;
L_53ea4:
    ;
    return ((u64)v1 << 32) | v0;
}
