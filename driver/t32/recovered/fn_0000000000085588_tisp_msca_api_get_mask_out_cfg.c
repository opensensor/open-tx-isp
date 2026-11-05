/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
u64 tisp_msca_api_get_mask_out_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_85590 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_85588:
    a0 = a0 & 0xff;
    v0 = a0 << (0x2 & 31);
    a0 = hi_85590;
    a0 = a0 - hi_85590 + (u32)(unsigned long)ref_t32_data_e2768;
    a0 = v0 + a0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a2 = 872;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a3 = v0 * a2;
    a0 = *(volatile u8 *)(unsigned long)(a1 + (1));
    a0 = a0 + 2;
    a0 = a0 << (0x4 & 31);
    v0 = a3 + a0;
    v0 = v1 + v0;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (20));
    a0 = 1;
    if (v1 != a0) { *(volatile u8 *)(unsigned long)(a1 + (2)) = 0; goto L_85610; }
    goto L_855d0;
L_855d0:
    *(volatile u8 *)(unsigned long)(a1 + (2)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (24));
    *(volatile u16 *)(unsigned long)(a1 + (4)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (22));
    *(volatile u16 *)(unsigned long)(a1 + (6)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (26));
    *(volatile u16 *)(unsigned long)(a1 + (8)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (28));
    *(volatile u16 *)(unsigned long)(a1 + (10)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (34));
    *(volatile u8 *)(unsigned long)(a1 + (19)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (33));
    *(volatile u8 *)(unsigned long)(a1 + (20)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (32));
    *(volatile u8 *)(unsigned long)(a1 + (21)) = v0;
    return ((u64)v1 << 32) | v0;
L_85610:
    *(volatile u16 *)(unsigned long)(a1 + (4)) = 0;
    *(volatile u16 *)(unsigned long)(a1 + (6)) = 0;
    *(volatile u16 *)(unsigned long)(a1 + (8)) = 0;
    *(volatile u16 *)(unsigned long)(a1 + (10)) = 0;
    *(volatile u8 *)(unsigned long)(a1 + (19)) = 0;
    *(volatile u8 *)(unsigned long)(a1 + (20)) = 0;
    *(volatile u8 *)(unsigned long)(a1 + (21)) = 0;
    return ((u64)v1 << 32) | v0;
}
