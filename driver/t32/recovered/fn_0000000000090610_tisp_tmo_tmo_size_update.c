/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
u64 tisp_tmo_tmo_size_update(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_90610 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_90610:
    v0 = hi_90610;
    sp = sp + -24;
    v0 = v0 - hi_90610 + (u32)(unsigned long)ref_t32_data_e35e0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (12)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (8)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (0)) = s0;
    s2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    s1 = *(volatile u32 *)(unsigned long)(a1 + (4));
    v0 = 15;
    t9 = *(volatile u32 *)(unsigned long)(s2 + (12));
    s0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    s3 = *(volatile u32 *)(unsigned long)(s2 + (0));
    *(volatile u8 *)(unsigned long)(t9 + (4)) = v0;
    v0 = 25;
    *(volatile u8 *)(unsigned long)(t9 + (5)) = v0;
    *(volatile u16 *)(unsigned long)(t9 + (0)) = s1;
    v0 = 10;
    s1 = s1 & 0xffff;
    s1 = s1 + 7;
    *(volatile u8 *)(unsigned long)(t9 + (6)) = v0;
    v0 = 15;
    if (s1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)s1 / (s32)v0; hi = (s32)s1 % (s32)v0; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    *(volatile u16 *)(unsigned long)(t9 + (2)) = s0;
    s0 = s0 & 0xffff;
    s0 = s0 + 12;
    v0 = 25;
    s5 = 4;
    t8 = 2;
    *(volatile u8 *)(unsigned long)(t9 + (7)) = s5;
    s1 = lo;
    s1 = s1 & 0xffff;
    if (s0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)s0 / (s32)v0; hi = (s32)s0 % (s32)v0; } else { lo = (s32)s0 < 0 ? 1 : ~0U; hi = s0; }
    s0 = lo;
    s0 = s0 & 0xffff;
    v0 = s1 * s0;
    s4 = v0 & 0xffff;
    v0 = (u32)s4 < (u32)(8);
    branch = (v0 == 0); *(volatile u8 *)(unsigned long)(t9 + (8)) = t8;
    if (branch) goto L_906e0;
    goto L_906c0;
L_906c0:
    t7 = s4 >> (0x1 & 31);
    t7 = t7 + 8192;
    if (t7 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t7 / (s32)s4; hi = (s32)t7 % (s32)s4; } else { lo = (s32)t7 < 0 ? 1 : ~0U; hi = t7; }
    *(volatile u8 *)(unsigned long)(t9 + (18)) = 0;
    v1 = 13;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_906e0:
    v0 = (u32)s4 < (u32)(16);
    if (v0 == 0) { v0 = (u32)s4 < (u32)(32); goto L_9070c; }
    goto L_906ec;
L_906ec:
    t6 = s4 >> (0x1 & 31);
    t6 = t6 + 16384;
    if (t6 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t6 / (s32)s4; hi = (s32)t6 % (s32)s4; } else { lo = (s32)t6 < 0 ? 1 : ~0U; hi = t6; }
    *(volatile u8 *)(unsigned long)(t9 + (18)) = 0;
    v1 = 14;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_9070c:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(64); goto L_90738; }
    goto L_90714;
L_90714:
    v0 = s4 >> (0x1 & 31);
    t5 = 0x8000;
    t5 = v0 + t5;
    if (t5 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t5 / (s32)s4; hi = (s32)t5 % (s32)s4; } else { lo = (s32)t5 < 0 ? 1 : ~0U; hi = t5; }
    *(volatile u8 *)(unsigned long)(t9 + (18)) = 0;
    v1 = 15;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_90738:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(128); goto L_90764; }
    goto L_90740;
L_90740:
    v0 = s4 >> (0x1 & 31);
    t4 = 0x1U << 16;
    t4 = v0 + t4;
    if (t4 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t4 / (s32)s4; hi = (s32)t4 % (s32)s4; } else { lo = (s32)t4 < 0 ? 1 : ~0U; hi = t4; }
    *(volatile u8 *)(unsigned long)(t9 + (18)) = 0;
    v1 = 16;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_90764:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(256); goto L_90794; }
    goto L_9076c;
L_9076c:
    v0 = s4 >> (0x1 & 31);
    t3 = 0x2U << 16;
    t3 = v0 + t3;
    if (t3 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t3 / (s32)s4; hi = (s32)t3 % (s32)s4; } else { lo = (s32)t3 < 0 ? 1 : ~0U; hi = t3; }
    v1 = 1;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 17;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_90794:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(512); goto L_907c0; }
    goto L_9079c;
L_9079c:
    v0 = s4 >> (0x1 & 31);
    t2 = 0x4U << 16;
    t2 = v0 + t2;
    if (t2 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t2 / (s32)s4; hi = (s32)t2 % (s32)s4; } else { lo = (s32)t2 < 0 ? 1 : ~0U; hi = t2; }
    *(volatile u8 *)(unsigned long)(t9 + (18)) = t8;
    v1 = 18;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_907c0:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(1024); goto L_907f0; }
    goto L_907c8;
L_907c8:
    v0 = s4 >> (0x1 & 31);
    t1 = 0x8U << 16;
    t1 = v0 + t1;
    if (t1 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t1 / (s32)s4; hi = (s32)t1 % (s32)s4; } else { lo = (s32)t1 < 0 ? 1 : ~0U; hi = t1; }
    v1 = 3;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 19;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_907f0:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(2048); goto L_9081c; }
    goto L_907f8;
L_907f8:
    t8 = s4 >> (0x1 & 31);
    t0 = 0x10U << 16;
    t0 = t8 + t0;
    if (t0 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)t0 / (s32)s4; hi = (s32)t0 % (s32)s4; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    *(volatile u8 *)(unsigned long)(t9 + (18)) = s5;
    v1 = 20;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_9081c:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(4096); goto L_9084c; }
    goto L_90824;
L_90824:
    t8 = s4 >> (0x1 & 31);
    a3 = 0x20U << 16;
    a3 = t8 + a3;
    if (a3 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)a3 / (s32)s4; hi = (s32)a3 % (s32)s4; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    v1 = 5;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 21;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_9084c:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(8192); goto L_9087c; }
    goto L_90854;
L_90854:
    t8 = s4 >> (0x1 & 31);
    a2 = 0x40U << 16;
    a2 = t8 + a2;
    if (a2 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)a2 / (s32)s4; hi = (s32)a2 % (s32)s4; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    v1 = 6;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 22;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_9087c:
    if (v0 == 0) { v0 = (u32)s4 < (u32)(16384); goto L_908ac; }
    goto L_90884;
L_90884:
    t8 = s4 >> (0x1 & 31);
    a1 = 0x80U << 16;
    a1 = t8 + a1;
    if (a1 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)a1 / (s32)s4; hi = (s32)a1 % (s32)s4; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    v1 = 7;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 23;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_908ac:
    if (v0 == 0) { v0 = (int16_t)s4; goto L_908dc; }
    goto L_908b4;
L_908b4:
    t8 = s4 >> (0x1 & 31);
    a0 = 0x100U << 16;
    a0 = t8 + a0;
    if (a0 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)a0 / (s32)s4; hi = (s32)a0 % (s32)s4; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = 8;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 24;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_908dc:
    branch = ((s32)v0 < 0); t8 = s4 >> (0x1 & 31);
    if (branch) goto L_90908;
    goto L_908e4;
L_908e4:
    v1 = 0x200U << 16;
    v1 = t8 + v1;
    if (v1 == 0x80000000U && s4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s4) { lo = (s32)v1 / (s32)s4; hi = (s32)v1 % (s32)s4; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = 9;
    *(volatile u8 *)(unsigned long)(t9 + (18)) = v1;
    v1 = 25;
    v0 = lo;
    v0 = v0 & 0xffff; goto L_90910;
L_90908:
    v1 = 0;
    v0 = 0;
L_90910:
    a0 = *(volatile u32 *)(unsigned long)(s2 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (48)) = s1;
    a0 = *(volatile u32 *)(unsigned long)(s2 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (50)) = s0;
    a0 = *(volatile u32 *)(unsigned long)(s2 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (52)) = v0;
    *(volatile u8 *)(unsigned long)(s3 + (10039)) = v1;
    a2 = *(volatile u8 *)(unsigned long)(t9 + (7));
    a1 = *(volatile u8 *)(unsigned long)(t9 + (4));
    a3 = *(volatile u8 *)(unsigned long)(t9 + (5));
    a0 = *(volatile u8 *)(unsigned long)(t9 + (8));
    v1 = a2 << (0x1 & 31);
    t0 = *(volatile u8 *)(unsigned long)(t9 + (6));
    v0 = v1 & 0xff;
    v1 = a1 + v0;
    a0 = a0 << (0x1 & 31);
    v0 = v0 + a3;
    v1 = v1 & 0xff;
    v0 = v0 & 0xff;
    a0 = a0 + t0;
    *(volatile u8 *)(unsigned long)(t9 + (11)) = a0;
    a1 = a1 * a3;
    *(volatile u8 *)(unsigned long)(t9 + (9)) = v1;
    *(volatile u8 *)(unsigned long)(t9 + (10)) = v0;
    a0 = v1 * v0;
    v1 = v1 - a2;
    v0 = v0 - a2;
    *(volatile u16 *)(unsigned long)(t9 + (14)) = a1;
    *(volatile u8 *)(unsigned long)(t9 + (12)) = v1;
    *(volatile u8 *)(unsigned long)(t9 + (13)) = v0;
    *(volatile u16 *)(unsigned long)(t9 + (16)) = a0;
    s5 = *(volatile u32 *)(unsigned long)(sp + (20));
    s4 = *(volatile u32 *)(unsigned long)(sp + (16));
    s3 = *(volatile u32 *)(unsigned long)(sp + (12));
    s2 = *(volatile u32 *)(unsigned long)(sp + (8));
    s1 = *(volatile u32 *)(unsigned long)(sp + (4));
    s0 = *(volatile u32 *)(unsigned long)(sp + (0));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
