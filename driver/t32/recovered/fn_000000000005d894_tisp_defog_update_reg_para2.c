/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2130[] __asm__("t32_data_e2130");
extern unsigned char ref_memcpy[] __asm__("memcpy");
u64 tisp_defog_update_reg_para2(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_5d894 = ((u32)(unsigned long)ref_t32_data_e2130 + 0x8000U) & 0xffff0000U;
    const u32 hi_5d994 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_5d894:
    v0 = hi_5d894;
    sp = sp + -32;
    v0 = v0 - hi_5d894 + (u32)(unsigned long)ref_t32_data_e2130;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t1 = 128;
    t0 = 127;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (20));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    t3 = *(volatile u8 *)(unsigned long)(s0 + (393));
    t4 = *(volatile u8 *)(unsigned long)(s0 + (411));
    t5 = *(volatile u8 *)(unsigned long)(s0 + (360));
    t8 = t1 - t3;
    a1 = s0 + 361;
    t2 = a0;
    a2 = s0 + 412;
    a3 = s0 + 394;
    t6 = s0 + 429;
    t7 = (s32)t3 < (s32)(65);
    t9 = (s32)t4 < (s32)(65);
    t1 = t1 - t4;
L_5d900:
    branch = (t7 == 0); ra = *(volatile u8 *)(unsigned long)(a3 + (0));
    if (branch) goto L_5d914;
    goto L_5d908;
L_5d908:
    ra = ra * t3;
    ra = (s32)ra >> (0x6 & 31); goto L_5d924;
L_5d914:
    ra = t0 - ra;
    ra = ra * t8;
    ra = (s32)ra >> (0x6 & 31);
    ra = t0 - ra;
L_5d924:
    branch = (t9 == 0); v0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    if (branch) goto L_5d938;
    goto L_5d92c;
L_5d92c:
    v0 = v0 * t4;
    v0 = (s32)v0 >> (0x6 & 31); goto L_5d948;
L_5d938:
    v0 = t0 - v0;
    v0 = v0 * t1;
    v0 = (s32)v0 >> (0x6 & 31);
    v0 = t0 - v0;
L_5d948:
    v0 = v0 & 0x7f;
    v1 = v0 << (0x7 & 31);
    v0 = ra & 0x7f;
    v0 = v1 | v0;
    a2 = a2 + 1;
    *(volatile u32 *)(unsigned long)(t2 + (0)) = v0;
    a3 = a3 + 1;
    branch = (a2 != t6); t2 = t2 + 4;
    if (branch) goto L_5d900;
    goto L_5d96c;
L_5d96c:
    v1 = a0 + 84;
    a2 = s0 + 393;
L_5d974:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    a1 = a1 + 1;
    v1 = v1 + 1;
    v0 = v0 * t5;
    v0 = (v0 >> 0x7) & ((1U << 0x7) - 1);
    branch = (a2 != a1); *(volatile u8 *)(unsigned long)(v1 + (-1)) = v0;
    if (branch) goto L_5d974;
    goto L_5d990;
L_5d990:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (327));
    s2 = hi_5d994;
    s2 = s2 - hi_5d994 + ((u32)(unsigned long)ref_memcpy + (0));
    *(volatile u8 *)(unsigned long)(a0 + (83)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (262));
    a1 = s0 + 217;
    a2 = 9;
    *(volatile u8 *)(unsigned long)(a0 + (82)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (261));
    *(volatile u8 *)(unsigned long)(a0 + (81)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (190));
    *(volatile u8 *)(unsigned long)(a0 + (80)) = v0;
    v0 = s0 + 263;
    *(volatile u32 *)(unsigned long)(a0 + (68)) = v0;
    v0 = s0 + 295;
    *(volatile u32 *)(unsigned long)(a0 + (72)) = v0;
    v0 = s0 + 328;
    *(volatile u32 *)(unsigned long)(a0 + (76)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (190));
    a0 = s1 + 2381;
    *(volatile u8 *)(unsigned long)(s1 + (2415)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (192));
    *(volatile u8 *)(unsigned long)(s1 + (2416)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (193));
    *(volatile u8 *)(unsigned long)(s1 + (2417)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (194));
    *(volatile u8 *)(unsigned long)(s1 + (2418)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (195));
    *(volatile u8 *)(unsigned long)(s1 + (2420)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (196));
    *(volatile u8 *)(unsigned long)(s1 + (2421)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (197));
    *(volatile u8 *)(unsigned long)(s1 + (2422)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (198));
    *(volatile u8 *)(unsigned long)(s1 + (2423)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (199));
    callee = s2; *(volatile u8 *)(unsigned long)(s1 + (2424)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5da28;
L_5da28:
    a1 = s0 + 226;
    a0 = s1 + 2390;
    callee = s2; a2 = 25;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5da38;
L_5da38:
    a1 = s0 + 200;
    a0 = s1 + 2364;
    callee = s2; a2 = 17;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5da48;
L_5da48:
    v0 = s0 + 251;
    s0 = s0 + 256;
    *(volatile u32 *)(unsigned long)(s1 + (2176)) = v0;
    *(volatile u32 *)(unsigned long)(s1 + (2180)) = s0;
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
