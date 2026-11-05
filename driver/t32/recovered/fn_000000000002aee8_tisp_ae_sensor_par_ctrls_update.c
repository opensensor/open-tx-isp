/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_tisp_math_exp2[] __asm__("tisp_math_exp2");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
extern unsigned char ref_t32_data_bf3e4[] __asm__("t32_data_bf3e4");
extern unsigned char ref_t32_data_c8500[] __asm__("t32_data_c8500");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c8524[] __asm__("t32_data_c8524");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
u64 tisp_ae_sensor_par_ctrls_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, u32 arg14, u32 arg15, u32 arg16, u32 arg17, u32 arg18, u32 arg19)
{
    u32 stack[86] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2aef4 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_2af84 = ((u32)(unsigned long)ref_tisp_math_exp2 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b010 = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b25c = ((u32)(unsigned long)ref_t32_data_bf3e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b260 = ((u32)(unsigned long)ref_t32_data_c8500 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b264 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_2b28c = ((u32)(unsigned long)ref_t32_data_bf3e4 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b290 = ((u32)(unsigned long)ref_t32_data_c8524 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b294 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_2b2d4 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[22];
    stack[26] = arg4;
    stack[27] = arg5;
    stack[28] = arg6;
    stack[29] = arg7;
    stack[30] = arg8;
    stack[31] = arg9;
    stack[32] = arg10;
    stack[33] = arg11;
    stack[34] = arg12;
    stack[35] = arg13;
    stack[36] = arg14;
    stack[37] = arg15;
    stack[38] = arg16;
    stack[39] = arg17;
    stack[40] = arg18;
    stack[41] = arg19;
L_2aee8:
    sp = sp + -88;
    a0 = a0 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (60)) = s3;
    s3 = hi_2aef4;
    *(volatile u32 *)(unsigned long)(sp + (68)) = s5;
    s3 = s3 - hi_2aef4 + (u32)(unsigned long)ref_t32_data_e15a8;
    s5 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (84)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (64)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s7;
    s2 = s5 + s3;
    v1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    *(volatile u32 *)(unsigned long)(sp + (100)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (92)) = a1;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(sp + (164));
    *(volatile u32 *)(unsigned long)(sp + (96)) = a2;
    t3 = *(volatile u32 *)(unsigned long)(v0 + (448));
    t0 = *(volatile u32 *)(unsigned long)(v0 + (452));
    t1 = *(volatile u32 *)(unsigned long)(v0 + (468));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (476));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (1736));
    *(volatile u32 *)(unsigned long)(sp + (44)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (36)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = a3;
    t2 = *(volatile u32 *)(unsigned long)(v0 + (464));
    *(volatile u32 *)(unsigned long)(sp + (16)) = a0;
    s8 = *(volatile u32 *)(unsigned long)(v0 + (460));
    s4 = *(volatile u32 *)(unsigned long)(sp + (148));
    s0 = *(volatile u32 *)(unsigned long)(sp + (152));
    s1 = *(volatile u32 *)(unsigned long)(sp + (156));
    s7 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (1740));
    s6 = hi_2af84;
    t4 = 1;
    v0 = v0 ^ 0x1;
    if (v0 == 0) t2 = a1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (160));
    s6 = s6 - hi_2af84 + (u32)(unsigned long)ref_tisp_math_exp2;
    a2 = 10;
    *(volatile u32 *)(unsigned long)(s7 + (7536)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = 1024;
    *(volatile u32 *)(unsigned long)(sp + (28)) = t4;
    *(volatile u32 *)(unsigned long)(a0 + (7540)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(sp + (24)) = t2;
    *(volatile u32 *)(unsigned long)(a0 + (7544)) = v0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(a0 + (7548)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(sp + (128));
    *(volatile u32 *)(unsigned long)(v0 + (7552)) = a1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a1 = 16;
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2afe4;
L_2afe4:
    v1 = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = *(volatile u32 *)(unsigned long)(sp + (132));
    a2 = 10;
    *(volatile u32 *)(unsigned long)(v1 + (7556)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a1 = 16;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    callee = s6; *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b008;
L_2b008:
    v1 = *(volatile u32 *)(unsigned long)(sp + (20));
    a0 = 32767;
    s6 = hi_2b010;
    *(volatile u32 *)(unsigned long)(v1 + (7560)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    s6 = s6 - hi_2b010 + (u32)(unsigned long)ref_t32_data_e1588;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(v0 + (7564)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = s6 + s5;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7536));
    *(volatile u32 *)(unsigned long)(v0 + (608)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7540));
    *(volatile u32 *)(unsigned long)(v0 + (612)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7544));
    *(volatile u32 *)(unsigned long)(v0 + (616)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7548));
    *(volatile u32 *)(unsigned long)(v0 + (620)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7552));
    *(volatile u32 *)(unsigned long)(v0 + (624)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7556));
    *(volatile u32 *)(unsigned long)(v0 + (628)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7560));
    *(volatile u32 *)(unsigned long)(v0 + (632)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7564));
    *(volatile u32 *)(unsigned long)(v0 + (636)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u8 *)(unsigned long)(a0 + (1250));
    t2 = *(volatile u32 *)(unsigned long)(sp + (24));
    t4 = *(volatile u32 *)(unsigned long)(sp + (28));
    a3 = *(volatile u32 *)(unsigned long)(sp + (32));
    t1 = *(volatile u32 *)(unsigned long)(sp + (36));
    t0 = *(volatile u32 *)(unsigned long)(sp + (40));
    branch = (a0 != t4); t3 = *(volatile u32 *)(unsigned long)(sp + (44));
    if (branch) goto L_2b0c4;
    goto L_2b0b4;
L_2b0b4:
    a1 = *(volatile u32 *)(unsigned long)(s7 + (7536));
    a0 = (u32)t3 < (u32)(a1);
    if (a0 == 0) a1 = t3;
    *(volatile u32 *)(unsigned long)(v0 + (608)) = a1;
L_2b0c4:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1254));
    a0 = 1;
    if (a1 != a0) { a1 = *(volatile u32 *)(unsigned long)(v0 + (624)); goto L_2b100; }
    goto L_2b0d8;
L_2b0d8:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7552));
    a1 = (u32)a0 < (u32)(t2);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (624)) = a0; goto L_2b0fc; }
    goto L_2b0e8;
L_2b0e8:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7536));
    a0 = (u32)t2 < (u32)(a0);
    if (a0 == 0) t3 = t2;
    a0 = t3;
    *(volatile u32 *)(unsigned long)(v0 + (624)) = a0;
L_2b0fc:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (624));
L_2b100:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (608));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (608)) = a1; goto L_2b110; }
    goto L_2b110;
L_2b110:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (608));
    *(volatile u32 *)(unsigned long)(a0 + (448)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (624));
    *(volatile u32 *)(unsigned long)(a0 + (464)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1251));
    a0 = 1;
    if (a1 != a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_2b150; }
    goto L_2b13c;
L_2b13c:
    a1 = *(volatile u32 *)(unsigned long)(s7 + (7540));
    a0 = (u32)t0 < (u32)(a1);
    if (a0 == 0) a1 = t0;
    *(volatile u32 *)(unsigned long)(v0 + (612)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_2b150:
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1255));
    a0 = 1;
    if (a1 != a0) { a1 = *(volatile u32 *)(unsigned long)(v0 + (628)); goto L_2b188; }
    goto L_2b160;
L_2b160:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7556));
    a1 = (u32)a0 < (u32)(t1);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (628)) = a0; goto L_2b184; }
    goto L_2b170;
L_2b170:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7540));
    a0 = (u32)t1 < (u32)(a0);
    if (a0 == 0) t0 = t1;
    a0 = t0;
    *(volatile u32 *)(unsigned long)(v0 + (628)) = a0;
L_2b184:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (628));
L_2b188:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (612));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (612)) = a1; goto L_2b198; }
    goto L_2b198;
L_2b198:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (612));
    *(volatile u32 *)(unsigned long)(a0 + (452)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (628));
    *(volatile u32 *)(unsigned long)(a0 + (468)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1253));
    a0 = 1;
    if (a1 != a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_2b1d8; }
    goto L_2b1c4;
L_2b1c4:
    a1 = *(volatile u32 *)(unsigned long)(s7 + (7548));
    a0 = (u32)s8 < (u32)(a1);
    if (a0 == 0) a1 = s8;
    *(volatile u32 *)(unsigned long)(v0 + (620)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_2b1d8:
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1257));
    a0 = 1;
    if (a1 != a0) { a1 = *(volatile u32 *)(unsigned long)(v0 + (636)); goto L_2b210; }
    goto L_2b1e8;
L_2b1e8:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7564));
    a1 = (u32)a0 < (u32)(a3);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (636)) = a0; goto L_2b20c; }
    goto L_2b1f8;
L_2b1f8:
    a0 = *(volatile u32 *)(unsigned long)(s7 + (7548));
    a0 = (u32)a3 < (u32)(a0);
    if (a0 == 0) s8 = a3;
    a0 = s8;
    *(volatile u32 *)(unsigned long)(v0 + (636)) = a0;
L_2b20c:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (636));
L_2b210:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (620));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (620)) = a1; goto L_2b220; }
    goto L_2b220;
L_2b220:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (620));
    *(volatile u32 *)(unsigned long)(a0 + (460)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (636));
    *(volatile u32 *)(unsigned long)(a0 + (476)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u16 *)(unsigned long)(sp + (94));
    *(volatile u16 *)(unsigned long)(v0 + (8554)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v1 = *(volatile u16 *)(unsigned long)(sp + (92));
    *(volatile u16 *)(unsigned long)(v0 + (8556)) = v1;
    v0 = s1 >> (0x10 & 31);
    branch = (v0 != 0); v0 = s0 >> (0x10 & 31);
    if (branch) goto L_2b288;
    goto L_2b25c;
L_2b25c:
    a1 = hi_2b25c;
    a0 = hi_2b260;
    v0 = hi_2b264;
    a2 = 698;
    a1 = a1 - hi_2b25c + (u32)(unsigned long)ref_t32_data_bf3e4;
    a0 = a0 - hi_2b260 + (u32)(unsigned long)ref_t32_data_c8500;
    v0 = v0 - hi_2b264 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; s1 = 0x19U << 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b280;
L_2b280:
    s1 = s1 + 1;
    v0 = s0 >> (0x10 & 31);
L_2b288:
    branch = (v0 != 0); a1 = hi_2b28c;
    if (branch) goto L_2b2b4;
    goto L_2b290;
L_2b290:
    a0 = hi_2b290;
    v0 = hi_2b294;
    a2 = 705;
    a1 = a1 - hi_2b28c + (u32)(unsigned long)ref_t32_data_bf3e4;
    a0 = a0 - hi_2b290 + (u32)(unsigned long)ref_t32_data_c8524;
    v0 = v0 - hi_2b294 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; s0 = 0x5U << 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b2b0;
L_2b2b0:
    s0 = s0 + 1;
L_2b2b4:
    branch = (s4 != 0); s2 = *(volatile u16 *)(unsigned long)(sp + (16));
    if (branch) goto L_2b2c4;
    goto L_2b2bc;
L_2b2bc:
    s4 = 0x19U << 16;
    s4 = s4 + 1;
L_2b2c4:
    s6 = s6 + s5;
    s7 = *(volatile u32 *)(unsigned long)(s6 + (0));
    a2 = s4 & 0xffff;
    a1 = s4 >> (0x10 & 31);
    s4 = hi_2b2d4;
    s4 = s4 - hi_2b2d4 + (u32)(unsigned long)ref_fix_point_div_32;
    a2 = a2 << (s2 & 31);
    a1 = a1 << (s2 & 31);
    callee = s4; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b2ec;
L_2b2ec:
    *(volatile u32 *)(unsigned long)(s7 + (1260)) = v0;
    a2 = s0 & 0xffff;
    s7 = *(volatile u32 *)(unsigned long)(s6 + (0));
    a1 = s0 >> (0x10 & 31);
    a2 = a2 << (s2 & 31);
    a1 = a1 << (s2 & 31);
    callee = s4; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b30c;
L_2b30c:
    a2 = s1 & 0xffff;
    a1 = s1 >> (0x10 & 31);
    s6 = *(volatile u32 *)(unsigned long)(s6 + (0));
    a0 = s2;
    s3 = s3 + s5;
    *(volatile u32 *)(unsigned long)(s7 + (1264)) = v0;
    a2 = a2 << (s2 & 31);
    callee = s4; a1 = a1 << (s2 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b330;
L_2b330:
    v1 = *(volatile u32 *)(unsigned long)(s3 + (0));
    *(volatile u32 *)(unsigned long)(s6 + (1268)) = v0;
    s1 = s1 << (0x1 & 31);
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = 0xffffU << 16;
    s1 = s1 & v0;
    s1 = s1 + 2;
    *(volatile u32 *)(unsigned long)(a0 + (1668)) = s1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    s0 = s0 << (0x1 & 31);
    s0 = s0 & v0;
    s0 = s0 + 2;
    *(volatile u32 *)(unsigned long)(v1 + (1672)) = s0;
    ra = *(volatile u32 *)(unsigned long)(sp + (84));
    s8 = *(volatile u32 *)(unsigned long)(sp + (80));
    s7 = *(volatile u32 *)(unsigned long)(sp + (76));
    s6 = *(volatile u32 *)(unsigned long)(sp + (72));
    s5 = *(volatile u32 *)(unsigned long)(sp + (68));
    s4 = *(volatile u32 *)(unsigned long)(sp + (64));
    s3 = *(volatile u32 *)(unsigned long)(sp + (60));
    s2 = *(volatile u32 *)(unsigned long)(sp + (56));
    s1 = *(volatile u32 *)(unsigned long)(sp + (52));
    s0 = *(volatile u32 *)(unsigned long)(sp + (48));
    v0 = 0;
    sp = sp + 88;
    return ((u64)v1 << 32) | v0;
}
