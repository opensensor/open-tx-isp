/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_f0904[] __asm__("t32_data_f0904");
u64 tisp_g_module_ratio_attr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b2138 = ((u32)(unsigned long)ref_t32_data_f0904 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_b2138:
    v0 = hi_b2138;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b2138 + (u32)(unsigned long)ref_t32_data_f0904);
    a0 = a0 << (0x7 & 31);
    a0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (1060));
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (1064));
    *(volatile u8 *)(unsigned long)(a1 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (1068));
    *(volatile u32 *)(unsigned long)(a1 + (8)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (1072));
    *(volatile u8 *)(unsigned long)(a1 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (1076));
    *(volatile u32 *)(unsigned long)(a1 + (16)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (1080));
    *(volatile u8 *)(unsigned long)(a1 + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (1084));
    *(volatile u32 *)(unsigned long)(a1 + (24)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (1088));
    *(volatile u8 *)(unsigned long)(a1 + (28)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (1092));
    *(volatile u32 *)(unsigned long)(a1 + (32)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (1096));
    *(volatile u8 *)(unsigned long)(a1 + (36)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
