/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
u64 func_zone_ct_weight(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_20040 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
    stack[5] = arg5;
L_1ff94:
    t0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    v0 = a0;
    t4 = *(volatile u32 *)(unsigned long)(sp + (16));
    v1 = (u32)a0 < (u32)(t0);
    t2 = *(volatile u32 *)(unsigned long)(sp + (20));
    branch = (v1 == 0); t1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    if (branch) goto L_1ffc0;
    goto L_1ffb0;
L_1ffb0:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    v1 = (u32)a0 < (u32)(v0);
    if (v1 != 0) { v1 = *(volatile u32 *)(unsigned long)(a1 + (8)); goto L_1ffc8; }
    goto L_1ffc0;
L_1ffc0:
    *(volatile u32 *)(unsigned long)(t2 + (0)) = t1; goto L_2003c;
L_1ffc8:
    t3 = 1;
    t3 = t3 << (a3 & 31);
    a2 = (u32)v1 < (u32)(v0);
    branch = (a2 != 0); t5 = t3 - t1;
    if (branch) goto L_1fff4;
    goto L_1ffdc;
L_1ffdc:
    a2 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v1 = (u32)v0 < (u32)(a2);
    branch = (v1 != 0); a2 = a2 - a0;
    if (branch) goto L_20018;
    goto L_1ffec;
L_1ffec:
    *(volatile u32 *)(unsigned long)(t2 + (0)) = t3; goto L_2003c;
L_1fff4:
    v1 = t0 - v1;
    product = (s64)(s32)t1 * (s32)v1; lo = product; hi = product >> 32;
    t0 = t0 - v0;
    v0 = v1 >> (0x1 & 31);
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)t5); lo = product; hi = product >> 32;
    t0 = lo;
    v0 = t0 + v0;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; } goto L_20034;
L_20018:
    v1 = t1 * a2;
    t0 = a2 >> (0x1 & 31);
    t1 = v1 + t0;
    v1 = v0 - a0;
    a0 = v1 * t5;
    v0 = a0 + t1;
    if (a2) { lo = v0 / a2; hi = v0 % a2; } else { lo = ~0U; hi = v0; }
L_20034:
    v0 = lo;
    *(volatile u32 *)(unsigned long)(t2 + (0)) = v0;
L_2003c:
    a2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    t9 = hi_20040;
    a1 = t4;
    t9 = t9 - hi_20040 + (u32)(unsigned long)ref_fix_point_mult2_32;
    callee = t9; a0 = a3;
    switch (callee) { case 0x1ff94: goto L_1ff94; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
