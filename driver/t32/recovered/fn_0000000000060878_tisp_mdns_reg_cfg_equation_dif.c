/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2170[] __asm__("t32_data_e2170");
extern unsigned char ref_t32_data_e216c[] __asm__("t32_data_e216c");
extern unsigned char ref_t32_data_e2168[] __asm__("t32_data_e2168");
extern unsigned char ref_t32_data_e2164[] __asm__("t32_data_e2164");
extern unsigned char ref_t32_data_e2160[] __asm__("t32_data_e2160");
extern unsigned char ref_t32_data_e215c[] __asm__("t32_data_e215c");
extern unsigned char ref_t32_data_e2158[] __asm__("t32_data_e2158");
extern unsigned char ref_t32_data_e2154[] __asm__("t32_data_e2154");
extern unsigned char ref_t32_data_e2178[] __asm__("t32_data_e2178");
extern unsigned char ref_t32_data_e2174[] __asm__("t32_data_e2174");
u64 tisp_mdns_reg_cfg_equation_dif(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_608c8 = ((u32)(unsigned long)ref_t32_data_e2170 + 0x8000U) & 0xffff0000U;
    const u32 hi_608dc = ((u32)(unsigned long)ref_t32_data_e216c + 0x8000U) & 0xffff0000U;
    const u32 hi_608e0 = ((u32)(unsigned long)ref_t32_data_e2168 + 0x8000U) & 0xffff0000U;
    const u32 hi_608e4 = ((u32)(unsigned long)ref_t32_data_e2164 + 0x8000U) & 0xffff0000U;
    const u32 hi_608e8 = ((u32)(unsigned long)ref_t32_data_e2160 + 0x8000U) & 0xffff0000U;
    const u32 hi_608ec = ((u32)(unsigned long)ref_t32_data_e215c + 0x8000U) & 0xffff0000U;
    const u32 hi_608f0 = ((u32)(unsigned long)ref_t32_data_e2158 + 0x8000U) & 0xffff0000U;
    const u32 hi_608f4 = ((u32)(unsigned long)ref_t32_data_e2154 + 0x8000U) & 0xffff0000U;
    const u32 hi_60b24 = ((u32)(unsigned long)ref_t32_data_e2178 + 0x8000U) & 0xffff0000U;
    const u32 hi_60b2c = ((u32)(unsigned long)ref_t32_data_e2174 + 0x8000U) & 0xffff0000U;
    const u32 hi_60a18 = ((u32)(unsigned long)ref_t32_data_e2154 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_60878:
    t2 = a0 ^ 0xff;
    v0 = 254;
    sp = sp + -24;
    if (t2 != 0) v0 = a0;
    v1 = (s32)v0 < (s32)(a1);
    t2 = v0;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s1;
    v0 = v0 + 1;
    s1 = a3 - a2;
    if (v1 == 0) a1 = v0;
    v1 = s1 << (0xd & 31);
    v0 = (s32)v1 >> (0x1f & 31);
    v1 = v0 ^ v1;
    v0 = v1 - v0;
    a1 = a1 - t2;
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = 256;
    a0 = v0 - a0;
    t0 = 7;
    *(volatile u32 *)(unsigned long)(sp + (0)) = s0;
    s0 = hi_608c8;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (12)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (8)) = s2;
    t8 = hi_608dc;
    t7 = hi_608e0;
    t6 = hi_608e4;
    t5 = hi_608e8;
    t4 = hi_608ec;
    t3 = hi_608f0;
    t9 = hi_608f4;
    *(volatile u32 *)(unsigned long)(s0 - hi_608c8 + (u32)(unsigned long)ref_t32_data_e2170) = a2;
    a1 = lo;
    if (a0 == 0x80000000U && t0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t0) { lo = (s32)a0 / (s32)t0; hi = (s32)a0 % (s32)t0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    v1 = a0 << (0x1 & 31);
    v0 = a0 << (0x2 & 31);
    t1 = a1 * a0;
    branch = ((s32)s1 <= 0); t0 = a0 << (0x3 & 31);
    if (branch) goto L_60a24;
    goto L_6091c;
L_6091c:
    s1 = 8192;
    if (t1 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)t1 / (s32)s1; hi = (s32)t1 % (s32)s1; } else { lo = (s32)t1 < 0 ? 1 : ~0U; hi = t1; }
    t1 = 6;
    s2 = lo;
    s2 = s2 + a2;
    *(volatile u32 *)(unsigned long)(t8 - hi_608dc + (u32)(unsigned long)ref_t32_data_e216c) = s2;
    s3 = v1 * a1;
    v1 = v1 + a0;
    if (s3 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)s3 / (s32)s1; hi = (s32)s3 % (s32)s1; } else { lo = (s32)s3 < 0 ? 1 : ~0U; hi = s3; }
    s3 = lo;
    s3 = s3 + a2;
    *(volatile u32 *)(unsigned long)(t7 - hi_608e0 + (u32)(unsigned long)ref_t32_data_e2168) = s3;
    v1 = v1 * a1;
    if (v1 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)v1 / (s32)s1; hi = (s32)v1 % (s32)s1; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = v1 + a2;
    *(volatile u32 *)(unsigned long)(t6 - hi_608e4 + (u32)(unsigned long)ref_t32_data_e2164) = v1;
    s4 = v0 * a1;
    v0 = v0 + a0;
    if (s4 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)s4 / (s32)s1; hi = (s32)s4 % (s32)s1; } else { lo = (s32)s4 < 0 ? 1 : ~0U; hi = s4; }
    s4 = lo;
    s4 = s4 + a2;
    *(volatile u32 *)(unsigned long)(t5 - hi_608e8 + (u32)(unsigned long)ref_t32_data_e2160) = s4;
    v0 = v0 * a1;
    if (v0 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)v0 / (s32)s1; hi = (s32)v0 % (s32)s1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + a2;
    *(volatile u32 *)(unsigned long)(t4 - hi_608ec + (u32)(unsigned long)ref_t32_data_e215c) = v0;
    t1 = a0 * t1;
    a0 = t0 - a0;
    t1 = t1 * a1;
    if (t1 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)t1 / (s32)s1; hi = (s32)t1 % (s32)s1; } else { lo = (s32)t1 < 0 ? 1 : ~0U; hi = t1; }
    t1 = lo;
    t1 = t1 + a2;
    *(volatile u32 *)(unsigned long)(t3 - hi_608f0 + (u32)(unsigned long)ref_t32_data_e2158) = t1;
    a0 = a0 * a1;
    if (a0 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)a0 / (s32)s1; hi = (s32)a0 % (s32)s1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    s1 = lo;
    s1 = s1 + a2;
    a2 = (s32)a2 < (s32)(a3);
    branch = (a2 != 0); *(volatile u32 *)(unsigned long)(t9 - hi_608f4 + (u32)(unsigned long)ref_t32_data_e2154) = s1;
    if (branch) goto L_609c8;
    goto L_609c4;
L_609c4:
    *(volatile u32 *)(unsigned long)(s0 - hi_608c8 + (u32)(unsigned long)ref_t32_data_e2170) = a3;
L_609c8:
    s2 = (s32)s2 < (s32)(a3);
    if (s2 == 0) { *(volatile u32 *)(unsigned long)(t8 - hi_608dc + (u32)(unsigned long)ref_t32_data_e216c) = a3; goto L_609d4; }
    goto L_609d4;
L_609d4:
    s3 = (s32)s3 < (s32)(a3);
    if (s3 == 0) { *(volatile u32 *)(unsigned long)(t7 - hi_608e0 + (u32)(unsigned long)ref_t32_data_e2168) = a3; goto L_609e0; }
    goto L_609e0;
L_609e0:
    v1 = (s32)v1 < (s32)(a3);
    if (v1 == 0) { *(volatile u32 *)(unsigned long)(t6 - hi_608e4 + (u32)(unsigned long)ref_t32_data_e2164) = a3; goto L_609ec; }
    goto L_609ec;
L_609ec:
    s4 = (s32)s4 < (s32)(a3);
    if (s4 == 0) { *(volatile u32 *)(unsigned long)(t5 - hi_608e8 + (u32)(unsigned long)ref_t32_data_e2160) = a3; goto L_609f8; }
    goto L_609f8;
L_609f8:
    v0 = (s32)v0 < (s32)(a3);
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(t4 - hi_608ec + (u32)(unsigned long)ref_t32_data_e215c) = a3; goto L_60a04; }
    goto L_60a04;
L_60a04:
    t1 = (s32)t1 < (s32)(a3);
    if (t1 == 0) { *(volatile u32 *)(unsigned long)(t3 - hi_608f0 + (u32)(unsigned long)ref_t32_data_e2158) = a3; goto L_60a10; }
    goto L_60a10;
L_60a10:
    s1 = (s32)s1 < (s32)(a3);
    branch = (s1 != 0); v0 = hi_60a18;
    if (branch) goto L_60b28;
    goto L_60a1c;
L_60a1c:
    *(volatile u32 *)(unsigned long)(t9 - hi_608f4 + (u32)(unsigned long)ref_t32_data_e2154) = a3; goto L_60b28;
L_60a24:
    s3 = 8192;
    if (t1 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)t1 / (s32)s3; hi = (s32)t1 % (s32)s3; } else { lo = (s32)t1 < 0 ? 1 : ~0U; hi = t1; }
    s4 = 6;
    t0 = t0 - a0;
    t1 = lo;
    t1 = a2 - t1;
    *(volatile u32 *)(unsigned long)(t8 - hi_608dc + (u32)(unsigned long)ref_t32_data_e216c) = t1;
    s1 = v1 * a1;
    v1 = v1 + a0;
    if (s1 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)s1 / (s32)s3; hi = (s32)s1 % (s32)s3; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    s1 = lo;
    s1 = a2 - s1;
    *(volatile u32 *)(unsigned long)(t7 - hi_608e0 + (u32)(unsigned long)ref_t32_data_e2168) = s1;
    v1 = v1 * a1;
    if (v1 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)v1 / (s32)s3; hi = (s32)v1 % (s32)s3; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = a2 - v1;
    *(volatile u32 *)(unsigned long)(t6 - hi_608e4 + (u32)(unsigned long)ref_t32_data_e2164) = v1;
    s2 = v0 * a1;
    v0 = v0 + a0;
    if (s2 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)s2 / (s32)s3; hi = (s32)s2 % (s32)s3; } else { lo = (s32)s2 < 0 ? 1 : ~0U; hi = s2; }
    s2 = lo;
    s2 = a2 - s2;
    *(volatile u32 *)(unsigned long)(t5 - hi_608e8 + (u32)(unsigned long)ref_t32_data_e2160) = s2;
    v0 = v0 * a1;
    if (v0 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)v0 / (s32)s3; hi = (s32)v0 % (s32)s3; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = a2 - v0;
    *(volatile u32 *)(unsigned long)(t4 - hi_608ec + (u32)(unsigned long)ref_t32_data_e215c) = v0;
    s4 = a0 * s4;
    s4 = s4 * a1;
    if (s4 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)s4 / (s32)s3; hi = (s32)s4 % (s32)s3; } else { lo = (s32)s4 < 0 ? 1 : ~0U; hi = s4; }
    s4 = lo;
    s4 = a2 - s4;
    *(volatile u32 *)(unsigned long)(t3 - hi_608f0 + (u32)(unsigned long)ref_t32_data_e2158) = s4;
    a0 = t0 * a1;
    if (a0 == 0x80000000U && s3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s3) { lo = (s32)a0 / (s32)s3; hi = (s32)a0 % (s32)s3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    a0 = a2 - a0;
    a2 = (s32)a3 < (s32)(a2);
    branch = (a2 != 0); *(volatile u32 *)(unsigned long)(t9 - hi_608f4 + (u32)(unsigned long)ref_t32_data_e2154) = a0;
    if (branch) goto L_60ad0;
    goto L_60acc;
L_60acc:
    *(volatile u32 *)(unsigned long)(s0 - hi_608c8 + (u32)(unsigned long)ref_t32_data_e2170) = a3;
L_60ad0:
    t1 = (s32)a3 < (s32)(t1);
    if (t1 == 0) { *(volatile u32 *)(unsigned long)(t8 - hi_608dc + (u32)(unsigned long)ref_t32_data_e216c) = a3; goto L_60adc; }
    goto L_60adc;
L_60adc:
    s1 = (s32)a3 < (s32)(s1);
    if (s1 == 0) { *(volatile u32 *)(unsigned long)(t7 - hi_608e0 + (u32)(unsigned long)ref_t32_data_e2168) = a3; goto L_60ae8; }
    goto L_60ae8;
L_60ae8:
    v1 = (s32)a3 < (s32)(v1);
    if (v1 == 0) { *(volatile u32 *)(unsigned long)(t6 - hi_608e4 + (u32)(unsigned long)ref_t32_data_e2164) = a3; goto L_60af4; }
    goto L_60af4;
L_60af4:
    s2 = (s32)a3 < (s32)(s2);
    if (s2 == 0) { *(volatile u32 *)(unsigned long)(t5 - hi_608e8 + (u32)(unsigned long)ref_t32_data_e2160) = a3; goto L_60b00; }
    goto L_60b00;
L_60b00:
    v0 = (s32)a3 < (s32)(v0);
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(t4 - hi_608ec + (u32)(unsigned long)ref_t32_data_e215c) = a3; goto L_60b0c; }
    goto L_60b0c;
L_60b0c:
    s4 = (s32)a3 < (s32)(s4);
    if (s4 == 0) { *(volatile u32 *)(unsigned long)(t3 - hi_608f0 + (u32)(unsigned long)ref_t32_data_e2158) = a3; goto L_60b18; }
    goto L_60b18;
L_60b18:
    a0 = (s32)a3 < (s32)(a0);
    if (a0 == 0) { *(volatile u32 *)(unsigned long)(t9 - hi_608f4 + (u32)(unsigned long)ref_t32_data_e2154) = a3; goto L_60b24; }
    goto L_60b24;
L_60b24:
    v0 = hi_60b24;
L_60b28:
    *(volatile u32 *)(unsigned long)(v0 - hi_60b24 + (u32)(unsigned long)ref_t32_data_e2178) = 0;
    v0 = hi_60b2c;
    s5 = *(volatile u32 *)(unsigned long)(sp + (20));
    s4 = *(volatile u32 *)(unsigned long)(sp + (16));
    s3 = *(volatile u32 *)(unsigned long)(sp + (12));
    s2 = *(volatile u32 *)(unsigned long)(sp + (8));
    s1 = *(volatile u32 *)(unsigned long)(sp + (4));
    s0 = *(volatile u32 *)(unsigned long)(sp + (0));
    *(volatile u32 *)(unsigned long)(v0 - hi_60b2c + (u32)(unsigned long)ref_t32_data_e2174) = t2;
    v0 = 0;
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
