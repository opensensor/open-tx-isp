/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
extern unsigned char ref_t32_data_e275c[] __asm__("t32_data_e275c");
u64 tisp_msca_set_mirr_flip(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_86480 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    const u32 hi_86558 = ((u32)(unsigned long)ref_t32_data_e275c + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_86480:
    v0 = hi_86480;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_86480 + (u32)(unsigned long)ref_t32_data_e2768;
    v0 = v1 + v0;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a2 = 872;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t0 = (v1 >> 0x2) & ((1U << 0x1) - 1);
    v1 = v1 & 0x3;
    a3 = v1 * a2;
    v1 = a3 + v0;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (48));
    a3 = (a3 & ~(((1U << 0x1) - 1) << 0x0)) | ((t0 & ((1U << 0x1) - 1)) << 0x0);
    *(volatile u8 *)(unsigned long)(v1 + (48)) = a3;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t0 = (v1 >> 0x3) & ((1U << 0x1) - 1);
    v1 = v1 & 0x3;
    a3 = v1 * a2;
    v1 = a3 + v0;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (48));
    a3 = (a3 & ~(((1U << 0x1) - 1) << 0x1)) | ((t0 & ((1U << 0x1) - 1)) << 0x1);
    *(volatile u8 *)(unsigned long)(v1 + (48)) = a3;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t0 = (v1 >> 0x4) & ((1U << 0x1) - 1);
    v1 = v1 & 0x3;
    a3 = v1 * a2;
    v1 = a3 + v0;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (48));
    a3 = (a3 & ~(((1U << 0x1) - 1) << 0x2)) | ((t0 & ((1U << 0x1) - 1)) << 0x2);
    *(volatile u8 *)(unsigned long)(v1 + (48)) = a3;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t0 = (v1 >> 0x5) & ((1U << 0x1) - 1);
    v1 = v1 & 0x3;
    a3 = v1 * a2;
    v1 = a3 + v0;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (48));
    a3 = (a3 & ~(((1U << 0x1) - 1) << 0x3)) | ((t0 & ((1U << 0x1) - 1)) << 0x3);
    *(volatile u8 *)(unsigned long)(v1 + (48)) = a3;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t0 = (v1 >> 0x6) & ((1U << 0x1) - 1);
    v1 = v1 & 0x3;
    a3 = v1 * a2;
    v1 = a3 + v0;
    a3 = *(volatile u8 *)(unsigned long)(v1 + (48));
    a3 = (a3 & ~(((1U << 0x1) - 1) << 0x4)) | ((t0 & ((1U << 0x1) - 1)) << 0x4);
    *(volatile u8 *)(unsigned long)(v1 + (48)) = a3;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a1 = (v1 >> 0x7) & ((1U << 0x1) - 1);
    v1 = v1 & 0x3;
    a3 = v1 * a2;
    v0 = a3 + v0;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (48));
    v1 = (v1 & ~(((1U << 0x1) - 1) << 0x5)) | ((a1 & ((1U << 0x1) - 1)) << 0x5);
    *(volatile u8 *)(unsigned long)(v0 + (48)) = v1;
    v0 = hi_86558;
    v0 = v0 - hi_86558 + (u32)(unsigned long)ref_t32_data_e275c;
    a0 = a0 + v0;
    v0 = 1;
    *(volatile u8 *)(unsigned long)(a0 + (0)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
