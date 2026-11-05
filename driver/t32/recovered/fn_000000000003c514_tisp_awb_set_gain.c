/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
extern unsigned char ref_fix_point_mult2_32[] __asm__("fix_point_mult2_32");
extern unsigned char ref_tisp_awb_gain_reg[] __asm__("tisp_awb_gain_reg");
extern unsigned char ref_t32_data_d03a0[] __asm__("t32_data_d03a0");
extern unsigned char ref_tisp_reg_write[] __asm__("tisp_reg_write");
extern unsigned char ref_system_reg_set_awb_trig[] __asm__("system_reg_set_awb_trig");
extern unsigned char ref_system_reg_write[] __asm__("system_reg_write");
u64 tisp_awb_set_gain(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[92] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3c514 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    const u32 hi_3c558 = ((u32)(unsigned long)ref_fix_point_mult2_32 + 0x8000U) & 0xffff0000U;
    const u32 hi_3c810 = ((u32)(unsigned long)ref_tisp_awb_gain_reg + 0x8000U) & 0xffff0000U;
    const u32 hi_3c82c = ((u32)(unsigned long)ref_t32_data_d03a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_3c844 = ((u32)(unsigned long)ref_tisp_reg_write + 0x8000U) & 0xffff0000U;
    const u32 hi_3c878 = ((u32)(unsigned long)ref_system_reg_set_awb_trig + 0x8000U) & 0xffff0000U;
    const u32 hi_3c890 = ((u32)(unsigned long)ref_system_reg_write + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[28];
L_3c514:
    v0 = hi_3c514;
    sp = sp + -112;
    t2 = a0 << (0x2 & 31);
    v0 = v0 - hi_3c514 + (u32)(unsigned long)ref_t32_data_e16b4;
    t2 = t2 + v0;
    *(volatile u32 *)(unsigned long)(sp + (108)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (84)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (104)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (100)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (96)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (92)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (88)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (80)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (76)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (72)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(t2 + (0));
    *(volatile u32 *)(unsigned long)(sp + (64)) = t2;
    t4 = hi_3c558;
    s0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s2 = *(volatile u32 *)(unsigned long)(v0 + (12));
    s1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    t1 = *(volatile u32 *)(unsigned long)(s0 + (3064));
    t0 = *(volatile u32 *)(unsigned long)(s0 + (3068));
    a3 = *(volatile u32 *)(unsigned long)(s0 + (3080));
    t7 = *(volatile u32 *)(unsigned long)(s0 + (3088));
    a1 = *(volatile u32 *)(unsigned long)(s0 + (24));
    t5 = *(volatile u16 *)(unsigned long)(s0 + (3306));
    s4 = *(volatile u16 *)(unsigned long)(s0 + (3308));
    *(volatile u32 *)(unsigned long)(sp + (60)) = t1;
    *(volatile u32 *)(unsigned long)(sp + (56)) = t0;
    *(volatile u32 *)(unsigned long)(sp + (52)) = a3;
    *(volatile u32 *)(unsigned long)(sp + (48)) = t7;
    *(volatile u32 *)(unsigned long)(sp + (24)) = a1;
    s7 = *(volatile u32 *)(unsigned long)(s0 + (3072));
    s6 = *(volatile u32 *)(unsigned long)(s0 + (3076));
    s8 = *(volatile u32 *)(unsigned long)(s0 + (3084));
    s5 = *(volatile u32 *)(unsigned long)(s0 + (3092));
    v0 = *(volatile u32 *)(unsigned long)(s0 + (28));
    a2 = *(volatile u32 *)(unsigned long)(s0 + (52));
    t6 = t5 + -10;
    t4 = t4 - hi_3c558 + (u32)(unsigned long)ref_fix_point_mult2_32;
    a2 = a2 << (t6 & 31);
    a1 = a1 << (s4 & 31);
    s3 = a0;
    a0 = t5;
    *(volatile u32 *)(unsigned long)(sp + (44)) = t6;
    *(volatile u32 *)(unsigned long)(sp + (40)) = t5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = t4;
    callee = t4; *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c5dc;
L_3c5dc:
    a0 = 1;
    a2 = *(volatile u32 *)(unsigned long)(s0 + (56));
    t6 = *(volatile u32 *)(unsigned long)(sp + (44));
    a1 = *(volatile u32 *)(unsigned long)(sp + (28));
    t5 = *(volatile u32 *)(unsigned long)(sp + (40));
    v1 = s4 + -1;
    v1 = a0 << (v1 & 31);
    t4 = *(volatile u32 *)(unsigned long)(sp + (36));
    v0 = v0 + v1;
    v0 = v0 >> (s4 & 31);
    a2 = a2 << (t6 & 31);
    a1 = a1 << (s4 & 31);
    a0 = t5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = v1;
    callee = t4; *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c61c;
L_3c61c:
    v1 = *(volatile u32 *)(unsigned long)(sp + (32));
    t3 = 0x2U << 16;
    a2 = *(volatile u32 *)(unsigned long)(sp + (24));
    v0 = v1 + v0;
    v1 = s1 + t3;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (-23452));
    v0 = v0 >> (s4 & 31);
    a1 = a2 & 0xffff;
    *(volatile u16 *)(unsigned long)(v1 + (-23448)) = a0;
    a0 = *(volatile u16 *)(unsigned long)(v1 + (-23450));
    *(volatile u16 *)(unsigned long)(v1 + (-23452)) = a1;
    t4 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(v1 + (-23446)) = a0;
    a0 = v0 & 0xffff;
    *(volatile u16 *)(unsigned long)(v1 + (-23450)) = a0;
    *(volatile u16 *)(unsigned long)(s2 + (4282)) = a1;
    *(volatile u16 *)(unsigned long)(s2 + (4284)) = a0;
    a1 = a2 & 0xffff;
    a0 = 0x1U << 16;
    if (a0 == 0x80000000U && a1 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a1) { lo = (s32)a0 / (s32)a1; hi = (s32)a0 % (s32)a1; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    t7 = *(volatile u32 *)(unsigned long)(sp + (48));
    a3 = *(volatile u32 *)(unsigned long)(sp + (52));
    t0 = *(volatile u32 *)(unsigned long)(sp + (56));
    t1 = *(volatile u32 *)(unsigned long)(sp + (60));
    t2 = *(volatile u32 *)(unsigned long)(sp + (64));
    a1 = lo;
    a1 = a1 & 0xffff;
    *(volatile u16 *)(unsigned long)(s2 + (4274)) = a1;
    if (a0 == 0x80000000U && t4 == ~0U) { lo = 0x80000000U; hi = 0; } else if (t4) { lo = (s32)a0 / (s32)t4; hi = (s32)a0 % (s32)t4; } else { lo = (s32)a0 < 0 ? 1 : ~0U; hi = a0; }
    a1 = a1 << (0x2 & 31);
    *(volatile u16 *)(unsigned long)(s2 + (144)) = a1;
    a0 = lo;
    a0 = a0 & 0xffff;
    *(volatile u16 *)(unsigned long)(s2 + (4276)) = a0;
    a0 = a0 << (0x2 & 31);
    *(volatile u16 *)(unsigned long)(s2 + (146)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (44));
    *(volatile u16 *)(unsigned long)(s2 + (148)) = a0;
    a0 = *(volatile u8 *)(unsigned long)(v1 + (-23474));
    a1 = a0 + -1;
    a1 = (u32)a1 < (u32)(8);
    branch = (a1 == 0); a1 = 9;
    if (branch) goto L_3c6e4;
    goto L_3c6cc;
L_3c6cc:
    v0 = *(volatile u16 *)(unsigned long)(v1 + (-23468));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(v1 + (-23466));
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (-23472)); goto L_3c730;
L_3c6e4:
    if (a0 != a1) { v0 = 10; goto L_3c718; }
    goto L_3c6ec;
L_3c6ec:
    a0 = *(volatile u16 *)(unsigned long)(v1 + (-23468));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (-23466));
    a0 = a0 + 32;
    v1 = v1 + 32;
    a0 = a0 * a2;
    v0 = v1 * v0;
    a0 = a0 >> (0x6 & 31);
    *(volatile u32 *)(unsigned long)(sp + (24)) = a0;
    v0 = v0 >> (0x6 & 31);
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0; goto L_3c734;
L_3c718:
    if (a0 != v0) { v1 = *(volatile u16 *)(unsigned long)(s2 + (4266)); goto L_3c738; }
    goto L_3c720;
L_3c720:
    v0 = *(volatile u32 *)(unsigned long)(t2 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = v0 + t3;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (-11156));
L_3c730:
    *(volatile u32 *)(unsigned long)(s0 + (44)) = v0;
L_3c734:
    v1 = *(volatile u16 *)(unsigned long)(s2 + (4266));
L_3c738:
    v0 = 1;
    if (v1 != v0) { v0 = *(volatile u32 *)(unsigned long)(s0 + (44)); goto L_3c760; }
    goto L_3c744;
L_3c744:
    v0 = *(volatile u16 *)(unsigned long)(s2 + (4268));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s2 + (4270));
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(s2 + (4272));
    *(volatile u32 *)(unsigned long)(s0 + (44)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s0 + (44));
L_3c760:
    *(volatile u16 *)(unsigned long)(s2 + (4290)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s0 + (44));
    v0 = *(volatile u32 *)(unsigned long)(s1 + (28760));
    a0 = (u32)v0 < (u32)(v1);
    if (a0 == 0) { v0 = v0 - v1; goto L_3c77c; }
    goto L_3c778;
L_3c778:
    v0 = v1 - v0;
L_3c77c:
    v0 = (u32)v0 < (u32)(200);
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(s1 + (28760)) = v1; goto L_3c7a4; }
    goto L_3c788;
L_3c788:
    v0 = 0x2U << 16;
    v0 = s1 + v0;
    a0 = *(volatile u8 *)(unsigned long)(v0 + (-23476));
    v0 = 1;
    branch = (a0 != v0); v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    if (branch) goto L_3c7dc;
    goto L_3c7a0;
L_3c7a0:
    *(volatile u32 *)(unsigned long)(s1 + (28760)) = v1;
L_3c7a4:
    v0 = *(volatile u32 *)(unsigned long)(s0 + (44));
    s5 = (u32)v0 < (u32)(s5);
    branch = (s5 != 0); s4 = (u32)t7 < (u32)(v0);
    if (branch) goto L_3c7c0;
    goto L_3c7b4;
L_3c7b4:
    *(volatile u32 *)(unsigned long)(s1 + (29792)) = t1;
    *(volatile u32 *)(unsigned long)(s1 + (29796)) = t0; goto L_3c7d8;
L_3c7c0:
    if (s4 != 0) { *(volatile u32 *)(unsigned long)(s1 + (29792)) = s7; goto L_3c7d4; }
    goto L_3c7c8;
L_3c7c8:
    *(volatile u32 *)(unsigned long)(s1 + (29792)) = a3;
    *(volatile u32 *)(unsigned long)(s1 + (29796)) = s8; goto L_3c7d8;
L_3c7d4:
    *(volatile u32 *)(unsigned long)(s1 + (29796)) = s6;
L_3c7d8:
    v0 = *(volatile u32 *)(unsigned long)(sp + (24));
L_3c7dc:
    v1 = *(volatile u32 *)(unsigned long)(s1 + (29792));
    a1 = sp + 16;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + v1;
    v0 = v0 + -1024;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    v1 = *(volatile u32 *)(unsigned long)(s1 + (29796));
    a0 = sp + 24;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + v1;
    v0 = v0 + -1024;
    *(volatile u32 *)(unsigned long)(sp + (28)) = v0;
    v0 = hi_3c810;
    v0 = v0 - hi_3c810 + (u32)(unsigned long)ref_tisp_awb_gain_reg;
    callee = v0; s2 = 0x2U << 16;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c820;
L_3c820:
    v0 = s1 + s2;
    v0 = *(volatile u8 *)(unsigned long)(v0 + (-23475));
    branch = (v0 != 0); s4 = hi_3c82c;
    if (branch) goto L_3c8b8;
    goto L_3c830;
L_3c830:
    a1 = *(volatile u8 *)(unsigned long)(s4 - hi_3c82c + (u32)(unsigned long)ref_t32_data_d03a0);
    v1 = 581;
    a2 = *(volatile u32 *)(unsigned long)(sp + (16));
    v0 = 24640;
    if (a1 != 0) v0 = v1;
    s0 = hi_3c844;
    a1 = v0;
    s0 = s0 - hi_3c844 + (u32)(unsigned long)ref_tisp_reg_write;
    callee = s0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c858;
L_3c858:
    a1 = *(volatile u8 *)(unsigned long)(s4 - hi_3c82c + (u32)(unsigned long)ref_t32_data_d03a0);
    v1 = 582;
    a2 = *(volatile u32 *)(unsigned long)(sp + (20));
    v0 = 24644;
    if (a1 != 0) v0 = v1;
    a1 = v0;
    callee = s0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c878;
L_3c878:
    v0 = hi_3c878;
    a1 = s3;
    v0 = v0 - hi_3c878 + (u32)(unsigned long)ref_system_reg_set_awb_trig;
    callee = v0; a0 = 2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c88c;
L_3c88c:
    a1 = *(volatile u32 *)(unsigned long)(sp + (16));
    s0 = hi_3c890;
    s0 = s0 - hi_3c890 + (u32)(unsigned long)ref_system_reg_write;
    callee = s0; a0 = s2 | 0xa040;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c8a0;
L_3c8a0:
    a1 = *(volatile u32 *)(unsigned long)(sp + (20));
    callee = s0; a0 = s2 | 0xa044;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c8ac;
L_3c8ac:
    a1 = 1;
    callee = s0; a0 = s2 | 0xa010;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_3c8b8;
L_3c8b8:
    v0 = 0x2U << 16;
    s1 = s1 + v0;
    *(volatile u8 *)(unsigned long)(s1 + (-23476)) = 0;
    ra = *(volatile u32 *)(unsigned long)(sp + (108));
    s8 = *(volatile u32 *)(unsigned long)(sp + (104));
    s7 = *(volatile u32 *)(unsigned long)(sp + (100));
    s6 = *(volatile u32 *)(unsigned long)(sp + (96));
    s5 = *(volatile u32 *)(unsigned long)(sp + (92));
    s4 = *(volatile u32 *)(unsigned long)(sp + (88));
    s3 = *(volatile u32 *)(unsigned long)(sp + (84));
    s2 = *(volatile u32 *)(unsigned long)(sp + (80));
    s1 = *(volatile u32 *)(unsigned long)(sp + (76));
    s0 = *(volatile u32 *)(unsigned long)(sp + (72));
    sp = sp + 112;
    return ((u64)v1 << 32) | v0;
}
