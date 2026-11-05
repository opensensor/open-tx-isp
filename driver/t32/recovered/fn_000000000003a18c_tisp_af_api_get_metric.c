/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1620[] __asm__("t32_data_e1620");
extern unsigned char ref_t32_data_d5c60[] __asm__("t32_data_d5c60");
u64 tisp_af_api_get_metric(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3a194 = ((u32)(unsigned long)ref_t32_data_e1620 + 0x8000U) & 0xffff0000U;
    const u32 hi_3a1a8 = ((u32)(unsigned long)ref_t32_data_d5c60 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_3a18c:
    t0 = 24;
    t2 = a0 * t0;
    v0 = hi_3a194;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_3a194 + (u32)(unsigned long)ref_t32_data_e1620;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = hi_3a1a8;
    v1 = v1 - hi_3a1a8 + (u32)(unsigned long)ref_t32_data_d5c60;
    t1 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a0 = t2 + v1;
    t0 = *(volatile u8 *)(unsigned long)(a0 + (9));
    v1 = *(volatile u32 *)(unsigned long)(t1 + (68));
    v1 = v1 >> (t0 & 31);
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (9));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (64));
    v1 = v1 >> (a0 & 31);
    *(volatile u32 *)(unsigned long)(a2 + (0)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (5400));
    *(volatile u8 *)(unsigned long)(a3 + (0)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
