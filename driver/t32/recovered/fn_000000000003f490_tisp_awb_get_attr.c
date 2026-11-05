/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
u64 tisp_awb_get_attr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3f490 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_3f490:
    v0 = hi_3f490;
    v0 = v0 - hi_3f490 + (u32)(unsigned long)ref_t32_data_e16b4;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(a1 + (12)) = 0;
    a2 = 1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = 9;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (44));
    *(volatile u32 *)(unsigned long)(a1 + (16)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = 0x2U << 16;
    a0 = a0 + v1;
    a0 = *(volatile u8 *)(unsigned long)(a0 + (-23474));
    *(volatile u32 *)(unsigned long)(a1 + (20)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (24)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(a1 + (28)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (32)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (36)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (40)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (44)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (48)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (52)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (56)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (60)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (64)) = a2;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (24));
    *(volatile u32 *)(unsigned long)(a1 + (68)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (28));
    *(volatile u32 *)(unsigned long)(a1 + (72)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = a0 + v1;
    a0 = *(volatile u8 *)(unsigned long)(a0 + (-23474));
    if (a0 != a3) { *(volatile u32 *)(unsigned long)(a1 + (0)) = a0; goto L_3f538; }
    goto L_3f52c;
L_3f52c:
    *(volatile u32 *)(unsigned long)(a1 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(a1 + (20)) = a2; goto L_3f558;
L_3f538:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = a0 + v1;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (-23468));
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (-23466));
    *(volatile u32 *)(unsigned long)(a1 + (8)) = v1;
L_3f558:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    branch = (v1 != 0); a0 = 0x2U << 16;
    if (branch) goto L_3f584;
    goto L_3f564;
L_3f564:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = v1 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (-23452));
    *(volatile u32 *)(unsigned long)(a1 + (4)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = v0 + a0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (-23450));
    *(volatile u32 *)(unsigned long)(a1 + (8)) = v0;
L_3f584:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
