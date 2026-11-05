/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
u64 tisp_awb_get_global_statis(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3f29c = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_3f29c:
    v0 = hi_3f29c;
    v0 = v0 - hi_3f29c + (u32)(unsigned long)ref_t32_data_e16b4;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = 0x2U << 16;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (4));
    v0 = v0 + v1;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-23452));
    v0 = 0x1U << 16;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(a0 + (4));
    a2 = a2 + v1;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (-23450));
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(a1 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (4));
    v0 = v0 + v1;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (-23464));
    *(volatile u32 *)(unsigned long)(a1 + (8)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (4));
    v1 = v0 + v1;
    v0 = *(volatile u16 *)(unsigned long)(v1 + (-23462));
    *(volatile u32 *)(unsigned long)(a1 + (12)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
