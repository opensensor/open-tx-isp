/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e2450[] __asm__("t32_data_e2450");
extern unsigned char ref_tisp_round_int64[] __asm__("tisp_round_int64");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_dc274[] __asm__("t32_data_dc274");
extern unsigned char ref_memset[] __asm__("memset");
u64 tisp_bcsh_interp_by_ct(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_7dffc = ((u32)(unsigned long)ref_t32_data_e2450 + 0x8000U) & 0xffff0000U;
    const u32 hi_7e07c = ((u32)(unsigned long)ref_tisp_round_int64 + 0x8000U) & 0xffff0000U;
    const u32 hi_7e0c4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7e0dc = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    const u32 hi_7e1f4 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7e38c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7e3ac = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_7e05c = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
    stack[16] = arg4;
L_7dff4:
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    s1 = hi_7dffc;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    s1 = s1 - hi_7dffc + (u32)(unsigned long)ref_t32_data_e2450;
    s2 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    v0 = s2 + s1;
    t2 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a1 = 1;
    t4 = *(volatile u8 *)(unsigned long)(sp + (64));
    t3 = *(volatile u32 *)(unsigned long)(t2 + (0));
    s4 = *(volatile u32 *)(unsigned long)(t2 + (8));
    a0 = *(volatile u32 *)(unsigned long)(t2 + (16));
    v1 = *(volatile u8 *)(unsigned long)(t3 + (1171));
    s0 = s4 + 184;
    v0 = *(volatile u8 *)(unsigned long)(t3 + (1172));
    branch = (v1 == a1); a0 = *(volatile int8_t *)(unsigned long)(a0 + (4));
    if (branch) goto L_7e0dc;
    goto L_7e050;
L_7e050:
    branch = (v1 != 0); v0 = (u32)v0 < (u32)(2);
    if (branch) goto L_7e060;
    goto L_7e058;
L_7e058:
    branch = (v0 != 0); v1 = hi_7e05c;
    if (branch) goto L_7e0e0;
    goto L_7e060;
L_7e060:
    branch = (a0 == 0); v1 = 1;
    if (branch) goto L_7e0dc;
    goto L_7e068;
L_7e068:
    branch = (t4 != v1); v0 = 1;
    if (branch) goto L_7e3fc;
    goto L_7e070;
L_7e070:
    s1 = s1 + s2;
    s4 = s0;
    s3 = 0;
    s5 = hi_7e07c;
    s2 = 9;
L_7e084:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = s3 << (0x2 & 31);
    a2 = 6;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s3 = s3 + 1;
    s4 = s4 + 4;
    v0 = v0 + v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (8));
    v0 = s5 - hi_7e07c + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7e0b0;
L_7e0b0:
    branch = (s3 != s2); *(volatile u32 *)(unsigned long)(s4 + (-4)) = v0;
    if (branch) goto L_7e084;
    goto L_7e0b8;
L_7e0b8:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 36;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    v0 = hi_7e0c4;
    v0 = v0 - hi_7e0c4 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a1 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7e0d4;
L_7e0d4:
    v0 = 0; goto L_7e3fc;
L_7e0dc:
    v1 = hi_7e0dc;
L_7e0e0:
    v1 = v1 - hi_7e0dc + (u32)(unsigned long)ref_t32_data_dc274;
    v0 = v1 + s2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = *(volatile u8 *)(unsigned long)(t3 + (1200));
    t1 = *(volatile u8 *)(unsigned long)(t3 + (1199));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (28));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = a3 + a0;
    a0 = (s32)a0 < (s32)(a2);
    branch = (a0 == 0); t0 = 0;
    if (branch) goto L_7e190;
    goto L_7e10c;
L_7e10c:
    a0 = 40;
    a1 = t1 + -1;
    t5 = a1 * a0;
    a0 = t5 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 - a3;
    a0 = (s32)a2 < (s32)(a0);
    branch = (a0 == 0); t0 = t1;
    if (branch) goto L_7e170;
    goto L_7e130;
L_7e130:
    a1 = 1; goto L_7e140;
L_7e138:
    a1 = a1 + 1;
L_7e13c:
    v0 = v0 + 40;
L_7e140:
    a0 = (s32)a1 < (s32)(t1);
    if (a0 == 0) { t5 = *(volatile u32 *)(unsigned long)(t2 + (4)); goto L_7e194; }
    goto L_7e14c;
L_7e14c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (40));
    t5 = a0 - a3;
    t5 = (s32)a2 < (s32)(t5);
    if (t5 != 0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_7e178; }
    goto L_7e160;
L_7e160:
    a0 = a3 + a0;
    a0 = (s32)a0 < (s32)(a2);
    if (a0 != 0) { a1 = a1 + 1; goto L_7e13c; }
    goto L_7e170;
L_7e170:
    t0 = a1 << (0x1 & 31); goto L_7e190;
L_7e178:
    a0 = a3 + a0;
    a0 = (s32)a0 < (s32)(a2);
    branch = (a0 == 0); t5 = a1 + -1;
    if (branch) goto L_7e138;
    goto L_7e188;
L_7e188:
    t0 = t5 << (0x1 & 31);
    t0 = t0 + 1;
L_7e190:
    t5 = *(volatile u32 *)(unsigned long)(t2 + (4));
L_7e194:
    t6 = *(volatile u16 *)(unsigned long)(t3 + (156));
    a1 = *(volatile u32 *)(unsigned long)(t5 + (8));
    branch = (t4 != 0); v0 = *(volatile u32 *)(unsigned long)(t5 + (12));
    if (branch) goto L_7e1d4;
    goto L_7e1a4;
L_7e1a4:
    if (t0 != v0) { v0 = a2 - a1; goto L_7e1bc; }
    goto L_7e1ac;
L_7e1ac:
    t4 = t0 & 0x1;
    branch = (t4 == 0); v0 = 1;
    if (branch) goto L_7e3fc;
    goto L_7e1b8;
L_7e1b8:
    v0 = a2 - a1;
L_7e1bc:
    a0 = (s32)v0 >> (0x1f & 31);
    v0 = a0 ^ v0;
    v0 = v0 - a0;
    a0 = (s32)t6 < (s32)(v0);
    branch = (a0 == 0); v0 = 1;
    if (branch) goto L_7e3fc;
    goto L_7e1d4;
L_7e1d4:
    s3 = *(volatile u8 *)(unsigned long)(t3 + (1174));
    *(volatile u32 *)(unsigned long)(t5 + (8)) = a2;
    v0 = *(volatile u32 *)(unsigned long)(t2 + (4));
    *(volatile u32 *)(unsigned long)(v0 + (12)) = t0;
    a1 = *(volatile u32 *)(unsigned long)(t2 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a1 + (1170));
    branch = (v0 != 0); a0 = 1;
    if (branch) goto L_7e220;
    goto L_7e1f4;
L_7e1f4:
    v0 = hi_7e1f4;
    a2 = 36;
    a1 = 0;
    v0 = v0 - hi_7e1f4 + ((u32)(unsigned long)ref_memset + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7e20c;
L_7e20c:
    v0 = 1024;
    *(volatile u32 *)(unsigned long)(s4 + (216)) = v0;
    *(volatile u32 *)(unsigned long)(s4 + (200)) = v0;
    *(volatile u32 *)(unsigned long)(s4 + (184)) = v0; goto L_7e39c;
L_7e220:
    if (v0 != a0) { v1 = 2; goto L_7e37c; }
    goto L_7e228;
L_7e228:
    branch = (t1 != v0); v1 = v1 + s2;
    if (branch) goto L_7e23c;
    goto L_7e230;
L_7e230:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (28)); goto L_7e254;
L_7e23c:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a1 = *(volatile u32 *)(unsigned long)(v0 + (28));
    v0 = *(volatile u32 *)(unsigned long)(a1 + (0));
    v0 = (s32)v0 < (s32)(a2);
    branch = (v0 != 0); v1 = 40;
    if (branch) goto L_7e260;
    goto L_7e254;
L_7e254:
    a2 = 36;
    a1 = a1 + 4; goto L_7e38c;
L_7e260:
    v0 = t1 + -1;
    v0 = v0 * v1;
    v1 = a1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = (s32)a2 < (s32)(v1);
    branch = (v1 == 0); v1 = a1 + 40;
    if (branch) goto L_7e2c4;
    goto L_7e27c;
L_7e27c:
    v0 = 1;
L_7e280:
    a0 = (s32)v0 < (s32)(t1);
    branch = (a0 == 0); t2 = v1 - a1;
    if (branch) goto L_7e39c;
    goto L_7e28c;
L_7e28c:
    v1 = v1 + 40;
    a0 = *(volatile u32 *)(unsigned long)(v1 + (-40));
    t0 = (s32)a0 < (s32)(a2);
    if (t0 != 0) { v0 = v0 + 1; goto L_7e280; }
    goto L_7e2a0;
L_7e2a0:
    v1 = 40;
    v0 = v0 + -1;
    v0 = v0 * v1;
    t1 = a1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t0 = a3 + v1;
    t0 = (s32)t0 < (s32)(a2);
    if (t0 != 0) { v0 = a0 - a3; goto L_7e2d4; }
    goto L_7e2c4;
L_7e2c4:
    v0 = v0 + 4;
    a2 = 36;
    a1 = a1 + v0; goto L_7e38c;
L_7e2d4:
    v0 = (s32)a2 < (s32)(v0);
    branch = (v0 != 0); v0 = a3 << (0x1 & 31);
    if (branch) goto L_7e2f0;
    goto L_7e2e0;
L_7e2e0:
    t2 = t2 + 4;
    a2 = 36;
    a1 = a1 + t2; goto L_7e38c;
L_7e2f0:
    a2 = a2 - v1;
    a0 = a0 - v1;
    a0 = a0 - v0;
    a3 = a2 - a3;
    t6 = a0 - a3;
    a2 = (s32)a0 >> (0x1 & 31);
    t0 = 0;
    t5 = -8192;
    t4 = 8191;
    t3 = 36;
L_7e318:
    v0 = t0 + t2;
    v0 = a1 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = t1 + t0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    product = (s64)(s32)t6 * (s32)v0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)a3 * (s32)v1); lo = product; hi = product >> 32;
    v0 = lo;
    t7 = v0 + a2;
    v1 = (s32)v0 < (s32)(1);
    t8 = v0 - a2;
    v0 = t7;
    if (v1 != 0) v0 = t8;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t7 = s0 + t0;
    t0 = t0 + 4;
    v0 = lo;
    v1 = (s32)v0 < (s32)(-8192);
    if (v1 != 0) v0 = t5;
    v1 = (s32)v0 < (s32)(8192);
    if (v1 == 0) v0 = t4;
    branch = (t0 != t3); *(volatile u32 *)(unsigned long)(t7 + (0)) = v0;
    if (branch) goto L_7e318;
    goto L_7e374;
L_7e374:
    s1 = s1 + s2; goto L_7e3a0;
L_7e37c:
    if (v0 != v1) { s1 = s1 + s2; goto L_7e3a0; }
    goto L_7e384;
L_7e384:
    a2 = 36;
    a1 = a1 + 104;
L_7e38c:
    v0 = hi_7e38c;
    v0 = v0 - hi_7e38c + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7e39c;
L_7e39c:
    s1 = s1 + s2;
L_7e3a0:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 36;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    v0 = hi_7e3ac;
    v0 = v0 - hi_7e3ac + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a1 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_7e3bc;
L_7e3bc:
    v0 = 1;
    branch = (s3 != v0); v0 = 0;
    if (branch) goto L_7e3fc;
    goto L_7e3c8;
L_7e3c8:
    a2 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a1 = 9;
L_7e3d0:
    v1 = *(volatile u32 *)(unsigned long)(a2 + (16));
    a0 = v0 << (0x2 & 31);
    v0 = v0 + 1;
    v1 = v1 + a0;
    a0 = *(volatile u32 *)(unsigned long)(s0 + (0));
    s0 = s0 + 4;
    a0 = a0 << (0x6 & 31);
    branch = (v0 != a1); *(volatile u32 *)(unsigned long)(v1 + (8)) = a0;
    if (branch) goto L_7e3d0;
    goto L_7e3f4;
L_7e3f4:
    v0 = 0; goto L_7e3fc;
L_7e3fc:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s5 = *(volatile u32 *)(unsigned long)(sp + (40));
    s4 = *(volatile u32 *)(unsigned long)(sp + (36));
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
