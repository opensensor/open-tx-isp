/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
extern unsigned char ref_fix_point_div[] __asm__("fix_point_div");
extern unsigned char ref___lshrdi3[] __asm__("__lshrdi3");
extern unsigned char ref_tisp_awb_sat_weight[] __asm__("tisp_awb_sat_weight");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_kernel_mxu_begin_partial[] __asm__("kernel_mxu_begin_partial");
extern unsigned char ref_tisp_awb_ct_detect_simd_3[] __asm__("tisp_awb_ct_detect_simd_3");
extern unsigned char ref_kernel_mxu_end[] __asm__("kernel_mxu_end");
u64 tisp_awb_long_alogrithm(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[116] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3d85c = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_3d8a0 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_3dc98 = ((u32)(unsigned long)ref_fix_point_div + 0x8000U) & 0xffff0000U;
    const u32 hi_3dd58 = (((u32)(unsigned long)ref___lshrdi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_3ddd4 = (((u32)(unsigned long)ref___lshrdi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_3e028 = ((u32)(unsigned long)ref_tisp_awb_sat_weight + 0x8000U) & 0xffff0000U;
    const u32 hi_3e0f8 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_3e1bc = (((u32)(unsigned long)ref_kernel_mxu_begin_partial + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_3e1cc = ((u32)(unsigned long)ref_tisp_awb_ct_detect_simd_3 + 0x8000U) & 0xffff0000U;
    const u32 hi_3e1e4 = (((u32)(unsigned long)ref_kernel_mxu_end + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[52];
L_3d85c:
    v0 = hi_3d85c;
    sp = sp + -208;
    v1 = a1 << (0x2 & 31);
    v0 = v0 - hi_3d85c + (u32)(unsigned long)ref_t32_data_e16b4;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (204)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (196)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (192)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (184)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (176)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (200)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (188)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (180)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (172)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (168)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (212)) = a1;
    s6 = hi_3d8a0;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    s5 = *(volatile u32 *)(unsigned long)(v0 + (12));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    s3 = *(volatile u16 *)(unsigned long)(s0 + (3306));
    *(volatile u32 *)(unsigned long)(sp + (36)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (96)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3308));
    *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    s7 = s3 + -10;
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
    v0 = 1;
    v0 = v0 << (s3 & 31);
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (40)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3190));
    s6 = s6 - hi_3d8a0 + (u32)(unsigned long)ref_fix_point_mult2_32;
    s4 = a0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3186));
    a0 = s3;
    *(volatile u32 *)(unsigned long)(sp + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    v1 = *(volatile u16 *)(unsigned long)(s0 + (3292));
    a2 = *(volatile u32 *)(unsigned long)(s0 + (52));
    *(volatile u32 *)(unsigned long)(sp + (108)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (12));
    a1 = *(volatile u32 *)(unsigned long)(sp + (56));
    a2 = a2 << (s7 & 31);
    *(volatile u32 *)(unsigned long)(sp + (100)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3312));
    s2 = *(volatile u16 *)(unsigned long)(s0 + (3310));
    *(volatile u32 *)(unsigned long)(sp + (112)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3314));
    *(volatile u32 *)(unsigned long)(sp + (116)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3316));
    *(volatile u32 *)(unsigned long)(sp + (120)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3290));
    v0 = v0 * v1;
    v0 = v0 & 0xffff;
    *(volatile u32 *)(unsigned long)(sp + (104)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (16));
    *(volatile u32 *)(unsigned long)(sp + (80)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (20));
    *(volatile u32 *)(unsigned long)(sp + (84)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (24));
    *(volatile u32 *)(unsigned long)(sp + (72)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (28));
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (76)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3d978;
L_3d978:
    a2 = *(volatile u32 *)(unsigned long)(s0 + (56));
    a1 = *(volatile u32 *)(unsigned long)(sp + (56));
    a0 = s3;
    a2 = a2 << (s7 & 31);
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (88)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3d990;
L_3d990:
    *(volatile u32 *)(unsigned long)(sp + (92)) = v0;
    t7 = 2048;
    t8 = 0;
L_3d99c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (68));
    v0 = (u32)t8 < (u32)(v0);
    branch = (v0 == 0); s8 = t7;
    if (branch) goto L_3dbfc;
    goto L_3d9ac;
L_3d9ac:
    t9 = 0;
L_3d9b0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = (u32)t9 < (u32)(v0);
    branch = (v0 == 0); t2 = s8 + -2048;
    if (branch) goto L_3dbec;
    goto L_3d9c0;
L_3d9c0:
    t2 = t2 & 0xffff;
    v1 = t2 << (0x2 & 31);
    v1 = s1 + v1;
    v0 = 0x1U << 16;
    t4 = v1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(t4 + (-2904));
    a3 = s8 + -1024;
    a3 = a3 & 0xffff;
    t1 = s8 + 1024;
    t1 = t1 & 0xffff;
    t6 = a3 << (0x2 & 31);
    branch = (a0 != 0); t5 = t2 << (0x1 & 31);
    if (branch) goto L_3da14;
    goto L_3d9f4;
L_3d9f4:
    t5 = s5 + t5;
    t6 = s1 + t6;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v1 + (16384)) = 0;
    *(volatile u16 *)(unsigned long)(t5 + (150)) = 0;
    *(volatile u16 *)(unsigned long)(t5 + (2198)) = 0; goto L_3daf8;
L_3da14:
    v0 = *(volatile u32 *)(unsigned long)(t4 + (-7000));
    a2 = *(volatile u32 *)(unsigned long)(sp + (88));
    *(volatile u32 *)(unsigned long)(sp + (160)) = t5;
    a1 = v0 << (0xa & 31);
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = s3;
    *(volatile u32 *)(unsigned long)(sp + (156)) = t6;
    *(volatile u32 *)(unsigned long)(sp + (152)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (148)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (144)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (140)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (136)) = t9;
    *(volatile u32 *)(unsigned long)(sp + (132)) = t8;
    *(volatile u32 *)(unsigned long)(sp + (128)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (124)) = t4;
    a1 = lo;
    callee = s6; a1 = a1 << (s7 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3da5c;
L_3da5c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (128));
    t4 = *(volatile u32 *)(unsigned long)(sp + (124));
    a2 = *(volatile u32 *)(unsigned long)(sp + (92));
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(t4 + (1192));
    v0 = *(volatile u32 *)(unsigned long)(t4 + (-2904));
    a0 = s3;
    a1 = a1 << (0xa & 31);
    if (v0) { lo = a1 / v0; hi = a1 % v0; } else { lo = ~0U; hi = a1; }
    a1 = lo;
    callee = s6; a1 = a1 << (s7 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3da8c;
L_3da8c:
    t6 = *(volatile u32 *)(unsigned long)(sp + (156));
    t4 = *(volatile u32 *)(unsigned long)(sp + (124));
    v1 = *(volatile u32 *)(unsigned long)(sp + (128));
    t6 = s1 + t6;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (9384));
    t5 = *(volatile u32 *)(unsigned long)(sp + (160));
    t1 = *(volatile u32 *)(unsigned long)(sp + (152));
    *(volatile u32 *)(unsigned long)(v1 + (16384)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (-7000));
    a0 = *(volatile u32 *)(unsigned long)(t4 + (-2904));
    t5 = s5 + t5;
    v0 = v0 << (0xa & 31);
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    a3 = *(volatile u32 *)(unsigned long)(sp + (148));
    t7 = *(volatile u32 *)(unsigned long)(sp + (144));
    t2 = *(volatile u32 *)(unsigned long)(sp + (140));
    t9 = *(volatile u32 *)(unsigned long)(sp + (136));
    t8 = *(volatile u32 *)(unsigned long)(sp + (132));
    v0 = lo;
    *(volatile u16 *)(unsigned long)(t5 + (150)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (1192));
    a0 = *(volatile u32 *)(unsigned long)(t4 + (-2904));
    v0 = v0 << (0xa & 31);
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(t5 + (2198)) = v0;
L_3daf8:
    t2 = t2 << (0x1 & 31);
    t2 = s5 + t2;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (150));
    a3 = a3 << (0x2 & 31);
    a3 = s1 + a3;
    *(volatile u32 *)(unsigned long)(v1 + (29800)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (2198));
    *(volatile u32 *)(unsigned long)(a3 + (29800)) = v0;
    v0 = 0x1U << 16;
    v1 = v1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-23384));
    branch = (a0 != 0); t1 = t1 << (0x2 & 31);
    if (branch) goto L_3db48;
    goto L_3db2c;
L_3db2c:
    v0 = s8 << (0x2 & 31);
    v0 = s1 + v0;
    t1 = s1 + t1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(t1 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(a3 + (16384)) = 0; goto L_3dbdc;
L_3db48:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (-27480));
    a2 = *(volatile u32 *)(unsigned long)(sp + (88));
    *(volatile u32 *)(unsigned long)(sp + (144)) = t1;
    a1 = v0 << (0xa & 31);
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = s3;
    *(volatile u32 *)(unsigned long)(sp + (140)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (136)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (132)) = t9;
    *(volatile u32 *)(unsigned long)(sp + (128)) = t8;
    *(volatile u32 *)(unsigned long)(sp + (124)) = v1;
    a1 = lo;
    callee = s6; a1 = a1 << (s7 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3db80;
L_3db80:
    v1 = *(volatile u32 *)(unsigned long)(sp + (124));
    a0 = s8 << (0x2 & 31);
    a0 = s1 + a0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (-19288));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (-23384));
    a2 = *(volatile u32 *)(unsigned long)(sp + (92));
    a1 = a1 << (0xa & 31);
    if (v0) { lo = a1 / v0; hi = a1 % v0; } else { lo = ~0U; hi = a1; }
    a0 = s3;
    a1 = lo;
    callee = s6; a1 = a1 << (s7 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3dbb4;
L_3dbb4:
    t1 = *(volatile u32 *)(unsigned long)(sp + (144));
    v1 = *(volatile u32 *)(unsigned long)(sp + (124));
    a3 = *(volatile u32 *)(unsigned long)(sp + (140));
    t1 = s1 + t1;
    *(volatile u32 *)(unsigned long)(t1 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (-11096));
    t7 = *(volatile u32 *)(unsigned long)(sp + (136));
    t9 = *(volatile u32 *)(unsigned long)(sp + (132));
    t8 = *(volatile u32 *)(unsigned long)(sp + (128));
    *(volatile u32 *)(unsigned long)(a3 + (16384)) = v0;
L_3dbdc:
    t3 = s8 + 1;
    t9 = t9 + 1;
    s8 = t3 & 0xffff; goto L_3d9b0;
L_3dbec:
    t7 = t7 + 32;
    t8 = t8 + 1;
    t7 = t7 & 0xffff; goto L_3d99c;
L_3dbfc:
    v0 = *(volatile u32 *)(unsigned long)(sp + (68));
    v1 = *(volatile u32 *)(unsigned long)(sp + (64));
    a0 = 2048;
    t3 = 0;
    s6 = v0 * v1;
    a2 = 0;
    a1 = 0;
    t2 = s6;
L_3dc1c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (68));
    v0 = (u32)a1 < (u32)(v0);
    branch = (v0 == 0); v1 = a0;
    if (branch) goto L_3dc94;
    goto L_3dc2c;
L_3dc2c:
    a3 = 0;
L_3dc30:
    v0 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = (u32)a3 < (u32)(v0);
    branch = (v0 == 0); v0 = v1 << (0x2 & 31);
    if (branch) goto L_3dc84;
    goto L_3dc40;
L_3dc40:
    v0 = s1 + v0;
    t4 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v1 + 1024;
    v0 = v0 & 0xffff;
    v0 = v0 << (0x2 & 31);
    v0 = s1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a2 + t4;
    v1 = v1 + 1;
    t3 = t3 + v0;
    t4 = (u32)t4 < (u32)(1);
    v0 = (u32)v0 < (u32)(1);
    t2 = t2 - t4;
    s6 = s6 - v0;
    a3 = a3 + 1;
    v1 = v1 & 0xffff; goto L_3dc30;
L_3dc84:
    a0 = a0 + 32;
    a1 = a1 + 1;
    a0 = a0 & 0xffff; goto L_3dc1c;
L_3dc94:
    v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    s7 = hi_3dc98;
    a3 = 0;
    a0 = s3;
    s7 = s7 - hi_3dc98 + (u32)(unsigned long)ref_fix_point_div;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (136)) = t2;
    callee = s7; *(volatile u32 *)(unsigned long)(sp + (132)) = t3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3dcbc;
L_3dcbc:
    *(volatile u32 *)(unsigned long)(sp + (128)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (60));
    s8 = 1;
    a1 = 2;
    s8 = s8 << (v0 & 31);
    if (s8 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)s8 / (s32)a1; hi = (s32)s8 % (s32)a1; } else { lo = (s32)s8 < 0 ? 1 : ~0U; hi = s8; }
    t3 = *(volatile u32 *)(unsigned long)(sp + (132));
    a3 = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    a2 = t3;
    a0 = s3;
    *(volatile u32 *)(unsigned long)(sp + (124)) = v1;
    s8 = lo;
    v0 = (s32)s8 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (88)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (92));
    callee = s7; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3dd04;
L_3dd04:
    a3 = 0x2U << 16;
    a3 = s1 + a3;
    t3 = v0;
    v0 = *(volatile u16 *)(unsigned long)(a3 + (-23464));
    t2 = *(volatile u32 *)(unsigned long)(sp + (136));
    t6 = v1;
    *(volatile u16 *)(unsigned long)(a3 + (-23460)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a3 + (-23462));
    t5 = *(volatile u32 *)(unsigned long)(sp + (124));
    t4 = *(volatile u32 *)(unsigned long)(sp + (128));
    branch = (t2 != 0); *(volatile u16 *)(unsigned long)(a3 + (-23458)) = v0;
    if (branch) goto L_3dd44;
    goto L_3dd34;
L_3dd34:
    v0 = 256;
    *(volatile u16 *)(unsigned long)(a3 + (-23464)) = v0;
    *(volatile u16 *)(unsigned long)(s5 + (4278)) = v0; goto L_3dda4;
L_3dd44:
    a0 = t4 + s8;
    v0 = (s32)s8 >> (0x1f & 31);
    a2 = *(volatile u32 *)(unsigned long)(sp + (60));
    a1 = t5 + v0;
    t4 = (u32)a0 < (u32)(t4);
    v0 = hi_3dd58;
    *(volatile u32 *)(unsigned long)(sp + (128)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (124)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (92)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (132)) = v1;
    v0 = v0 - hi_3dd58 + ((u32)(unsigned long)ref___lshrdi3 + (0));
    callee = v0; a1 = t4 + a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3dd78;
L_3dd78:
    t2 = *(volatile u32 *)(unsigned long)(sp + (92));
    a3 = *(volatile u32 *)(unsigned long)(sp + (124));
    t6 = *(volatile u32 *)(unsigned long)(sp + (132));
    v1 = t2 >> (0x1 & 31);
    v0 = v1 + v0;
    if (t2) { lo = v0 / t2; hi = v0 % t2; } else { lo = ~0U; hi = v0; }
    t3 = *(volatile u32 *)(unsigned long)(sp + (128));
    t2 = lo;
    t2 = t2 & 0xffff;
    *(volatile u16 *)(unsigned long)(a3 + (-23464)) = t2;
    *(volatile u16 *)(unsigned long)(s5 + (4278)) = t2;
L_3dda4:
    branch = (s6 != 0); v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    if (branch) goto L_3ddc4;
    goto L_3ddac;
L_3ddac:
    v0 = 0x2U << 16;
    v1 = 256;
    v0 = s1 + v0;
    *(volatile u16 *)(unsigned long)(v0 + (-23462)) = v1;
    *(volatile u16 *)(unsigned long)(s5 + (4280)) = v1; goto L_3de08;
L_3ddc4:
    a0 = s8 + t3;
    a2 = *(volatile u32 *)(unsigned long)(sp + (60));
    a1 = v0 + t6;
    s8 = (u32)a0 < (u32)(s8);
    v0 = hi_3ddd4;
    v0 = v0 - hi_3ddd4 + ((u32)(unsigned long)ref___lshrdi3 + (0));
    callee = v0; a1 = s8 + a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3dde4;
L_3dde4:
    v1 = s6 >> (0x1 & 31);
    v0 = v1 + v0;
    if (s6) { lo = v0 / s6; hi = v0 % s6; } else { lo = ~0U; hi = v0; }
    v0 = 0x2U << 16;
    v0 = s1 + v0;
    t1 = lo;
    t1 = t1 & 0xffff;
    *(volatile u16 *)(unsigned long)(v0 + (-23462)) = t1;
    *(volatile u16 *)(unsigned long)(s5 + (4280)) = t1;
L_3de08:
    v1 = *(volatile u16 *)(unsigned long)(s5 + (4278));
    v0 = 0x1U << 16;
    a0 = 0;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a3 = 0;
    t3 = 0x1U << 16;
    t2 = 0x2U << 16;
    v1 = lo;
    *(volatile u16 *)(unsigned long)(s5 + (4286)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(s5 + (4280));
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(s5 + (4288)) = v0;
L_3de3c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (68));
    v0 = (u32)a3 < (u32)(v0);
    branch = (v0 == 0); a1 = a0;
    if (branch) goto L_3ded4;
    goto L_3de4c;
L_3de4c:
    t1 = 0;
L_3de50:
    v0 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = (u32)t1 < (u32)(v0);
    branch = (v0 == 0); v0 = a1 << (0x2 & 31);
    if (branch) goto L_3dec4;
    goto L_3de60;
L_3de60:
    v0 = s1 + v0;
    a2 = v0 + t3;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (-11096));
    branch = (v1 != 0); v0 = v0 + t2;
    if (branch) goto L_3de84;
    goto L_3de74;
L_3de74:
    *(volatile u32 *)(unsigned long)(v0 + (-23444)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (-19348)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (-15252)) = 0; goto L_3deb4;
L_3de84:
    t4 = *(volatile u32 *)(unsigned long)(a2 + (-27480));
    if (v1) { lo = t4 / v1; hi = t4 % v1; } else { lo = ~0U; hi = t4; }
    t4 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (-23444)) = t4;
    t4 = *(volatile u32 *)(unsigned long)(a2 + (-23384));
    if (v1) { lo = t4 / v1; hi = t4 % v1; } else { lo = ~0U; hi = t4; }
    t4 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (-19348)) = t4;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (-19288));
    if (v1) { lo = a2 / v1; hi = a2 % v1; } else { lo = ~0U; hi = a2; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (-15252)) = v1;
L_3deb4:
    a1 = a1 + 1;
    t1 = t1 + 1;
    a1 = a1 & 0xffff; goto L_3de50;
L_3dec4:
    a0 = a0 + 32;
    a3 = a3 + 1;
    a0 = a0 & 0xffff; goto L_3de3c;
L_3ded4:
    a3 = 2048;
    t2 = 0;
    t5 = 0x1U << 16;
    t4 = 1000;
L_3dee4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (68));
    v0 = (u32)t2 < (u32)(v0);
    branch = (v0 == 0); a1 = a3;
    if (branch) goto L_3dfe8;
    goto L_3def4;
L_3def4:
    t3 = 0;
L_3def8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = (u32)t3 < (u32)(v0);
    branch = (v0 == 0); v1 = a1 + -2048;
    if (branch) goto L_3dfd8;
    goto L_3df08;
L_3df08:
    v1 = v1 & 0xffff;
    a2 = v1 << (0x2 & 31);
    a2 = s1 + a2;
    a0 = a2 + t5;
    t1 = *(volatile u32 *)(unsigned long)(a0 + (-11096));
    t0 = *(volatile u32 *)(unsigned long)(sp + (104));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (9384));
    t1 = t4 * t1;
    v0 = a1 + -1024;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t1 = lo;
    a0 = t4 * a0;
    if (t0) { lo = a0 / t0; hi = a0 % t0; } else { lo = ~0U; hi = a0; }
    t0 = *(volatile u32 *)(unsigned long)(sp + (96));
    a0 = lo;
    a0 = a0 & 0xffff;
    a0 = (u32)t0 < (u32)(a0);
    branch = (a0 != 0); v0 = v0 & 0xffff;
    if (branch) goto L_3df84;
    goto L_3df54;
L_3df54:
    a0 = v0 << (0x2 & 31);
    v1 = v1 << (0x1 & 31);
    v1 = s5 + v1;
    a0 = s1 + a0;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(a2 + (16384)) = 0;
    *(volatile u16 *)(unsigned long)(v1 + (150)) = 0;
    *(volatile u16 *)(unsigned long)(v1 + (2198)) = 0;
    *(volatile u32 *)(unsigned long)(a2 + (29800)) = 0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (2198));
    *(volatile u32 *)(unsigned long)(a0 + (29800)) = v1;
L_3df84:
    v1 = *(volatile u32 *)(unsigned long)(sp + (96));
    t1 = t1 & 0xffff;
    t1 = (u32)v1 < (u32)(t1);
    if (t1 != 0) { a1 = a1 + 1; goto L_3dfcc; }
    goto L_3df98;
L_3df98:
    v1 = a1 << (0x2 & 31);
    v1 = s1 + v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = 0;
    v1 = a1 + 1024;
    v1 = v1 & 0xffff;
    v0 = v0 + 4096;
    v1 = v1 << (0x2 & 31);
    v0 = v0 << (0x2 & 31);
    v1 = s1 + v1;
    v0 = s1 + v0;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    a1 = a1 + 1;
L_3dfcc:
    t3 = t3 + 1;
    a1 = a1 & 0xffff; goto L_3def8;
L_3dfd8:
    a3 = a3 + 32;
    t2 = t2 + 1;
    a3 = a3 & 0xffff; goto L_3dee4;
L_3dfe8:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (3438));
    v0 = v0 + -1;
    v0 = v0 & 0xffff;
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); v0 = 0x1U << 16;
    if (branch) goto L_3e048;
    goto L_3e000;
L_3e000:
    a3 = v0 + 1192;
    v0 = v0 + 9384;
    v1 = sp + 40;
    v0 = s1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (212));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v1 = s1 + 24576;
    a2 = 0xf4a8;
    a1 = 0xe4a8;
    v0 = hi_3e028;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    a3 = s1 + a3;
    a2 = s1 + a2;
    v0 = v0 - hi_3e028 + (u32)(unsigned long)ref_tisp_awb_sat_weight;
    callee = v0; a1 = s1 + a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e044;
L_3e044:
    v0 = 0x1U << 16;
L_3e048:
    v0 = s1 + v0;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (13500));
    v0 = 1;
    branch = (v1 != v0); v0 = 0x2U << 16;
    if (branch) goto L_3e0f0;
    goto L_3e05c;
L_3e05c:
    v0 = s1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-23464));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (-23456));
    a0 = (u32)v0 < (u32)(v1);
    if (a0 == 0) { v0 = v0 - v1; goto L_3e078; }
    goto L_3e074;
L_3e074:
    v0 = v1 - v0;
L_3e078:
    v1 = 0x2U << 16;
    v1 = s1 + v1;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (-23462));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (-23454));
    a1 = (u32)v1 < (u32)(a0);
    branch = (a1 == 0); v0 = v0 & 0xffff;
    if (branch) goto L_3e09c;
    goto L_3e094;
L_3e094:
    v1 = a0 - v1; goto L_3e0a0;
L_3e09c:
    v1 = v1 - a0;
L_3e0a0:
    a0 = 0x1U << 16;
    a0 = s1 + a0;
    a1 = *(volatile u8 *)(unsigned long)(a0 + (13508));
    a0 = 1;
    branch = (a1 != a0); v1 = v1 & 0xffff;
    if (branch) goto L_3e0ec;
    goto L_3e0b8;
L_3e0b8:
    v0 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (120));
    v0 = v0 & 0xffff;
    v0 = (u32)v0 < (u32)(v1);
    branch = (v0 == 0); v0 = 0x2U << 16;
    if (branch) goto L_3e0f0;
    goto L_3e0d0;
L_3e0d0:
    v0 = s1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (-23476));
    v0 = 0xffU << 16;
    v0 = v0 + 255;
    v0 = v1 & v0;
    branch = (v0 == 0); ra = *(volatile u32 *)(unsigned long)(sp + (204));
    if (branch) goto L_3e5b8;
    goto L_3e0ec;
L_3e0ec:
    v0 = 0x2U << 16;
L_3e0f0:
    v0 = s1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-23464));
    s6 = hi_3e0f8;
    s6 = s6 - hi_3e0f8 + ((u32)(unsigned long)ref_memset + (0));
    *(volatile u16 *)(unsigned long)(v0 + (-23456)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-23462));
    a2 = 784;
    a1 = 0;
    *(volatile u16 *)(unsigned long)(v0 + (-23454)) = v1;
    callee = s6; a0 = *(volatile u32 *)(unsigned long)(s4 + (144));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e11c;
L_3e11c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (148));
    a2 = 784;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e12c;
L_3e12c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (152));
    a2 = 784;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e13c;
L_3e13c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (156));
    a2 = 144;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e14c;
L_3e14c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (160));
    a2 = 720;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e15c;
L_3e15c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (164));
    a2 = 960;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e16c;
L_3e16c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (172));
    a2 = 4096;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e17c;
L_3e17c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (176));
    a2 = 4096;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e18c;
L_3e18c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (180));
    a2 = 4096;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e19c;
L_3e19c:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (184));
    a2 = 4096;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e1ac;
L_3e1ac:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (188));
    a2 = 4096;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e1bc;
L_3e1bc:
    v0 = hi_3e1bc;
    v0 = v0 - hi_3e1bc + ((u32)(unsigned long)ref_kernel_mxu_begin_partial + (0));
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e1cc;
L_3e1cc:
    v0 = hi_3e1cc;
    a0 = s4;
    a2 = sp + 32;
    v0 = v0 - hi_3e1cc + (u32)(unsigned long)ref_tisp_awb_ct_detect_simd_3;
    callee = v0; a1 = sp + 48;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e1e4;
L_3e1e4:
    v0 = hi_3e1e4;
    v0 = v0 - hi_3e1e4 + ((u32)(unsigned long)ref_kernel_mxu_end + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e1f4;
L_3e1f4:
    v0 = 0x1U << 16;
    v1 = s1 + v0;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (13500));
    v1 = 1;
    branch = (a0 != v1); a2 = *(volatile u32 *)(unsigned long)(sp + (48));
    if (branch) goto L_3e31c;
    goto L_3e20c;
L_3e20c:
    v1 = v0 + 13516;
    v0 = v0 + 13572;
    v1 = s1 + v1;
    v0 = s1 + v0;
L_3e21c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v1 + 4;
    *(volatile u32 *)(unsigned long)(v1 + (-8)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (56));
    *(volatile u32 *)(unsigned long)(v1 + (52)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (116));
    branch = (v0 != v1); *(volatile u32 *)(unsigned long)(v1 + (112)) = a0;
    if (branch) goto L_3e21c;
    goto L_3e23c;
L_3e23c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (48));
    v0 = 0x1U << 16;
    v0 = s1 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (13568)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (52));
    *(volatile u32 *)(unsigned long)(v0 + (13628)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (44));
    *(volatile u32 *)(unsigned long)(v0 + (13688)) = v1;
    v0 = (u32)s2 < (u32)(16);
    if (v0 == 0) { s2 = 15; goto L_3e270; }
    goto L_3e268;
L_3e268:
    v0 = 1;
    if (s2 == 0) s2 = v0;
L_3e270:
    v0 = 15;
    v0 = v0 - s2;
    v1 = v0 + 19762;
    v1 = v1 << (0x2 & 31);
    v1 = s1 + v1;
    a0 = 0;
    t1 = 0;
    a2 = 0;
    t2 = 0;
    t0 = 0;
    a1 = 0;
    a3 = 15;
L_3e2a0:
    t3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = v0 + 1;
    t0 = t0 + v0;
    t4 = v0 * t3;
    t3 = *(volatile u32 *)(unsigned long)(v1 + (60));
    a2 = a2 + v0;
    a0 = a0 + v0;
    v1 = v1 + 4;
    a1 = t4 + a1;
    t4 = v0 * t3;
    t3 = *(volatile u32 *)(unsigned long)(v1 + (116));
    t2 = t4 + t2;
    t4 = v0 * t3;
    branch = (v0 != a3); t1 = t4 + t1;
    if (branch) goto L_3e2a0;
    goto L_3e2dc;
L_3e2dc:
    a3 = t0 >> (0x1 & 31);
    a1 = a3 + a1;
    if (t0) { lo = a1 / t0; hi = a1 % t0; } else { lo = ~0U; hi = a1; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(sp + (48)) = a1;
    a1 = a2 >> (0x1 & 31);
    v1 = a1 + t2;
    if (a2) { lo = v1 / a2; hi = v1 % a2; } else { lo = ~0U; hi = v1; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v1;
    v1 = a0 >> (0x1 & 31);
    v0 = v1 + t1;
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (44)) = v0; goto L_3e348;
L_3e31c:
    a1 = *(volatile u32 *)(unsigned long)(sp + (52));
    v1 = v0 + 13512;
    v0 = v0 + 13572;
    v1 = s1 + v1;
    v0 = s1 + v0;
L_3e330:
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a2;
    *(volatile u32 *)(unsigned long)(v1 + (60)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (44));
    v1 = v1 + 4;
    branch = (v0 != v1); *(volatile u32 *)(unsigned long)(v1 + (116)) = a0;
    if (branch) goto L_3e330;
    goto L_3e348;
L_3e348:
    v0 = 0x1U << 16;
    v0 = s1 + v0;
    a1 = *(volatile u8 *)(unsigned long)(v0 + (13500));
    v1 = 1;
    if (a1 != v1) { *(volatile u8 *)(unsigned long)(v0 + (13500)) = v1; goto L_3e3c8; }
    goto L_3e360;
L_3e360:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (13564));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (13568));
    if (a0 != v1) { v0 = *(volatile u32 *)(unsigned long)(sp + (48)); goto L_3e3d4; }
    goto L_3e370;
L_3e370:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (13624));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (13628));
    if (a0 != v1) { v0 = *(volatile u32 *)(unsigned long)(sp + (48)); goto L_3e3d4; }
    goto L_3e380;
L_3e380:
    v1 = 0x2U << 16;
    s1 = s1 + v1;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (-23476));
    v1 = 0xffU << 16;
    v1 = v1 + 255;
    v1 = a0 & v1;
    if (v1 != 0) { v0 = *(volatile u32 *)(unsigned long)(sp + (48)); goto L_3e3d4; }
    goto L_3e3a0;
L_3e3a0:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (16));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (24));
    if (a0 != v1) { v0 = *(volatile u32 *)(unsigned long)(sp + (48)); goto L_3e3d4; }
    goto L_3e3b0;
L_3e3b0:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (20));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (28));
    if (a0 != v1) { v0 = *(volatile u32 *)(unsigned long)(sp + (48)); goto L_3e3d4; }
    goto L_3e3c0;
L_3e3c0:
    *(volatile u8 *)(unsigned long)(v0 + (13508)) = a1; goto L_3e5b4;
L_3e3c8:
    *(volatile u8 *)(unsigned long)(v0 + (13508)) = 0;
    s2 = 1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (48));
L_3e3d4:
    a2 = *(volatile u32 *)(unsigned long)(sp + (56));
    a3 = 0;
    a0 = s3;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    callee = s7; *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e3ec;
L_3e3ec:
    *(volatile u32 *)(unsigned long)(sp + (40)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (52));
    a2 = *(volatile u32 *)(unsigned long)(sp + (56));
    a3 = 0;
    a0 = s3;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    callee = s7; *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3e40c;
L_3e40c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (60));
    a1 = *(volatile u32 *)(unsigned long)(sp + (60));
    t0 = 1;
    a0 = v1 + -1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (40));
    a0 = t0 << (a0 & 31);
    v0 = a0 + v0;
    v1 = a0 + v1;
    v1 = v1 >> (a1 & 31);
    v0 = v0 >> (a1 & 31);
    a0 = *(volatile u32 *)(unsigned long)(sp + (80));
    a1 = *(volatile u32 *)(unsigned long)(sp + (80));
    *(volatile u32 *)(unsigned long)(sp + (40)) = v1;
    a0 = (u32)a0 < (u32)(v1);
    a3 = v1 - a1;
    a1 = a1 - v1;
    if (a0 != 0) a1 = a3;
    a0 = *(volatile u32 *)(unsigned long)(sp + (84));
    *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    t1 = (u32)a0 < (u32)(v0);
    a2 = v0 - a0;
    a0 = a0 - v0;
    if (t1 != 0) a0 = a2;
    a0 = a1 + a0;
    a1 = *(volatile u32 *)(unsigned long)(sp + (108));
    branch = (a1 != 0); a1 = *(volatile u32 *)(unsigned long)(sp + (112));
    if (branch) goto L_3e4d8;
    goto L_3e478;
L_3e478:
    a1 = *(volatile u32 *)(unsigned long)(sp + (116));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 == 0) { *(volatile u32 *)(unsigned long)(s0 + (8)) = 0; goto L_3e498; }
    goto L_3e488;
L_3e488:
    a0 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (a0 != t0) { if (a3 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)a3 / (s32)s2; hi = (s32)a3 % (s32)s2; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; } goto L_3e4a0; }
    goto L_3e494;
L_3e494:
    *(volatile u32 *)(unsigned long)(s0 + (8)) = 0;
L_3e498:
    *(volatile u32 *)(unsigned long)(s0 + (12)) = 0; goto L_3e5b4;
L_3e4a0:
    *(volatile u32 *)(unsigned long)(s0 + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (72));
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = t0;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = v1;
    a3 = lo;
    a3 = a3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (76));
    if (a2 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)a2 / (s32)s2; hi = (s32)a2 % (s32)s2; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a3;
    s2 = lo;
    s2 = s2 + v0;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = s2; goto L_3e5b4;
L_3e4d8:
    a0 = (u32)a1 < (u32)(a0);
    branch = (a0 == 0); a0 = *(volatile u32 *)(unsigned long)(sp + (100));
    if (branch) goto L_3e4f4;
    goto L_3e4e4;
L_3e4e4:
    a0 = *(volatile u32 *)(unsigned long)(sp + (32));
    branch = (a0 != t0); a0 = *(volatile u32 *)(unsigned long)(sp + (72));
    if (branch) goto L_3e574;
    goto L_3e4f0;
L_3e4f0:
    a0 = *(volatile u32 *)(unsigned long)(sp + (100));
L_3e4f4:
    a0 = a0 + 1;
    if (a0 == s2) { v0 = *(volatile u32 *)(unsigned long)(s0 + (16)); goto L_3e510; }
    goto L_3e500;
L_3e500:
    a0 = 1;
    if (s2 != a0) { *(volatile u32 *)(unsigned long)(s0 + (8)) = a0; goto L_3e524; }
    goto L_3e50c;
L_3e50c:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (16));
L_3e510:
    *(volatile u32 *)(unsigned long)(s0 + (8)) = 0;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (20));
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v0; goto L_3e564;
L_3e524:
    a0 = *(volatile u32 *)(unsigned long)(sp + (100));
    s2 = s2 - a0;
    a0 = *(volatile u32 *)(unsigned long)(sp + (72));
    v1 = v1 - a0;
    if (v1 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)v1 / (s32)s2; hi = (s32)v1 % (s32)s2; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (72));
    v1 = lo;
    v1 = v1 + a0;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (76));
    v0 = v0 - v1;
    if (v0 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)v0 / (s32)s2; hi = (s32)v0 % (s32)s2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (76));
    s2 = lo;
    s2 = s2 + v0;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = s2;
L_3e564:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (12));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = v0; goto L_3e5b4;
L_3e574:
    *(volatile u32 *)(unsigned long)(s0 + (16)) = v1;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = v0;
    v1 = v1 - a0;
    if (v1 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)v1 / (s32)s2; hi = (s32)v1 % (s32)s2; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = *(volatile u32 *)(unsigned long)(sp + (72));
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = t0;
    v1 = lo;
    v1 = v1 + a0;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (76));
    v0 = v0 - v1;
    if (v0 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)v0 / (s32)s2; hi = (s32)v0 % (s32)s2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v0;
L_3e5b4:
    ra = *(volatile u32 *)(unsigned long)(sp + (204));
L_3e5b8:
    s8 = *(volatile u32 *)(unsigned long)(sp + (200));
    s7 = *(volatile u32 *)(unsigned long)(sp + (196));
    s6 = *(volatile u32 *)(unsigned long)(sp + (192));
    s5 = *(volatile u32 *)(unsigned long)(sp + (188));
    s4 = *(volatile u32 *)(unsigned long)(sp + (184));
    s3 = *(volatile u32 *)(unsigned long)(sp + (180));
    s2 = *(volatile u32 *)(unsigned long)(sp + (176));
    s1 = *(volatile u32 *)(unsigned long)(sp + (172));
    s0 = *(volatile u32 *)(unsigned long)(sp + (168));
    sp = sp + 208;
    return ((u64)v1 << 32) | v0;
}
