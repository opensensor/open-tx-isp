/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e16b4[] __asm__("t32_data_e16b4");
u64 tisp_awb_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[76] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_3cd60 = ((u32)(unsigned long)ref_t32_data_e16b4 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[12];
L_3cd60:
    v0 = hi_3cd60;
    sp = sp + -48;
    v0 = v0 - hi_3cd60 + (u32)(unsigned long)ref_t32_data_e16b4;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + v0;
    *(volatile u32 *)(unsigned long)(sp + (12)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s1;
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0));
    s3 = *(volatile u32 *)(unsigned long)(v1 + (4));
    t4 = *(volatile u16 *)(unsigned long)(v0 + (3190));
    s4 = *(volatile u16 *)(unsigned long)(v0 + (3186));
    v0 = t4 >> (0x2 & 31);
    s0 = v0 << (0x2 & 31);
    v1 = t4 - s0;
    a0 = t4 & 0x3;
    branch = (a0 != 0); v1 = v1 & 0xffff;
    if (branch) goto L_3cde0;
    goto L_3cdc4;
L_3cdc4:
    t0 = 26;
    product = (s64)(s32)v0 * (s32)t0; lo = product; hi = product >> 32;
    t0 = 6;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v1 * (s32)t0); lo = product; hi = product >> 32;
    t0 = lo;
    t0 = t0 & 0xffff; goto L_3ce04;
L_3cde0:
    t0 = 6;
    product = (s64)(s32)v1 * (s32)t0; lo = product; hi = product >> 32;
    v1 = 24;
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)v1); lo = product; hi = product >> 32;
    v0 = v0 + 1;
    v0 = v0 << (0x1 & 31);
    v1 = lo;
    v0 = v1 + v0;
    t0 = v0 & 0xffff;
L_3ce04:
    v0 = 6;
    v0 = t4 * v0;
    t5 = 2;
    t3 = 0;
    s5 = 26;
    s6 = 6;
    s7 = 0x1U << 16;
    s1 = 1;
    s2 = 2;
    *(volatile u32 *)(unsigned long)(sp + (0)) = v0;
    v0 = 24;
    v0 = t4 * v0;
    v0 = v0 + 4;
    *(volatile u32 *)(unsigned long)(sp + (4)) = v0;
L_3ce3c:
    branch = (t3 == s4); t8 = *(volatile u32 *)(unsigned long)(sp + (4));
    if (branch) goto L_3d03c;
    goto L_3ce44;
L_3ce44:
    t7 = *(volatile u32 *)(unsigned long)(sp + (0));
    t9 = t3 << (0x5 & 31);
    t9 = t9 & 0xffff;
    a2 = 0;
L_3ce54:
    branch = (a2 == t4); t1 = a2 & 0x3;
    if (branch) goto L_3d028;
    goto L_3ce5c;
L_3ce5c:
    product = (s64)(s32)t1 * (s32)s6; lo = product; hi = product >> 32;
    v0 = a2 >> (0x2 & 31);
    product = (((u64)hi << 32) | lo) + ((s64)(s32)v0 * (s32)s5); lo = product; hi = product >> 32;
    v0 = a2 + t9;
    v0 = v0 & 0xffff;
    v0 = v0 << (0x2 & 31);
    v0 = s3 + v0;
    v0 = v0 + s7;
    v1 = lo;
    v1 = t5 + v1;
    v1 = v1 & 0xffff;
    a0 = v1 << (0x2 & 31);
    a3 = a1 + a0;
    t2 = *(volatile u32 *)(unsigned long)(a3 + (0));
    t6 = a0 + 4;
    t6 = a1 + t6;
    t2 = (t2 >> 0x0) & ((1U << 0x16) - 1);
    *(volatile u32 *)(unsigned long)(v0 + (-27480)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(t6 + (0));
    s8 = *(volatile u32 *)(unsigned long)(a3 + (0));
    t2 = t2 & 0xfff;
    s8 = s8 >> (0x16 & 31);
    t2 = t2 << (0xa & 31);
    t2 = t2 | s8;
    s8 = a0 + 8;
    *(volatile u32 *)(unsigned long)(v0 + (-23384)) = t2;
    s8 = a1 + s8;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (0));
    t6 = *(volatile u32 *)(unsigned long)(t6 + (0));
    t2 = t2 & 0x3;
    t6 = t6 >> (0xc & 31);
    t2 = t2 << (0x14 & 31);
    t2 = t2 | t6;
    *(volatile u32 *)(unsigned long)(v0 + (-19288)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (0));
    t6 = a0 + 12;
    t6 = a1 + t6;
    t2 = (t2 >> 0x2) & ((1U << 0x16) - 1);
    *(volatile u32 *)(unsigned long)(v0 + (-15192)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(t6 + (0));
    s8 = *(volatile u8 *)(unsigned long)(s8 + (3));
    t2 = t2 & 0x3f;
    t2 = t2 << (0x8 & 31);
    t2 = t2 | s8;
    *(volatile u32 *)(unsigned long)(v0 + (-11096)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(t6 + (0));
    s8 = a0 + 16;
    s8 = a1 + s8;
    t2 = (t2 >> 0x6) & ((1U << 0x16) - 1);
    *(volatile u32 *)(unsigned long)(v0 + (-7000)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(s8 + (0));
    t6 = *(volatile u32 *)(unsigned long)(t6 + (0));
    a0 = a0 + 20;
    t2 = (t2 >> 0x0) & ((1U << 0x12) - 1);
    t6 = t6 >> (0x1c & 31);
    t2 = t2 << (0x4 & 31);
    t2 = t2 | t6;
    *(volatile u32 *)(unsigned long)(v0 + (-2904)) = t2;
    a0 = a1 + a0;
    t2 = *(volatile u8 *)(unsigned long)(a0 + (0));
    t6 = *(volatile u32 *)(unsigned long)(s8 + (0));
    t2 = t2 << (0xe & 31);
    t6 = t6 >> (0x12 & 31);
    t2 = t2 | t6;
    *(volatile u32 *)(unsigned long)(v0 + (1192)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t2 = (t2 >> 0x8) & ((1U << 0x16) - 1);
    *(volatile u32 *)(unsigned long)(v0 + (5288)) = t2;
    t2 = (u32)a2 < (u32)(s0);
    branch = (t2 == 0); ;
    if (branch) goto L_3cfb8;
    goto L_3cf78;
L_3cf78:
    branch = (t1 != 0); v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    if (branch) goto L_3cf88;
    goto L_3cf80;
L_3cf80:
    a0 = *(volatile u32 *)(unsigned long)(a3 + (96)); goto L_3cfa4;
L_3cf88:
    branch = (t1 != s1); ;
    if (branch) goto L_3cf98;
    goto L_3cf90;
L_3cf90:
    a0 = *(volatile u16 *)(unsigned long)(a3 + (74)); goto L_3cfa4;
L_3cf98:
    if (t1 != s2) { a0 = *(volatile u16 *)(unsigned long)(a3 + (30)); goto L_3cfa4; }
    goto L_3cfa0;
L_3cfa0:
    a0 = *(volatile u32 *)(unsigned long)(a3 + (52));
L_3cfa4:
    a0 = a0 & 0xfff;
    a0 = a0 << (0x2 & 31);
    v1 = v1 >> (0x1e & 31);
    v1 = a0 | v1; goto L_3d010;
L_3cfb8:
    branch = (t1 != 0); ;
    if (branch) goto L_3cfd4;
    goto L_3cfc0;
L_3cfc0:
    v1 = t7 + v1;
    v1 = v1 << (0x2 & 31);
    v1 = a1 + v1;
    v1 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_3cffc;
L_3cfd4:
    branch = (t1 != s1); v1 = t7 + v1;
    if (branch) goto L_3cfec;
    goto L_3cfdc;
L_3cfdc:
    v1 = v1 << (0x2 & 31);
    v1 = a1 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (2)); goto L_3cffc;
L_3cfec:
    if (t1 != s2) { a2 = a2 + 1; goto L_3d018; }
    goto L_3cff4;
L_3cff4:
    a3 = a3 + t8;
    v1 = *(volatile u32 *)(unsigned long)(a3 + (0));
L_3cffc:
    v1 = v1 & 0xfff;
    a3 = v1 << (0x2 & 31);
    v1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v1 = v1 >> (0x1e & 31);
    v1 = a3 | v1;
L_3d010:
    *(volatile u32 *)(unsigned long)(v0 + (9384)) = v1;
    a2 = a2 + 1;
L_3d018:
    a2 = a2 & 0xffff;
    t7 = t7 + -6;
    t8 = t8 + -24; goto L_3ce54;
L_3d028:
    t3 = t3 + 1;
    t5 = t0 + t5;
    t3 = t3 & 0xffff;
    t5 = t5 & 0xffff; goto L_3ce3c;
L_3d03c:
    s8 = *(volatile u32 *)(unsigned long)(sp + (44));
    s7 = *(volatile u32 *)(unsigned long)(sp + (40));
    s6 = *(volatile u32 *)(unsigned long)(sp + (36));
    s5 = *(volatile u32 *)(unsigned long)(sp + (32));
    s4 = *(volatile u32 *)(unsigned long)(sp + (28));
    s3 = *(volatile u32 *)(unsigned long)(sp + (24));
    s2 = *(volatile u32 *)(unsigned long)(sp + (20));
    s1 = *(volatile u32 *)(unsigned long)(sp + (16));
    s0 = *(volatile u32 *)(unsigned long)(sp + (12));
    sp = sp + 48;
    return ((u64)v1 << 32) | v0;
}
