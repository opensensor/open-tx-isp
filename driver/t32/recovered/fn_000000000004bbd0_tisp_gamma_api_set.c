/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1834[] __asm__("t32_data_e1834");
extern unsigned char ref_tisp_gamma_interp_by_ev[] __asm__("tisp_gamma_interp_by_ev");
extern unsigned char ref_tisp_gamma_update_curve[] __asm__("tisp_gamma_update_curve");
extern unsigned char ref_t32_data_bf754[] __asm__("t32_data_bf754");
extern unsigned char ref_t32_data_bf650[] __asm__("t32_data_bf650");
extern unsigned char ref_t32_data_bf54c[] __asm__("t32_data_bf54c");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tisp_gamma_strength_transform[] __asm__("tisp_gamma_strength_transform");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
extern unsigned char ref_tisp_gamma_addr_write_lut_rgb[] __asm__("tisp_gamma_addr_write_lut_rgb");
extern unsigned char ref_tisp_gamma_prepare_write_lut[] __asm__("tisp_gamma_prepare_write_lut");
u64 tisp_gamma_api_set(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_4bbd0 = ((u32)(unsigned long)ref_t32_data_e1834 + 0x8000U) & 0xffff0000U;
    const u32 hi_4bc44 = ((u32)(unsigned long)ref_tisp_gamma_interp_by_ev + 0x8000U) & 0xffff0000U;
    const u32 hi_4bc60 = ((u32)(unsigned long)ref_tisp_gamma_update_curve + 0x8000U) & 0xffff0000U;
    const u32 hi_4bc94 = ((u32)(unsigned long)ref_t32_data_bf754 + 0x8000U) & 0xffff0000U;
    const u32 hi_4bcb8 = ((u32)(unsigned long)ref_t32_data_bf650 + 0x8000U) & 0xffff0000U;
    const u32 hi_4bcdc = ((u32)(unsigned long)ref_t32_data_bf54c + 0x8000U) & 0xffff0000U;
    const u32 hi_4bd10 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4bd20 = ((u32)(unsigned long)ref_tisp_gamma_strength_transform + 0x8000U) & 0xffff0000U;
    const u32 hi_4bd30 = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4bd44 = ((u32)(unsigned long)ref_tisp_gamma_addr_write_lut_rgb + 0x8000U) & 0xffff0000U;
    const u32 hi_4bd40 = ((u32)(unsigned long)ref_tisp_gamma_prepare_write_lut + 0x8000U) & 0xffff0000U;
    const u32 hi_4bc74 = ((u32)(unsigned long)ref_tisp_gamma_strength_transform + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
L_4bbd0:
    v0 = hi_4bbd0;
    sp = sp + -32;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_4bbd0 + (u32)(unsigned long)ref_t32_data_e1834;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (28)) = ra;
    t7 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(t7 + (20));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    branch = (v0 != 0); s0 = a0;
    if (branch) goto L_4bc78;
    goto L_4bc08;
L_4bc08:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    v1 = 2;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (86));
    if (a0 == v1) { *(volatile u8 *)(unsigned long)(v0 + (86)) = 0; goto L_4bc1c; }
    goto L_4bc1c;
L_4bc1c:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    v1 = 2;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (87));
    if (a0 == v1) { *(volatile u8 *)(unsigned long)(v0 + (87)) = 0; goto L_4bc30; }
    goto L_4bc30;
L_4bc30:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (8));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = 1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_4bc44;
    v0 = v0 - hi_4bc44 + (u32)(unsigned long)ref_tisp_gamma_interp_by_ev;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bc54;
L_4bc54:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (8));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = hi_4bc60;
    v0 = v0 - hi_4bc60 + (u32)(unsigned long)ref_tisp_gamma_update_curve;
    callee = v0; a0 = s0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bc70;
L_4bc70:
    v0 = hi_4bc74; goto L_4bd24;
L_4bc78:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (20));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = 1;
    if (v1 != v0) { a0 = 2; goto L_4bcac; }
    goto L_4bc8c;
L_4bc8c:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    v1 = 2;
    a1 = hi_4bc94;
    *(volatile u8 *)(unsigned long)(v0 + (87)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(t7 + (20));
    a2 = 258;
    a1 = a1 - hi_4bc94 + (u32)(unsigned long)ref_t32_data_bf754; goto L_4bd10;
L_4bcac:
    branch = (v1 != a0); v0 = 3;
    if (branch) goto L_4bcd0;
    goto L_4bcb4;
L_4bcb4:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a1 = hi_4bcb8;
    a2 = 258;
    *(volatile u8 *)(unsigned long)(v0 + (87)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(t7 + (20));
    a1 = a1 - hi_4bcb8 + (u32)(unsigned long)ref_t32_data_bf650; goto L_4bd10;
L_4bcd0:
    if (v1 != v0) { a2 = 4; goto L_4bcf4; }
    goto L_4bcd8;
L_4bcd8:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a1 = hi_4bcdc;
    a2 = 258;
    *(volatile u8 *)(unsigned long)(v0 + (87)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(t7 + (20));
    a1 = a1 - hi_4bcdc + (u32)(unsigned long)ref_t32_data_bf54c; goto L_4bd10;
L_4bcf4:
    branch = (v1 != a2); v0 = -1;
    if (branch) goto L_4bd68;
    goto L_4bcfc;
L_4bcfc:
    v0 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a2 = 258;
    a1 = a1 + 4;
    *(volatile u8 *)(unsigned long)(v0 + (87)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(t7 + (20));
L_4bd10:
    v0 = hi_4bd10;
    v0 = v0 - hi_4bd10 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = a0 + 4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bd20;
L_4bd20:
    v0 = hi_4bd20;
L_4bd24:
    v0 = v0 - hi_4bd20 + (u32)(unsigned long)ref_tisp_gamma_strength_transform;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bd30;
L_4bd30:
    v0 = hi_4bd30;
    v1 = *(volatile u8 *)(unsigned long)(v0 - hi_4bd30 + (u32)(unsigned long)ref_t32_data_d03a0);
    v0 = 1;
    if (v1 != v0) { v0 = hi_4bd40; goto L_4bd54; }
    goto L_4bd44;
L_4bd44:
    v0 = hi_4bd44;
    a0 = s0;
    v0 = v0 - hi_4bd44 + (u32)(unsigned long)ref_tisp_gamma_addr_write_lut_rgb; goto L_4bd5c;
L_4bd54:
    a0 = (int8_t)s0;
    v0 = v0 - hi_4bd40 + (u32)(unsigned long)ref_tisp_gamma_prepare_write_lut;
L_4bd5c:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4bd64;
L_4bd64:
    v0 = 0;
L_4bd68:
    ra = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
