/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_beea4[] __asm__("t32_data_beea4");
extern unsigned char ref___lshrdi3[] __asm__("__lshrdi3");
u64 tisp_math_exp2(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1d194 = ((u32)(unsigned long)ref_t32_data_beea4 + 0x8000U) & 0xffff0000U;
    const u32 hi_1d224 = (((u32)(unsigned long)ref___lshrdi3 + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_1d180:
    a1 = a1 & 0xff;
    t0 = 1;
    v1 = t0 << (a1 & 31);
    sp = sp + -32;
    v1 = v1 + -1;
    a3 = hi_1d194;
    v0 = (u32)a1 < (u32)(6);
    v1 = v1 & a0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    s1 = a2 & 0xff;
    s2 = a0 >> (a1 & 31);
    branch = (v0 == 0); a3 = a3 - hi_1d194 + (u32)(unsigned long)ref_t32_data_beea4;
    if (branch) goto L_1d1ec;
    goto L_1d1c0;
L_1d1c0:
    a2 = 5;
    a1 = a2 - a1;
    v1 = v1 << (a1 & 31);
    v1 = v1 << (0x2 & 31);
    v1 = a3 + v1;
    v0 = 30;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_1d1dc:
    v0 = v0 - s1;
    v0 = v0 - s2;
    v0 = v1 >> (v0 & 31); goto L_1d24c;
L_1d1ec:
    a2 = a1 + -5;
    a1 = v1 >> (a2 & 31);
    v0 = a1 << (0x2 & 31);
    a1 = a1 + 1;
    a1 = a1 << (0x2 & 31);
    v0 = a3 + v0;
    a3 = a3 + a1;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    t0 = t0 << (a2 & 31);
    t0 = t0 + -1;
    a0 = a0 - s0;
    v1 = t0 & v1;
    product = (u64)(u32)a0 * (u32)v1; lo = product; hi = product >> 32;
    v0 = hi_1d224;
    v0 = v0 - hi_1d224 + ((u32)(unsigned long)ref___lshrdi3 + (0));
    a0 = lo;
L_1d230:
    callee = v0; a1 = hi;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1d238;
L_1d238:
    v0 = s0 + v0;
    s0 = 30;
    s1 = s0 - s1;
    s0 = s1 - s2;
    v0 = v0 >> (s0 & 31);
L_1d24c:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
