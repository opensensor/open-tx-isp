/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9310[] __asm__("t32_data_d9310");
extern unsigned char ref_t32_data_d9318[] __asm__("t32_data_d9318");
extern unsigned char ref_t32_data_d9304[] __asm__("t32_data_d9304");
extern unsigned char ref_t32_data_d930c[] __asm__("t32_data_d930c");
extern unsigned char ref_private_complete[] __asm__("private_complete");
u64 vic_mdma_irq_function(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3edc = ((u32)(unsigned long)ref_t32_data_d9310 + 0x8000U) & 0xffff0000U;
    const u32 hi_3eec = ((u32)(unsigned long)ref_t32_data_d9318 + 0x8000U) & 0xffff0000U;
    const u32 hi_3f14 = ((u32)(unsigned long)ref_t32_data_d9304 + 0x8000U) & 0xffff0000U;
    const u32 hi_3f3c = ((u32)(unsigned long)ref_t32_data_d930c + 0x8000U) & 0xffff0000U;
    const u32 hi_3f48 = ((u32)(unsigned long)ref_private_complete + 0x8000U) & 0xffff0000U;
    const u32 hi_3ee8 = ((u32)(unsigned long)ref_t32_data_d930c + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_3ed8:
    branch = (a1 != 0); a3 = hi_3edc;
    if (branch) goto L_3f30;
    goto L_3ee0;
L_3ee0:
    a1 = *(volatile u32 *)(unsigned long)(a3 - hi_3edc + (u32)(unsigned long)ref_t32_data_d9310);
    branch = (a1 == 0); v0 = hi_3ee8;
    if (branch) goto L_3f40;
    goto L_3eec;
L_3eec:
    t0 = hi_3eec;
    a2 = *(volatile u32 *)(unsigned long)(t0 - hi_3eec + (u32)(unsigned long)ref_t32_data_d9318);
    a1 = a1 + -1;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (288));
    a2 = a2 + 1;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (292));
    *(volatile u32 *)(unsigned long)(t0 - hi_3eec + (u32)(unsigned long)ref_t32_data_d9318) = a2;
    branch = (a1 == 0); *(volatile u32 *)(unsigned long)(a3 - hi_3edc + (u32)(unsigned long)ref_t32_data_d9310) = a1;
    if (branch) goto L_3f3c;
    goto L_3f10;
L_3f10:
    v1 = v1 * v0;
    v0 = hi_3f14;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_3f14 + (u32)(unsigned long)ref_t32_data_d9304);
    v1 = v1 << (0x1 & 31);
    a1 = v1 * a2;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (244));
    v0 = a1 + v0;
    *(volatile u32 *)(unsigned long)(v1 + (800)) = v0;
L_3f30:
    v0 = *(volatile u32 *)(unsigned long)(a3 - hi_3edc + (u32)(unsigned long)ref_t32_data_d9310);
    branch = (v0 != 0); ;
    if (branch) goto L_3f58;
    goto L_3f3c;
L_3f3c:
    v0 = hi_3f3c;
L_3f40:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_3f3c + (u32)(unsigned long)ref_t32_data_d930c);
    branch = (v0 != 0); t9 = hi_3f48;
    if (branch) goto L_3f58;
    goto L_3f4c;
L_3f4c:
    t9 = t9 - hi_3f48 + (u32)(unsigned long)ref_private_complete;
    callee = t9; a0 = a0 + 880;
    switch (callee) { case 0x3ed8: goto L_3ed8; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_3f58:
    ;
    return ((u64)v1 << 32) | v0;
}
