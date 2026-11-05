/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
extern unsigned char ref___udelay[] __asm__("__udelay");
extern unsigned char ref_private_msleep[] __asm__("private_msleep");
extern unsigned char ref___private_spin_lock_irqsave[] __asm__("__private_spin_lock_irqsave");
extern unsigned char ref_private_spin_unlock_irqrestore[] __asm__("private_spin_unlock_irqrestore");
extern unsigned char ref_t32_data_c47a0[] __asm__("t32_data_c47a0");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_c47bc[] __asm__("t32_data_c47bc");
extern unsigned char ref_t32_data_c47d8[] __asm__("t32_data_c47d8");
u64 mipi_phy_stream_on_constprop_5(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_79c4 = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_79d4 = (((u32)(unsigned long)ref___udelay + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_79d0 = ((u32)(unsigned long)ref_private_msleep + 0x8000U) & 0xffff0000U;
    const u32 hi_7a00 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_7a24 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_7b28 = ((u32)(unsigned long)ref_t32_data_c47a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_7b94 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_7bdc = ((u32)(unsigned long)ref_t32_data_c47bc + 0x8000U) & 0xffff0000U;
    const u32 hi_7be0 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_7c1c = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_7c2c = (((u32)(unsigned long)ref___udelay + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7c28 = ((u32)(unsigned long)ref_private_msleep + 0x8000U) & 0xffff0000U;
    const u32 hi_7c6c = ((u32)(unsigned long)ref_t32_data_c47a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_7c80 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_7d8c = ((u32)(unsigned long)ref_t32_data_c47d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_7de8 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_7e08 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_7908:
    sp = sp + -56;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    branch = (a0 == 0); s0 = 0;
    if (branch) goto L_7940;
    goto L_7934;
L_7934:
    v0 = (u32)a0 < (u32)(-4095);
    if (v0 != 0) { s0 = *(volatile u32 *)(unsigned long)(a0 + (280)); goto L_7940; }
    goto L_7940;
L_7940:
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    branch = (s0 == 0); s1 = -22;
    if (branch) goto L_7e1c;
    goto L_794c;
L_794c:
    v0 = (u32)s0 < (u32)(-4095);
    branch = (v0 == 0); ra = *(volatile u32 *)(unsigned long)(sp + (52));
    if (branch) goto L_7e20;
    goto L_7958;
L_7958:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (4));
    v0 = v1 + 176;
    v0 = v0 << (0x2 & 31);
    v0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = (s32)v0 < (s32)(2);
    branch = (v0 != 0); s1 = 0;
    if (branch) goto L_7e20;
    goto L_7978;
L_7978:
    s1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    branch = (s1 == 0); v0 = s1;
    if (branch) goto L_7e24;
    goto L_7984;
L_7984:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (860));
    a0 = 1;
    branch = (v0 != a0); s1 = a1;
    if (branch) goto L_7bfc;
    goto L_7994;
L_7994:
    a0 = 104;
    a1 = v1 * a0;
    v1 = a1 + s0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (340));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (20));
    branch = (a2 != v0); v0 = 2;
    if (branch) goto L_7bd4;
    goto L_79b0;
L_79b0:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (856));
    branch = (v0 != 0); s3 = *(volatile u8 *)(unsigned long)(v1 + (40));
    if (branch) goto L_7a34;
    goto L_79bc;
L_79bc:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    *(volatile u32 *)(unsigned long)(v0 + (12)) = 0;
    v0 = hi_79c4;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_79c4 + (u32)(unsigned long)ref_t32_data_d9008);
    if (v0 == 0) { v0 = hi_79d0; goto L_79e4; }
    goto L_79d4;
L_79d4:
    v0 = hi_79d4;
    a0 = 1000;
    v0 = v0 - hi_79d4 + ((u32)(unsigned long)ref___udelay + (0)); goto L_79ec;
L_79e4:
    a0 = 1;
    v0 = v0 - hi_79d0 + (u32)(unsigned long)ref_private_msleep;
L_79ec:
    callee = v0; s2 = s0 + 732;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_79f4;
L_79f4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    v1 = 1;
    *(volatile u32 *)(unsigned long)(v0 + (12)) = v1;
    v0 = hi_7a00;
    a1 = sp + 16;
    v0 = v0 - hi_7a00 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7a14;
L_7a14:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (856));
    a1 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s0 + (856)) = v0;
    v0 = hi_7a24;
    v0 = v0 - hi_7a24 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7a34;
L_7a34:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    a1 = 104;
    v1 = v0 * a1;
    v0 = v1 + s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (340));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (41));
    v0 = s3 << (0x2 & 31);
    v0 = s0 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (244));
    a0 = a0 + -1;
    *(volatile u32 *)(unsigned long)(v1 + (4)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    a0 = v1 * a1;
    v1 = a0 + s0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (340));
    a0 = 4;
    a1 = *(volatile u8 *)(unsigned long)(v1 + (41));
    branch = (a1 != a0); v1 = *(volatile u32 *)(unsigned long)(v0 + (244));
    if (branch) goto L_7a88;
    goto L_7a80;
L_7a80:
    a0 = 15; goto L_7a8c;
L_7a88:
    a0 = 3;
L_7a8c:
    *(volatile u32 *)(unsigned long)(v1 + (256)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (244));
    *(volatile u32 *)(unsigned long)(v1 + (8)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (244));
    *(volatile u32 *)(unsigned long)(v1 + (16)) = 0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (244));
    v1 = 1;
    *(volatile u32 *)(unsigned long)(a0 + (16)) = v1;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (244));
    a0 = -1;
    *(volatile u32 *)(unsigned long)(a1 + (40)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (244));
    *(volatile u32 *)(unsigned long)(v0 + (44)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    a0 = 125;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    branch = (s3 != v1); v0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    if (branch) goto L_7ae4;
    goto L_7ad4;
L_7ad4:
    *(volatile u32 *)(unsigned long)(v0 + (128)) = s3;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    v1 = 95; goto L_7af0;
L_7ae4:
    *(volatile u32 *)(unsigned long)(v0 + (128)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    v1 = 31;
L_7af0:
    *(volatile u32 *)(unsigned long)(v0 + (128)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    v1 = 104;
    a0 = v0 * v1;
    v0 = a0 + s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (340));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (40));
    branch = (v0 != 0); v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    if (branch) goto L_7b1c;
    goto L_7b14;
L_7b14:
    v0 = 63; goto L_7b20;
L_7b1c:
    v0 = 15;
L_7b20:
    *(volatile u32 *)(unsigned long)(v1 + (296)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    a1 = hi_7b28;
    a1 = a1 - hi_7b28 + (u32)(unsigned long)ref_t32_data_c47a0;
    *(volatile u32 *)(unsigned long)(v1 + (424)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (552)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (680)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (808)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (936)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    v1 = 104;
    a0 = v0 * v1;
    v0 = a0 + s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (340));
    a0 = 0;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (28));
    v0 = 115;
    s1 = v0 * s1;
    v0 = 4000;
    if (s1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)s1 / (s32)v0; hi = (s32)s1 % (s32)v0; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    v0 = 255;
    s1 = lo;
    s1 = s1 + -3;
    v1 = (u32)s1 < (u32)(256);
    if (v1 == 0) s1 = v0;
    v0 = hi_7b94;
    v0 = v0 - hi_7b94 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a2 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7ba4;
L_7ba4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (352)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (480)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (608)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (736)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (864)) = s1;
    s1 = 0; goto L_7e1c;
L_7bd4:
    branch = (a2 == v0); s1 = 0;
    if (branch) goto L_7e1c;
    goto L_7bdc;
L_7bdc:
    a1 = hi_7bdc;
    v0 = hi_7be0;
    a1 = a1 - hi_7bdc + (u32)(unsigned long)ref_t32_data_c47bc;
    v0 = v0 - hi_7be0 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7bf4;
L_7bf4:
    ra = *(volatile u32 *)(unsigned long)(sp + (52)); goto L_7e20;
L_7bfc:
    v1 = 2;
    branch = (v0 != v1); s1 = 0;
    if (branch) goto L_7e1c;
    goto L_7c08;
L_7c08:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (856));
    branch = (v0 != 0); ra = *(volatile u32 *)(unsigned long)(sp + (52));
    if (branch) goto L_7e20;
    goto L_7c14;
L_7c14:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    *(volatile u32 *)(unsigned long)(v0 + (12)) = 0;
    v0 = hi_7c1c;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_7c1c + (u32)(unsigned long)ref_t32_data_d9008);
    if (v0 == 0) { v0 = hi_7c28; goto L_7c3c; }
    goto L_7c2c;
L_7c2c:
    v0 = hi_7c2c;
    a0 = 1000;
    v0 = v0 - hi_7c2c + ((u32)(unsigned long)ref___udelay + (0)); goto L_7c44;
L_7c3c:
    a0 = 1;
    v0 = v0 - hi_7c28 + (u32)(unsigned long)ref_private_msleep;
L_7c44:
    callee = v0; s2 = 115;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7c4c;
L_7c4c:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (244));
    v0 = 1;
    *(volatile u32 *)(unsigned long)(v1 + (12)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (340));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    s4 = 4000;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (41));
    s6 = 255;
    a1 = hi_7c6c;
    v1 = v1 + -1;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (444));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (248));
    s5 = hi_7c80;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (41));
    a1 = a1 - hi_7c6c + (u32)(unsigned long)ref_t32_data_c47a0;
    s5 = s5 - hi_7c80 + (u32)(unsigned long)ref_isp_printf;
    v1 = v1 + -1;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    v1 = 3;
    *(volatile u32 *)(unsigned long)(a0 + (256)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (248));
    *(volatile u32 *)(unsigned long)(a0 + (256)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (244));
    *(volatile u32 *)(unsigned long)(v1 + (8)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (248));
    *(volatile u32 *)(unsigned long)(v1 + (8)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (244));
    *(volatile u32 *)(unsigned long)(v1 + (16)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (248));
    *(volatile u32 *)(unsigned long)(v1 + (16)) = 0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (244));
    *(volatile u32 *)(unsigned long)(v1 + (16)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (248));
    *(volatile u32 *)(unsigned long)(v1 + (16)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    v1 = -1;
    *(volatile u32 *)(unsigned long)(a0 + (40)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (248));
    *(volatile u32 *)(unsigned long)(a0 + (40)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (244));
    *(volatile u32 *)(unsigned long)(a0 + (44)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (248));
    *(volatile u32 *)(unsigned long)(a0 + (44)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    a0 = 125;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (244));
    a0 = 0;
    *(volatile u32 *)(unsigned long)(v1 + (128)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    v1 = 95;
    *(volatile u32 *)(unsigned long)(v0 + (128)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    v0 = 15;
    *(volatile u32 *)(unsigned long)(v1 + (296)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (424)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (552)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (680)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (808)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v1 + (936)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (444));
    s3 = *(volatile u32 *)(unsigned long)(v0 + (28));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (340));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (28));
    s1 = s2 * s1;
    if (s1 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)s1 / (s32)s4; hi = (s32)s1 % (s32)s4; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    s1 = lo;
    s1 = s1 + -3;
    v0 = (u32)s1 < (u32)(256);
    s2 = s3 * s2;
    if (v0 == 0) s1 = s6;
    callee = s5; a2 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7d8c;
L_7d8c:
    a1 = hi_7d8c;
    a1 = a1 - hi_7d8c + (u32)(unsigned long)ref_t32_data_c47d8;
    a0 = 0;
    if (s2 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)s2 / (s32)s4; hi = (s32)s2 % (s32)s4; } else { lo = (s32)s2 < 0 ? 1 : ~0U; hi = s2; }
    s2 = lo;
    s2 = s2 + -3;
    v0 = (u32)s2 < (u32)(256);
    if (v0 == 0) s2 = s6;
    callee = s5; a2 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7db4;
L_7db4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    a1 = sp + 16;
    *(volatile u32 *)(unsigned long)(v0 + (352)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (480)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (608)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    s1 = s0 + 732;
    a0 = s1;
    *(volatile u32 *)(unsigned long)(v0 + (736)) = s2;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (736));
    *(volatile u32 *)(unsigned long)(v0 + (864)) = s2;
    v0 = hi_7de8;
    v0 = v0 - hi_7de8 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7df8;
L_7df8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (856));
    a1 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s0 + (856)) = v0;
    v0 = hi_7e08;
    v0 = v0 - hi_7e08 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7e18;
L_7e18:
    s1 = 0;
L_7e1c:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
L_7e20:
    v0 = s1;
L_7e24:
    s6 = *(volatile u32 *)(unsigned long)(sp + (48));
    s5 = *(volatile u32 *)(unsigned long)(sp + (44));
    s4 = *(volatile u32 *)(unsigned long)(sp + (40));
    s3 = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
