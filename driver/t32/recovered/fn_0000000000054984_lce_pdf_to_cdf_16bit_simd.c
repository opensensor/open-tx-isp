/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_ce1f0[] __asm__("t32_data_ce1f0");
extern unsigned char ref_t32_data_ce1e0[] __asm__("t32_data_ce1e0");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 lce_pdf_to_cdf_16bit_simd(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[80] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_5498c = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_54990 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[16];
L_54984:
    a2 = 32767;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a2; vx[2] = tmp; }
    a3 = hi_5498c;
    a2 = hi_54990;
    a3 = a3 - hi_5498c + (u32)(unsigned long)ref_t32_data_ce1f0;
    a2 = a2 - hi_54990 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 0; vx[0] = tmp; }
    v0 = a0;
    v1 = a1;
    t0 = a0 + 16;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[6] = tmp; }
    sp = sp + -64;
L_549c4:
    t1 = *(volatile u16 *)(unsigned long)(v0 + (0));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (15 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (15 & 31); vx[3] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (32)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (64));
    v0 = v0 + 2;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] < vx[4].w[i]) ? ~0U : 0; vx[4] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (34)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (126));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] < vx[3].w[i]) ? ~0U : 0; vx[3] = tmp; }
    v1 = v1 + 1;
    *(volatile u16 *)(unsigned long)(sp + (36)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (190));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[4].w[i]) | (vx[2].w[i] & vx[4].w[i]); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[3].w[i]) | (vx[2].w[i] & vx[3].w[i]); vx[1] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (38)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (254));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (7 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[3] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (40)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (318));
    *(volatile u16 *)(unsigned long)(sp + (42)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (382));
    *(volatile u16 *)(unsigned long)(sp + (44)) = t1;
    t1 = *(volatile u16 *)(unsigned long)(v0 + (446));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (0)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (16)))[i] = vx[3].b[i]; }
    *(volatile u16 *)(unsigned long)(sp + (46)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (0));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[4] = tmp; }
    *(volatile u8 *)(unsigned long)(v1 + (-1)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (4));
    *(volatile u8 *)(unsigned long)(v1 + (19)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (8));
    *(volatile u8 *)(unsigned long)(v1 + (39)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (12));
    *(volatile u8 *)(unsigned long)(v1 + (59)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u8 *)(unsigned long)(v1 + (79)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (20));
    *(volatile u8 *)(unsigned long)(v1 + (99)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (24));
    *(volatile u8 *)(unsigned long)(v1 + (119)) = t1;
    t1 = *(volatile u32 *)(unsigned long)(sp + (28));
    *(volatile u8 *)(unsigned long)(v1 + (139)) = t1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(sp + (32)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[7].w[i]; vx[0] = tmp; }
    branch = (v0 != t0); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[3].w[i]; vx[1] = tmp; }
    if (branch) goto L_549c4;
    goto L_54a90;
L_54a90:
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a1 = a1 + 8;
    v1 = 0;
    a2 = 12;
L_54aa4:
    v0 = v1 << (0x2 & 31);
    v0 = a0 + v0;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (16));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (15 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (15 & 31); vx[3] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (32)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (80));
    v1 = v1 + 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] < vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (34)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (144));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] < vx[3].w[i]) ? ~0U : 0; vx[3] = tmp; }
    a1 = a1 + 1;
    *(volatile u16 *)(unsigned long)(sp + (36)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (208));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[3].w[i]) | (vx[2].w[i] & vx[3].w[i]); vx[1] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (38)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (272));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[0].w[i] >> (7 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[1].w[i] >> (7 & 31); vx[3] = tmp; }
    *(volatile u16 *)(unsigned long)(sp + (40)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (336));
    *(volatile u16 *)(unsigned long)(sp + (42)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (400));
    *(volatile u16 *)(unsigned long)(sp + (44)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (464));
    *(volatile u16 *)(unsigned long)(sp + (46)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (18));
    *(volatile u16 *)(unsigned long)(sp + (48)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (82));
    *(volatile u16 *)(unsigned long)(sp + (50)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (146));
    *(volatile u16 *)(unsigned long)(sp + (52)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (210));
    *(volatile u16 *)(unsigned long)(sp + (54)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (274));
    *(volatile u16 *)(unsigned long)(sp + (56)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (338));
    *(volatile u16 *)(unsigned long)(sp + (58)) = a3;
    a3 = *(volatile u16 *)(unsigned long)(v0 + (402));
    v0 = *(volatile u16 *)(unsigned long)(v0 + (466));
    *(volatile u16 *)(unsigned long)(sp + (60)) = a3;
    *(volatile u16 *)(unsigned long)(sp + (62)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (0)))[i] = vx[6].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (0));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (16)))[i] = vx[3].b[i]; }
    *(volatile u8 *)(unsigned long)(a1 + (-1)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (4));
    *(volatile u8 *)(unsigned long)(a1 + (19)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (8));
    *(volatile u8 *)(unsigned long)(a1 + (39)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (12));
    *(volatile u8 *)(unsigned long)(a1 + (59)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (16));
    *(volatile u8 *)(unsigned long)(a1 + (79)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (20));
    *(volatile u8 *)(unsigned long)(a1 + (99)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (24));
    *(volatile u8 *)(unsigned long)(a1 + (119)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (28));
    *(volatile u8 *)(unsigned long)(a1 + (139)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(sp + (32)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[6].w[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[3].w[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(sp + (48)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[0].w[i] + (u32)vx[6].w[i]; vx[0] = tmp; }
    branch = (v1 != a2); { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] + (u32)vx[3].w[i]; vx[1] = tmp; }
    if (branch) goto L_54aa4;
    goto L_54bc8;
L_54bc8:
    sp = sp + 64;
    return ((u64)v1 << 32) | v0;
}
