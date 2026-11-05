/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
u64 tisp_msca_api_get_osd_out_attribute_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_85fe4 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_85fdc:
    a0 = a0 & 0xff;
    v0 = a0 << (0x2 & 31);
    a0 = hi_85fe4;
    a0 = a0 - hi_85fe4 + (u32)(unsigned long)ref_t32_data_e2768;
    a0 = v0 + a0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a1 + (29));
    a0 = v1 + v0;
    a2 = *(volatile u8 *)(unsigned long)(a0 + (844));
    v0 = v0 << (0x4 & 31);
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    a2 = *(volatile u8 *)(unsigned long)(v1 + (840));
    v1 = a1 + 12;
    a1 = a1 + 16;
    *(volatile u8 *)(unsigned long)(a1 + (12)) = a2;
    a2 = *(volatile u8 *)(unsigned long)(a0 + (842));
    *(volatile u32 *)(unsigned long)(a1 + (-12)) = a2;
    a0 = *(volatile u8 *)(unsigned long)(a0 + (846));
    *(volatile u32 *)(unsigned long)(a1 + (-8)) = a0;
L_8602c:
    a0 = *(volatile u8 *)(unsigned long)(v0 + (848));
    v1 = v1 + 1;
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(v1 + (-1)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (851));
    *(volatile u8 *)(unsigned long)(v1 + (3)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (855));
    *(volatile u8 *)(unsigned long)(v1 + (7)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (859));
    branch = (v1 != a1); *(volatile u8 *)(unsigned long)(v1 + (11)) = a0;
    if (branch) goto L_8602c;
    goto L_86058;
L_86058:
    ;
    return ((u64)v1 << 32) | v0;
}
