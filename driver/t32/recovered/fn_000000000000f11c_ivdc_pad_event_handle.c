/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_be370[] __asm__("t32_data_be370");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_c5c7c[] __asm__("t32_data_c5c7c");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_cf2e4[] __asm__("t32_data_cf2e4");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_t32_data_ce230[] __asm__("t32_data_ce230");
extern unsigned char ref_t32_data_d900c[] __asm__("t32_data_d900c");
extern unsigned char ref_t32_data_c5c98[] __asm__("t32_data_c5c98");
extern unsigned char ref_t32_data_d9010[] __asm__("t32_data_d9010");
extern unsigned char ref_t32_data_d9898[] __asm__("t32_data_d9898");
extern unsigned char ref_ivdc_enable_irq[] __asm__("ivdc_enable_irq");
extern unsigned char ref_t32_data_cf2dc[] __asm__("t32_data_cf2dc");
extern unsigned char ref_private_mutex_lock[] __asm__("private_mutex_lock");
extern unsigned char ref_private_mutex_unlock[] __asm__("private_mutex_unlock");
extern unsigned char ref_tx_isp_send_event_to_remote[] __asm__("tx_isp_send_event_to_remote");
extern unsigned char ref_ivdc_disable_irq[] __asm__("ivdc_disable_irq");
extern unsigned char ref_t32_data_cf2e0[] __asm__("t32_data_cf2e0");
extern unsigned char ref_t32_data_d98b4[] __asm__("t32_data_d98b4");
extern unsigned char ref_t32_data_d98b8[] __asm__("t32_data_d98b8");
extern unsigned char ref_t32_data_c5cd0[] __asm__("t32_data_c5cd0");
extern unsigned char ref_t32_data_c5ce8[] __asm__("t32_data_c5ce8");
extern unsigned char ref_t32_data_be424[] __asm__("t32_data_be424");
extern unsigned char ref_t32_data_c5d08[] __asm__("t32_data_c5d08");
extern unsigned char ref_t32_data_c5d30[] __asm__("t32_data_c5d30");
u64 ivdc_pad_event_handle(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_f140 = ((u32)(unsigned long)ref_t32_data_be370 + 0x8000U) & 0xffff0000U;
    const u32 hi_f1dc = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_f1fc = ((u32)(unsigned long)ref_t32_data_c5c7c + 0x8000U) & 0xffff0000U;
    const u32 hi_f1f8 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_f218 = ((u32)(unsigned long)ref_t32_data_cf2e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_f230 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_f254 = ((u32)(unsigned long)ref_t32_data_ce230 + 0x8000U) & 0xffff0000U;
    const u32 hi_f2ec = ((u32)(unsigned long)ref_t32_data_d900c + 0x8000U) & 0xffff0000U;
    const u32 hi_f37c = ((u32)(unsigned long)ref_t32_data_d900c + 0x8000U) & 0xffff0000U;
    const u32 hi_f408 = ((u32)(unsigned long)ref_t32_data_d900c + 0x8000U) & 0xffff0000U;
    const u32 hi_f494 = ((u32)(unsigned long)ref_t32_data_d900c + 0x8000U) & 0xffff0000U;
    const u32 hi_f548 = ((u32)(unsigned long)ref_t32_data_ce230 + 0x8000U) & 0xffff0000U;
    const u32 hi_f55c = ((u32)(unsigned long)ref_t32_data_c5c98 + 0x8000U) & 0xffff0000U;
    const u32 hi_f594 = ((u32)(unsigned long)ref_t32_data_d9010 + 0x8000U) & 0xffff0000U;
    const u32 hi_f5fc = ((u32)(unsigned long)ref_t32_data_d9898 + 0x8000U) & 0xffff0000U;
    const u32 hi_f60c = ((u32)(unsigned long)ref_ivdc_enable_irq + 0x8000U) & 0xffff0000U;
    const u32 hi_f61c = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_f634 = ((u32)(unsigned long)ref_t32_data_cf2dc + 0x8000U) & 0xffff0000U;
    const u32 hi_f664 = ((u32)(unsigned long)ref_private_mutex_lock + 0x8000U) & 0xffff0000U;
    const u32 hi_f680 = ((u32)(unsigned long)ref_private_mutex_unlock + 0x8000U) & 0xffff0000U;
    const u32 hi_f6c4 = ((u32)(unsigned long)ref_tx_isp_send_event_to_remote + 0x8000U) & 0xffff0000U;
    const u32 hi_f728 = ((u32)(unsigned long)ref_private_mutex_lock + 0x8000U) & 0xffff0000U;
    const u32 hi_f72c = ((u32)(unsigned long)ref_t32_data_d9898 + 0x8000U) & 0xffff0000U;
    const u32 hi_f748 = ((u32)(unsigned long)ref_private_mutex_unlock + 0x8000U) & 0xffff0000U;
    const u32 hi_f764 = ((u32)(unsigned long)ref_ivdc_disable_irq + 0x8000U) & 0xffff0000U;
    const u32 hi_f778 = ((u32)(unsigned long)ref_t32_data_cf2dc + 0x8000U) & 0xffff0000U;
    const u32 hi_f780 = ((u32)(unsigned long)ref_t32_data_cf2e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_f788 = ((u32)(unsigned long)ref_t32_data_cf2e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_f7ac = ((u32)(unsigned long)ref_tx_isp_send_event_to_remote + 0x8000U) & 0xffff0000U;
    const u32 hi_f7d0 = ((u32)(unsigned long)ref_t32_data_d98b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_f7dc = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_f8bc = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_f8d4 = ((u32)(unsigned long)ref_t32_data_d9010 + 0x8000U) & 0xffff0000U;
    const u32 hi_f924 = ((u32)(unsigned long)ref_t32_data_d98b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_f954 = ((u32)(unsigned long)ref_t32_data_d9010 + 0x8000U) & 0xffff0000U;
    const u32 hi_f960 = ((u32)(unsigned long)ref_t32_data_ce230 + 0x8000U) & 0xffff0000U;
    const u32 hi_f9a0 = ((u32)(unsigned long)ref_t32_data_d98b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_f9b0 = ((u32)(unsigned long)ref_t32_data_c5cd0 + 0x8000U) & 0xffff0000U;
    const u32 hi_f9cc = ((u32)(unsigned long)ref_t32_data_c5ce8 + 0x8000U) & 0xffff0000U;
    const u32 hi_f9d4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_f9f4 = ((u32)(unsigned long)ref_t32_data_be424 + 0x8000U) & 0xffff0000U;
    const u32 hi_f9f8 = ((u32)(unsigned long)ref_t32_data_c5d08 + 0x8000U) & 0xffff0000U;
    const u32 hi_f9fc = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_fa20 = ((u32)(unsigned long)ref_t32_data_c5d30 + 0x8000U) & 0xffff0000U;
    const u32 hi_fac0 = ((u32)(unsigned long)ref_t32_data_c5d30 + 0x8000U) & 0xffff0000U;
    const u32 hi_fac4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_fad8 = ((u32)(unsigned long)ref_t32_data_cf2e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_fbec = ((u32)(unsigned long)ref_tx_isp_send_event_to_remote + 0x8000U) & 0xffff0000U;
    const u32 hi_f5f0 = ((u32)(unsigned long)ref_t32_data_d9898 + 0x8000U) & 0xffff0000U;
    const u32 hi_f608 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_f7c0 = ((u32)(unsigned long)ref_t32_data_d98b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_f948 = ((u32)(unsigned long)ref_t32_data_c5ce8 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
    v0 = *(volatile u8 *)(unsigned long)(a0 + (5));
    branch = (v0 == 0); ;
    if (branch) goto L_fc54;
    goto L_f128;
L_f128:
    v0 = 0xfcffU << 16;
    v0 = v0 | 0xffff;
    a1 = a1 + v0;
    v0 = (u32)a1 < (u32)(8);
    branch = (v0 == 0); a1 = a1 << (0x2 & 31);
    if (branch) goto L_fc54;
    goto L_f140;
L_f140:
    v0 = hi_f140;
    v0 = v0 - hi_f140 + (u32)(unsigned long)ref_t32_data_be370;
    a1 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    sp = sp + -64;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s0;
    s4 = a2;
    callee = v0; s1 = a0;
    switch (callee) { case 0xf180: goto L_f180; case 0xf184: goto L_f184; case 0xf18c: goto L_f18c; case 0xf1a0: goto L_f1a0; case 0xf1a4: goto L_f1a4; case 0xf1bc: goto L_f1bc; case 0xf258: goto L_f258; case 0xf36c: goto L_f36c; case 0xf5c4: goto L_f5c4; case 0xf6ec: goto L_f6ec; case 0xf7b4: goto L_f7b4; case 0xf86c: goto L_f86c; case 0xf874: goto L_f874; case 0xf8a8: goto L_f8a8; case 0xfab4: goto L_fab4; case 0xfb98: goto L_fb98; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_f180:
    s1 = a0;
L_f184:
    branch = (a0 == 0); v0 = -1;
    if (branch) goto L_fc28;
    goto L_f18c;
L_f18c:
    v1 = (u32)a0 < (u32)(-4095);
    branch = (v1 == 0); a1 = 0;
    if (branch) goto L_fc08;
    goto L_f198;
L_f198:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0)); goto L_fc08;
L_f1a0:
    branch = (a0 == 0); v0 = -1;
    if (branch) goto L_fc28;
    goto L_f1a8;
L_f1a4:
    v0 = -1;
L_f1a8:
    v0 = (u32)a0 < (u32)(-4095);
    branch = (v0 == 0); s0 = 0;
    if (branch) goto L_f1d0;
    goto L_f1b4;
L_f1b4:
    s5 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (s5 == 0); v1 = (u32)s5 < (u32)(-4095);
    if (branch) goto L_f1d4;
    goto L_f1c0;
L_f1bc:
    v1 = (u32)s5 < (u32)(-4095);
L_f1c0:
    if (v1 != 0) { s0 = *(volatile u32 *)(unsigned long)(s5 + (280)); goto L_f1d4; }
    goto L_f1c8;
L_f1c8:
    ; goto L_f1d4;
L_f1d0:
    s5 = 0;
L_f1d4:
    branch = (v0 == 0); a2 = 116;
    if (branch) goto L_fc00;
    goto L_f1dc;
L_f1dc:
    v0 = hi_f1dc;
    a1 = s4;
    v0 = v0 - hi_f1dc + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s0 + 328;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f1f0;
L_f1f0:
    s3 = *(volatile u32 *)(unsigned long)(s4 + (4));
    s2 = *(volatile u32 *)(unsigned long)(s4 + (8));
    v1 = hi_f1f8;
    a1 = hi_f1fc;
    a3 = s2;
    a2 = s3;
    a1 = a1 - hi_f1fc + (u32)(unsigned long)ref_t32_data_c5c7c;
    s6 = v1 - hi_f1f8 + (u32)(unsigned long)ref_isp_printf;
    callee = s6; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f218;
L_f218:
    v0 = hi_f218;
    a1 = *(volatile u32 *)(unsigned long)(v0 - hi_f218 + (u32)(unsigned long)ref_t32_data_cf2e4);
    a3 = 1;
    v1 = s6;
    a0 = v0;
    branch = (a1 != a3); a2 = hi_f230;
    if (branch) goto L_f278;
    goto L_f234;
L_f234:
    v0 = *(volatile u32 *)(unsigned long)(a2 - hi_f230 + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (v0 != a1); a3 = *(volatile u32 *)(unsigned long)(s0 + (284));
    if (branch) goto L_f24c;
    goto L_f240;
L_f240:
    v0 = s3 + 63;
    v0 = v0 >> (0x6 & 31); goto L_f26c;
L_f24c:
    v0 = (s32)v0 < (s32)(2);
    branch = (v0 != 0); v0 = hi_f254;
    if (branch) goto L_f274;
    goto L_f258;
L_f258:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_f254 + (u32)(unsigned long)ref_t32_data_ce230);
    a1 = 64;
    v0 = v0 + 63;
    if (v0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)v0 / (s32)a1; hi = (s32)v0 % (s32)a1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
L_f26c:
    v0 = v0 << (0x6 & 31);
    *(volatile u32 *)(unsigned long)(a3 + (32)) = v0;
L_f274:
    *(volatile u32 *)(unsigned long)(a0 - hi_f218 + (u32)(unsigned long)ref_t32_data_cf2e4) = 0;
L_f278:
    v0 = *(volatile u8 *)(unsigned long)(s1 + (4));
    branch = (v0 != 0); a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    if (branch) goto L_f31c;
    goto L_f284;
L_f284:
    v0 = s2 & 0xfff;
    a1 = s3 & 0xfff;
    v0 = v0 << (0x10 & 31);
    v0 = v0 | a1;
    *(volatile u32 *)(unsigned long)(a0 + (16)) = v0;
    v0 = s2 >> (0x1 & 31);
    a0 = v0 & 0xfff;
    a1 = a0 << (0x10 & 31);
    a0 = s3 + 7;
    a0 = a0 & 0xff8;
    a0 = a1 | a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (20)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = 0x110U << 16;
    a0 = v0 | a0;
    *(volatile u32 *)(unsigned long)(a1 + (76)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (80)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = s2 << (0x10 & 31);
    a0 = a0 | s3;
    *(volatile u32 *)(unsigned long)(a1 + (448)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = 512;
    *(volatile u32 *)(unsigned long)(a0 + (208)) = a1;
    a0 = hi_f2ec;
    a0 = *(volatile u32 *)(unsigned long)(a0 - hi_f2ec + (u32)(unsigned long)ref_t32_data_d900c);
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a3 = a0;
    if (a0 == 0) a3 = v0;
    *(volatile u32 *)(unsigned long)(a1 + (164)) = a3;
    s2 = s2 - a0;
    if (a0 != 0) v0 = s2;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (168)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f4c0;
L_f31c:
    a1 = 1;
    branch = (v0 != a1); a1 = 2;
    if (branch) goto L_f3ac;
    goto L_f328;
L_f328:
    v0 = s2 & 0xfff;
    a1 = s3 & 0xfff;
    v0 = v0 << (0x10 & 31);
    v0 = v0 | a1;
    *(volatile u32 *)(unsigned long)(a0 + (1536)) = v0;
    v0 = s2 >> (0x1 & 31);
    a0 = v0 & 0xfff;
    a1 = a0 << (0x10 & 31);
    a0 = s3 + 7;
    a0 = a0 & 0xff8;
    a0 = a1 | a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (1540)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1556)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1560)) = v0;
L_f36c:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = s2 << (0x10 & 31);
    a0 = a0 | s3;
    *(volatile u32 *)(unsigned long)(a1 + (1580)) = a0;
    a0 = hi_f37c;
    a0 = *(volatile u32 *)(unsigned long)(a0 - hi_f37c + (u32)(unsigned long)ref_t32_data_d900c);
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a3 = a0;
    if (a0 == 0) a3 = v0;
    *(volatile u32 *)(unsigned long)(a1 + (1564)) = a3;
    s2 = s2 - a0;
    if (a0 != 0) v0 = s2;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1568)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f4c0;
L_f3ac:
    branch = (v0 != a1); a1 = 3;
    if (branch) goto L_f438;
    goto L_f3b4;
L_f3b4:
    v0 = s2 & 0xfff;
    a1 = s3 & 0xfff;
    v0 = v0 << (0x10 & 31);
    v0 = v0 | a1;
    *(volatile u32 *)(unsigned long)(a0 + (1600)) = v0;
    v0 = s2 >> (0x1 & 31);
    a0 = v0 & 0xfff;
    a1 = a0 << (0x10 & 31);
    a0 = s3 + 7;
    a0 = a0 & 0xff8;
    a0 = a1 | a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (1604)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1620)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1624)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = s2 << (0x10 & 31);
    a0 = a0 | s3;
    *(volatile u32 *)(unsigned long)(a1 + (1644)) = a0;
    a0 = hi_f408;
    a0 = *(volatile u32 *)(unsigned long)(a0 - hi_f408 + (u32)(unsigned long)ref_t32_data_d900c);
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a3 = a0;
    if (a0 == 0) a3 = v0;
    *(volatile u32 *)(unsigned long)(a1 + (1628)) = a3;
    s2 = s2 - a0;
    if (a0 != 0) v0 = s2;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1632)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f4c0;
L_f438:
    if (v0 != a1) { v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f4c0; }
    goto L_f440;
L_f440:
    v0 = s2 & 0xfff;
    a1 = s3 & 0xfff;
    v0 = v0 << (0x10 & 31);
    v0 = v0 | a1;
    *(volatile u32 *)(unsigned long)(a0 + (1664)) = v0;
    v0 = s2 >> (0x1 & 31);
    a0 = v0 & 0xfff;
    a1 = a0 << (0x10 & 31);
    a0 = s3 + 7;
    a0 = a0 & 0xff8;
    a0 = a1 | a0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a1 + (1668)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1684)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1688)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = s2 << (0x10 & 31);
    a0 = a0 | s3;
    *(volatile u32 *)(unsigned long)(a1 + (1708)) = a0;
    a0 = hi_f494;
    a0 = *(volatile u32 *)(unsigned long)(a0 - hi_f494 + (u32)(unsigned long)ref_t32_data_d900c);
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a3 = a0;
    if (a0 == 0) a3 = v0;
    *(volatile u32 *)(unsigned long)(a1 + (1692)) = a3;
    s2 = s2 - a0;
    if (a0 != 0) v0 = s2;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(a0 + (1696)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
L_f4c0:
    a0 = 0xe488;
    a1 = 1;
    *(volatile u32 *)(unsigned long)(v0 + (36)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v0 = 0x4U << 16;
    v0 = v0 + 4225;
    *(volatile u32 *)(unsigned long)(a0 + (88)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = 7;
    *(volatile u32 *)(unsigned long)(v0 + (100)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = 0x1U << 16;
    *(volatile u32 *)(unsigned long)(v0 + (132)) = a1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (104)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(a2 - hi_f230 + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (v0 != a1); a0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    if (branch) goto L_f51c;
    goto L_f508;
L_f508:
    v0 = 0x3010U << 16;
    v0 = v0 | 0xc703;
    *(volatile u32 *)(unsigned long)(a0 + (96)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f578;
L_f51c:
    v0 = (s32)v0 < (s32)(2);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f578; }
    goto L_f528;
L_f528:
    v0 = 0x3010U << 16;
    v0 = v0 | 0xf703;
    *(volatile u32 *)(unsigned long)(a0 + (96)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = 3;
    *(volatile u32 *)(unsigned long)(v0 + (100)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (104)) = 0;
    v0 = hi_f548;
    a2 = *(volatile u32 *)(unsigned long)(v0 - hi_f548 + (u32)(unsigned long)ref_t32_data_ce230);
    v0 = (u32)a2 < (u32)(s3);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (284)); goto L_f578; }
    goto L_f55c;
L_f55c:
    a1 = hi_f55c;
    a3 = s3;
    a1 = a1 - hi_f55c + (u32)(unsigned long)ref_t32_data_c5c98;
    callee = v1; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f570;
L_f570:
    v0 = -22; goto L_fc28;
L_f578:
    a1 = 0x300U << 16;
    v1 = 0x1000U << 16;
    *(volatile u32 *)(unsigned long)(v0 + (108)) = a1;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a2 = s4;
    a1 = a1 + 2;
    *(volatile u32 *)(unsigned long)(v0 + (60)) = v1;
    v0 = hi_f594;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_f594 + (u32)(unsigned long)ref_t32_data_d9010);
    v1 = 2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = 0x20U << 16;
    v0 = lo;
    v0 = v0 | v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v1 + (72)) = v0;
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(s5 + (276)); goto L_fbc0;
L_f5c4:
    branch = (a0 == 0); v0 = (u32)a0 < (u32)(-4095);
    if (branch) goto L_f5f4;
    goto L_f5cc;
L_f5cc:
    branch = (v0 == 0); s0 = 0;
    if (branch) goto L_f5f8;
    goto L_f5d4;
L_f5d4:
    s0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (s0 == 0); s2 = 0;
    if (branch) goto L_f5fc;
    goto L_f5e0;
L_f5e0:
    v0 = (u32)s0 < (u32)(-4095);
    if (v0 != 0) { s2 = *(volatile u32 *)(unsigned long)(s0 + (280)); goto L_f5fc; }
    goto L_f5ec;
L_f5ec:
    s3 = hi_f5f0; goto L_f600;
L_f5f4:
    s0 = 0;
L_f5f8:
    s2 = 0;
L_f5fc:
    s3 = hi_f5fc;
L_f600:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_f5fc + (u32)(unsigned long)ref_t32_data_d9898);
    branch = (v0 != 0); v0 = hi_f608;
    if (branch) goto L_f620;
    goto L_f60c;
L_f60c:
    v0 = hi_f60c;
    v0 = v0 - hi_f60c + (u32)(unsigned long)ref_ivdc_enable_irq;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f61c;
L_f61c:
    v0 = hi_f61c;
L_f620:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_f61c + (u32)(unsigned long)ref_t32_data_d9014);
    v0 = v0 + -1;
    v0 = (u32)v0 < (u32)(4);
    if (v0 == 0) { a0 = *(volatile u8 *)(unsigned long)(s1 + (4)); goto L_f6a8; }
    goto L_f634;
L_f634:
    v1 = hi_f634;
    a1 = *(volatile u32 *)(unsigned long)(v1 - hi_f634 + (u32)(unsigned long)ref_t32_data_cf2dc);
    a0 = 1;
    branch = (a1 != a0); v0 = *(volatile u32 *)(unsigned long)(s2 + (284));
    if (branch) goto L_f658;
    goto L_f648;
L_f648:
    a0 = 2;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = a0;
    *(volatile u32 *)(unsigned long)(v1 - hi_f634 + (u32)(unsigned long)ref_t32_data_cf2dc) = 0; goto L_f660;
L_f658:
    v1 = 34;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
L_f660:
    s4 = s2 + 456;
    v0 = hi_f664;
    v0 = v0 - hi_f664 + (u32)(unsigned long)ref_private_mutex_lock;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f674;
L_f674:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_f5fc + (u32)(unsigned long)ref_t32_data_d9898);
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s3 - hi_f5fc + (u32)(unsigned long)ref_t32_data_d9898) = v0;
    v0 = hi_f680;
    v0 = v0 - hi_f680 + (u32)(unsigned long)ref_private_mutex_unlock;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f690;
L_f690:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (284));
    v1 = 44;
    *(volatile u32 *)(unsigned long)(v0 + (236)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
L_f6a8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (276));
    a1 = 0x300U << 16;
    a2 = 0;
    a1 = a1 + 3;
L_f6b8:
    v1 = 36;
    a3 = a0 * v1;
    a0 = a3 + v0;
    v0 = hi_f6c4;
    v0 = v0 - hi_f6c4 + (u32)(unsigned long)ref_tx_isp_send_event_to_remote;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f6d4;
L_f6d4:
    branch = (v0 == 0); v1 = -515;
    if (branch) goto L_f86c;
    goto L_f6dc;
L_f6dc:
    branch = (v0 != v1); ra = *(volatile u32 *)(unsigned long)(sp + (60));
    if (branch) goto L_fc2c;
    goto L_f6e4;
L_f6e4:
    v0 = 0; goto L_fc2c;
L_f6ec:
    branch = (a0 == 0); v0 = (u32)a0 < (u32)(-4095);
    if (branch) goto L_f71c;
    goto L_f6f4;
L_f6f4:
    branch = (v0 == 0); s2 = 0;
    if (branch) goto L_f720;
    goto L_f6fc;
L_f6fc:
    s2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (s2 == 0); s0 = 0;
    if (branch) goto L_f724;
    goto L_f708;
L_f708:
    v0 = (u32)s2 < (u32)(-4095);
    if (v0 != 0) { s0 = *(volatile u32 *)(unsigned long)(s2 + (280)); goto L_f724; }
    goto L_f714;
L_f714:
    s4 = s0 + 456; goto L_f728;
L_f71c:
    s2 = 0;
L_f720:
    s0 = 0;
L_f724:
    s4 = s0 + 456;
L_f728:
    v0 = hi_f728;
    s3 = hi_f72c;
    v0 = v0 - hi_f728 + (u32)(unsigned long)ref_private_mutex_lock;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f73c;
L_f73c:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_f72c + (u32)(unsigned long)ref_t32_data_d9898);
    v0 = v0 + -1;
    *(volatile u32 *)(unsigned long)(s3 - hi_f72c + (u32)(unsigned long)ref_t32_data_d9898) = v0;
    v0 = hi_f748;
    v0 = v0 - hi_f748 + (u32)(unsigned long)ref_private_mutex_unlock;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f758;
L_f758:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_f72c + (u32)(unsigned long)ref_t32_data_d9898);
    if (v0 != 0) { a0 = *(volatile u8 *)(unsigned long)(s1 + (4)); goto L_f794; }
    goto L_f764;
L_f764:
    v0 = hi_f764;
    v0 = v0 - hi_f764 + (u32)(unsigned long)ref_ivdc_disable_irq;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f774;
L_f774:
    v0 = 1;
    v1 = hi_f778;
    *(volatile u32 *)(unsigned long)(v1 - hi_f778 + (u32)(unsigned long)ref_t32_data_cf2dc) = v0;
    v1 = hi_f780;
    *(volatile u32 *)(unsigned long)(v1 - hi_f780 + (u32)(unsigned long)ref_t32_data_cf2e0) = v0;
    v1 = hi_f788;
    *(volatile u32 *)(unsigned long)(v1 - hi_f788 + (u32)(unsigned long)ref_t32_data_cf2e4) = v0;
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
L_f794:
    v1 = 36;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (276));
    a3 = a0 * v1;
    a1 = 0x300U << 16;
    a2 = 0;
    a0 = a3 + v0;
    v0 = hi_f7ac;
    v0 = v0 - hi_f7ac + (u32)(unsigned long)ref_tx_isp_send_event_to_remote;
L_f7b4:
    callee = v0; a1 = a1 + 4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f7bc;
L_f7bc:
    if (v0 == 0) { v0 = hi_f7c0; goto L_f7d4; }
    goto L_f7c4;
L_f7c4:
    v1 = -515;
    branch = (v0 != v1); ra = *(volatile u32 *)(unsigned long)(sp + (60));
    if (branch) goto L_fc2c;
    goto L_f7d0;
L_f7d0:
    v0 = hi_f7d0;
L_f7d4:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_f7d0 + (u32)(unsigned long)ref_t32_data_d98b4);
    branch = (v0 == 0); v1 = hi_f7dc;
    if (branch) goto L_f86c;
    goto L_f7e0;
L_f7e0:
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_f7dc + (u32)(unsigned long)ref_t32_data_d9014);
    a0 = (s32)v0 < (s32)(2);
    branch = (a0 != 0); a0 = 0x3000U << 16;
    if (branch) goto L_f820;
    goto L_f7f0;
L_f7f0:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = a0 | 0xc703;
    *(volatile u32 *)(unsigned long)(a1 + (96)) = a0;
    a1 = 2;
    branch = (v0 == a1); a0 = 0x3c0U << 16;
    if (branch) goto L_f818;
    goto L_f808;
L_f808:
    v0 = v0 ^ 0x3;
    a1 = 0x7c0U << 16;
    a0 = 0x5c0U << 16;
    if (v0 != 0) a0 = a1;
L_f818:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (92)) = a0;
L_f820:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a0 = 3;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 - hi_f7dc + (u32)(unsigned long)ref_t32_data_d9014);
    v1 = (s32)v0 < (s32)(2);
    branch = (v1 != 0); v1 = 0x3010U << 16;
    if (branch) goto L_f86c;
    goto L_f83c;
L_f83c:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = v1 | 0xc703;
    *(volatile u32 *)(unsigned long)(a1 + (96)) = v1;
    v1 = 2;
    if (v0 == v1) { v0 = 0x3c4U << 16; goto L_f860; }
    goto L_f854;
L_f854:
    if (v0 == a0) { v0 = 0x5c4U << 16; goto L_f860; }
    goto L_f85c;
L_f85c:
    v0 = 0x7c4U << 16;
L_f860:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v0 = v0 + 4352;
    *(volatile u32 *)(unsigned long)(v1 + (92)) = v0;
L_f86c:
    v0 = 0; goto L_fc28;
L_f874:
    branch = (a0 == 0); v0 = 0;
    if (branch) goto L_f888;
    goto L_f87c;
L_f87c:
    v1 = (u32)a0 < (u32)(-4095);
    if (v1 != 0) { v0 = *(volatile u32 *)(unsigned long)(a0 + (0)); goto L_f888; }
    goto L_f888;
L_f888:
    v1 = 4096;
    *(volatile u32 *)(unsigned long)(s4 + (40)) = v1;
    a1 = 0x300U << 16;
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (276));
    a2 = s4;
    a1 = a1 + 5; goto L_fbc0;
L_f8a8:
    branch = (a0 == 0); s5 = 0;
    if (branch) goto L_f8bc;
    goto L_f8b0;
L_f8b0:
    v0 = (u32)a0 < (u32)(-4095);
    if (v0 != 0) { s5 = *(volatile u32 *)(unsigned long)(a0 + (0)); goto L_f8bc; }
    goto L_f8bc;
L_f8bc:
    s2 = hi_f8bc;
    v0 = *(volatile u32 *)(unsigned long)(s2 - hi_f8bc + (u32)(unsigned long)ref_t32_data_d9014);
    v1 = 1;
    branch = (v0 != v1); s0 = *(volatile u32 *)(unsigned long)(s1 + (32));
    if (branch) goto L_f94c;
    goto L_f8d0;
L_f8d0:
    s3 = *(volatile u32 *)(unsigned long)(s0 + (332));
    s6 = hi_f8d4;
    v1 = *(volatile u32 *)(unsigned long)(s6 - hi_f8d4 + (u32)(unsigned long)ref_t32_data_d9010);
    s3 = s3 + 63;
    s3 = s3 >> (0x6 & 31);
    branch = (v1 != 0); s3 = s3 << (0x6 & 31);
    if (branch) goto L_f910;
    goto L_f8ec;
L_f8ec:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (336));
    v0 = v1 << (0x1 & 31);
    v0 = v0 + v1;
    v0 = v0 * s3;
    v1 = v1 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(s6 - hi_f8d4 + (u32)(unsigned long)ref_t32_data_d9010) = v1;
    v0 = v0 >> (0x2 & 31);
    *(volatile u32 *)(unsigned long)(s0 + (504)) = v0; goto L_f924;
L_f910:
    v0 = v1 << (0x1 & 31);
    v0 = v0 + v1;
    v0 = v0 * s3;
    v0 = v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(s0 + (504)) = v0;
L_f924:
    v0 = hi_f924;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_f924 + (u32)(unsigned long)ref_t32_data_d98b8);
    branch = (v0 == 0); v1 = 0x8000U << 16;
    if (branch) goto L_f9b0;
    goto L_f934;
L_f934:
    *(volatile u32 *)(unsigned long)(s0 + (500)) = v0;
    v0 = v0 + v1;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(s0 + (496)) = v0;
    if (branch) goto L_f9ec;
    goto L_f944;
L_f944:
    a1 = hi_f948; goto L_f9d0;
L_f94c:
    v0 = (s32)v0 < (s32)(2);
    branch = (v0 != 0); s6 = hi_f954;
    if (branch) goto L_fb64;
    goto L_f958;
L_f958:
    a1 = *(volatile u32 *)(unsigned long)(s6 - hi_f954 + (u32)(unsigned long)ref_t32_data_d9010);
    branch = (a1 != 0); s3 = hi_f960;
    if (branch) goto L_fa8c;
    goto L_f964;
L_f964:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_f960 + (u32)(unsigned long)ref_t32_data_ce230);
    v1 = 64;
    v0 = v0 + 63;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = 192;
    v0 = lo;
    v0 = v0 * v1;
    v1 = 2160;
    v0 = v0 * v1;
    v1 = 4;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (504)) = v0;
    v0 = 1080;
    *(volatile u32 *)(unsigned long)(s6 - hi_f954 + (u32)(unsigned long)ref_t32_data_d9010) = v0;
L_f9a0:
    v0 = hi_f9a0;
    a2 = *(volatile u32 *)(unsigned long)(v0 - hi_f9a0 + (u32)(unsigned long)ref_t32_data_d98b8);
    if (a2 != 0) { v0 = 0x8000U << 16; goto L_f9bc; }
    goto L_f9b0;
L_f9b0:
    a1 = hi_f9b0;
    a1 = a1 - hi_f9b0 + (u32)(unsigned long)ref_t32_data_c5cd0; goto L_f9d4;
L_f9bc:
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(s0 + (500)) = a2;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(s0 + (496)) = v0;
    if (branch) goto L_fac0;
    goto L_f9cc;
L_f9cc:
    a1 = hi_f9cc;
L_f9d0:
    a1 = a1 - hi_f9cc + (u32)(unsigned long)ref_t32_data_c5ce8;
L_f9d4:
    v0 = hi_f9d4;
    v0 = v0 - hi_f9d4 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_f9e4;
L_f9e4:
    v0 = -12; goto L_fc28;
L_f9ec:
    v0 = *(volatile u32 *)(unsigned long)(s6 - hi_f954 + (u32)(unsigned long)ref_t32_data_d9010);
    a3 = *(volatile u8 *)(unsigned long)(s1 + (4));
    a2 = hi_f9f4;
    a1 = hi_f9f8;
    s7 = hi_f9fc;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    a2 = a2 - hi_f9f4 + (u32)(unsigned long)ref_t32_data_be424;
    a1 = a1 - hi_f9f8 + (u32)(unsigned long)ref_t32_data_c5d08;
    a0 = 1;
    s7 = s7 - hi_f9fc + (u32)(unsigned long)ref_isp_printf;
    callee = s7; *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_fa1c;
L_fa1c:
    a2 = *(volatile u32 *)(unsigned long)(s0 + (500));
    a1 = hi_fa20;
    a1 = a1 - hi_fa20 + (u32)(unsigned long)ref_t32_data_c5d30;
    callee = s7; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_fa30;
L_fa30:
    a0 = *(volatile u32 *)(unsigned long)(s6 - hi_f954 + (u32)(unsigned long)ref_t32_data_d9010);
    v0 = 2;
    a1 = 3840;
    if (a0 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a0 / (s32)v0; hi = (s32)a0 % (s32)v0; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = (u32)a0 < (u32)(3841);
    if (v1 == 0) a0 = a1;
    v0 = lo;
    v1 = (u32)v0 < (u32)(3841);
    if (v1 == 0) v0 = a1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v0 = v0 << (0x10 & 31);
    v0 = v0 | a0;
    *(volatile u32 *)(unsigned long)(v1 + (48)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (500));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (52)) = v1;
    v1 = s3 * a0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (500));
    s3 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (56)) = s3;
    v0 = *(volatile u32 *)(unsigned long)(s2 - hi_f8bc + (u32)(unsigned long)ref_t32_data_d9014); goto L_fb68;
L_fa8c:
    v1 = *(volatile u32 *)(unsigned long)(s3 - hi_f960 + (u32)(unsigned long)ref_t32_data_ce230);
    a0 = 64;
    v0 = 192;
    v1 = v1 + 63;
    if (v1 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v1 / (s32)a0; hi = (s32)v1 % (s32)a0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = lo;
    v1 = v1 * v0;
    v0 = v1 * a1;
    v1 = 2;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
L_fab4:
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s0 + (504)) = v0; goto L_f9a0;
L_fac0:
    a1 = hi_fac0;
    v0 = hi_fac4;
    a1 = a1 - hi_fac0 + (u32)(unsigned long)ref_t32_data_c5d30;
    v0 = v0 - hi_fac4 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_fad8;
L_fad8:
    a2 = hi_fad8;
    v1 = *(volatile u32 *)(unsigned long)(a2 - hi_fad8 + (u32)(unsigned long)ref_t32_data_cf2e0);
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s2 - hi_f8bc + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_fb68;
    goto L_faec;
L_faec:
    a0 = *(volatile u32 *)(unsigned long)(s6 - hi_f954 + (u32)(unsigned long)ref_t32_data_d9010);
    v0 = 3840;
    v1 = v0;
    a1 = (u32)a0 < (u32)(3841);
    if (a1 != 0) v1 = a0;
    a1 = v1;
    v1 = 2;
    if (a0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a0 / (s32)v1; hi = (s32)a0 % (s32)v1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    *(volatile u32 *)(unsigned long)(a2 - hi_fad8 + (u32)(unsigned long)ref_t32_data_cf2e0) = 0;
    v1 = lo;
    a0 = (u32)v1 < (u32)(3841);
    if (a0 == 0) v1 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    v1 = v1 << (0x10 & 31);
    v1 = v1 | a1;
    *(volatile u32 *)(unsigned long)(v0 + (48)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (500));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    a1 = a1 << (0x6 & 31);
    *(volatile u32 *)(unsigned long)(v0 + (52)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_f960 + (u32)(unsigned long)ref_t32_data_ce230);
    v1 = 64;
    v0 = v0 + 63;
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v1 = *(volatile u32 *)(unsigned long)(s0 + (500));
    v0 = lo;
    a0 = v0 * a1;
    v0 = a0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v1 + (56)) = v0;
L_fb64:
    v0 = *(volatile u32 *)(unsigned long)(s2 - hi_f8bc + (u32)(unsigned long)ref_t32_data_d9014);
L_fb68:
    if (v0 == 0) { a1 = 0x300U << 16; goto L_fb84; }
    goto L_fb70;
L_fb70:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (40)) = 0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (284));
    *(volatile u32 *)(unsigned long)(v0 + (44)) = 0;
    a1 = 0x300U << 16;
L_fb84:
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(s5 + (276));
    a2 = s4;
    a1 = a1 + 7; goto L_fbc0;
L_fb98:
    branch = (a0 == 0); v0 = 0;
    if (branch) goto L_fbac;
    goto L_fba0;
L_fba0:
    v1 = (u32)a0 < (u32)(-4095);
    if (v1 != 0) { v0 = *(volatile u32 *)(unsigned long)(a0 + (0)); goto L_fbac; }
    goto L_fbac;
L_fbac:
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (276));
    a1 = 0x300U << 16;
    a2 = 0;
    a1 = a1 + 8;
L_fbc0:
    v1 = 36;
    a3 = a0 * v1;
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s7 = *(volatile u32 *)(unsigned long)(sp + (56));
    s6 = *(volatile u32 *)(unsigned long)(sp + (52));
    s5 = *(volatile u32 *)(unsigned long)(sp + (48));
    s4 = *(volatile u32 *)(unsigned long)(sp + (44));
    s3 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (36));
    s1 = *(volatile u32 *)(unsigned long)(sp + (32));
    s0 = *(volatile u32 *)(unsigned long)(sp + (28));
    t9 = hi_fbec;
    t9 = t9 - hi_fbec + (u32)(unsigned long)ref_tx_isp_send_event_to_remote;
    sp = sp + 64;
    callee = t9; a0 = a3 + v0;
    switch (callee) { case 0xf180: goto L_f180; case 0xf184: goto L_f184; case 0xf18c: goto L_f18c; case 0xf1a0: goto L_f1a0; case 0xf1a4: goto L_f1a4; case 0xf1bc: goto L_f1bc; case 0xf258: goto L_f258; case 0xf36c: goto L_f36c; case 0xf5c4: goto L_f5c4; case 0xf6ec: goto L_f6ec; case 0xf7b4: goto L_f7b4; case 0xf86c: goto L_f86c; case 0xf874: goto L_f874; case 0xf8a8: goto L_f8a8; case 0xfab4: goto L_fab4; case 0xfb98: goto L_fb98; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_fc00:
    v0 = -1; goto L_fc28;
L_fc08:
    branch = (v1 == 0); v0 = -1;
    if (branch) goto L_fc28;
    goto L_fc10;
L_fc10:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (276));
    a1 = 0x300U << 16;
    a0 = *(volatile u8 *)(unsigned long)(s1 + (4));
    a2 = s4;
    a1 = a1 + 1; goto L_f6b8;
L_fc28:
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
L_fc2c:
    s7 = *(volatile u32 *)(unsigned long)(sp + (56));
    s6 = *(volatile u32 *)(unsigned long)(sp + (52));
    s5 = *(volatile u32 *)(unsigned long)(sp + (48));
    s4 = *(volatile u32 *)(unsigned long)(sp + (44));
    s3 = *(volatile u32 *)(unsigned long)(sp + (40));
    s2 = *(volatile u32 *)(unsigned long)(sp + (36));
    s1 = *(volatile u32 *)(unsigned long)(sp + (32));
    s0 = *(volatile u32 *)(unsigned long)(sp + (28));
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
L_fc54:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
