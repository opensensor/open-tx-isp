/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2194[] __asm__("t32_data_e2194");
u64 tisp_mdns_reg_cfg_equation_smp_15(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_604f8 = ((u32)(unsigned long)ref_t32_data_e2194 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_604c8:
    v0 = (s32)a0 < (s32)(15);
    v1 = 14;
    if (v0 == 0) a0 = v1;
    t2 = a3 - a2;
    t3 = -a0;
    t3 = t3 * t2;
    v1 = (s32)a0 < (s32)(a1);
    v0 = a0 + 1;
    if (v1 == 0) a1 = v0;
    v1 = (s32)a1 < (s32)(15);
    v0 = 15;
    if (v1 == 0) a1 = v0;
    v0 = hi_604f8;
    v0 = v0 - hi_604f8 + (u32)(unsigned long)ref_t32_data_e2194;
    a1 = a1 - a0;
    t1 = 0;
    t0 = 0;
    t4 = v0;
    t5 = 15;
L_60514:
    v1 = (s32)a0 < (s32)(t0);
    branch = (v1 != 0); v1 = t1 + t3;
    if (branch) goto L_60528;
    goto L_60520;
L_60520:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a2; goto L_6054c;
L_60528:
    if (v1 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v1 / (s32)a1; hi = (s32)v1 % (s32)a1; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = v1 + a2;
    branch = ((s32)t2 <= 0); t6 = (s32)a3 < (s32)(v1);
    if (branch) goto L_60540;
    goto L_6053c;
L_6053c:
    t6 = (s32)v1 < (s32)(a3);
L_60540:
    if (t6 == 0) { *(volatile u32 *)(unsigned long)(v0 + (0)) = a3; goto L_6054c; }
    goto L_60548;
L_60548:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
L_6054c:
    t0 = t0 + 1;
    v0 = v0 + 4;
    branch = (t0 != t5); t1 = t1 + t2;
    if (branch) goto L_60514;
    goto L_6055c;
L_6055c:
    *(volatile u32 *)(unsigned long)(t4 + (60)) = a3;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
