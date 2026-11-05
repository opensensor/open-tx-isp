/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_ce1b0[] __asm__("t32_data_ce1b0");
extern unsigned char ref_t32_data_ce1c0[] __asm__("t32_data_ce1c0");
extern unsigned char ref_t32_data_ce1a0[] __asm__("t32_data_ce1a0");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 lce_16bit_data_converge_16bit_simd(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[68] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_541b4 = ((u32)(unsigned long)ref_t32_data_ce1b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_541c4 = ((u32)(unsigned long)ref_t32_data_ce1c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_54210 = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[4];
    stack[8] = arg4;
L_541b0:
    sp = sp + -16;
    v1 = hi_541b4;
    v1 = v1 - hi_541b4 + (u32)(unsigned long)ref_t32_data_ce1b0;
    v0 = *(volatile u32 *)(unsigned long)(sp + (32));
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v1 = hi_541c4;
    v1 = v1 - hi_541c4 + (u32)(unsigned long)ref_t32_data_ce1c0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[8] = tmp; }
    a0 = (int8_t)a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a0; vx[11] = tmp; }
    a2 = (int8_t)a2;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[10].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a2; vx[2] = tmp; }
    a1 = (int8_t)a1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[1].h[i] > (s16)vx[10].h[i] ? (s64)(s16)vx[1].h[i] - (s64)(s16)vx[10].h[i] : (s64)(s16)vx[10].h[i] - (s64)(s16)vx[1].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[15].h[i] > (s16)vx[16].h[i] ? (s64)(s16)vx[15].h[i] - (s64)(s16)vx[16].h[i] : (s64)(s16)vx[16].h[i] - (s64)(s16)vx[15].h[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = a1; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] | vx[15].w[i]; vx[14] = tmp; }
    v1 = hi_54210;
    v1 = v1 - hi_54210 + (u32)(unsigned long)ref_t32_data_ce1a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[16].h[i] + (u16)vx[0].h[i]; vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] * (u32)vx[11].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[5].h[i] * (u32)vx[11].h[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[0].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[14].h[i] + (u16)vx[0].h[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[17].h[i]  < (s16)vx[15].h[i]) ? ~0U : 0; vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] | vx[2].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s64)(s16)vx[4].h[i] >> (7 & 15)) + ((7 & 15) ? ((vx[4].h[i] >> (((7 & 15) - 1) & 15)) & 1) : 0); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s64)(s16)vx[5].h[i] >> (7 & 15)) + ((7 & 15) ? ((vx[5].h[i] >> (((7 & 15) - 1) & 15)) & 1) : 0); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[14].h[i]  < (s16)vx[16].h[i]) ? ~0U : 0; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[2].h[i]  < (s16)vx[4].h[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[2].h[i]  < (s16)vx[5].h[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[9].w[i]) | (vx[2].w[i] & vx[9].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i]  < (s16)vx[0].h[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[5].h[i]  < (s16)vx[0].h[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[4].w[i]) | (vx[0].w[i] & vx[4].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[10].h[i] + (u16)vx[0].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[10].h[i] + (u16)vx[9].h[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i]  < (s16)vx[1].h[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[16].h[i] + (u16)vx[5].h[i]; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[16].h[i] - (u16)vx[5].h[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[4].w[i]) | (vx[6].w[i] & vx[4].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[10].h[i] - (u16)vx[9].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[3].h[i]  < (s16)vx[10].h[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[17].w[i]) | (vx[18].w[i] & vx[17].w[i]); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[10].w[i]) | (vx[4].w[i] & vx[10].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[14].w[i]) | (vx[5].w[i] & vx[14].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[4].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a3 + (16)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[12].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (s16)vx[4].h[i] > (s16)vx[6].h[i] ? (s64)(s16)vx[4].h[i] - (s64)(s16)vx[6].h[i] : (s64)(s16)vx[6].h[i] - (s64)(s16)vx[4].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[3].h[i] * (u32)vx[11].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s64)(s16)vx[3].h[i] >> (7 & 15)) + ((7 & 15) ? ((vx[3].h[i] >> (((7 & 15) - 1) & 15)) & 1) : 0); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[2].h[i]  < (s16)vx[3].h[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[2].w[i]) | (vx[7].w[i] & vx[2].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[3].h[i]  < (s16)vx[0].h[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[3].w[i]) | (vx[0].w[i] & vx[3].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[6].h[i] + (u16)vx[0].h[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[0].h[i]; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[6].h[i] + (u16)vx[1].h[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[2].h[i]  < (s16)vx[4].h[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[0].h[i]  < (s16)vx[6].h[i]) ? ~0U : 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[6].h[i] - (u16)vx[1].h[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[2].w[i]) | (vx[3].w[i] & vx[2].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[0].w[i]) | (vx[1].w[i] & vx[0].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[9].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (0)))[i] = vx[1].b[i]; }
    v1 = *(volatile u8 *)(unsigned long)(sp + (0));
    *(volatile u8 *)(unsigned long)(v0 + (16)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(sp + (1));
    *(volatile u8 *)(unsigned long)(v0 + (17)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(sp + (2));
    *(volatile u8 *)(unsigned long)(v0 + (18)) = v1;
    v1 = *(volatile u8 *)(unsigned long)(sp + (3));
    *(volatile u8 *)(unsigned long)(v0 + (19)) = v1;
    sp = sp + 16;
    return ((u64)v1 << 32) | v0;
}
