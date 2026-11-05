/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_d8724[] __asm__("t32_data_d8724");
extern unsigned char ref_tisp_tmo_adr_5x5_init[] __asm__("tisp_tmo_adr_5x5_init");
u64 tisp_tmo_adr_base_pars(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[100] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_94fe4 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_95010 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_9510c = ((u32)(unsigned long)ref_t32_data_d8724 + 0x8000U) & 0xffff0000U;
    const u32 hi_95194 = ((u32)(unsigned long)ref_tisp_tmo_adr_5x5_init + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[36];
L_94fcc:
    sp = sp + -144;
    *(volatile u32 *)(unsigned long)(sp + (112)) = s0;
    s0 = 6;
    if (a0 == 0x80000000U && s0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s0) { lo = (s32)a0 / (s32)s0; hi = (s32)a0 % (s32)s0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    *(volatile u32 *)(unsigned long)(sp + (116)) = s1;
    s1 = 4;
    v0 = hi_94fe4;
    v1 = a2 << (0x2 & 31);
    v0 = v0 - hi_94fe4 + (u32)(unsigned long)ref_t32_data_e35e0;
    *(volatile u32 *)(unsigned long)(sp + (140)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (136)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (120)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (132)) = s5;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = hi_95010;
    s6 = a3 - hi_95010 + ((u32)(unsigned long)ref_memcpy + (0));
    s5 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s3 = a0;
    *(volatile u16 *)(unsigned long)(sp + (104)) = a1;
    *(volatile u16 *)(unsigned long)(sp + (92)) = a0;
    s4 = a1;
    a0 = s5 + 320;
    s2 = a2;
    a2 = 10;
    *(volatile u16 *)(unsigned long)(sp + (96)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (80)) = 0;
    s0 = lo;
    if (a1 == 0x80000000U && s1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s1) { lo = (s32)a1 / (s32)s1; hi = (s32)a1 % (s32)s1; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = sp + 96;
    s1 = lo;
    v0 = s1 & 0x1;
    s1 = s1 - v0;
    v0 = s0 & 0x1;
    s0 = s0 - v0;
    v0 = s1 & 0xffff;
    v1 = v0 << (0x1 & 31);
    v1 = v1 & 0xffff;
    v0 = v0 + v1;
    *(volatile u16 *)(unsigned long)(sp + (100)) = v1;
    v1 = s0 & 0xffff;
    *(volatile u16 *)(unsigned long)(sp + (102)) = v0;
    v0 = v1 << (0x1 & 31);
    v0 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(sp + (84)) = v0;
    v0 = v1 + v0;
    v0 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(sp + (86)) = v0;
    v0 = v1 + v0;
    v0 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(sp + (88)) = v0;
    v0 = v1 + v0;
    *(volatile u16 *)(unsigned long)(sp + (98)) = s1;
    *(volatile u16 *)(unsigned long)(sp + (82)) = s0;
    callee = s6; *(volatile u16 *)(unsigned long)(sp + (90)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_950b4;
L_950b4:
    a2 = 14;
    a1 = sp + 80;
    callee = s6; a0 = s5 + 330;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_950c4;
L_950c4:
    s0 = s0 + 1;
    v1 = 2;
    if (s0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)s0 / (s32)v1; hi = (s32)s0 % (s32)v1; } else { lo = (s32)s0 < 0 ? 1 : ~0U; hi = s0; }
    s1 = s1 + 1;
    s0 = lo;
    if (s1 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)s1 / (s32)v1; hi = (s32)s1 % (s32)v1; } else { lo = (s32)s1 < 0 ? 1 : ~0U; hi = s1; }
    s1 = lo;
    v0 = (s32)s1 < (s32)(s0);
    branch = (v0 == 0); a3 = s6;
    if (branch) goto L_950fc;
    goto L_950ec;
L_950ec:
    v0 = s1 << (0x1 & 31);
    s1 = v0 + s1;
    v0 = s1 + 1; goto L_95108;
L_950fc:
    v0 = s0 << (0x1 & 31);
    s0 = v0 + s0;
    v0 = s0 + 1;
L_95108:
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a2 = hi_9510c;
    a2 = a2 - hi_9510c + (u32)(unsigned long)ref_t32_data_d8724;
    t1 = 0;
    t5 = 0x2U << 16;
    t3 = 62;
    v1 = lo;
    product = (s64)(s32)v1 * (s32)v1; lo = product; hi = product >> 32;
    v0 = lo;
    v1 = hi;
L_95130:
    t2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    a0 = sp + 16;
    t4 = a0 + t1;
    product = (s64)(s32)v1 * (s32)t2; lo = product; hi = product >> 32;
    a1 = (s32)t2 >> (0x1f & 31);
    t1 = t1 + 2;
    a2 = a2 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)v0); lo = product; hi = product >> 32;
    t0 = lo;
    product = (u64)(u32)t2 * (u32)v0; lo = product; hi = product >> 32;
    a0 = lo;
    a1 = hi;
    t0 = t0 + a1;
    a1 = a0 + t5;
    a0 = (u32)a1 < (u32)(a0);
    a0 = a0 + t0;
    a0 = a0 << (0xe & 31);
    a1 = a1 >> (0x12 & 31);
    a1 = a0 | a1;
    branch = (t1 != t3); *(volatile u16 *)(unsigned long)(t4 + (0)) = a1;
    if (branch) goto L_95130;
    goto L_95184;
L_95184:
    a1 = sp + 16;
    a0 = s5 + 574;
    callee = a3; a2 = 62;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_95194;
L_95194:
    v0 = hi_95194;
    a3 = s2;
    a2 = sp + 16;
    a1 = s4;
    v0 = v0 - hi_95194 + (u32)(unsigned long)ref_tisp_tmo_adr_5x5_init;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_951b0;
L_951b0:
    ra = *(volatile u32 *)(unsigned long)(sp + (140));
    s6 = *(volatile u32 *)(unsigned long)(sp + (136));
    s5 = *(volatile u32 *)(unsigned long)(sp + (132));
    s4 = *(volatile u32 *)(unsigned long)(sp + (128));
    s3 = *(volatile u32 *)(unsigned long)(sp + (124));
    s2 = *(volatile u32 *)(unsigned long)(sp + (120));
    s1 = *(volatile u32 *)(unsigned long)(sp + (116));
    s0 = *(volatile u32 *)(unsigned long)(sp + (112));
    sp = sp + 144;
    return ((u64)v1 << 32) | v0;
}
