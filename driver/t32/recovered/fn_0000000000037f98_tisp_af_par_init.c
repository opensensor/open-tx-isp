/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1620[] __asm__("t32_data_e1620");
extern unsigned char ref_t32_data_d6014[] __asm__("t32_data_d6014");
extern unsigned char ref_t32_data_d5c90[] __asm__("t32_data_d5c90");
extern unsigned char ref_t32_data_e1600[] __asm__("t32_data_e1600");
u64 tisp_af_par_init(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_37f98 = ((u32)(unsigned long)ref_t32_data_e1620 + 0x8000U) & 0xffff0000U;
    const u32 hi_382a4 = ((u32)(unsigned long)ref_t32_data_d6014 + 0x8000U) & 0xffff0000U;
    const u32 hi_38324 = ((u32)(unsigned long)ref_t32_data_d5c90 + 0x8000U) & 0xffff0000U;
    const u32 hi_38070 = ((u32)(unsigned long)ref_t32_data_e1600 + 0x8000U) & 0xffff0000U;
    const u32 hi_383f4 = ((u32)(unsigned long)ref_t32_data_d6014 + 0x8000U) & 0xffff0000U;
    const u32 hi_38478 = ((u32)(unsigned long)ref_t32_data_d5c90 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
L_37f98:
    v0 = hi_37f98;
    a0 = a0 << (0x2 & 31);
    v0 = v0 - hi_37f98 + (u32)(unsigned long)ref_t32_data_e1620;
    v0 = a0 + v0;
    sp = sp + -72;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a2 = *(volatile u16 *)(unsigned long)(v0 + (16));
    a1 = *(volatile u16 *)(unsigned long)(v0 + (18));
    a3 = *(volatile u16 *)(unsigned long)(v1 + (84));
    t3 = *(volatile u16 *)(unsigned long)(v1 + (86));
    t2 = v1 + 80;
    a2 = a2 - a3;
    a2 = a2 + -14;
    if (a2 == 0x80000000U && t3 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t3) { lo = (s32)a2 / (s32)t3; hi = (s32)a2 % (s32)t3; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    t4 = *(volatile u16 *)(unsigned long)(v1 + (80));
    a2 = lo;
    a2 = a2 & 0xffff;
    a3 = a2 & 0x1;
    branch = (a3 == 0); t1 = *(volatile u16 *)(unsigned long)(v1 + (82));
    if (branch) goto L_37ff4;
    goto L_37fec;
L_37fec:
    a2 = a2 + -1;
    a2 = a2 & 0xffff;
L_37ff4:
    a3 = 0;
L_37ff8:
    t0 = (u32)a3 < (u32)(t3);
    branch = (t0 == 0); t0 = a3 + 4;
    if (branch) goto L_3801c;
    goto L_38004;
L_38004:
    t0 = t0 << (0x1 & 31);
    t0 = t2 + t0;
    a3 = a3 + 1;
    *(volatile u16 *)(unsigned long)(t0 + (0)) = a2;
    a3 = a3 & 0xff; goto L_37ff8;
L_3801c:
    a1 = a1 - t4;
    a1 = a1 + -2;
    if (a1 == 0x80000000U && t1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t1) { lo = (s32)a1 / (s32)t1; hi = (s32)a1 % (s32)t1; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = lo;
    a1 = a1 & 0xffff;
    a2 = a1 & 0x1;
    branch = (a2 == 0); a2 = 0;
    if (branch) goto L_38044;
    goto L_3803c;
L_3803c:
    a1 = a1 + -1;
    a1 = a1 & 0xffff;
L_38044:
    a3 = (u32)a2 < (u32)(t1);
    branch = (a3 == 0); a3 = a2 + 19;
    if (branch) goto L_38068;
    goto L_38050;
L_38050:
    a3 = a3 << (0x1 & 31);
    a3 = t2 + a3;
    a2 = a2 + 1;
    *(volatile u16 *)(unsigned long)(a3 + (0)) = a1;
    a2 = a2 & 0xff; goto L_38044;
L_38068:
    a1 = *(volatile u8 *)(unsigned long)(v1 + (768));
    if (a1 != 0) { a1 = hi_38070; goto L_383e8; }
    goto L_38074;
L_38074:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (368));
    a0 = (u32)a0 < (u32)(6);
    if (a0 != 0) { t5 = *(volatile u16 *)(unsigned long)(v1 + (424)); goto L_38090; }
    goto L_38084;
L_38084:
    a0 = 5;
    *(volatile u16 *)(unsigned long)(v1 + (368)) = a0;
    t5 = *(volatile u16 *)(unsigned long)(v1 + (424));
L_38090:
    a0 = (u32)t5 < (u32)(6);
    if (a0 != 0) { a0 = *(volatile u16 *)(unsigned long)(v1 + (284)); goto L_380a8; }
    goto L_3809c;
L_3809c:
    a0 = 5;
    *(volatile u16 *)(unsigned long)(v1 + (368)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (284));
L_380a8:
    a0 = (u32)a0 < (u32)(9);
    if (a0 != 0) { a0 = *(volatile u16 *)(unsigned long)(v1 + (326)); goto L_380c0; }
    goto L_380b4;
L_380b4:
    a0 = 8;
    *(volatile u16 *)(unsigned long)(v1 + (284)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (326));
L_380c0:
    a0 = (u32)a0 < (u32)(9);
    if (a0 != 0) { a0 = *(volatile u16 *)(unsigned long)(v1 + (370)); goto L_380d8; }
    goto L_380cc;
L_380cc:
    a0 = 8;
    *(volatile u16 *)(unsigned long)(v1 + (326)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (370));
L_380d8:
    a0 = (u32)a0 < (u32)(7);
    if (a0 != 0) { a0 = *(volatile u16 *)(unsigned long)(v1 + (426)); goto L_380f0; }
    goto L_380e4;
L_380e4:
    a0 = 6;
    *(volatile u16 *)(unsigned long)(v1 + (370)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (426));
L_380f0:
    a1 = (u32)a0 < (u32)(7);
    if (a1 != 0) { a1 = *(volatile u16 *)(unsigned long)(v1 + (286)); goto L_38108; }
    goto L_380fc;
L_380fc:
    a1 = 6;
    *(volatile u16 *)(unsigned long)(v1 + (370)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (286));
L_38108:
    a1 = (u32)a1 < (u32)(10);
    if (a1 != 0) { a1 = *(volatile u16 *)(unsigned long)(v1 + (328)); goto L_38120; }
    goto L_38114;
L_38114:
    a1 = 9;
    *(volatile u16 *)(unsigned long)(v1 + (286)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (328));
L_38120:
    a1 = (u32)a1 < (u32)(10);
    if (a1 != 0) { t2 = *(volatile u16 *)(unsigned long)(v1 + (368)); goto L_38138; }
    goto L_3812c;
L_3812c:
    a1 = 9;
    *(volatile u16 *)(unsigned long)(v1 + (328)) = a1;
    t2 = *(volatile u16 *)(unsigned long)(v1 + (368));
L_38138:
    a1 = *(volatile u16 *)(unsigned long)(v1 + (370));
    a1 = (u32)t2 < (u32)(a1);
    branch = (a1 != 0); a0 = (u32)t5 < (u32)(a0);
    if (branch) goto L_38150;
    goto L_38148;
L_38148:
    a1 = t2 + 1;
    *(volatile u16 *)(unsigned long)(v1 + (370)) = a1;
L_38150:
    if (a0 != 0) { t4 = *(volatile u16 *)(unsigned long)(v1 + (284)); goto L_38164; }
    goto L_38158;
L_38158:
    a0 = t5 + 1;
    *(volatile u16 *)(unsigned long)(v1 + (426)) = a0;
    t4 = *(volatile u16 *)(unsigned long)(v1 + (284));
L_38164:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (286));
    a0 = (u32)t4 < (u32)(a0);
    if (a0 != 0) { t3 = *(volatile u16 *)(unsigned long)(v1 + (326)); goto L_38180; }
    goto L_38174;
L_38174:
    a0 = t4 + 1;
    *(volatile u16 *)(unsigned long)(v1 + (286)) = a0;
    t3 = *(volatile u16 *)(unsigned long)(v1 + (326));
L_38180:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (328));
    a0 = (u32)t3 < (u32)(a0);
    if (a0 != 0) { t0 = *(volatile u16 *)(unsigned long)(v1 + (370)); goto L_3819c; }
    goto L_38190;
L_38190:
    a0 = t3 + 1;
    *(volatile u16 *)(unsigned long)(v1 + (328)) = a0;
    t0 = *(volatile u16 *)(unsigned long)(v1 + (370));
L_3819c:
    a3 = *(volatile u16 *)(unsigned long)(v1 + (426));
    a2 = *(volatile u16 *)(unsigned long)(v1 + (286));
    t6 = *(volatile u16 *)(unsigned long)(v1 + (328));
    t0 = t0 - t2;
    t0 = t0 & 0xffff;
    a3 = a3 - t5;
    a2 = a2 - t4;
    t6 = t6 - t3;
    a3 = a3 & 0xffff;
    a2 = a2 & 0xffff;
    t6 = t6 & 0xffff;
    a1 = 0;
    t1 = 0;
    t0 = t0 + -1;
    t7 = 6;
L_381d8:
    a0 = (s32)t1 < (s32)(t0);
    branch = (a0 == 0); a0 = t7 - t1;
    if (branch) goto L_381f8;
    goto L_381e4;
L_381e4:
    a1 = a1 + a0;
    t1 = t1 + 1;
    a1 = a1 & 0xffff;
    t1 = t1 & 0xff; goto L_381d8;
L_381f8:
    a0 = 0;
    t0 = 0;
    a3 = a3 + -1;
    t7 = 6;
L_38208:
    t1 = (s32)t0 < (s32)(a3);
    branch = (t1 == 0); t1 = t7 - t0;
    if (branch) goto L_38228;
    goto L_38214;
L_38214:
    a0 = a0 + t1;
    t0 = t0 + 1;
    a0 = a0 & 0xffff;
    t0 = t0 & 0xff; goto L_38208;
L_38228:
    t1 = 0;
    a3 = 0;
    a2 = a2 + -1;
    t7 = 9;
L_38238:
    t0 = (s32)a3 < (s32)(a2);
    branch = (t0 == 0); t0 = t7 - a3;
    if (branch) goto L_38258;
    goto L_38244;
L_38244:
    t1 = t1 + t0;
    a3 = a3 + 1;
    t1 = t1 & 0xffff;
    a3 = a3 & 0xff; goto L_38238;
L_38258:
    a2 = 0;
    t0 = 0;
    t6 = t6 + -1;
    t7 = 9;
L_38268:
    a3 = (s32)t0 < (s32)(t6);
    branch = (a3 == 0); a3 = t7 - t0;
    if (branch) goto L_38288;
    goto L_38274;
L_38274:
    a3 = a2 + a3;
    t0 = t0 + 1;
    a2 = a3 & 0xffff;
    t0 = t0 & 0xff; goto L_38268;
L_38288:
    a1 = a1 + t2;
    t0 = 12;
    a1 = a1 & 0xffff;
    a1 = a1 * t0;
    a0 = a0 + t5;
L_3829c:
    t4 = t1 + t4;
    a2 = a2 + t3;
    t1 = hi_382a4;
    a3 = a0 & 0xffff;
    a2 = a2 & 0xffff;
    a0 = t4 & 0xffff;
    t3 = sp + 24;
    t0 = 0;
    t1 = t1 - hi_382a4 + (u32)(unsigned long)ref_t32_data_d6014;
    t5 = 48;
    a1 = a1 << (0x2 & 31);
L_382c8:
    t2 = a1 + t0;
    t2 = t1 + t2;
    t2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    t0 = t0 + 4;
    t3 = t3 + 2;
    *(volatile u16 *)(unsigned long)(t3 + (-2)) = t2;
    branch = (t0 != t5); t4 = t1;
    if (branch) goto L_382c8;
    goto L_382e8;
L_382e8:
    a1 = 12;
    a1 = a3 * a1;
    t0 = sp;
    a3 = 0;
    t2 = 48;
    a1 = a1 << (0x2 & 31);
L_38300:
    t1 = a1 + a3;
    t1 = t4 + t1;
    t1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    a3 = a3 + 4;
    t0 = t0 + 2;
    branch = (a3 != t2); *(volatile u16 *)(unsigned long)(t0 + (-2)) = t1;
    if (branch) goto L_38300;
    goto L_3831c;
L_3831c:
    a1 = a0 << (0x2 & 31);
    a0 = a1 + a0;
    a3 = hi_38324;
    t0 = sp + 60;
    a0 = a0 << (0x2 & 31);
    a1 = 0;
    a3 = a3 - hi_38324 + (u32)(unsigned long)ref_t32_data_d5c90;
    t2 = 20;
L_3833c:
    t1 = a0 + a1;
    t1 = a3 + t1;
    t1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    a1 = a1 + 4;
    t0 = t0 + 2;
    *(volatile u16 *)(unsigned long)(t0 + (-2)) = t1;
    branch = (a1 != t2); t1 = a3;
    if (branch) goto L_3833c;
    goto L_3835c;
L_3835c:
    a0 = a2 << (0x2 & 31);
    a2 = a0 + a2;
    a1 = sp + 48;
    a2 = a2 << (0x2 & 31);
    a0 = 0;
    t0 = 20;
L_38374:
    a3 = a2 + a0;
    a3 = t1 + a3;
    a3 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a0 = a0 + 4;
    a1 = a1 + 2;
    branch = (a0 != t0); *(volatile u16 *)(unsigned long)(a1 + (-2)) = a3;
    if (branch) goto L_38374;
    goto L_38390;
L_38390:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
L_38394:
    t5 = *(volatile u16 *)(unsigned long)(sp + (64));
    t4 = *(volatile u16 *)(unsigned long)(sp + (66));
    t3 = *(volatile u16 *)(unsigned long)(sp + (68));
    *(volatile u16 *)(unsigned long)(a0 + (288)) = t5;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    t2 = *(volatile u16 *)(unsigned long)(sp + (52));
    t1 = *(volatile u16 *)(unsigned long)(sp + (54));
    *(volatile u16 *)(unsigned long)(a0 + (290)) = t4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    t0 = *(volatile u16 *)(unsigned long)(sp + (56));
    a1 = sp + 24;
    *(volatile u16 *)(unsigned long)(a0 + (292)) = t3;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    t6 = 12;
    *(volatile u16 *)(unsigned long)(a0 + (330)) = t2;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    *(volatile u16 *)(unsigned long)(a0 + (332)) = t1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    *(volatile u16 *)(unsigned long)(a0 + (334)) = t0;
    a0 = 2; goto L_384e4;
L_383e8:
    a1 = a1 - hi_38070 + (u32)(unsigned long)ref_t32_data_e1600;
    a0 = a1 + a0;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (2));
    a3 = hi_383f4;
    t0 = sp + 24;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a1;
    a1 = v1 + a1;
    t2 = *(volatile u8 *)(unsigned long)(a1 + (786));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (773));
    a0 = 12;
    a2 = 0;
    a1 = a1 * a0;
    a3 = a3 - hi_383f4 + (u32)(unsigned long)ref_t32_data_d6014;
    a0 = 48;
    a1 = a1 << (0x2 & 31);
L_38424:
    t1 = a1 + a2;
    t1 = a3 + t1;
    t1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    a2 = a2 + 4;
    t0 = t0 + 2;
    *(volatile u16 *)(unsigned long)(t0 + (-2)) = t1;
    branch = (a2 != a0); t1 = a3;
    if (branch) goto L_38424;
    goto L_38444;
L_38444:
    a3 = sp;
    a1 = a1 + 48;
    a2 = 0;
    a0 = 48;
L_38454:
    t0 = a1 + a2;
    t0 = t1 + t0;
    t0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    a2 = a2 + 4;
    a3 = a3 + 2;
    branch = (a2 != a0); *(volatile u16 *)(unsigned long)(a3 + (-2)) = t0;
    if (branch) goto L_38454;
    goto L_38470;
L_38470:
    a0 = t2 << (0x2 & 31);
    a0 = a0 + t2;
    a2 = hi_38478;
    a3 = sp + 60;
    a0 = a0 << (0x2 & 31);
    a1 = 0;
    a2 = a2 - hi_38478 + (u32)(unsigned long)ref_t32_data_d5c90;
    t2 = 20;
L_38490:
    t0 = a0 + a1;
    t0 = a2 + t0;
    t0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    a1 = a1 + 4;
    a3 = a3 + 2;
    *(volatile u16 *)(unsigned long)(a3 + (-2)) = t0;
    branch = (a1 != t2); t1 = a2;
    if (branch) goto L_38490;
    goto L_384b0;
L_384b0:
    a2 = sp + 48;
    a0 = a0 + 20;
    a1 = 0;
    t0 = 20;
L_384c0:
    a3 = a0 + a1;
    a3 = t1 + a3;
    a3 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a1 = a1 + 4;
    a2 = a2 + 2;
    branch = (a1 != t0); *(volatile u16 *)(unsigned long)(a2 + (-2)) = a3;
    if (branch) goto L_384c0;
    goto L_384dc;
L_384dc:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12)); goto L_38394;
L_384e4:
    a3 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a2 = a0 + 184;
    a2 = a2 << (0x1 & 31);
    a2 = a3 + a2;
    a3 = *(volatile u16 *)(unsigned long)(a1 + (4));
    a0 = a0 + 1;
    a1 = a1 + 2;
    branch = (a0 != t6); *(volatile u16 *)(unsigned long)(a2 + (0)) = a3;
    if (branch) goto L_384e4;
    goto L_38508;
L_38508:
    a1 = sp;
    a0 = 2;
    t6 = 12;
L_38514:
    a3 = *(volatile u32 *)(unsigned long)(v0 + (12));
    a2 = a0 + 208;
    a2 = a2 << (0x1 & 31);
    a2 = a3 + a2;
    a3 = *(volatile u16 *)(unsigned long)(a1 + (4));
    a0 = a0 + 1;
    a1 = a1 + 2;
    branch = (a0 != t6); *(volatile u16 *)(unsigned long)(a2 + (8)) = a3;
    if (branch) goto L_38514;
    goto L_38538;
L_38538:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (86));
    *(volatile u8 *)(unsigned long)(a0 + (0)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (82));
    *(volatile u8 *)(unsigned long)(a0 + (1)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (84));
    *(volatile u16 *)(unsigned long)(a0 + (2)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (88));
    *(volatile u16 *)(unsigned long)(a0 + (4)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (90));
    *(volatile u16 *)(unsigned long)(a0 + (6)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (92));
    *(volatile u16 *)(unsigned long)(a0 + (8)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (94));
    *(volatile u16 *)(unsigned long)(a0 + (10)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (96));
    *(volatile u16 *)(unsigned long)(a0 + (12)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (98));
    *(volatile u16 *)(unsigned long)(a0 + (14)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (100));
    *(volatile u16 *)(unsigned long)(a0 + (16)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (100));
    *(volatile u16 *)(unsigned long)(a0 + (18)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (104));
    *(volatile u16 *)(unsigned long)(a0 + (20)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (106));
    *(volatile u16 *)(unsigned long)(a0 + (22)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (108));
    *(volatile u16 *)(unsigned long)(a0 + (24)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (110));
    *(volatile u16 *)(unsigned long)(a0 + (26)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (112));
    *(volatile u16 *)(unsigned long)(a0 + (28)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (114));
    *(volatile u16 *)(unsigned long)(a0 + (30)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (116));
    *(volatile u16 *)(unsigned long)(a0 + (32)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (80));
    *(volatile u16 *)(unsigned long)(a0 + (34)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (118));
    *(volatile u8 *)(unsigned long)(a0 + (36)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (120));
    *(volatile u8 *)(unsigned long)(a0 + (37)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (122));
    *(volatile u8 *)(unsigned long)(a0 + (38)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (124));
    *(volatile u8 *)(unsigned long)(a0 + (39)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (126));
    *(volatile u8 *)(unsigned long)(a0 + (40)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (128));
    *(volatile u8 *)(unsigned long)(a0 + (41)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (130));
    *(volatile u8 *)(unsigned long)(a0 + (42)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (130));
    *(volatile u8 *)(unsigned long)(a0 + (43)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (134));
    *(volatile u8 *)(unsigned long)(a0 + (44)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (136));
    *(volatile u8 *)(unsigned long)(a0 + (45)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (138));
    *(volatile u8 *)(unsigned long)(a0 + (46)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (140));
    *(volatile u8 *)(unsigned long)(a0 + (47)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (142));
    *(volatile u8 *)(unsigned long)(a0 + (48)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (144));
    *(volatile u8 *)(unsigned long)(a0 + (49)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (146));
    *(volatile u8 *)(unsigned long)(a0 + (50)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (60));
    *(volatile u16 *)(unsigned long)(a0 + (52)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (62));
    *(volatile u16 *)(unsigned long)(a0 + (54)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (48));
    *(volatile u16 *)(unsigned long)(a0 + (56)) = t5;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (58)) = t4;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (60)) = t3;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (62)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (50));
    *(volatile u16 *)(unsigned long)(a0 + (64)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = 15;
    *(volatile u16 *)(unsigned long)(a0 + (66)) = t2;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (68)) = t1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u16 *)(unsigned long)(a0 + (70)) = t0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(a0 + (72)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (24));
    *(volatile u16 *)(unsigned long)(a0 + (74)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (28));
    *(volatile u16 *)(unsigned long)(a0 + (76)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (30));
    *(volatile u16 *)(unsigned long)(a0 + (78)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (32));
    *(volatile u16 *)(unsigned long)(a0 + (80)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (34));
    *(volatile u16 *)(unsigned long)(a0 + (82)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (38));
    *(volatile u16 *)(unsigned long)(a0 + (84)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (40));
    *(volatile u16 *)(unsigned long)(a0 + (86)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (42));
    *(volatile u16 *)(unsigned long)(a0 + (88)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (44));
    *(volatile u16 *)(unsigned long)(a0 + (90)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (46));
    *(volatile u16 *)(unsigned long)(a0 + (92)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (0));
    *(volatile u16 *)(unsigned long)(a0 + (94)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (4));
    *(volatile u16 *)(unsigned long)(a0 + (96)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (6));
    *(volatile u16 *)(unsigned long)(a0 + (98)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (8));
    *(volatile u16 *)(unsigned long)(a0 + (100)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (10));
    *(volatile u16 *)(unsigned long)(a0 + (102)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (14));
    *(volatile u16 *)(unsigned long)(a0 + (104)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (16));
    *(volatile u16 *)(unsigned long)(a0 + (106)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (18));
    *(volatile u16 *)(unsigned long)(a0 + (108)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (20));
    *(volatile u16 *)(unsigned long)(a0 + (110)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(sp + (22));
    *(volatile u16 *)(unsigned long)(a0 + (112)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (523));
    *(volatile u8 *)(unsigned long)(a0 + (114)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (294));
    *(volatile u8 *)(unsigned long)(a0 + (115)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (296));
    *(volatile u8 *)(unsigned long)(a0 + (116)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (298));
    *(volatile u16 *)(unsigned long)(a0 + (118)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (300));
    *(volatile u8 *)(unsigned long)(a0 + (120)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (302));
    *(volatile u8 *)(unsigned long)(a0 + (121)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (304));
    *(volatile u8 *)(unsigned long)(a0 + (122)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (306));
    *(volatile u16 *)(unsigned long)(a0 + (124)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (308));
    *(volatile u8 *)(unsigned long)(a0 + (126)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (524));
    *(volatile u8 *)(unsigned long)(a0 + (127)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (336));
    *(volatile u8 *)(unsigned long)(a0 + (128)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (338));
    *(volatile u8 *)(unsigned long)(a0 + (129)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (340));
    *(volatile u16 *)(unsigned long)(a0 + (130)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (342));
    *(volatile u8 *)(unsigned long)(a0 + (132)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (344));
    *(volatile u8 *)(unsigned long)(a0 + (133)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (346));
    *(volatile u8 *)(unsigned long)(a0 + (134)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (348));
    *(volatile u16 *)(unsigned long)(a0 + (136)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (350));
    *(volatile u8 *)(unsigned long)(a0 + (138)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (525));
    *(volatile u8 *)(unsigned long)(a0 + (139)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (392));
    *(volatile u8 *)(unsigned long)(a0 + (140)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (394));
    *(volatile u8 *)(unsigned long)(a0 + (141)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (396));
    *(volatile u16 *)(unsigned long)(a0 + (142)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (398));
    *(volatile u8 *)(unsigned long)(a0 + (144)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (400));
    *(volatile u8 *)(unsigned long)(a0 + (145)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (402));
    *(volatile u8 *)(unsigned long)(a0 + (146)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (404));
    *(volatile u16 *)(unsigned long)(a0 + (148)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (406));
    *(volatile u8 *)(unsigned long)(a0 + (150)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (526));
    *(volatile u8 *)(unsigned long)(a0 + (151)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (448));
    *(volatile u8 *)(unsigned long)(a0 + (152)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (450));
    *(volatile u8 *)(unsigned long)(a0 + (153)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (452));
    *(volatile u16 *)(unsigned long)(a0 + (154)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (454));
    *(volatile u8 *)(unsigned long)(a0 + (156)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (456));
    *(volatile u8 *)(unsigned long)(a0 + (157)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (458));
    *(volatile u8 *)(unsigned long)(a0 + (158)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (460));
    *(volatile u16 *)(unsigned long)(a0 + (160)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (462));
    *(volatile u8 *)(unsigned long)(a0 + (162)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (527));
    *(volatile u8 *)(unsigned long)(a0 + (163)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (310));
    *(volatile u8 *)(unsigned long)(a0 + (164)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (312));
    *(volatile u8 *)(unsigned long)(a0 + (165)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (314));
    *(volatile u8 *)(unsigned long)(a0 + (166)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (316));
    *(volatile u8 *)(unsigned long)(a0 + (167)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (528));
    *(volatile u8 *)(unsigned long)(a0 + (168)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (352));
    *(volatile u8 *)(unsigned long)(a0 + (169)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (354));
    *(volatile u8 *)(unsigned long)(a0 + (170)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (356));
    *(volatile u8 *)(unsigned long)(a0 + (171)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (358));
    *(volatile u8 *)(unsigned long)(a0 + (172)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (529));
    *(volatile u8 *)(unsigned long)(a0 + (173)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (408));
    *(volatile u8 *)(unsigned long)(a0 + (174)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (410));
    *(volatile u8 *)(unsigned long)(a0 + (175)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (412));
    *(volatile u8 *)(unsigned long)(a0 + (176)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (414));
    *(volatile u8 *)(unsigned long)(a0 + (177)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (530));
    *(volatile u8 *)(unsigned long)(a0 + (178)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (464));
    *(volatile u8 *)(unsigned long)(a0 + (179)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (466));
    *(volatile u8 *)(unsigned long)(a0 + (180)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (468));
    *(volatile u8 *)(unsigned long)(a0 + (181)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (470));
    *(volatile u8 *)(unsigned long)(a0 + (182)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (531));
    *(volatile u8 *)(unsigned long)(a0 + (183)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (532));
    *(volatile u8 *)(unsigned long)(a0 + (184)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (533));
    *(volatile u8 *)(unsigned long)(a0 + (185)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (534));
    *(volatile u8 *)(unsigned long)(a0 + (186)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (535));
    *(volatile u8 *)(unsigned long)(a0 + (187)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (536));
    *(volatile u8 *)(unsigned long)(a0 + (188)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (318));
    *(volatile u8 *)(unsigned long)(a0 + (189)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (320));
    *(volatile u8 *)(unsigned long)(a0 + (190)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (322));
    *(volatile u16 *)(unsigned long)(a0 + (192)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (324));
    *(volatile u16 *)(unsigned long)(a0 + (194)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (537));
    *(volatile u8 *)(unsigned long)(a0 + (196)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (360));
    *(volatile u8 *)(unsigned long)(a0 + (197)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (362));
    *(volatile u8 *)(unsigned long)(a0 + (198)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (364));
    *(volatile u16 *)(unsigned long)(a0 + (200)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (366));
    *(volatile u16 *)(unsigned long)(a0 + (202)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (538));
    *(volatile u8 *)(unsigned long)(a0 + (204)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (416));
    *(volatile u8 *)(unsigned long)(a0 + (205)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (418));
    *(volatile u8 *)(unsigned long)(a0 + (206)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (420));
    *(volatile u16 *)(unsigned long)(a0 + (208)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (422));
    *(volatile u16 *)(unsigned long)(a0 + (210)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u8 *)(unsigned long)(v1 + (539));
    *(volatile u8 *)(unsigned long)(a0 + (212)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (472));
    *(volatile u8 *)(unsigned long)(a0 + (213)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (474));
    *(volatile u8 *)(unsigned long)(a0 + (214)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a1 = *(volatile u16 *)(unsigned long)(v1 + (476));
    *(volatile u16 *)(unsigned long)(a0 + (216)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (478));
    *(volatile u16 *)(unsigned long)(a0 + (218)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    a0 = 1;
    *(volatile u8 *)(unsigned long)(v1 + (220)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u8 *)(unsigned long)(v0 + (221)) = 0;
    sp = sp + 72;
    return ((u64)v1 << 32) | v0;
}
