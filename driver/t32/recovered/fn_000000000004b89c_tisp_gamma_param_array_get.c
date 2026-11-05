/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1834[] __asm__("t32_data_e1834");
extern unsigned char ref_t32_data_e1820[] __asm__("t32_data_e1820");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_dc274[] __asm__("t32_data_dc274");
u64 tisp_gamma_param_array_get(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4b8a0 = ((u32)(unsigned long)ref_t32_data_e1834 + 0x8000U) & 0xffff0000U;
    const u32 hi_4b8e0 = ((u32)(unsigned long)ref_t32_data_e1820 + 0x8000U) & 0xffff0000U;
    const u32 hi_4b8ec = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4b908 = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_4b89c:
    sp = sp + -56;
    v0 = hi_4b8a0;
    v0 = v0 - hi_4b8a0 + (u32)(unsigned long)ref_t32_data_e1834;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    s6 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (44)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = s6 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s5 = a1;
    s2 = hi_4b8e0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s4 = *(volatile u32 *)(unsigned long)(s2 - hi_4b8e0 + (u32)(unsigned long)ref_t32_data_e1820);
    s1 = hi_4b8ec;
    s3 = a2;
    a0 = s5;
    a2 = 92;
    s1 = s1 - hi_4b8ec + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s1; s0 = *(volatile u8 *)(unsigned long)(a1 + (90));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4b908;
L_4b908:
    v0 = hi_4b908;
    s4 = s4 >> (0x1 & 31);
    v0 = v0 - hi_4b908 + (u32)(unsigned long)ref_t32_data_dc274;
    s4 = s4 << (0x1 & 31);
    v1 = 0;
    s7 = 0;
    s6 = v0 + s6;
L_4b924:
    v0 = s7 & 0xff;
    v0 = (u32)v0 < (u32)(s0);
    branch = (v0 == 0); s8 = v1 + s4;
    if (branch) goto L_4b960;
    goto L_4b934;
L_4b934:
    v0 = *(volatile u32 *)(unsigned long)(s6 + (0));
    a2 = *(volatile u32 *)(unsigned long)(s2 - hi_4b8e0 + (u32)(unsigned long)ref_t32_data_e1820);
    a1 = *(volatile u32 *)(unsigned long)(v0 + (32));
    v0 = a2 * s7;
    s7 = s7 + 1;
    a1 = a1 + v1;
    a0 = v0 + s5;
    callee = s1; a0 = a0 + 92;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4b958;
L_4b958:
    v1 = s8; goto L_4b924;
L_4b960:
    v0 = *(volatile u32 *)(unsigned long)(s2 - hi_4b8e0 + (u32)(unsigned long)ref_t32_data_e1820);
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s8 = *(volatile u32 *)(unsigned long)(sp + (48));
    s0 = s0 * v0;
    s7 = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = 0;
    s0 = s0 + 92;
    *(volatile u32 *)(unsigned long)(s3 + (0)) = s0;
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
