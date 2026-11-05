/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2190[] __asm__("t32_data_e2190");
extern unsigned char ref_t32_data_e218c[] __asm__("t32_data_e218c");
extern unsigned char ref_t32_data_e2188[] __asm__("t32_data_e2188");
extern unsigned char ref_t32_data_e2184[] __asm__("t32_data_e2184");
extern unsigned char ref_t32_data_e2180[] __asm__("t32_data_e2180");
extern unsigned char ref_t32_data_e217c[] __asm__("t32_data_e217c");
u64 tisp_mdns_reg_cfg_equation_smp(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_605a4 = ((u32)(unsigned long)ref_t32_data_e2190 + 0x8000U) & 0xffff0000U;
    const u32 hi_605a8 = ((u32)(unsigned long)ref_t32_data_e218c + 0x8000U) & 0xffff0000U;
    const u32 hi_605ac = ((u32)(unsigned long)ref_t32_data_e2188 + 0x8000U) & 0xffff0000U;
    const u32 hi_605b0 = ((u32)(unsigned long)ref_t32_data_e2184 + 0x8000U) & 0xffff0000U;
    const u32 hi_605b4 = ((u32)(unsigned long)ref_t32_data_e2180 + 0x8000U) & 0xffff0000U;
    const u32 hi_605b8 = ((u32)(unsigned long)ref_t32_data_e217c + 0x8000U) & 0xffff0000U;
    const u32 hi_6069c = ((u32)(unsigned long)ref_t32_data_e2190 + 0x8000U) & 0xffff0000U;
    const u32 hi_606b4 = ((u32)(unsigned long)ref_t32_data_e218c + 0x8000U) & 0xffff0000U;
    const u32 hi_606cc = ((u32)(unsigned long)ref_t32_data_e2188 + 0x8000U) & 0xffff0000U;
    const u32 hi_606e4 = ((u32)(unsigned long)ref_t32_data_e2184 + 0x8000U) & 0xffff0000U;
    const u32 hi_606fc = ((u32)(unsigned long)ref_t32_data_e2180 + 0x8000U) & 0xffff0000U;
    const u32 hi_607f8 = ((u32)(unsigned long)ref_t32_data_e2190 + 0x8000U) & 0xffff0000U;
    const u32 hi_60810 = ((u32)(unsigned long)ref_t32_data_e218c + 0x8000U) & 0xffff0000U;
    const u32 hi_60828 = ((u32)(unsigned long)ref_t32_data_e2188 + 0x8000U) & 0xffff0000U;
    const u32 hi_60840 = ((u32)(unsigned long)ref_t32_data_e2184 + 0x8000U) & 0xffff0000U;
    const u32 hi_60858 = ((u32)(unsigned long)ref_t32_data_e2180 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_60568:
    v1 = (s32)a0 < (s32)(7);
    v0 = 6;
    if (v1 == 0) a0 = v0;
    v1 = (s32)a0 < (s32)(a1);
    v0 = a0 + 1;
    if (v1 == 0) a1 = v0;
    v1 = (s32)a1 < (s32)(7);
    v0 = 7;
    t7 = a3 - a2;
    if (v1 == 0) a1 = v0;
    v1 = (s32)t7 >> (0x1f & 31);
    v0 = v1 ^ t7;
    a1 = a1 - a0;
    v0 = v0 - v1;
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t5 = hi_605a4;
    t4 = hi_605a8;
    t3 = hi_605ac;
    t2 = hi_605b0;
    t1 = hi_605b4;
    t0 = hi_605b8;
    branch = ((s32)t7 <= 0); a1 = lo;
    if (branch) goto L_6071c;
    goto L_605c4;
L_605c4:
    branch = (a0 != 0); v0 = 1;
    if (branch) goto L_60600;
    goto L_605cc;
L_605cc:
    v1 = a2 + a1;
    *(volatile u32 *)(unsigned long)(t5 - hi_605a4 + (u32)(unsigned long)ref_t32_data_e2190) = v1;
    v1 = a1 + v1;
    *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c) = v1;
    v1 = a1 + v1;
    *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = v1;
    v1 = a1 + v1;
    *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = v1;
    v1 = a1 + v1;
    *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = v1;
    v1 = a1 + v1;
    *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c) = v1; goto L_6068c;
L_60600:
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t5 - hi_605a4 + (u32)(unsigned long)ref_t32_data_e2190) = a2;
    if (branch) goto L_60630;
    goto L_60608;
L_60608:
    t6 = a2 + a1;
    *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c) = t6;
    t6 = a1 + t6;
    *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = t6;
    t6 = a1 + t6;
    *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = t6;
    t6 = a1 + t6;
    *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = t6;
    a2 = a1 + t6; goto L_60688;
L_60630:
    v0 = 2;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c) = a2;
    if (branch) goto L_60648;
    goto L_6063c;
L_6063c:
    a2 = a2 + a1;
    *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = a2; goto L_60654;
L_60648:
    v0 = 3;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = a2;
    if (branch) goto L_60660;
    goto L_60654;
L_60654:
    a2 = a2 + a1;
    *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = a2; goto L_6066c;
L_60660:
    v0 = 4;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = a2;
    if (branch) goto L_60678;
    goto L_6066c;
L_6066c:
    a2 = a2 + a1;
    *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = a2; goto L_60684;
L_60678:
    v0 = 5;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = a2;
    if (branch) goto L_60688;
    goto L_60684;
L_60684:
    a2 = a2 + a1;
L_60688:
    *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c) = a2;
L_6068c:
    v0 = *(volatile u32 *)(unsigned long)(t5 - hi_605a4 + (u32)(unsigned long)ref_t32_data_e2190);
    v0 = (s32)v0 < (s32)(a3);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c);
    if (branch) goto L_606a8;
    goto L_6069c;
L_6069c:
    v0 = hi_6069c;
    *(volatile u32 *)(unsigned long)(v0 - hi_6069c + (u32)(unsigned long)ref_t32_data_e2190) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c);
L_606a8:
    v0 = (s32)v0 < (s32)(a3);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188);
    if (branch) goto L_606c0;
    goto L_606b4;
L_606b4:
    v0 = hi_606b4;
    *(volatile u32 *)(unsigned long)(v0 - hi_606b4 + (u32)(unsigned long)ref_t32_data_e218c) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188);
L_606c0:
    v0 = (s32)v0 < (s32)(a3);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184);
    if (branch) goto L_606d8;
    goto L_606cc;
L_606cc:
    v0 = hi_606cc;
    *(volatile u32 *)(unsigned long)(v0 - hi_606cc + (u32)(unsigned long)ref_t32_data_e2188) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184);
L_606d8:
    v0 = (s32)v0 < (s32)(a3);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180);
    if (branch) goto L_606f0;
    goto L_606e4;
L_606e4:
    v0 = hi_606e4;
    *(volatile u32 *)(unsigned long)(v0 - hi_606e4 + (u32)(unsigned long)ref_t32_data_e2184) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180);
L_606f0:
    v0 = (s32)v0 < (s32)(a3);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c);
    if (branch) goto L_60708;
    goto L_606fc;
L_606fc:
    v0 = hi_606fc;
    *(volatile u32 *)(unsigned long)(v0 - hi_606fc + (u32)(unsigned long)ref_t32_data_e2180) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c);
L_60708:
    v0 = (s32)v0 < (s32)(a3);
L_6070c:
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c) = a3; goto L_6086c; }
    goto L_60714;
L_60714:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
L_6071c:
    branch = (a0 != 0); v0 = 1;
    if (branch) goto L_60758;
    goto L_60724;
L_60724:
    v0 = a2 - a1;
    *(volatile u32 *)(unsigned long)(t5 - hi_605a4 + (u32)(unsigned long)ref_t32_data_e2190) = v0;
    v0 = v0 - a1;
    *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c) = v0;
    v0 = v0 - a1;
    *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = v0;
    v0 = v0 - a1;
    *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = v0;
    v0 = v0 - a1;
    *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = v0;
    v0 = v0 - a1;
    *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c) = v0; goto L_607e8;
L_60758:
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t5 - hi_605a4 + (u32)(unsigned long)ref_t32_data_e2190) = a2;
    if (branch) goto L_6078c;
    goto L_60760;
L_60760:
    a0 = a2 - a1;
    *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c) = a0;
    a0 = a0 - a1;
    *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = a0;
    a0 = a0 - a1;
    *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = a0;
    a0 = a0 - a1;
    *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = a0;
    a0 = a0 - a1;
    *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c) = a0; goto L_607e8;
L_6078c:
    v0 = 2;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c) = a2;
    if (branch) goto L_607a4;
    goto L_60798;
L_60798:
    a2 = a2 - a1;
    *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = a2; goto L_607b0;
L_607a4:
    v0 = 3;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188) = a2;
    if (branch) goto L_607bc;
    goto L_607b0;
L_607b0:
    a2 = a2 - a1;
    *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = a2; goto L_607c8;
L_607bc:
    v0 = 4;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184) = a2;
    if (branch) goto L_607d4;
    goto L_607c8;
L_607c8:
    a2 = a2 - a1;
    *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = a2; goto L_607e0;
L_607d4:
    v0 = 5;
    branch = (a0 != v0); *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180) = a2;
    if (branch) goto L_607e4;
    goto L_607e0;
L_607e0:
    a2 = a2 - a1;
L_607e4:
    *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c) = a2;
L_607e8:
    v0 = *(volatile u32 *)(unsigned long)(t5 - hi_605a4 + (u32)(unsigned long)ref_t32_data_e2190);
    v0 = (s32)a3 < (s32)(v0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c);
    if (branch) goto L_60804;
    goto L_607f8;
L_607f8:
    v0 = hi_607f8;
    *(volatile u32 *)(unsigned long)(v0 - hi_607f8 + (u32)(unsigned long)ref_t32_data_e2190) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t4 - hi_605a8 + (u32)(unsigned long)ref_t32_data_e218c);
L_60804:
    v0 = (s32)a3 < (s32)(v0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188);
    if (branch) goto L_6081c;
    goto L_60810;
L_60810:
    v0 = hi_60810;
    *(volatile u32 *)(unsigned long)(v0 - hi_60810 + (u32)(unsigned long)ref_t32_data_e218c) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t3 - hi_605ac + (u32)(unsigned long)ref_t32_data_e2188);
L_6081c:
    v0 = (s32)a3 < (s32)(v0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184);
    if (branch) goto L_60834;
    goto L_60828;
L_60828:
    v0 = hi_60828;
    *(volatile u32 *)(unsigned long)(v0 - hi_60828 + (u32)(unsigned long)ref_t32_data_e2188) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t2 - hi_605b0 + (u32)(unsigned long)ref_t32_data_e2184);
L_60834:
    v0 = (s32)a3 < (s32)(v0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180);
    if (branch) goto L_6084c;
    goto L_60840;
L_60840:
    v0 = hi_60840;
    *(volatile u32 *)(unsigned long)(v0 - hi_60840 + (u32)(unsigned long)ref_t32_data_e2184) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t1 - hi_605b4 + (u32)(unsigned long)ref_t32_data_e2180);
L_6084c:
    v0 = (s32)a3 < (s32)(v0);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c); goto L_60864; }
    goto L_60858;
L_60858:
    v0 = hi_60858;
    *(volatile u32 *)(unsigned long)(v0 - hi_60858 + (u32)(unsigned long)ref_t32_data_e2180) = a3;
    v0 = *(volatile u32 *)(unsigned long)(t0 - hi_605b8 + (u32)(unsigned long)ref_t32_data_e217c);
L_60864:
    v0 = (s32)a3 < (s32)(v0); goto L_6070c;
L_6086c:
    v0 = 0;
    ;
    return ((u64)v1 << 32) | v0;
}
