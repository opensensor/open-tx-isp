/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
u64 tx_isp_open(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_1566c = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_15660:
    v1 = *(volatile u32 *)(unsigned long)(a1 + (120));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (292));
    if (v0 == 0) { v0 = hi_1566c; goto L_15680; }
    goto L_15670;
L_15670:
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (292)) = v0;
    v0 = 0;
    return ((u64)v1 << 32) | v0;
L_15680:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_1566c + (u32)(unsigned long)ref_t32_data_d9008);
    sp = sp + -32;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    if (branch) goto L_156a8;
    goto L_1569c;
L_1569c:
    *(volatile u32 *)(unsigned long)(v1 + (312)) = 0;
    *(volatile u32 *)(unsigned long)(v1 + (316)) = 0;
    *(volatile u32 *)(unsigned long)(v1 + (320)) = 0;
L_156a8:
    s1 = v1 + 72;
    s0 = v1 + 136;
    v0 = 0;
    s2 = -515;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (0));
L_156bc:
    if (a0 == 0) { s1 = s1 + 4; goto L_15708; }
    goto L_156c4;
L_156c4:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (264));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_156dc; }
    goto L_156d4;
L_156d4:
    v0 = -515; goto L_15704;
L_156dc:
    if (v0 == 0) { v0 = -515; goto L_15704; }
    goto L_156e4;
L_156e4:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_156ec;
L_156ec:
    if (v0 == 0) { s1 = s1 + 4; goto L_15708; }
    goto L_156f4;
L_156f4:
    if (v0 == s2) { v0 = -515; goto L_15704; }
    goto L_156fc;
L_156fc:
    ra = *(volatile u32 *)(unsigned long)(sp + (28)); goto L_15720;
L_15704:
    s1 = s1 + 4;
L_15708:
    if (s1 != s0) { a0 = *(volatile u32 *)(unsigned long)(s1 + (0)); goto L_156bc; }
    goto L_15710;
L_15710:
    v1 = -515;
    v1 = v0 ^ v1;
    if (v1 == 0) v0 = 0;
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
L_15720:
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
