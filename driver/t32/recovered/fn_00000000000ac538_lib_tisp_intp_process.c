/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e3b50[] __asm__("t32_data_e3b50");
extern unsigned char ref_t32_data_e3cf0[] __asm__("t32_data_e3cf0");
extern unsigned char ref_t32_data_e3cd8[] __asm__("t32_data_e3cd8");
u64 lib_tisp_intp_process(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_ac548 = ((u32)(unsigned long)ref_t32_data_e3b50 + 0x8000U) & 0xffff0000U;
    const u32 hi_ac544 = ((u32)(unsigned long)ref_t32_data_e3cf0 + 0x8000U) & 0xffff0000U;
    const u32 hi_ac57c = ((u32)(unsigned long)ref_t32_data_e3cd8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_ac538:
    sp = sp + -56;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    s3 = hi_ac544;
    s2 = hi_ac548;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    s4 = a0 & 0xff;
    s2 = s2 - hi_ac548 + (u32)(unsigned long)ref_t32_data_e3b50;
    s3 = s3 - hi_ac544 + (u32)(unsigned long)ref_t32_data_e3cf0;
    s0 = 0;
    s1 = 1;
    s6 = hi_ac57c;
    s5 = 1;
    s7 = 96;
L_ac588:
    v1 = (u32)s0 < (u32)(32);
    branch = (v1 == 0); v0 = s0 & 0xff;
    if (branch) goto L_ac5d0;
    goto L_ac594;
L_ac594:
    v1 = *(volatile u32 *)(unsigned long)(s6 - hi_ac57c + (u32)(unsigned long)ref_t32_data_e3cd8);
    v0 = s5 << (s0 & 31);
    v0 = v0 & v1;
    if (v0 == 0) { s0 = s0 + 1; goto L_ac61c; }
    goto L_ac5a8;
L_ac5a8:
    v1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    if (v1 == 0) { s0 = s0 + 1; goto L_ac61c; }
    goto L_ac5b4;
L_ac5b4:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a0 = s4;
    v0 = v0 + 1;
    callee = v1; *(volatile u32 *)(unsigned long)(s3 + (0)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_ac5c8;
L_ac5c8:
    v1 = v0 ^ 0x1; goto L_ac614;
L_ac5d0:
    v0 = (u32)v0 < (u32)(64);
    branch = (v0 == 0); v1 = s6 - hi_ac57c + (u32)(unsigned long)ref_t32_data_e3cd8;
    if (branch) goto L_ac5e8;
    goto L_ac5dc;
L_ac5dc:
    v0 = s5 << (s0 & 31);
    v1 = *(volatile u32 *)(unsigned long)(v1 + (12)); goto L_ac5f0;
L_ac5e8:
    v1 = *(volatile u32 *)(unsigned long)(v1 + (16));
    v0 = s5 << (s0 & 31);
L_ac5f0:
    v0 = v0 & v1;
    if (v0 == 0) { s0 = s0 + 1; goto L_ac61c; }
    goto L_ac5fc;
L_ac5fc:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    if (v0 == 0) { s0 = s0 + 1; goto L_ac61c; }
    goto L_ac608;
L_ac608:
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_ac610;
L_ac610:
    v1 = v0 ^ 0x1;
L_ac614:
    if (v1 != 0) s1 = v0;
    s0 = s0 + 1;
L_ac61c:
    s2 = s2 + 4;
    branch = (s0 != s7); s3 = s3 + 4;
    if (branch) goto L_ac588;
    goto L_ac628;
L_ac628:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    v0 = s1;
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
