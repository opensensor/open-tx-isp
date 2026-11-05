/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e3b40[] __asm__("t32_data_e3b40");
extern unsigned char ref_t32_data_e3b30[] __asm__("t32_data_e3b30");
extern unsigned char ref_private_kmalloc[] __asm__("private_kmalloc");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_c2b10[] __asm__("t32_data_c2b10");
extern unsigned char ref_t32_data_c2c50[] __asm__("t32_data_c2c50");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_tisp_wdr_interplate[] __asm__("tisp_wdr_interplate");
extern unsigned char ref_tisp_tmo_timeratio_curve_adjust[] __asm__("tisp_tmo_timeratio_curve_adjust");
extern unsigned char ref_tisp_wdr_get_lum_s[] __asm__("tisp_wdr_get_lum_s");
extern unsigned char ref_tisp_wdr_paixu[] __asm__("tisp_wdr_paixu");
extern unsigned char ref_t32_data_e3a9a[] __asm__("t32_data_e3a9a");
extern unsigned char ref_t32_data_e3b2c[] __asm__("t32_data_e3b2c");
extern unsigned char ref_t32_data_e3b2a[] __asm__("t32_data_e3b2a");
extern unsigned char ref_t32_data_e3b20[] __asm__("t32_data_e3b20");
extern unsigned char ref_t32_data_e3b14[] __asm__("t32_data_e3b14");
extern unsigned char ref_t32_data_e3b3a[] __asm__("t32_data_e3b3a");
extern unsigned char ref_t32_data_e3b3c[] __asm__("t32_data_e3b3c");
extern unsigned char ref_t32_data_e3b10[] __asm__("t32_data_e3b10");
extern unsigned char ref_tisp_wdr_log2[] __asm__("tisp_wdr_log2");
extern unsigned char ref_private_kfree[] __asm__("private_kfree");
u64 Tiziano_wdr_fusion_fpga(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[242] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_a557c = ((u32)(unsigned long)ref_t32_data_e3b40 + 0x8000U) & 0xffff0000U;
    const u32 hi_a55d4 = ((u32)(unsigned long)ref_t32_data_e3b30 + 0x8000U) & 0xffff0000U;
    const u32 hi_a56dc = ((u32)(unsigned long)ref_private_kmalloc + 0x8000U) & 0xffff0000U;
    const u32 hi_a571c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_a5720 = ((u32)(unsigned long)ref_t32_data_c2b10 + 0x8000U) & 0xffff0000U;
    const u32 hi_a574c = ((u32)(unsigned long)ref_t32_data_c2c50 + 0x8000U) & 0xffff0000U;
    const u32 hi_a57e0 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_a5934 = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a5b04 = ((u32)(unsigned long)ref_tisp_tmo_timeratio_curve_adjust + 0x8000U) & 0xffff0000U;
    const u32 hi_a5c20 = ((u32)(unsigned long)ref_tisp_wdr_get_lum_s + 0x8000U) & 0xffff0000U;
    const u32 hi_a5c80 = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a5cbc = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a5f70 = ((u32)(unsigned long)ref_tisp_wdr_paixu + 0x8000U) & 0xffff0000U;
    const u32 hi_a60f0 = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a61bc = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a6214 = ((u32)(unsigned long)ref_tisp_wdr_get_lum_s + 0x8000U) & 0xffff0000U;
    const u32 hi_a6548 = ((u32)(unsigned long)ref_t32_data_e3a9a + 0x8000U) & 0xffff0000U;
    const u32 hi_a6560 = ((u32)(unsigned long)ref_t32_data_e3b2c + 0x8000U) & 0xffff0000U;
    const u32 hi_a659c = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a6618 = ((u32)(unsigned long)ref_t32_data_e3b2a + 0x8000U) & 0xffff0000U;
    const u32 hi_a66cc = ((u32)(unsigned long)ref_t32_data_e3b20 + 0x8000U) & 0xffff0000U;
    const u32 hi_a67e4 = ((u32)(unsigned long)ref_t32_data_e3b20 + 0x8000U) & 0xffff0000U;
    const u32 hi_a67ec = ((u32)(unsigned long)ref_t32_data_e3b14 + 0x8000U) & 0xffff0000U;
    const u32 hi_a687c = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a68e8 = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a6954 = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a69d4 = ((u32)(unsigned long)ref_t32_data_e3b3a + 0x8000U) & 0xffff0000U;
    const u32 hi_a6a00 = ((u32)(unsigned long)ref_t32_data_e3b3c + 0x8000U) & 0xffff0000U;
    const u32 hi_a6a1c = ((u32)(unsigned long)ref_t32_data_e3b10 + 0x8000U) & 0xffff0000U;
    const u32 hi_a6d9c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_a7094 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_a72ec = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_a7338 = ((u32)(unsigned long)ref_tisp_wdr_get_lum_s + 0x8000U) & 0xffff0000U;
    const u32 hi_a73c8 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_a73f0 = ((u32)(unsigned long)ref_tisp_wdr_interplate + 0x8000U) & 0xffff0000U;
    const u32 hi_a75b8 = ((u32)(unsigned long)ref_tisp_wdr_log2 + 0x8000U) & 0xffff0000U;
    const u32 hi_a7660 = ((u32)(unsigned long)ref_private_kfree + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[178];
L_a557c:
    v0 = hi_a557c;
    sp = sp + -712;
    v1 = a0 << (0x2 & 31);
    v0 = v0 - hi_a557c + (u32)(unsigned long)ref_t32_data_e3b40;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(sp + (708)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (704)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (696)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (692)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (688)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (684)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (680)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (700)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (676)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (672)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (712)) = a0;
    *(volatile u32 *)(unsigned long)(sp + (512)) = 0;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    s7 = *(volatile u32 *)(unsigned long)(v0 + (24));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (20));
    a0 = hi_a55d4;
    s5 = 0x208U << 16;
    *(volatile u32 *)(unsigned long)(sp + (560)) = v0;
    s2 = v0 + 880;
    v0 = v0 + 930;
    *(volatile u32 *)(unsigned long)(sp + (640)) = v0;
    v0 = s7 + 6224;
    *(volatile u32 *)(unsigned long)(sp + (644)) = v0;
    v0 = s7 + 7124;
    *(volatile u32 *)(unsigned long)(sp + (648)) = v0;
    v0 = s7 + 8024;
    *(volatile u32 *)(unsigned long)(sp + (592)) = v0;
    v0 = s0 + 1758;
    *(volatile u32 *)(unsigned long)(sp + (628)) = v0;
    v0 = s0 + 1835;
    *(volatile u32 *)(unsigned long)(sp + (596)) = v0;
    v0 = s0 + 802;
    *(volatile u32 *)(unsigned long)(sp + (600)) = v0;
    v0 = s0 + 988;
    *(volatile u32 *)(unsigned long)(sp + (572)) = v0;
    v0 = s0 + 1038;
    *(volatile u32 *)(unsigned long)(sp + (576)) = v0;
    v0 = s0 + 1088;
    *(volatile u32 *)(unsigned long)(sp + (580)) = v0;
    v0 = s0 + 1138;
    *(volatile u32 *)(unsigned long)(sp + (584)) = v0;
    v0 = s0 + 1188;
    *(volatile u32 *)(unsigned long)(sp + (588)) = v0;
    v0 = s0 + 1516;
    *(volatile u32 *)(unsigned long)(sp + (604)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (516)) = 0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (104));
    s3 = *(volatile u32 *)(unsigned long)(s1 + (4));
    *(volatile u32 *)(unsigned long)(sp + (492)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (652)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    *(volatile u32 *)(unsigned long)(sp + (496)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (500)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (632)) = v0;
    v0 = a0 - hi_a55d4 + (u32)(unsigned long)ref_t32_data_e3b30;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (8));
    *(volatile u32 *)(unsigned long)(sp + (480)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (484)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (564)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s7 + (6220));
    *(volatile u16 *)(unsigned long)(sp + (488)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (468)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (552)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (768));
    *(volatile u32 *)(unsigned long)(sp + (472)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (476)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (656)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (790));
    *(volatile u32 *)(unsigned long)(sp + (444)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (448)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (660)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(a0 - hi_a55d4 + (u32)(unsigned long)ref_t32_data_e3b30);
    *(volatile u32 *)(unsigned long)(sp + (452)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (536)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (540)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (528)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (532)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (520)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (524)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (608)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (2));
    s6 = hi_a56dc;
    s6 = s6 - hi_a56dc + (u32)(unsigned long)ref_private_kmalloc;
    *(volatile u32 *)(unsigned long)(sp + (612)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (4));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (6));
    a1 = s5 + 32;
    a0 = 450;
    *(volatile u32 *)(unsigned long)(sp + (616)) = v1;
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (620)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5704;
L_a5704:
    a1 = s5 | 0x20;
    a0 = 450;
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (544)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5714;
L_a5714:
    *(volatile u32 *)(unsigned long)(sp + (548)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (756));
    a3 = hi_a571c;
    a1 = hi_a5720;
    *(volatile u32 *)(unsigned long)(sp + (636)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(sp + (636));
    v1 = a3 - hi_a571c + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 320;
    a1 = a1 - hi_a5720 + (u32)(unsigned long)ref_t32_data_c2b10;
    a0 = sp + 32;
    *(volatile u32 *)(unsigned long)(sp + (556)) = v1;
    callee = v1; *(volatile u32 *)(unsigned long)(sp + (624)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5748;
L_a5748:
    v1 = *(volatile u32 *)(unsigned long)(sp + (556));
    a1 = hi_a574c;
    a2 = 50;
    a1 = a1 - hi_a574c + (u32)(unsigned long)ref_t32_data_c2c50;
    a0 = sp + 352;
    *(volatile u32 *)(unsigned long)(sp + (664)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (424)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (428)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (432)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (436)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (440)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (404)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (408)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (412)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (416)) = 0;
    callee = v1; *(volatile u32 *)(unsigned long)(sp + (420)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a578c;
L_a578c:
    a1 = s5 | 0x20;
    callee = s6; a0 = 50;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5798;
L_a5798:
    a1 = s5 | 0x20;
    a0 = 50;
    callee = s6; s8 = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a57a8;
L_a57a8:
    a1 = s5 | 0x20;
    a0 = 50;
    s4 = v0;
    *(volatile u32 *)(unsigned long)(sp + (456)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (460)) = 0;
    *(volatile u16 *)(unsigned long)(sp + (464)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (504)) = 0;
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (508)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a57cc;
L_a57cc:
    a1 = s5 | 0x20;
    a0 = 50;
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (556)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a57dc;
L_a57dc:
    a0 = *(volatile u32 *)(unsigned long)(sp + (556));
    s6 = hi_a57e0;
    s6 = s6 - hi_a57e0 + ((u32)(unsigned long)ref_memset + (0));
    a2 = 50;
    a1 = 0;
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (568)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a57f8;
L_a57f8:
    a0 = *(volatile u32 *)(unsigned long)(sp + (568));
    a2 = 50;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5808;
L_a5808:
    v1 = *(volatile u32 *)(unsigned long)(sp + (664));
    a0 = *(volatile u32 *)(unsigned long)(sp + (568));
    a2 = 50;
    callee = v1; a1 = sp + 352;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a581c;
L_a581c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (544));
    a2 = 510;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a582c;
L_a582c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (548));
    a2 = 450;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a583c;
L_a583c:
    a2 = 50;
    a1 = 0;
    callee = s6; a0 = s8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a584c;
L_a584c:
    a0 = s4;
    a2 = 50;
    callee = s6; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a585c;
L_a585c:
    a0 = *(volatile u8 *)(unsigned long)(s0 + (1833));
    v0 = 1;
    branch = (a0 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (632));
    if (branch) goto L_a5adc;
    goto L_a586c;
L_a586c:
    t1 = *(volatile u32 *)(unsigned long)(s0 + (144));
    t9 = s0 + 1782;
    t8 = s0 + 1788;
    v0 = (u32)s3 < (u32)(t1);
    branch = (v0 == 0); t7 = s0 + 1794;
    if (branch) goto L_a5918;
    goto L_a5884;
L_a5884:
    v0 = 0;
    a0 = 6;
L_a588c:
    a2 = t9 + v0;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = sp + 536;
    a1 = v1 + v0;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    a2 = t8 + v0;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = sp + 528;
    a1 = v1 + v0;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    a2 = t7 + v0;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = sp + 520;
    a1 = v1 + v0;
    v0 = v0 + 2;
    branch = (v0 != a0); *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_a588c;
    goto L_a58d0;
L_a58d0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (564));
L_a58d4:
    a0 = *(volatile s16 *)(unsigned long)(sp + (536));
    v1 = *(volatile u32 *)(unsigned long)(sp + (564));
    a1 = *(volatile s16 *)(unsigned long)(sp + (540));
    a0 = a0 * v0;
    v0 = *(volatile s16 *)(unsigned long)(sp + (538));
    a1 = a1 * v1;
    *(volatile u32 *)(unsigned long)(sp + (444)) = a0;
    v0 = v0 * v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (552));
    *(volatile u32 *)(unsigned long)(sp + (452)) = a1;
    a0 = (u32)a0 < (u32)(v1);
    branch = (a0 == 0); *(volatile u32 *)(unsigned long)(sp + (448)) = v0;
    if (branch) goto L_a5a28;
    goto L_a5908;
L_a5908:
    v0 = *(volatile u16 *)(unsigned long)(sp + (528));
    *(volatile u16 *)(unsigned long)(s0 + (256)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (520)); goto L_a5ad4;
L_a5918:
    t2 = *(volatile u32 *)(unsigned long)(s0 + (148));
    t6 = s0 + 1800;
    t5 = s0 + 1806;
    v0 = (u32)s3 < (u32)(t2);
    branch = (v0 == 0); t4 = s0 + 1812;
    if (branch) goto L_a59d4;
    goto L_a5930;
L_a5930:
    t0 = 0;
    s5 = hi_a5934;
    s6 = 6;
L_a593c:
    v0 = t6 + t0;
    a3 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = t9 + t0;
    a2 = *(volatile s16 *)(unsigned long)(v0 + (0));
    a1 = t2;
    a0 = t1;
    t3 = s5 - hi_a5934 + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = t3; *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5960;
L_a5960:
    v1 = sp + 536;
    a0 = v1 + t0;
    *(volatile u16 *)(unsigned long)(a0 + (0)) = v0;
    v0 = t5 + t0;
    a3 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = t8 + t0;
    a2 = *(volatile s16 *)(unsigned long)(v0 + (0));
    a1 = t2;
    a0 = t1;
    callee = t3; *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a598c;
L_a598c:
    v1 = sp + 528;
    a0 = v1 + t0;
    *(volatile u16 *)(unsigned long)(a0 + (0)) = v0;
    v0 = t4 + t0;
    a3 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = t7 + t0;
    a2 = *(volatile s16 *)(unsigned long)(v0 + (0));
    a0 = t1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    callee = t3; a1 = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a59b8;
L_a59b8:
    v1 = sp + 520;
    a0 = v1 + t0;
    t0 = t0 + 2;
    branch = (t0 != s6); *(volatile u16 *)(unsigned long)(a0 + (0)) = v0;
    if (branch) goto L_a593c;
    goto L_a59cc;
L_a59cc:
    v0 = *(volatile u32 *)(unsigned long)(sp + (564)); goto L_a58d4;
L_a59d4:
    v0 = 0;
    a0 = 6;
L_a59dc:
    a2 = t6 + v0;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = sp + 536;
    a1 = v1 + v0;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    a2 = t5 + v0;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = sp + 528;
    a1 = v1 + v0;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    a2 = t4 + v0;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v1 = sp + 520;
    a1 = v1 + v0;
    v0 = v0 + 2;
    branch = (v0 != a0); *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_a59dc;
    goto L_a5a20;
L_a5a20:
    v0 = *(volatile u32 *)(unsigned long)(sp + (564)); goto L_a58d4;
L_a5a28:
    v1 = *(volatile u32 *)(unsigned long)(sp + (552));
    a0 = (u32)a1 < (u32)(v1);
    if (a0 == 0) { v0 = *(volatile u16 *)(unsigned long)(sp + (532)); goto L_a5acc; }
    goto L_a5a38;
L_a5a38:
    a0 = (u32)v0 < (u32)(v1);
    if (a0 == 0) v0 = a1;
    a2 = 2;
    a1 = 1;
    if (a0 != 0) a2 = a1;
    a1 = (u32)a0 < (u32)(1);
    v1 = sp + 32;
    t0 = a1 << (0x1 & 31);
    a1 = a1 << (0x2 & 31);
    a1 = v1 + a1;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (412));
    t0 = v1 + t0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (552));
    a2 = a2 << (0x1 & 31);
    t2 = *(volatile s16 *)(unsigned long)(t0 + (496));
    t1 = a0 - v1;
    v1 = sp + 32;
    a2 = v1 + a2;
    a1 = *(volatile s16 *)(unsigned long)(a2 + (496));
    a3 = a0 - v0;
    v0 = a3 >> (0x1 & 31);
    a1 = a1 - t2;
    v1 = a1 * t1;
    a1 = *(volatile s16 *)(unsigned long)(t0 + (488));
    a0 = v1 + v0;
    if (a3) { lo = a0 / a3; hi = a0 % a3; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    a0 = a0 + t2;
    *(volatile u16 *)(unsigned long)(s0 + (256)) = a0;
    a0 = *(volatile s16 *)(unsigned long)(a2 + (488));
    a0 = a0 - a1;
    v1 = a0 * t1;
    v0 = v1 + v0;
    if (a3) { lo = v0 / a3; hi = v0 % a3; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + a1; goto L_a5ad4;
L_a5acc:
    *(volatile u16 *)(unsigned long)(s0 + (256)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (524));
L_a5ad4:
    *(volatile u16 *)(unsigned long)(s0 + (258)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (632));
L_a5adc:
    v0 = s3 << (0x8 & 31);
    a3 = *(volatile u8 *)(unsigned long)(s0 + (1568));
    a0 = v1 >> (0x1 & 31);
    v0 = v0 + a0;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1678));
    a2 = *(volatile u8 *)(unsigned long)(s0 + (278));
    a0 = *(volatile u32 *)(unsigned long)(sp + (712));
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (1586));
    t0 = hi_a5b04;
    t0 = t0 - hi_a5b04 + (u32)(unsigned long)ref_tisp_tmo_timeratio_curve_adjust;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (1572));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (1570));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    s5 = lo;
    s6 = s5 & 0xffff;
    callee = t0; a1 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5b30;
L_a5b30:
    a0 = *(volatile u16 *)(unsigned long)(s0 + (750));
    v1 = *(volatile u32 *)(unsigned long)(sp + (656));
    s5 = s5 & 0xffff;
    a0 = a0 << (0x8 & 31);
    a1 = (u32)a0 < (u32)(s6);
    v0 = 1;
    a0 = a0 & 0xffff;
    if (a1 != 0) s5 = a0;
    branch = (v1 != v0); t5 = 0;
    if (branch) goto L_a5cf4;
    goto L_a5b58;
L_a5b58:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (758));
    v0 = (u32)s5 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (766)); goto L_a5b70; }
    goto L_a5b68;
L_a5b68:
    t5 = *(volatile s16 *)(unsigned long)(s0 + (770)); goto L_a5bfc;
L_a5b70:
    v0 = (u32)s5 < (u32)(v0);
    if (v0 == 0) { t5 = *(volatile s16 *)(unsigned long)(s0 + (778)); goto L_a5bfc; }
    goto L_a5b7c;
L_a5b7c:
    a3 = s0 + 758;
    a2 = s0 + 760;
    v0 = 0;
    t0 = 4;
L_a5b8c:
    a0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a1 = (u32)s5 < (u32)(a0);
    branch = (a1 == 0); t1 = a2 - a3;
    if (branch) goto L_a5bec;
    goto L_a5b9c;
L_a5b9c:
    a1 = s0 + 770;
    v0 = v0 << (0x1 & 31);
    a2 = a1 + v0;
    v0 = a3 + v0;
    t5 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t0 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a3 = 2;
    a2 = a0 - t5;
    if (a2 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a2 / (s32)a3; hi = (s32)a2 % (s32)a3; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a1 = a1 + t1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    t5 = s5 - t5;
    a1 = a1 - t0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)t5); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)a0 / (s32)a2; hi = (s32)a0 % (s32)a2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    a0 = t0 + a0;
    t5 = (int16_t)a0; goto L_a5bfc;
L_a5bec:
    v0 = v0 + 1;
    branch = (v0 != t0); a2 = a2 + 2;
    if (branch) goto L_a5b8c;
    goto L_a5bf8;
L_a5bf8:
    t5 = 0;
L_a5bfc:
    a0 = *(volatile u16 *)(unsigned long)(s0 + (1668));
    v0 = 1;
    branch = (a0 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (660));
    if (branch) goto L_a5cf8;
    goto L_a5c0c;
L_a5c0c:
    v0 = sp + 32;
    a3 = *(volatile u32 *)(unsigned long)(sp + (596));
    a1 = *(volatile u32 *)(unsigned long)(sp + (600));
    a0 = *(volatile u32 *)(unsigned long)(sp + (592));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_a5c20;
    v0 = v0 - hi_a5c20 + (u32)(unsigned long)ref_tisp_wdr_get_lum_s;
    callee = v0; a2 = sp + 512;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5c30;
L_a5c30:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1684));
    v0 = (s32)t5 < (s32)(v0);
    if (v0 != 0) { *(volatile u16 *)(unsigned long)(s0 + (1684)) = t5; goto L_a5c40; }
    goto L_a5c40;
L_a5c40:
    t0 = *(volatile u16 *)(unsigned long)(sp + (518));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1670));
    a0 = (u32)t0 < (u32)(v0);
    if (a0 == 0) { a0 = *(volatile u16 *)(unsigned long)(s0 + (1672)); goto L_a5c64; }
    goto L_a5c54;
L_a5c54:
    t5 = *(volatile u16 *)(unsigned long)(s0 + (1680));
    t5 = -t5;
    t5 = (int16_t)t5; goto L_a5cf4;
L_a5c64:
    a1 = (u32)t0 < (u32)(a0);
    if (a1 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (1674)); goto L_a5c98; }
    goto L_a5c70;
L_a5c70:
    a3 = *(volatile u16 *)(unsigned long)(s0 + (1682));
    a2 = *(volatile u16 *)(unsigned long)(s0 + (1680));
    a1 = a0;
    a0 = v0;
    v0 = hi_a5c80;
    v0 = v0 - hi_a5c80 + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5c90;
L_a5c90:
    v0 = -v0; goto L_a5ccc;
L_a5c98:
    a1 = (u32)t0 < (u32)(v0);
    if (a1 == 0) { a1 = *(volatile u16 *)(unsigned long)(s0 + (1676)); goto L_a5cd4; }
    goto L_a5ca4;
L_a5ca4:
    a2 = *(volatile u16 *)(unsigned long)(s0 + (1682));
    a3 = *(volatile u16 *)(unsigned long)(s0 + (1684));
    a1 = v0;
    a2 = -a2;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t0;
    a2 = (int16_t)a2;
L_a5cbc:
    v0 = hi_a5cbc;
    v0 = v0 - hi_a5cbc + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5ccc;
L_a5ccc:
    t5 = (int16_t)v0; goto L_a5cf4;
L_a5cd4:
    a0 = (u32)t0 < (u32)(a1);
    if (a0 == 0) { t5 = *(volatile s16 *)(unsigned long)(s0 + (1686)); goto L_a5cf4; }
    goto L_a5ce0;
L_a5ce0:
    a3 = *(volatile u16 *)(unsigned long)(s0 + (1686));
    a2 = *(volatile u16 *)(unsigned long)(s0 + (1684));
    a0 = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t0; goto L_a5cbc;
L_a5cf4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (660));
L_a5cf8:
    a0 = 1;
    branch = (v1 != a0); v0 = t5;
    if (branch) goto L_a5da8;
    goto L_a5d04;
L_a5d04:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (780));
    v0 = (u32)s5 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (788)); goto L_a5d1c; }
    goto L_a5d14;
L_a5d14:
    v0 = *(volatile s16 *)(unsigned long)(s0 + (792)); goto L_a5da8;
L_a5d1c:
    v0 = (u32)s5 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile s16 *)(unsigned long)(s0 + (800)); goto L_a5da8; }
    goto L_a5d28;
L_a5d28:
    t1 = s0 + 780;
    t0 = s0 + 782;
    a0 = 0;
    a1 = 4;
L_a5d38:
    v0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    a2 = (u32)s5 < (u32)(v0);
    branch = (a2 == 0); t2 = t0 - t1;
    if (branch) goto L_a5d98;
    goto L_a5d48;
L_a5d48:
    a3 = s0 + 792;
    a1 = a0 << (0x1 & 31);
    a0 = a3 + a1;
    a1 = t1 + a1;
    t0 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a3 = a3 + t2;
    a1 = *(volatile u16 *)(unsigned long)(a3 + (0));
    a2 = v0 - t0;
    a3 = 2;
    if (a2 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a2 / (s32)a3; hi = (s32)a2 % (s32)a3; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v0 = s5 - t0;
    a1 = a1 - a0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a1 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = a0 + v0;
    v0 = (int16_t)v0; goto L_a5da8;
L_a5d98:
    a0 = a0 + 1;
    branch = (a0 != a1); t0 = t0 + 2;
    if (branch) goto L_a5d38;
    goto L_a5da4;
L_a5da4:
    v0 = 0;
L_a5da8:
    v0 = s5 - v0;
    t5 = s5 - t5;
    *(volatile u32 *)(unsigned long)(s1 + (20)) = v0;
    *(volatile u32 *)(unsigned long)(s1 + (16)) = t5;
    a0 = *(volatile u16 *)(unsigned long)(s0 + (754));
    v0 = 1;
    branch = (a0 != v0); s6 = 4095;
    if (branch) goto L_a5de8;
    goto L_a5dc8;
L_a5dc8:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (6204));
    v0 = *(volatile u32 *)(unsigned long)(s7 + (6200));
    v0 = v0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s7 + (6208));
    v0 = v0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s7 + (6212));
    v0 = v0 + a0;
    s6 = (v0 >> 0x2) & ((1U << 0x10) - 1);
L_a5de8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (620));
    a1 = 0;
    a3 = 210;
    a2 = v0 >> (0x1 & 31);
    a0 = a1 & 0xffff;
L_a5dfc:
    t0 = a1 + 14;
L_a5e00:
    v0 = (s32)a0 < (s32)(t0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (544));
    if (branch) goto L_a5e70;
    goto L_a5e0c;
L_a5e0c:
    t1 = a0 << (0x1 & 31);
    t2 = a0 << (0x2 & 31);
    t3 = v0 + t1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (644));
    v1 = *(volatile u32 *)(unsigned long)(sp + (620));
    a0 = a0 + 1;
    v0 = v0 + t2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a0 & 0xffff;
    v0 = v0 << (0x4 & 31);
    v0 = v0 + a2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(t3 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (548));
    t1 = v0 + t1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (648));
    v0 = v0 + t2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 << (0x4 & 31);
    v0 = v0 + a2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(t1 + (0)) = v0; goto L_a5e00;
L_a5e70:
    a1 = a1 + 15;
    branch = (a1 != a3); a0 = a1 & 0xffff;
    if (branch) goto L_a5dfc;
    goto L_a5e7c;
L_a5e7c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (612));
    a0 = s7 + 7064;
    a2 = s7 + 7964;
    t1 = v0 >> (0x1 & 31);
    v0 = *(volatile u32 *)(unsigned long)(sp + (544));
    t0 = s7 + 7120;
    a3 = v0 + 420;
    v0 = *(volatile u32 *)(unsigned long)(sp + (548));
    a1 = v0 + 420;
L_a5ea0:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(sp + (612));
    a0 = a0 + 4;
    v0 = v0 << (0x4 & 31);
    v0 = v0 + t1;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a3 = a3 + 2;
    a2 = a2 + 4;
    a1 = a1 + 2;
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a3 + (-2)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a2 + (-4));
    v0 = v0 << (0x4 & 31);
    v0 = v0 + t1;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (a0 != t0); *(volatile u16 *)(unsigned long)(a1 + (-2)) = v0;
    if (branch) goto L_a5ea0;
    goto L_a5ee8;
L_a5ee8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (608));
    a0 = s7 + 6280;
    a2 = s7 + 7180;
    t1 = v0 >> (0x1 & 31);
    v0 = *(volatile u32 *)(unsigned long)(sp + (544));
    a3 = v0 + 28;
    v0 = *(volatile u32 *)(unsigned long)(sp + (548));
    a1 = v0 + 28;
L_a5f08:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(sp + (608));
    a0 = a0 + 60;
    v0 = v0 << (0x4 & 31);
    v0 = v0 + t1;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a3 = a3 + 30;
    a2 = a2 + 60;
    a1 = a1 + 30;
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a3 + (-30)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a2 + (-60));
    v0 = v0 << (0x4 & 31);
    v0 = v0 + t1;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (a0 != t0); *(volatile u16 *)(unsigned long)(a1 + (-30)) = v0;
    if (branch) goto L_a5f08;
    goto L_a5f50;
L_a5f50:
    v0 = *(volatile u32 *)(unsigned long)(sp + (616));
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7120));
    v1 = *(volatile u32 *)(unsigned long)(sp + (616));
    a1 = v0 >> (0x1 & 31);
    a0 = a0 << (0x4 & 31);
    a0 = a0 + a1;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (544));
    t3 = hi_a5f70;
    a2 = 1;
    t3 = t3 - hi_a5f70 + (u32)(unsigned long)ref_tisp_wdr_paixu;
    a0 = lo;
    *(volatile u16 *)(unsigned long)(v0 + (448)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(s7 + (8020));
    a0 = *(volatile u32 *)(unsigned long)(sp + (544));
    v0 = v0 << (0x4 & 31);
    v0 = v0 + a1;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (548));
    a1 = *(volatile u32 *)(unsigned long)(sp + (624));
    v0 = lo;
    callee = t3; *(volatile u16 *)(unsigned long)(v1 + (448)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5fac;
L_a5fac:
    a0 = *(volatile u32 *)(unsigned long)(sp + (548));
    a1 = 10;
    callee = t3; a2 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a5fbc;
L_a5fbc:
    a1 = *(volatile u8 *)(unsigned long)(sp + (636));
    t7 = 0;
    v0 = 0;
L_a5fc8:
    v1 = (u32)v0 < (u32)(a1);
    branch = (v1 == 0); a0 = *(volatile u32 *)(unsigned long)(sp + (544));
    if (branch) goto L_a5ff0;
    goto L_a5fd4;
L_a5fd4:
    v1 = v0 << (0x1 & 31);
    v0 = v0 + 1;
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v0 = v0 & 0xffff;
    t7 = t7 + v1; goto L_a5fc8;
L_a5ff0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (624));
    a0 = *(volatile u32 *)(unsigned long)(sp + (548));
    v1 = 0;
    v0 = v0 >> (0x1 & 31);
    t7 = v0 + t7;
    v0 = *(volatile u32 *)(unsigned long)(sp + (624));
    if (v0) { lo = t7 / v0; hi = t7 % v0; } else { lo = ~0U; hi = t7; }
    v0 = 0;
    t7 = lo;
    t7 = t7 + 1;
    t7 = t7 & 0xffff;
L_a601c:
    branch = (v1 == a1); v1 = v1 + 1;
    if (branch) goto L_a6038;
    goto L_a6024;
L_a6024:
    a2 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = v1 & 0xffff;
    v0 = v0 + a2;
    a0 = a0 + 2; goto L_a601c;
L_a6038:
    v0 = v0 + 5;
    v1 = 10;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1688));
    v0 = lo;
    s7 = v0 & 0xffff;
    t6 = v0 & 0xffff;
    s5 = s5 * s7;
    v0 = 1;
    if (s5 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)s5 / (s32)t7; hi = (s32)s5 % (s32)t7; } else { lo = (s32)s5 < 0 ? 1 : ~0U; hi = s5; }
    s5 = lo;
    branch = (v1 != v0); s5 = (s32)s5 >> (0x8 & 31);
    if (branch) goto L_a610c;
    goto L_a606c;
L_a606c:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1690));
    v0 = (u32)s5 < (u32)(v0);
    if (v0 == 0) { v1 = *(volatile u16 *)(unsigned long)(s0 + (1696)); goto L_a6084; }
    goto L_a607c;
L_a607c:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1700)); goto L_a6108;
L_a6084:
    v0 = (u32)s5 < (u32)(v1);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (1706)); goto L_a6108; }
    goto L_a6090;
L_a6090:
    a1 = *(volatile u16 *)(unsigned long)(s0 + (1692));
    v0 = (u32)s5 < (u32)(a1);
    branch = (v0 != 0); a0 = 8;
    if (branch) goto L_a60c8;
    goto L_a60a0;
L_a60a0:
    a1 = *(volatile u16 *)(unsigned long)(s0 + (1694));
    a2 = 2;
    v0 = (u32)s5 < (u32)(a1);
    if (v0 == 0) a1 = v1;
    v1 = 6;
    if (v0 != 0) a0 = v1;
    v1 = 3;
    if (v0 != 0) v1 = a2;
    v0 = v1; goto L_a60d0;
L_a60c8:
    a0 = 4;
    v0 = 1;
L_a60d0:
    v1 = s0 + 1698;
    v0 = v0 << (0x1 & 31);
    a0 = v1 + a0;
    v1 = v1 + v0;
    v0 = s0 + v0;
    a3 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a2 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(v0 + (1688));
    v0 = hi_a60f0;
    v0 = v0 - hi_a60f0 + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a6100;
L_a6100:
    *(volatile u16 *)(unsigned long)(s0 + (1698)) = v0; goto L_a610c;
L_a6108:
    *(volatile u16 *)(unsigned long)(s0 + (1698)) = v0;
L_a610c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (552));
    v0 = 0x1U << 16;
    t5 = 0xffff;
    t8 = (u32)v1 < (u32)(v0);
    v0 = (u32)s5 < (u32)(v0);
    if (t8 == 0) v1 = t5;
    if (v0 != 0) t5 = s5;
    v0 = *(volatile u32 *)(unsigned long)(sp + (564));
    *(volatile u16 *)(unsigned long)(s1 + (102)) = t6;
    *(volatile u16 *)(unsigned long)(s1 + (104)) = t7;
    if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; }
    *(volatile u16 *)(unsigned long)(s1 + (108)) = t5;
    t8 = v1;
    v0 = lo;
    *(volatile u16 *)(unsigned long)(s1 + (106)) = v0;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1708));
    v0 = 1;
    if (v1 != v0) { t9 = *(volatile u16 *)(unsigned long)(s0 + (1728)); goto L_a61e4; }
    goto L_a6158;
L_a6158:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1710));
    v0 = (u32)t5 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (1726)); goto L_a6170; }
    goto L_a6168;
L_a6168:
    t9 = *(volatile u16 *)(unsigned long)(s0 + (1730)); goto L_a61e4;
L_a6170:
    v0 = (u32)t5 < (u32)(v0);
    if (v0 == 0) { t9 = *(volatile u16 *)(unsigned long)(s0 + (1746)); goto L_a61e4; }
    goto L_a617c;
L_a617c:
    t0 = s0 + 1708;
    v1 = s0 + 1712;
    v0 = 1;
    a2 = 9;
L_a618c:
    a1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a3 = (u32)t5 < (u32)(a1);
    branch = (a3 == 0); a0 = v1 - t0;
    if (branch) goto L_a61d4;
    goto L_a619c;
L_a619c:
    v1 = s0 + 1728;
    v0 = v0 << (0x1 & 31);
    a0 = v1 + a0;
    v1 = v1 + v0;
    v0 = t0 + v0;
    a3 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a2 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = hi_a61bc;
    v0 = v0 - hi_a61bc + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = t5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a61cc;
L_a61cc:
    t9 = v0 & 0xffff; goto L_a61e4;
L_a61d4:
    v0 = v0 + 1;
    branch = (v0 != a2); v1 = v1 + 2;
    if (branch) goto L_a618c;
    goto L_a61e0;
L_a61e0:
    t9 = 0;
L_a61e4:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (808));
    v0 = 1;
    if (v1 != v0) { t0 = *(volatile u16 *)(unsigned long)(s0 + (832)); goto L_a62cc; }
    goto L_a61f4;
L_a61f4:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1668));
    branch = (v0 != 0); a1 = *(volatile u16 *)(unsigned long)(sp + (518));
    if (branch) goto L_a6228;
    goto L_a6200;
L_a6200:
    v0 = sp + 32;
    a3 = *(volatile u32 *)(unsigned long)(sp + (596));
    a1 = *(volatile u32 *)(unsigned long)(sp + (600));
    a0 = *(volatile u32 *)(unsigned long)(sp + (592));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_a6214;
    v0 = v0 - hi_a6214 + (u32)(unsigned long)ref_tisp_wdr_get_lum_s;
    callee = v0; a2 = sp + 512;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a6224;
L_a6224:
    a1 = *(volatile u16 *)(unsigned long)(sp + (518));
L_a6228:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (810));
    v0 = (u32)a1 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (830)); goto L_a6240; }
    goto L_a6238;
L_a6238:
    t0 = *(volatile u16 *)(unsigned long)(s0 + (834)); goto L_a62cc;
L_a6240:
    v0 = (u32)a1 < (u32)(v0);
    if (v0 == 0) { t0 = *(volatile u16 *)(unsigned long)(s0 + (854)); goto L_a62cc; }
    goto L_a624c;
L_a624c:
    a3 = s0 + 808;
    v1 = s0 + 812;
    v0 = 1;
    a2 = 11;
L_a625c:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t0 = (u32)a1 < (u32)(a0);
    branch = (t0 == 0); t1 = v1 - a3;
    if (branch) goto L_a62bc;
    goto L_a626c;
L_a626c:
    v1 = s0 + 832;
    v0 = v0 << (0x1 & 31);
    a2 = v1 + v0;
    v0 = a3 + v0;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v1 = v1 + t1;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = a0 - a3;
    a1 = a1 - a3;
    a3 = 2;
    if (a0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a0 / (s32)a3; hi = (s32)a0 % (s32)a3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v1 = v1 - a2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a1); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = a2 + v0;
    t0 = v0 & 0xffff; goto L_a62cc;
L_a62bc:
    v0 = v0 + 1;
    branch = (v0 != a2); v1 = v1 + 2;
    if (branch) goto L_a625c;
    goto L_a62c8;
L_a62c8:
    t0 = 0;
L_a62cc:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (856));
    v0 = 1;
    if (v1 != v0) { t1 = *(volatile u16 *)(unsigned long)(s0 + (880)); goto L_a6380; }
    goto L_a62dc;
L_a62dc:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (858));
    v0 = (u32)t6 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (878)); goto L_a62f4; }
    goto L_a62ec;
L_a62ec:
    t1 = *(volatile u16 *)(unsigned long)(s0 + (882)); goto L_a6380;
L_a62f4:
    v0 = (u32)t6 < (u32)(v0);
    if (v0 == 0) { t1 = *(volatile u16 *)(unsigned long)(s0 + (902)); goto L_a6380; }
    goto L_a6300;
L_a6300:
    a3 = s0 + 856;
    v1 = s0 + 860;
    v0 = 1;
    a1 = 11;
L_a6310:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t1 = (u32)t6 < (u32)(a0);
    branch = (t1 == 0); a2 = v1 - a3;
    if (branch) goto L_a6370;
    goto L_a6320;
L_a6320:
    v1 = s0 + 880;
    v0 = v0 << (0x1 & 31);
    a1 = v1 + v0;
    v0 = a3 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v1 = v1 + a2;
    a2 = 2;
    a0 = a0 - v0;
    if (a0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)a0 / (s32)a2; hi = (s32)a0 % (s32)a2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v0 = s7 - v0;
    v1 = v1 - a1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = a1 + v0;
    t1 = v0 & 0xffff; goto L_a6380;
L_a6370:
    v0 = v0 + 1;
    branch = (v0 != a1); v1 = v1 + 2;
    if (branch) goto L_a6310;
    goto L_a637c;
L_a637c:
    t1 = 0;
L_a6380:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (904));
    v0 = 1;
    if (v1 != v0) { t2 = *(volatile u16 *)(unsigned long)(s0 + (928)); goto L_a6434; }
    goto L_a6390;
L_a6390:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (906));
    v0 = (u32)t7 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (926)); goto L_a63a8; }
    goto L_a63a0;
L_a63a0:
    t2 = *(volatile u16 *)(unsigned long)(s0 + (930)); goto L_a6434;
L_a63a8:
    v0 = (u32)t7 < (u32)(v0);
    if (v0 == 0) { t2 = *(volatile u16 *)(unsigned long)(s0 + (950)); goto L_a6434; }
    goto L_a63b4;
L_a63b4:
    a3 = s0 + 904;
    v0 = s0 + 908;
    a1 = 1;
    a0 = 11;
L_a63c4:
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t2 = (u32)t7 < (u32)(v1);
    branch = (t2 == 0); a2 = v0 - a3;
    if (branch) goto L_a6424;
    goto L_a63d4;
L_a63d4:
    v0 = s0 + 928;
    a1 = a1 << (0x1 & 31);
    a0 = v0 + a1;
    a1 = a3 + a1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v0 = v0 + a2;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = v1 - a1;
    t7 = t7 - a1;
    a1 = 2;
    if (v1 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v1 / (s32)a1; hi = (s32)v1 % (s32)a1; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = v0 - a0;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)t7); lo = product; hi = product >> 32;
    t7 = lo;
    if (t7 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)t7 / (s32)v1; hi = (s32)t7 % (s32)v1; } else { lo = (s32)t7 < 0 ? 1 : ~0U; hi = t7; }
    t7 = lo;
    t7 = a0 + t7;
    t2 = t7 & 0xffff; goto L_a6434;
L_a6424:
    a1 = a1 + 1;
    branch = (a1 != a0); v0 = v0 + 2;
    if (branch) goto L_a63c4;
    goto L_a6430;
L_a6430:
    t2 = 0;
L_a6434:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (952));
    v0 = 1;
    if (v1 != v0) { t3 = *(volatile u16 *)(unsigned long)(s0 + (964)); goto L_a6508; }
    goto L_a6444;
L_a6444:
    v1 = sp + 424;
    v0 = s0 + 954;
    a2 = s0 + 964;
    a0 = v1;
L_a6454:
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(sp + (564));
    v0 = v0 + 2;
    a0 = a0 + 4;
    a1 = a1 * a3;
    branch = (a2 != v0); *(volatile u32 *)(unsigned long)(a0 + (-4)) = a1;
    if (branch) goto L_a6454;
    goto L_a6470;
L_a6470:
    v0 = *(volatile u32 *)(unsigned long)(sp + (424));
    v0 = (u32)v0 < (u32)(t8);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (440));
    if (branch) goto L_a6488;
    goto L_a6480;
L_a6480:
    t3 = *(volatile u16 *)(unsigned long)(s0 + (966)); goto L_a6508;
L_a6488:
    v0 = (u32)v0 < (u32)(t8);
    if (v0 == 0) { t3 = *(volatile u16 *)(unsigned long)(s0 + (974)); goto L_a6508; }
    goto L_a6494;
L_a6494:
    v0 = 1;
    a0 = 5;
L_a649c:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a2 = (u32)a1 < (u32)(t8);
    if (a2 == 0) { v0 = v0 + 1; goto L_a64fc; }
    goto L_a64ac;
L_a64ac:
    a0 = v0 & 0xffff;
    a0 = a0 + 1;
    a0 = a0 << (0x1 & 31);
    v1 = s0 + 964;
    v1 = v1 + a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (-2));
    t8 = t8 - a1;
    a2 = v0 + -1;
    v1 = v1 - a0;
    t8 = v1 * t8;
    a2 = a2 << (0x2 & 31);
    a2 = sp + a2;
    v1 = *(volatile u32 *)(unsigned long)(a2 + (424));
    v0 = v1 - a1;
    if (v0) { lo = t8 / v0; hi = t8 % v0; } else { lo = ~0U; hi = t8; }
    t3 = lo;
    t3 = a0 + t3;
    t3 = t3 & 0xffff; goto L_a6508;
L_a64fc:
    branch = (v0 != a0); v1 = v1 + 4;
    if (branch) goto L_a649c;
    goto L_a6504;
L_a6504:
    t3 = 0;
L_a6508:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (152));
    v0 = (u32)s3 < (u32)(v1);
    branch = (v0 == 0); t7 = s0 + 1768;
    if (branch) goto L_a6584;
    goto L_a6518;
L_a6518:
    t8 = *(volatile u32 *)(unsigned long)(sp + (628));
    v0 = sp + 404;
L_a6520:
    v1 = *(volatile s16 *)(unsigned long)(t8 + (0));
    t8 = t8 + 2;
    v0 = v0 + 4;
    branch = (t7 != t8); *(volatile u32 *)(unsigned long)(v0 + (-4)) = v1;
    if (branch) goto L_a6520;
    goto L_a6534;
L_a6534:
    v0 = *(volatile u32 *)(unsigned long)(sp + (420));
L_a6538:
    a0 = *(volatile u32 *)(unsigned long)(sp + (404));
    v1 = *(volatile u32 *)(unsigned long)(sp + (412));
    t9 = t9 * v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (416));
    t7 = hi_a6548;
    t9 = t9 + 8;
    lo = t9;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)a0); lo = product; hi = product >> 32;
    a0 = *(volatile u32 *)(unsigned long)(sp + (408));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t1 * (s32)a0); lo = product; hi = product >> 32;
    a0 = hi_a6560;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t2 * (s32)v1); lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t3 * (s32)v0); lo = product; hi = product >> 32;
    v0 = *(volatile u8 *)(unsigned long)(t7 - hi_a6548 + (u32)(unsigned long)ref_t32_data_e3a9a);
    t3 = lo;
    branch = (v0 == 0); t3 = t3 >> (0x4 & 31);
    if (branch) goto L_a6670;
    goto L_a657c;
L_a657c:
    v1 = *(volatile u16 *)(unsigned long)(a0 - hi_a6560 + (u32)(unsigned long)ref_t32_data_e3b2c); goto L_a6610;
L_a6584:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (156));
    *(volatile u32 *)(unsigned long)(sp + (552)) = v0;
    v0 = (u32)s3 < (u32)(v0);
    branch = (v0 == 0); v0 = sp + 404;
    if (branch) goto L_a65f0;
    goto L_a6598;
L_a6598:
    t8 = *(volatile u32 *)(unsigned long)(sp + (628));
    v0 = hi_a659c;
    s5 = t7;
    t4 = sp + 404;
    *(volatile u32 *)(unsigned long)(sp + (564)) = v0;
L_a65ac:
    v0 = *(volatile u32 *)(unsigned long)(sp + (564));
    a3 = *(volatile s16 *)(unsigned long)(s5 + (0));
    a2 = *(volatile s16 *)(unsigned long)(t8 + (0));
    a1 = *(volatile u32 *)(unsigned long)(sp + (552));
    a0 = v1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    v0 = v0 - hi_a659c + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (608)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a65d0;
L_a65d0:
    t8 = t8 + 2;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = v0;
    s5 = s5 + 2;
    t4 = t4 + 4;
    branch = (t7 != t8); v1 = *(volatile u32 *)(unsigned long)(sp + (608));
    if (branch) goto L_a65ac;
    goto L_a65e8;
L_a65e8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (420)); goto L_a6538;
L_a65f0:
    v1 = s0 + 1778;
L_a65f4:
    a0 = *(volatile s16 *)(unsigned long)(t7 + (0));
    t7 = t7 + 2;
    v0 = v0 + 4;
    branch = (t7 != v1); *(volatile u32 *)(unsigned long)(v0 + (-4)) = a0;
    if (branch) goto L_a65f4;
    goto L_a6608;
L_a6608:
    v0 = *(volatile u32 *)(unsigned long)(sp + (420)); goto L_a6538;
L_a6610:
    a1 = (u32)v1 < (u32)(t3);
    branch = (a1 == 0); v0 = hi_a6618;
    if (branch) goto L_a6648;
    goto L_a661c;
L_a661c:
    t3 = t3 - v1;
    t3 = t3 & 0xffff;
    a1 = (u32)t3 < (u32)(51);
    branch = (a1 == 0); a1 = 50;
    if (branch) goto L_a6638;
    goto L_a6630;
L_a6630:
    *(volatile u16 *)(unsigned long)(v0 - hi_a6618 + (u32)(unsigned long)ref_t32_data_e3b2a) = t3; goto L_a663c;
L_a6638:
    *(volatile u16 *)(unsigned long)(v0 - hi_a6618 + (u32)(unsigned long)ref_t32_data_e3b2a) = a1;
L_a663c:
    t3 = *(volatile u16 *)(unsigned long)(v0 - hi_a6618 + (u32)(unsigned long)ref_t32_data_e3b2a);
    t3 = t3 + v1; goto L_a6670;
L_a6648:
    t3 = v1 - t3;
    t3 = t3 & 0xffff;
    a1 = (u32)t3 < (u32)(51);
    branch = (a1 == 0); a1 = 50;
    if (branch) goto L_a6664;
    goto L_a665c;
L_a665c:
    *(volatile u16 *)(unsigned long)(v0 - hi_a6618 + (u32)(unsigned long)ref_t32_data_e3b2a) = t3; goto L_a6668;
L_a6664:
    *(volatile u16 *)(unsigned long)(v0 - hi_a6618 + (u32)(unsigned long)ref_t32_data_e3b2a) = a1;
L_a6668:
    t3 = *(volatile u16 *)(unsigned long)(v0 - hi_a6618 + (u32)(unsigned long)ref_t32_data_e3b2a);
    t3 = v1 - t3;
L_a6670:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (256));
    v0 = (u32)v0 < (u32)(4096);
    branch = (v0 == 0); *(volatile u16 *)(unsigned long)(a0 - hi_a6560 + (u32)(unsigned long)ref_t32_data_e3b2c) = t3;
    if (branch) goto L_a66a0;
    goto L_a6680;
L_a6680:
    t0 = *(volatile u32 *)(unsigned long)(s1 + (16));
    t0 = s6 * t0;
    t0 = t0 + 128;
    v0 = t0 >> (0x8 & 31);
    t0 = (u32)v0 < (u32)(t3);
    if (t0 == 0) v0 = t3;
    t0 = v0; goto L_a66a8;
L_a66a0:
    t0 = 4095;
    s6 = 4095;
L_a66a8:
    v0 = *(volatile u8 *)(unsigned long)(t7 - hi_a6548 + (u32)(unsigned long)ref_t32_data_e3a9a);
    branch = (v0 == 0); v1 = *(volatile u32 *)(unsigned long)(sp + (604));
    if (branch) goto L_a66cc;
    goto L_a66b4;
L_a66b4:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1514));
L_a66b8:
    v0 = 1;
    branch = (v1 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (652));
    if (branch) goto L_a6858;
    goto L_a66c4;
L_a66c4:
    t8 = *(volatile u16 *)(unsigned long)(s0 + (1536)); goto L_a66f4;
L_a66cc:
    v0 = hi_a66cc;
    v0 = v0 - hi_a66cc + (u32)(unsigned long)ref_t32_data_e3b20;
    a0 = s0 + 1526;
L_a66d8:
    a1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v1 = v1 + 2;
    v0 = v0 + 2;
    branch = (v1 != a0); *(volatile u16 *)(unsigned long)(v0 + (-2)) = a1;
    if (branch) goto L_a66d8;
    goto L_a66ec;
L_a66ec:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1514)); goto L_a66b8;
L_a66f4:
    t1 = s0 + 1548;
    v0 = (u32)t8 < (u32)(t6);
    branch = (v0 != 0); t2 = s0 + 1558;
    if (branch) goto L_a6868;
    goto L_a6704;
L_a6704:
    v0 = sp + 492;
L_a6708:
    v1 = *(volatile u16 *)(unsigned long)(t1 + (0));
    t1 = t1 + 2;
    v0 = v0 + 2;
    branch = (t2 != t1); *(volatile u16 *)(unsigned long)(v0 + (-2)) = v1;
    if (branch) goto L_a6708;
    goto L_a671c;
L_a671c:
    t6 = *(volatile u16 *)(unsigned long)(s0 + (1540));
L_a6720:
    t1 = s0 + 1588;
    v0 = (u32)t6 < (u32)(t5);
    branch = (v0 != 0); t2 = s0 + 1598;
    if (branch) goto L_a68d4;
    goto L_a6730;
L_a6730:
    v0 = sp + 480;
L_a6734:
    v1 = *(volatile u16 *)(unsigned long)(t1 + (0));
    t1 = t1 + 2;
    v0 = v0 + 2;
    branch = (t2 != t1); *(volatile u16 *)(unsigned long)(v0 + (-2)) = v1;
    if (branch) goto L_a6734;
    goto L_a6748;
L_a6748:
    t5 = *(volatile u16 *)(unsigned long)(s1 + (106));
L_a674c:
    t6 = *(volatile u16 *)(unsigned long)(s0 + (1544));
    t1 = s0 + 1628;
    v0 = (u32)t6 < (u32)(t5);
    branch = (v0 != 0); t2 = s0 + 1638;
    if (branch) goto L_a6940;
    goto L_a6760;
L_a6760:
    v0 = sp + 468;
L_a6764:
    v1 = *(volatile u16 *)(unsigned long)(t1 + (0));
    t1 = t1 + 2;
    v0 = v0 + 2;
    branch = (t2 != t1); *(volatile u16 *)(unsigned long)(v0 + (-2)) = v1;
    if (branch) goto L_a6764;
    goto L_a6778;
L_a6778:
    a0 = 0;
L_a677c:
    a2 = 16;
    a3 = 10;
L_a6784:
    a1 = sp + 480;
    a1 = a1 + a0;
    t2 = *(volatile u16 *)(unsigned long)(s0 + (1576));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (604));
    product = (s64)(s32)a1 * (s32)t2; lo = product; hi = product >> 32;
    t1 = v0 + a0;
    v0 = sp + 492;
    v0 = v0 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1574));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v0); lo = product; hi = product >> 32;
    v0 = sp + 468;
    v0 = v0 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1578));
    a0 = a0 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (a0 != a3); *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    if (branch) goto L_a6784;
    goto L_a67e0;
L_a67e0:
    a2 = *(volatile u32 *)(unsigned long)(sp + (604));
    a1 = hi_a67e4;
    a1 = a1 - hi_a67e4 + (u32)(unsigned long)ref_t32_data_e3b20;
    v1 = hi_a67ec;
    v1 = v1 - hi_a67ec + (u32)(unsigned long)ref_t32_data_e3b14;
    t4 = s0 + 1526;
    a3 = a1;
    t1 = a2;
    t5 = 1;
    t2 = 1;
L_a6808:
    v0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a3 + (0));
    t6 = (u32)a0 < (u32)(v0);
    branch = (t6 == 0); v0 = a0 - v0;
    if (branch) goto L_a69ac;
    goto L_a681c;
L_a681c:
    *(volatile u16 *)(unsigned long)(v1 + (0)) = t2;
    v0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = a0 + v0;
L_a6828:
    t1 = t1 + 2;
    *(volatile u16 *)(unsigned long)(a3 + (0)) = a0;
    v1 = v1 + 2;
    branch = (t1 != t4); a3 = a3 + 2;
    if (branch) goto L_a6808;
    goto L_a683c;
L_a683c:
    v0 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a2 = a2 + 2;
    a1 = a1 + 2;
    branch = (t4 != a2); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v0;
    if (branch) goto L_a683c;
    goto L_a6850;
L_a6850:
    v1 = *(volatile u32 *)(unsigned long)(sp + (652));
    v0 = 1;
L_a6858:
    if (v1 != v0) { v0 = (u32)t0 < (u32)(4096); goto L_a6a58; }
    goto L_a6860;
L_a6860:
    v0 = *(volatile u8 *)(unsigned long)(t7 - hi_a6548 + (u32)(unsigned long)ref_t32_data_e3a9a); goto L_a69cc;
L_a6868:
    t9 = *(volatile u16 *)(unsigned long)(s0 + (1538));
    t6 = (u32)t9 < (u32)(t6);
    branch = (t6 != 0); v0 = sp + 492;
    if (branch) goto L_a68b4;
    goto L_a6878;
L_a6878:
    t4 = sp + 492;
    t6 = hi_a687c;
L_a6880:
    a3 = *(volatile u16 *)(unsigned long)(t1 + (10));
    a2 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a1 = t9;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s7;
    v0 = t6 - hi_a687c + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; a0 = t8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a689c;
L_a689c:
    t1 = t1 + 2;
    *(volatile u16 *)(unsigned long)(t4 + (0)) = v0;
    branch = (t1 != t2); t4 = t4 + 2;
    if (branch) goto L_a6880;
    goto L_a68ac;
L_a68ac:
    t6 = *(volatile u16 *)(unsigned long)(s0 + (1540)); goto L_a6720;
L_a68b4:
    v1 = s0 + 1568;
L_a68b8:
    a0 = *(volatile u16 *)(unsigned long)(t2 + (0));
    t2 = t2 + 2;
    v0 = v0 + 2;
    branch = (v1 != t2); *(volatile u16 *)(unsigned long)(v0 + (-2)) = a0;
    if (branch) goto L_a68b8;
    goto L_a68cc;
L_a68cc:
    t6 = *(volatile u16 *)(unsigned long)(s0 + (1540)); goto L_a6720;
L_a68d4:
    t8 = *(volatile u16 *)(unsigned long)(s0 + (1542));
    v0 = (u32)t8 < (u32)(t5);
    branch = (v0 != 0); v0 = sp + 480;
    if (branch) goto L_a6920;
    goto L_a68e4;
L_a68e4:
    t4 = sp + 480;
    t9 = hi_a68e8;
L_a68ec:
    a3 = *(volatile u16 *)(unsigned long)(t1 + (10));
    a2 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a1 = t8;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t5;
    v0 = t9 - hi_a68e8 + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; a0 = t6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a6908;
L_a6908:
    t1 = t1 + 2;
    *(volatile u16 *)(unsigned long)(t4 + (0)) = v0;
    branch = (t1 != t2); t4 = t4 + 2;
    if (branch) goto L_a68ec;
    goto L_a6918;
L_a6918:
    t5 = *(volatile u16 *)(unsigned long)(s1 + (106)); goto L_a674c;
L_a6920:
    v1 = s0 + 1608;
L_a6924:
    a0 = *(volatile u16 *)(unsigned long)(t2 + (0));
    t2 = t2 + 2;
    v0 = v0 + 2;
    branch = (v1 != t2); *(volatile u16 *)(unsigned long)(v0 + (-2)) = a0;
    if (branch) goto L_a6924;
    goto L_a6938;
L_a6938:
    t5 = *(volatile u16 *)(unsigned long)(s1 + (106)); goto L_a674c;
L_a6940:
    t8 = *(volatile u16 *)(unsigned long)(s0 + (1546));
    v0 = (u32)t8 < (u32)(t5);
    branch = (v0 != 0); v0 = sp + 468;
    if (branch) goto L_a698c;
    goto L_a6950;
L_a6950:
    t4 = sp + 468;
    t9 = hi_a6954;
L_a6958:
    a3 = *(volatile u16 *)(unsigned long)(t1 + (10));
    a2 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a1 = t8;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t5;
    v0 = t9 - hi_a6954 + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; a0 = t6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a6974;
L_a6974:
    t1 = t1 + 2;
    *(volatile u16 *)(unsigned long)(t4 + (0)) = v0;
    branch = (t1 != t2); t4 = t4 + 2;
    if (branch) goto L_a6958;
    goto L_a6984;
L_a6984:
    a0 = 0; goto L_a677c;
L_a698c:
    v1 = s0 + 1648;
L_a6990:
    a0 = *(volatile u16 *)(unsigned long)(t2 + (0));
    t2 = t2 + 2;
    v0 = v0 + 2;
    branch = (v1 != t2); *(volatile u16 *)(unsigned long)(v0 + (-2)) = a0;
    if (branch) goto L_a6990;
    goto L_a69a4;
L_a69a4:
    a0 = 0; goto L_a677c;
L_a69ac:
    v0 = v0 & 0xffff;
    t6 = (u32)v0 < (u32)(2);
    if (t6 == 0) { *(volatile u16 *)(unsigned long)(v1 + (0)) = t5; goto L_a69c0; }
    goto L_a69bc;
L_a69bc:
    *(volatile u16 *)(unsigned long)(v1 + (0)) = v0;
L_a69c0:
    v0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = a0 - v0; goto L_a6828;
L_a69cc:
    a0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    branch = (v0 != 0); a1 = hi_a69d4;
    if (branch) goto L_a69dc;
    goto L_a69d8;
L_a69d8:
    *(volatile u16 *)(unsigned long)(a1 - hi_a69d4 + (u32)(unsigned long)ref_t32_data_e3b3a) = a0;
L_a69dc:
    a2 = *(volatile u16 *)(unsigned long)(a1 - hi_a69d4 + (u32)(unsigned long)ref_t32_data_e3b3a);
    v1 = (u32)a0 < (u32)(a2);
    v0 = a2 - a0;
    a0 = a0 - a2;
    if (v1 == 0) v0 = a0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (112));
    v0 = v0 & 0xffff;
    v0 = (u32)v1 < (u32)(v0);
    branch = (v0 != 0); v1 = hi_a6a00;
    if (branch) goto L_a6a10;
    goto L_a6a04;
L_a6a04:
    v0 = *(volatile u8 *)(unsigned long)(v1 - hi_a6a00 + (u32)(unsigned long)ref_t32_data_e3b3c);
    if (v0 != 0) { a0 = *(volatile u32 *)(unsigned long)(s0 + (108)); goto L_a6a40; }
    goto L_a6a10;
L_a6a10:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v0 = (u32)s3 < (u32)(v0);
    if (v0 != 0) { v0 = hi_a6a1c; goto L_a6a28; }
    goto L_a6a20;
L_a6a20:
    v0 = 1; goto L_a6a2c;
L_a6a28:
    v0 = *(volatile u8 *)(unsigned long)(v0 - hi_a6a1c + (u32)(unsigned long)ref_t32_data_e3b10);
L_a6a2c:
    *(volatile u16 *)(unsigned long)(s0 + (278)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    *(volatile u16 *)(unsigned long)(a1 - hi_a69d4 + (u32)(unsigned long)ref_t32_data_e3b3a) = v0;
    v0 = *(volatile u8 *)(unsigned long)(v1 - hi_a6a00 + (u32)(unsigned long)ref_t32_data_e3b3c);
    a0 = *(volatile u32 *)(unsigned long)(s0 + (108));
L_a6a40:
    v0 = v0 + 1;
    v0 = v0 & 0xff;
    a0 = (u32)a0 < (u32)(v0);
    if (a0 != 0) v0 = 0;
    *(volatile u8 *)(unsigned long)(v1 - hi_a6a00 + (u32)(unsigned long)ref_t32_data_e3b3c) = v0;
    v0 = (u32)t0 < (u32)(4096);
L_a6a58:
    branch = (v0 != 0); a0 = 32;
    if (branch) goto L_a6a78;
    goto L_a6a60;
L_a6a60:
    a0 = t0 << (0x5 & 31);
    v0 = s6 >> (0x1 & 31);
    a0 = a0 + v0;
    if (s6) { lo = a0 / s6; hi = a0 % s6; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    a0 = a0 & 0xffff;
L_a6a78:
    v0 = *(volatile u16 *)(unsigned long)(sp + (512));
    *(volatile u16 *)(unsigned long)(s1 + (90)) = t0;
    *(volatile u16 *)(unsigned long)(s1 + (92)) = s6;
    *(volatile u16 *)(unsigned long)(s1 + (96)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (518));
    *(volatile u16 *)(unsigned long)(s1 + (94)) = t3;
    *(volatile u16 *)(unsigned long)(s1 + (100)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1488));
    v0 = (u32)t0 < (u32)(v0);
    if (v0 == 0) { a1 = *(volatile u16 *)(unsigned long)(s0 + (1494)); goto L_a6aac; }
    goto L_a6aa4;
L_a6aa4:
    s5 = *(volatile u16 *)(unsigned long)(s0 + (1496)); goto L_a6b48;
L_a6aac:
    v0 = (u32)t0 < (u32)(a1);
    if (v0 == 0) { s5 = *(volatile u16 *)(unsigned long)(s0 + (1502)); goto L_a6b48; }
    goto L_a6ab8;
L_a6ab8:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1490));
    v1 = (u32)t0 < (u32)(v0);
    branch = (v1 != 0); a2 = 6;
    if (branch) goto L_a6af4;
    goto L_a6ac8;
L_a6ac8:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1492));
    v1 = (u32)t0 < (u32)(v0);
    if (v1 == 0) v0 = a1;
    a1 = 4;
    if (v1 != 0) a2 = a1;
    a3 = a2;
    a1 = 2;
    a2 = 1;
    if (v1 != 0) a1 = a2;
    v1 = a1; goto L_a6afc;
L_a6af4:
    a3 = 2;
    v1 = 0;
L_a6afc:
    a2 = s0 + 1496;
    v1 = v1 << (0x1 & 31);
    a1 = a2 + v1;
    v1 = s0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (1488));
    a2 = a2 + a3;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v0 = v0 - v1;
    t0 = t0 - v1;
    v1 = 2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a2 = a2 - a1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)t0); lo = product; hi = product >> 32;
    t0 = lo;
    if (v0) { lo = t0 / v0; hi = t0 % v0; } else { lo = ~0U; hi = t0; }
    v0 = lo;
    s5 = a1 + v0;
    s5 = s5 & 0xffff;
L_a6b48:
    s5 = a0 - s5;
    s5 = s5 & 0xffff;
    v1 = a0 >> (0x1 & 31);
    v0 = s5 << (0x8 & 31);
    v0 = v0 + v1;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    *(volatile u16 *)(unsigned long)(s1 + (98)) = s5;
    a0 = lo;
    a0 = a0 & 0xffff;
    *(volatile u32 *)(unsigned long)(s1 + (32)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (160));
    v1 = (u32)v1 < (u32)(s3);
    branch = (v1 != 0); v0 = *(volatile u16 *)(unsigned long)(s0 + (976));
    if (branch) goto L_a6d70;
    goto L_a6b80;
L_a6b80:
    v1 = (u32)v0 < (u32)(s5);
    branch = (v1 == 0); a2 = 50;
    if (branch) goto L_a713c;
    goto L_a6b8c;
L_a6b8c:
    a0 = *(volatile u16 *)(unsigned long)(s0 + (978));
    v1 = (u32)a0 < (u32)(s5);
    if (v1 != 0) { v1 = *(volatile u16 *)(unsigned long)(s0 + (980)); goto L_a6bec; }
    goto L_a6b9c;
L_a6b9c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (572));
    s5 = s5 - v0;
    s5 = s5 & 0xffff;
    a3 = sp + 352;
    a2 = s2;
    v0 = s0 + 1038;
L_a6bb4:
    a1 = *(volatile u16 *)(unsigned long)(a3 + (0));
    v1 = *(volatile s16 *)(unsigned long)(a0 + (0));
    a0 = a0 + 2;
    a3 = a3 + 2;
    v1 = v1 - a1;
    v1 = v1 * s5;
    a2 = a2 + 2;
    v1 = v1 + 16;
    v1 = (s32)v1 >> (0x5 & 31);
    v1 = a1 + v1;
    branch = (a0 != v0); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v1;
    if (branch) goto L_a6bb4;
    goto L_a6be4;
L_a6be4:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a6bec:
    v0 = (u32)v1 < (u32)(s5);
    if (v0 != 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (982)); goto L_a6c48; }
    goto L_a6bf8;
L_a6bf8:
    v1 = *(volatile u32 *)(unsigned long)(sp + (576));
    a1 = *(volatile u32 *)(unsigned long)(sp + (572));
    s5 = s5 - a0;
    s5 = s5 & 0xffff;
    a0 = s2;
    a3 = s0 + 1088;
L_a6c10:
    a2 = *(volatile s16 *)(unsigned long)(a1 + (0));
    v0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    v1 = v1 + 2;
    a1 = a1 + 2;
    v0 = v0 - a2;
    v0 = v0 * s5;
    a0 = a0 + 2;
    v0 = v0 + 32;
    v0 = (s32)v0 >> (0x6 & 31);
    v0 = v0 + a2;
    branch = (v1 != a3); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_a6c10;
    goto L_a6c40;
L_a6c40:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a6c48:
    a0 = (u32)v0 < (u32)(s5);
    if (a0 != 0) { a0 = *(volatile u16 *)(unsigned long)(s0 + (984)); goto L_a6ca4; }
    goto L_a6c54;
L_a6c54:
    s5 = s5 - v1;
    a1 = *(volatile u32 *)(unsigned long)(sp + (576));
    v1 = *(volatile u32 *)(unsigned long)(sp + (580));
    s5 = s5 & 0xffff;
    a0 = s2;
    a3 = s0 + 1138;
L_a6c6c:
    a2 = *(volatile s16 *)(unsigned long)(a1 + (0));
    v0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    v1 = v1 + 2;
    a1 = a1 + 2;
    v0 = v0 - a2;
    v0 = v0 * s5;
    a0 = a0 + 2;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + a2;
    branch = (v1 != a3); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_a6c6c;
    goto L_a6c9c;
L_a6c9c:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a6ca4:
    v1 = (u32)a0 < (u32)(s5);
    if (v1 != 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (986)); goto L_a6d00; }
    goto L_a6cb0;
L_a6cb0:
    v1 = *(volatile u32 *)(unsigned long)(sp + (584));
    a1 = *(volatile u32 *)(unsigned long)(sp + (580));
    s5 = s5 - v0;
    s5 = s5 & 0xffff;
    a0 = s2;
    a3 = s0 + 1188;
L_a6cc8:
    a2 = *(volatile s16 *)(unsigned long)(a1 + (0));
    v0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    v1 = v1 + 2;
    a1 = a1 + 2;
    v0 = v0 - a2;
    v0 = v0 * s5;
    a0 = a0 + 2;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + a2;
    branch = (v1 != a3); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_a6cc8;
    goto L_a6cf8;
L_a6cf8:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a6d00:
    v1 = (u32)v0 < (u32)(s5);
    branch = (v1 != 0); a3 = *(volatile u32 *)(unsigned long)(sp + (584));
    if (branch) goto L_a6d64;
    goto L_a6d0c;
L_a6d0c:
    a1 = *(volatile u32 *)(unsigned long)(sp + (588));
    s5 = s5 - a0;
    a0 = v0 - a0;
    s5 = s5 & 0xffff;
    t2 = (s32)a0 >> (0x1 & 31);
    a2 = s2;
    t1 = s0 + 1238;
L_a6d28:
    t0 = *(volatile s16 *)(unsigned long)(a3 + (0));
    v1 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a1 = a1 + 2;
    a3 = a3 + 2;
    v1 = v1 - t0;
    t3 = v1 * s5;
    a2 = a2 + 2;
    v0 = t3 + t2;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + t0;
    branch = (a1 != t1); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v0;
    if (branch) goto L_a6d28;
    goto L_a6d5c;
L_a6d5c:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a6d64:
    a2 = 50;
    a1 = *(volatile u32 *)(unsigned long)(sp + (588)); goto L_a72ec;
L_a6d70:
    a3 = *(volatile u32 *)(unsigned long)(s0 + (164));
    v1 = s0 + 1238;
    a2 = s0 + 1288;
    a3 = (u32)a3 < (u32)(s3);
    a1 = s0 + 1338;
    a0 = s0 + 1388;
    branch = (a3 != 0); s6 = s0 + 1438;
    if (branch) goto L_a712c;
    goto L_a6d90;
L_a6d90:
    a3 = (u32)v0 < (u32)(s5);
    if (a3 != 0) { t0 = *(volatile u16 *)(unsigned long)(s0 + (978)); goto L_a6dcc; }
    goto L_a6d9c;
L_a6d9c:
    s6 = hi_a6d9c;
    a1 = sp + 352;
    a0 = s8;
    s6 = s6 - hi_a6d9c + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s6; a2 = 50;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a6db4;
L_a6db4:
    a2 = 50;
    a1 = sp + 352;
    callee = s6; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a6dc4;
L_a6dc4:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976)); goto L_a70bc;
L_a6dcc:
    a3 = (u32)t0 < (u32)(s5);
    if (a3 != 0) { a3 = *(volatile u16 *)(unsigned long)(s0 + (980)); goto L_a6e54; }
    goto L_a6dd8;
L_a6dd8:
    a1 = *(volatile u32 *)(unsigned long)(sp + (572));
    v0 = s5 - v0;
    v0 = v0 & 0xffff;
    a2 = s2;
    t0 = s8;
    a3 = s4;
    t1 = s0 + 1038;
L_a6df4:
    t2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a1 = a1 + 2;
    a2 = a2 + 2;
    a0 = a0 - t2;
    a0 = a0 * v0;
    t0 = t0 + 2;
    v1 = v1 + 2;
    a3 = a3 + 2;
    a0 = a0 + 16;
    a0 = (s32)a0 >> (0x5 & 31);
    a0 = t2 + a0;
    *(volatile u16 *)(unsigned long)(t0 + (-2)) = a0;
    t2 = *(volatile u16 *)(unsigned long)(a2 + (-2));
    a0 = *(volatile s16 *)(unsigned long)(v1 + (-2));
    a0 = a0 - t2;
    a0 = a0 * v0;
    a0 = a0 + 16;
    a0 = (s32)a0 >> (0x5 & 31);
    a0 = t2 + a0;
    branch = (a1 != t1); *(volatile u16 *)(unsigned long)(a3 + (-2)) = a0;
    if (branch) goto L_a6df4;
    goto L_a6e4c;
L_a6e4c:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976)); goto L_a70bc;
L_a6e54:
    v0 = (u32)a3 < (u32)(s5);
    if (v0 != 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (982)); goto L_a6ee0; }
    goto L_a6e60;
L_a6e60:
    a1 = s5 - t0;
    a1 = a1 & 0xffff;
    a0 = 0;
    a3 = 50;
L_a6e70:
    v0 = *(volatile u32 *)(unsigned long)(sp + (572));
    t1 = s8 + a0;
    v0 = v0 + a0;
    t0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (576));
    v0 = v0 + a0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = v0 - t0;
    v0 = v0 * a1;
    v0 = v0 + 32;
    v0 = (s32)v0 >> (0x6 & 31);
    v0 = v0 + t0;
    *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    v0 = v1 + a0;
    t0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = a2 + a0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    t1 = s4 + a0;
    a0 = a0 + 2;
    v0 = v0 - t0;
    v0 = v0 * a1;
    v0 = v0 + 32;
    v0 = (s32)v0 >> (0x6 & 31);
    v0 = v0 + t0;
    branch = (a0 != a3); *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    if (branch) goto L_a6e70;
    goto L_a6ed8;
L_a6ed8:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976)); goto L_a70bc;
L_a6ee0:
    v1 = (u32)v0 < (u32)(s5);
    if (v1 != 0) { v1 = *(volatile u16 *)(unsigned long)(s0 + (984)); goto L_a6f6c; }
    goto L_a6eec;
L_a6eec:
    a0 = s5 - a3;
    a0 = a0 & 0xffff;
    v1 = 0;
    a3 = 50;
L_a6efc:
    v0 = *(volatile u32 *)(unsigned long)(sp + (576));
    t1 = s8 + v1;
    v0 = v0 + v1;
    t0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (580));
    v0 = v0 + v1;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = v0 - t0;
    v0 = v0 * a0;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + t0;
    *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    v0 = a2 + v1;
    t0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = a1 + v1;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    t1 = s4 + v1;
    v1 = v1 + 2;
    v0 = v0 - t0;
    v0 = v0 * a0;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + t0;
    branch = (v1 != a3); *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    if (branch) goto L_a6efc;
    goto L_a6f64;
L_a6f64:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976)); goto L_a70bc;
L_a6f6c:
    a2 = (u32)v1 < (u32)(s5);
    if (a2 != 0) { a2 = *(volatile u16 *)(unsigned long)(s0 + (986)); goto L_a6ff8; }
    goto L_a6f78;
L_a6f78:
    a2 = s5 - v0;
    a2 = a2 & 0xffff;
    v1 = 0;
    a3 = 50;
L_a6f88:
    v0 = *(volatile u32 *)(unsigned long)(sp + (580));
    t1 = s8 + v1;
    v0 = v0 + v1;
    t0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (584));
    v0 = v0 + v1;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = v0 - t0;
    v0 = v0 * a2;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + t0;
    *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    v0 = a1 + v1;
    t0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = a0 + v1;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    t1 = s4 + v1;
    v1 = v1 + 2;
    v0 = v0 - t0;
    v0 = v0 * a2;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + t0;
    branch = (v1 != a3); *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    if (branch) goto L_a6f88;
    goto L_a6ff0;
L_a6ff0:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976)); goto L_a70bc;
L_a6ff8:
    v0 = (u32)a2 < (u32)(s5);
    branch = (v0 != 0); a3 = s5 - v1;
    if (branch) goto L_a7090;
    goto L_a7004;
L_a7004:
    a2 = a2 - v1;
    a3 = a3 & 0xffff;
    t0 = (s32)a2 >> (0x1 & 31);
    a1 = 0;
    t1 = 50;
L_a7018:
    v0 = *(volatile u32 *)(unsigned long)(sp + (584));
    t3 = s8 + a1;
    v0 = v0 + a1;
    t2 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (588));
    v0 = v0 + a1;
    v1 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v1 = v1 - t2;
    t4 = v1 * a3;
    v0 = t4 + t0;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + t2;
    *(volatile u16 *)(unsigned long)(t3 + (0)) = v0;
    v0 = a0 + a1;
    t2 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = s6 + a1;
    v1 = *(volatile s16 *)(unsigned long)(v0 + (0));
    t3 = s4 + a1;
    a1 = a1 + 2;
    v1 = v1 - t2;
    t4 = v1 * a3;
    v0 = t4 + t0;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + t2;
    branch = (a1 != t1); *(volatile u16 *)(unsigned long)(t3 + (0)) = v0;
    if (branch) goto L_a7018;
    goto L_a7088;
L_a7088:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976)); goto L_a70bc;
L_a7090:
    a1 = *(volatile u32 *)(unsigned long)(sp + (588));
    s7 = hi_a7094;
    a2 = 50;
    s7 = s7 - hi_a7094 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s7; a0 = s8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a70a8;
L_a70a8:
    a2 = 50;
    a1 = s6;
    callee = s7; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a70b8;
L_a70b8:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (976));
L_a70bc:
    s5 = (u32)v0 < (u32)(s5);
    if (s5 == 0) { v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300; }
    goto L_a70c8;
L_a70c8:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (160));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (164));
    a1 = s4;
    s3 = s3 - a0;
    a0 = v0 - a0;
    s3 = s3 & 0xffff;
    t2 = (s32)a0 >> (0x1 & 31);
    a3 = s8;
    a2 = s2;
    t1 = s4 + 50;
L_a70f0:
    t0 = *(volatile s16 *)(unsigned long)(a3 + (0));
    v1 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a1 = a1 + 2;
    a3 = a3 + 2;
    v1 = v1 - t0;
    t3 = v1 * s3;
    a2 = a2 + 2;
    v0 = t3 + t2;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + t0;
    branch = (a1 != t1); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v0;
    if (branch) goto L_a70f0;
    goto L_a7124;
L_a7124:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a712c:
    a3 = (u32)v0 < (u32)(s5);
    if (a3 != 0) { t0 = *(volatile u16 *)(unsigned long)(s0 + (978)); goto L_a7144; }
    goto L_a7138;
L_a7138:
    a2 = 50;
L_a713c:
    a1 = sp + 352; goto L_a72ec;
L_a7144:
    a3 = (u32)t0 < (u32)(s5);
    if (a3 != 0) { a3 = *(volatile u16 *)(unsigned long)(s0 + (980)); goto L_a7198; }
    goto L_a7150;
L_a7150:
    s5 = s5 - v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (560));
    s5 = s5 & 0xffff;
    a0 = s2;
    a2 = v0 + 930;
L_a7164:
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v0 = *(volatile s16 *)(unsigned long)(v1 + (0));
    a0 = a0 + 2;
    v1 = v1 + 2;
    v0 = v0 - a1;
    v0 = v0 * s5;
    v0 = v0 + 16;
    v0 = (s32)v0 >> (0x5 & 31);
    v0 = a1 + v0;
    branch = (a0 != a2); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_a7164;
    goto L_a7190;
L_a7190:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a7198:
    v0 = (u32)a3 < (u32)(s5);
    if (v0 != 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (982)); goto L_a71e8; }
    goto L_a71a4;
L_a71a4:
    s5 = s5 - t0;
    s5 = s5 & 0xffff;
    a0 = s2;
L_a71b0:
    a3 = *(volatile s16 *)(unsigned long)(v1 + (0));
    v0 = *(volatile s16 *)(unsigned long)(a2 + (0));
    a2 = a2 + 2;
    v1 = v1 + 2;
    v0 = v0 - a3;
    v0 = v0 * s5;
    a0 = a0 + 2;
    v0 = v0 + 32;
    v0 = (s32)v0 >> (0x6 & 31);
    v0 = v0 + a3;
    branch = (a1 != a2); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v0;
    if (branch) goto L_a71b0;
    goto L_a71e0;
L_a71e0:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a71e8:
    v1 = (u32)v0 < (u32)(s5);
    if (v1 != 0) { v1 = *(volatile u16 *)(unsigned long)(s0 + (984)); goto L_a7238; }
    goto L_a71f4;
L_a71f4:
    s5 = s5 - a3;
    s5 = s5 & 0xffff;
    v1 = s2;
L_a7200:
    a3 = *(volatile s16 *)(unsigned long)(a2 + (0));
    v0 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a1 = a1 + 2;
    a2 = a2 + 2;
    v0 = v0 - a3;
    v0 = v0 * s5;
    v1 = v1 + 2;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + a3;
    branch = (a0 != a1); *(volatile u16 *)(unsigned long)(v1 + (-2)) = v0;
    if (branch) goto L_a7200;
    goto L_a7230;
L_a7230:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a7238:
    a2 = (u32)v1 < (u32)(s5);
    if (a2 != 0) { v0 = *(volatile u16 *)(unsigned long)(s0 + (986)); goto L_a7288; }
    goto L_a7244;
L_a7244:
    s5 = s5 - v0;
    s5 = s5 & 0xffff;
    v1 = s2;
L_a7250:
    a2 = *(volatile s16 *)(unsigned long)(a1 + (0));
    v0 = *(volatile s16 *)(unsigned long)(a0 + (0));
    a0 = a0 + 2;
    a1 = a1 + 2;
    v0 = v0 - a2;
    v0 = v0 * s5;
    v1 = v1 + 2;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v0 = v0 + a2;
    branch = (s6 != a0); *(volatile u16 *)(unsigned long)(v1 + (-2)) = v0;
    if (branch) goto L_a7250;
    goto L_a7280;
L_a7280:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a7288:
    a1 = (u32)v0 < (u32)(s5);
    branch = (a1 != 0); s5 = s5 - v1;
    if (branch) goto L_a72e4;
    goto L_a7294;
L_a7294:
    a1 = v0 - v1;
    s5 = s5 & 0xffff;
    t1 = (s32)a1 >> (0x1 & 31);
    a2 = s2;
    t0 = s0 + 1488;
L_a72a8:
    a3 = *(volatile s16 *)(unsigned long)(a0 + (0));
    v1 = *(volatile s16 *)(unsigned long)(s6 + (0));
    s6 = s6 + 2;
    a0 = a0 + 2;
    v1 = v1 - a3;
    t2 = v1 * s5;
    a2 = a2 + 2;
    v0 = t2 + t1;
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    v0 = v0 + a3;
    branch = (s6 != t0); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v0;
    if (branch) goto L_a72a8;
    goto L_a72dc;
L_a72dc:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748)); goto L_a7300;
L_a72e4:
    a2 = 50;
    a1 = s6;
L_a72ec:
    v0 = hi_a72ec;
    v0 = v0 - hi_a72ec + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a72fc;
L_a72fc:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1748));
L_a7300:
    v0 = 1;
    branch = (v1 != v0); a1 = s0 + 1506;
    if (branch) goto L_a7460;
    goto L_a730c;
L_a730c:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1668));
    branch = (v0 != 0); v0 = *(volatile u16 *)(unsigned long)(sp + (512));
    if (branch) goto L_a734c;
    goto L_a7318;
L_a7318:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (808));
    branch = (v0 != 0); v0 = *(volatile u16 *)(unsigned long)(sp + (512));
    if (branch) goto L_a734c;
    goto L_a7324;
L_a7324:
    v0 = sp + 32;
    a3 = *(volatile u32 *)(unsigned long)(sp + (596));
    a1 = *(volatile u32 *)(unsigned long)(sp + (600));
    a0 = *(volatile u32 *)(unsigned long)(sp + (592));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_a7338;
    v0 = v0 - hi_a7338 + (u32)(unsigned long)ref_tisp_wdr_get_lum_s;
    callee = v0; a2 = sp + 512;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7348;
L_a7348:
    v0 = *(volatile u16 *)(unsigned long)(sp + (512));
L_a734c:
    v0 = (u32)v0 < (u32)(3901);
    branch = (v0 != 0); v0 = *(volatile u16 *)(unsigned long)(sp + (516));
    if (branch) goto L_a736c;
    goto L_a7358;
L_a7358:
    v1 = *(volatile u16 *)(unsigned long)(sp + (514));
    v0 = v0 + v1;
    v0 = (s32)v0 >> (0x1 & 31);
    *(volatile u16 *)(unsigned long)(sp + (516)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (516));
L_a736c:
    v1 = *(volatile u16 *)(unsigned long)(s0 + (1752));
    v0 = (u32)v1 < (u32)(v0);
    branch = (v0 != 0); a1 = s0 + 1506;
    if (branch) goto L_a7460;
    goto L_a737c;
L_a737c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (568));
    t0 = *(volatile u32 *)(unsigned long)(sp + (556));
    a2 = v0 + 50;
    v1 = t0;
L_a738c:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = a0 & 0xffff;
    a1 = (u32)a1 < (u32)(4096);
    if (a1 == 0) { a0 = 4095; goto L_a73a0; }
    goto L_a73a0;
L_a73a0:
    v0 = v0 + 2;
    *(volatile u16 *)(unsigned long)(v1 + (0)) = a0;
    branch = (v0 != a2); v1 = v1 + 2;
    if (branch) goto L_a738c;
    goto L_a73b0;
L_a73b0:
    v0 = *(volatile u16 *)(unsigned long)(sp + (516));
    a0 = *(volatile u16 *)(unsigned long)(s0 + (1750));
    v1 = (u32)a0 < (u32)(v0);
    if (v1 != 0) { a3 = *(volatile u16 *)(unsigned long)(s0 + (1756)); goto L_a73e4; }
    goto L_a73c4;
L_a73c4:
    a1 = *(volatile u32 *)(unsigned long)(sp + (556));
L_a73c8:
    v0 = hi_a73c8;
    a2 = 50;
    v0 = v0 - hi_a73c8 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a73dc;
L_a73dc:
    a1 = s0 + 1506; goto L_a7460;
L_a73e4:
    a2 = *(volatile u16 *)(unsigned long)(s0 + (1754));
    a1 = *(volatile u16 *)(unsigned long)(s0 + (1752));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_a73f0;
    v0 = v0 - hi_a73f0 + (u32)(unsigned long)ref_tisp_wdr_interplate;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7400;
L_a7400:
    v1 = *(volatile u32 *)(unsigned long)(sp + (556));
    v0 = v0 & 0xffff;
    a2 = 128;
    a1 = s2;
    a3 = v1 + 50;
    a2 = a2 - v0;
L_a7418:
    v1 = *(volatile u16 *)(unsigned long)(t0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (0));
    product = (s64)(s32)v1 * (s32)v0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a2 * (s32)a0); lo = product; hi = product >> 32;
    v1 = lo;
    v1 = (s32)v1 >> (0x7 & 31);
    *(volatile u16 *)(unsigned long)(t0 + (0)) = v1;
    a0 = v1;
    v1 = v1 & 0xffff;
    v1 = (u32)v1 < (u32)(4096);
    if (v1 == 0) { a0 = 4095; goto L_a7448; }
    goto L_a7448;
L_a7448:
    *(volatile u16 *)(unsigned long)(t0 + (0)) = a0;
    t0 = t0 + 2;
    branch = (t0 != a3); a1 = a1 + 2;
    if (branch) goto L_a7418;
    goto L_a7458;
L_a7458:
    a1 = *(volatile u32 *)(unsigned long)(sp + (556)); goto L_a73c8;
L_a7460:
    t0 = sp + 456;
    a3 = s0 + 1518;
    a2 = sp + 504;
    t2 = s0 + 1514;
    t1 = 2;
L_a7474:
    v1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a1 + (-2));
    v0 = v1 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    branch = (v1 == a0); *(volatile u16 *)(unsigned long)(t0 + (2)) = v0;
    if (branch) goto L_a74c0;
    goto L_a748c;
L_a748c:
    a0 = *(volatile u16 *)(unsigned long)(t0 + (0));
    v1 = *(volatile u16 *)(unsigned long)(a3 + (0));
    a0 = v0 - a0;
    if (a0 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)a0 / (s32)t1; hi = (s32)a0 % (s32)t1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = *(volatile u16 *)(unsigned long)(a3 + (-2));
    v1 = v1 - v0;
    v1 = v1 << (0x4 & 31);
    v0 = lo;
    v0 = v1 + v0;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = v0; goto L_a74c4;
L_a74c0:
    *(volatile u16 *)(unsigned long)(a2 + (0)) = 0;
L_a74c4:
    a1 = a1 + 2;
    t0 = t0 + 2;
    a3 = a3 + 2;
    branch = (t2 != a1); a2 = a2 + 2;
    if (branch) goto L_a7474;
    goto L_a74d8;
L_a74d8:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (1516));
    v1 = *(volatile u32 *)(unsigned long)(sp + (560));
    a0 = *(volatile u32 *)(unsigned long)(sp + (640));
    a2 = *(volatile u16 *)(unsigned long)(sp + (456));
    a3 = *(volatile u16 *)(unsigned long)(sp + (458));
    t0 = *(volatile u16 *)(unsigned long)(sp + (504));
    t1 = *(volatile u16 *)(unsigned long)(sp + (460));
    t2 = *(volatile u16 *)(unsigned long)(sp + (506));
    t3 = *(volatile u16 *)(unsigned long)(sp + (462));
    t4 = *(volatile u16 *)(unsigned long)(sp + (508));
    t5 = *(volatile u16 *)(unsigned long)(sp + (510));
    v0 = v0 << (0x4 & 31);
    *(volatile u16 *)(unsigned long)(v1 + (930)) = v0;
    t6 = 33;
    v0 = a0;
    v1 = 1;
L_a7518:
    a1 = (u32)a2 < (u32)(v1);
    if (a1 != 0) { a1 = (u32)a3 < (u32)(v1); goto L_a752c; }
    goto L_a7524;
L_a7524:
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0)); goto L_a7568;
L_a752c:
    if (a1 != 0) { a1 = (u32)t1 < (u32)(v1); goto L_a7540; }
    goto L_a7534;
L_a7534:
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = t0 + a1; goto L_a7568;
L_a7540:
    if (a1 != 0) { a1 = (u32)t3 < (u32)(v1); goto L_a7554; }
    goto L_a7548;
L_a7548:
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = t2 + a1; goto L_a7568;
L_a7554:
    branch = (a1 != 0); a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    if (branch) goto L_a7564;
    goto L_a755c;
L_a755c:
    a1 = t4 + a1; goto L_a7568;
L_a7564:
    a1 = t5 + a1;
L_a7568:
    v1 = v1 + 1;
    v1 = v1 & 0xffff;
    *(volatile u16 *)(unsigned long)(v0 + (2)) = a1;
    branch = (v1 != t6); v0 = v0 + 2;
    if (branch) goto L_a7518;
    goto L_a757c;
L_a757c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (560));
    v0 = v0 + 996;
L_a7584:
    v1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = a0 + 2;
    v1 = v1 >> (0x4 & 31);
    branch = (a0 != v0); *(volatile u16 *)(unsigned long)(a0 + (-2)) = v1;
    if (branch) goto L_a7584;
    goto L_a7598;
L_a7598:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    a1 = 1;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (20));
    a0 = v0 - a0;
    v0 = (s32)a0 < (s32)(0);
    if (v0 != 0) a0 = a1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (16));
    t1 = hi_a75b8;
    t1 = t1 - hi_a75b8 + (u32)(unsigned long)ref_tisp_wdr_log2;
    v1 = v1 - v0;
    v1 = v1 << (0xa & 31);
    v0 = (s32)a0 >> (0x1 & 31);
    v0 = v1 + v0;
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s1 + (24)) = v0;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (256));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (258));
    v0 = v0 - v1;
    v1 = (s32)0 < (s32)(v0);
    if (v1 == 0) v0 = a1;
    v1 = *(volatile u16 *)(unsigned long)(s0 + (260));
    a0 = (s32)v0 >> (0x1 & 31);
    v1 = v1 << (0xc & 31);
    v1 = v1 + a0;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s1 + (28)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s0 + (290));
    a0 = *(volatile u16 *)(unsigned long)(s0 + (292));
    callee = t1; a0 = a0 - v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a761c;
L_a761c:
    *(volatile u16 *)(unsigned long)(s0 + (294)) = v0;
    a0 = *(volatile u16 *)(unsigned long)(s0 + (302));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (300));
    callee = t1; a0 = a0 - v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7630;
L_a7630:
    *(volatile u16 *)(unsigned long)(s0 + (304)) = v0;
    a0 = *(volatile u16 *)(unsigned long)(s0 + (270));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (268));
    callee = t1; a0 = a0 - v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7644;
L_a7644:
    *(volatile u16 *)(unsigned long)(s0 + (276)) = v0;
    a0 = *(volatile u16 *)(unsigned long)(s0 + (264));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (262));
    callee = t1; a0 = a0 - v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7658;
L_a7658:
    a0 = *(volatile u32 *)(unsigned long)(sp + (544));
    *(volatile u16 *)(unsigned long)(s0 + (266)) = v0;
    s0 = hi_a7660;
    s0 = s0 - hi_a7660 + (u32)(unsigned long)ref_private_kfree;
    callee = s0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7670;
L_a7670:
    callee = s0; a0 = *(volatile u32 *)(unsigned long)(sp + (548));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7678;
L_a7678:
    callee = s0; a0 = s8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7680;
L_a7680:
    callee = s0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7688;
L_a7688:
    callee = s0; a0 = *(volatile u32 *)(unsigned long)(sp + (556));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7690;
L_a7690:
    callee = s0; a0 = *(volatile u32 *)(unsigned long)(sp + (568));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_a7698;
L_a7698:
    ra = *(volatile u32 *)(unsigned long)(sp + (708));
    s8 = *(volatile u32 *)(unsigned long)(sp + (704));
    s7 = *(volatile u32 *)(unsigned long)(sp + (700));
    s6 = *(volatile u32 *)(unsigned long)(sp + (696));
    s5 = *(volatile u32 *)(unsigned long)(sp + (692));
    s4 = *(volatile u32 *)(unsigned long)(sp + (688));
    s3 = *(volatile u32 *)(unsigned long)(sp + (684));
    s2 = *(volatile u32 *)(unsigned long)(sp + (680));
    s1 = *(volatile u32 *)(unsigned long)(sp + (676));
    s0 = *(volatile u32 *)(unsigned long)(sp + (672));
    sp = sp + 712;
    return ((u64)v1 << 32) | v0;
}
