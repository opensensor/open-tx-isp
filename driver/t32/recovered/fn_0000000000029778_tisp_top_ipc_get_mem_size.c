/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dc0a8[] __asm__("t32_data_dc0a8");
u64 tisp_top_ipc_get_mem_size(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_29798 = ((u32)(unsigned long)ref_t32_data_dc0a8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_29778:
    a0 = a0 & 0xffff;
    a1 = a1 & 0xffff;
    v0 = a0 * a1;
    v1 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = v0 + 1;
    v1 = 2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = hi_29798;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(v1 - hi_29798 + (u32)(unsigned long)ref_t32_data_dc0a8) = v0;
    return ((u64)v1 << 32) | v0;
}
