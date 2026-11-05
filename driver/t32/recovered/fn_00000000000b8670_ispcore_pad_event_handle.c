/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c312c[] __asm__("t32_data_c312c");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_c3370[] __asm__("t32_data_c3370");
extern unsigned char ref_t32_data_ccdf8[] __asm__("t32_data_ccdf8");
extern unsigned char ref_t32_data_cce1c[] __asm__("t32_data_cce1c");
extern unsigned char ref_t32_data_cce64[] __asm__("t32_data_cce64");
extern unsigned char ref_t32_data_ccebc[] __asm__("t32_data_ccebc");
extern unsigned char ref_t32_data_d8ce0[] __asm__("t32_data_d8ce0");
extern unsigned char ref_t32_data_c3354[] __asm__("t32_data_c3354");
extern unsigned char ref_t32_data_ccfa4[] __asm__("t32_data_ccfa4");
extern unsigned char ref_private_init_completion[] __asm__("private_init_completion");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_lib_tisp_msca_channel_attr_set[] __asm__("lib_tisp_msca_channel_attr_set");
extern unsigned char ref___private_spin_lock_irqsave[] __asm__("__private_spin_lock_irqsave");
extern unsigned char ref_private_spin_unlock_irqrestore[] __asm__("private_spin_unlock_irqrestore");
extern unsigned char ref_tisp_msca_channel_start[] __asm__("tisp_msca_channel_start");
extern unsigned char ref_lib_tisp_msca_chx_stream_on[] __asm__("lib_tisp_msca_chx_stream_on");
extern unsigned char ref_lib_tisp_api_set_msca_dma_stride[] __asm__("lib_tisp_api_set_msca_dma_stride");
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
extern unsigned char ref___ispcore_get_frame_drop[] __asm__("__ispcore_get_frame_drop");
extern unsigned char ref_tisp_msca_chx_en[] __asm__("tisp_msca_chx_en");
extern unsigned char ref_tisp_msca_addr_fifo_write[] __asm__("tisp_msca_addr_fifo_write");
extern unsigned char ref_t32_data_f3354[] __asm__("t32_data_f3354");
extern unsigned char ref_lib_tisp_stream_on[] __asm__("lib_tisp_stream_on");
extern unsigned char ref_t32_data_ccf18[] __asm__("t32_data_ccf18");
extern unsigned char ref_ispcore_frame_channel_streamoff[] __asm__("ispcore_frame_channel_streamoff");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_t32_data_c3338[] __asm__("t32_data_c3338");
extern unsigned char ref_t32_data_ccf38[] __asm__("t32_data_ccf38");
extern unsigned char ref_t32_data_ccf64[] __asm__("t32_data_ccf64");
extern unsigned char ref_t32_data_f3774[] __asm__("t32_data_f3774");
extern unsigned char ref_t32_data_f3340[] __asm__("t32_data_f3340");
extern unsigned char ref_t32_data_f3750[] __asm__("t32_data_f3750");
extern unsigned char ref_t32_data_f3808[] __asm__("t32_data_f3808");
extern unsigned char ref_t32_data_f3810[] __asm__("t32_data_f3810");
extern unsigned char ref_t32_data_f3778[] __asm__("t32_data_f3778");
extern unsigned char ref_t32_data_f333c[] __asm__("t32_data_f333c");
extern unsigned char ref_t32_data_f374c[] __asm__("t32_data_f374c");
extern unsigned char ref_t32_data_f3804[] __asm__("t32_data_f3804");
extern unsigned char ref_t32_data_f380c[] __asm__("t32_data_f380c");
extern unsigned char ref_t32_data_ccf7c[] __asm__("t32_data_ccf7c");
extern unsigned char ref_private_kmalloc[] __asm__("private_kmalloc");
extern unsigned char ref_private_kfree[] __asm__("private_kfree");
u64 ispcore_pad_event_handle(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[100] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b8694 = ((u32)(unsigned long)ref_t32_data_c312c + 0x8000U) & 0xffff0000U;
    const u32 hi_b8700 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b878c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b877c = ((u32)(unsigned long)ref_t32_data_c3370 + 0x8000U) & 0xffff0000U;
    const u32 hi_b87bc = ((u32)(unsigned long)ref_t32_data_ccdf8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b87e0 = ((u32)(unsigned long)ref_t32_data_cce1c + 0x8000U) & 0xffff0000U;
    const u32 hi_b8800 = ((u32)(unsigned long)ref_t32_data_cce64 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8830 = ((u32)(unsigned long)ref_t32_data_ccebc + 0x8000U) & 0xffff0000U;
    const u32 hi_b8858 = ((u32)(unsigned long)ref_t32_data_d8ce0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8888 = ((u32)(unsigned long)ref_t32_data_c3354 + 0x8000U) & 0xffff0000U;
    const u32 hi_b888c = ((u32)(unsigned long)ref_t32_data_ccfa4 + 0x8000U) & 0xffff0000U;
    const u32 hi_b88a8 = ((u32)(unsigned long)ref_private_init_completion + 0x8000U) & 0xffff0000U;
    const u32 hi_b88b8 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b8988 = ((u32)(unsigned long)ref_lib_tisp_msca_channel_attr_set + 0x8000U) & 0xffff0000U;
    const u32 hi_b8998 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b89e8 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_b8a00 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_b8a20 = ((u32)(unsigned long)ref_tisp_msca_channel_start + 0x8000U) & 0xffff0000U;
    const u32 hi_b8a24 = ((u32)(unsigned long)ref_lib_tisp_msca_chx_stream_on + 0x8000U) & 0xffff0000U;
    const u32 hi_b8a28 = ((u32)(unsigned long)ref_lib_tisp_api_set_msca_dma_stride + 0x8000U) & 0xffff0000U;
    const u32 hi_b8abc = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8ad8 = ((u32)(unsigned long)ref___ispcore_get_frame_drop + 0x8000U) & 0xffff0000U;
    const u32 hi_b8aec = ((u32)(unsigned long)ref_tisp_msca_chx_en + 0x8000U) & 0xffff0000U;
    const u32 hi_b8b10 = ((u32)(unsigned long)ref_tisp_msca_addr_fifo_write + 0x8000U) & 0xffff0000U;
    const u32 hi_b8b98 = ((u32)(unsigned long)ref_t32_data_f3354 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8ba0 = ((u32)(unsigned long)ref_lib_tisp_stream_on + 0x8000U) & 0xffff0000U;
    const u32 hi_b8bbc = ((u32)(unsigned long)ref_t32_data_ccf18 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8bc0 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b8c34 = ((u32)(unsigned long)ref_ispcore_frame_channel_streamoff + 0x8000U) & 0xffff0000U;
    const u32 hi_b8c90 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_b8cd0 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8ce8 = ((u32)(unsigned long)ref_t32_data_c3338 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8cec = ((u32)(unsigned long)ref_t32_data_ccf38 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8cf0 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b8d50 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_b8ed4 = ((u32)(unsigned long)ref_t32_data_c3338 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8f3c = ((u32)(unsigned long)ref_t32_data_ccf64 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8f40 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b8f68 = ((u32)(unsigned long)ref_tisp_msca_chx_en + 0x8000U) & 0xffff0000U;
    const u32 hi_b8f84 = ((u32)(unsigned long)ref_tisp_msca_addr_fifo_write + 0x8000U) & 0xffff0000U;
    const u32 hi_b9014 = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_b9038 = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_b9064 = ((u32)(unsigned long)ref_t32_data_f3774 + 0x8000U) & 0xffff0000U;
    const u32 hi_b9068 = ((u32)(unsigned long)ref_t32_data_f3340 + 0x8000U) & 0xffff0000U;
    const u32 hi_b9090 = ((u32)(unsigned long)ref_t32_data_f3750 + 0x8000U) & 0xffff0000U;
    const u32 hi_b90a8 = ((u32)(unsigned long)ref_t32_data_f3808 + 0x8000U) & 0xffff0000U;
    const u32 hi_b90b8 = ((u32)(unsigned long)ref_t32_data_f3810 + 0x8000U) & 0xffff0000U;
    const u32 hi_b90c4 = ((u32)(unsigned long)ref_tisp_msca_addr_fifo_write + 0x8000U) & 0xffff0000U;
    const u32 hi_b912c = ((u32)(unsigned long)ref_t32_data_f3778 + 0x8000U) & 0xffff0000U;
    const u32 hi_b9130 = ((u32)(unsigned long)ref_t32_data_f333c + 0x8000U) & 0xffff0000U;
    const u32 hi_b9158 = ((u32)(unsigned long)ref_t32_data_f374c + 0x8000U) & 0xffff0000U;
    const u32 hi_b9170 = ((u32)(unsigned long)ref_t32_data_f3804 + 0x8000U) & 0xffff0000U;
    const u32 hi_b9180 = ((u32)(unsigned long)ref_t32_data_f380c + 0x8000U) & 0xffff0000U;
    const u32 hi_b918c = ((u32)(unsigned long)ref_tisp_msca_addr_fifo_write + 0x8000U) & 0xffff0000U;
    const u32 hi_b91f4 = ((u32)(unsigned long)ref_t32_data_c3338 + 0x8000U) & 0xffff0000U;
    const u32 hi_b91f8 = ((u32)(unsigned long)ref_t32_data_ccf7c + 0x8000U) & 0xffff0000U;
    const u32 hi_b91fc = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b9244 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_b928c = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_b92ac = ((u32)(unsigned long)ref_private_kmalloc + 0x8000U) & 0xffff0000U;
    const u32 hi_b9348 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_b938c = ((u32)(unsigned long)ref_private_kfree + 0x8000U) & 0xffff0000U;
    const u32 hi_b93a8 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_b8aa4 = ((u32)(unsigned long)ref_t32_data_ccf18 + 0x8000U) & 0xffff0000U;
    const u32 hi_b8edc = ((u32)(unsigned long)ref_t32_data_ccf64 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[36];
    v1 = *(volatile u8 *)(unsigned long)(a0 + (5));
    branch = (v1 == 0); v0 = 0;
    if (branch) goto L_b9438;
    goto L_b867c;
L_b867c:
    v0 = 0xfcffU << 16;
    v0 = v0 | 0xffff;
    a1 = a1 + v0;
    v0 = (u32)a1 < (u32)(8);
    branch = (v0 == 0); a1 = a1 << (0x2 & 31);
    if (branch) goto L_b9440;
    goto L_b8694;
L_b8694:
    v0 = hi_b8694;
    v0 = v0 - hi_b8694 + (u32)(unsigned long)ref_t32_data_c312c;
    a1 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    sp = sp + -144;
    *(volatile u32 *)(unsigned long)(sp + (108)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (104)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (140)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (136)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (132)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (120)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (116)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (112)) = s2;
    s0 = a2;
    callee = v0; s1 = a0;
    switch (callee) { case 0xb86dc: goto L_b86dc; case 0xb873c: goto L_b873c; case 0xb8744: goto L_b8744; case 0xb89b8: goto L_b89b8; case 0xb8c34: goto L_b8c34; case 0xb8c4c: goto L_b8c4c; case 0xb9228: goto L_b9228; case 0xb932c: goto L_b932c; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
L_b86dc:
    a1 = *(volatile u32 *)(unsigned long)(a0 + (32));
    branch = (a2 == 0); v0 = 0;
    if (branch) goto L_b940c;
    goto L_b86e8;
L_b86e8:
    branch = (a1 == 0); ra = *(volatile u32 *)(unsigned long)(sp + (140));
    if (branch) goto L_b9410;
    goto L_b86f0;
L_b86f0:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (136));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (1148));
    v0 = 1;
    if (v1 != v0) { v0 = hi_b8700; goto L_b8728; }
    goto L_b8704;
L_b8704:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    *(volatile u32 *)(unsigned long)(a2 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (8));
    *(volatile u32 *)(unsigned long)(a2 + (8)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (24));
    *(volatile u8 *)(unsigned long)(a2 + (52)) = 0;
    *(volatile u8 *)(unsigned long)(a2 + (72)) = 0;
    *(volatile u32 *)(unsigned long)(a2 + (24)) = v0; goto L_b873c;
L_b8728:
    a2 = 116;
    v0 = v0 - hi_b8700 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8738;
L_b8738:
    *(volatile u32 *)(unsigned long)(s0 + (24)) = 0;
L_b873c:
    v0 = 0; goto L_b940c;
L_b8744:
    branch = (a0 == 0); v0 = -22;
    if (branch) goto L_b940c;
    goto L_b874c;
L_b874c:
    v1 = (u32)a0 < (u32)(-4095);
    branch = (v1 == 0); ra = *(volatile u32 *)(unsigned long)(sp + (140));
    if (branch) goto L_b9410;
    goto L_b8758;
L_b8758:
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (v1 == 0); a0 = (u32)v1 < (u32)(-4095);
    if (branch) goto L_b9410;
    goto L_b8764;
L_b8764:
    branch = (a0 == 0); s8 = *(volatile u32 *)(unsigned long)(sp + (136));
    if (branch) goto L_b9414;
    goto L_b876c;
L_b876c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (280));
    branch = (a0 == 0); v1 = (u32)a0 < (u32)(-4095);
    if (branch) goto L_b9410;
    goto L_b8778;
L_b8778:
    branch = (v1 == 0); a2 = hi_b877c;
    if (branch) goto L_b9410;
    goto L_b8780;
L_b8780:
    s4 = *(volatile u32 *)(unsigned long)(s1 + (32));
    v0 = 3;
    v1 = *(volatile u32 *)(unsigned long)(s4 + (116));
    s1 = hi_b878c;
    s1 = s1 - hi_b878c + (u32)(unsigned long)ref_isp_printf;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v0 = 104;
    a3 = 1949;
    a2 = a2 - hi_b877c + (u32)(unsigned long)ref_t32_data_c3370;
    v1 = lo;
    a1 = v1 * v0;
    v0 = a1 + a0;
    s2 = *(volatile u32 *)(unsigned long)(v0 + (384));
    s3 = *(volatile u32 *)(unsigned long)(v0 + (388));
    v0 = *(volatile u32 *)(unsigned long)(s4 + (8));
    a1 = hi_b87bc;
    a1 = a1 - hi_b87bc + (u32)(unsigned long)ref_t32_data_ccdf8;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s4 + (4));
    a0 = 0;
    callee = s1; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b87d8;
L_b87d8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (80));
    a2 = *(volatile u8 *)(unsigned long)(s0 + (72));
    a1 = hi_b87e0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    a3 = *(volatile u32 *)(unsigned long)(s0 + (76));
    a1 = a1 - hi_b87e0 + (u32)(unsigned long)ref_t32_data_cce1c;
    callee = s1; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b87f8;
L_b87f8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (68));
    a2 = *(volatile u8 *)(unsigned long)(s0 + (52));
    a1 = hi_b8800;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (64));
    a1 = a1 - hi_b8800 + (u32)(unsigned long)ref_t32_data_cce64;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (60));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    callee = s1; a3 = *(volatile u32 *)(unsigned long)(s0 + (56));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8828;
L_b8828:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (108));
    a2 = *(volatile u8 *)(unsigned long)(s0 + (92));
    a1 = hi_b8830;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (104));
    a1 = a1 - hi_b8830 + (u32)(unsigned long)ref_t32_data_ccebc;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (100));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    callee = s1; a3 = *(volatile u32 *)(unsigned long)(s0 + (96));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8858;
L_b8858:
    v1 = hi_b8858;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (12));
    v1 = v1 - hi_b8858 + (u32)(unsigned long)ref_t32_data_d8ce0;
    v0 = 0;
    a3 = v1;
    a1 = 8;
L_b8870:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (32));
    if (a0 == a2) { a1 = 44; goto L_b93c0; }
    goto L_b887c;
L_b887c:
    v0 = v0 + 1;
    branch = (v0 != a1); v1 = v1 + 44;
    if (branch) goto L_b8870;
    goto L_b8888;
L_b8888:
    a2 = hi_b8888;
    a1 = hi_b888c;
    *(volatile u32 *)(unsigned long)(sp + (16)) = a0;
    a3 = 1895;
    a2 = a2 - hi_b8888 + (u32)(unsigned long)ref_t32_data_c3354;
    a1 = a1 - hi_b888c + (u32)(unsigned long)ref_t32_data_ccfa4;
    callee = s1; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b88a8;
L_b88a8:
    v0 = hi_b88a8;
    v0 = v0 - hi_b88a8 + (u32)(unsigned long)ref_private_init_completion;
    callee = v0; a0 = s4 + 240;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b88b8;
L_b88b8:
    v0 = hi_b88b8;
    *(volatile u8 *)(unsigned long)(s4 + (252)) = 0;
    a2 = 52;
    a1 = 0;
    v0 = v0 - hi_b88b8 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a0 = sp + 32;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b88d4;
L_b88d4:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (92));
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(sp + (64)) = v0;
    if (branch) goto L_b8904;
    goto L_b88e0;
L_b88e0:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (100));
    *(volatile u32 *)(unsigned long)(sp + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (96));
    *(volatile u32 *)(unsigned long)(sp + (72)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (104));
    *(volatile u32 *)(unsigned long)(sp + (76)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (108));
    *(volatile u32 *)(unsigned long)(sp + (80)) = v0; goto L_b8914;
L_b8904:
    *(volatile u32 *)(unsigned long)(sp + (68)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (72)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s3;
L_b8914:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (72));
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    if (branch) goto L_b8930;
    goto L_b8920;
L_b8920:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (76));
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (80)); goto L_b893c;
L_b8930:
    v0 = *(volatile u32 *)(unsigned long)(sp + (76));
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (80));
L_b893c:
    *(volatile u32 *)(unsigned long)(sp + (40)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s0 + (52));
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    if (branch) goto L_b896c;
    goto L_b894c;
L_b894c:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (60));
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (56));
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (64));
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (68)); goto L_b8980;
L_b896c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (36));
    *(volatile u32 *)(unsigned long)(sp + (48)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
L_b8980:
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
    a0 = *(volatile u8 *)(unsigned long)(s4 + (116));
    v0 = hi_b8988;
    v0 = v0 - hi_b8988 + (u32)(unsigned long)ref_lib_tisp_msca_channel_attr_set;
    callee = v0; a1 = sp + 32;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8998;
L_b8998:
    v0 = hi_b8998;
    a2 = 116;
    a1 = s0;
    v0 = v0 - hi_b8998 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b89b0;
L_b89b0:
    v0 = 0; goto L_b940c;
L_b89b8:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (v0 == 0); s5 = 0;
    if (branch) goto L_b89d0;
    goto L_b89c4;
L_b89c4:
    v1 = (u32)v0 < (u32)(-4095);
    if (v1 != 0) { s5 = *(volatile u32 *)(unsigned long)(v0 + (280)); goto L_b89d0; }
    goto L_b89d0;
L_b89d0:
    s2 = *(volatile u8 *)(unsigned long)(s1 + (7));
    v0 = 3;
    s0 = *(volatile u32 *)(unsigned long)(s1 + (32));
    branch = (s2 != v0); *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    if (branch) goto L_b873c;
    goto L_b89e4;
L_b89e4:
    s4 = s0 + 168;
    v0 = hi_b89e8;
    v0 = v0 - hi_b89e8 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    a1 = sp + 32;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b89fc;
L_b89fc:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (128));
    s3 = hi_b8a00;
    v0 = 4;
    branch = (v1 == v0); s3 = s3 - hi_b8a00 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    if (branch) goto L_b8c20;
    goto L_b8a10;
L_b8a10:
    *(volatile u32 *)(unsigned long)(s0 + (128)) = v0;
    *(volatile u8 *)(unsigned long)(s1 + (7)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s5 + (1196));
    t0 = 1;
    s7 = hi_b8a20;
    s6 = hi_b8a24;
    s8 = hi_b8a28;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    s7 = s7 - hi_b8a20 + (u32)(unsigned long)ref_tisp_msca_channel_start;
    s6 = s6 - hi_b8a24 + (u32)(unsigned long)ref_lib_tisp_msca_chx_stream_on;
    s8 = s8 - hi_b8a28 + (u32)(unsigned long)ref_lib_tisp_api_set_msca_dma_stride;
    branch = (v0 == t0); *(volatile u32 *)(unsigned long)(sp + (92)) = t0;
    if (branch) goto L_b8bdc;
    goto L_b8a44;
L_b8a44:
    s1 = *(volatile u32 *)(unsigned long)(s0 + (212));
    v1 = s0 + 212;
    a0 = a0 & 0xff;
    v0 = v1 ^ s1;
    *(volatile u32 *)(unsigned long)(sp + (88)) = v1;
    callee = s7; if (v0 == 0) s1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8a60;
L_b8a60:
    callee = s6; a0 = *(volatile u8 *)(unsigned long)(s0 + (116));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8a68;
L_b8a68:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (40));
    a3 = 0;
    if (a0 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)a0 / (s32)s2; hi = (s32)a0 % (s32)s2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = hi;
    a1 = a1 & 0xff;
    a0 = lo;
    callee = s8; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8a8c;
L_b8a8c:
    t0 = *(volatile u32 *)(unsigned long)(sp + (92));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (212));
    v1 = *(volatile u32 *)(unsigned long)(sp + (88));
    branch = (v1 == v0); *(volatile u32 *)(unsigned long)(s0 + (208)) = t0;
    if (branch) goto L_b8bbc;
    goto L_b8aa0;
L_b8aa0:
    branch = (v0 == 0); a1 = hi_b8aa4;
    if (branch) goto L_b8bc0;
    goto L_b8aa8;
L_b8aa8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    v0 = v0 + 2;
    v0 = (u32)v0 < (u32)(5);
    branch = (v0 == 0); a1 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (branch) goto L_b8c24;
    goto L_b8abc;
L_b8abc:
    v0 = hi_b8abc;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b8abc + (u32)(unsigned long)ref_t32_data_d9008);
    branch = (v0 == 0); ;
    if (branch) goto L_b8c24;
    goto L_b8acc;
L_b8acc:
    v0 = *(volatile u32 *)(unsigned long)(s5 + (4020));
    branch = (v0 != 0); ;
    if (branch) goto L_b8c24;
    goto L_b8ad8;
L_b8ad8:
    v0 = hi_b8ad8;
    v0 = v0 - hi_b8ad8 + (u32)(unsigned long)ref___ispcore_get_frame_drop;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8ae8;
L_b8ae8:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    s6 = hi_b8aec;
    s6 = s6 - hi_b8aec + (u32)(unsigned long)ref_tisp_msca_chx_en;
    if (a0 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)a0 / (s32)s2; hi = (s32)a0 % (s32)s2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = hi;
    branch = (v0 != 0); a0 = lo;
    if (branch) goto L_b8b7c;
    goto L_b8b04;
L_b8b04:
    a1 = *(volatile u8 *)(unsigned long)(s0 + (120));
    a3 = *(volatile u32 *)(unsigned long)(s1 + (12));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (8));
    v0 = hi_b8b10;
    v0 = v0 - hi_b8b10 + (u32)(unsigned long)ref_tisp_msca_addr_fifo_write;
    callee = v0; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8b20;
L_b8b20:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (116));
    a2 = 1;
    s0 = s0 + 220;
    if (a0 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)a0 / (s32)s2; hi = (s32)a0 % (s32)s2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = hi;
    a1 = a1 & 0xff;
    a0 = lo;
    callee = s6; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8b44;
L_b8b44:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    v1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = 256;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0;
    v0 = 512;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    *(volatile u32 *)(unsigned long)(s0 + (4)) = s1;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s0;
    *(volatile u32 *)(unsigned long)(s1 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = s1; goto L_b8b8c;
L_b8b7c:
    a2 = 0;
    a1 = a1 & 0xff;
    callee = s6; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8b8c;
L_b8b8c:
    v0 = *(volatile u32 *)(unsigned long)(s5 + (4012));
    branch = (v0 != 0); a1 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (branch) goto L_b8c24;
    goto L_b8b98;
L_b8b98:
    v0 = hi_b8b98;
    *(volatile u32 *)(unsigned long)(v0 - hi_b8b98 + (u32)(unsigned long)ref_t32_data_f3354) = 0;
    v0 = hi_b8ba0;
    v0 = v0 - hi_b8ba0 + (u32)(unsigned long)ref_lib_tisp_stream_on;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8bb0;
L_b8bb0:
    v0 = 1;
    *(volatile u32 *)(unsigned long)(s5 + (4012)) = v0; goto L_b8c20;
L_b8bbc:
    a1 = hi_b8bbc;
L_b8bc0:
    v0 = hi_b8bc0;
    a1 = a1 - hi_b8bbc + (u32)(unsigned long)ref_t32_data_ccf18;
    v0 = v0 - hi_b8bc0 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8bd4;
L_b8bd4:
    a1 = *(volatile u32 *)(unsigned long)(sp + (32)); goto L_b8c24;
L_b8bdc:
    if (a0 == 0x80000000U && s2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s2) { lo = (s32)a0 / (s32)s2; hi = (s32)a0 % (s32)s2; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    *(volatile u32 *)(unsigned long)(s0 + (208)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (220));
    v1 = s0 + 220;
    a3 = 0;
    v1 = v0 ^ v1;
    if (v1 == 0) v0 = 0;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (40));
    a1 = hi;
    a1 = a1 & 0xff;
    a0 = lo;
    callee = s8; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8c10;
L_b8c10:
    callee = s7; a0 = *(volatile u8 *)(unsigned long)(s0 + (116));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8c18;
L_b8c18:
    callee = s6; a0 = *(volatile u8 *)(unsigned long)(s0 + (116));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8c20;
L_b8c20:
    a1 = *(volatile u32 *)(unsigned long)(sp + (32));
L_b8c24:
    callee = s3; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8c2c;
L_b8c2c:
    v0 = 0; goto L_b940c;
L_b8c34:
    v0 = hi_b8c34;
    v0 = v0 - hi_b8c34 + (u32)(unsigned long)ref_ispcore_frame_channel_streamoff;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8c44;
L_b8c44:
    ra = *(volatile u32 *)(unsigned long)(sp + (140)); goto L_b9410;
L_b8c4c:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (v0 == 0); s6 = 0;
    if (branch) goto L_b8c64;
    goto L_b8c58;
L_b8c58:
    v1 = (u32)v0 < (u32)(-4095);
    if (v1 != 0) { s6 = *(volatile u32 *)(unsigned long)(v0 + (280)); goto L_b8c64; }
    goto L_b8c64;
L_b8c64:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (20));
    *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    v1 = v1 & 0x20;
    branch = (v1 != 0); v0 = 0;
    if (branch) goto L_b940c;
    goto L_b8c78;
L_b8c78:
    branch = (s0 == 0); s1 = *(volatile u32 *)(unsigned long)(s1 + (32));
    if (branch) goto L_b91f4;
    goto L_b8c80;
L_b8c80:
    branch = (s1 == 0); s3 = s1 + 168;
    if (branch) goto L_b91f4;
    goto L_b8c88;
L_b8c88:
    v0 = 4;
    *(volatile u8 *)(unsigned long)(s0 + (-36)) = v0;
    v0 = hi_b8c90;
    v0 = v0 - hi_b8c90 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    a1 = sp + 32;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8ca4;
L_b8ca4:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (12));
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); v1 = 1;
    if (branch) goto L_b8ce8;
    goto L_b8cb4;
L_b8cb4:
    v0 = 5;
    s5 = *(volatile u32 *)(unsigned long)(s1 + (4));
    s4 = *(volatile u32 *)(unsigned long)(s1 + (8));
    *(volatile u8 *)(unsigned long)(s0 + (-36)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (-32));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s0 + (-32)) = v0;
    v0 = hi_b8cd0;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_b8cd0 + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (a0 != v1); s7 = v0;
    if (branch) goto L_b8d2c;
    goto L_b8ce0;
L_b8ce0:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (116)); goto L_b8d14;
L_b8ce8:
    a2 = hi_b8ce8;
    a1 = hi_b8cec;
    v0 = hi_b8cf0;
    a3 = 1540;
    a2 = a2 - hi_b8ce8 + (u32)(unsigned long)ref_t32_data_c3338;
    a1 = a1 - hi_b8cec + (u32)(unsigned long)ref_t32_data_ccf38;
    v0 = v0 - hi_b8cf0 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8d0c;
L_b8d0c:
    v0 = -1; goto L_b940c;
L_b8d14:
    if (v0 != 0) { v1 = *(volatile u32 *)(unsigned long)(s6 + (1196)); goto L_b8d30; }
    goto L_b8d1c;
L_b8d1c:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    v1 = 0x100U << 16;
    v0 = v0 | v1;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = v0;
L_b8d2c:
    v1 = *(volatile u32 *)(unsigned long)(s6 + (1196));
L_b8d30:
    s8 = 1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (228));
    branch = (v1 == s8); s2 = s1 + 228;
    if (branch) goto L_b8ed0;
    goto L_b8d40;
L_b8d40:
    s2 = v0 ^ s2;
    if (s2 == 0) v0 = 0;
    a0 = v0 + 8;
    s2 = v0;
    v0 = hi_b8d50;
    a2 = 8;
    v0 = v0 - hi_b8d50 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a1 = s0 + 8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8d64;
L_b8d64:
    v0 = *(volatile u32 *)(unsigned long)(s7 - hi_b8cd0 + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (v0 != s8); v1 = 2;
    if (branch) goto L_b8d84;
    goto L_b8d70;
L_b8d70:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (116));
    if (v0 == 0) { a0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8dfc; }
    goto L_b8d7c;
L_b8d7c:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8e78;
L_b8d84:
    branch = (v0 != v1); v1 = 3;
    if (branch) goto L_b8dac;
    goto L_b8d8c;
L_b8d8c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (116));
    if (v0 == 0) { a0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8dfc; }
    goto L_b8d98;
L_b8d98:
    v1 = 3;
    if (v0 != v1) { v0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8e78; }
    goto L_b8da4;
L_b8da4:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8dfc;
L_b8dac:
    branch = (v0 != v1); v1 = 4;
    if (branch) goto L_b8dcc;
    goto L_b8db4;
L_b8db4:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (116));
    v0 = (u32)v1 < (u32)(7);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8e78; }
    goto L_b8dc4;
L_b8dc4:
    v0 = 73; goto L_b8de8;
L_b8dcc:
    if (v0 != v1) { v0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8e78; }
    goto L_b8dd4;
L_b8dd4:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (116));
    v0 = (u32)v1 < (u32)(10);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8e78; }
    goto L_b8de4;
L_b8de4:
    v0 = 585;
L_b8de8:
    v0 = v0 >> (v1 & 31);
    v0 = v0 & 0x1;
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (8)); goto L_b8e78; }
    goto L_b8df8;
L_b8df8:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (8));
L_b8dfc:
    v0 = 0x100U << 16;
    v1 = 3;
    t0 = a0 | v0;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = t0;
    a1 = *(volatile u32 *)(unsigned long)(s1 + (116));
    v0 = 4;
    a3 = 12;
    if (a1 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a1 / (s32)v1; hi = (s32)a1 % (s32)v1; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a2 = lo;
    if (a2 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)a2 / (s32)v0; hi = (s32)a2 % (s32)v0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = hi;
    a2 = a2 << (0x19 & 31);
    if (a1 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a1 / (s32)a3; hi = (s32)a1 % (s32)a3; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = lo;
    a1 = a1 << (0x1c & 31);
    a1 = a2 | a1;
    a1 = a1 | a0;
    *(volatile u32 *)(unsigned long)(s0 + (8)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (116));
    if (a0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)a0 / (s32)v1; hi = (s32)a0 % (s32)v1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v1 = lo;
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    v1 = hi;
    v1 = v1 << (0x19 & 31);
    if (a0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a0 / (s32)a3; hi = (s32)a0 % (s32)a3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    v0 = lo;
    v0 = v0 << (0x1c & 31);
    v0 = v1 | v0;
    v0 = v0 | t0;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (8));
L_b8e78:
    v1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    s1 = s1 + 212;
    *(volatile u32 *)(unsigned long)(s2 + (8)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (12));
    *(volatile u32 *)(unsigned long)(s2 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (40));
    *(volatile u32 *)(unsigned long)(s2 + (40)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (44));
    *(volatile u32 *)(unsigned long)(s2 + (44)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (4));
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = 256;
    *(volatile u32 *)(unsigned long)(s2 + (0)) = v0;
    v0 = 512;
    *(volatile u32 *)(unsigned long)(s2 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    *(volatile u32 *)(unsigned long)(s1 + (4)) = s2;
    *(volatile u32 *)(unsigned long)(s2 + (0)) = s1;
    *(volatile u32 *)(unsigned long)(s2 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = s2; goto L_b91e8;
L_b8ed0:
    branch = (v0 == s2); a2 = hi_b8ed4;
    if (branch) goto L_b8f3c;
    goto L_b8ed8;
L_b8ed8:
    branch = (v0 == 0); a1 = hi_b8edc;
    if (branch) goto L_b8f40;
    goto L_b8ee0;
L_b8ee0:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (8)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (12));
    *(volatile u32 *)(unsigned long)(v0 + (12)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (40));
    *(volatile u32 *)(unsigned long)(v0 + (40)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (44));
    *(volatile u32 *)(unsigned long)(v0 + (44)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a0;
    v1 = 256;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v1 = 512;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (216));
    a0 = s1 + 212;
    *(volatile u32 *)(unsigned long)(s1 + (216)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0; goto L_b8f5c;
L_b8f3c:
    a1 = hi_b8f3c;
L_b8f40:
    v0 = hi_b8f40;
    a3 = 1595;
    a2 = a2 - hi_b8ed4 + (u32)(unsigned long)ref_t32_data_c3338;
    a1 = a1 - hi_b8f3c + (u32)(unsigned long)ref_t32_data_ccf64;
    v0 = v0 - hi_b8f40 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8f5c;
L_b8f5c:
    v1 = *(volatile u32 *)(unsigned long)(s6 + (4284));
    v0 = 1;
    branch = (v1 == v0); s2 = hi_b8f68;
    if (branch) goto L_b9038;
    goto L_b8f6c;
L_b8f6c:
    s0 = *(volatile u32 *)(unsigned long)(s1 + (212));
    s6 = s1 + 212;
    branch = (s6 == s0); s2 = s2 - hi_b8f68 + (u32)(unsigned long)ref_tisp_msca_chx_en;
    if (branch) goto L_b9028;
    goto L_b8f7c;
L_b8f7c:
    branch = (s0 == 0); s7 = 3;
    if (branch) goto L_b9028;
    goto L_b8f84;
L_b8f84:
    s8 = hi_b8f84;
    t0 = 256;
    t1 = 512;
    t2 = s1 + 220;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (116));
L_b8f98:
    a3 = *(volatile u32 *)(unsigned long)(s0 + (12));
    a2 = *(volatile u32 *)(unsigned long)(s0 + (8));
    if (a0 == 0x80000000U && s7 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s7) { lo = (s32)a0 / (s32)s7; hi = (s32)a0 % (s32)s7; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = *(volatile u8 *)(unsigned long)(s1 + (120));
    v0 = s8 - hi_b8f84 + (u32)(unsigned long)ref_tisp_msca_addr_fifo_write;
    *(volatile u32 *)(unsigned long)(sp + (96)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (92)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (88)) = t0;
    a0 = lo;
    callee = v0; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8fc4;
L_b8fc4:
    a1 = *(volatile u8 *)(unsigned long)(s1 + (116));
    a2 = 1;
    callee = s2; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b8fd4;
L_b8fd4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (4));
    v1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    t0 = *(volatile u32 *)(unsigned long)(sp + (88));
    t1 = *(volatile u32 *)(unsigned long)(sp + (92));
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t0;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = t1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (224));
    t2 = *(volatile u32 *)(unsigned long)(sp + (96));
    *(volatile u32 *)(unsigned long)(s1 + (224)) = s0;
    *(volatile u32 *)(unsigned long)(s0 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = t2;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = s0;
    s0 = *(volatile u32 *)(unsigned long)(s1 + (212));
    branch = (s6 == s0); v0 = hi_b9014;
    if (branch) goto L_b903c;
    goto L_b9018;
L_b9018:
    if (s0 != 0) { a0 = *(volatile u32 *)(unsigned long)(s1 + (116)); goto L_b8f98; }
    goto L_b9020;
L_b9020:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b9014 + (u32)(unsigned long)ref_t32_data_d9008); goto L_b9040;
L_b9028:
    a1 = *(volatile u8 *)(unsigned long)(s1 + (116));
    a2 = 0;
    callee = s2; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b9038;
L_b9038:
    v0 = hi_b9038;
L_b903c:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b9038 + (u32)(unsigned long)ref_t32_data_d9008);
L_b9040:
    branch = (v0 == 0); s0 = s5 + 15;
    if (branch) goto L_b91e8;
    goto L_b9048;
L_b9048:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (120));
    a1 = -16;
    s4 = s4 + 15;
    s0 = s0 & a1;
    s4 = s4 & a1;
    branch = (v0 != 0); s0 = s0 * s4;
    if (branch) goto L_b9120;
    goto L_b9064;
L_b9064:
    v0 = hi_b9064;
    v1 = hi_b9068;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b9064 + (u32)(unsigned long)ref_t32_data_f3774);
    a0 = *(volatile u32 *)(unsigned long)(v1 - hi_b9068 + (u32)(unsigned long)ref_t32_data_f3340);
    a2 = (u32)a0 < (u32)(v0);
    if (a2 == 0) { a1 = *(volatile u32 *)(unsigned long)(sp + (32)); goto L_b91ec; }
    goto L_b9080;
L_b9080:
    a0 = a0 + 1;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(v1 - hi_b9068 + (u32)(unsigned long)ref_t32_data_f3340) = a0;
    if (branch) goto L_b91e8;
    goto L_b908c;
L_b908c:
    a0 = *(volatile u32 *)(unsigned long)(s1 + (8));
    a2 = hi_b9090;
    s2 = 0;
    a0 = a0 + 15;
    v1 = a0 & a1;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (4));
    s4 = a2;
    s6 = hi_b90a8;
    v0 = a0 << (0x1 & 31);
    v0 = v0 + a0;
    v0 = v1 * v0;
    s7 = hi_b90b8;
    s8 = 0x8000U << 16;
    s5 = 3;
    v1 = hi_b90c4;
    v0 = v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(a2 - hi_b9090 + (u32)(unsigned long)ref_t32_data_f3750) = v0;
L_b90d0:
    v0 = *(volatile u32 *)(unsigned long)(s6 - hi_b90a8 + (u32)(unsigned long)ref_t32_data_f3808);
    v0 = (u32)s2 < (u32)(v0);
    branch = (v0 == 0); a2 = *(volatile u32 *)(unsigned long)(s7 - hi_b90b8 + (u32)(unsigned long)ref_t32_data_f3810);
    if (branch) goto L_b91e8;
    goto L_b90e0;
L_b90e0:
    v0 = *(volatile u32 *)(unsigned long)(s4 - hi_b9090 + (u32)(unsigned long)ref_t32_data_f3750);
    a1 = *(volatile u8 *)(unsigned long)(s1 + (120));
    a0 = s2 * v0;
    a2 = s8 + a2;
    v0 = v1 - hi_b90c4 + (u32)(unsigned long)ref_tisp_msca_addr_fifo_write;
    *(volatile u32 *)(unsigned long)(sp + (88)) = v1;
    s2 = s2 + 1;
    a2 = a0 + a2;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (116));
    a3 = s0 + a2;
    if (a0 == 0x80000000U && s5 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s5) { lo = (s32)a0 / (s32)s5; hi = (s32)a0 % (s32)s5; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    callee = v0; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b9118;
L_b9118:
    v1 = *(volatile u32 *)(unsigned long)(sp + (88)); goto L_b90d0;
L_b9120:
    v1 = 1;
    if (v0 != v1) { a1 = *(volatile u32 *)(unsigned long)(sp + (32)); goto L_b91ec; }
    goto L_b912c;
L_b912c:
    v0 = hi_b912c;
    v1 = hi_b9130;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_b912c + (u32)(unsigned long)ref_t32_data_f3778);
    a0 = *(volatile u32 *)(unsigned long)(v1 - hi_b9130 + (u32)(unsigned long)ref_t32_data_f333c);
    a2 = (u32)a0 < (u32)(v0);
    if (a2 == 0) { a1 = *(volatile u32 *)(unsigned long)(sp + (32)); goto L_b91ec; }
    goto L_b9148;
L_b9148:
    a0 = a0 + 1;
    branch = (v0 != a0); *(volatile u32 *)(unsigned long)(v1 - hi_b9130 + (u32)(unsigned long)ref_t32_data_f333c) = a0;
    if (branch) goto L_b91e8;
    goto L_b9154;
L_b9154:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (8));
    a0 = hi_b9158;
    s2 = 0;
    v0 = v1 + 15;
    v1 = v0 & a1;
    a1 = *(volatile u32 *)(unsigned long)(s1 + (4));
    s4 = a0;
    s6 = hi_b9170;
    v0 = a1 << (0x1 & 31);
    v0 = v0 + a1;
    v0 = v1 * v0;
    s7 = hi_b9180;
    s8 = 0x8000U << 16;
    s5 = 3;
    v1 = hi_b918c;
    v0 = v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(a0 - hi_b9158 + (u32)(unsigned long)ref_t32_data_f374c) = v0;
L_b9198:
    v0 = *(volatile u32 *)(unsigned long)(s6 - hi_b9170 + (u32)(unsigned long)ref_t32_data_f3804);
    v0 = (u32)s2 < (u32)(v0);
    branch = (v0 == 0); a2 = *(volatile u32 *)(unsigned long)(s7 - hi_b9180 + (u32)(unsigned long)ref_t32_data_f380c);
    if (branch) goto L_b91e8;
    goto L_b91a8;
L_b91a8:
    v0 = *(volatile u32 *)(unsigned long)(s4 - hi_b9158 + (u32)(unsigned long)ref_t32_data_f374c);
    a1 = *(volatile u8 *)(unsigned long)(s1 + (120));
    a0 = s2 * v0;
    a2 = s8 + a2;
    v0 = v1 - hi_b918c + (u32)(unsigned long)ref_tisp_msca_addr_fifo_write;
    *(volatile u32 *)(unsigned long)(sp + (88)) = v1;
    s2 = s2 + 1;
    a2 = a0 + a2;
    a0 = *(volatile u32 *)(unsigned long)(s1 + (116));
    a3 = s0 + a2;
    if (a0 == 0x80000000U && s5 == ~0U) { lo = 0x80000000U; hi = 0; } else if (s5) { lo = (s32)a0 / (s32)s5; hi = (s32)a0 % (s32)s5; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a0 = lo;
    callee = v0; a0 = a0 & 0xff;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b91e0;
L_b91e0:
    v1 = *(volatile u32 *)(unsigned long)(sp + (88)); goto L_b9198;
L_b91e8:
    a1 = *(volatile u32 *)(unsigned long)(sp + (32));
L_b91ec:
    a0 = s3; goto L_b93a8;
L_b91f4:
    a2 = hi_b91f4;
    a1 = hi_b91f8;
    v0 = hi_b91fc;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    a3 = 1647;
    a2 = a2 - hi_b91f4 + (u32)(unsigned long)ref_t32_data_c3338;
    a1 = a1 - hi_b91f8 + (u32)(unsigned long)ref_t32_data_ccf7c;
    v0 = v0 - hi_b91fc + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b9220;
L_b9220:
    v0 = 0; goto L_b940c;
L_b9228:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (20));
    v0 = v0 & 0x20;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    if (branch) goto L_b873c;
    goto L_b9238;
L_b9238:
    s1 = *(volatile u32 *)(unsigned long)(a0 + (32));
    branch = (s1 == 0); s2 = s1 + 168;
    if (branch) goto L_b873c;
    goto L_b9244;
L_b9244:
    v0 = hi_b9244;
    a1 = sp + 32;
    v0 = v0 - hi_b9244 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b9258;
L_b9258:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    s0 = s1 + 228;
    *(volatile u32 *)(unsigned long)(s1 + (228)) = s0;
    v0 = v0 + 1;
    *(volatile u8 *)(unsigned long)(s1 + (207)) = v0;
    v0 = s1 + 212;
    *(volatile u32 *)(unsigned long)(s1 + (212)) = v0;
    *(volatile u32 *)(unsigned long)(s1 + (216)) = v0;
    v0 = s1 + 220;
    *(volatile u32 *)(unsigned long)(s1 + (220)) = v0;
    *(volatile u32 *)(unsigned long)(s1 + (224)) = v0;
    *(volatile u32 *)(unsigned long)(s1 + (232)) = s0;
    a1 = *(volatile u32 *)(unsigned long)(sp + (32));
    v0 = hi_b928c;
    v0 = v0 - hi_b928c + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b929c;
L_b929c:
    a0 = *(volatile u8 *)(unsigned long)(s1 + (207));
    v0 = 52;
    a1 = 0x208U << 16;
    a0 = a0 * v0;
    v0 = hi_b92ac;
    v0 = v0 - hi_b92ac + (u32)(unsigned long)ref_private_kmalloc;
    callee = v0; a1 = a1 + 32;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b92bc;
L_b92bc:
    *(volatile u32 *)(unsigned long)(s1 + (236)) = v0;
    a0 = 0;
    a2 = 52;
L_b92c8:
    v0 = *(volatile u8 *)(unsigned long)(s1 + (207));
    v0 = (s32)a0 < (s32)(v0);
    branch = (v0 == 0); a1 = a0 * a2;
    if (branch) goto L_b930c;
    goto L_b92d8;
L_b92d8:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (236));
    a0 = a0 + 1;
    v1 = v1 + a1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (236));
    v1 = *(volatile u32 *)(unsigned long)(s1 + (232));
    v0 = v0 + a1;
    *(volatile u32 *)(unsigned long)(s1 + (232)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = s0;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0; goto L_b92c8;
L_b930c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (260));
    if (v0 != 0) { v0 = 0; goto L_b940c; }
    goto L_b9318;
L_b9318:
    v0 = -1;
    *(volatile u32 *)(unsigned long)(s1 + (264)) = 0;
    *(volatile u32 *)(unsigned long)(s1 + (268)) = v0;
    *(volatile u32 *)(unsigned long)(s1 + (272)) = 0; goto L_b873c;
L_b932c:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (20));
    v0 = v0 & 0x20;
    branch = (v0 != 0); *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    if (branch) goto L_b873c;
    goto L_b933c;
L_b933c:
    s0 = *(volatile u32 *)(unsigned long)(a0 + (32));
    branch = (s0 == 0); s1 = s0 + 168;
    if (branch) goto L_b873c;
    goto L_b9348;
L_b9348:
    v0 = hi_b9348;
    a0 = s1;
    v0 = v0 - hi_b9348 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    callee = v0; a1 = sp + 32;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b935c;
L_b935c:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (236));
    branch = (a0 == 0); a1 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (branch) goto L_b93a4;
    goto L_b9368;
L_b9368:
    v0 = s0 + 212;
    *(volatile u32 *)(unsigned long)(s0 + (212)) = v0;
    *(volatile u32 *)(unsigned long)(s0 + (216)) = v0;
    v0 = s0 + 220;
    *(volatile u32 *)(unsigned long)(s0 + (220)) = v0;
    *(volatile u32 *)(unsigned long)(s0 + (224)) = v0;
    v0 = s0 + 228;
    *(volatile u32 *)(unsigned long)(s0 + (228)) = v0;
    *(volatile u32 *)(unsigned long)(s0 + (232)) = v0;
    v0 = hi_b938c;
    v0 = v0 - hi_b938c + (u32)(unsigned long)ref_private_kfree;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b939c;
L_b939c:
    *(volatile u32 *)(unsigned long)(s0 + (236)) = 0;
    a1 = *(volatile u32 *)(unsigned long)(sp + (32));
L_b93a4:
    a0 = s1;
L_b93a8:
    v0 = hi_b93a8;
    v0 = v0 - hi_b93a8 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b93b8;
L_b93b8:
    v0 = 0; goto L_b940c;
L_b93c0:
    v1 = v0 * a1;
    a2 = *(volatile u32 *)(unsigned long)(s0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    a1 = v1 + a3;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (36));
    v1 = a2 * v1;
    v1 = v1 >> (0x3 & 31);
    *(volatile u32 *)(unsigned long)(s0 + (20)) = v1;
    v1 = a0 * v1;
    *(volatile u32 *)(unsigned long)(s0 + (24)) = v1;
    v1 = 44;
    a0 = v0 * v1;
    v0 = a0 + a3;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (36));
    v1 = v1 >> (0x3 & 31);
    v1 = v1 * a2;
    *(volatile u32 *)(unsigned long)(s4 + (200)) = v1;
    *(volatile u32 *)(unsigned long)(s0 + (32)) = v0; goto L_b88a8;
L_b940c:
    ra = *(volatile u32 *)(unsigned long)(sp + (140));
L_b9410:
    s8 = *(volatile u32 *)(unsigned long)(sp + (136));
L_b9414:
    s7 = *(volatile u32 *)(unsigned long)(sp + (132));
    s6 = *(volatile u32 *)(unsigned long)(sp + (128));
    s5 = *(volatile u32 *)(unsigned long)(sp + (124));
    s4 = *(volatile u32 *)(unsigned long)(sp + (120));
    s3 = *(volatile u32 *)(unsigned long)(sp + (116));
    s2 = *(volatile u32 *)(unsigned long)(sp + (112));
    s1 = *(volatile u32 *)(unsigned long)(sp + (108));
    s0 = *(volatile u32 *)(unsigned long)(sp + (104));
    sp = sp + 144;
L_b9438:
    ;
    return ((u64)v1 << 32) | v0;
L_b9440:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
