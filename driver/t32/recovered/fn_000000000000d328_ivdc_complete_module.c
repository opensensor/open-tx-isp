/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_be40c[] __asm__("t32_data_be40c");
extern unsigned char ref_t32_data_c52d8[] __asm__("t32_data_c52d8");
extern unsigned char ref_t32_data_d98b0[] __asm__("t32_data_d98b0");
extern unsigned char ref_t32_data_c52fc[] __asm__("t32_data_c52fc");
extern unsigned char ref_t32_data_c5324[] __asm__("t32_data_c5324");
extern unsigned char ref_t32_data_c5358[] __asm__("t32_data_c5358");
u64 ivdc_complete_module(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_d358 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_d364 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_d368 = ((u32)(unsigned long)ref_t32_data_be40c + 0x8000U) & 0xffff0000U;
    const u32 hi_d380 = ((u32)(unsigned long)ref_t32_data_c52d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_d37c = ((u32)(unsigned long)ref_t32_data_d98b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_d39c = ((u32)(unsigned long)ref_t32_data_c52fc + 0x8000U) & 0xffff0000U;
    const u32 hi_d3cc = ((u32)(unsigned long)ref_t32_data_c5324 + 0x8000U) & 0xffff0000U;
    const u32 hi_d4b4 = ((u32)(unsigned long)ref_t32_data_c5324 + 0x8000U) & 0xffff0000U;
    const u32 hi_d5a0 = ((u32)(unsigned long)ref_t32_data_c5324 + 0x8000U) & 0xffff0000U;
    const u32 hi_d68c = ((u32)(unsigned long)ref_t32_data_c5324 + 0x8000U) & 0xffff0000U;
    const u32 hi_d754 = ((u32)(unsigned long)ref_t32_data_c5358 + 0x8000U) & 0xffff0000U;
    const u32 hi_d674 = ((u32)(unsigned long)ref_t32_data_c5358 + 0x8000U) & 0xffff0000U;
    const u32 hi_d724 = ((u32)(unsigned long)ref_t32_data_c5358 + 0x8000U) & 0xffff0000U;
    const u32 hi_d73c = ((u32)(unsigned long)ref_t32_data_c5358 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
L_d344:
    branch = (a0 == 0); s0 = 0;
    if (branch) goto L_d358;
    goto L_d34c;
L_d34c:
    v0 = (u32)a0 < (u32)(-4095);
    if (v0 != 0) { s0 = *(volatile u32 *)(unsigned long)(a0 + (280)); goto L_d358; }
    goto L_d358;
L_d358:
    s4 = hi_d358;
    v1 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (v1 == 0); s3 = hi_d364;
    if (branch) goto L_d78c;
    goto L_d368;
L_d368:
    s2 = hi_d368;
    branch = (s0 == 0); s3 = s3 - hi_d364 + (u32)(unsigned long)ref_isp_printf;
    if (branch) goto L_d380;
    goto L_d374;
L_d374:
    v0 = (u32)s0 < (u32)(-4095);
    branch = (v0 != 0); s1 = hi_d37c;
    if (branch) goto L_d394;
    goto L_d380;
L_d380:
    a1 = hi_d380;
    a3 = 748;
    a2 = s2 - hi_d368 + (u32)(unsigned long)ref_t32_data_be40c;
    a1 = a1 - hi_d380 + (u32)(unsigned long)ref_t32_data_c52d8; goto L_d3ac;
L_d394:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
    branch = (v0 != 0); a1 = hi_d39c;
    if (branch) goto L_d3b4;
    goto L_d3a0;
L_d3a0:
    a3 = 752;
    a2 = s2 - hi_d368 + (u32)(unsigned long)ref_t32_data_be40c;
    a1 = a1 - hi_d39c + (u32)(unsigned long)ref_t32_data_c52fc;
L_d3ac:
    a0 = 2; goto L_d768;
L_d3b4:
    if ((s32)v1 <= 0) { v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014); goto L_d498; }
    goto L_d3bc;
L_d3bc:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (24));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (28));
L_d3c4:
    a1 = a0 | v1;
    branch = (a1 == 0); a1 = hi_d3cc;
    if (branch) goto L_d428;
    goto L_d3d0;
L_d3d0:
    branch = (a0 == 0); ;
    if (branch) goto L_d3f8;
    goto L_d3d8;
L_d3d8:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (24)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (192));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (192)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = 36;
    *(volatile u32 *)(unsigned long)(a0 + (8)) = a1;
L_d3f8:
    if (v1 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d444; }
    goto L_d400;
L_d400:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (28)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (196));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (196)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = 40;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d444;
L_d428:
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    a3 = 0;
    a2 = 773;
    a1 = a1 - hi_d3cc + (u32)(unsigned long)ref_t32_data_c5324;
    callee = s3; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_d440;
L_d440:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
L_d444:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (128));
    a0 = (v0 >> 0x10) & ((1U << 0x1) - 1);
    v1 = v0 & 0x7;
    v0 = v0 >> (0x4 & 31);
    branch = (a0 == 0); v0 = v0 & 0x7;
    if (branch) goto L_d470;
    goto L_d45c;
L_d45c:
    v1 = v1 + 7;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d498;
    goto L_d468;
L_d468:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_d484;
L_d470:
    v0 = v1 - v0;
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d498;
    goto L_d480;
L_d480:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
L_d484:
    v0 = 0x100U << 16;
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
L_d498:
    v0 = (s32)v0 < (s32)(2);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
    if (branch) goto L_d57c;
    goto L_d4a4;
L_d4a4:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1544));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1548));
    a1 = a0 | v1;
    branch = (a1 == 0); a1 = hi_d4b4;
    if (branch) goto L_d510;
    goto L_d4b8;
L_d4b8:
    branch = (a0 == 0); ;
    if (branch) goto L_d4e0;
    goto L_d4c0;
L_d4c0:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (1544)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (1572));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1572)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = 36;
    *(volatile u32 *)(unsigned long)(a0 + (8)) = a1;
L_d4e0:
    if (v1 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d52c; }
    goto L_d4e8;
L_d4e8:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1548)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1576));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (1576)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = 40;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d52c;
L_d510:
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    a3 = 0;
    a2 = 809;
    a1 = a1 - hi_d4b4 + (u32)(unsigned long)ref_t32_data_c5324;
    callee = s3; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_d528;
L_d528:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
L_d52c:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (128));
    a0 = (v0 >> 0x10) & ((1U << 0x1) - 1);
    v1 = v0 & 0x7;
    v0 = v0 >> (0x4 & 31);
    branch = (a0 == 0); v0 = v0 & 0x7;
    if (branch) goto L_d558;
    goto L_d544;
L_d544:
    v1 = v1 + 7;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d580;
    goto L_d550;
L_d550:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_d56c;
L_d558:
    v0 = v1 - v0;
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d580;
    goto L_d568;
L_d568:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
L_d56c:
    v0 = 0x100U << 16;
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
L_d57c:
    v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
L_d580:
    v0 = (s32)v0 < (s32)(3);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d66c;
    goto L_d58c;
L_d58c:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1608));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1612));
    a1 = a0 | v1;
    branch = (a1 == 0); a1 = hi_d5a0;
    if (branch) goto L_d5fc;
    goto L_d5a4;
L_d5a4:
    branch = (a0 == 0); ;
    if (branch) goto L_d5cc;
    goto L_d5ac;
L_d5ac:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (1608)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (1636));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1636)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = 36;
    *(volatile u32 *)(unsigned long)(a0 + (8)) = a1;
L_d5cc:
    if (v1 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d618; }
    goto L_d5d4;
L_d5d4:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1612)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1640));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (1640)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = 40;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d618;
L_d5fc:
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    a3 = 0;
    a2 = 845;
    a1 = a1 - hi_d5a0 + (u32)(unsigned long)ref_t32_data_c5324;
    callee = s3; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_d614;
L_d610:
    a0 = 2;
L_d614:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
L_d618:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (128));
    a0 = (v0 >> 0x10) & ((1U << 0x1) - 1);
    v1 = v0 & 0x7;
L_d624:
    v0 = v0 >> (0x4 & 31);
    branch = (a0 == 0); v0 = v0 & 0x7;
    if (branch) goto L_d644;
    goto L_d630;
L_d630:
    v1 = v1 + 7;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d66c;
    goto L_d63c;
L_d638:
    v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
L_d63c:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_d658;
L_d644:
    v0 = v1 - v0;
    v0 = (u32)v0 < (u32)(2);
L_d64c:
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_d66c;
    goto L_d654;
L_d654:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
L_d658:
    v0 = 0x100U << 16;
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s4 - hi_d358 + (u32)(unsigned long)ref_t32_data_d9014);
L_d66c:
    v0 = (s32)v0 < (s32)(4);
    branch = (v0 != 0); a1 = hi_d674;
    if (branch) goto L_d758;
    goto L_d678;
L_d678:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1672));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1676));
    a1 = a0 | v1;
    branch = (a1 == 0); a1 = hi_d68c;
    if (branch) goto L_d6e8;
    goto L_d690;
L_d690:
    branch = (a0 == 0); ;
    if (branch) goto L_d6b8;
    goto L_d698;
L_d698:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (1672)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (1700));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1700)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = 36;
    *(volatile u32 *)(unsigned long)(a0 + (8)) = a1;
L_d6b8:
    if (v1 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d704; }
    goto L_d6c0;
L_d6c0:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1676)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1704));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (1704)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = 40;
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0); goto L_d704;
L_d6e8:
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    a3 = 0;
    a2 = 881;
    a1 = a1 - hi_d68c + (u32)(unsigned long)ref_t32_data_c5324;
    callee = s3; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_d700;
L_d700:
    v0 = *(volatile u32 *)(unsigned long)(s1 - hi_d37c + (u32)(unsigned long)ref_t32_data_d98b0);
L_d704:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (128));
    a0 = (v0 >> 0x10) & ((1U << 0x1) - 1);
    v1 = v0 & 0x7;
    v0 = v0 >> (0x4 & 31);
    branch = (a0 == 0); v0 = v0 & 0x7;
    if (branch) goto L_d730;
    goto L_d71c;
L_d71c:
    v1 = v1 + 7;
    branch = (v1 != v0); a1 = hi_d724;
    if (branch) goto L_d758;
    goto L_d728;
L_d728:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_d744;
L_d730:
    v0 = v1 - v0;
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); a1 = hi_d73c;
    if (branch) goto L_d758;
    goto L_d740;
L_d740:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
L_d744:
    v0 = 0x100U << 16;
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v1 + (120)) = v0;
    a1 = hi_d754;
L_d758:
    a3 = 899;
    a2 = s2 - hi_d368 + (u32)(unsigned long)ref_t32_data_be40c;
    a1 = a1 - hi_d754 + (u32)(unsigned long)ref_t32_data_c5358;
    a0 = 0;
L_d768:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s4 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    t9 = s3;
    s3 = *(volatile u32 *)(unsigned long)(sp + (36));
    callee = t9; sp = sp + 48;
    switch (callee) { case 0xd344: goto L_d344; case 0xd3a0: goto L_d3a0; case 0xd3c4: goto L_d3c4; case 0xd610: goto L_d610; case 0xd624: goto L_d624; case 0xd638: goto L_d638; case 0xd64c: goto L_d64c; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_d78c:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s4 = *(volatile u32 *)(unsigned long)(sp + (40));
    s3 = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
