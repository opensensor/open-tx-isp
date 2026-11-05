/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_fix_point_div[] __asm__("fix_point_div");
u64 tisp_tmo_adr_ispint_adr_64(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_95728 = ((u32)(unsigned long)ref_fix_point_div + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
    stack[12] = arg4;
L_95638:
    sp = sp + -32;
    t0 = *(volatile u32 *)(unsigned long)(sp + (48));
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    t2 = a2;
    v1 = 0;
L_95650:
    v0 = (s32)v1 < (s32)(t0);
    branch = (v0 == 0); t2 = t2 + 8;
    if (branch) goto L_957cc;
    goto L_9565c;
L_9565c:
    t1 = *(volatile u32 *)(unsigned long)(t2 + (-4));
    t3 = (s32)t1 < (s32)(a1);
    branch = (t3 != 0); v0 = *(volatile u32 *)(unsigned long)(t2 + (-8));
    if (branch) goto L_957c4;
    goto L_9566c;
L_9566c:
    branch = (a1 != t1); t3 = (u32)v0 < (u32)(a0);
    if (branch) goto L_9567c;
    goto L_95674;
L_95674:
    if (t3 != 0) { v1 = v1 + 1; goto L_95650; }
    goto L_9567c;
L_9567c:
    if (v1 == 0) { v0 = *(volatile s16 *)(unsigned long)(a3 + (0)); goto L_957d8; }
    goto L_95684;
L_95684:
    t0 = v1 << (0x3 & 31);
    t0 = t0 + -8;
    a2 = a2 + t0;
    t0 = *(volatile u32 *)(unsigned long)(a2 + (0));
    t2 = *(volatile u32 *)(unsigned long)(a2 + (4));
    branch = (v0 != t0); a2 = v1 << (0x1 & 31);
    if (branch) goto L_956b4;
    goto L_956a0;
L_956a0:
    branch = (t1 != t2); s0 = a2 + -2;
    if (branch) goto L_956b8;
    goto L_956a8;
L_956a8:
    a3 = a3 + a2;
    v0 = *(volatile s16 *)(unsigned long)(a3 + (0)); goto L_957d8;
L_956b4:
    s0 = a2 + -2;
L_956b8:
    s0 = a3 + s0;
    a3 = a3 + a2;
    a2 = *(volatile s16 *)(unsigned long)(a3 + (0));
    a3 = *(volatile s16 *)(unsigned long)(s0 + (0));
    v1 = v0 - t0;
    t0 = a0 - t0;
    a0 = (u32)a0 < (u32)(t0);
    a1 = a1 - t2;
    a2 = a2 - a3;
    a1 = a1 - a0;
    product = (s64)(s32)a1 * (s32)a2; lo = product; hi = product >> 32;
    a3 = (s32)a2 >> (0x1f & 31);
    v0 = (u32)v0 < (u32)(v1);
    t1 = t1 - t2;
    v0 = t1 - v0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t0); lo = product; hi = product >> 32;
    a3 = lo;
    product = (u64)(u32)a2 * (u32)t0; lo = product; hi = product >> 32;
    a2 = v1 >> (0x1 & 31);
    a1 = hi;
    a1 = a3 + a1;
    a3 = v0 << (0x1f & 31);
    a0 = lo;
    a2 = a3 | a2;
    a2 = a0 + a2;
    a3 = (s32)v0 >> (0x1 & 31);
    a3 = a1 + a3;
    a0 = (u32)a2 < (u32)(a0);
    a1 = hi_95728;
    a3 = a0 + a3;
    branch = ((s32)a3 >= 0); a1 = a1 - hi_95728 + (u32)(unsigned long)ref_fix_point_div;
    if (branch) goto L_95778;
    goto L_95738;
L_95738:
    a2 = -a2;
    a3 = -a3;
    branch = ((s32)v0 >= 0); a0 = (u32)0 < (u32)(a2);
    if (branch) goto L_95768;
    goto L_95748;
L_95748:
    v1 = -v1;
    t0 = (u32)0 < (u32)(v1);
    v0 = -v0;
    v0 = v0 - t0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    a3 = a3 - a0; goto L_957b0;
L_95768:
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    a3 = a3 - a0; goto L_95798;
L_95778:
    if ((s32)v0 >= 0) { *(volatile u32 *)(unsigned long)(sp + (16)) = v1; goto L_957ac; }
    goto L_95780;
L_95780:
    v1 = -v1;
    a0 = (u32)0 < (u32)(v1);
    v0 = -v0;
    v0 = v0 - a0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
L_95798:
    callee = a1; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_957a0;
L_957a0:
    v1 = *(volatile s16 *)(unsigned long)(s0 + (0));
    v0 = v1 - v0; goto L_957d8;
L_957ac:
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
L_957b0:
    callee = a1; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_957b8;
L_957b8:
    v1 = *(volatile s16 *)(unsigned long)(s0 + (0));
    v0 = v1 + v0; goto L_957d8;
L_957c4:
    v1 = v1 + 1; goto L_95650;
L_957cc:
    t0 = t0 << (0x1 & 31);
    a3 = a3 + t0;
    v0 = *(volatile s16 *)(unsigned long)(a3 + (-2));
L_957d8:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
