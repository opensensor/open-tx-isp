/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_da784[] __asm__("t32_data_da784");
extern unsigned char ref_private_complete[] __asm__("private_complete");
u64 tx_isp_notify(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_16074 = ((u32)(unsigned long)ref_t32_data_da784 + 0x8000U) & 0xffff0000U;
    const u32 hi_160bc = ((u32)(unsigned long)ref_private_complete + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_16074:
    v0 = hi_16074;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_16074 + (u32)(unsigned long)ref_t32_data_da784);
    v0 = 0x100U << 16;
    sp = sp + -56;
    v0 = v0 + 17;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    branch = (a1 != v0); *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    if (branch) goto L_160d8;
    goto L_160b0;
L_160b0:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (68));
    if (v0 == 0) { v0 = 0; goto L_161a0; }
    goto L_160bc;
L_160bc:
    v0 = hi_160bc;
    *(volatile u32 *)(unsigned long)(a0 + (68)) = 0;
    v0 = v0 - hi_160bc + (u32)(unsigned long)ref_private_complete;
    callee = v0; a0 = a0 + 72;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_160d0;
L_160d0:
    v0 = 0; goto L_161a0;
L_160d8:
    s1 = 0xff00U << 16;
    s7 = a1;
    s3 = a2;
    s2 = a0 + 84;
    s0 = a0 + 148;
    v0 = 0;
    s1 = a1 & s1;
    s4 = 0x100U << 16;
    s5 = -515;
    s6 = 0x200U << 16;
    a0 = *(volatile u32 *)(unsigned long)(s2 + (0));
L_16104:
    if (a0 == 0) { s2 = s2 + 4; goto L_16188; }
    goto L_1610c;
L_1610c:
    branch = (s1 != s4); ;
    if (branch) goto L_1612c;
    goto L_16114;
L_16114:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (264));
L_16118:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(v0 + (32)); goto L_1615c; }
    goto L_16124;
L_16124:
    v0 = -515; goto L_16184;
L_1612c:
    branch = (s1 != s6); v0 = 0x500U << 16;
    if (branch) goto L_1614c;
    goto L_16134;
L_16134:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (264));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    if (v0 == 0) { v0 = -515; goto L_16184; }
    goto L_16144;
L_16144:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8)); goto L_1615c;
L_1614c:
    if (s1 == v0) { v0 = *(volatile u32 *)(unsigned long)(a0 + (264)); goto L_16118; }
    goto L_16154;
L_16154:
    v0 = 0; goto L_16184;
L_1615c:
    branch = (v0 == 0); a2 = s3;
    if (branch) goto L_16124;
    goto L_16164;
L_16164:
    callee = v0; a1 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1616c;
L_1616c:
    if (v0 == 0) { v0 = 0; goto L_16184; }
    goto L_16174;
L_16174:
    if (v0 == s5) { v0 = -515; goto L_16184; }
    goto L_1617c;
L_1617c:
    ra = *(volatile u32 *)(unsigned long)(sp + (52)); goto L_161a4;
L_16184:
    s2 = s2 + 4;
L_16188:
    if (s2 != s0) { a0 = *(volatile u32 *)(unsigned long)(s2 + (0)); goto L_16104; }
    goto L_16190;
L_16190:
    v1 = -515;
    branch = (v0 != v1); ra = *(volatile u32 *)(unsigned long)(sp + (52));
    if (branch) goto L_161a4;
    goto L_1619c;
L_1619c:
    v0 = 0;
L_161a0:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
L_161a4:
    s7 = *(volatile u32 *)(unsigned long)(sp + (48));
    s6 = *(volatile u32 *)(unsigned long)(sp + (44));
    s5 = *(volatile u32 *)(unsigned long)(sp + (40));
    s4 = *(volatile u32 *)(unsigned long)(sp + (36));
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
