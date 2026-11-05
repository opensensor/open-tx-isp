/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
u64 tisp_awb_long_par_update(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[66] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3d158 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[2];
L_3d158:
    v0 = hi_3d158;
    sp = sp + -8;
    v0 = v0 - hi_3d158 + (u32)(unsigned long)ref_t32_data_e16b4;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (4)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (0)) = s0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a2 = 0x2U << 16;
    a3 = 0x9490;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t2 = *(volatile u32 *)(unsigned long)(v1 + (12));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (44));
    t1 = *(volatile u16 *)(unsigned long)(v0 + (3308));
    a3 = v1 + a3;
    a2 = v1 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (-23484));
    *(volatile u32 *)(unsigned long)(v0 + (48)) = a0;
    *(volatile u32 *)(unsigned long)(a1 + (8)) = a3;
    a3 = 0x94a0;
    a3 = v1 + a3;
    *(volatile u32 *)(unsigned long)(a1 + (12)) = a3;
    t4 = *(volatile u32 *)(unsigned long)(v0 + (228));
    t0 = *(volatile u32 *)(unsigned long)(v0 + (32));
    t3 = *(volatile u32 *)(unsigned long)(v0 + (36));
    *(volatile u32 *)(unsigned long)(v1 + (28672)) = t4;
    a3 = *(volatile u32 *)(unsigned long)(v0 + (232));
    a3 = a3 << (t1 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (28676)) = a3;
    t5 = *(volatile u32 *)(unsigned long)(v0 + (236));
    *(volatile u32 *)(unsigned long)(v1 + (28680)) = t5;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (240));
    t7 = t5 & 0xffff;
    a0 = a0 << (t1 & 31);
    *(volatile u32 *)(unsigned long)(v1 + (28684)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (32));
    a0 = (u32)a2 < (u32)(a0);
    branch = (a0 != 0); t1 = t4 & 0xffff;
    if (branch) goto L_3d208;
    goto L_3d1f8;
L_3d1f8:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (36));
    a0 = (u32)a2 < (u32)(a0);
    if (a0 == 0) { a0 = *(volatile u8 *)(unsigned long)(v0 + (5702)); goto L_3d234; }
    goto L_3d208;
L_3d208:
    *(volatile u8 *)(unsigned long)(v1 + (28688)) = 0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (5703));
    a3 = t4 & 0xffff;
    *(volatile u8 *)(unsigned long)(v1 + (28689)) = a0;
    a0 = v0 + 1264;
    *(volatile u32 *)(unsigned long)(a1 + (16)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a3;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (28676)); goto L_3d25c;
L_3d234:
    a3 = t5 & 0xffff;
    *(volatile u8 *)(unsigned long)(v1 + (28688)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (5703));
    *(volatile u8 *)(unsigned long)(v1 + (28689)) = a0;
    a0 = v0 + 364;
    *(volatile u32 *)(unsigned long)(a1 + (16)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a3;
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (28684));
L_3d25c:
    *(volatile u32 *)(unsigned long)(a0 + (4)) = a3;
    a0 = t3 - t0;
    a3 = 3;
    if (a0 == 0x80000000U && a3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a3) { lo = (s32)a0 / (s32)a3; hi = (s32)a0 % (s32)a3; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    t6 = 1;
    a0 = lo;
    branch = (t1 != t6); a3 = t3 + a0;
    if (branch) goto L_3d4b0;
    goto L_3d27c;
L_3d27c:
    t1 = (u32)a2 < (u32)(t0);
    branch = (t1 == 0); t1 = t0 + a0;
    if (branch) goto L_3d2bc;
    goto L_3d288;
L_3d288:
    t0 = 0;
    t6 = 16;
L_3d290:
    t1 = v0 + t0;
    t8 = *(volatile u32 *)(unsigned long)(t1 + (180));
    t1 = *(volatile u32 *)(unsigned long)(a1 + (8));
    t1 = t1 + t0;
    t0 = t0 + 4;
    branch = (t0 != t6); *(volatile u32 *)(unsigned long)(t1 + (0)) = t8;
    if (branch) goto L_3d290;
    goto L_3d2ac;
L_3d2ac:
    branch = (t7 == 0); a3 = (u32)a2 < (u32)(a3);
    if (branch) goto L_3d410;
    goto L_3d2b4;
L_3d2b4:
    a0 = v0 + 3322; goto L_3d548;
L_3d2bc:
    t1 = (u32)a2 < (u32)(t1);
    if (t1 == 0) { t0 = (u32)a2 < (u32)(t3); goto L_3d318; }
    goto L_3d2c8;
L_3d2c8:
    t9 = v0 + 196;
    t8 = 0;
    t6 = a2 - t0;
    s1 = 16;
L_3d2d8:
    t0 = *(volatile u32 *)(unsigned long)(t9 + (-16));
    t1 = *(volatile u32 *)(unsigned long)(t9 + (0));
    s0 = *(volatile u32 *)(unsigned long)(a1 + (8));
    product = (s64)(s32)t0 * (s32)a0; lo = product; hi = product >> 32;
    t1 = t1 - t0;
    s0 = s0 + t8;
    t8 = t8 + 4;
    t9 = t9 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t1 * (s32)t6); lo = product; hi = product >> 32;
    t0 = lo;
    if (a0) { lo = t0 / a0; hi = t0 % a0; } else { lo = ~0U; hi = t0; }
    t0 = lo;
    branch = (t8 != s1); *(volatile u32 *)(unsigned long)(s0 + (0)) = t0;
    if (branch) goto L_3d2d8;
    goto L_3d310;
L_3d310:
    ; goto L_3d2ac;
L_3d318:
    if (t0 == 0) { a3 = (u32)a2 < (u32)(a3); goto L_3d34c; }
    goto L_3d320;
L_3d320:
    t0 = 0;
    t6 = 16;
L_3d328:
    t1 = v0 + t0;
    t8 = *(volatile u32 *)(unsigned long)(t1 + (196));
    t1 = *(volatile u32 *)(unsigned long)(a1 + (8));
    t1 = t1 + t0;
    t0 = t0 + 4;
    branch = (t0 != t6); *(volatile u32 *)(unsigned long)(t1 + (0)) = t8;
    if (branch) goto L_3d328;
    goto L_3d344;
L_3d344:
    ; goto L_3d2ac;
L_3d34c:
    if (a3 == 0) { a0 = 0; goto L_3d3e0; }
    goto L_3d354;
L_3d354:
    t6 = v0 + 212;
    t5 = 0;
    a3 = a2 - t3;
    t9 = 16;
L_3d364:
    t0 = *(volatile u32 *)(unsigned long)(t6 + (-16));
    t1 = *(volatile u32 *)(unsigned long)(t6 + (0));
    t8 = *(volatile u32 *)(unsigned long)(a1 + (8));
    product = (s64)(s32)t0 * (s32)a0; lo = product; hi = product >> 32;
    t1 = t1 - t0;
    t8 = t8 + t5;
    t5 = t5 + 4;
    t6 = t6 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t1 * (s32)a3); lo = product; hi = product >> 32;
    t0 = lo;
    if (a0) { lo = t0 / a0; hi = t0 % a0; } else { lo = ~0U; hi = t0; }
    t0 = lo;
    branch = (t5 != t9); *(volatile u32 *)(unsigned long)(t8 + (0)) = t0;
    if (branch) goto L_3d364;
    goto L_3d39c;
L_3d39c:
    t1 = *(volatile u32 *)(unsigned long)(v1 + (28676));
    t0 = *(volatile u32 *)(unsigned long)(v1 + (28684));
    t5 = *(volatile u32 *)(unsigned long)(a1 + (12));
    product = (s64)(s32)a0 * (s32)t1; lo = product; hi = product >> 32;
    t0 = t0 - t1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)a3); lo = product; hi = product >> 32;
    a3 = lo;
    if (a0) { lo = a3 / a0; hi = a3 % a0; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    branch = (t7 != 0); *(volatile u32 *)(unsigned long)(t5 + (4)) = a3;
    if (branch) goto L_3d544;
    goto L_3d3c8;
L_3d3c8:
    a3 = *(volatile u32 *)(unsigned long)(a1 + (12));
L_3d3cc:
    t4 = t4 & 0xffff;
    t1 = 16;
    *(volatile u32 *)(unsigned long)(a3 + (0)) = t4;
    a3 = 0; goto L_3d428;
L_3d3e0:
    a3 = 16;
L_3d3e4:
    a2 = v0 + a0;
    t0 = *(volatile u32 *)(unsigned long)(a2 + (212));
    a2 = *(volatile u32 *)(unsigned long)(a1 + (8));
    a2 = a2 + a0;
    a0 = a0 + 4;
    branch = (a0 != a3); *(volatile u32 *)(unsigned long)(a2 + (0)) = t0;
    if (branch) goto L_3d3e4;
    goto L_3d400;
L_3d400:
    if (t7 == 0) { a0 = *(volatile u32 *)(unsigned long)(a1 + (12)); goto L_3d478; }
    goto L_3d408;
L_3d408:
    a0 = v0 + 3322; goto L_3d548;
L_3d410:
    branch = (a3 == 0); a3 = (u32)a2 < (u32)(t3);
    if (branch) goto L_3d474;
    goto L_3d418;
L_3d418:
    if (a3 != 0) { a0 = v0 + 3322; goto L_3d548; }
    goto L_3d420;
L_3d420:
    a3 = *(volatile u32 *)(unsigned long)(a1 + (12)); goto L_3d3cc;
L_3d428:
    t0 = v0 + a3;
    t4 = *(volatile u32 *)(unsigned long)(t0 + (196));
    t0 = *(volatile u32 *)(unsigned long)(a1 + (8));
    t0 = t0 + a3;
    a3 = a3 + 4;
    branch = (a3 != t1); *(volatile u32 *)(unsigned long)(t0 + (0)) = t4;
    if (branch) goto L_3d428;
    goto L_3d444;
L_3d444:
    t0 = *(volatile u32 *)(unsigned long)(v1 + (28676));
    a3 = 0x1U << 16;
    a2 = a2 - t3;
    product = (s64)(s32)t0 * (s32)a0; lo = product; hi = product >> 32;
    a3 = a3 - t0;
    t1 = *(volatile u32 *)(unsigned long)(a1 + (12));
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)a2); lo = product; hi = product >> 32;
    a2 = lo;
    if (a0) { lo = a2 / a0; hi = a2 % a0; } else { lo = ~0U; hi = a2; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (4)) = a0; goto L_3d544;
L_3d474:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
L_3d478:
    t5 = t5 & 0xffff;
    a3 = 16;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = t5;
    a0 = 0;
L_3d488:
    a2 = v0 + a0;
    t0 = *(volatile u32 *)(unsigned long)(a2 + (196));
    a2 = *(volatile u32 *)(unsigned long)(a1 + (8));
    a2 = a2 + a0;
    a0 = a0 + 4;
    branch = (a0 != a3); *(volatile u32 *)(unsigned long)(a2 + (0)) = t0;
    if (branch) goto L_3d488;
    goto L_3d4a4;
L_3d4a4:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
    a2 = 0x1U << 16; goto L_3d540;
L_3d4b0:
    branch = (t1 != 0); t0 = 0;
    if (branch) goto L_3d544;
    goto L_3d4b8;
L_3d4b8:
    t4 = 16;
L_3d4bc:
    t1 = v0 + t0;
    t5 = *(volatile u32 *)(unsigned long)(t1 + (212));
    t1 = *(volatile u32 *)(unsigned long)(a1 + (8));
    t1 = t1 + t0;
    t0 = t0 + 4;
    branch = (t0 != t4); *(volatile u32 *)(unsigned long)(t1 + (0)) = t5;
    if (branch) goto L_3d4bc;
    goto L_3d4d8;
L_3d4d8:
    t1 = *(volatile u32 *)(unsigned long)(a1 + (12));
    t0 = 0x1U << 16;
    *(volatile u32 *)(unsigned long)(t1 + (4)) = t0;
    t1 = 1;
    if (t7 != t1) { a0 = v0 + 3322; goto L_3d548; }
    goto L_3d4f0;
L_3d4f0:
    t1 = (u32)a2 < (u32)(t3);
    branch = (t1 != 0); a3 = (u32)a2 < (u32)(a3);
    if (branch) goto L_3d530;
    goto L_3d4fc;
L_3d4fc:
    if (a3 == 0) { a0 = *(volatile u32 *)(unsigned long)(a1 + (12)); goto L_3d53c; }
    goto L_3d504;
L_3d504:
    t4 = *(volatile u32 *)(unsigned long)(v1 + (28684));
    a2 = a2 - t3;
    a3 = a0 << (0x10 & 31);
    t0 = t0 - t4;
    t3 = t0 * a2;
    t1 = *(volatile u32 *)(unsigned long)(a1 + (12));
    a2 = a3 - t3;
    if (a0) { lo = a2 / a0; hi = a2 % a0; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    *(volatile u32 *)(unsigned long)(t1 + (4)) = a2; goto L_3d544;
L_3d530:
    branch = (a3 != 0); a0 = v0 + 3322;
    if (branch) goto L_3d548;
    goto L_3d538;
L_3d538:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (12));
L_3d53c:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (28684));
L_3d540:
    *(volatile u32 *)(unsigned long)(a0 + (4)) = a2;
L_3d544:
    a0 = v0 + 3322;
L_3d548:
    *(volatile u32 *)(unsigned long)(a1 + (0)) = a0;
    a0 = v1 + 28688;
    *(volatile u32 *)(unsigned long)(a1 + (4)) = a0;
    a0 = v0 + 3184;
    *(volatile u32 *)(unsigned long)(a1 + (20)) = a0;
    a0 = v0 + 60;
    *(volatile u32 *)(unsigned long)(a1 + (24)) = a0;
    a0 = v0 + 120;
    *(volatile u32 *)(unsigned long)(a1 + (28)) = a0;
    a0 = v0 + 2164;
    *(volatile u32 *)(unsigned long)(a1 + (32)) = a0;
    a0 = v0 + 5714;
    *(volatile u32 *)(unsigned long)(a1 + (36)) = a0;
    a0 = v0 + 244;
    *(volatile u32 *)(unsigned long)(a1 + (40)) = a0;
    a0 = v0 + 44;
    *(volatile u32 *)(unsigned long)(a1 + (44)) = a0;
    a0 = v1 + 28764;
    *(volatile u32 *)(unsigned long)(a1 + (48)) = a0;
    a0 = v0 + 3306;
    *(volatile u32 *)(unsigned long)(a1 + (52)) = a0;
    a0 = v0 + 3448;
    *(volatile u32 *)(unsigned long)(a1 + (56)) = a0;
    a0 = v0 + 3438;
    *(volatile u32 *)(unsigned long)(a1 + (60)) = a0;
    a0 = v0 + 292;
    *(volatile u32 *)(unsigned long)(a1 + (64)) = a0;
    a0 = v0 + 3362;
    *(volatile u32 *)(unsigned long)(a1 + (68)) = a0;
    a0 = v1 + 28708;
    *(volatile u32 *)(unsigned long)(a1 + (72)) = a0;
    a0 = v0 + 324;
    *(volatile u32 *)(unsigned long)(a1 + (76)) = a0;
    a0 = v1 + 28718;
    *(volatile u32 *)(unsigned long)(a1 + (80)) = a0;
    a0 = v1 + 28738;
    *(volatile u32 *)(unsigned long)(a1 + (84)) = a0;
    a0 = v1 + 16384;
    *(volatile u32 *)(unsigned long)(a1 + (136)) = a0;
    a0 = v1 + 24576;
    *(volatile u32 *)(unsigned long)(a1 + (140)) = a0;
    a0 = 0x1U << 16;
    a2 = a0 + 13692;
    a2 = v1 + a2;
    *(volatile u32 *)(unsigned long)(a1 + (144)) = a2;
    a2 = a0 + 14476;
    a3 = v1 + a2;
    *(volatile u32 *)(unsigned long)(a1 + (148)) = a3;
    a3 = a2 + 23480;
    a3 = v1 + a3;
    *(volatile u32 *)(unsigned long)(a1 + (188)) = a3;
    a3 = v0 + 5126;
    *(volatile u32 *)(unsigned long)(a1 + (88)) = a3;
    a3 = v0 + 5166;
    *(volatile u32 *)(unsigned long)(a1 + (92)) = a3;
    a3 = v0 + 52;
    *(volatile u32 *)(unsigned long)(a1 + (96)) = a3;
    a3 = v1 + 29800;
    *(volatile u32 *)(unsigned long)(a1 + (100)) = a3;
    a3 = v0 + 5206;
    *(volatile u32 *)(unsigned long)(a1 + (104)) = a3;
    a3 = v0 + 5226;
    *(volatile u32 *)(unsigned long)(a1 + (112)) = a3;
    t2 = t2 + 4246;
    a3 = v0 + 5234;
    v0 = v0 + 5682;
    *(volatile u32 *)(unsigned long)(a1 + (132)) = v1;
    *(volatile u32 *)(unsigned long)(a1 + (108)) = t2;
    *(volatile u32 *)(unsigned long)(a1 + (116)) = a3;
    *(volatile u32 *)(unsigned long)(a1 + (128)) = v0;
    v0 = a0 + 15260;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a1 + (152)) = v0;
    v0 = a0 + 15652;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a1 + (156)) = v0;
    v0 = a0 + 15796;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a1 + (160)) = v0;
    v0 = a0 + 16516;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a1 + (164)) = v0;
    v0 = a0 + 17476;
    v0 = v1 + v0;
    a3 = 0x9468;
    *(volatile u32 *)(unsigned long)(a1 + (168)) = v0;
    v0 = a0 + 21572;
    a3 = v1 + a3;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(a1 + (120)) = a3;
    *(volatile u32 *)(unsigned long)(a1 + (172)) = v0;
    a3 = 0x947c;
    v0 = a0 + 25668;
    a2 = a2 + 19384;
    a0 = a0 + 29764;
    a3 = v1 + a3;
    v0 = v1 + v0;
    a0 = v1 + a0;
    v1 = v1 + a2;
    s1 = *(volatile u32 *)(unsigned long)(sp + (4));
    s0 = *(volatile u32 *)(unsigned long)(sp + (0));
    *(volatile u32 *)(unsigned long)(a1 + (124)) = a3;
    *(volatile u32 *)(unsigned long)(a1 + (176)) = v0;
    *(volatile u32 *)(unsigned long)(a1 + (180)) = a0;
    *(volatile u32 *)(unsigned long)(a1 + (184)) = v1;
    sp = sp + 8;
    return ((u64)v1 << 32) | v0;
}
