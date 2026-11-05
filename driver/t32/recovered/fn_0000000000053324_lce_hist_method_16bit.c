/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bf860[] __asm__("t32_data_bf860");
extern unsigned char ref_t32_data_bf9a8[] __asm__("t32_data_bf9a8");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
u64 lce_hist_method_16bit(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[178] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_53360 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_533d0 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_533cc = ((u32)(unsigned long)ref_t32_data_bf860 + 0x8000U) & 0xffff0000U;
    const u32 hi_533ec = ((u32)(unsigned long)ref_t32_data_bf9a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_53564 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[114];
L_53324:
    sp = sp + -456;
    *(volatile u32 *)(unsigned long)(sp + (452)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (440)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (428)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (424)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (416)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (448)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (444)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (436)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (432)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (420)) = s1;
    t0 = *(volatile u32 *)(unsigned long)(a2 + (4));
    a3 = *(volatile u32 *)(unsigned long)(a2 + (24));
    v1 = *(volatile u32 *)(unsigned long)(a2 + (36));
    t3 = *(volatile u32 *)(unsigned long)(a2 + (40));
    s6 = hi_53360;
    s6 = s6 - hi_53360 + ((u32)(unsigned long)ref_memset + (0));
    s5 = *(volatile u32 *)(unsigned long)(a2 + (20));
    s4 = *(volatile u32 *)(unsigned long)(a2 + (32));
    *(volatile u32 *)(unsigned long)(sp + (460)) = a1;
    s8 = *(volatile u32 *)(unsigned long)(a2 + (28));
    s1 = *(volatile u32 *)(unsigned long)(a2 + (44));
    s7 = *(volatile u32 *)(unsigned long)(a2 + (48));
    a1 = 0;
    a2 = 128;
    s2 = a0;
    a0 = sp + 144;
    s0 = t0 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (412)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (408)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (404)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (400)) = t3;
    callee = s6; s3 = sp + 336;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_533ac;
L_533ac:
    a2 = 128;
    a1 = 0;
    callee = s6; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_533bc;
L_533bc:
    a2 = 64;
    a1 = 0;
    callee = s6; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_533cc;
L_533cc:
    a1 = hi_533cc;
    s6 = hi_533d0;
    s6 = s6 - hi_533d0 + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 64;
    a1 = a1 - hi_533cc + (u32)(unsigned long)ref_t32_data_bf860;
    callee = s6; a0 = sp + 272;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_533e8;
L_533e8:
    t0 = *(volatile u32 *)(unsigned long)(sp + (412));
    a0 = hi_533ec;
    a0 = a0 - hi_533ec + (u32)(unsigned long)ref_t32_data_bf9a8;
    v0 = t0 & 0xff;
    a1 = v0 << (0x1 & 31);
    a0 = a1 + a0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (404));
    a3 = *(volatile u32 *)(unsigned long)(sp + (408));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = v1 & 0xffff;
    a3 = a3 & 0xff;
    v1 = v1 * a0;
    t3 = *(volatile u32 *)(unsigned long)(sp + (400));
    t1 = sp + 16;
    a1 = sp + 144;
    t5 = s6;
    t6 = a1;
    t4 = t1;
    a2 = 0;
    t0 = 0;
    t2 = 0;
    s6 = s4 & 0xffff;
    ra = s5 & 0xff;
    a0 = a3 * a0;
    v1 = (s32)v1 >> (0xa & 31);
    a3 = 0;
    a0 = (s32)a0 >> (0xa & 31);
L_53454:
    t7 = (u32)a3 < (u32)(s0);
    t9 = v1 + t0;
    branch = (t7 == 0); t8 = a0 + a2;
    if (branch) goto L_53494;
    goto L_53464;
L_53464:
    a2 = ra + a2;
    t0 = s6 + t0;
    a3 = a3 + 1;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = t0;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = a2;
    t2 = t2 + a2;
    a3 = a3 & 0xff;
    t4 = t4 + 4;
    t6 = t6 + 4;
    a2 = t8;
    t0 = t9; goto L_53454;
L_53494:
    v0 = v0 << (0x2 & 31);
    a2 = sp + 16;
    v0 = a2 + v0;
    s1 = s1 & 0xffff;
    t3 = t3 & 0xffff;
    s0 = s0 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = t3;
    *(volatile u32 *)(unsigned long)(v0 + (128)) = s1;
    t2 = t2 + s1;
    s0 = s0 & 0xff;
    a3 = 31;
    s4 = s4 & 0xffff;
    s5 = s5 & 0xff;
L_534c8:
    v0 = (u32)s0 < (u32)(32);
    branch = (v0 == 0); a2 = s0 << (0x2 & 31);
    if (branch) goto L_53508;
    goto L_534d4;
L_534d4:
    v0 = a3 - s0;
    t3 = v1 * v0;
    t0 = sp + 16;
    a2 = t0 + a2;
    s0 = s0 + 1;
    s0 = s0 & 0xff;
    t0 = t3 + s4;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = t0;
    t0 = a0 * v0;
    v0 = t0 + s5;
    *(volatile u32 *)(unsigned long)(a2 + (128)) = v0;
    t2 = t2 + v0; goto L_534c8;
L_53508:
    a2 = s3;
    t0 = s2 + 64;
    v0 = 0;
    s8 = s8 & 0xff;
L_53518:
    v1 = *(volatile u16 *)(unsigned long)(s2 + (0));
    a3 = *(volatile u32 *)(unsigned long)(t1 + (0));
    s2 = s2 + 2;
    v1 = v1 + -1024;
    v1 = v1 * s8;
    t1 = t1 + 4;
    a2 = a2 + 2;
    v1 = (s32)v1 >> (0x7 & 31);
    v1 = v1 + 1024;
    a0 = (s32)a3 < (s32)(v1);
    if (a0 != 0) v1 = a3;
    *(volatile u16 *)(unsigned long)(a2 + (-2)) = v1;
    v1 = v1 & 0xffff;
    branch = (t0 != s2); v0 = v0 + v1;
    if (branch) goto L_53518;
    goto L_53554;
L_53554:
    a2 = 0x8000;
    a2 = a2 - v0;
    branch = ((s32)a2 >= 0); a0 = 0;
    if (branch) goto L_535cc;
    goto L_53564;
L_53564:
    v1 = hi_53564;
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_53564 + (u32)(unsigned long)ref_t32_data_d6c67);
    v0 = v0 << (0x5 & 31);
    v1 = 1;
    v0 = (s32)v0 >> (0xe & 31);
    v1 = v1 << (a0 & 31);
    v0 = v0 + 1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a1 = 0;
    v1 = 0;
    s7 = s7 & 0xff;
    a2 = 64;
    v0 = lo;
L_53598:
    a0 = s3 + a1;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a3 = sp + 272;
    a3 = a3 + a1;
    a0 = a0 * v0;
    a1 = a1 + 2;
    a0 = a0 >> (s7 & 31);
    *(volatile u16 *)(unsigned long)(a3 + (0)) = a0;
    a0 = a0 & 0xffff;
    branch = (a1 != a2); v1 = v1 + a0;
    if (branch) goto L_53598;
    goto L_535c4;
L_535c4:
    v0 = 0x8000; goto L_53614;
L_535cc:
    v1 = 0;
    a3 = 64;
L_535d4:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    t0 = s3 + a0;
    t0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    v0 = a2 * v0;
    a1 = a1 + 4;
    if (v0 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)v0 / (s32)t2; hi = (s32)v0 % (s32)t2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + t0;
    t0 = sp + 272;
    v0 = v0 & 0xffff;
    t0 = t0 + a0;
    a0 = a0 + 2;
    *(volatile u16 *)(unsigned long)(t0 + (0)) = v0;
    branch = (a0 != a3); v1 = v1 + v0;
    if (branch) goto L_535d4;
    goto L_53610;
L_53610:
    v0 = 0x8000;
L_53614:
    v1 = v0 - v1;
    v0 = 32;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a1 = v1 << (0x5 & 31);
    a1 = (s32)a1 >> (0xa & 31);
    v0 = sp + 272;
    v1 = hi;
L_53630:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = v0 + 2;
    a0 = a1 + a0;
    branch = (s3 != v0); *(volatile u16 *)(unsigned long)(v0 + (-2)) = a0;
    if (branch) goto L_53630;
    goto L_53644;
L_53644:
    v0 = *(volatile u16 *)(unsigned long)(sp + (334));
    a0 = *(volatile u32 *)(unsigned long)(sp + (460));
    a1 = sp + 272;
    v0 = v1 + v0;
    a2 = 64;
    callee = t5; *(volatile u16 *)(unsigned long)(sp + (334)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_53660;
L_53660:
    ra = *(volatile u32 *)(unsigned long)(sp + (452));
    s8 = *(volatile u32 *)(unsigned long)(sp + (448));
    s7 = *(volatile u32 *)(unsigned long)(sp + (444));
    s6 = *(volatile u32 *)(unsigned long)(sp + (440));
    s5 = *(volatile u32 *)(unsigned long)(sp + (436));
    s4 = *(volatile u32 *)(unsigned long)(sp + (432));
    s3 = *(volatile u32 *)(unsigned long)(sp + (428));
    s2 = *(volatile u32 *)(unsigned long)(sp + (424));
    s1 = *(volatile u32 *)(unsigned long)(sp + (420));
    s0 = *(volatile u32 *)(unsigned long)(sp + (416));
    sp = sp + 456;
    return ((u64)v1 << 32) | v0;
}
