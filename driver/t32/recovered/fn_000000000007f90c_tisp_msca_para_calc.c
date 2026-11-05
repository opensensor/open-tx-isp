/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e28ac[] __asm__("t32_data_e28ac");
extern unsigned char ref_t32_data_e2768[] __asm__("t32_data_e2768");
u64 tisp_msca_para_calc(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7f910 = ((u32)(unsigned long)ref_t32_data_e28ac + 0x8000U) & 0xffff0000U;
    const u32 hi_7f924 = ((u32)(unsigned long)ref_t32_data_e2768 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_7f90c:
    a0 = a0 & 0xff;
    v0 = hi_7f910;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_7f910 + (u32)(unsigned long)ref_t32_data_e28ac;
    v0 = a0 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_7f924;
    v0 = v0 - hi_7f924 + (u32)(unsigned long)ref_t32_data_e2768;
    a0 = a0 + v0;
    a1 = a1 & 0xff;
    v0 = 872;
    a2 = a1 * v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = a2 + a0;
    t0 = *(volatile u16 *)(unsigned long)(v0 + (26));
    a0 = *(volatile u16 *)(unsigned long)(v0 + (34));
    a3 = *(volatile u16 *)(unsigned long)(v0 + (28));
    t0 = t0 << (0xe & 31);
    if (t0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)t0 / (s32)a0; hi = (s32)t0 % (s32)a0; } else { lo = (s32)t0 < 0 ? 1 : ~0U; hi = t0; }
    v0 = *(volatile u16 *)(unsigned long)(v0 + (32));
    a3 = a3 << (0xe & 31);
    t0 = lo;
    if (a3 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a3 / (s32)v0; hi = (s32)a3 % (s32)v0; } else { lo = (s32)a3 < 0 ? 1 : ~0U; hi = a3; }
    v0 = 1;
    branch = (a1 == v0); a3 = lo;
    if (branch) goto L_7f9b4;
    goto L_7f974;
L_7f974:
    if (a1 == 0) { a2 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_7f9a0; }
    goto L_7f97c;
L_7f97c:
    v0 = 2;
    if (a1 != v0) { a2 = 0; goto L_7f9cc; }
    goto L_7f988;
L_7f988:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a2 + (68));
    v0 = *(volatile u32 *)(unsigned long)(a2 + (72));
    t2 = *(volatile u32 *)(unsigned long)(a2 + (76));
    a2 = *(volatile u32 *)(unsigned long)(a2 + (80)); goto L_7f9d8;
L_7f9a0:
    a0 = *(volatile u32 *)(unsigned long)(a2 + (4));
    v0 = *(volatile u32 *)(unsigned long)(a2 + (8));
    t2 = *(volatile u32 *)(unsigned long)(a2 + (12));
    a2 = *(volatile u32 *)(unsigned long)(a2 + (16)); goto L_7f9d8;
L_7f9b4:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a2 + (36));
    v0 = *(volatile u32 *)(unsigned long)(a2 + (40));
    t2 = *(volatile u32 *)(unsigned long)(a2 + (44));
    a2 = *(volatile u32 *)(unsigned long)(a2 + (48)); goto L_7f9d8;
L_7f9cc:
    t2 = 0;
    v0 = 0;
    a0 = 0;
L_7f9d8:
    a0 = v0 - a0;
    a0 = a0 & 0xffff;
    t6 = (u32)a2 < (u32)(t2);
    t4 = a0 >> (0x1 & 31);
    t1 = 8;
    t5 = 1;
    a2 = a2 - t2;
    t2 = t1;
L_7f9f8:
    branch = (a0 == 0); v0 = 0;
    if (branch) goto L_7fa24;
    goto L_7fa00;
L_7fa00:
    branch = (t6 == 0); v0 = t5 << (t1 & 31);
    if (branch) goto L_7fa14;
    goto L_7fa08;
L_7fa08:
    v0 = a2 * v0;
    v0 = v0 - t4; goto L_7fa1c;
L_7fa14:
    t3 = a2 * v0;
    v0 = t3 + t4;
L_7fa1c:
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v0 = lo;
L_7fa24:
    t3 = v0 + 128;
    t3 = (u32)t3 < (u32)(257);
    if (t3 != 0) { a0 = 1; goto L_7fa4c; }
    goto L_7fa34;
L_7fa34:
    t1 = t1 + -1;
    branch = (t1 != 0); t2 = t1;
    if (branch) goto L_7f9f8;
    goto L_7fa40;
L_7fa40:
    t2 = 8;
    v0 = 0;
    a0 = 1;
L_7fa4c:
    if (a1 == a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_7fa90; }
    goto L_7fa54;
L_7fa54:
    branch = (a1 == 0); a0 = 2;
    if (branch) goto L_7fa6c;
    goto L_7fa5c;
L_7fa5c:
    if (a1 == a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_7fab0; }
    goto L_7fa64;
L_7fa64:
    ;
    return ((u64)v1 << 32) | v0;
L_7fa6c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (24)) = t2;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (28)) = t0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (32)) = a3;
    return ((u64)v1 << 32) | v0;
L_7fa90:
    *(volatile u32 *)(unsigned long)(a0 + (52)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (56)) = t2;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (60)) = t0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (64)) = a3;
    return ((u64)v1 << 32) | v0;
L_7fab0:
    *(volatile u32 *)(unsigned long)(a0 + (84)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (88)) = t2;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (92)) = t0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (96)) = a3;
    return ((u64)v1 << 32) | v0;
}
