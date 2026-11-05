/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_t32_data_c029c[] __asm__("t32_data_c029c");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_tmo_tmo_dark_protect(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[176] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_96d5c = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_96d88 = ((u32)(unsigned long)ref_t32_data_c029c + 0x8000U) & 0xffff0000U;
    const u32 hi_96da0 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[112];
L_96d5c:
    v0 = hi_96d5c;
    sp = sp + -448;
    v0 = v0 - hi_96d5c + (u32)(unsigned long)ref_t32_data_e35e0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (444)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (440)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (436)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (432)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (428)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = hi_96d88;
    a2 = 402;
    s3 = *(volatile u32 *)(unsigned long)(v0 + (12));
    s2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = hi_96da0;
    a1 = a1 - hi_96d88 + (u32)(unsigned long)ref_t32_data_c029c;
    v0 = v0 - hi_96da0 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_96db4;
L_96db4:
    v0 = *(volatile u16 *)(unsigned long)(s3 + (0));
    a0 = *(volatile u16 *)(unsigned long)(s3 + (2));
    t2 = *(volatile u8 *)(unsigned long)(s2 + (2842));
    t1 = *(volatile u16 *)(unsigned long)(s2 + (2844));
    a0 = v0 * a0;
    v0 = 4;
    a1 = *(volatile u16 *)(unsigned long)(s2 + (2846));
    a3 = *(volatile u16 *)(unsigned long)(s2 + (2848));
    t0 = s0 + 30000;
    t3 = s0 + 32048;
    a2 = 0;
    t4 = 10000;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    v1 = a0 >> (0x8 & 31);
L_96df0:
    v0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t0 = t0 + 4;
    a2 = a2 + v0;
    v0 = (u32)a2 < (u32)(a0);
    if (v0 == 0) a2 = a0;
    v0 = a2 << (0x8 & 31);
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 * t4;
    v0 = v0 >> (0x10 & 31);
    branch = (t0 != t3); *(volatile u32 *)(unsigned long)(t0 + (2044)) = v0;
    if (branch) goto L_96df0;
    goto L_96e20;
L_96e20:
    v0 = 1;
    branch = (t2 != v0); ra = *(volatile u32 *)(unsigned long)(sp + (444));
    if (branch) goto L_96ec4;
    goto L_96e2c;
L_96e2c:
    v0 = a3 + 8012;
    v0 = v0 << (0x2 & 31);
    s0 = s0 + v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (0));
    v1 = (u32)v0 < (u32)(t1);
    branch = (v1 != 0); s3 = *(volatile u32 *)(unsigned long)(sp + (440));
    if (branch) goto L_96ec8;
    goto L_96e48;
L_96e48:
    v1 = (u32)a1 < (u32)(v0);
    branch = (v1 == 0); t0 = s1 + 402;
    if (branch) goto L_96e78;
    goto L_96e54;
L_96e54:
    v0 = sp + 16;
    v1 = s1;
L_96e5c:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v1 = v1 + 2;
    v0 = v0 + 2;
    branch = (t0 != v1); *(volatile u16 *)(unsigned long)(v1 + (-2)) = a0;
    if (branch) goto L_96e5c;
    goto L_96e70;
L_96e70:
    ra = *(volatile u32 *)(unsigned long)(sp + (444)); goto L_96ec4;
L_96e78:
    v0 = v0 - t1;
    a1 = a1 - t1;
    v1 = s1;
    a0 = sp + 16;
    a2 = (int16_t)v0;
    a1 = (int16_t)a1;
L_96e90:
    a3 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = v1 + 2;
    a0 = a0 + 2;
    v0 = a3 - v0;
    v0 = (int16_t)v0;
    v0 = v0 * a2;
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = a3 - v0;
    branch = (t0 != v1); *(volatile u16 *)(unsigned long)(v1 + (-2)) = v0;
    if (branch) goto L_96e90;
    goto L_96ec0;
L_96ec0:
    ra = *(volatile u32 *)(unsigned long)(sp + (444));
L_96ec4:
    s3 = *(volatile u32 *)(unsigned long)(sp + (440));
L_96ec8:
    s2 = *(volatile u32 *)(unsigned long)(sp + (436));
    s1 = *(volatile u32 *)(unsigned long)(sp + (432));
    s0 = *(volatile u32 *)(unsigned long)(sp + (428));
    sp = sp + 448;
    return ((u64)v1 << 32) | v0;
}
