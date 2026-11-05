/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_ce1f0[] __asm__("t32_data_ce1f0");
extern unsigned char ref_t32_data_ce1e0[] __asm__("t32_data_ce1e0");
extern unsigned char ref_t32_data_ce1d0[] __asm__("t32_data_ce1d0");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 tisp_lce_std_hist_transform_simd(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[64] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_5401c = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_54028 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_54064 = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[0];
    stack[4] = arg4;
L_5401c:
    v0 = hi_5401c;
    v0 = v0 - hi_5401c + (u32)(unsigned long)ref_t32_data_ce1f0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_54028;
    v0 = v0 - hi_54028 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a3; vx[9] = tmp; }
    a2 = a1 + 32;
    a3 = a1 + 16;
    a0 = a1 + 48;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    v0 = hi_54064;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] * (u32)vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[1].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (vx[9].w[i] & 31); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[7].w[i] >> (vx[9].w[i] & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[11].w[i] >> (vx[9].w[i] & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (vx[9].w[i] & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (vx[9].w[i] & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[10].w[i] >> (vx[9].w[i] & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] + (u32)vx[6].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[3].w[i] >> (vx[9].w[i] & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[8].w[i] >> (vx[9].w[i] & 31); vx[3] = tmp; }
    v0 = v0 - hi_54064 + (u32)(unsigned long)ref_t32_data_ce1d0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[7].w[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[4].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[5].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[6].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[2].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[4].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[3].w[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[1].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    v1 = (s32)vx[0].w[1];
    v0 = (s32)vx[0].w[0];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[1].b[i]; }
    v0 = v0 + v1;
    v1 = (s32)vx[0].w[2];
    v1 = v0 + v1;
    v0 = (s32)vx[0].w[3];
    v0 = v1 + v0;
    v1 = 0x8000;
    t0 = (s32)v0 < (s32)(v1);
    branch = (t0 == 0); t0 = a1;
    if (branch) goto L_54198;
    goto L_54130;
L_54130:
    v0 = v1 - v0;
    v1 = (s32)v0 >> (0x5 & 31);
    v0 = v0 & 0x1f;
    t1 = 0;
L_54140:
    branch = (t1 == v0); t1 = t1 + 1;
    if (branch) goto L_5415c;
    goto L_54148;
L_54148:
    t2 = *(volatile u16 *)(unsigned long)(t0 + (0));
    t0 = t0 + 2;
    t2 = t2 + 1;
    *(volatile u16 *)(unsigned long)(t0 + (-2)) = t2; goto L_54140;
L_5415c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = v1; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[4].h[i] + (u16)vx[0].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[3].h[i] + (u16)vx[0].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[0].h[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[0].h[i]; vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[0].b[i]; }
L_54190:
    ;
    return ((u64)v1 << 32) | v0;
L_54198:
    branch = (v0 == v1); v1 = *(volatile u32 *)(unsigned long)(sp + (16));
    if (branch) goto L_54190;
    goto L_541a0;
L_541a0:
    v0 = v0 + -32768;
    *(volatile u16 *)(unsigned long)(v1 + (0)) = v0;
    ;
    return ((u64)v1 << 32) | v0;
}
