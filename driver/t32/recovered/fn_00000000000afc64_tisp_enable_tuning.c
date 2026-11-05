/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_private_vmalloc[] __asm__("private_vmalloc");
extern unsigned char ref_t32_data_f0904[] __asm__("t32_data_f0904");
extern unsigned char ref_t32_data_c3000[] __asm__("t32_data_c3000");
extern unsigned char ref_t32_data_cb6b0[] __asm__("t32_data_cb6b0");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_system_irq_func_set[] __asm__("system_irq_func_set");
extern unsigned char ref_tisp_top_frame_count[] __asm__("tisp_top_frame_count");
u64 tisp_enable_tuning(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_afc68 = ((u32)(unsigned long)ref_private_vmalloc + 0x8000U) & 0xffff0000U;
    const u32 hi_afc90 = ((u32)(unsigned long)ref_t32_data_f0904 + 0x8000U) & 0xffff0000U;
    const u32 hi_afc9c = ((u32)(unsigned long)ref_t32_data_c3000 + 0x8000U) & 0xffff0000U;
    const u32 hi_afca0 = ((u32)(unsigned long)ref_t32_data_cb6b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_afca4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_afcc8 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_afe78 = ((u32)(unsigned long)ref_system_irq_func_set + 0x8000U) & 0xffff0000U;
    const u32 hi_afe74 = ((u32)(unsigned long)ref_tisp_top_frame_count + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_afc64:
    sp = sp + -40;
    v0 = hi_afc68;
    a0 = 4532;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    v0 = v0 - hi_afc68 + (u32)(unsigned long)ref_private_vmalloc;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_afc90;
L_afc90:
    s2 = hi_afc90;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(s2 - hi_afc90 + (u32)(unsigned long)ref_t32_data_f0904) = v0;
    if (branch) goto L_afcc8;
    goto L_afc9c;
L_afc9c:
    a2 = hi_afc9c;
    a1 = hi_afca0;
    v0 = hi_afca4;
    a3 = 94;
    a2 = a2 - hi_afc9c + (u32)(unsigned long)ref_t32_data_c3000;
    a1 = a1 - hi_afca0 + (u32)(unsigned long)ref_t32_data_cb6b0;
    v0 = v0 - hi_afca4 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_afcc0;
L_afcc0:
    v0 = -1; goto L_afe94;
L_afcc8:
    s0 = hi_afcc8;
    a2 = 4532;
    a0 = v0;
    s0 = s0 - hi_afcc8 + ((u32)(unsigned long)ref_memset + (0));
    callee = s0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_afce0;
L_afce0:
    s1 = s0;
    v0 = 0;
    a0 = -128;
    a2 = 4;
L_afcf0:
    v1 = *(volatile u32 *)(unsigned long)(s2 - hi_afc90 + (u32)(unsigned long)ref_t32_data_f0904);
    v1 = v1 + v0;
    *(volatile u8 *)(unsigned long)(v1 + (0)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s2 - hi_afc90 + (u32)(unsigned long)ref_t32_data_f0904);
    a1 = v1 + v0;
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(a1 + (4)) = a0;
    *(volatile u8 *)(unsigned long)(a1 + (8)) = a0;
    *(volatile u8 *)(unsigned long)(a1 + (12)) = a0;
    branch = (v0 != a2); *(volatile u8 *)(unsigned long)(a1 + (16)) = a0;
    if (branch) goto L_afcf0;
    goto L_afd1c;
L_afd1c:
    v0 = v1;
    a3 = v1 + 512;
    a1 = v1;
    t0 = -128;
    a0 = a1;
L_afd30:
    a2 = 16;
L_afd34:
    a2 = a2 + -1;
    *(volatile u32 *)(unsigned long)(a0 + (1060)) = 0;
    *(volatile u8 *)(unsigned long)(a0 + (1064)) = t0;
    branch = (a2 != 0); a0 = a0 + 8;
    if (branch) goto L_afd34;
    goto L_afd48;
L_afd48:
    a1 = a1 + 128;
    branch = (a1 != a3); a0 = a1;
    if (branch) goto L_afd30;
    goto L_afd54;
L_afd54:
    a2 = 4;
    a1 = 1;
    a0 = 15;
    t8 = 13;
    t7 = 64;
    t6 = -112;
    t5 = -64;
    t4 = 3;
    t3 = 42;
    t2 = 22;
    t1 = 200;
    t0 = 19;
    a3 = 58;
L_afd88:
    a2 = a2 + -1;
    *(volatile u32 *)(unsigned long)(v0 + (1572)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (1576)) = a1;
    *(volatile u32 *)(unsigned long)(v0 + (1580)) = a1;
    *(volatile u8 *)(unsigned long)(v0 + (1584)) = a0;
    *(volatile u8 *)(unsigned long)(v0 + (1585)) = a0;
    *(volatile u8 *)(unsigned long)(v0 + (1592)) = t8;
    *(volatile u8 *)(unsigned long)(v0 + (1593)) = t7;
    *(volatile u8 *)(unsigned long)(v0 + (1594)) = t6;
    *(volatile u8 *)(unsigned long)(v0 + (1595)) = t5;
    *(volatile u32 *)(unsigned long)(v0 + (1596)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (1600)) = a1;
    *(volatile u32 *)(unsigned long)(v0 + (1604)) = a1;
    *(volatile u8 *)(unsigned long)(v0 + (1608)) = a0;
    *(volatile u8 *)(unsigned long)(v0 + (1609)) = a0;
    *(volatile u32 *)(unsigned long)(v0 + (1612)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (1616)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (1620)) = a1;
    *(volatile u32 *)(unsigned long)(v0 + (1624)) = t4;
    *(volatile u8 *)(unsigned long)(v0 + (1628)) = a0;
    *(volatile u8 *)(unsigned long)(v0 + (1629)) = a0;
    *(volatile u8 *)(unsigned long)(v0 + (1632)) = 0;
    *(volatile u16 *)(unsigned long)(v0 + (1634)) = t3;
    *(volatile u16 *)(unsigned long)(v0 + (1636)) = t2;
    *(volatile u16 *)(unsigned long)(v0 + (1638)) = t1;
    *(volatile u16 *)(unsigned long)(v0 + (1640)) = t0;
    *(volatile u16 *)(unsigned long)(v0 + (1642)) = a3;
    branch = (a2 != 0); v0 = v0 + 72;
    if (branch) goto L_afd88;
    goto L_afdfc;
L_afdfc:
    v0 = v1 + 2164;
    a0 = v1 + 1872;
    v1 = v1 + 4004;
L_afe08:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = 0;
    v0 = v0 + 460;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(a0 + (52)) = 0;
    branch = (v1 != v0); a0 = a0 + 76;
    if (branch) goto L_afe08;
    goto L_afe24;
L_afe24:
    s0 = 0;
    s4 = 44;
    s3 = 4;
    a0 = s0 * s4;
L_afe34:
    v1 = *(volatile u32 *)(unsigned long)(s2 - hi_afc90 + (u32)(unsigned long)ref_t32_data_f0904);
    a2 = 16;
    a1 = 0;
    s0 = s0 + 1;
    v0 = v1 + a0;
    *(volatile u32 *)(unsigned long)(v0 + (4004)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4008)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4012)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4016)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4020)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4024)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4028)) = 0;
    callee = s1; a0 = v0 + 4032;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_afe6c;
L_afe6c:
    branch = (s0 != s3); a0 = s0 * s4;
    if (branch) goto L_afe34;
    goto L_afe74;
L_afe74:
    a2 = hi_afe74;
    v0 = hi_afe78;
    v0 = v0 - hi_afe78 + (u32)(unsigned long)ref_system_irq_func_set;
    a2 = a2 - hi_afe74 + (u32)(unsigned long)ref_tisp_top_frame_count;
    a1 = 57;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_afe90;
L_afe90:
    v0 = 0;
L_afe94:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
