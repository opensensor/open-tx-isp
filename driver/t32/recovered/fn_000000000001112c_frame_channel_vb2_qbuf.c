/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_c5fcc[] __asm__("t32_data_c5fcc");
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_t32_data_f37d4[] __asm__("t32_data_f37d4");
extern unsigned char ref_t32_data_f37a4[] __asm__("t32_data_f37a4");
extern unsigned char ref_t32_data_f3774[] __asm__("t32_data_f3774");
extern unsigned char ref_t32_data_d9ba4[] __asm__("t32_data_d9ba4");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_d9d04[] __asm__("t32_data_d9d04");
extern unsigned char ref_t32_data_d9d14[] __asm__("t32_data_d9d14");
extern unsigned char ref_private_copy_from_user[] __asm__("private_copy_from_user");
extern unsigned char ref_t32_data_c5f08[] __asm__("t32_data_c5f08");
extern unsigned char ref_t32_data_be52c[] __asm__("t32_data_be52c");
extern unsigned char ref_t32_data_c6104[] __asm__("t32_data_c6104");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_c6144[] __asm__("t32_data_c6144");
extern unsigned char ref_t32_data_c6160[] __asm__("t32_data_c6160");
extern unsigned char ref_t32_data_c618c[] __asm__("t32_data_c618c");
extern unsigned char ref_t32_data_c61a4[] __asm__("t32_data_c61a4");
extern unsigned char ref_t32_data_c61c0[] __asm__("t32_data_c61c0");
extern unsigned char ref_t32_data_c61f8[] __asm__("t32_data_c61f8");
extern unsigned char ref_mips_dma_map_ops[] __asm__("mips_dma_map_ops");
extern unsigned char ref_private_mutex_lock[] __asm__("private_mutex_lock");
extern unsigned char ref___private_spin_lock_irqsave[] __asm__("__private_spin_lock_irqsave");
extern unsigned char ref_private_spin_unlock_irqrestore[] __asm__("private_spin_unlock_irqrestore");
extern unsigned char ref___enqueue_in_driver[] __asm__("__enqueue_in_driver");
extern unsigned char ref___fill_tisp_buffer[] __asm__("__fill_tisp_buffer");
extern unsigned char ref_private_mutex_unlock[] __asm__("private_mutex_unlock");
extern unsigned char ref_private_copy_to_user[] __asm__("private_copy_to_user");
extern unsigned char ref_t32_data_c5f98[] __asm__("t32_data_c5f98");
u64 frame_channel_vb2_qbuf(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[102] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_11178 = ((u32)(unsigned long)ref_t32_data_c5fcc + 0x8000U) & 0xffff0000U;
    const u32 hi_11174 = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_11190 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_111bc = ((u32)(unsigned long)ref_t32_data_f37d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_111b0 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_111d4 = ((u32)(unsigned long)ref_t32_data_f37a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_111ec = ((u32)(unsigned long)ref_t32_data_f3774 + 0x8000U) & 0xffff0000U;
    const u32 hi_11204 = ((u32)(unsigned long)ref_t32_data_d9ba4 + 0x8000U) & 0xffff0000U;
    const u32 hi_11240 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_112dc = ((u32)(unsigned long)ref_t32_data_d9d04 + 0x8000U) & 0xffff0000U;
    const u32 hi_11300 = ((u32)(unsigned long)ref_t32_data_d9d14 + 0x8000U) & 0xffff0000U;
    const u32 hi_1123c = ((u32)(unsigned long)ref_private_copy_from_user + 0x8000U) & 0xffff0000U;
    const u32 hi_11340 = ((u32)(unsigned long)ref_t32_data_c5f08 + 0x8000U) & 0xffff0000U;
    const u32 hi_11358 = ((u32)(unsigned long)ref_t32_data_be52c + 0x8000U) & 0xffff0000U;
    const u32 hi_1135c = ((u32)(unsigned long)ref_t32_data_c6104 + 0x8000U) & 0xffff0000U;
    const u32 hi_1136c = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_11390 = ((u32)(unsigned long)ref_t32_data_c6144 + 0x8000U) & 0xffff0000U;
    const u32 hi_113ac = ((u32)(unsigned long)ref_t32_data_c6160 + 0x8000U) & 0xffff0000U;
    const u32 hi_113cc = ((u32)(unsigned long)ref_t32_data_c618c + 0x8000U) & 0xffff0000U;
    const u32 hi_113e8 = ((u32)(unsigned long)ref_t32_data_c61a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_113f0 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_11414 = ((u32)(unsigned long)ref_t32_data_c61c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_11428 = ((u32)(unsigned long)ref_t32_data_c61f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_114e4 = (((u32)(unsigned long)ref_mips_dma_map_ops + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_11574 = ((u32)(unsigned long)ref_private_mutex_lock + 0x8000U) & 0xffff0000U;
    const u32 hi_11588 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_115d0 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_115f0 = ((u32)(unsigned long)ref___enqueue_in_driver + 0x8000U) & 0xffff0000U;
    const u32 hi_11608 = ((u32)(unsigned long)ref___fill_tisp_buffer + 0x8000U) & 0xffff0000U;
    const u32 hi_1161c = ((u32)(unsigned long)ref_private_mutex_unlock + 0x8000U) & 0xffff0000U;
    const u32 hi_11640 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_11658 = ((u32)(unsigned long)ref_private_copy_to_user + 0x8000U) & 0xffff0000U;
    const u32 hi_11670 = ((u32)(unsigned long)ref_t32_data_c5f98 + 0x8000U) & 0xffff0000U;
    const u32 hi_11678 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_11270 = ((u32)(unsigned long)ref_t32_data_d9d04 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[38];
    sp = sp + -152;
    v0 = -22;
    *(volatile u32 *)(unsigned long)(sp + (148)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (144)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (140)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (136)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (132)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s0;
    branch = (a0 == 0); *(volatile u32 *)(unsigned long)(sp + (112)) = 0;
    if (branch) goto L_1168c;
    goto L_11158;
L_11158:
    v1 = (u32)a0 < (u32)(-4095);
    branch = (v1 == 0); s2 = a1;
    if (branch) goto L_1168c;
    goto L_11164;
L_11164:
    branch = (a1 == 0); s1 = a0;
    if (branch) goto L_11178;
    goto L_1116c;
L_1116c:
    v0 = (u32)a1 < (u32)(-4095);
    if (v0 != 0) { v0 = hi_11174; goto L_11184; }
    goto L_11178;
L_11178:
    a1 = hi_11178;
    a1 = a1 - hi_11178 + (u32)(unsigned long)ref_t32_data_c5fcc; goto L_113f0;
L_11184:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_11174 + (u32)(unsigned long)ref_t32_data_d9008);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(a0 + (808)); goto L_111ac; }
    goto L_11190;
L_11190:
    s3 = hi_11190;
L_11194:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_11190 + (u32)(unsigned long)ref_t32_data_d9014);
L_11198:
    v1 = 1;
    branch = (v0 != v1); v1 = 2;
    if (branch) goto L_11260;
    goto L_111a4;
L_111a4:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (720)); goto L_1122c;
L_111ac:
    branch = (v0 != 0); s3 = hi_111b0;
    if (branch) goto L_11194;
    goto L_111b4;
L_111b4:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (720));
    v1 = v0 << (0x2 & 31);
    v0 = hi_111bc;
    v0 = v0 - hi_111bc + (u32)(unsigned long)ref_t32_data_f37d4;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s3 - hi_111b0 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_11198;
    goto L_111d4;
L_111d4:
    v0 = hi_111d4;
    v0 = v0 - hi_111d4 + (u32)(unsigned long)ref_t32_data_f37a4;
    v0 = v1 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s3 - hi_111b0 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_11198;
    goto L_111ec;
L_111ec:
    v0 = hi_111ec;
    v0 = v0 - hi_111ec + (u32)(unsigned long)ref_t32_data_f3774;
    v0 = v1 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s3 - hi_111b0 + (u32)(unsigned long)ref_t32_data_d9014);
    if (branch) goto L_11198;
    goto L_11204;
L_11204:
    v0 = hi_11204;
    v0 = v0 - hi_11204 + (u32)(unsigned long)ref_t32_data_d9ba4;
    v0 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = v1 + 1;
    v1 = (s32)v1 < (s32)(a0);
    branch = (v1 == 0); *(volatile u32 *)(unsigned long)(v0 + (0)) = a1;
    if (branch) goto L_11194;
    goto L_11224;
L_11224:
    v0 = 0; goto L_1168c;
L_1122c:
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (720)); goto L_112d8; }
    goto L_11234;
L_11234:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (808));
L_11238:
    if (v0 == 0) { v0 = hi_1123c; goto L_11324; }
    goto L_11240;
L_11240:
    v0 = hi_11240;
    a2 = 96;
    a1 = s2;
    v0 = v0 - hi_11240 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11258;
L_11258:
    v0 = *(volatile u32 *)(unsigned long)(sp + (88)); goto L_1134c;
L_11260:
    branch = (v0 != v1); v1 = 3;
    if (branch) goto L_11288;
    goto L_11268;
L_11268:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (720));
    branch = (v0 == 0); a0 = hi_11270;
    if (branch) goto L_112e0;
    goto L_11274;
L_11274:
    v1 = 3;
    if (v0 != v1) { v0 = *(volatile u32 *)(unsigned long)(s1 + (808)); goto L_11238; }
    goto L_11280;
L_11280:
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; } goto L_112e4;
L_11288:
    branch = (v0 != v1); v1 = 4;
    if (branch) goto L_112a8;
    goto L_11290;
L_11290:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (720));
    v0 = (u32)v1 < (u32)(7);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (808)); goto L_11238; }
    goto L_112a0;
L_112a0:
    v0 = 73; goto L_112c4;
L_112a8:
    if (v0 != v1) { v0 = *(volatile u32 *)(unsigned long)(s1 + (808)); goto L_11238; }
    goto L_112b0;
L_112b0:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (720));
    v0 = (u32)v1 < (u32)(10);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (808)); goto L_11238; }
    goto L_112c0;
L_112c0:
    v0 = 585;
L_112c4:
    v0 = v0 >> (v1 & 31);
    v0 = v0 & 0x1;
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (808)); goto L_11238; }
    goto L_112d4;
L_112d4:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (720));
L_112d8:
    v1 = 3;
    a0 = hi_112dc;
L_112e0:
    if (v0 == 0x80000000U && v1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v1) { lo = (s32)v0 / (s32)v1; hi = (s32)v0 % (s32)v1; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
L_112e4:
    a0 = a0 - hi_112dc + (u32)(unsigned long)ref_t32_data_d9d04;
    v0 = lo;
    v0 = v0 << (0x2 & 31);
    a0 = v0 + a0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = v1 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v1;
    a0 = hi_11300;
    a0 = a0 - hi_11300 + (u32)(unsigned long)ref_t32_data_d9d14;
    v0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = (s32)v0 < (s32)(v1);
    if (v1 == 0) { v0 = *(volatile u32 *)(unsigned long)(s1 + (808)); goto L_11238; }
    goto L_1131c;
L_1131c:
    v0 = 0; goto L_1168c;
L_11324:
    a2 = 96;
    a1 = s2;
    v0 = v0 - hi_1123c + (u32)(unsigned long)ref_private_copy_from_user;
    callee = v0; a0 = sp + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11338;
L_11338:
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    if (branch) goto L_1134c;
    goto L_11340;
L_11340:
    a1 = hi_11340;
    a1 = a1 - hi_11340 + (u32)(unsigned long)ref_t32_data_c5f08; goto L_11678;
L_1134c:
    v1 = 1;
    if (v0 == v1) { a0 = *(volatile u32 *)(unsigned long)(sp + (20)); goto L_11384; }
    goto L_11358;
L_11358:
    a2 = hi_11358;
    a1 = hi_1135c;
    a3 = 799;
    a2 = a2 - hi_11358 + (u32)(unsigned long)ref_t32_data_be52c;
    a1 = a1 - hi_1135c + (u32)(unsigned long)ref_t32_data_c6104;
L_1136c:
    v0 = hi_1136c;
    v0 = v0 - hi_1136c + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1137c;
L_1137c:
    v0 = -22; goto L_1168c;
L_11384:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (44));
    branch = (a0 == v1); a2 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (branch) goto L_1139c;
    goto L_11390;
L_11390:
    a1 = hi_11390;
    a1 = a1 - hi_11390 + (u32)(unsigned long)ref_t32_data_c6144; goto L_113f0;
L_1139c:
    a3 = *(volatile u32 *)(unsigned long)(s1 + (532));
    v1 = (u32)a2 < (u32)(a3);
    if (v1 != 0) { a2 = a2 + 58; goto L_113b8; }
    goto L_113ac;
L_113ac:
    a1 = hi_113ac;
    a1 = a1 - hi_113ac + (u32)(unsigned long)ref_t32_data_c6160; goto L_1136c;
L_113b8:
    a2 = a2 << (0x2 & 31);
    a2 = s1 + a2;
    s0 = *(volatile u32 *)(unsigned long)(a2 + (44));
    if (s0 != 0) { *(volatile u8 *)(unsigned long)(s0 + (104)) = v0; goto L_113d8; }
    goto L_113cc;
L_113cc:
    a1 = hi_113cc;
    a1 = a1 - hi_113cc + (u32)(unsigned long)ref_t32_data_c618c; goto L_113f0;
L_113d8:
    v1 = *(volatile u32 *)(unsigned long)(sp + (64));
    v0 = *(volatile u32 *)(unsigned long)(s1 + (68));
    branch = (v1 == v0); a2 = *(volatile u32 *)(unsigned long)(sp + (72));
    if (branch) goto L_11408;
    goto L_113e8;
L_113e8:
    a1 = hi_113e8;
    a1 = a1 - hi_113e8 + (u32)(unsigned long)ref_t32_data_c61a4;
L_113f0:
    v0 = hi_113f0;
    v0 = v0 - hi_113f0 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11400;
L_11400:
    v0 = -22; goto L_1168c;
L_11408:
    a3 = *(volatile u32 *)(unsigned long)(s1 + (96));
    if (a2 == a3) { v0 = *(volatile u32 *)(unsigned long)(s0 + (100)); goto L_11420; }
    goto L_11414;
L_11414:
    a1 = hi_11414;
    a1 = a1 - hi_11414 + (u32)(unsigned long)ref_t32_data_c61c0; goto L_1136c;
L_11420:
    branch = (v0 == 0); s4 = *(volatile u32 *)(unsigned long)(sp + (68));
    if (branch) goto L_1143c;
    goto L_11428;
L_11428:
    a1 = hi_11428;
    a3 = *(volatile u32 *)(unsigned long)(s0 + (52));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (720));
    a1 = a1 - hi_11428 + (u32)(unsigned long)ref_t32_data_c61f8; goto L_1136c;
L_1143c:
    *(volatile u32 *)(unsigned long)(s0 + (52)) = s4;
    v0 = *(volatile u32 *)(unsigned long)(sp + (72));
    *(volatile u32 *)(unsigned long)(s0 + (56)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (32));
    *(volatile u32 *)(unsigned long)(s0 + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (36));
    *(volatile u32 *)(unsigned long)(s0 + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    *(volatile u32 *)(unsigned long)(s0 + (24)) = v0;
    v0 = 0xffffU << 16;
    v1 = v0 + 7096;
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    v0 = v0 & v1;
    *(volatile u32 *)(unsigned long)(s0 + (12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (108));
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(s0 + (92)) = v0;
    if (branch) goto L_11488;
    goto L_11480;
L_11480:
    v0 = *(volatile u32 *)(unsigned long)(sp + (104));
    *(volatile u32 *)(unsigned long)(s0 + (88)) = v0;
L_11488:
    v0 = *(volatile u32 *)(unsigned long)(sp + (100));
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(s0 + (84)) = v0;
    if (branch) goto L_1149c;
    goto L_11494;
L_11494:
    v0 = *(volatile u32 *)(unsigned long)(sp + (96));
    *(volatile u32 *)(unsigned long)(s0 + (80)) = v0;
L_1149c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (88));
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(sp + (80));
    if (branch) goto L_114d0;
    goto L_114ac;
L_114ac:
    *(volatile u32 *)(unsigned long)(s0 + (64)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (84));
    *(volatile u32 *)(unsigned long)(s0 + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    *(volatile u32 *)(unsigned long)(s0 + (72)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (92));
    *(volatile u16 *)(unsigned long)(s0 + (76)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (94));
    *(volatile u16 *)(unsigned long)(s0 + (78)) = v0;
L_114d0:
    branch = ((s32)s4 >= 0); s5 = *(volatile u32 *)(unsigned long)(s0 + (64));
    if (branch) goto L_114e4;
    goto L_114d8;
L_114d8:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_111b0 + (u32)(unsigned long)ref_t32_data_d9014);
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (68)); goto L_11544; }
    goto L_114e4;
L_114e4:
    v0 = hi_114e4;
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_114e4 + ((u32)(unsigned long)ref_mips_dma_map_ops + (0)));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (36));
    branch = (v1 == 0); s3 = v0;
    if (branch) goto L_11514;
    goto L_114f8;
L_114f8:
    a2 = *(volatile u16 *)(unsigned long)(s0 + (78));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (68));
    a3 = 2;
    a1 = s4;
    a2 = a2 * v0;
    callee = v1; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11514;
L_11514:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (78));
    a2 = *(volatile u32 *)(unsigned long)(s0 + (68));
    a2 = v0 * a2;
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_114e4 + ((u32)(unsigned long)ref_mips_dma_map_ops + (0)));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (36));
    branch = (v0 == 0); a2 = a2 >> (0x1 & 31);
    if (branch) goto L_11540;
    goto L_11530;
L_11530:
    a3 = 2;
    a1 = s5;
    callee = v0; a0 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11540;
L_11540:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (68));
L_11544:
    *(volatile u32 *)(unsigned long)(s0 + (148)) = s4;
    s4 = s1 + 48;
    *(volatile u32 *)(unsigned long)(s0 + (180)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (72));
    *(volatile u32 *)(unsigned long)(s0 + (152)) = s5;
    *(volatile u32 *)(unsigned long)(s0 + (184)) = v0;
    v0 = s0 + 140;
    *(volatile u32 *)(unsigned long)(s0 + (140)) = v0;
    *(volatile u32 *)(unsigned long)(s0 + (144)) = v0;
    v0 = 2;
    *(volatile u32 *)(unsigned long)(s0 + (100)) = v0;
    *(volatile u8 *)(unsigned long)(s0 + (104)) = v0;
    v0 = hi_11574;
    v0 = v0 - hi_11574 + (u32)(unsigned long)ref_private_mutex_lock;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11584;
L_11584:
    s3 = s1 + 724;
    v0 = hi_11588;
    a1 = sp + 112;
    v0 = v0 - hi_11588 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1159c;
L_1159c:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (540));
    v0 = s0 + 124;
    a0 = s1 + 536;
    *(volatile u32 *)(unsigned long)(s1 + (540)) = v0;
    *(volatile u32 *)(unsigned long)(s0 + (124)) = a0;
    *(volatile u32 *)(unsigned long)(s0 + (128)) = v1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    v0 = 1;
    *(volatile u32 *)(unsigned long)(s0 + (100)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (544));
    a1 = *(volatile u32 *)(unsigned long)(sp + (112));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s1 + (544)) = v0;
    v0 = hi_115d0;
    v0 = v0 - hi_115d0 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_115e0;
L_115e0:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (580));
    v0 = v0 & 0x1;
    branch = (v0 == 0); v0 = 30;
    if (branch) goto L_11604;
    goto L_115f0;
L_115f0:
    v0 = hi_115f0;
    v0 = v0 - hi_115f0 + (u32)(unsigned long)ref___enqueue_in_driver;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11600;
L_11600:
    v0 = 30;
L_11604:
    *(volatile u8 *)(unsigned long)(s0 + (104)) = v0;
    v0 = hi_11608;
    a1 = sp + 16;
    v0 = v0 - hi_11608 + (u32)(unsigned long)ref___fill_tisp_buffer;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1161c;
L_1161c:
    v0 = hi_1161c;
    v0 = v0 - hi_1161c + (u32)(unsigned long)ref_private_mutex_unlock;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1162c;
L_1162c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (808));
    a2 = 96;
    a1 = sp + 16;
    branch = (v0 == 0); a0 = s2;
    if (branch) goto L_11658;
    goto L_11640;
L_11640:
    v0 = hi_11640;
    v0 = v0 - hi_11640 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11650;
L_11650:
    v0 = 0; goto L_1168c;
L_11658:
    v0 = hi_11658;
    v0 = v0 - hi_11658 + (u32)(unsigned long)ref_private_copy_to_user;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11668;
L_11668:
    branch = (v0 == 0); v0 = 0;
    if (branch) goto L_1168c;
    goto L_11670;
L_1166c:
    v0 = 0;
L_11670:
    a1 = hi_11670;
    a1 = a1 - hi_11670 + (u32)(unsigned long)ref_t32_data_c5f98;
L_11678:
    v0 = hi_11678;
    v0 = v0 - hi_11678 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_11688;
L_11688:
    v0 = -12;
L_1168c:
    ra = *(volatile u32 *)(unsigned long)(sp + (148));
    s5 = *(volatile u32 *)(unsigned long)(sp + (144));
    s4 = *(volatile u32 *)(unsigned long)(sp + (140));
    s3 = *(volatile u32 *)(unsigned long)(sp + (136));
    s2 = *(volatile u32 *)(unsigned long)(sp + (132));
    s1 = *(volatile u32 *)(unsigned long)(sp + (128));
    s0 = *(volatile u32 *)(unsigned long)(sp + (124));
    sp = sp + 152;
    return ((u64)v1 << 32) | v0;
}
