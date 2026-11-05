/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
u64 tisp_tmo_tmo_detail_ev_interp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[68] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_962f4 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[4];
L_962f4:
    v0 = hi_962f4;
    sp = sp + -16;
    v0 = v0 - hi_962f4 + (u32)(unsigned long)ref_t32_data_e35e0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (8)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (12)) = s2;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = *(volatile u8 *)(unsigned long)(t2 + (10931));
    t4 = t2 + 2530;
    s1 = t2 + 2552;
    s0 = t2 + 2574;
    t8 = t2 + 2596;
    t3 = t2 + 2618;
    t9 = t2 + 2640;
    t7 = t2 + 2662;
    branch = (v1 != 0); t6 = t2 + 2684;
    if (branch) goto L_963ec;
    goto L_96348;
L_96348:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (24));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (28));
    a1 = t2 + 888;
    a0 = 0;
    t0 = 9;
L_9635c:
    branch = (a3 != 0); v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    if (branch) goto L_96370;
    goto L_96364;
L_96364:
    v1 = (u32)a2 < (u32)(v0);
    if (v1 != 0) { a0 = a0 + 1; goto L_963a4; }
    goto L_96370;
L_96370:
    branch = (a3 != 0); v1 = *(volatile u32 *)(unsigned long)(a1 + (4));
    if (branch) goto L_963a0;
    goto L_96378;
L_96378:
    t5 = (u32)a2 < (u32)(v1);
    if (t5 == 0) { a0 = a0 + 1; goto L_963a4; }
    goto L_96384;
L_96384:
    a1 = v1 - a2;
    a1 = a1 << (0x8 & 31);
    v1 = v1 - v0;
    if (v1) { lo = a1 / v1; hi = a1 % v1; } else { lo = ~0U; hi = a1; }
    v1 = lo;
    v0 = v1 & 0xffff; goto L_963b4;
L_963a0:
    a0 = a0 + 1;
L_963a4:
    a0 = a0 & 0xff;
    branch = (a0 != t0); a1 = a1 + 4;
    if (branch) goto L_9635c;
    goto L_963b0;
L_963b0:
    v0 = 0;
L_963b4:
    branch = (a3 != 0); v1 = *(volatile u32 *)(unsigned long)(t2 + (924));
    if (branch) goto L_963c8;
    goto L_963bc;
L_963bc:
    v1 = (u32)a2 < (u32)(v1);
    branch = (v1 != 0); ;
    if (branch) goto L_963d0;
    goto L_963c8;
L_963c8:
    v0 = 256;
    a0 = 9;
L_963d0:
    branch = (a3 != 0); v1 = *(volatile u32 *)(unsigned long)(t2 + (888));
    if (branch) goto L_96470;
    goto L_963d8;
L_963d8:
    a2 = (u32)a2 < (u32)(v1);
    v1 = 256;
    if (a2 != 0) v0 = v1;
    if (a2 != 0) a0 = 0; goto L_96470;
L_963ec:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (32));
    a2 = t2 + 1008;
    a0 = 0;
    a3 = 9;
L_963fc:
    a1 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = (u32)a1 < (u32)(v1);
    if (v0 != 0) { a0 = a0 + 1; goto L_96438; }
    goto L_9640c;
L_9640c:
    v0 = *(volatile u32 *)(unsigned long)(a2 + (4));
    t0 = (u32)v0 < (u32)(v1);
    if (t0 == 0) { a0 = a0 + 1; goto L_96438; }
    goto L_9641c;
L_9641c:
    a2 = a1 - v1;
    a2 = a2 << (0x8 & 31);
    a1 = a1 - v0;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    v0 = a1 & 0xffff; goto L_96448;
L_96438:
    a0 = a0 & 0xff;
    branch = (a0 != a3); a2 = a2 + 4;
    if (branch) goto L_963fc;
    goto L_96444;
L_96444:
    v0 = 0;
L_96448:
    a1 = *(volatile u32 *)(unsigned long)(t2 + (1044));
    a2 = 256;
    a3 = 9;
    a1 = (u32)a1 < (u32)(v1);
    if (a1 == 0) v0 = a2;
    if (a1 == 0) a0 = a3;
    a1 = *(volatile u32 *)(unsigned long)(t2 + (1008));
    v1 = (u32)a1 < (u32)(v1);
    if (v1 != 0) v0 = a2;
    if (v1 != 0) a0 = 0;
L_96470:
    a2 = a0 + 1;
    a2 = t2 + a2;
    t0 = *(volatile int8_t *)(unsigned long)(a2 + (10932));
    v1 = 256;
    a1 = v1 - v0;
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    a3 = t2 + a0;
    t5 = *(volatile int8_t *)(unsigned long)(a3 + (10932));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (363)) = t0;
    t0 = *(volatile int8_t *)(unsigned long)(a2 + (10943));
    t5 = *(volatile int8_t *)(unsigned long)(a3 + (10943));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (364)) = t0;
    t0 = *(volatile int8_t *)(unsigned long)(a2 + (10954));
    t5 = *(volatile int8_t *)(unsigned long)(a3 + (10954));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (365)) = t0;
    t0 = *(volatile int8_t *)(unsigned long)(a2 + (10965));
    t5 = *(volatile int8_t *)(unsigned long)(a3 + (10965));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (366)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10053));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10053));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (367)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10064));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10064));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (368)) = t0;
    t0 = *(volatile int8_t *)(unsigned long)(a2 + (10976));
    t5 = *(volatile int8_t *)(unsigned long)(a3 + (10976));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (369)) = t0;
    t0 = *(volatile int8_t *)(unsigned long)(a2 + (10987));
    t5 = *(volatile int8_t *)(unsigned long)(a3 + (10987));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (370)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10075));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10075));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (379)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10086));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10086));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (380)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10097));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10097));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (381)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10108));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10108));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (382)) = t0;
    t0 = *(volatile u8 *)(unsigned long)(a2 + (10119));
    t5 = *(volatile u8 *)(unsigned long)(a3 + (10119));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t5 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    if (t0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t0 / (s32)v1; hi = (s32)t0 % (s32)v1; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    t0 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (383)) = t0;
    a2 = *(volatile u8 *)(unsigned long)(a2 + (10130));
    a3 = *(volatile u8 *)(unsigned long)(a3 + (10130));
    t0 = a0 << (0x1 & 31);
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    t5 = t0 + 2;
    a0 = t4 + t0;
    t4 = t4 + t5;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)v0); lo = product; hi = product >> 32;
    a2 = lo;
    if (a2 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a2 / (s32)v1; hi = (s32)a2 % (s32)v1; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u8 *)(unsigned long)(t1 + (384)) = a2;
    a3 = *(volatile u16 *)(unsigned long)(t4 + (0));
    a2 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = s1 + t0;
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    s1 = s1 + t5;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v0); lo = product; hi = product >> 32;
    a3 = lo;
    if (a3 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a3 / (s32)v1; hi = (s32)a3 % (s32)v1; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    s2 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (56)) = s2;
    a3 = *(volatile u16 *)(unsigned long)(s1 + (0));
    a2 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = s0 + t0;
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    s0 = s0 + t5;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v0); lo = product; hi = product >> 32;
    a3 = lo;
    if (a3 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a3 / (s32)v1; hi = (s32)a3 % (s32)v1; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    t4 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (60)) = t4;
    a2 = *(volatile u16 *)(unsigned long)(s0 + (0));
    s1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = t8 + t0;
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    t8 = t8 + t5;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s1 * (s32)v0); lo = product; hi = product >> 32;
    a2 = lo;
    if (a2 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a2 / (s32)v1; hi = (s32)a2 % (s32)v1; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (64)) = a3;
    a2 = *(volatile u16 *)(unsigned long)(t8 + (0));
    s0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = t3 + t0;
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    t3 = t3 + t5;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s0 * (s32)v0); lo = product; hi = product >> 32;
    a2 = lo;
    if (a2 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a2 / (s32)v1; hi = (s32)a2 % (s32)v1; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (68)) = a2;
    s0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t3 + (0));
    a2 = a3 - a2;
    product = (s64)(s32)a0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s0 * (s32)v0); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a0 / (s32)v1; hi = (s32)a0 % (s32)v1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = t9 + t0;
    t9 = t9 + t5;
    t8 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (76)) = t8;
    s0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t9 + (0));
    product = (s64)(s32)a0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s0 * (s32)v0); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a0 / (s32)v1; hi = (s32)a0 % (s32)v1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = t7 + t0;
    t7 = t7 + t5;
    t0 = t6 + t0;
    t5 = t6 + t5;
    t3 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (80)) = t3;
    t7 = *(volatile u16 *)(unsigned long)(t7 + (0));
    t9 = *(volatile u16 *)(unsigned long)(a0 + (0));
    product = (s64)(s32)t7 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t9 * (s32)v0); lo = product; hi = product >> 32;
    t7 = lo;
    if (t7 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t7 / (s32)v1; hi = (s32)t7 % (s32)v1; } else { lo = (s32)t7 < 0 ? 1 : ~0U; hi = t7; }
    t7 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (84)) = t7;
    a0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t0 = *(volatile u16 *)(unsigned long)(t5 + (0));
    product = (s64)(s32)t0 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = lo;
    branch = (s2 != t4); *(volatile u32 *)(unsigned long)(t1 + (88)) = v1;
    if (branch) goto L_967a0;
    goto L_96794;
L_96794:
    a2 = a2 << (0xa & 31);
    *(volatile u32 *)(unsigned long)(t1 + (72)) = a2; goto L_967bc;
L_967a0:
    a3 = t4 - s2;
    a2 = a2 << (0xa & 31);
    a0 = a3 >> (0x1 & 31);
    a0 = a2 + a0;
    if (a3) { lo = a0 / a3; hi = a0 % a3; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (72)) = a0;
L_967bc:
    branch = (t8 != t3); v0 = v1 - t7;
    if (branch) goto L_967d0;
    goto L_967c4;
L_967c4:
    v0 = v0 << (0x7 & 31);
    *(volatile u32 *)(unsigned long)(t1 + (92)) = v0; goto L_967ec;
L_967d0:
    a0 = t3 - t8;
    v0 = v0 << (0x7 & 31);
    v1 = a0 >> (0x1 & 31);
    v1 = v0 + v1;
    if (a0) { lo = v1 / a0; hi = v1 % a0; } else { lo = ~0U; hi = v1; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (92)) = v1;
L_967ec:
    v0 = *(volatile u16 *)(unsigned long)(t2 + (2706));
    *(volatile u32 *)(unsigned long)(t1 + (96)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (2708));
    *(volatile u32 *)(unsigned long)(t1 + (100)) = v0;
    s2 = *(volatile u32 *)(unsigned long)(sp + (12));
    s1 = *(volatile u32 *)(unsigned long)(sp + (8));
    s0 = *(volatile u32 *)(unsigned long)(sp + (4));
    sp = sp + 16;
    return ((u64)v1 << 32) | v0;
}
