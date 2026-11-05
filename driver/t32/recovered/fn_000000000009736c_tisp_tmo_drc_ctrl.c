/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_tisp_tmo_tmo_ev_interp[] __asm__("tisp_tmo_tmo_ev_interp");
extern unsigned char ref_t32_data_d89a0[] __asm__("t32_data_d89a0");
extern unsigned char ref_t32_data_c0544[] __asm__("t32_data_c0544");
u64 tisp_tmo_drc_ctrl(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_97370 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_973b4 = ((u32)(unsigned long)ref_tisp_tmo_tmo_ev_interp + 0x8000U) & 0xffff0000U;
    const u32 hi_973d4 = ((u32)(unsigned long)ref_t32_data_d89a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9742c = ((u32)(unsigned long)ref_t32_data_c0544 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_9736c:
    a0 = a0 & 0xff;
    v0 = hi_97370;
    sp = sp + -32;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_97370 + (u32)(unsigned long)ref_t32_data_e35e0;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = 1;
    v0 = *(volatile u16 *)(unsigned long)(s1 + (54));
    branch = (v0 != v1); ra = *(volatile u32 *)(unsigned long)(sp + (28));
    if (branch) goto L_97480;
    goto L_973a4;
L_973a4:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (10042));
    if (v1 != v0) { s1 = *(volatile u32 *)(unsigned long)(sp + (24)); goto L_97484; }
    goto L_973b4;
L_973b4:
    v0 = hi_973b4;
    v0 = v0 - hi_973b4 + (u32)(unsigned long)ref_tisp_tmo_tmo_ev_interp;
    callee = v0; s0 = *(volatile u32 *)(unsigned long)(s1 + (8));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_973c4;
L_973c4:
    v0 = *(volatile u16 *)(unsigned long)(s1 + (56));
    v1 = (u32)v0 < (u32)(128);
    branch = (v1 == 0); v1 = 128;
    if (branch) goto L_97424;
    goto L_973d4;
L_973d4:
    a1 = hi_973d4;
    v0 = s0;
    a1 = a1 - hi_973d4 + (u32)(unsigned long)ref_t32_data_d89a0;
    t0 = s0 + 402;
    a2 = 128;
L_973e8:
    v1 = *(volatile u16 *)(unsigned long)(s1 + (56));
    a3 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a0 = a2 - v1;
    product = (s64)(s32)a3 * (s32)v1; lo = product; hi = product >> 32;
    v0 = v0 + 2;
    a1 = a1 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)t1); lo = product; hi = product >> 32;
    v1 = lo;
    if (v1 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v1 / (s32)a2; hi = (s32)v1 % (s32)a2; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    branch = (t0 != v0); *(volatile u16 *)(unsigned long)(v0 + (-2)) = v1;
    if (branch) goto L_973e8;
    goto L_9741c;
L_9741c:
    ra = *(volatile u32 *)(unsigned long)(sp + (28)); goto L_97480;
L_97424:
    branch = (v0 == v1); ra = *(volatile u32 *)(unsigned long)(sp + (28));
    if (branch) goto L_97480;
    goto L_9742c;
L_9742c:
    a2 = hi_9742c;
    v0 = s0;
    a2 = a2 - hi_9742c + (u32)(unsigned long)ref_t32_data_c0544;
    t0 = s0 + 402;
    t2 = 256;
    a3 = 128;
L_97444:
    a1 = *(volatile u16 *)(unsigned long)(s1 + (56));
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    t1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a0 = t2 - a1;
    a1 = a1 + -128;
    product = (s64)(s32)a1 * (s32)v1; lo = product; hi = product >> 32;
    v0 = v0 + 2;
    a2 = a2 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)t1); lo = product; hi = product >> 32;
    v1 = lo;
    if (v1 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)v1 / (s32)a3; hi = (s32)v1 % (s32)a3; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    branch = (v0 != t0); *(volatile u16 *)(unsigned long)(v0 + (-2)) = v1;
    if (branch) goto L_97444;
    goto L_9747c;
L_9747c:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
L_97480:
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
L_97484:
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
