/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
u64 tisp_ae_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[66] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2ac04 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[2];
L_2ac04:
    v0 = hi_2ac04;
    sp = sp + -8;
    v0 = v0 - hi_2ac04 + (u32)(unsigned long)ref_t32_data_e15a8;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (0)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t3 = 0;
    t2 = 0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    t0 = *(volatile u16 *)(unsigned long)(v1 + (2774));
    t4 = *(volatile u16 *)(unsigned long)(v1 + (2770));
    v1 = *(volatile u32 *)(unsigned long)(a1 + (12));
    s0 = t0 << (0x4 & 31);
    t0 = t0 << (0x2 & 31);
    v1 = (v1 >> 0x1c) & ((1U << 0x2) - 1);
    *(volatile u8 *)(unsigned long)(a0 + (8606)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    t5 = v1 + 2048;
    t6 = v1 + 2948;
    t7 = v1 + 3848;
    t8 = v1 + 4748;
    t9 = v1 + 5648;
    v1 = v1 + 6548;
L_2ac6c:
    v0 = (u32)t2 < (u32)(t4);
    branch = (v0 == 0); v0 = a1;
    if (branch) goto L_2ad30;
    goto L_2ac78;
L_2ac78:
    t1 = 0;
L_2ac7c:
    branch = (t1 == t0); v0 = v0 + 16;
    if (branch) goto L_2ad20;
    goto L_2ac84;
L_2ac84:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-8));
    a0 = t3 + t1;
    a3 = t5 + a0;
    a2 = (a2 >> 0x0) & ((1U << 0x16) - 1);
    *(volatile u32 *)(unsigned long)(a3 + (0)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-4));
    s1 = t6 + a0;
    t1 = t1 + 4;
    a2 = a2 & 0xfff;
    a3 = a2 << (0xa & 31);
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-8));
    a2 = a2 >> (0x16 & 31);
    a2 = a3 | a2;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s1 = t7 + a0;
    a2 = a2 & 0x3;
    a3 = a2 << (0x14 & 31);
    a2 = *(volatile u32 *)(unsigned long)(v0 + (-4));
    a2 = a2 >> (0xc & 31);
    a2 = a3 | a2;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = t8 + a0;
    a2 = (a2 >> 0x2) & ((1U << 0xe) - 1);
    *(volatile u32 *)(unsigned long)(a3 + (0)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = t9 + a0;
    a0 = v1 + a0;
    a2 = (a2 >> 0x10) & ((1U << 0xe) - 1);
    *(volatile u32 *)(unsigned long)(a3 + (0)) = a2;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a2 = (a2 >> 0x0) & ((1U << 0x14) - 1);
    a3 = a2 << (0x2 & 31);
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a2 >> (0x1e & 31);
    a2 = a3 | a2;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a2; goto L_2ac7c;
L_2ad20:
    t2 = t2 + 1;
    a1 = a1 + s0;
    t3 = t3 + 60; goto L_2ac6c;
L_2ad30:
    s1 = *(volatile u32 *)(unsigned long)(sp + (4));
    s0 = *(volatile u32 *)(unsigned long)(sp + (0));
    sp = sp + 8;
    return ((u64)v1 << 32) | v0;
}
