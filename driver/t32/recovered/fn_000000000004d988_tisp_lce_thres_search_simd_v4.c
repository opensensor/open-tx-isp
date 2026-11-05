/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_ce1a0[] __asm__("t32_data_ce1a0");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 tisp_lce_thres_search_simd_v4(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[82] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_4db34 = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[18];
    stack[22] = arg4;
L_4d988:
    v0 = *(volatile u16 *)(unsigned long)(a0 + (0));
    sp = sp + -72;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    *(volatile u16 *)(unsigned long)(sp + (0)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (64));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 8; vx[10] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (2)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (128));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[0].h[0]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[0].h[1]; vx[12] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (4)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (192));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 16; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 24; vx[8] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (6)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (256));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[0].h[2]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] | vx[2].w[i]; vx[7] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (8)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (320));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[10].w[i] | vx[10].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[9].w[i] | vx[9].w[i]; vx[5] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (10)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (384));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[8].w[i] | vx[8].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[11].w[i] | vx[11].w[i]; vx[13] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (12)) = v0;
    v0 = *(volatile u16 *)(unsigned long)(a0 + (448));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[12].w[i] | vx[12].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[15] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (14)) = v0;
    *(volatile u32 *)(unsigned long)(sp + (64)) = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[3] = tmp; }
L_4da10:
    v0 = *(volatile u32 *)(unsigned long)(sp + (64));
    v1 = (s32)v0 < (s32)(32);
    branch = (v1 == 0); v1 = v0 + 256;
    if (branch) goto L_4db34;
    goto L_4da20;
L_4da20:
    v1 = v1 << (0x1 & 31);
    v1 = a0 + v1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(sp + (0)))[i]; }
    *(volatile u16 *)(unsigned long)(sp + (16)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (64));
    *(volatile u16 *)(unsigned long)(sp + (18)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (128));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (192));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[2].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[2].h[i] + vx[1].h[i]); vx[2] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (20)) = a1;
    *(volatile u16 *)(unsigned long)(sp + (22)) = v1;
    v1 = v0 + 384;
    v1 = v1 << (0x1 & 31);
    v1 = a0 + v1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(sp + (64)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[0].h[i] <= vx[2].h[i]) ? ~0U : 0; vx[16] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (24)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (64));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[11].h[i] <= vx[2].h[i]) ? ~0U : 0; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[12].h[i] <= vx[2].h[i]) ? ~0U : 0; vx[17] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (26)) = a1;
    a1 = *(volatile u16 *)(unsigned long)(v1 + (128));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (192));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[0]; vx[1] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (28)) = a1;
    a1 = v0 + 1;
    *(volatile u16 *)(unsigned long)(sp + (30)) = v1;
    v1 = a1 << (0x1 & 31);
    v1 = a0 + v1;
    t0 = *(volatile u16 *)(unsigned long)(v1 + (0));
    v0 = v0 + 129;
    v0 = v0 << (0x1 & 31);
    *(volatile u16 *)(unsigned long)(sp + (0)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(v1 + (64));
    v0 = a0 + v0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[8].w[i] & ~vx[16].w[i]) | (vx[1].w[i] & vx[16].w[i]); vx[8] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (2)) = t0;
    t0 = *(volatile u16 *)(unsigned long)(v1 + (128));
    v1 = *(volatile u16 *)(unsigned long)(v1 + (192));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[16].w[i]) | (vx[3].w[i] & vx[16].w[i]); vx[0] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (4)) = t0;
    *(volatile u16 *)(unsigned long)(sp + (6)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[18].w[i]) | (vx[1].w[i] & vx[18].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[17].w[i]) | (vx[1].w[i] & vx[17].w[i]); vx[9] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (8)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (64));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[18].w[i]) | (vx[3].w[i] & vx[18].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[17].w[i]) | (vx[3].w[i] & vx[17].w[i]); vx[12] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (10)) = v1;
    v1 = *(volatile u16 *)(unsigned long)(v0 + (128));
    *(volatile u16 *)(unsigned long)(sp + (12)) = v1;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (192));
    { unsigned int i; for (i = 0; i < 16; i++) vx[16].b[i] = ((volatile u8 *)(unsigned long)(sp + (16)))[i]; }
    *(volatile u32 *)(unsigned long)(sp + (64)) = a1;
    *(volatile u16 *)(unsigned long)(sp + (14)) = v0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[16].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[16].h[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[13].h[i] <= vx[7].h[i]) ? ~0U : 0; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] <= vx[7].h[i]) ? ~0U : 0; vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[15].h[i] <= vx[7].h[i]) ? ~0U : 0; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[18].w[i]) | (vx[1].w[i] & vx[18].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[17].w[i]) | (vx[1].w[i] & vx[17].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[16].w[i]) | (vx[1].w[i] & vx[16].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[18].w[i]) | (vx[3].w[i] & vx[18].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[17].w[i]) | (vx[3].w[i] & vx[17].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[16].w[i]) | (vx[3].w[i] & vx[16].w[i]); vx[15] = tmp; } goto L_4da10;
L_4db34:
    v0 = hi_4db34;
    v0 = v0 - hi_4db34 + (u32)(unsigned long)ref_t32_data_ce1a0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (88));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[0].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[0].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[0].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    sp = sp + 72;
    return ((u64)v1 << 32) | v0;
}
