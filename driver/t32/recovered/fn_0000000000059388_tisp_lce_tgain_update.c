/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1da8[] __asm__("t32_data_e1da8");
extern unsigned char ref_tisp_lce_tgain_interp_strength[] __asm__("tisp_lce_tgain_interp_strength");
u64 tisp_lce_tgain_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_59388 = ((u32)(unsigned long)ref_t32_data_e1da8 + 0x8000U) & 0xffff0000U;
    const u32 hi_59440 = ((u32)(unsigned long)ref_tisp_lce_tgain_interp_strength + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
    stack[10] = arg4;
    stack[11] = arg5;
L_59388:
    v0 = hi_59388;
    sp = sp + -24;
    a1 = a0 << (0x2 & 31);
    v0 = v0 - hi_59388 + (u32)(unsigned long)ref_t32_data_e1da8;
    v0 = a1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = 0x2U << 16;
    v1 = *(volatile u32 *)(unsigned long)(sp + (40));
    a1 = v0 + a1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (44));
    branch = (a3 != 0); t0 = *(volatile u32 *)(unsigned long)(a1 + (10296));
    if (branch) goto L_593c8;
    goto L_593bc;
L_593bc:
    a3 = (u32)a2 < (u32)(t0);
    branch = (a3 != 0); a1 = t0 - a2;
    if (branch) goto L_593cc;
    goto L_593c8;
L_593c8:
    a1 = a2 - t0;
L_593cc:
    a3 = 0x2U << 16;
    a3 = v0 + a3;
    branch = (t1 != 0); a3 = *(volatile u32 *)(unsigned long)(a3 + (10300));
    if (branch) goto L_593e8;
    goto L_593dc;
L_593dc:
    t0 = (u32)v1 < (u32)(a3);
    branch = (t0 != 0); t1 = a3 - v1;
    if (branch) goto L_593ec;
    goto L_593e8;
L_593e8:
    t1 = v1 - a3;
L_593ec:
    a1 = (s32)a1 >> (0x7 & 31);
    branch = ((s32)a1 <= 0); ;
    if (branch) goto L_59418;
    goto L_593f8;
L_593f8:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (507));
    branch = (a1 != 0); ;
    if (branch) goto L_59418;
    goto L_59408;
L_59408:
    v1 = 0x2U << 16;
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (10296)) = a2; goto L_59440;
L_59418:
    branch = ((s32)t1 <= 0); ra = *(volatile u32 *)(unsigned long)(sp + (20));
    if (branch) goto L_59454;
    goto L_59420;
L_59420:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = *(volatile u8 *)(unsigned long)(a1 + (507));
    a1 = 1;
    if (a2 != a1) { v0 = 0; goto L_59458; }
    goto L_59434;
L_59434:
    a1 = 0x2U << 16;
    v0 = v0 + a1;
    *(volatile u32 *)(unsigned long)(v0 + (10300)) = v1;
L_59440:
    v0 = hi_59440;
    v0 = v0 - hi_59440 + (u32)(unsigned long)ref_tisp_lce_tgain_interp_strength;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_59450;
L_59450:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
L_59454:
    v0 = 0;
L_59458:
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
