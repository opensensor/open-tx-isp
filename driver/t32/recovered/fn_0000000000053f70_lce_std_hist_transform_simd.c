/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 lce_std_hist_transform_simd(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    sp = (u32)(unsigned long)&stack[0];
L_53f70:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a2; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a3; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    t0 = a1 + 128;
    v0 = a1;
L_53f84:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = v0 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] * (u32)vx[3].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (vx[2].w[i] & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (-16)))[i] = vx[1].b[i]; }
    branch = (v0 != t0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[1].w[i]; vx[0] = tmp; }
    if (branch) goto L_53f84;
    goto L_53fa0;
L_53fa0:
    v1 = (s32)vx[0].w[1];
    v0 = (s32)vx[0].w[0];
    v0 = v0 + v1;
    v1 = (s32)vx[0].w[2];
    v0 = v0 + v1;
    v1 = (s32)vx[0].w[3];
    v0 = v0 + v1;
    v1 = 0x8000;
    a0 = (s32)v0 < (s32)(v1);
    branch = (a0 == 0); v0 = v1 - v0;
    if (branch) goto L_54014;
    goto L_53fcc;
L_53fcc:
    a0 = (s32)v0 >> (0x5 & 31);
    v1 = a1;
    v0 = v0 & 0x1f;
    a2 = 0;
L_53fdc:
    branch = (a2 == v0); a2 = a2 + 1;
    if (branch) goto L_53ff8;
    goto L_53fe4;
L_53fe4:
    a3 = *(volatile u32 *)(unsigned long)(v1 + (0));
    v1 = v1 + 4;
    a3 = a3 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (-4)) = a3; goto L_53fdc;
L_53ff8:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[1] = tmp; }
L_53ffc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    a1 = a1 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[1].w[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (-16)))[i] = vx[0].b[i]; }
    branch = (t0 != a1); ;
    if (branch) goto L_53ffc;
    goto L_54014;
L_54014:
    ;
    return ((u64)v1 << 32) | v0;
}
