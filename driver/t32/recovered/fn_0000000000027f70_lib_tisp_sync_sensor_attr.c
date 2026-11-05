/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_dd2d4[] __asm__("t32_data_dd2d4");
extern unsigned char ref_tisp_ae_par_sensor_trig[] __asm__("tisp_ae_par_sensor_trig");
u64 lib_tisp_sync_sensor_attr(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_27f80 = ((u32)(unsigned long)ref_t32_data_dd2d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_27f88 = ((u32)(unsigned long)ref_tisp_ae_par_sensor_trig + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
L_27f70:
    v1 = 232;
    a0 = a0 & 0xff;
    a3 = a0 * v1;
    a2 = *(volatile u32 *)(unsigned long)(a1 + (36));
    v0 = hi_27f80;
    v0 = v0 - hi_27f80 + (u32)(unsigned long)ref_t32_data_dd2d4;
    t9 = hi_27f88;
    t9 = t9 - hi_27f88 + (u32)(unsigned long)ref_tisp_ae_par_sensor_trig;
    v0 = a3 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (36)) = a2;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (40));
    *(volatile u32 *)(unsigned long)(v0 + (40)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (116));
    *(volatile u8 *)(unsigned long)(v0 + (116)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (117));
    *(volatile u8 *)(unsigned long)(v0 + (117)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (118));
    *(volatile u8 *)(unsigned long)(v0 + (118)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (68));
    *(volatile u32 *)(unsigned long)(v0 + (68)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (72));
    *(volatile u32 *)(unsigned long)(v0 + (72)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (88));
    *(volatile u32 *)(unsigned long)(v0 + (88)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (92));
    *(volatile u32 *)(unsigned long)(v0 + (92)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (96));
    *(volatile u32 *)(unsigned long)(v0 + (96)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (100));
    *(volatile u32 *)(unsigned long)(v0 + (100)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (119));
    *(volatile u8 *)(unsigned long)(v0 + (119)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (120));
    *(volatile u8 *)(unsigned long)(v0 + (120)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (121));
    *(volatile u8 *)(unsigned long)(v0 + (121)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(v0 + (0)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(a1 + (2));
    *(volatile u16 *)(unsigned long)(v0 + (2)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (56));
    *(volatile u32 *)(unsigned long)(v0 + (56)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (60));
    *(volatile u32 *)(unsigned long)(v0 + (60)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (64));
    *(volatile u32 *)(unsigned long)(v0 + (64)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(a1 + (123));
    callee = t9; *(volatile u8 *)(unsigned long)(v0 + (123)) = v1;
    switch (callee) { case 0x27f70: goto L_27f70; default: break; }

    return ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
}
