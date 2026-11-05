/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_fix_point_div[] __asm__("fix_point_div");
u64 tisp_tmo_adr_map_y_filter(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[124] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_99b6c = ((u32)(unsigned long)ref_fix_point_div + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[60];
L_99a84:
    sp = sp + -240;
    v0 = 4095;
    *(volatile u32 *)(unsigned long)(sp + (224)) = s6;
    s6 = a0 + 2;
    *(volatile u32 *)(unsigned long)(sp + (236)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (232)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (228)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (220)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (216)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (212)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (208)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (204)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (200)) = s0;
    t6 = (int16_t)a2;
    t7 = (int16_t)a3;
    *(volatile u16 *)(unsigned long)(a0 + (30)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (84)) = v0;
    t1 = a1;
    t2 = sp + 88;
    t0 = s6;
    a0 = sp + 24;
    a2 = 0;
    t9 = 0;
    a3 = 1;
    t8 = 15;
    t5 = 10000;
    t3 = 2;
    t4 = 16;
L_99af8:
    if (a3 == t8) { v0 = *(volatile s16 *)(unsigned long)(t0 + (0)); goto L_99b0c; }
    goto L_99b00;
L_99b00:
    v0 = *(volatile u32 *)(unsigned long)(t1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(t0 + (0));
L_99b0c:
    s0 = *(volatile s16 *)(unsigned long)(t0 + (-2));
    a3 = a3 + 1;
    a0 = a0 + 4;
    v1 = v0 - s0;
    if (v1 == 0x80000000U && t3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t3) { lo = (s32)v1 / (s32)t3; hi = (s32)v1 % (s32)t3; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    s0 = *(volatile u32 *)(unsigned long)(a0 + (-4));
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t0 = t0 + 2;
    t2 = t2 + 4;
    v0 = v0 - s0;
    t1 = t1 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)t5); lo = product; hi = product >> 32;
    s0 = lo;
    if (s0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)s0 / (s32)v1; hi = (s32)s0 % (s32)v1; } else { lo = (s32)s0 < 0 ? 1 : ~0U; hi = s0; }
    s0 = lo;
    *(volatile u32 *)(unsigned long)(t2 + (-4)) = s0;
    v0 = (s32)s0 >> (0x1f & 31);
    s0 = a2 + s0;
    s4 = (u32)s0 < (u32)(a2);
    v0 = t9 + v0;
    s4 = s4 + v0;
    a2 = s0;
    branch = (a3 != t4); t9 = s4;
    if (branch) goto L_99af8;
    goto L_99b6c;
L_99b6c:
    v0 = hi_99b6c;
    t1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (152)) = v0;
    t2 = 4095;
    t3 = 10000;
L_99b80:
    v0 = (s32)t1 < (s32)(t6);
    branch = (v0 == 0); s3 = *(volatile u32 *)(unsigned long)(sp + (88));
    if (branch) goto L_99d48;
    goto L_99b8c;
L_99b8c:
    a0 = sp + 88;
    s2 = (s32)s3 >> (0x1f & 31);
L_99b94:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (4));
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 + 4;
    v0 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (4));
    v0 = v0 + v1;
    v0 = v0 + 1;
    v1 = 3;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
    v1 = (s32)v0 >> (0x1f & 31);
    v0 = s3 + v0;
    a2 = (u32)v0 < (u32)(s3);
    s2 = s2 + v1;
    s3 = v0;
    v0 = sp + 140;
    branch = (a0 != v0); s2 = a2 + s2;
    if (branch) goto L_99b94;
    goto L_99be0;
L_99be0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (144));
    s7 = sp + 24;
    s5 = sp + 88;
    v1 = (s32)v0 >> (0x1f & 31);
    s3 = v0 + s3;
    v0 = (u32)s3 < (u32)(v0);
    s2 = v1 + s2;
    s2 = v0 + s2;
    v0 = s2 << (0x1f & 31);
    t4 = s3 >> (0x1 & 31);
    t4 = v0 | t4;
    t9 = s2 >> (0x1 & 31);
    t0 = s6;
    s8 = 1;
    t5 = 2;
    t8 = 16;
L_99c20:
    v0 = *(volatile s16 *)(unsigned long)(t0 + (-2));
    s1 = *(volatile s16 *)(unsigned long)(t0 + (0));
    v1 = (s32)t7 < (s32)(s8);
    branch = (v1 == 0); s1 = s1 - v0;
    if (branch) goto L_99c5c;
    goto L_99c34;
L_99c34:
    a0 = t2 - v0;
    if (a0 == 0x80000000U && t5 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t5) { lo = (s32)a0 / (s32)t5; hi = (s32)a0 % (s32)t5; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = *(volatile u32 *)(unsigned long)(s7 + (0));
    v1 = t2 - v1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)t3); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s5 + (0)) = v0; goto L_99d04;
L_99c5c:
    v0 = *(volatile u32 *)(unsigned long)(s5 + (0));
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s2;
    product = (s64)(s32)s4 * (s32)v0; lo = product; hi = product >> 32;
    v1 = (s32)v0 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (196)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (192)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (188)) = t8;
    *(volatile u32 *)(unsigned long)(sp + (184)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (180)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (176)) = t6;
    *(volatile u32 *)(unsigned long)(sp + (172)) = a1;
    *(volatile u32 *)(unsigned long)(sp + (168)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (164)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (160)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (156)) = t9;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)s0); lo = product; hi = product >> 32;
    a0 = lo;
    product = (u64)(u32)v0 * (u32)s0; lo = product; hi = product >> 32;
    v0 = lo;
    a2 = v0 + t4;
    a3 = (u32)a2 < (u32)(v0);
    v1 = hi;
    v1 = a0 + v1;
    v0 = v1 + t9;
    a3 = a3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (152));
    v0 = v0 - hi_99b6c + (u32)(unsigned long)ref_fix_point_div;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_99cd4;
L_99cd4:
    t3 = *(volatile u32 *)(unsigned long)(sp + (196));
    t2 = *(volatile u32 *)(unsigned long)(sp + (192));
    t8 = *(volatile u32 *)(unsigned long)(sp + (188));
    t5 = *(volatile u32 *)(unsigned long)(sp + (184));
    t7 = *(volatile u32 *)(unsigned long)(sp + (180));
    t6 = *(volatile u32 *)(unsigned long)(sp + (176));
    a1 = *(volatile u32 *)(unsigned long)(sp + (172));
    t0 = *(volatile u32 *)(unsigned long)(sp + (168));
    t1 = *(volatile u32 *)(unsigned long)(sp + (164));
    t4 = *(volatile u32 *)(unsigned long)(sp + (160));
    t9 = *(volatile u32 *)(unsigned long)(sp + (156));
    *(volatile u32 *)(unsigned long)(s5 + (0)) = v0;
L_99d04:
    v0 = *(volatile u32 *)(unsigned long)(s5 + (0));
    s8 = s8 + 1;
    t0 = t0 + 2;
    s1 = s1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s7 + (0));
    s5 = s5 + 4;
    s7 = s7 + 4;
    s1 = s1 + 5000;
    if (s1 == 0x80000000U && t3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t3) { lo = (s32)s1 / (s32)t3; hi = (s32)s1 % (s32)t3; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    s1 = lo;
    s1 = s1 + v0;
    v0 = (s32)s1 < (s32)(4096);
    if (v0 == 0) s1 = t2;
    branch = (s8 != t8); *(volatile u32 *)(unsigned long)(s7 + (0)) = s1;
    if (branch) goto L_99c20;
    goto L_99d40;
L_99d40:
    t1 = t1 + 1; goto L_99b80;
L_99d48:
    v0 = 0;
    v1 = 56;
L_99d50:
    a2 = sp + 24;
    a2 = a2 + v0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (4));
    a0 = a1 + v0;
    v0 = v0 + 4;
    branch = (v0 != v1); *(volatile u32 *)(unsigned long)(a0 + (0)) = a2;
    if (branch) goto L_99d50;
    goto L_99d6c;
L_99d6c:
    ra = *(volatile u32 *)(unsigned long)(sp + (236));
    s8 = *(volatile u32 *)(unsigned long)(sp + (232));
    s7 = *(volatile u32 *)(unsigned long)(sp + (228));
    s6 = *(volatile u32 *)(unsigned long)(sp + (224));
    s5 = *(volatile u32 *)(unsigned long)(sp + (220));
    s4 = *(volatile u32 *)(unsigned long)(sp + (216));
    s3 = *(volatile u32 *)(unsigned long)(sp + (212));
    s2 = *(volatile u32 *)(unsigned long)(sp + (208));
    s1 = *(volatile u32 *)(unsigned long)(sp + (204));
    s0 = *(volatile u32 *)(unsigned long)(sp + (200));
    sp = sp + 240;
    return ((u64)v1 << 32) | v0;
}
