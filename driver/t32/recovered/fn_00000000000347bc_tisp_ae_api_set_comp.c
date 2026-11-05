/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_d2a30[] __asm__("t32_data_d2a30");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
u64 tisp_ae_api_set_comp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_347c4 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_347d8 = ((u32)(unsigned long)ref_t32_data_d2a30 + 0x8000U) & 0xffff0000U;
    const u32 hi_34838 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_347bc:
    t0 = 1028;
    t1 = a0 * t0;
    v1 = hi_347c4;
    a2 = a0 << (0x2 & 31);
    v1 = v1 - hi_347c4 + (u32)(unsigned long)ref_t32_data_e15a8;
    v1 = a2 + v1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = hi_347d8;
    v1 = v1 - hi_347d8 + (u32)(unsigned long)ref_t32_data_d2a30;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a1 = a1 & 0xffff;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (2960));
    a0 = t1 + v1;
    *(volatile u8 *)(unsigned long)(a0 + (1024)) = a1;
    branch = (a1 == 0); a0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    if (branch) goto L_34810;
    goto L_347fc;
L_347fc:
    v1 = (u32)a1 < (u32)(129);
    branch = (v1 == 0); v1 = 300;
    if (branch) goto L_34820;
    goto L_34808;
L_34808:
    a1 = v0 * a1; goto L_34818;
L_34810:
    a1 = 1;
    a1 = v0 * a1;
L_34818:
    a1 = (s32)a1 >> (0x7 & 31); goto L_34838;
L_34820:
    a1 = a1 * v1;
    v1 = 127;
    v0 = v0 + -302;
    if (a1 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a1 / (s32)v1; hi = (s32)a1 % (s32)v1; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = lo;
    a1 = a1 + v0;
L_34838:
    v0 = hi_34838;
    v0 = v0 - hi_34838 + (u32)(unsigned long)ref_t32_data_e1588;
    *(volatile u16 *)(unsigned long)(a0 + (2960)) = a1;
    v0 = v0 + a2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (1285)) = v1;
    return ((u64)v1 << 32) | v0;
}
