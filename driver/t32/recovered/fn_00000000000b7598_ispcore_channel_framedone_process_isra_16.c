/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_tisp_msca_addr_fifo_read[] __asm__("tisp_msca_addr_fifo_read");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_tisp_get_fps[] __asm__("tisp_get_fps");
extern unsigned char ref_lib_tisp_api_get_csccr_output[] __asm__("lib_tisp_api_get_csccr_output");
extern unsigned char ref_tisp_csc_get_full_range[] __asm__("tisp_csc_get_full_range");
extern unsigned char ref_tisp_msca_addr_fifo_write[] __asm__("tisp_msca_addr_fifo_write");
extern unsigned char ref_t32_data_f3348[] __asm__("t32_data_f3348");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tx_isp_send_event_to_remote[] __asm__("tx_isp_send_event_to_remote");
extern unsigned char ref_t32_data_c34b8[] __asm__("t32_data_c34b8");
extern unsigned char ref_t32_data_ccd80[] __asm__("t32_data_ccd80");
extern unsigned char ref_printk[] __asm__("printk");
u64 ispcore_channel_framedone_process_isra_16(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[86] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b75e4 = ((u32)(unsigned long)ref_tisp_msca_addr_fifo_read + 0x8000U) & 0xffff0000U;
    const u32 hi_b7630 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_b77b4 = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_b77c8 = ((u32)(unsigned long)ref_lib_tisp_api_get_csccr_output + 0x8000U) & 0xffff0000U;
    const u32 hi_b77dc = ((u32)(unsigned long)ref_tisp_csc_get_full_range + 0x8000U) & 0xffff0000U;
    const u32 hi_b77f4 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_b7814 = ((u32)(unsigned long)ref_tisp_msca_addr_fifo_write + 0x8000U) & 0xffff0000U;
    const u32 hi_b782c = ((u32)(unsigned long)ref_t32_data_f3348 + 0x8000U) & 0xffff0000U;
    const u32 hi_b7850 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b7868 = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_b787c = ((u32)(unsigned long)ref_lib_tisp_api_get_csccr_output + 0x8000U) & 0xffff0000U;
    const u32 hi_b7890 = ((u32)(unsigned long)ref_tisp_csc_get_full_range + 0x8000U) & 0xffff0000U;
    const u32 hi_b78e0 = ((u32)(unsigned long)ref_tx_isp_send_event_to_remote + 0x8000U) & 0xffff0000U;
    const u32 hi_b7848 = ((u32)(unsigned long)ref_t32_data_c34b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b78f8 = ((u32)(unsigned long)ref_t32_data_ccd80 + 0x8000U) & 0xffff0000U;
    const u32 hi_b78fc = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b7738 = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_b775c = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_b777c = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_b778c = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    const u32 hi_b779c = ((u32)(unsigned long)ref_tisp_get_fps + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[22];
    sp = sp + -88;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s0;
    s0 = a1 << (0x1 & 31);
    s0 = s0 + a1;
    v0 = s0 + a2;
    v1 = v0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (80)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (84)) = ra;
    v1 = a0 + v1;
    s1 = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (848));
    s0 = 284;
    t0 = a2;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (848)) = a0;
    a0 = v0 * s0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (1132));
    s2 = a1 & 0xff;
    v0 = hi_b75e4;
    a3 = sp + 28;
    v0 = v0 - hi_b75e4 + (u32)(unsigned long)ref_tisp_msca_addr_fifo_read;
    a2 = sp + 24;
    a1 = t0 & 0xff;
    s0 = a0 + v1;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b7604;
L_b7604:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (1196));
    a3 = 1;
    branch = (v0 == a3); v1 = s0 + 220;
    if (branch) goto L_b77f4;
    goto L_b7614;
L_b7614:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (220));
    branch = (v0 == v1); ra = *(volatile u32 *)(unsigned long)(sp + (84));
    if (branch) goto L_b791c;
    goto L_b7620;
L_b7620:
    branch = (v0 == 0); v1 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_b791c;
    goto L_b7628;
L_b7628:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    branch = (a0 != v1); a2 = hi_b7630;
    if (branch) goto L_b7720;
    goto L_b7634;
L_b7634:
    v1 = *(volatile u32 *)(unsigned long)(a2 - hi_b7630 + (u32)(unsigned long)ref_t32_data_d9014);
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    branch = (v1 != a3); a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    if (branch) goto L_b7658;
    goto L_b7644;
L_b7644:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (116));
    branch = (v1 == 0); v1 = 256;
    if (branch) goto L_b76d0;
    goto L_b7650;
L_b7650:
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0; goto L_b76f8;
L_b7658:
    a3 = 2;
    branch = (v1 != a3); a3 = 3;
    if (branch) goto L_b7684;
    goto L_b7664;
L_b7664:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (116));
    if (v1 == 0) { v1 = 256; goto L_b76d0; }
    goto L_b7670;
L_b7670:
    a3 = 3;
    branch = (v1 != a3); v1 = 256;
    if (branch) goto L_b76f4;
    goto L_b767c;
L_b767c:
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0; goto L_b76d4;
L_b7684:
    branch = (v1 != a3); a3 = 4;
    if (branch) goto L_b76a4;
    goto L_b768c;
L_b768c:
    a3 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v1 = (u32)a3 < (u32)(7);
    if (v1 == 0) { v1 = 256; goto L_b76f4; }
    goto L_b769c;
L_b769c:
    v1 = 73; goto L_b76c0;
L_b76a4:
    branch = (v1 != a3); v1 = 256;
    if (branch) goto L_b76f4;
    goto L_b76ac;
L_b76ac:
    a3 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v1 = (u32)a3 < (u32)(10);
    branch = (v1 == 0); v1 = 256;
    if (branch) goto L_b76f4;
    goto L_b76bc;
L_b76bc:
    v1 = 585;
L_b76c0:
    v1 = v1 >> (a3 & 31);
    v1 = v1 & 0x1;
    branch = (v1 == 0); v1 = 256;
    if (branch) goto L_b76f4;
    goto L_b76d0;
L_b76d0:
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0;
L_b76d4:
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v1 = 512;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (216));
    a0 = s0 + 212;
    *(volatile u32 *)(unsigned long)(s0 + (216)) = v0; goto L_b7714;
L_b76f4:
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0;
L_b76f8:
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v1 = 512;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (232));
    a0 = s0 + 228;
    *(volatile u32 *)(unsigned long)(s0 + (232)) = v0;
L_b7714:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
L_b7720:
    v0 = *(volatile u32 *)(unsigned long)(a2 - hi_b7630 + (u32)(unsigned long)ref_t32_data_d9014);
    v1 = 1;
    if (v0 != v1) { v1 = 2; goto L_b7744; }
    goto L_b7730;
L_b7730:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    branch = (v0 != 0); v0 = hi_b7738;
    if (branch) goto L_b77b8;
    goto L_b773c;
L_b773c:
    ra = *(volatile u32 *)(unsigned long)(sp + (84)); goto L_b791c;
L_b7744:
    branch = (v0 != v1); v1 = 3;
    if (branch) goto L_b7768;
    goto L_b774c;
L_b774c:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    branch = (v0 == 0); ra = *(volatile u32 *)(unsigned long)(sp + (84));
    if (branch) goto L_b791c;
    goto L_b7758;
L_b7758:
    branch = (v0 != v1); v0 = hi_b775c;
    if (branch) goto L_b77b8;
    goto L_b7760;
L_b7760:
    s2 = *(volatile u32 *)(unsigned long)(sp + (80)); goto L_b7920;
L_b7768:
    branch = (v0 != v1); v1 = 4;
    if (branch) goto L_b7788;
    goto L_b7770;
L_b7770:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v0 = (u32)v1 < (u32)(7);
    if (v0 == 0) { v0 = hi_b777c; goto L_b77b8; }
    goto L_b7780;
L_b7780:
    v0 = 73; goto L_b77a4;
L_b7788:
    branch = (v0 != v1); v0 = hi_b778c;
    if (branch) goto L_b77b8;
    goto L_b7790;
L_b7790:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v0 = (u32)v1 < (u32)(10);
    branch = (v0 == 0); v0 = hi_b779c;
    if (branch) goto L_b77b8;
    goto L_b77a0;
L_b77a0:
    v0 = 585;
L_b77a4:
    v0 = v0 >> (v1 & 31);
    v0 = v0 & 0x1;
    branch = (v0 != 0); ra = *(volatile u32 *)(unsigned long)(sp + (84));
    if (branch) goto L_b791c;
    goto L_b77b4;
L_b77b4:
    v0 = hi_b77b4;
L_b77b8:
    a1 = sp + 40;
    v0 = v0 - hi_b77b4 + (u32)(unsigned long)ref_tisp_get_fps;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b77c8;
L_b77c8:
    v0 = hi_b77c8;
    v0 = v0 - hi_b77c8 + (u32)(unsigned long)ref_lib_tisp_api_get_csccr_output;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b77d8;
L_b77d8:
    *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    v0 = hi_b77dc;
    v0 = v0 - hi_b77dc + (u32)(unsigned long)ref_tisp_csc_get_full_range;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b77ec;
L_b77ec:
    *(volatile u32 *)(unsigned long)(sp + (64)) = v0; goto L_b78dc;
L_b77f4:
    v1 = hi_b77f4;
    v1 = *(volatile u32 *)(unsigned long)(v1 - hi_b77f4 + (u32)(unsigned long)ref_t32_data_d9014);
    if (v1 != v0) { s1 = *(volatile u32 *)(unsigned long)(s0 + (220)); goto L_b7840; }
    goto L_b7804;
L_b7804:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    if (v0 != 0) { s1 = *(volatile u32 *)(unsigned long)(s0 + (220)); goto L_b7840; }
    goto L_b7810;
L_b7810:
    a1 = *(volatile u8 *)(unsigned long)(s0 + (120));
    v0 = hi_b7814;
    v0 = v0 - hi_b7814 + (u32)(unsigned long)ref_tisp_msca_addr_fifo_write;
    a3 = 0x8100U << 16;
    a2 = 0x8000U << 16;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b782c;
L_b782c:
    v1 = hi_b782c;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_b782c + (u32)(unsigned long)ref_t32_data_f3348);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 - hi_b782c + (u32)(unsigned long)ref_t32_data_f3348) = v0; goto L_b7918;
L_b7840:
    v0 = s0 + 220;
    branch = (s1 == v0); a1 = hi_b7848;
    if (branch) goto L_b78f8;
    goto L_b784c;
L_b784c:
    branch = (s1 == 0); v0 = hi_b7850;
    if (branch) goto L_b78f8;
    goto L_b7854;
L_b7854:
    a2 = 52;
    a1 = s1;
    v0 = v0 - hi_b7850 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b7868;
L_b7868:
    v0 = hi_b7868;
    a1 = sp + 40;
    v0 = v0 - hi_b7868 + (u32)(unsigned long)ref_tisp_get_fps;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b787c;
L_b787c:
    v0 = hi_b787c;
    v0 = v0 - hi_b787c + (u32)(unsigned long)ref_lib_tisp_api_get_csccr_output;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b788c;
L_b788c:
    *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    v0 = hi_b7890;
    v0 = v0 - hi_b7890 + (u32)(unsigned long)ref_tisp_csc_get_full_range;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b78a0;
L_b78a0:
    *(volatile u32 *)(unsigned long)(sp + (64)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    v1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = 256;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
    v0 = 512;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (232));
    v1 = s0 + 228;
    *(volatile u32 *)(unsigned long)(s0 + (232)) = s1;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = s1;
L_b78dc:
    a1 = 0x300U << 16;
    v0 = hi_b78e0;
    a2 = sp + 16;
    a1 = a1 + 6;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (132));
    v0 = v0 - hi_b78e0 + (u32)(unsigned long)ref_tx_isp_send_event_to_remote; goto L_b7910;
L_b78f8:
    a0 = hi_b78f8;
    v0 = hi_b78fc;
    a2 = 869;
    a1 = a1 - hi_b7848 + (u32)(unsigned long)ref_t32_data_c34b8;
    a0 = a0 - hi_b78f8 + (u32)(unsigned long)ref_t32_data_ccd80;
    v0 = v0 - hi_b78fc + ((u32)(unsigned long)ref_printk + (0));
L_b7910:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b7918;
L_b7918:
    ra = *(volatile u32 *)(unsigned long)(sp + (84));
L_b791c:
    s2 = *(volatile u32 *)(unsigned long)(sp + (80));
L_b7920:
    s1 = *(volatile u32 *)(unsigned long)(sp + (76));
    s0 = *(volatile u32 *)(unsigned long)(sp + (72));
    v0 = 0;
    sp = sp + 88;
    return ((u64)v1 << 32) | v0;
}
