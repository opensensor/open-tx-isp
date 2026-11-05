/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_private_dma_cache_sync[] __asm__("private_dma_cache_sync");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_tmo_tmo_stat_limit(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9c60c = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9c660 = ((u32)(unsigned long)ref_private_dma_cache_sync + 0x8000U) & 0xffff0000U;
    const u32 hi_9c804 = ((u32)(unsigned long)ref_private_dma_cache_sync + 0x8000U) & 0xffff0000U;
    const u32 hi_9c8f8 = ((u32)(unsigned long)ref_private_dma_cache_sync + 0x8000U) & 0xffff0000U;
    const u32 hi_9ca50 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_9c8f4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_9c604:
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    s2 = hi_9c60c;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    s2 = s2 - hi_9c60c + (u32)(unsigned long)ref_t32_data_e35e0;
    s3 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = s3 + s2;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v1 + (20));
    s6 = *(volatile u8 *)(unsigned long)(v1 + (53));
    s5 = *(volatile u16 *)(unsigned long)(v0 + (3366));
    s1 = *(volatile u16 *)(unsigned long)(v0 + (3368));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (3382));
    v1 = 1;
    branch = (v0 != v1); v1 = 2;
    if (branch) goto L_9c7fc;
    goto L_9c660;
L_9c660:
    v0 = hi_9c660;
    a3 = 0;
    a2 = 7520;
    a1 = s0;
    v0 = v0 - hi_9c660 + (u32)(unsigned long)ref_private_dma_cache_sync;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c67c;
L_9c67c:
    v0 = s0 + 18;
    t5 = s0 + 7518;
    a0 = 410;
    a1 = 819;
    a2 = 1229;
    a3 = 1638;
    t0 = 2048;
    t1 = 2457;
    t2 = 2867;
    t3 = 3276;
    t4 = 3686;
    t6 = 4095;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-18));
L_9c6b0:
    v1 = (u32)v1 < (u32)(411);
    if (v1 == 0) { *(volatile u16 *)(unsigned long)(v0 + (-18)) = a0; goto L_9c6bc; }
    goto L_9c6bc;
L_9c6bc:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-16));
    t7 = (u32)v1 < (u32)(820);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(410);
    if (branch) goto L_9c6d4;
    goto L_9c6cc;
L_9c6cc:
    *(volatile u16 *)(unsigned long)(v0 + (-16)) = a1; goto L_9c6dc;
L_9c6d4:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-16)) = a0; goto L_9c6dc; }
    goto L_9c6dc;
L_9c6dc:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-14));
    t7 = (u32)v1 < (u32)(1230);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(819);
    if (branch) goto L_9c6f4;
    goto L_9c6ec;
L_9c6ec:
    *(volatile u16 *)(unsigned long)(v0 + (-14)) = a2; goto L_9c6fc;
L_9c6f4:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-14)) = a1; goto L_9c6fc; }
    goto L_9c6fc;
L_9c6fc:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-12));
    t7 = (u32)v1 < (u32)(1639);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(1229);
    if (branch) goto L_9c714;
    goto L_9c70c;
L_9c70c:
    *(volatile u16 *)(unsigned long)(v0 + (-12)) = a3; goto L_9c71c;
L_9c714:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-12)) = a2; goto L_9c71c; }
    goto L_9c71c;
L_9c71c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-10));
    t7 = (u32)v1 < (u32)(2049);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(1638);
    if (branch) goto L_9c734;
    goto L_9c72c;
L_9c72c:
    *(volatile u16 *)(unsigned long)(v0 + (-10)) = t0; goto L_9c73c;
L_9c734:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-10)) = a3; goto L_9c73c; }
    goto L_9c73c;
L_9c73c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-8));
    t7 = (u32)v1 < (u32)(2458);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(2048);
    if (branch) goto L_9c754;
    goto L_9c74c;
L_9c74c:
    *(volatile u16 *)(unsigned long)(v0 + (-8)) = t1; goto L_9c75c;
L_9c754:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-8)) = t0; goto L_9c75c; }
    goto L_9c75c;
L_9c75c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-6));
    t7 = (u32)v1 < (u32)(2868);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(2457);
    if (branch) goto L_9c774;
    goto L_9c76c;
L_9c76c:
    *(volatile u16 *)(unsigned long)(v0 + (-6)) = t2; goto L_9c77c;
L_9c774:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-6)) = t1; goto L_9c77c; }
    goto L_9c77c;
L_9c77c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-4));
    t7 = (u32)v1 < (u32)(3277);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(2867);
    if (branch) goto L_9c794;
    goto L_9c78c;
L_9c78c:
    *(volatile u16 *)(unsigned long)(v0 + (-4)) = t3; goto L_9c79c;
L_9c794:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-4)) = t2; goto L_9c79c; }
    goto L_9c79c;
L_9c79c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (-2));
    t7 = (u32)v1 < (u32)(3687);
    branch = (t7 != 0); v1 = (u32)v1 < (u32)(3276);
    if (branch) goto L_9c7b4;
    goto L_9c7ac;
L_9c7ac:
    *(volatile u16 *)(unsigned long)(v0 + (-2)) = t4; goto L_9c7bc;
L_9c7b4:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (-2)) = t3; goto L_9c7bc; }
    goto L_9c7bc;
L_9c7bc:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t7 = (u32)v1 < (u32)(4096);
    if (t7 != 0) { v1 = (u32)v1 < (u32)(3686); goto L_9c7d4; }
    goto L_9c7cc;
L_9c7cc:
    *(volatile u16 *)(unsigned long)(v0 + (0)) = t6; goto L_9c7dc;
L_9c7d4:
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (0)) = t4; goto L_9c7dc; }
    goto L_9c7dc;
L_9c7dc:
    v0 = v0 + 20;
    if (v0 != t5) { v1 = *(volatile u16 *)(unsigned long)(v0 + (-18)); goto L_9c6b0; }
    goto L_9c7e8;
L_9c7e8:
    v0 = 1;
L_9c7ec:
    branch = (s5 != v0); s4 = s0 + 7520;
    if (branch) goto L_9ca50;
    goto L_9c7f4;
L_9c7f4:
    ; goto L_9c8f0;
L_9c7fc:
    branch = (v0 != v1); v0 = 1;
    if (branch) goto L_9c7ec;
    goto L_9c804;
L_9c804:
    v0 = hi_9c804;
    a3 = 0;
    a2 = 7520;
    a1 = s0;
    v0 = v0 - hi_9c804 + (u32)(unsigned long)ref_private_dma_cache_sync;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c820;
L_9c820:
    v0 = s0 + 2;
    a0 = s0 + 7502;
    a1 = 410;
    a2 = 819;
    a3 = 1229;
    t0 = 1638;
    t1 = 2048;
    t2 = 2457;
    t3 = 2867;
    t4 = 3276;
    t5 = 3686;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
L_9c850:
    v1 = (u32)v1 < (u32)(410);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (0)) = a1; goto L_9c85c; }
    goto L_9c85c;
L_9c85c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (2));
    v1 = (u32)v1 < (u32)(819);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (2)) = a2; goto L_9c86c; }
    goto L_9c86c;
L_9c86c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (4));
    v1 = (u32)v1 < (u32)(1229);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (4)) = a3; goto L_9c87c; }
    goto L_9c87c;
L_9c87c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (6));
    v1 = (u32)v1 < (u32)(1638);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (6)) = t0; goto L_9c88c; }
    goto L_9c88c;
L_9c88c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (8));
    v1 = (u32)v1 < (u32)(2048);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (8)) = t1; goto L_9c89c; }
    goto L_9c89c;
L_9c89c:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (10));
    v1 = (u32)v1 < (u32)(2457);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (10)) = t2; goto L_9c8ac; }
    goto L_9c8ac;
L_9c8ac:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (12));
    v1 = (u32)v1 < (u32)(2867);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (12)) = t3; goto L_9c8bc; }
    goto L_9c8bc;
L_9c8bc:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (14));
    v1 = (u32)v1 < (u32)(3276);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (14)) = t4; goto L_9c8cc; }
    goto L_9c8cc;
L_9c8cc:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (16));
    v1 = (u32)v1 < (u32)(3686);
    if (v1 != 0) { *(volatile u16 *)(unsigned long)(v0 + (16)) = t5; goto L_9c8dc; }
    goto L_9c8dc;
L_9c8dc:
    v0 = v0 + 20;
    if (v0 != a0) { v1 = *(volatile u16 *)(unsigned long)(v0 + (0)); goto L_9c850; }
    goto L_9c8e8;
L_9c8e8:
    v0 = 1; goto L_9c7ec;
L_9c8f0:
    branch = (s6 != s5); v0 = hi_9c8f4;
    if (branch) goto L_9ca54;
    goto L_9c8f8;
L_9c8f8:
    v0 = hi_9c8f8;
    a3 = 0;
    a0 = 0;
    v0 = v0 - hi_9c8f8 + (u32)(unsigned long)ref_private_dma_cache_sync;
    a2 = 7520;
    callee = v0; a1 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9c914;
L_9c914:
    v1 = 16;
    v1 = v1 - s1;
    a0 = s4;
    v0 = s0 + 2;
    a3 = s0 + 15020;
    v1 = v1 & 0xff;
L_9c92c:
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-2));
    a0 = a0 + 20;
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    v0 = v0 + 20;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-20));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-22)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-18));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-18));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-20)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-16));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-16));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-18)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-14));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-14));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-16)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-12));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-12));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-14)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-10));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-10));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-12)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-8));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-8));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-10)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-6));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-6));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-8)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-4));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (-4));
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v0 + (-6)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (-2));
    product = (s64)(s32)a1 * (s32)s1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)v1); lo = product; hi = product >> 32;
    a1 = lo;
    a1 = (s32)a1 >> (0x4 & 31);
    branch = (a3 != a0); *(volatile u16 *)(unsigned long)(v0 + (-4)) = a1;
    if (branch) goto L_9c92c;
    goto L_9ca50;
L_9ca50:
    v0 = hi_9ca50;
L_9ca54:
    s2 = s2 + s3;
    a1 = s0;
    a0 = s4;
    v0 = v0 - hi_9ca50 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a2 = 7520;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9ca6c;
L_9ca6c:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (53)) = v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
