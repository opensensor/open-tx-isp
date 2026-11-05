/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_bf9ec[] __asm__("t32_data_bf9ec");
extern unsigned char ref_t32_data_d6be4[] __asm__("t32_data_d6be4");
extern unsigned char ref_t32_data_d6b64[] __asm__("t32_data_d6b64");
u64 tisp_lce_hist_method(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[132] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4d3f0 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4d4b4 = ((u32)(unsigned long)ref_t32_data_bf9ec + 0x8000U) & 0xffff0000U;
    const u32 hi_4d57c = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d5dc = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d640 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d6a4 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d71c = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d77c = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[68];
L_4d3d0:
    sp = sp + -272;
    *(volatile u32 *)(unsigned long)(sp + (268)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (264)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (260)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (256)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (252)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (248)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (244)) = s0;
    s3 = hi_4d3f0;
    s5 = a0;
    s3 = s3 - hi_4d3f0 + ((u32)(unsigned long)ref_memset + (0));
    s2 = *(volatile u8 *)(unsigned long)(a2 + (0));
    s0 = *(volatile u8 *)(unsigned long)(a2 + (1));
    s1 = *(volatile u8 *)(unsigned long)(a2 + (2));
    a0 = sp + 144;
    a2 = 64;
    s4 = a1;
    callee = s3; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4d41c;
L_4d41c:
    a2 = 128;
    a1 = 0;
    callee = s3; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4d42c;
L_4d42c:
    a0 = sp + 208;
    a2 = 32;
    callee = s3; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4d43c;
L_4d43c:
    a0 = s5;
    a3 = s5 + 64;
    v1 = s5;
    v0 = 0;
    a1 = *(volatile u8 *)(unsigned long)(s4 + (0));
L_4d450:
    a2 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t0 = a1 & 0xffff;
    t1 = (u32)t0 < (u32)(a2);
    if (t1 == 0) { v1 = v1 + 2; goto L_4d478; }
    goto L_4d464;
L_4d464:
    v0 = v0 - t0;
    v0 = v0 + a2;
    v0 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(v1 + (0)) = a1;
    v1 = v1 + 2;
L_4d478:
    if (v1 != a3) { a1 = *(volatile u8 *)(unsigned long)(s4 + (0)); goto L_4d450; }
    goto L_4d480;
L_4d480:
    v1 = s0 - s2;
    v1 = (s32)v1 < (s32)(3);
    if (v1 == 0) { v1 = v0 + 2; goto L_4d4a4; }
    goto L_4d490;
L_4d490:
    t0 = v0 + 1;
    t0 = (t0 >> 0x1) & ((1U << 0x10) - 1);
    v1 = 0;
    t2 = 1; goto L_4d4b0;
L_4d4a4:
    v1 = (v1 >> 0x2) & ((1U << 0x10) - 1);
    t0 = 0;
    t2 = 0;
L_4d4b0:
    a2 = s1 - s0;
    a1 = hi_4d4b4;
    a2 = (s32)a2 < (s32)(3);
    branch = (a2 == 0); a1 = a1 - hi_4d4b4 + (u32)(unsigned long)ref_t32_data_bf9ec;
    if (branch) goto L_4d4fc;
    goto L_4d4c4;
L_4d4c4:
    if (t2 == 0) { v0 = v0 - v1; goto L_4d4e4; }
    goto L_4d4cc;
L_4d4cc:
    v0 = v0 - t0;
    v0 = v0 & 0xffff;
    t1 = 0;
    a2 = 0;
    t4 = 1; goto L_4d550;
L_4d4e4:
    v0 = v0 - v1;
    v0 = v0 & 0xffff;
    t1 = 0;
    a2 = 0;
    t4 = 1; goto L_4d538;
L_4d4fc:
    a2 = v0 + 2;
    branch = (t2 == 0); a2 = (a2 >> 0x2) & ((1U << 0x10) - 1);
    if (branch) goto L_4d520;
    goto L_4d508;
L_4d508:
    v0 = v0 - t0;
    v0 = v0 - a2;
    t1 = v0 & 0xffff;
    t4 = 0;
    v0 = 0; goto L_4d550;
L_4d520:
    v0 = v0 - v1;
    v0 = v0 - v1;
    v0 = v0 - a2;
    t1 = v0 & 0xffff;
    t4 = 0;
    v0 = 0;
L_4d538:
    if (s1 == 0) { s1 = 1; goto L_4d5b4; }
    goto L_4d540;
L_4d540:
    if (t2 == 0) { t0 = s2 + -1; goto L_4d5c0; }
    goto L_4d548;
L_4d548:
    v1 = s0 + -1; goto L_4d564;
L_4d550:
    branch = (s1 != 0); ;
    if (branch) goto L_4d540;
    goto L_4d558;
L_4d558:
    s1 = 1;
    s0 = 1;
    v1 = s0 + -1;
L_4d564:
    v1 = v1 << (0x1 & 31);
    v1 = a1 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = sp + 16;
    t2 = 0;
    t0 = v1 * t0;
    v1 = hi_4d57c;
    v1 = v1 - hi_4d57c + (u32)(unsigned long)ref_t32_data_d6be4;
L_4d584:
    t3 = t2 & 0xff;
    t3 = (u32)t3 < (u32)(s0);
    branch = (t3 == 0); t3 = sp + 208;
    if (branch) goto L_4d688;
    goto L_4d594;
L_4d594:
    t6 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t3 = t3 + t2;
    *(volatile u32 *)(unsigned long)(t5 + (0)) = t0;
    *(volatile u8 *)(unsigned long)(t3 + (0)) = t6;
    t2 = t2 + 1;
    t5 = t5 + 4;
    v1 = v1 + 4; goto L_4d584;
L_4d5b4:
    s0 = 1;
    s2 = 1;
    t0 = s2 + -1;
L_4d5c0:
    t0 = t0 << (0x1 & 31);
    t0 = a1 + t0;
    t7 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t0 = 32;
    t0 = t0 - s2;
    t7 = t7 * v1;
    t0 = t0 & 0xff;
    t8 = hi_4d5dc;
    t5 = s2;
    t6 = sp + 16;
    t0 = t0 << (0x2 & 31);
    t2 = 0;
    t8 = t8 - hi_4d5dc + (u32)(unsigned long)ref_t32_data_d6b64;
L_4d5f4:
    t3 = t2 & 0xff;
    t3 = (u32)t3 < (u32)(s2);
    branch = (t3 == 0); t3 = sp + 208;
    if (branch) goto L_4d62c;
    goto L_4d604;
L_4d604:
    t9 = t3 + t2;
    t3 = t2 << (0x2 & 31);
    t3 = t3 + t0;
    t3 = t8 + t3;
    t3 = *(volatile u32 *)(unsigned long)(t3 + (0));
    *(volatile u32 *)(unsigned long)(t6 + (0)) = t7;
    t2 = t2 + 1;
    *(volatile u8 *)(unsigned long)(t9 + (0)) = t3;
    t6 = t6 + 4; goto L_4d5f4;
L_4d62c:
    t0 = s0 - s2;
    t0 = t0 + -1;
    t0 = t0 << (0x1 & 31);
    t0 = a1 + t0;
    t0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t2 = hi_4d640;
    t2 = t2 - hi_4d640 + (u32)(unsigned long)ref_t32_data_d6be4;
    v1 = t0 * v1;
L_4d64c:
    t0 = (u32)s2 < (u32)(s0);
    branch = (t0 == 0); t0 = s2 << (0x2 & 31);
    if (branch) goto L_4d688;
    goto L_4d658;
L_4d658:
    t3 = sp + 16;
    t0 = t3 + t0;
    *(volatile u32 *)(unsigned long)(t0 + (0)) = v1;
    t0 = s2 - t5;
    t0 = t0 << (0x2 & 31);
    t0 = t0 + t2;
    t0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t3 = t3 + s2;
    s2 = s2 + 1;
    *(volatile u8 *)(unsigned long)(t3 + (192)) = t0;
    s2 = s2 & 0xff; goto L_4d64c;
L_4d688:
    branch = (t4 == 0); v1 = s1 - s0;
    if (branch) goto L_4d700;
    goto L_4d690;
L_4d690:
    v1 = 31;
    v1 = v1 - s0;
    v1 = v1 << (0x1 & 31);
    a1 = a1 + v1;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a1 = hi_4d6a4;
    a1 = a1 - hi_4d6a4 + (u32)(unsigned long)ref_t32_data_d6b64;
    v0 = v1 * v0;
L_4d6b0:
    v1 = (u32)s0 < (u32)(32);
    branch = (v1 == 0); v1 = s0 << (0x2 & 31);
    if (branch) goto L_4d6e8;
    goto L_4d6bc;
L_4d6bc:
    a2 = sp + 16;
    a2 = a2 + v1;
    v1 = v1 + a1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a2 + (0)) = v0;
    a2 = sp + 16;
    a2 = a2 + s0;
    s0 = s0 + 1;
    *(volatile u8 *)(unsigned long)(a2 + (192)) = v1;
    s0 = s0 & 0xff; goto L_4d6b0;
L_4d6e8:
    v0 = sp + 144;
    t0 = sp + 16;
    a2 = v0;
    a1 = 0;
    t2 = 32; goto L_4d7c4;
L_4d700:
    v1 = v1 + -1;
    v1 = v1 << (0x1 & 31);
    v1 = a1 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v0 = 32;
    v0 = v0 - s1;
    a2 = v1 * a2;
    t2 = hi_4d71c;
    v0 = v0 & 0xff;
    t0 = s1;
    t2 = t2 - hi_4d71c + (u32)(unsigned long)ref_t32_data_d6b64;
L_4d72c:
    v1 = (u32)s0 < (u32)(s1);
    branch = (v1 == 0); v1 = s0 << (0x2 & 31);
    if (branch) goto L_4d768;
    goto L_4d738;
L_4d738:
    t3 = sp + 16;
    v1 = t3 + v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a2;
    v1 = v0 + s0;
    v1 = v1 << (0x2 & 31);
    v1 = v1 + t2;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t3 = t3 + s0;
    s0 = s0 + 1;
    *(volatile u8 *)(unsigned long)(t3 + (192)) = v1;
    s0 = s0 & 0xff; goto L_4d72c;
L_4d768:
    v1 = 31;
    v1 = v1 - s1;
    v1 = v1 << (0x1 & 31);
    a1 = a1 + v1;
    v0 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a1 = hi_4d77c;
    a1 = a1 - hi_4d77c + (u32)(unsigned long)ref_t32_data_d6be4;
    v0 = v0 * t1;
L_4d788:
    v1 = (u32)s1 < (u32)(32);
    branch = (v1 == 0); v1 = s1 << (0x2 & 31);
    if (branch) goto L_4d6e8;
    goto L_4d794;
L_4d794:
    a2 = sp + 16;
    v1 = a2 + v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    v1 = s1 - t0;
    v1 = v1 << (0x2 & 31);
    v1 = v1 + a1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = a2 + s1;
    s1 = s1 + 1;
    *(volatile u8 *)(unsigned long)(a2 + (192)) = v1;
    s1 = s1 & 0xff; goto L_4d788;
L_4d7c4:
    v1 = sp + 208;
    v1 = v1 + a1;
    t1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    a1 = a1 + 1;
    t0 = t0 + 4;
    v1 = v1 * t1;
    a2 = a2 + 2;
    t1 = (v1 >> 0xe) & ((1U << 0x1) - 1);
    v1 = v1 >> (0xf & 31);
    v1 = t1 + v1;
    branch = (a1 != t2); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v1;
    if (branch) goto L_4d7c4;
    goto L_4d7f8;
L_4d7f8:
    v1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a0 = a0 + 16;
    v0 = v0 + 16;
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-16)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-14));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-14));
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-14)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-12));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-12));
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-12)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-10));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-10));
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-10)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-8));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-8));
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-8)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-6));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-6));
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-6)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-4));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-4));
    v1 = v1 + a1;
    *(volatile u16 *)(unsigned long)(a0 + (-4)) = v1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (-2));
    v1 = *(volatile u16 *)(unsigned long)(a0 + (-2));
    v1 = v1 + a1;
    branch = (a3 != a0); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v1;
    if (branch) goto L_4d7f8;
    goto L_4d884;
L_4d884:
    ra = *(volatile u32 *)(unsigned long)(sp + (268));
    s5 = *(volatile u32 *)(unsigned long)(sp + (264));
    s4 = *(volatile u32 *)(unsigned long)(sp + (260));
    s3 = *(volatile u32 *)(unsigned long)(sp + (256));
    s2 = *(volatile u32 *)(unsigned long)(sp + (252));
    s1 = *(volatile u32 *)(unsigned long)(sp + (248));
    s0 = *(volatile u32 *)(unsigned long)(sp + (244));
    sp = sp + 272;
    return ((u64)v1 << 32) | v0;
}
