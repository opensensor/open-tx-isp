/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_t32_data_dd2d4[] __asm__("t32_data_dd2d4");
extern unsigned char ref_tisp_set_sensor_short_analog_gain[] __asm__("tisp_set_sensor_short_analog_gain");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
u64 tisp_set_ae_short_ag(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[132] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2fbb0 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_2fbe4 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_2fc18 = ((u32)(unsigned long)ref_t32_data_dd2d4 + 0x8000U) & 0xffff0000U;
    const u32 hi_2fc5c = ((u32)(unsigned long)ref_tisp_set_sensor_short_analog_gain + 0x8000U) & 0xffff0000U;
    const u32 hi_2fc98 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_2fcb4 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[68];
L_2fba8:
    sp = sp + -272;
    a0 = a0 & 0xff;
    v0 = hi_2fbb0;
    v0 = v0 - hi_2fbb0 + (u32)(unsigned long)ref_t32_data_e15a8;
    *(volatile u32 *)(unsigned long)(sp + (256)) = s4;
    s4 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (240)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (268)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (264)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (260)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (252)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (248)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (244)) = s1;
    v0 = s4 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = hi_2fbe4;
    s0 = s0 - hi_2fbe4 + (u32)(unsigned long)ref_t32_data_e1588;
    v1 = s4 + s0;
    s2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    s3 = *(volatile u32 *)(unsigned long)(s2 + (596));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (7636));
    branch = (v1 == s3); ra = *(volatile u32 *)(unsigned long)(sp + (268));
    if (branch) goto L_2fce0;
    goto L_2fc08;
L_2fc08:
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s6 = *(volatile u32 *)(unsigned long)(s2 + (604));
    a2 = sp + 16;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (1736));
    v0 = hi_2fc18;
    v1 = v0 - hi_2fc18 + (u32)(unsigned long)ref_t32_data_dd2d4;
    v0 = 232;
    a1 = a0 * v0;
    v0 = a1 + v1;
    a3 = v0 + 8;
    v1 = 0;
L_2fc34:
    a1 = (u32)v1 < (u32)(224);
    branch = (a1 == 0); t0 = a3 + v1;
    if (branch) goto L_2fc54;
    goto L_2fc40;
L_2fc40:
    t0 = *(volatile u8 *)(unsigned long)(t0 + (0));
    a1 = a2 + v1;
    v1 = v1 + 1;
    *(volatile u8 *)(unsigned long)(a1 + (0)) = t0; goto L_2fc34;
L_2fc54:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = hi_2fc5c;
    v0 = v0 - hi_2fc5c + (u32)(unsigned long)ref_tisp_set_sensor_short_analog_gain;
    callee = v0; a1 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2fc6c;
L_2fc6c:
    s0 = s0 + s4;
    *(volatile u32 *)(unsigned long)(s2 + (596)) = v0;
    s5 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v0 + (1283));
    branch = (v1 != 0); ra = *(volatile u32 *)(unsigned long)(sp + (268));
    if (branch) goto L_2fce0;
    goto L_2fc88;
L_2fc88:
    v0 = *(volatile u8 *)(unsigned long)(v0 + (1284));
    if (v0 != 0) { s6 = *(volatile u32 *)(unsigned long)(sp + (264)); goto L_2fce4; }
    goto L_2fc94;
L_2fc94:
    s1 = s1 & 0xffff;
    v0 = hi_2fc98;
    a2 = s6;
    a1 = s3;
    v0 = v0 - hi_2fc98 + (u32)(unsigned long)ref_fix_point_mult2_32;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2fcb0;
L_2fcb0:
    a1 = v0;
    v0 = hi_2fcb4;
    a0 = s1;
    v0 = v0 - hi_2fcb4 + (u32)(unsigned long)ref_fix_point_div_32;
    callee = v0; a2 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2fcc8;
L_2fcc8:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (668));
    v1 = (u32)a0 < (u32)(v0);
    if (v1 != 0) v0 = a0;
    *(volatile u32 *)(unsigned long)(s2 + (604)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (268));
L_2fce0:
    s6 = *(volatile u32 *)(unsigned long)(sp + (264));
L_2fce4:
    s5 = *(volatile u32 *)(unsigned long)(sp + (260));
    s4 = *(volatile u32 *)(unsigned long)(sp + (256));
    s3 = *(volatile u32 *)(unsigned long)(sp + (252));
    s2 = *(volatile u32 *)(unsigned long)(sp + (248));
    s1 = *(volatile u32 *)(unsigned long)(sp + (244));
    s0 = *(volatile u32 *)(unsigned long)(sp + (240));
    sp = sp + 272;
    return ((u64)v1 << 32) | v0;
}
