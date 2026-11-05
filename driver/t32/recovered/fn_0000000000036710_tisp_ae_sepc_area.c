/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e1518[] __asm__("t32_data_e1518");
extern unsigned char ref_t32_data_e1524[] __asm__("t32_data_e1524");
extern unsigned char ref_t32_data_e151c[] __asm__("t32_data_e151c");
extern unsigned char ref_t32_data_e1520[] __asm__("t32_data_e1520");
extern unsigned char ref_tisp_ae_roi_point[] __asm__("tisp_ae_roi_point");
u64 tisp_ae_sepc_area(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_36718 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_36784 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_367b8 = ((u32)(unsigned long)ref_t32_data_e1518 + 0x8000U) & 0xffff0000U;
    const u32 hi_367c0 = ((u32)(unsigned long)ref_t32_data_e1524 + 0x8000U) & 0xffff0000U;
    const u32 hi_367c8 = ((u32)(unsigned long)ref_t32_data_e151c + 0x8000U) & 0xffff0000U;
    const u32 hi_36824 = ((u32)(unsigned long)ref_t32_data_e1520 + 0x8000U) & 0xffff0000U;
    const u32 hi_3688c = ((u32)(unsigned long)ref_tisp_ae_roi_point + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_36710:
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    s1 = hi_36718;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    s1 = s1 - hi_36718 + (u32)(unsigned long)ref_t32_data_e1588;
    s2 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    v0 = s2 + s1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = a1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (1520));
    if (a1 != v1) { *(volatile u32 *)(unsigned long)(v0 + (1520)) = v1; goto L_3674c; }
    goto L_3674c;
L_3674c:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (4));
    if (v1 != 0) { *(volatile u8 *)(unsigned long)(v0 + (2182)) = 0; goto L_36784; }
    goto L_36758;
L_36758:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (8));
    if (v1 != 0) { *(volatile u8 *)(unsigned long)(v0 + (2182)) = 0; goto L_36784; }
    goto L_36764;
L_36764:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (12));
    if (v1 != 0) { *(volatile u8 *)(unsigned long)(v0 + (2182)) = 0; goto L_36784; }
    goto L_36770;
L_36770:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (16));
    if (v1 != 0) { *(volatile u8 *)(unsigned long)(v0 + (2182)) = 0; goto L_36784; }
    goto L_3677c;
L_3677c:
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (2182)) = v1;
L_36784:
    v0 = hi_36784;
    v0 = v0 - hi_36784 + (u32)(unsigned long)ref_t32_data_e15a8;
    v0 = v0 + s2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t0 = 15;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a3 = *(volatile u32 *)(unsigned long)(s0 + (12));
    a2 = *(volatile u32 *)(unsigned long)(s0 + (8));
    v1 = *(volatile u16 *)(unsigned long)(v0 + (8548));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (8550));
    t3 = *(volatile u32 *)(unsigned long)(s0 + (16));
    if (t0) { lo = v1 / t0; hi = v1 % t0; } else { lo = ~0U; hi = v1; }
    t1 = hi_367b8;
    t1 = t1 - hi_367b8 + (u32)(unsigned long)ref_t32_data_e1518;
    t2 = hi_367c0;
    t2 = t2 - hi_367c0 + (u32)(unsigned long)ref_t32_data_e1524;
    t6 = hi_367c8;
    t6 = t6 - hi_367c8 + (u32)(unsigned long)ref_t32_data_e151c;
    t6 = a0 + t6;
    v1 = lo;
    if (t0) { lo = v0 / t0; hi = v0 % t0; } else { lo = ~0U; hi = v0; }
    t0 = a0 + t1;
    v0 = lo;
    if (v1) { lo = a1 / v1; hi = a1 % v1; } else { lo = ~0U; hi = a1; }
    t5 = lo;
    t5 = t5 & 0xff;
    *(volatile u8 *)(unsigned long)(t6 + (0)) = t5;
    if (v1) { lo = a3 / v1; hi = a3 % v1; } else { lo = ~0U; hi = a3; }
    t5 = (u32)t5 < (u32)(15);
    v1 = lo;
    v1 = v1 + 1;
    v1 = v1 & 0xff;
    if (v0) { lo = a2 / v0; hi = a2 % v0; } else { lo = ~0U; hi = a2; }
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v1;
    t0 = a0 + t2;
    t4 = lo;
    t4 = t4 & 0xff;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = t4;
    if (v0) { lo = t3 / v0; hi = t3 % v0; } else { lo = ~0U; hi = t3; }
    t0 = hi_36824;
    t0 = t0 - hi_36824 + (u32)(unsigned long)ref_t32_data_e1520;
    t7 = a0 + t0;
    v0 = lo;
    v0 = v0 + 1;
    v0 = v0 & 0xff;
    branch = (t5 != 0); *(volatile u8 *)(unsigned long)(t7 + (0)) = v0;
    if (branch) goto L_3684c;
    goto L_36844;
L_36844:
    t5 = 14;
    *(volatile u8 *)(unsigned long)(t6 + (0)) = t5;
L_3684c:
    t4 = (u32)t4 < (u32)(15);
    branch = (t4 != 0); v1 = (u32)v1 < (u32)(15);
    if (branch) goto L_36864;
    goto L_36858;
L_36858:
    t2 = t2 + a0;
    t4 = 14;
    *(volatile u8 *)(unsigned long)(t2 + (0)) = t4;
L_36864:
    branch = (v1 != 0); v0 = (u32)v0 < (u32)(15);
    if (branch) goto L_36878;
    goto L_3686c;
L_3686c:
    t1 = t1 + a0;
    v1 = 15;
    *(volatile u8 *)(unsigned long)(t1 + (0)) = v1;
L_36878:
    branch = (v0 != 0); t3 = t3 & 0xffff;
    if (branch) goto L_3688c;
    goto L_36880;
L_36880:
    t0 = t0 + a0;
    v0 = 15;
    *(volatile u8 *)(unsigned long)(t0 + (0)) = v0;
L_3688c:
    v0 = hi_3688c;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t3;
    a3 = a3 & 0xffff;
    a2 = a2 & 0xffff;
    a1 = a1 & 0xffff;
    v0 = v0 - hi_3688c + (u32)(unsigned long)ref_tisp_ae_roi_point;
    callee = v0; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_368ac;
L_368ac:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (20));
    v1 = (u32)v0 < (u32)(201);
    if (v1 != 0) { v0 = (u32)v0 < (u32)(10); goto L_368c4; }
    goto L_368bc;
L_368bc:
    v0 = 200; goto L_368cc;
L_368c4:
    branch = (v0 == 0); v0 = 10;
    if (branch) goto L_368d0;
    goto L_368cc;
L_368cc:
    *(volatile u32 *)(unsigned long)(s0 + (20)) = v0;
L_368d0:
    s1 = s1 + s2;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (20));
    *(volatile u8 *)(unsigned long)(v0 + (1296)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (4));
    *(volatile u32 *)(unsigned long)(v0 + (1500)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (8));
    *(volatile u32 *)(unsigned long)(v0 + (1504)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (12));
    *(volatile u32 *)(unsigned long)(v0 + (1508)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (16));
    *(volatile u32 *)(unsigned long)(v0 + (1512)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (20));
    *(volatile u32 *)(unsigned long)(v0 + (1516)) = v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
