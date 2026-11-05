/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d989c[] __asm__("t32_data_d989c");
extern unsigned char ref_t32_data_be390[] __asm__("t32_data_be390");
extern unsigned char ref_t32_data_c5b80[] __asm__("t32_data_c5b80");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
u64 ivdc_core_ops_ioctl(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_e700 = ((u32)(unsigned long)ref_t32_data_d989c + 0x8000U) & 0xffff0000U;
    const u32 hi_e778 = ((u32)(unsigned long)ref_t32_data_be390 + 0x8000U) & 0xffff0000U;
    const u32 hi_e77c = ((u32)(unsigned long)ref_t32_data_c5b80 + 0x8000U) & 0xffff0000U;
    const u32 hi_e780 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_e774 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_e7dc = ((u32)(unsigned long)ref_t32_data_d989c + 0x8000U) & 0xffff0000U;
    const u32 hi_e750 = ((u32)(unsigned long)ref_t32_data_be390 + 0x8000U) & 0xffff0000U;
    const u32 hi_e75c = ((u32)(unsigned long)ref_t32_data_c5b80 + 0x8000U) & 0xffff0000U;
    const u32 hi_e768 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_e6bc:
    v0 = 0x100U << 16;
    sp = sp + -24;
    a3 = v0 + 3;
    branch = (a1 == a3); *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    if (branch) goto L_e74c;
    goto L_e6d0;
L_e6d0:
    a3 = v0 + 4;
    a3 = (u32)a1 < (u32)(a3);
    branch = (a3 == 0); v1 = v0 + 14;
    if (branch) goto L_e6f0;
    goto L_e6e0;
L_e6e0:
    branch = (a1 == v0); ;
    if (branch) goto L_e70c;
    goto L_e6e8;
L_e6e8:
    v0 = 0; goto L_e7e8;
L_e6f0:
    branch = (a1 == v1); v0 = v0 + 15;
    if (branch) goto L_e7dc;
    goto L_e6f8;
L_e6f8:
    branch = (a1 != v0); v1 = 1;
    if (branch) goto L_e7e4;
    goto L_e700;
L_e700:
    v0 = hi_e700;
    *(volatile u32 *)(unsigned long)(v0 - hi_e700 + (u32)(unsigned long)ref_t32_data_d989c) = v1; goto L_e7e4;
L_e70c:
    branch = (a0 == 0); v0 = -19;
    if (branch) goto L_e7e8;
    goto L_e714;
L_e714:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (264));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    if (v0 == 0) { v0 = 0; goto L_e7e8; }
    goto L_e724;
L_e724:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    if (v0 == 0) { v0 = 0; goto L_e7e8; }
    goto L_e730;
L_e730:
    callee = v0; a1 = a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e738;
L_e738:
    v1 = -515;
    if (v0 == v1) { v0 = 0; goto L_e7e8; }
    goto L_e744;
L_e744:
    ra = *(volatile u32 *)(unsigned long)(sp + (20)); goto L_e7ec;
L_e74c:
    branch = (a0 == 0); a2 = hi_e750;
    if (branch) goto L_e77c;
    goto L_e754;
L_e754:
    v0 = (u32)a0 < (u32)(-4095);
    branch = (v0 == 0); a1 = hi_e75c;
    if (branch) goto L_e780;
    goto L_e760;
L_e760:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (280));
    branch = (v1 == 0); v0 = hi_e768;
    if (branch) goto L_e784;
    goto L_e76c;
L_e76c:
    v0 = (u32)v1 < (u32)(-4095);
    if (v0 != 0) { v0 = hi_e774; goto L_e7a4; }
    goto L_e778;
L_e778:
    a2 = hi_e778;
L_e77c:
    a1 = hi_e77c;
L_e780:
    v0 = hi_e780;
L_e784:
    a3 = 537;
    a2 = a2 - hi_e778 + (u32)(unsigned long)ref_t32_data_be390;
    a1 = a1 - hi_e77c + (u32)(unsigned long)ref_t32_data_c5b80;
    v0 = v0 - hi_e780 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_e79c;
L_e79c:
    v0 = -22; goto L_e7e8;
L_e7a4:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_e774 + (u32)(unsigned long)ref_t32_data_d9014);
    a0 = 1;
    branch = (v0 != a0); a0 = (s32)v0 < (s32)(2);
    if (branch) goto L_e7c0;
    goto L_e7b4;
L_e7b4:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (284));
    v1 = 7; goto L_e7d0;
L_e7c0:
    branch = (a0 != 0); v0 = 0;
    if (branch) goto L_e7e8;
    goto L_e7c8;
L_e7c8:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (284));
    v1 = 3;
L_e7d0:
    *(volatile u32 *)(unsigned long)(v0 + (100)) = v1;
    v0 = 0; goto L_e7e8;
L_e7dc:
    v0 = hi_e7dc;
    *(volatile u32 *)(unsigned long)(v0 - hi_e7dc + (u32)(unsigned long)ref_t32_data_d989c) = 0;
L_e7e4:
    v0 = 0;
L_e7e8:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
L_e7ec:
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
