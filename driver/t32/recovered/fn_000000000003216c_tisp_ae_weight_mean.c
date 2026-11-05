/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e15d8[] __asm__("t32_data_e15d8");
extern unsigned char ref_tisp_ae_fliker_detect[] __asm__("tisp_ae_fliker_detect");
extern unsigned char ref_t32_data_e151c[] __asm__("t32_data_e151c");
extern unsigned char ref_t32_data_e1518[] __asm__("t32_data_e1518");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_t32_data_e1524[] __asm__("t32_data_e1524");
extern unsigned char ref_t32_data_e1520[] __asm__("t32_data_e1520");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
u64 tisp_ae_weight_mean(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[102] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3217c = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_321c4 = ((u32)(unsigned long)ref_t32_data_e15d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_3245c = ((u32)(unsigned long)ref_t32_data_e15d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_3246c = ((u32)(unsigned long)ref_tisp_ae_fliker_detect + 0x8000U) & 0xffff0000U;
    const u32 hi_32498 = ((u32)(unsigned long)ref_t32_data_e151c + 0x8000U) & 0xffff0000U;
    const u32 hi_3249c = ((u32)(unsigned long)ref_t32_data_e1518 + 0x8000U) & 0xffff0000U;
    const u32 hi_324b8 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_324fc = ((u32)(unsigned long)ref_t32_data_e1524 + 0x8000U) & 0xffff0000U;
    const u32 hi_3250c = ((u32)(unsigned long)ref_t32_data_e1520 + 0x8000U) & 0xffff0000U;
    const u32 hi_32590 = ((u32)(unsigned long)ref_t32_data_e151c + 0x8000U) & 0xffff0000U;
    const u32 hi_32618 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_326c0 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[38];
    stack[42] = arg4;
    stack[43] = arg5;
L_3216c:
    sp = sp + -152;
    v0 = *(volatile u16 *)(unsigned long)(sp + (168));
    *(volatile u32 *)(unsigned long)(sp + (136)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s3;
    s6 = hi_3217c;
    s3 = a0 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (96)) = v0;
    s6 = s6 - hi_3217c + (u32)(unsigned long)ref_t32_data_e15a8;
    v0 = s3 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (144)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (132)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (120)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (116)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (112)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (148)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (140)) = s7;
    v1 = v0 + s6;
    t4 = *(volatile u32 *)(unsigned long)(v1 + (0));
    s1 = a1;
    *(volatile u32 *)(unsigned long)(sp + (160)) = a2;
    v1 = *(volatile u32 *)(unsigned long)(t4 + (0));
    t2 = hi_321c4;
    a3 = a3 & 0xffff;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (2774));
    s7 = *(volatile u16 *)(unsigned long)(v1 + (2944));
    t2 = t2 - hi_321c4 + (u32)(unsigned long)ref_t32_data_e15d8;
    *(volatile u32 *)(unsigned long)(sp + (28)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (2770));
    t6 = 0;
    t8 = 0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (2778));
    s5 = 0;
    a2 = 0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = a0;
    a0 = v1 + 3062;
    *(volatile u32 *)(unsigned long)(sp + (40)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(t4 + (4));
    v1 = v1 + 1270;
    s0 = 0;
    a1 = a0 + 2048;
    *(volatile u32 *)(unsigned long)(sp + (44)) = a1;
    a1 = a0 + 2948;
    *(volatile u32 *)(unsigned long)(sp + (48)) = a1;
    a1 = a0 + 3848;
    *(volatile u32 *)(unsigned long)(sp + (52)) = a1;
    a1 = a0 + 4748;
    *(volatile u32 *)(unsigned long)(sp + (56)) = a1;
    a1 = a0 + 5648;
    *(volatile u32 *)(unsigned long)(sp + (60)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (414));
    s4 = a0 + 7648;
    s2 = 0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (466));
    *(volatile u32 *)(unsigned long)(sp + (80)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (28));
    *(volatile u32 *)(unsigned long)(sp + (68)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (11796));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (11826));
    v1 = v1 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (72)) = a1;
    *(volatile u32 *)(unsigned long)(sp + (76)) = a0;
    *(volatile u32 *)(unsigned long)(sp + (92)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (24)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    s8 = 0;
    t5 = 0;
    *(volatile u32 *)(unsigned long)(sp + (100)) = s6;
    t2 = t2 + v0;
    a3 = a3 + -1;
L_32290:
    v0 = *(volatile u32 *)(unsigned long)(sp + (32));
    v0 = (u32)a2 < (u32)(v0);
    branch = (v0 == 0); v0 = a2 << (0x4 & 31);
    if (branch) goto L_32448;
    goto L_322a0;
L_322a0:
    v0 = v0 - a2;
    *(volatile u32 *)(unsigned long)(sp + (88)) = v0;
    v0 = t6 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (84)) = v0;
    v0 = a2 + 5896;
    v0 = v0 << (0x1 & 31);
    t1 = 0;
    t0 = 0;
    *(volatile u32 *)(unsigned long)(sp + (104)) = v0;
L_322c4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (92));
    branch = (t1 == v0); v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    if (branch) goto L_32434;
    goto L_322d0;
L_322d0:
    v1 = *(volatile u32 *)(unsigned long)(sp + (104));
    a0 = t0 + 5912;
    s6 = t0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    a0 = a0 << (0x1 & 31);
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    v0 = v0 + s6;
    t7 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(t4 + (4));
    v1 = v0 + v1;
    v0 = v0 + a0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (2));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (4));
    a0 = t8 + t1;
    ra = ra + a0;
    v1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (56));
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    v0 = v0 + a0;
    t3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (60));
    v0 = v0 + a0;
    t9 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (44));
    v0 = v0 + a0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (48));
    v0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = s4 + a0;
    v0 = a1 + v0;
    v0 = v0 + ra;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    ra = lo;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = ra;
    ra = *(volatile u32 *)(unsigned long)(t2 + (0));
    a0 = t0 + t6;
    a0 = a0 + 2712;
    a0 = a0 << (0x2 & 31);
    a0 = ra + a0;
    ra = *(volatile u32 *)(unsigned long)(sp + (84));
    t0 = t0 + 1;
    ra = ra + t1;
    ra = s4 + ra;
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    t1 = t1 + 4;
    ra = ra << (0x4 & 31);
    *(volatile u32 *)(unsigned long)(a0 + (8)) = ra;
    a0 = *(volatile u32 *)(unsigned long)(sp + (80));
    ra = *(volatile u32 *)(unsigned long)(sp + (16));
    s6 = a0 + s6;
    a0 = *(volatile u8 *)(unsigned long)(s6 + (0));
    lo = ra;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)v0); lo = product; hi = product >> 32;
    ra = lo;
    *(volatile u32 *)(unsigned long)(sp + (16)) = ra;
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    lo = ra;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a0); lo = product; hi = product >> 32;
    ra = lo;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    ra = 8;
    a0 = ra - a0;
    ra = a0 * v0;
    s5 = ra + s5;
    ra = *(volatile u32 *)(unsigned long)(sp + (24));
    lo = ra;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a0); lo = product; hi = product >> 32;
    a0 = lo;
    *(volatile u32 *)(unsigned long)(sp + (24)) = a0;
    a0 = t3 * a3;
    ra = t7 * t9;
    if (s7) { lo = a0 / s7; hi = a0 % s7; } else { lo = ~0U; hi = a0; }
    t5 = t5 + ra;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t7 * (s32)t3); lo = product; hi = product >> 32;
    t3 = t3 + t9;
    t3 = v1 - t3;
    a0 = lo;
    s6 = ra + a0;
    s6 = s6 + s0;
    a1 = a1 * a3;
    s8 = s8 + a0;
    if (s7) { lo = a1 / s7; hi = a1 % s7; } else { lo = ~0U; hi = a1; }
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t7 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    s2 = s2 + v0;
    v0 = t3 * t7;
    s0 = v0 + s6; goto L_322c4;
L_32434:
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    a2 = a2 + 1;
    t8 = t8 + 60;
    t6 = t6 + v0; goto L_32290;
L_32448:
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1748));
    v0 = 1;
    branch = (v1 != v0); s6 = s3 << (0x2 & 31);
    if (branch) goto L_3248c;
    goto L_3245c;
L_3245c:
    v0 = hi_3245c;
    v0 = v0 - hi_3245c + (u32)(unsigned long)ref_t32_data_e15d8;
    v0 = v0 + s6;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_3246c;
    a0 = s3;
    a1 = a1 + 10856;
    v0 = v0 - hi_3246c + (u32)(unsigned long)ref_tisp_ae_fliker_detect;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (40)) = t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_32484;
L_32484:
    t5 = *(volatile u32 *)(unsigned long)(sp + (40));
    v0 = 1;
L_3248c:
    if (s0 == 0) s0 = v0;
    if (s0) { lo = s2 / s0; hi = s2 % s0; } else { lo = ~0U; hi = s2; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (20));
    t0 = hi_32498;
    t1 = hi_3249c;
    t0 = t0 - hi_32498 + (u32)(unsigned long)ref_t32_data_e151c;
    t1 = t1 - hi_3249c + (u32)(unsigned long)ref_t32_data_e1518;
    t0 = t0 + s3;
    t1 = t1 + s3;
    s2 = lo;
    if (s2 == 0) s2 = v0;
    v0 = hi_324b8;
    v0 = v0 - hi_324b8 + (u32)(unsigned long)ref_t32_data_e1588;
    v0 = v0 + s6;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(a1 + (1524)) = s2;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (172));
    v1 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    v1 = 0;
    if (v0) { lo = s5 / v0; hi = s5 % v0; } else { lo = ~0U; hi = s5; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (172));
    s5 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = s5;
    v0 = hi_324fc;
    v0 = v0 - hi_324fc + (u32)(unsigned long)ref_t32_data_e1524;
    v0 = v0 + s3;
    a2 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = hi_3250c;
    v0 = v0 - hi_3250c + (u32)(unsigned long)ref_t32_data_e1520;
    v0 = v0 + s3;
    a3 = a2 << (0x4 & 31);
    t6 = *(volatile u8 *)(unsigned long)(v0 + (0));
    t4 = a2;
    a3 = a3 - a2;
    v0 = 0;
L_3252c:
    a0 = (u32)t4 < (u32)(t6);
    branch = (a0 == 0); a0 = v0 << (0x1e & 31);
    if (branch) goto L_32588;
    goto L_32538;
L_32538:
    t3 = *(volatile u8 *)(unsigned long)(t0 + (0));
    a0 = a0 - v0;
    a0 = a0 + a3;
    t7 = *(volatile u8 *)(unsigned long)(t1 + (0));
    a0 = a0 + t3;
    a0 = a0 << (0x2 & 31);
    t3 = t3 - v0;
L_32554:
    t2 = v0 + t3;
    t2 = (u32)t2 < (u32)(t7);
    branch = (t2 == 0); t2 = v0 << (0x2 & 31);
    if (branch) goto L_3257c;
    goto L_32564;
L_32564:
    t2 = t2 + a0;
    t2 = s4 + t2;
    t2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    v0 = v0 + 1;
    v1 = v1 + t2; goto L_32554;
L_3257c:
    t4 = t4 + 1;
    a3 = a3 + 15; goto L_3252c;
L_32588:
    if (v1 != 0) { if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; } goto L_325c0; }
    goto L_32590;
L_32590:
    v0 = hi_32590;
    v0 = v0 - hi_32590 + (u32)(unsigned long)ref_t32_data_e151c;
    s3 = v0 + s3;
    v1 = *(volatile u8 *)(unsigned long)(s3 + (0));
    v0 = a2 << (0x4 & 31);
    a2 = v0 - a2;
    a2 = a2 + v1;
    a2 = a2 << (0x2 & 31);
    s4 = s4 + a2;
    v1 = *(volatile u32 *)(unsigned long)(s4 + (0));
    v0 = 1;
    if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; }
L_325c0:
    v1 = *(volatile u8 *)(unsigned long)(a1 + (1297));
    v0 = lo;
    branch = (v1 == 0); *(volatile u32 *)(unsigned long)(a1 + (1528)) = v0;
    if (branch) goto L_32600;
    goto L_325d0;
L_325d0:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (1536));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (1532));
    a1 = *(volatile u32 *)(unsigned long)(a1 + (1524));
    product = (s64)(s32)v0 * (s32)v1; lo = product; hi = product >> 32;
    a2 = a0 + v1;
    a3 = 1;
    if (a2 == 0) a2 = a3;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)a1); lo = product; hi = product >> 32;
    v0 = lo;
    if (a2) { lo = v0 / a2; hi = v0 % a2; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
L_32600:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    branch = (v0 != 0); s2 = *(volatile u16 *)(unsigned long)(sp + (68));
    if (branch) goto L_32618;
    goto L_3260c;
L_3260c:
    v0 = 1;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
    s2 = *(volatile u16 *)(unsigned long)(sp + (68));
L_32618:
    s4 = hi_32618;
    s4 = s4 - hi_32618 + (u32)(unsigned long)ref_fix_point_div_32;
    s0 = s0 << (s2 & 31);
    a1 = t5 << (s2 & 31);
    a2 = s0;
    callee = s4; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_32634;
L_32634:
    v1 = *(volatile u32 *)(unsigned long)(sp + (160));
    a2 = s0;
    a1 = s8 << (s2 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    callee = s4; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3264c;
L_3264c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (160));
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = 1;
    if (v1 != v0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (0)); goto L_32784; }
    goto L_32664;
L_32664:
    v0 = *(volatile u32 *)(unsigned long)(sp + (36));
    v0 = (u32)v0 < (u32)(255);
    branch = (v0 == 0); s0 = 255;
    if (branch) goto L_3268c;
    goto L_32674;
L_32674:
    v0 = *(volatile u32 *)(unsigned long)(sp + (36));
    v1 = 3;
    v0 = v0 << (0x1 & 31);
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    s0 = v0 & 0xffff;
L_3268c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (96));
    a2 = s7 << (0x10 & 31);
    a0 = 16;
    a1 = v0 + -1;
    callee = s4; a1 = a1 << (0x10 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_326a4;
L_326a4:
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (100));
    s7 = 256;
    s7 = s7 - s0;
    s7 = s7 << (0x10 & 31);
    s5 = s0;
    t0 = 0;
    s3 = hi_326c0;
    s6 = v0 + s6;
    t1 = 256;
L_326cc:
    a1 = s5 - s0;
    a2 = s7;
    a1 = a1 << (0x10 & 31);
    a0 = 16;
    *(volatile u32 *)(unsigned long)(sp + (24)) = t1;
    callee = s4; *(volatile u32 *)(unsigned long)(sp + (20)) = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_326e8;
L_326e8:
    s8 = s3 - hi_326c0 + (u32)(unsigned long)ref_fix_point_mult2_32;
    a2 = v0;
    a1 = v0;
    callee = s8; a0 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_326fc;
L_326fc:
    a1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a2 = v0;
    callee = s8; a0 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3270c;
L_3270c:
    v1 = *(volatile u32 *)(unsigned long)(s6 + (0));
    a0 = s5 << (0x2 & 31);
    a2 = v0 >> (0xb & 31);
    v1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    s5 = s5 + 1;
    v1 = v1 + a0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = 5;
    callee = s8; a1 = a1 << (0x5 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_32734;
L_32734:
    t0 = *(volatile u32 *)(unsigned long)(sp + (20));
    t1 = *(volatile u32 *)(unsigned long)(sp + (24));
    v0 = v0 >> (0x5 & 31);
    branch = (s5 != t1); t0 = t0 + v0;
    if (branch) goto L_326cc;
    goto L_32748;
L_32748:
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    v1 = *(volatile u32 *)(unsigned long)(sp + (32));
    a0 = s2;
    a2 = v0 * v1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (72));
    a2 = a2 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (76));
    a2 = a2 * v0;
    callee = s4; a1 = a2 + t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_32770;
L_32770:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = v0 * v1;
    s2 = v0 >> (s2 & 31);
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s2;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
L_32784:
    v0 = (u32)v0 < (u32)(256);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (0)); goto L_3279c; }
    goto L_32790;
L_32790:
    v0 = 255;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
L_3279c:
    branch = (v0 != 0); v0 = 1;
    if (branch) goto L_327a8;
    goto L_327a4;
L_327a4:
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
L_327a8:
    ra = *(volatile u32 *)(unsigned long)(sp + (148));
    s8 = *(volatile u32 *)(unsigned long)(sp + (144));
    s7 = *(volatile u32 *)(unsigned long)(sp + (140));
    s6 = *(volatile u32 *)(unsigned long)(sp + (136));
    s5 = *(volatile u32 *)(unsigned long)(sp + (132));
    s4 = *(volatile u32 *)(unsigned long)(sp + (128));
    s3 = *(volatile u32 *)(unsigned long)(sp + (124));
    s2 = *(volatile u32 *)(unsigned long)(sp + (120));
    s1 = *(volatile u32 *)(unsigned long)(sp + (116));
    s0 = *(volatile u32 *)(unsigned long)(sp + (112));
    sp = sp + 152;
    return ((u64)v1 << 32) | v0;
}
