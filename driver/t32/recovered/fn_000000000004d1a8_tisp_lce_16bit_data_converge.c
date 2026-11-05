/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_lce_16bit_data_converge(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_4d1a8:
    t0 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = a1 & 0xff;
    a2 = a2 & 0xff;
    a0 = a0 & 0xff;
    t4 = t0 + 20;
    t2 = a1 & 0xffff;
    t3 = a2 & 0xffff;
L_4d1c4:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u8 *)(unsigned long)(t0 + (0));
    t5 = v1 + a1;
    t1 = (s32)t5 < (s32)(v0);
    branch = (t1 == 0); t1 = a1 + v0;
    if (branch) goto L_4d224;
    goto L_4d1dc;
L_4d1dc:
    v0 = v0 - v1;
    v0 = v0 & 0xffff;
    v0 = v0 * a0;
    t1 = (v0 >> 0x6) & ((1U << 0x1) - 1);
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = t1 + v0;
    v0 = v0 & 0xffff;
    t1 = (u32)v0 < (u32)(t2);
    branch = (t1 == 0); t1 = (u32)t3 < (u32)(v0);
    if (branch) goto L_4d20c;
    goto L_4d204;
L_4d204:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = t5; goto L_4d270;
L_4d20c:
    if (t1 == 0) { v0 = v1 + v0; goto L_4d21c; }
    goto L_4d214;
L_4d214:
    v1 = v1 + a2; goto L_4d26c;
L_4d21c:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v0; goto L_4d270;
L_4d224:
    t1 = (s32)t1 < (s32)(v1);
    if (t1 == 0) { t0 = t0 + 1; goto L_4d274; }
    goto L_4d230;
L_4d230:
    v0 = v1 - v0;
    v0 = v0 & 0xffff;
    v0 = v0 * a0;
    t1 = (v0 >> 0x6) & ((1U << 0x1) - 1);
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = t1 + v0;
    v0 = v0 & 0xffff;
    t1 = (u32)v0 < (u32)(t2);
    branch = (t1 == 0); t1 = (u32)t3 < (u32)(v0);
    if (branch) goto L_4d260;
    goto L_4d258;
L_4d258:
    v1 = v1 - a1; goto L_4d26c;
L_4d260:
    if (t1 == 0) { v1 = v1 - v0; goto L_4d26c; }
    goto L_4d268;
L_4d268:
    v1 = v1 - a2;
L_4d26c:
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
L_4d270:
    t0 = t0 + 1;
L_4d274:
    branch = (t0 != t4); a3 = a3 + 1;
    if (branch) goto L_4d1c4;
    goto L_4d27c;
L_4d27c:
    ;
    return ((u64)v1 << 32) | v0;
}
