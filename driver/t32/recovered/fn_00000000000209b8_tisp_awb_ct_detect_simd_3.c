/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_dc02c[] __asm__("t32_data_dc02c");
extern unsigned char ref_t32_data_dc004[] __asm__("t32_data_dc004");
extern unsigned char ref_t32_data_dbfdc[] __asm__("t32_data_dbfdc");
extern unsigned char ref_t32_data_dbfb4[] __asm__("t32_data_dbfb4");
extern unsigned char ref_t32_data_dbf8c[] __asm__("t32_data_dbf8c");
extern unsigned char ref_t32_data_dbf64[] __asm__("t32_data_dbf64");
extern unsigned char ref_t32_data_dbf3c[] __asm__("t32_data_dbf3c");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_bf150[] __asm__("t32_data_bf150");
extern unsigned char ref_t32_data_bf15c[] __asm__("t32_data_bf15c");
extern unsigned char ref_t32_data_bf164[] __asm__("t32_data_bf164");
extern unsigned char ref_t32_data_dbf28[] __asm__("t32_data_dbf28");
extern unsigned char ref_t32_data_dbf14[] __asm__("t32_data_dbf14");
extern unsigned char ref_t32_data_db710[] __asm__("t32_data_db710");
extern unsigned char ref_ISPAWBInterpolation1[] __asm__("ISPAWBInterpolation1");
extern unsigned char ref_t32_data_dbf10[] __asm__("t32_data_dbf10");
extern unsigned char ref_func_zone_ct_weight[] __asm__("func_zone_ct_weight");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c7d34[] __asm__("t32_data_c7d34");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
extern unsigned char ref_ISPAWBInterpolation2[] __asm__("ISPAWBInterpolation2");
extern unsigned char ref_t32_data_db690[] __asm__("t32_data_db690");
extern unsigned char ref_t32_data_db5a0[] __asm__("t32_data_db5a0");
extern unsigned char ref_t32_data_db4b0[] __asm__("t32_data_db4b0");
extern unsigned char ref_t32_data_db3c0[] __asm__("t32_data_db3c0");
extern unsigned char ref_t32_data_db2d0[] __asm__("t32_data_db2d0");
extern unsigned char ref_t32_data_db250[] __asm__("t32_data_db250");
extern unsigned char ref_t32_data_db1d0[] __asm__("t32_data_db1d0");
extern unsigned char ref_t32_data_db150[] __asm__("t32_data_db150");
extern unsigned char ref_t32_data_db060[] __asm__("t32_data_db060");
extern unsigned char ref_t32_data_db050[] __asm__("t32_data_db050");
extern unsigned char ref_t32_data_db040[] __asm__("t32_data_db040");
extern unsigned char ref_t32_data_db030[] __asm__("t32_data_db030");
extern unsigned char ref_t32_data_db020[] __asm__("t32_data_db020");
extern unsigned char ref_t32_data_db010[] __asm__("t32_data_db010");
extern unsigned char ref_t32_data_db000[] __asm__("t32_data_db000");
extern unsigned char ref_t32_data_ce130[] __asm__("t32_data_ce130");
extern unsigned char ref_t32_data_dae60[] __asm__("t32_data_dae60");
extern unsigned char ref_t32_data_dae50[] __asm__("t32_data_dae50");
extern unsigned char ref_t32_data_dae40[] __asm__("t32_data_dae40");
extern unsigned char ref_t32_data_dae30[] __asm__("t32_data_dae30");
extern unsigned char ref_t32_data_dadf0[] __asm__("t32_data_dadf0");
extern unsigned char ref_t32_data_dae00[] __asm__("t32_data_dae00");
extern unsigned char ref_t32_data_dae20[] __asm__("t32_data_dae20");
extern unsigned char ref_t32_data_dae10[] __asm__("t32_data_dae10");
extern unsigned char ref_Tiziano_Awb_Ct_Detect_GrayWorld[] __asm__("Tiziano_Awb_Ct_Detect_GrayWorld");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
extern unsigned char ref_fix_point_mult3_32[] __asm__("fix_point_mult3_32");
extern unsigned char ref_t32_data_dafd0[] __asm__("t32_data_dafd0");
extern unsigned char ref_t32_data_dafa8[] __asm__("t32_data_dafa8");
extern unsigned char ref_t32_data_daf80[] __asm__("t32_data_daf80");
extern unsigned char ref_t32_data_daf58[] __asm__("t32_data_daf58");
extern unsigned char ref_t32_data_daf30[] __asm__("t32_data_daf30");
extern unsigned char ref_t32_data_daf24[] __asm__("t32_data_daf24");
extern unsigned char ref_t32_data_daf10[] __asm__("t32_data_daf10");
extern unsigned char ref_t32_data_daec0[] __asm__("t32_data_daec0");
extern unsigned char ref_t32_data_dae70[] __asm__("t32_data_dae70");
extern unsigned char ref_t32_data_daee8[] __asm__("t32_data_daee8");
extern unsigned char ref_t32_data_dae98[] __asm__("t32_data_dae98");
extern unsigned char ref_Tiziano_Awb_Ct_Cal[] __asm__("Tiziano_Awb_Ct_Cal");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 tisp_awb_ct_detect_simd_3(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[208] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_20a1c = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_20bb8 = ((u32)(unsigned long)ref_t32_data_dc02c + 0x8000U) & 0xffff0000U;
    const u32 hi_20c04 = ((u32)(unsigned long)ref_t32_data_dc004 + 0x8000U) & 0xffff0000U;
    const u32 hi_20c18 = ((u32)(unsigned long)ref_t32_data_dbfdc + 0x8000U) & 0xffff0000U;
    const u32 hi_20c2c = ((u32)(unsigned long)ref_t32_data_dbfb4 + 0x8000U) & 0xffff0000U;
    const u32 hi_20c40 = ((u32)(unsigned long)ref_t32_data_dbf8c + 0x8000U) & 0xffff0000U;
    const u32 hi_20c54 = ((u32)(unsigned long)ref_t32_data_dbf64 + 0x8000U) & 0xffff0000U;
    const u32 hi_20c68 = ((u32)(unsigned long)ref_t32_data_dbf3c + 0x8000U) & 0xffff0000U;
    const u32 hi_20c84 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_20c80 = ((u32)(unsigned long)ref_t32_data_bf150 + 0x8000U) & 0xffff0000U;
    const u32 hi_20ca8 = ((u32)(unsigned long)ref_t32_data_bf15c + 0x8000U) & 0xffff0000U;
    const u32 hi_20cd0 = ((u32)(unsigned long)ref_t32_data_bf164 + 0x8000U) & 0xffff0000U;
    const u32 hi_20ce8 = ((u32)(unsigned long)ref_t32_data_dbf28 + 0x8000U) & 0xffff0000U;
    const u32 hi_20cec = ((u32)(unsigned long)ref_t32_data_dbf14 + 0x8000U) & 0xffff0000U;
    const u32 hi_20f84 = ((u32)(unsigned long)ref_t32_data_db710 + 0x8000U) & 0xffff0000U;
    const u32 hi_20f94 = ((u32)(unsigned long)ref_ISPAWBInterpolation1 + 0x8000U) & 0xffff0000U;
    const u32 hi_20fe0 = ((u32)(unsigned long)ref_t32_data_dbf10 + 0x8000U) & 0xffff0000U;
    const u32 hi_2372c = ((u32)(unsigned long)ref_t32_data_dbf10 + 0x8000U) & 0xffff0000U;
    const u32 hi_21284 = ((u32)(unsigned long)ref_func_zone_ct_weight + 0x8000U) & 0xffff0000U;
    const u32 hi_21368 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_21364 = ((u32)(unsigned long)ref_t32_data_c7d34 + 0x8000U) & 0xffff0000U;
    const u32 hi_21384 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_213ac = ((u32)(unsigned long)ref_func_zone_ct_weight + 0x8000U) & 0xffff0000U;
    const u32 hi_21498 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_21494 = ((u32)(unsigned long)ref_t32_data_c7d34 + 0x8000U) & 0xffff0000U;
    const u32 hi_214b4 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_214dc = ((u32)(unsigned long)ref_func_zone_ct_weight + 0x8000U) & 0xffff0000U;
    const u32 hi_2161c = ((u32)(unsigned long)ref_ISPAWBInterpolation2 + 0x8000U) & 0xffff0000U;
    const u32 hi_21710 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_2170c = ((u32)(unsigned long)ref_t32_data_c7d34 + 0x8000U) & 0xffff0000U;
    const u32 hi_2172c = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_21754 = ((u32)(unsigned long)ref_func_zone_ct_weight + 0x8000U) & 0xffff0000U;
    const u32 hi_21bbc = ((u32)(unsigned long)ref_t32_data_db690 + 0x8000U) & 0xffff0000U;
    const u32 hi_21bd8 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_2218c = ((u32)(unsigned long)ref_t32_data_db5a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_22198 = ((u32)(unsigned long)ref_t32_data_db4b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_2219c = ((u32)(unsigned long)ref_t32_data_db3c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_221a4 = ((u32)(unsigned long)ref_t32_data_db2d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_2246c = ((u32)(unsigned long)ref_t32_data_db250 + 0x8000U) & 0xffff0000U;
    const u32 hi_22470 = ((u32)(unsigned long)ref_t32_data_db1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_22474 = ((u32)(unsigned long)ref_t32_data_db150 + 0x8000U) & 0xffff0000U;
    const u32 hi_226f0 = ((u32)(unsigned long)ref_t32_data_db060 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b10 = ((u32)(unsigned long)ref_t32_data_db050 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b38 = ((u32)(unsigned long)ref_t32_data_db040 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b44 = ((u32)(unsigned long)ref_t32_data_db030 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b50 = ((u32)(unsigned long)ref_t32_data_db020 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b58 = ((u32)(unsigned long)ref_t32_data_db010 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b68 = ((u32)(unsigned long)ref_t32_data_db000 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b80 = ((u32)(unsigned long)ref_t32_data_ce130 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b84 = ((u32)(unsigned long)ref_t32_data_dae60 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b90 = ((u32)(unsigned long)ref_t32_data_dae50 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b94 = ((u32)(unsigned long)ref_t32_data_dae40 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b98 = ((u32)(unsigned long)ref_t32_data_dae30 + 0x8000U) & 0xffff0000U;
    const u32 hi_22ba8 = ((u32)(unsigned long)ref_t32_data_dadf0 + 0x8000U) & 0xffff0000U;
    const u32 hi_22ba0 = ((u32)(unsigned long)ref_t32_data_dae00 + 0x8000U) & 0xffff0000U;
    const u32 hi_22b9c = ((u32)(unsigned long)ref_t32_data_dae20 + 0x8000U) & 0xffff0000U;
    const u32 hi_22bac = ((u32)(unsigned long)ref_t32_data_dae10 + 0x8000U) & 0xffff0000U;
    const u32 hi_22e1c = ((u32)(unsigned long)ref_Tiziano_Awb_Ct_Detect_GrayWorld + 0x8000U) & 0xffff0000U;
    const u32 hi_22e34 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_22eb8 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_22ec0 = ((u32)(unsigned long)ref_fix_point_mult3_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_2305c = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_23058 = ((u32)(unsigned long)ref_t32_data_c7d34 + 0x8000U) & 0xffff0000U;
    const u32 hi_230f4 = ((u32)(unsigned long)ref_t32_data_c7d34 + 0x8000U) & 0xffff0000U;
    const u32 hi_230ec = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_23100 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_23108 = ((u32)(unsigned long)ref_fix_point_mult3_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_233e4 = ((u32)(unsigned long)ref_t32_data_dc02c + 0x8000U) & 0xffff0000U;
    const u32 hi_233e8 = ((u32)(unsigned long)ref_t32_data_dc004 + 0x8000U) & 0xffff0000U;
    const u32 hi_23590 = ((u32)(unsigned long)ref_t32_data_dbf8c + 0x8000U) & 0xffff0000U;
    const u32 hi_233ec = ((u32)(unsigned long)ref_t32_data_dbfdc + 0x8000U) & 0xffff0000U;
    const u32 hi_235e4 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_23630 = ((u32)(unsigned long)ref_t32_data_dbf64 + 0x8000U) & 0xffff0000U;
    const u32 hi_23654 = ((u32)(unsigned long)ref_t32_data_dbf3c + 0x8000U) & 0xffff0000U;
    const u32 hi_236dc = ((u32)(unsigned long)ref_t32_data_dc02c + 0x8000U) & 0xffff0000U;
    const u32 hi_23730 = ((u32)(unsigned long)ref_t32_data_dafa8 + 0x8000U) & 0xffff0000U;
    const u32 hi_23734 = ((u32)(unsigned long)ref_t32_data_daf80 + 0x8000U) & 0xffff0000U;
    const u32 hi_23738 = ((u32)(unsigned long)ref_t32_data_daf58 + 0x8000U) & 0xffff0000U;
    const u32 hi_2373c = ((u32)(unsigned long)ref_t32_data_daf30 + 0x8000U) & 0xffff0000U;
    const u32 hi_23758 = ((u32)(unsigned long)ref_t32_data_dc004 + 0x8000U) & 0xffff0000U;
    const u32 hi_2375c = ((u32)(unsigned long)ref_t32_data_dbfdc + 0x8000U) & 0xffff0000U;
    const u32 hi_23760 = ((u32)(unsigned long)ref_t32_data_dbf8c + 0x8000U) & 0xffff0000U;
    const u32 hi_23764 = ((u32)(unsigned long)ref_t32_data_dbf64 + 0x8000U) & 0xffff0000U;
    const u32 hi_23768 = ((u32)(unsigned long)ref_t32_data_dbf3c + 0x8000U) & 0xffff0000U;
    const u32 hi_237bc = ((u32)(unsigned long)ref_t32_data_dbfb4 + 0x8000U) & 0xffff0000U;
    const u32 hi_23924 = ((u32)(unsigned long)ref_t32_data_dbfb4 + 0x8000U) & 0xffff0000U;
    const u32 hi_2392c = ((u32)(unsigned long)ref_t32_data_daf24 + 0x8000U) & 0xffff0000U;
    const u32 hi_2398c = ((u32)(unsigned long)ref_t32_data_daf24 + 0x8000U) & 0xffff0000U;
    const u32 hi_23c2c = ((u32)(unsigned long)ref_t32_data_daf24 + 0x8000U) & 0xffff0000U;
    const u32 hi_23d1c = ((u32)(unsigned long)ref_t32_data_dbf28 + 0x8000U) & 0xffff0000U;
    const u32 hi_23dc0 = ((u32)(unsigned long)ref_t32_data_daf24 + 0x8000U) & 0xffff0000U;
    const u32 hi_23ea4 = ((u32)(unsigned long)ref_t32_data_dbf28 + 0x8000U) & 0xffff0000U;
    const u32 hi_23ebc = ((u32)(unsigned long)ref_t32_data_dbf14 + 0x8000U) & 0xffff0000U;
    const u32 hi_23ef8 = ((u32)(unsigned long)ref_t32_data_dbf14 + 0x8000U) & 0xffff0000U;
    const u32 hi_23f6c = ((u32)(unsigned long)ref_t32_data_daf10 + 0x8000U) & 0xffff0000U;
    const u32 hi_23f70 = ((u32)(unsigned long)ref_t32_data_dbf14 + 0x8000U) & 0xffff0000U;
    const u32 hi_23f78 = ((u32)(unsigned long)ref_t32_data_dbf28 + 0x8000U) & 0xffff0000U;
    const u32 hi_24044 = ((u32)(unsigned long)ref_t32_data_daf24 + 0x8000U) & 0xffff0000U;
    const u32 hi_240e0 = ((u32)(unsigned long)ref_t32_data_daf24 + 0x8000U) & 0xffff0000U;
    const u32 hi_24170 = ((u32)(unsigned long)ref_t32_data_dc02c + 0x8000U) & 0xffff0000U;
    const u32 hi_2418c = ((u32)(unsigned long)ref_t32_data_daec0 + 0x8000U) & 0xffff0000U;
    const u32 hi_241a4 = ((u32)(unsigned long)ref_t32_data_dae70 + 0x8000U) & 0xffff0000U;
    const u32 hi_241ac = ((u32)(unsigned long)ref_t32_data_daee8 + 0x8000U) & 0xffff0000U;
    const u32 hi_241b4 = ((u32)(unsigned long)ref_t32_data_dae98 + 0x8000U) & 0xffff0000U;
    const u32 hi_2436c = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_243b4 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_24454 = ((u32)(unsigned long)ref_t32_data_dafd0 + 0x8000U) & 0xffff0000U;
    const u32 hi_24478 = ((u32)(unsigned long)ref_t32_data_dafa8 + 0x8000U) & 0xffff0000U;
    const u32 hi_244b0 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_24510 = ((u32)(unsigned long)ref_Tiziano_Awb_Ct_Cal + 0x8000U) & 0xffff0000U;
    const u32 hi_23c98 = ((u32)(unsigned long)ref_t32_data_dbf28 + 0x8000U) & 0xffff0000U;
    const u32 hi_23ed8 = ((u32)(unsigned long)ref_t32_data_dbf14 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[144];
L_209b8:
    sp = sp + -512;
    *(volatile u32 *)(unsigned long)(sp + (508)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (504)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (500)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (496)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (492)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (488)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (480)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (476)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (484)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (472)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (16));
    s8 = sp;
    s5 = a0;
    *(volatile u32 *)(unsigned long)(s8 + (124)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(a0 + (20));
    s3 = *(volatile u32 *)(unsigned long)(a0 + (24));
    *(volatile u32 *)(unsigned long)(s8 + (308)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (4));
    s0 = *(volatile u32 *)(unsigned long)(a0 + (28));
    *(volatile u32 *)(unsigned long)(s8 + (516)) = a1;
    *(volatile u32 *)(unsigned long)(s8 + (312)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (32));
    *(volatile u32 *)(unsigned long)(s8 + (520)) = a2;
    s1 = hi_20a1c;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (36));
    sp = sp + -64;
    s1 = s1 - hi_20a1c + ((u32)(unsigned long)ref_memset + (0));
    *(volatile u32 *)(unsigned long)(s8 + (220)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (8));
    a2 = 40;
    a1 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (12));
    s4 = sp + 47;
    s4 = s4 >> (0x4 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (168)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (40));
    s4 = s4 << (0x4 & 31);
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(s8 + (364)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    s2 = *(volatile u32 *)(unsigned long)(s5 + (56));
    *(volatile u32 *)(unsigned long)(s8 + (316)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (68));
    *(volatile u32 *)(unsigned long)(s8 + (320)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s5 + (44));
    *(volatile u32 *)(unsigned long)(s8 + (324)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (72));
    *(volatile u32 *)(unsigned long)(s8 + (228)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s5 + (48));
    *(volatile u32 *)(unsigned long)(s8 + (372)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (76));
    *(volatile u32 *)(unsigned long)(s8 + (260)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s5 + (52));
    *(volatile u32 *)(unsigned long)(s8 + (376)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (80));
    s6 = *(volatile u16 *)(unsigned long)(v0 + (0));
    s7 = *(volatile u16 *)(unsigned long)(v0 + (2));
    *(volatile u32 *)(unsigned long)(s8 + (380)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (84));
    v0 = *(volatile u32 *)(unsigned long)(s5 + (60));
    *(volatile u32 *)(unsigned long)(s8 + (384)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (132));
    *(volatile u32 *)(unsigned long)(s8 + (368)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s5 + (64));
    *(volatile u32 *)(unsigned long)(s8 + (108)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (136));
    *(volatile u32 *)(unsigned long)(s8 + (156)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (140));
    *(volatile u32 *)(unsigned long)(s8 + (328)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (144));
    *(volatile u32 *)(unsigned long)(s8 + (388)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (148));
    *(volatile u32 *)(unsigned long)(s8 + (392)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (152));
    *(volatile u32 *)(unsigned long)(s8 + (264)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (156));
    *(volatile u32 *)(unsigned long)(s8 + (268)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (160));
    *(volatile u32 *)(unsigned long)(s8 + (132)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (164));
    *(volatile u32 *)(unsigned long)(s8 + (144)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (172));
    *(volatile u32 *)(unsigned long)(s8 + (112)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (176));
    *(volatile u32 *)(unsigned long)(s8 + (396)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (180));
    *(volatile u32 *)(unsigned long)(s8 + (400)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (184));
    *(volatile u32 *)(unsigned long)(s8 + (160)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (188));
    *(volatile u32 *)(unsigned long)(s8 + (272)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (88));
    *(volatile u32 *)(unsigned long)(s8 + (164)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (92));
    *(volatile u32 *)(unsigned long)(s8 + (172)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (96));
    *(volatile u32 *)(unsigned long)(s8 + (332)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (100));
    *(volatile u32 *)(unsigned long)(s8 + (336)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (108));
    *(volatile u32 *)(unsigned long)(s8 + (404)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (112));
    *(volatile u32 *)(unsigned long)(s8 + (232)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (116));
    *(volatile u32 *)(unsigned long)(s8 + (76)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (72)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (276)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (120));
    *(volatile u32 *)(unsigned long)(s8 + (68)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (236)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (124));
    *(volatile u32 *)(unsigned long)(s8 + (176)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s5 + (128));
    *(volatile u32 *)(unsigned long)(s8 + (148)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (168));
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(s8 + (240)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (2));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (6));
    *(volatile u32 *)(unsigned long)(s8 + (64)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (120)) = a0;
    *(volatile u32 *)(unsigned long)(s8 + (104)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = hi_20bb8;
    a0 = a0 - hi_20bb8 + (u32)(unsigned long)ref_t32_data_dc02c;
    *(volatile u32 *)(unsigned long)(s8 + (280)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    *(volatile u32 *)(unsigned long)(s8 + (408)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    *(volatile u32 *)(unsigned long)(s8 + (412)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (12));
    *(volatile u32 *)(unsigned long)(s8 + (60)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (16));
    *(volatile u32 *)(unsigned long)(s8 + (340)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (20));
    *(volatile u32 *)(unsigned long)(s8 + (416)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (148));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (24));
    *(volatile u32 *)(unsigned long)(s8 + (344)) = v1;
    callee = s1; *(volatile u32 *)(unsigned long)(s8 + (420)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c04;
L_20c04:
    a0 = hi_20c04;
    a2 = 40;
    a1 = 0;
    callee = s1; a0 = a0 - hi_20c04 + (u32)(unsigned long)ref_t32_data_dc004;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c18;
L_20c18:
    a0 = hi_20c18;
    a2 = 40;
    a1 = 0;
    callee = s1; a0 = a0 - hi_20c18 + (u32)(unsigned long)ref_t32_data_dbfdc;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c2c;
L_20c2c:
    a0 = hi_20c2c;
    a2 = 40;
    a1 = 0;
    callee = s1; a0 = a0 - hi_20c2c + (u32)(unsigned long)ref_t32_data_dbfb4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c40;
L_20c40:
    a0 = hi_20c40;
    a2 = 40;
    a1 = 0;
    callee = s1; a0 = a0 - hi_20c40 + (u32)(unsigned long)ref_t32_data_dbf8c;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c54;
L_20c54:
    a0 = hi_20c54;
    a2 = 40;
    a1 = 0;
    callee = s1; a0 = a0 - hi_20c54 + (u32)(unsigned long)ref_t32_data_dbf64;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c68;
L_20c68:
    a0 = hi_20c68;
    a2 = 40;
    a1 = 0;
    callee = s1; a0 = a0 - hi_20c68 + (u32)(unsigned long)ref_t32_data_dbf3c;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20c7c;
L_20c7c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    a1 = hi_20c80;
    s1 = hi_20c84;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    s1 = s1 - hi_20c84 + ((u32)(unsigned long)ref_memcpy + (0));
    a2 = 10;
    a1 = a1 - hi_20c80 + (u32)(unsigned long)ref_t32_data_bf150;
    a0 = s8 + 32;
    callee = s1; *(volatile u32 *)(unsigned long)(s8 + (424)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20ca4;
L_20ca4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    a1 = hi_20ca8;
    a2 = 8;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (10));
    a1 = a1 - hi_20ca8 + (u32)(unsigned long)ref_t32_data_bf15c;
    a0 = s8 + 52;
    *(volatile u32 *)(unsigned long)(s8 + (428)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (12));
    callee = s1; *(volatile u32 *)(unsigned long)(s8 + (348)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20cd0;
L_20cd0:
    a1 = hi_20cd0;
    a1 = a1 - hi_20cd0 + (u32)(unsigned long)ref_t32_data_bf164;
    a0 = s8 + 44;
    callee = s1; a2 = 8;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20ce4;
L_20ce4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    a0 = hi_20ce8;
    v1 = hi_20cec;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (14));
    a0 = a0 - hi_20ce8 + (u32)(unsigned long)ref_t32_data_dbf28;
    v1 = v1 - hi_20cec + (u32)(unsigned long)ref_t32_data_dbf14;
    *(volatile u32 *)(unsigned long)(s8 + (432)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    a1 = 6;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (16));
    *(volatile u32 *)(unsigned long)(s8 + (436)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (18));
    *(volatile u32 *)(unsigned long)(s8 + (440)) = v0;
    v0 = 0;
L_20d20:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (236));
    a2 = a2 + v0;
    a3 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a2 = a0 + v0;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = a3;
    a2 = *(volatile u32 *)(unsigned long)(s8 + (176));
    a2 = a2 + v0;
    a3 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a2 = v1 + v0;
    v0 = v0 + 2;
    branch = (v0 != a1); *(volatile u16 *)(unsigned long)(a2 + (0)) = a3;
    if (branch) goto L_20d20;
    goto L_20d50;
L_20d50:
    v0 = 0;
    v1 = 8;
L_20d58:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (236));
    a0 = s8 + 52;
    a0 = a0 + v0;
    a1 = a1 + v0;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (6));
    *(volatile u16 *)(unsigned long)(a0 + (0)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(s8 + (176));
    a0 = s8 + 44;
    a0 = a0 + v0;
    a1 = a1 + v0;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (6));
    v0 = v0 + 2;
    branch = (v0 != v1); *(volatile u16 *)(unsigned long)(a0 + (0)) = a1;
    if (branch) goto L_20d58;
    goto L_20d90;
L_20d90:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (164));
    v0 = 0;
    a0 = 10;
L_20d9c:
    a1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    if (a1 != 0) { v0 = v0 + 1; goto L_20db4; }
    goto L_20da8;
L_20da8:
    v0 = v0 & 0xff;
    *(volatile u32 *)(unsigned long)(s8 + (152)) = v0; goto L_20dc4;
L_20db4:
    v0 = v0 & 0xffff;
    branch = (v0 != a0); v1 = v1 + 4;
    if (branch) goto L_20d9c;
    goto L_20dc0;
L_20dc0:
    *(volatile u32 *)(unsigned long)(s8 + (152)) = 0;
L_20dc4:
    v0 = *(volatile u16 *)(unsigned long)(s2 + (6));
    v1 = 1;
    branch = (v0 == v1); v1 = *(volatile u32 *)(unsigned long)(s8 + (520));
    if (branch) goto L_22de4;
    goto L_20dd4;
L_20dd4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (156));
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = v0;
    v0 = 0;
L_20de4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (120));
    branch = (v0 == v1); a1 = a0;
    if (branch) goto L_20e28;
    goto L_20df0;
L_20df0:
    v1 = 0;
L_20df4:
    a3 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (v1 == a3); v1 = v1 + 1;
    if (branch) goto L_20e18;
    goto L_20e00;
L_20e00:
    a3 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v1 = v1 & 0xffff;
    t0 = (u32)a2 < (u32)(a3);
    if (t0 != 0) a2 = a3;
    a1 = a1 + 4; goto L_20df4;
L_20e18:
    v0 = v0 + 1;
    v0 = v0 & 0xffff;
    a0 = a0 + 128; goto L_20de4;
L_20e28:
    v0 = 0;
    t0 = 2;
L_20e30:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (120));
    v1 = v0 & 0xffff;
    v1 = (u32)v1 < (u32)(a0);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (156));
    if (branch) goto L_20ebc;
    goto L_20e44;
L_20e44:
    a0 = v0 << (0x7 & 31);
    a3 = v1 + a0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (160));
    a0 = v1 + a0;
    v1 = 0;
L_20e58:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (104));
    if (v1 == a1) { v0 = v0 + 1; goto L_20e30; }
    goto L_20e64;
L_20e64:
    a1 = *(volatile u16 *)(unsigned long)(s2 + (2));
    if (a1 == t0) { a0 = *(volatile u32 *)(unsigned long)(s8 + (160)); goto L_20e7c; }
    goto L_20e70;
L_20e70:
    if (a2 != 0) { a1 = *(volatile u32 *)(unsigned long)(a3 + (0)); goto L_20e98; }
    goto L_20e78;
L_20e78:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (160));
L_20e7c:
    v0 = v0 & 0xffff;
    v0 = v0 << (0x7 & 31);
    v0 = a0 + v0;
    v1 = v1 << (0x2 & 31);
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0; goto L_22ddc;
L_20e98:
    v1 = v1 + 1;
    v1 = v1 & 0xffff;
    a1 = a1 << (s6 & 31);
    if (a2) { lo = a1 / a2; hi = a1 % a2; } else { lo = ~0U; hi = a1; }
    a3 = a3 + 4;
    a0 = a0 + 4;
    a1 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (-4)) = a1; goto L_20e58;
L_20ebc:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    a1 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (284)) = v0;
    a3 = v0;
L_20ecc:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (120));
    branch = (a1 == v0); v0 = a3;
    if (branch) goto L_20f64;
    goto L_20ed8;
L_20ed8:
    a2 = 0;
L_20edc:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (104));
    if (a2 == v1) { a1 = a1 + 1; goto L_20f58; }
    goto L_20ee8;
L_20ee8:
    v1 = *(volatile u32 *)(unsigned long)(s3 + (56));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 << (s7 & 31);
    t0 = (u32)v1 < (u32)(a0);
    if (t0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (0)) = v1; goto L_20f18; }
    goto L_20f00;
L_20f00:
    v1 = *(volatile u32 *)(unsigned long)(s3 + (0));
    v1 = v1 << (s7 & 31);
    a0 = (u32)a0 < (u32)(v1);
    if (a0 == 0) { v1 = *(volatile u32 *)(unsigned long)(s0 + (56)); goto L_20f1c; }
    goto L_20f14;
L_20f14:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
L_20f18:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (56));
L_20f1c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4096));
    v1 = v1 << (s7 & 31);
    t0 = (u32)v1 < (u32)(a0);
    if (t0 != 0) { *(volatile u32 *)(unsigned long)(v0 + (4096)) = v1; goto L_20f48; }
    goto L_20f30;
L_20f30:
    v1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    v1 = v1 << (s7 & 31);
    a0 = (u32)a0 < (u32)(v1);
    if (a0 == 0) { a2 = a2 + 1; goto L_20f4c; }
    goto L_20f44;
L_20f44:
    *(volatile u32 *)(unsigned long)(v0 + (4096)) = v1;
L_20f48:
    a2 = a2 + 1;
L_20f4c:
    a2 = a2 & 0xffff;
    v0 = v0 + 4; goto L_20edc;
L_20f58:
    a1 = a1 & 0xffff;
    a3 = a3 + 128; goto L_20ecc;
L_20f64:
    v0 = 0xfU << 16;
    v0 = v0 + 16960;
    v0 = v0 << (s7 & 31);
    v1 = 1;
    *(volatile u32 *)(unsigned long)(s8 + (300)) = v0;
    v0 = s7 + -1;
    v0 = v1 << (v0 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (116)) = v0;
    v0 = hi_20f84;
    v0 = v0 - hi_20f84 + (u32)(unsigned long)ref_t32_data_db710;
    *(volatile u32 *)(unsigned long)(s8 + (216)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    s2 = hi_20f94;
    s2 = s2 - hi_20f94 + (u32)(unsigned long)ref_ISPAWBInterpolation1;
    *(volatile u32 *)(unsigned long)(s8 + (288)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (120));
    v0 = v0 << (0x7 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (136)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (136));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(s8 + (444)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    v0 = v0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (252)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    *(volatile u32 *)(unsigned long)(s8 + (296)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    *(volatile u32 *)(unsigned long)(s8 + (140)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (216));
    *(volatile u32 *)(unsigned long)(s8 + (256)) = v0;
    v0 = hi_20fe0;
    *(volatile u32 *)(unsigned long)(s8 + (360)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (452)) = v0;
    v0 = v0 - hi_20fe0 + (u32)(unsigned long)ref_t32_data_dbf10;
    *(volatile u32 *)(unsigned long)(s8 + (304)) = v0;
L_20ff4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (444));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (140));
    branch = (v0 == v1); v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    if (branch) goto L_21800;
    goto L_21004;
L_21004:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (252));
    s1 = *(volatile u32 *)(unsigned long)(s8 + (296));
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(s8 + (448)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (200)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (248)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (256));
    *(volatile u32 *)(unsigned long)(s8 + (292)) = v0;
L_21034:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (244));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (448));
    branch = (v0 == v1); v0 = *(volatile u32 *)(unsigned long)(s8 + (256));
    if (branch) goto L_217dc;
    goto L_21044;
L_21044:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v0 = v0 << (s7 & 31);
    v0 = (u32)a0 < (u32)(v0);
    branch = (v0 != 0); t3 = 0;
    if (branch) goto L_210c8;
    goto L_2105c;
L_2105c:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (56));
    v0 = v0 << (s7 & 31);
    v1 = (u32)v0 < (u32)(a0);
    if (v1 != 0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (0)); goto L_210cc; }
    goto L_21070;
L_21070:
    branch = (a0 == v0); t3 = 15;
    if (branch) goto L_210c8;
    goto L_21078;
L_21078:
    v1 = s3;
    t3 = 0;
    a1 = 14;
L_21084:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = v0 << (s7 & 31);
    v0 = (u32)a0 < (u32)(v0);
    branch = (v0 != 0); ;
    if (branch) goto L_210ac;
    goto L_21098;
L_21098:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = v0 << (s7 & 31);
    v0 = (u32)a0 < (u32)(v0);
    if (v0 != 0) { t3 = t3 + 1; goto L_210c4; }
    goto L_210ac;
L_210ac:
    branch = (t3 == a1); v1 = v1 + 4;
    if (branch) goto L_210c0;
    goto L_210b4;
L_210b4:
    t3 = t3 + 1;
    t3 = t3 & 0xffff; goto L_21084;
L_210c0:
    t3 = t3 + 1;
L_210c4:
    t3 = t3 & 0xff;
L_210c8:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
L_210cc:
    a0 = *(volatile u32 *)(unsigned long)(s1 + (4096));
    v0 = v0 << (s7 & 31);
    v0 = (u32)a0 < (u32)(v0);
    branch = (v0 != 0); v0 = 15;
    if (branch) goto L_21180;
    goto L_210e0;
L_210e0:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (56));
    v0 = v0 << (s7 & 31);
    v1 = (u32)v0 < (u32)(a0);
    if (v1 != 0) { v0 = 15; goto L_21180; }
    goto L_210f4;
L_210f4:
    branch = (a0 == v0); v1 = s0;
    if (branch) goto L_211a4;
    goto L_210fc;
L_210fc:
    t4 = 0;
    a1 = 14;
L_21104:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = v0 << (s7 & 31);
    v0 = (u32)a0 < (u32)(v0);
    branch = (v0 != 0); ;
    if (branch) goto L_2112c;
    goto L_21118;
L_21118:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = v0 << (s7 & 31);
    v0 = (u32)a0 < (u32)(v0);
    if (v0 != 0) { t4 = t4 + 1; goto L_21144; }
    goto L_2112c;
L_2112c:
    branch = (t4 == a1); v1 = v1 + 4;
    if (branch) goto L_21140;
    goto L_21134;
L_21134:
    t4 = t4 + 1;
    t4 = t4 & 0xffff; goto L_21104;
L_21140:
    t4 = t4 + 1;
L_21144:
    v0 = 15;
    branch = (t3 != v0); t4 = t4 & 0xff;
    if (branch) goto L_2116c;
    goto L_21150;
L_21150:
    branch = (t4 == t3); v0 = 195;
    if (branch) goto L_211b8;
    goto L_21158;
L_21158:
    v0 = t4 + -1;
    v1 = 14;
    v0 = v0 * v1;
    v0 = v0 + 13; goto L_2119c;
L_2116c:
    branch = (t4 != v0); v1 = t4 + -1;
    if (branch) goto L_2118c;
    goto L_21174;
L_21174:
    v0 = t3 + 181;
L_21178:
    t4 = 15; goto L_211b8;
L_21180:
    branch = (t3 == v0); t4 = 0;
    if (branch) goto L_21158;
    goto L_21188;
L_21188:
    v1 = t4 + -1;
L_2118c:
    a0 = 14;
    a1 = v1 * a0;
    v0 = t3 + -1;
    v0 = a1 + v0;
L_2119c:
    v0 = v0 & 0xffff; goto L_211b8;
L_211a4:
    v0 = 15;
    branch = (t3 != v0); v0 = t3 + 181;
    if (branch) goto L_21178;
    goto L_211b0;
L_211b0:
    t4 = 15;
    v0 = 195;
L_211b8:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v1 = v0 << (0x1 & 31);
    v0 = v0 << (0x2 & 31);
    v1 = a0 + v1;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = a0 + 1;
    *(volatile u16 *)(unsigned long)(v1 + (0)) = a0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (388));
    a1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = v1 + a1;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (392));
    a0 = *(volatile u32 *)(unsigned long)(s1 + (4096));
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = v1 + a0;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (360));
    v0 = 0x1U << 16;
    branch = (t3 == 0); *(volatile u32 *)(unsigned long)(v1 - hi_20cec + (u32)(unsigned long)ref_t32_data_dbf10) = v0;
    if (branch) goto L_2121c;
    goto L_21214;
L_21214:
    branch = (t4 != 0); v0 = 15;
    if (branch) goto L_21228;
    goto L_2121c;
L_2121c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (244));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0; goto L_2177c;
L_21228:
    branch = (t3 != v0); t5 = 0x3fffU << 16;
    if (branch) goto L_213d4;
    goto L_21230;
L_21230:
    branch = (t4 != t3); t5 = t4 << (0x2 & 31);
    if (branch) goto L_212a4;
    goto L_21238;
L_21238:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (240));
    v1 = *(volatile u32 *)(unsigned long)(v0 + (896));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (248));
    v1 = v1 << (s7 & 31);
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v0 = 1;
    if (a0 != v0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (452)); goto L_21780; }
    goto L_2125c;
L_2125c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a0 = 0xfU << 16;
    a0 = a0 + 16960;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (896));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (360));
    a2 = *(volatile u32 *)(unsigned long)(s8 + (168));
    if (v0) { lo = a0 / v0; hi = a0 % v0; } else { lo = ~0U; hi = a0; }
    a1 = a1 - hi_2372c + (u32)(unsigned long)ref_t32_data_dbf10;
    *(volatile u32 *)(unsigned long)(sp + (20)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = hi_21284;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    a3 = s6;
    v0 = v0 - hi_21284 + (u32)(unsigned long)ref_func_zone_ct_weight;
    callee = v0; a0 = lo;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2129c;
L_2129c:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (248)); goto L_21778;
L_212a4:
    v0 = 60;
    t4 = t4 + -1;
    t4 = t4 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    t5 = t5 + -4;
    t6 = s0 + t5;
    a3 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (4096));
    t5 = t5 + 4;
    t5 = s0 + t5;
    a1 = s7;
    a0 = s6;
    t3 = t4 + 56;
    t4 = t4 + 116;
    v0 = v0 + t4;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    v0 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t5 + (0));
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21304;
L_21304:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (200));
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (240));
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (452));
    if (branch) goto L_21780;
    goto L_2131c;
L_2131c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (4096));
    a3 = *(volatile u32 *)(unsigned long)(t6 + (0));
    t4 = v0 + t4;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a1 = s7;
    a0 = s6;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v0 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t5 + (0));
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21358;
L_21358:
    branch = (v0 != 0); a2 = v0;
    if (branch) goto L_21380;
    goto L_21360;
L_21360:
    *(volatile u32 *)(unsigned long)(s8 + (352)) = v0;
    a0 = hi_21364;
    v0 = hi_21368;
    a1 = 940;
    v0 = v0 - hi_21368 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_21364 + (u32)(unsigned long)ref_t32_data_c7d34;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2137c;
L_2137c:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (352));
L_21380:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    v0 = hi_21384;
    v0 = v0 - hi_21384 + (u32)(unsigned long)ref_fix_point_div_32;
    callee = v0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21394;
L_21394:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    a2 = *(volatile u32 *)(unsigned long)(s8 + (168));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v0 + v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a0 = v0 >> (s7 & 31);
    v0 = hi_213ac;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (200));
    a3 = s6;
    v0 = v0 - hi_213ac + (u32)(unsigned long)ref_func_zone_ct_weight;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_213cc;
L_213cc:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (200)); goto L_21778;
L_213d4:
    branch = (t4 != v0); t5 = t5 | 0xffff;
    if (branch) goto L_21504;
    goto L_213dc;
L_213dc:
    t3 = t3 + t5;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    t3 = t3 << (0x2 & 31);
    t6 = s3 + t3;
    t5 = t3 + 840;
    t4 = t3 + 4;
    t3 = t3 + 844;
    v0 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (0));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    t4 = s3 + t4;
    a1 = s7;
    v0 = v0 + t5;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = s6;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21434;
L_21434:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (184));
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (240));
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (452));
    if (branch) goto L_21780;
    goto L_2144c;
L_2144c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(t6 + (0));
    t3 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    a1 = s7;
    a0 = s6;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v0 = v0 + t5;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21488;
L_21488:
    branch = (v0 != 0); a2 = v0;
    if (branch) goto L_214b0;
    goto L_21490;
L_21490:
    *(volatile u32 *)(unsigned long)(s8 + (352)) = v0;
    a0 = hi_21494;
    v0 = hi_21498;
    a1 = 953;
    v0 = v0 - hi_21498 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_21494 + (u32)(unsigned long)ref_t32_data_c7d34;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_214ac;
L_214ac:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (352));
L_214b0:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    v0 = hi_214b4;
    v0 = v0 - hi_214b4 + (u32)(unsigned long)ref_fix_point_div_32;
    callee = v0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_214c4;
L_214c4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    a2 = *(volatile u32 *)(unsigned long)(s8 + (168));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a0 = v0 >> (s7 & 31);
    v0 = hi_214dc;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (184));
    a3 = s6;
    v0 = v0 - hi_214dc + (u32)(unsigned long)ref_func_zone_ct_weight;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_214fc;
L_214fc:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (184)); goto L_21778;
L_21504:
    v0 = t4 + -1;
    t8 = v0 << (0x4 & 31);
    t8 = t8 - v0;
    t6 = t8 + t3;
    t6 = t6 + t5;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    t6 = t6 << (0x2 & 31);
    t9 = t6 + 4;
    t7 = t3 + t5;
    v0 = v0 + t9;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t7 = t7 << (0x2 & 31);
    t0 = s3 + t7;
    t7 = t7 + 4;
    t7 = s3 + t7;
    t2 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = *(volatile u32 *)(unsigned long)(t7 + (0));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a3 = t2;
    a2 = t1;
    v0 = v0 + t6;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = s7;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    a0 = s6;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (464)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (460)) = v1;
    *(volatile u32 *)(unsigned long)(s8 + (456)) = t2;
    callee = s2; *(volatile u32 *)(unsigned long)(s8 + (352)) = t1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21588;
L_21588:
    t8 = t8 + 15;
    t3 = t8 + t3;
    t3 = t3 + t5;
    *(volatile u32 *)(unsigned long)(s8 + (356)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    t3 = t3 << (0x2 & 31);
    t8 = t3 + 4;
    v0 = v0 + t8;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (460));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (352));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (456));
    a2 = t1;
    v0 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = t2;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    a1 = s7;
    a0 = s6;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_215e4;
L_215e4:
    t4 = t4 + t5;
    t4 = t4 << (0x2 & 31);
    v1 = s0 + t4;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (4096));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (356));
    t4 = t4 + 4;
    t4 = s0 + t4;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a1 = s7;
    a0 = s6;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_2161c;
    v0 = v0 - hi_2161c + (u32)(unsigned long)ref_ISPAWBInterpolation2;
    *(volatile u32 *)(unsigned long)(s8 + (352)) = v1;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (356)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21630;
L_21630:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (180));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (464));
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (240));
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (452));
    if (branch) goto L_21780;
    goto L_2164c;
L_2164c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t5 = *(volatile u32 *)(unsigned long)(s1 + (0));
    t9 = v0 + t9;
    v0 = *(volatile u32 *)(unsigned long)(t9 + (0));
    t7 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a2 = t5;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a3 = v1;
    a1 = s7;
    t6 = v0 + t6;
    v0 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a0 = s6;
    *(volatile u32 *)(unsigned long)(sp + (16)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    callee = s2; *(volatile u32 *)(unsigned long)(s8 + (456)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21694;
L_21694:
    t6 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (456));
    a2 = t5;
    t8 = v0 + t8;
    v0 = *(volatile u32 *)(unsigned long)(t8 + (0));
    a3 = v1;
    a1 = s7;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a0 = s6;
    t3 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    *(volatile u32 *)(unsigned long)(sp + (16)) = t7;
    callee = s2; *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_216d4;
L_216d4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (352));
    a2 = *(volatile u32 *)(unsigned long)(s1 + (4096));
    a1 = s7;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = t6;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (356));
    callee = v0; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21700;
L_21700:
    branch = (v0 != 0); a2 = v0;
    if (branch) goto L_21728;
    goto L_21708;
L_21708:
    *(volatile u32 *)(unsigned long)(s8 + (352)) = v0;
    a0 = hi_2170c;
    v0 = hi_21710;
    a1 = 977;
    v0 = v0 - hi_21710 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_2170c + (u32)(unsigned long)ref_t32_data_c7d34;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21724;
L_21724:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (352));
L_21728:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    v0 = hi_2172c;
    v0 = v0 - hi_2172c + (u32)(unsigned long)ref_fix_point_div_32;
    callee = v0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2173c;
L_2173c:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    a2 = *(volatile u32 *)(unsigned long)(s8 + (168));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a0 = v0 >> (s7 & 31);
    v0 = hi_21754;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (180));
    a3 = s6;
    v0 = v0 - hi_21754 + (u32)(unsigned long)ref_func_zone_ct_weight;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    callee = v0; *(volatile u32 *)(unsigned long)(sp + (16)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21774;
L_21774:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (180));
L_21778:
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
L_2177c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (452));
L_21780:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (292));
    s1 = s1 + 4;
    v0 = *(volatile u32 *)(unsigned long)(v0 - hi_20fe0 + (u32)(unsigned long)ref_t32_data_dbf10);
    v0 = v0 >> (0x6 & 31);
    *(volatile u16 *)(unsigned long)(v1 + (0)) = v0;
    v0 = v1 + 2;
    *(volatile u32 *)(unsigned long)(s8 + (292)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (244));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (248));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (248)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (200));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (200)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (184));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (180));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0; goto L_21034;
L_217dc:
    v0 = v0 + 64;
    *(volatile u32 *)(unsigned long)(s8 + (256)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (140)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (296));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (296)) = v0; goto L_20ff4;
L_21800:
    a1 = 0;
L_21804:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (312));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = (u32)a1 < (u32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    if (branch) goto L_21938;
    goto L_21818;
L_21818:
    a0 = a1 << (0x2 & 31);
    a2 = 0;
    t2 = v0 + a0;
    a0 = a0 + 2;
    a0 = v0 + a0;
L_2182c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    branch = (v0 == a2); v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    if (branch) goto L_2192c;
    goto L_21838;
L_21838:
    a3 = 0;
    t0 = v0 + a2;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    t1 = v0 + a2;
L_21848:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (a3 == v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (116));
    if (branch) goto L_21924;
    goto L_21854;
L_21854:
    v1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t3 = *(volatile u16 *)(unsigned long)(t2 + (0));
    v1 = v0 + v1;
    v1 = v1 >> (s7 & 31);
    t4 = (u32)v1 < (u32)(t3);
    v0 = t3 - v1;
    v1 = v1 - t3;
    if (t4 == 0) v0 = v1;
    t3 = *(volatile u32 *)(unsigned long)(s8 + (116));
    v1 = *(volatile u32 *)(unsigned long)(t1 + (4096));
    t4 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = t3 + v1;
    v1 = v1 >> (s7 & 31);
    t3 = (u32)v1 < (u32)(t4);
    t5 = t4 - v1;
    v1 = v1 - t4;
    if (t3 != 0) v1 = t5;
    product = (s64)(s32)v1 * (s32)v1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    t3 = (u32)v0 < (u32)(818);
    branch = (t3 == 0); v1 = 0;
    if (branch) goto L_218fc;
    goto L_218b0;
L_218b0:
    t3 = (u32)v0 < (u32)(679);
    branch = (t3 == 0); v1 = 1;
    if (branch) goto L_218fc;
    goto L_218bc;
L_218bc:
    t3 = (u32)v0 < (u32)(615);
    branch = (t3 == 0); v1 = 2;
    if (branch) goto L_218fc;
    goto L_218c8;
L_218c8:
    t3 = (u32)v0 < (u32)(572);
    branch = (t3 == 0); v1 = 3;
    if (branch) goto L_218fc;
    goto L_218d4;
L_218d4:
    t3 = (u32)v0 < (u32)(540);
    branch = (t3 == 0); v1 = 4;
    if (branch) goto L_218fc;
    goto L_218e0;
L_218e0:
    t3 = (u32)v0 < (u32)(514);
    branch = (t3 == 0); v1 = 5;
    if (branch) goto L_218fc;
    goto L_218ec;
L_218ec:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (260));
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
L_218fc:
    v0 = v1 << (s7 & 31);
    v1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v1 = (u32)v1 < (u32)(v0);
    if (v1 != 0) { *(volatile u32 *)(unsigned long)(t0 + (0)) = v0; goto L_21910; }
    goto L_21910;
L_21910:
    a3 = a3 + 1;
    a3 = a3 & 0xffff;
    t0 = t0 + 4;
    t1 = t1 + 4; goto L_21848;
L_21924:
    a2 = a2 + 128; goto L_2182c;
L_2192c:
    a1 = a1 + 1;
    a1 = a1 & 0xffff; goto L_21804;
L_21938:
    a1 = 0;
    t3 = 256;
L_21940:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (312));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (1));
    v0 = (u32)a1 < (u32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (324));
    if (branch) goto L_21a78;
    goto L_21954;
L_21954:
    a0 = a1 << (0x2 & 31);
    a2 = 0;
    t2 = v0 + a0;
    a0 = a0 + 2;
    a0 = v0 + a0;
L_21968:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    branch = (v0 == a2); v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    if (branch) goto L_21a6c;
    goto L_21974;
L_21974:
    a3 = 0;
    t0 = v0 + a2;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    t1 = v0 + a2;
L_21984:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (a3 == v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (116));
    if (branch) goto L_21a64;
    goto L_21990;
L_21990:
    v1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t4 = *(volatile u16 *)(unsigned long)(t2 + (0));
    v1 = v0 + v1;
    v1 = v1 >> (s7 & 31);
    t5 = (u32)v1 < (u32)(t4);
    v0 = t4 - v1;
    v1 = v1 - t4;
    if (t5 == 0) v0 = v1;
    t4 = *(volatile u32 *)(unsigned long)(s8 + (116));
    v1 = *(volatile u32 *)(unsigned long)(t1 + (4096));
    t5 = *(volatile u16 *)(unsigned long)(a0 + (0));
    v1 = t4 + v1;
    v1 = v1 >> (s7 & 31);
    t4 = (u32)v1 < (u32)(t5);
    t6 = t5 - v1;
    v1 = v1 - t5;
    if (t4 != 0) v1 = t6;
    product = (s64)(s32)v1 * (s32)v1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    t4 = (u32)v0 < (u32)(818);
    branch = (t4 == 0); v1 = 0;
    if (branch) goto L_21a38;
    goto L_219ec;
L_219ec:
    t4 = (u32)v0 < (u32)(679);
    branch = (t4 == 0); v1 = 1;
    if (branch) goto L_21a38;
    goto L_219f8;
L_219f8:
    t4 = (u32)v0 < (u32)(615);
    branch = (t4 == 0); v1 = 2;
    if (branch) goto L_21a38;
    goto L_21a04;
L_21a04:
    t4 = (u32)v0 < (u32)(572);
    branch = (t4 == 0); v1 = 3;
    if (branch) goto L_21a38;
    goto L_21a10;
L_21a10:
    t4 = (u32)v0 < (u32)(540);
    branch = (t4 == 0); v1 = 4;
    if (branch) goto L_21a38;
    goto L_21a1c;
L_21a1c:
    t4 = (u32)v0 < (u32)(514);
    branch = (t4 == 0); v1 = 5;
    if (branch) goto L_21a38;
    goto L_21a28;
L_21a28:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (260));
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
L_21a38:
    v0 = t3 - v1;
    v1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v0 = v0 << (s7 & 31);
    v1 = (u32)v0 < (u32)(v1);
    if (v1 != 0) { *(volatile u32 *)(unsigned long)(t0 + (0)) = v0; goto L_21a50; }
    goto L_21a50;
L_21a50:
    a3 = a3 + 1;
    a3 = a3 & 0xffff;
    t0 = t0 + 4;
    t1 = t1 + 4; goto L_21984;
L_21a64:
    a2 = a2 + 128; goto L_21968;
L_21a6c:
    a1 = a1 + 1;
    a1 = a1 & 0xffff; goto L_21940;
L_21a78:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    a0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    v0 = s4 + 16;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (0)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    v1 = v0;
    t5 = a0 & 0x3;
    v0 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (16)))[i] = vx[0].b[i]; }
    a1 = -1;
L_21aa4:
    a0 = (s32)v0 < (s32)(t5);
    branch = (a0 == 0); v0 = v0 + 1;
    if (branch) goto L_21abc;
    goto L_21ab0;
L_21ab0:
    *(volatile u32 *)(unsigned long)(v1 + (0)) = a1;
    v1 = v1 + 4; goto L_21aa4;
L_21abc:
    v0 = -s6;
    v1 = -1;
    v0 = v1 >> (v0 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (124)) = v0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[4] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (368));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = v0 + -1;
    v0 = v0 & 0xffff;
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = s6; vx[3] = tmp; }
    if (branch) goto L_21b04;
    goto L_21aec;
L_21aec:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (328));
    s1 = 0;
    a0 = 0;
    a2 = v0 + -4; goto L_21b70;
L_21b04:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (280));
    v0 = 1;
    if (v1 != v0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (144)); goto L_21d28; }
    goto L_21b14;
L_21b14:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (268)); goto L_21d38;
L_21b1c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s4 + (16)))[i]; }
    a0 = a0 + 1;
    a0 = a0 & 0xffff;
    a1 = a1 + 128;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] & vx[2].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] < vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[2].w[i]) | (vx[1].w[i] & vx[2].w[i]); vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (0)))[i] = vx[0].b[i]; }
    a3 = *(volatile u32 *)(unsigned long)(s4 + (0));
    v0 = *(volatile u32 *)(unsigned long)(s4 + (4));
    v1 = (u32)a3 < (u32)(v0);
    if (v1 == 0) v0 = a3;
    a3 = *(volatile u32 *)(unsigned long)(s4 + (8));
    v1 = (u32)v0 < (u32)(a3);
    if (v1 != 0) v0 = a3;
    a3 = *(volatile u32 *)(unsigned long)(s4 + (12));
    v1 = (u32)v0 < (u32)(a3);
    if (v1 != 0) v0 = a3;
    v1 = (u32)s1 < (u32)(v0);
    if (v1 != 0) s1 = v0;
L_21b70:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (120));
    branch = (a0 == v0); v1 = a1;
    if (branch) goto L_21bac;
    goto L_21b7c;
L_21b7c:
    a3 = 0;
L_21b80:
    v0 = (s32)a2 < (s32)(a3);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s4 + (0)))[i]; }
    branch = (v0 != 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] < vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    if (branch) goto L_21b1c;
    goto L_21b94;
L_21b94:
    v1 = v1 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[2].w[i]) | (vx[1].w[i] & vx[2].w[i]); vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (0)))[i] = vx[0].b[i]; }
    a3 = a3 + 4; goto L_21b80;
L_21bac:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = s1; vx[0] = tmp; }
    v0 = (u32)s1 < (u32)(2);
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (0)))[i] = vx[0].b[i]; }
    branch = (v0 != 0); v0 = hi_21bbc;
    if (branch) goto L_21b04;
    goto L_21bc0;
L_21bc0:
    t2 = v0 - hi_21bbc + (u32)(unsigned long)ref_t32_data_db690;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (112));
    t0 = 0;
    t4 = v0 + -4;
    t6 = t2;
    t7 = hi_21bd8;
L_21bdc:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (120));
    v0 = t0 & 0xffff;
    v0 = (u32)v0 < (u32)(v1);
    branch = (v0 == 0); t3 = t0 << (0x7 & 31);
    if (branch) goto L_21b04;
    goto L_21bf0;
L_21bf0:
    v1 = 0;
    a2 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[5] = tmp; }
L_21bfc:
    a1 = t1 + v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    a1 = *(volatile u32 *)(unsigned long)(s8 + (328));
    v0 = v1 + t3;
    a0 = (s32)t4 < (s32)(a2);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a1 + (v0)))[i]; }
    a3 = t2 + v1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[7] = tmp; }
    v1 = v1 + 16;
    branch = (a0 != 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] >> (vx[3].w[i] & 31); vx[6] = tmp; }
    if (branch) goto L_21c58;
    goto L_21c28;
L_21c28:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[6].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] & vx[5].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[5].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] << (vx[3].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[7].w[i] * (u32)vx[1].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[0].w[i] * (u32)vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] * (u32)vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[0].w[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[0].b[i]; }
    a2 = a2 + 4; goto L_21bfc;
L_21c58:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[6].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] & vx[4].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[4].w[i]; vx[0] = tmp; }
    v1 = t1;
    s2 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] << (vx[3].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[7].w[i] * (u32)vx[1].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[0].w[i] * (u32)vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] * (u32)vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[0].w[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[0].b[i]; }
    a3 = t6;
L_21c8c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (s2 == v0); v0 = t7 - hi_21bd8 + (u32)(unsigned long)ref_fix_point_div_32;
    if (branch) goto L_21d18;
    goto L_21c98;
L_21c98:
    a1 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a2 = s1;
    a0 = s6;
    *(volatile u32 *)(unsigned long)(s8 + (292)) = t5;
    *(volatile u32 *)(unsigned long)(s8 + (256)) = t6;
    *(volatile u32 *)(unsigned long)(s8 + (248)) = t4;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (240)) = v1;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (180)) = t1;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (200)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (184)))[i] = vx[4].b[i]; }
    *(volatile u32 *)(unsigned long)(s8 + (168)) = a3;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (140)) = t7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_21cd4;
L_21cd4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (240));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (168));
    s2 = s2 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    s2 = s2 & 0xffff;
    a3 = a3 + 4;
    v1 = v1 + 4;
    t5 = *(volatile u32 *)(unsigned long)(s8 + (292));
    t6 = *(volatile u32 *)(unsigned long)(s8 + (256));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (248));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (244));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (180));
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (200)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (184)))[i]; }
    t7 = *(volatile u32 *)(unsigned long)(s8 + (140)); goto L_21c8c;
L_21d18:
    t0 = t0 + 1;
    t1 = t1 + 128; goto L_21bdc;
L_21d24:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (144));
L_21d28:
    a1 = 0;
    v1 = v0 + 480;
    a0 = v0 + 720; goto L_22924;
L_21d38:
    a2 = 14;
    a3 = 14;
    v1 = v0 + 48;
    a1 = v0 + 96;
L_21d48:
    t1 = 0;
    t4 = 0;
L_21d50:
    t3 = t1;
    t2 = 0;
L_21d58:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = t3 << (0x1 & 31);
    v0 = a0 + v0;
    t0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    branch = (t0 == 0); t3 = t3 + 1;
    if (branch) goto L_21d90;
    goto L_21d70;
L_21d70:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (48));
    a0 = (u32)a0 < (u32)(t0);
    branch = (a0 == 0); ;
    if (branch) goto L_21d90;
    goto L_21d80;
L_21d80:
    *(volatile u32 *)(unsigned long)(v1 + (-48)) = t2;
    *(volatile u32 *)(unsigned long)(v1 + (0)) = t4;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(v1 + (48)) = v0;
L_21d90:
    t2 = t2 + 1;
    branch = (t2 != a2); t3 = t3 & 0xffff;
    if (branch) goto L_21d58;
    goto L_21d9c;
L_21d9c:
    t1 = t1 + 14;
    t4 = t4 + 1;
    branch = (t4 != t2); t1 = t1 & 0xffff;
    if (branch) goto L_21d50;
    goto L_21dac;
L_21dac:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-48));
    v1 = v1 + 4;
    t0 = v0 * a3;
    v0 = t0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = v0 & 0xffff;
    v0 = v0 << (0x1 & 31);
    v0 = a0 + v0;
    branch = (a1 != v1); *(volatile u16 *)(unsigned long)(v0 + (0)) = 0;
    if (branch) goto L_21d48;
    goto L_21dd8;
L_21dd8:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (132));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (268));
    v0 = a1;
    a2 = a1 + 240;
L_21de8:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = v0 + 20;
    v1 = v1 + 4;
    a0 = a0 << (0x2 & 31);
    a0 = s3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (-20)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (44));
    a0 = a0 << (0x2 & 31);
    a0 = s0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (220)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-4));
    a0 = a0 << (0x2 & 31);
    a0 = s3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (-16)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (44));
    a0 = a0 + 1;
    a0 = a0 << (0x2 & 31);
    a0 = s0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (224)) = a0;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (-4));
    a3 = a3 << (0x2 & 31);
    a3 = s3 + a3;
    a0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a3 = *(volatile u32 *)(unsigned long)(a3 + (4));
    a0 = a0 + 1;
    a0 = a0 + a3;
    a0 = a0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(v0 + (-12)) = a0;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (44));
    a3 = a3 << (0x2 & 31);
    a3 = s0 + a3;
    a0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    a3 = *(volatile u32 *)(unsigned long)(a3 + (4));
    a0 = a0 + 1;
    a0 = a0 + a3;
    a0 = a0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(v0 + (228)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-4));
    a0 = a0 + 1;
    a0 = a0 << (0x2 & 31);
    a0 = s3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (-8)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (44));
    a0 = a0 << (0x2 & 31);
    a0 = s0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (232)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-4));
    a0 = a0 + 1;
    a0 = a0 << (0x2 & 31);
    a0 = s3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (-4)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (44));
    a0 = a0 + 1;
    a0 = a0 << (0x2 & 31);
    a0 = s0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (v0 != a2); *(volatile u32 *)(unsigned long)(v0 + (236)) = a0;
    if (branch) goto L_21de8;
    goto L_21eec;
L_21eec:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    a3 = 1;
    t0 = 60;
    t1 = 61;
L_21efc:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(a0 + (240)); goto L_21f20; }
    goto L_21f08;
L_21f08:
    a3 = a3 + 1;
L_21f0c:
    a3 = a3 & 0xffff;
    branch = (a3 != t1); a0 = a0 + 4;
    if (branch) goto L_21efc;
    goto L_21f18;
L_21f18:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 1; vx[5] = tmp; } goto L_21f6c;
L_21f20:
    if (v0 == 0) { a3 = a3 + 1; goto L_21f0c; }
    goto L_21f28;
L_21f28:
    v0 = a3;
L_21f2c:
    branch = (v0 == t0); t2 = *(volatile u32 *)(unsigned long)(s8 + (132));
    if (branch) goto L_21f08;
    goto L_21f34;
L_21f34:
    v1 = v0 << (0x2 & 31);
    t3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = t2 + v1;
    t2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    branch = (t3 != t2); v0 = v0 + 1;
    if (branch) goto L_21f64;
    goto L_21f4c;
L_21f4c:
    t3 = *(volatile u32 *)(unsigned long)(a0 + (240));
    t2 = *(volatile u32 *)(unsigned long)(v1 + (240));
    branch = (t3 != t2); ;
    if (branch) goto L_21f64;
    goto L_21f5c;
L_21f5c:
    *(volatile u32 *)(unsigned long)(v1 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v1 + (240)) = 0;
L_21f64:
    v0 = v0 & 0xffff; goto L_21f2c;
L_21f6c:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = s7; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[6] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (408));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] - (u32)vx[5].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (16)))[i] = vx[6].b[i]; }
    branch = (t5 == 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] << (vx[3].w[i] & 31); vx[3] = tmp; }
    if (branch) goto L_21fac;
    goto L_21f8c;
L_21f8c:
    v0 = -1;
    v1 = 1;
    branch = (t5 == v1); *(volatile u32 *)(unsigned long)(s4 + (16)) = v0;
    if (branch) goto L_21fac;
    goto L_21f9c;
L_21f9c:
    v1 = 3;
    branch = (t5 != v1); *(volatile u32 *)(unsigned long)(s4 + (20)) = v0;
    if (branch) goto L_21fac;
    goto L_21fa8;
L_21fa8:
    *(volatile u32 *)(unsigned long)(s4 + (24)) = v0;
L_21fac:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[9] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[9].w[i] | vx[9].w[i]; vx[11] = tmp; }
    t1 = v0 + -4;
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
L_21fc0:
    if (v0 == 0) { a1 = a1 + 4; goto L_2217c; }
    goto L_21fc8;
L_21fc8:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (240));
    if (v0 == 0) { a1 = a1 + 4; goto L_2217c; }
    goto L_21fd4;
L_21fd4:
    a3 = 0;
L_21fd8:
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    v1 = *(volatile u32 *)(unsigned long)(s8 + (108));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[14] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(a1 + (240));
    a3 = a3 + 1;
    a3 = a3 & 0xffff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[7] = tmp; }
    v0 = 0;
L_22004:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (120));
    branch = (v0 == a0); t2 = v1;
    if (branch) goto L_220ac;
    goto L_22010;
L_22010:
    t0 = v1 + 4096;
    t3 = 0;
L_22018:
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(t0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    a0 = (s32)t1 < (s32)(t3);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] + (u32)vx[8].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] + (u32)vx[12].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (vx[4].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[13].w[i] >> (vx[4].w[i] & 31); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] > vx[2].w[i] ? vx[15].w[i] - vx[2].w[i] : vx[2].w[i] - vx[15].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[14].w[i] > vx[13].w[i] ? vx[14].w[i] - vx[13].w[i] : vx[13].w[i] - vx[14].w[i]; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[13].w[i] * (u32)vx[13].w[i]); vx[2] = tmp; }
    branch = (a0 != 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] <= vx[10].w[i]) ? ~0U : 0; vx[2] = tmp; }
    if (branch) goto L_22078;
    goto L_2204c;
L_2204c:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[2].w[i]) | (vx[12].w[i] & vx[2].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[2].w[i]) | (vx[8].w[i] & vx[2].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] & vx[5].w[i]; vx[2] = tmp; }
    t2 = t2 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[12].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[2].w[i]; vx[7] = tmp; }
    t0 = t0 + 16;
    t3 = t3 + 4; goto L_22018;
L_22078:
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(s4 + (16)))[i]; }
    v0 = v0 + 1;
    v0 = v0 & 0xffff;
    v1 = v1 + 128;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] & vx[13].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[2].w[i]) | (vx[12].w[i] & vx[2].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[2].w[i]) | (vx[8].w[i] & vx[2].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] & vx[5].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[12].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[2].w[i]; vx[7] = tmp; } goto L_22004;
L_220ac:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 2; i++) tmp.d[i] = vx[0].d[1]; vx[2] = tmp; }
    vx[2].d[1] = vx[1].d[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[2].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[2].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[1]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[2].w[i]; vx[0] = tmp; }
    v0 = (u32)vx[0].w[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[3]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[0].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 2; i++) tmp.d[i] = vx[7].d[1]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[0].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[1]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[0].w[i]; vx[7] = tmp; }
    a0 = (u32)vx[7].w[0];
    branch = (a0 == 0); v1 = (u32)vx[1].w[2];
    if (branch) goto L_22178;
    goto L_220ec;
L_220ec:
    t0 = a0 >> (0x1 & 31);
    v0 = v0 + t0;
    if (a0) { lo = v0 / a0; hi = v0 % a0; } else { lo = ~0U; hi = v0; }
    v1 = v1 + t0;
    t3 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = lo;
    v0 = v0 >> (s7 & 31);
    t2 = (u32)t3 < (u32)(v0);
    if (a0) { lo = v1 / a0; hi = v1 % a0; } else { lo = ~0U; hi = v1; }
    t0 = v0 - t3;
    t3 = t3 - v0;
    if (t2 == 0) t0 = t3;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (340));
    t0 = (u32)t2 < (u32)(t0);
    v1 = lo;
    branch = (t0 != 0); v1 = v1 >> (s7 & 31);
    if (branch) goto L_22154;
    goto L_22130;
L_22130:
    t3 = *(volatile u32 *)(unsigned long)(a1 + (240));
    t2 = (u32)t3 < (u32)(v1);
    t0 = v1 - t3;
    t3 = t3 - v1;
    if (t2 == 0) t0 = t3;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (340));
    t0 = (u32)t2 < (u32)(t0);
    if (t0 == 0) { *(volatile u32 *)(unsigned long)(a1 + (480)) = a0; goto L_22178; }
    goto L_22154;
L_22154:
    t0 = *(volatile u32 *)(unsigned long)(s8 + (416));
    t0 = (u32)t0 < (u32)(a3);
    if (t0 == 0) { *(volatile u32 *)(unsigned long)(a1 + (0)) = v0; goto L_2216c; }
    goto L_22164;
L_22164:
    *(volatile u32 *)(unsigned long)(a1 + (480)) = a0; goto L_22178;
L_2216c:
    *(volatile u32 *)(unsigned long)(a1 + (240)) = v1;
    *(volatile u32 *)(unsigned long)(a1 + (480)) = a0; goto L_21fd8;
L_22178:
    a1 = a1 + 4;
L_2217c:
    if (a1 != a2) { v0 = *(volatile u32 *)(unsigned long)(a1 + (0)); goto L_21fc0; }
    goto L_22184;
L_22184:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (412));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    t0 = hi_2218c;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[12] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    t1 = hi_22198;
    t2 = hi_2219c;
    v1 = v0 + 480;
    t3 = hi_221a4;
    a1 = v0 + 720;
    t6 = a0 + 720;
    v0 = v1;
    t0 = t0 - hi_2218c + (u32)(unsigned long)ref_t32_data_db5a0;
    t1 = t1 - hi_22198 + (u32)(unsigned long)ref_t32_data_db4b0;
    t2 = t2 - hi_2219c + (u32)(unsigned long)ref_t32_data_db3c0;
    t3 = t3 - hi_221a4 + (u32)(unsigned long)ref_t32_data_db2d0;
    t7 = 60;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[11] = tmp; }
    t5 = s4 + 32;
L_221d0:
    t8 = 16;
    t9 = -1;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (132));
L_221dc:
    a0 = a0 + 480;
    a2 = a0;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
L_221e8:
    if (a3 == 0) { a2 = a2 + 4; goto L_2221c; }
    goto L_221f0;
L_221f0:
    t4 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = (u32)t4 < (u32)(a3);
    if (a3 == 0) { a2 = a2 + 4; goto L_2221c; }
    goto L_22200;
L_22200:
    a3 = *(volatile u32 *)(unsigned long)(a2 + (-480));
    *(volatile u32 *)(unsigned long)(v0 + (-480)) = a3;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (-240));
    *(volatile u32 *)(unsigned long)(v0 + (-240)) = a3;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a3;
    a2 = a2 + 4;
L_2221c:
    if (t6 != a2) { a3 = *(volatile u32 *)(unsigned long)(a2 + (0)); goto L_221e8; }
    goto L_22224;
L_22224:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (a2 == 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[8] = tmp; }
    if (branch) goto L_22468;
    goto L_22230;
L_22230:
    t4 = 0;
    a2 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[8].w[i] | vx[8].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[8].w[i] | vx[8].w[i]; vx[10] = tmp; }
L_22240:
    ra = *(volatile u32 *)(unsigned long)(a0 + (0));
    if (ra == 0) { t4 = t4 + 1; goto L_22280; }
    goto L_2224c;
L_2224c:
    s1 = *(volatile u32 *)(unsigned long)(a0 + (-480));
    a3 = a2 << (0x2 & 31);
    s0 = a3 + t0;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = s1;
    s1 = *(volatile u32 *)(unsigned long)(a0 + (-240));
    s0 = a3 + t1;
    a2 = a2 + 1;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = s1;
    s0 = a3 + t2;
    a3 = a3 + t3;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = ra;
    *(volatile u32 *)(unsigned long)(a3 + (0)) = t4;
    t4 = t4 + 1;
L_22280:
    branch = (t4 != t7); a0 = a0 + 4;
    if (branch) goto L_22240;
    goto L_22288;
L_22288:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-480));
    a3 = 0;
    s0 = a2 + -4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[9] = tmp; }
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-240));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[0] = tmp; }
    a0 = 0;
L_222a4:
    t4 = (s32)s0 < (s32)(a0);
    branch = (t4 != 0); t4 = 0;
    if (branch) goto L_22334;
    goto L_222b0;
L_222b0:
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(t1 + (a3)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(t0 + (a3)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] > vx[13].w[i] ? vx[0].w[i] - vx[13].w[i] : vx[13].w[i] - vx[0].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[9].w[i] > vx[14].w[i] ? vx[9].w[i] - vx[14].w[i] : vx[14].w[i] - vx[9].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] + ((u32)vx[1].w[i] * (u32)vx[1].w[i]); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t2 + (a3)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] <= vx[12].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[2].w[i]) | (vx[1].w[i] & vx[2].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[2].w[i]) | (vx[14].w[i] & vx[2].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[2].w[i]) | (vx[13].w[i] & vx[2].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] & vx[5].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] + (u32)vx[1].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[8].w[i] + ((u32)vx[1].w[i] * (u32)vx[14].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[i] + ((u32)vx[1].w[i] * (u32)vx[13].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[2].b[i]; }
    ra = t5 + t4;
L_222f4:
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    if (ra == 0) { t4 = t4 + 4; goto L_22320; }
    goto L_22300;
L_22300:
    ra = a3 + t4;
    ra = t3 + ra;
    ra = *(volatile u32 *)(unsigned long)(ra + (0));
    s1 = *(volatile u32 *)(unsigned long)(s8 + (132));
    ra = ra << (0x2 & 31);
    ra = s1 + ra;
    *(volatile u32 *)(unsigned long)(ra + (480)) = 0;
    t4 = t4 + 4;
L_22320:
    branch = (t4 != t8); ra = t5 + t4;
    if (branch) goto L_222f4;
    goto L_22328;
L_22328:
    a0 = a0 + 4;
    a3 = a3 + 16; goto L_222a4;
L_22334:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[1] = tmp; }
    t4 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a3 = 0;
    s0 = a2 & 0x3;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (16)))[i] = vx[1].b[i]; }
L_22348:
    ra = (s32)a3 < (s32)(s0);
    branch = (ra == 0); a3 = a3 + 1;
    if (branch) goto L_22360;
    goto L_22354;
L_22354:
    *(volatile u32 *)(unsigned long)(t4 + (0)) = t9;
    t4 = t4 + 4; goto L_22348;
L_22360:
    ra = a0 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t1 + (ra)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(t0 + (ra)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t2 + (ra)))[i]; }
    t4 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] > vx[1].w[i] ? vx[0].w[i] - vx[1].w[i] : vx[1].w[i] - vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[9].w[i] > vx[13].w[i] ? vx[9].w[i] - vx[13].w[i] : vx[13].w[i] - vx[9].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] * (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] + ((u32)vx[9].w[i] * (u32)vx[9].w[i]); vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(s4 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] <= vx[12].w[i]) ? ~0U : 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[9].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[0].w[i]) | (vx[2].w[i] & vx[0].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[0].w[i]) | (vx[1].w[i] & vx[0].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[0].w[i]) | (vx[13].w[i] & vx[0].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[8].w[i] | vx[8].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[5].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[i] + ((u32)vx[2].w[i] * (u32)vx[9].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] + ((u32)vx[2].w[i] * (u32)vx[13].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] + (u32)vx[2].w[i]; vx[2] = tmp; }
L_223b4:
    a3 = (s32)a0 < (s32)(a2);
    branch = (a3 == 0); a3 = t5 + t4;
    if (branch) goto L_223f0;
    goto L_223c0;
L_223c0:
    a3 = *(volatile u32 *)(unsigned long)(a3 + (0));
    branch = (a3 == 0); a0 = a0 + 1;
    if (branch) goto L_223e8;
    goto L_223cc;
L_223cc:
    a3 = ra + t4;
    a3 = t3 + a3;
    a3 = *(volatile u32 *)(unsigned long)(a3 + (0));
    s0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    a3 = a3 << (0x2 & 31);
    a3 = s0 + a3;
    *(volatile u32 *)(unsigned long)(a3 + (480)) = 0;
L_223e8:
    t4 = t4 + 4; goto L_223b4;
L_223f0:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 2; i++) tmp.d[i] = vx[1].d[1]; vx[8] = tmp; }
    vx[8].d[1] = vx[7].d[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[8].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[8].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[1]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[7].w[i]; vx[0] = tmp; }
    a0 = (u32)vx[0].w[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[3]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[0].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 2; i++) tmp.d[i] = vx[2].d[1]; vx[0] = tmp; }
    a3 = (u32)vx[1].w[2];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[1]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[1].w[i]; vx[0] = tmp; }
    a2 = (u32)vx[0].w[0];
    if (a2 == 0) { v0 = v0 + 4; goto L_22460; }
    goto L_22434;
L_22434:
    t4 = a2 >> (0x1 & 31);
    a0 = a0 + t4;
    if (a2) { lo = a0 / a2; hi = a0 % a2; } else { lo = ~0U; hi = a0; }
    a3 = a3 + t4;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    a0 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (-480)) = a0;
    if (a2) { lo = a3 / a2; hi = a3 % a2; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (-240)) = a3;
    v0 = v0 + 4;
L_22460:
    branch = (a1 != v0); a0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    if (branch) goto L_221dc;
    goto L_22468;
L_22468:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (60));
    a2 = hi_2246c;
    a3 = hi_22470;
    t0 = hi_22474;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[9] = tmp; }
    a2 = a2 - hi_2246c + (u32)(unsigned long)ref_t32_data_db250;
    v0 = v1;
    a3 = a3 - hi_22470 + (u32)(unsigned long)ref_t32_data_db1d0;
    t0 = t0 - hi_22474 + (u32)(unsigned long)ref_t32_data_db150;
    t6 = -1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (-480));
L_22494:
    if (a0 != 0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (-240)); goto L_224b8; }
    goto L_2249c;
L_2249c:
    v0 = v0 + 4;
L_224a0:
    if (v0 != a1) { a0 = *(volatile u32 *)(unsigned long)(v0 + (-480)); goto L_22494; }
    goto L_224a8;
L_224a8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    t0 = v0 + 960;
    v0 = a1; goto L_22688;
L_224b8:
    if (a0 == 0) { v0 = v0 + 4; goto L_224a0; }
    goto L_224c0;
L_224c0:
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (240)) = 0;
    t1 = 0;
L_224cc:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    branch = (a0 == t1); a0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    if (branch) goto L_2249c;
    goto L_224d8;
L_224d8:
    t2 = 0;
    t4 = a0 + t1;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    t5 = a0 + t1;
    a0 = 0;
L_224ec:
    t3 = *(volatile u32 *)(unsigned long)(s8 + (104));
    if (t2 == t3) { t2 = *(volatile u32 *)(unsigned long)(v0 + (-480)); goto L_22540; }
    goto L_224f8;
L_224f8:
    t3 = *(volatile u32 *)(unsigned long)(t4 + (0));
    branch = (t3 == 0); t2 = t2 + 1;
    if (branch) goto L_22530;
    goto L_22504;
L_22504:
    t8 = *(volatile u32 *)(unsigned long)(t5 + (0));
    t3 = a0 << (0x2 & 31);
    t7 = t3 + a2;
    *(volatile u32 *)(unsigned long)(t7 + (0)) = t8;
    t8 = *(volatile u32 *)(unsigned long)(t5 + (4096));
    t7 = t3 + a3;
    t3 = t3 + t0;
    *(volatile u32 *)(unsigned long)(t7 + (0)) = t8;
    t7 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(t3 + (0)) = t7;
L_22530:
    t2 = t2 & 0xffff;
    t4 = t4 + 4;
    t5 = t5 + 4; goto L_224ec;
L_2253c:
    t5 = t5 + 4;
L_22540:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[7] = tmp; }
    t3 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t2; vx[10] = tmp; }
    t2 = *(volatile u32 *)(unsigned long)(v0 + (-240));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[i] | vx[7].w[i]; vx[8] = tmp; }
    t5 = a0 + -4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = t2; vx[1] = tmp; }
    t2 = 0;
L_22560:
    t4 = (s32)t5 < (s32)(t2);
    branch = (t4 != 0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    if (branch) goto L_225bc;
    goto L_2256c;
L_2256c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a3 + (t3)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (t3)))[i]; }
    t2 = t2 + 4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[3].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[3].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (vx[4].w[i] & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (vx[4].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] > vx[0].w[i] ? vx[1].w[i] - vx[0].w[i] : vx[0].w[i] - vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[10].w[i] > vx[2].w[i] ? vx[10].w[i] - vx[2].w[i] : vx[2].w[i] - vx[10].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] * (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] + ((u32)vx[2].w[i] * (u32)vx[2].w[i]); vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t0 + (t3)))[i]; }
    t3 = t3 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] <= vx[9].w[i]) ? ~0U : 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[0].w[i]) | (vx[2].w[i] & vx[0].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[5].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] + (u32)vx[2].w[i]; vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[0].w[i]; vx[7] = tmp; } goto L_22560;
L_225bc:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (128));
    t3 = 0;
    t7 = a0 & 0x3;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (16)))[i] = vx[0].b[i]; }
L_225cc:
    t5 = (s32)t3 < (s32)(t7);
    branch = (t5 == 0); t3 = t3 + 1;
    if (branch) goto L_225e4;
    goto L_225d8;
L_225d8:
    *(volatile u32 *)(unsigned long)(t4 + (0)) = t6;
    t4 = t4 + 4; goto L_225cc;
L_225e4:
    a0 = (s32)t2 < (s32)(a0);
    if (a0 == 0) { { union t32_vec tmp; unsigned int i; for (i = 0; i < 2; i++) tmp.d[i] = vx[7].d[1]; vx[1] = tmp; } goto L_22644; }
    goto L_225f0;
L_225f0:
    t2 = t2 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a3 + (t2)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (t2)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[3].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[3].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (vx[4].w[i] & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (vx[4].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] > vx[0].w[i] ? vx[1].w[i] - vx[0].w[i] : vx[0].w[i] - vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[10].w[i] > vx[2].w[i] ? vx[10].w[i] - vx[2].w[i] : vx[2].w[i] - vx[10].w[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s4 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] * (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] + ((u32)vx[2].w[i] * (u32)vx[2].w[i]); vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t0 + (t2)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] <= vx[9].w[i]) ? ~0U : 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[0].w[i]) | (vx[2].w[i] & vx[0].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] & vx[5].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] + (u32)vx[2].w[i]; vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s4 + (32)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[0].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 2; i++) tmp.d[i] = vx[7].d[1]; vx[1] = tmp; }
L_22644:
    t2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t1 = t1 + 128;
    vx[1].d[1] = vx[8].d[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] + (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[1]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[2].w[i]; vx[0] = tmp; }
    a0 = (s32)vx[0].w[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[3]; vx[0] = tmp; }
    a0 = t2 + a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[0].w[i]; vx[1] = tmp; }
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    t2 = *(volatile u32 *)(unsigned long)(v0 + (240));
    a0 = (s32)vx[1].w[2];
    a0 = t2 + a0;
    *(volatile u32 *)(unsigned long)(v0 + (240)) = a0; goto L_224cc;
L_22688:
    a3 = *(volatile u32 *)(unsigned long)(v0 + (-240));
L_2268c:
    if (a3 == 0) { v0 = v0 + 4; goto L_226b0; }
    goto L_22694;
L_22694:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a3 >> (0x1 & 31);
    a0 = a2 + a0;
    if (a3) { lo = a0 / a3; hi = a0 % a3; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    v0 = v0 + 4;
L_226b0:
    if (t0 != v0) { a3 = *(volatile u32 *)(unsigned long)(v0 + (-240)); goto L_2268c; }
    goto L_226b8;
L_226b8:
    *(volatile u32 *)(unsigned long)(s8 + (64)) = 0;
    a2 = a1;
    a0 = 0;
    v0 = 0;
    t2 = 1;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
L_226d0:
    branch = (a3 == 0); a2 = a2 + 4;
    if (branch) goto L_226e4;
    goto L_226d8;
L_226d8:
    t1 = (u32)v0 < (u32)(a3);
    if (t1 != 0) v0 = a3;
    if (t1 != 0) a0 = t2;
L_226e4:
    if (a2 != t0) { a3 = *(volatile u32 *)(unsigned long)(a2 + (0)); goto L_226d0; }
    goto L_226ec;
L_226ec:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (64));
    t0 = hi_226f0;
    t1 = 256;
    if (a0 == 0) v0 = a2;
    a2 = *(volatile u32 *)(unsigned long)(s8 + (344));
    *(volatile u32 *)(unsigned long)(s8 + (64)) = v0;
    t2 = v0 >> (0x1 & 31);
    t0 = t0 - hi_226f0 + (u32)(unsigned long)ref_t32_data_db060;
    a0 = v1;
    t1 = t1 - a2;
L_22714:
    a2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(t0 + (0)) = a2;
    if (branch) goto L_22740;
    goto L_22720;
L_22720:
    branch = (a2 == 0); t3 = *(volatile u32 *)(unsigned long)(s8 + (344));
    if (branch) goto L_22744;
    goto L_22728;
L_22728:
    a3 = *(volatile u32 *)(unsigned long)(a0 + (240));
    t3 = a2 * a3;
    a3 = t3 + t2;
    if (v0) { lo = a3 / v0; hi = a3 % v0; } else { lo = ~0U; hi = a3; }
    a3 = lo;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = a3;
L_22740:
    t3 = *(volatile u32 *)(unsigned long)(s8 + (344));
L_22744:
    a3 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 + 4;
    product = (s64)(s32)t3 * (s32)a2; lo = product; hi = product >> 32;
    t0 = t0 + 4;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t1 * (s32)a3); lo = product; hi = product >> 32;
    a2 = lo;
    a2 = a2 >> (0x8 & 31);
    branch = (a1 != a0); *(volatile u32 *)(unsigned long)(a0 + (-4)) = a2;
    if (branch) goto L_22714;
    goto L_22768;
L_22768:
    *(volatile u32 *)(unsigned long)(s8 + (64)) = 0;
    a0 = 0;
    v0 = 0;
    t0 = 1;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
L_2277c:
    branch = (a2 == 0); v1 = v1 + 4;
    if (branch) goto L_22790;
    goto L_22784;
L_22784:
    a3 = (u32)v0 < (u32)(a2);
    if (a3 != 0) v0 = a2;
    if (a3 != 0) a0 = t0;
L_22790:
    if (v1 != a1) { a2 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_2277c; }
    goto L_22798;
L_22798:
    if (a0 != 0) { *(volatile u32 *)(unsigned long)(s8 + (64)) = v0; goto L_227a0; }
    goto L_227a0;
L_227a0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (64));
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (144)); goto L_21d28; }
    goto L_227ac;
L_227ac:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    t8 = *(volatile u32 *)(unsigned long)(s8 + (108));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (112));
    v0 = v0 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (92)) = s7;
    *(volatile u32 *)(unsigned long)(s8 + (84)) = v1;
    *(volatile u32 *)(unsigned long)(s8 + (80)) = v0;
    t1 = 0;
    t9 = 17;
L_227d0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (120));
    branch = (t1 == v0); t7 = t8;
    if (branch) goto L_21d24;
    goto L_227dc;
L_227dc:
    t5 = t4;
    t6 = t4;
    t2 = 0;
L_227e8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (t2 == v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (116));
    if (branch) goto L_22910;
    goto L_227f4;
L_227f4:
    a1 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a2 = *(volatile u32 *)(unsigned long)(t7 + (4096));
    ra = *(volatile u32 *)(unsigned long)(s8 + (60));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (144));
    a1 = v0 + a1;
    a2 = v0 + a2;
    a1 = a1 >> (s7 & 31);
    a2 = a2 >> (s7 & 31);
    a0 = 1;
    v0 = 0;
L_2281c:
    a3 = *(volatile u32 *)(unsigned long)(t3 + (0));
    if (a3 == 0) { a0 = a0 + 1; goto L_22898; }
    goto L_22828;
L_22828:
    t0 = *(volatile u32 *)(unsigned long)(t3 + (240));
    if (t0 == 0) { a0 = a0 + 1; goto L_22898; }
    goto L_22834;
L_22834:
    s0 = a3 - a1;
    s1 = (u32)a1 < (u32)(a3);
    v1 = a1 - a3;
    if (s1 != 0) v1 = s0;
    a3 = (u32)a2 < (u32)(t0);
    s0 = t0 - a2;
    t0 = a2 - t0;
    if (a3 != 0) t0 = s0;
    product = (s64)(s32)t0 * (s32)t0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)v1); lo = product; hi = product >> 32;
    v1 = lo;
    v1 = (u32)ra < (u32)(v1);
    if (v1 != 0) { a0 = a0 + 1; goto L_22898; }
    goto L_2286c;
L_2286c:
    if (v0 == 0) { v0 = a0; goto L_22894; }
    goto L_22874;
L_22874:
    a3 = *(volatile u32 *)(unsigned long)(s8 + (144));
    v1 = v0 + -1;
    v1 = v1 << (0x2 & 31);
    v1 = a3 + v1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (480));
    a3 = *(volatile u32 *)(unsigned long)(t3 + (480));
    v1 = (u32)v1 < (u32)(a3);
    if (v1 != 0) v0 = a0;
L_22894:
    a0 = a0 + 1;
L_22898:
    a0 = a0 & 0xffff;
    branch = (a0 != t9); t3 = t3 + 4;
    if (branch) goto L_2281c;
    goto L_228a4;
L_228a4:
    branch = (v0 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (64));
    if (branch) goto L_228e0;
    goto L_228ac;
L_228ac:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    v0 = v0 + -1;
    v0 = v0 << (0x2 & 31);
    v0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (480));
    a1 = *(volatile u32 *)(unsigned long)(t6 + (0));
    v0 = v1 >> (0x1 & 31);
    a2 = a0 * a1;
    v0 = a2 + v0;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = v1; goto L_228f8;
L_228e0:
    a0 = *(volatile u32 *)(unsigned long)(t5 + (0));
    v0 = v1 >> (0x1 & 31);
    v0 = v0 + a0;
    if (v1) { lo = v0 / v1; hi = v0 % v1; } else { lo = ~0U; hi = v0; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(t5 + (0)) = v1;
L_228f8:
    t2 = t2 + 1;
    t2 = t2 & 0xffff;
    t6 = t6 + 4;
    t5 = t5 + 4;
    t7 = t7 + 4; goto L_227e8;
L_22910:
    t1 = t1 + 1;
    t1 = t1 & 0xffff;
    t4 = t4 + 128;
    t8 = t8 + 128; goto L_227d0;
L_22924:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v1 + 4;
    v0 = (u32)v0 < (u32)(5);
    v0 = (u32)v0 < (u32)(1);
    branch = (v1 != a0); a1 = a1 + v0;
    if (branch) goto L_22924;
    goto L_2293c;
L_2293c:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (376));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (372));
    t5 = *(volatile u32 *)(unsigned long)(s8 + (384));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (380));
    t7 = a0 + 40;
    t8 = 2;
    t9 = 1;
    a1 = (u32)a1 < (u32)(2);
    ra = 256;
L_22960:
    v0 = *(volatile u8 *)(unsigned long)(t3 + (0));
    branch = (v0 == t8); a2 = 0;
    if (branch) goto L_22a24;
    goto L_2296c;
L_2296c:
    a0 = a0 + 4;
    t3 = t3 + 1;
    t5 = t5 + 2;
    branch = (a0 != t7); t4 = t4 + 2;
    if (branch) goto L_22960;
    goto L_22980;
L_22980:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (112));
    a0 = 0;
    v0 = 0; goto L_22ac0;
L_22990:
    v1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t6 = *(volatile u16 *)(unsigned long)(t4 + (0));
    v1 = v0 + v1;
    v1 = v1 >> (s7 & 31);
    v0 = (u32)v1 < (u32)(t6);
    s0 = t6 - v1;
    t2 = v1 - t6;
    if (v0 != 0) t2 = s0;
    v1 = *(volatile u32 *)(unsigned long)(t1 + (4096));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (116));
    t6 = *(volatile u16 *)(unsigned long)(t5 + (0));
    v1 = v0 + v1;
    v1 = v1 >> (s7 & 31);
    v0 = (u32)v1 < (u32)(t6);
    s0 = t6 - v1;
    v1 = v1 - t6;
    if (v0 != 0) v1 = s0;
    product = (s64)(s32)v1 * (s32)v1; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t2 * (s32)t2); lo = product; hi = product >> 32;
    t2 = lo;
    v1 = (u32)t2 < (u32)(615);
    branch = (v1 != 0); v0 = 0;
    if (branch) goto L_22a44;
    goto L_229ec;
L_229ec:
    v1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v0 = ra - v0;
    v0 = v0 << (s7 & 31);
    v1 = (u32)v0 < (u32)(v1);
    if (v1 != 0) { *(volatile u32 *)(unsigned long)(t0 + (0)) = v0; goto L_22a04; }
    goto L_22a04;
L_22a04:
    a3 = a3 + 1;
    a3 = a3 & 0xffff;
    t0 = t0 + 4;
    t1 = t1 + 4;
L_22a14:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (a3 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (116));
    if (branch) goto L_22990;
    goto L_22a20;
L_22a20:
    a2 = a2 + 128;
L_22a24:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    branch = (v0 == a2); v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    if (branch) goto L_2296c;
    goto L_22a30;
L_22a30:
    a3 = 0;
    t0 = v0 + a2;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    t1 = v0 + a2; goto L_22a14;
L_22a44:
    v1 = (u32)t2 < (u32)(572);
    branch = (v1 == 0); v0 = 3;
    if (branch) goto L_229ec;
    goto L_22a50;
L_22a50:
    v1 = (u32)t2 < (u32)(540);
    branch = (v1 == 0); v0 = 4;
    if (branch) goto L_229ec;
    goto L_22a5c;
L_22a5c:
    v1 = (u32)t2 < (u32)(514);
    branch = (v1 == 0); v0 = 5;
    if (branch) goto L_229ec;
    goto L_22a68;
L_22a68:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (280));
    branch = (v0 != t9); ;
    if (branch) goto L_22a84;
    goto L_22a74;
L_22a74:
    if (a1 == 0) { v0 = *(volatile u32 *)(unsigned long)(a0 + (0)); goto L_22a90; }
    goto L_22a7c;
L_22a7c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (260)); goto L_22aa4;
L_22a84:
    if (v0 != 0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (260)); goto L_22aa4; }
    goto L_22a8c;
L_22a8c:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
L_22a90:
    v0 = v0 * v0;
    v1 = (u32)t2 < (u32)(v0);
    branch = (v1 != 0); v0 = 256;
    if (branch) goto L_229ec;
    goto L_22aa0;
L_22aa0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (260));
L_22aa4:
    t2 = t2 << (0x1 & 31);
    t2 = v0 + t2;
    v0 = *(volatile u16 *)(unsigned long)(t2 + (0)); goto L_229ec;
L_22ab4:
    v0 = v0 + 1;
    v0 = v0 & 0xffff;
    a1 = a1 + 128;
L_22ac0:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (120));
    branch = (v0 == v1); a2 = a1;
    if (branch) goto L_22af0;
    goto L_22acc;
L_22acc:
    v1 = 0;
L_22ad0:
    a3 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (v1 == a3); v1 = v1 + 1;
    if (branch) goto L_22ab4;
    goto L_22adc;
L_22adc:
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v1 = v1 & 0xffff;
    a0 = a0 + a3;
    a2 = a2 + 4; goto L_22ad0;
L_22af0:
    branch = (a0 == 0); v0 = 1;
    if (branch) goto L_22de0;
    goto L_22af8;
L_22af8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (520));
    *(volatile u32 *)(unsigned long)(s8 + (92)) = s7;
    *(volatile u32 *)(unsigned long)(s8 + (88)) = s6;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (88)))[i]; }
    v1 = -1;
    a2 = hi_22b10;
    v0 = -s7;
    v0 = v1 >> (v0 & 31);
    a2 = a2 - hi_22b10 + (u32)(unsigned long)ref_t32_data_db050;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[0]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (92)))[i]; }
    *(volatile u32 *)(unsigned long)(s8 + (100)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[0].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (100)))[i]; }
    t0 = hi_22b38;
    t0 = t0 - hi_22b38 + (u32)(unsigned long)ref_t32_data_db040;
    *(volatile u32 *)(unsigned long)(s8 + (96)) = v0;
    t1 = hi_22b44;
    t1 = t1 - hi_22b44 + (u32)(unsigned long)ref_t32_data_db030;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[0]; vx[0] = tmp; }
    v1 = hi_22b50;
    v1 = v1 - hi_22b50 + (u32)(unsigned long)ref_t32_data_db020;
    a0 = hi_22b58;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t0 + (0)))[i] = vx[0].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (96)))[i]; }
    a0 = a0 - hi_22b58 + (u32)(unsigned long)ref_t32_data_db010;
    a3 = hi_22b68;
    a3 = a3 - hi_22b68 + (u32)(unsigned long)ref_t32_data_db000;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[3].w[0]; vx[3] = tmp; }
    t2 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[0]; vx[0] = tmp; }
    *(volatile u32 *)(unsigned long)(s8 + (116)) = a2;
    t5 = hi_22b80;
    t6 = hi_22b84;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t1 + (0)))[i] = vx[0].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (76)))[i]; }
    t7 = hi_22b90;
    t8 = hi_22b94;
    t9 = hi_22b98;
    ra = hi_22b9c;
    s0 = hi_22ba0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[0]; vx[0] = tmp; }
    s1 = hi_22ba8;
    s2 = hi_22bac;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (0)))[i] = vx[0].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (72)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[0]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[0].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (68)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[0]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[0].b[i]; }
L_22bcc:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (120));
    v0 = t2 & 0xffff;
    v0 = (u32)v0 < (u32)(a1);
    branch = (v0 == 0); t3 = t2 << (0x7 & 31);
    if (branch) goto L_22d90;
    goto L_22be0;
L_22be0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    s4 = t2 << (0x5 & 31);
    s3 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (160));
    a1 = 0;
    t3 = v0 + t3;
L_22bf8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    v0 = (u32)a1 < (u32)(v0);
    branch = (v0 == 0); a2 = *(volatile u32 *)(unsigned long)(s8 + (108));
    if (branch) goto L_24544;
    goto L_22c08;
L_22c08:
    v0 = a1 << (0x2 & 31);
    t4 = a1 + s4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s3 + (v0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(t3 + (v0)))[i]; }
    v0 = t4 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(a2 + (v0)))[i]; }
    v0 = v0 + 4096;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a2 + (v0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (220));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (8 & 31); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (t4)))[i]; }
    v0 = t5 - hi_22b80 + (u32)(unsigned long)ref_t32_data_ce130;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (8 & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (vx[3].w[i] & 31); vx[9] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (116));
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    a1 = a1 + 4;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] << (vx[3].w[i] & 31); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] & vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] & vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] << (vx[3].w[i] & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] + ((u32)vx[9].w[i] * (u32)vx[0].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[5].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] >> (vx[3].w[i] & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] & vx[0].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] & vx[8].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[5].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[5].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[4].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] << (vx[3].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[5].w[i] + ((u32)vx[9].w[i] * (u32)vx[4].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = t6 - hi_22b84 + (u32)(unsigned long)ref_t32_data_dae60;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] >> (vx[3].w[i] & 31); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] >> (vx[9].w[i] & 31); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] + (u32)vx[2].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[i] & vx[10].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] + (u32)vx[0].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] << (8 & 31); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] >> (vx[9].w[i] & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[8].w[i] & vx[10].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] << (vx[9].w[i] & 31); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[8].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[i] + ((u32)vx[12].w[i] * (u32)vx[8].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (vx[9].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[11].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] + (u32)vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] >> (vx[9].w[i] & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[6].w[i] & vx[10].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[6].w[i] | vx[6].w[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[7].b[i]; }
    v0 = t7 - hi_22b90 + (u32)(unsigned long)ref_t32_data_dae50;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[6].b[i]; }
    v0 = t8 - hi_22b94 + (u32)(unsigned long)ref_t32_data_dae40;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    v0 = t9 - hi_22b98 + (u32)(unsigned long)ref_t32_data_dae30;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[8].b[i]; }
    v0 = s1 - hi_22ba8 + (u32)(unsigned long)ref_t32_data_dadf0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[8].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] << (vx[9].w[i] & 31); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] + ((u32)vx[7].w[i] * (u32)vx[8].w[i]); vx[1] = tmp; }
    v0 = s0 - hi_22ba0 + (u32)(unsigned long)ref_t32_data_dae00;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] >> (vx[9].w[i] & 31); vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[6].w[i]; vx[1] = tmp; }
    v0 = ra - hi_22b9c + (u32)(unsigned long)ref_t32_data_dae20;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] + (u32)vx[0].w[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s2 - hi_22bac + (u32)(unsigned long)ref_t32_data_dae10;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[4].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[0].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] + (u32)vx[2].w[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] + (u32)vx[1].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[1].b[i]; }
    a1 = a1 & 0xffff; goto L_22bf8;
L_22d90:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (76));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (72));
    a2 = *(volatile u32 *)(unsigned long)(s8 + (68));
    t1 = 16;
L_22da0:
    t2 = v1 + v0;
    t2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    a1 = a1 + t2;
    t2 = a0 + v0;
    t2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    t0 = t0 + t2;
    t2 = a3 + v0;
    t2 = *(volatile u32 *)(unsigned long)(t2 + (0));
    v0 = v0 + 4;
    branch = (v0 != t1); a2 = a2 + t2;
    if (branch) goto L_22da0;
    goto L_22dcc;
L_22dcc:
    *(volatile u32 *)(unsigned long)(s8 + (76)) = a1;
    *(volatile u32 *)(unsigned long)(s8 + (72)) = t0;
    branch = (a2 != 0); *(volatile u32 *)(unsigned long)(s8 + (68)) = a2;
    if (branch) goto L_22e34;
    goto L_22ddc;
L_22ddc:
    v0 = 1;
L_22de0:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (520));
L_22de4:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (156));
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    v1 = 5000;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (516));
    v0 = v0 << (s6 & 31);
    a0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
    *(volatile u32 *)(unsigned long)(v1 + (4)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (520));
    a3 = v1;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_22e1c;
    v0 = v0 - hi_22e1c + (u32)(unsigned long)ref_Tiziano_Awb_Ct_Detect_GrayWorld;
    callee = v0; a2 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_22e2c;
L_22e2c:
    sp = s8; goto L_24550;
L_22e34:
    s0 = hi_22e34;
    s0 = s0 - hi_22e34 + (u32)(unsigned long)ref_fix_point_div_32;
    callee = s0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_22e44;
L_22e44:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (68));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (72));
    a0 = s7;
    callee = s0; *(volatile u32 *)(unsigned long)(s8 + (116)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_22e58;
L_22e58:
    v1 = *(volatile u8 *)(unsigned long)(s8 + (364));
    *(volatile u32 *)(unsigned long)(s8 + (120)) = v0;
    v0 = 1;
    branch = (v1 != v0); *(volatile u32 *)(unsigned long)(s8 + (124)) = s0;
    if (branch) goto L_23394;
    goto L_22e6c;
L_22e6c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (68));
    branch = (v0 == 0); v1 = *(volatile u16 *)(unsigned long)(s8 + (420));
    if (branch) goto L_23398;
    goto L_22e78;
L_22e78:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (160));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (136));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (108));
    *(volatile u32 *)(unsigned long)(s8 + (200)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (220));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (112));
    s4 = *(volatile u32 *)(unsigned long)(s8 + (220));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (396));
    s3 = *(volatile u32 *)(unsigned long)(s8 + (160));
    s1 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (160));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v0 = v0 + v1;
    *(volatile u32 *)(unsigned long)(s8 + (132)) = v0;
    v0 = hi_22eb8;
    *(volatile u32 *)(unsigned long)(s8 + (140)) = v0;
    v0 = hi_22ec0;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = v0;
L_22ec8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    branch = (s3 == v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (252));
    if (branch) goto L_2304c;
    goto L_22ed4;
L_22ed4:
    t0 = t4;
    t5 = t2;
    v0 = s3 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (108)) = v0;
    t6 = t3;
    s0 = s4;
    v1 = s3;
L_22ef0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    if (v1 == v0) { s3 = s3 + 128; goto L_23038; }
    goto L_22efc;
L_22efc:
    v0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    *(volatile u32 *)(unsigned long)(s8 + (224)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    *(volatile u32 *)(unsigned long)(s8 + (256)) = t4;
    *(volatile u32 *)(unsigned long)(s8 + (248)) = t6;
    a0 = (u32)v0 < (u32)(v1);
    a2 = v1 - v0;
    v0 = v0 - v1;
    if (a0 == 0) a2 = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (120));
    v0 = *(volatile u32 *)(unsigned long)(t0 + (4096));
    a1 = a2;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = t5;
    a0 = (u32)v0 < (u32)(v1);
    t7 = v1 - v0;
    v0 = v0 - v1;
    if (a0 == 0) t7 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    a0 = s6;
    *(volatile u32 *)(unsigned long)(s8 + (240)) = t3;
    s2 = v0 - hi_22eb8 + (u32)(unsigned long)ref_fix_point_mult2_32;
    *(volatile u32 *)(unsigned long)(s8 + (228)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = t0;
    callee = s2; *(volatile u32 *)(unsigned long)(s8 + (168)) = t7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_22f60;
L_22f60:
    t7 = *(volatile u32 *)(unsigned long)(s8 + (168));
    a0 = s6;
    *(volatile u32 *)(unsigned long)(s8 + (156)) = v0;
    a2 = t7;
    callee = s2; a1 = t7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_22f78;
L_22f78:
    a3 = *(volatile u32 *)(unsigned long)(s8 + (156));
    t6 = *(volatile u32 *)(unsigned long)(s8 + (248));
    t5 = *(volatile u32 *)(unsigned long)(s8 + (244));
    a1 = a3 + v0;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = a1;
    a2 = *(volatile u32 *)(unsigned long)(t5 + (0));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (184));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (228));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (240));
    branch = (a2 == 0); t4 = *(volatile u32 *)(unsigned long)(s8 + (256));
    if (branch) goto L_23020;
    goto L_22fa8;
L_22fa8:
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    if (a3 == 0) { v1 = v1 + 4; goto L_23024; }
    goto L_22fb4;
L_22fb4:
    v0 = *(volatile u8 *)(unsigned long)(s0 + (0));
    if (v0 == 0) { v1 = v1 + 4; goto L_23024; }
    goto L_22fc0;
L_22fc0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    a0 = s6;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = t4;
    v0 = v0 - hi_22ec0 + (u32)(unsigned long)ref_fix_point_mult3_32;
    *(volatile u32 *)(unsigned long)(s8 + (240)) = t6;
    *(volatile u32 *)(unsigned long)(s8 + (228)) = t5;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = t3;
    *(volatile u32 *)(unsigned long)(s8 + (168)) = t2;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (156)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_22fec;
L_22fec:
    a2 = *(volatile u8 *)(unsigned long)(s0 + (0));
    a1 = v0;
    a0 = s6;
    callee = s2; a2 = a2 << (s6 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23000;
L_23000:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (244));
    t6 = *(volatile u32 *)(unsigned long)(s8 + (240));
    t5 = *(volatile u32 *)(unsigned long)(s8 + (228));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (184));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (168));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (156));
    s1 = s1 + v0;
L_23020:
    v1 = v1 + 4;
L_23024:
    s0 = s0 + 1;
    t6 = t6 + 4;
    t5 = t5 + 4;
    t0 = t0 + 4; goto L_22ef0;
L_23038:
    s4 = s4 + 32;
    t3 = t3 + 128;
    t2 = t2 + 128;
    t4 = t4 + 128; goto L_22ec8;
L_2304c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (68));
    branch = (v0 != 0); a2 = *(volatile u32 *)(unsigned long)(s8 + (68));
    if (branch) goto L_23074;
    goto L_23058;
L_23058:
    a0 = hi_23058;
    v0 = hi_2305c;
    a1 = 1970;
    v0 = v0 - hi_2305c + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_23058 + (u32)(unsigned long)ref_t32_data_c7d34;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23070;
L_23070:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (68));
L_23074:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a1 = s1;
    callee = v0; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23084;
L_23084:
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(s8 + (248)) = v0;
    if (branch) goto L_23394;
    goto L_2308c;
L_2308c:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (320));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (316));
    s4 = *(volatile u32 *)(unsigned long)(s8 + (400));
    s0 = 0;
    v0 = v0 - v1;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (316));
    *(volatile u32 *)(unsigned long)(s8 + (156)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = 0;
    v0 = v0 << (0x6 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (264)) = v0;
    v0 = v1 << (0x6 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (256)) = v0;
    v0 = 1;
    v0 = v0 << (s6 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (268)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (244));
    v0 = v0 << (0x6 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (280)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    v0 = s4 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (260)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    *(volatile u32 *)(unsigned long)(s8 + (108)) = v0;
    v0 = hi_230ec;
    *(volatile u32 *)(unsigned long)(s8 + (296)) = v0;
    v0 = hi_230f4;
    v0 = v0 - hi_230f4 + (u32)(unsigned long)ref_t32_data_c7d34;
    *(volatile u32 *)(unsigned long)(s8 + (300)) = v0;
    v0 = hi_23100;
    *(volatile u32 *)(unsigned long)(s8 + (304)) = v0;
    v0 = hi_23108;
    *(volatile u32 *)(unsigned long)(s8 + (308)) = v0;
L_23110:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (260));
    branch = (v0 == s4); v0 = *(volatile u32 *)(unsigned long)(s8 + (252));
    if (branch) goto L_2335c;
    goto L_2311c;
L_2311c:
    s2 = *(volatile u32 *)(unsigned long)(s8 + (284));
    *(volatile u32 *)(unsigned long)(s8 + (132)) = s4;
    v0 = s4 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (292)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    *(volatile u32 *)(unsigned long)(s8 + (168)) = s4;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = s4;
    *(volatile u32 *)(unsigned long)(s8 + (112)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    s1 = s4;
    *(volatile u32 *)(unsigned long)(s8 + (140)) = v0;
    s3 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (180));
    *(volatile u32 *)(unsigned long)(s8 + (228)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (200));
    *(volatile u32 *)(unsigned long)(s8 + (224)) = v0;
L_2315c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (292));
    branch = (s1 == v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    if (branch) goto L_23318;
    goto L_23168;
L_23168:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (248));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    callee = v0; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2317c;
L_2317c:
    a3 = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (296));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v1 = v1 - hi_230ec + (u32)(unsigned long)ref_fix_point_mult2_32;
    v0 = (u32)v0 < (u32)(a3);
    branch = (v0 == 0); *(volatile u32 *)(unsigned long)(s8 + (240)) = v1;
    if (branch) goto L_231a4;
    goto L_23198;
L_23198:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (184));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0; goto L_2322c;
L_231a4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (256));
    v0 = (u32)a3 < (u32)(v0);
    if (v0 == 0) { v0 = *(volatile u32 *)(unsigned long)(s8 + (244)); goto L_231c0; }
    goto L_231b4;
L_231b4:
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (168)); goto L_23228;
L_231c0:
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    if (branch) goto L_231e8;
    goto L_231c8;
L_231c8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (300));
    a1 = 1997;
    v0 = v0 - hi_23100 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (312)) = a3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_231e0;
L_231e0:
    a3 = *(volatile u32 *)(unsigned long)(s8 + (312));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
L_231e8:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (280));
    t0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (256));
    *(volatile u32 *)(unsigned long)(s8 + (312)) = t0;
    a1 = a3 - v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    callee = v0; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23208;
L_23208:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (268));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (312));
    a0 = s6;
    a2 = v1 - v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (240));
    callee = v0; a1 = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23224;
L_23224:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (132));
L_23228:
    *(volatile u32 *)(unsigned long)(v1 + (0)) = v0;
L_2322c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    a1 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s7;
    a3 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a1 = a1 >> (0x8 & 31);
    a3 = a3 << (s7 & 31);
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    s1 = s1 + 4;
    v0 = v0 - hi_23108 + (u32)(unsigned long)ref_fix_point_mult3_32;
    callee = v0; a2 = a2 >> (0x8 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23260;
L_23260:
    t0 = v0 << (0x8 & 31);
    a1 = *(volatile u32 *)(unsigned long)(s2 + (0));
    *(volatile u32 *)(unsigned long)(s8 + (316)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (240));
    a2 = t0;
    a0 = s6;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (312)) = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23280;
L_23280:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (144));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (312));
    a1 = *(volatile u32 *)(unsigned long)(s2 + (4096));
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (240));
    a2 = t0;
    callee = v0; a0 = s6;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_232a4;
L_232a4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (156));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (316));
    s2 = s2 + 4;
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (156)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    s0 = s0 + a3;
    s3 = s3 + 4;
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (228)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (184));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (168));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (168)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (140)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (132)) = v0;
L_23308:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (112));
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(s8 + (112)) = v0; goto L_2315c;
L_23318:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (200));
    s4 = s4 + 128;
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (200)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (180));
    v0 = v0 + 32;
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (284));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (284)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (108)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = v0; goto L_23110;
L_2335c:
    branch = (s0 == 0); v1 = *(volatile u16 *)(unsigned long)(s8 + (420));
    if (branch) goto L_23398;
    goto L_23364;
L_23364:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (144));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a2 = s0;
    callee = v0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23378;
L_23378:
    *(volatile u32 *)(unsigned long)(s8 + (116)) = v0;
    a1 = *(volatile u32 *)(unsigned long)(s8 + (156));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a2 = s0;
    callee = v0; a0 = s7;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_23390;
L_23390:
    *(volatile u32 *)(unsigned long)(s8 + (120)) = v0;
L_23394:
    v1 = *(volatile u16 *)(unsigned long)(s8 + (420));
L_23398:
    v0 = 1;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    if (branch) goto L_24508;
    goto L_233a4;
L_233a4:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (164));
    s1 = *(volatile u32 *)(unsigned long)(s8 + (272));
    v0 = v0 << (0x2 & 31);
    v1 = v0 + -8;
    v1 = a0 + v1;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (172));
    v0 = v0 + -2;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (160));
    v1 = v1 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (132)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (136));
    v0 = a0 + v0;
    s6 = *(volatile u32 *)(unsigned long)(s8 + (220));
    s4 = *(volatile u32 *)(unsigned long)(s8 + (336));
    *(volatile u32 *)(unsigned long)(s8 + (140)) = v0;
    t8 = hi_233e4;
    t7 = hi_233e8;
    v0 = hi_233ec;
    t9 = s1 + v1;
    *(volatile u32 *)(unsigned long)(s8 + (124)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (108)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (112)) = 0;
    t8 = t8 - hi_233e4 + (u32)(unsigned long)ref_t32_data_dc02c;
    t7 = t7 - hi_233e8 + (u32)(unsigned long)ref_t32_data_dc004;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = v0;
L_2340c:
    branch = (s1 == t9); v0 = *(volatile u32 *)(unsigned long)(s8 + (252));
    if (branch) goto L_236d8;
    goto L_23414;
L_23414:
    s7 = *(volatile u32 *)(unsigned long)(s8 + (216));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (288));
    t3 = s1 + v0;
    s3 = s4;
    a3 = s6;
    t0 = t2;
    t1 = s1;
    s2 = s1;
L_23434:
    branch = (t3 == s2); v0 = *(volatile u32 *)(unsigned long)(s8 + (172));
    if (branch) goto L_236ac;
    goto L_2343c;
L_2343c:
    a1 = *(volatile u32 *)(unsigned long)(s3 + (4096));
    a2 = *(volatile u32 *)(unsigned long)(s8 + (112));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (6));
    a0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    v0 = (u32)v0 < (u32)(a1);
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (112)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = (u32)v0 < (u32)(a0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    if (branch) goto L_23478;
    goto L_2346c;
L_2346c:
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (124)) = v0; goto L_23480;
L_23478:
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (172));
    if (branch) goto L_23494;
    goto L_23480;
L_23480:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (108));
    v0 = (u32)0 < (u32)(a1);
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (108)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (172));
L_23494:
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = (u32)v0 < (u32)(a1);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    if (branch) goto L_234f0;
    goto L_234a4;
L_234a4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = (u32)v0 < (u32)(a1);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    if (branch) goto L_234f0;
    goto L_234b8;
L_234b8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (164));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = (u32)v0 < (u32)(a0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    if (branch) goto L_234f0;
    goto L_234cc;
L_234cc:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = (u32)v0 < (u32)(a0);
    branch = (v0 != 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    if (branch) goto L_234f0;
    goto L_234e0;
L_234e0:
    a2 = 1;
    s0 = 0;
    t6 = *(volatile u16 *)(unsigned long)(s8 + (152)); goto L_23528;
L_234f0:
    *(volatile u32 *)(unsigned long)(s2 + (0)) = v0; goto L_2368c;
L_234f8:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (164));
    v0 = v0 & 0xff;
    v0 = v0 << (0x1 & 31);
    t4 = t4 + v0;
    t4 = *(volatile u16 *)(unsigned long)(t4 + (0));
    t4 = (u32)a0 < (u32)(t4);
    branch = (t4 == 0); t5 = *(volatile u32 *)(unsigned long)(s8 + (164));
    if (branch) goto L_2353c;
    goto L_23518;
L_23518:
    s0 = s0 + 1;
L_2351c:
    a2 = a2 + 2;
    s0 = s0 & 0xffff;
    a2 = a2 & 0xff;
L_23528:
    v0 = (u32)s0 < (u32)(t6);
    branch = (v0 != 0); v0 = a2 + -1;
    if (branch) goto L_234f8;
    goto L_23534;
L_23534:
    s2 = s2 + 4; goto L_23690;
L_2353c:
    t4 = a2 << (0x1 & 31);
    t5 = t5 + t4;
    t5 = *(volatile u16 *)(unsigned long)(t5 + (0));
    t5 = (u32)a0 < (u32)(t5);
    if (t5 == 0) { s0 = s0 + 1; goto L_2351c; }
    goto L_23554;
L_23554:
    t5 = *(volatile u32 *)(unsigned long)(s8 + (172));
    t4 = t5 + t4;
    t4 = *(volatile u16 *)(unsigned long)(t4 + (0));
    t4 = (u32)a1 < (u32)(t4);
    if (t4 != 0) { s0 = s0 + 1; goto L_2351c; }
    goto L_2356c;
L_2356c:
    v0 = t5 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = (u32)a1 < (u32)(v0);
    if (v0 == 0) { s0 = s0 + 1; goto L_2351c; }
    goto L_23580;
L_23580:
    *(volatile u32 *)(unsigned long)(t1 + (0)) = s0;
    s0 = s0 << (0x2 & 31);
    a2 = s0 + t8;
    v0 = *(volatile u32 *)(unsigned long)(a2 + (0));
    t4 = hi_23590;
    t4 = t4 - hi_23590 + (u32)(unsigned long)ref_t32_data_dbf8c;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a2 + (0)) = v0;
    a2 = s0 + t7;
    v0 = *(volatile u32 *)(unsigned long)(a2 + (0));
    t4 = s0 + t4;
    t5 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    *(volatile u32 *)(unsigned long)(a2 + (0)) = a0;
    *(volatile u32 *)(unsigned long)(s8 + (244)) = t2;
    v0 = v0 - hi_233ec + (u32)(unsigned long)ref_t32_data_dbfdc;
    v0 = s0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(s8 + (240)) = v1;
    *(volatile u32 *)(unsigned long)(s8 + (228)) = t9;
    a1 = a0 + a1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a1;
    a2 = *(volatile u8 *)(unsigned long)(a3 + (0));
    a1 = *(volatile u32 *)(unsigned long)(t0 + (0));
    v0 = hi_235e4;
    a0 = 10;
    a1 = a1 >> (0x6 & 31);
    a2 = a2 << (0xa & 31);
    v0 = v0 - hi_235e4 + (u32)(unsigned long)ref_fix_point_mult2_32;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = t3;
    *(volatile u32 *)(unsigned long)(s8 + (220)) = t1;
    *(volatile u32 *)(unsigned long)(s8 + (180)) = t8;
    *(volatile u32 *)(unsigned long)(s8 + (200)) = t7;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = t4;
    *(volatile u32 *)(unsigned long)(s8 + (168)) = t5;
    *(volatile u32 *)(unsigned long)(s8 + (160)) = a3;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (156)) = t0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_2361c;
L_2361c:
    t5 = *(volatile u32 *)(unsigned long)(s8 + (168));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (184));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (240));
    v0 = t5 + v0;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = v0;
    v0 = hi_23630;
    v0 = v0 - hi_23630 + (u32)(unsigned long)ref_t32_data_dbf64;
    v0 = s0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (156));
    a0 = a0 >> (0x6 & 31);
    a0 = a0 + a1;
    *(volatile u32 *)(unsigned long)(v0 + (0)) = a0;
    v0 = hi_23654;
    v0 = v0 - hi_23654 + (u32)(unsigned long)ref_t32_data_dbf3c;
    s0 = s0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(s7 + (0));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (160));
    t7 = *(volatile u32 *)(unsigned long)(s8 + (200));
    t8 = *(volatile u32 *)(unsigned long)(s8 + (180));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (220));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (224));
    t9 = *(volatile u32 *)(unsigned long)(s8 + (228));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (244));
    v0 = v0 + a0;
    *(volatile u32 *)(unsigned long)(s0 + (0)) = v0;
L_2368c:
    s2 = s2 + 4;
L_23690:
    t1 = t1 + 4;
    t0 = t0 + 4;
    a3 = a3 + 1;
    v1 = v1 + 4;
    s7 = s7 + 2;
    s3 = s3 + 4; goto L_23434;
L_236ac:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (288));
    s1 = s1 + 128;
    t2 = t2 + 128;
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (288)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (216));
    s6 = s6 + 32;
    s4 = s4 + 128;
    v0 = v0 + 64;
    *(volatile u32 *)(unsigned long)(s8 + (216)) = v0; goto L_2340c;
L_236d8:
    t2 = *(volatile u32 *)(unsigned long)(s8 + (404));
    v1 = hi_236dc;
    s6 = *(volatile u16 *)(unsigned long)(s8 + (152));
    v1 = v1 - hi_236dc + (u32)(unsigned long)ref_t32_data_dc02c;
    a2 = v1;
    a1 = t2;
    a0 = 0;
    v0 = 0;
    s4 = v1;
L_236fc:
    a3 = (u32)v0 < (u32)(s6);
    branch = (a3 == 0); v0 = v0 + 1;
    if (branch) goto L_23724;
    goto L_23708;
L_23708:
    *(volatile u16 *)(unsigned long)(a1 + (0)) = 0;
    a3 = *(volatile u32 *)(unsigned long)(a2 + (0));
    v0 = v0 & 0xffff;
    a0 = a0 + a3;
    a1 = a1 + 2;
    a2 = a2 + 4; goto L_236fc;
L_23724:
    branch = (a0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    if (branch) goto L_24508;
    goto L_2372c;
L_2372c:
    a1 = hi_2372c;
    a2 = hi_23730;
    a3 = hi_23734;
    t0 = hi_23738;
    t1 = hi_2373c;
    a1 = a1 - hi_2372c + (u32)(unsigned long)ref_t32_data_dafd0;
    a2 = a2 - hi_23730 + (u32)(unsigned long)ref_t32_data_dafa8;
    a3 = a3 - hi_23734 + (u32)(unsigned long)ref_t32_data_daf80;
    t0 = t0 - hi_23738 + (u32)(unsigned long)ref_t32_data_daf58;
    t1 = t1 - hi_2373c + (u32)(unsigned long)ref_t32_data_daf30;
    v0 = v0 << (0x2 & 31);
    ra = hi_23758;
    s0 = hi_2375c;
    s1 = hi_23760;
    s2 = hi_23764;
    s3 = hi_23768;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = v0;
    t3 = v1;
    t4 = t1;
    t5 = t0;
    t6 = a3;
    t8 = a2;
    t7 = a1;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (156)) = a1;
    *(volatile u32 *)(unsigned long)(s8 + (160)) = a2;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (132)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (140)) = t1;
    ra = ra - hi_23758 + (u32)(unsigned long)ref_t32_data_dc004;
    s0 = s0 - hi_2375c + (u32)(unsigned long)ref_t32_data_dbfdc;
    s1 = s1 - hi_23760 + (u32)(unsigned long)ref_t32_data_dbf8c;
    s2 = s2 - hi_23764 + (u32)(unsigned long)ref_t32_data_dbf64;
    s3 = s3 - hi_23768 + (u32)(unsigned long)ref_t32_data_dbf3c;
L_237b4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    if (a0 == v0) { t7 = hi_237bc; goto L_23870; }
    goto L_237c0;
L_237c0:
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    *(volatile u16 *)(unsigned long)(t2 + (0)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(t7 + (0)) = 0; goto L_2383c; }
    goto L_237d4;
L_237d4:
    t9 = ra + a0;
    t9 = *(volatile u32 *)(unsigned long)(t9 + (0));
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    t9 = lo;
    *(volatile u32 *)(unsigned long)(t7 + (0)) = t9;
    t9 = s0 + a0;
    t9 = *(volatile u32 *)(unsigned long)(t9 + (0));
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    t9 = lo;
    *(volatile u32 *)(unsigned long)(t8 + (0)) = t9;
    t9 = s1 + a0;
    t9 = *(volatile u32 *)(unsigned long)(t9 + (0));
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    t9 = lo;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = t9;
    t9 = s2 + a0;
    t9 = *(volatile u32 *)(unsigned long)(t9 + (0));
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    t9 = lo;
    *(volatile u32 *)(unsigned long)(t5 + (0)) = t9;
    t9 = s3 + a0;
    t9 = *(volatile u32 *)(unsigned long)(t9 + (0));
    if (v0) { lo = t9 / v0; hi = t9 % v0; } else { lo = ~0U; hi = t9; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = v0; goto L_2384c;
L_2383c:
    *(volatile u32 *)(unsigned long)(t8 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(t5 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(t4 + (0)) = 0;
L_2384c:
    a0 = a0 + 4;
    t7 = t7 + 4;
    t8 = t8 + 4;
    t6 = t6 + 4;
    t5 = t5 + 4;
    t4 = t4 + 4;
    t3 = t3 + 4;
    t2 = t2 + 2; goto L_237b4;
L_23870:
    t3 = 0;
    t7 = t7 - hi_237bc + (u32)(unsigned long)ref_t32_data_dbfb4;
L_23878:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    branch = (v0 == t3); v0 = *(volatile u32 *)(unsigned long)(s8 + (336));
    if (branch) goto L_23924;
    goto L_23884;
L_23884:
    t4 = 0;
    t6 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    t8 = v0 + t3;
L_23894:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (104));
    branch = (t4 == v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (156));
    if (branch) goto L_2391c;
    goto L_238a0;
L_238a0:
    a0 = *(volatile u8 *)(unsigned long)(t8 + (0));
    t2 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a0 = a0 << (0x2 & 31);
    v0 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t9 = *(volatile u32 *)(unsigned long)(t6 + (4096));
    ra = (u32)v0 < (u32)(t2);
    t5 = t2 - v0;
    v0 = v0 - t2;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (160));
    if (ra != 0) v0 = t5;
    t2 = t2 + a0;
    t5 = *(volatile u32 *)(unsigned long)(t2 + (0));
    t2 = (u32)t5 < (u32)(t9);
    ra = t9 - t5;
    t5 = t5 - t9;
    if (t2 != 0) t5 = ra;
    product = (s64)(s32)t5 * (s32)t5; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)v0); lo = product; hi = product >> 32;
    v0 = lo;
    v0 = (u32)v0 < (u32)(1000);
    branch = (v0 == 0); t4 = t4 + 1;
    if (branch) goto L_2390c;
    goto L_238fc;
L_238fc:
    a0 = t7 + a0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (0)) = v0;
L_2390c:
    t4 = t4 & 0xffff;
    t6 = t6 + 4;
    t8 = t8 + 4; goto L_23894;
L_2391c:
    t3 = t3 + 128; goto L_23878;
L_23924:
    t9 = hi_23924;
    t9 = t9 - hi_23924 + (u32)(unsigned long)ref_t32_data_dbfb4;
    t5 = hi_2392c;
    t2 = t9;
    t4 = v1;
    a0 = 0;
    v0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (136)) = t9;
    t5 = t5 - hi_2392c + (u32)(unsigned long)ref_t32_data_daf24;
    t6 = 1;
L_2394c:
    t3 = a0 & 0xffff;
    t3 = (u32)t3 < (u32)(s6);
    branch = (t3 == 0); t3 = t5 + a0;
    if (branch) goto L_23988;
    goto L_2395c;
L_2395c:
    *(volatile u8 *)(unsigned long)(t3 + (0)) = a0;
    t3 = *(volatile u32 *)(unsigned long)(t2 + (0));
    if (t3 == 0) { *(volatile u32 *)(unsigned long)(t2 + (0)) = t6; goto L_2396c; }
    goto L_2396c;
L_2396c:
    t3 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a0 = a0 + 1;
    t4 = t4 + 4;
    v0 = v0 + t3;
    v0 = v0 & 0xffff;
    t2 = t2 + 4; goto L_2394c;
L_23988:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (152));
    ra = hi_2398c;
    ra = ra - hi_2398c + (u32)(unsigned long)ref_t32_data_daf24;
    s0 = a0 + -1;
L_23998:
    branch = (s0 == 0); t8 = t1;
    if (branch) goto L_23a7c;
    goto L_239a0;
L_239a0:
    t7 = t0;
    t6 = a3;
    t5 = t9;
    t4 = a2;
    t3 = a1;
    a0 = ra;
    t2 = v1;
L_239bc:
    s1 = a0 - ra;
    s1 = (u32)s1 < (u32)(s0);
    if (s1 == 0) { s0 = s0 + -1; goto L_23998; }
    goto L_239cc;
L_239cc:
    s1 = *(volatile u32 *)(unsigned long)(t2 + (0));
    s2 = *(volatile u32 *)(unsigned long)(t2 + (4));
    s3 = (u32)s1 < (u32)(s2);
    if (s3 == 0) { t2 = t2 + 4; goto L_23a5c; }
    goto L_239e0;
L_239e0:
    *(volatile u32 *)(unsigned long)(t2 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t2 + (4)) = s1;
    s2 = *(volatile u32 *)(unsigned long)(t3 + (4));
    s1 = *(volatile u32 *)(unsigned long)(t3 + (0));
    s3 = *(volatile u8 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(t3 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t3 + (4)) = s1;
    s2 = *(volatile u32 *)(unsigned long)(t4 + (4));
    s1 = *(volatile u32 *)(unsigned long)(t4 + (0));
    s7 = *(volatile u8 *)(unsigned long)(a0 + (1));
    *(volatile u32 *)(unsigned long)(t4 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t4 + (4)) = s1;
    s2 = *(volatile u32 *)(unsigned long)(t5 + (4));
    s1 = *(volatile u32 *)(unsigned long)(t5 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (0)) = s7;
    *(volatile u32 *)(unsigned long)(t5 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t5 + (4)) = s1;
    s2 = *(volatile u32 *)(unsigned long)(t6 + (4));
    s1 = *(volatile u32 *)(unsigned long)(t6 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (1)) = s3;
    *(volatile u32 *)(unsigned long)(t6 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t6 + (4)) = s1;
    s2 = *(volatile u32 *)(unsigned long)(t7 + (4));
    s1 = *(volatile u32 *)(unsigned long)(t7 + (0));
    *(volatile u32 *)(unsigned long)(t7 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t7 + (4)) = s1;
    s2 = *(volatile u32 *)(unsigned long)(t8 + (4));
    s1 = *(volatile u32 *)(unsigned long)(t8 + (0));
    *(volatile u32 *)(unsigned long)(t8 + (0)) = s2;
    *(volatile u32 *)(unsigned long)(t8 + (4)) = s1;
    t2 = t2 + 4;
L_23a5c:
    a0 = a0 + 1;
    t3 = t3 + 4;
    t4 = t4 + 4;
    t5 = t5 + 4;
    t6 = t6 + 4;
    t7 = t7 + 4;
    t8 = t8 + 4; goto L_239bc;
L_23a7c:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    if (a0 == 0) { a0 = 0; goto L_23acc; }
    goto L_23a88;
L_23a88:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (112));
    a2 = 100;
    a0 = a0 >> (0x1 & 31);
    a3 = a1 * a2;
    a1 = a3 + a0;
    a3 = *(volatile u32 *)(unsigned long)(s8 + (108));
    if (a3) { lo = a1 / a3; hi = a1 % a3; } else { lo = ~0U; hi = a1; }
    a3 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a1 = lo;
    a1 = (int16_t)a1;
    t0 = a3 * a2;
    a2 = *(volatile u32 *)(unsigned long)(s8 + (108));
    a0 = t0 + a0;
    if (a2) { lo = a0 / a2; hi = a0 % a2; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    a0 = a0 & 0xffff; goto L_23ad0;
L_23acc:
    a1 = 0;
L_23ad0:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (232));
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a2 = (s32)a2 < (s32)(a1);
    if (a2 == 0) { a2 = *(volatile u32 *)(unsigned long)(s8 + (232)); goto L_23af0; }
    goto L_23ae4;
L_23ae4:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    a2 = *(volatile u16 *)(unsigned long)(a1 + (0)); goto L_23b7c;
L_23af0:
    a2 = *(volatile u16 *)(unsigned long)(a2 + (6));
    a2 = (s32)a2 < (s32)(a1);
    if (a2 == 0) { a1 = *(volatile u32 *)(unsigned long)(s8 + (276)); goto L_23b78; }
    goto L_23b00;
L_23b00:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (232));
    t1 = a2 + 2;
    a2 = *(volatile u32 *)(unsigned long)(s8 + (276));
    t2 = a2 + 2;
    a2 = *(volatile u32 *)(unsigned long)(s8 + (232));
    t3 = a2 + 8;
    a2 = 0;
L_23b1c:
    t0 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a3 = (s32)t0 < (s32)(a1);
    if (a3 == 0) { t1 = t1 + 2; goto L_23b68; }
    goto L_23b2c;
L_23b2c:
    t4 = *(volatile u16 *)(unsigned long)(t1 + (-2));
    a3 = (s32)t4 < (s32)(a1);
    branch = (a3 != 0); t1 = t1 + 2;
    if (branch) goto L_23b68;
    goto L_23b3c;
L_23b3c:
    a2 = *(volatile u16 *)(unsigned long)(t2 + (-2));
    t0 = t4 - t0;
    a3 = *(volatile u16 *)(unsigned long)(t2 + (0));
    product = (s64)(s32)a2 * (s32)t0; lo = product; hi = product >> 32;
    t4 = t4 - a1;
    a3 = a3 - a2;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t4); lo = product; hi = product >> 32;
    a2 = lo;
    if (a2 == 0x80000000U && t0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t0) { lo = (s32)a2 / (s32)t0; hi = (s32)a2 % (s32)t0; } else { lo = (s32)a2 < 0 ? 1 : ~0U; hi = a2; }
    a2 = lo;
    a2 = a2 & 0xffff;
L_23b68:
    branch = (t3 != t1); t2 = t2 + 2;
    if (branch) goto L_23b1c;
    goto L_23b70;
L_23b70:
    a1 = *(volatile u16 *)(unsigned long)(s8 + (52)); goto L_23b80;
L_23b78:
    a2 = *(volatile u16 *)(unsigned long)(a1 + (6));
L_23b7c:
    a1 = *(volatile u16 *)(unsigned long)(s8 + (52));
L_23b80:
    a1 = (u32)a0 < (u32)(a1);
    if (a1 == 0) { a1 = *(volatile u16 *)(unsigned long)(s8 + (58)); goto L_23b94; }
    goto L_23b8c;
L_23b8c:
    a1 = *(volatile u16 *)(unsigned long)(s8 + (44)); goto L_23c0c;
L_23b94:
    a1 = (u32)a0 < (u32)(a1);
    branch = (a1 == 0); a1 = *(volatile u16 *)(unsigned long)(s8 + (50));
    if (branch) goto L_23c0c;
    goto L_23ba0;
L_23ba0:
    t1 = s8 + 52;
    t2 = s8 + 44;
    t3 = s8 + 58;
    a1 = 0;
L_23bb0:
    t0 = *(volatile u16 *)(unsigned long)(t1 + (2));
    a3 = (u32)a0 < (u32)(t0);
    if (a3 == 0) { t1 = t1 + 2; goto L_23bfc; }
    goto L_23bc0;
L_23bc0:
    t4 = *(volatile u16 *)(unsigned long)(t1 + (0));
    a3 = (u32)a0 < (u32)(t4);
    branch = (a3 != 0); t1 = t1 + 2;
    if (branch) goto L_23bfc;
    goto L_23bd0;
L_23bd0:
    a1 = *(volatile u16 *)(unsigned long)(t2 + (0));
    t0 = t0 - t4;
    a3 = *(volatile u16 *)(unsigned long)(t2 + (2));
    product = (s64)(s32)a1 * (s32)t0; lo = product; hi = product >> 32;
    t4 = a0 - t4;
    a3 = a3 - a1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t4); lo = product; hi = product >> 32;
    a1 = lo;
    if (a1 == 0x80000000U && t0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t0) { lo = (s32)a1 / (s32)t0; hi = (s32)a1 % (s32)t0; } else { lo = (s32)a1 < 0 ? 1 : ~0U; hi = a1; }
    a1 = lo;
    a1 = a1 & 0xffff;
L_23bfc:
    branch = (t3 != t1); t2 = t2 + 2;
    if (branch) goto L_23bb0;
    goto L_23c04;
L_23c04:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (348)); goto L_23c10;
L_23c0c:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (348));
L_23c10:
    branch = (a0 != 0); s0 = 3;
    if (branch) goto L_23d30;
    goto L_23c18;
L_23c18:
    v1 = s0 + -1;
    v0 = v1 << (0x2 & 31);
    v0 = s4 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (v0 != 0); t1 = hi_23c2c;
    if (branch) goto L_23c38;
    goto L_23c30;
L_23c30:
    s0 = v1 & 0xff; goto L_23c18;
L_23c38:
    t0 = 0;
    a0 = 12;
    v1 = 0;
    t3 = s0 & 0xffff;
    t1 = t1 - hi_23c2c + (u32)(unsigned long)ref_t32_data_daf24;
L_23c4c:
    v0 = t0 & 0xffff;
    v0 = (u32)v0 < (u32)(t3);
    branch = (v0 == 0); v0 = t1 + t0;
    if (branch) goto L_23c90;
    goto L_23c5c;
L_23c5c:
    a3 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = (u32)v1 < (u32)(a3);
    branch = (v0 == 0); t2 = v1;
    if (branch) goto L_23c70;
    goto L_23c6c;
L_23c6c:
    t2 = a3;
L_23c70:
    v0 = (u32)a3 < (u32)(a0);
    v1 = t2 & 0xff;
    branch = (v0 == 0); t2 = a0;
    if (branch) goto L_23c84;
    goto L_23c80;
L_23c80:
    t2 = a3;
L_23c84:
    a0 = t2 & 0xff;
    t0 = t0 + 1; goto L_23c4c;
L_23c90:
    v0 = (u32)s0 < (u32)(3);
    branch = (v0 == 0); t1 = hi_23c98;
    if (branch) goto L_23f70;
    goto L_23c9c;
L_23c9c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (236));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (176));
    a3 = 1024;
    t6 = v0 + 6;
    t3 = 0;
    t0 = 1024;
    t1 = 0;
L_23cb8:
    t2 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t5 = t1;
    t1 = (u32)t1 < (u32)(t2);
    if (t1 != 0) { t5 = t2; goto L_23ccc; }
    goto L_23ccc;
L_23ccc:
    t1 = t5 & 0xffff;
    t5 = t0;
    t0 = (u32)t2 < (u32)(t0);
    if (t0 != 0) { t5 = t2; goto L_23ce0; }
    goto L_23ce0;
L_23ce0:
    t2 = *(volatile u16 *)(unsigned long)(t4 + (0));
    t0 = t5 & 0xffff;
    t5 = t3;
    t3 = (u32)t3 < (u32)(t2);
    if (t3 != 0) { t5 = t2; goto L_23cf8; }
    goto L_23cf8;
L_23cf8:
    t3 = t5 & 0xffff;
    t5 = a3;
    a3 = (u32)t2 < (u32)(a3);
    if (a3 != 0) { t5 = t2; goto L_23d0c; }
    goto L_23d0c;
L_23d0c:
    v0 = v0 + 2;
    a3 = t5 & 0xffff;
    branch = (t6 != v0); t4 = t4 + 2;
    if (branch) goto L_23cb8;
    goto L_23d1c;
L_23d1c:
    v0 = hi_23d1c;
    *(volatile u16 *)(unsigned long)(v0 - hi_23d1c + (u32)(unsigned long)ref_t32_data_dbf28) = t1;
    v0 = v0 - hi_23d1c + (u32)(unsigned long)ref_t32_data_dbf28;
    *(volatile u16 *)(unsigned long)(v0 + (2)) = t0; goto L_23ebc;
L_23d30:
    a3 = *(volatile u32 *)(unsigned long)(s8 + (348));
    a0 = 1;
    branch = (a3 != a0); a0 = 12;
    if (branch) goto L_23f64;
    goto L_23d40;
L_23d40:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (428));
    a3 = 0;
    s0 = 0;
    v0 = v0 * a0;
    a0 = 100;
    v0 = v0 + 50;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    a0 = 0;
    v0 = lo;
    v0 = v0 & 0xffff;
L_23d68:
    t0 = (u32)a0 < (u32)(s6);
    if (t0 == 0) { v1 = (u32)s0 < (u32)(2); goto L_23da4; }
    goto L_23d74;
L_23d74:
    t0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    s0 = s0 + 1;
    s0 = s0 & 0xff;
    a3 = a3 + t0;
    a3 = a3 & 0xffff;
    t0 = (u32)v0 < (u32)(a3);
    branch = (t0 != 0); v1 = v1 + 4;
    if (branch) goto L_23da0;
    goto L_23d94;
L_23d94:
    a0 = a0 + 1;
    a0 = a0 & 0xffff; goto L_23d68;
L_23da0:
    v1 = (u32)s0 < (u32)(2);
L_23da4:
    v0 = 2;
    if (v1 != 0) s0 = v0;
L_23dac:
    v1 = s0 + -1;
    v0 = v1 << (0x2 & 31);
    v0 = s4 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    branch = (v0 != 0); t2 = hi_23dc0;
    if (branch) goto L_23dcc;
    goto L_23dc4;
L_23dc4:
    s0 = v1 & 0xff; goto L_23dac;
L_23dcc:
    t1 = 0;
    a0 = 12;
    v1 = 0;
    t0 = s0 & 0xffff;
    t2 = t2 - hi_23dc0 + (u32)(unsigned long)ref_t32_data_daf24;
L_23de0:
    v0 = t1 & 0xffff;
    v0 = (u32)v0 < (u32)(t0);
    branch = (v0 == 0); v0 = t2 + t1;
    if (branch) goto L_23e24;
    goto L_23df0;
L_23df0:
    a3 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = (u32)v1 < (u32)(a3);
    branch = (v0 == 0); t3 = v1;
    if (branch) goto L_23e04;
    goto L_23e00;
L_23e00:
    t3 = a3;
L_23e04:
    v0 = (u32)a3 < (u32)(a0);
    v1 = t3 & 0xff;
    branch = (v0 == 0); t3 = a0;
    if (branch) goto L_23e18;
    goto L_23e14;
L_23e14:
    t3 = a3;
L_23e18:
    a0 = t3 & 0xff;
    t1 = t1 + 1; goto L_23de0;
L_23e24:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (236));
    t5 = *(volatile u32 *)(unsigned long)(s8 + (176));
    a3 = 1024;
    t7 = v0 + 6;
    t3 = 0;
    t2 = 1024;
    t4 = 0;
L_23e40:
    t1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t6 = t4;
    t4 = (u32)t4 < (u32)(t1);
    if (t4 != 0) { t6 = t1; goto L_23e54; }
    goto L_23e54;
L_23e54:
    t4 = t6 & 0xffff;
    t6 = t2;
    t2 = (u32)t1 < (u32)(t2);
    if (t2 != 0) { t6 = t1; goto L_23e68; }
    goto L_23e68;
L_23e68:
    t1 = *(volatile u16 *)(unsigned long)(t5 + (0));
    t2 = t6 & 0xffff;
    t6 = t3;
    t3 = (u32)t3 < (u32)(t1);
    if (t3 != 0) { t6 = t1; goto L_23e80; }
    goto L_23e80;
L_23e80:
    t3 = t6 & 0xffff;
    t6 = a3;
    a3 = (u32)t1 < (u32)(a3);
    if (a3 != 0) { t6 = t1; goto L_23e94; }
    goto L_23e94;
L_23e94:
    v0 = v0 + 2;
    a3 = t6 & 0xffff;
    branch = (v0 != t7); t5 = t5 + 2;
    if (branch) goto L_23e40;
    goto L_23ea4;
L_23ea4:
    t5 = hi_23ea4;
    t1 = (u32)s0 < (u32)(3);
    branch = (t1 == 0); v0 = t5 - hi_23ea4 + (u32)(unsigned long)ref_t32_data_dbf28;
    if (branch) goto L_23ed0;
    goto L_23eb4;
L_23eb4:
    *(volatile u16 *)(unsigned long)(t5 - hi_23ea4 + (u32)(unsigned long)ref_t32_data_dbf28) = t4;
    *(volatile u16 *)(unsigned long)(v0 + (2)) = t2;
L_23ebc:
    v0 = hi_23ebc;
    *(volatile u16 *)(unsigned long)(v0 - hi_23ebc + (u32)(unsigned long)ref_t32_data_dbf14) = a3;
    v0 = v0 - hi_23ebc + (u32)(unsigned long)ref_t32_data_dbf14;
    *(volatile u16 *)(unsigned long)(v0 + (2)) = t3; goto L_23f6c;
L_23ed0:
    t1 = 3;
    if (s0 == t1) { t1 = hi_23ed8; goto L_23f70; }
    goto L_23edc;
L_23edc:
    t3 = (u32)t1 < (u32)(t0);
    branch = (t3 == 0); v0 = v0 + 2;
    if (branch) goto L_23ef8;
    goto L_23ee8;
L_23ee8:
    t1 = t1 + 1;
    *(volatile u16 *)(unsigned long)(v0 + (4)) = t2;
    t1 = t1 & 0xffff; goto L_23edc;
L_23ef8:
    t3 = hi_23ef8;
    v0 = 0;
    t1 = s0 + -3;
    t3 = t3 - hi_23ef8 + (u32)(unsigned long)ref_t32_data_dbf14;
L_23f08:
    t4 = (s32)v0 < (s32)(t1);
    branch = (t4 == 0); t2 = t3;
    if (branch) goto L_23f2c;
    goto L_23f14;
L_23f14:
    t2 = v0 << (0x1 & 31);
    t2 = t3 + t2;
    v0 = v0 + 1;
    *(volatile u16 *)(unsigned long)(t2 + (0)) = a3;
    v0 = v0 & 0xffff; goto L_23f08;
L_23f2c:
    v0 = t0 + -3;
L_23f30:
    v0 = v0 & 0xffff;
    a3 = (u32)v0 < (u32)(t0);
    branch = (a3 == 0); t3 = *(volatile u32 *)(unsigned long)(s8 + (176));
    if (branch) goto L_23f6c;
    goto L_23f40;
L_23f40:
    a3 = v0 - t1;
    a3 = a3 << (0x1 & 31);
    a3 = t3 + a3;
    t3 = *(volatile u16 *)(unsigned long)(a3 + (0));
    a3 = v0 << (0x1 & 31);
    a3 = t2 + a3;
    *(volatile u16 *)(unsigned long)(a3 + (0)) = t3;
    v0 = v0 + 1; goto L_23f30;
L_23f64:
    v1 = 0;
    s0 = 3;
L_23f6c:
    t1 = hi_23f6c;
L_23f70:
    t4 = hi_23f70;
    t2 = 1024;
    t3 = hi_23f78;
    t0 = 0;
    t1 = t1 - hi_23f6c + (u32)(unsigned long)ref_t32_data_daf10;
    t4 = t4 - hi_23f70 + (u32)(unsigned long)ref_t32_data_dbf14;
    t7 = t2 - a2;
    t3 = t3 - hi_23f78 + (u32)(unsigned long)ref_t32_data_dbf28;
    t5 = 20;
L_23f94:
    v0 = t4 + t0;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = t3 + t0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t6 = t1 + t0;
    t0 = t0 + 2;
    product = (s64)(s32)v0 * (s32)a2; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)t7); lo = product; hi = product >> 32;
    v0 = lo;
    if (v0 == 0x80000000U && t2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t2) { lo = (s32)v0 / (s32)t2; hi = (s32)v0 % (s32)t2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    *(volatile u16 *)(unsigned long)(t6 + (0)) = v0;
    branch = (t0 != t5); t6 = t1;
    if (branch) goto L_23f94;
    goto L_23fcc;
L_23fcc:
    v0 = (u32)v1 < (u32)(a0);
    if (v0 == 0) { v0 = v1 - a0; goto L_23fdc; }
    goto L_23fd8;
L_23fd8:
    v0 = a0 - v1;
L_23fdc:
    v0 = v0 & 0xff;
    v0 = (u32)v0 < (u32)(2);
    branch = (v0 == 0); v1 = 1;
    if (branch) goto L_2400c;
    goto L_23fec;
L_23fec:
    v0 = 0;
    a2 = 1024;
    v1 = 20;
L_23ff8:
    a0 = t6 + v0;
    v0 = v0 + 2;
    branch = (v0 != v1); *(volatile u16 *)(unsigned long)(a0 + (0)) = a2;
    if (branch) goto L_23ff8;
    goto L_24008;
L_24008:
    v1 = 0;
L_2400c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (148));
    *(volatile u16 *)(unsigned long)(v0 + (2)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (440));
    v0 = 1;
    branch = (v1 == v0); v0 = s0 << (0x2 & 31);
    if (branch) goto L_24044;
    goto L_24024;
L_24024:
    *(volatile u32 *)(unsigned long)(s8 + (108)) = v0;
    t2 = 0;
    v0 = 0;
    t1 = 0;
    t0 = 0;
    a3 = 0;
    v1 = 0; goto L_24084;
L_24044:
    a0 = hi_24044;
    a2 = 1024;
    a3 = a1 << (0xa & 31);
    v1 = t6;
    a0 = a0 - hi_24044 + (u32)(unsigned long)ref_t32_data_daf24;
    a1 = a2 - a1;
L_2405c:
    v0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v1 = v1 + 2;
    t0 = a1 * v0;
    v0 = t0 + a3;
    if (v0 == 0x80000000U && a2 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a2) { lo = (s32)v0 / (s32)a2; hi = (s32)v0 % (s32)a2; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    v0 = lo;
    branch = (v1 != a0); *(volatile u16 *)(unsigned long)(v1 + (-2)) = v0;
    if (branch) goto L_2405c;
    goto L_2407c;
L_2407c:
    v0 = s0 << (0x2 & 31); goto L_24024;
L_24084:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    branch = (v0 == a0); a0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    if (branch) goto L_240e0;
    goto L_24090;
L_24090:
    a0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = v1 + a0;
    a0 = s4 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a3 = a3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t0 = t0 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    a0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t1 = t1 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    a0 = a0 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 + 4;
    t2 = t2 + a0; goto L_24084;
L_240e0:
    a1 = hi_240e0;
    a2 = s0 + -1;
    a1 = a1 - hi_240e0 + (u32)(unsigned long)ref_t32_data_daf24;
L_240ec:
    branch = (a2 == 0); a0 = s8 + 32;
    if (branch) goto L_24140;
    goto L_240f4;
L_240f4:
    v0 = a1;
L_240f8:
    t3 = v0 - a1;
    t3 = (u32)t3 < (u32)(a2);
    if (t3 == 0) { a2 = a2 + -1; goto L_240ec; }
    goto L_24108;
L_24108:
    t3 = *(volatile u8 *)(unsigned long)(v0 + (0));
    t4 = *(volatile u8 *)(unsigned long)(v0 + (1));
    t5 = (u32)t4 < (u32)(t3);
    if (t5 == 0) { v0 = v0 + 1; goto L_24138; }
    goto L_2411c;
L_2411c:
    *(volatile u8 *)(unsigned long)(v0 + (0)) = t4;
    *(volatile u8 *)(unsigned long)(v0 + (1)) = t3;
    t4 = *(volatile u8 *)(unsigned long)(a0 + (1));
    t3 = *(volatile u8 *)(unsigned long)(a0 + (0));
    *(volatile u8 *)(unsigned long)(a0 + (0)) = t4;
    *(volatile u8 *)(unsigned long)(a0 + (1)) = t3;
    v0 = v0 + 1;
L_24138:
    a0 = a0 + 1; goto L_240f8;
L_24140:
    *(volatile u32 *)(unsigned long)(s8 + (76)) = 0;
    branch = (v1 == 0); *(volatile u32 *)(unsigned long)(s8 + (72)) = 0;
    if (branch) goto L_24508;
    goto L_2414c;
L_2414c:
    if (a3 == 0) { a2 = *(volatile u32 *)(unsigned long)(s8 + (120)); goto L_2450c; }
    goto L_24154;
L_24154:
    if (t0 == 0) { a2 = *(volatile u32 *)(unsigned long)(s8 + (120)); goto L_2450c; }
    goto L_2415c;
L_2415c:
    if (t1 == 0) { a2 = *(volatile u32 *)(unsigned long)(s8 + (120)); goto L_2450c; }
    goto L_24164;
L_24164:
    if (t2 == 0) { a2 = *(volatile u32 *)(unsigned long)(s8 + (120)); goto L_2450c; }
    goto L_2416c;
L_2416c:
    v0 = v1 >> (0x1 & 31);
    a0 = hi_24170;
    a0 = a0 - hi_24170 + (u32)(unsigned long)ref_t32_data_dc02c;
    *(volatile u32 *)(unsigned long)(s8 + (112)) = v0;
    v0 = a3 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (124)) = v0;
    *(volatile u32 *)(unsigned long)(s8 + (156)) = a0;
    v0 = t0 >> (0x1 & 31);
    a0 = hi_2418c;
    a0 = a0 - hi_2418c + (u32)(unsigned long)ref_t32_data_daec0;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = v0;
    s6 = *(volatile u8 *)(unsigned long)(s8 + (424));
    v0 = t1 >> (0x1 & 31);
    *(volatile u32 *)(unsigned long)(s8 + (148)) = v0;
    s2 = hi_241a4;
    v0 = t2 >> (0x1 & 31);
    s3 = hi_241ac;
    *(volatile u32 *)(unsigned long)(s8 + (160)) = a0;
    a0 = hi_241b4;
    *(volatile u32 *)(unsigned long)(s8 + (152)) = v0;
    s2 = s2 - hi_241a4 + (u32)(unsigned long)ref_t32_data_dae70;
    s3 = s3 - hi_241ac + (u32)(unsigned long)ref_t32_data_daee8;
    s1 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (104)) = 0;
    t5 = 0;
    s7 = 0;
    v0 = 0;
    t4 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (164)) = a0;
L_241e0:
    a0 = *(volatile u32 *)(unsigned long)(s8 + (108));
    branch = (s1 == a0); a0 = *(volatile u32 *)(unsigned long)(s8 + (136));
    if (branch) goto L_244ac;
    goto L_241ec;
L_241ec:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (112));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (148));
    a0 = a0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    ra = s8 + 32;
    t9 = t6;
    a0 = a0 << (0xa & 31);
    a0 = a0 + a1;
    if (v1) { lo = a0 / v1; hi = a0 % v1; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s3 + (0)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (156));
    a0 = a0 + s1;
    a1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (124));
    a1 = a1 << (0xa & 31);
    a1 = a1 + a0;
    if (a3) { lo = a1 / a3; hi = a1 % a3; } else { lo = ~0U; hi = a1; }
    a0 = *(volatile u32 *)(unsigned long)(s8 + (128));
    a0 = a0 + s1;
    a2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (144));
    a2 = a2 << (0xa & 31);
    a2 = a2 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (160));
    t7 = a0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (132));
    a0 = a0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 << (0xa & 31);
    a0 = a0 + t3;
    t3 = *(volatile u32 *)(unsigned long)(s8 + (152));
    a1 = lo;
    if (t0) { lo = a2 / t0; hi = a2 % t0; } else { lo = ~0U; hi = a2; }
    a2 = lo;
    if (t1) { lo = a0 / t1; hi = a0 % t1; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(t7 + (0)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (164));
    s4 = a0 - hi_241b4 + (u32)(unsigned long)ref_t32_data_dae98;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (140));
    s4 = s4 + s1;
    a0 = a0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 << (0xa & 31);
    a0 = a0 + t3;
    if (t2) { lo = a0 / t2; hi = a0 % t2; } else { lo = ~0U; hi = a0; }
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s4 + (0)) = a0;
    a0 = ra;
L_242b4:
    t8 = a0 - ra;
    t8 = (u32)t8 < (u32)(s0);
    if (t8 == 0) { a0 = *(volatile u32 *)(unsigned long)(s8 + (432)); goto L_242e0; }
    goto L_242c4;
L_242c4:
    t8 = *(volatile u8 *)(unsigned long)(a0 + (0));
    branch = (t8 != t4); a0 = a0 + 1;
    if (branch) goto L_242d8;
    goto L_242d0;
L_242d0:
    t8 = *(volatile u16 *)(unsigned long)(t9 + (0));
    *(volatile u32 *)(unsigned long)(s2 + (0)) = t8;
L_242d8:
    t9 = t9 + 2; goto L_242b4;
L_242e0:
    branch = (a0 != 0); a0 = *(volatile u32 *)(unsigned long)(s8 + (436));
    if (branch) goto L_242f4;
    goto L_242e8;
L_242e8:
    a0 = 1024;
    *(volatile u32 *)(unsigned long)(s3 + (0)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s8 + (436));
L_242f4:
    branch = (a0 != 0); a0 = 1;
    if (branch) goto L_24308;
    goto L_242fc;
L_242fc:
    a0 = 1024;
    *(volatile u32 *)(unsigned long)(s2 + (0)) = a0;
    a0 = 1;
L_24308:
    branch = (s6 != a0); a0 = 2;
    if (branch) goto L_24318;
    goto L_24310;
L_24310:
    v0 = a1 << (0x2 & 31); goto L_24444;
L_24318:
    branch = (s6 != a0); a0 = 3;
    if (branch) goto L_2432c;
    goto L_24320;
L_24320:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    v0 = v0 << (0x2 & 31); goto L_24444;
L_2432c:
    branch = (s6 != a0); a0 = 4;
    if (branch) goto L_243a8;
    goto L_24334;
L_24334:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    a0 = 20;
    *(volatile u32 *)(unsigned long)(s8 + (220)) = t6;
    a2 = a2 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    *(volatile u32 *)(unsigned long)(s8 + (216)) = t5;
    *(volatile u32 *)(unsigned long)(s8 + (180)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (200)) = t1;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (176)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (172)) = v1;
    *(volatile u32 *)(unsigned long)(s8 + (168)) = t4;
    a1 = a1 * v0;
    a2 = a2 + 8;
    v0 = hi_2436c;
    a2 = a2 >> (0x4 & 31);
    v0 = v0 - hi_2436c + (u32)(unsigned long)ref_fix_point_mult2_32;
    a1 = a1 + 8;
    callee = v0; a1 = a1 >> (0x4 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_24384;
L_24384:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (168));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (172));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (176));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (184));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (200));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (180));
    t5 = *(volatile u32 *)(unsigned long)(s8 + (216));
    t6 = *(volatile u32 *)(unsigned long)(s8 + (220)); goto L_24444;
L_243a8:
    if (s6 != a0) { a0 = *(volatile u32 *)(unsigned long)(s4 + (0)); goto L_24448; }
    goto L_243b0;
L_243b0:
    v0 = *(volatile u32 *)(unsigned long)(s2 + (0));
    t8 = hi_243b4;
    t8 = t8 - hi_243b4 + (u32)(unsigned long)ref_fix_point_mult2_32;
    a2 = a2 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s3 + (0));
    a0 = 20;
    *(volatile u32 *)(unsigned long)(s8 + (228)) = t6;
    *(volatile u32 *)(unsigned long)(s8 + (220)) = t5;
    *(volatile u32 *)(unsigned long)(s8 + (216)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (180)) = t1;
    *(volatile u32 *)(unsigned long)(s8 + (200)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (184)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (176)) = v1;
    *(volatile u32 *)(unsigned long)(s8 + (172)) = t4;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = t7;
    *(volatile u32 *)(unsigned long)(s8 + (168)) = t8;
    a1 = a1 * v0;
    a2 = a2 + 8;
    a2 = a2 >> (0x4 & 31);
    a1 = a1 + 8;
    callee = t8; a1 = a1 >> (0x4 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_24408;
L_24408:
    t7 = *(volatile u32 *)(unsigned long)(s8 + (224));
    t8 = *(volatile u32 *)(unsigned long)(s8 + (168));
    a1 = v0;
    a2 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a0 = 12;
    callee = t8; a2 = a2 << (0x2 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_24424;
L_24424:
    t6 = *(volatile u32 *)(unsigned long)(s8 + (228));
    t5 = *(volatile u32 *)(unsigned long)(s8 + (220));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (216));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (180));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (200));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (184));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (176));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (172));
L_24444:
    a0 = *(volatile u32 *)(unsigned long)(s4 + (0));
L_24448:
    t4 = t4 + 1;
    t4 = t4 & 0xffff;
    v0 = v0 * a0;
    a0 = hi_24454;
    a0 = a0 - hi_24454 + (u32)(unsigned long)ref_t32_data_dafd0;
    a0 = a0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    s2 = s2 + 4;
    s3 = s3 + 4;
    v0 = v0 + 512;
    v0 = v0 >> (0xa & 31);
    a1 = v0 * a0;
    a0 = hi_24478;
    a0 = a0 - hi_24478 + (u32)(unsigned long)ref_t32_data_dafa8;
    a0 = a0 + s1;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    s7 = s7 + v0;
    s1 = s1 + 4;
    t5 = a1 + t5;
    a1 = *(volatile u32 *)(unsigned long)(s8 + (104));
    lo = a1;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)a0); lo = product; hi = product >> 32;
    a0 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (104)) = a0; goto L_241e0;
L_244ac:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    s0 = hi_244b0;
    a1 = t5;
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = s0 - hi_244b0 + (u32)(unsigned long)ref_fix_point_mult2_32;
    callee = s0; a0 = 4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_244c8;
L_244c8:
    s1 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (104));
    a0 = 4;
    callee = s0; a2 = *(volatile u32 *)(unsigned long)(v0 + (4));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_244e0;
L_244e0:
    branch = (s6 == 0); a2 = *(volatile u32 *)(unsigned long)(s8 + (120));
    if (branch) goto L_2450c;
    goto L_244e8;
L_244e8:
    branch = (s7 == 0); a1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    if (branch) goto L_24510;
    goto L_244f0;
L_244f0:
    if (s7) { lo = s1 / s7; hi = s1 % s7; } else { lo = ~0U; hi = s1; }
    v1 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (116)) = v1;
    if (s7) { lo = v0 / s7; hi = v0 % s7; } else { lo = ~0U; hi = v0; }
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (120)) = v0;
L_24508:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (120));
L_2450c:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (116));
L_24510:
    v0 = hi_24510;
    v0 = v0 - hi_24510 + (u32)(unsigned long)ref_Tiziano_Awb_Ct_Cal;
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_24520;
L_24520:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (516));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (116));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (120));
    *(volatile u32 *)(unsigned long)(v0 + (4)) = v1;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (520));
    *(volatile u32 *)(unsigned long)(v0 + (0)) = 0;
    *(volatile u32 *)(unsigned long)(v0 + (4)) = 0; goto L_2454c;
L_24544:
    t2 = t2 + 1; goto L_22bcc;
L_2454c:
    sp = s8;
L_24550:
    ra = *(volatile u32 *)(unsigned long)(sp + (508));
    s8 = *(volatile u32 *)(unsigned long)(sp + (504));
    s7 = *(volatile u32 *)(unsigned long)(sp + (500));
    s6 = *(volatile u32 *)(unsigned long)(sp + (496));
    s5 = *(volatile u32 *)(unsigned long)(sp + (492));
    s4 = *(volatile u32 *)(unsigned long)(sp + (488));
    s3 = *(volatile u32 *)(unsigned long)(sp + (484));
    s2 = *(volatile u32 *)(unsigned long)(sp + (480));
    s1 = *(volatile u32 *)(unsigned long)(sp + (476));
    s0 = *(volatile u32 *)(unsigned long)(sp + (472));
    sp = sp + 512;
    return ((u64)v1 << 32) | v0;
}
