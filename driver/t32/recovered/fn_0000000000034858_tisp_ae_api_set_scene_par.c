/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
u64 tisp_ae_api_set_scene_par(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3485c = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_34858:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = hi_3485c;
    a2 = 1;
    a0 = a0 << (0x2 & 31);
    branch = (v1 != a2); v0 = v0 - hi_3485c + (u32)(unsigned long)ref_t32_data_e15a8;
    if (branch) goto L_34890;
    goto L_34870;
L_34870:
    a2 = v0 + a0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u16 *)(unsigned long)(a3 + (2942)) = v1;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1704)) = v1;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0)); goto L_348ec;
L_34890:
    a3 = 3;
    branch = (v1 != a3); a3 = 2;
    if (branch) goto L_348c0;
    goto L_3489c;
L_3489c:
    v1 = v0 + a0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1684)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (4));
    v1 = v1 + 1;
    *(volatile u16 *)(unsigned long)(a2 + (2942)) = v1; goto L_348f0;
L_348c0:
    if (v1 != a3) { v1 = *(volatile u32 *)(unsigned long)(a1 + (8)); goto L_348f4; }
    goto L_348c8;
L_348c8:
    v1 = v0 + a0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1684)) = a2;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1704)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (4));
    v1 = v1 + 1;
L_348ec:
    *(volatile u32 *)(unsigned long)(a2 + (1708)) = v1;
L_348f0:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (8));
L_348f4:
    a2 = 1;
    branch = (v1 != a2); a3 = 3;
    if (branch) goto L_34924;
    goto L_34900;
L_34900:
    a2 = v0 + a0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u16 *)(unsigned long)(a3 + (2940)) = v1;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1712)) = v1;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u32 *)(unsigned long)(a2 + (1716)) = v1; goto L_34980;
L_34924:
    branch = (v1 != a3); a3 = 2;
    if (branch) goto L_34950;
    goto L_3492c;
L_3492c:
    v1 = v0 + a0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1684)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(a1 + (12));
    v1 = v1 + 1;
    *(volatile u16 *)(unsigned long)(a2 + (2940)) = v1; goto L_34980;
L_34950:
    if (v1 != a3) { v1 = *(volatile u32 *)(unsigned long)(a1 + (16)); goto L_34984; }
    goto L_34958;
L_34958:
    v1 = v0 + a0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a3 + (1684)) = a2;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (12));
    t0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = a3 + 1;
    *(volatile u32 *)(unsigned long)(t0 + (1712)) = a3;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v1 + (1716)) = a2;
L_34980:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (16));
L_34984:
    branch = (v1 != 0); v1 = v0 + a0;
    if (branch) goto L_3499c;
    goto L_3498c;
L_3498c:
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u16 *)(unsigned long)(v1 + (2956)) = 0; goto L_349b8;
L_3499c:
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = 1;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u16 *)(unsigned long)(a2 + (2956)) = a3;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(a1 + (20));
    *(volatile u16 *)(unsigned long)(v1 + (2960)) = a2;
L_349b8:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (24));
    branch = (v1 == 0); v0 = v0 + a0;
    if (branch) goto L_349e0;
    goto L_349c4;
L_349c4:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (28));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(v1 + (368)) = a0;
    *(volatile u32 *)(unsigned long)(v1 + (372)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (8566)) = 0;
L_349e0:
    ;
    return ((u64)v1 << 32) | v0;
}
