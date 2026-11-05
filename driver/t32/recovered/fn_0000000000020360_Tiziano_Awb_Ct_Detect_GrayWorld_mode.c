/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_fix_point_mult3_32[] __asm__("fix_point_mult3_32");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
extern unsigned char ref_Tiziano_Awb_Ct_Cal[] __asm__("Tiziano_Awb_Ct_Cal");
u64 Tiziano_Awb_Ct_Detect_GrayWorld_mode(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[98] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2042c = ((u32)(unsigned long)ref_fix_point_mult3_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_20434 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_205d4 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_2074c = ((u32)(unsigned long)ref_fix_point_mult3_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_20738 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_208b0 = ((u32)(unsigned long)ref_Tiziano_Awb_Ct_Cal + 0x8000U) & 0xffff0000U;
    const u32 hi_2061c = ((u32)(unsigned long)ref_Tiziano_Awb_Ct_Cal + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[34];
    stack[38] = arg4;
    stack[39] = arg5;
L_20360:
    sp = sp + -136;
    *(volatile u32 *)(unsigned long)(sp + (132)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (120)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (116)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (112)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (108)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (104)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (100)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (96)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a2 + (56));
    a1 = *(volatile u32 *)(unsigned long)(sp + (156));
    *(volatile u32 *)(unsigned long)(sp + (40)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (40));
    v0 = a1 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v1 = 1;
    branch = (v0 != v1); ra = *(volatile u32 *)(unsigned long)(sp + (132));
    if (branch) goto L_208dc;
    goto L_203b4;
L_203b4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (152));
    s5 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (s5 != v0); s8 = *(volatile u32 *)(unsigned long)(sp + (128));
    if (branch) goto L_208e0;
    goto L_203c4;
L_203c4:
    v1 = *(volatile u32 *)(unsigned long)(a2 + (36));
    v0 = *(volatile u32 *)(unsigned long)(a2 + (20));
    *(volatile u32 *)(unsigned long)(sp + (28)) = a0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (44));
    a0 = *(volatile u32 *)(unsigned long)(a2 + (52));
    t6 = *(volatile u32 *)(unsigned long)(a2 + (24));
    *(volatile u32 *)(unsigned long)(sp + (36)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (48));
    s0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    t7 = *(volatile u32 *)(unsigned long)(a2 + (28));
    *(volatile u32 *)(unsigned long)(sp + (48)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (172));
    s3 = *(volatile u16 *)(unsigned long)(a0 + (2));
    s1 = a3;
    *(volatile u32 *)(unsigned long)(sp + (44)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (2));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (6));
    s4 = a2;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = a1 << (0xb & 31);
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = 4;
    v0 = v0 << (s0 & 31);
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = hi_2042c;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = hi_20434;
    v1 = s5 << (s0 & 31);
    s7 = 0;
    s6 = 0;
    s8 = 0;
    t5 = 0;
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
L_20450:
    v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = (u32)t5 < (u32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (branch) goto L_20594;
    goto L_20460;
L_20460:
    s2 = t5 << (0x5 & 31);
    s5 = v0 + s2;
    v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    t9 = s5;
    s2 = s2 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = s2 << (0x2 & 31);
    s2 = v0 + s2;
L_20480:
    a0 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = s5 - t9;
    v0 = (u32)v0 < (u32)(a0);
    if (v0 == 0) { t5 = t5 + 1; goto L_20450; }
    goto L_20494;
L_20494:
    v0 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v0 = v0 << (s3 & 31);
    v0 = (u32)a1 < (u32)(v0);
    branch = (v0 != 0); t2 = v1;
    if (branch) goto L_204f0;
    goto L_204ac;
L_204ac:
    v0 = *(volatile u32 *)(unsigned long)(t6 + (56));
    v0 = v0 << (s3 & 31);
    v0 = (u32)v0 < (u32)(a1);
    if (v0 != 0) { a2 = *(volatile u8 *)(unsigned long)(s5 + (0)); goto L_204f4; }
    goto L_204c0;
L_204c0:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s2 + (4096));
    v0 = v0 << (s3 & 31);
    v0 = (u32)a0 < (u32)(v0);
    if (v0 != 0) { a2 = *(volatile u8 *)(unsigned long)(s5 + (0)); goto L_204f4; }
    goto L_204d8;
L_204d8:
    t2 = *(volatile u32 *)(unsigned long)(t7 + (56));
    v0 = *(volatile u32 *)(unsigned long)(sp + (52));
    t2 = t2 << (s3 & 31);
    t2 = (u32)t2 < (u32)(a0);
    if (t2 != 0) v0 = v1;
    t2 = v0;
L_204f0:
    a2 = *(volatile u8 *)(unsigned long)(s5 + (0));
L_204f4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (56));
    a3 = t2;
    a2 = a2 << (s0 & 31);
    t8 = v0 - hi_2042c + (u32)(unsigned long)ref_fix_point_mult3_32;
    a0 = s0;
    *(volatile u32 *)(unsigned long)(sp + (88)) = t9;
    *(volatile u32 *)(unsigned long)(sp + (84)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (80)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (76)) = t6;
    *(volatile u32 *)(unsigned long)(sp + (72)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (64)) = t2;
    callee = t8; *(volatile u32 *)(unsigned long)(sp + (68)) = t8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20528;
L_20528:
    a2 = *(volatile u8 *)(unsigned long)(s5 + (0));
    t2 = *(volatile u32 *)(unsigned long)(sp + (64));
    a1 = *(volatile u32 *)(unsigned long)(s2 + (4096));
    t8 = *(volatile u32 *)(unsigned long)(sp + (68));
    a3 = t2;
    a2 = a2 << (s0 & 31);
    a0 = s0;
    callee = t8; s8 = s8 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2054c;
L_2054c:
    s6 = s6 + v0;
    a1 = *(volatile u8 *)(unsigned long)(s5 + (0));
    t2 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = *(volatile u32 *)(unsigned long)(sp + (60));
    a1 = a1 << (s0 & 31);
    a2 = t2;
    v0 = v0 - hi_20434 + (u32)(unsigned long)ref_fix_point_mult2_32;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20570;
L_20570:
    s7 = s7 + v0;
    s5 = s5 + 1;
    s2 = s2 + 4;
    t9 = *(volatile u32 *)(unsigned long)(sp + (88));
    v1 = *(volatile u32 *)(unsigned long)(sp + (84));
    t7 = *(volatile u32 *)(unsigned long)(sp + (80));
    t6 = *(volatile u32 *)(unsigned long)(sp + (76));
    t5 = *(volatile u32 *)(unsigned long)(sp + (72)); goto L_20480;
L_20594:
    branch = (s7 == 0); v1 = *(volatile u32 *)(unsigned long)(sp + (152));
    if (branch) goto L_205b0;
    goto L_2059c;
L_2059c:
    branch = (s8 == 0); a0 = *(volatile u32 *)(unsigned long)(sp + (36));
    if (branch) goto L_205b4;
    goto L_205a4;
L_205a4:
    branch = (s6 != 0); v0 = *(volatile u32 *)(unsigned long)(sp + (152));
    if (branch) goto L_205d4;
    goto L_205ac;
L_205ac:
    v1 = *(volatile u32 *)(unsigned long)(sp + (152));
L_205b0:
    a0 = *(volatile u32 *)(unsigned long)(sp + (36));
L_205b4:
    v0 = 1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    s0 = v0 << (s0 & 31);
    v1 = 5000;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s0;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = s0; goto L_208d8;
L_205d4:
    s2 = hi_205d4;
    s2 = s2 - hi_205d4 + (u32)(unsigned long)ref_fix_point_div_32;
    a2 = s7;
    a1 = s8;
    a0 = s0;
    callee = s2; *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_205f0;
L_205f0:
    a0 = s0;
    a2 = s7;
    a1 = s6;
    callee = s2; s5 = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20604;
L_20604:
    t5 = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    a0 = 1;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (4));
    if (v0 != a0) { v0 = hi_2061c; goto L_208b4; }
    goto L_20620;
L_20620:
    a2 = s3 + -1;
    a2 = v0 << (a2 & 31);
    t1 = s5 + a2;
    t2 = t5 + a2;
    t1 = t1 >> (s3 & 31);
    t2 = t2 >> (s3 & 31);
    a3 = 0;
L_2063c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = (u32)a3 < (u32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (44));
    if (branch) goto L_20738;
    goto L_2064c;
L_2064c:
    t3 = a3 << (0x7 & 31);
    a0 = a3 << (0x5 & 31);
    t3 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    t4 = 0;
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    a0 = a0 << (0x2 & 31);
    a0 = v0 + a0;
L_20670:
    v0 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = (u32)t4 < (u32)(v0);
    if (v0 == 0) { a3 = a3 + 1; goto L_2063c; }
    goto L_20680;
L_20680:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = a2 + a1;
    a1 = a1 >> (s3 & 31);
    t6 = (u32)a1 < (u32)(t1);
    v0 = t1 - a1;
    a1 = a1 - t1;
    if (t6 == 0) v0 = a1;
    a1 = *(volatile u32 *)(unsigned long)(a0 + (4096));
    t6 = v0;
    a1 = a2 + a1;
    a1 = a1 >> (s3 & 31);
    v0 = (u32)a1 < (u32)(t2);
    t7 = t2 - a1;
    a1 = a1 - t2;
    if (v0 != 0) a1 = t7;
    product = (s64)(s32)a1 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t6 * (s32)t6); lo = product; hi = product >> 32;
    v0 = lo;
    t6 = (u32)v0 < (u32)(818);
    branch = (t6 == 0); a1 = 0;
    if (branch) goto L_20720;
    goto L_206d4;
L_206d4:
    t6 = (u32)v0 < (u32)(679);
    branch = (t6 == 0); a1 = 1;
    if (branch) goto L_20720;
    goto L_206e0;
L_206e0:
    t6 = (u32)v0 < (u32)(615);
    branch = (t6 == 0); a1 = 2;
    if (branch) goto L_20720;
    goto L_206ec;
L_206ec:
    t6 = (u32)v0 < (u32)(572);
    branch = (t6 == 0); a1 = 3;
    if (branch) goto L_20720;
    goto L_206f8;
L_206f8:
    t6 = (u32)v0 < (u32)(540);
    branch = (t6 == 0); a1 = 4;
    if (branch) goto L_20720;
    goto L_20704;
L_20704:
    t6 = (u32)v0 < (u32)(514);
    branch = (t6 == 0); a1 = 5;
    if (branch) goto L_20720;
    goto L_20710;
L_20710:
    v1 = *(volatile u32 *)(unsigned long)(sp + (48));
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
L_20720:
    a1 = a1 << (s3 & 31);
    *(volatile u32 *)(unsigned long)(t3 + (0)) = a1;
    t4 = t4 + 1;
    t3 = t3 + 4;
    a0 = a0 + 4; goto L_20670;
L_20738:
    v0 = hi_20738;
    s8 = 0;
    s6 = 0;
    s2 = 0;
    t4 = 0;
    t8 = hi_2074c;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
L_20754:
    v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = (u32)t4 < (u32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_20844;
    goto L_20764;
L_20764:
    t0 = t4 << (0x5 & 31);
    t2 = t4 << (0x7 & 31);
    t1 = v0 + t0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    t1 = t1 << (0x2 & 31);
    t1 = v0 + t1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = v0 + t0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (44));
    t9 = s3;
    s7 = v0 + t2;
L_20790:
    v1 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = s3 - t9;
    v0 = (u32)v0 < (u32)(v1);
    if (v0 == 0) { t4 = t4 + 1; goto L_20754; }
    goto L_207a4;
L_207a4:
    a2 = *(volatile u8 *)(unsigned long)(s3 + (0));
    a3 = *(volatile u32 *)(unsigned long)(s7 + (0));
    a1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t7 = t8 - hi_2074c + (u32)(unsigned long)ref_fix_point_mult3_32;
    a2 = a2 << (s0 & 31);
    a0 = s0;
    *(volatile u32 *)(unsigned long)(sp + (72)) = t9;
    *(volatile u32 *)(unsigned long)(sp + (68)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (64)) = t4;
    *(volatile u32 *)(unsigned long)(sp + (60)) = t8;
    *(volatile u32 *)(unsigned long)(sp + (52)) = t1;
    callee = t7; *(volatile u32 *)(unsigned long)(sp + (56)) = t7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_207d8;
L_207d8:
    t1 = *(volatile u32 *)(unsigned long)(sp + (52));
    a2 = *(volatile u8 *)(unsigned long)(s3 + (0));
    a3 = *(volatile u32 *)(unsigned long)(s7 + (0));
    a1 = *(volatile u32 *)(unsigned long)(t1 + (4096));
    t7 = *(volatile u32 *)(unsigned long)(sp + (56));
    a2 = a2 << (s0 & 31);
    a0 = s0;
    callee = t7; s2 = s2 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_207fc;
L_207fc:
    s6 = s6 + v0;
    a1 = *(volatile u8 *)(unsigned long)(s3 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (48));
    a2 = *(volatile u32 *)(unsigned long)(s7 + (0));
    a1 = a1 << (s0 & 31);
    v0 = v0 - hi_20738 + (u32)(unsigned long)ref_fix_point_mult2_32;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2081c;
L_2081c:
    t1 = *(volatile u32 *)(unsigned long)(sp + (52));
    s8 = s8 + v0;
    s3 = s3 + 1;
    t1 = t1 + 4;
    s7 = s7 + 4;
    t9 = *(volatile u32 *)(unsigned long)(sp + (72));
    t5 = *(volatile u32 *)(unsigned long)(sp + (68));
    t4 = *(volatile u32 *)(unsigned long)(sp + (64));
    t8 = *(volatile u32 *)(unsigned long)(sp + (60)); goto L_20790;
L_20844:
    branch = (s8 == 0); v1 = *(volatile u32 *)(unsigned long)(sp + (152));
    if (branch) goto L_20860;
    goto L_2084c;
L_2084c:
    branch = (s2 == 0); v0 = 1;
    if (branch) goto L_20864;
    goto L_20854;
L_20854:
    branch = (s6 != 0); v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    if (branch) goto L_20884;
    goto L_2085c;
L_2085c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (152));
L_20860:
    v0 = 1;
L_20864:
    s0 = v0 << (s0 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (36));
    a0 = 5000;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s0;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = s0; goto L_208b0;
L_20884:
    a2 = s8;
    a1 = s2;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20894;
L_20894:
    s5 = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    a2 = s8;
    a1 = s6;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_208ac;
L_208ac:
    t5 = v0;
L_208b0:
    v0 = hi_208b0;
L_208b4:
    a2 = t5;
    a1 = s5;
    a0 = s4;
    v0 = v0 - hi_208b0 + (u32)(unsigned long)ref_Tiziano_Awb_Ct_Cal;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_208cc;
L_208cc:
    t5 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s5;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = t5;
L_208d8:
    ra = *(volatile u32 *)(unsigned long)(sp + (132));
L_208dc:
    s8 = *(volatile u32 *)(unsigned long)(sp + (128));
L_208e0:
    s7 = *(volatile u32 *)(unsigned long)(sp + (124));
    s6 = *(volatile u32 *)(unsigned long)(sp + (120));
    s5 = *(volatile u32 *)(unsigned long)(sp + (116));
    s4 = *(volatile u32 *)(unsigned long)(sp + (112));
    s3 = *(volatile u32 *)(unsigned long)(sp + (108));
    s2 = *(volatile u32 *)(unsigned long)(sp + (104));
    s1 = *(volatile u32 *)(unsigned long)(sp + (100));
    s0 = *(volatile u32 *)(unsigned long)(sp + (96));
    sp = sp + 136;
    return ((u64)v1 << 32) | v0;
}
