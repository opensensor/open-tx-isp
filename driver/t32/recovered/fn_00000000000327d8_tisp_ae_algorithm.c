/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e15d8[] __asm__("t32_data_e15d8");
extern unsigned char ref_tisp_ae_weight_mean[] __asm__("tisp_ae_weight_mean");
extern unsigned char ref_tisp_ae_tune[] __asm__("tisp_ae_tune");
u64 tisp_ae_algorithm(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_327dc = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_32820 = ((u32)(unsigned long)ref_t32_data_e15d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_32860 = ((u32)(unsigned long)ref_tisp_ae_weight_mean + 0x8000U) & 0xffff0000U;
    const u32 hi_32880 = ((u32)(unsigned long)ref_tisp_ae_tune + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_327d8:
    sp = sp + -64;
    v0 = hi_327dc;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s0;
    s0 = a0 & 0xff;
    v1 = s0 << (0x2 & 31);
    v0 = v0 - hi_327dc + (u32)(unsigned long)ref_t32_data_e15a8;
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s1;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (40)) = 0;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = 0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(a0 + (1684));
    a0 = hi_32820;
    a0 = a0 - hi_32820 + (u32)(unsigned long)ref_t32_data_e15d8;
    v1 = v1 + a0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a2 + (8568));
    *(volatile u32 *)(unsigned long)(v1 + (10852)) = a0;
    v1 = 1;
    if (a1 != v1) { v0 = 1; goto L_32854; }
    goto L_32844;
L_32844:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u16 *)(unsigned long)(v0 + (2940));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (2942)); goto L_32858;
L_32854:
    a3 = 1;
L_32858:
    s1 = sp + 32;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_32860;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    a2 = sp + 24;
    a1 = sp + 40;
    v0 = v0 - hi_32860 + (u32)(unsigned long)ref_tisp_ae_weight_mean;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3287c;
L_3287c:
    a1 = *(volatile u32 *)(unsigned long)(sp + (40));
    v0 = hi_32880;
    a3 = s1;
    a2 = sp + 24;
    v0 = v0 - hi_32880 + (u32)(unsigned long)ref_tisp_ae_tune;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_32898;
L_32898:
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s1 = *(volatile u32 *)(unsigned long)(sp + (56));
    s0 = *(volatile u32 *)(unsigned long)(sp + (52));
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
}
