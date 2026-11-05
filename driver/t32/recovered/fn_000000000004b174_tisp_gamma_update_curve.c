/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1834[] __asm__("t32_data_e1834");
extern unsigned char ref_t32_data_dc274[] __asm__("t32_data_dc274");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_gamma_update_curve(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4b17c = ((u32)(unsigned long)ref_t32_data_e1834 + 0x8000U) & 0xffff0000U;
    const u32 hi_4b1d8 = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    const u32 hi_4b1f0 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4b1d4 = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    const u32 hi_4b298 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4b224 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_4b174:
    sp = sp + -56;
    a0 = a0 & 0xff;
    v0 = hi_4b17c;
    v0 = v0 - hi_4b17c + (u32)(unsigned long)ref_t32_data_e1834;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    s3 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = s3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s5 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = 0x134U << 16;
    v1 = *(volatile u32 *)(unsigned long)(s5 + (0));
    v0 = v0 | 0xff91;
    v0 = (u32)v1 < (u32)(v0);
    branch = (v0 == 0); s4 = hi_4b1d4;
    if (branch) goto L_4b208;
    goto L_4b1d8;
L_4b1d8:
    a0 = hi_4b1d8;
    a0 = a0 - hi_4b1d8 + (u32)(unsigned long)ref_t32_data_dc274;
    s3 = s3 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a2 = 258;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (32));
    v0 = hi_4b1f0;
    v0 = v0 - hi_4b1f0 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4b200;
L_4b200:
    v0 = 1; goto L_4b35c;
L_4b208:
    a3 = a3 << (0x16 & 31);
    a2 = a2 >> (0xa & 31);
    s4 = s4 - hi_4b1d4 + (u32)(unsigned long)ref_t32_data_dc274;
    s2 = a3 | a2;
    s0 = 0;
    s6 = s4 + s3;
    s7 = 266;
    s8 = hi_4b224;
L_4b228:
    a0 = *(volatile u8 *)(unsigned long)(s5 + (90));
    v0 = (u32)s0 < (u32)(a0);
    branch = (v0 == 0); v0 = 0;
    if (branch) goto L_4b35c;
    goto L_4b238;
L_4b238:
    v0 = *(volatile u32 *)(unsigned long)(s6 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (32));
    v0 = s0 * s7;
    a1 = v0 + a3;
    a2 = *(volatile u16 *)(unsigned long)(a1 + (260));
    v1 = *(volatile u16 *)(unsigned long)(a1 + (264));
    v0 = a2 << (0x10 & 31);
    a2 = *(volatile u16 *)(unsigned long)(a1 + (258));
    v1 = v1 << (0x10 & 31);
    a2 = v0 + a2;
    v0 = *(volatile u16 *)(unsigned long)(a1 + (262));
    v1 = v1 + v0;
    v0 = (s32)s2 < (s32)(a2);
    branch = (v0 != 0); ;
    if (branch) goto L_4b288;
    goto L_4b274;
L_4b274:
    v1 = (s32)v1 < (s32)(s2);
    branch = (v1 != 0); a0 = a0 + -1;
    if (branch) goto L_4b338;
    goto L_4b280;
L_4b280:
    a2 = 258; goto L_4b298;
L_4b288:
    branch = (s0 != 0); v1 = v1 - a2;
    if (branch) goto L_4b2b0;
    goto L_4b290;
L_4b290:
    a2 = 258;
    a1 = a3;
L_4b298:
    v0 = hi_4b298;
    v0 = v0 - hi_4b298 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4b2a8;
L_4b2a8:
    v0 = 0; goto L_4b35c;
L_4b2b0:
    branch = (v1 == 0); v0 = 255;
    if (branch) goto L_4b35c;
    goto L_4b2b8;
L_4b2b8:
    s0 = s0 + -1;
    v0 = 133;
    s0 = s0 * v0;
    a2 = s2 - a2;
    t0 = v1 >> (0x1 & 31);
    a0 = s1;
    a3 = s1 + 258;
    s3 = s4 + s3;
    t1 = v1 - a2;
    s0 = s0 << (0x1 & 31);
    t2 = s0 - s1;
    s0 = s0 + 266;
    s0 = s0 - s1;
L_4b2ec:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (32));
    a1 = v0 + t2;
    v0 = v0 + s0;
    v0 = v0 + a0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = a1 + a0;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    product = (s64)(s32)v0 * (s32)a2; lo = product; hi = product >> 32;
    a0 = a0 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)t1); lo = product; hi = product >> 32;
    v0 = lo;
    v0 = v0 + t0;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    branch = (a3 != a0); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_4b2ec;
    goto L_4b330;
L_4b330:
    v0 = 0; goto L_4b35c;
L_4b338:
    if (s0 != a0) { s0 = s0 + 1; goto L_4b354; }
    goto L_4b340;
L_4b340:
    a2 = 258;
    v0 = s8 - hi_4b224 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4b350;
L_4b350:
    s0 = s0 + 1;
L_4b354:
    s0 = s0 & 0xff; goto L_4b228;
L_4b35c:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s8 = *(volatile u32 *)(unsigned long)(sp + (48));
    s7 = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
