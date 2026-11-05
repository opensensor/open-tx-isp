/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_log2_int_to_fixed(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_1e0ac:
    a1 = a1 & 0xff;
    a2 = a2 & 0xff;
    branch = (a0 == 0); v0 = 0;
    if (branch) goto L_1e1a8;
    goto L_1e0bc;
L_1e0bc:
    a3 = 0x1U << 16;
    a3 = (u32)a0 < (u32)(a3);
    if (a3 != 0) { t0 = a0; goto L_1e0d8; }
    goto L_1e0cc;
L_1e0cc:
    t0 = a0 >> (0x10 & 31);
    v1 = 16; goto L_1e0dc;
L_1e0d8:
    v1 = 0;
L_1e0dc:
    v0 = (u32)t0 < (u32)(256);
    branch = (v0 != 0); v0 = (u32)t0 < (u32)(16);
    if (branch) goto L_1e0f8;
    goto L_1e0e8;
L_1e0e8:
    a3 = v1 + 8;
    t0 = t0 >> (0x8 & 31);
    v1 = a3 & 0xff;
    v0 = (u32)t0 < (u32)(16);
L_1e0f8:
    branch = (v0 != 0); v0 = (u32)t0 < (u32)(4);
    if (branch) goto L_1e110;
    goto L_1e100;
L_1e100:
    a3 = v1 + 4;
    t0 = t0 >> (0x4 & 31);
    v1 = a3 & 0xff;
    v0 = (u32)t0 < (u32)(4);
L_1e110:
    branch = (v0 != 0); v0 = 1;
    if (branch) goto L_1e124;
    goto L_1e118;
L_1e118:
    a3 = v1 + 2;
    t0 = t0 >> (0x2 & 31);
    v1 = a3 & 0xff;
L_1e124:
    branch = (t0 == v0); a3 = v1 + 1;
    if (branch) goto L_1e130;
    goto L_1e12c;
L_1e12c:
    v1 = a3 & 0xff;
L_1e130:
    v0 = (u32)v1 < (u32)(16);
    if (v0 == 0) { v0 = v1 + -15; goto L_1e154; }
    goto L_1e13c;
L_1e13c:
    a3 = 15;
    a3 = a3 - v1;
    a0 = a0 << (a3 & 31);
L_1e148:
    v0 = 0;
    a3 = 0; goto L_1e170;
L_1e154:
    a0 = a0 >> (v0 & 31); goto L_1e148;
L_1e15c:
    branch = ((s32)a0 >= 0); v0 = v0 << (0x1 & 31);
    if (branch) goto L_1e184;
    goto L_1e164;
L_1e164:
    v0 = v0 + 1;
    a0 = a0 >> (0x10 & 31);
L_1e16c:
    a3 = a3 + 1;
L_1e170:
    t0 = (s32)a3 < (s32)(a1);
    if (t0 != 0) { a0 = a0 * a0; goto L_1e15c; }
    goto L_1e17c;
L_1e17c:
    v1 = v1 << (a1 & 31); goto L_1e18c;
L_1e184:
    a0 = a0 >> (0xf & 31); goto L_1e16c;
L_1e18c:
    v0 = v1 + v0;
    v1 = v0 << (a2 & 31);
    v0 = 15;
    a0 = a0 & 0x7fff;
    v0 = v0 - a2;
    v0 = a0 >> (v0 & 31);
    v0 = v1 | v0;
L_1e1a8:
    ;
    return ((u64)v1 << 32) | v0;
}
