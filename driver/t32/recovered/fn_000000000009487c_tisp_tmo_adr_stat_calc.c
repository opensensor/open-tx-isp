/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35b0[] __asm__("t32_data_e35b0");
extern unsigned char ref_t32_data_e3570[] __asm__("t32_data_e3570");
extern unsigned char ref_t32_data_e3580[] __asm__("t32_data_e3580");
u64 tisp_tmo_adr_stat_calc(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9487c = ((u32)(unsigned long)ref_t32_data_e35b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_94890 = ((u32)(unsigned long)ref_t32_data_e3570 + 0x8000U) & 0xffff0000U;
    const u32 hi_9489c = ((u32)(unsigned long)ref_t32_data_e3580 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_9487c:
    v0 = hi_9487c;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_9487c + (u32)(unsigned long)ref_t32_data_e35b0;
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = hi_94890;
    a1 = a1 - hi_94890 + (u32)(unsigned long)ref_t32_data_e3570;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = hi_9489c;
    v0 = v0 - hi_9489c + (u32)(unsigned long)ref_t32_data_e3580;
    v0 = a0 + v0;
    a0 = a0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t2 = v1 + 5408;
    a2 = 0;
    a1 = v0 * a1;
    v0 = 4;
    a3 = 0;
    if (a1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a1 / (s32)v0; hi = (s32)a1 % (s32)v0; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    v0 = 5120;
    a1 = lo;
    a0 = (s32)a1 < (s32)(5120);
    if (a0 != 0) a1 = v0;
    v0 = 24;
    if (a1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a1 / (s32)v0; hi = (s32)a1 % (s32)v0; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a0 = v1 + 5312;
    v0 = lo;
L_948ec:
    t1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t0 = *(volatile u32 *)(unsigned long)(a0 + (96));
    t3 = *(volatile u32 *)(unsigned long)(a0 + (192));
    if (t1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)t1 / (s32)v0; hi = (s32)t1 % (s32)v0; } else { lo = (s32)t1 < 0 ? 1 : ~0U; hi = t1; }
    a3 = a3 + t1;
    *(volatile u32 *)(unsigned long)(a0 + (4544)) = t3;
    t3 = *(volatile u32 *)(unsigned long)(a0 + (288));
    a2 = a2 + t0;
    a0 = a0 + 4;
    *(volatile u32 *)(unsigned long)(a0 + (4636)) = t3;
    t1 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (4348)) = t1;
    if (t0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)t0 / (s32)v0; hi = (s32)t0 % (s32)v0; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    branch = (t2 != a0); *(volatile u32 *)(unsigned long)(a0 + (4444)) = t0;
    if (branch) goto L_948ec;
    goto L_9492c;
L_9492c:
    if (a3 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a3 / (s32)a1; hi = (s32)a3 % (s32)a1; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    t2 = (s32)a1 >> (0x8 & 31);
    a0 = v1;
    t3 = v1 + 2048;
    t0 = v1;
    t4 = 10000;
    t1 = 0x1U << 16;
    a3 = lo;
    *(volatile u32 *)(unsigned long)(v1 + (10048)) = a3;
    a3 = 0;
    if (a2 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a2 / (s32)a1; hi = (s32)a2 % (s32)a1; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(v1 + (10052)) = a2;
L_94960:
    a2 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t0 = t0 + 4;
    a3 = a3 + a2;
    a2 = (s32)a3 < (s32)(a1);
    if (a2 == 0) a3 = a1;
    a2 = a3 << (0x8 & 31);
    if (a2 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)a2 / (s32)t2; hi = (s32)a2 % (s32)t2; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    a2 = a2 * t4;
    if (a2 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)a2 / (s32)t1; hi = (s32)a2 % (s32)t1; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    branch = (t3 != t0); *(volatile u32 *)(unsigned long)(t0 + (5692)) = a2;
    if (branch) goto L_94960;
    goto L_94994;
L_94994:
    a3 = 0;
    a1 = 10000;
    t0 = 24;
L_949a0:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2048));
    a3 = a3 + 1;
    v1 = v1 + 80;
    a2 = a1 * a2;
    a0 = a0 + 56;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3912)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (1972));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3916)) = a2;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (1980));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (1976));
    a2 = a2 + t1;
    a2 = a2 * a1;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3920)) = a2;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (1988));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (1984));
    a2 = a2 + t1;
    a2 = a2 * a1;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3924)) = a2;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (1996));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (1992));
    a2 = a2 + t1;
    a2 = a2 * a1;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3928)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2000));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3932)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2004));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3936)) = a2;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (2012));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2008));
    a2 = a2 + t1;
    a2 = a2 * a1;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3940)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2016));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3944)) = a2;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (2024));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2020));
    a2 = a2 + t1;
    a2 = a2 * a1;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3948)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2028));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3952)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2032));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (2036));
    a2 = a2 + t1;
    a2 = a2 * a1;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3956)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2040));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (3960)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (2044));
    a2 = a1 * a2;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    branch = (a3 != t0); *(volatile u32 *)(unsigned long)(a0 + (3964)) = a2;
    if (branch) goto L_949a0;
    goto L_94af8;
L_94af8:
    ;
    return ((u64)v1 << 32) | v0;
}
