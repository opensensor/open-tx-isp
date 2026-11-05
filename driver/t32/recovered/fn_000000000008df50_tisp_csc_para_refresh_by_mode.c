/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_bfea0[] __asm__("t32_data_bfea0");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_d7ffc[] __asm__("t32_data_d7ffc");
extern unsigned char ref_t32_data_d7fa0[] __asm__("t32_data_d7fa0");
extern unsigned char ref_t32_data_d7f44[] __asm__("t32_data_d7f44");
extern unsigned char ref_t32_data_d7ee8[] __asm__("t32_data_d7ee8");
extern unsigned char ref_t32_data_d7e8c[] __asm__("t32_data_d7e8c");
extern unsigned char ref_t32_data_d7e30[] __asm__("t32_data_d7e30");
extern unsigned char ref_t32_data_bfeb8[] __asm__("t32_data_bfeb8");
extern unsigned char ref_t32_data_bfec0[] __asm__("t32_data_bfec0");
u64 tisp_csc_para_refresh_by_mode(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8df74 = ((u32)(unsigned long)ref_t32_data_bfea0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8df88 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_8df98 = ((u32)(unsigned long)ref_t32_data_d7ffc + 0x8000U) & 0xffff0000U;
    const u32 hi_8dfa4 = ((u32)(unsigned long)ref_t32_data_d7fa0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8dfb0 = ((u32)(unsigned long)ref_t32_data_d7f44 + 0x8000U) & 0xffff0000U;
    const u32 hi_8dfbc = ((u32)(unsigned long)ref_t32_data_d7ee8 + 0x8000U) & 0xffff0000U;
    const u32 hi_8dfc8 = ((u32)(unsigned long)ref_t32_data_d7e8c + 0x8000U) & 0xffff0000U;
    const u32 hi_8dfd4 = ((u32)(unsigned long)ref_t32_data_d7e30 + 0x8000U) & 0xffff0000U;
    const u32 hi_8dfe8 = ((u32)(unsigned long)ref_t32_data_bfeb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_8e010 = ((u32)(unsigned long)ref_t32_data_bfec0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8e030 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_8df50:
    v0 = a0;
    a1 = a1 & 0xff;
    a0 = a2;
    a2 = 1;
    branch = (a1 != a2); v1 = (u32)v0 < (u32)(7);
    if (branch) goto L_8dfe0;
    goto L_8df68;
L_8df68:
    v1 = (u32)v0 < (u32)(6);
    branch = (v1 == 0); ;
    if (branch) goto L_8e0d8;
    goto L_8df74;
L_8df74:
    v1 = hi_8df74;
    v0 = v0 << (0x2 & 31);
    v1 = v1 - hi_8df74 + (u32)(unsigned long)ref_t32_data_bfea0;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t9 = hi_8df88;
    t9 = t9 - hi_8df88 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a2 = 92;
    switch (callee) { case 0x8df50: goto L_8df50; case 0x8df98: goto L_8df98; case 0x8dfa4: goto L_8dfa4; case 0x8dfb0: goto L_8dfb0; case 0x8dfbc: goto L_8dfbc; case 0x8dfc8: goto L_8dfc8; case 0x8dfd4: goto L_8dfd4; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_8df98:
    a1 = hi_8df98;
    a1 = a1 - hi_8df98 + (u32)(unsigned long)ref_t32_data_d7ffc; goto L_8e0d0;
L_8dfa4:
    a1 = hi_8dfa4;
    a1 = a1 - hi_8dfa4 + (u32)(unsigned long)ref_t32_data_d7fa0; goto L_8e0d0;
L_8dfb0:
    a1 = hi_8dfb0;
    a1 = a1 - hi_8dfb0 + (u32)(unsigned long)ref_t32_data_d7f44; goto L_8e0d0;
L_8dfbc:
    a1 = hi_8dfbc;
    a1 = a1 - hi_8dfbc + (u32)(unsigned long)ref_t32_data_d7ee8; goto L_8e0d0;
L_8dfc8:
    a1 = hi_8dfc8;
    a1 = a1 - hi_8dfc8 + (u32)(unsigned long)ref_t32_data_d7e8c; goto L_8e0d0;
L_8dfd4:
    a1 = hi_8dfd4;
    a1 = a1 - hi_8dfd4 + (u32)(unsigned long)ref_t32_data_d7e30; goto L_8e0d0;
L_8dfe0:
    branch = (v1 == 0); ;
    if (branch) goto L_8e0d8;
    goto L_8dfe8;
L_8dfe8:
    v1 = hi_8dfe8;
    v1 = v1 - hi_8dfe8 + (u32)(unsigned long)ref_t32_data_bfeb8;
    v1 = v0 + v1;
    v1 = *(volatile u8 *)(unsigned long)(v1 + (0));
    branch = (v1 != a2); ;
    if (branch) goto L_8e0d8;
    goto L_8e000;
L_8e000:
    sp = sp + -32;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    s0 = a0;
    a0 = v0 << (0x2 & 31);
    v0 = hi_8e010;
    v0 = v0 - hi_8e010 + (u32)(unsigned long)ref_t32_data_bfec0;
    v0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    s2 = hi_8e030;
    a1 = s1 + 4;
    *(volatile u8 *)(unsigned long)(s0 + (91)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (40));
    a0 = s0 + 4;
    s2 = s2 - hi_8e030 + ((u32)(unsigned long)ref_memcpy + (0));
    *(volatile u8 *)(unsigned long)(s0 + (82)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (41));
    a2 = 36;
    *(volatile u8 *)(unsigned long)(s0 + (83)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (42));
    *(volatile u8 *)(unsigned long)(s0 + (84)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (43));
    *(volatile u8 *)(unsigned long)(s0 + (85)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (44));
    *(volatile u8 *)(unsigned long)(s0 + (86)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (45));
    *(volatile u8 *)(unsigned long)(s0 + (87)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (84));
    *(volatile u8 *)(unsigned long)(s0 + (92)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (85));
    *(volatile u8 *)(unsigned long)(s0 + (93)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (86));
    *(volatile u8 *)(unsigned long)(s0 + (94)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (87));
    *(volatile u8 *)(unsigned long)(s0 + (95)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (88));
    *(volatile u8 *)(unsigned long)(s0 + (96)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (89));
    callee = s2; *(volatile u8 *)(unsigned long)(s0 + (97)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8e0ac;
L_8e0ac:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    a1 = s1 + 48;
    a0 = s0 + 40;
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    t9 = s2;
    a2 = 36;
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 32;
L_8e0d0:
    callee = t9; ;
    switch (callee) { case 0x8df50: goto L_8df50; case 0x8df98: goto L_8df98; case 0x8dfa4: goto L_8dfa4; case 0x8dfb0: goto L_8dfb0; case 0x8dfbc: goto L_8dfbc; case 0x8dfc8: goto L_8dfc8; case 0x8dfd4: goto L_8dfd4; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_8e0d8:
    ;
    return ((u64)v1 << 32) | v0;
}
