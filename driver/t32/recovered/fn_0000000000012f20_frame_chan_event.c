/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_be4c0[] __asm__("t32_data_be4c0");
extern unsigned char ref_t32_data_c66f8[] __asm__("t32_data_c66f8");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_dump_msca_regs[] __asm__("dump_msca_regs");
extern unsigned char ref___private_spin_lock_irqsave[] __asm__("__private_spin_lock_irqsave");
extern unsigned char ref_t32_data_c6714[] __asm__("t32_data_c6714");
extern unsigned char ref_t32_data_c673c[] __asm__("t32_data_c673c");
extern unsigned char ref_t32_data_c6750[] __asm__("t32_data_c6750");
extern unsigned char ref_t32_data_d9a54[] __asm__("t32_data_d9a54");
extern unsigned char ref_t32_data_f3774[] __asm__("t32_data_f3774");
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_private_getrawmonotonic[] __asm__("private_getrawmonotonic");
extern unsigned char ref_private_wake_up[] __asm__("private_wake_up");
extern unsigned char ref_t32_data_d9008[] __asm__("t32_data_d9008");
extern unsigned char ref_t32_data_d9004[] __asm__("t32_data_d9004");
extern unsigned char ref_up[] __asm__("up");
extern unsigned char ref_private_complete[] __asm__("private_complete");
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_d9a84[] __asm__("t32_data_d9a84");
extern unsigned char ref_sprintf[] __asm__("sprintf");
extern unsigned char ref_t32_data_c6770[] __asm__("t32_data_c6770");
extern unsigned char ref_t32_data_c6794[] __asm__("t32_data_c6794");
extern unsigned char ref_t32_data_d9874[] __asm__("t32_data_d9874");
extern unsigned char ref_VPU_Encoder_SendFrame[] __asm__("VPU_Encoder_SendFrame");
extern unsigned char ref_t32_data_f3848[] __asm__("t32_data_f3848");
extern unsigned char ref_t32_data_c67a8[] __asm__("t32_data_c67a8");
extern unsigned char ref_t32_data_d9bd4[] __asm__("t32_data_d9bd4");
extern unsigned char ref_t32_data_c67e0[] __asm__("t32_data_c67e0");
extern unsigned char ref_private_spin_unlock_irqrestore[] __asm__("private_spin_unlock_irqrestore");
u64 frame_chan_event(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[104] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_12f88 = ((u32)(unsigned long)ref_t32_data_be4c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_12f8c = ((u32)(unsigned long)ref_t32_data_c66f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_12f90 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_12fac = ((u32)(unsigned long)ref_dump_msca_regs + 0x8000U) & 0xffff0000U;
    const u32 hi_12fe0 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_13050 = ((u32)(unsigned long)ref_t32_data_c6714 + 0x8000U) & 0xffff0000U;
    const u32 hi_13054 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_13070 = ((u32)(unsigned long)ref_t32_data_c673c + 0x8000U) & 0xffff0000U;
    const u32 hi_130a8 = ((u32)(unsigned long)ref_t32_data_c6750 + 0x8000U) & 0xffff0000U;
    const u32 hi_130b8 = ((u32)(unsigned long)ref_dump_msca_regs + 0x8000U) & 0xffff0000U;
    const u32 hi_130cc = ((u32)(unsigned long)ref_t32_data_d9a54 + 0x8000U) & 0xffff0000U;
    const u32 hi_130d4 = ((u32)(unsigned long)ref_t32_data_f3774 + 0x8000U) & 0xffff0000U;
    const u32 hi_13134 = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_13220 = ((u32)(unsigned long)ref_private_getrawmonotonic + 0x8000U) & 0xffff0000U;
    const u32 hi_132c8 = ((u32)(unsigned long)ref_private_wake_up + 0x8000U) & 0xffff0000U;
    const u32 hi_13248 = ((u32)(unsigned long)ref_t32_data_d9008 + 0x8000U) & 0xffff0000U;
    const u32 hi_132e0 = ((u32)(unsigned long)ref_t32_data_d9004 + 0x8000U) & 0xffff0000U;
    const u32 hi_132f0 = (((u32)(unsigned long)ref_up + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_13300 = ((u32)(unsigned long)ref_private_complete + 0x8000U) & 0xffff0000U;
    const u32 hi_13320 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_13348 = ((u32)(unsigned long)ref_t32_data_d9a84 + 0x8000U) & 0xffff0000U;
    const u32 hi_133a4 = (((u32)(unsigned long)ref_sprintf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_133a0 = ((u32)(unsigned long)ref_t32_data_c6770 + 0x8000U) & 0xffff0000U;
    const u32 hi_130dc = ((u32)(unsigned long)ref_t32_data_be4c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_133c0 = ((u32)(unsigned long)ref_t32_data_c6794 + 0x8000U) & 0xffff0000U;
    const u32 hi_133e4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_133f4 = ((u32)(unsigned long)ref_t32_data_d9874 + 0x8000U) & 0xffff0000U;
    const u32 hi_13408 = (((u32)(unsigned long)ref_VPU_Encoder_SendFrame + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_13418 = ((u32)(unsigned long)ref_t32_data_f3848 + 0x8000U) & 0xffff0000U;
    const u32 hi_134a4 = (((u32)(unsigned long)ref_sprintf + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_134a0 = ((u32)(unsigned long)ref_t32_data_c6770 + 0x8000U) & 0xffff0000U;
    const u32 hi_134c0 = ((u32)(unsigned long)ref_t32_data_c6794 + 0x8000U) & 0xffff0000U;
    const u32 hi_134e4 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_13500 = ((u32)(unsigned long)ref_t32_data_c67a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_13528 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_13538 = ((u32)(unsigned long)ref_dump_msca_regs + 0x8000U) & 0xffff0000U;
    const u32 hi_13580 = ((u32)(unsigned long)ref_t32_data_d9bd4 + 0x8000U) & 0xffff0000U;
    const u32 hi_135ac = ((u32)(unsigned long)ref_t32_data_c67e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_135b0 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_135e0 = ((u32)(unsigned long)ref_t32_data_d9bd4 + 0x8000U) & 0xffff0000U;
    const u32 hi_135f4 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    const u32 hi_131f8 = ((u32)(unsigned long)ref_private_getrawmonotonic + 0x8000U) & 0xffff0000U;
    const u32 hi_132ec = ((u32)(unsigned long)ref_private_complete + 0x8000U) & 0xffff0000U;
    const u32 hi_13404 = ((u32)(unsigned long)ref_t32_data_f3848 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[40];
L_12f20:
    branch = (a0 == 0); v0 = -22;
    if (branch) goto L_13640;
    goto L_12f28;
L_12f28:
    v1 = (u32)a0 < (u32)(-4095);
    branch = (v1 == 0); ;
    if (branch) goto L_13640;
    goto L_12f34;
L_12f34:
    v0 = 0x300U << 16;
    v0 = v0 + 6;
    branch = (a1 != v0); ;
    if (branch) goto L_13638;
    goto L_12f44;
L_12f44:
    sp = sp + -160;
    *(volatile u32 *)(unsigned long)(sp + (120)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (156)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (152)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (148)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (144)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (140)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (136)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (132)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (128)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (124)) = s1;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    s0 = a2;
    a0 = *(volatile u8 *)(unsigned long)(a0 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (288));
    branch = (a2 != 0); *(volatile u32 *)(unsigned long)(sp + (104)) = 0;
    if (branch) goto L_12fc4;
    goto L_12f88;
L_12f88:
    a2 = hi_12f88;
    a1 = hi_12f8c;
    v0 = hi_12f90;
    a3 = 70;
    a2 = a2 - hi_12f88 + (u32)(unsigned long)ref_t32_data_be4c0;
    a1 = a1 - hi_12f8c + (u32)(unsigned long)ref_t32_data_c66f8;
    v0 = v0 - hi_12f90 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12fac;
L_12fac:
    v0 = hi_12fac;
    v0 = v0 - hi_12fac + (u32)(unsigned long)ref_dump_msca_regs;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12fbc;
L_12fbc:
    ra = *(volatile u32 *)(unsigned long)(sp + (156)); goto L_13608;
L_12fc4:
    v1 = 816;
    a1 = a0 * v1;
    s1 = 0;
    s8 = a1 + v0;
    v0 = s8 + 724;
    *(volatile u32 *)(unsigned long)(sp + (112)) = v0;
    a0 = v0;
    v0 = hi_12fe0;
    v0 = v0 - hi_12fe0 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    callee = v0; a1 = sp + 104;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_12ff0;
L_12ff0:
    s2 = *(volatile u32 *)(unsigned long)(s8 + (536));
    s4 = s8 + 536;
    s2 = s2 + -124;
L_12ffc:
    v0 = s2 + 124;
    branch = (s4 == v0); ;
    if (branch) goto L_13044;
    goto L_13008;
L_13008:
    a0 = *(volatile u32 *)(unsigned long)(s2 + (52));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (8));
    if (a0 != v0) { s2 = *(volatile u32 *)(unsigned long)(s2 + (124)); goto L_13034; }
    goto L_13018;
L_13018:
    v0 = 101;
    *(volatile u8 *)(unsigned long)(s2 + (104)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (32));
    branch = (s1 == 0); *(volatile u32 *)(unsigned long)(s2 + (120)) = v0;
    if (branch) goto L_130c8;
    goto L_1302c;
L_1302c:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (720)); goto L_13050;
L_13034:
    s1 = s1 + 1;
    s1 = s1 & 0xff;
    s2 = s2 + -124; goto L_12ffc;
L_13044:
    branch = (s1 == 0); s2 = 0;
    if (branch) goto L_13570;
    goto L_1304c;
L_1304c:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (720));
L_13050:
    a1 = hi_13050;
    s5 = hi_13054;
    a3 = s1;
    a1 = a1 - hi_13050 + (u32)(unsigned long)ref_t32_data_c6714;
    s5 = s5 - hi_13054 + (u32)(unsigned long)ref_isp_printf;
    callee = s5; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1306c;
L_1306c:
    s3 = *(volatile u32 *)(unsigned long)(s8 + (536));
    s6 = hi_13070;
    s6 = s6 - hi_13070 + (u32)(unsigned long)ref_t32_data_c673c;
    s3 = s3 + -124;
L_1307c:
    v0 = s3 + 124;
    branch = (s4 == v0); a1 = s6;
    if (branch) goto L_130a0;
    goto L_13088;
L_13088:
    a2 = *(volatile u32 *)(unsigned long)(s3 + (52));
    callee = s5; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13094;
L_13094:
    s3 = *(volatile u32 *)(unsigned long)(s3 + (124));
    s3 = s3 + -124; goto L_1307c;
L_130a0:
    a3 = *(volatile u32 *)(unsigned long)(s0 + (36));
    a2 = *(volatile u32 *)(unsigned long)(s0 + (8));
    a1 = hi_130a8;
    a1 = a1 - hi_130a8 + (u32)(unsigned long)ref_t32_data_c6750;
    callee = s5; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_130b8;
L_130b8:
    v0 = hi_130b8;
    v0 = v0 - hi_130b8 + (u32)(unsigned long)ref_dump_msca_regs;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_130c8;
L_130c8:
    branch = (s2 == 0); s6 = hi_130cc;
    if (branch) goto L_13570;
    goto L_130d0;
L_130d0:
    v0 = s6 - hi_130cc + (u32)(unsigned long)ref_t32_data_d9a54;
    s7 = hi_130d4;
    s2 = 0;
    s5 = hi_130dc;
    *(volatile u32 *)(unsigned long)(sp + (116)) = v0;
    s7 = s7 - hi_130d4 + (u32)(unsigned long)ref_t32_data_f3774;
    a1 = *(volatile u32 *)(unsigned long)(s0 + (36));
L_130ec:
    s6 = *(volatile u32 *)(unsigned long)(s8 + (536));
    s4 = s1 ^ s2;
    v0 = a1 - s1;
    v0 = v0 + s2;
    if (s4 != 0) a1 = v0;
    a0 = s6 + -124;
    branch = (a0 == 0); s4 = a1;
    if (branch) goto L_134fc;
    goto L_1310c;
L_1310c:
    a1 = *(volatile u32 *)(unsigned long)(s6 + (-24));
    v0 = 3;
    if (a1 != v0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (720)); goto L_13500; }
    goto L_1311c;
L_1311c:
    v0 = 102;
    *(volatile u8 *)(unsigned long)(s6 + (-20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (24));
    a2 = 1;
    a0 = *(volatile u32 *)(unsigned long)(s6 + (-32));
    *(volatile u32 *)(unsigned long)(s6 + (-64)) = v0;
    v0 = hi_13134;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_13134 + (u32)(unsigned long)ref_t32_data_d9014);
    if (v0 != a2) { a2 = 2; goto L_13158; }
    goto L_13144;
L_13144:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (720));
    branch = (v0 == 0); ;
    if (branch) goto L_131c4;
    goto L_13150;
L_13150:
    ; goto L_131ec;
L_13158:
    branch = (v0 != a2); ;
    if (branch) goto L_1317c;
    goto L_13160;
L_13160:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (720));
    branch = (v0 == 0); ;
    if (branch) goto L_131c4;
    goto L_1316c;
L_1316c:
    branch = (v0 != a1); ;
    if (branch) goto L_131ec;
    goto L_13174;
L_13174:
    ; goto L_131c4;
L_1317c:
    branch = (v0 != a1); a1 = 4;
    if (branch) goto L_1319c;
    goto L_13184;
L_13184:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (720));
    v0 = (u32)a1 < (u32)(7);
    branch = (v0 == 0); v0 = 73;
    if (branch) goto L_131ec;
    goto L_13194;
L_13194:
    v0 = v0 >> (a1 & 31); goto L_131b8;
L_1319c:
    branch = (v0 != a1); ;
    if (branch) goto L_131ec;
    goto L_131a4;
L_131a4:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (720));
    v0 = (u32)a1 < (u32)(10);
    branch = (v0 == 0); v0 = 585;
    if (branch) goto L_131ec;
    goto L_131b4;
L_131b4:
    v0 = v0 >> (a1 & 31);
L_131b8:
    v0 = v0 & 0x1;
    branch = (v0 == 0); ;
    if (branch) goto L_131ec;
    goto L_131c4;
L_131c4:
    branch = (a0 == 0); v0 = 4;
    if (branch) goto L_131dc;
    goto L_131cc;
L_131cc:
    branch = (a0 != v0); v0 = 3;
    if (branch) goto L_131ec;
    goto L_131d4;
L_131d4:
    *(volatile u16 *)(unsigned long)(s6 + (-8)) = v0; goto L_131ec;
L_131dc:
    v0 = *(volatile u32 *)(unsigned long)(s6 + (-36));
    v0 = v0 | 0x3;
    *(volatile u32 *)(unsigned long)(s6 + (-36)) = v0; goto L_13208;
L_131ec:
    branch = (a0 == 0); v0 = 4;
    if (branch) goto L_13208;
    goto L_131f4;
L_131f4:
    branch = (a0 != v0); v0 = hi_131f8;
    if (branch) goto L_13224;
    goto L_131fc;
L_131fc:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (28));
    *(volatile u8 *)(unsigned long)(s6 + (-6)) = v0; goto L_13220;
L_13208:
    a0 = *(volatile u16 *)(unsigned long)(s6 + (-36));
    *(volatile u32 *)(unsigned long)(s6 + (-36)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (28));
    v0 = v0 << (0x10 & 31);
    v0 = v0 | a0;
    *(volatile u32 *)(unsigned long)(s6 + (-36)) = v0;
L_13220:
    v0 = hi_13220;
L_13224:
    v0 = v0 - hi_13220 + (u32)(unsigned long)ref_private_getrawmonotonic;
    callee = v0; a0 = sp + 96;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13230;
L_13230:
    v0 = *(volatile u32 *)(unsigned long)(s6 + (-12));
    a0 = 1000;
    a1 = s8 + 548;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s6 + (-12)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (96));
    s3 = hi_13248;
    *(volatile u32 *)(unsigned long)(s6 + (-104)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (100));
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s6 + (-100)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (48));
    *(volatile u32 *)(unsigned long)(s6 + (-80)) = s4;
L_13268:
    v0 = v0 & 0xf;
    *(volatile u32 *)(unsigned long)(s6 + (-44)) = v0;
    v0 = 4;
    *(volatile u32 *)(unsigned long)(s6 + (-24)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (552));
    v0 = s6 + 8;
    *(volatile u32 *)(unsigned long)(s8 + (552)) = v0;
    *(volatile u32 *)(unsigned long)(s6 + (12)) = a0;
    *(volatile u32 *)(unsigned long)(s6 + (8)) = a1;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (556));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (556)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s6 + (4));
    a0 = *(volatile u32 *)(unsigned long)(s6 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (4)) = v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    v0 = 256;
    *(volatile u32 *)(unsigned long)(s6 + (0)) = v0;
    v0 = 512;
    *(volatile u32 *)(unsigned long)(s6 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (544));
    v0 = v0 + -1;
    *(volatile u32 *)(unsigned long)(s8 + (544)) = v0;
    v0 = hi_132c8;
    v0 = v0 - hi_132c8 + (u32)(unsigned long)ref_private_wake_up;
    callee = v0; a0 = s8 + 560;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_132d8;
L_132d8:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_13248 + (u32)(unsigned long)ref_t32_data_d9008);
    branch = (v0 == 0); v0 = hi_132e0;
    if (branch) goto L_13300;
    goto L_132e4;
L_132e4:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_132e0 + (u32)(unsigned long)ref_t32_data_d9004);
    if (v0 != 0) { v0 = hi_132ec; goto L_13304; }
    goto L_132f0;
L_132f0:
    v0 = hi_132f0;
    a0 = s8 + 752;
    v0 = v0 - hi_132f0 + ((u32)(unsigned long)ref_up + (0)); goto L_1330c;
L_13300:
    v0 = hi_13300;
L_13304:
    a0 = s8 + 740;
    v0 = v0 - hi_13300 + (u32)(unsigned long)ref_private_complete;
L_1330c:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13314;
L_13314:
    v0 = *(volatile u32 *)(unsigned long)(s3 - hi_13248 + (u32)(unsigned long)ref_t32_data_d9008);
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(s8 + (764)) = s4;
    if (branch) goto L_13554;
    goto L_13320;
L_13320:
    v0 = hi_13320;
    a0 = sp + 36;
    a2 = 60;
    a1 = 0;
    v0 = v0 - hi_13320 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (32)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_1333c;
L_1333c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (808));
    a0 = 1;
    branch = (v0 != a0); a0 = hi_13348;
    if (branch) goto L_1343c;
    goto L_1334c;
L_1334c:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (720));
    a0 = a0 - hi_13348 + (u32)(unsigned long)ref_t32_data_d9a84;
    v0 = a2 << (0x2 & 31);
    a0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a1 = v0 + 1;
    v0 = (s32)v0 < (s32)(11);
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(a0 + (0)) = a1;
    if (branch) goto L_133f4;
    goto L_13370;
L_13370:
    a0 = *(volatile u32 *)(unsigned long)(s6 + (-104));
    v0 = 0xfU << 16;
    v0 = v0 + 16960;
    v1 = a0 * v0;
    a1 = *(volatile u32 *)(unsigned long)(s6 + (-100));
    a3 = *(volatile u32 *)(unsigned long)(s6 + (-124));
    s3 = sp + 32;
    a0 = s3;
    v0 = v1 + a1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = (s32)v0 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    a1 = hi_133a0;
    v0 = hi_133a4;
    v0 = v0 - hi_133a4 + ((u32)(unsigned long)ref_sprintf + (0));
    callee = v0; a1 = a1 - hi_133a0 + (u32)(unsigned long)ref_t32_data_c6770;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_133b4;
L_133b4:
    v0 = 0xb000U << 16;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8312));
    a0 = 24000;
    a1 = hi_133c0;
    v0 = v0 << (0xa & 31);
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    a3 = 188;
    a2 = s5 - hi_130dc + (u32)(unsigned long)ref_t32_data_be4c0;
    a1 = a1 - hi_133c0 + (u32)(unsigned long)ref_t32_data_c6794;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = hi_133e4;
    v0 = v0 - hi_133e4 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_133f4;
L_133f4:
    v0 = hi_133f4;
    a0 = *(volatile u32 *)(unsigned long)(v0 - hi_133f4 + (u32)(unsigned long)ref_t32_data_d9874);
    v0 = 1;
    branch = (a0 != v0); v0 = hi_13404;
    if (branch) goto L_1341c;
    goto L_13408;
L_13408:
    v0 = hi_13408;
    v0 = v0 - hi_13408 + ((u32)(unsigned long)ref_VPU_Encoder_SendFrame + (0));
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(s8 + (720));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13418;
L_13418:
    v0 = hi_13418;
L_1341c:
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_13418 + (u32)(unsigned long)ref_t32_data_f3848);
    if (v0 == 0) { s2 = s2 + 1; goto L_13558; }
    goto L_13428;
L_13428:
    a1 = *(volatile u32 *)(unsigned long)(s6 + (-124));
    callee = v0; a0 = *(volatile u32 *)(unsigned long)(s8 + (720));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13434;
L_13434:
    s2 = s2 + 1; goto L_13558;
L_1343c:
    if (v0 != 0) { s2 = s2 + 1; goto L_13558; }
    goto L_13444;
L_13444:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (720));
    v0 = *(volatile u32 *)(unsigned long)(sp + (116));
    a0 = a2 << (0x2 & 31);
    a1 = a0 + v0;
    a0 = a0 + s7;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a3 = v0 + 1;
    v0 = (u32)v0 < (u32)(a0);
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(a1 + (0)) = a3;
    if (branch) goto L_13554;
    goto L_13470;
L_13470:
    a0 = *(volatile u32 *)(unsigned long)(s6 + (-104));
    v0 = 0xfU << 16;
    v0 = v0 + 16960;
    v1 = a0 * v0;
    a1 = *(volatile u32 *)(unsigned long)(s6 + (-100));
    a3 = *(volatile u32 *)(unsigned long)(s6 + (-124));
    s3 = sp + 32;
    a0 = s3;
    v0 = v1 + a1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = (s32)v0 >> (0x1f & 31);
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    a1 = hi_134a0;
    v0 = hi_134a4;
    v0 = v0 - hi_134a4 + ((u32)(unsigned long)ref_sprintf + (0));
    callee = v0; a1 = a1 - hi_134a0 + (u32)(unsigned long)ref_t32_data_c6770;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_134b4;
L_134b4:
    v0 = 0xb000U << 16;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8312));
    a0 = 24000;
    a1 = hi_134c0;
    v0 = v0 << (0xa & 31);
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    *(volatile u32 *)(unsigned long)(sp + (16)) = s3;
    a3 = 199;
    a2 = s5 - hi_130dc + (u32)(unsigned long)ref_t32_data_be4c0;
    a1 = a1 - hi_134c0 + (u32)(unsigned long)ref_t32_data_c6794;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = hi_134e4;
    v0 = v0 - hi_134e4 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_134f4;
L_134f4:
    s2 = s2 + 1; goto L_13558;
L_134fc:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (720));
L_13500:
    a1 = hi_13500;
    a3 = 205;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s6 + (-24));
    a2 = s5 - hi_130dc + (u32)(unsigned long)ref_t32_data_be4c0;
    a1 = a1 - hi_13500 + (u32)(unsigned long)ref_t32_data_c67a8;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s6 + (-72));
    *(volatile u32 *)(unsigned long)(sp + (16)) = a0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = hi_13528;
    v0 = v0 - hi_13528 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13538;
L_13538:
    v0 = hi_13538;
    v0 = v0 - hi_13538 + (u32)(unsigned long)ref_dump_msca_regs;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13548;
L_13548:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (768));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (768)) = v0;
L_13554:
    s2 = s2 + 1;
L_13558:
    s2 = s2 & 0xff;
    v0 = (u32)s1 < (u32)(s2);
    if (v0 == 0) { a1 = *(volatile u32 *)(unsigned long)(s0 + (36)); goto L_130ec; }
    goto L_13568;
L_13568:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (720)); goto L_135d4;
L_13570:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (808));
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (804)); goto L_135c8; }
    goto L_1357c;
L_1357c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (720));
    a0 = hi_13580;
    a0 = a0 - hi_13580 + (u32)(unsigned long)ref_t32_data_d9bd4;
    a1 = v0 << (0x2 & 31);
    a0 = a1 + a0;
    a3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (36));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (24)) = a0;
    a2 = *(volatile u32 *)(unsigned long)(s0 + (8));
    a1 = hi_135ac;
    v0 = hi_135b0;
    a1 = a1 - hi_135ac + (u32)(unsigned long)ref_t32_data_c67e0;
    v0 = v0 - hi_135b0 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_135c4;
L_135c4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (804));
L_135c8:
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (804)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (720));
L_135d4:
    a1 = *(volatile u32 *)(unsigned long)(sp + (104));
    a0 = *(volatile u32 *)(unsigned long)(sp + (112));
    v1 = v0 << (0x2 & 31);
    v0 = hi_135e0;
    v0 = v0 - hi_135e0 + (u32)(unsigned long)ref_t32_data_d9bd4;
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (8));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = hi_135f4;
    v0 = v0 - hi_135f4 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_13604;
L_13604:
    ra = *(volatile u32 *)(unsigned long)(sp + (156));
L_13608:
    s8 = *(volatile u32 *)(unsigned long)(sp + (152));
    s7 = *(volatile u32 *)(unsigned long)(sp + (148));
    s6 = *(volatile u32 *)(unsigned long)(sp + (144));
    s5 = *(volatile u32 *)(unsigned long)(sp + (140));
    s4 = *(volatile u32 *)(unsigned long)(sp + (136));
    s3 = *(volatile u32 *)(unsigned long)(sp + (132));
    s2 = *(volatile u32 *)(unsigned long)(sp + (128));
    s1 = *(volatile u32 *)(unsigned long)(sp + (124));
    s0 = *(volatile u32 *)(unsigned long)(sp + (120));
    v0 = 0;
    sp = sp + 160; goto L_13640;
L_13638:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
L_13640:
    ;
    return ((u64)v1 << 32) | v0;
}
