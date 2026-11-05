/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e28f0[] __asm__("t32_data_e28f0");
extern unsigned char ref_div64_u64[] __asm__("div64_u64");
extern unsigned char ref_tisp_ccm_sub_interp[] __asm__("tisp_ccm_sub_interp");
u64 tisp_ccm_interp_by_ev(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[74] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8bf64 = ((u32)(unsigned long)ref_t32_data_e28f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8c428 = (((u32)(unsigned long)ref_div64_u64 + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_8c444 = ((u32)(unsigned long)ref_tisp_ccm_sub_interp + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[10];
    stack[14] = arg4;
L_8bf5c:
    sp = sp + -40;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    s1 = hi_8bf64;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    s1 = s1 - hi_8bf64 + (u32)(unsigned long)ref_t32_data_e28f0;
    s2 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (36)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = s2 + s1;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t2 = *(volatile u8 *)(unsigned long)(sp + (56));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = *(volatile u32 *)(unsigned long)(t1 + (4));
    a1 = (s32)a3 < (s32)(v0);
    branch = (a1 != 0); a0 = *(volatile u32 *)(unsigned long)(t1 + (0));
    if (branch) goto L_8bfb8;
    goto L_8bfa4;
L_8bfa4:
    branch = (v0 != a3); a1 = a2 - a0;
    if (branch) goto L_8bfc8;
    goto L_8bfac;
L_8bfac:
    a1 = (u32)a2 < (u32)(a0);
    if (a1 == 0) { a1 = a2 - a0; goto L_8bfc8; }
    goto L_8bfb8;
L_8bfb8:
    a1 = a0 - a2;
    t0 = (u32)a0 < (u32)(a1);
    a0 = v0 - a3; goto L_8bfd0;
L_8bfc8:
    t0 = (u32)a2 < (u32)(a1);
    a0 = a3 - v0;
L_8bfd0:
    v0 = a0 - t0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t3 = *(volatile u32 *)(unsigned long)(v1 + (16));
    a0 = (s32)v0 < (s32)(1);
    t4 = *(volatile u8 *)(unsigned long)(t0 + (864));
    v0 = -1;
    t6 = 1;
    if (a0 != 0) v0 = a1;
    t5 = *(volatile int8_t *)(unsigned long)(t3 + (0));
    a1 = *(volatile u8 *)(unsigned long)(t0 + (865));
    branch = (t4 == t6); a0 = 1;
    if (branch) goto L_8c018;
    goto L_8c000;
L_8c000:
    if (t4 != 0) { a0 = (u32)t5 < (u32)(1); goto L_8c018; }
    goto L_8c008;
L_8c008:
    a1 = (u32)a1 < (u32)(2);
    if (a1 != 0) { a1 = 1; goto L_8c01c; }
    goto L_8c014;
L_8c014:
    a0 = (u32)t5 < (u32)(1);
L_8c018:
    a1 = 1;
L_8c01c:
    branch = (a0 == 0); a1 = a1 - a0;
    if (branch) goto L_8c030;
    goto L_8c024;
L_8c024:
    t4 = *(volatile u8 *)(unsigned long)(t0 + (863));
    if (t4 == 0) { a2 = *(volatile u8 *)(unsigned long)(t0 + (866)); goto L_8c048; }
    goto L_8c030;
L_8c030:
    if (a1 == 0) { a0 = *(volatile u32 *)(unsigned long)(t0 + (52)); goto L_8c0fc; }
    goto L_8c038;
L_8c038:
    t3 = *(volatile int8_t *)(unsigned long)(t3 + (1));
    if (t3 != 0) { a0 = *(volatile u32 *)(unsigned long)(t0 + (52)); goto L_8c0fc; }
    goto L_8c044;
L_8c044:
    a2 = *(volatile u8 *)(unsigned long)(t0 + (866));
L_8c048:
    a3 = *(volatile u8 *)(unsigned long)(t0 + (867));
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    v0 = 1024;
    *(volatile u16 *)(unsigned long)(t0 + (80)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (82)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (84)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (86)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (88)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (90)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (92)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (94)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (96)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (98)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    *(volatile u16 *)(unsigned long)(t0 + (100)) = v0;
    t0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    branch = (a1 == 0); *(volatile u16 *)(unsigned long)(t0 + (102)) = v0;
    if (branch) goto L_8c0d0;
    goto L_8c0b4;
L_8c0b4:
    v0 = 1;
    branch = (a3 != v0); ;
    if (branch) goto L_8c0d0;
    goto L_8c0c0;
L_8c0c0:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (16));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u8 *)(unsigned long)(a1 + (1));
    *(volatile u8 *)(unsigned long)(v0 + (863)) = a1;
L_8c0d0:
    branch = (a0 == 0); v0 = 0;
    if (branch) goto L_8c8dc;
    goto L_8c0d8;
L_8c0d8:
    v0 = 1;
    if (a2 != v0) { v0 = 0; goto L_8c8dc; }
    goto L_8c0e4;
L_8c0e4:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (16));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u8 *)(unsigned long)(v1 + (863));
    *(volatile u8 *)(unsigned long)(v0 + (1)) = v1;
L_8c0f4:
    v0 = 0; goto L_8c8dc;
L_8c0fc:
    v0 = (u32)v0 < (u32)(a0);
    if (v0 == 0) { *(volatile u32 *)(unsigned long)(t1 + (0)) = a2; goto L_8c114; }
    goto L_8c108;
L_8c108:
    branch = (t2 == 0); v0 = 1;
    if (branch) goto L_8c8dc;
    goto L_8c110;
L_8c110:
    *(volatile u32 *)(unsigned long)(t1 + (0)) = a2;
L_8c114:
    *(volatile u32 *)(unsigned long)(t1 + (4)) = a3;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = 1;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (56));
    if (v0 != a1) { a3 = a3 << (0x16 & 31); goto L_8c24c; }
    goto L_8c12c;
L_8c12c:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (838));
    *(volatile u16 *)(unsigned long)(a1 + (76)) = a0;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (840));
    *(volatile u16 *)(unsigned long)(a0 + (78)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (512));
    *(volatile u16 *)(unsigned long)(a0 + (80)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (514));
    *(volatile u16 *)(unsigned long)(a0 + (82)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (516));
    *(volatile u16 *)(unsigned long)(a0 + (84)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (518));
    *(volatile u16 *)(unsigned long)(a0 + (86)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (520));
    *(volatile u16 *)(unsigned long)(a0 + (88)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (522));
    *(volatile u16 *)(unsigned long)(a0 + (90)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (524));
    *(volatile u16 *)(unsigned long)(a0 + (92)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (526));
    *(volatile u16 *)(unsigned long)(a0 + (94)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (528));
    *(volatile u16 *)(unsigned long)(a0 + (96)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (530));
    *(volatile u16 *)(unsigned long)(a0 + (98)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (532));
    *(volatile u16 *)(unsigned long)(a0 + (100)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (534));
    *(volatile u16 *)(unsigned long)(a0 + (102)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (686));
    *(volatile u16 *)(unsigned long)(a0 + (60)) = a1;
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (688));
    *(volatile u16 *)(unsigned long)(a0 + (62)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u16 *)(unsigned long)(a1 + (690));
    *(volatile u16 *)(unsigned long)(a0 + (64)) = a1;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (692));
    *(volatile u16 *)(unsigned long)(a0 + (66)) = v1; goto L_8c8dc;
L_8c24c:
    t0 = t0 + 4;
    a2 = a2 >> (0xa & 31);
    a0 = a3 | a2;
    v0 = t0;
    s0 = 0;
    a3 = 11;
    a1 = 12;
L_8c268:
    a2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t1 = (u32)a0 < (u32)(a2);
    branch = (t1 == 0); ;
    if (branch) goto L_8c764;
    goto L_8c278;
L_8c278:
    if (s0 != 0) { v0 = s0 << (0x2 & 31); goto L_8c3e4; }
    goto L_8c280;
L_8c280:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (790));
    *(volatile u16 *)(unsigned long)(v0 + (76)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (814));
    *(volatile u16 *)(unsigned long)(v0 + (78)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (224));
    *(volatile u16 *)(unsigned long)(v0 + (80)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (248));
    *(volatile u16 *)(unsigned long)(v0 + (82)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (272));
    *(volatile u16 *)(unsigned long)(v0 + (84)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (296));
    *(volatile u16 *)(unsigned long)(v0 + (86)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (320));
    *(volatile u16 *)(unsigned long)(v0 + (88)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (344));
    *(volatile u16 *)(unsigned long)(v0 + (90)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (368));
    *(volatile u16 *)(unsigned long)(v0 + (92)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (392));
    *(volatile u16 *)(unsigned long)(v0 + (94)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (416));
    *(volatile u16 *)(unsigned long)(v0 + (96)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (440));
    *(volatile u16 *)(unsigned long)(v0 + (98)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (464));
    *(volatile u16 *)(unsigned long)(v0 + (100)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (488));
    *(volatile u16 *)(unsigned long)(v0 + (102)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (694));
    *(volatile u16 *)(unsigned long)(v0 + (60)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (718));
    *(volatile u16 *)(unsigned long)(v0 + (62)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (742));
    *(volatile u16 *)(unsigned long)(v0 + (64)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (766));
    *(volatile u16 *)(unsigned long)(v0 + (66)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (586));
    *(volatile u16 *)(unsigned long)(v0 + (68)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (610));
    *(volatile u16 *)(unsigned long)(v0 + (70)) = a0;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    a0 = *(volatile u16 *)(unsigned long)(a0 + (638));
    *(volatile u16 *)(unsigned long)(v0 + (72)) = a0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (8));
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (662));
    *(volatile u16 *)(unsigned long)(v0 + (74)) = v1; goto L_8c0f4;
L_8c3e4:
    t0 = t0 + v0;
    a1 = *(volatile u32 *)(unsigned long)(t0 + (-4));
    a2 = a2 - a1;
    branch = (a2 == 0); v0 = 2;
    if (branch) goto L_8c8dc;
    goto L_8c3f8;
L_8c3f8:
    a0 = a0 - a1;
    v0 = (s32)a0 >> (0x1f & 31);
    v1 = a0 >> (0x14 & 31);
    a1 = a0 << (0xc & 31);
    v0 = v0 << (0xc & 31);
    a0 = (s32)a2 >> (0x1 & 31);
    a3 = (s32)a2 >> (0x1f & 31);
    a0 = a1 + a0;
    v0 = v1 | v0;
    v0 = v0 + a3;
    a1 = (u32)a0 < (u32)(a1);
    a1 = a1 + v0;
    v0 = hi_8c428;
    v0 = v0 - hi_8c428 + ((u32)(unsigned long)ref_div64_u64 + (0));
    callee = v0; s1 = s1 + s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c438;
L_8c438:
    s3 = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    s0 = s0 << (0x1 & 31);
    s2 = hi_8c444;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s2 = s2 - hi_8c444 + (u32)(unsigned long)ref_tisp_ccm_sub_interp;
    a0 = s3;
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (790));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (788));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c468;
L_8c468:
    *(volatile u16 *)(unsigned long)(s4 + (76)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (814));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (812));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c48c;
L_8c48c:
    *(volatile u16 *)(unsigned long)(s4 + (78)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (224));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (222));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c4b0;
L_8c4b0:
    *(volatile u16 *)(unsigned long)(s4 + (80)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (248));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (246));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c4d4;
L_8c4d4:
    *(volatile u16 *)(unsigned long)(s4 + (82)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (272));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (270));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c4f8;
L_8c4f8:
    *(volatile u16 *)(unsigned long)(s4 + (84)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (296));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (294));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c51c;
L_8c51c:
    *(volatile u16 *)(unsigned long)(s4 + (86)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (320));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (318));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c540;
L_8c540:
    *(volatile u16 *)(unsigned long)(s4 + (88)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (344));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (342));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c564;
L_8c564:
    *(volatile u16 *)(unsigned long)(s4 + (90)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (368));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (366));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c588;
L_8c588:
    *(volatile u16 *)(unsigned long)(s4 + (92)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (392));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (390));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c5ac;
L_8c5ac:
    *(volatile u16 *)(unsigned long)(s4 + (94)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (416));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (414));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c5d0;
L_8c5d0:
    *(volatile u16 *)(unsigned long)(s4 + (96)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (440));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (438));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c5f4;
L_8c5f4:
    *(volatile u16 *)(unsigned long)(s4 + (98)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (464));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (462));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c618;
L_8c618:
    *(volatile u16 *)(unsigned long)(s4 + (100)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (488));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (486));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c63c;
L_8c63c:
    *(volatile u16 *)(unsigned long)(s4 + (102)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (694));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (692));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c660;
L_8c660:
    *(volatile u16 *)(unsigned long)(s4 + (60)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (718));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (716));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c684;
L_8c684:
    *(volatile u16 *)(unsigned long)(s4 + (62)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (742));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (740));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c6a8;
L_8c6a8:
    *(volatile u16 *)(unsigned long)(s4 + (64)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (766));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (764));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c6cc;
L_8c6cc:
    *(volatile u16 *)(unsigned long)(s4 + (66)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (586));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (584));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c6f0;
L_8c6f0:
    *(volatile u16 *)(unsigned long)(s4 + (68)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (610));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (608));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c714;
L_8c714:
    *(volatile u16 *)(unsigned long)(s4 + (70)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s4 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    v0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(v0 + (638));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(v0 + (636));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c738;
L_8c738:
    *(volatile u16 *)(unsigned long)(s4 + (72)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = s3;
    s1 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    s0 = v0 + s0;
    a2 = *(volatile u16 *)(unsigned long)(s0 + (662));
    callee = s2; a1 = *(volatile u16 *)(unsigned long)(s0 + (660));
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8c75c;
L_8c75c:
    *(volatile u16 *)(unsigned long)(s1 + (74)) = v0; goto L_8c0f4;
L_8c764:
    branch = (s0 != a3); s0 = s0 + 1;
    if (branch) goto L_8c8cc;
    goto L_8c76c;
L_8c76c:
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (812));
    *(volatile u16 *)(unsigned long)(a2 + (76)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (836));
    *(volatile u16 *)(unsigned long)(a2 + (78)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (246));
    *(volatile u16 *)(unsigned long)(a2 + (80)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (270));
    *(volatile u16 *)(unsigned long)(a2 + (82)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (294));
    *(volatile u16 *)(unsigned long)(a2 + (84)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (318));
    *(volatile u16 *)(unsigned long)(a2 + (86)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (342));
    *(volatile u16 *)(unsigned long)(a2 + (88)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (366));
    *(volatile u16 *)(unsigned long)(a2 + (90)) = t1;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (390));
    *(volatile u16 *)(unsigned long)(a2 + (92)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (414));
    *(volatile u16 *)(unsigned long)(a2 + (94)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (438));
    *(volatile u16 *)(unsigned long)(a2 + (96)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (462));
    *(volatile u16 *)(unsigned long)(a2 + (98)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (486));
    *(volatile u16 *)(unsigned long)(a2 + (100)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (510));
    *(volatile u16 *)(unsigned long)(a2 + (102)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (716));
    *(volatile u16 *)(unsigned long)(a2 + (60)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (740));
    *(volatile u16 *)(unsigned long)(a2 + (62)) = t1;
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (764));
    *(volatile u16 *)(unsigned long)(a2 + (64)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (788));
    *(volatile u16 *)(unsigned long)(a2 + (66)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (608));
    *(volatile u16 *)(unsigned long)(a2 + (68)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (632));
    *(volatile u16 *)(unsigned long)(a2 + (70)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (660));
    *(volatile u16 *)(unsigned long)(a2 + (72)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = *(volatile u32 *)(unsigned long)(v1 + (8));
    t1 = *(volatile u16 *)(unsigned long)(t1 + (684));
    *(volatile u16 *)(unsigned long)(a2 + (74)) = t1;
L_8c8cc:
    branch = (s0 != a1); v0 = v0 + 4;
    if (branch) goto L_8c268;
    goto L_8c8d4;
L_8c8d4:
    v0 = 0; goto L_8c8dc;
L_8c8dc:
    ra = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 40;
    return ((u64)v1 << 32) | v0;
}
