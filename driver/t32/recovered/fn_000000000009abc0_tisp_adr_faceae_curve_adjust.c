/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35b0[] __asm__("t32_data_e35b0");
extern unsigned char ref_t32_data_e3244[] __asm__("t32_data_e3244");
extern unsigned char ref_t32_data_e34e8[] __asm__("t32_data_e34e8");
extern unsigned char ref_t32_data_e3248[] __asm__("t32_data_e3248");
u64 tisp_adr_faceae_curve_adjust(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9abc0 = ((u32)(unsigned long)ref_t32_data_e35b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9abd4 = ((u32)(unsigned long)ref_t32_data_e3244 + 0x8000U) & 0xffff0000U;
    const u32 hi_9ac00 = ((u32)(unsigned long)ref_t32_data_e34e8 + 0x8000U) & 0xffff0000U;
    const u32 hi_9abd8 = ((u32)(unsigned long)ref_t32_data_e3248 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_9abc0:
    v0 = hi_9abc0;
    v0 = v0 - hi_9abc0 + (u32)(unsigned long)ref_t32_data_e35b0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = hi_9abd4;
    a3 = hi_9abd8;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(a0 - hi_9abd4 + (u32)(unsigned long)ref_t32_data_e3244);
    t3 = 1;
    a2 = a2 + 128;
    v1 = v0 + 1;
    v0 = 0x1U << 16;
    v0 = v0 | 0x86a1;
    v0 = (u32)v1 < (u32)(v0);
    if (v0 == 0) v1 = 0;
    v0 = hi_9ac00;
    *(volatile u32 *)(unsigned long)(a0 - hi_9abd4 + (u32)(unsigned long)ref_t32_data_e3244) = v1;
    v0 = v0 - hi_9ac00 + (u32)(unsigned long)ref_t32_data_e34e8;
    v1 = 0;
    a3 = a3 - hi_9abd8 + (u32)(unsigned long)ref_t32_data_e3248;
    t4 = 28;
    t5 = 672;
L_9ac1c:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    branch = (a0 == t3); a1 = a2 + v1;
    if (branch) goto L_9ac3c;
    goto L_9ac28;
L_9ac28:
    v1 = v1 + 28;
L_9ac2c:
    branch = (v1 != t5); v0 = v0 + 1;
    if (branch) goto L_9ac1c;
    goto L_9ac34;
L_9ac34:
    ;
    return ((u64)v1 << 32) | v0;
L_9ac3c:
    a0 = 0;
L_9ac40:
    t0 = v1 + a0;
    t0 = a3 + t0;
    t2 = *(volatile u16 *)(unsigned long)(a1 + (0));
    t0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t6 = (int16_t)t2;
    t1 = (int16_t)t0;
    t1 = (s32)t1 < (s32)(t6);
    if (t1 != 0) { t0 = t2; goto L_9ac64; }
    goto L_9ac64;
L_9ac64:
    a0 = a0 + 2;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = t0;
    branch = (a0 != t4); a1 = a1 + 2;
    if (branch) goto L_9ac40;
    goto L_9ac74;
L_9ac74:
    v1 = v1 + 28; goto L_9ac2c;
}
