/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e22c8[] __asm__("t32_data_e22c8");
u64 tisp_mdns_cmp_par_calc(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_5fe68 = ((u32)(unsigned long)ref_t32_data_e22c8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_5fe60:
    a0 = a0 & 0xff;
    v0 = a0 << (0x2 & 31);
    a0 = hi_5fe68;
    a0 = a0 - hi_5fe68 + (u32)(unsigned long)ref_t32_data_e22c8;
    a0 = v0 + a0;
    a3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t0 = 0x5U << 16;
    t0 = t0 | 0xdc00;
    t2 = *(volatile u16 *)(unsigned long)(a3 + (88));
    v0 = a2 + 31;
    v0 = v0 >> (0x5 & 31);
    if (t0 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)t0 / (s32)t2; hi = (s32)t0 % (s32)t2; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    a0 = 64;
    t4 = (u32)t2 < (u32)(1201);
    t1 = 3072;
    t0 = lo;
    v0 = v0 * a1;
    a1 = a1 + -1;
    a1 = a1 << (0x10 & 31);
    v1 = t0 * v0;
    v1 = v1 + 63;
    if (v1 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v1 / (s32)a0; hi = (s32)v1 % (s32)a0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(a3 + (48)) = v1;
    v1 = a2 + -1;
    a1 = a1 | v1;
    v1 = 16000;
    a2 = a2 * v1;
    v1 = 8192;
    if (t2) { lo = a2 / t2; hi = a2 % t2; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    a2 = v1 - a2;
    v1 = (s32)a2 < (s32)(3072);
    branch = (v1 == 0); *(volatile u32 *)(unsigned long)(a3 + (52)) = a1;
    if (branch) goto L_5ff0c;
    goto L_5feec;
L_5feec:
    if (t4 != 0) { t1 = (s32)a2 < (s32)(2500); goto L_5ff00; }
    goto L_5fef4;
L_5fef4:
    t1 = (s32)a2 < (s32)(1024);
    v1 = 1024; goto L_5ff04;
L_5ff00:
    v1 = 2500;
L_5ff04:
    if (t1 == 0) v1 = a2;
    t1 = v1;
L_5ff0c:
    v1 = 8192;
    a0 = v1 - t1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = 100;
    v1 = lo;
    a2 = t0 - v1;
    t0 = (s32)a2 < (s32)(100);
    if (t0 != 0) a2 = a1;
    t0 = (s32)a2 < (s32)(385);
    a1 = 384;
    if (t0 != 0) a1 = a2;
    a2 = a1 << (0x1 & 31);
    a2 = a2 + a1;
    a2 = (s32)a2 >> (0x2 & 31);
    a2 = a2 << (0x10 & 31);
    a2 = a2 | a1;
    *(volatile u32 *)(unsigned long)(a3 + (60)) = a2;
    t0 = 44;
    a2 = 40;
    if (t4 != 0) t0 = a2;
    t3 = t0;
    t0 = 32;
    if (t4 == 0) a2 = t0;
    t4 = a2;
    a2 = 0x6400U << 16;
    a2 = a2 + 30720;
    t0 = t3 | a2;
    a2 = t4 << (0x10 & 31);
    a2 = t0 | a2;
    *(volatile u32 *)(unsigned long)(a3 + (64)) = a2;
    a2 = v0 * v1;
    v1 = a0 - a2;
    a0 = (s32)0 < (s32)(v1);
    a2 = 1;
    if (a0 == 0) v1 = a2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = lo;
    t0 = (s32)v1 < (s32)(255);
    branch = (t0 == 0); a0 = 255;
    if (branch) goto L_5ffb8;
    goto L_5ffac;
L_5ffac:
    a0 = (s32)0 < (s32)(v1);
    if (a0 != 0) a2 = v1;
    a0 = a2;
L_5ffb8:
    v1 = 0xf04U << 16;
    v1 = v1 + 512;
    a0 = a0 | v1;
    v1 = (u32)t2 < (u32)(1200);
    branch = (v1 == 0); *(volatile u32 *)(unsigned long)(a3 + (68)) = a0;
    if (branch) goto L_5ffd8;
    goto L_5ffd0;
L_5ffd0:
    v1 = 0xfcfcU << 16; goto L_5ffdc;
L_5ffd8:
    v1 = 0xfdfeU << 16;
L_5ffdc:
    v1 = v1 + 2;
    *(volatile u32 *)(unsigned long)(a3 + (72)) = v1;
    v1 = a1 << (0x10 & 31);
    t1 = v1 | t1;
    a1 = (s32)a1 < (s32)(170);
    *(volatile u32 *)(unsigned long)(a3 + (76)) = t1;
    branch = (a1 != 0); v1 = 0x14U << 16;
    if (branch) goto L_60004;
    goto L_5fffc;
L_5fffc:
    v1 = v1 + 5; goto L_60008;
L_60004:
    v1 = v1 + 8;
L_60008:
    *(volatile u32 *)(unsigned long)(a3 + (80)) = v1;
    v0 = v0 + -256;
    v1 = 0x7600U << 16;
    v0 = v0 | v1;
    *(volatile u32 *)(unsigned long)(a3 + (84)) = v0;
    return ((u64)v1 << 32) | v0;
}
