/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_da760[] __asm__("t32_data_da760");
u64 sensor_set_analog_gain_short(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_14f54 = ((u32)(unsigned long)ref_t32_data_da760 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a2 = 104;
    v0 = hi_14f54;
    a3 = v1 * a2;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_14f54 + (u32)(unsigned long)ref_t32_data_da760);
    v1 = a3 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (376));
    a3 = a0 << (0x10 & 31);
    a2 = *(volatile u16 *)(unsigned long)(v1 + (252));
    a2 = a2 | a3;
    *(volatile u32 *)(unsigned long)(v1 + (252)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (168));
    branch = (a0 == a2); a2 = 96;
    if (branch) goto L_14fd0;
    goto L_14f84;
L_14f84:
    *(volatile u32 *)(unsigned long)(v1 + (168)) = a0;
    a3 = *(volatile u32 *)(unsigned long)(a1 + (0));
    t0 = a3 * a2;
    a3 = t0 + v0;
    t0 = 1;
    *(volatile u32 *)(unsigned long)(a3 + (1312)) = t0;
    a3 = *(volatile u32 *)(unsigned long)(a1 + (0));
    t1 = a3 * a2;
    a3 = t1 + v0;
    *(volatile u32 *)(unsigned long)(a3 + (1316)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a3 = a0 * a2;
    a0 = a3 + v0;
    *(volatile u32 *)(unsigned long)(a0 + (1360)) = t0;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (252));
    a1 = a0 * a2;
    v0 = a1 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (1364)) = v1;
L_14fd0:
    ;
    return ((u64)v1 << 32) | v0;
}
