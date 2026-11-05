/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dd0a4[] __asm__("t32_data_dd0a4");
extern unsigned char ref_tisp_get_tuning[] __asm__("tisp_get_tuning");
extern unsigned char ref_t32_data_e2388[] __asm__("t32_data_e2388");
extern unsigned char ref_t32_data_e235c[] __asm__("t32_data_e235c");
extern unsigned char ref_t32_data_e2330[] __asm__("t32_data_e2330");
extern unsigned char ref_t32_data_e2304[] __asm__("t32_data_e2304");
extern unsigned char ref_t32_data_e22d8[] __asm__("t32_data_e22d8");
extern unsigned char ref_t32_data_e22c8[] __asm__("t32_data_e22c8");
extern unsigned char ref_tisp_mdns_refresh[] __asm__("tisp_mdns_refresh");
u64 tisp_s_mdns_ratio(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_742c0 = ((u32)(unsigned long)ref_t32_data_dd0a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_742e4 = ((u32)(unsigned long)ref_tisp_get_tuning + 0x8000U) & 0xffff0000U;
    const u32 hi_74320 = ((u32)(unsigned long)ref_t32_data_e2388 + 0x8000U) & 0xffff0000U;
    const u32 hi_74324 = ((u32)(unsigned long)ref_t32_data_e235c + 0x8000U) & 0xffff0000U;
    const u32 hi_74328 = ((u32)(unsigned long)ref_t32_data_e2330 + 0x8000U) & 0xffff0000U;
    const u32 hi_7432c = ((u32)(unsigned long)ref_t32_data_e2304 + 0x8000U) & 0xffff0000U;
    const u32 hi_74330 = ((u32)(unsigned long)ref_t32_data_e22d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_74510 = ((u32)(unsigned long)ref_t32_data_e22c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_74534 = ((u32)(unsigned long)ref_tisp_mdns_refresh + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_742bc:
    sp = sp + -40;
    v0 = hi_742c0;
    v0 = v0 - hi_742c0 + (u32)(unsigned long)ref_t32_data_dd0a4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    s0 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    v0 = s0 + v0;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_742e4;
    v0 = v0 - hi_742e4 + (u32)(unsigned long)ref_tisp_get_tuning;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_742f4;
L_742f4:
    a0 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = a0 << (0x7 & 31);
    v0 = v0 + a1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1068));
    branch = (v1 == 0); a2 = 128;
    if (branch) goto L_74310;
    goto L_7430c;
L_7430c:
    a2 = *(volatile u8 *)(unsigned long)(v0 + (1072));
L_74310:
    v0 = 0x8bb9;
    t3 = 11;
    v1 = s1 + v0;
    v0 = a0 * t3;
    a3 = hi_74320;
    t0 = hi_74324;
    t1 = hi_74328;
    t2 = hi_7432c;
    t3 = hi_74330;
    a3 = a3 - hi_74320 + (u32)(unsigned long)ref_t32_data_e2388;
    t0 = t0 - hi_74324 + (u32)(unsigned long)ref_t32_data_e235c;
    t1 = t1 - hi_74328 + (u32)(unsigned long)ref_t32_data_e2330;
    t2 = t2 - hi_7432c + (u32)(unsigned long)ref_t32_data_e2304;
    t3 = t3 - hi_74330 + (u32)(unsigned long)ref_t32_data_e22d8;
    a1 = 0;
    t4 = (u32)a2 < (u32)(129);
    t5 = a2 + -128;
    t6 = 128;
    t8 = 180;
    t9 = 255;
    a3 = a3 + v0;
    t0 = t0 + v0;
    t1 = t1 + v0;
    t2 = t2 + v0;
    t3 = t3 + v0;
    t7 = 11;
L_74378:
    branch = (t4 != 0); v0 = a3 + a1;
    if (branch) goto L_743a8;
    goto L_74380;
L_74380:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    s1 = (int8_t)v0;
    s2 = t6 - v0;
    s1 = (s32)0 < (s32)(s1);
    if (s1 == 0) s2 = 0;
    s1 = s2 * t5;
    s1 = (s32)s1 >> (0x7 & 31);
    v0 = v0 + s1;
    v0 = v0 & 0xff; goto L_743c0;
L_743a8:
    s1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = (int8_t)s1;
    v0 = (s32)0 < (s32)(v0);
    if (v0 == 0) s1 = 0;
    v0 = s1 * a2;
    v0 = (v0 >> 0x7) & ((1U << 0x8) - 1);
L_743c0:
    *(volatile u8 *)(unsigned long)(v1 + (-800)) = v0;
    branch = (t4 != 0); v0 = t0 + a1;
    if (branch) goto L_743f4;
    goto L_743cc;
L_743cc:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    s1 = (int8_t)v0;
    s2 = t6 - v0;
    s1 = (s32)0 < (s32)(s1);
    if (s1 == 0) s2 = 0;
    s1 = s2 * t5;
    s1 = (s32)s1 >> (0x7 & 31);
    v0 = v0 + s1;
    v0 = v0 & 0xff; goto L_7440c;
L_743f4:
    s1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = (int8_t)s1;
    v0 = (s32)0 < (s32)(v0);
    if (v0 == 0) s1 = 0;
    v0 = s1 * a2;
    v0 = (v0 >> 0x7) & ((1U << 0x8) - 1);
L_7440c:
    *(volatile u8 *)(unsigned long)(v1 + (-701)) = v0;
    branch = (t4 != 0); v0 = t1 + a1;
    if (branch) goto L_74440;
    goto L_74418;
L_74418:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    s1 = (int8_t)v0;
    s2 = t6 - v0;
    s1 = (s32)0 < (s32)(s1);
    if (s1 == 0) s2 = 0;
    s1 = s2 * t5;
    s1 = (s32)s1 >> (0x7 & 31);
    v0 = v0 + s1;
    v0 = v0 & 0xff; goto L_74458;
L_74440:
    s1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = (int8_t)s1;
    v0 = (s32)0 < (s32)(v0);
    if (v0 == 0) s1 = 0;
    v0 = s1 * a2;
    v0 = (v0 >> 0x7) & ((1U << 0x8) - 1);
L_74458:
    *(volatile u8 *)(unsigned long)(v1 + (-635)) = v0;
    branch = (t4 != 0); v0 = t2 + a1;
    if (branch) goto L_74490;
    goto L_74464;
L_74464:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    s2 = v0 + -1;
    s2 = s2 & 0xff;
    s1 = t8 - v0;
    s2 = (u32)s2 < (u32)(179);
    if (s2 == 0) s1 = 0;
    s1 = s1 * t5;
    s1 = (s32)s1 >> (0x7 & 31);
    v0 = v0 + s1;
    v0 = v0 & 0xff; goto L_744ac;
L_74490:
    s1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = s1 + -1;
    v0 = v0 & 0xff;
    v0 = (u32)v0 < (u32)(179);
    if (v0 == 0) s1 = 0;
    v0 = s1 * a2;
    v0 = (v0 >> 0x7) & ((1U << 0x8) - 1);
L_744ac:
    *(volatile u8 *)(unsigned long)(v1 + (55)) = v0;
    branch = (t4 != 0); v0 = t3 + a1;
    if (branch) goto L_744e4;
    goto L_744b8;
L_744b8:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    s2 = v0 + -1;
    s2 = s2 & 0xff;
    s1 = t9 - v0;
    s2 = (u32)s2 < (u32)(254);
    if (s2 == 0) s1 = 0;
    s1 = s1 * t5;
    s1 = (s32)s1 >> (0x7 & 31);
    v0 = v0 + s1;
    v0 = v0 & 0xff; goto L_74500;
L_744e4:
    s1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = s1 + -1;
    v0 = v0 & 0xff;
    v0 = (u32)v0 < (u32)(254);
    if (v0 == 0) s1 = 0;
    v0 = s1 * a2;
    v0 = (v0 >> 0x7) & ((1U << 0x8) - 1);
L_74500:
    a1 = a1 + 1;
    *(volatile u8 *)(unsigned long)(v1 + (0)) = v0;
    branch = (a1 != t7); v1 = v1 + 1;
    if (branch) goto L_74378;
    goto L_74510;
L_74510:
    v0 = hi_74510;
    v0 = v0 - hi_74510 + (u32)(unsigned long)ref_t32_data_e22c8;
    s0 = v0 + s0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    t9 = hi_74534;
    t9 = t9 - hi_74534 + (u32)(unsigned long)ref_tisp_mdns_refresh;
    callee = t9; sp = sp + 40;
    switch (callee) { case 0x742bc: goto L_742bc; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
