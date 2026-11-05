/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d6b50[] __asm__("t32_data_d6b50");
u64 tisp_lce_hist_adjust(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4ce20 = ((u32)(unsigned long)ref_t32_data_d6b50 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_4ce20:
    a3 = hi_4ce20;
    a3 = a3 - hi_4ce20 + (u32)(unsigned long)ref_t32_data_d6b50;
    t2 = a0 + 20;
L_4ce2c:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a0 + (0));
    v0 = v0 - v1;
    v0 = v0 & 0xffff;
    t1 = (int16_t)v0;
    branch = ((s32)t1 <= 0); ;
    if (branch) goto L_4ce50;
    goto L_4ce48;
L_4ce48:
    t0 = *(volatile u8 *)(unsigned long)(a1 + (0)); goto L_4ce5c;
L_4ce50:
    branch = (t1 == 0); t0 = 0;
    if (branch) goto L_4ce64;
    goto L_4ce58;
L_4ce58:
    t0 = *(volatile u8 *)(unsigned long)(a2 + (0));
L_4ce5c:
    v0 = v0 * t0;
    t0 = (int16_t)v0;
L_4ce64:
    v1 = v1 << (0x8 & 31);
    v1 = v1 + 128;
    v0 = v1 + t0;
    v0 = v0 >> (0x8 & 31);
    *(volatile u8 *)(unsigned long)(a0 + (0)) = v0;
    a0 = a0 + 1;
    a3 = a3 + 1;
    a1 = a1 + 1;
    branch = (t2 != a0); a2 = a2 + 1;
    if (branch) goto L_4ce2c;
    goto L_4ce8c;
L_4ce8c:
    ;
    return ((u64)v1 << 32) | v0;
}
