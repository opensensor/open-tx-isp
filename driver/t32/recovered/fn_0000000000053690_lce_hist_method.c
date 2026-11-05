/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bf8a0[] __asm__("t32_data_bf8a0");
extern unsigned char ref_t32_data_bf9a8[] __asm__("t32_data_bf9a8");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
extern unsigned char ref_t32_data_d6c66[] __asm__("t32_data_d6c66");
u64 lce_hist_method(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[210] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_536c8 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_53734 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_53730 = ((u32)(unsigned long)ref_t32_data_bf8a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_53754 = ((u32)(unsigned long)ref_t32_data_bf9a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_538e0 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_538dc = ((u32)(unsigned long)ref_t32_data_d6c66 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[146];
L_53690:
    sp = sp + -584;
    *(volatile u32 *)(unsigned long)(sp + (580)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (556)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (548)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (544)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (576)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (572)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (568)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (564)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (560)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (552)) = s2;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    t2 = *(volatile u32 *)(unsigned long)(a2 + (24));
    t1 = *(volatile u32 *)(unsigned long)(a2 + (40));
    a3 = hi_536c8;
    s0 = a3 - hi_536c8 + ((u32)(unsigned long)ref_memset + (0));
    s7 = *(volatile u32 *)(unsigned long)(a2 + (20));
    s5 = *(volatile u32 *)(unsigned long)(a2 + (32));
    s4 = *(volatile u32 *)(unsigned long)(a2 + (36));
    *(volatile u32 *)(unsigned long)(sp + (588)) = a1;
    s6 = *(volatile u32 *)(unsigned long)(a2 + (28));
    s8 = *(volatile u32 *)(unsigned long)(a2 + (44));
    s2 = *(volatile u32 *)(unsigned long)(a2 + (48));
    a1 = 0;
    a2 = 128;
    s3 = a0;
    a0 = sp + 400;
    *(volatile u32 *)(unsigned long)(sp + (540)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (536)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (532)) = t1;
    callee = s0; s1 = sp + 144;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_53710;
L_53710:
    a2 = 128;
    a1 = 0;
    callee = s0; a0 = sp + 272;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_53720;
L_53720:
    a2 = 128;
    a1 = 0;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_53730;
L_53730:
    a1 = hi_53730;
    a3 = hi_53734;
    a3 = a3 - hi_53734 + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 128;
    a1 = a1 - hi_53730 + (u32)(unsigned long)ref_t32_data_bf8a0;
    a0 = sp + 16;
    callee = a3; *(volatile u32 *)(unsigned long)(sp + (528)) = a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_53750;
L_53750:
    v1 = *(volatile u32 *)(unsigned long)(sp + (540));
    v0 = hi_53754;
    v0 = v0 - hi_53754 + (u32)(unsigned long)ref_t32_data_bf9a8;
    v1 = v1 & 0xff;
    a0 = v1 << (0x1 & 31);
    v0 = a0 + v0;
    t2 = *(volatile u32 *)(unsigned long)(sp + (536));
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t0 = s4 & 0xffff;
    v0 = t2 & 0xff;
    t0 = t0 * a0;
    a3 = *(volatile u32 *)(unsigned long)(sp + (528));
    t1 = *(volatile u32 *)(unsigned long)(sp + (532));
    t4 = sp + 272;
    t3 = sp + 400;
    a1 = 0;
    a2 = 0;
    t2 = 0;
    t8 = s5 & 0xffff;
    t9 = s7 & 0xff;
    v0 = v0 * a0;
    t0 = (s32)t0 >> (0xa & 31);
    a0 = 0;
    v0 = (s32)v0 >> (0xa & 31);
L_537b0:
    t5 = (s32)t2 < (s32)(v1);
    t7 = t0 + a2;
    branch = (t5 == 0); t6 = v0 + a1;
    if (branch) goto L_537ec;
    goto L_537c0;
L_537c0:
    a1 = t9 + a1;
    a2 = t8 + a2;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = a2;
    *(volatile u32 *)(unsigned long)(t3 + (0)) = a1;
    a0 = a0 + a1;
    t2 = t2 + 1;
    t4 = t4 + 4;
    t3 = t3 + 4;
    a1 = t6;
    a2 = t7; goto L_537b0;
L_537ec:
    t3 = v1 << (0x2 & 31);
    a1 = sp + 16;
    a1 = a1 + t3;
    t1 = t1 & 0xffff;
    s8 = s8 & 0xffff;
    *(volatile u32 *)(unsigned long)(a1 + (256)) = t1;
    *(volatile u32 *)(unsigned long)(a1 + (384)) = s8;
    a1 = 31;
    t1 = v1 + 1;
    v1 = a1 - v1;
    t6 = t0 * v1;
    a0 = a0 + s8;
    t2 = 0;
    t4 = 0;
    t5 = 0;
    s5 = s5 & 0xffff;
    s7 = s7 & 0xff;
    v1 = v0 * v1;
L_53834:
    a1 = (s32)t1 < (s32)(32);
    t5 = t5 - t0;
    t4 = t4 + 4;
    branch = (a1 == 0); t2 = t2 - v0;
    if (branch) goto L_53880;
    goto L_53848;
L_53848:
    a2 = t3 + t4;
    a1 = sp + 272;
    t7 = a1 + a2;
    a1 = t5 + t6;
    a1 = s5 + a1;
    *(volatile u32 *)(unsigned long)(t7 + (0)) = a1;
    a1 = t2 + v1;
    t7 = sp + 400;
    a1 = s7 + a1;
    a2 = t7 + a2;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = a1;
    a0 = a0 + a1;
    t1 = t1 + 1; goto L_53834;
L_53880:
    a1 = 0;
    v0 = 0;
    s6 = s6 & 0xff;
    t1 = 128;
L_53890:
    v1 = s3 + a1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = sp + 272;
    a2 = a2 + a1;
    v1 = v1 + -1024;
    v1 = v1 * s6;
    t0 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v1 = (s32)v1 >> (0x7 & 31);
    v1 = v1 + 1024;
    a2 = (s32)t0 < (s32)(v1);
    if (a2 != 0) v1 = t0;
    a2 = s1 + a1;
    a1 = a1 + 4;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = v1;
    branch = (a1 != t1); v0 = v0 + v1;
    if (branch) goto L_53890;
    goto L_538d0;
L_538d0:
    a2 = 0x8000;
    a2 = a2 - v0;
    if ((s32)a2 >= 0) { v0 = hi_538dc; goto L_53944; }
    goto L_538e0;
L_538e0:
    v1 = hi_538e0;
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_538e0 + (u32)(unsigned long)ref_t32_data_d6c67);
    v0 = v0 << (0x5 & 31);
    v1 = 1;
    v0 = (s32)v0 >> (0xe & 31);
    v1 = v1 << (a0 & 31);
    v0 = v0 + 1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a1 = 0;
    v1 = 0;
    s2 = s2 & 0xff;
    a2 = 128;
    v0 = lo;
L_53914:
    a0 = s1 + v1;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t0 = sp + 16;
    t0 = t0 + v1;
    a0 = v0 * a0;
    v1 = v1 + 4;
    a0 = a0 >> (s2 & 31);
    *(volatile u32 *)(unsigned long)(t0 + (0)) = a0;
    branch = (v1 != a2); a1 = a1 + a0;
    if (branch) goto L_53914;
    goto L_5393c;
L_5393c:
    v0 = 0x8000; goto L_539a4;
L_53944:
    t0 = *(volatile u8 *)(unsigned long)(v0 - hi_538dc + (u32)(unsigned long)ref_t32_data_d6c66);
    v0 = 1;
    v1 = 0;
    v0 = v0 << (t0 & 31);
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a1 = 0;
    t1 = 128;
    a0 = lo;
L_53964:
    v0 = sp + 400;
    v0 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t2 = s1 + v1;
    t2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    v0 = a2 * v0;
    v0 = v0 * a0;
    v0 = v0 >> (t0 & 31);
    v0 = v0 + t2;
    t2 = sp + 16;
    t2 = t2 + v1;
    v1 = v1 + 4;
    *(volatile u32 *)(unsigned long)(t2 + (0)) = v0;
    branch = (v1 != t1); a1 = a1 + v0;
    if (branch) goto L_53964;
    goto L_539a0;
L_539a0:
    v0 = 0x8000;
L_539a4:
    v0 = v0 - a1;
    v1 = 32;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a1 = v0 << (0x5 & 31);
    a1 = (s32)a1 >> (0xa & 31);
    v1 = sp + 16;
    v0 = hi;
L_539c0:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v1 + 4;
    a0 = a0 + a1;
    branch = (s1 != v1); *(volatile u32 *)(unsigned long)(v1 + (-4)) = a0;
    if (branch) goto L_539c0;
    goto L_539d4;
L_539d4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (140));
    a0 = *(volatile u32 *)(unsigned long)(sp + (588));
    a1 = sp + 16;
    v0 = v1 + v0;
    a2 = 128;
    callee = a3; *(volatile u32 *)(unsigned long)(sp + (140)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_539f0;
L_539f0:
    ra = *(volatile u32 *)(unsigned long)(sp + (580));
    s8 = *(volatile u32 *)(unsigned long)(sp + (576));
    s7 = *(volatile u32 *)(unsigned long)(sp + (572));
    s6 = *(volatile u32 *)(unsigned long)(sp + (568));
    s5 = *(volatile u32 *)(unsigned long)(sp + (564));
    s4 = *(volatile u32 *)(unsigned long)(sp + (560));
    s3 = *(volatile u32 *)(unsigned long)(sp + (556));
    s2 = *(volatile u32 *)(unsigned long)(sp + (552));
    s1 = *(volatile u32 *)(unsigned long)(sp + (548));
    s0 = *(volatile u32 *)(unsigned long)(sp + (544));
    sp = sp + 584;
    return ((u64)v1 << 32) | v0;
}
