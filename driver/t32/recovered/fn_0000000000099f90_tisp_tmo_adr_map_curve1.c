/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d8324[] __asm__("t32_data_d8324");
extern unsigned char ref_fix_point_div[] __asm__("fix_point_div");
u64 tisp_tmo_adr_map_curve1(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[118] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_99fcc = ((u32)(unsigned long)ref_t32_data_d8324 + 0x8000U) & 0xffff0000U;
    const u32 hi_9a01c = ((u32)(unsigned long)ref_fix_point_div + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[54];
L_99f90:
    v0 = (s32)a1 < (s32)(0);
    if (v0 != 0) a1 = 0;
    v0 = (s32)a2 < (s32)(0);
    sp = sp + -216;
    if (v0 != 0) a2 = 0;
    v0 = 255;
    *(volatile u32 *)(unsigned long)(sp + (180)) = s1;
    s1 = (s32)a2 < (s32)(256);
    if (s1 == 0) a2 = v0;
    *(volatile u32 *)(unsigned long)(sp + (196)) = s5;
    s5 = a2 * a2;
    *(volatile u32 *)(unsigned long)(sp + (200)) = s6;
    v1 = (s32)a1 < (s32)(256);
    if (v1 != 0) v0 = a1;
    a1 = v0 << (0x2 & 31);
    v0 = hi_99fcc;
    v0 = v0 - hi_99fcc + (u32)(unsigned long)ref_t32_data_d8324;
    *(volatile u32 *)(unsigned long)(sp + (208)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (204)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (192)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (188)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (176)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (212)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (184)) = s2;
    v0 = a1 + v0;
    s2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s7 = 256;
    s6 = a2 * s5;
    s8 = s7 - a2;
    s0 = a0;
    s1 = a2;
    s4 = sp + 24;
    s3 = 0;
    t1 = (s32)s8 >> (0x1f & 31);
    t2 = s2 + 256;
    t3 = hi_9a01c;
    t0 = (s32)s6 >> (0x1f & 31);
L_9a024:
    branch = ((s32)s2 >= 0); v0 = s3;
    if (branch) goto L_9a034;
    goto L_9a02c;
L_9a02c:
    v0 = 32;
    v0 = v0 - s3;
L_9a034:
    v0 = v0 << (0x3 & 31);
    a3 = s1 + v0;
    a3 = s7 - a3;
    branch = ((s32)s2 >= 0); t5 = (s32)a3 >> (0x1f & 31);
    if (branch) goto L_9a05c;
    goto L_9a048;
L_9a048:
    v1 = s7 - s2;
    v1 = v1 * v0;
    v0 = v0 - s2;
    a2 = (s32)v1 >> (0x1f & 31); goto L_9a068;
L_9a05c:
    v1 = t2 * v0;
    v0 = s2 + v0;
    a2 = (s32)v1 >> (0x1f & 31);
L_9a068:
    product = (s64)(s32)a3 * (s32)a3; lo = product; hi = product >> 32;
    t4 = (s32)v0 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (172)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (168)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (164)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (160)) = t3;
    a0 = lo;
    a1 = hi;
    product = (s64)(s32)t1 * (s32)a0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s8 * (s32)a1); lo = product; hi = product >> 32;
    t6 = lo;
    product = (u64)(u32)a0 * (u32)s8; lo = product; hi = product >> 32;
    a0 = lo;
    a1 = hi;
    a1 = t6 + a1;
    product = (s64)(s32)t5 * (s32)a0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)a1); lo = product; hi = product >> 32;
    t5 = lo;
    product = (u64)(u32)a0 * (u32)a3; lo = product; hi = product >> 32;
    a1 = hi;
    a1 = t5 + a1;
    a0 = lo;
    lo = a0;
    hi = a1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s5 * (s32)s5); lo = product; hi = product >> 32;
    a0 = lo;
    a1 = hi;
    product = (s64)(s32)a2 * (s32)a0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a1); lo = product; hi = product >> 32;
    a1 = lo;
    product = (u64)(u32)a0 * (u32)v1; lo = product; hi = product >> 32;
    a0 = 0;
    a3 = hi;
    a2 = lo;
    product = (s64)(s32)t0 * (s32)v0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t4 * (s32)s6); lo = product; hi = product >> 32;
    t4 = lo;
    product = (u64)(u32)v0 * (u32)s6; lo = product; hi = product >> 32;
    v1 = hi;
    v1 = t4 + v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = t3 - hi_9a01c + (u32)(unsigned long)ref_fix_point_div;
    callee = v0; a3 = a1 + a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9a120;
L_9a120:
    a0 = v0;
    t3 = *(volatile u32 *)(unsigned long)(sp + (160));
    t0 = *(volatile u32 *)(unsigned long)(sp + (164));
    t1 = *(volatile u32 *)(unsigned long)(sp + (168));
    branch = (v1 != 0); t2 = *(volatile u32 *)(unsigned long)(sp + (172));
    if (branch) goto L_9a14c;
    goto L_9a138;
L_9a138:
    v1 = 0x1U << 16;
    v1 = v1 + 1;
    v0 = (u32)v0 < (u32)(v1);
    branch = (v0 != 0); ;
    if (branch) goto L_9a150;
    goto L_9a14c;
L_9a14c:
    a0 = 0x1U << 16;
L_9a150:
    branch = ((s32)s2 >= 0); v0 = a0;
    if (branch) goto L_9a160;
    goto L_9a158;
L_9a158:
    v1 = 0x1U << 16;
    v0 = v1 - a0;
L_9a160:
    *(volatile u32 *)(unsigned long)(s4 + (0)) = v0;
    s3 = s3 + 1;
    v0 = 33;
    branch = (s3 != v0); s4 = s4 + 4;
    if (branch) goto L_9a024;
    goto L_9a174;
L_9a174:
    a0 = *(volatile u32 *)(unsigned long)(sp + (24));
    v1 = *(volatile u32 *)(unsigned long)(sp + (28));
    a2 = 0xfU << 16;
    v0 = a0 << (0x4 & 31);
    v0 = v0 - a0;
    v0 = v0 + v1;
    a1 = v0 << (0xc & 31);
    a1 = a1 - v0;
    a2 = a2 | 0xfff0;
    if (a1 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)a1 / (s32)a2; hi = (s32)a1 % (s32)a2; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a2 = 0x7U << 16;
    a2 = a2 | 0xfff8;
    ra = *(volatile u32 *)(unsigned long)(sp + (212));
    s8 = *(volatile u32 *)(unsigned long)(sp + (208));
    s7 = *(volatile u32 *)(unsigned long)(sp + (204));
    s6 = *(volatile u32 *)(unsigned long)(sp + (200));
    s5 = *(volatile u32 *)(unsigned long)(sp + (196));
    s4 = *(volatile u32 *)(unsigned long)(sp + (192));
    s3 = *(volatile u32 *)(unsigned long)(sp + (188));
    s2 = *(volatile u32 *)(unsigned long)(sp + (184));
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = a1;
    a1 = a0 << (0x3 & 31);
    v0 = v0 - a1;
    a1 = v0 << (0xc & 31);
    a1 = a1 - v0;
    if (a1 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)a1 / (s32)a2; hi = (s32)a1 % (s32)a2; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a2 = *(volatile u32 *)(unsigned long)(sp + (32));
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = a1;
    a1 = a0 << (0x2 & 31);
    v0 = v0 - a1;
    a1 = v0 << (0xc & 31);
    v0 = a1 - v0;
    a1 = 0x3U << 16;
    a1 = a1 | 0xfffc;
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a0 = v1 + a0;
    a1 = 0x1U << 16;
    a1 = a1 | 0xfffe;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = v0;
    v0 = a0 << (0xc & 31);
    a0 = v0 - a0;
    if (a0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a0 / (s32)a1; hi = (s32)a0 % (s32)a1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = 0xffff;
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a0;
    a0 = v1 << (0xc & 31);
    a0 = a0 - v1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = v1 + a2;
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a0;
    a0 = v1 << (0xc & 31);
    a0 = a0 - v1;
    if (a0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a0 / (s32)a1; hi = (s32)a0 % (s32)a1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = a2 << (0xc & 31);
    v1 = v1 - a2;
    a0 = *(volatile u32 *)(unsigned long)(sp + (36));
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (40));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (48));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (56));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (36)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (72));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (40)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (88));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (44)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (120));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (48)) = v1;
    v1 = a0 << (0xc & 31);
    v1 = v1 - a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (52)) = v0;
    s1 = *(volatile u32 *)(unsigned long)(sp + (180));
    s0 = *(volatile u32 *)(unsigned long)(sp + (176));
    sp = sp + 216;
    return ((u64)v1 << 32) | v0;
}
