/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e35e0[] __asm__("t32_data_e35e0");
extern unsigned char ref_t32_data_e35b0[] __asm__("t32_data_e35b0");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_c0488[] __asm__("t32_data_c0488");
extern unsigned char ref_t32_data_c04a4[] __asm__("t32_data_c04a4");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_d8320[] __asm__("t32_data_d8320");
extern unsigned char ref_t32_data_d8120[] __asm__("t32_data_d8120");
extern unsigned char ref_t32_data_e31b0[] __asm__("t32_data_e31b0");
extern unsigned char ref_t32_data_d8914[] __asm__("t32_data_d8914");
extern unsigned char ref_tisp_tmo_adr_ispint_adr_16[] __asm__("tisp_tmo_adr_ispint_adr_16");
extern unsigned char ref_tisp_tmo_adr_local_info[] __asm__("tisp_tmo_adr_local_info");
extern unsigned char ref_t32_data_d88d4[] __asm__("t32_data_d88d4");
extern unsigned char ref_tisp_tmo_adr_map_curve1[] __asm__("tisp_tmo_adr_map_curve1");
extern unsigned char ref_t32_data_e3518[] __asm__("t32_data_e3518");
extern unsigned char ref_tisp_tmo_adr_interp1_short[] __asm__("tisp_tmo_adr_interp1_short");
extern unsigned char ref_t32_data_d87a0[] __asm__("t32_data_d87a0");
extern unsigned char ref_t32_data_d88a4[] __asm__("t32_data_d88a4");
extern unsigned char ref_t32_data_e3188[] __asm__("t32_data_e3188");
extern unsigned char ref_t32_data_d88f4[] __asm__("t32_data_d88f4");
extern unsigned char ref_tisp_tmo_adr_map_y_filter_sp[] __asm__("tisp_tmo_adr_map_y_filter_sp");
extern unsigned char ref_t32_data_e3160[] __asm__("t32_data_e3160");
extern unsigned char ref_tisp_tmo_adr_subsection_up[] __asm__("tisp_tmo_adr_subsection_up");
extern unsigned char ref_tisp_tmo_adr_map_y_filter[] __asm__("tisp_tmo_adr_map_y_filter");
extern unsigned char ref_t32_data_e3500[] __asm__("t32_data_e3500");
extern unsigned char ref_tisp_adr_faceae_curve_adjust[] __asm__("tisp_adr_faceae_curve_adjust");
extern unsigned char ref_t32_data_d88f0[] __asm__("t32_data_d88f0");
extern unsigned char ref_t32_data_e3516[] __asm__("t32_data_e3516");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_ca3e0[] __asm__("t32_data_ca3e0");
u64 tisp_tmo_adr_fpga(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[304] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_9ace4 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9ad30 = ((u32)(unsigned long)ref_t32_data_e35b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9ad28 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_9ad24 = ((u32)(unsigned long)ref_t32_data_c0488 + 0x8000U) & 0xffff0000U;
    const u32 hi_9ae28 = ((u32)(unsigned long)ref_t32_data_c04a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9ae78 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_9aeac = ((u32)(unsigned long)ref_t32_data_d8320 + 0x8000U) & 0xffff0000U;
    const u32 hi_9aec0 = ((u32)(unsigned long)ref_t32_data_d8120 + 0x8000U) & 0xffff0000U;
    const u32 hi_9afa0 = ((u32)(unsigned long)ref_t32_data_e31b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9af98 = ((u32)(unsigned long)ref_t32_data_d8914 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b0b8 = ((u32)(unsigned long)ref_tisp_tmo_adr_ispint_adr_16 + 0x8000U) & 0xffff0000U;
    const u32 hi_9afc4 = ((u32)(unsigned long)ref_tisp_tmo_adr_local_info + 0x8000U) & 0xffff0000U;
    const u32 hi_9b1f0 = ((u32)(unsigned long)ref_t32_data_d88d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b248 = ((u32)(unsigned long)ref_tisp_tmo_adr_map_curve1 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b33c = ((u32)(unsigned long)ref_tisp_tmo_adr_ispint_adr_16 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b368 = ((u32)(unsigned long)ref_t32_data_e3518 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b3fc = ((u32)(unsigned long)ref_tisp_tmo_adr_interp1_short + 0x8000U) & 0xffff0000U;
    const u32 hi_9b3f8 = ((u32)(unsigned long)ref_t32_data_d87a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b3e0 = ((u32)(unsigned long)ref_t32_data_d88a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b4a0 = ((u32)(unsigned long)ref_t32_data_d87a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b4b8 = ((u32)(unsigned long)ref_t32_data_e3188 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b658 = ((u32)(unsigned long)ref_tisp_tmo_adr_interp1_short + 0x8000U) & 0xffff0000U;
    const u32 hi_9b69c = ((u32)(unsigned long)ref_t32_data_d88f4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b7b4 = ((u32)(unsigned long)ref_tisp_tmo_adr_map_curve1 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b8d0 = ((u32)(unsigned long)ref_tisp_tmo_adr_map_y_filter_sp + 0x8000U) & 0xffff0000U;
    const u32 hi_9b950 = ((u32)(unsigned long)ref_t32_data_e3160 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b958 = ((u32)(unsigned long)ref_tisp_tmo_adr_subsection_up + 0x8000U) & 0xffff0000U;
    const u32 hi_9bac4 = ((u32)(unsigned long)ref_t32_data_d88d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9baec = ((u32)(unsigned long)ref_tisp_tmo_adr_map_y_filter + 0x8000U) & 0xffff0000U;
    const u32 hi_9bae8 = ((u32)(unsigned long)ref_t32_data_d88d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9bda4 = ((u32)(unsigned long)ref_t32_data_e3500 + 0x8000U) & 0xffff0000U;
    const u32 hi_9bdb8 = ((u32)(unsigned long)ref_tisp_adr_faceae_curve_adjust + 0x8000U) & 0xffff0000U;
    const u32 hi_9bde0 = ((u32)(unsigned long)ref_t32_data_d88d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_9be30 = ((u32)(unsigned long)ref_t32_data_d88f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9bdcc = ((u32)(unsigned long)ref_t32_data_e3516 + 0x8000U) & 0xffff0000U;
    const u32 hi_9bea4 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_9bea0 = ((u32)(unsigned long)ref_t32_data_ca3e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b378 = ((u32)(unsigned long)ref_t32_data_d87a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b3a0 = ((u32)(unsigned long)ref_t32_data_e35e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9b504 = ((u32)(unsigned long)ref_t32_data_d87a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_9bce0 = ((u32)(unsigned long)ref_t32_data_e3500 + 0x8000U) & 0xffff0000U;
    const u32 hi_9bdb4 = ((u32)(unsigned long)ref_t32_data_e3516 + 0x8000U) & 0xffff0000U;
    const u32 hi_9be18 = ((u32)(unsigned long)ref_t32_data_e3500 + 0x8000U) & 0xffff0000U;
    const u32 hi_9be80 = ((u32)(unsigned long)ref_t32_data_e3500 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[240];
L_9ace0:
    sp = sp + -960;
    v0 = hi_9ace4;
    v0 = v0 - hi_9ace4 + (u32)(unsigned long)ref_t32_data_e35e0;
    *(volatile u32 *)(unsigned long)(sp + (960)) = a0;
    a0 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (956)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (948)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (940)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (928)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (952)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (944)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (936)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (932)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (924)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (920)) = s0;
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = hi_9ad24;
    s5 = hi_9ad28;
    s6 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = hi_9ad30;
    v0 = v0 - hi_9ad30 + (u32)(unsigned long)ref_t32_data_e35b0;
    a0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    s5 = s5 - hi_9ad28 + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 26;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = a1 - hi_9ad24 + (u32)(unsigned long)ref_t32_data_c0488;
    a0 = sp + 652;
    *(volatile u32 *)(unsigned long)(sp + (756)) = v0;
    v0 = s0 + 68;
    *(volatile u32 *)(unsigned long)(sp + (772)) = v0;
    v0 = s0 + 100;
    *(volatile u32 *)(unsigned long)(sp + (776)) = v0;
    v0 = s0 + 128;
    *(volatile u32 *)(unsigned long)(sp + (752)) = v0;
    v0 = s1 + 3968;
    *(volatile u32 *)(unsigned long)(sp + (820)) = v0;
    v0 = s1 + 5696;
    *(volatile u32 *)(unsigned long)(sp + (780)) = v0;
    v0 = s6 + 9574;
    *(volatile u32 *)(unsigned long)(sp + (816)) = v0;
    v0 = s6 + 8336;
    *(volatile u32 *)(unsigned long)(sp + (824)) = v0;
    v0 = s6 + 8798;
    *(volatile u32 *)(unsigned long)(sp + (828)) = v0;
    v0 = s6 + 8820;
    *(volatile u32 *)(unsigned long)(sp + (832)) = v0;
    v0 = s6 + 8732;
    *(volatile u32 *)(unsigned long)(sp + (836)) = v0;
    v0 = s6 + 8754;
    *(volatile u32 *)(unsigned long)(sp + (840)) = v0;
    v0 = s6 + 9272;
    *(volatile u32 *)(unsigned long)(sp + (764)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (10048));
    s7 = s1 + 9664;
    s2 = s1 + 9760;
    *(volatile u32 *)(unsigned long)(sp + (844)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (10052));
    *(volatile u32 *)(unsigned long)(sp + (848)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9916));
    *(volatile u32 *)(unsigned long)(sp + (760)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9918));
    *(volatile u32 *)(unsigned long)(sp + (784)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9920));
    *(volatile u32 *)(unsigned long)(sp + (788)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9922));
    *(volatile u32 *)(unsigned long)(sp + (792)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9906));
    *(volatile u32 *)(unsigned long)(sp + (852)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9908));
    *(volatile u32 *)(unsigned long)(sp + (796)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9910));
    *(volatile u32 *)(unsigned long)(sp + (856)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9844));
    *(volatile u32 *)(unsigned long)(sp + (860)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9822));
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (864)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9ae24;
L_9ae24:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9926));
    a1 = hi_9ae28;
    a2 = 18;
    *(volatile u32 *)(unsigned long)(sp + (800)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9928));
    a1 = a1 - hi_9ae28 + (u32)(unsigned long)ref_t32_data_c04a4;
    a0 = sp + 680;
    *(volatile u32 *)(unsigned long)(sp + (804)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9930));
    *(volatile u32 *)(unsigned long)(sp + (868)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9638));
    *(volatile u32 *)(unsigned long)(sp + (872)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9934));
    *(volatile u32 *)(unsigned long)(sp + (876)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9936));
    *(volatile u32 *)(unsigned long)(sp + (768)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9938));
    *(volatile u32 *)(unsigned long)(sp + (808)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9940));
    callee = s5; *(volatile u32 *)(unsigned long)(sp + (812)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9ae78;
L_9ae78:
    s5 = hi_9ae78;
    a2 = 32;
    a1 = 0;
    s5 = s5 - hi_9ae78 + ((u32)(unsigned long)ref_memset + (0));
    callee = s5; a0 = sp + 508;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9ae90;
L_9ae90:
    a2 = 34;
    a1 = 0;
    callee = s5; a0 = sp + 472;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9aea0;
L_9aea0:
    v0 = 10;
    *(volatile u16 *)(unsigned long)(sp + (472)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (8316));
    a3 = hi_9aeac;
    t1 = *(volatile s16 *)(unsigned long)(s6 + (8314));
    *(volatile u32 *)(unsigned long)(sp + (880)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (8318));
    a1 = *(volatile u32 *)(unsigned long)(a3 - hi_9aeac + (u32)(unsigned long)ref_t32_data_d8320);
    a2 = hi_9aec0;
    *(volatile u32 *)(unsigned long)(sp + (884)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (8320));
    a2 = a2 - hi_9aec0 + (u32)(unsigned long)ref_t32_data_d8120;
    t0 = s1 + 5696;
    *(volatile u32 *)(unsigned long)(sp + (888)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (8322));
    a0 = 0;
    t4 = 16;
    *(volatile u32 *)(unsigned long)(sp + (892)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (8324));
    t5 = 32;
    t6 = 64;
    *(volatile u32 *)(unsigned long)(sp + (896)) = v0;
    t7 = 96;
    v0 = 0;
    t3 = 128;
L_9af04:
    if (a0 != 0) { t8 = *(volatile u32 *)(unsigned long)(t0 + (0)); goto L_9af14; }
    goto L_9af0c;
L_9af0c:
    t2 = *(volatile u32 *)(unsigned long)(s1 + (5696)); goto L_9af1c;
L_9af14:
    t2 = *(volatile u32 *)(unsigned long)(t0 + (-4));
    t2 = t8 - t2;
L_9af1c:
    t8 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v1 = t2 * t8;
    branch = (a0 != t4); v0 = v1 + v0;
    if (branch) goto L_9af3c;
    goto L_9af2c;
L_9af2c:
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (50)) = v1; goto L_9af80;
L_9af3c:
    branch = (a0 != t5); ;
    if (branch) goto L_9af54;
    goto L_9af44;
L_9af44:
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (52)) = v1; goto L_9af80;
L_9af54:
    branch = (a0 != t6); ;
    if (branch) goto L_9af6c;
    goto L_9af5c;
L_9af5c:
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (54)) = v1; goto L_9af80;
L_9af6c:
    if (a0 != t7) { a0 = a0 + 1; goto L_9af84; }
    goto L_9af74;
L_9af74:
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (56)) = v1;
L_9af80:
    a0 = a0 + 1;
L_9af84:
    a2 = a2 + 4;
    branch = (a0 != t3); t0 = t0 + 4;
    if (branch) goto L_9af04;
    goto L_9af90;
L_9af90:
    a0 = *(volatile u32 *)(unsigned long)(a3 - hi_9aeac + (u32)(unsigned long)ref_t32_data_d8320);
    s8 = s2;
    s2 = hi_9af98;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    s1 = hi_9afa0;
    t6 = s7;
    s4 = s0;
    s7 = 4095;
    s5 = 0;
    s3 = 0;
    s1 = s1 - hi_9afa0 + (u32)(unsigned long)ref_t32_data_e31b0;
    v0 = lo;
    *(volatile u16 *)(unsigned long)(s0 + (48)) = v0;
    v0 = hi_9afc4;
    *(volatile u32 *)(unsigned long)(sp + (904)) = v0;
    v0 = s2 - hi_9af98 + (u32)(unsigned long)ref_t32_data_d8914;
    *(volatile u32 *)(unsigned long)(sp + (908)) = v0;
L_9afd4:
    s2 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a0 = 3;
    v0 = (s32)s5 < (s32)(s2);
    if (v0 != 0) s5 = s2;
    v0 = (s32)s2 < (s32)(s7);
    if (v0 != 0) s7 = s2;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (0));
    *(volatile u32 *)(unsigned long)(sp + (900)) = v0;
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9574));
    branch = (v0 != a0); a0 = 2;
    if (branch) goto L_9b03c;
    goto L_9b000;
L_9b000:
    a0 = s3 & 0x3;
    a1 = 6;
    v1 = a0 * a1;
    v0 = (s32)s3 >> (0x2 & 31);
    a0 = 0xc800;
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (816));
    v0 = v0 + 5;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = v0 * t1;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo; goto L_9b120;
L_9b03c:
    branch = (v0 != a0); v0 = *(volatile u32 *)(unsigned long)(sp + (904));
    if (branch) goto L_9b0f4;
    goto L_9b044;
L_9b044:
    a2 = *(volatile u32 *)(unsigned long)(sp + (832));
    v0 = sp + 472;
    a3 = s6 + 8316;
    a1 = 0;
    t9 = 17;
L_9b058:
    a0 = (s32)a1 < (s32)(3);
    if (a0 == 0) { a0 = (s32)a1 < (s32)(11); goto L_9b06c; }
    goto L_9b064;
L_9b064:
    a0 = *(volatile s16 *)(unsigned long)(a3 + (0)); goto L_9b078;
L_9b06c:
    if (a0 == 0) { *(volatile u16 *)(unsigned long)(v0 + (0)) = 0; goto L_9b07c; }
    goto L_9b074;
L_9b074:
    a0 = *(volatile s16 *)(unsigned long)(a2 + (0));
L_9b078:
    *(volatile u16 *)(unsigned long)(v0 + (0)) = a0;
L_9b07c:
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t8 = (int16_t)a0;
    if ((s32)t8 < 0) { a0 = 0; goto L_9b08c; }
    goto L_9b08c;
L_9b08c:
    t8 = (int16_t)a0;
    t8 = (s32)t8 < (s32)(1025);
    if (t8 == 0) { a0 = 1024; goto L_9b09c; }
    goto L_9b09c;
L_9b09c:
    a1 = a1 + 1;
    *(volatile u16 *)(unsigned long)(v0 + (0)) = a0;
    a3 = a3 + 2;
    v0 = v0 + 2;
    branch = (a1 != t9); a2 = a2 + 2;
    if (branch) goto L_9b058;
    goto L_9b0b4;
L_9b0b4:
    a1 = *(volatile u32 *)(unsigned long)(sp + (908));
    v0 = hi_9b0b8;
    a0 = (int16_t)s2;
    a3 = 17;
    a2 = sp + 472;
    v0 = v0 - hi_9b0b8 + (u32)(unsigned long)ref_tisp_tmo_adr_ispint_adr_16;
    *(volatile u32 *)(unsigned long)(sp + (916)) = t6;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (912)) = t1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b0d8;
L_9b0d8:
    t1 = *(volatile u32 *)(unsigned long)(sp + (912));
    a0 = 0xc800;
    t6 = *(volatile u32 *)(unsigned long)(sp + (916));
    v0 = v0 * t1;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo; goto L_9b120;
L_9b0f4:
    a3 = *(volatile u32 *)(unsigned long)(sp + (888));
    a2 = *(volatile u32 *)(unsigned long)(sp + (884));
    a1 = *(volatile u32 *)(unsigned long)(sp + (880));
    a0 = t1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s2;
    v0 = v0 - hi_9afc4 + (u32)(unsigned long)ref_tisp_tmo_adr_local_info;
    *(volatile u32 *)(unsigned long)(sp + (916)) = t6;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (912)) = t1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b118;
L_9b118:
    t6 = *(volatile u32 *)(unsigned long)(sp + (916));
    t1 = *(volatile u32 *)(unsigned long)(sp + (912));
L_9b120:
    a2 = *(volatile s16 *)(unsigned long)(s6 + (9270));
    a1 = 1;
    a0 = s3 << (0x2 & 31);
    branch = (a2 != a1); v1 = sp + 40;
    if (branch) goto L_9b158;
    goto L_9b134;
L_9b134:
    a1 = v1 + a0;
    a0 = s1 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = 10000;
    a0 = v0 * a0;
    if (a0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)a0 / (s32)a2; hi = (s32)a0 % (s32)a2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(a1 + (0)) = a0; goto L_9b160;
L_9b158:
    a0 = v1 + a0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
L_9b160:
    a0 = *(volatile s16 *)(unsigned long)(s6 + (100));
    a1 = 2;
    branch = (a0 == a1); a1 = 3;
    if (branch) goto L_9b19c;
    goto L_9b170;
L_9b170:
    branch = (a0 == a1); v0 = s2;
    if (branch) goto L_9b19c;
    goto L_9b178;
L_9b178:
    a1 = 4;
    branch = (a0 == a1); v0 = *(volatile u32 *)(unsigned long)(sp + (900));
    if (branch) goto L_9b19c;
    goto L_9b184;
L_9b184:
    a1 = 5;
    branch = (a0 != a1); v0 = 0;
    if (branch) goto L_9b19c;
    goto L_9b190;
L_9b190:
    v0 = s3 << (0x2 & 31);
    v0 = s1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
L_9b19c:
    *(volatile u16 *)(unsigned long)(s4 + (0)) = v0;
    s3 = s3 + 1;
    v0 = 24;
    t6 = t6 + 4;
    s8 = s8 + 4;
    branch = (s3 != v0); s4 = s4 + 2;
    if (branch) goto L_9afd4;
    goto L_9b1b8;
L_9b1b8:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (100));
    if (v0 != 0) { a0 = *(volatile s16 *)(unsigned long)(s6 + (100)); goto L_9b1d8; }
    goto L_9b1c4;
L_9b1c4:
    v0 = *(volatile u16 *)(unsigned long)(sp + (844));
    *(volatile u16 *)(unsigned long)(s0 + (0)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (848));
    *(volatile u16 *)(unsigned long)(s0 + (2)) = v0;
    a0 = *(volatile s16 *)(unsigned long)(s6 + (100));
L_9b1d8:
    v0 = 1;
    branch = (a0 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (852));
    if (branch) goto L_9b1f0;
    goto L_9b1e4;
L_9b1e4:
    *(volatile u16 *)(unsigned long)(s0 + (0)) = s7;
    *(volatile u16 *)(unsigned long)(s0 + (2)) = s5;
    v1 = *(volatile u32 *)(unsigned long)(sp + (852));
L_9b1f0:
    v0 = hi_9b1f0;
    a1 = 1;
    *(volatile u32 *)(unsigned long)(sp + (816)) = v0;
    s1 = v0 - hi_9b1f0 + (u32)(unsigned long)ref_t32_data_d88d4;
    a0 = 28;
    branch = (v1 != a1); v0 = 0;
    if (branch) goto L_9b2d8;
    goto L_9b20c;
L_9b20c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (856));
    v1 = *(volatile u32 *)(unsigned long)(sp + (796));
    a2 = v0 + 155;
    a0 = (s32)a2 < (s32)(155);
    v0 = 155;
    if (a0 == 0) v0 = a2;
    s4 = v1;
    a0 = (s32)v1 < (s32)(0);
    if (a0 != 0) s4 = 0;
    a1 = (s32)s4 < (s32)(101);
    a0 = 100;
    a2 = (s32)v0 < (s32)(256);
    if (a1 == 0) s4 = a0;
    a0 = 255;
    if (a2 != 0) a0 = v0;
    v0 = hi_9b248;
    a2 = a0;
    a1 = 30;
    v0 = v0 - hi_9b248 + (u32)(unsigned long)ref_tisp_tmo_adr_map_curve1;
    callee = v0; a0 = sp + 136;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b260;
L_9b260:
    a1 = sp + 136;
    a2 = 0;
    a3 = 100;
    t0 = 28;
L_9b270:
    v0 = s1 + a2;
    v0 = *(volatile s16 *)(unsigned long)(v0 + (2));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(sp + (776));
    product = (s64)(s32)v0 * (s32)a3; lo = product; hi = product >> 32;
    a0 = a0 - v0;
    t1 = v1 + a2;
    a2 = a2 + 2;
    a1 = a1 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a0 * (s32)s4); lo = product; hi = product >> 32;
    v0 = lo;
    v0 = v0 + 50;
    if (v0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)v0 / (s32)a3; hi = (s32)v0 % (s32)a3; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (a2 != t0); *(volatile u16 *)(unsigned long)(t1 + (0)) = v0;
    if (branch) goto L_9b270;
    goto L_9b2b0;
L_9b2b0:
    v1 = *(volatile u32 *)(unsigned long)(sp + (860));
L_9b2b4:
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(sp + (772));
    if (branch) goto L_9b384;
    goto L_9b2c0;
L_9b2c0:
    a1 = s6 + 9824;
    a2 = sp + 700;
    t0 = s6 + 9842;
    t1 = 800;
    a3 = 100; goto L_9b2fc;
L_9b2d8:
    a1 = s1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (776));
    a2 = *(volatile s16 *)(unsigned long)(a1 + (2));
    a1 = v1 + v0;
    v0 = v0 + 2;
    branch = (v0 != a0); *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_9b2d8;
    goto L_9b2f4;
L_9b2f4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (860)); goto L_9b2b4;
L_9b2fc:
    a0 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a1 = a1 + 2;
    a2 = a2 + 2;
    v0 = (s32)a0 < (s32)(0);
    if (v0 != 0) a0 = 0;
    v0 = a0;
    a0 = (s32)a0 < (s32)(801);
    if (a0 == 0) v0 = t1;
    v0 = v0 << (0xa & 31);
    if (v0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)v0 / (s32)a3; hi = (s32)v0 % (s32)a3; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (a1 != t0); *(volatile u16 *)(unsigned long)(a2 + (-2)) = v0;
    if (branch) goto L_9b2fc;
    goto L_9b330;
L_9b330:
    t4 = *(volatile u32 *)(unsigned long)(sp + (772));
    t5 = s1;
    t6 = s0 + 100;
    t7 = hi_9b33c;
L_9b340:
    a0 = *(volatile s16 *)(unsigned long)(t5 + (0));
    a3 = 9;
    a2 = sp + 700;
    v0 = t7 - hi_9b33c + (u32)(unsigned long)ref_tisp_tmo_adr_ispint_adr_16;
    callee = v0; a1 = sp + 680;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b358;
L_9b358:
    *(volatile u16 *)(unsigned long)(t4 + (0)) = v0;
    t4 = t4 + 2;
    branch = (t4 != t6); t5 = t5 + 2;
    if (branch) goto L_9b340;
    goto L_9b368;
L_9b368:
    v0 = hi_9b368;
L_9b36c:
    a1 = *(volatile s16 *)(unsigned long)(v0 - hi_9b368 + (u32)(unsigned long)ref_t32_data_e3518);
    a0 = 1;
    if (a1 != a0) { v0 = hi_9b378; goto L_9b4a4; }
    goto L_9b37c;
L_9b37c:
    *(volatile u16 *)(unsigned long)(v0 - hi_9b368 + (u32)(unsigned long)ref_t32_data_e3518) = 0; goto L_9b3a4;
L_9b384:
    a0 = s0 + 100;
    a1 = 1024;
    *(volatile u16 *)(unsigned long)(v0 + (0)) = a1;
L_9b390:
    v0 = v0 + 2;
    if (v0 != a0) { *(volatile u16 *)(unsigned long)(v0 + (0)) = a1; goto L_9b390; }
    goto L_9b39c;
L_9b39c:
    v0 = hi_9b3a0; goto L_9b36c;
L_9b3a4:
    v0 = 4095;
    *(volatile u16 *)(unsigned long)(sp + (564)) = v0;
    *(volatile u16 *)(unsigned long)(sp + (540)) = 0;
    v0 = 0;
    a0 = 22;
L_9b3b8:
    a1 = s6 + v0;
    a2 = *(volatile s16 *)(unsigned long)(a1 + (9784));
    v1 = sp + 540;
    a1 = v1 + v0;
    v0 = v0 + 2;
    branch = (v0 != a0); *(volatile u16 *)(unsigned long)(a1 + (2)) = a2;
    if (branch) goto L_9b3b8;
    goto L_9b3d4;
L_9b3d4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (864));
    a0 = 1;
    s5 = s6 + 376;
    s4 = hi_9b3e0;
    branch = (v1 != a0); v0 = 0;
    if (branch) goto L_9b4e0;
    goto L_9b3ec;
L_9b3ec:
    a1 = *(volatile u32 *)(unsigned long)(sp + (764));
    s3 = 13;
    s8 = 129;
    s7 = hi_9b3f8;
    s2 = hi_9b3fc;
    s2 = s2 - hi_9b3fc + (u32)(unsigned long)ref_tisp_tmo_adr_interp1_short;
    a3 = sp + 624;
    a2 = sp + 652;
    a0 = s7 - hi_9b3f8 + (u32)(unsigned long)ref_t32_data_d87a0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s3;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = s8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b41c;
L_9b41c:
    a3 = sp + 596;
    a2 = sp + 624;
    a1 = sp + 540;
    a0 = sp + 652;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s3;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b438;
L_9b438:
    a0 = *(volatile u32 *)(unsigned long)(sp + (764));
    a3 = sp + 568;
    a2 = sp + 596;
    a1 = s7 - hi_9b3f8 + (u32)(unsigned long)ref_t32_data_d87a0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s3;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = s8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b454;
L_9b454:
    v0 = 23;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (756));
    a1 = sp + 568;
    a0 = sp + 652;
    a3 = v0 + 872;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    callee = s2; a2 = s4 - hi_9b3e0 + (u32)(unsigned long)ref_t32_data_d88a4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b478;
L_9b478:
    v0 = *(volatile u32 *)(unsigned long)(sp + (756));
    v1 = *(volatile u32 *)(unsigned long)(sp + (756));
    a0 = s5;
    v0 = v0 + 874;
    a1 = v1 + 916;
L_9b48c:
    a2 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = v0 + 2;
    a0 = a0 + 2;
    branch = (v0 != a1); *(volatile u16 *)(unsigned long)(a0 + (-2)) = a2;
    if (branch) goto L_9b48c;
    goto L_9b4a0;
L_9b4a0:
    v0 = hi_9b4a0;
L_9b4a4:
    v0 = v0 - hi_9b4a0 + (u32)(unsigned long)ref_t32_data_d87a0;
    *(volatile u32 *)(unsigned long)(sp + (772)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (788));
    v0 = *(volatile u32 *)(unsigned long)(sp + (784));
    s4 = 1;
    s8 = hi_9b4b8;
    s7 = v0 + v1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (792));
    s2 = 0;
    s8 = s8 - hi_9b4b8 + (u32)(unsigned long)ref_t32_data_e3188;
    v0 = s7 + v0;
    s7 = (s32)0 < (s32)(v0);
    if (s7 == 0) v0 = s4;
    s7 = v0; goto L_9b924;
L_9b4e0:
    s4 = s4 - hi_9b3e0 + (u32)(unsigned long)ref_t32_data_d88a4;
    a0 = 42;
L_9b4e8:
    a1 = s4 + v0;
    a2 = *(volatile s16 *)(unsigned long)(a1 + (2));
    a1 = s5 + v0;
    v0 = v0 + 2;
    branch = (v0 != a0); *(volatile u16 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_9b4e8;
    goto L_9b500;
L_9b500:
    v0 = hi_9b504; goto L_9b4a4;
L_9b508:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
L_9b50c:
    a2 = *(volatile u32 *)(unsigned long)(a0 + (4));
    a2 = (s32)a1 < (s32)(a2);
    if (a2 != 0) { a0 = a0 + 4; goto L_9b528; }
    goto L_9b51c;
L_9b51c:
    a1 = a1 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = a1;
    a0 = a0 + 4;
L_9b528:
    if (s8 != a0) { a1 = *(volatile u32 *)(unsigned long)(a0 + (0)); goto L_9b50c; }
    goto L_9b530;
L_9b530:
    a0 = 4095;
    *(volatile u16 *)(unsigned long)(sp + (734)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(a3 + (40));
    *(volatile u16 *)(unsigned long)(sp + (720)) = 0;
    a1 = 14;
    *(volatile u16 *)(unsigned long)(sp + (750)) = a0;
    a0 = 0;
L_9b54c:
    a3 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = sp + 736;
    a2 = v1 + a0;
    a0 = a0 + 2;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = a3;
    branch = (a0 != a1); v0 = v0 + 4;
    if (branch) goto L_9b54c;
    goto L_9b568;
L_9b568:
    a2 = *(volatile u32 *)(unsigned long)(sp + (824));
    t1 = *(volatile u32 *)(unsigned long)(sp + (840));
    t0 = *(volatile u32 *)(unsigned long)(sp + (836));
    a3 = sp + 720;
    a0 = v1;
    t3 = s6 + 8348;
    t2 = 100;
L_9b584:
    a1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    v0 = (int16_t)a1;
    v0 = (s32)v0 < (s32)(251);
    if (v0 == 0) { a1 = 250; goto L_9b598; }
    goto L_9b598;
L_9b598:
    *(volatile u16 *)(unsigned long)(a2 + (0)) = a1;
    v0 = *(volatile s16 *)(unsigned long)(t1 + (0));
    t4 = (int16_t)a1;
    t5 = *(volatile u16 *)(unsigned long)(a3 + (0));
    v0 = v0 * t4;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (2));
    v0 = v0 + 50;
    if (v0 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)v0 / (s32)t2; hi = (s32)v0 % (s32)t2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    t4 = (int16_t)v0;
    v0 = v0 + t5;
    *(volatile u16 *)(unsigned long)(a3 + (2)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v0 = a1 - v0;
    v0 = v0 & 0xffff;
    a1 = (int16_t)v0;
    a1 = (s32)t4 < (s32)(a1);
    branch = (a1 == 0); a2 = a2 + 2;
    if (branch) goto L_9b5ec;
    goto L_9b5e4;
L_9b5e4:
    v0 = t5 + v0;
    *(volatile u16 *)(unsigned long)(a3 + (2)) = v0;
L_9b5ec:
    *(volatile u16 *)(unsigned long)(t0 + (0)) = t4;
    t1 = t1 + 2;
    a3 = a3 + 2;
    a0 = a0 + 2;
    branch = (t3 != a2); t0 = t0 + 2;
    if (branch) goto L_9b584;
    goto L_9b604;
L_9b604:
    v0 = *(volatile u16 *)(unsigned long)(s6 + (8740));
    a0 = *(volatile u16 *)(unsigned long)(s6 + (8734));
    s3 = sp + 508;
    *(volatile u16 *)(unsigned long)(s6 + (8750)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s6 + (8742));
    a1 = sp + 720;
    a3 = s3;
    *(volatile u16 *)(unsigned long)(s6 + (8752)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s6 + (8732));
    v0 = v0 + a0;
    *(volatile u16 *)(unsigned long)(s6 + (8746)) = v0;
    a0 = *(volatile u16 *)(unsigned long)(s6 + (8738));
    v0 = *(volatile u16 *)(unsigned long)(s6 + (8736));
    v0 = v0 + a0;
    *(volatile u16 *)(unsigned long)(s6 + (8748)) = v0;
    v0 = 16;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = 8;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (816));
    a2 = v0 - hi_9b1f0 + (u32)(unsigned long)ref_t32_data_d88d4;
    v0 = hi_9b658;
    v0 = v0 - hi_9b658 + (u32)(unsigned long)ref_tisp_tmo_adr_interp1_short;
    callee = v0; a0 = sp + 736;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b668;
L_9b668:
    a0 = sp + 360;
    v0 = 0;
    a1 = 28;
L_9b674:
    a2 = s3 + v0;
    a2 = *(volatile s16 *)(unsigned long)(a2 + (2));
    v0 = v0 + 2;
    a0 = a0 + 4;
    branch = (v0 != a1); *(volatile u32 *)(unsigned long)(a0 + (-4)) = a2;
    if (branch) goto L_9b674;
    goto L_9b68c;
L_9b68c:
    t6 = 14;
    t6 = s2 * t6;
    t4 = *(volatile u32 *)(unsigned long)(sp + (828));
    a1 = sp + 304;
    a3 = hi_9b69c;
    a3 = a3 - hi_9b69c + (u32)(unsigned long)ref_t32_data_d88f4;
    s3 = s1;
    t3 = s6 + 8798;
    t1 = s1;
    t0 = a1;
    a2 = 0;
    t7 = 10000;
    t2 = 64;
    t5 = 4095;
    t8 = 14;
L_9b6c8:
    v1 = *(volatile u32 *)(unsigned long)(sp + (820));
    v0 = a2 << (0x2 & 31);
    v0 = v0 + t6;
    v0 = v1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = a0 << (0xc & 31);
    a0 = v0 - a0;
    a0 = a0 + 5000;
    if (a0 == 0x80000000U && t7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t7) { lo = (s32)a0 / (s32)t7; hi = (s32)a0 % (s32)t7; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = (s32)a2 < (s32)(11);
    branch = (v0 == 0); a0 = lo;
    if (branch) goto L_9b990;
    goto L_9b6f8;
L_9b6f8:
    v0 = *(volatile s16 *)(unsigned long)(t4 + (0));
L_9b6fc:
    t9 = *(volatile s16 *)(unsigned long)(a3 + (0));
    v0 = v0 * t9;
    v0 = v0 + 32;
    if (v0 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)v0 / (s32)t2; hi = (s32)v0 % (s32)t2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    t9 = (s32)v0 < (s32)(a0);
    if (t9 == 0) { t9 = *(volatile s16 *)(unsigned long)(a3 + (0)); goto L_9b998; }
    goto L_9b71c;
L_9b71c:
    if (a2 != 0) { a0 = *(volatile u32 *)(unsigned long)(t0 + (-4)); goto L_9b9d4; }
    goto L_9b724;
L_9b724:
    *(volatile u32 *)(unsigned long)(sp + (304)) = v0;
L_9b728:
    a0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    a2 = a2 + 1;
    t0 = t0 + 4;
    v0 = (s32)a0 < (s32)(4096);
    if (v0 == 0) a0 = t5;
    *(volatile u32 *)(unsigned long)(t0 + (-4)) = a0;
    a3 = a3 + 2;
    t1 = t1 + 2;
    t4 = t4 + 2;
    branch = (a2 != t8); t3 = t3 + 2;
    if (branch) goto L_9b6c8;
    goto L_9b754;
L_9b754:
    t1 = 100;
    t0 = s3;
    a2 = 0;
    a3 = t1 - s5;
    t2 = 14;
L_9b768:
    v0 = *(volatile s16 *)(unsigned long)(t0 + (2));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a0 = (s32)a0 < (s32)(v0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(a1 + (0)) = v0; goto L_9b77c; }
    goto L_9b77c;
L_9b77c:
    product = (s64)(s32)v0 * (s32)a3; lo = product; hi = product >> 32;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a2 = a2 + 1;
    a1 = a1 + 4;
    t0 = t0 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s5 * (s32)a0); lo = product; hi = product >> 32;
    v0 = lo;
    v0 = v0 + 50;
    if (v0 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)v0 / (s32)t1; hi = (s32)v0 % (s32)t1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (a2 != t2); *(volatile u32 *)(unsigned long)(a1 + (-4)) = v0;
    if (branch) goto L_9b768;
    goto L_9b7ac;
L_9b7ac:
    a2 = *(volatile u32 *)(unsigned long)(sp + (896));
    a1 = *(volatile u32 *)(unsigned long)(sp + (892));
    v0 = hi_9b7b4;
    v0 = v0 - hi_9b7b4 + (u32)(unsigned long)ref_tisp_tmo_adr_map_curve1;
    a0 = sp + 248;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (776)) = a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b7c8;
L_9b7c8:
    a3 = *(volatile u32 *)(unsigned long)(sp + (776));
    v0 = sp + 248;
    t0 = s3;
    a2 = 0;
    t1 = 100;
    t2 = 14;
L_9b7e0:
    a0 = *(volatile s16 *)(unsigned long)(t0 + (2));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = (s32)a1 < (s32)(a0);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (0)) = a0; goto L_9b7f4; }
    goto L_9b7f4;
L_9b7f4:
    product = (s64)(s32)a3 * (s32)a0; lo = product; hi = product >> 32;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a2 + 1;
    v0 = v0 + 4;
    t0 = t0 + 2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)s5 * (s32)a1); lo = product; hi = product >> 32;
    a0 = lo;
    a0 = a0 + 50;
    if (a0 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)a0 / (s32)t1; hi = (s32)a0 % (s32)t1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    branch = (a2 != t2); *(volatile u32 *)(unsigned long)(v0 + (-4)) = a0;
    if (branch) goto L_9b7e0;
    goto L_9b824;
L_9b824:
    v0 = 0;
    a2 = 56;
L_9b82c:
    v1 = sp + 192;
    a3 = v1 + v0;
    v1 = sp + 360;
    a0 = v1 + v0;
    v1 = sp + 304;
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = v1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(sp + (788));
    product = (s64)(s32)v1 * (s32)a0; lo = product; hi = product >> 32;
    v1 = *(volatile u32 *)(unsigned long)(sp + (784));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a1); lo = product; hi = product >> 32;
    v1 = sp + 248;
    a0 = v1 + v0;
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(sp + (792));
    v0 = v0 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)a1); lo = product; hi = product >> 32;
    a0 = lo;
    if (a0 == 0x80000000U && s7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s7) { lo = (s32)a0 / (s32)s7; hi = (s32)a0 % (s32)s7; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = lo;
    branch = (v0 != a2); *(volatile u32 *)(unsigned long)(a3 + (0)) = v1;
    if (branch) goto L_9b82c;
    goto L_9b888;
L_9b888:
    v0 = *(volatile u32 *)(unsigned long)(sp + (760));
    branch = (v0 != 0); a0 = 56;
    if (branch) goto L_9b9e0;
    goto L_9b894;
L_9b894:
    v1 = sp + 416;
    a1 = v1 + v0;
    v1 = sp + 360;
    a2 = v1 + v0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 + 4;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_9b894;
    goto L_9b8b4;
L_9b8b4:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9864));
L_9b8b8:
    if (v0 != s4) { a0 = 2; goto L_9babc; }
    goto L_9b8c0;
L_9b8c0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (816));
    a2 = 3;
    a1 = sp + 416;
    a0 = v0 - hi_9b1f0 + (u32)(unsigned long)ref_t32_data_d88d4;
L_9b8d0:
    v0 = hi_9b8d0;
    v0 = v0 - hi_9b8d0 + (u32)(unsigned long)ref_tisp_tmo_adr_map_y_filter_sp;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b8e0;
L_9b8e0:
    a2 = s2 << (0x3 & 31);
L_9b8e4:
    a0 = sp + 416;
    a2 = a2 - s2;
    v0 = 0;
    a3 = 28;
L_9b8f4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (752));
    t0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = a2 + v0;
    a1 = v1 + a1;
    v0 = v0 + 2;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = t0;
    branch = (v0 != a3); a0 = a0 + 4;
    if (branch) goto L_9b8f4;
    goto L_9b914;
L_9b914:
    s2 = s2 + 4;
    v0 = 96;
    branch = (s2 == v0); v1 = *(volatile u32 *)(unsigned long)(sp + (800));
    if (branch) goto L_9bb08;
    goto L_9b924;
L_9b924:
    v0 = sp + s2;
    s5 = *(volatile u32 *)(unsigned long)(v0 + (40));
    v0 = 16;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = 10;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = 8;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (780));
    a3 = *(volatile u32 *)(unsigned long)(sp + (764));
    a2 = *(volatile u32 *)(unsigned long)(sp + (772));
    s3 = hi_9b950;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_9b958;
    a0 = s3 - hi_9b950 + (u32)(unsigned long)ref_t32_data_e3160;
    v0 = v0 - hi_9b958 + (u32)(unsigned long)ref_tisp_tmo_adr_subsection_up;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    callee = v0; a1 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9b970;
L_9b970:
    a0 = *(volatile u32 *)(unsigned long)(s3 - hi_9b950 + (u32)(unsigned long)ref_t32_data_e3160);
    v0 = (s32)0 < (s32)(a0);
    if (v0 == 0) a0 = s4;
    v0 = s3 - hi_9b950 + (u32)(unsigned long)ref_t32_data_e3160;
    *(volatile u32 *)(unsigned long)(s3 - hi_9b950 + (u32)(unsigned long)ref_t32_data_e3160) = a0;
    a3 = v0;
    a0 = v0; goto L_9b508;
L_9b990:
    v0 = *(volatile s16 *)(unsigned long)(t3 + (0)); goto L_9b6fc;
L_9b998:
    t9 = (s32)a0 < (s32)(t9);
    branch = (t9 == 0); v0 = a0;
    if (branch) goto L_9b71c;
    goto L_9b9a4;
L_9b9a4:
    a0 = *(volatile s16 *)(unsigned long)(t1 + (0));
    v0 = *(volatile s16 *)(unsigned long)(t1 + (2));
    t9 = t5 - a0;
    v0 = v0 - a0;
    branch = (a2 == 0); a0 = 4095;
    if (branch) goto L_9b9c4;
    goto L_9b9bc;
L_9b9bc:
    a0 = *(volatile u32 *)(unsigned long)(t0 + (-4));
    a0 = t5 - a0;
L_9b9c4:
    v0 = a0 * v0;
    if (v0 == 0x80000000U && t9 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t9) { lo = (s32)v0 / (s32)t9; hi = (s32)v0 % (s32)t9; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo; goto L_9b71c;
L_9b9d4:
    v0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(t0 + (0)) = v0; goto L_9b728;
L_9b9e0:
    branch = (v0 != s4); v1 = *(volatile u32 *)(unsigned long)(sp + (760));
    if (branch) goto L_9ba18;
    goto L_9b9e8;
L_9b9e8:
    v0 = 0;
    a0 = 56;
L_9b9f0:
    v1 = sp + 416;
    a1 = v1 + v0;
    v1 = sp + 304;
    a2 = v1 + v0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 + 4;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_9b9f0;
    goto L_9ba10;
L_9ba10:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9864)); goto L_9b8b8;
L_9ba18:
    v0 = 2;
    branch = (v1 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (760));
    if (branch) goto L_9ba54;
    goto L_9ba24;
L_9ba24:
    v0 = 0;
    a0 = 56;
L_9ba2c:
    v1 = sp + 416;
    a1 = v1 + v0;
    v1 = sp + 248;
    a2 = v1 + v0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 + 4;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_9ba2c;
    goto L_9ba4c;
L_9ba4c:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9864)); goto L_9b8b8;
L_9ba54:
    v0 = 3;
    branch = (v1 != v0); a0 = s3;
    if (branch) goto L_9ba90;
    goto L_9ba60;
L_9ba60:
    v0 = 0;
    a0 = 56;
L_9ba68:
    v1 = sp + 416;
    a1 = v1 + v0;
    v1 = sp + 192;
    a2 = v1 + v0;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 + 4;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(a1 + (0)) = a2;
    if (branch) goto L_9ba68;
    goto L_9ba88;
L_9ba88:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9864)); goto L_9b8b8;
L_9ba90:
    v0 = 0;
    a1 = 56;
L_9ba98:
    a3 = *(volatile s16 *)(unsigned long)(a0 + (2));
    v1 = sp + 416;
    a2 = v1 + v0;
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = a3;
    branch = (v0 != a1); a0 = a0 + 2;
    if (branch) goto L_9ba98;
    goto L_9bab4;
L_9bab4:
    v0 = *(volatile s16 *)(unsigned long)(s6 + (9864)); goto L_9b8b8;
L_9babc:
    if (v0 != a0) { a0 = 3; goto L_9bad8; }
    goto L_9bac4;
L_9bac4:
    a0 = hi_9bac4;
    a2 = *(volatile s16 *)(unsigned long)(s6 + (9862));
    a1 = sp + 416;
    a0 = a0 - hi_9bac4 + (u32)(unsigned long)ref_t32_data_d88d4; goto L_9b8d0;
L_9bad8:
    if (v0 != a0) { a2 = s2 << (0x3 & 31); goto L_9b8e4; }
    goto L_9bae0;
L_9bae0:
    a3 = *(volatile s16 *)(unsigned long)(s6 + (9860));
    a2 = *(volatile s16 *)(unsigned long)(s6 + (9862));
    a0 = hi_9bae8;
    v0 = hi_9baec;
    a1 = sp + 416;
    v0 = v0 - hi_9baec + (u32)(unsigned long)ref_tisp_tmo_adr_map_y_filter;
    callee = v0; a0 = a0 - hi_9bae8 + (u32)(unsigned long)ref_t32_data_d88d4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9bb00;
L_9bb00:
    a2 = s2 << (0x3 & 31); goto L_9b8e4;
L_9bb08:
    a0 = 1;
    branch = (v1 != a0); v0 = 0;
    if (branch) goto L_9bc74;
    goto L_9bb14;
L_9bb14:
    v0 = *(volatile u32 *)(unsigned long)(sp + (804));
    v1 = *(volatile u32 *)(unsigned long)(sp + (804));
    a0 = (s32)v0 < (s32)(513);
    v0 = 512;
    if (a0 == 0) v1 = v0;
    a0 = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (868));
    v0 = 9;
    branch = (v1 == v0); v1 = *(volatile u32 *)(unsigned long)(sp + (800));
    if (branch) goto L_9bb48;
    goto L_9bb3c;
L_9bb3c:
    v0 = (s32)0 < (s32)(a0);
    if (v0 != 0) v1 = a0;
    a0 = v1;
L_9bb48:
    a3 = *(volatile u32 *)(unsigned long)(sp + (752));
    t0 = *(volatile u32 *)(unsigned long)(sp + (756));
    t3 = a0 << (0x15 & 31);
    t6 = s0 + 800;
    t7 = 28;
    t4 = 4096;
    t5 = 0x10U << 16;
L_9bb64:
    t2 = 0;
    v0 = 0;
L_9bb6c:
    a1 = a3 + t2;
    t1 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a1 = t0 + t2;
    a1 = *(volatile s16 *)(unsigned long)(a1 + (200));
    t2 = t2 + 2;
    a2 = (s32)a1 < (s32)(t1);
    t8 = t1 - a1;
    a1 = a1 - t1;
    if (a2 != 0) a1 = t8;
    a2 = (s32)v0 < (s32)(a1);
    branch = (t2 != t7); if (a2 != 0) v0 = a1;
    if (branch) goto L_9bb6c;
    goto L_9bb9c;
L_9bb9c:
    a1 = (s32)a0 < (s32)(v0);
    branch = (a1 == 0); t1 = a3;
    if (branch) goto L_9bc3c;
    goto L_9bba8;
L_9bba8:
    if (t3 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)t3 / (s32)v0; hi = (s32)t3 % (s32)v0; } else { lo = (s32)t3 < 0 ? 1 : ~0U; hi = t3; }
    t2 = t0;
    a1 = a3;
    t1 = 4082;
    t8 = lo;
L_9bbbc:
    v0 = *(volatile s16 *)(unsigned long)(a1 + (0));
    a2 = *(volatile s16 *)(unsigned long)(t2 + (200));
    t9 = (s32)a2 < (s32)(v0);
    if (t9 == 0) { v0 = a2 - v0; goto L_9bbec; }
    goto L_9bbd0;
L_9bbd0:
    v0 = v0 - a2;
    v1 = v0 * t8;
    v0 = v1 + t5;
    v0 = (s32)v0 >> (0x15 & 31);
    a2 = v0 + a2;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a2; goto L_9bc00;
L_9bbec:
    v1 = v0 * t8;
    v0 = v1 + t5;
    v0 = (s32)v0 >> (0x15 & 31);
    v0 = a2 - v0;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = v0;
L_9bc00:
    a2 = *(volatile s16 *)(unsigned long)(a1 + (0));
    t2 = t2 + 2;
    a1 = a1 + 2;
    v0 = (s32)t1 < (s32)(a2);
    if (v0 != 0) a2 = t1;
    v0 = (int16_t)a2;
    t1 = t1 + 1;
    *(volatile u16 *)(unsigned long)(a1 + (-2)) = v0;
    branch = (t1 != t4); *(volatile u16 *)(unsigned long)(t2 + (198)) = v0;
    if (branch) goto L_9bbbc;
    goto L_9bc28;
L_9bc28:
    a3 = a3 + 28;
L_9bc2c:
    branch = (a3 != t6); t0 = t0 + 28;
    if (branch) goto L_9bb64;
    goto L_9bc34;
L_9bc34:
    v1 = *(volatile u32 *)(unsigned long)(sp + (872)); goto L_9bcb4;
L_9bc3c:
    v0 = 4082;
L_9bc40:
    a2 = *(volatile s16 *)(unsigned long)(t1 + (0));
    t1 = t1 + 2;
    a1 = (s32)v0 < (s32)(a2);
    if (a1 != 0) a2 = v0;
    a1 = (int16_t)a2;
    a2 = v0 << (0x1 & 31);
    a2 = t0 + a2;
    v0 = v0 + 1;
    *(volatile u16 *)(unsigned long)(t1 + (-2)) = a1;
    branch = (v0 != t4); *(volatile u16 *)(unsigned long)(a2 + (-7964)) = a1;
    if (branch) goto L_9bc40;
    goto L_9bc6c;
L_9bc6c:
    a3 = a3 + 28; goto L_9bc2c;
L_9bc74:
    a3 = 28;
    a2 = 672;
    a0 = 0;
L_9bc80:
    v1 = *(volatile u32 *)(unsigned long)(sp + (752));
    a1 = a0 + v0;
    a0 = a0 + 2;
    t0 = v1 + a1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (756));
    t0 = *(volatile s16 *)(unsigned long)(t0 + (0));
    a1 = v1 + a1;
    branch = (a0 != a3); *(volatile u16 *)(unsigned long)(a1 + (200)) = t0;
    if (branch) goto L_9bc80;
    goto L_9bca4;
L_9bca4:
    v0 = v0 + 28;
    if (v0 != a2) { a0 = 0; goto L_9bc80; }
    goto L_9bcb0;
L_9bcb0:
    v1 = *(volatile u32 *)(unsigned long)(sp + (872));
L_9bcb4:
    v0 = 1;
    branch = (v1 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (876));
    if (branch) goto L_9bcdc;
    goto L_9bcc0;
L_9bcc0:
    a2 = *(volatile u32 *)(unsigned long)(sp + (752)); goto L_9bcec;
L_9bcc8:
    a2 = a2 + 28;
    branch = (a2 != t4); t2 = s6 + 9640;
    if (branch) goto L_9bd00;
    goto L_9bcd4;
L_9bcd4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (876));
    v0 = 1;
L_9bcdc:
    if (v1 != v0) { v0 = hi_9bce0; goto L_9bda8; }
    goto L_9bce4;
L_9bce4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (812)); goto L_9bd64;
L_9bcec:
    t4 = s0 + 800;
    t5 = 1;
    t3 = 100;
    t6 = 14;
    t2 = s6 + 9640;
L_9bd00:
    a3 = a2;
    t0 = s3;
    t1 = 0;
    v0 = 0;
L_9bd10:
    a1 = *(volatile s16 *)(unsigned long)(t0 + (0));
    a0 = *(volatile s16 *)(unsigned long)(t0 + (2));
    t1 = t1 + 1;
    a0 = a0 - a1;
    a1 = *(volatile s16 *)(unsigned long)(t2 + (0));
    if (a0 == 0) a0 = t5;
    a0 = a1 * a0;
    a1 = *(volatile s16 *)(unsigned long)(a3 + (0));
    a0 = a0 + 50;
    if (a0 == 0x80000000U && t3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t3) { lo = (s32)a0 / (s32)t3; hi = (s32)a0 % (s32)t3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    v0 = a0 + v0;
    a0 = (s32)a1 < (s32)(v0);
    if (a0 != 0) v0 = a1;
    v0 = (int16_t)v0;
    branch = (t1 == t6); *(volatile u16 *)(unsigned long)(a3 + (0)) = v0;
    if (branch) goto L_9bcc8;
    goto L_9bd54;
L_9bd54:
    t0 = t0 + 2;
    a3 = a3 + 2;
    t2 = t2 + 2; goto L_9bd10;
L_9bd64:
    branch = ((s32)v1 >= 0); v0 = *(volatile u16 *)(unsigned long)(sp + (812));
    if (branch) goto L_9bd70;
    goto L_9bd6c;
L_9bd6c:
    v0 = 0;
L_9bd70:
    v1 = (int16_t)v0;
    v1 = (s32)v1 < (s32)(512);
    if (v1 == 0) { v0 = 511; goto L_9bd80; }
    goto L_9bd80;
L_9bd80:
    v1 = *(volatile u32 *)(unsigned long)(sp + (780));
    v0 = (int16_t)v0;
    v0 = v0 << (0x2 & 31);
    v0 = v1 + v0;
    v1 = *(volatile s16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(sp + (768));
    v0 = (s32)v1 < (s32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (808));
    if (branch) goto L_9bdd0;
    goto L_9bda4;
L_9bda4:
    v0 = hi_9bda4;
L_9bda8:
    v1 = *(volatile u8 *)(unsigned long)(v0 - hi_9bda4 + (u32)(unsigned long)ref_t32_data_e3500);
    v0 = 1;
    if (v1 != v0) { v0 = hi_9bdb4; goto L_9be84; }
    goto L_9bdb8;
L_9bdb8:
    v0 = hi_9bdb8;
    v0 = v0 - hi_9bdb8 + (u32)(unsigned long)ref_tisp_adr_faceae_curve_adjust;
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(sp + (960));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9bdc8;
L_9bdc8:
    v0 = hi_9bdcc; goto L_9be84;
L_9bdd0:
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); s0 = s0 + 800;
    if (branch) goto L_9be1c;
    goto L_9bddc;
L_9bddc:
    v1 = *(volatile u32 *)(unsigned long)(sp + (752));
    a0 = hi_9bde0;
    a0 = a0 - hi_9bde0 + (u32)(unsigned long)ref_t32_data_d88d4;
    a1 = 28;
    v0 = 0;
L_9bdf0:
    a2 = a0 + v0;
    a3 = *(volatile s16 *)(unsigned long)(a2 + (2));
    a2 = v1 + v0;
    v0 = v0 + 2;
    branch = (v0 != a1); *(volatile u16 *)(unsigned long)(a2 + (0)) = a3;
    if (branch) goto L_9bdf0;
    goto L_9be08;
L_9be08:
    v1 = v1 + 28;
    if (s0 != v1) { v0 = 0; goto L_9bdf0; }
    goto L_9be14;
L_9be14:
    v0 = hi_9be18; goto L_9bda8;
L_9be1c:
    a0 = *(volatile u32 *)(unsigned long)(sp + (768));
    a1 = *(volatile u32 *)(unsigned long)(sp + (768));
    v0 = *(volatile u32 *)(unsigned long)(sp + (752));
    a0 = v1 - a0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (808));
    t1 = hi_9be30;
    t1 = t1 - hi_9be30 + (u32)(unsigned long)ref_t32_data_d88f0;
    a1 = v1 - a1;
    a2 = s3;
L_9be40:
    a3 = v0;
L_9be44:
    t0 = *(volatile s16 *)(unsigned long)(a3 + (0));
    v1 = *(volatile s16 *)(unsigned long)(a2 + (2));
    a2 = a2 + 2;
    a3 = a3 + 2;
    v1 = t0 - v1;
    v1 = v1 * a0;
    if (v1 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v1 / (s32)a1; hi = (s32)v1 % (s32)a1; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = t0 - v1;
    branch = (t1 != a2); *(volatile u16 *)(unsigned long)(a3 + (-2)) = v1;
    if (branch) goto L_9be44;
    goto L_9be70;
L_9be70:
    v0 = v0 + 28;
    if (s0 != v0) { a2 = s3; goto L_9be40; }
    goto L_9be7c;
L_9be7c:
    v0 = hi_9be80; goto L_9bda8;
L_9be84:
    v1 = *(volatile u16 *)(unsigned long)(v0 - hi_9bdcc + (u32)(unsigned long)ref_t32_data_e3516);
    v0 = 1000;
    if (v0) { lo = v1 / v0; hi = v1 % v0; } else { lo = ~0U; hi = v1; }
    v1 = hi;
    v0 = v1 & 0xffff;
    branch = (v0 != 0); ra = *(volatile u32 *)(unsigned long)(sp + (956));
    if (branch) goto L_9beb8;
    goto L_9bea0;
L_9bea0:
    a0 = hi_9bea0;
    v0 = hi_9bea4;
    v0 = v0 - hi_9bea4 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_9bea0 + (u32)(unsigned long)ref_t32_data_ca3e0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_9beb4;
L_9beb4:
    ra = *(volatile u32 *)(unsigned long)(sp + (956));
L_9beb8:
    s8 = *(volatile u32 *)(unsigned long)(sp + (952));
    s7 = *(volatile u32 *)(unsigned long)(sp + (948));
    s6 = *(volatile u32 *)(unsigned long)(sp + (944));
    s5 = *(volatile u32 *)(unsigned long)(sp + (940));
    s4 = *(volatile u32 *)(unsigned long)(sp + (936));
    s3 = *(volatile u32 *)(unsigned long)(sp + (932));
    s2 = *(volatile u32 *)(unsigned long)(sp + (928));
    s1 = *(volatile u32 *)(unsigned long)(sp + (924));
    s0 = *(volatile u32 *)(unsigned long)(sp + (920));
    sp = sp + 960;
    return ((u64)v1 << 32) | v0;
}
