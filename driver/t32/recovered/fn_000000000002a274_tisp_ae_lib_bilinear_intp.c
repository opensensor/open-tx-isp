/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_tisp_ae_lib_div_64[] __asm__("tisp_ae_lib_div_64");
u64 tisp_ae_lib_bilinear_intp(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2a340 = ((u32)(unsigned long)ref_tisp_ae_lib_div_64 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
    stack[12] = arg4;
    stack[13] = arg5;
    stack[14] = arg6;
    stack[15] = arg7;
L_2a274:
    sp = sp + -32;
    t0 = *(volatile u32 *)(unsigned long)(sp + (52));
    v1 = a3;
    v0 = a0;
    a0 = (u32)t0 < (u32)(v1);
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    t1 = a2;
    a3 = *(volatile u32 *)(unsigned long)(sp + (48));
    s0 = *(volatile u32 *)(unsigned long)(sp + (56));
    branch = (a0 != 0); t3 = *(volatile u32 *)(unsigned long)(sp + (60));
    if (branch) goto L_2a2bc;
    goto L_2a2a8;
L_2a2a8:
    if (v1 != t0) { a2 = a3 - t1; goto L_2a2d0; }
    goto L_2a2b0;
L_2a2b0:
    a0 = (u32)a3 < (u32)(a2);
    if (a0 == 0) { a2 = a3 - t1; goto L_2a2d0; }
    goto L_2a2bc;
L_2a2bc:
    a2 = t1 - a3;
    a3 = (u32)t1 < (u32)(a2);
    t0 = v1 - t0;
    a3 = t0 - a3; goto L_2a2dc;
L_2a2d0:
    t2 = (u32)a3 < (u32)(a2);
    t0 = t0 - v1;
    a3 = t0 - t2;
L_2a2dc:
    a0 = (u32)v1 < (u32)(a1);
    branch = (a0 != 0); a0 = v0 - t1;
    if (branch) goto L_2a300;
    goto L_2a2e8;
L_2a2e8:
    branch = (a1 != v1); a0 = t1 - v0;
    if (branch) goto L_2a310;
    goto L_2a2f0;
L_2a2f0:
    a0 = (u32)t1 < (u32)(v0);
    if (a0 == 0) { a0 = t1 - v0; goto L_2a310; }
    goto L_2a2fc;
L_2a2fc:
    a0 = v0 - t1;
L_2a300:
    v0 = (u32)v0 < (u32)(a0);
    v1 = a1 - v1;
    v1 = v1 - v0; goto L_2a31c;
L_2a310:
    t1 = (u32)t1 < (u32)(a0);
    v1 = v1 - a1;
    v1 = v1 - t1;
L_2a31c:
    s1 = (u32)t3 < (u32)(s0);
    v0 = s0 - t3;
    t3 = t3 - s0;
    if (s1 != 0) t3 = v0;
    product = (u64)(u32)t3 * (u32)a0; lo = product; hi = product >> 32;
    a1 = hi;
    a0 = lo;
    v0 = v1 * t3;
    a1 = v0 + a1;
    v0 = hi_2a340;
    v0 = v0 - hi_2a340 + (u32)(unsigned long)ref_tisp_ae_lib_div_64;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2a350;
L_2a350:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    v1 = s0 - v0;
    v0 = s0 + v0;
    if (s1 != 0) v0 = v1;
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
