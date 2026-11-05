/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
u64 tisp_msca_api_set_mask_out_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_85638 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_85630:
    t1 = *(volatile u8 *)(unsigned long)(a1 + (2));
    a0 = a0 & 0xff;
    t0 = hi_85638;
    v1 = 1;
    a0 = a0 << (0x2 & 31);
    t0 = t0 - hi_85638 + (u32)(unsigned long)ref_t32_data_e2768;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (1));
    branch = (t1 != v1); a3 = *(volatile u8 *)(unsigned long)(a1 + (0));
    if (branch) goto L_85748;
    goto L_85654;
L_85654:
    v1 = t0 + a0;
    v0 = v0 + 2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v0 << (0x4 & 31);
    v0 = 872;
    t2 = a3 * v0;
    v1 = t2 + v1;
    v1 = a2 + v1;
    *(volatile u8 *)(unsigned long)(v1 + (20)) = t1;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (1));
    t1 = *(volatile u16 *)(unsigned long)(a1 + (4));
    t2 = a3 * v0;
    v1 = v1 + 2;
    v1 = v1 << (0x4 & 31);
    v1 = t2 + v1;
    v1 = a2 + v1;
    *(volatile u16 *)(unsigned long)(v1 + (24)) = t1;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (1));
    t1 = *(volatile u16 *)(unsigned long)(a1 + (6));
    t2 = a3 * v0;
    v1 = v1 + 2;
    v1 = v1 << (0x4 & 31);
    v1 = t2 + v1;
    v1 = a2 + v1;
    *(volatile u16 *)(unsigned long)(v1 + (22)) = t1;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (1));
    t1 = *(volatile u16 *)(unsigned long)(a1 + (8));
    t2 = a3 * v0;
    v1 = v1 + 2;
    v1 = v1 << (0x4 & 31);
    v1 = t2 + v1;
    v1 = a2 + v1;
    *(volatile u16 *)(unsigned long)(v1 + (26)) = t1;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (1));
    t1 = *(volatile u16 *)(unsigned long)(a1 + (10));
    t2 = a3 * v0;
    v1 = v1 + 2;
    v1 = v1 << (0x4 & 31);
    v1 = t2 + v1;
    v1 = a2 + v1;
    *(volatile u16 *)(unsigned long)(v1 + (28)) = t1;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (1));
    t1 = a3 * v0;
    v1 = v1 + 2;
    v1 = v1 << (0x4 & 31);
    v0 = t1 + v1;
    a2 = a2 + v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (19));
    v1 = v0 << (0x10 & 31);
    v0 = *(volatile u8 *)(unsigned long)(a1 + (20));
    v0 = v0 << (0x8 & 31);
    v0 = v1 | v0;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (21));
    v0 = v0 | v1;
    *(volatile u32 *)(unsigned long)(a2 + (32)) = v0; goto L_8576c;
L_85748:
    v1 = t0 + a0;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = 872;
    t1 = a3 * v1;
    v0 = v0 + 2;
    v0 = v0 << (0x4 & 31);
    v0 = t1 + v0;
    v0 = a2 + v0;
    *(volatile u8 *)(unsigned long)(v0 + (20)) = 0;
L_8576c:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t0 = t0 + a0;
    a0 = 872;
    a2 = v0 * a0;
    v1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a1 + (1));
    v0 = 1;
    v0 = v0 << (a0 & 31);
    v1 = a2 + v1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (884));
    v0 = v0 | a0;
    *(volatile u32 *)(unsigned long)(v1 + (884)) = v0;
    return ((u64)v1 << 32) | v0;
}
