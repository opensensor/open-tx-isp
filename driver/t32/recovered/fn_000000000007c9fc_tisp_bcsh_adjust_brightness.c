/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_tisp_round_int64[] __asm__("tisp_round_int64");
u64 tisp_bcsh_adjust_brightness(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7ca60 = ((u32)(unsigned long)ref_tisp_round_int64 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
    stack[22] = arg4;
    stack[23] = arg5;
    stack[24] = arg6;
    stack[25] = arg7;
    stack[26] = arg8;
    stack[27] = arg9;
    stack[28] = arg10;
    stack[29] = arg11;
    stack[30] = arg12;
    stack[31] = arg13;
L_7c9fc:
    sp = sp + -72;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s5;
    s5 = *(volatile u8 *)(unsigned long)(sp + (124));
    a0 = a0 & 0xff;
    a0 = a0 + -128;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (68)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    s4 = a1;
    s6 = a2;
    *(volatile u32 *)(unsigned long)(sp + (84)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = 0;
    s5 = s5 << (0x2 & 31);
    s0 = a0 << (0x3 & 31);
    s3 = sp + 84;
    s2 = 0;
    s7 = 12;
    s8 = hi_7ca60;
L_7ca64:
    v1 = s6;
    s1 = 0;
    a0 = 0;
    a1 = 0;
L_7ca74:
    a2 = s3 + s1;
    v0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(a2 + (4));
    s1 = s1 + 4;
    v1 = v1 + 2;
    v0 = v0 * a2;
    a3 = (s32)v0 >> (0x1f & 31);
    v0 = a0 + v0;
    a2 = (u32)v0 < (u32)(a0);
    a1 = a1 + a3;
    a0 = v0;
    branch = (s1 != s7); a1 = a2 + a1;
    if (branch) goto L_7ca74;
    goto L_7caa8;
L_7caa8:
    v0 = s8 - hi_7ca60 + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a2 = 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7cab4;
L_7cab4:
    v1 = sp + 16;
    v1 = v1 + s2;
    s2 = s2 + 4;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    branch = (s2 != s1); s3 = s3 + 12;
    if (branch) goto L_7ca64;
    goto L_7cacc;
L_7cacc:
    v0 = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = *(volatile u32 *)(unsigned long)(sp + (16));
    ra = *(volatile u32 *)(unsigned long)(sp + (68));
    *(volatile u16 *)(unsigned long)(s4 + (2)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    a0 = a0 + s5;
    a0 = a0 + s0;
    *(volatile u16 *)(unsigned long)(s4 + (4)) = v0;
    s8 = *(volatile u32 *)(unsigned long)(sp + (64));
    s7 = *(volatile u32 *)(unsigned long)(sp + (60));
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    *(volatile u16 *)(unsigned long)(s4 + (0)) = a0;
    v0 = 0;
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    sp = sp + 72;
    return ((u64)v1 << 32) | v0;
}
