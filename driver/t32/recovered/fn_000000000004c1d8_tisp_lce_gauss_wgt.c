/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_calculate_exponential[] __asm__("calculate_exponential");
extern unsigned char ref_t32_data_e1da8[] __asm__("t32_data_e1da8");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_lce_gauss_wgt(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[88] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4c20c = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4c244 = ((u32)(unsigned long)ref_calculate_exponential + 0x8000U) & 0xffff0000U;
    const u32 hi_4c300 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c330 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c360 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c390 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c3b4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[24];
L_4c1d8:
    sp = sp + -96;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (68)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (92)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s1;
    s2 = *(volatile u8 *)(unsigned long)(a1 + (1));
    s6 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v0 = hi_4c20c;
    s3 = s2 << (0x1 & 31);
    s3 = s3 * s2;
    s1 = *(volatile u8 *)(unsigned long)(a1 + (2));
    s0 = a0;
    s5 = a2;
    a1 = 0;
    a2 = 32;
    a0 = sp + 16;
    v0 = v0 - hi_4c20c + ((u32)(unsigned long)ref_memset + (0));
    s4 = a3 & 0xff;
    callee = v0; s6 = s6 << (0xc & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4c240;
L_4c240:
    s2 = 0;
    s8 = hi_4c244;
    s7 = 32;
    t0 = (s32)s3 >> (0x1 & 31);
L_4c250:
    a0 = s2 << (0x3 & 31);
    a0 = a0 - s1;
    a0 = a0 * a0;
    a3 = 12;
    a2 = 12;
    a1 = 10;
    v0 = s8 - hi_4c244 + (u32)(unsigned long)ref_calculate_exponential;
    *(volatile u32 *)(unsigned long)(sp + (48)) = t0;
    a0 = a0 << (0xc & 31);
    a0 = a0 + t0;
    if (a0 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)a0 / (s32)s3; hi = (s32)a0 % (s32)s3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    callee = v0; a0 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4c284;
L_4c284:
    v1 = sp + 16;
    a0 = v1 + s2;
    v1 = (s32)v0 >> (0x1 & 31);
    v1 = v1 + s6;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    s2 = s2 + 1;
    t0 = *(volatile u32 *)(unsigned long)(sp + (48));
    v1 = lo;
    branch = (s2 != s7); *(volatile u8 *)(unsigned long)(a0 + (0)) = v1;
    if (branch) goto L_4c250;
    goto L_4c2ac;
L_4c2ac:
    v1 = sp + 16;
    v0 = s5;
    a0 = s5 + 8;
L_4c2b8:
    a1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    v0 = v0 + 1;
    v1 = v1 + 1;
    branch = (a0 != v0); *(volatile u8 *)(unsigned long)(v0 + (-1)) = a1;
    if (branch) goto L_4c2b8;
    goto L_4c2cc;
L_4c2cc:
    v0 = 0;
    a0 = 12;
L_4c2d4:
    v1 = v0 << (0x1 & 31);
    a2 = sp + 16;
    v1 = a2 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (8));
    a1 = s5 + v0;
    v0 = v0 + 1;
    branch = (v0 != a0); *(volatile u8 *)(unsigned long)(a1 + (8)) = v1;
    if (branch) goto L_4c2d4;
    goto L_4c2f4;
L_4c2f4:
    v0 = 1;
    branch = (s4 != v0); v0 = 2;
    if (branch) goto L_4c328;
    goto L_4c300;
L_4c300:
    v0 = hi_4c300;
    v0 = v0 - hi_4c300 + (u32)(unsigned long)ref_t32_data_e1da8;
    s0 = s0 << (0x2 & 31);
    s0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a2 = 32;
    a1 = sp + 16;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a0 + 149; goto L_4c3b4;
L_4c328:
    branch = (s4 != v0); v0 = 3;
    if (branch) goto L_4c358;
    goto L_4c330;
L_4c330:
    v0 = hi_4c330;
    v0 = v0 - hi_4c330 + (u32)(unsigned long)ref_t32_data_e1da8;
    s0 = s0 << (0x2 & 31);
    s0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a2 = 32;
    a1 = sp + 16;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a0 + 181; goto L_4c3b4;
L_4c358:
    branch = (s4 != v0); v0 = 4;
    if (branch) goto L_4c388;
    goto L_4c360;
L_4c360:
    v0 = hi_4c360;
    v0 = v0 - hi_4c360 + (u32)(unsigned long)ref_t32_data_e1da8;
    s0 = s0 << (0x2 & 31);
    s0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a2 = 32;
    a1 = sp + 16;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a0 + 643; goto L_4c3b4;
L_4c388:
    branch = (s4 != v0); ra = *(volatile u32 *)(unsigned long)(sp + (92));
    if (branch) goto L_4c3c8;
    goto L_4c390;
L_4c390:
    v0 = hi_4c390;
    v0 = v0 - hi_4c390 + (u32)(unsigned long)ref_t32_data_e1da8;
    s0 = s0 << (0x2 & 31);
    s0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a2 = 32;
    a1 = sp + 16;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a0 + 675;
L_4c3b4:
    v0 = hi_4c3b4;
    v0 = v0 - hi_4c3b4 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4c3c4;
L_4c3c4:
    ra = *(volatile u32 *)(unsigned long)(sp + (92));
L_4c3c8:
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
