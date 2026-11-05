/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e3b40[] __asm__("t32_data_e3b40");
extern unsigned char ref_t32_data_e3b0c[] __asm__("t32_data_e3b0c");
extern unsigned char ref_t32_data_e3a99[] __asm__("t32_data_e3a99");
extern unsigned char ref_t32_data_e3ad0[] __asm__("t32_data_e3ad0");
extern unsigned char ref_t32_data_e3a98[] __asm__("t32_data_e3a98");
extern unsigned char ref_t32_data_e3aa0[] __asm__("t32_data_e3aa0");
extern unsigned char ref_t32_data_e3ab0[] __asm__("t32_data_e3ab0");
extern unsigned char ref_t32_data_e3a9a[] __asm__("t32_data_e3a9a");
extern unsigned char ref_t32_data_e3ac0[] __asm__("t32_data_e3ac0");
extern unsigned char ref_Tiziano_wdr_deghost_fpga[] __asm__("Tiziano_wdr_deghost_fpga");
extern unsigned char ref_Tiziano_wdr_fusion_fpga[] __asm__("Tiziano_wdr_fusion_fpga");
extern unsigned char ref_t32_data_e3aa4[] __asm__("t32_data_e3aa4");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_e3a80[] __asm__("t32_data_e3a80");
extern unsigned char ref_system_reg_write[] __asm__("system_reg_write");
extern unsigned char ref_tisp_wdr_params_hard_refresh[] __asm__("tisp_wdr_params_hard_refresh");
extern unsigned char ref_tisp_wdr_softout_reg_refresh[] __asm__("tisp_wdr_softout_reg_refresh");
u64 tisp_wdr_process(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_aab0c = ((u32)(unsigned long)ref_t32_data_e3b40 + 0x8000U) & 0xffff0000U;
    const u32 hi_aab50 = ((u32)(unsigned long)ref_t32_data_e3b0c + 0x8000U) & 0xffff0000U;
    const u32 hi_aab80 = ((u32)(unsigned long)ref_t32_data_e3a99 + 0x8000U) & 0xffff0000U;
    const u32 hi_aab88 = ((u32)(unsigned long)ref_t32_data_e3ad0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aab64 = ((u32)(unsigned long)ref_t32_data_e3a98 + 0x8000U) & 0xffff0000U;
    const u32 hi_aaba4 = ((u32)(unsigned long)ref_t32_data_e3aa0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aabb0 = ((u32)(unsigned long)ref_t32_data_e3ab0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aab68 = ((u32)(unsigned long)ref_t32_data_e3a9a + 0x8000U) & 0xffff0000U;
    const u32 hi_aabc4 = ((u32)(unsigned long)ref_t32_data_e3ac0 + 0x8000U) & 0xffff0000U;
    const u32 hi_aabe4 = ((u32)(unsigned long)ref_Tiziano_wdr_deghost_fpga + 0x8000U) & 0xffff0000U;
    const u32 hi_aac24 = ((u32)(unsigned long)ref_Tiziano_wdr_fusion_fpga + 0x8000U) & 0xffff0000U;
    const u32 hi_aac6c = ((u32)(unsigned long)ref_t32_data_e3aa4 + 0x8000U) & 0xffff0000U;
    const u32 hi_aacb8 = ((u32)(unsigned long)ref_t32_data_e3aa4 + 0x8000U) & 0xffff0000U;
    const u32 hi_aace0 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_aad18 = ((u32)(unsigned long)ref_t32_data_e3a80 + 0x8000U) & 0xffff0000U;
    const u32 hi_aad30 = ((u32)(unsigned long)ref_system_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_aad78 = ((u32)(unsigned long)ref_tisp_wdr_params_hard_refresh + 0x8000U) & 0xffff0000U;
    const u32 hi_aad88 = ((u32)(unsigned long)ref_tisp_wdr_softout_reg_refresh + 0x8000U) & 0xffff0000U;
    const u32 hi_aad28 = ((u32)(unsigned long)ref_tisp_wdr_params_hard_refresh + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
L_aab0c:
    v0 = hi_aab0c;
    sp = sp + -72;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_aab0c + (u32)(unsigned long)ref_t32_data_e3b40;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (68)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s3 = a0;
    a0 = hi_aab50;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s5 = *(volatile u32 *)(unsigned long)(v0 + (20));
    v0 = *(volatile u32 *)(unsigned long)(a0 - hi_aab50 + (u32)(unsigned long)ref_t32_data_e3b0c);
    s8 = hi_aab64;
    s4 = hi_aab68;
    v0 = v0 + 1;
    v1 = v0 ^ 0x1e;
    if (v1 == 0) v0 = 0;
    v1 = *(volatile u8 *)(unsigned long)(s0 + (1832));
    *(volatile u32 *)(unsigned long)(a0 - hi_aab50 + (u32)(unsigned long)ref_t32_data_e3b0c) = v0;
    v0 = hi_aab80;
    *(volatile u8 *)(unsigned long)(v0 - hi_aab80 + (u32)(unsigned long)ref_t32_data_e3a99) = v1;
    v1 = hi_aab88;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (1831));
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_aab88 + (u32)(unsigned long)ref_t32_data_e3ad0);
    v1 = 1;
    branch = (a0 != v1); *(volatile u8 *)(unsigned long)(s8 - hi_aab64 + (u32)(unsigned long)ref_t32_data_e3a98) = v0;
    if (branch) goto L_aabdc;
    goto L_aaba0;
L_aaba0:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    a0 = hi_aaba4;
    a0 = *(volatile u32 *)(unsigned long)(a0 - hi_aaba4 + (u32)(unsigned long)ref_t32_data_e3aa0);
    *(volatile u32 *)(unsigned long)(s1 + (8)) = v1;
    v1 = hi_aabb0;
    v1 = *(volatile u32 *)(unsigned long)(v1 - hi_aabb0 + (u32)(unsigned long)ref_t32_data_e3ab0);
    *(volatile u32 *)(unsigned long)(s1 + (12)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(s4 - hi_aab68 + (u32)(unsigned long)ref_t32_data_e3a9a);
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v1;
    v1 = hi_aabc4;
    v1 = *(volatile u32 *)(unsigned long)(v1 - hi_aabc4 + (u32)(unsigned long)ref_t32_data_e3ac0);
    branch = (a0 != 0); *(volatile u32 *)(unsigned long)(s1 + (4)) = v1;
    if (branch) goto L_aabd8;
    goto L_aabd4;
L_aabd4:
    *(volatile u32 *)(unsigned long)(s1 + (8)) = v1;
L_aabd8:
    v1 = 1;
L_aabdc:
    if (v0 != v1) { s7 = 0; goto L_aac10; }
    goto L_aabe4;
L_aabe4:
    v0 = hi_aabe4;
    v0 = v0 - hi_aabe4 + (u32)(unsigned long)ref_Tiziano_wdr_deghost_fpga;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aabf4;
L_aabf4:
    s6 = *(volatile u16 *)(unsigned long)(s0 + (494));
    a2 = *(volatile u16 *)(unsigned long)(s0 + (506));
    a1 = *(volatile u16 *)(unsigned long)(s0 + (508));
    v1 = *(volatile u16 *)(unsigned long)(s0 + (514));
    s2 = *(volatile u16 *)(unsigned long)(s0 + (516));
    s7 = *(volatile u16 *)(unsigned long)(s0 + (504)); goto L_aac24;
L_aac10:
    s2 = 0;
    v1 = 0;
    a1 = 0;
    a2 = 0;
    s6 = 0;
L_aac24:
    v0 = hi_aac24;
    a0 = s3;
    v0 = v0 - hi_aac24 + (u32)(unsigned long)ref_Tiziano_wdr_fusion_fpga;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = a1;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = a2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aac40;
L_aac40:
    v0 = *(volatile u8 *)(unsigned long)(s8 - hi_aab64 + (u32)(unsigned long)ref_t32_data_e3a98);
    a0 = 1;
    a2 = *(volatile u32 *)(unsigned long)(sp + (16));
    a1 = *(volatile u32 *)(unsigned long)(sp + (20));
    branch = (v0 != a0); v1 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_aace0;
    goto L_aac58;
L_aac58:
    branch = (s6 != v0); ;
    if (branch) goto L_aaca4;
    goto L_aac60;
L_aac60:
    branch = (a2 == s6); v0 = s2;
    if (branch) goto L_aac90;
    goto L_aac68;
L_aac68:
    branch = (a1 == s6); v0 = hi_aac6c;
    if (branch) goto L_aac8c;
    goto L_aac70;
L_aac70:
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_aac6c + (u32)(unsigned long)ref_t32_data_e3aa4);
    if (a0 != 0) { v0 = s2; goto L_aac90; }
    goto L_aac7c;
L_aac7c:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_aac6c + (u32)(unsigned long)ref_t32_data_e3aa0);
    v0 = (u32)v1 < (u32)(v0);
    if (v0 == 0) { s2 = s7; goto L_aacdc; }
    goto L_aac8c;
L_aac8c:
    v0 = s2;
L_aac90:
    s2 = (u32)s7 < (u32)(s2);
    if (s2 != 0) { v0 = s7; goto L_aac9c; }
    goto L_aac9c;
L_aac9c:
    s2 = v0 & 0xffff; goto L_aacdc;
L_aaca4:
    if (s6 != 0) { s2 = *(volatile u16 *)(unsigned long)(s0 + (190)); goto L_aacdc; }
    goto L_aacac;
L_aacac:
    if (a2 == v0) { *(volatile u16 *)(unsigned long)(s0 + (190)) = s2; goto L_aace0; }
    goto L_aacb4;
L_aacb4:
    branch = (a1 == v0); v0 = hi_aacb8;
    if (branch) goto L_aacdc;
    goto L_aacbc;
L_aacbc:
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_aacb8 + (u32)(unsigned long)ref_t32_data_e3aa4);
    if (a0 != 0) { *(volatile u16 *)(unsigned long)(s0 + (190)) = s2; goto L_aace0; }
    goto L_aacc8;
L_aacc8:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_aacb8 + (u32)(unsigned long)ref_t32_data_e3aa0);
    v0 = (u32)v1 < (u32)(v0);
    if (v0 != 0) { *(volatile u16 *)(unsigned long)(s0 + (190)) = s2; goto L_aace0; }
    goto L_aacd8;
L_aacd8:
    s2 = *(volatile u16 *)(unsigned long)(s0 + (190));
L_aacdc:
    *(volatile u16 *)(unsigned long)(s0 + (190)) = s2;
L_aace0:
    s2 = hi_aace0;
    a2 = 54;
    a1 = s1 + 36;
    s2 = s2 - hi_aace0 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s2; a0 = s5 + 700;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aacf8;
L_aacf8:
    v0 = *(volatile u16 *)(unsigned long)(s1 + (90));
    a0 = s5 + 8;
    a2 = 20;
    *(volatile u16 *)(unsigned long)(s5 + (776)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s1 + (92));
    a1 = s1 + 16;
    callee = s2; *(volatile u16 *)(unsigned long)(s5 + (778)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aad18;
L_aad18:
    v0 = hi_aad18;
    a0 = *(volatile u8 *)(unsigned long)(v0 - hi_aad18 + (u32)(unsigned long)ref_t32_data_e3a80);
    v1 = 1;
    if (a0 != v1) { v0 = hi_aad28; goto L_aad7c; }
    goto L_aad2c;
L_aad2c:
    s2 = 0x2U << 16;
    s1 = hi_aad30;
    a1 = 1;
    a0 = s2 | 0x8008;
    s1 = s1 - hi_aad30 + (u32)(unsigned long)ref_system_reg_write;
    callee = s1; *(volatile u8 *)(unsigned long)(v0 - hi_aad18 + (u32)(unsigned long)ref_t32_data_e3a80) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aad48;
L_aad48:
    v0 = *(volatile u8 *)(unsigned long)(s5 + (1032));
    a1 = *(volatile u8 *)(unsigned long)(s0 + (1831));
    a0 = s2 | 0x800c;
    v0 = v0 & 0x1;
    v1 = v0 << (0x4 & 31);
    v0 = *(volatile u8 *)(unsigned long)(s5 + (1033));
    a1 = a1 & 0x1;
    v0 = v0 & 0x1;
    v0 = v0 << (0x8 & 31);
    v0 = v1 | v0;
    callee = s1; a1 = v0 | a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aad78;
L_aad78:
    v0 = hi_aad78;
L_aad7c:
    v0 = v0 - hi_aad78 + (u32)(unsigned long)ref_tisp_wdr_params_hard_refresh;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aad88;
L_aad88:
    v0 = hi_aad88;
    v0 = v0 - hi_aad88 + (u32)(unsigned long)ref_tisp_wdr_softout_reg_refresh;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_aad98;
L_aad98:
    v0 = *(volatile u8 *)(unsigned long)(s4 - hi_aab68 + (u32)(unsigned long)ref_t32_data_e3a9a);
    ra = *(volatile u32 *)(unsigned long)(sp + (68));
    s8 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = v0 ^ 0xff;
    v0 = (u32)0 < (u32)(v0);
    *(volatile u8 *)(unsigned long)(s4 - hi_aab68 + (u32)(unsigned long)ref_t32_data_e3a9a) = v0;
    s7 = *(volatile u32 *)(unsigned long)(sp + (60));
    s6 = *(volatile u32 *)(unsigned long)(sp + (56));
    s5 = *(volatile u32 *)(unsigned long)(sp + (52));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    v0 = 0;
    sp = sp + 72;
    return ((u64)v1 << 32) | v0;
}
