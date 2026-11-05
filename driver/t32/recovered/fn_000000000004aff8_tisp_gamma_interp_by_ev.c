/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1834[] __asm__("t32_data_e1834");
u64 tisp_gamma_interp_by_ev(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4aff8 = ((u32)(unsigned long)ref_t32_data_e1834 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_4aff8:
    v0 = hi_4aff8;
    v0 = v0 - hi_4aff8 + (u32)(unsigned long)ref_t32_data_e1834;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = 1;
    t2 = *(volatile u8 *)(unsigned long)(sp + (16));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    t3 = *(volatile u8 *)(unsigned long)(t1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a2;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = a3;
    v0 = *(volatile u8 *)(unsigned long)(v1 + (86));
    if (v0 == a0) { v0 = *(volatile u8 *)(unsigned long)(v1 + (72)); goto L_4b054; }
    goto L_4b038;
L_4b038:
    branch = (v0 != 0); v0 = -1;
    if (branch) goto L_4b0a4;
    goto L_4b040;
L_4b040:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (87));
    v0 = 2;
    branch = (a0 == v0); v0 = -1;
    if (branch) goto L_4b0a4;
    goto L_4b050;
L_4b050:
    v0 = *(volatile u8 *)(unsigned long)(v1 + (72));
L_4b054:
    branch = (v0 != 0); a0 = 1;
    if (branch) goto L_4b080;
    goto L_4b05c;
L_4b05c:
    if (t2 != 0) { v0 = -1; goto L_4b078; }
    goto L_4b064;
L_4b064:
    a0 = *(volatile u8 *)(unsigned long)(t1 + (0));
    v1 = 255;
    branch = (a0 == v1); v0 = 1;
    if (branch) goto L_4b16c;
    goto L_4b074;
L_4b074:
    v0 = -1;
L_4b078:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = v0; goto L_4b168;
L_4b080:
    if (v0 == a0) { a3 = a3 << (0x16 & 31); goto L_4b0b4; }
    goto L_4b088;
L_4b088:
    branch = (t2 != 0); v1 = *(volatile u8 *)(unsigned long)(v1 + (73));
    if (branch) goto L_4b09c;
    goto L_4b090;
L_4b090:
    a0 = *(volatile u8 *)(unsigned long)(t1 + (0));
    branch = (a0 == v1); v0 = 1;
    if (branch) goto L_4b16c;
    goto L_4b09c;
L_4b09c:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = v1; goto L_4b168;
L_4b0a4:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = v0;
    v0 = t2 ^ 0x1;
    v0 = (u32)0 < (u32)(v0);
    return ((u64)v1 << 32) | v0;
L_4b0b4:
    t0 = v1 + 24;
    a2 = a2 >> (0xa & 31);
    a2 = a3 | a2;
    v0 = t0;
    a0 = 0;
    a3 = 0;
    t5 = 11;
    t4 = 12;
L_4b0d4:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t6 = (u32)a2 < (u32)(a1);
    branch = (t6 == 0); ;
    if (branch) goto L_4b140;
    goto L_4b0e4;
L_4b0e4:
    if (a3 != 0) { v0 = a3 << (0x2 & 31); goto L_4b0f4; }
    goto L_4b0ec;
L_4b0ec:
    a0 = *(volatile u8 *)(unsigned long)(v1 + (74)); goto L_4b154;
L_4b0f4:
    t0 = t0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(t0 + (-4));
    v0 = -1;
    a1 = a1 - a0;
    a2 = a2 - a0;
    branch = (a1 == 0); a0 = a1 - a2;
    if (branch) goto L_4b16c;
    goto L_4b110;
L_4b110:
    v1 = v1 + 74;
    a3 = v1 + a3;
    v0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v1 = a1 >> (0x1 & 31);
    t0 = v0 * a2;
    a2 = t0 + v1;
    v1 = *(volatile u8 *)(unsigned long)(a3 + (-1));
    v0 = v1 * a0;
    a0 = v0 + a2;
    if (a1) { lo = a0 / a1; hi = a0 % a1; } else { lo = ~0U; hi = a0; }
    a0 = lo; goto L_4b154;
L_4b140:
    if (a3 == t5) { a0 = *(volatile u8 *)(unsigned long)(v1 + (85)); goto L_4b148; }
    goto L_4b148;
L_4b148:
    a3 = a3 + 1;
    branch = (a3 != t4); v0 = v0 + 4;
    if (branch) goto L_4b0d4;
    goto L_4b154;
L_4b154:
    if (a0 != t3) { *(volatile u8 *)(unsigned long)(t1 + (0)) = a0; goto L_4b168; }
    goto L_4b15c;
L_4b15c:
    branch = (t2 == 0); v0 = 1;
    if (branch) goto L_4b16c;
    goto L_4b164;
L_4b164:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = a0;
L_4b168:
    v0 = 0;
L_4b16c:
    ;
    return ((u64)v1 << 32) | v0;
}
