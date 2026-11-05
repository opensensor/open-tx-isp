/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e17e0[] __asm__("t32_data_e17e0");
extern unsigned char ref___private_spin_lock_irqsave[] __asm__("__private_spin_lock_irqsave");
extern unsigned char ref_private_spin_unlock_irqrestore[] __asm__("private_spin_unlock_irqrestore");
u64 tisp_lsc_mesh_itp(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, u32 arg14, u32 arg15, u32 arg16)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_43a4c = ((u32)(unsigned long)ref_t32_data_e17e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_43a64 = ((u32)(unsigned long)ref___private_spin_lock_irqsave + 0x8000U) & 0xffff0000U;
    const u32 hi_43c28 = ((u32)(unsigned long)ref_private_spin_unlock_irqrestore + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
    stack[22] = arg4;
    stack[23] = arg5;
    stack[24] = arg6;
    stack[25] = arg7;
    stack[26] = arg8;
    stack[27] = arg9;
    stack[28] = arg10;
    stack[29] = arg11;
    stack[30] = arg12;
    stack[31] = arg13;
    stack[32] = arg14;
    stack[33] = arg15;
    stack[34] = arg16;
L_43a48:
    sp = sp + -72;
    t3 = hi_43a4c;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s8;
    s8 = a0;
    a0 = *(volatile u32 *)(unsigned long)(t3 - hi_43a4c + (u32)(unsigned long)ref_t32_data_e17e0);
    *(volatile u32 *)(unsigned long)(sp + (52)) = s5;
    s5 = *(volatile u8 *)(unsigned long)(sp + (100));
    v0 = hi_43a64;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (68)) = ra;
    s7 = a1 & 0xff;
    a0 = a0 + 16;
    a1 = sp + 16;
    v0 = v0 - hi_43a64 + (u32)(unsigned long)ref___private_spin_lock_irqsave;
    *(volatile u32 *)(unsigned long)(sp + (24)) = t3;
    s6 = a2;
    s0 = *(volatile u32 *)(unsigned long)(sp + (136));
    s4 = a3 & 0xff;
    s2 = *(volatile u8 *)(unsigned long)(sp + (92));
    s3 = *(volatile u8 *)(unsigned long)(sp + (108));
    s1 = *(volatile u8 *)(unsigned long)(sp + (116));
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_43abc;
L_43abc:
    branch = (s7 == s5); t3 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_43ae8;
    goto L_43ac4;
L_43ac4:
    v0 = (u32)s5 < (u32)(s7);
    branch = (v0 == 0); v1 = s5 - s7;
    if (branch) goto L_43adc;
    goto L_43ad0;
L_43ad0:
    v1 = s7 - s5;
    a1 = v1 & 0xff; goto L_43aec;
L_43adc:
    v1 = v1 & 0xff;
    a1 = 0; goto L_43af0;
L_43ae8:
    a1 = 0;
L_43aec:
    v1 = 0;
L_43af0:
    branch = (s4 == s3); v0 = (u32)s3 < (u32)(s4);
    if (branch) goto L_43b18;
    goto L_43af8;
L_43af8:
    branch = (v0 == 0); a3 = s3 - s4;
    if (branch) goto L_43b0c;
    goto L_43b00;
L_43b00:
    a3 = s4 - s3;
    t0 = a3 & 0xff; goto L_43b1c;
L_43b0c:
    a3 = a3 & 0xff;
    t0 = 0; goto L_43b20;
L_43b18:
    t0 = 0;
L_43b1c:
    a3 = 0;
L_43b20:
    branch = (s2 == s1); v0 = (u32)s1 < (u32)(s2);
    if (branch) goto L_43b48;
    goto L_43b28;
L_43b28:
    branch = (v0 == 0); t1 = s1 - s2;
    if (branch) goto L_43b3c;
    goto L_43b30;
L_43b30:
    t1 = s2 - s1;
    t2 = t1 & 0xff; goto L_43b4c;
L_43b3c:
    t1 = t1 & 0xff;
    t2 = 0; goto L_43b50;
L_43b48:
    t2 = 0;
L_43b4c:
    t1 = 0;
L_43b50:
    t4 = *(volatile u32 *)(unsigned long)(sp + (132));
    ra = *(volatile u32 *)(unsigned long)(sp + (96));
    t9 = *(volatile u32 *)(unsigned long)(sp + (120));
    t8 = *(volatile u32 *)(unsigned long)(sp + (104));
    t7 = *(volatile u32 *)(unsigned long)(sp + (124));
    t6 = *(volatile u32 *)(unsigned long)(sp + (88));
    s1 = *(volatile u32 *)(unsigned long)(sp + (112));
    s2 = *(volatile u32 *)(unsigned long)(sp + (128));
    t4 = t4 << (0x1 & 31);
    a0 = s8;
    a2 = s6;
    t5 = 0;
L_43b80:
    v0 = (s32)t5 < (s32)(t4);
    branch = (v0 == 0); t5 = t5 + 1;
    if (branch) goto L_43c20;
    goto L_43b8c;
L_43b8c:
    v0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = a0 + 2;
    s3 = (s32)v0 >> (v1 & 31);
    v0 = *(volatile u16 *)(unsigned long)(ra + (0));
    t9 = t9 + 2;
    ra = ra + 2;
    v0 = (s32)v0 >> (a1 & 31);
    v0 = v0 - s3;
    v0 = v0 * s0;
    a2 = a2 + 2;
    t8 = t8 + 2;
    t7 = t7 + 2;
    t6 = t6 + 2;
    s1 = s1 + 2;
    s2 = s2 + 2;
    v0 = v0 >> (0xc & 31);
    v0 = v0 + s3;
    *(volatile u16 *)(unsigned long)(t9 + (-2)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a2 + (-2));
    s3 = (s32)v0 >> (a3 & 31);
    v0 = *(volatile u16 *)(unsigned long)(t8 + (-2));
    v0 = (s32)v0 >> (t0 & 31);
    v0 = v0 - s3;
    v0 = v0 * s0;
    v0 = v0 >> (0xc & 31);
    v0 = v0 + s3;
    *(volatile u16 *)(unsigned long)(t7 + (-2)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(t6 + (-2));
    s3 = (s32)v0 >> (t1 & 31);
    v0 = *(volatile u16 *)(unsigned long)(s1 + (-2));
    v0 = (s32)v0 >> (t2 & 31);
    v0 = v0 - s3;
    v0 = v0 * s0;
    v0 = v0 >> (0xc & 31);
    v0 = v0 + s3;
    *(volatile u16 *)(unsigned long)(s2 + (-2)) = v0; goto L_43b80;
L_43c20:
    a0 = *(volatile u32 *)(unsigned long)(t3 - hi_43a4c + (u32)(unsigned long)ref_t32_data_e17e0);
    a1 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = hi_43c28;
    v0 = v0 - hi_43c28 + (u32)(unsigned long)ref_private_spin_unlock_irqrestore;
    callee = v0; a0 = a0 + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_43c38;
L_43c38:
    ra = *(volatile u32 *)(unsigned long)(sp + (68));
    s8 = *(volatile u32 *)(unsigned long)(sp + (64));
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
