/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_dd0a4[] __asm__("t32_data_dd0a4");
u64 tisp_ae_api_get_antiflick(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_346b0 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_34700 = ((u32)(unsigned long)ref_t32_data_dd0a4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_346b0:
    v0 = hi_346b0;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_346b0 + (u32)(unsigned long)ref_t32_data_e15a8;
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = *(volatile u16 *)(unsigned long)(v1 + (2920));
    if (a2 != 0) { v1 = *(volatile u16 *)(unsigned long)(v1 + (2922)); goto L_346e0; }
    goto L_346d4;
L_346d4:
    *(volatile u32 *)(unsigned long)(a1 + (0)) = 0;
    *(volatile u8 *)(unsigned long)(a1 + (4)) = 0;
    return ((u64)v1 << 32) | v0;
L_346e0:
    if (v1 != 0) { v0 = 1; goto L_346fc; }
    goto L_346e8;
L_346e8:
    v1 = 2;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (1660)); goto L_34714;
L_346fc:
    *(volatile u32 *)(unsigned long)(a1 + (0)) = v0;
    v0 = hi_34700;
    v0 = v0 - hi_34700 + (u32)(unsigned long)ref_t32_data_dd0a4;
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (1764));
L_34714:
    *(volatile u8 *)(unsigned long)(a1 + (4)) = v0;
    return ((u64)v1 << 32) | v0;
}
