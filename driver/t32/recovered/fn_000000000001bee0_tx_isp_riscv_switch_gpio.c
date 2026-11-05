/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_da798[] __asm__("t32_data_da798");
extern unsigned char ref_t32_data_bee08[] __asm__("t32_data_bee08");
extern unsigned char ref_t32_data_c799c[] __asm__("t32_data_c799c");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 tx_isp_riscv_switch_gpio(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1bee0 = ((u32)(unsigned long)ref_t32_data_da798 + 0x8000U) & 0xffff0000U;
    const u32 hi_1bef4 = ((u32)(unsigned long)ref_t32_data_bee08 + 0x8000U) & 0xffff0000U;
    const u32 hi_1bef8 = ((u32)(unsigned long)ref_t32_data_c799c + 0x8000U) & 0xffff0000U;
    const u32 hi_1befc = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
    stack[10] = arg4;
L_1bee0:
    v0 = hi_1bee0;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_1bee0 + (u32)(unsigned long)ref_t32_data_da798);
    sp = sp + -24;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    if (branch) goto L_1bf20;
    goto L_1bef4;
L_1bef4:
    a2 = hi_1bef4;
    a1 = hi_1bef8;
    v0 = hi_1befc;
    a3 = 237;
    a2 = a2 - hi_1bef4 + (u32)(unsigned long)ref_t32_data_bee08;
    a1 = a1 - hi_1bef8 + (u32)(unsigned long)ref_t32_data_c799c;
    v0 = v0 - hi_1befc + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1bf18;
L_1bf18:
    v0 = -22; goto L_1bf50;
L_1bf20:
    v1 = 3;
    v0 = 0;
    v0 = (v0 & ~(((1U << 0x8) - 1) << 0x0)) | ((v1 & ((1U << 0x8) - 1)) << 0x0);
    v0 = (v0 & ~(((1U << 0x8) - 1) << 0x8)) | ((a1 & ((1U << 0x8) - 1)) << 0x8);
    v1 = *(volatile u32 *)(unsigned long)(sp + (40));
    v0 = (v0 & ~(((1U << 0x8) - 1) << 0x10)) | ((a3 & ((1U << 0x8) - 1)) << 0x10);
    v0 = (v0 & ~(((1U << 0x4) - 1) << 0x18)) | ((a0 & ((1U << 0x4) - 1)) << 0x18);
    v0 = (v0 & ~(((1U << 0x2) - 1) << 0x1c)) | ((a2 & ((1U << 0x2) - 1)) << 0x1c);
    v0 = (v0 & ~(((1U << 0x2) - 1) << 0x1e)) | ((v1 & ((1U << 0x2) - 1)) << 0x1e);
    v1 = 0xb222U << 16;
    *(volatile u32 *)(unsigned long)(v1 + (8)) = v0;
    v0 = 0;
L_1bf50:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
