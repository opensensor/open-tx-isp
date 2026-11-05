/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_ISPAWBInterpolation1[] __asm__("ISPAWBInterpolation1");
extern unsigned char ref_ISPAWBInterpolation2[] __asm__("ISPAWBInterpolation2");
extern unsigned char ref_fix_point_div_32[] __asm__("fix_point_div_32");
u64 Tiziano_Awb_Ct_Cal(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_20208 = ((u32)(unsigned long)ref_ISPAWBInterpolation1 + 0x8000U) & 0xffff0000U;
    const u32 hi_2025c = ((u32)(unsigned long)ref_ISPAWBInterpolation1 + 0x8000U) & 0xffff0000U;
    const u32 hi_202d0 = ((u32)(unsigned long)ref_ISPAWBInterpolation2 + 0x8000U) & 0xffff0000U;
    const u32 hi_20300 = ((u32)(unsigned long)ref_fix_point_div_32 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_20054:
    sp = sp + -56;
    *(volatile u32 *)(unsigned long)(sp + (52)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (52));
    a3 = *(volatile u32 *)(unsigned long)(a0 + (24));
    t8 = *(volatile u32 *)(unsigned long)(a0 + (28));
    s0 = *(volatile u16 *)(unsigned long)(v0 + (2));
    t7 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(a3 + (56));
    t3 = *(volatile u32 *)(unsigned long)(a0 + (32));
    s1 = *(volatile u32 *)(unsigned long)(a0 + (44));
    v0 = v0 << (s0 & 31);
    v1 = (u32)v0 < (u32)(a1);
    branch = (v1 != 0); t4 = v0;
    if (branch) goto L_200b4;
    goto L_200a0;
L_200a0:
    t4 = *(volatile u32 *)(unsigned long)(a3 + (0));
    v1 = t4 << (s0 & 31);
    t4 = (u32)a1 < (u32)(v1);
    if (t4 == 0) v1 = a1;
    t4 = v1;
L_200b4:
    a1 = *(volatile u32 *)(unsigned long)(t8 + (56));
    a1 = a1 << (s0 & 31);
    v1 = (u32)a1 < (u32)(a2);
    branch = (v1 != 0); t5 = a1;
    if (branch) goto L_200dc;
    goto L_200c8;
L_200c8:
    t5 = *(volatile u32 *)(unsigned long)(t8 + (0));
    v1 = t5 << (s0 & 31);
    t5 = (u32)a2 < (u32)(v1);
    if (t5 == 0) v1 = a2;
    t5 = v1;
L_200dc:
    branch = (t4 == v0); v1 = a3;
    if (branch) goto L_20330;
    goto L_200e4;
L_200e4:
    a2 = 0;
    t0 = 14;
L_200ec:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v0 = v0 << (s0 & 31);
    v0 = (u32)t4 < (u32)(v0);
    branch = (v0 != 0); a0 = a2 + 1;
    if (branch) goto L_20114;
    goto L_20100;
L_20100:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    v0 = v0 << (s0 & 31);
    v0 = (u32)t4 < (u32)(v0);
    branch = (v0 != 0); ;
    if (branch) goto L_20124;
    goto L_20114;
L_20114:
    branch = (a2 == t0); v1 = v1 + 4;
    if (branch) goto L_20124;
    goto L_2011c;
L_2011c:
    a2 = a0; goto L_200ec;
L_20124:
    branch = (t5 == a1); v0 = a0;
    if (branch) goto L_20184;
    goto L_2012c;
L_2012c:
    a1 = t8;
    t6 = 0;
    a2 = 14;
L_20138:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    a0 = a0 << (s0 & 31);
    a0 = (u32)t5 < (u32)(a0);
    branch = (a0 != 0); v1 = t6 + 1;
    if (branch) goto L_20160;
    goto L_2014c;
L_2014c:
    a0 = *(volatile u32 *)(unsigned long)(a1 + (4));
    a0 = a0 << (s0 & 31);
    a0 = (u32)t5 < (u32)(a0);
    if (a0 != 0) { a1 = 15; goto L_20174; }
    goto L_20160;
L_20160:
    branch = (t6 == a2); a1 = a1 + 4;
    if (branch) goto L_20170;
    goto L_20168;
L_20168:
    t6 = v1; goto L_20138;
L_20170:
    a1 = 15;
L_20174:
    branch = (v0 != a1); a0 = v1;
    if (branch) goto L_201d0;
    goto L_2017c;
L_2017c:
    v0 = 60; goto L_20198;
L_20184:
    v1 = 15;
    if (a0 != v1) { v0 = v0 << (0x2 & 31); goto L_201dc; }
    goto L_20190;
L_20190:
    a0 = 15;
L_20194:
    v0 = 60;
L_20198:
    a1 = a0 * v0;
    v1 = a0 << (0x2 & 31);
    v1 = v1 + -4;
    v1 = t8 + v1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = t5;
    a0 = a1 + t3;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (56));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(a0 + (-4));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0; goto L_20208;
L_201d0:
    if (v1 != a1) { a0 = v1 << (0x4 & 31); goto L_2021c; }
    goto L_201d8;
L_201d8:
    v0 = v0 << (0x2 & 31);
L_201dc:
    v0 = v0 + -4;
    t3 = t3 + v0;
    v1 = a3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (844));
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = t4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (840));
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
L_20208:
    v0 = hi_20208;
    a1 = s0;
    a0 = t7;
    v0 = v0 - hi_20208 + (u32)(unsigned long)ref_ISPAWBInterpolation1; goto L_202dc;
L_2021c:
    a1 = 0x3fffU << 16;
    a1 = a1 | 0xffff;
    v1 = a0 - v1;
    v1 = v1 + v0;
    a2 = v0 + a1;
    v0 = a1 + -15;
    v0 = v1 + v0;
    v0 = v0 << (0x2 & 31);
    t3 = t3 + v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (4));
    a2 = a2 << (0x2 & 31);
    a3 = a3 + a2;
    t9 = *(volatile u32 *)(unsigned long)(a3 + (0));
    s2 = *(volatile u32 *)(unsigned long)(a3 + (4));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (0));
    s3 = hi_2025c;
    a3 = t9;
    a2 = t4;
    a0 = t7;
    a1 = s0;
    s3 = s3 - hi_2025c + (u32)(unsigned long)ref_ISPAWBInterpolation1;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (16)) = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20280;
L_20280:
    s4 = v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (64));
    a3 = t9;
    a2 = t4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(t3 + (60));
    a1 = s0;
    a0 = t7;
    *(volatile u32 *)(unsigned long)(sp + (20)) = v0;
    callee = s3; *(volatile u32 *)(unsigned long)(sp + (16)) = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_202ac;
L_202ac:
    v1 = t6 << (0x2 & 31);
    v1 = t8 + v1;
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(sp + (24)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s4;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (4));
    a2 = t5;
    a1 = s0;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_202d0;
    a0 = t7;
    v0 = v0 - hi_202d0 + (u32)(unsigned long)ref_ISPAWBInterpolation2;
L_202dc:
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_202e4;
L_202e4:
    branch = (v0 != 0); a1 = 0xfU << 16;
    if (branch) goto L_202f8;
    goto L_202ec;
L_202ec:
    v0 = 5000;
    *(volatile u32 *)(unsigned long)(s1 + (0)) = v0; goto L_20340;
L_202f8:
    a2 = v0;
    a1 = a1 + 16960;
    v0 = hi_20300;
    a0 = s0;
    v0 = v0 - hi_20300 + (u32)(unsigned long)ref_fix_point_div_32;
    callee = v0; a1 = a1 << (s0 & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_20314;
L_20314:
    a0 = s0 + -1;
    v1 = 1;
    v1 = v1 << (a0 & 31);
    v0 = v1 + v0;
    s0 = v0 >> (s0 & 31);
    *(volatile u32 *)(unsigned long)(s1 + (0)) = s0; goto L_20340;
L_20330:
    branch = (t5 != a1); v0 = 15;
    if (branch) goto L_2012c;
    goto L_20338;
L_20338:
    a0 = 15; goto L_20194;
L_20340:
    ra = *(volatile u32 *)(unsigned long)(sp + (52));
    s4 = *(volatile u32 *)(unsigned long)(sp + (48));
    s3 = *(volatile u32 *)(unsigned long)(sp + (44));
    s2 = *(volatile u32 *)(unsigned long)(sp + (40));
    s1 = *(volatile u32 *)(unsigned long)(sp + (36));
    s0 = *(volatile u32 *)(unsigned long)(sp + (32));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
