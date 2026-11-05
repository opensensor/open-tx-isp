/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dc284[] __asm__("t32_data_dc284");
extern unsigned char ref_t32_data_bf3b8[] __asm__("t32_data_bf3b8");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c8690[] __asm__("t32_data_c8690");
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
u64 tisp_ae_api_set_exp_list(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_34d08 = ((u32)(unsigned long)ref_t32_data_dc284 + 0x8000U) & 0xffff0000U;
    const u32 hi_34d28 = ((u32)(unsigned long)ref_t32_data_bf3b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_34d30 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_34d2c = ((u32)(unsigned long)ref_t32_data_c8690 + 0x8000U) & 0xffff0000U;
    const u32 hi_34d20 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_34df0 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[6];
L_34d00:
    v1 = 904;
    a3 = a0 * v1;
    v0 = hi_34d08;
    v0 = v0 - hi_34d08 + (u32)(unsigned long)ref_t32_data_dc284;
    v0 = a3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (900));
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 != 0); v0 = hi_34d20;
    if (branch) goto L_34d5c;
    goto L_34d24;
L_34d24:
    sp = sp + -24;
    a1 = hi_34d28;
    a0 = hi_34d2c;
    v0 = hi_34d30;
    a2 = 5282;
    *(volatile u32 *)(unsigned long)(sp + (20)) = ra;
    a1 = a1 - hi_34d28 + (u32)(unsigned long)ref_t32_data_bf3b8;
    v0 = v0 - hi_34d30 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_34d2c + (u32)(unsigned long)ref_t32_data_c8690;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_34d4c;
L_34d4c:
    ra = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = 0;
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
L_34d5c:
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_34d20 + (u32)(unsigned long)ref_t32_data_e15a8;
    v0 = a0 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (1740)) = a1;
    v0 = 1;
    branch = (a1 != v0); ;
    if (branch) goto L_34e08;
    goto L_34d80;
L_34d80:
    t0 = 65;
L_34d84:
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u32 *)(unsigned long)(a2 + (0));
    a1 = v0 + 143;
    a1 = a1 << (0x2 & 31);
    a1 = a3 + a1;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = t1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u32 *)(unsigned long)(a2 + (4));
    a1 = v0 + 144;
    a1 = a1 << (0x2 & 31);
    a1 = a3 + a1;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = t1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u32 *)(unsigned long)(a2 + (8));
    a1 = v0 + 145;
    a1 = a1 << (0x2 & 31);
    a1 = a3 + a1;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = t1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u32 *)(unsigned long)(a2 + (12));
    a1 = v0 + 146;
    a1 = a1 << (0x2 & 31);
    a1 = a3 + a1;
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = t1;
    branch = (v0 != t0); a2 = a2 + 20;
    if (branch) goto L_34d84;
    goto L_34df0;
L_34df0:
    v0 = hi_34df0;
    v0 = v0 - hi_34df0 + (u32)(unsigned long)ref_t32_data_e1588;
    a0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = 1;
    *(volatile u8 *)(unsigned long)(v0 + (1285)) = v1;
L_34e08:
    v0 = 0;
    return ((u64)v1 << 32) | v0;
}
