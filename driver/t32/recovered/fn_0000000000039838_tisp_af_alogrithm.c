/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1620[] __asm__("t32_data_e1620");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
extern unsigned char ref_t32_data_e15f0[] __asm__("t32_data_e15f0");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
u64 tisp_af_alogrithm(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[88] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_39840 = ((u32)(unsigned long)ref_t32_data_e1620 + 0x8000U) & 0xffff0000U;
    const u32 hi_39970 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_39aac = ((u32)(unsigned long)ref_t32_data_e15f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_39afc = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[24];
L_39838:
    sp = sp + -96;
    v0 = a0 & 0xff;
    a2 = hi_39840;
    a2 = a2 - hi_39840 + (u32)(unsigned long)ref_t32_data_e1620;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s6;
    s6 = v0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (72)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (68)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (92)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = s6 + a2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t7 = 0;
    s4 = 0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    t3 = 0;
    v0 = a0 + 1800;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (486));
    t2 = *(volatile u16 *)(unsigned long)(s0 + (82));
    s5 = *(volatile u16 *)(unsigned long)(s0 + (86));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (6428));
    t5 = *(volatile u16 *)(unsigned long)(s0 + (480));
    s8 = *(volatile u16 *)(unsigned long)(s0 + (482));
    s7 = *(volatile u16 *)(unsigned long)(s0 + (484));
    s1 = *(volatile u16 *)(unsigned long)(s0 + (488));
    t1 = a0 + 900;
    t9 = a0 + 2700;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    a3 = s0 + 543;
    s2 = t2 << (0x2 & 31);
    s3 = 0;
    t4 = 0;
    a1 = 0;
    t6 = 0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = a2;
L_398e8:
    v0 = (u32)t6 < (u32)(t2);
    branch = (v0 == 0); t0 = a3;
    if (branch) goto L_39970;
    goto L_398f4;
L_398f4:
    t8 = 0;
L_398f8:
    v0 = t0 - a3;
    v0 = (u32)v0 < (u32)(s5);
    branch = (v0 == 0); v1 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_39960;
    goto L_39908;
L_39908:
    v0 = t7 + t8;
    a2 = *(volatile u8 *)(unsigned long)(t0 + (0));
    ra = v1 + v0;
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    s4 = s4 + a2;
    t8 = t8 + 4;
    v1 = a2 * ra;
    ra = t9 + v0;
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    t0 = t0 + 1;
    a1 = v1 + a1;
    v1 = a2 * ra;
    ra = a0 + v0;
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    v0 = t1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t4 = v1 + t4;
    v1 = a2 * ra;
    s3 = v1 + s3;
    v1 = a2 * v0;
    t3 = v1 + t3; goto L_398f8;
L_39960:
    t6 = t6 + 1;
    a3 = a3 + 15;
    t7 = t7 + s2; goto L_398e8;
L_39970:
    s2 = hi_39970;
    s2 = s2 - hi_39970 + (u32)(unsigned long)ref_fix_point_mult2_32;
    a2 = t5;
    a1 = a1 << (s1 & 31);
    a0 = s1;
    *(volatile u32 *)(unsigned long)(sp + (48)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (44)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = t4;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (36)) = t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_39998;
L_39998:
    t5 = *(volatile u32 *)(unsigned long)(sp + (36));
    a3 = 1;
    a3 = a3 << (s1 & 31);
    a2 = a3 - t5;
    a1 = s3 << (s1 & 31);
    a0 = s1;
    *(volatile u32 *)(unsigned long)(sp + (36)) = a3;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_399bc;
L_399bc:
    t4 = *(volatile u32 *)(unsigned long)(sp + (40));
    t0 = *(volatile u32 *)(unsigned long)(sp + (24));
    a2 = s8;
    a1 = t4 << (s1 & 31);
    a0 = s1;
    callee = s2; s3 = t0 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_399d8;
L_399d8:
    t3 = *(volatile u32 *)(unsigned long)(sp + (44));
    a3 = *(volatile u32 *)(unsigned long)(sp + (36));
    a0 = s1;
    a1 = t3 << (s1 & 31);
    a2 = a3 - s8;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_399f4;
L_399f4:
    if (s4) { lo = s3 / s4; hi = s3 % s4; } else { lo = ~0U; hi = s3; }
    t0 = *(volatile u32 *)(unsigned long)(sp + (24));
    a0 = s1;
    a2 = s7;
    t0 = t0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = t0;
    s8 = lo;
    a1 = s8 << (s1 & 31);
    if (s4) { lo = t0 / s4; hi = t0 % s4; } else { lo = ~0U; hi = t0; }
    callee = s2; s4 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_39a20;
L_39a20:
    a2 = *(volatile u32 *)(unsigned long)(sp + (20));
    a1 = s4 << (s1 & 31);
    a0 = s1;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_39a34;
L_39a34:
    a3 = *(volatile u32 *)(unsigned long)(sp + (24));
    a1 = s3 >> (0x3 & 31);
    a1 = a1 << (s1 & 31);
    v0 = a3 + v0;
    a3 = v0 >> (s1 & 31);
    a0 = s1;
    a2 = s7;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (24)) = a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_39a58;
L_39a58:
    t0 = *(volatile u32 *)(unsigned long)(sp + (36));
    a2 = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = s1;
    a1 = t0 >> (0x3 & 31);
    a1 = a1 << (s1 & 31);
    callee = s2; s3 = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_39a74;
L_39a74:
    t2 = *(volatile u32 *)(unsigned long)(sp + (48));
    a3 = *(volatile u32 *)(unsigned long)(sp + (24));
    v0 = s3 + v0;
    s1 = v0 >> (s1 & 31);
    a0 = s0 + 64;
    v0 = s0 + 8;
L_39a8c:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + 4;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(v0 + (-8)) = a1;
    if (branch) goto L_39a8c;
    goto L_39a9c;
L_39a9c:
    s5 = s5 * t2;
    *(volatile u32 *)(unsigned long)(s0 + (60)) = a3;
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u32 *)(unsigned long)(s0 + (64)) = s1;
    s1 = hi_39aac;
    s2 = v1 << (0x2 & 31);
    s1 = s1 - hi_39aac + (u32)(unsigned long)ref_t32_data_e15f0;
    a2 = s2 + s1;
    a0 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = s8 * s5;
    a3 = a3 * s5;
    v1 = (u32)a0 < (u32)(v0);
    a1 = v0 - a0;
    *(volatile u32 *)(unsigned long)(s0 + (72)) = v0;
    v0 = a0 - v0;
    if (v1 == 0) a1 = v0;
    s4 = s4 * s5;
    *(volatile u32 *)(unsigned long)(s0 + (68)) = a3;
    branch = (a0 != 0); *(volatile u32 *)(unsigned long)(s0 + (76)) = s4;
    if (branch) goto L_39af4;
    goto L_39aec;
L_39aec:
    v0 = 1;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = v0;
L_39af4:
    v0 = s1 + s6;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_39afc;
    v0 = v0 - hi_39afc + (u32)(unsigned long)ref_fix_point_div_32;
    callee = v0; a0 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_39b0c;
L_39b0c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (32));
    t1 = v1 + s6;
    a0 = *(volatile u32 *)(unsigned long)(t1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (6431));
    if (a1 != 0) { v0 = 1; goto L_39b5c; }
    goto L_39b28;
L_39b28:
    a3 = 254;
L_39b2c:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = a1 << (0x2 & 31);
    a1 = a1 + 1;
    a2 = v1 + a2;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (5408));
    branch = (a1 != a3); *(volatile u32 *)(unsigned long)(a2 + (5404)) = v1;
    if (branch) goto L_39b2c;
    goto L_39b48;
L_39b48:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(sp + (28));
    v0 = v0 << (a0 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (6420)) = v0; goto L_39c04;
L_39b5c:
    branch = (a1 != v0); v0 = 2;
    if (branch) goto L_39b94;
    goto L_39b64;
L_39b64:
    v0 = 0;
    v1 = 254;
L_39b6c:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = v0 << (0x2 & 31);
    v0 = v0 + 1;
    a1 = a1 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (5408));
    branch = (v0 != v1); *(volatile u32 *)(unsigned long)(a1 + (5404)) = a2;
    if (branch) goto L_39b6c;
    goto L_39b88;
L_39b88:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (68)); goto L_39c00;
L_39b94:
    branch = (a1 != v0); v0 = 3;
    if (branch) goto L_39bcc;
    goto L_39b9c;
L_39b9c:
    v0 = 0;
    v1 = 254;
L_39ba4:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = v0 << (0x2 & 31);
    v0 = v0 + 1;
    a1 = a1 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (5408));
    branch = (v0 != v1); *(volatile u32 *)(unsigned long)(a1 + (5404)) = a2;
    if (branch) goto L_39ba4;
    goto L_39bc0;
L_39bc0:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (72)); goto L_39c00;
L_39bcc:
    if (a1 != v0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (72)); goto L_39c08; }
    goto L_39bd4;
L_39bd4:
    v0 = 0;
    v1 = 254;
L_39bdc:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = v0 << (0x2 & 31);
    v0 = v0 + 1;
    a1 = a1 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (5408));
    branch = (v0 != v1); *(volatile u32 *)(unsigned long)(a1 + (5404)) = a2;
    if (branch) goto L_39bdc;
    goto L_39bf8;
L_39bf8:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (76));
L_39c00:
    *(volatile u32 *)(unsigned long)(v0 + (6420)) = v1;
L_39c04:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (72));
L_39c08:
    s1 = s1 + s2;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (92));
    s8 = *(volatile u32 *)(unsigned long)(sp + (88));
    s7 = *(volatile u32 *)(unsigned long)(sp + (84));
    s6 = *(volatile u32 *)(unsigned long)(sp + (80));
    s5 = *(volatile u32 *)(unsigned long)(sp + (76));
    s4 = *(volatile u32 *)(unsigned long)(sp + (72));
    s3 = *(volatile u32 *)(unsigned long)(sp + (68));
    s2 = *(volatile u32 *)(unsigned long)(sp + (64));
    s1 = *(volatile u32 *)(unsigned long)(sp + (60));
    s0 = *(volatile u32 *)(unsigned long)(sp + (56));
    sp = sp + 96;
    return ((u64)v1 << 32) | v0;
}
