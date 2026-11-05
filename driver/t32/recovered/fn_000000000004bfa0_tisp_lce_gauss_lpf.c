/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_calculate_exponential[] __asm__("calculate_exponential");
extern unsigned char ref_div64_u64[] __asm__("div64_u64");
u64 tisp_lce_gauss_lpf(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[286] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4bfd0 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4c020 = ((u32)(unsigned long)ref_calculate_exponential + 0x8000U) & 0xffff0000U;
    const u32 hi_4c0d0 = (((u32)(unsigned long)ref_div64_u64 + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[222];
L_4bfa0:
    sp = sp + -888;
    *(volatile u32 *)(unsigned long)(sp + (884)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (852)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (848)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (880)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (876)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (872)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (868)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (864)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (860)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (856)) = s2;
    s2 = *(volatile u8 *)(unsigned long)(a0 + (0));
    s0 = hi_4bfd0;
    s0 = s0 - hi_4bfd0 + ((u32)(unsigned long)ref_memset + (0));
    a2 = 648;
    a0 = sp + 16;
    s1 = a1;
    callee = s0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bfec;
L_4bfec:
    a2 = 162;
    a1 = 0;
    callee = s0; a0 = sp + 664;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bffc;
L_4bffc:
    s0 = s2;
    s2 = (u32)s2 < (u32)(9);
    if (s2 != 0) { s0 = 9; goto L_4c00c; }
    goto L_4c00c;
L_4c00c:
    s0 = s0 & 0xff;
    s0 = s0 * s0;
    s6 = sp + 16;
    s3 = 252;
    s4 = 0;
    t0 = hi_4c020;
    t1 = 0x100U << 16;
    t2 = 5;
    s8 = (s0 >> 0x1) & ((1U << 0x10) - 1);
L_4c030:
    s7 = s3 * s3;
    s5 = s6;
    s2 = 252;
    s7 = s7 & 0xff;
L_4c040:
    v0 = s2 * s2;
    a3 = 8;
    a2 = 10;
    a1 = 15;
    *(volatile u32 *)(unsigned long)(sp + (840)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (836)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (832)) = t0;
    s2 = s2 + 1;
    s2 = s2 & 0xff;
    s5 = s5 + 8;
    a0 = v0 + s7;
    a0 = a0 & 0xff;
    a0 = a0 << (0x13 & 31);
    a0 = a0 + s8;
    if (a0 == 0x80000000U && s0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s0) { lo = (s32)a0 / (s32)s0; hi = (s32)a0 % (s32)s0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = t0 - hi_4c020 + (u32)(unsigned long)ref_calculate_exponential;
    callee = v0; a0 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4c088;
L_4c088:
    t1 = *(volatile u32 *)(unsigned long)(sp + (836));
    v1 = (s32)v0 >> (0x1 & 31);
    t2 = *(volatile u32 *)(unsigned long)(sp + (840));
    v1 = v1 + t1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    t0 = *(volatile u32 *)(unsigned long)(sp + (832));
    v0 = lo;
    v1 = (s32)v0 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(s5 + (-8)) = v0;
    *(volatile u32 *)(unsigned long)(s5 + (-4)) = v1;
    branch = (s2 != t2); s4 = v0 + s4;
    if (branch) goto L_4c040;
    goto L_4c0b8;
L_4c0b8:
    s3 = s3 + 1;
    s3 = s3 & 0xff;
    branch = (s3 != s2); s6 = s6 + 72;
    if (branch) goto L_4c030;
    goto L_4c0c8;
L_4c0c8:
    s2 = 0;
    s5 = (s32)s4 >> (0x1f & 31);
    s6 = hi_4c0d0;
    s7 = 18;
    s8 = 162;
    s3 = s2 << (0x2 & 31);
L_4c0e0:
    s0 = 0;
L_4c0e4:
    v0 = s0 << (0x2 & 31);
    v1 = sp + 16;
    v0 = v0 + s3;
    v0 = v1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a2 = s4;
    a1 = a0 >> (0x10 & 31);
    v0 = v0 << (0x10 & 31);
    a0 = a0 << (0x10 & 31);
    a1 = a1 | v0;
    v0 = s6 - hi_4c0d0 + ((u32)(unsigned long)ref_div64_u64 + (0));
    callee = v0; a3 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4c11c;
L_4c11c:
    v1 = s0 + s2;
    a0 = sp + 664;
    v1 = a0 + v1;
    s0 = s0 + 2;
    branch = (s0 != s7); *(volatile u16 *)(unsigned long)(v1 + (0)) = v0;
    if (branch) goto L_4c0e4;
    goto L_4c134;
L_4c134:
    s2 = s2 + 18;
    if (s2 != s8) { s3 = s2 << (0x2 & 31); goto L_4c0e0; }
    goto L_4c140;
L_4c140:
    a0 = 0;
    a1 = 14;
    t2 = 5;
L_4c14c:
    a2 = a0 & 0xff;
    t0 = a0 << (0x3 & 31);
    v0 = a2;
    t1 = a2 + a1;
    t0 = t0 + a0;
L_4c160:
    a3 = t0 + v0;
    a3 = a3 << (0x1 & 31);
    t3 = sp + 16;
    v1 = t1 - v0;
    a3 = t3 + a3;
    v1 = v1 & 0xff;
    a3 = *(volatile u16 *)(unsigned long)(a3 + (648));
    v1 = v1 << (0x1 & 31);
    v0 = v0 + 1;
    v1 = s1 + v1;
    v0 = v0 & 0xff;
    branch = (v0 != t2); *(volatile u16 *)(unsigned long)(v1 + (0)) = a3;
    if (branch) goto L_4c160;
    goto L_4c194;
L_4c194:
    a2 = a2 + -5;
    a1 = a1 + a2;
    a0 = a0 + 1;
    branch = (a0 != v0); a1 = a1 & 0xff;
    if (branch) goto L_4c14c;
    goto L_4c1a8;
L_4c1a8:
    ra = *(volatile u32 *)(unsigned long)(sp + (884));
    s8 = *(volatile u32 *)(unsigned long)(sp + (880));
    s7 = *(volatile u32 *)(unsigned long)(sp + (876));
    s6 = *(volatile u32 *)(unsigned long)(sp + (872));
    s5 = *(volatile u32 *)(unsigned long)(sp + (868));
    s4 = *(volatile u32 *)(unsigned long)(sp + (864));
    s3 = *(volatile u32 *)(unsigned long)(sp + (860));
    s2 = *(volatile u32 *)(unsigned long)(sp + (856));
    s1 = *(volatile u32 *)(unsigned long)(sp + (852));
    s0 = *(volatile u32 *)(unsigned long)(sp + (848));
    sp = sp + 888;
    return ((u64)v1 << 32) | v0;
}
