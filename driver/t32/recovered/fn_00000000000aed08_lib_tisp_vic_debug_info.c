/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_cb360[] __asm__("t32_data_cb360");
extern unsigned char ref_t32_data_cb368[] __asm__("t32_data_cb368");
extern unsigned char ref_t32_data_e3f20[] __asm__("t32_data_e3f20");
extern unsigned char ref_t32_data_e3f58[] __asm__("t32_data_e3f58");
extern unsigned char ref_t32_data_cb2b4[] __asm__("t32_data_cb2b4");
extern unsigned char ref_t32_data_cb2b8[] __asm__("t32_data_cb2b8");
extern unsigned char ref_t32_data_cb2c0[] __asm__("t32_data_cb2c0");
extern unsigned char ref_t32_data_cb2c8[] __asm__("t32_data_cb2c8");
extern unsigned char ref_t32_data_cb2d0[] __asm__("t32_data_cb2d0");
extern unsigned char ref_t32_data_cb2d8[] __asm__("t32_data_cb2d8");
extern unsigned char ref_private_seq_printf[] __asm__("private_seq_printf");
extern unsigned char ref_t32_data_cb2e0[] __asm__("t32_data_cb2e0");
extern unsigned char ref_t32_data_cb340[] __asm__("t32_data_cb340");
extern unsigned char ref_t32_data_cb348[] __asm__("t32_data_cb348");
extern unsigned char ref_t32_data_cb350[] __asm__("t32_data_cb350");
extern unsigned char ref_t32_data_cb370[] __asm__("t32_data_cb370");
extern unsigned char ref_t32_data_cb380[] __asm__("t32_data_cb380");
extern unsigned char ref_t32_data_cb384[] __asm__("t32_data_cb384");
extern unsigned char ref_t32_data_cb418[] __asm__("t32_data_cb418");
extern unsigned char ref_t32_data_cb424[] __asm__("t32_data_cb424");
extern unsigned char ref_t32_data_cb430[] __asm__("t32_data_cb430");
extern unsigned char ref_t32_data_cb43c[] __asm__("t32_data_cb43c");
extern unsigned char ref_t32_data_cb448[] __asm__("t32_data_cb448");
extern unsigned char ref_t32_data_cb454[] __asm__("t32_data_cb454");
extern unsigned char ref_t32_data_cb3e4[] __asm__("t32_data_cb3e4");
extern unsigned char ref_t32_data_cb3ec[] __asm__("t32_data_cb3ec");
extern unsigned char ref_t32_data_cb3f4[] __asm__("t32_data_cb3f4");
extern unsigned char ref_t32_data_cb45c[] __asm__("t32_data_cb45c");
extern unsigned char ref_t32_data_cb480[] __asm__("t32_data_cb480");
extern unsigned char ref_t32_data_cb4f0[] __asm__("t32_data_cb4f0");
extern unsigned char ref_t32_data_cb4f8[] __asm__("t32_data_cb4f8");
extern unsigned char ref_t32_data_cb500[] __asm__("t32_data_cb500");
extern unsigned char ref_t32_data_cb508[] __asm__("t32_data_cb508");
extern unsigned char ref_t32_data_cb510[] __asm__("t32_data_cb510");
extern unsigned char ref_t32_data_cb518[] __asm__("t32_data_cb518");
extern unsigned char ref_t32_data_cb4e0[] __asm__("t32_data_cb4e0");
extern unsigned char ref_t32_data_cb4e8[] __asm__("t32_data_cb4e8");
extern unsigned char ref_t32_data_cb520[] __asm__("t32_data_cb520");
extern unsigned char ref_t32_data_cb598[] __asm__("t32_data_cb598");
extern unsigned char ref_t32_data_cb5a4[] __asm__("t32_data_cb5a4");
extern unsigned char ref_t32_data_cb5b0[] __asm__("t32_data_cb5b0");
extern unsigned char ref_t32_data_cb5bc[] __asm__("t32_data_cb5bc");
extern unsigned char ref_t32_data_cb5c8[] __asm__("t32_data_cb5c8");
extern unsigned char ref_t32_data_cb5d4[] __asm__("t32_data_cb5d4");
extern unsigned char ref_t32_data_cb580[] __asm__("t32_data_cb580");
extern unsigned char ref_t32_data_cb58c[] __asm__("t32_data_cb58c");
u64 lib_tisp_vic_debug_info(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[90] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_aed10 = ((u32)(unsigned long)ref_t32_data_cb360 + 0x8000U) & 0xffff0000U;
    const u32 hi_aed1c = ((u32)(unsigned long)ref_t32_data_cb368 + 0x8000U) & 0xffff0000U;
    const u32 hi_aed2c = ((u32)(unsigned long)ref_t32_data_e3f20 + 0x8000U) & 0xffff0000U;
    const u32 hi_aed28 = ((u32)(unsigned long)ref_t32_data_e3f58 + 0x8000U) & 0xffff0000U;
    const u32 hi_aed84 = ((u32)(unsigned long)ref_t32_data_cb2b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeda0 = ((u32)(unsigned long)ref_t32_data_cb2b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_aed9c = ((u32)(unsigned long)ref_t32_data_cb2c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeddc = ((u32)(unsigned long)ref_t32_data_cb2c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_aedf8 = ((u32)(unsigned long)ref_t32_data_cb2d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee10 = ((u32)(unsigned long)ref_t32_data_cb2d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee0c = ((u32)(unsigned long)ref_t32_data_cb2c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee3c = ((u32)(unsigned long)ref_private_seq_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_aed60 = ((u32)(unsigned long)ref_t32_data_cb2e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee58 = ((u32)(unsigned long)ref_t32_data_cb340 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee5c = ((u32)(unsigned long)ref_t32_data_cb348 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee68 = ((u32)(unsigned long)ref_t32_data_cb350 + 0x8000U) & 0xffff0000U;
    const u32 hi_aee88 = ((u32)(unsigned long)ref_t32_data_cb370 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeea8 = ((u32)(unsigned long)ref_t32_data_cb380 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeeb8 = ((u32)(unsigned long)ref_t32_data_cb384 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeecc = ((u32)(unsigned long)ref_t32_data_cb418 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeed8 = ((u32)(unsigned long)ref_t32_data_cb424 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeee4 = ((u32)(unsigned long)ref_t32_data_cb430 + 0x8000U) & 0xffff0000U;
    const u32 hi_aeef0 = ((u32)(unsigned long)ref_t32_data_cb43c + 0x8000U) & 0xffff0000U;
    const u32 hi_aeefc = ((u32)(unsigned long)ref_t32_data_cb448 + 0x8000U) & 0xffff0000U;
    const u32 hi_aef08 = ((u32)(unsigned long)ref_t32_data_cb454 + 0x8000U) & 0xffff0000U;
    const u32 hi_aef14 = ((u32)(unsigned long)ref_t32_data_cb3e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_aef18 = ((u32)(unsigned long)ref_t32_data_cb3ec + 0x8000U) & 0xffff0000U;
    const u32 hi_aef10 = ((u32)(unsigned long)ref_t32_data_cb3f4 + 0x8000U) & 0xffff0000U;
    const u32 hi_aef3c = ((u32)(unsigned long)ref_t32_data_cb45c + 0x8000U) & 0xffff0000U;
    const u32 hi_aef8c = ((u32)(unsigned long)ref_t32_data_cb480 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefa0 = ((u32)(unsigned long)ref_t32_data_cb4f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefac = ((u32)(unsigned long)ref_t32_data_cb4f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefb8 = ((u32)(unsigned long)ref_t32_data_cb500 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefc4 = ((u32)(unsigned long)ref_t32_data_cb508 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefd0 = ((u32)(unsigned long)ref_t32_data_cb510 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefdc = ((u32)(unsigned long)ref_t32_data_cb518 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefe4 = ((u32)(unsigned long)ref_t32_data_cb4e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aefe8 = ((u32)(unsigned long)ref_t32_data_cb4e8 + 0x8000U) & 0xffff0000U;
    const u32 hi_af058 = ((u32)(unsigned long)ref_t32_data_cb520 + 0x8000U) & 0xffff0000U;
    const u32 hi_af06c = ((u32)(unsigned long)ref_t32_data_cb598 + 0x8000U) & 0xffff0000U;
    const u32 hi_af078 = ((u32)(unsigned long)ref_t32_data_cb5a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_af084 = ((u32)(unsigned long)ref_t32_data_cb5b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_af090 = ((u32)(unsigned long)ref_t32_data_cb5bc + 0x8000U) & 0xffff0000U;
    const u32 hi_af09c = ((u32)(unsigned long)ref_t32_data_cb5c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_af0a8 = ((u32)(unsigned long)ref_t32_data_cb5d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_af0b0 = ((u32)(unsigned long)ref_t32_data_cb580 + 0x8000U) & 0xffff0000U;
    const u32 hi_af0b4 = ((u32)(unsigned long)ref_t32_data_cb58c + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[26];
L_aed08:
    sp = sp + -104;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s5;
    s5 = hi_aed10;
    v0 = s5 - hi_aed10 + (u32)(unsigned long)ref_t32_data_cb360;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s6;
    s6 = hi_aed1c;
    *(volatile u32 *)(unsigned long)(sp + (92)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s2;
    s7 = hi_aed28;
    s2 = hi_aed2c;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = s6 - hi_aed1c + (u32)(unsigned long)ref_t32_data_cb368;
    *(volatile u32 *)(unsigned long)(sp + (96)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (68)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (100)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s0;
    s1 = a0;
    s2 = s2 - hi_aed2c + (u32)(unsigned long)ref_t32_data_e3f20;
    s7 = s7 - hi_aed28 + (u32)(unsigned long)ref_t32_data_e3f58;
    s3 = 0;
    s8 = hi_aed60;
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
L_aed68:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    if (v0 == 0) { s3 = s3 + 1; goto L_af128; }
    goto L_aed74;
L_aed74:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = 1;
    branch = (v0 != a0); s5 = sp + 48;
    if (branch) goto L_aed94;
    goto L_aed84;
L_aed84:
    v0 = hi_aed84;
    a0 = s5;
    v0 = v0 - hi_aed84 + (u32)(unsigned long)ref_t32_data_cb2b4; goto L_aedb8;
L_aed94:
    a0 = 2;
    if (v0 != a0) { v0 = hi_aed9c; goto L_aedb0; }
    goto L_aeda0;
L_aeda0:
    v0 = hi_aeda0;
    a0 = s5;
    v0 = v0 - hi_aeda0 + (u32)(unsigned long)ref_t32_data_cb2b8; goto L_aedb8;
L_aedb0:
    a0 = s5;
    v0 = v0 - hi_aed9c + (u32)(unsigned long)ref_t32_data_cb2c0;
L_aedb8:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(a0 + (0)) = at;
    branch = (at != 0); a0 = a0 + 1;
    if (branch) goto L_aedb8;
    goto L_aedcc;
L_aedcc:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    branch = (v0 != 0); s4 = sp + 40;
    if (branch) goto L_aedec;
    goto L_aeddc;
L_aeddc:
    v0 = hi_aeddc;
    a0 = s4;
    v0 = v0 - hi_aeddc + (u32)(unsigned long)ref_t32_data_cb2c8; goto L_aee28;
L_aedec:
    a0 = 1;
    if (v0 != a0) { a0 = 2; goto L_aee08; }
    goto L_aedf8;
L_aedf8:
    v0 = hi_aedf8;
    a0 = s4;
    v0 = v0 - hi_aedf8 + (u32)(unsigned long)ref_t32_data_cb2d0; goto L_aee28;
L_aee08:
    if (v0 != a0) { v0 = hi_aee0c; goto L_aee20; }
    goto L_aee10;
L_aee10:
    v0 = hi_aee10;
    a0 = s4;
    v0 = v0 - hi_aee10 + (u32)(unsigned long)ref_t32_data_cb2d8; goto L_aee28;
L_aee20:
    a0 = s4;
    v0 = v0 - hi_aee0c + (u32)(unsigned long)ref_t32_data_cb2c0;
L_aee28:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(a0 + (0)) = at;
    branch = (at != 0); a0 = a0 + 1;
    if (branch) goto L_aee28;
    goto L_aee3c;
L_aee3c:
    s0 = hi_aee3c;
    s0 = s0 - hi_aee3c + (u32)(unsigned long)ref_private_seq_printf;
    a2 = s3;
    a1 = s8 - hi_aed60 + (u32)(unsigned long)ref_t32_data_cb2e0;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aee54;
L_aee54:
    v0 = *(volatile u32 *)(unsigned long)(sp + (56));
    a3 = hi_aee58;
    a2 = hi_aee5c;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (60));
    a1 = hi_aee68;
    a3 = a3 - hi_aee58 + (u32)(unsigned long)ref_t32_data_cb340;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a2 = a2 - hi_aee5c + (u32)(unsigned long)ref_t32_data_cb348;
    a1 = a1 - hi_aee68 + (u32)(unsigned long)ref_t32_data_cb350;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aee84;
L_aee84:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a1 = hi_aee88;
    a1 = a1 - hi_aee88 + (u32)(unsigned long)ref_t32_data_cb370;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (118));
    a2 = *(volatile u16 *)(unsigned long)(v0 + (116));
    a0 = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s5;
    callee = s0; s4 = hi_aeea8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aeeac;
L_aeeac:
    a1 = s4 - hi_aeea8 + (u32)(unsigned long)ref_t32_data_cb380;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aeeb8;
L_aeeb8:
    a1 = hi_aeeb8;
    a2 = s3;
    a1 = a1 - hi_aeeb8 + (u32)(unsigned long)ref_t32_data_cb384;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aeecc;
L_aeecc:
    v0 = hi_aeecc;
    v0 = v0 - hi_aeecc + (u32)(unsigned long)ref_t32_data_cb418;
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = hi_aeed8;
    v0 = v0 - hi_aeed8 + (u32)(unsigned long)ref_t32_data_cb424;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    v0 = hi_aeee4;
    v0 = v0 - hi_aeee4 + (u32)(unsigned long)ref_t32_data_cb430;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = hi_aeef0;
    v0 = v0 - hi_aeef0 + (u32)(unsigned long)ref_t32_data_cb43c;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = hi_aeefc;
    v0 = v0 - hi_aeefc + (u32)(unsigned long)ref_t32_data_cb448;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = hi_aef08;
    v0 = v0 - hi_aef08 + (u32)(unsigned long)ref_t32_data_cb454;
    s6 = hi_aef10;
    a3 = hi_aef14;
    a2 = hi_aef18;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a3 = a3 - hi_aef14 + (u32)(unsigned long)ref_t32_data_cb3e4;
    a2 = a2 - hi_aef18 + (u32)(unsigned long)ref_t32_data_cb3ec;
    a1 = s6 - hi_aef10 + (u32)(unsigned long)ref_t32_data_cb3f4;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aef34;
L_aef34:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a2 = *(volatile u32 *)(unsigned long)(s7 + (0));
    s5 = hi_aef3c;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (112));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (56));
    a1 = s5 - hi_aef3c + (u32)(unsigned long)ref_t32_data_cb45c;
    *(volatile u32 *)(unsigned long)(sp + (36)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (108));
    a0 = s1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (104));
    *(volatile u32 *)(unsigned long)(sp + (28)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (100));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (96));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (92));
    callee = s0; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aef80;
L_aef80:
    a1 = s4 - hi_aeea8 + (u32)(unsigned long)ref_t32_data_cb380;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aef8c;
L_aef8c:
    a1 = hi_aef8c;
    a2 = s3;
    a1 = a1 - hi_aef8c + (u32)(unsigned long)ref_t32_data_cb480;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aefa0;
L_aefa0:
    v0 = hi_aefa0;
    v0 = v0 - hi_aefa0 + (u32)(unsigned long)ref_t32_data_cb4f0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = hi_aefac;
    v0 = v0 - hi_aefac + (u32)(unsigned long)ref_t32_data_cb4f8;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    v0 = hi_aefb8;
    v0 = v0 - hi_aefb8 + (u32)(unsigned long)ref_t32_data_cb500;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = hi_aefc4;
    v0 = v0 - hi_aefc4 + (u32)(unsigned long)ref_t32_data_cb508;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = hi_aefd0;
    v0 = v0 - hi_aefd0 + (u32)(unsigned long)ref_t32_data_cb510;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = hi_aefdc;
    v0 = v0 - hi_aefdc + (u32)(unsigned long)ref_t32_data_cb518;
    a3 = hi_aefe4;
    a2 = hi_aefe8;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a3 = a3 - hi_aefe4 + (u32)(unsigned long)ref_t32_data_cb4e0;
    a2 = a2 - hi_aefe8 + (u32)(unsigned long)ref_t32_data_cb4e8;
    a1 = s6 - hi_aef10 + (u32)(unsigned long)ref_t32_data_cb3f4;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af004;
L_af004:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a1 = s5 - hi_aef3c + (u32)(unsigned long)ref_t32_data_cb45c;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (88));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (64));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (60));
    *(volatile u32 *)(unsigned long)(sp + (36)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (84));
    *(volatile u32 *)(unsigned long)(sp + (32)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (80));
    *(volatile u32 *)(unsigned long)(sp + (28)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (76));
    *(volatile u32 *)(unsigned long)(sp + (24)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (72));
    *(volatile u32 *)(unsigned long)(sp + (20)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (68));
    a0 = s1;
    callee = s0; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af04c;
L_af04c:
    a1 = s4 - hi_aeea8 + (u32)(unsigned long)ref_t32_data_cb380;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af058;
L_af058:
    a1 = hi_af058;
    a2 = s3;
    a1 = a1 - hi_af058 + (u32)(unsigned long)ref_t32_data_cb520;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af06c;
L_af06c:
    v0 = hi_af06c;
    v0 = v0 - hi_af06c + (u32)(unsigned long)ref_t32_data_cb598;
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = hi_af078;
    v0 = v0 - hi_af078 + (u32)(unsigned long)ref_t32_data_cb5a4;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    v0 = hi_af084;
    v0 = v0 - hi_af084 + (u32)(unsigned long)ref_t32_data_cb5b0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = hi_af090;
    v0 = v0 - hi_af090 + (u32)(unsigned long)ref_t32_data_cb5bc;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = hi_af09c;
    v0 = v0 - hi_af09c + (u32)(unsigned long)ref_t32_data_cb5c8;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = hi_af0a8;
    v0 = v0 - hi_af0a8 + (u32)(unsigned long)ref_t32_data_cb5d4;
    a3 = hi_af0b0;
    a2 = hi_af0b4;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a3 = a3 - hi_af0b0 + (u32)(unsigned long)ref_t32_data_cb580;
    a2 = a2 - hi_af0b4 + (u32)(unsigned long)ref_t32_data_cb58c;
    a1 = s6 - hi_aef10 + (u32)(unsigned long)ref_t32_data_cb3f4;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af0d0;
L_af0d0:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a1 = s5 - hi_aef3c + (u32)(unsigned long)ref_t32_data_cb45c;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (52));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (8));
    *(volatile u32 *)(unsigned long)(sp + (36)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (48));
    *(volatile u32 *)(unsigned long)(sp + (32)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (44));
    *(volatile u32 *)(unsigned long)(sp + (28)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (40));
    *(volatile u32 *)(unsigned long)(sp + (24)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (28));
    *(volatile u32 *)(unsigned long)(sp + (20)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (24));
    a0 = s1;
    callee = s0; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af118;
L_af118:
    a1 = s4 - hi_aeea8 + (u32)(unsigned long)ref_t32_data_cb380;
    callee = s0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_af124;
L_af124:
    s3 = s3 + 1;
L_af128:
    v0 = 2;
    s2 = s2 + 4;
    branch = (s3 != v0); s7 = s7 + 4;
    if (branch) goto L_aed68;
    goto L_af138;
L_af138:
    ra = *(volatile u32 *)(unsigned long)(sp + (100));
    s8 = *(volatile u32 *)(unsigned long)(sp + (96));
    s7 = *(volatile u32 *)(unsigned long)(sp + (92));
    s6 = *(volatile u32 *)(unsigned long)(sp + (88));
    s5 = *(volatile u32 *)(unsigned long)(sp + (84));
    s4 = *(volatile u32 *)(unsigned long)(sp + (80));
    s3 = *(volatile u32 *)(unsigned long)(sp + (76));
    s2 = *(volatile u32 *)(unsigned long)(sp + (72));
    s1 = *(volatile u32 *)(unsigned long)(sp + (68));
    s0 = *(volatile u32 *)(unsigned long)(sp + (64));
    sp = sp + 104;
    return ((u64)v1 << 32) | v0;
}
