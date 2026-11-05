/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c2e30[] __asm__("t32_data_c2e30");
extern unsigned char ref_t32_data_cb5e0[] __asm__("t32_data_cb5e0");
extern unsigned char ref_t32_data_cb614[] __asm__("t32_data_cb614");
extern unsigned char ref_t32_data_e3f34[] __asm__("t32_data_e3f34");
extern unsigned char ref_t32_data_cb224[] __asm__("t32_data_cb224");
extern unsigned char ref_t32_data_e3f48[] __asm__("t32_data_e3f48");
extern unsigned char ref_t32_data_e3f00[] __asm__("t32_data_e3f00");
extern unsigned char ref_t32_data_cb09c[] __asm__("t32_data_cb09c");
extern unsigned char ref_t32_data_e3f28[] __asm__("t32_data_e3f28");
extern unsigned char ref_t32_data_cb074[] __asm__("t32_data_cb074");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_e3f44[] __asm__("t32_data_e3f44");
extern unsigned char ref_t32_data_e3f30[] __asm__("t32_data_e3f30");
extern unsigned char ref_t32_data_cb64c[] __asm__("t32_data_cb64c");
extern unsigned char ref_t32_data_e3f2c[] __asm__("t32_data_e3f2c");
extern unsigned char ref_system_reg_write[] __asm__("system_reg_write");
extern unsigned char ref_t32_data_e3f20[] __asm__("t32_data_e3f20");
extern unsigned char ref_tisp_vic_mdma_enable[] __asm__("tisp_vic_mdma_enable");
extern unsigned char ref_t32_data_e3f40[] __asm__("t32_data_e3f40");
u64 lib_tisp_save_specified_frame_raw(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_af1b0 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_af1b4 = ((u32)(unsigned long)ref_t32_data_c2e30 + 0x8000U) & 0xffff0000U;
    const u32 hi_af1c0 = ((u32)(unsigned long)ref_t32_data_cb5e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_af20c = ((u32)(unsigned long)ref_t32_data_cb614 + 0x8000U) & 0xffff0000U;
    const u32 hi_af220 = ((u32)(unsigned long)ref_t32_data_e3f34 + 0x8000U) & 0xffff0000U;
    const u32 hi_af238 = ((u32)(unsigned long)ref_t32_data_cb224 + 0x8000U) & 0xffff0000U;
    const u32 hi_af294 = ((u32)(unsigned long)ref_t32_data_e3f48 + 0x8000U) & 0xffff0000U;
    const u32 hi_af29c = ((u32)(unsigned long)ref_t32_data_e3f00 + 0x8000U) & 0xffff0000U;
    const u32 hi_af2cc = ((u32)(unsigned long)ref_t32_data_cb09c + 0x8000U) & 0xffff0000U;
    const u32 hi_af2a8 = ((u32)(unsigned long)ref_t32_data_e3f28 + 0x8000U) & 0xffff0000U;
    const u32 hi_af310 = ((u32)(unsigned long)ref_t32_data_cb074 + 0x8000U) & 0xffff0000U;
    const u32 hi_af314 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_af374 = ((u32)(unsigned long)ref_t32_data_e3f44 + 0x8000U) & 0xffff0000U;
    const u32 hi_af358 = ((u32)(unsigned long)ref_t32_data_e3f30 + 0x8000U) & 0xffff0000U;
    const u32 hi_af398 = ((u32)(unsigned long)ref_t32_data_cb64c + 0x8000U) & 0xffff0000U;
    const u32 hi_af36c = ((u32)(unsigned long)ref_t32_data_e3f2c + 0x8000U) & 0xffff0000U;
    const u32 hi_af3cc = ((u32)(unsigned long)ref_system_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_af40c = ((u32)(unsigned long)ref_t32_data_e3f20 + 0x8000U) & 0xffff0000U;
    const u32 hi_af458 = ((u32)(unsigned long)ref_tisp_vic_mdma_enable + 0x8000U) & 0xffff0000U;
    const u32 hi_af470 = ((u32)(unsigned long)ref_t32_data_e3f40 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_af184:
    sp = sp + -64;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    s1 = a0 & 0xff;
    a0 = *(volatile u8 *)(unsigned long)(a1 + (12));
    s5 = hi_af1b0;
    s6 = hi_af1b4;
    branch = (a0 != 0); s5 = s5 - hi_af1b0 + ((u32)(unsigned long)ref_printk + (0));
    if (branch) goto L_af1d8;
    goto L_af1c0;
L_af1c0:
    a0 = hi_af1c0;
    a3 = *(volatile u8 *)(unsigned long)(a1 + (14));
    a2 = 964;
    a1 = s6 - hi_af1b4 + (u32)(unsigned long)ref_t32_data_c2e30;
    a0 = a0 - hi_af1c0 + (u32)(unsigned long)ref_t32_data_cb5e0; goto L_af248;
L_af1d8:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    if (v0 != 0) { v1 = *(volatile u8 *)(unsigned long)(a1 + (14)); goto L_af220; }
    goto L_af1e4;
L_af1e4:
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    a1 = s6 - hi_af1b4 + (u32)(unsigned long)ref_t32_data_c2e30;
    t9 = s5;
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    a0 = hi_af20c;
    a2 = 969;
    a0 = a0 - hi_af20c + (u32)(unsigned long)ref_t32_data_cb614;
    callee = t9; sp = sp + 64;
    switch (callee) { case 0xaf184: goto L_af184; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_af220:
    a2 = hi_af220;
    v0 = v1 + -1;
    v0 = (u32)v0 < (u32)(10);
    branch = (v0 != 0); s0 = a2 - hi_af220 + (u32)(unsigned long)ref_t32_data_e3f34;
    if (branch) goto L_af274;
    goto L_af234;
L_af234:
    a3 = *(volatile u8 *)(unsigned long)(s0 + (10));
    a0 = hi_af238;
    a2 = 974;
    a1 = s6 - hi_af1b4 + (u32)(unsigned long)ref_t32_data_c2e30;
    a0 = a0 - hi_af238 + (u32)(unsigned long)ref_t32_data_cb224;
L_af248:
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    t9 = s5;
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    callee = t9; sp = sp + 64;
    switch (callee) { case 0xaf184: goto L_af184; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_af274:
    v0 = *(volatile u8 *)(unsigned long)(a1 + (13));
    *(volatile u8 *)(unsigned long)(s0 + (7)) = a0;
    *(volatile u8 *)(unsigned long)(s0 + (10)) = v1;
    *(volatile u8 *)(unsigned long)(s0 + (8)) = v0;
    v0 = s1 & 0x1;
    *(volatile u8 *)(unsigned long)(s0 + (6)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    s3 = a1;
    a1 = hi_af294;
    *(volatile u8 *)(unsigned long)(a1 - hi_af294 + (u32)(unsigned long)ref_t32_data_e3f48) = a0;
    s4 = hi_af29c;
    a0 = 1;
    *(volatile u32 *)(unsigned long)(a2 - hi_af220 + (u32)(unsigned long)ref_t32_data_e3f34) = v1;
    s2 = hi_af2a8;
    branch = (v1 == a0); s4 = s4 - hi_af29c + (u32)(unsigned long)ref_t32_data_e3f00;
    if (branch) goto L_af310;
    goto L_af2b4;
L_af2b4:
    branch = (v1 == 0); v0 = v0 << (0x4 & 31);
    if (branch) goto L_af304;
    goto L_af2bc;
L_af2bc:
    a0 = 2;
    branch = (v1 != a0); v0 = s4 + v0;
    if (branch) goto L_af338;
    goto L_af2c8;
L_af2c8:
    a3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = hi_af2cc;
    a2 = 994;
    v0 = a3 << (0x1 & 31);
    a3 = v0 + a3;
    a3 = a3 >> (0x1 & 31);
    a3 = a3 + 7;
    a3 = a3 >> (0x3 & 31);
    a3 = a3 << (0x3 & 31);
    a1 = s6 - hi_af1b4 + (u32)(unsigned long)ref_t32_data_c2e30;
    a0 = a0 - hi_af2cc + (u32)(unsigned long)ref_t32_data_cb09c;
    callee = s5; *(volatile u32 *)(unsigned long)(s2 - hi_af2a8 + (u32)(unsigned long)ref_t32_data_e3f28) = a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af2fc;
L_af2fc:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (6)); goto L_af354;
L_af304:
    v0 = s4 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_af340;
L_af310:
    a1 = hi_af310;
    v0 = hi_af314;
    a3 = 990;
    a2 = s6 - hi_af1b4 + (u32)(unsigned long)ref_t32_data_c2e30;
    a1 = a1 - hi_af310 + (u32)(unsigned long)ref_t32_data_cb074;
    v0 = v0 - hi_af314 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af330;
L_af330:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (6)); goto L_af354;
L_af338:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 << (0x1 & 31);
L_af340:
    v0 = v0 + 7;
    v0 = v0 >> (0x3 & 31);
    v0 = v0 << (0x3 & 31);
    *(volatile u32 *)(unsigned long)(s2 - hi_af2a8 + (u32)(unsigned long)ref_t32_data_e3f28) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (6));
L_af354:
    v1 = *(volatile u32 *)(unsigned long)(s2 - hi_af2a8 + (u32)(unsigned long)ref_t32_data_e3f28);
    a0 = hi_af358;
    v0 = v0 << (0x4 & 31);
    s4 = s4 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s4 + (4));
    a3 = s1;
    s4 = hi_af36c;
    v0 = v0 * v1;
    v1 = hi_af374;
    a2 = 1005;
    a1 = s6 - hi_af1b4 + (u32)(unsigned long)ref_t32_data_c2e30;
    *(volatile u32 *)(unsigned long)(v1 - hi_af374 + (u32)(unsigned long)ref_t32_data_e3f44) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (4));
    v1 = 0x8000U << 16;
    v1 = v0 + v1;
    *(volatile u32 *)(unsigned long)(a0 - hi_af358 + (u32)(unsigned long)ref_t32_data_e3f30) = v1;
    v1 = *(volatile u8 *)(unsigned long)(s3 + (12));
    a0 = hi_af398;
    a0 = a0 - hi_af398 + (u32)(unsigned long)ref_t32_data_cb64c;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(s3 + (14));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    *(volatile u32 *)(unsigned long)(s4 - hi_af36c + (u32)(unsigned long)ref_t32_data_e3f2c) = v0;
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af3b8;
L_af3b8:
    v1 = *(volatile u8 *)(unsigned long)(s0 + (4));
    v0 = 1;
    branch = (v1 != v0); s3 = s4;
    if (branch) goto L_af3fc;
    goto L_af3c8;
L_af3c8:
    a0 = *(volatile u8 *)(unsigned long)(s0 + (8));
    v0 = hi_af3cc;
    a1 = 2;
    branch = (a0 != a1); v0 = v0 - hi_af3cc + (u32)(unsigned long)ref_system_reg_write;
    if (branch) goto L_af3e4;
    goto L_af3dc;
L_af3dc:
    a1 = 17424; goto L_af3f0;
L_af3e4:
    branch = (a0 == v1); a1 = 17428;
    if (branch) goto L_af3f0;
    goto L_af3ec;
L_af3ec:
    a1 = 17472;
L_af3f0:
    a0 = 0x8U << 16;
    callee = v0; a0 = a0 + 428;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af3fc;
L_af3fc:
    v1 = *(volatile u8 *)(unsigned long)(s0 + (10));
    v0 = 1;
    branch = (v1 != v0); ra = *(volatile u32 *)(unsigned long)(sp + (60));
    if (branch) goto L_af46c;
    goto L_af40c;
L_af40c:
    v0 = hi_af40c;
    v0 = v0 - hi_af40c + (u32)(unsigned long)ref_t32_data_e3f20;
    s1 = s1 << (0x2 & 31);
    s1 = s1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    branch = (v0 != 0); v1 = 1;
    if (branch) goto L_af470;
    goto L_af42c;
L_af42c:
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    a3 = *(volatile u32 *)(unsigned long)(s3 - hi_af40c + (u32)(unsigned long)ref_t32_data_e3f2c);
    a1 = *(volatile u32 *)(unsigned long)(s2 - hi_af2a8 + (u32)(unsigned long)ref_t32_data_e3f28);
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    a0 = s0;
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    t9 = hi_af458;
    a2 = 1;
    t9 = t9 - hi_af458 + (u32)(unsigned long)ref_tisp_vic_mdma_enable;
    callee = t9; sp = sp + 64;
    switch (callee) { case 0xaf184: goto L_af184; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_af46c:
    v1 = 1;
L_af470:
    v0 = hi_af470;
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    *(volatile u8 *)(unsigned long)(v0 - hi_af470 + (u32)(unsigned long)ref_t32_data_e3f40) = v1;
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
}
