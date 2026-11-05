/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dc060[] __asm__("t32_data_dc060");
extern unsigned char ref_t32_data_dc284[] __asm__("t32_data_dc284");
extern unsigned char ref_t32_data_f32f8[] __asm__("t32_data_f32f8");
extern unsigned char ref_t32_data_f32d8[] __asm__("t32_data_f32d8");
extern unsigned char ref_t32_data_f32e8[] __asm__("t32_data_f32e8");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
extern unsigned char ref_tisp_reg_write[] __asm__("tisp_reg_write");
extern unsigned char ref_t32_data_c2fd0[] __asm__("t32_data_c2fd0");
extern unsigned char ref_t32_data_cb748[] __asm__("t32_data_cb748");
extern unsigned char ref_isp_printf[] __asm__("isp_printf");
extern unsigned char ref_t32_data_e4018[] __asm__("t32_data_e4018");
u64 lib_tisp_set_csccr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_b0440 = ((u32)(unsigned long)ref_t32_data_dc060 + 0x8000U) & 0xffff0000U;
    const u32 hi_b0474 = ((u32)(unsigned long)ref_t32_data_dc284 + 0x8000U) & 0xffff0000U;
    const u32 hi_b0488 = ((u32)(unsigned long)ref_t32_data_f32f8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b049c = ((u32)(unsigned long)ref_t32_data_f32d8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b04b8 = ((u32)(unsigned long)ref_t32_data_f32e8 + 0x8000U) & 0xffff0000U;
    const u32 hi_b04e0 = ((u32)(unsigned long)ref_t32_data_dc284 + 0x8000U) & 0xffff0000U;
    const u32 hi_b04f0 = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b050c = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_b054c = ((u32)(unsigned long)ref_t32_data_c2fd0 + 0x8000U) & 0xffff0000U;
    const u32 hi_b0550 = ((u32)(unsigned long)ref_t32_data_cb748 + 0x8000U) & 0xffff0000U;
    const u32 hi_b0554 = ((u32)(unsigned long)ref_isp_printf + 0x8000U) & 0xffff0000U;
    const u32 hi_b0580 = ((u32)(unsigned long)ref_t32_data_e4018 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
L_b043c:
    sp = sp + -40;
    v0 = hi_b0440;
    v0 = v0 - hi_b0440 + (u32)(unsigned long)ref_t32_data_dc060;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    s0 = a0 & 0xff;
    v0 = s0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    v1 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = 1;
    branch = (v1 != v0); a1 = a1 & 0xff;
    if (branch) goto L_b0578;
    goto L_b0470;
L_b0470:
    branch = (a1 != 0); v0 = hi_b0474;
    if (branch) goto L_b04d4;
    goto L_b0478;
L_b0478:
    v1 = 904;
    a0 = s0 * v1;
    v0 = v0 - hi_b0474 + (u32)(unsigned long)ref_t32_data_dc284;
    s0 = s0 << (0x2 & 31);
    v1 = hi_b0488;
    v1 = v1 - hi_b0488 + (u32)(unsigned long)ref_t32_data_f32f8;
    v1 = s0 + v1;
    v0 = a0 + v0;
    *(volatile u8 *)(unsigned long)(v0 + (37)) = 0;
    v0 = hi_b049c;
    v0 = v0 - hi_b049c + (u32)(unsigned long)ref_t32_data_f32d8;
    v0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = v0 + 1;
    a0 = (a0 >> 0x0) & ((1U << 0x18) - 1);
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a0;
    v1 = hi_b04b8;
    v1 = v1 - hi_b04b8 + (u32)(unsigned long)ref_t32_data_f32e8;
    v0 = v0 + 2;
    s0 = s0 + v1;
    v0 = (v0 >> 0x0) & ((1U << 0x18) - 1);
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0; goto L_b0540;
L_b04d4:
    branch = (a1 != v1); v1 = 904;
    if (branch) goto L_b0548;
    goto L_b04dc;
L_b04dc:
    a0 = s0 * v1;
    v0 = hi_b04e0;
    v0 = v0 - hi_b04e0 + (u32)(unsigned long)ref_t32_data_dc284;
    v0 = a0 + v0;
    *(volatile u8 *)(unsigned long)(v0 + (37)) = a1;
    v0 = hi_b04f0;
    v1 = *(volatile u8 *)(unsigned long)(v0 - hi_b04f0 + (u32)(unsigned long)ref_t32_data_d03a0);
    s2 = v0;
    branch = (v1 != 0); a1 = 777;
    if (branch) goto L_b050c;
    goto L_b0504;
L_b0504:
    a1 = 0x1U << 16;
    a1 = a1 + 16468;
L_b050c:
    s1 = hi_b050c;
    a2 = 0;
    s1 = s1 - hi_b050c + (u32)(unsigned long)ref_tisp_reg_write;
    callee = s1; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b0520;
L_b0520:
    v0 = *(volatile u8 *)(unsigned long)(s2 - hi_b04f0 + (u32)(unsigned long)ref_t32_data_d03a0);
    branch = (v0 != 0); a1 = 771;
    if (branch) goto L_b0534;
    goto L_b052c;
L_b052c:
    a1 = 0x1U << 16;
    a1 = a1 + 16400;
L_b0534:
    a2 = -1;
    callee = s1; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b0540;
L_b0540:
    v0 = 0; goto L_b0590;
L_b0548:
    *(volatile u32 *)(unsigned long)(sp + (16)) = a1;
    a2 = hi_b054c;
    a1 = hi_b0550;
    v0 = hi_b0554;
    a3 = 298;
    a2 = a2 - hi_b054c + (u32)(unsigned long)ref_t32_data_c2fd0;
    a1 = a1 - hi_b0550 + (u32)(unsigned long)ref_t32_data_cb748;
    v0 = v0 - hi_b0554 + (u32)(unsigned long)ref_isp_printf;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_b0570;
L_b0570:
    v0 = -1; goto L_b0590;
L_b0578:
    branch = (v1 != 0); v0 = 0;
    if (branch) goto L_b0590;
    goto L_b0580;
L_b0580:
    v1 = hi_b0580;
    v1 = v1 - hi_b0580 + (u32)(unsigned long)ref_t32_data_e4018;
    s0 = s0 + v1;
    *(volatile u8 *)(unsigned long)(s0 + (0)) = a1;
L_b0590:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
