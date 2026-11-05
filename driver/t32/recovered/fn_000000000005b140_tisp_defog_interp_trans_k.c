/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2130[] __asm__("t32_data_e2130");
u64 tisp_defog_interp_trans_k(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_5b148 = ((u32)(unsigned long)ref_t32_data_e2130 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
    stack[5] = arg5;
    stack[6] = arg6;
    stack[7] = arg7;
    stack[8] = arg8;
L_5b140:
    a0 = a0 & 0xff;
    v1 = a0 << (0x2 & 31);
    a0 = hi_5b148;
    a0 = a0 - hi_5b148 + (u32)(unsigned long)ref_t32_data_e2130;
    a0 = v1 + a0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t0 = *(volatile u32 *)(unsigned long)(sp + (16));
    t1 = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (12));
    t2 = *(volatile u32 *)(unsigned long)(sp + (24));
    t4 = *(volatile u32 *)(unsigned long)(sp + (28));
    t3 = *(volatile u8 *)(unsigned long)(a0 + (191));
    branch = (t3 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (branch) goto L_5b190;
    goto L_5b178;
L_5b178:
    a0 = a0 + 44;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (28));
    t3 = a0;
    v1 = 0;
    t6 = 8; goto L_5b30c;
L_5b190:
    a0 = a2;
    v1 = 0;
    t6 = 8;
L_5b19c:
    t3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t5 = (u32)a1 < (u32)(t3);
    branch = (t5 == 0); ;
    if (branch) goto L_5b2c4;
    goto L_5b1ac;
L_5b1ac:
    if (v1 != 0) { a0 = v1 << (0x2 & 31); goto L_5b1dc; }
    goto L_5b1b4;
L_5b1b4:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (0));
L_5b1b8:
    *(volatile u8 *)(unsigned long)(v0 + (0)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t0 + (0));
    *(volatile u8 *)(unsigned long)(v0 + (1)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t1 + (0));
    *(volatile u8 *)(unsigned long)(v0 + (2)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t2 + (0));
    *(volatile u8 *)(unsigned long)(v0 + (3)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t4 + (0)); goto L_5b2f0;
L_5b1dc:
    a2 = a2 + a0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (-4));
    t6 = v1 + -1;
    a2 = a1 - a2;
    a1 = t3 - a1;
    t3 = a3 + v1;
    a3 = a3 + t6;
    a3 = *(volatile u8 *)(unsigned long)(a3 + (0));
    t3 = *(volatile u8 *)(unsigned long)(t3 + (0));
    a0 = a2 + a1;
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    t5 = a0 >> (0x1 & 31);
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t3 * (s32)a2); lo = product; hi = product >> 32;
    a3 = lo;
    a3 = a3 + t5;
    if (a0) { lo = a3 / a0; hi = a3 % a0; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (0)) = a3;
    a3 = t0 + v1;
    t0 = t0 + t6;
    t3 = *(volatile u8 *)(unsigned long)(a3 + (0));
    a3 = *(volatile u8 *)(unsigned long)(t0 + (0));
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t3 * (s32)a2); lo = product; hi = product >> 32;
    a3 = lo;
    a3 = a3 + t5;
    if (a0) { lo = a3 / a0; hi = a3 % a0; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (1)) = a3;
    a3 = t1 + v1;
    t1 = t1 + t6;
    t0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    a3 = *(volatile u8 *)(unsigned long)(t1 + (0));
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)a2); lo = product; hi = product >> 32;
    a3 = lo;
    a3 = a3 + t5;
    if (a0) { lo = a3 / a0; hi = a3 % a0; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (2)) = a3;
    a3 = t2 + v1;
    t2 = t2 + t6;
    t0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    a3 = *(volatile u8 *)(unsigned long)(t2 + (0));
    v1 = t4 + v1;
    t4 = t4 + t6;
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)a2); lo = product; hi = product >> 32;
    a3 = lo;
    a3 = a3 + t5;
    if (a0) { lo = a3 / a0; hi = a3 % a0; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (3)) = a3;
    a3 = *(volatile u8 *)(unsigned long)(t4 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    product = (s64)(s32)a3 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a2); lo = product; hi = product >> 32; goto L_5b40c;
L_5b2c4:
    branch = (v1 != t6); a0 = a0 + 4;
    if (branch) goto L_5b2f8;
    goto L_5b2cc;
L_5b2cc:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (0)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t0 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (1)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t1 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (2)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t2 + (8));
    *(volatile u8 *)(unsigned long)(v0 + (3)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(t4 + (8));
L_5b2f0:
    *(volatile u8 *)(unsigned long)(v0 + (4)) = v1;
    return ((u64)v1 << 32) | v0;
L_5b2f8:
    v1 = v1 + 1; goto L_5b19c;
L_5b300:
    branch = (v1 == t6); t3 = t3 + 4;
    if (branch) goto L_5b2cc;
    goto L_5b308;
L_5b308:
    v1 = v1 + 1;
L_5b30c:
    t5 = *(volatile u32 *)(unsigned long)(t3 + (0));
    a1 = (u32)t5 < (u32)(a2);
    branch = (a1 == 0); ;
    if (branch) goto L_5b300;
    goto L_5b31c;
L_5b31c:
    if (v1 == 0) { v1 = *(volatile u8 *)(unsigned long)(a3 + (0)); goto L_5b1b8; }
    goto L_5b324;
L_5b324:
    a1 = v1 << (0x2 & 31);
    a0 = a0 + a1;
    a1 = *(volatile u32 *)(unsigned long)(a0 + (-4));
    t6 = v1 + -1;
    t3 = a1 - a2;
    a1 = a2 - t5;
    a2 = a3 + v1;
    a3 = a3 + t6;
    t7 = *(volatile u8 *)(unsigned long)(a2 + (0));
    a2 = *(volatile u8 *)(unsigned long)(a3 + (0));
    a0 = t3 + a1;
    t5 = a0 >> (0x1 & 31);
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t7 * (s32)t3); lo = product; hi = product >> 32;
    a2 = lo;
    a2 = a2 + t5;
    if (a0) { lo = a2 / a0; hi = a2 % a0; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (0)) = a2;
    a2 = t0 + v1;
    t0 = t0 + t6;
    a3 = *(volatile u8 *)(unsigned long)(a2 + (0));
    a2 = *(volatile u8 *)(unsigned long)(t0 + (0));
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t3); lo = product; hi = product >> 32;
    a2 = lo;
    a2 = a2 + t5;
    if (a0) { lo = a2 / a0; hi = a2 % a0; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (1)) = a2;
    a2 = t1 + v1;
    t1 = t1 + t6;
    a3 = *(volatile u8 *)(unsigned long)(a2 + (0));
    a2 = *(volatile u8 *)(unsigned long)(t1 + (0));
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t3); lo = product; hi = product >> 32;
    a2 = lo;
    a2 = a2 + t5;
    if (a0) { lo = a2 / a0; hi = a2 % a0; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (2)) = a2;
    a2 = t2 + v1;
    t2 = t2 + t6;
    a3 = *(volatile u8 *)(unsigned long)(a2 + (0));
    a2 = *(volatile u8 *)(unsigned long)(t2 + (0));
    v1 = t4 + v1;
    t4 = t4 + t6;
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t3); lo = product; hi = product >> 32;
    a2 = lo;
    a2 = a2 + t5;
    if (a0) { lo = a2 / a0; hi = a2 % a0; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (3)) = a2;
    a2 = *(volatile u8 *)(unsigned long)(t4 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    product = (s64)(s32)a2 * (s32)a1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)t3); lo = product; hi = product >> 32;
L_5b40c:
    a1 = lo;
    a1 = a1 + t5;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u8 *)(unsigned long)(v0 + (4)) = a0;
    return ((u64)v1 << 32) | v0;
}
