/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
u64 tisp_awb_params_refresh(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3ba04 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_3ba04:
    v0 = hi_3ba04;
    v0 = v0 - hi_3ba04 + (u32)(unsigned long)ref_t32_data_e16b4;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a3 = *(volatile u16 *)(unsigned long)(v0 + (3188));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (28690));
    t0 = *(volatile u16 *)(unsigned long)(v0 + (3184));
    t1 = *(volatile u16 *)(unsigned long)(v0 + (3186));
    a0 = a0 - a3;
    a0 = a0 + 1;
    a3 = 2;
    if (a0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a0 / (s32)a3; hi = (s32)a0 % (s32)a3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a2 = *(volatile u16 *)(unsigned long)(v0 + (3190));
    v1 = *(volatile u16 *)(unsigned long)(a1 + (28692));
    a0 = lo;
L_3ba4c:
    if (a0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)a0 / (s32)a2; hi = (s32)a0 % (s32)a2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a3 = lo;
    a3 = a3 & 0xffff;
    t2 = (u32)a3 < (u32)(127);
    if (t2 != 0) { v1 = v1 - t0; goto L_3ba70; }
    goto L_3ba64;
L_3ba64:
    a2 = a2 + 1;
    a2 = a2 & 0xffff; goto L_3ba4c;
L_3ba70:
    v1 = v1 + 1;
    a0 = 2;
    if (v1 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v1 / (s32)a0; hi = (s32)v1 % (s32)a0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
L_3ba80:
    if (v1 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)v1 / (s32)t1; hi = (s32)v1 % (s32)t1; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a0 = lo;
    a0 = a0 & 0xffff;
    t0 = (u32)a0 < (u32)(127);
    if (t0 != 0) { v1 = 0x1U << 16; goto L_3baa4; }
    goto L_3ba98;
L_3ba98:
    a0 = t1 + 1;
    t1 = a0 & 0xffff; goto L_3ba80;
L_3baa4:
    *(volatile u16 *)(unsigned long)(v0 + (3186)) = t1;
    *(volatile u16 *)(unsigned long)(v0 + (3190)) = a2;
    v1 = a1 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (13501));
    branch = (v1 != 0); v1 = 0x1U << 16;
    if (branch) goto L_3bae0;
    goto L_3babc;
L_3babc:
    v1 = 0x2U << 16;
    v1 = a1 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (-23476));
    branch = (v1 != 0); v1 = 0x1U << 16;
    if (branch) goto L_3bae0;
    goto L_3bad0;
L_3bad0:
    v1 = 1;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    *(volatile u32 *)(unsigned long)(v0 + (12)) = 0;
    v1 = 0x1U << 16;
L_3bae0:
    a1 = a1 + v1;
    *(volatile u8 *)(unsigned long)(a1 + (13501)) = 0;
    v1 = v0 + 3222;
    a1 = v0 + 3192;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a3;
L_3baf4:
    a1 = a1 + 2;
    if (a1 != v1) { *(volatile u16 *)(unsigned long)(a1 + (0)) = a3; goto L_3baf4; }
    goto L_3bb00;
L_3bb00:
    a1 = v0 + 3252;
    *(volatile u16 *)(unsigned long)(v1 + (0)) = a0;
L_3bb08:
    v1 = v1 + 2;
    if (a1 != v1) { *(volatile u16 *)(unsigned long)(v1 + (0)) = a0; goto L_3bb08; }
    goto L_3bb14;
L_3bb14:
    *(volatile u16 *)(unsigned long)(v0 + (3290)) = a3;
    *(volatile u16 *)(unsigned long)(v0 + (3292)) = a0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
