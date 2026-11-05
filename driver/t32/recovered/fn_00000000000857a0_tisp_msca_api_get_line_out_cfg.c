/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
u64 tisp_msca_api_get_line_out_cfg(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_857ac = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_857a0:
    a0 = a0 & 0xff;
    v0 = a0 << (0x2 & 31);
    v1 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a0 = hi_857ac;
    a0 = a0 - hi_857ac + (u32)(unsigned long)ref_t32_data_e2768;
    a0 = v0 + a0;
    v0 = 28;
    a2 = v1 * v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = a2 + a0;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (116));
    *(volatile u32 *)(unsigned long)(a1 + (4)) = v1;
    a0 = *(volatile u8 *)(unsigned long)(a0 + (676));
    *(volatile u8 *)(unsigned long)(a1 + (1)) = a0;
    a0 = 2;
    branch = (v1 != a0); a0 = 1;
    if (branch) goto L_85820;
    goto L_857e4;
L_857e4:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (120));
    *(volatile u8 *)(unsigned long)(a1 + (12)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (122));
    *(volatile u16 *)(unsigned long)(a1 + (14)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (124));
    *(volatile u16 *)(unsigned long)(a1 + (16)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (126));
    *(volatile u16 *)(unsigned long)(a1 + (18)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (128));
    *(volatile u16 *)(unsigned long)(a1 + (20)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (136));
    *(volatile u8 *)(unsigned long)(a1 + (28)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (137));
    *(volatile u8 *)(unsigned long)(a1 + (29)) = v1; goto L_858bc;
L_85820:
    branch = (v1 != a0); ;
    if (branch) goto L_85874;
    goto L_85828;
L_85828:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (120));
    *(volatile u8 *)(unsigned long)(a1 + (12)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (122));
    *(volatile u16 *)(unsigned long)(a1 + (14)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (124));
    *(volatile u16 *)(unsigned long)(a1 + (16)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (126));
    *(volatile u16 *)(unsigned long)(a1 + (18)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (128));
    *(volatile u16 *)(unsigned long)(a1 + (20)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (136));
    *(volatile u8 *)(unsigned long)(a1 + (28)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (137));
    *(volatile u8 *)(unsigned long)(a1 + (29)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (138));
    *(volatile u16 *)(unsigned long)(a1 + (30)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (140));
    *(volatile u8 *)(unsigned long)(a1 + (32)) = v1; goto L_858bc;
L_85874:
    branch = (v1 != 0); ;
    if (branch) goto L_858d4;
    goto L_8587c;
L_8587c:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (120));
    *(volatile u8 *)(unsigned long)(a1 + (12)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (122));
    *(volatile u16 *)(unsigned long)(a1 + (14)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (124));
    *(volatile u16 *)(unsigned long)(a1 + (16)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (126));
    *(volatile u16 *)(unsigned long)(a1 + (18)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (128));
    *(volatile u16 *)(unsigned long)(a1 + (20)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (136));
    *(volatile u8 *)(unsigned long)(a1 + (28)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (137));
    *(volatile u8 *)(unsigned long)(a1 + (29)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (138));
    *(volatile u8 *)(unsigned long)(a1 + (30)) = v1;
L_858bc:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (134));
    *(volatile u8 *)(unsigned long)(a1 + (25)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (133));
    *(volatile u8 *)(unsigned long)(a1 + (26)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (132));
    *(volatile u8 *)(unsigned long)(a1 + (27)) = v0;
L_858d4:
    ;
    return ((u64)v1 << 32) | v0;
}
