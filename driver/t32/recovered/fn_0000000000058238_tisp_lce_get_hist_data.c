/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1da8[] __asm__("t32_data_e1da8");
u64 tisp_lce_get_hist_data(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[66] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_58238 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[2];
L_58238:
    v0 = hi_58238;
    sp = sp + -8;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_58238 + (u32)(unsigned long)ref_t32_data_e1da8;
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s0;
    t5 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = 0;
    t4 = 36;
    t6 = 16;
    t7 = 8;
    t8 = 144;
    t9 = 32;
    t3 = a2 * t4;
L_58270:
    a0 = 0;
    t0 = a0 << (0x7 & 31);
L_58278:
    t0 = t0 + a2;
    s0 = a0 + t3;
    t0 = t0 << (0x1 & 31);
    a3 = 0;
    v0 = s0 + a3;
L_5828c:
    v0 = v0 << (0x5 & 31);
    v1 = a3 + t0;
    v0 = a1 + v0;
    v1 = t5 + v1;
    t1 = 0;
L_582a0:
    t2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t1 = t1 + 1;
    v0 = v0 + 4;
    t2 = t2 & 0x1fff;
    *(volatile u16 *)(unsigned long)(v1 + (164)) = t2;
    t2 = *(volatile u16 *)(unsigned long)(v0 + (-2));
    v1 = v1 + 128;
    t2 = t2 & 0x1fff;
    branch = (t1 != t6); *(volatile u16 *)(unsigned long)(v1 + (100)) = t2;
    if (branch) goto L_582a0;
    goto L_582c8;
L_582c8:
    a3 = a3 + 2;
    if (a3 != t7) { v0 = s0 + a3; goto L_5828c; }
    goto L_582d4;
L_582d4:
    a0 = a0 + 8;
    if (a0 != t8) { t0 = a0 << (0x7 & 31); goto L_58278; }
    goto L_582e0;
L_582e0:
    a2 = a2 + 4;
    if (a2 != t9) { t3 = a2 * t4; goto L_58270; }
    goto L_582ec;
L_582ec:
    s0 = *(volatile u32 *)(unsigned long)(sp + (4));
    sp = sp + 8;
    return ((u64)v1 << 32) | v0;
}
