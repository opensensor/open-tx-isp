/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d9014[] __asm__("t32_data_d9014");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_be3b4[] __asm__("t32_data_be3b4");
extern unsigned char ref_t32_data_c537c[] __asm__("t32_data_c537c");
extern unsigned char ref_ivdc_core_ops_init[] __asm__("ivdc_core_ops_init");
extern unsigned char ref_t32_data_d98f4[] __asm__("t32_data_d98f4");
extern unsigned char ref_t32_data_d98ac[] __asm__("t32_data_d98ac");
extern unsigned char ref_t32_data_d98f0[] __asm__("t32_data_d98f0");
extern unsigned char ref_t32_data_d98a8[] __asm__("t32_data_d98a8");
extern unsigned char ref_t32_data_d98ec[] __asm__("t32_data_d98ec");
extern unsigned char ref_t32_data_d98a4[] __asm__("t32_data_d98a4");
extern unsigned char ref_t32_data_d98e8[] __asm__("t32_data_d98e8");
extern unsigned char ref_t32_data_c5bfc[] __asm__("t32_data_c5bfc");
extern unsigned char ref_t32_data_d98a0[] __asm__("t32_data_d98a0");
u64 ivdc_suspend_module(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_eaac = ((u32)(unsigned long)ref_t32_data_d9014 + 0x8000U) & 0xffff0000U;
    const u32 hi_eab8 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_eabc = ((u32)(unsigned long)ref_t32_data_be3b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_ead4 = ((u32)(unsigned long)ref_t32_data_c537c + 0x8000U) & 0xffff0000U;
    const u32 hi_ead0 = ((u32)(unsigned long)ref_ivdc_core_ops_init + 0x8000U) & 0xffff0000U;
    const u32 hi_eb0c = ((u32)(unsigned long)ref_t32_data_d98f4 + 0x8000U) & 0xffff0000U;
    const u32 hi_eb14 = ((u32)(unsigned long)ref_t32_data_d98ac + 0x8000U) & 0xffff0000U;
    const u32 hi_eb20 = ((u32)(unsigned long)ref_t32_data_d98f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_eb28 = ((u32)(unsigned long)ref_t32_data_d98a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_eb34 = ((u32)(unsigned long)ref_t32_data_d98ec + 0x8000U) & 0xffff0000U;
    const u32 hi_eb3c = ((u32)(unsigned long)ref_t32_data_d98a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_eb48 = ((u32)(unsigned long)ref_t32_data_d98e8 + 0x8000U) & 0xffff0000U;
    const u32 hi_eb18 = ((u32)(unsigned long)ref_t32_data_c5bfc + 0x8000U) & 0xffff0000U;
    const u32 hi_eb54 = ((u32)(unsigned long)ref_t32_data_d98a0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    branch = (a0 == 0); s0 = 0;
    if (branch) goto L_eaac;
    goto L_eaa0;
L_eaa0:
    v0 = (u32)a0 < (u32)(-4095);
    if (v0 != 0) { s0 = *(volatile u32 *)(unsigned long)(a0 + (280)); goto L_eaac; }
    goto L_eaac;
L_eaac:
    v0 = hi_eaac;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_eaac + (u32)(unsigned long)ref_t32_data_d9014);
    branch = (v0 == 0); s1 = hi_eab8;
    if (branch) goto L_eb68;
    goto L_eabc;
L_eabc:
    s2 = hi_eabc;
    branch = (s0 == 0); s1 = s1 - hi_eab8 + (u32)(unsigned long)ref_isp_printf;
    if (branch) goto L_ead4;
    goto L_eac8;
L_eac8:
    v0 = (u32)s0 < (u32)(-4095);
    if (v0 != 0) { v0 = hi_ead0; goto L_eaf4; }
    goto L_ead4;
L_ead4:
    a1 = hi_ead4;
    a3 = 686;
    a2 = s2 - hi_eabc + (u32)(unsigned long)ref_t32_data_be3b4;
    a1 = a1 - hi_ead4 + (u32)(unsigned long)ref_t32_data_c537c;
    callee = s1; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_eaec;
L_eaec:
    v0 = -22; goto L_eb68;
L_eaf4:
    a1 = sp + 16;
    v0 = v0 - hi_ead0 + (u32)(unsigned long)ref_ivdc_core_ops_init;
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_eb04;
L_eb04:
    v0 = 1;
    *(volatile u32 *)(unsigned long)(s0 + (444)) = v0;
    v0 = hi_eb0c;
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_eb0c + (u32)(unsigned long)ref_t32_data_d98f4);
    v0 = hi_eb14;
    a1 = hi_eb18;
    *(volatile u32 *)(unsigned long)(v0 - hi_eb14 + (u32)(unsigned long)ref_t32_data_d98ac) = v1;
    v0 = hi_eb20;
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_eb20 + (u32)(unsigned long)ref_t32_data_d98f0);
    v0 = hi_eb28;
    a3 = 698;
    *(volatile u32 *)(unsigned long)(v0 - hi_eb28 + (u32)(unsigned long)ref_t32_data_d98a8) = v1;
    v0 = hi_eb34;
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_eb34 + (u32)(unsigned long)ref_t32_data_d98ec);
    v0 = hi_eb3c;
    a2 = s2 - hi_eabc + (u32)(unsigned long)ref_t32_data_be3b4;
    *(volatile u32 *)(unsigned long)(v0 - hi_eb3c + (u32)(unsigned long)ref_t32_data_d98a4) = v1;
    v0 = hi_eb48;
    v1 = *(volatile u32 *)(unsigned long)(v0 - hi_eb48 + (u32)(unsigned long)ref_t32_data_d98e8);
    a1 = a1 - hi_eb18 + (u32)(unsigned long)ref_t32_data_c5bfc;
    v0 = hi_eb54;
    a0 = 0;
    callee = s1; *(volatile u32 *)(unsigned long)(v0 - hi_eb54 + (u32)(unsigned long)ref_t32_data_d98a0) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_eb64;
L_eb64:
    v0 = 0;
L_eb68:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
