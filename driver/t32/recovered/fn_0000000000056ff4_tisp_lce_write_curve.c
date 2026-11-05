/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1da8[] __asm__("t32_data_e1da8");
extern unsigned char ref_t32_data_e1db8[] __asm__("t32_data_e1db8");
u64 tisp_lce_write_curve(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_56ff4 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    const u32 hi_57010 = ((u32)(unsigned long)ref_t32_data_e1db8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_56ff4:
    v0 = hi_56ff4;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_56ff4 + (u32)(unsigned long)ref_t32_data_e1da8;
    v0 = v1 + v0;
    v1 = 36;
    a1 = a0 * v1;
    a3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_57010;
    v0 = v0 - hi_57010 + (u32)(unsigned long)ref_t32_data_e1db8;
    t3 = 20;
    a0 = a1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (12));
    v0 = 0x1U << 16;
    v0 = v0 | 0xc2a4;
    a2 = a3 + v0;
    t1 = v0 + 11520;
    v0 = v1 - v0;
    t1 = a3 + t1;
    a3 = v0 - a3;
    a1 = a2;
L_57044:
    t0 = 0;
    t2 = a3 + a2;
L_5704c:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (1));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t4 = t2 + t0;
    a0 = v0 << (0x8 & 31);
    v0 = *(volatile u8 *)(unsigned long)(a1 + (2));
    t0 = t0 + 4;
    a1 = a1 + 4;
    v0 = v0 << (0x10 & 31);
    v0 = a0 | v0;
    v1 = v0 | v1;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (-1));
    v0 = v0 << (0x18 & 31);
    v0 = v1 | v0;
    branch = (t0 != t3); *(volatile u32 *)(unsigned long)(t4 + (11520)) = v0;
    if (branch) goto L_5704c;
    goto L_57088;
L_57088:
    a2 = a2 + 20;
    branch = (a2 != t1); a1 = a2;
    if (branch) goto L_57044;
    goto L_57094;
L_57094:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
