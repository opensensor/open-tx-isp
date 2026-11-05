/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c6648[] __asm__("t32_data_c6648");
extern unsigned char ref_sprintf[] __asm__("sprintf");
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
extern unsigned char ref_t32_data_c6654[] __asm__("t32_data_c6654");
extern unsigned char ref_t32_data_c6660[] __asm__("t32_data_c6660");
extern unsigned char ref_t32_data_c666c[] __asm__("t32_data_c666c");
extern unsigned char ref_t32_data_c6678[] __asm__("t32_data_c6678");
extern unsigned char ref_t32_data_c6684[] __asm__("t32_data_c6684");
extern unsigned char ref_t32_data_c6690[] __asm__("t32_data_c6690");
extern unsigned char ref_t32_data_c669c[] __asm__("t32_data_c669c");
extern unsigned char ref_t32_data_c66a8[] __asm__("t32_data_c66a8");
extern unsigned char ref_t32_data_c66b4[] __asm__("t32_data_c66b4");
extern unsigned char ref_t32_data_cf5b4[] __asm__("t32_data_cf5b4");
extern unsigned char ref_private_misc_register[] __asm__("private_misc_register");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_c66c0[] __asm__("t32_data_c66c0");
extern unsigned char ref_t32_data_c66e4[] __asm__("t32_data_c66e4");
u64 tx_isp_frame_chan_misc_register(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_12a40 = ((u32)(unsigned long)ref_t32_data_c6648 + 0x8000U) & 0xffff0000U;
    const u32 hi_12a44 = (((u32)(unsigned long)ref_sprintf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_12a5c = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_12a6c = ((u32)(unsigned long)ref_t32_data_c6654 + 0x8000U) & 0xffff0000U;
    const u32 hi_12aa4 = ((u32)(unsigned long)ref_t32_data_c6660 + 0x8000U) & 0xffff0000U;
    const u32 hi_12adc = ((u32)(unsigned long)ref_t32_data_c666c + 0x8000U) & 0xffff0000U;
    const u32 hi_12b14 = ((u32)(unsigned long)ref_t32_data_c6678 + 0x8000U) & 0xffff0000U;
    const u32 hi_12b4c = ((u32)(unsigned long)ref_t32_data_c6684 + 0x8000U) & 0xffff0000U;
    const u32 hi_12b84 = ((u32)(unsigned long)ref_t32_data_c6690 + 0x8000U) & 0xffff0000U;
    const u32 hi_12bbc = ((u32)(unsigned long)ref_t32_data_c669c + 0x8000U) & 0xffff0000U;
    const u32 hi_12bf4 = ((u32)(unsigned long)ref_t32_data_c66a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_12c2c = ((u32)(unsigned long)ref_t32_data_c66b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_12c6c = ((u32)(unsigned long)ref_t32_data_cf5b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_12c78 = ((u32)(unsigned long)ref_private_misc_register + 0x8000U) & 0xffff0000U;
    const u32 hi_12c8c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_12c9c = ((u32)(unsigned long)ref_t32_data_c66c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_12cb4 = ((u32)(unsigned long)ref_t32_data_c66e4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
    sp = sp + -32;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    a2 = *(volatile u32 *)(unsigned long)(a0 + (720));
    s1 = a0 + 700;
    a1 = hi_12a40;
    v0 = hi_12a44;
    s0 = a0;
    a1 = a1 - hi_12a40 + (u32)(unsigned long)ref_t32_data_c6648;
    v0 = v0 - hi_12a44 + ((u32)(unsigned long)ref_sprintf + (0));
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12a5c;
L_12a5c:
    v0 = hi_12a5c;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_12a5c + (u32)(unsigned long)ref_t32_data_d9008);
    if (v0 == 0) { v0 = 255; goto L_12c68; }
    goto L_12a6c;
L_12a6c:
    v0 = hi_12a6c;
    v1 = s1;
    v0 = v0 - hi_12a6c + (u32)(unsigned long)ref_t32_data_c6654;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12a7c:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12a98;
    goto L_12a8c;
L_12a8c:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12a7c;
    goto L_12a94;
L_12a94:
    a0 = at;
L_12a98:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 60;
    if (branch) goto L_12c68;
    goto L_12aa4;
L_12aa4:
    v0 = hi_12aa4;
    v1 = s1;
    v0 = v0 - hi_12aa4 + (u32)(unsigned long)ref_t32_data_c6660;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12ab4:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12ad0;
    goto L_12ac4;
L_12ac4:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12ab4;
    goto L_12acc;
L_12acc:
    a0 = at;
L_12ad0:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 59;
    if (branch) goto L_12c68;
    goto L_12adc;
L_12adc:
    v0 = hi_12adc;
    v1 = s1;
    v0 = v0 - hi_12adc + (u32)(unsigned long)ref_t32_data_c666c;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12aec:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12b08;
    goto L_12afc;
L_12afc:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12aec;
    goto L_12b04;
L_12b04:
    a0 = at;
L_12b08:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 58;
    if (branch) goto L_12c68;
    goto L_12b14;
L_12b14:
    v0 = hi_12b14;
    v1 = s1;
    v0 = v0 - hi_12b14 + (u32)(unsigned long)ref_t32_data_c6678;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12b24:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12b40;
    goto L_12b34;
L_12b34:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12b24;
    goto L_12b3c;
L_12b3c:
    a0 = at;
L_12b40:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 44;
    if (branch) goto L_12c68;
    goto L_12b4c;
L_12b4c:
    v0 = hi_12b4c;
    v1 = s1;
    v0 = v0 - hi_12b4c + (u32)(unsigned long)ref_t32_data_c6684;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12b5c:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12b78;
    goto L_12b6c;
L_12b6c:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12b5c;
    goto L_12b74;
L_12b74:
    a0 = at;
L_12b78:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 43;
    if (branch) goto L_12c68;
    goto L_12b84;
L_12b84:
    v0 = hi_12b84;
    v1 = s1;
    v0 = v0 - hi_12b84 + (u32)(unsigned long)ref_t32_data_c6690;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12b94:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12bb0;
    goto L_12ba4;
L_12ba4:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12b94;
    goto L_12bac;
L_12bac:
    a0 = at;
L_12bb0:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 42;
    if (branch) goto L_12c68;
    goto L_12bbc;
L_12bbc:
    v0 = hi_12bbc;
    v1 = s1;
    v0 = v0 - hi_12bbc + (u32)(unsigned long)ref_t32_data_c669c;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12bcc:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12be8;
    goto L_12bdc;
L_12bdc:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12bcc;
    goto L_12be4;
L_12be4:
    a0 = at;
L_12be8:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 41;
    if (branch) goto L_12c68;
    goto L_12bf4;
L_12bf4:
    v0 = hi_12bf4;
    v1 = s1;
    v0 = v0 - hi_12bf4 + (u32)(unsigned long)ref_t32_data_c66a8;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12c04:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12c20;
    goto L_12c14;
L_12c14:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12c04;
    goto L_12c1c;
L_12c1c:
    a0 = at;
L_12c20:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 40;
    if (branch) goto L_12c68;
    goto L_12c2c;
L_12c2c:
    v0 = hi_12c2c;
    v1 = s1;
    v0 = v0 - hi_12c2c + (u32)(unsigned long)ref_t32_data_c66b4;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
L_12c3c:
    at = *(volatile u8 *)(unsigned long)(v0 + (0));
    v1 = v1 + 1;
    branch = (at != a0); v0 = v0 + 1;
    if (branch) goto L_12c58;
    goto L_12c4c;
L_12c4c:
    branch = (a0 != 0); a0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    if (branch) goto L_12c3c;
    goto L_12c54;
L_12c54:
    a0 = at;
L_12c58:
    a0 = a0 - at;
    branch = (a0 == 0); v0 = 39;
    if (branch) goto L_12c68;
    goto L_12c64;
L_12c64:
    v0 = 255;
L_12c68:
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
    v0 = hi_12c6c;
    v0 = v0 - hi_12c6c + (u32)(unsigned long)ref_t32_data_cf5b4;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = v0;
    v0 = hi_12c78;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = s1;
    v0 = v0 - hi_12c78 + (u32)(unsigned long)ref_private_misc_register;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12c8c;
L_12c8c:
    v1 = hi_12c8c;
    branch = ((s32)v0 >= 0); v1 = v1 - hi_12c8c + (u32)(unsigned long)ref_isp_printf;
    if (branch) goto L_12cb4;
    goto L_12c98;
L_12c98:
    a2 = *(volatile u32 *)(unsigned long)(s0 + (720));
    a1 = hi_12c9c;
    a1 = a1 - hi_12c9c + (u32)(unsigned long)ref_t32_data_c66c0;
    callee = v1; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12cac;
L_12cac:
    v0 = -2; goto L_12cd4;
L_12cb4:
    a1 = hi_12cb4;
    a2 = s1;
    a1 = a1 - hi_12cb4 + (u32)(unsigned long)ref_t32_data_c66e4;
    callee = v1; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12cc8;
L_12cc8:
    v0 = 1;
    *(volatile u32 *)(unsigned long)(s0 + (40)) = v0;
    v0 = 0;
L_12cd4:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
