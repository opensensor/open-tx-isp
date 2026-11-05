/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 lce_hist_filter_and_judge_16bit_simd(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[70] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    sp = (u32)(unsigned long)&stack[6];
    stack[10] = arg4;
L_54318:
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 0; vx[0] = tmp; }
    sp = sp + -24;
    v0 = *(volatile u32 *)(unsigned long)(sp + (40));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = -1; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[1] = tmp; }
    *(volatile u32 *)(unsigned long)(sp + (16)) = 0;
L_54334:
    a2 = *(volatile u32 *)(unsigned long)(sp + (16));
    v1 = (s32)a2 < (s32)(32);
    branch = (v1 == 0); v1 = a2 << (0x1 & 31);
    if (branch) goto L_5442c;
    goto L_54344;
L_54344:
    a1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(sp + (16)))[i]; }
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    a2 = a2 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[3].h[0]; vx[3] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (0)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (2));
    *(volatile u32 *)(unsigned long)(sp + (16)) = a2;
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (2)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (4));
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (4)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (6));
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (6)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (8));
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (8)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (10));
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (10)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (12));
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    a1 = a1 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (12)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v0 + (14));
    a1 = a1 << (0x6 & 31);
    a1 = a0 + a1;
    v1 = a1 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    *(volatile u16 *)(unsigned long)(sp + (14)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(sp + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[0].h[i] + vx[4].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[0].h[i] + vx[4].h[i]); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[2].h[i] < vx[0].h[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[4].w[i]) | (vx[5].w[i] & vx[4].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[4].w[i]) | (vx[3].w[i] & vx[4].w[i]); vx[1] = tmp; } goto L_54334;
L_5442c:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[1].b[i]; }
    sp = sp + 24;
    return ((u64)v1 << 32) | v0;
}
