/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_d6b50[] __asm__("t32_data_d6b50");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 lce_self_light_correct_local_simd_test(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[68] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_54bdc = ((u32)(unsigned long)ref_t32_data_d6b50 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[4];
    stack[8] = arg4;
L_54bd0:
    sp = sp + -16;
    v0 = *(volatile u8 *)(unsigned long)(a2 + (8));
    a2 = *(volatile u32 *)(unsigned long)(sp + (32));
    v1 = hi_54bdc;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 0; vx[8] = tmp; }
    v1 = v1 - hi_54bdc + (u32)(unsigned long)ref_t32_data_d6b50;
    t0 = a3 + 20;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i] != 0) ? ~0U : 0; vx[4] = tmp; }
L_54bf4:
    v0 = *(volatile u8 *)(unsigned long)(v1 + (0));
    a3 = a3 + 1;
    v1 = v1 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v0; vx[5] = tmp; }
    v0 = *(volatile u8 *)(unsigned long)(a3 + (-1));
    a2 = a2 + 1;
    a0 = a0 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v0; vx[1] = tmp; }
    v0 = *(volatile u8 *)(unsigned long)(a2 + (-1));
    a1 = a1 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v0; vx[3] = tmp; }
    v0 = *(volatile u8 *)(unsigned long)(a0 + (-1));
    *(volatile u16 *)(unsigned long)(sp + (0)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (19));
    *(volatile u16 *)(unsigned long)(sp + (2)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (39));
    *(volatile u16 *)(unsigned long)(sp + (4)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (59));
    *(volatile u16 *)(unsigned long)(sp + (6)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (79));
    *(volatile u16 *)(unsigned long)(sp + (8)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (99));
    *(volatile u16 *)(unsigned long)(sp + (10)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (119));
    *(volatile u16 *)(unsigned long)(sp + (12)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a0 + (139));
    *(volatile u16 *)(unsigned long)(sp + (14)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(sp + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] - (u16)vx[5].h[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[0].h[i] * (u32)vx[1].h[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[8].h[i]  < (s16)vx[0].h[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[0].h[i] * (u32)vx[3].h[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[0].h[i]  < (s16)vx[8].h[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[1].h[i] >> (7 & 15); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[7].w[i] & vx[4].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[2].h[i] >> (7 & 15); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[6].w[i] & vx[4].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[1].w[i] & vx[7].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[0].h[i] + (u16)vx[5].h[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u16 *)(unsigned long)(sp + (0));
    *(volatile u8 *)(unsigned long)(a1 + (-1)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (2));
    *(volatile u8 *)(unsigned long)(a1 + (19)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (4));
    *(volatile u8 *)(unsigned long)(a1 + (39)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (6));
    *(volatile u8 *)(unsigned long)(a1 + (59)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (8));
    *(volatile u8 *)(unsigned long)(a1 + (79)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (10));
    *(volatile u8 *)(unsigned long)(a1 + (99)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (12));
    *(volatile u8 *)(unsigned long)(a1 + (119)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(sp + (14));
    branch = (a3 != t0); *(volatile u8 *)(unsigned long)(a1 + (139)) = v0;
    if (branch) goto L_54bf4;
    goto L_54cdc;
L_54cdc:
    sp = sp + 16;
    return ((u64)v1 << 32) | v0;
}
