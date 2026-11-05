/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_t32_data_be3f8[] __asm__("t32_data_be3f8");
extern unsigned char ref_t32_data_c537c[] __asm__("t32_data_c537c");
extern unsigned char ref_t32_data_d98b0[] __asm__("t32_data_d98b0");
extern unsigned char ref_t32_data_c53a0[] __asm__("t32_data_c53a0");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_c53c4[] __asm__("t32_data_c53c4");
u64 ivdc_prepare_module(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_d7c8 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_d7ec = ((u32)(unsigned long)ref_t32_data_be3f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_d7f0 = ((u32)(unsigned long)ref_t32_data_c537c + 0x8000U) & 0xffff0000U;
    const u32 hi_d7e8 = ((u32)(unsigned long)ref_t32_data_d98b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_d838 = ((u32)(unsigned long)ref_t32_data_be3f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_d83c = ((u32)(unsigned long)ref_t32_data_c53a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_d84c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_d864 = ((u32)(unsigned long)ref_t32_data_c53c4 + 0x8000U) & 0xffff0000U;
    const u32 hi_d868 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_d7dc = ((u32)(unsigned long)ref_t32_data_be3f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_d834 = ((u32)(unsigned long)ref_t32_data_be3f8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
    sp = sp + -24;
    v1 = 0;
    branch = (a0 == 0); *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    if (branch) goto L_d7c8;
    goto L_d7bc;
L_d7bc:
    v0 = (u32)a0 < (u32)(-4095);
    if (v0 != 0) { v1 = *(volatile u32 *)(unsigned long)(a0 + (280)); goto L_d7c8; }
    goto L_d7c8;
L_d7c8:
    v0 = hi_d7c8;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_d7c8 + (u32)(unsigned long)ref_t32_data_d9014);
    if (v0 == 0) { ra = *(volatile u32 *)(unsigned long)(sp + (20)); goto L_d88c; }
    goto L_d7d8;
L_d7d8:
    branch = (v1 == 0); a2 = hi_d7dc;
    if (branch) goto L_d7f0;
    goto L_d7e0;
L_d7e0:
    v0 = (u32)v1 < (u32)(-4095);
    if (v0 != 0) { v0 = hi_d7e8; goto L_d804; }
    goto L_d7ec;
L_d7ec:
    a2 = hi_d7ec;
L_d7f0:
    a1 = hi_d7f0;
    a3 = 659;
    a2 = a2 - hi_d7ec + (u32)(unsigned long)ref_t32_data_be3f8;
    a1 = a1 - hi_d7f0 + (u32)(unsigned long)ref_t32_data_c537c; goto L_d84c;
L_d804:
    a1 = *(volatile u32 *)(unsigned long)(v0 - hi_d7e8 + (u32)(unsigned long)ref_t32_data_d98b0);
    branch = (a1 == 0); a2 = 1708;
    if (branch) goto L_d838;
    goto L_d810;
L_d810:
    v0 = 0;
L_d814:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (284));
    a0 = a0 + v0;
    a3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a1 + v0;
    v0 = v0 + 4;
    branch = (v0 != a2); *(volatile u32 *)(unsigned long)(a0 + (0)) = a3;
    if (branch) goto L_d814;
    goto L_d830;
L_d830:
    a2 = hi_d834; goto L_d864;
L_d838:
    a2 = hi_d838;
    a1 = hi_d83c;
    a3 = 671;
    a2 = a2 - hi_d838 + (u32)(unsigned long)ref_t32_data_be3f8;
    a1 = a1 - hi_d83c + (u32)(unsigned long)ref_t32_data_c53a0;
L_d84c:
    v0 = hi_d84c;
    v0 = v0 - hi_d84c + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_d85c;
L_d85c:
    v0 = -22; goto L_d888;
L_d864:
    a1 = hi_d864;
    v0 = hi_d868;
    a3 = 674;
    a2 = a2 - hi_d838 + (u32)(unsigned long)ref_t32_data_be3f8;
    a1 = a1 - hi_d864 + (u32)(unsigned long)ref_t32_data_c53c4;
    v0 = v0 - hi_d868 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_d884;
L_d884:
    v0 = 0;
L_d888:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
L_d88c:
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
