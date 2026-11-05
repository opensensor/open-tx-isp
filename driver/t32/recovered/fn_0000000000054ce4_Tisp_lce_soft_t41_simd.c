/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
extern unsigned char ref_t32_data_bf860[] __asm__("t32_data_bf860");
extern unsigned char ref_t32_data_ce1f0[] __asm__("t32_data_ce1f0");
extern unsigned char ref_t32_data_ce1e0[] __asm__("t32_data_ce1e0");
extern unsigned char ref_lce_hist_filter_and_judge[] __asm__("lce_hist_filter_and_judge");
extern unsigned char ref_lce_hist_method[] __asm__("lce_hist_method");
extern unsigned char ref_lce_pdf_to_cdf[] __asm__("lce_pdf_to_cdf");
extern unsigned char ref_lce_self_light_correct_local[] __asm__("lce_self_light_correct_local");
extern unsigned char ref_lce_16bit_data_converge[] __asm__("lce_16bit_data_converge");
extern unsigned char ref_t32_data_ce140[] __asm__("t32_data_ce140");
extern unsigned char ref_t32_data_ce150[] __asm__("t32_data_ce150");
extern unsigned char ref_t32_data_ce160[] __asm__("t32_data_ce160");
extern unsigned char ref_t32_data_ce170[] __asm__("t32_data_ce170");
extern unsigned char ref_t32_data_ce1d0[] __asm__("t32_data_ce1d0");
extern unsigned char ref_t32_data_e1d64[] __asm__("t32_data_e1d64");
extern unsigned char ref_t32_data_e1d54[] __asm__("t32_data_e1d54");
extern unsigned char ref_t32_data_e1b54[] __asm__("t32_data_e1b54");
extern unsigned char ref_t32_data_e1b44[] __asm__("t32_data_e1b44");
extern unsigned char ref_lce_hist_filter_and_judge_16bit[] __asm__("lce_hist_filter_and_judge_16bit");
extern unsigned char ref_t32_data_bf9a8[] __asm__("t32_data_bf9a8");
extern unsigned char ref_t32_data_e1a74[] __asm__("t32_data_e1a74");
extern unsigned char ref_t32_data_e1a84[] __asm__("t32_data_e1a84");
extern unsigned char ref_t32_data_e19f4[] __asm__("t32_data_e19f4");
extern unsigned char ref_t32_data_e1aa4[] __asm__("t32_data_e1aa4");
extern unsigned char ref_t32_data_e1ac4[] __asm__("t32_data_e1ac4");
extern unsigned char ref_t32_data_e1ae4[] __asm__("t32_data_e1ae4");
extern unsigned char ref_t32_data_e1b04[] __asm__("t32_data_e1b04");
extern unsigned char ref_t32_data_e1b14[] __asm__("t32_data_e1b14");
extern unsigned char ref_t32_data_e1b24[] __asm__("t32_data_e1b24");
extern unsigned char ref_t32_data_e1b34[] __asm__("t32_data_e1b34");
extern unsigned char ref_t32_data_e1a14[] __asm__("t32_data_e1a14");
extern unsigned char ref_t32_data_e1a34[] __asm__("t32_data_e1a34");
extern unsigned char ref_t32_data_e1a54[] __asm__("t32_data_e1a54");
extern unsigned char ref_t32_data_e1954[] __asm__("t32_data_e1954");
extern unsigned char ref_t32_data_e18b4[] __asm__("t32_data_e18b4");
extern unsigned char ref_lce_self_light_correct_local_simd_test[] __asm__("lce_self_light_correct_local_simd_test");
extern unsigned char ref_t32_data_e18a4[] __asm__("t32_data_e18a4");
extern unsigned char ref_t32_data_ce1b0[] __asm__("t32_data_ce1b0");
extern unsigned char ref_t32_data_ce1c0[] __asm__("t32_data_ce1c0");
extern unsigned char ref_t32_data_ce1a0[] __asm__("t32_data_ce1a0");
extern unsigned char ref_t32_data_ce210[] __asm__("t32_data_ce210");
extern unsigned char ref_t32_data_ce190[] __asm__("t32_data_ce190");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 Tisp_lce_soft_t41_simd(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[236] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_54d6c = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_54f1c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_54f40 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_54f18 = ((u32)(unsigned long)ref_t32_data_bf860 + 0x8000U) & 0xffff0000U;
    const u32 hi_54fb0 = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_54fb4 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_550b4 = ((u32)(unsigned long)ref_lce_hist_filter_and_judge + 0x8000U) & 0xffff0000U;
    const u32 hi_551a8 = ((u32)(unsigned long)ref_lce_hist_method + 0x8000U) & 0xffff0000U;
    const u32 hi_551bc = ((u32)(unsigned long)ref_lce_pdf_to_cdf + 0x8000U) & 0xffff0000U;
    const u32 hi_55204 = ((u32)(unsigned long)ref_lce_self_light_correct_local + 0x8000U) & 0xffff0000U;
    const u32 hi_55234 = ((u32)(unsigned long)ref_lce_16bit_data_converge + 0x8000U) & 0xffff0000U;
    const u32 hi_55268 = ((u32)(unsigned long)ref_t32_data_ce140 + 0x8000U) & 0xffff0000U;
    const u32 hi_5526c = ((u32)(unsigned long)ref_t32_data_ce150 + 0x8000U) & 0xffff0000U;
    const u32 hi_55270 = ((u32)(unsigned long)ref_t32_data_ce160 + 0x8000U) & 0xffff0000U;
    const u32 hi_55274 = ((u32)(unsigned long)ref_t32_data_ce170 + 0x8000U) & 0xffff0000U;
    const u32 hi_552ac = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_55354 = ((u32)(unsigned long)ref_t32_data_e1d64 + 0x8000U) & 0xffff0000U;
    const u32 hi_55358 = ((u32)(unsigned long)ref_t32_data_e1d54 + 0x8000U) & 0xffff0000U;
    const u32 hi_55560 = ((u32)(unsigned long)ref_t32_data_e1b54 + 0x8000U) & 0xffff0000U;
    const u32 hi_55570 = ((u32)(unsigned long)ref_t32_data_e1b44 + 0x8000U) & 0xffff0000U;
    const u32 hi_555cc = ((u32)(unsigned long)ref_lce_hist_filter_and_judge_16bit + 0x8000U) & 0xffff0000U;
    const u32 hi_55638 = ((u32)(unsigned long)ref_t32_data_bf9a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_5564c = ((u32)(unsigned long)ref_t32_data_e1a74 + 0x8000U) & 0xffff0000U;
    const u32 hi_5565c = ((u32)(unsigned long)ref_t32_data_e1a84 + 0x8000U) & 0xffff0000U;
    const u32 hi_5566c = ((u32)(unsigned long)ref_t32_data_e19f4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5585c = ((u32)(unsigned long)ref_t32_data_e1aa4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5586c = ((u32)(unsigned long)ref_t32_data_e1ac4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5587c = ((u32)(unsigned long)ref_t32_data_e1ae4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5598c = ((u32)(unsigned long)ref_t32_data_e1b04 + 0x8000U) & 0xffff0000U;
    const u32 hi_559cc = ((u32)(unsigned long)ref_t32_data_e1b14 + 0x8000U) & 0xffff0000U;
    const u32 hi_559e0 = ((u32)(unsigned long)ref_t32_data_e1b24 + 0x8000U) & 0xffff0000U;
    const u32 hi_559ec = ((u32)(unsigned long)ref_t32_data_e1b34 + 0x8000U) & 0xffff0000U;
    const u32 hi_55a40 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_55b0c = ((u32)(unsigned long)ref_t32_data_e1a14 + 0x8000U) & 0xffff0000U;
    const u32 hi_55b28 = ((u32)(unsigned long)ref_t32_data_e1a34 + 0x8000U) & 0xffff0000U;
    const u32 hi_55b3c = ((u32)(unsigned long)ref_t32_data_e1a54 + 0x8000U) & 0xffff0000U;
    const u32 hi_55c90 = ((u32)(unsigned long)ref_t32_data_e1954 + 0x8000U) & 0xffff0000U;
    const u32 hi_55d9c = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_55da8 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_55efc = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_55f00 = ((u32)(unsigned long)ref_t32_data_e18b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_55f50 = ((u32)(unsigned long)ref_lce_self_light_correct_local_simd_test + 0x8000U) & 0xffff0000U;
    const u32 hi_55f78 = ((u32)(unsigned long)ref_t32_data_e18a4 + 0x8000U) & 0xffff0000U;
    const u32 hi_56000 = ((u32)(unsigned long)ref_t32_data_ce1b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_5600c = ((u32)(unsigned long)ref_t32_data_ce1c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_56018 = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_561e0 = ((u32)(unsigned long)ref_t32_data_ce210 + 0x8000U) & 0xffff0000U;
    const u32 hi_5622c = ((u32)(unsigned long)ref_t32_data_ce190 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[172];
L_54ce4:
    sp = sp + -688;
    v0 = a3 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (684)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (680)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (676)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (672)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (668)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (664)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (660)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (656)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (652)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (648)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (384)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (12));
    t3 = *(volatile u32 *)(unsigned long)(a1 + (4));
    t2 = *(volatile u32 *)(unsigned long)(a1 + (8));
    *(volatile u32 *)(unsigned long)(sp + (388)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (13));
    t5 = *(volatile u8 *)(unsigned long)(a1 + (112));
    *(volatile u32 *)(unsigned long)(sp + (632)) = t3;
    *(volatile u32 *)(unsigned long)(sp + (392)) = v0;
    v0 = a1 + 68;
    *(volatile u32 *)(unsigned long)(sp + (396)) = v0;
    v0 = a1 + 224;
    *(volatile u32 *)(unsigned long)(sp + (328)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (229));
    *(volatile u32 *)(unsigned long)(sp + (616)) = t2;
    *(volatile u32 *)(unsigned long)(sp + (232)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (400)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (230));
    a3 = 0x1U << 16;
    a3 = a3 + 10496;
    *(volatile u32 *)(unsigned long)(sp + (404)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (235));
    t1 = hi_54d6c;
    s5 = a1;
    *(volatile u32 *)(unsigned long)(sp + (272)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (236));
    s6 = a2;
    a0 = sp + 24;
    *(volatile u32 *)(unsigned long)(sp + (264)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (237));
    s8 = *(volatile u8 *)(unsigned long)(a1 + (289));
    s7 = *(volatile u8 *)(unsigned long)(a1 + (290));
    *(volatile u32 *)(unsigned long)(sp + (332)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (238));
    *(volatile u32 *)(unsigned long)(sp + (408)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (119));
    *(volatile u32 *)(unsigned long)(sp + (412)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (120));
    *(volatile u32 *)(unsigned long)(sp + (416)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (121));
    *(volatile u32 *)(unsigned long)(sp + (420)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (239));
    *(volatile u32 *)(unsigned long)(sp + (424)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (242));
    *(volatile u32 *)(unsigned long)(sp + (428)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (243));
    *(volatile u32 *)(unsigned long)(sp + (432)) = v0;
    v0 = a1 + 244;
    *(volatile u32 *)(unsigned long)(sp + (436)) = v0;
    v0 = a1 + 264;
    *(volatile u32 *)(unsigned long)(sp + (440)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (284));
    *(volatile u32 *)(unsigned long)(sp + (444)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (285));
    *(volatile u32 *)(unsigned long)(sp + (448)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (291));
    *(volatile u32 *)(unsigned long)(sp + (312)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (292));
    *(volatile u32 *)(unsigned long)(sp + (336)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (293));
    *(volatile u32 *)(unsigned long)(sp + (452)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (339));
    *(volatile u32 *)(unsigned long)(sp + (456)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (340));
    *(volatile u32 *)(unsigned long)(sp + (460)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (341));
    *(volatile u32 *)(unsigned long)(sp + (464)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (294));
    *(volatile u32 *)(unsigned long)(sp + (472)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (297));
    *(volatile u32 *)(unsigned long)(sp + (488)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (298));
    a1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (504)) = v0;
    v0 = a2 + a3;
    a3 = a3 + 24899;
    s2 = a3 + 533;
    *(volatile u32 *)(unsigned long)(sp + (352)) = v0;
    v0 = a2 + s2;
    *(volatile u32 *)(unsigned long)(sp + (356)) = v0;
    v0 = a3 + -13379;
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(sp + (268)) = v0;
    v0 = a3 + 701;
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(sp + (468)) = v0;
    v0 = a3 + 721;
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(sp + (520)) = v0;
    v0 = a3 + -1155;
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(sp + (524)) = v0;
    v0 = a3 + 637;
    t0 = a3 + 277;
    s3 = a3 + 149;
    s0 = a3 + 553;
    s1 = a3 + 405;
    v0 = a2 + v0;
    s2 = a2 + t0;
    s4 = a2 + a3;
    s1 = a2 + s1;
    *(volatile u32 *)(unsigned long)(sp + (528)) = v0;
    s0 = a2 + s0;
    v0 = a2 + s3;
    s3 = t1 - hi_54d6c + ((u32)(unsigned long)ref_memset + (0));
    a2 = 72;
    *(volatile u32 *)(unsigned long)(sp + (600)) = a3;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (360)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_54ec8;
L_54ec8:
    a0 = *(volatile u8 *)(unsigned long)(s5 + (234));
    v0 = 15;
    *(volatile u8 *)(unsigned long)(sp + (224)) = v0;
    v0 = a0 << (0x3 & 31);
    *(volatile u32 *)(unsigned long)(sp + (288)) = v0;
    v0 = s8 & 0xffff;
    v1 = v0 << (0x3 & 31);
    a1 = s7 & 0xffff;
    *(volatile u32 *)(unsigned long)(sp + (536)) = v1;
    v1 = a1 << (0x3 & 31);
    *(volatile u32 *)(unsigned long)(sp + (552)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (272));
    v0 = v0 + a1;
    v0 = v0 << (0x3 & 31);
    a0 = a0 + v1;
    v1 = a0 << (0x3 & 31);
    *(volatile u32 *)(unsigned long)(sp + (532)) = v1;
    *(volatile u32 *)(unsigned long)(sp + (568)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (332));
    v0 = *(volatile u32 *)(unsigned long)(sp + (264));
    a1 = hi_54f18;
    t4 = hi_54f1c;
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(sp + (376)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (336));
    v0 = *(volatile u32 *)(unsigned long)(sp + (312));
    t4 = t4 - hi_54f1c + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 64;
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(sp + (584)) = v0;
    v0 = hi_54f40;
    v0 = *(volatile u8 *)(unsigned long)(v0 - hi_54f40 + (u32)(unsigned long)ref_t32_data_d6c67);
    a1 = a1 - hi_54f18 + (u32)(unsigned long)ref_t32_data_bf860;
    a0 = sp + 96;
    v0 = v0 + -6;
    v0 = v0 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (292)) = t4;
    callee = t4; *(volatile u32 *)(unsigned long)(sp + (380)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_54f64;
L_54f64:
    t5 = *(volatile u32 *)(unsigned long)(sp + (232));
    v0 = 128;
    a3 = *(volatile u32 *)(unsigned long)(sp + (600));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t5; vx[0] = tmp; }
    t5 = v0 - t5;
    a0 = a3 + 21;
    a2 = 128;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (232)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t5; vx[0] = tmp; }
    a1 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (248)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (296)))[i] = vx[0].b[i]; }
    callee = s3; a0 = s6 + a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_54fa0;
L_54fa0:
    a0 = *(volatile u32 *)(unsigned long)(sp + (360));
    a2 = 128;
    callee = s3; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_54fb0;
L_54fb0:
    a3 = hi_54fb0;
    t1 = hi_54fb4;
    a3 = a3 - hi_54fb0 + (u32)(unsigned long)ref_t32_data_ce1f0;
    t1 = t1 - hi_54fb4 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (296)))[i]; }
    t4 = *(volatile u32 *)(unsigned long)(sp + (292));
    t2 = *(volatile u32 *)(unsigned long)(sp + (616));
    t3 = *(volatile u32 *)(unsigned long)(sp + (632));
    s3 = t4;
    a2 = 0;
    t4 = s1;
    t5 = 2048;
    t6 = 0x9000;
    a1 = 0;
L_54ff0:
    a0 = a1 + a2;
L_54ff4:
    a0 = s6 + a0;
    v0 = s2;
L_54ffc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    v0 = v0 + 32;
    a0 = a0 + 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] + (u32)vx[6].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[1].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (-32)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (-16)))[i] = vx[1].b[i]; }
    *(volatile u32 *)(unsigned long)(sp + (296)) = a3;
    branch = (v0 != t4); *(volatile u32 *)(unsigned long)(sp + (292)) = t1;
    if (branch) goto L_54ffc;
    goto L_55034;
L_55034:
    a1 = a1 + 64;
    if (a1 != t5) { a0 = a1 + a2; goto L_54ff4; }
    goto L_55040;
L_55040:
    a2 = a2 + 2048;
    branch = (a2 != t6); a1 = 0;
    if (branch) goto L_54ff0;
    goto L_5504c;
L_5504c:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t3; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t2; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[1] = tmp; }
    a1 = s2;
L_5505c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    a1 = a1 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[4].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (vx[3].w[i] & 31); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (-16)))[i] = vx[2].b[i]; }
    branch = (a1 != t4); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[2].w[i]; vx[1] = tmp; }
    if (branch) goto L_5505c;
    goto L_55078;
L_55078:
    a0 = (s32)vx[1].w[1];
    v0 = (s32)vx[1].w[0];
    v0 = v0 + a0;
    a0 = (s32)vx[1].w[2];
    v0 = v0 + a0;
    a0 = (s32)vx[1].w[3];
    v0 = v0 + a0;
    a0 = 0x8000;
    a2 = (s32)v0 < (s32)(a0);
    branch = (a2 != 0); v0 = a0 - v0;
    if (branch) goto L_550ec;
    goto L_550a4;
L_550a4:
    v0 = sp + 600;
L_550a8:
    a2 = *(volatile u32 *)(unsigned long)(sp + (328));
    a1 = *(volatile u32 *)(unsigned long)(sp + (360));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = hi_550b4;
    a0 = s2;
    v0 = v0 - hi_550b4 + (u32)(unsigned long)ref_lce_hist_filter_and_judge;
    callee = v0; a3 = sp + 224;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_550c8;
L_550c8:
    v1 = *(volatile u32 *)(unsigned long)(sp + (444));
    a0 = sp + 600;
    v0 = 1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    if (v1 != v0) { a0 = *(volatile u8 *)(unsigned long)(sp + (224)); goto L_55144; }
    goto L_550e0;
L_550e0:
    v0 = *(volatile u8 *)(unsigned long)(sp + (448));
    *(volatile u8 *)(unsigned long)(sp + (224)) = v0; goto L_55140;
L_550ec:
    a2 = (s32)v0 >> (0x5 & 31);
    a0 = s2;
    v0 = v0 & 0x1f;
    a3 = 0;
L_550fc:
    branch = (a3 == v0); a3 = a3 + 1;
    if (branch) goto L_55118;
    goto L_55104;
L_55104:
    t1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 + 4;
    t1 = t1 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (-4)) = t1; goto L_550fc;
L_55118:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a2; vx[2] = tmp; }
    v0 = s2;
L_55120:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = v0 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[2].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (-16)))[i] = vx[1].b[i]; }
    branch = (a1 != v0); ;
    if (branch) goto L_55120;
    goto L_55138;
L_55138:
    v0 = sp + 600; goto L_550a8;
L_55140:
    a0 = *(volatile u8 *)(unsigned long)(sp + (224));
L_55144:
    v0 = 0x2U << 16;
    v0 = s6 + v0;
    *(volatile u8 *)(unsigned long)(v0 + (-30143)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (312));
    *(volatile u32 *)(unsigned long)(sp + (28)) = a0;
    a2 = sp + 24;
    *(volatile u32 *)(unsigned long)(sp + (44)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (336));
    a1 = s1;
    *(volatile u32 *)(unsigned long)(sp + (48)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (452));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (360)))[i] = vx[0].b[i]; }
    *(volatile u32 *)(unsigned long)(sp + (36)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (52)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (536));
    *(volatile u32 *)(unsigned long)(sp + (40)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (56)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (552));
    *(volatile u32 *)(unsigned long)(sp + (60)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (568));
    *(volatile u32 *)(unsigned long)(sp + (64)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (584));
    *(volatile u32 *)(unsigned long)(sp + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (380));
    *(volatile u32 *)(unsigned long)(sp + (72)) = v0;
    v0 = hi_551a8;
    v0 = v0 - hi_551a8 + (u32)(unsigned long)ref_lce_hist_method;
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_551b8;
L_551b8:
    a1 = *(volatile u32 *)(unsigned long)(sp + (356));
    v0 = hi_551bc;
    v0 = v0 - hi_551bc + (u32)(unsigned long)ref_lce_pdf_to_cdf;
    callee = v0; a0 = s1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_551cc;
L_551cc:
    v1 = *(volatile u32 *)(unsigned long)(sp + (472));
    v0 = 1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (360)))[i]; }
    branch = (v1 != v0); v1 = *(volatile u32 *)(unsigned long)(sp + (384));
    if (branch) goto L_55220;
    goto L_551e0;
L_551e0:
    v0 = *(volatile u32 *)(unsigned long)(sp + (488));
    a0 = *(volatile u32 *)(unsigned long)(sp + (356));
    a3 = s5 + 299;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (504));
    a2 = sp + 24;
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = s5 + 319;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_55204;
    v0 = v0 - hi_55204 + (u32)(unsigned long)ref_lce_self_light_correct_local;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (312)))[i] = vx[0].b[i]; }
    callee = v0; a1 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_55218;
L_55218:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (312)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (384));
L_55220:
    v0 = 4;
    branch = (v1 == v0); a2 = *(volatile u32 *)(unsigned long)(sp + (464));
    if (branch) goto L_55250;
    goto L_5522c;
L_5522c:
    a1 = *(volatile u32 *)(unsigned long)(sp + (460));
    a0 = *(volatile u32 *)(unsigned long)(sp + (456));
    v0 = hi_55234;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = v0 - hi_55234 + (u32)(unsigned long)ref_lce_16bit_data_converge;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (312)))[i] = vx[0].b[i]; }
    callee = v0; a3 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5524c;
L_5524c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (312)))[i]; }
L_55250:
    a2 = 20;
    a1 = s0;
    v0 = s3;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_55268;
L_55268:
    a3 = hi_55268;
    a2 = hi_5526c;
    a1 = hi_55270;
    a0 = hi_55274;
    a3 = a3 - hi_55268 + (u32)(unsigned long)ref_t32_data_ce140;
    a2 = a2 - hi_5526c + (u32)(unsigned long)ref_t32_data_ce150;
    a1 = a1 - hi_55270 + (u32)(unsigned long)ref_t32_data_ce160;
    a0 = a0 - hi_55274 + (u32)(unsigned long)ref_t32_data_ce170;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (312)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    v0 = 0x1U << 16;
    v0 = v0 | 0x8c7c;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    s8 = hi_552ac;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s6 + (v0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (272));
    s2 = 0;
    *(volatile u32 *)(unsigned long)(sp + (448)) = a3;
    v0 = v0 << (0x3 & 31);
    *(volatile u32 *)(unsigned long)(sp + (444)) = v0;
    v0 = s8 - hi_552ac + (u32)(unsigned long)ref_t32_data_ce1d0;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    *(volatile u32 *)(unsigned long)(sp + (356)) = v0;
    v0 = sp + 536;
    *(volatile u32 *)(unsigned long)(sp + (452)) = a2;
    *(volatile u32 *)(unsigned long)(sp + (456)) = a1;
    *(volatile u32 *)(unsigned long)(sp + (460)) = a0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (272)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(sp + (232)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[5].w[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (472)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(sp + (232)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[5].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[5].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[5].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[5].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = sp + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (488)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (504)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s2 << (0x5 & 31);
L_55330:
    v0 = v0 & 0xffff;
    *(volatile u32 *)(unsigned long)(sp + (360)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (388));
    s3 = 0;
    s7 = (s32)s2 < (s32)(v0);
    v0 = 2;
    if (s7 != 0) v0 = 0;
    *(volatile u32 *)(unsigned long)(sp + (312)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (312));
L_55354:
    s0 = hi_55354;
    a1 = hi_55358;
    t4 = v0 + 1;
    v0 = 9;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[9] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (296));
    s0 = s0 - hi_55354 + (u32)(unsigned long)ref_t32_data_e1d64;
    a1 = a1 - hi_55358 + (u32)(unsigned long)ref_t32_data_e1d54;
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (292));
    a2 = s3;
    t9 = s3 + 8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    t5 = s0;
    s8 = s0;
    *(volatile u32 *)(unsigned long)(sp + (464)) = a1;
    t4 = t4 & 0xff;
    t8 = 0x8000;
L_5539c:
    v0 = *(volatile u32 *)(unsigned long)(sp + (360));
    v1 = *(volatile u32 *)(unsigned long)(sp + (392));
    v0 = v0 + a2;
    v0 = v0 & 0xffff;
    a3 = (s32)a2 < (s32)(v1);
    *(volatile u16 *)(unsigned long)(t5 + (0)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (312));
    t0 = *(volatile u8 *)(unsigned long)(s5 + (110));
    if (a3 == 0) v1 = t4;
    a0 = v1;
    branch = (t0 != s2); a3 = 0;
    if (branch) goto L_553d8;
    goto L_553cc;
L_553cc:
    a3 = *(volatile u8 *)(unsigned long)(s5 + (111));
    a3 = a3 ^ a2;
    a3 = (u32)a3 < (u32)(1);
L_553d8:
    v0 = v0 << (0x6 & 31);
    v0 = s6 + v0;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = a3;
    v1 = *(volatile u32 *)(unsigned long)(sp + (396));
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    a0 = a0 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[4] = tmp; }
    a0 = v1 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t2 = v0 + 16;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    t0 = v0 + 48;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[11].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[11].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    t1 = v0 + 32;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[2].w[i]; vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[2].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[11].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] * (u32)vx[2].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[2].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[15].w[i] >> (vx[9].w[i] & 31); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[2].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[11].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[8].w[i] >> (vx[9].w[i] & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[2].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] * (u32)vx[2].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[14].w[i] >> (vx[9].w[i] & 31); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[2].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (vx[9].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] + (u32)vx[7].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (vx[9].w[i] & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[13].w[i] >> (vx[9].w[i] & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (vx[9].w[i] & 31); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (vx[9].w[i] & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[5].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(sp + (272)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[6].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[15].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[3].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[7].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[4].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t2 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t1 + (0)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[2].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    a3 = (s32)vx[1].w[1];
    a0 = (s32)vx[1].w[0];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t0 + (0)))[i] = vx[2].b[i]; }
    a0 = a0 + a3;
    a3 = (s32)vx[1].w[2];
    a3 = a0 + a3;
    a0 = (s32)vx[1].w[3];
    a0 = a3 + a0;
    a3 = (s32)a0 < (s32)(t8);
    branch = (a3 == 0); s7 = *(volatile u32 *)(unsigned long)(sp + (356));
    if (branch) goto L_55544;
    goto L_554e0;
L_554e0:
    a0 = t8 - a0;
    a3 = (s32)a0 >> (0x5 & 31);
    t3 = v0;
    a0 = a0 & 0x1f;
    t6 = 0;
L_554f4:
    branch = (a0 == t6); t6 = t6 + 1;
    if (branch) goto L_55510;
    goto L_554fc;
L_554fc:
    t7 = *(volatile u16 *)(unsigned long)(t3 + (0));
    t3 = t3 + 2;
    t7 = t7 + 1;
    *(volatile u16 *)(unsigned long)(t3 + (-2)) = t7; goto L_554f4;
L_55510:
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a3; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[1].h[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[4].h[i] + (u16)vx[1].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[3].h[i] + (u16)vx[1].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[1].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t2 + (0)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t1 + (0)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t0 + (0)))[i] = vx[1].b[i]; }
L_55544:
    a2 = a2 + 1;
    t5 = t5 + 2;
    branch = (a2 != t9); a1 = a1 + 2;
    if (branch) goto L_5539c;
    goto L_55554;
L_55554:
    v0 = 1024;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[2] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (408));
    t1 = hi_55560;
    t1 = t1 - hi_55560 + (u32)(unsigned long)ref_t32_data_e1b54;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[15] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (288));
    t3 = hi_55570;
    t3 = t3 - hi_55570 + (u32)(unsigned long)ref_t32_data_e1b44;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[18] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (264));
    t2 = t1;
    t4 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[19] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (380));
    *(volatile u32 *)(unsigned long)(sp + (232)) = t1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[16] = tmp; }
L_55598:
    v0 = sp + 632;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[16].b[i]; }
    v0 = sp + 616;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    v0 = sp + 600;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[18].b[i]; }
    v0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = s8 + t4;
    t6 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = *(volatile u32 *)(unsigned long)(sp + (328));
    v0 = hi_555cc;
    t0 = t6 << (0x6 & 31);
    t5 = s6 + t0;
    a0 = t5;
    v0 = v0 - hi_555cc + (u32)(unsigned long)ref_lce_hist_filter_and_judge_16bit;
    a3 = t3;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (336)))[i] = vx[0].b[i]; }
    callee = v0; a1 = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_555f0;
L_555f0:
    a0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    a0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (400));
    a0 = sp + 600;
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    a0 = sp + 616;
    { unsigned int i; for (i = 0; i < 16; i++) vx[19].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    v0 = 1;
    a0 = sp + 632;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (336)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[16].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(sp + (524));
    if (branch) goto L_55638;
    goto L_5562c;
L_5562c:
    v0 = *(volatile u16 *)(unsigned long)(sp + (404));
    *(volatile u16 *)(unsigned long)(t3 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (524));
L_55638:
    a0 = hi_55638;
    a0 = a0 - hi_55638 + (u32)(unsigned long)ref_t32_data_bf9a8;
    t6 = v0 + t6;
    v0 = *(volatile u16 *)(unsigned long)(t3 + (0));
    v1 = *(volatile u32 *)(unsigned long)(sp + (444));
    a2 = hi_5564c;
    *(volatile u8 *)(unsigned long)(t6 + (0)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(t3 + (0));
    *(volatile u32 *)(unsigned long)(a2 - hi_5564c + (u32)(unsigned long)ref_t32_data_e1a74) = 0;
    t9 = hi_5565c;
    a1 = v0 << (0x1 & 31);
    a0 = a1 + a0;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    t8 = hi_5566c;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[11] = tmp; }
    a3 = v1 * a1;
    v1 = *(volatile u32 *)(unsigned long)(sp + (332));
    s4 = v0 + -4;
    t9 = t9 - hi_5565c + (u32)(unsigned long)ref_t32_data_e1a84;
    t8 = t8 - hi_5566c + (u32)(unsigned long)ref_t32_data_e19f4;
    a1 = v1 * a1;
    a3 = (s32)a3 >> (0xa & 31);
    a0 = a3 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[4] = tmp; }
    t6 = a3 << (0x1 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a3; vx[7] = tmp; }
    a1 = (s32)a1 >> (0xa & 31);
    a0 = a1 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[5] = tmp; }
    a0 = a2 - hi_5564c + (u32)(unsigned long)ref_t32_data_e1a74;
    *(volatile u32 *)(unsigned long)(a0 + (8)) = t6;
    t6 = t6 + a3;
    *(volatile u32 *)(unsigned long)(a0 + (12)) = t6;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = a3;
    t6 = a1 << (0x1 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    *(volatile u32 *)(unsigned long)(a0 + (8)) = t6;
    t6 = t6 + a1;
    *(volatile u32 *)(unsigned long)(a0 + (4)) = a1;
    *(volatile u32 *)(unsigned long)(a0 + (12)) = t6;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a1; vx[8] = tmp; }
    a0 = 0;
L_556e4:
    s1 = (s32)s4 < (s32)(a0);
    t7 = t9;
    branch = (s1 != 0); t6 = t8;
    if (branch) goto L_55720;
    goto L_556f4;
L_556f4:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] + (u32)vx[3].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[18].w[i] + (u32)vx[1].w[i]; vx[9] = tmp; }
    t6 = a0 << (0x2 & 31);
    a0 = a0 + 4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] + (u32)vx[6].w[i]; vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t9 + (t6)))[i] = vx[9].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] + (u32)vx[1].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t8 + (t6)))[i] = vx[6].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] + (u32)vx[3].w[i]; vx[3] = tmp; }
    a0 = a0 & 0xff; goto L_556e4;
L_55720:
    t9 = 0;
L_55724:
    t8 = (u32)a0 < (u32)(v0);
    branch = (t8 == 0); ra = a3 * a0;
    if (branch) goto L_55768;
    goto L_55730;
L_55730:
    v1 = *(volatile u32 *)(unsigned long)(sp + (288));
    t8 = a0 << (0x2 & 31);
    s1 = t7 + t8;
    t8 = t6 + t8;
    s4 = ra + v1;
    ra = a1 * a0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (264));
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s4;
    a0 = a0 + 1;
    a0 = a0 & 0xff;
    s1 = ra + v1;
    *(volatile u32 *)(unsigned long)(t8 + (0)) = s1;
    t9 = t9 + s1; goto L_55724;
L_55768:
    v1 = *(volatile u32 *)(unsigned long)(sp + (532));
    a0 = v0 << (0x2 & 31);
    t8 = t7 + a0;
    *(volatile u32 *)(unsigned long)(t8 + (0)) = v1;
    t8 = 30;
    t8 = t8 - v0;
    *(volatile u32 *)(unsigned long)(a2 - hi_5564c + (u32)(unsigned long)ref_t32_data_e1a74) = t8;
    t8 = 29;
    a2 = a2 - hi_5564c + (u32)(unsigned long)ref_t32_data_e1a74;
    t8 = t8 - v0;
    *(volatile u32 *)(unsigned long)(a2 + (4)) = t8;
    t8 = 28;
    t8 = t8 - v0;
    v1 = *(volatile u32 *)(unsigned long)(sp + (376));
    *(volatile u32 *)(unsigned long)(a2 + (8)) = t8;
    t8 = 27;
    a0 = t6 + a0;
    t8 = t8 - v0;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v1;
    *(volatile u32 *)(unsigned long)(a2 + (12)) = t8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a0 = t9 + v1;
    v0 = v0 + 1;
L_557c4:
    v0 = v0 & 0xff;
    a2 = (u32)v0 < (u32)(29);
    branch = (a2 == 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[18].w[i] | vx[18].w[i]; vx[4] = tmp; }
    if (branch) goto L_55800;
    goto L_557d4;
L_557d4:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[19].w[i] | vx[19].w[i]; vx[3] = tmp; }
    a2 = v0 << (0x2 & 31);
    v0 = v0 + 4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] + ((u32)vx[7].w[i] * (u32)vx[1].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[3].w[i] + ((u32)vx[8].w[i] * (u32)vx[1].w[i]); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t7 + (a2)))[i] = vx[4].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] + (u32)vx[3].w[i]; vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t6 + (a2)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 4; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] - (u32)vx[3].w[i]; vx[1] = tmp; } goto L_557c4;
L_55800:
    t9 = 31;
L_55804:
    a2 = (u32)v0 < (u32)(32);
    branch = (a2 == 0); a2 = t9 - v0;
    if (branch) goto L_5584c;
    goto L_55810;
L_55810:
    ra = a3 * a2;
    v1 = *(volatile u32 *)(unsigned long)(sp + (288));
    t8 = v0 << (0x2 & 31);
    s1 = t7 + t8;
    v0 = v0 + 1;
    t8 = t6 + t8;
    v0 = v0 & 0xff;
    s4 = ra + v1;
    ra = a1 * a2;
    v1 = *(volatile u32 *)(unsigned long)(sp + (264));
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s4;
    a2 = ra + v1;
    *(volatile u32 *)(unsigned long)(t8 + (0)) = a2;
    a0 = a0 + a2; goto L_55804;
L_5584c:
    v0 = t0 + 16;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(s6 + (v0)))[i]; }
    v0 = t0 + 32;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(s6 + (v0)))[i]; }
    v0 = hi_5585c;
    v0 = v0 - hi_5585c + (u32)(unsigned long)ref_t32_data_e1aa4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[27].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[26].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    v0 = hi_5586c;
    v0 = v0 - hi_5586c + (u32)(unsigned long)ref_t32_data_e1ac4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[25].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[24].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    v0 = hi_5587c;
    v0 = v0 - hi_5587c + (u32)(unsigned long)ref_t32_data_e1ae4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[23].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[22].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (296));
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(t5 + (0)))[i]; }
    t0 = t0 + 48;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (292));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s6 + (t0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[29].b[i] = ((volatile u8 *)(unsigned long)(t7 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[17].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[28].b[i] = ((volatile u8 *)(unsigned long)(t7 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] - (u32)vx[2].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] - (u32)vx[2].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] - (u32)vx[2].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] - (u32)vx[2].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[15].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] - (u32)vx[2].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[15].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] * (u32)vx[15].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[15].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] * (u32)vx[15].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] - (u32)vx[2].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (7 & 31); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[8].w[i] >> (7 & 31); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[14].w[i] >> (7 & 31); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[10].w[i] >> (7 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] + (u32)vx[2].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] - (u32)vx[2].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] + (u32)vx[2].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[13].w[i] >> (7 & 31); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] + (u32)vx[2].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] + (u32)vx[2].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[25].w[i] < vx[12].w[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[26].w[i] < vx[8].w[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[15].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[15].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] + (u32)vx[2].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[29].w[i] < vx[14].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[28].w[i] < vx[10].w[i]) ? ~0U : 0; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (336)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[8].w[i] & ~vx[4].w[i]) | (vx[26].w[i] & vx[4].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] - (u32)vx[2].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(sp + (336)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[27].w[i] < vx[13].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[21].w[i]) | (vx[29].w[i] & vx[21].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[5].w[i]) | (vx[28].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[15].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[7].w[i] >> (7 & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[9].w[i] >> (7 & 31); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[8].w[i]) | (vx[25].w[i] & vx[8].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[20].w[i]) | (vx[27].w[i] & vx[20].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] + (u32)vx[5].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[2].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] + (u32)vx[2].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[13].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[24].w[i] < vx[7].w[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[23].w[i] < vx[9].w[i]) ? ~0U : 0; vx[31] = tmp; }
    v0 = hi_5598c;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[4].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[2].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[3].w[i]) | (vx[24].w[i] & vx[3].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[31].w[i]) | (vx[23].w[i] & vx[31].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[12].w[i]; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[31].b[i] = ((volatile u8 *)(unsigned long)(s7 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[22].w[i] < vx[1].w[i]) ? ~0U : 0; vx[30] = tmp; }
    v0 = v0 - hi_5598c + (u32)(unsigned long)ref_t32_data_e1b04;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[3].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[14].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[30].w[i]) | (vx[22].w[i] & vx[30].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[13].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[9].w[i]; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[14].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    v0 = hi_559cc;
    v0 = v0 - hi_559cc + (u32)(unsigned long)ref_t32_data_e1b14;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[1].w[i]; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[13].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    v0 = hi_559e0;
    v0 = v0 - hi_559e0 + (u32)(unsigned long)ref_t32_data_e1b24;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[12].b[i]; }
    v0 = hi_559ec;
    v0 = v0 - hi_559ec + (u32)(unsigned long)ref_t32_data_e1b34;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    a1 = (s32)vx[25].w[1];
    v0 = (s32)vx[25].w[0];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[14].b[(sel & 31) >> 1]); } vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[13].b[(sel & 31) >> 1]); } vx[22] = tmp; }
    a1 = v0 + a1;
    v0 = (s32)vx[25].w[2];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[14].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[13].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    a1 = a1 + v0;
    v0 = (s32)vx[25].w[3];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    a1 = a1 + v0;
    v0 = 0x8000;
    v0 = v0 - a1;
    branch = ((s32)v0 >= 0); { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[17].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    if (branch) goto L_55b00;
    goto L_55a40;
L_55a40:
    v0 = hi_55a40;
    a0 = *(volatile u8 *)(unsigned long)(v0 - hi_55a40 + (u32)(unsigned long)ref_t32_data_d6c67);
    v0 = 1;
    v0 = v0 << (a0 & 31);
    a0 = a1 << (0x5 & 31);
    a0 = (s32)a0 >> (0xe & 31);
    a0 = a0 + 1;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[23].w[i]; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[14].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[22].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[4].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[9].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[12].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[6].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[23].w[i] >> (vx[16].w[i] & 31); vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (vx[16].w[i] & 31); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[13].w[i] >> (vx[16].w[i] & 31); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (vx[16].w[i] & 31); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[3].w[i] >> (vx[16].w[i] & 31); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[17].w[i] >> (vx[16].w[i] & 31); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[23].w[i] + (u32)vx[14].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (vx[16].w[i] & 31); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (vx[16].w[i] & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[14].b[(sel & 31) >> 1] : vx[23].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[22].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (96)))[i] = vx[14].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[13].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[13].b[(sel & 31) >> 1] : vx[22].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[9].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (112)))[i] = vx[13].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[3].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[6].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (128)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[11].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[11].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    a0 = (s32)vx[1].w[1];
    v0 = (s32)vx[1].w[0];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (144)))[i] = vx[11].b[i]; }
    v0 = v0 + a0;
    a0 = (s32)vx[1].w[2];
    a0 = v0 + a0;
    v0 = (s32)vx[1].w[3]; goto L_55c14;
L_55b00:
    a2 = (s32)vx[11].w[3];
    a1 = (s32)vx[11].w[2];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[25] = tmp; }
    v0 = hi_55b0c;
    v0 = v0 - hi_55b0c + (u32)(unsigned long)ref_t32_data_e1a14;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[20].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[29].b[i] = ((volatile u8 *)(unsigned long)(t6 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t6 + (16)))[i]; }
    a1 = a1 + a2;
    v0 = hi_55b28;
    a2 = (s32)vx[11].w[1];
    v0 = v0 - hi_55b28 + (u32)(unsigned long)ref_t32_data_e1a34;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    v0 = hi_55b3c;
    v0 = v0 - hi_55b3c + (u32)(unsigned long)ref_t32_data_e1a54;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    a2 = a1 + a2;
    a1 = (s32)vx[11].w[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[29].w[i] * (u32)vx[25].w[i]; vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[25].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] * (u32)vx[25].w[i]; vx[13] = tmp; }
    a1 = a2 + a1;
    a0 = a1 + a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[25].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[20].w[i] * (u32)vx[25].w[i]; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[25].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[29].w[i] / vx[17].w[i] : ~0U; vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[5].w[i] / vx[17].w[i] : ~0U; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[13].w[i] / vx[17].w[i] : ~0U; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[25].w[i]; vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[24].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[7].w[i] / vx[17].w[i] : ~0U; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[20].w[i] / vx[17].w[i] : ~0U; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[3].w[i] / vx[17].w[i] : ~0U; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] * (u32)vx[25].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[8].w[i] / vx[17].w[i] : ~0U; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] ? vx[25].w[i] / vx[17].w[i] : ~0U; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[29].w[i] + (u32)vx[23].w[i]; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] + (u32)vx[14].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] + (u32)vx[22].w[i]; vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[6].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[23].w[i] + (u32)vx[14].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[20].w[i] + (u32)vx[4].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] + (u32)vx[9].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[14].b[(sel & 31) >> 1] : vx[23].b[(sel & 31) >> 1]); } vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[22].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] + (u32)vx[12].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (96)))[i] = vx[23].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[13].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[13].b[(sel & 31) >> 1] : vx[22].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[9].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[1].w[i]; vx[17] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (112)))[i] = vx[13].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[3].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[11].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[31].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[17].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (128)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[17].w[i]; vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (144)))[i] = vx[11].b[i]; }
    a0 = (s32)vx[7].w[1];
    v0 = (s32)vx[7].w[0];
    v0 = v0 + a0;
    a0 = (s32)vx[7].w[2];
    a0 = v0 + a0;
    v0 = (s32)vx[7].w[3];
L_55c14:
    v0 = a0 + v0;
    a1 = 0x8000;
    v0 = a1 - v0;
    a0 = v0 << (0x5 & 31);
    a0 = (s32)a0 >> (0xa & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a0; vx[1] = tmp; }
    a0 = 32;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(sp + (96)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(sp + (112)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(sp + (128)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(sp + (144)))[i]; }
    t4 = t4 + 2;
    v0 = 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[5].h[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[4].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[3].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[6].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t2 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t2 + (16)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t2 + (32)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t2 + (48)))[i] = vx[1].b[i]; }
    a0 = *(volatile u16 *)(unsigned long)(t2 + (62));
    t3 = t3 + 2;
    t2 = t2 + 64;
    a1 = hi;
    a0 = a1 + a0;
    branch = (t4 != v0); *(volatile u16 *)(unsigned long)(t2 + (-2)) = a0;
    if (branch) goto L_55598;
    goto L_55c88;
L_55c88:
    v1 = *(volatile u32 *)(unsigned long)(sp + (296));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[1] = tmp; }
    a0 = hi_55c90;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (292));
    a2 = a0 - hi_55c90 + (u32)(unsigned long)ref_t32_data_e1954;
    a3 = 32767;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a3; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[7] = tmp; }
    v0 = a2;
    a1 = 0;
    *(volatile u32 *)(unsigned long)(sp + (336)) = a2;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[6] = tmp; }
    a3 = 8;
L_55cc8:
    t0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (15 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (15 & 31); vx[4] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (192)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (64));
    a1 = a1 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] < vx[5].w[i]) ? ~0U : 0; vx[5] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (194)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (128));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] < vx[4].w[i]) ? ~0U : 0; vx[4] = tmp; }
    t1 = t1 + 2;
    *(volatile u16 *)(unsigned long)(sp + (196)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (190));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[3].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[4].w[i]) | (vx[3].w[i] & vx[4].w[i]); vx[2] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (198)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (254));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (7 & 31); vx[4] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (200)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (318));
    v0 = v0 + 1;
    *(volatile u16 *)(unsigned long)(sp + (202)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (382));
    *(volatile u16 *)(unsigned long)(sp + (204)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(t1 + (446));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (160)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (176)))[i] = vx[4].b[i]; }
    *(volatile u16 *)(unsigned long)(sp + (206)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (160));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[4] = tmp; }
    *(volatile u8 *)(unsigned long)(v0 + (-1)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (164));
    *(volatile u8 *)(unsigned long)(v0 + (19)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (168));
    *(volatile u8 *)(unsigned long)(v0 + (39)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (172));
    *(volatile u8 *)(unsigned long)(v0 + (59)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (176));
    *(volatile u8 *)(unsigned long)(v0 + (79)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (180));
    *(volatile u8 *)(unsigned long)(v0 + (99)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (184));
    *(volatile u8 *)(unsigned long)(v0 + (119)) = t0;
    t0 = *(volatile u32 *)(unsigned long)(sp + (188));
    *(volatile u8 *)(unsigned long)(v0 + (139)) = t0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(sp + (192)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[5].w[i]; vx[2] = tmp; }
    branch = (a1 != a3); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[5] = tmp; }
    if (branch) goto L_55cc8;
    goto L_55d9c;
L_55d9c:
    v0 = hi_55d9c;
    v0 = v0 - hi_55d9c + (u32)(unsigned long)ref_t32_data_ce1f0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_55da8;
    v0 = v0 - hi_55da8 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    a3 = 0;
    t0 = 12;
L_55dbc:
    v0 = a3 << (0x1 & 31);
    v1 = *(volatile u32 *)(unsigned long)(sp + (232));
    a1 = v0 + 8;
    a1 = a1 << (0x1 & 31);
    a1 = v1 + a1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v0 = v0 + 9;
    v0 = v0 << (0x1 & 31);
    *(volatile u16 *)(unsigned long)(sp + (192)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (64));
    v0 = v1 + v0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (15 & 31); vx[8] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (194)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (128));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (15 & 31); vx[6] = tmp; }
    a3 = a3 + 1;
    *(volatile u16 *)(unsigned long)(sp + (196)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (192));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] < vx[8].w[i]) ? ~0U : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] < vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (198)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (256));
    a2 = a2 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[8].w[i]) | (vx[3].w[i] & vx[8].w[i]); vx[1] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (200)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (320));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[6].w[i]) | (vx[3].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[8] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (202)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(a1 + (384));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (448));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (7 & 31); vx[6] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (204)) = t1;
    *(volatile u16 *)(unsigned long)(sp + (206)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    *(volatile u16 *)(unsigned long)(sp + (208)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (64));
    *(volatile u16 *)(unsigned long)(sp + (210)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (128));
    *(volatile u16 *)(unsigned long)(sp + (212)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (192));
    *(volatile u16 *)(unsigned long)(sp + (214)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (256));
    *(volatile u16 *)(unsigned long)(sp + (216)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (320));
    *(volatile u16 *)(unsigned long)(sp + (218)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (384));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (448));
    *(volatile u16 *)(unsigned long)(sp + (220)) = a1;
    *(volatile u16 *)(unsigned long)(sp + (222)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (160)))[i] = vx[8].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (160));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (176)))[i] = vx[6].b[i]; }
    *(volatile u8 *)(unsigned long)(a2 + (7)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (164));
    *(volatile u8 *)(unsigned long)(a2 + (27)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (168));
    *(volatile u8 *)(unsigned long)(a2 + (47)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (172));
    *(volatile u8 *)(unsigned long)(a2 + (67)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (176));
    *(volatile u8 *)(unsigned long)(a2 + (87)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (180));
    *(volatile u8 *)(unsigned long)(a2 + (107)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (184));
    *(volatile u8 *)(unsigned long)(a2 + (127)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (188));
    *(volatile u8 *)(unsigned long)(a2 + (147)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(sp + (192)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[6].w[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(sp + (208)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    branch = (a3 != t0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[6].w[i]; vx[2] = tmp; }
    if (branch) goto L_55dbc;
    goto L_55ef8;
L_55ef8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (424));
    s1 = hi_55efc;
    a3 = hi_55f00;
    s1 = s1 - hi_55efc + ((u32)(unsigned long)ref_memcpy + (0));
    s4 = a3 - hi_55f00 + (u32)(unsigned long)ref_t32_data_e18b4;
    s8 = 0;
    branch = (v0 == 0); s7 = 160;
    if (branch) goto L_55f8c;
    goto L_55f18;
L_55f18:
    v0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (428));
    a3 = *(volatile u32 *)(unsigned long)(sp + (436));
    *(volatile u32 *)(unsigned long)(sp + (20)) = 0;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (432));
    a2 = sp + 24;
    a1 = s4;
    *(volatile u32 *)(unsigned long)(sp + (36)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (440));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_55f50;
    v0 = v0 - hi_55f50 + (u32)(unsigned long)ref_lce_self_light_correct_local_simd_test;
    callee = v0; a0 = a0 - hi_55c90 + (u32)(unsigned long)ref_t32_data_e1954;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_55f60;
L_55f60:
    v0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile int8_t *)(unsigned long)(sp + (412));
L_55f74:
    s7 = s4;
    s4 = hi_55f78;
    s8 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v0; vx[6] = tmp; }
    s4 = s4 - hi_55f78 + (u32)(unsigned long)ref_t32_data_e18a4; goto L_562c4;
L_55f8c:
    v0 = sp + 584;
L_55f90:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (336));
    a0 = s4 + s8;
    a2 = 20;
    callee = s1; a1 = v0 + s8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_55fb0;
L_55fb0:
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    s8 = s8 + 20;
    v0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (s8 != s7); ;
    if (branch) goto L_55f90;
    goto L_55fcc;
L_55fcc:
    v0 = *(volatile int8_t *)(unsigned long)(sp + (412)); goto L_55f74;
L_55fd4:
    v0 = 4;
    branch = (v1 == v0); v1 = *(volatile u32 *)(unsigned long)(sp + (268));
    if (branch) goto L_56134;
    goto L_55fe0;
L_55fe0:
    v0 = *(volatile u16 *)(unsigned long)(s0 + (0));
    a0 = 20;
    a1 = v0 * a0;
    a0 = *(volatile int8_t *)(unsigned long)(sp + (416));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s7 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a0; vx[8] = tmp; }
    a0 = *(volatile int8_t *)(unsigned long)(sp + (420));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a0; vx[11] = tmp; }
    a0 = hi_56000;
    a0 = a0 - hi_56000 + (u32)(unsigned long)ref_t32_data_ce1b0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    a0 = hi_5600c;
    a0 = a0 - hi_5600c + (u32)(unsigned long)ref_t32_data_ce1c0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    a0 = hi_56018;
    a0 = a0 - hi_56018 + (u32)(unsigned long)ref_t32_data_ce1a0;
    v0 = a1 + v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[17].w[i] | vx[17].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[3].h[i] + (u16)vx[8].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[17].h[i] > (s16)vx[16].h[i] ? (s64)(s16)vx[17].h[i] - (s64)(s16)vx[16].h[i] : (s64)(s16)vx[16].h[i] - (s64)(s16)vx[17].h[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[1].h[i] > (s16)vx[12].h[i] ? (s64)(s16)vx[1].h[i] - (s64)(s16)vx[12].h[i] : (s64)(s16)vx[12].h[i] - (s64)(s16)vx[1].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[16].h[i] + (u16)vx[8].h[i]; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[3].h[i]  < (s16)vx[16].h[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[18].h[i]  < (s16)vx[17].h[i]) ? ~0U : 0; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[7].h[i] * (u32)vx[6].h[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] * (u32)vx[6].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s64)(s16)vx[7].h[i] >> (7 & 15)) + ((7 & 15) ? ((vx[7].h[i] >> (((7 & 15) - 1) & 15)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s64)(s16)vx[4].h[i] >> (7 & 15)) + ((7 & 15) ? ((vx[4].h[i] >> (((7 & 15) - 1) & 15)) & 1) : 0); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[11].h[i]  < (s16)vx[7].h[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[11].h[i]  < (s16)vx[4].h[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[9].w[i]) | (vx[11].w[i] & vx[9].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[7].h[i]  < (s16)vx[8].h[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[2].w[i]) | (vx[11].w[i] & vx[2].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i]  < (s16)vx[8].h[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[7].w[i]) | (vx[8].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[12].h[i] + (u16)vx[8].h[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[4].w[i]) | (vx[8].w[i] & vx[4].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[16].h[i] + (u16)vx[7].h[i]; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[9].h[i]  < (s16)vx[1].h[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[12].h[i] + (u16)vx[2].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[12].h[i] - (u16)vx[2].h[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[17].w[i] & ~vx[18].w[i]) | (vx[19].w[i] & vx[18].w[i]); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[16].h[i] - (u16)vx[7].h[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[9].w[i]) | (vx[4].w[i] & vx[9].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[8].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[17].w[i] & ~vx[3].w[i]) | (vx[7].w[i] & vx[3].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i]  < (s16)vx[12].h[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[12].w[i]) | (vx[2].w[i] & vx[12].w[i]); vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s7 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s7 + (0)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[1].h[i] > (s16)vx[9].h[i] ? (s64)(s16)vx[1].h[i] - (s64)(s16)vx[9].h[i] : (s64)(s16)vx[9].h[i] - (s64)(s16)vx[1].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] * (u32)vx[6].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s64)(s16)vx[4].h[i] >> (7 & 15)) + ((7 & 15) ? ((vx[4].h[i] >> (((7 & 15) - 1) & 15)) & 1) : 0); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[11].h[i]  < (s16)vx[4].h[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[3].w[i]) | (vx[11].w[i] & vx[3].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i]  < (s16)vx[8].h[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[4].w[i]) | (vx[8].w[i] & vx[4].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[9].h[i] + (u16)vx[8].h[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[8].h[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[9].h[i] + (u16)vx[3].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[2].h[i]  < (s16)vx[1].h[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[9].h[i] - (u16)vx[3].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[2].w[i]) | (vx[4].w[i] & vx[2].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[8].h[i]  < (s16)vx[9].h[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[1].w[i]) | (vx[3].w[i] & vx[1].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (160)))[i] = vx[1].b[i]; }
    v0 = *(volatile u8 *)(unsigned long)(sp + (160));
    *(volatile u8 *)(unsigned long)(s7 + (16)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(sp + (161));
    *(volatile u8 *)(unsigned long)(s7 + (17)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(sp + (162));
    *(volatile u8 *)(unsigned long)(s7 + (18)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(sp + (163));
    *(volatile u8 *)(unsigned long)(s7 + (19)) = v0;
L_56134:
    a0 = *(volatile u16 *)(unsigned long)(s0 + (0));
    t1 = 20;
    v0 = sp + 632;
    v1 = a0 * t1;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[6].b[i]; }
    v0 = sp + 616;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
    v0 = sp + 600;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (268));
    t2 = s7 + 16;
    a1 = t2;
    a2 = 4;
    *(volatile u32 *)(unsigned long)(sp + (584)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (568)) = t2;
    s8 = s8 + 2;
    s0 = s0 + 2;
    s7 = s7 + 20;
    a0 = v1 + v0;
    callee = s1; a0 = a0 + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_56188;
L_56188:
    t1 = *(volatile u32 *)(unsigned long)(sp + (584));
    v0 = *(volatile u16 *)(unsigned long)(s0 + (-2));
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s7 + (-20)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (268));
    a0 = v0 * t1;
    a2 = 4;
    a1 = s4;
    v0 = a0 + v1;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (448));
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(sp + (248)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(sp + (472)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = sp + 600;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (452));
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(sp + (248)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (352));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] + ((u32)vx[2].w[i] * (u32)vx[1].w[i]); vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(sp + (488)))[i]; }
    v0 = hi_561e0;
    v0 = v0 - hi_561e0 + (u32)(unsigned long)ref_t32_data_ce210;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (456));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (7 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] + ((u32)vx[5].w[i] * (u32)vx[2].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(sp + (504)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (460));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] + ((u32)vx[5].w[i] * (u32)vx[2].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = sp + 536;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[1] = tmp; }
    v0 = hi_5622c;
    v0 = v0 - hi_5622c + (u32)(unsigned long)ref_t32_data_ce190;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[5].w[i] * (u32)vx[3].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (7 & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u16 *)(unsigned long)(s0 + (-2));
    a0 = v0 * t1;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    v0 = a0 + v1;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    t2 = *(volatile u32 *)(unsigned long)(sp + (568));
    v0 = sp + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(sp + (248)))[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[3].w[i] * (u32)vx[1].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] >> (7 & 31)) + ((7 & 31) ? ((vx[2].w[i] >> (((7 & 31) - 1) & 31)) & 1) : 0); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (0)))[i] = vx[1].b[i]; }
    a0 = *(volatile u16 *)(unsigned long)(s0 + (-2));
    v0 = *(volatile u32 *)(unsigned long)(sp + (352));
    v1 = a0 * t1;
    a0 = v1 + v0;
    callee = s1; a0 = a0 + 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_562a0;
L_562a0:
    v1 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v1 = sp + 616;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v0 = 16;
    v1 = sp + 632;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    if (s8 == v0) { s3 = s3 + 8; goto L_56354; }
    goto L_562c4;
L_562c4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (464));
    v0 = v0 + s8;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    if (v0 == 0) { v1 = *(volatile u32 *)(unsigned long)(sp + (384)); goto L_55fd4; }
    goto L_562d8;
L_562d8:
    v0 = sp + 600;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[6].b[i]; }
    v0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (232));
    a0 = *(volatile u32 *)(unsigned long)(sp + (528));
    a1 = s8 << (0x5 & 31);
    a2 = 64;
    callee = s1; a1 = v0 + a1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_56308;
L_56308:
    a1 = 10;
    v1 = s8 * a1;
    v0 = *(volatile u32 *)(unsigned long)(sp + (336));
    a0 = *(volatile u32 *)(unsigned long)(sp + (468));
    a2 = 20;
    callee = s1; a1 = v1 + v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_56324;
L_56324:
    a0 = *(volatile u32 *)(unsigned long)(sp + (520));
    a2 = 20;
    callee = s1; a1 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_56334;
L_56334:
    v0 = sp + 600;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = sp + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = sp + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(sp + (384)); goto L_55fd4;
L_56354:
    v0 = 32;
    branch = (s3 != v0); v0 = *(volatile u32 *)(unsigned long)(sp + (312));
    if (branch) goto L_55354;
    goto L_56360;
L_56360:
    s2 = s2 + 1;
    v0 = 18;
    if (s2 != v0) { v0 = s2 << (0x5 & 31); goto L_55330; }
    goto L_56370;
L_56370:
    ra = *(volatile u32 *)(unsigned long)(sp + (684));
    s8 = *(volatile u32 *)(unsigned long)(sp + (680));
    s7 = *(volatile u32 *)(unsigned long)(sp + (676));
    s6 = *(volatile u32 *)(unsigned long)(sp + (672));
    s5 = *(volatile u32 *)(unsigned long)(sp + (668));
    s4 = *(volatile u32 *)(unsigned long)(sp + (664));
    s3 = *(volatile u32 *)(unsigned long)(sp + (660));
    s2 = *(volatile u32 *)(unsigned long)(sp + (656));
    s1 = *(volatile u32 *)(unsigned long)(sp + (652));
    s0 = *(volatile u32 *)(unsigned long)(sp + (648));
    sp = sp + 688;
    return ((u64)v1 << 32) | v0;
}
