/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e28f0[] __asm__("t32_data_e28f0");
extern unsigned char ref_tisp_round_int64[] __asm__("tisp_round_int64");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_t32_data_dc274[] __asm__("t32_data_dc274");
u64 tisp_ccm_interp_by_ct(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_8c994 = ((u32)(unsigned long)ref_t32_data_e28f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_8ca18 = ((u32)(unsigned long)ref_tisp_round_int64 + 0x8000U) & 0xffff0000U;
    const u32 hi_8ca58 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_8ca9c = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    const u32 hi_8cd14 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_8cd34 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_8c9f4 = ((u32)(unsigned long)ref_t32_data_dc274 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_8c98c:
    sp = sp + -48;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s1;
    s1 = hi_8c994;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s2;
    s1 = s1 - hi_8c994 + (u32)(unsigned long)ref_t32_data_e28f0;
    s2 = a0 << (0x2 & 31);
    *(volatile u32 *)(unsigned long)(sp + (44)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s0;
    v0 = s2 + s1;
    t4 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a3 = 1;
    a2 = a2 & 0xff;
    t3 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a0 = *(volatile u32 *)(unsigned long)(t4 + (16));
    s0 = *(volatile u32 *)(unsigned long)(t4 + (8));
    v1 = *(volatile u8 *)(unsigned long)(t3 + (864));
    v0 = *(volatile u8 *)(unsigned long)(t3 + (865));
    branch = (v1 == a3); a0 = *(volatile int8_t *)(unsigned long)(a0 + (0));
    if (branch) goto L_8ca9c;
    goto L_8c9e8;
L_8c9e8:
    branch = (v1 != 0); v0 = (u32)v0 < (u32)(2);
    if (branch) goto L_8c9f8;
    goto L_8c9f0;
L_8c9f0:
    branch = (v0 != 0); v1 = hi_8c9f4;
    if (branch) goto L_8caa0;
    goto L_8c9f8;
L_8c9f8:
    branch = (a0 == 0); v1 = 1;
    if (branch) goto L_8ca9c;
    goto L_8ca00;
L_8ca00:
    branch = (a2 != v1); v0 = 1;
    if (branch) goto L_8cd80;
    goto L_8ca08;
L_8ca08:
    s5 = *(volatile u8 *)(unsigned long)(t3 + (866));
    s1 = s1 + s2;
    s4 = s0;
    s3 = 0;
    s6 = hi_8ca18;
    s2 = 9;
L_8ca20:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    v1 = s3 << (0x2 & 31);
    a2 = 0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (16));
    s3 = s3 + 1;
    s4 = s4 + 4;
    v0 = v0 + v1;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = s6 - hi_8ca18 + (u32)(unsigned long)ref_tisp_round_int64;
    callee = v0; a1 = (s32)a0 >> (0x1f & 31);
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8ca4c;
L_8ca4c:
    branch = (s3 != s2); *(volatile u32 *)(unsigned long)(s4 + (-4)) = v0;
    if (branch) goto L_8ca20;
    goto L_8ca54;
L_8ca54:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    s3 = hi_8ca58;
    a2 = 36;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    s3 = s3 - hi_8ca58 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = s3; a1 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8ca70;
L_8ca70:
    v0 = 1;
    if (s5 != v0) { v0 = 0; goto L_8cd80; }
    goto L_8ca7c;
L_8ca7c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 36;
    a1 = s0;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    callee = s3; a0 = a0 + 60;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8ca94;
L_8ca94:
    v0 = 0; goto L_8cd80;
L_8ca9c:
    v1 = hi_8ca9c;
L_8caa0:
    v1 = v1 - hi_8ca9c + (u32)(unsigned long)ref_t32_data_dc274;
    v0 = v1 + s2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t0 = *(volatile u8 *)(unsigned long)(t3 + (869));
    t2 = *(volatile u8 *)(unsigned long)(t3 + (868));
    v0 = *(volatile u32 *)(unsigned long)(v0 + (24));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = t0 + a0;
    a0 = (s32)a0 < (s32)(a1);
    branch = (a0 == 0); t1 = 0;
    if (branch) goto L_8cb50;
    goto L_8cacc;
L_8cacc:
    a0 = 40;
    a3 = t2 + -1;
    t5 = a3 * a0;
    a0 = t5 + v0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 - t0;
    a0 = (s32)a1 < (s32)(a0);
    branch = (a0 == 0); t1 = t2;
    if (branch) goto L_8cb30;
    goto L_8caf0;
L_8caf0:
    a3 = 1; goto L_8cb00;
L_8caf8:
    a3 = a3 + 1;
L_8cafc:
    v0 = v0 + 40;
L_8cb00:
    a0 = (s32)a3 < (s32)(t2);
    if (a0 == 0) { t5 = *(volatile u32 *)(unsigned long)(t4 + (4)); goto L_8cb54; }
    goto L_8cb0c;
L_8cb0c:
    a0 = *(volatile u32 *)(unsigned long)(v0 + (40));
    t5 = a0 - t0;
    t5 = (s32)a1 < (s32)(t5);
    if (t5 != 0) { a0 = *(volatile u32 *)(unsigned long)(v0 + (0)); goto L_8cb38; }
    goto L_8cb20;
L_8cb20:
    a0 = t0 + a0;
    a0 = (s32)a0 < (s32)(a1);
    if (a0 != 0) { a3 = a3 + 1; goto L_8cafc; }
    goto L_8cb30;
L_8cb30:
    t1 = a3 << (0x1 & 31); goto L_8cb50;
L_8cb38:
    a0 = t0 + a0;
    a0 = (s32)a0 < (s32)(a1);
    branch = (a0 == 0); t5 = a3 + -1;
    if (branch) goto L_8caf8;
    goto L_8cb48;
L_8cb48:
    t1 = t5 << (0x1 & 31);
    t1 = t1 + 1;
L_8cb50:
    t5 = *(volatile u32 *)(unsigned long)(t4 + (4));
L_8cb54:
    t6 = *(volatile u16 *)(unsigned long)(t3 + (584));
    a3 = *(volatile u32 *)(unsigned long)(t5 + (8));
    branch = (a2 != 0); v0 = *(volatile u32 *)(unsigned long)(t5 + (12));
    if (branch) goto L_8cb94;
    goto L_8cb64;
L_8cb64:
    if (t1 != v0) { v0 = a1 - a3; goto L_8cb7c; }
    goto L_8cb6c;
L_8cb6c:
    a2 = t1 & 0x1;
    branch = (a2 == 0); v0 = 1;
    if (branch) goto L_8cd80;
    goto L_8cb78;
L_8cb78:
    v0 = a1 - a3;
L_8cb7c:
    a0 = (s32)v0 >> (0x1f & 31);
    v0 = a0 ^ v0;
    v0 = v0 - a0;
    a0 = (s32)t6 < (s32)(v0);
    branch = (a0 == 0); v0 = 1;
    if (branch) goto L_8cd80;
    goto L_8cb94;
L_8cb94:
    s3 = *(volatile u8 *)(unsigned long)(t3 + (867));
    *(volatile u32 *)(unsigned long)(t5 + (8)) = a1;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (4));
    *(volatile u32 *)(unsigned long)(v0 + (12)) = t1;
    v0 = *(volatile u32 *)(unsigned long)(t4 + (0));
    a0 = *(volatile u32 *)(unsigned long)(v0 + (56));
    branch = (a0 != 0); a2 = 36;
    if (branch) goto L_8cd10;
    goto L_8cbb4;
L_8cbb4:
    v0 = 1;
    branch = (t2 != v0); v1 = v1 + s2;
    if (branch) goto L_8cbd4;
    goto L_8cbc0;
L_8cbc0:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = 36;
    a1 = *(volatile u32 *)(unsigned long)(v0 + (24));
    a1 = a1 + 4; goto L_8cd14;
L_8cbd4:
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a3 = *(volatile u32 *)(unsigned long)(v0 + (24));
    v0 = *(volatile u32 *)(unsigned long)(a3 + (0));
    v0 = (u32)v0 < (u32)(a1);
    branch = (v0 != 0); v1 = 40;
    if (branch) goto L_8cbf8;
    goto L_8cbec;
L_8cbec:
    a2 = 36;
    a1 = a3 + 4; goto L_8cd14;
L_8cbf8:
    v0 = t2 + -1;
    v0 = v0 * v1;
    v1 = a3 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = (u32)a1 < (u32)(v1);
    branch = (v1 == 0); v1 = a3 + 40;
    if (branch) goto L_8cc60;
    goto L_8cc14;
L_8cc14:
    v0 = 1; goto L_8cc20;
L_8cc1c:
    v0 = v0 + 1;
L_8cc20:
    a0 = (s32)v0 < (s32)(t2);
    branch = (a0 == 0); t1 = v1 - a3;
    if (branch) goto L_8cd24;
    goto L_8cc2c;
L_8cc2c:
    a0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    a2 = (u32)a0 < (u32)(a1);
    branch = (a2 != 0); v1 = v1 + 40;
    if (branch) goto L_8cc1c;
    goto L_8cc3c;
L_8cc3c:
    v1 = 40;
    v0 = v0 + -1;
    v0 = v0 * v1;
    t2 = a3 + v0;
    v1 = *(volatile u32 *)(unsigned long)(t2 + (0));
    a2 = t0 + v1;
    a2 = (u32)a2 < (u32)(a1);
    if (a2 != 0) { v0 = a0 - t0; goto L_8cc68; }
    goto L_8cc60;
L_8cc60:
    a1 = v0 + 4; goto L_8cc78;
L_8cc68:
    v0 = (u32)a1 < (u32)(v0);
    branch = (v0 != 0); a0 = a0 - v1;
    if (branch) goto L_8cc84;
    goto L_8cc74;
L_8cc74:
    a1 = t1 + 4;
L_8cc78:
    a2 = 36;
    a1 = a3 + a1; goto L_8cd14;
L_8cc84:
    v0 = t0 << (0x1 & 31);
    v1 = a1 - v1;
    a0 = a0 - v0;
    t0 = v1 - t0;
    t6 = a0 - t0;
    a1 = (s32)a0 >> (0x1 & 31);
    a2 = 0;
    t5 = -8192;
    t4 = 8191;
    t3 = 36;
L_8ccac:
    v0 = a2 + t1;
    v0 = a3 + v0;
    v1 = *(volatile u32 *)(unsigned long)(v0 + (4));
    v0 = t2 + a2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (4));
    product = (s64)(s32)t6 * (s32)v0; lo = product; hi = product >> 32;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)t0 * (s32)v1); lo = product; hi = product >> 32;
    v0 = lo;
    t7 = v0 + a1;
    v1 = (s32)v0 < (s32)(1);
    t8 = v0 - a1;
    v0 = t7;
    if (v1 != 0) v0 = t8;
    if (v0 == 0x80000000U && a0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (a0) { lo = (s32)v0 / (s32)a0; hi = (s32)v0 % (s32)a0; } else { lo = (s32)v0 < 0 ? 1 : ~0U; hi = v0; }
    t7 = s0 + a2;
    a2 = a2 + 4;
    v0 = lo;
    v1 = (s32)v0 < (s32)(-8192);
    if (v1 != 0) v0 = t5;
    v1 = (s32)v0 < (s32)(8192);
    if (v1 == 0) v0 = t4;
    branch = (a2 != t3); *(volatile u32 *)(unsigned long)(t7 + (0)) = v0;
    if (branch) goto L_8ccac;
    goto L_8cd08;
L_8cd08:
    s1 = s1 + s2; goto L_8cd28;
L_8cd10:
    a1 = v0 + 60;
L_8cd14:
    v0 = hi_8cd14;
    v0 = v0 - hi_8cd14 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8cd24;
L_8cd24:
    s1 = s1 + s2;
L_8cd28:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a2 = 36;
    a0 = *(volatile u32 *)(unsigned long)(v0 + (12));
    v0 = hi_8cd34;
    v0 = v0 - hi_8cd34 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a1 = s0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_8cd44;
L_8cd44:
    v0 = 1;
    branch = (s3 != v0); v0 = 0;
    if (branch) goto L_8cd80;
    goto L_8cd50;
L_8cd50:
    a3 = *(volatile u32 *)(unsigned long)(s1 + (0));
    a0 = 9;
L_8cd58:
    v1 = *(volatile u32 *)(unsigned long)(a3 + (16));
    a1 = *(volatile u32 *)(unsigned long)(s0 + (0));
    a2 = v0 << (0x2 & 31);
    v1 = v1 + a2;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (4)) = a1;
    branch = (v0 != a0); s0 = s0 + 4;
    if (branch) goto L_8cd58;
    goto L_8cd78;
L_8cd78:
    v0 = 0; goto L_8cd80;
L_8cd80:
    ra = *(volatile u32 *)(unsigned long)(sp + (44));
    s6 = *(volatile u32 *)(unsigned long)(sp + (40));
    s5 = *(volatile u32 *)(unsigned long)(sp + (36));
    s4 = *(volatile u32 *)(unsigned long)(sp + (32));
    s3 = *(volatile u32 *)(unsigned long)(sp + (28));
    s2 = *(volatile u32 *)(unsigned long)(sp + (24));
    s1 = *(volatile u32 *)(unsigned long)(sp + (20));
    s0 = *(volatile u32 *)(unsigned long)(sp + (16));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
