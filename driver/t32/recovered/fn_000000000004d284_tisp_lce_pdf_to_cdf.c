/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_bf994[] __asm__("t32_data_bf994");
extern unsigned char ref_t32_data_c9660[] __asm__("t32_data_c9660");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
extern unsigned char ref_t32_data_d6c64[] __asm__("t32_data_d6c64");
extern unsigned char ref_t32_data_d6c65[] __asm__("t32_data_d6c65");
u64 tisp_lce_pdf_to_cdf(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[88] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4d288 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4d2f8 = ((u32)(unsigned long)ref_t32_data_bf994 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d2fc = ((u32)(unsigned long)ref_t32_data_c9660 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d300 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4d2e8 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d334 = ((u32)(unsigned long)ref_t32_data_d6c64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d338 = ((u32)(unsigned long)ref_t32_data_d6c65 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d358 = ((u32)(unsigned long)ref_t32_data_d6c64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d35c = ((u32)(unsigned long)ref_t32_data_d6c65 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[24];
L_4d284:
    sp = sp + -96;
    v0 = hi_4d288;
    a2 = 64;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (92)) = ra;
    s0 = a0;
    s1 = a1;
    a0 = sp + 16;
    v0 = v0 - hi_4d288 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4d2b4;
L_4d2b4:
    a2 = sp + 16;
    a0 = s0;
    a1 = s0 + 64;
    v1 = a2;
    v0 = 0;
L_4d2c8:
    a3 = *(volatile u16 *)(unsigned long)(a0 + (0));
    *(volatile u16 *)(unsigned long)(v1 + (0)) = v0;
    a0 = a0 + 2;
    v0 = v0 + a3;
    v0 = v0 & 0xffff;
    branch = (a0 != a1); v1 = v1 + 2;
    if (branch) goto L_4d2c8;
    goto L_4d2e4;
L_4d2e4:
    branch = (v0 != 0); v1 = hi_4d2e8;
    if (branch) goto L_4d31c;
    goto L_4d2ec;
L_4d2ec:
    ra = *(volatile u32 *)(unsigned long)(sp + (92));
    s1 = *(volatile u32 *)(unsigned long)(sp + (88));
    s0 = *(volatile u32 *)(unsigned long)(sp + (84));
    a1 = hi_4d2f8;
    a0 = hi_4d2fc;
    t9 = hi_4d300;
    a2 = 1065;
    a1 = a1 - hi_4d2f8 + (u32)(unsigned long)ref_t32_data_bf994;
    a0 = a0 - hi_4d2fc + (u32)(unsigned long)ref_t32_data_c9660;
    t9 = t9 - hi_4d300 + ((u32)(unsigned long)ref_printk + (0));
    callee = t9; sp = sp + 96;
    switch (callee) { case 0x4d284: goto L_4d284; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_4d31c:
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_4d2e8 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    a1 = s1;
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a3 = s1 + 8;
    t4 = hi_4d334;
    t3 = hi_4d338;
    v0 = lo;
L_4d340:
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = *(volatile u8 *)(unsigned long)(t4 - hi_4d334 + (u32)(unsigned long)ref_t32_data_d6c64);
    t0 = *(volatile u8 *)(unsigned long)(t3 - hi_4d338 + (u32)(unsigned long)ref_t32_data_d6c65);
    v1 = v1 * v0;
    a1 = a1 + 1;
    a2 = a2 + 2;
    t2 = hi_4d358;
    t1 = hi_4d35c;
    a0 = v1 >> (a0 & 31);
    a0 = a0 & 0x1;
    v1 = v1 >> (t0 & 31);
    v1 = a0 + v1;
    branch = (a1 != a3); *(volatile u8 *)(unsigned long)(a1 + (-1)) = v1;
    if (branch) goto L_4d340;
    goto L_4d378;
L_4d378:
    a2 = 0;
    a3 = 12;
L_4d380:
    v1 = a2 << (0x2 & 31);
    a0 = sp + 16;
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (18));
    a1 = *(volatile u8 *)(unsigned long)(t2 - hi_4d358 + (u32)(unsigned long)ref_t32_data_d6c64);
    a0 = *(volatile u8 *)(unsigned long)(t1 - hi_4d35c + (u32)(unsigned long)ref_t32_data_d6c65);
    v1 = v1 * v0;
    t0 = s1 + a2;
    a2 = a2 + 1;
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    a0 = v1 >> (a0 & 31);
    a0 = a1 + a0;
    branch = (a2 != a3); *(volatile u8 *)(unsigned long)(t0 + (8)) = a0;
    if (branch) goto L_4d380;
    goto L_4d3bc;
L_4d3bc:
    ra = *(volatile u32 *)(unsigned long)(sp + (92));
    s1 = *(volatile u32 *)(unsigned long)(sp + (88));
    s0 = *(volatile u32 *)(unsigned long)(sp + (84));
    sp = sp + 96;
    return ((u64)v1 << 32) | v0;
}
