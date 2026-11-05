/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2760[] __asm__("t32_data_e2760");
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
extern unsigned char ref_t32_data_e2650[] __asm__("t32_data_e2650");
extern unsigned char ref_t32_data_dc284[] __asm__("t32_data_dc284");
u64 lib_tisp_msca_channel_attr_set(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_85300 = ((u32)(unsigned long)ref_t32_data_e2760 + 0x8000U) & 0xffff0000U;
    const u32 hi_85320 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    const u32 hi_85334 = ((u32)(unsigned long)ref_t32_data_e2650 + 0x8000U) & 0xffff0000U;
    const u32 hi_853f0 = ((u32)(unsigned long)ref_t32_data_dc284 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_852f4:
    a0 = a0 & 0xff;
    v1 = 3;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    v0 = hi_85300;
    v0 = v0 - hi_85300 + (u32)(unsigned long)ref_t32_data_e2760;
    v1 = lo;
    v1 = v1 & 0xff;
    v0 = v1 + v0;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    a0 = hi;
    a3 = a0 & 0xff;
    a0 = hi_85320;
    t1 = v1 << (0x2 & 31);
    branch = (v0 != 0); a0 = a0 - hi_85320 + (u32)(unsigned long)ref_t32_data_e2768;
    if (branch) goto L_85464;
    goto L_85330;
L_85330:
    t2 = *(volatile u32 *)(unsigned long)(a1 + (32));
    v0 = hi_85334;
    t3 = 1;
    t0 = v0 - hi_85334 + (u32)(unsigned long)ref_t32_data_e2650;
    a2 = v1 << (0x4 & 31);
    branch = (t2 != t3); v0 = a0 + t1;
    if (branch) goto L_853d8;
    goto L_8534c;
L_8534c:
    t3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    t4 = a3 * v0;
    v1 = a2 - v1;
    v1 = v1 + a3;
    v0 = t4 + t3;
    t3 = *(volatile u32 *)(unsigned long)(a1 + (36));
    *(volatile u16 *)(unsigned long)(v0 + (22)) = t3;
    t3 = *(volatile u32 *)(unsigned long)(a1 + (40));
    *(volatile u16 *)(unsigned long)(v0 + (24)) = t3;
    t3 = *(volatile u32 *)(unsigned long)(a1 + (44));
    *(volatile u16 *)(unsigned long)(v0 + (26)) = t3;
    t3 = *(volatile u32 *)(unsigned long)(a1 + (48));
    *(volatile u16 *)(unsigned long)(v0 + (28)) = t3;
    v0 = v1 << (0x2 & 31);
    v0 = t0 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = t2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (36));
    *(volatile u32 *)(unsigned long)(v0 + (12)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (40));
    v0 = v1 + 4;
    v0 = v0 << (0x2 & 31);
    v0 = t0 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (44));
    v0 = v1 + 8;
    v0 = v0 << (0x2 & 31);
    v0 = t0 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (48));
    v1 = v1 + 12;
    v1 = v1 << (0x2 & 31);
    v0 = t0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a2; goto L_85464;
L_853d8:
    t3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    t2 = a3 * v0;
    v0 = 904;
    t4 = v1 * v0;
    t3 = t2 + t3;
    t2 = hi_853f0;
    t2 = t2 - hi_853f0 + (u32)(unsigned long)ref_t32_data_dc284;
    *(volatile u16 *)(unsigned long)(t3 + (22)) = 0;
    *(volatile u16 *)(unsigned long)(t3 + (24)) = 0;
    t2 = t4 + t2;
    v0 = *(volatile u32 *)(unsigned long)(t2 + (0));
    *(volatile u16 *)(unsigned long)(t3 + (26)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t2 + (4));
    *(volatile u16 *)(unsigned long)(t3 + (28)) = v0;
    v0 = a2 - v1;
    v0 = v0 + a3;
    v1 = v0 << (0x2 & 31);
    v1 = t0 + v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v1 + (12)) = 0;
    v1 = v0 + 4;
    v1 = v1 << (0x2 & 31);
    v1 = t0 + v1;
    *(volatile u32 *)(unsigned long)(v1 + (8)) = 0;
    a2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    v1 = v0 + 8;
    v1 = v1 << (0x2 & 31);
    v1 = t0 + v1;
    *(volatile u32 *)(unsigned long)(v1 + (4)) = a2;
    v0 = v0 + 12;
    v1 = *(volatile u32 *)(unsigned long)(t2 + (4));
    v0 = v0 << (0x2 & 31);
    v0 = t0 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
L_85464:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    branch = (v0 == 0); v0 = a0 + t1;
    if (branch) goto L_85498;
    goto L_85470;
L_85470:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    a2 = a3 * v0;
    v0 = a2 + v1;
    v1 = 1;
    *(volatile u16 *)(unsigned long)(v0 + (30)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (34)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (8)); goto L_854b8;
L_85498:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    a2 = a3 * v0;
    v0 = a2 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (26));
    *(volatile u16 *)(unsigned long)(v0 + (30)) = 0;
    *(volatile u16 *)(unsigned long)(v0 + (34)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (28));
L_854b8:
    *(volatile u16 *)(unsigned long)(v0 + (32)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    branch = (v0 == 0); v0 = a0 + t1;
    if (branch) goto L_854f8;
    goto L_854c8;
L_854c8:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    a2 = a3 * v0;
    v0 = a2 + v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (16));
    *(volatile u16 *)(unsigned long)(v0 + (40)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (20));
    *(volatile u16 *)(unsigned long)(v0 + (42)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (24));
    *(volatile u16 *)(unsigned long)(v0 + (44)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (28)); goto L_8551c;
L_854f8:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 872;
    a1 = a3 * v0;
    v0 = a1 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (34));
    *(volatile u16 *)(unsigned long)(v0 + (40)) = 0;
    *(volatile u16 *)(unsigned long)(v0 + (42)) = 0;
    *(volatile u16 *)(unsigned long)(v0 + (44)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (32));
L_8551c:
    *(volatile u16 *)(unsigned long)(v0 + (46)) = v1;
    a0 = a0 + t1;
    v0 = 872;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a3 * v0;
    v0 = a0 + v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (44));
    a0 = a3 << (0x1 & 31);
    a0 = v1 + a0;
    *(volatile u8 *)(unsigned long)(v0 + (36)) = 0;
    *(volatile u8 *)(unsigned long)(v0 + (37)) = 0;
    *(volatile u16 *)(unsigned long)(a0 + (0)) = a1;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (46));
    *(volatile u16 *)(unsigned long)(a0 + (6)) = v0;
    return ((u64)v1 << 32) | v0;
}
