/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_fix_point_mult2[] __asm__("fix_point_mult2");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
extern unsigned char ref_tisp_ae_fps_calc_max_exp[] __asm__("tisp_ae_fps_calc_max_exp");
extern unsigned char ref___ashldi3[] __asm__("__ashldi3");
extern unsigned char ref_fix_point_mult3_64[] __asm__("fix_point_mult3_64");
u64 tisp_ae_par_calc(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[88] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_30620 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_30658 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_30690 = ((u32)(unsigned long)ref_fix_point_mult2 + 0x8000U) & 0xffff0000U;
    const u32 hi_306b8 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_3071c = ((u32)(unsigned long)ref_tisp_ae_fps_calc_max_exp + 0x8000U) & 0xffff0000U;
    const u32 hi_3088c = (((u32)(unsigned long)ref___ashldi3 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_30890 = ((u32)(unsigned long)ref_fix_point_mult3_64 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[24];
L_30618:
    sp = sp + -96;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s2;
    s2 = hi_30620;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s4;
    s2 = s2 - hi_30620 + (u32)(unsigned long)ref_t32_data_e15a8;
    s4 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (92)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (68)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s0;
    s6 = s4 + s2;
    v1 = *(volatile u32 *)(unsigned long)(s6 + (0));
    s1 = hi_30658;
    s1 = s1 - hi_30658 + (u32)(unsigned long)ref_t32_data_e1588;
    t0 = s4 + s1;
    v0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (1260));
    s8 = *(volatile u32 *)(unsigned long)(v0 + (608));
    s0 = *(volatile u16 *)(unsigned long)(v1 + (1736));
    v0 = *(volatile u16 *)(unsigned long)(t1 + (8554));
    s5 = 0xfU << 16;
    a3 = 0;
    v0 = v0 << (s0 & 31);
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_30690;
    s7 = a0;
    s5 = s5 + 16960;
    a0 = s0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    v0 = v0 - hi_30690 + (u32)(unsigned long)ref_fix_point_mult2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = t1;
    callee = v0; s5 = s5 << (s0 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_306b8;
L_306b8:
    s3 = hi_306b8;
    a0 = s0;
    a2 = v0;
    s3 = s3 - hi_306b8 + (u32)(unsigned long)ref_fix_point_div_32;
    callee = s3; a1 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_306d0;
L_306d0:
    t1 = *(volatile u32 *)(unsigned long)(sp + (32));
    t0 = *(volatile u32 *)(unsigned long)(sp + (36));
    *(volatile u32 *)(unsigned long)(t1 + (8680)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (608));
    *(volatile u32 *)(unsigned long)(v0 + (676)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (612));
    *(volatile u32 *)(unsigned long)(v0 + (680)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (620));
    *(volatile u32 *)(unsigned long)(v0 + (684)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s6 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (1672));
    if (a0 != 0) { v0 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_30718; }
    goto L_3070c;
L_3070c:
    a0 = 1;
    *(volatile u32 *)(unsigned long)(v1 + (1672)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
L_30718:
    a0 = s0;
    s6 = hi_3071c;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (1672));
    s6 = s6 - hi_3071c + (u32)(unsigned long)ref_tisp_ae_fps_calc_max_exp;
    a2 = a1 & 0xffff;
    a1 = a1 >> (0x10 & 31);
    a2 = a2 << (s0 & 31);
    callee = s3; a1 = a1 << (s0 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3073c;
L_3073c:
    a1 = v0;
    callee = s6; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_30748;
L_30748:
    t1 = v0;
    v1 = 5;
    t0 = s2 + s4;
    t3 = 1;
    a3 = s1 + s4;
    t2 = 65;
L_30760:
    a1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v0 = v1 << (0x2 & 31);
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (588));
    if (a0 == 0) { *(volatile u32 *)(unsigned long)(v0 + (588)) = t3; goto L_3077c; }
    goto L_3077c;
L_3077c:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = v1 + 144;
    v0 = v0 << (0x2 & 31);
    v0 = a0 + v0;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a1 = s5;
    a0 = s0;
    a2 = a2 << (s0 & 31);
    *(volatile u32 *)(unsigned long)(sp + (52)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (48)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (44)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = t1;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (32)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_307b8;
L_307b8:
    a1 = v0;
    callee = s6; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_307c4;
L_307c4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (32));
    a1 = (u32)v0 < (u32)(s8);
    t1 = *(volatile u32 *)(unsigned long)(sp + (36));
    a0 = v1 + 168;
    t0 = *(volatile u32 *)(unsigned long)(sp + (40));
    t3 = *(volatile u32 *)(unsigned long)(sp + (44));
    a3 = *(volatile u32 *)(unsigned long)(sp + (48));
    branch = (a1 == 0); t2 = *(volatile u32 *)(unsigned long)(sp + (52));
    if (branch) goto L_307fc;
    goto L_307e8;
L_307e8:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a0 = a0 << (0x2 & 31);
    a0 = v0 + a0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = s8; goto L_30828;
L_307fc:
    a1 = (u32)t1 < (u32)(v0);
    if (a1 == 0) { a1 = *(volatile u32 *)(unsigned long)(a3 + (0)); goto L_3081c; }
    goto L_30808;
L_30808:
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a0 = a0 << (0x2 & 31);
    a0 = v0 + a0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = t1; goto L_30828;
L_3081c:
    a0 = a0 << (0x2 & 31);
    a0 = a1 + a0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
L_30828:
    a2 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v0 = v1 + 145;
    v0 = v0 << (0x2 & 31);
    a1 = *(volatile u32 *)(unsigned long)(a2 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    v0 = a1 + v0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (12));
    v0 = v1 + 169;
    v0 = v0 << (0x2 & 31);
    v0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v1 + 146;
    v0 = v0 << (0x2 & 31);
    v0 = a1 + v0;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (12));
    v0 = v1 + 170;
    v0 = v0 << (0x2 & 31);
    a0 = a0 + v0;
    v1 = v1 + 4;
    branch = (v1 != t2); *(volatile u32 *)(unsigned long)(a0 + (0)) = a1;
    if (branch) goto L_30760;
    goto L_30880;
L_30880:
    s5 = 1;
    s7 = 0;
    s1 = s1 + s4;
    t0 = hi_3088c;
    s6 = hi_30890;
    s8 = 16;
L_30898:
    s3 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = s5 + 168;
    v0 = v0 << (0x2 & 31);
    v0 = s3 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (32)) = t0;
    v0 = t0 - hi_3088c + ((u32)(unsigned long)ref___ashldi3 + (0));
    a2 = s0;
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_308c0;
L_308c0:
    a0 = s5 + 170;
    a0 = a0 << (0x2 & 31);
    a0 = s3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (28)) = 0;
    a2 = v0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = a0;
    a0 = s5 + 169;
    a0 = a0 << (0x2 & 31);
    a0 = s3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a3 = v1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = a0;
    v0 = s6 - hi_30890 + (u32)(unsigned long)ref_fix_point_mult3_64;
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_30904;
L_30904:
    a0 = s7 + 10;
    a0 = a0 << (0x3 & 31);
    s3 = s3 + a0;
    s7 = s7 + 1;
    *(volatile u32 *)(unsigned long)(s3 + (0)) = v0;
    *(volatile u32 *)(unsigned long)(s3 + (4)) = v1;
    s5 = s5 + 4;
    branch = (s7 != s8); t0 = *(volatile u32 *)(unsigned long)(sp + (32));
    if (branch) goto L_30898;
    goto L_30928;
L_30928:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = -1;
    a2 = 14;
    a0 = v0 + 80;
L_30938:
    t0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(a0 + (8));
    v1 = v1 + 1;
    a1 = v1 & 0xff;
    branch = (t0 != a3); v1 = (int8_t)a1;
    if (branch) goto L_30974;
    goto L_30950;
L_30950:
    t0 = *(volatile u32 *)(unsigned long)(a0 + (4));
    a3 = *(volatile u32 *)(unsigned long)(a0 + (12));
    branch = (t0 != a3); ;
    if (branch) goto L_30974;
    goto L_30960;
L_30960:
    a0 = 14;
    if (v1 != a0) { s2 = s2 + s4; goto L_309a4; }
    goto L_3096c;
L_3096c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (192)); goto L_30980;
L_30974:
    branch = (a1 != a2); a0 = a0 + 8;
    if (branch) goto L_30938;
    goto L_3097c;
L_3097c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (192));
L_30980:
    v1 = *(volatile u32 *)(unsigned long)(v0 + (200));
    branch = (a0 != v1); v1 = 15;
    if (branch) goto L_309a0;
    goto L_3098c;
L_3098c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (196));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (204));
    branch = (a0 != v1); v1 = 15;
    if (branch) goto L_309a0;
    goto L_3099c;
L_3099c:
    v1 = 14;
L_309a0:
    s2 = s2 + s4;
L_309a4:
    a1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (8576)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (1744));
    branch = (v1 != 0); ra = *(volatile u32 *)(unsigned long)(sp + (92));
    if (branch) goto L_30a60;
    goto L_309c0;
L_309c0:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (612));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (620));
    v1 = v0 + 684;
    t1 = v0 + 940;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
L_309d4:
    a0 = *(volatile u32 *)(unsigned long)(a0 + (1740));
    if (a0 != 0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (-4)); goto L_30a0c; }
    goto L_309e0;
L_309e0:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-8));
    t0 = *(volatile u32 *)(unsigned long)(v0 + (608));
    t2 = (u32)a0 < (u32)(t0);
    if (t2 != 0) { *(volatile u32 *)(unsigned long)(v1 + (-8)) = t0; goto L_30a08; }
    goto L_309f4;
L_309f4:
    t0 = *(volatile u32 *)(unsigned long)(v0 + (624));
    a0 = (u32)t0 < (u32)(a0);
    if (a0 == 0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (-4)); goto L_30a0c; }
    goto L_30a04;
L_30a04:
    *(volatile u32 *)(unsigned long)(v1 + (-8)) = t0;
L_30a08:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-4));
L_30a0c:
    t0 = (u32)a0 < (u32)(a2);
    if (t0 == 0) { t0 = *(volatile u32 *)(unsigned long)(v0 + (628)); goto L_30a20; }
    goto L_30a18;
L_30a18:
    *(volatile u32 *)(unsigned long)(v1 + (-4)) = a2; goto L_30a2c;
L_30a20:
    a0 = (u32)t0 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v1 + (-4)) = t0; goto L_30a2c; }
    goto L_30a2c;
L_30a2c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t0 = (u32)a0 < (u32)(a3);
    if (t0 == 0) { t0 = *(volatile u32 *)(unsigned long)(v0 + (636)); goto L_30a44; }
    goto L_30a3c;
L_30a3c:
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a3; goto L_30a50;
L_30a44:
    a0 = (u32)t0 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v1 + (0)) = t0; goto L_30a50; }
    goto L_30a50;
L_30a50:
    v1 = v1 + 16;
    if (t1 != v1) { a0 = *(volatile u32 *)(unsigned long)(a1 + (0)); goto L_309d4; }
    goto L_30a5c;
L_30a5c:
    ra = *(volatile u32 *)(unsigned long)(sp + (92));
L_30a60:
    s8 = *(volatile u32 *)(unsigned long)(sp + (88));
    s7 = *(volatile u32 *)(unsigned long)(sp + (84));
    s6 = *(volatile u32 *)(unsigned long)(sp + (80));
    s5 = *(volatile u32 *)(unsigned long)(sp + (76));
    s4 = *(volatile u32 *)(unsigned long)(sp + (72));
    s3 = *(volatile u32 *)(unsigned long)(sp + (68));
    s2 = *(volatile u32 *)(unsigned long)(sp + (64));
    s1 = *(volatile u32 *)(unsigned long)(sp + (60));
    s0 = *(volatile u32 *)(unsigned long)(sp + (56));
    sp = sp + 96;
    return ((u64)v1 << 32) | v0;
}
