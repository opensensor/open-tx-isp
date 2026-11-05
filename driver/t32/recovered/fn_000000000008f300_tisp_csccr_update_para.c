/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e3120[] __asm__("t32_data_e3120");
extern unsigned char ref_t32_data_ca2e0[] __asm__("t32_data_ca2e0");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
u64 tisp_csccr_update_para(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8f308 = ((u32)(unsigned long)ref_t32_data_e3120 + 0x8000U) & 0xffff0000U;
    const u32 hi_8f390 = ((u32)(unsigned long)ref_t32_data_ca2e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8f394 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_8f380 = ((u32)(unsigned long)ref_t32_data_ca2e0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_8f300:
    a0 = a0 & 0xff;
    v0 = a0 << (0x2 & 31);
    a0 = hi_8f308;
    sp = sp + -24;
    a0 = a0 - hi_8f308 + (u32)(unsigned long)ref_t32_data_e3120;
    a0 = v0 + a0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    a3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = 1;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (13));
    if (a0 == v1) { t4 = *(volatile u8 *)(unsigned long)(v0 + (5)); goto L_8f34c; }
    goto L_8f334;
L_8f334:
    branch = (a0 != 0); v1 = *(volatile u8 *)(unsigned long)(v0 + (14));
    if (branch) goto L_8f44c;
    goto L_8f33c;
L_8f33c:
    v1 = (u32)v1 < (u32)(2);
    if (v1 == 0) { v0 = *(volatile u32 *)(unsigned long)(a3 + (8)); goto L_8f450; }
    goto L_8f348;
L_8f348:
    t4 = *(volatile u8 *)(unsigned long)(v0 + (5));
L_8f34c:
    v1 = *(volatile u8 *)(unsigned long)(v0 + (6));
    t3 = *(volatile u8 *)(unsigned long)(v0 + (7));
    a1 = *(volatile u8 *)(unsigned long)(v0 + (8));
    t5 = *(volatile u8 *)(unsigned long)(v0 + (9));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (10));
    t1 = *(volatile u8 *)(unsigned long)(v0 + (11));
    t0 = *(volatile u8 *)(unsigned long)(v0 + (12));
L_8f368:
    a2 = (s32)a1 < (s32)(t3);
    v0 = (s32)v1 < (s32)(t4);
    v0 = v0 | a2;
    a2 = (s32)a0 < (s32)(t5);
    v0 = a2 | v0;
    if (v0 != 0) { a1 = hi_8f380; goto L_8f394; }
    goto L_8f384;
L_8f384:
    v0 = (s32)t0 < (s32)(t1);
    if (v0 == 0) { v0 = v1 - t4; goto L_8f3b0; }
    goto L_8f390;
L_8f390:
    a1 = hi_8f390;
L_8f394:
    v0 = hi_8f394;
    a1 = a1 - hi_8f390 + (u32)(unsigned long)ref_t32_data_ca2e0;
    v0 = v0 - hi_8f394 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8f3a8;
L_8f3a8:
    v0 = -1; goto L_8f474;
L_8f3b0:
    a2 = 2;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t2 = a1 - t3;
    a1 = t2 << (0xa & 31);
    v1 = lo;
    v1 = a1 + v1;
    a1 = t0 - t1;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = a0 - t5;
    a1 = a1 << (0xa & 31);
    t1 = t1 + -128;
    t0 = t0 + -128;
    v0 = lo;
    if (v1 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v1 / (s32)a2; hi = (s32)v1 % (s32)a2; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a2 = lo;
    a0 = a1 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a3 + (4));
    if (a0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a0 / (s32)v1; hi = (s32)a0 % (s32)v1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = 2047;
    v1 = (s32)v0 < (s32)(2048);
    if (v1 == 0) v0 = a1;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (2)) = t4;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (4)) = t2;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (6)) = t3;
    v1 = *(volatile u32 *)(unsigned long)(a3 + (4));
    a0 = lo;
    v0 = (s32)a0 < (s32)(2048);
    if (v0 == 0) a0 = a1;
    *(volatile u16 *)(unsigned long)(v1 + (8)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (10)) = t1;
    v0 = *(volatile u32 *)(unsigned long)(a3 + (4));
    *(volatile u16 *)(unsigned long)(v0 + (12)) = t0;
    v0 = 0; goto L_8f474;
L_8f44c:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (8));
L_8f450:
    t4 = *(volatile u8 *)(unsigned long)(v0 + (4));
    v1 = *(volatile u8 *)(unsigned long)(v0 + (5));
    t3 = *(volatile u8 *)(unsigned long)(v0 + (6));
    a1 = *(volatile u8 *)(unsigned long)(v0 + (7));
    t5 = *(volatile u8 *)(unsigned long)(v0 + (8));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (9));
    t1 = *(volatile u8 *)(unsigned long)(v0 + (10));
    t0 = *(volatile u8 *)(unsigned long)(v0 + (11)); goto L_8f368;
L_8f474:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
