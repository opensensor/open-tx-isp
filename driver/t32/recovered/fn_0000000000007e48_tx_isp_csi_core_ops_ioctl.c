/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_bdad0[] __asm__("t32_data_bdad0");
extern unsigned char ref_t32_data_c4768[] __asm__("t32_data_c4768");
extern unsigned char ref_mipi_phy_stream_on_constprop_5[] __asm__("mipi_phy_stream_on_constprop_5");
extern unsigned char ref_t32_data_c47f4[] __asm__("t32_data_c47f4");
extern unsigned char ref_t32_data_c4818[] __asm__("t32_data_c4818");
u64 tx_isp_csi_core_ops_ioctl(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7e60 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_7e70 = ((u32)(unsigned long)ref_t32_data_bdad0 + 0x8000U) & 0xffff0000U;
    const u32 hi_7ea0 = ((u32)(unsigned long)ref_t32_data_c4768 + 0x8000U) & 0xffff0000U;
    const u32 hi_7ec8 = ((u32)(unsigned long)ref_mipi_phy_stream_on_constprop_5 + 0x8000U) & 0xffff0000U;
    const u32 hi_7ee0 = ((u32)(unsigned long)ref_t32_data_c47f4 + 0x8000U) & 0xffff0000U;
    const u32 hi_7f00 = ((u32)(unsigned long)ref_t32_data_c4818 + 0x8000U) & 0xffff0000U;
    const u32 hi_7e84 = ((u32)(unsigned long)ref_t32_data_c4768 + 0x8000U) & 0xffff0000U;
    const u32 hi_7e90 = ((u32)(unsigned long)ref_t32_data_c4768 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_7e48:
    v1 = 0x100U << 16;
    v1 = v1 + 3;
    branch = (a1 != v1); ;
    if (branch) goto L_7f24;
    goto L_7e58;
L_7e58:
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    s0 = hi_7e60;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    s2 = hi_7e70;
    branch = (a0 == 0); s0 = s0 - hi_7e60 + (u32)(unsigned long)ref_isp_printf;
    if (branch) goto L_7ea0;
    goto L_7e7c;
L_7e7c:
    v1 = (u32)a0 < (u32)(-4095);
    if (v1 == 0) { a1 = hi_7e84; goto L_7ea4; }
    goto L_7e88;
L_7e88:
    s1 = *(volatile u32 *)(unsigned long)(a0 + (280));
    if (s1 == 0) { a1 = hi_7e90; goto L_7ea4; }
    goto L_7e94;
L_7e94:
    v0 = (u32)s1 < (u32)(-4095);
    if (v0 != 0) { v0 = 1; goto L_7eb4; }
    goto L_7ea0;
L_7ea0:
    a1 = hi_7ea0;
L_7ea4:
    a3 = 503;
    a2 = s2 - hi_7e70 + (u32)(unsigned long)ref_t32_data_bdad0;
    a1 = a1 - hi_7ea0 + (u32)(unsigned long)ref_t32_data_c4768; goto L_7ef0;
L_7eb4:
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (856));
    *(volatile u32 *)(unsigned long)(sp + (28)) = 0;
    v0 = v0 + -1;
    *(volatile u32 *)(unsigned long)(s1 + (856)) = v0;
    v0 = hi_7ec8;
    v0 = v0 - hi_7ec8 + (u32)(unsigned long)ref_mipi_phy_stream_on_constprop_5;
    callee = v0; a1 = sp + 24;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7ed8;
L_7ed8:
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (856)); goto L_7f00; }
    goto L_7ee0;
L_7ee0:
    a1 = hi_7ee0;
    a3 = 512;
    a2 = s2 - hi_7e70 + (u32)(unsigned long)ref_t32_data_bdad0;
    a1 = a1 - hi_7ee0 + (u32)(unsigned long)ref_t32_data_c47f4;
L_7ef0:
    callee = s0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7ef8;
L_7ef8:
    v0 = -22; goto L_7f2c;
L_7f00:
    a1 = hi_7f00;
    a3 = 515;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a2 = s2 - hi_7e70 + (u32)(unsigned long)ref_t32_data_bdad0;
    a1 = a1 - hi_7f00 + (u32)(unsigned long)ref_t32_data_c4818;
    callee = s0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7f1c;
L_7f1c:
    v0 = 0; goto L_7f2c;
L_7f24:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
L_7f2c:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
