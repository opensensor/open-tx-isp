/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
u64 tisp_awb_sat_weight(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3d6f4 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
    stack[10] = arg4;
    stack[11] = arg5;
    stack[12] = arg6;
L_3d6f4:
    v0 = hi_3d6f4;
    sp = sp + -24;
    v0 = v0 - hi_3d6f4 + (u32)(unsigned long)ref_t32_data_e16b4;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (0)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (12)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (8)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t9 = *(volatile u32 *)(unsigned long)(sp + (48));
    t2 = 0;
    t1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t5 = 0;
    t7 = 1;
    s2 = *(volatile u32 *)(unsigned long)(t1 + (4));
    t6 = *(volatile u16 *)(unsigned long)(t1 + (3306));
    s3 = *(volatile u16 *)(unsigned long)(t1 + (3190));
    s1 = *(volatile u16 *)(unsigned long)(t1 + (3186));
    s0 = 3;
L_3d74c:
    v0 = (u32)t5 < (u32)(s1);
    branch = (v0 == 0); t3 = t2;
    if (branch) goto L_3d83c;
    goto L_3d758;
L_3d758:
    t8 = 0;
L_3d75c:
    v0 = (u32)t8 < (u32)(s3);
    branch = (v0 == 0); s4 = t3 << (0x2 & 31);
    if (branch) goto L_3d82c;
    goto L_3d768;
L_3d768:
    v0 = a2 + s4;
    s5 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (44));
    branch = (s5 == 0); t4 = v0 + s4;
    if (branch) goto L_3d7dc;
    goto L_3d77c;
L_3d77c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    v0 = v0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = (u32)s2 < (u32)(v0);
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(t4 + (0)) = t7; goto L_3d81c; }
    goto L_3d794;
L_3d794:
    v0 = a1 + s4;
    v1 = *(volatile u32 *)(unsigned long)(t9 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s4 = a3 + s4;
    t0 = *(volatile u32 *)(unsigned long)(t9 + (4));
    v0 = v0 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s4 + (0));
    v1 = v1 * t0;
    v0 = v0 >> (t6 & 31);
    t0 = v1 >> (t6 & 31);
    v1 = (u32)t0 < (u32)(v0);
    a0 = t0;
    if (v1 == 0) a0 = v0;
    v1 = a0;
    s4 = (u32)a0 < (u32)(s5);
    if (s4 == 0) v1 = s5;
    if (v1 != 0) { s4 = *(volatile u16 *)(unsigned long)(t1 + (3438)); goto L_3d7e4; }
    goto L_3d7dc;
L_3d7dc:
    *(volatile u32 *)(unsigned long)(t4 + (0)) = t7; goto L_3d81c;
L_3d7e4:
    branch = (s4 != t7); a0 = v1 << (t6 & 31);
    if (branch) goto L_3d800;
    goto L_3d7ec;
L_3d7ec:
    v1 = (u32)v0 < (u32)(t0);
    if (v1 != 0) v0 = t0;
    s4 = (u32)s5 < (u32)(v0);
    if (s4 == 0) v0 = s5; goto L_3d810;
L_3d800:
    v1 = v0 + t0;
    v0 = v1 + s5;
    if (s0) { lo = v0 / s0; hi = v0 % s0; } else { lo = ~0U; hi = v0; }
    v0 = lo;
L_3d810:
    if (v0) { lo = a0 / v0; hi = a0 % v0; } else { lo = ~0U; hi = a0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = v0;
L_3d81c:
    t3 = t3 + 1;
    t8 = t8 + 1;
    t3 = t3 & 0xffff; goto L_3d75c;
L_3d82c:
    t2 = t2 + 32;
    t5 = t5 + 1;
    t2 = t2 & 0xffff; goto L_3d74c;
L_3d83c:
    s5 = *(volatile u32 *)(unsigned long)(sp + (20));
    s4 = *(volatile u32 *)(unsigned long)(sp + (16));
    s3 = *(volatile u32 *)(unsigned long)(sp + (12));
    s2 = *(volatile u32 *)(unsigned long)(sp + (8));
    s1 = *(volatile u32 *)(unsigned long)(sp + (4));
    s0 = *(volatile u32 *)(unsigned long)(sp + (0));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
