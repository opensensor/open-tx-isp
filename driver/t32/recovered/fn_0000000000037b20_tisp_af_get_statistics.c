/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_e1620[] __asm__("t32_data_e1620");
u64 tisp_af_get_statistics(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[78] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    const u32 hi_37b28 = ((u32)(unsigned long)ref_t32_data_e1620 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[14];
L_37b20:
    a0 = a0 & 0xff;
    v0 = a0 << (0x2 & 31);
    a0 = hi_37b28;
    sp = sp + -56;
    a0 = a0 - hi_37b28 + (u32)(unsigned long)ref_t32_data_e1620;
    a0 = v0 + a0;
    *(volatile u32 *)(unsigned long)(sp + (24)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (52)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (48)) = s7;
    *(volatile u32 *)(unsigned long)(sp + (44)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (40)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (36)) = s4;
    *(volatile u32 *)(unsigned long)(sp + (32)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (28)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (20)) = s0;
    t1 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = *(volatile u32 *)(unsigned long)(t1 + (4));
    a0 = *(volatile u8 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u8 *)(unsigned long)(v0 + (1));
    a2 = a0 >> (0x3 & 31);
    *(volatile u32 *)(unsigned long)(sp + (4)) = v0;
    v0 = a2 << (0x3 & 31);
    t9 = a0 & 0xffff;
    s1 = v0 & 0xffff;
    v1 = t9 - s1;
    a3 = a0 & 0x7;
    branch = (a3 != 0); v1 = v1 & 0xffff;
    if (branch) goto L_37ba0;
    goto L_37b90;
L_37b90:
    v1 = v0 + v1;
    v1 = v1 << (0x1 & 31);
    v0 = v1 + a2; goto L_37bb0;
L_37ba0:
    v0 = v0 + v1;
    v1 = v0 << (0x1 & 31);
    v0 = a2 + 1;
    v0 = v1 + v0;
L_37bb0:
    v0 = v0 << (0x1 & 31);
    v0 = v0 & 0xffff;
    *(volatile u32 *)(unsigned long)(sp + (0)) = v0;
    v0 = a0 << (0x2 & 31);
    a0 = a0 << (0x4 & 31);
    *(volatile u32 *)(unsigned long)(sp + (8)) = v0;
    v0 = a0 + 4;
    *(volatile u32 *)(unsigned long)(sp + (12)) = v0;
    t5 = 2;
    t6 = 0;
    t4 = 0;
    s2 = 1;
    s3 = 2;
    s4 = 3;
    s5 = 4;
    s6 = 5;
    s7 = 6;
L_37bf4:
    v0 = *(volatile u32 *)(unsigned long)(sp + (4));
    v0 = (u32)t4 < (u32)(v0);
    branch = (v0 == 0); s0 = *(volatile u32 *)(unsigned long)(sp + (12));
    if (branch) goto L_37ea8;
    goto L_37c04;
L_37c04:
    t3 = *(volatile u32 *)(unsigned long)(sp + (8));
    a3 = 0;
L_37c0c:
    v0 = (u32)a3 < (u32)(t9);
    branch = (v0 == 0); v1 = a3 >> (0x3 & 31);
    if (branch) goto L_37e88;
    goto L_37c18;
L_37c18:
    t0 = 34;
    t2 = v1 * t0;
    a2 = a3 & 0x7;
    a0 = a2 << (0x2 & 31);
    t7 = *(volatile u32 *)(unsigned long)(t1 + (0));
    v0 = a3 + t6;
    v0 = v0 & 0xffff;
    v1 = t2 + a0;
    v1 = t5 + v1;
    v1 = v1 & 0xffff;
    t0 = v1 << (0x2 & 31);
    a0 = a1 + t0;
    t2 = v0 << (0x2 & 31);
    t2 = t7 + t2;
    t7 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t8 = t0 + 4;
    t8 = a1 + t8;
    t7 = (t7 >> 0x0) & ((1U << 0x17) - 1);
    *(volatile u32 *)(unsigned long)(t2 + (0)) = t7;
    t2 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t7 = v0 + 224;
    t7 = t7 << (0x2 & 31);
    t7 = t2 + t7;
    t2 = *(volatile u32 *)(unsigned long)(t8 + (0));
    s8 = *(volatile u32 *)(unsigned long)(a0 + (0));
    t2 = t2 & 0x3fff;
    s8 = s8 >> (0x17 & 31);
    t2 = t2 << (0x9 & 31);
    t2 = t2 | s8;
    *(volatile u32 *)(unsigned long)(t7 + (4)) = t2;
    t2 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t7 = t0 + 8;
    s8 = v0 + 448;
    t7 = a1 + t7;
    s8 = s8 << (0x2 & 31);
    s8 = t2 + s8;
    t2 = *(volatile u32 *)(unsigned long)(t7 + (0));
    t8 = *(volatile u32 *)(unsigned long)(t8 + (0));
    t0 = t0 + 12;
    t2 = t2 & 0x1f;
    t8 = t8 >> (0xe & 31);
    t2 = t2 << (0x12 & 31);
    t2 = t2 | t8;
    *(volatile u32 *)(unsigned long)(s8 + (8)) = t2;
    t8 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t2 = v0 + 672;
    t2 = t2 << (0x2 & 31);
    t2 = t8 + t2;
    t8 = *(volatile u32 *)(unsigned long)(t7 + (0));
    t0 = a1 + t0;
    t8 = (t8 >> 0x5) & ((1U << 0x17) - 1);
    *(volatile u32 *)(unsigned long)(t2 + (12)) = t8;
    t2 = *(volatile u32 *)(unsigned long)(t1 + (0));
    t8 = v0 + 900;
    t8 = t8 << (0x2 & 31);
    t8 = t2 + t8;
    t2 = *(volatile u32 *)(unsigned long)(t0 + (0));
    t7 = *(volatile u32 *)(unsigned long)(t7 + (0));
    v0 = v0 + 1124;
    t2 = (t2 >> 0x0) & ((1U << 0x14) - 1);
    t7 = t7 >> (0x1c & 31);
    t2 = t2 << (0x4 & 31);
    t2 = t2 | t7;
    *(volatile u32 *)(unsigned long)(t8 + (0)) = t2;
    t7 = (u32)a3 < (u32)(s1);
    t2 = *(volatile u32 *)(unsigned long)(t1 + (0));
    branch = (t7 == 0); t0 = *(volatile u32 *)(unsigned long)(t0 + (0));
    if (branch) goto L_37da4;
    goto L_37d28;
L_37d28:
    v0 = v0 << (0x2 & 31);
    branch = (a2 != 0); t2 = t2 + v0;
    if (branch) goto L_37d3c;
    goto L_37d34;
L_37d34:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (128)); goto L_37d78;
L_37d3c:
    branch = (a2 != s2); ;
    if (branch) goto L_37d4c;
    goto L_37d44;
L_37d44:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (112)); goto L_37e48;
L_37d4c:
    branch = (a2 != s3); ;
    if (branch) goto L_37d5c;
    goto L_37d54;
L_37d54:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (96)); goto L_37e58;
L_37d5c:
    branch = (a2 != s4); ;
    if (branch) goto L_37d6c;
    goto L_37d64;
L_37d64:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (80)); goto L_37e60;
L_37d6c:
    branch = (a2 != s5); ;
    if (branch) goto L_37d84;
    goto L_37d74;
L_37d74:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (68));
L_37d78:
    v0 = v0 << (0xc & 31);
    v0 = v0 & 0xffff; goto L_37e68;
L_37d84:
    branch = (a2 != s6); ;
    if (branch) goto L_37d94;
    goto L_37d8c;
L_37d8c:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (52)); goto L_37e48;
L_37d94:
    if (a2 != s7) { v0 = *(volatile u32 *)(unsigned long)(a0 + (20)); goto L_37e60; }
    goto L_37d9c;
L_37d9c:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (36)); goto L_37e58;
L_37da4:
    branch = (a2 != 0); ;
    if (branch) goto L_37dc8;
    goto L_37dac;
L_37dac:
    v1 = t3 + v1;
    v1 = v1 << (0x2 & 31);
    v0 = v0 << (0x2 & 31);
    v1 = a1 + v1;
    t2 = t2 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_37d78;
L_37dc8:
    branch = (a2 != s2); ;
    if (branch) goto L_37dec;
    goto L_37dd0;
L_37dd0:
    v1 = t3 + v1;
    v1 = v1 << (0x2 & 31);
    v0 = v0 << (0x2 & 31);
    v1 = a1 + v1;
    t2 = t2 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_37e48;
L_37dec:
    branch = (a2 != s3); ;
    if (branch) goto L_37e10;
    goto L_37df4;
L_37df4:
    v1 = t3 + v1;
    v1 = v1 << (0x2 & 31);
    v0 = v0 << (0x2 & 31);
    v1 = a1 + v1;
    t2 = t2 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_37e58;
L_37e10:
    branch = (a2 != s4); v0 = v0 << (0x2 & 31);
    if (branch) goto L_37e30;
    goto L_37e18;
L_37e18:
    v1 = t3 + v1;
    v1 = v1 << (0x2 & 31);
    v1 = a1 + v1;
    t2 = t2 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v1 + (0)); goto L_37e60;
L_37e30:
    a0 = a0 + s0;
    t2 = t2 + v0;
    branch = (a2 == s5); v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    if (branch) goto L_37d78;
    goto L_37e40;
L_37e40:
    branch = (a2 != s6); ;
    if (branch) goto L_37e50;
    goto L_37e48;
L_37e48:
    v0 = (v0 >> 0x8) & ((1U << 0x4) - 1); goto L_37e64;
L_37e50:
    if (a2 != s7) { v0 = (v0 >> 0x18) & ((1U << 0x4) - 1); goto L_37e64; }
    goto L_37e58;
L_37e58:
    v0 = (v0 >> 0x10) & ((1U << 0x4) - 1); goto L_37e64;
L_37e60:
    v0 = (v0 >> 0x18) & ((1U << 0x4) - 1);
L_37e64:
    v0 = v0 << (0xc & 31);
L_37e68:
    t0 = t0 >> (0x14 & 31);
    t0 = v0 | t0;
    a3 = a3 + 1;
    *(volatile u32 *)(unsigned long)(t2 + (4)) = t0;
    a3 = a3 & 0xffff;
    t3 = t3 + -4;
    s0 = s0 + -16; goto L_37c0c;
L_37e88:
    v0 = *(volatile u32 *)(unsigned long)(sp + (0));
    t4 = t4 + 1;
    t6 = t9 + t6;
    t5 = v0 + t5;
    t4 = t4 & 0xffff;
    t6 = t6 & 0xffff;
    t5 = t5 & 0xffff; goto L_37bf4;
L_37ea8:
    s8 = *(volatile u32 *)(unsigned long)(sp + (52));
    s7 = *(volatile u32 *)(unsigned long)(sp + (48));
    s6 = *(volatile u32 *)(unsigned long)(sp + (44));
    s5 = *(volatile u32 *)(unsigned long)(sp + (40));
    s4 = *(volatile u32 *)(unsigned long)(sp + (36));
    s3 = *(volatile u32 *)(unsigned long)(sp + (32));
    s2 = *(volatile u32 *)(unsigned long)(sp + (28));
    s1 = *(volatile u32 *)(unsigned long)(sp + (24));
    s0 = *(volatile u32 *)(unsigned long)(sp + (20));
    sp = sp + 56;
    return ((u64)v1 << 32) | v0;
}
