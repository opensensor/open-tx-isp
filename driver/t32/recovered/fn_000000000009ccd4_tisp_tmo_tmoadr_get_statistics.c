/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_t32_data_e35b0[] __asm__("t32_data_e35b0");
u64 tisp_tmo_tmoadr_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9ccd4 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9ccf8 = ((u32)(unsigned long)ref_t32_data_e35b0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_9ccd4:
    v0 = hi_9ccd4;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_9ccd4 + (u32)(unsigned long)ref_t32_data_e35e0;
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (385));
    if (v1 != 0) { a0 = 1; goto L_9ce98; }
    goto L_9ccf8;
L_9ccf8:
    v0 = hi_9ccf8;
    v0 = v0 - hi_9ccf8 + (u32)(unsigned long)ref_t32_data_e35b0;
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = a1;
    t0 = v1;
    a0 = v1 + 5504;
    t5 = v1 + 5600;
    t2 = v1;
L_9cd20:
    t6 = t2 + 72;
    t1 = t2;
    t3 = v0;
L_9cd2c:
    a2 = *(volatile u32 *)(unsigned long)(t3 + (0));
    t1 = t1 + 12;
    t3 = t3 + 8;
    a3 = a2 >> (0x10 & 31);
    t4 = a3 & 0x1;
    t4 = t4 << (0x10 & 31);
    a2 = a2 & 0xffff;
    a2 = t4 + a2;
    *(volatile u32 *)(unsigned long)(t1 + (2036)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(t3 + (-4));
    a3 = a3 >> (0x4 & 31);
    t4 = a2 & 0x1f;
    t4 = t4 << (0xc & 31);
    a3 = t4 + a3;
    *(volatile u32 *)(unsigned long)(t1 + (2040)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(t3 + (-2));
    a2 = (a2 >> 0x8) & ((1U << 0x8) - 1);
    a3 = a3 & 0x1ff;
    a3 = a3 << (0x8 & 31);
    a2 = a3 + a2;
    branch = (t1 != t6); *(volatile u32 *)(unsigned long)(t1 + (2044)) = a2;
    if (branch) goto L_9cd2c;
    goto L_9cd84;
L_9cd84:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (48));
    a0 = a0 + 4;
    v0 = v0 + 64;
    a3 = a2 >> (0x10 & 31);
    t1 = a3 & 0x1;
    t1 = t1 << (0x10 & 31);
    a2 = a2 & 0xffff;
    a2 = t1 + a2;
    *(volatile u32 *)(unsigned long)(t2 + (2120)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-12));
    a3 = a3 >> (0x4 & 31);
    t2 = t2 + 80;
    t1 = a2 & 0x1f;
    t1 = t1 << (0xc & 31);
    a3 = t1 + a3;
    *(volatile u32 *)(unsigned long)(t2 + (2044)) = a3;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (-10));
    a2 = (a2 >> 0x8) & ((1U << 0x8) - 1);
    a3 = t1 & 0xf;
    a3 = a3 << (0x8 & 31);
    a2 = a3 + a2;
    t1 = t1 >> (0x4 & 31);
    *(volatile u32 *)(unsigned long)(a0 + (-4)) = a2;
    *(volatile u32 *)(unsigned long)(a0 + (92)) = t1;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-8));
    a2 = (a2 >> 0x0) & ((1U << 0x1d) - 1);
    *(volatile u32 *)(unsigned long)(a0 + (-196)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-4));
    a2 = (a2 >> 0x0) & ((1U << 0x1d) - 1);
    branch = (a0 != t5); *(volatile u32 *)(unsigned long)(a0 + (-100)) = a2;
    if (branch) goto L_9cd20;
    goto L_9ce00;
L_9ce00:
    a2 = a1 + 1540;
    t1 = v1 + 2040;
L_9ce08:
    v0 = *(volatile u32 *)(unsigned long)(a2 + (-4));
    t0 = t0 + 12;
    a2 = a2 + 8;
    a0 = v0 >> (0x10 & 31);
    a3 = a0 & 0x1f;
    a3 = a3 << (0x10 & 31);
    v0 = v0 & 0xffff;
    v0 = a3 + v0;
    *(volatile u32 *)(unsigned long)(t0 + (-12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a2 + (-8));
    a0 = a0 >> (0x5 & 31);
    a3 = v0 & 0x3ff;
    a3 = a3 << (0xb & 31);
    a0 = a3 + a0;
    *(volatile u32 *)(unsigned long)(t0 + (-8)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(a2 + (-6));
    v0 = (v0 >> 0xa) & ((1U << 0x6) - 1);
    a0 = a0 & 0x7fff;
    a0 = a0 << (0x6 & 31);
    v0 = a0 + v0;
    branch = (t1 != t0); *(volatile u32 *)(unsigned long)(t0 + (-4)) = v0;
    if (branch) goto L_9ce08;
    goto L_9ce60;
L_9ce60:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (2896));
    v0 = a0 >> (0x10 & 31);
    a2 = v0 & 0x1f;
    a2 = a2 << (0x10 & 31);
    a0 = a0 & 0xffff;
    a0 = a2 + a0;
    *(volatile u32 *)(unsigned long)(v1 + (2040)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (2900));
    v0 = v0 >> (0x5 & 31);
    a0 = a0 & 0x3ff;
    a0 = a0 << (0xb & 31);
    v0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(v1 + (2044)) = v0;
    return ((u64)v1 << 32) | v0;
L_9ce98:
    branch = (v1 != a0); a2 = a1;
    if (branch) goto L_9cf64;
    goto L_9cea0;
L_9cea0:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = a0;
    a3 = a0 + 15000;
L_9ceac:
    v1 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 + 4;
    a2 = a2 + 4;
    t0 = v1 & 0xffff;
    v1 = (v1 >> 0x10) & ((1U << 0xf) - 1);
    *(volatile u32 *)(unsigned long)(v0 + (-4)) = t0;
    branch = (v0 != a3); *(volatile u32 *)(unsigned long)(v0 + (14996)) = v1;
    if (branch) goto L_9ceac;
    goto L_9cecc;
L_9cecc:
    a2 = a0 + 30000;
    a3 = a1 + 15004;
    t1 = a0 + 32040;
L_9ced8:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (-4));
    a2 = a2 + 12;
    a3 = a3 + 8;
    v1 = v0 >> (0x10 & 31);
    t0 = v1 & 0x1f;
    t0 = t0 << (0x10 & 31);
    v0 = v0 & 0xffff;
    v0 = t0 + v0;
    *(volatile u32 *)(unsigned long)(a2 + (-12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (-8));
    v1 = v1 >> (0x5 & 31);
    t0 = v0 & 0x3ff;
    t0 = t0 << (0xb & 31);
    v1 = t0 + v1;
    *(volatile u32 *)(unsigned long)(a2 + (-8)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(a3 + (-6));
    v0 = (v0 >> 0xa) & ((1U << 0x6) - 1);
    v1 = v1 & 0x7fff;
    v1 = v1 << (0x6 & 31);
    v0 = v1 + v0;
    branch = (a2 != t1); *(volatile u32 *)(unsigned long)(a2 + (-4)) = v0;
    if (branch) goto L_9ced8;
    goto L_9cf30;
L_9cf30:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (16360));
    v0 = v1 >> (0x10 & 31);
    a2 = v0 & 0x1f;
    a2 = a2 << (0x10 & 31);
    v1 = v1 & 0xffff;
    v1 = a2 + v1;
    *(volatile u32 *)(unsigned long)(a0 + (32040)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (16364));
    v0 = v0 >> (0x5 & 31);
    v1 = v1 & 0x3ff;
    v1 = v1 << (0xb & 31);
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a0 + (32044)) = v0;
L_9cf64:
    ;
    return ((u64)v1 << 32) | v0;
}
