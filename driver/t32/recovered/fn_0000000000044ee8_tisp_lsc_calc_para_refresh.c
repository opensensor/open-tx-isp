/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e17e0[] __asm__("t32_data_e17e0");
extern unsigned char ref_t32_data_bf504[] __asm__("t32_data_bf504");
extern unsigned char ref_t32_data_c94f8[] __asm__("t32_data_c94f8");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 tisp_lsc_calc_para_refresh(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_44ef0 = ((u32)(unsigned long)ref_t32_data_e17e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_45024 = ((u32)(unsigned long)ref_t32_data_bf504 + 0x8000U) & 0xffff0000U;
    const u32 hi_45028 = ((u32)(unsigned long)ref_t32_data_c94f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4504c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_44ee8:
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s0;
    s0 = hi_44ef0;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s1;
    s0 = s0 - hi_44ef0 + (u32)(unsigned long)ref_t32_data_e17e0;
    s1 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    v0 = s1 + s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    t7 = *(volatile u32 *)(unsigned long)(v0 + (8));
    t1 = *(volatile u8 *)(unsigned long)(a0 + (67));
    t3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t4 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v1 = *(volatile u32 *)(unsigned long)(a0 + (16));
    t2 = *(volatile u8 *)(unsigned long)(a0 + (66));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (20));
    a2 = -v1;
    v1 = t3 + v1;
    a1 = (s32)v1 < (s32)(a2);
    if (a1 != 0) v1 = a2;
    a3 = -a0;
    a1 = t4 + a0;
    a0 = (s32)a1 < (s32)(a3);
    if (a0 != 0) a1 = a3;
    product = (s64)(s32)a1 * (s32)a1; lo = product; hi = product >> 32;
    a0 = (s32)t2 >> (0x1 & 31);
    a1 = (s32)t3 >> (0x1 & 31);
    a0 = a1 + a0;
    t0 = (s32)t4 >> (0x1 & 31);
    a1 = (s32)t1 >> (0x1 & 31);
    a1 = t0 + a1;
    t0 = 0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v1); lo = product; hi = product >> 32;
    v1 = lo;
    if (a0 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)a0 / (s32)t2; hi = (s32)a0 % (s32)t2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = hi;
    t6 = lo;
    if (a1 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)a1 / (s32)t1; hi = (s32)a1 % (s32)t1; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    t5 = hi;
    branch = ((s32)a0 <= 0); a1 = lo;
    if (branch) goto L_44f9c;
    goto L_44f94;
L_44f94:
    t2 = t2 - a0;
    t0 = t2 & 0xff;
L_44f9c:
    *(volatile u8 *)(unsigned long)(t7 + (15)) = t0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    branch = ((s32)t5 <= 0); t0 = 0;
    if (branch) goto L_44fb4;
    goto L_44fac;
L_44fac:
    t1 = t1 - t5;
    t0 = t1 & 0xff;
L_44fb4:
    product = (s64)(s32)a3 * (s32)a3; lo = product; hi = product >> 32;
    *(volatile u8 *)(unsigned long)(a0 + (16)) = t0;
    t1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    t0 = *(volatile u8 *)(unsigned long)(t1 + (15));
    t0 = (u32)0 < (u32)(t0);
    a0 = t0 + t6;
    *(volatile u8 *)(unsigned long)(t1 + (17)) = a0;
    t0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(t0 + (16));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)a2); lo = product; hi = product >> 32;
    a0 = (u32)0 < (u32)(a0);
    a1 = a0 + a1;
    *(volatile u8 *)(unsigned long)(t0 + (18)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a2;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(a1 + (18));
    a2 = *(volatile u8 *)(unsigned long)(a1 + (17));
    a0 = a0 * a2;
    a0 = a0 << (0x1 & 31);
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    a0 = (s32)a0 < (s32)(1153);
    if (a0 != 0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (12)); goto L_45084; }
    goto L_45020;
L_45020:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = hi_45024;
    a1 = hi_45028;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (67));
    a0 = 1;
    a3 = 1611;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v1;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (66));
    a2 = a2 - hi_45024 + (u32)(unsigned long)ref_t32_data_bf504;
    *(volatile u32 *)(unsigned long)(sp + (20)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = hi_4504c;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t3;
    a1 = a1 - hi_45028 + (u32)(unsigned long)ref_t32_data_c94f8;
    v0 = v0 - hi_4504c + (u32)(unsigned long)ref_isp_printf;
    callee = v0; s0 = s0 + s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_45064;
L_45064:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v0 = 80;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (67)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u8 *)(unsigned long)(v1 + (66)) = v0;
    v0 = -1; goto L_451b8;
L_45084:
    a1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (15));
    *(volatile u8 *)(unsigned long)(a0 + (4)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (16));
    *(volatile u8 *)(unsigned long)(a0 + (5)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (17));
    *(volatile u8 *)(unsigned long)(a0 + (6)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (18));
    *(volatile u8 *)(unsigned long)(a0 + (7)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (19));
    *(volatile u8 *)(unsigned long)(a0 + (8)) = a1;
    a1 = 0x30U << 16;
    a1 = a1 + 1;
    a1 = (s32)v1 < (s32)(a1);
    branch = (a1 != 0); a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    if (branch) goto L_450f8;
    goto L_450f0;
L_450f0:
    v1 = 4; goto L_45110;
L_450f8:
    a1 = 0x18U << 16;
    a1 = a1 + 1;
    a1 = (s32)v1 < (s32)(a1);
    if (a1 != 0) { a1 = 0xcU << 16; goto L_45118; }
    goto L_4510c;
L_4510c:
    v1 = 3;
L_45110:
    *(volatile u8 *)(unsigned long)(a0 + (19)) = v1; goto L_45148;
L_45118:
    a1 = a1 + 1;
    a1 = (s32)v1 < (s32)(a1);
    if (a1 != 0) { a1 = 0x6U << 16; goto L_45130; }
    goto L_45128;
L_45128:
    v1 = 2; goto L_45110;
L_45130:
    a1 = a1 + 1;
    v1 = (s32)v1 < (s32)(a1);
    if (v1 != 0) { *(volatile u8 *)(unsigned long)(a0 + (19)) = 0; goto L_45148; }
    goto L_45140;
L_45140:
    v1 = 1; goto L_45110;
L_45148:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = *(volatile u8 *)(unsigned long)(v1 + (114));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (115));
    a0 = a2 + 1;
    a0 = (s32)a0 < (s32)(v1);
    branch = (a0 != 0); a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    if (branch) goto L_4516c;
    goto L_45164;
L_45164:
    v1 = 1023; goto L_4517c;
L_4516c:
    v1 = v1 - a2;
    a0 = 1024;
    if (a0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a0 / (s32)v1; hi = (s32)a0 % (s32)v1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = lo;
L_4517c:
    *(volatile u16 *)(unsigned long)(a1 + (8)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    a2 = *(volatile u8 *)(unsigned long)(v1 + (63));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (64));
    a0 = a2 + 1;
    a0 = (s32)a0 < (s32)(v1);
    branch = (a0 == 0); v0 = 1023;
    if (branch) goto L_451b0;
    goto L_451a0;
L_451a0:
    v0 = v1 - a2;
    v1 = 1024;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = lo;
L_451b0:
    *(volatile u16 *)(unsigned long)(a1 + (12)) = v0;
    v0 = 0;
L_451b8:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s1 = *(volatile u32 *)(unsigned long)(sp + (40));
    s0 = *(volatile u32 *)(unsigned long)(sp + (36));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
