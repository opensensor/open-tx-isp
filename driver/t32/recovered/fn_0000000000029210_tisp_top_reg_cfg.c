/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1484[] __asm__("t32_data_e1484");
extern unsigned char ref_t32_data_e1474[] __asm__("t32_data_e1474");
extern unsigned char ref_t32_data_e1464[] __asm__("t32_data_e1464");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
extern unsigned char ref_tisp_reg_write[] __asm__("tisp_reg_write");
extern unsigned char ref_t32_data_dc284[] __asm__("t32_data_dc284");
extern unsigned char ref_t32_data_e1460[] __asm__("t32_data_e1460");
u64 tisp_top_reg_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_29214 = ((u32)(unsigned long)ref_t32_data_e1484 + 0x8000U) & 0xffff0000U;
    const u32 hi_292d0 = ((u32)(unsigned long)ref_t32_data_e1474 + 0x8000U) & 0xffff0000U;
    const u32 hi_292f0 = ((u32)(unsigned long)ref_t32_data_e1464 + 0x8000U) & 0xffff0000U;
    const u32 hi_292e4 = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_29314 = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_29330 = ((u32)(unsigned long)ref_t32_data_dc284 + 0x8000U) & 0xffff0000U;
    const u32 hi_29374 = ((u32)(unsigned long)ref_t32_data_e1460 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_29210:
    sp = sp + -56;
    v0 = hi_29214;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    s2 = a0 & 0xff;
    a3 = s2 << (0x2 & 31);
    v0 = v0 - hi_29214 + (u32)(unsigned long)ref_t32_data_e1484;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    v0 = a3 + v0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    t0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = 0xfU << 16;
    v0 = 0;
    a1 = t0 + 4;
    s4 = 0;
    a2 = a2 | 0xffff;
    t2 = 1;
    t1 = 32;
L_29270:
    a0 = t2 << (v0 & 31);
    v1 = ~(0 | a0);
    a2 = v1 & a2;
    a0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v1 = v1 & s4;
    s4 = *(volatile u8 *)(unsigned long)(a1 + (32));
    a0 = a0 << (v0 & 31);
    a2 = a0 + a2;
    s4 = s4 << (v0 & 31);
    v0 = v0 + 1;
    s4 = s4 + v1;
    branch = (v0 != t1); a1 = a1 + 1;
    if (branch) goto L_29270;
    goto L_292a4;
L_292a4:
    a0 = 0;
    v0 = 0;
    a1 = 10;
L_292b0:
    v1 = t0 + a0;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (68));
    v1 = v1 << (a0 & 31);
    a0 = a0 + 1;
    branch = (a0 != a1); v0 = v0 | v1;
    if (branch) goto L_292b0;
    goto L_292c8;
L_292c8:
    a0 = s2 & 0x1;
    a1 = a0 << (0x2 & 31);
    a0 = hi_292d0;
    a0 = a0 - hi_292d0 + (u32)(unsigned long)ref_t32_data_e1474;
    a0 = a1 + a0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = v0 | 0x4;
    s3 = hi_292e4;
    v1 = v1 ^ 0x1;
    if (v1 == 0) v0 = a0;
    v1 = hi_292f0;
    v1 = v1 - hi_292f0 + (u32)(unsigned long)ref_t32_data_e1464;
    a1 = *(volatile u8 *)(unsigned long)(s3 - hi_292e4 + (u32)(unsigned long)ref_t32_data_d03a0);
    a3 = v1 + a3;
    *(volatile u32 *)(unsigned long)(a3 + (0)) = v0;
    s1 = v1;
    v0 = 64;
    v1 = 2;
    if (a1 != 0) v0 = v1;
    s0 = hi_29314;
    a1 = v0;
    s0 = s0 - hi_29314 + (u32)(unsigned long)ref_tisp_reg_write;
    callee = s0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_29328;
L_29328:
    v1 = 904;
    a0 = s2 * v1;
    v0 = hi_29330;
    v0 = v0 - hi_29330 + (u32)(unsigned long)ref_t32_data_dc284;
    s6 = 0;
    v1 = a0 + v0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (900));
    v1 = 0;
L_29348:
    a0 = (u32)v1 < (u32)(a1);
    branch = (a0 == 0); a0 = v1 << (0x2 & 31);
    if (branch) goto L_2936c;
    goto L_29354;
L_29354:
    a0 = s1 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = v1 + 1;
    v1 = v1 & 0xff;
    s6 = s6 | a0; goto L_29348;
L_2936c:
    s5 = 904;
    v1 = s2 * s5;
    s7 = hi_29374;
    s1 = 0;
    s7 = s7 - hi_29374 + (u32)(unsigned long)ref_t32_data_e1460;
    s8 = 1;
    s5 = v1 + v0;
L_29388:
    v1 = *(volatile u32 *)(unsigned long)(s5 + (900));
    v1 = (u32)s1 < (u32)(v1);
    branch = (v1 == 0); v0 = s1 + s7;
    if (branch) goto L_293d0;
    goto L_29398;
L_29398:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    if (v0 != s8) { s1 = s1 + 1; goto L_293c8; }
    goto L_293a4;
L_293a4:
    a1 = *(volatile u8 *)(unsigned long)(s3 - hi_292e4 + (u32)(unsigned long)ref_t32_data_d03a0);
    v0 = 96;
    v1 = 4;
    if (a1 != 0) v0 = v1;
    a2 = s6;
    a1 = v0;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_293c4;
L_293c4:
    s1 = s1 + 1;
L_293c8:
    s1 = s1 & 0xff; goto L_29388;
L_293d0:
    a1 = *(volatile u8 *)(unsigned long)(s3 - hi_292e4 + (u32)(unsigned long)ref_t32_data_d03a0);
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s8 = *(volatile u32 *)(unsigned long)(sp + (48));
    s7 = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    a2 = s4;
    v0 = 108;
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    v1 = 6;
    a0 = s2;
    t9 = s0;
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (a1 != 0) v0 = v1;
    a1 = v0;
    callee = t9; sp = sp + 56;
    switch (callee) { case 0x29210: goto L_29210; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
