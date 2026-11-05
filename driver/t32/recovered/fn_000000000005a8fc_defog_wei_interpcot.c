/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
u64 defog_wei_interpcot(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[138] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_5a904 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[74];
L_5a8fc:
    sp = sp + -296;
    *(volatile u32 *)(unsigned long)(sp + (284)) = s3;
    s3 = hi_5a904;
    *(volatile u32 *)(unsigned long)(sp + (288)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (280)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (276)) = s1;
    s4 = a0;
    s1 = a1;
    s2 = a2;
    a1 = 0;
    a2 = 128;
    a0 = sp + 144;
    s3 = s3 - hi_5a904 + ((u32)(unsigned long)ref_memset + (0));
    *(volatile u32 *)(unsigned long)(sp + (292)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (272)) = s0;
    callee = s3; s0 = a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5a940;
L_5a940:
    a2 = 128;
    a1 = 0;
    callee = s3; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5a950;
L_5a950:
    s4 = s1 + s4;
    a1 = s1;
    a2 = s2;
L_5a95c:
    branch = (a1 == s4); v1 = sp + 16;
    if (branch) goto L_5a998;
    goto L_5a964;
L_5a964:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    v0 = v0 << (0x2 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (128));
    a1 = a1 + 1;
    a2 = a2 + 1;
    v1 = v1 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (128)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 + a0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1; goto L_5a95c;
L_5a998:
    a1 = sp + 144;
    a3 = s0;
    a0 = sp + 16;
    t0 = 0;
    t2 = 31;
    t1 = 32;
L_5a9b0:
    a2 = *(volatile u32 *)(unsigned long)(a1 + (0));
    if (a2 == 0) { *(volatile u8 *)(unsigned long)(a3 + (0)) = 0; goto L_5a9e4; }
    goto L_5a9bc;
L_5a9bc:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = a2 >> (0x1 & 31);
    v0 = v1 + v0;
    if (a2) { lo = v0 / a2; hi = v0 % a2; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 & 0xff;
    v1 = (u32)v0 < (u32)(32);
    if (v1 == 0) { *(volatile u8 *)(unsigned long)(a3 + (0)) = t2; goto L_5a9e4; }
    goto L_5a9e0;
L_5a9e0:
    *(volatile u8 *)(unsigned long)(a3 + (0)) = v0;
L_5a9e4:
    if (t0 == 0) { t0 = t0 + 1; goto L_5aa04; }
    goto L_5a9ec;
L_5a9ec:
    v1 = *(volatile u8 *)(unsigned long)(a3 + (-1));
    v0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = (u32)v0 < (u32)(v1);
    if (v0 != 0) { *(volatile u8 *)(unsigned long)(a3 + (0)) = v1; goto L_5aa00; }
    goto L_5aa00;
L_5aa00:
    t0 = t0 + 1;
L_5aa04:
    a1 = a1 + 4;
    a3 = a3 + 1;
    branch = (t0 != t1); a0 = a0 + 4;
    if (branch) goto L_5a9b0;
    goto L_5aa14;
L_5aa14:
    ra = *(volatile u32 *)(unsigned long)(sp + (292));
    s4 = *(volatile u32 *)(unsigned long)(sp + (288));
    s3 = *(volatile u32 *)(unsigned long)(sp + (284));
    s2 = *(volatile u32 *)(unsigned long)(sp + (280));
    s1 = *(volatile u32 *)(unsigned long)(sp + (276));
    s0 = *(volatile u32 *)(unsigned long)(sp + (272));
    sp = sp + 296;
    return ((u64)v1 << 32) | v0;
}
