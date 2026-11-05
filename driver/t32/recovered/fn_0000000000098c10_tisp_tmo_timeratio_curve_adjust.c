/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c090c[] __asm__("t32_data_c090c");
extern unsigned char ref_t32_data_c07a4[] __asm__("t32_data_c07a4");
extern unsigned char ref_t32_data_c06f0[] __asm__("t32_data_c06f0");
extern unsigned char ref_t32_data_c06d8[] __asm__("t32_data_c06d8");
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_tisp_tmo_tmo_ev_interp[] __asm__("tisp_tmo_tmo_ev_interp");
extern unsigned char ref_t32_data_d89a0[] __asm__("t32_data_d89a0");
extern unsigned char ref_t32_data_e3501[] __asm__("t32_data_e3501");
u64 tisp_tmo_timeratio_curve_adjust(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_98cc0 = ((u32)(unsigned long)ref_t32_data_c090c + 0x8000U) & 0xffff0000U;
    const u32 hi_98cf8 = ((u32)(unsigned long)ref_t32_data_c07a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_98d30 = ((u32)(unsigned long)ref_t32_data_c06f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_98d44 = ((u32)(unsigned long)ref_t32_data_c06d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_98d74 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_98d98 = ((u32)(unsigned long)ref_tisp_tmo_tmo_ev_interp + 0x8000U) & 0xffff0000U;
    const u32 hi_98da8 = ((u32)(unsigned long)ref_t32_data_d89a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_98e58 = ((u32)(unsigned long)ref_t32_data_e3501 + 0x8000U) & 0xffff0000U;
    const u32 hi_98ed4 = ((u32)(unsigned long)ref_t32_data_e3501 + 0x8000U) & 0xffff0000U;
    const u32 hi_98ee8 = ((u32)(unsigned long)ref_tisp_tmo_tmo_ev_interp + 0x8000U) & 0xffff0000U;
    const u32 hi_98c94 = ((u32)(unsigned long)ref_t32_data_e3501 + 0x8000U) & 0xffff0000U;
    const u32 hi_98ca4 = ((u32)(unsigned long)ref_t32_data_e3501 + 0x8000U) & 0xffff0000U;
    const u32 hi_98d94 = ((u32)(unsigned long)ref_t32_data_d89a0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
    stack[12] = arg4;
    stack[13] = arg5;
    stack[14] = arg6;
    stack[15] = arg7;
L_98c10:
    a1 = a1 & 0xffff;
    sp = sp + -32;
    v0 = (u32)a1 < (u32)(1281);
    a2 = a2 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    a3 = a3 & 0xff;
    v1 = *(volatile u8 *)(unsigned long)(sp + (48));
    s1 = *(volatile u8 *)(unsigned long)(sp + (52));
    t0 = *(volatile u8 *)(unsigned long)(sp + (56));
    branch = (v0 == 0); t2 = *(volatile u16 *)(unsigned long)(sp + (60));
    if (branch) goto L_98c5c;
    goto L_98c48;
L_98c48:
    v0 = 140;
    v0 = a1 * v0;
    v0 = (s32)v0 >> (0x8 & 31);
    v0 = v0 + 2000; goto L_98c7c;
L_98c5c:
    t1 = (u32)a1 < (u32)(2561);
    branch = (t1 == 0); v0 = 2500;
    if (branch) goto L_98c7c;
    goto L_98c68;
L_98c68:
    v0 = 140;
    v0 = a1 * v0;
    t1 = (s32)v0 >> (0x8 & 31);
    v0 = 3400;
    v0 = v0 - t1;
L_98c7c:
    t3 = t0 ^ 0x1;
    t1 = 1;
    branch = (a3 != t1); if (t3 == 0) v0 = t2;
    if (branch) goto L_98ed4;
    goto L_98c8c;
L_98c8c:
    a3 = 3;
    if (a2 != a3) { v0 = hi_98c94; goto L_98ed8; }
    goto L_98c98;
L_98c98:
    v1 = v1 << (0x5 & 31);
    v1 = (u32)v1 < (u32)(a1);
    if (v1 != 0) { v0 = hi_98ca4; goto L_98ed8; }
    goto L_98ca8;
L_98ca8:
    a1 = a1 * v0;
    a1 = a1 >> (0x8 & 31);
    t1 = a1 & 0xffff;
    v0 = (u32)t1 < (u32)(2);
    branch = (v0 != 0); s0 = 0;
    if (branch) goto L_98d74;
    goto L_98cc0;
L_98cc0:
    v0 = hi_98cc0;
    v0 = v0 - hi_98cc0 + (u32)(unsigned long)ref_t32_data_c090c;
    a3 = 0;
    t3 = 178;
L_98cd0:
    if (a3 == t3) { s0 = 0; goto L_98d74; }
    goto L_98cd8;
L_98cd8:
    t2 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v1 = (u32)t2 < (u32)(t1);
    branch = (v1 == 0); a2 = a3 + 1;
    if (branch) goto L_98d68;
    goto L_98ce8;
L_98ce8:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (2));
    t4 = (u32)v1 < (u32)(t1);
    if (t4 != 0) { a3 = a2; goto L_98d6c; }
    goto L_98cf8;
L_98cf8:
    v0 = hi_98cf8;
    v0 = v0 - hi_98cf8 + (u32)(unsigned long)ref_t32_data_c07a4;
    t1 = a3 << (0x1 & 31);
    t1 = t1 + v0;
    s0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    v1 = v1 - t2;
    a2 = a2 << (0x1 & 31);
    product = (s64)(s32)v1 * (s32)s0; lo = product; hi = product >> 32;
    a2 = a2 + v0;
    v0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a1 = a1 & 0xffff;
    a1 = a1 - t2;
    v0 = v0 - s0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)a1); lo = product; hi = product >> 32;
    v0 = hi_98d30;
    v0 = v0 - hi_98d30 + (u32)(unsigned long)ref_t32_data_c06f0;
    a3 = a3 + v0;
    v0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v1 = v0 << (0x1 & 31);
    v0 = hi_98d44;
    v0 = v0 - hi_98d44 + (u32)(unsigned long)ref_t32_data_c06d8;
    v0 = v1 + v0;
    s0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = lo;
    if (a1 == 0x80000000U && s0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s0) { lo = (s32)a1 / (s32)s0; hi = (s32)a1 % (s32)s0; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = lo;
    s0 = a1 & 0xffff; goto L_98d74;
L_98d68:
    a3 = a2;
L_98d6c:
    v0 = v0 + 2; goto L_98cd0;
L_98d74:
    v0 = hi_98d74;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_98d74 + (u32)(unsigned long)ref_t32_data_e35e0;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s2 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = 1;
    branch = (t0 != v0); v1 = hi_98d94;
    if (branch) goto L_98dac;
    goto L_98d98;
L_98d98:
    v0 = hi_98d98;
    v0 = v0 - hi_98d98 + (u32)(unsigned long)ref_tisp_tmo_tmo_ev_interp;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_98da8;
L_98da8:
    v1 = hi_98da8;
L_98dac:
    v1 = v1 - hi_98da8 + (u32)(unsigned long)ref_t32_data_d89a0;
    v0 = s2;
    a2 = s2 + 402;
    a0 = v1;
    a3 = 8191;
L_98dc0:
    if (v0 == a2) { v0 = 1; goto L_98de4; }
    goto L_98dc8;
L_98dc8:
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a1 = (u32)a1 < (u32)(s0);
    if (a1 == 0) { *(volatile u16 *)(unsigned long)(v0 + (0)) = a3; goto L_98dd8; }
    goto L_98dd8;
L_98dd8:
    a0 = a0 + 2;
    v0 = v0 + 2; goto L_98dc0;
L_98de4:
    a1 = 201;
L_98de8:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (2));
    a0 = (u32)a0 < (u32)(s0);
    if (a0 != 0) { v0 = v0 + 1; goto L_98e10; }
    goto L_98df8;
L_98df8:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = (u32)a0 < (u32)(s0);
    if (a0 == 0) { v0 = v0 + 1; goto L_98e10; }
    goto L_98e08;
L_98e08:
    v0 = v0 & 0xffff; goto L_98e20;
L_98e10:
    v0 = v0 & 0xff;
    branch = (v0 != a1); v1 = v1 + 2;
    if (branch) goto L_98de8;
    goto L_98e1c;
L_98e1c:
    v0 = 0;
L_98e20:
    v1 = v0 + -6;
    v1 = (u32)v1 < (u32)(7);
    branch = (v1 == 0); v1 = (u32)v0 < (u32)(6);
    if (branch) goto L_98e3c;
    goto L_98e30;
L_98e30:
    a0 = v0 + -2;
    a0 = (a0 >> 0x1) & ((1U << 0x10) - 1); goto L_98e48;
L_98e3c:
    a0 = 10;
    a1 = 1;
    if (v1 != 0) a0 = a1;
L_98e48:
    v1 = (u32)v0 < (u32)(3);
    branch = (v1 == 0); s1 = s1 & 0xffff;
    if (branch) goto L_98e64;
    goto L_98e54;
L_98e54:
    v1 = 1;
    v0 = hi_98e58;
    *(volatile u8 *)(unsigned long)(v0 - hi_98e58 + (u32)(unsigned long)ref_t32_data_e3501) = v1; goto L_98efc;
L_98e64:
    v1 = a0;
    a0 = (u32)s1 < (u32)(a0);
    if (a0 != 0) { v1 = s1; goto L_98e74; }
    goto L_98e74;
L_98e74:
    v1 = v1 & 0xffff;
    a1 = v0 - v1;
    a1 = a1 << (0x1 & 31);
    a1 = a1 + -2;
    a1 = s2 + a1;
    a0 = 1;
    v1 = v1 + 1;
    t2 = 8191;
L_98e94:
    a2 = (s32)a0 < (s32)(v1);
    branch = (a2 == 0); a2 = v1 - a0;
    if (branch) goto L_98e54;
    goto L_98ea0;
L_98ea0:
    t1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    t0 = v0 - a0;
    a3 = t2 - t1;
    a2 = a3 * a2;
    t0 = t0 << (0x1 & 31);
    t0 = s2 + t0;
    a0 = a0 + 1;
    a0 = a0 & 0xff;
    if (a2 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a2 / (s32)v1; hi = (s32)a2 % (s32)v1; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    a2 = t1 + a2;
    *(volatile u16 *)(unsigned long)(t0 + (0)) = a2; goto L_98e94;
L_98ed4:
    v0 = hi_98ed4;
L_98ed8:
    a1 = *(volatile u8 *)(unsigned long)(v0 - hi_98ed4 + (u32)(unsigned long)ref_t32_data_e3501);
    v1 = 1;
    branch = (a1 != v1); s0 = v0;
    if (branch) goto L_98ef8;
    goto L_98ee8;
L_98ee8:
    v0 = hi_98ee8;
    v0 = v0 - hi_98ee8 + (u32)(unsigned long)ref_tisp_tmo_tmo_ev_interp;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_98ef8;
L_98ef8:
    *(volatile u8 *)(unsigned long)(s0 - hi_98ed4 + (u32)(unsigned long)ref_t32_data_e3501) = 0;
L_98efc:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
