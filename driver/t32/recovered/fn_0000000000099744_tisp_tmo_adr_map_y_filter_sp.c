/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c0444[] __asm__("t32_data_c0444");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tisp_tmo_adr_interp1_short[] __asm__("tisp_tmo_adr_interp1_short");
extern unsigned char ref_fix_point_div[] __asm__("fix_point_div");
u64 tisp_tmo_adr_map_y_filter_sp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[166] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_99754 = ((u32)(unsigned long)ref_t32_data_c0444 + 0x8000U) & 0xffff0000U;
    const u32 hi_99748 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_997d0 = ((u32)(unsigned long)ref_tisp_tmo_adr_interp1_short + 0x8000U) & 0xffff0000U;
    const u32 hi_99888 = ((u32)(unsigned long)ref_fix_point_div + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[102];
L_99744:
    sp = sp + -408;
    v0 = hi_99748;
    *(volatile u32 *)(unsigned long)(sp + (384)) = s4;
    s4 = a1;
    a1 = hi_99754;
    *(volatile u32 *)(unsigned long)(sp + (400)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (396)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (392)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (388)) = s5;
    s6 = a0;
    *(volatile u32 *)(unsigned long)(sp + (404)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (380)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (376)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (372)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (368)) = s0;
    s8 = (int16_t)a2;
    a1 = a1 - hi_99754 + (u32)(unsigned long)ref_t32_data_c0444;
    a2 = 66;
    v0 = v0 - hi_99748 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = sp + 152;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_99798;
L_99798:
    s5 = sp + 288;
    v0 = 4095;
    *(volatile u16 *)(unsigned long)(sp + (318)) = v0;
    *(volatile u16 *)(unsigned long)(s6 + (30)) = v0;
    *(volatile u16 *)(unsigned long)(sp + (288)) = 0;
    s7 = s4 + 56;
    v1 = s5;
    v0 = s4;
L_997b8:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + 4;
    v1 = v1 + 2;
    branch = (s7 != v0); *(volatile u16 *)(unsigned long)(v1 + (0)) = a0;
    if (branch) goto L_997b8;
    goto L_997cc;
L_997cc:
    v0 = 33;
    t0 = hi_997d0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = 16;
    a3 = sp + 220;
    a2 = sp + 152;
    a0 = s6;
    s0 = t0 - hi_997d0 + (u32)(unsigned long)ref_tisp_tmo_adr_interp1_short;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    callee = s0; a1 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_997f8;
L_997f8:
    a3 = sp + 220;
    t1 = sp + 152;
    a2 = 0;
    a0 = 0;
    t2 = 0;
    t0 = s0;
    t5 = 10000;
    t3 = 2;
    t4 = 128;
L_9981c:
    v0 = *(volatile s16 *)(unsigned long)(t1 + (2));
    s1 = *(volatile s16 *)(unsigned long)(t1 + (0));
    a3 = a3 + 2;
    t1 = t1 + 2;
    v1 = v0 - s1;
    if (v1 == 0x80000000U && t3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t3) { lo = (s32)v1 / (s32)t3; hi = (s32)v1 % (s32)t3; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    s1 = *(volatile s16 *)(unsigned long)(a3 + (-2));
    v0 = *(volatile s16 *)(unsigned long)(a3 + (0));
    v0 = v0 - s1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)t5); lo = product; hi = product >> 32;
    v0 = sp + 24;
    v0 = v0 + a2;
    a2 = a2 + 4;
    s1 = lo;
    if (s1 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)s1 / (s32)v1; hi = (s32)s1 % (s32)v1; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    s1 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = s1;
    v0 = (s32)s1 >> (0x1f & 31);
    s1 = a0 + s1;
    a0 = (u32)s1 < (u32)(a0);
    v0 = t2 + v0;
    a1 = a0 + v0;
    t2 = a1;
    branch = (a2 != t4); a0 = s1;
    if (branch) goto L_9981c;
    goto L_99880;
L_99880:
    t4 = 0;
    t6 = 3;
    t8 = hi_99888;
    t7 = 10000;
L_99890:
    v0 = (s32)t4 < (s32)(s8);
    branch = (v0 == 0); s3 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_99a1c;
    goto L_9989c;
L_9989c:
    t3 = sp + 24;
    v1 = t3;
    a0 = (s32)s3 >> (0x1f & 31);
L_998a8:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v1 + 4;
    v0 = v0 + a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = v0 + a2;
    v0 = v0 + 1;
    if (v0 == 0x80000000U && t6 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t6) { lo = (s32)v0 / (s32)t6; hi = (s32)v0 % (s32)t6; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    s2 = (s32)v0 >> (0x1f & 31);
    v0 = s3 + v0;
    a2 = (u32)v0 < (u32)(s3);
    a0 = a0 + s2;
    s3 = v0;
    v0 = sp + 144;
    branch = (v0 != v1); a0 = a2 + a0;
    if (branch) goto L_998a8;
    goto L_998f0;
L_998f0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (148));
    t2 = sp + 220;
    t1 = sp + 152;
    s2 = (s32)v0 >> (0x1f & 31);
    s3 = v0 + s3;
    v0 = (u32)s3 < (u32)(v0);
    s2 = s2 + a0;
    s2 = v0 + s2;
    v0 = s2 << (0x1f & 31);
    t5 = s3 >> (0x1 & 31);
    t5 = v0 | t5;
    t9 = s2 >> (0x1 & 31);
L_99920:
    v0 = *(volatile s16 *)(unsigned long)(t1 + (0));
    s0 = *(volatile s16 *)(unsigned long)(t1 + (2));
    *(volatile u32 *)(unsigned long)(sp + (360)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (356)) = t6;
    s0 = s0 - v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s2;
    product = (s64)(s32)a1 * (s32)v0; lo = product; hi = product >> 32;
    v1 = (s32)v0 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (352)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (348)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (344)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (340)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (336)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (332)) = a1;
    *(volatile u32 *)(unsigned long)(sp + (328)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (324)) = t9;
    *(volatile u32 *)(unsigned long)(sp + (320)) = t8;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)s1); lo = product; hi = product >> 32;
    a0 = lo;
    product = (u64)(u32)v0 * (u32)s1; lo = product; hi = product >> 32;
    v0 = lo;
    a2 = v0 + t5;
    a3 = (u32)a2 < (u32)(v0);
    v1 = hi;
    v1 = a0 + v1;
    v0 = v1 + t9;
    a3 = a3 + v0;
    v0 = t8 - hi_99888 + (u32)(unsigned long)ref_fix_point_div;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_999a0;
L_999a0:
    s0 = s0 * v0;
    t7 = *(volatile u32 *)(unsigned long)(sp + (360));
    t3 = *(volatile u32 *)(unsigned long)(sp + (336));
    t2 = *(volatile u32 *)(unsigned long)(sp + (348));
    t8 = *(volatile u32 *)(unsigned long)(sp + (320));
    *(volatile u32 *)(unsigned long)(t3 + (0)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (0));
    t9 = *(volatile u32 *)(unsigned long)(sp + (324));
    t5 = *(volatile u32 *)(unsigned long)(sp + (328));
    a1 = *(volatile u32 *)(unsigned long)(sp + (332));
    t1 = *(volatile u32 *)(unsigned long)(sp + (340));
    t4 = *(volatile u32 *)(unsigned long)(sp + (344));
    t0 = *(volatile u32 *)(unsigned long)(sp + (352));
    s0 = s0 + 5000;
    if (s0 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)s0 / (s32)t7; hi = (s32)s0 % (s32)t7; } else { lo = (s32)s0 < 0 ? 1 : ~0U; hi = s0; }
    s0 = lo;
    s0 = s0 + v0;
    v0 = s0;
    s0 = (int16_t)s0;
    s0 = (s32)s0 < (s32)(4096);
    branch = (s0 != 0); t6 = *(volatile u32 *)(unsigned long)(sp + (356));
    if (branch) goto L_999fc;
    goto L_999f8;
L_999f8:
    v0 = 4095;
L_999fc:
    *(volatile u16 *)(unsigned long)(t2 + (2)) = v0;
    t1 = t1 + 2;
    v0 = sp + 216;
    t3 = t3 + 4;
    branch = (t1 != v0); t2 = t2 + 2;
    if (branch) goto L_99920;
    goto L_99a14;
L_99a14:
    t4 = t4 + 1; goto L_99890;
L_99a1c:
    v0 = 16;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = 33;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a3 = s5;
    a2 = s6;
    a1 = sp + 220;
    callee = t0; a0 = sp + 152;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_99a40;
L_99a40:
    v0 = *(volatile s16 *)(unsigned long)(s5 + (2));
    s4 = s4 + 4;
    s5 = s5 + 2;
    branch = (s7 != s4); *(volatile u32 *)(unsigned long)(s4 + (-4)) = v0;
    if (branch) goto L_99a40;
    goto L_99a54;
L_99a54:
    ra = *(volatile u32 *)(unsigned long)(sp + (404));
    s8 = *(volatile u32 *)(unsigned long)(sp + (400));
    s7 = *(volatile u32 *)(unsigned long)(sp + (396));
    s6 = *(volatile u32 *)(unsigned long)(sp + (392));
    s5 = *(volatile u32 *)(unsigned long)(sp + (388));
    s4 = *(volatile u32 *)(unsigned long)(sp + (384));
    s3 = *(volatile u32 *)(unsigned long)(sp + (380));
    s2 = *(volatile u32 *)(unsigned long)(sp + (376));
    s1 = *(volatile u32 *)(unsigned long)(sp + (372));
    s0 = *(volatile u32 *)(unsigned long)(sp + (368));
    sp = sp + 408;
    return ((u64)v1 << 32) | v0;
}
