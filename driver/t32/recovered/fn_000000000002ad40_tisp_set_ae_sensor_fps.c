/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_t32_data_dd2d4[] __asm__("t32_data_dd2d4");
u64 tisp_set_ae_sensor_fps(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[104] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2ad48 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_2ad6c = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_2ade0 = ((u32)(unsigned long)ref_t32_data_dd2d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_2ae64 = ((u32)(unsigned long)ref_t32_data_dd2d4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[40];
L_2ad40:
    sp = sp + -160;
    v1 = a0 & 0xff;
    t0 = hi_2ad48;
    t0 = t0 - hi_2ad48 + (u32)(unsigned long)ref_t32_data_e15a8;
    *(volatile u32 *)(unsigned long)(sp + (148)) = s1;
    s1 = v1 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (156)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (152)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (144)) = s0;
    v0 = s1 + t0;
    t3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = hi_2ad6c;
    a0 = a0 - hi_2ad6c + (u32)(unsigned long)ref_t32_data_e1588;
    a0 = s1 + a0;
    t1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    a0 = *(volatile u32 *)(unsigned long)(t3 + (4));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v1;
    a3 = *(volatile u32 *)(unsigned long)(t3 + (4));
    t2 = *(volatile u32 *)(unsigned long)(a0 + (11780));
    a0 = 1;
    t4 = *(volatile u32 *)(unsigned long)(a3 + (11772));
    a1 = *(volatile u32 *)(unsigned long)(t1 + (1264));
    a2 = *(volatile u32 *)(unsigned long)(t1 + (1268));
    branch = (t4 != a0); s0 = *(volatile u16 *)(unsigned long)(v0 + (1736));
    if (branch) goto L_2ae20;
    goto L_2ada8;
L_2ada8:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (11776));
    if (t2) { lo = v0 / t2; hi = v0 % t2; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 << (s0 & 31);
    a0 = (u32)a2 < (u32)(v0);
    branch = (a0 == 0); v0 = (u32)v0 < (u32)(a1);
    if (branch) goto L_2adcc;
    goto L_2adc4;
L_2adc4:
    s0 = a2 >> (s0 & 31); goto L_2add8;
L_2adcc:
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(t3 + (4)); goto L_2ade0; }
    goto L_2add4;
L_2add4:
    s0 = a1 >> (s0 & 31);
L_2add8:
    *(volatile u32 *)(unsigned long)(a3 + (11776)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (4));
L_2ade0:
    a1 = hi_2ade0;
    a1 = a1 - hi_2ade0 + (u32)(unsigned long)ref_t32_data_dd2d4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (11776));
    v0 = 232;
    a2 = v1 * v0;
    a0 = a0 << (0x10 & 31);
    a0 = a0 + t2;
    v1 = a2 + a1;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (56));
    if (a0 == v0) { ra = *(volatile u32 *)(unsigned long)(sp + (156)); goto L_2aed4; }
    goto L_2ae0c;
L_2ae0c:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (212));
    callee = v0; a1 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2ae18;
L_2ae18:
    ra = *(volatile u32 *)(unsigned long)(sp + (156)); goto L_2aed4;
L_2ae20:
    a3 = *(volatile u32 *)(unsigned long)(t3 + (0));
    a3 = *(volatile u32 *)(unsigned long)(a3 + (1740));
    branch = (a3 != a0); s2 = t0;
    if (branch) goto L_2ae98;
    goto L_2ae30;
L_2ae30:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1664));
    a3 = (u32)a2 < (u32)(a0);
    branch = (a3 == 0); a0 = (u32)a0 < (u32)(a1);
    if (branch) goto L_2ae48;
    goto L_2ae40;
L_2ae40:
    *(volatile u32 *)(unsigned long)(v0 + (1664)) = a2; goto L_2ae50;
L_2ae48:
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (1664)) = a1; goto L_2ae50; }
    goto L_2ae50;
L_2ae50:
    a0 = 232;
    a1 = v1 * a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (1664));
    v0 = v0 << (0x1 & 31);
    s0 = v0 >> (s0 & 31);
    v0 = hi_2ae64;
    v0 = v0 - hi_2ae64 + (u32)(unsigned long)ref_t32_data_dd2d4;
    s0 = s0 << (0x10 & 31);
    s0 = s0 + 2;
    v1 = a1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (56));
    branch = (s0 == v0); a1 = sp + 16;
    if (branch) goto L_2aeac;
    goto L_2ae84;
L_2ae84:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (212));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2ae90;
L_2ae90:
    t0 = s2 + s1; goto L_2aeb0;
L_2ae98:
    v0 = *(volatile u32 *)(unsigned long)(t1 + (1272));
    v0 = v0 << (0x1 & 31);
    s0 = v0 >> (s0 & 31);
    s0 = s0 << (0x10 & 31);
    s0 = s0 + 2;
L_2aeac:
    t0 = s2 + s1;
L_2aeb0:
    v0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    s0 = s0 + -2;
    s0 = s0 >> (0x10 & 31);
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u32 *)(unsigned long)(v1 + (11776)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = 2;
    *(volatile u32 *)(unsigned long)(v0 + (11780)) = v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (156));
L_2aed4:
    s2 = *(volatile u32 *)(unsigned long)(sp + (152));
    s1 = *(volatile u32 *)(unsigned long)(sp + (148));
    s0 = *(volatile u32 *)(unsigned long)(sp + (144));
    sp = sp + 160;
    return ((u64)v1 << 32) | v0;
}
