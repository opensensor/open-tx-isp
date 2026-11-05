/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e15a8[] __asm__("t32_data_e15a8");
extern unsigned char ref_tisp_math_exp2[] __asm__("tisp_math_exp2");
extern unsigned char ref_t32_data_e1588[] __asm__("t32_data_e1588");
u64 tisp_ae_short_sensor_par_ctrls_update(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4, u32 arg5, u32 arg6, u32 arg7, u32 arg8, u32 arg9, u32 arg10, u32 arg11, u32 arg12, u32 arg13, u32 arg14, u32 arg15, u32 arg16, u32 arg17, u32 arg18, u32 arg19, u32 arg20, u32 arg21, u32 arg22, u32 arg23, u32 arg24, u32 arg25, u32 arg26)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_2b3a4 = ((u32)(unsigned long)ref_t32_data_e15a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b410 = ((u32)(unsigned long)ref_tisp_math_exp2 + 0x8000U) & 0xffff0000U;
    const u32 hi_2b49c = ((u32)(unsigned long)ref_t32_data_e1588 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
    stack[20] = arg4;
    stack[21] = arg5;
    stack[22] = arg6;
    stack[23] = arg7;
    stack[24] = arg8;
    stack[25] = arg9;
    stack[26] = arg10;
    stack[27] = arg11;
    stack[28] = arg12;
    stack[29] = arg13;
    stack[30] = arg14;
    stack[31] = arg15;
    stack[32] = arg16;
    stack[33] = arg17;
    stack[34] = arg18;
    stack[35] = arg19;
    stack[36] = arg20;
    stack[37] = arg21;
    stack[38] = arg22;
    stack[39] = arg23;
    stack[40] = arg24;
    stack[41] = arg25;
    stack[42] = arg26;
L_2b398:
    sp = sp + -64;
    a0 = a0 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s1;
    s1 = hi_2b3a4;
    *(volatile u32 *)(unsigned long)(sp + (76)) = a3;
    s1 = s1 - hi_2b3a4 + (u32)(unsigned long)ref_t32_data_e15a8;
    a3 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (60)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (56)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s0;
    s1 = a3 + s1;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    *(volatile u32 *)(unsigned long)(sp + (20)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (68)) = a1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u32 *)(unsigned long)(sp + (72)) = a2;
    s7 = *(volatile u32 *)(unsigned long)(v1 + (480));
    s5 = *(volatile u32 *)(unsigned long)(v1 + (484));
    s3 = *(volatile u32 *)(unsigned long)(v1 + (492));
    s8 = *(volatile u32 *)(unsigned long)(v1 + (496));
    s6 = *(volatile u32 *)(unsigned long)(v1 + (500));
    s4 = *(volatile u32 *)(unsigned long)(v1 + (508));
    v1 = *(volatile u32 *)(unsigned long)(sp + (156));
    s2 = hi_2b410;
    a2 = 10;
    *(volatile u32 *)(unsigned long)(s0 + (7568)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = 1024;
    a1 = 16;
    *(volatile u32 *)(unsigned long)(a0 + (7572)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    s2 = s2 - hi_2b410 + (u32)(unsigned long)ref_tisp_math_exp2;
    *(volatile u32 *)(unsigned long)(a0 + (7576)) = v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u32 *)(unsigned long)(a0 + (7580)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(sp + (160));
    *(volatile u32 *)(unsigned long)(v1 + (7584)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = *(volatile u32 *)(unsigned long)(sp + (164));
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b45c;
L_2b45c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = *(volatile u32 *)(unsigned long)(sp + (168));
    a1 = 16;
    *(volatile u32 *)(unsigned long)(v1 + (7588)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 10;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2b480;
L_2b480:
    v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    a0 = 32767;
    a3 = *(volatile u32 *)(unsigned long)(sp + (20));
    *(volatile u32 *)(unsigned long)(v1 + (7592)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(v0 + (7596)) = a0;
    a0 = hi_2b49c;
    a0 = a0 - hi_2b49c + (u32)(unsigned long)ref_t32_data_e1588;
    a0 = a3 + a0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7568));
    *(volatile u32 *)(unsigned long)(v0 + (640)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7572));
    *(volatile u32 *)(unsigned long)(v0 + (644)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7576));
    *(volatile u32 *)(unsigned long)(v0 + (648)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7580));
    *(volatile u32 *)(unsigned long)(v0 + (652)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7584));
    *(volatile u32 *)(unsigned long)(v0 + (656)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7588));
    *(volatile u32 *)(unsigned long)(v0 + (660)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7592));
    *(volatile u32 *)(unsigned long)(v0 + (664)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (7596));
    *(volatile u32 *)(unsigned long)(v0 + (668)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1258));
    a0 = 1;
    if (a1 != a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_2b534; }
    goto L_2b520;
L_2b520:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (7568));
    a0 = (u32)s7 < (u32)(a1);
    if (a0 == 0) a1 = s7;
    *(volatile u32 *)(unsigned long)(v0 + (640)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_2b534:
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1262));
    a0 = 1;
    if (a1 != a0) { a1 = *(volatile u32 *)(unsigned long)(v0 + (656)); goto L_2b56c; }
    goto L_2b544;
L_2b544:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (7584));
    a1 = (u32)a0 < (u32)(s8);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (656)) = a0; goto L_2b568; }
    goto L_2b554;
L_2b554:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (7568));
    a0 = (u32)s8 < (u32)(a0);
    if (a0 == 0) s7 = s8;
    a0 = s7;
    *(volatile u32 *)(unsigned long)(v0 + (656)) = a0;
L_2b568:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (656));
L_2b56c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (640));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (640)) = a1; goto L_2b57c; }
    goto L_2b57c;
L_2b57c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (640));
    *(volatile u32 *)(unsigned long)(a0 + (480)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (656));
    *(volatile u32 *)(unsigned long)(a0 + (496)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = 1;
    a2 = *(volatile u16 *)(unsigned long)(a1 + (1232));
    if (a2 != a0) { a1 = *(volatile u8 *)(unsigned long)(a1 + (1259)); goto L_2b5b8; }
    goto L_2b5a8;
L_2b5a8:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (612));
    *(volatile u32 *)(unsigned long)(v0 + (644)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (628)); goto L_2b604;
L_2b5b8:
    if (a1 != a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_2b5d4; }
    goto L_2b5c0;
L_2b5c0:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (7572));
    a0 = (u32)s5 < (u32)(a1);
    if (a0 == 0) a1 = s5;
    *(volatile u32 *)(unsigned long)(v0 + (644)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_2b5d4:
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1263));
    a0 = 1;
    if (a1 != a0) { a1 = *(volatile u32 *)(unsigned long)(v0 + (660)); goto L_2b60c; }
    goto L_2b5e4;
L_2b5e4:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (7588));
    a1 = (u32)a0 < (u32)(s6);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (660)) = a0; goto L_2b608; }
    goto L_2b5f4;
L_2b5f4:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (7572));
    a0 = (u32)s6 < (u32)(a0);
    if (a0 == 0) s5 = s6;
    a0 = s5;
L_2b604:
    *(volatile u32 *)(unsigned long)(v0 + (660)) = a0;
L_2b608:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (660));
L_2b60c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (644));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (644)) = a1; goto L_2b61c; }
    goto L_2b61c;
L_2b61c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (644));
    *(volatile u32 *)(unsigned long)(a0 + (484)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (660));
    *(volatile u32 *)(unsigned long)(a0 + (500)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1261));
    a0 = 1;
    if (a1 != a0) { a0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_2b65c; }
    goto L_2b648;
L_2b648:
    a1 = *(volatile u32 *)(unsigned long)(s0 + (7580));
    a0 = (u32)s3 < (u32)(a1);
    if (a0 == 0) a1 = s3;
    *(volatile u32 *)(unsigned long)(v0 + (652)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_2b65c:
    a1 = *(volatile u8 *)(unsigned long)(a0 + (1265));
    a0 = 1;
    if (a1 != a0) { a1 = *(volatile u32 *)(unsigned long)(v0 + (668)); goto L_2b694; }
    goto L_2b66c;
L_2b66c:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (7596));
    a1 = (u32)a0 < (u32)(s4);
    if (a1 != 0) { *(volatile u32 *)(unsigned long)(v0 + (668)) = a0; goto L_2b690; }
    goto L_2b67c;
L_2b67c:
    a0 = *(volatile u32 *)(unsigned long)(s0 + (7580));
    a0 = (u32)s4 < (u32)(a0);
    if (a0 == 0) s3 = s4;
    a0 = s3;
    *(volatile u32 *)(unsigned long)(v0 + (668)) = a0;
L_2b690:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (668));
L_2b694:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (652));
    a0 = (u32)a1 < (u32)(a0);
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (652)) = a1; goto L_2b6a4; }
    goto L_2b6a4;
L_2b6a4:
    a1 = *(volatile u32 *)(unsigned long)(v0 + (652));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (492)) = a1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (668));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(v1 + (508)) = v0;
    ra = *(volatile u32 *)(unsigned long)(sp + (60));
    s8 = *(volatile u32 *)(unsigned long)(sp + (56));
    s7 = *(volatile u32 *)(unsigned long)(sp + (52));
    s6 = *(volatile u32 *)(unsigned long)(sp + (48));
    s5 = *(volatile u32 *)(unsigned long)(sp + (44));
    s4 = *(volatile u32 *)(unsigned long)(sp + (40));
    s3 = *(volatile u32 *)(unsigned long)(sp + (36));
    s2 = *(volatile u32 *)(unsigned long)(sp + (32));
    s1 = *(volatile u32 *)(unsigned long)(sp + (28));
    s0 = *(volatile u32 *)(unsigned long)(sp + (24));
    v0 = 0;
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
}
