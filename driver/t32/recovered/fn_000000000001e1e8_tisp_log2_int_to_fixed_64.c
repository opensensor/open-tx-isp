/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref___ashldi3[] __asm__("__ashldi3");
extern unsigned char ref___lshrdi3[] __asm__("__lshrdi3");
u64 tisp_log2_int_to_fixed_64(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1e2c8 = (((u32)(unsigned long)ref___ashldi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1e2c0 = (((u32)(unsigned long)ref___lshrdi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1e390 = (((u32)(unsigned long)ref___ashldi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_1e3ac = (((u32)(unsigned long)ref___lshrdi3 + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_1e1e8:
    v1 = a0 | a1;
    branch = (v1 == 0); ;
    if (branch) goto L_1e3e4;
    goto L_1e1f4;
L_1e1f4:
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    s3 = a2 & 0xff;
    branch = (a1 == 0); s2 = a3 & 0xff;
    if (branch) goto L_1e228;
    goto L_1e218;
L_1e218:
    v0 = a1;
    v1 = 0;
    s0 = 32; goto L_1e234;
L_1e228:
    v0 = a0;
    v1 = 0;
    s0 = 0;
L_1e234:
    a2 = 0x1U << 16;
    a2 = (u32)v0 < (u32)(a2);
    branch = (a2 != 0); a2 = (u32)v0 < (u32)(256);
    if (branch) goto L_1e254;
    goto L_1e244;
L_1e244:
    v0 = v0 >> (0x10 & 31);
    v1 = 0;
    s0 = s0 + 16;
    a2 = (u32)v0 < (u32)(256);
L_1e254:
    branch = (a2 != 0); a2 = (u32)v0 < (u32)(16);
    if (branch) goto L_1e26c;
    goto L_1e25c;
L_1e25c:
    v0 = v0 >> (0x8 & 31);
    v1 = 0;
    s0 = s0 + 8;
    a2 = (u32)v0 < (u32)(16);
L_1e26c:
    branch = (a2 != 0); a2 = (u32)v0 < (u32)(4);
    if (branch) goto L_1e284;
    goto L_1e274;
L_1e274:
    v0 = v0 >> (0x4 & 31);
    v1 = 0;
    s0 = s0 + 4;
    a2 = (u32)v0 < (u32)(4);
L_1e284:
    branch = (a2 != 0); a2 = 1;
    if (branch) goto L_1e2a4;
    goto L_1e28c;
L_1e28c:
    a2 = v1 << (0x1e & 31);
    v0 = v0 >> (0x2 & 31);
    v0 = a2 | v0;
    v1 = v1 >> (0x2 & 31);
    s0 = s0 + 2;
    a2 = 1;
L_1e2a4:
    if (v0 != a2) { s0 = s0 + 1; goto L_1e2b8; }
    goto L_1e2ac;
L_1e2ac:
    branch = (v1 == 0); v0 = (s32)s0 < (s32)(16);
    if (branch) goto L_1e2bc;
    goto L_1e2b4;
L_1e2b4:
    s0 = s0 + 1;
L_1e2b8:
    v0 = (s32)s0 < (s32)(16);
L_1e2bc:
    if (v0 == 0) { v0 = hi_1e2c0; goto L_1e2f4; }
    goto L_1e2c4;
L_1e2c4:
    a2 = 15;
    v0 = hi_1e2c8;
    a2 = a2 - s0;
    v0 = v0 - hi_1e2c8 + ((u32)(unsigned long)ref___ashldi3 + (0));
L_1e2d4:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1e2dc;
L_1e2dc:
    s1 = v0;
    a0 = 0;
    a2 = 0;
    v0 = 0;
    a3 = 0x8000U << 16; goto L_1e358;
L_1e2f4:
    a2 = s0 + -15;
    v0 = v0 - hi_1e2c0 + ((u32)(unsigned long)ref___lshrdi3 + (0)); goto L_1e2d4;
L_1e300:
    a2 = a2 << (0x1 & 31);
    product = (u64)(u32)s1 * (u32)s1; lo = product; hi = product >> 32;
    v1 = v1 << (0x1 & 31);
    t1 = hi;
    v1 = v1 + t1;
    t1 = v1;
    t0 = lo;
    a1 = a3 & t0;
    v1 = a1 | v1;
    a1 = a0 >> (0x1f & 31);
    a2 = a1 | a2;
    branch = (v1 == 0); a0 = a0 << (0x1 & 31);
    if (branch) goto L_1e36c;
    goto L_1e334;
L_1e334:
    a1 = a0 + 1;
    v1 = (u32)a1 < (u32)(a0);
    a2 = v1 + a2;
    s1 = t0 >> (0x10 & 31);
    v1 = t1 << (0x10 & 31);
    s1 = v1 | s1;
    a0 = a1;
    v1 = t1 >> (0x10 & 31);
L_1e354:
    v0 = v0 + 1;
L_1e358:
    a1 = (s32)v0 < (s32)(s3);
    branch = (a1 != 0); v1 = v1 * s1;
    if (branch) goto L_1e300;
    goto L_1e364;
L_1e364:
    s0 = s0 << (s3 & 31); goto L_1e380;
L_1e36c:
    v1 = t1 << (0x11 & 31);
    s1 = t0 >> (0xf & 31);
    s1 = v1 | s1;
    v1 = t1 >> (0xf & 31); goto L_1e354;
L_1e380:
    a0 = s0 + a0;
    a1 = (s32)s0 >> (0x1f & 31);
    a1 = a1 + a2;
    s0 = (u32)a0 < (u32)(s0);
    v0 = hi_1e390;
    a2 = s2;
    v0 = v0 - hi_1e390 + ((u32)(unsigned long)ref___ashldi3 + (0));
    callee = v0; a1 = s0 + a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1e3a4;
L_1e3a4:
    s0 = v0;
    a2 = 15;
    v0 = hi_1e3ac;
    a2 = a2 - s2;
    a0 = s1 & 0x7fff;
    v0 = v0 - hi_1e3ac + ((u32)(unsigned long)ref___lshrdi3 + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1e3c4;
L_1e3c4:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    v0 = s0 | v0;
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
L_1e3e4:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
