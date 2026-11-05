/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
u64 tisp_sdns_param_scale(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    sp = (u32)(unsigned long)&stack[0];
L_76920:
    v0 = a0 & 0xffff;
    v1 = (u32)v0 < (u32)(65);
    branch = (v1 != 0); v1 = (u32)v0 < (u32)(129);
    if (branch) goto L_76988;
    goto L_76930;
L_76930:
    if (v1 == 0) { v1 = (u32)v0 < (u32)(193); goto L_76948; }
    goto L_76938;
L_76938:
    v0 = v0 + -48;
    v0 = v0 << (0x2 & 31);
    v0 = v0 & 0xfffc;
    return ((u64)v1 << 32) | v0;
L_76948:
    if (v1 == 0) { v1 = (u32)v0 < (u32)(256); goto L_76960; }
    goto L_76950;
L_76950:
    v0 = v0 + -108;
    v0 = v0 << (0x4 & 31);
    v0 = v0 & 0xfff0;
    return ((u64)v1 << 32) | v0;
L_76960:
    branch = (v1 == 0); ;
    if (branch) goto L_76988;
    goto L_76968;
L_76968:
    v0 = v0 + -150;
    v0 = v0 << (0x5 & 31);
    a0 = v0 & 0xffe0;
    v0 = a0;
    a0 = (u32)a0 < (u32)(3061);
    if (a0 == 0) { v0 = 3060; goto L_76984; }
    goto L_76984;
L_76984:
    v0 = v0 & 0xffff;
L_76988:
    ;
    return ((u64)v1 << 32) | v0;
}
