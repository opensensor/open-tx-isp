/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_tmo_adr_ispint_adr_16(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_9587c:
    v0 = a3 << (0x1 & 31);
    v0 = a2 + v0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (-2));
    a0 = (int16_t)a0;
    t2 = a1;
    v1 = 0;
L_95894:
    t0 = (s32)v1 < (s32)(a3);
    branch = (t0 == 0); t2 = t2 + 2;
    if (branch) goto L_9591c;
    goto L_958a0;
L_958a0:
    t0 = *(volatile s16 *)(unsigned long)(t2 + (-2));
    t3 = (s32)t0 < (s32)(a0);
    branch = (t3 != 0); t1 = v1 << (0x1 & 31);
    if (branch) goto L_95914;
    goto L_958b0;
L_958b0:
    branch = (v1 != 0); v1 = v1 << (0x1 & 31);
    if (branch) goto L_958c0;
    goto L_958b8;
L_958b8:
    v0 = *(volatile s16 *)(unsigned long)(a2 + (0));
    return ((u64)v1 << 32) | v0;
L_958c0:
    v1 = v1 + -2;
    a1 = a1 + v1;
    t2 = *(volatile s16 *)(unsigned long)(a1 + (0));
    branch = (t0 != t2); a3 = a2 + t1;
    if (branch) goto L_958dc;
    goto L_958d4;
L_958d4:
    v0 = *(volatile s16 *)(unsigned long)(a3 + (0));
    return ((u64)v1 << 32) | v0;
L_958dc:
    v1 = a2 + v1;
    a2 = *(volatile s16 *)(unsigned long)(v1 + (0));
    v1 = *(volatile s16 *)(unsigned long)(a3 + (0));
    a0 = a0 - t2;
    a1 = t0 - t2;
    v1 = v1 - a2;
    a3 = v1 * a0;
    v0 = (s32)a1 >> (0x1 & 31);
    a0 = a3 + v0;
    if (a0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a0 / (s32)a1; hi = (s32)a0 % (s32)a1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = lo;
    v0 = v0 + a2;
    v0 = (int16_t)v0;
    return ((u64)v1 << 32) | v0;
L_95914:
    v1 = v1 + 1; goto L_95894;
L_9591c:
    ;
    return ((u64)v1 << 32) | v0;
}
