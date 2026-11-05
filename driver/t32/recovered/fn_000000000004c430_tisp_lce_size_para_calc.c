/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
extern unsigned char ref_t32_data_d6c65[] __asm__("t32_data_d6c65");
extern unsigned char ref_t32_data_d6c64[] __asm__("t32_data_d6c64");
extern unsigned char ref_t32_data_e1da8[] __asm__("t32_data_e1da8");
u64 tisp_lce_size_para_calc(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7)
{
    u32 stack[94] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4c434 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4c578 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c5ac = ((u32)(unsigned long)ref_t32_data_d6c65 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c5c0 = ((u32)(unsigned long)ref_t32_data_d6c64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4c5c8 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[30];
    stack[34] = arg4;
    stack[35] = arg5;
    stack[36] = arg6;
    stack[37] = arg7;
L_4c430:
    sp = sp + -120;
    v0 = hi_4c434;
    v0 = v0 - hi_4c434 + ((u32)(unsigned long)ref_memset + (0));
    *(volatile u32 *)(unsigned long)(sp + (112)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (108)) = s6;
    s7 = a2;
    *(volatile u32 *)(unsigned long)(sp + (104)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (100)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (96)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (92)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s0;
    s1 = a1;
    a2 = 36;
    a1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (116)) = ra;
    s5 = a0;
    a0 = sp + 16;
    s6 = a3;
    s4 = *(volatile u32 *)(unsigned long)(sp + (136));
    s2 = *(volatile u32 *)(unsigned long)(sp + (140));
    s0 = *(volatile u32 *)(unsigned long)(sp + (144));
    s3 = *(volatile u32 *)(unsigned long)(sp + (148));
    *(volatile u32 *)(unsigned long)(sp + (64)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (68)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (72)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (56)) = 0;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (60)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4c4a8;
L_4c4a8:
    v0 = 18;
    a1 = s1 >> (0x1 & 31);
    if (v0) { lo = a1 / v0; hi = a1 % v0; } else { lo = ~0U; hi = a1; }
    a2 = (s7 >> 0x1) & ((1U << 0x5) - 1);
    t0 = s7 >> (0x5 & 31);
    t0 = t0 & 0xfe;
    *(volatile u8 *)(unsigned long)(s6 + (1)) = a2;
    *(volatile u8 *)(unsigned long)(s6 + (3)) = t0;
    t1 = hi;
    v1 = t1 & 0xff;
    a0 = v1 | a2;
    v0 = lo;
    v0 = v0 << (0x1 & 31);
    v0 = v0 & 0xff;
    *(volatile u8 *)(unsigned long)(s6 + (0)) = v1;
    *(volatile u8 *)(unsigned long)(s6 + (2)) = v0;
    branch = (a0 != 0); v1 = v0 * t0;
    if (branch) goto L_4c500;
    goto L_4c4f0;
L_4c4f0:
    a0 = v1;
    a3 = v1;
    a1 = v1; goto L_4c550;
L_4c500:
    branch = (t1 != 0); ;
    if (branch) goto L_4c524;
    goto L_4c508;
L_4c508:
    if (a2 == 0) { a1 = v0 + 2; goto L_4c540; }
    goto L_4c510;
L_4c510:
    a0 = t0 + 2;
    a0 = a0 * v0;
    a1 = v1;
    a3 = a0; goto L_4c550;
L_4c524:
    if (a2 != 0) { a1 = v0 + 2; goto L_4c540; }
    goto L_4c52c;
L_4c52c:
    a0 = v0 + 2;
    a0 = a0 * t0;
    a3 = v1;
    a1 = a0; goto L_4c550;
L_4c540:
    a3 = t0 + 2;
    a0 = a1 * a3;
    a1 = a1 * t0;
    a3 = v0 * a3;
L_4c550:
    *(volatile u32 *)(unsigned long)(s4 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(s4 + (4)) = a1;
    *(volatile u32 *)(unsigned long)(s4 + (8)) = a3;
    *(volatile u32 *)(unsigned long)(s4 + (12)) = v1;
    *(volatile u32 *)(unsigned long)(s2 + (4)) = a1;
    a1 = (u32)v1 < (u32)(8192);
    *(volatile u32 *)(unsigned long)(s2 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(s2 + (8)) = a3;
    *(volatile u32 *)(unsigned long)(s2 + (12)) = v1;
    branch = (a1 != 0); a0 = hi_4c578;
    if (branch) goto L_4c584;
    goto L_4c57c;
L_4c57c:
    v1 = 24; goto L_4c5a4;
L_4c584:
    a1 = (u32)v1 < (u32)(4096);
    if (a1 != 0) { v1 = (u32)v1 < (u32)(2048); goto L_4c598; }
    goto L_4c590;
L_4c590:
    v1 = 23; goto L_4c5a4;
L_4c598:
    if (v1 != 0) { v1 = 21; goto L_4c5a4; }
    goto L_4c5a0;
L_4c5a0:
    v1 = 22;
L_4c5a4:
    *(volatile u8 *)(unsigned long)(a0 - hi_4c578 + (u32)(unsigned long)ref_t32_data_d6c67) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a0 - hi_4c578 + (u32)(unsigned long)ref_t32_data_d6c67);
    a0 = hi_4c5ac;
    s5 = s5 << (0x2 & 31);
    a1 = v1 + -8;
    *(volatile u8 *)(unsigned long)(a0 - hi_4c5ac + (u32)(unsigned long)ref_t32_data_d6c65) = a1;
    v1 = v1 + -9;
    a0 = hi_4c5c0;
    *(volatile u8 *)(unsigned long)(a0 - hi_4c5c0 + (u32)(unsigned long)ref_t32_data_d6c64) = v1;
    v1 = hi_4c5c8;
    v1 = v1 - hi_4c5c8 + (u32)(unsigned long)ref_t32_data_e1da8;
    s5 = s5 + v1;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (0));
    v1 = 0x2U << 16;
    a1 = *(volatile u32 *)(unsigned long)(s4 + (0));
    a0 = a0 + v1;
    v1 = *(volatile u8 *)(unsigned long)(a0 + (10084));
    *(volatile u32 *)(unsigned long)(sp + (72)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (60)) = t0;
    a1 = v1 * a1;
    a1 = a1 + 32;
    a1 = a1 >> (0x6 & 31);
    *(volatile u8 *)(unsigned long)(a0 + (10133)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(s4 + (4));
    a1 = v1 * a1;
    a1 = a1 + 32;
    a1 = a1 >> (0x6 & 31);
    *(volatile u8 *)(unsigned long)(a0 + (10134)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(s4 + (8));
    a1 = v1 * a1;
    a1 = a1 + 32;
    a1 = a1 >> (0x6 & 31);
    *(volatile u8 *)(unsigned long)(a0 + (10135)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(s4 + (12));
    v1 = v1 * a1;
    v1 = v1 + 32;
    v1 = v1 >> (0x6 & 31);
    *(volatile u8 *)(unsigned long)(a0 + (10136)) = v1;
    a1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v1 = 0x200U << 16;
    a0 = a1 >> (0x1 & 31);
    a0 = a0 + v1;
    if (a1) { lo = a0 / a1; hi = a0 % a1; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s3 + (0)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(s2 + (4));
    a0 = a1 >> (0x1 & 31);
    a0 = a0 + v1;
    if (a1) { lo = a0 / a1; hi = a0 % a1; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s3 + (4)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(s2 + (8));
    a0 = a1 >> (0x1 & 31);
    a0 = a0 + v1;
    if (a1) { lo = a0 / a1; hi = a0 % a1; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s3 + (8)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(s2 + (12));
    a0 = a1 >> (0x1 & 31);
    v1 = a0 + v1;
    if (a1) { lo = v1 / a1; hi = v1 % a1; } else { lo = ~0U; hi = v1; }
    a1 = v0 + 1;
    if (t1 == 0) a1 = v0;
    *(volatile u32 *)(unsigned long)(sp + (68)) = a1;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s3 + (12)) = v1;
    v1 = v0 + 2;
    if (t1 == 0) v1 = v0;
    v0 = t0 + 2;
    if (a2 == 0) v0 = t0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = t0 + 1;
    if (a2 == 0) v0 = t0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v1 = 0;
    t0 = 12;
    v0 = sp + 64;
L_4c6dc:
    v0 = v0 + v1;
    a0 = v1 << (0x1 & 31);
    a3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a0 + v1;
    v0 = 0;
L_4c6f0:
    a1 = a0 + v0;
    a2 = sp + 16;
    a1 = a2 + a1;
    a2 = sp + 52;
    a2 = a2 + v0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 + 4;
    a2 = a2 * a3;
    branch = (v0 != t0); *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_4c6f0;
    goto L_4c718;
L_4c718:
    v1 = v1 + 4;
    branch = (v1 != v0); v0 = sp + 64;
    if (branch) goto L_4c6dc;
    goto L_4c724;
L_4c724:
    v0 = *(volatile u32 *)(unsigned long)(sp + (48));
    t2 = *(volatile u32 *)(unsigned long)(sp + (16));
    t1 = *(volatile u32 *)(unsigned long)(sp + (20));
    t3 = (u32)v0 < (u32)(16385);
    t0 = *(volatile u32 *)(unsigned long)(sp + (24));
    a3 = *(volatile u32 *)(unsigned long)(sp + (28));
    a2 = *(volatile u32 *)(unsigned long)(sp + (32));
    a1 = *(volatile u32 *)(unsigned long)(sp + (36));
    a0 = *(volatile u32 *)(unsigned long)(sp + (40));
    v1 = *(volatile u32 *)(unsigned long)(sp + (44));
    branch = (t3 != 0); s1 = v0 >> (0x1 & 31);
    if (branch) goto L_4c810;
    goto L_4c754;
L_4c754:
    t9 = 0x800U << 16;
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t9;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t9;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t9;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t9;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t9;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t9;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t9;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t9;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t9 = s1 + t9;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    v0 = 3;
    t9 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t9; goto L_4cd60;
L_4c810:
    t3 = (u32)v0 < (u32)(8193);
    branch = (t3 != 0); t3 = (u32)v0 < (u32)(4097);
    if (branch) goto L_4c8d8;
    goto L_4c81c;
L_4c81c:
    t8 = 0x400U << 16;
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t8;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t8;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t8;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t8;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t8;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t8;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t8;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t8;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t8 = s1 + t8;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t8 / v0; hi = t8 % v0; } else { lo = ~0U; hi = t8; }
    v0 = 4;
    t8 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t8; goto L_4cd60;
L_4c8d8:
    branch = (t3 != 0); t3 = (u32)v0 < (u32)(2049);
    if (branch) goto L_4c99c;
    goto L_4c8e0;
L_4c8e0:
    t7 = 0x200U << 16;
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t7;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t7;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t7;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t7;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t7;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t7;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t7;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t7;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t7 = s1 + t7;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t7 / v0; hi = t7 % v0; } else { lo = ~0U; hi = t7; }
    v0 = 5;
    t7 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t7; goto L_4cd60;
L_4c99c:
    branch = (t3 != 0); t3 = (u32)v0 < (u32)(1025);
    if (branch) goto L_4ca60;
    goto L_4c9a4;
L_4c9a4:
    t6 = 0x100U << 16;
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t6;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t6;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t6;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t6;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t6;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t6;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t6;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t6;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t6 = s1 + t6;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t6 / v0; hi = t6 % v0; } else { lo = ~0U; hi = t6; }
    v0 = 6;
    t6 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t6; goto L_4cd60;
L_4ca60:
    branch = (t3 != 0); t3 = (u32)v0 < (u32)(513);
    if (branch) goto L_4cb24;
    goto L_4ca68;
L_4ca68:
    t5 = 0x80U << 16;
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t5;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t5;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t5;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t5;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t5;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t5;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t5;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t5;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t5 = s1 + t5;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t5 / v0; hi = t5 % v0; } else { lo = ~0U; hi = t5; }
    v0 = 7;
    t5 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t5; goto L_4cd60;
L_4cb24:
    branch = (t3 != 0); t3 = (u32)v0 < (u32)(257);
    if (branch) goto L_4cbe8;
    goto L_4cb2c;
L_4cb2c:
    t4 = 0x40U << 16;
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t4;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t4;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t4;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t4;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t4;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t4;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t4;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t4;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t4 = s1 + t4;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t4 / v0; hi = t4 % v0; } else { lo = ~0U; hi = t4; }
    v0 = 8;
    t4 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t4; goto L_4cd60;
L_4cbe8:
    branch = (t3 != 0); t9 = 0x10U << 16;
    if (branch) goto L_4ccac;
    goto L_4cbf0;
L_4cbf0:
    t3 = 0x20U << 16;
    t4 = t2 >> (0x1 & 31);
    t4 = t4 + t3;
    if (t2) { lo = t4 / t2; hi = t4 % t2; } else { lo = ~0U; hi = t4; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t3;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t3;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t3;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t3;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t3;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t3;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t3;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t3 = s1 + t3;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t3 / v0; hi = t3 % v0; } else { lo = ~0U; hi = t3; }
    v0 = 9;
    t3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t3; goto L_4cd60;
L_4ccac:
    t3 = t2 >> (0x1 & 31);
    t3 = t3 + t9;
    if (t2) { lo = t3 / t2; hi = t3 % t2; } else { lo = ~0U; hi = t3; }
    t2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    t2 = t1 >> (0x1 & 31);
    t2 = t2 + t9;
    if (t1) { lo = t2 / t1; hi = t2 % t1; } else { lo = ~0U; hi = t2; }
    t1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    t1 = t0 >> (0x1 & 31);
    t1 = t1 + t9;
    if (t0) { lo = t1 / t0; hi = t1 % t0; } else { lo = ~0U; hi = t1; }
    t0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = t0;
    t0 = a3 >> (0x1 & 31);
    t0 = t0 + t9;
    if (a3) { lo = t0 / a3; hi = t0 % a3; } else { lo = ~0U; hi = t0; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = a3;
    a3 = a2 >> (0x1 & 31);
    a3 = a3 + t9;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (16)) = a2;
    a2 = a1 >> (0x1 & 31);
    a2 = a2 + t9;
    if (a1) { lo = a2 / a1; hi = a2 % a1; } else { lo = ~0U; hi = a2; }
    a1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (20)) = a1;
    a1 = a0 >> (0x1 & 31);
    a1 = a1 + t9;
    if (a0) { lo = a1 / a0; hi = a1 % a0; } else { lo = ~0U; hi = a1; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = a0;
    a0 = v1 >> (0x1 & 31);
    a0 = a0 + t9;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    t9 = s1 + t9;
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (28)) = v1;
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    v0 = 10;
    t9 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = t9;
L_4cd60:
    *(volatile u32 *)(unsigned long)(s0 + (36)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (116));
    s7 = *(volatile u32 *)(unsigned long)(sp + (112));
    s6 = *(volatile u32 *)(unsigned long)(sp + (108));
    s5 = *(volatile u32 *)(unsigned long)(sp + (104));
    s4 = *(volatile u32 *)(unsigned long)(sp + (100));
    s3 = *(volatile u32 *)(unsigned long)(sp + (96));
    s2 = *(volatile u32 *)(unsigned long)(sp + (92));
    s1 = *(volatile u32 *)(unsigned long)(sp + (88));
    s0 = *(volatile u32 *)(unsigned long)(sp + (84));
    sp = sp + 120;
    return ((u64)v1 << 32) | v0;
}
