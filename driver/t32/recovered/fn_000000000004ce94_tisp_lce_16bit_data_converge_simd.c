/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_t32_data_ce140[] __asm__("t32_data_ce140");
extern unsigned char ref_t32_data_ce150[] __asm__("t32_data_ce150");
extern unsigned char ref_t32_data_ce160[] __asm__("t32_data_ce160");
extern unsigned char ref_t32_data_ce170[] __asm__("t32_data_ce170");
extern unsigned char ref_t32_data_ce180[] __asm__("t32_data_ce180");
extern unsigned char ref_t32_data_ce190[] __asm__("t32_data_ce190");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 tisp_lce_16bit_data_converge_simd(u32 a0, u32 a1, u32 a2, u32 a3, u32 arg4)
{
    u32 stack[72] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_4ce9c = ((u32)(unsigned long)ref_t32_data_ce140 + 0x8000U) & 0xffff0000U;
    const u32 hi_4cea8 = ((u32)(unsigned long)ref_t32_data_ce150 + 0x8000U) & 0xffff0000U;
    const u32 hi_4ceb4 = ((u32)(unsigned long)ref_t32_data_ce160 + 0x8000U) & 0xffff0000U;
    const u32 hi_4ced0 = ((u32)(unsigned long)ref_t32_data_ce170 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d0b4 = ((u32)(unsigned long)ref_t32_data_ce180 + 0x8000U) & 0xffff0000U;
    const u32 hi_4d0d0 = ((u32)(unsigned long)ref_t32_data_ce190 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[8];
    stack[12] = arg4;
L_4ce94:
    v1 = 64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v1; vx[16] = tmp; }
    v1 = hi_4ce9c;
    v1 = v1 - hi_4ce9c + (u32)(unsigned long)ref_t32_data_ce140;
    { unsigned int i; for (i = 0; i < 16; i++) vx[21].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v1 = hi_4cea8;
    v1 = v1 - hi_4cea8 + (u32)(unsigned long)ref_t32_data_ce150;
    { unsigned int i; for (i = 0; i < 16; i++) vx[20].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v1 = hi_4ceb4;
    v1 = v1 - hi_4ceb4 + (u32)(unsigned long)ref_t32_data_ce160;
    sp = sp + -32;
    { unsigned int i; for (i = 0; i < 16; i++) vx[19].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(sp + (48));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[9] = tmp; }
    v1 = hi_4ced0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v1 = v1 - hi_4ced0 + (u32)(unsigned long)ref_t32_data_ce170;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[19].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[0].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[21].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[0].b[(sel & 31) >> 1]); } vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[20].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[0].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] | vx[15].w[i]; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[19].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[21].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[20].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[22].w[i] | vx[22].w[i]; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[10].w[i] | vx[10].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[11].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[0].b[(sel & 31) >> 1]); } vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[24].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[19].w[i] - (s64)(s32)vx[24].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[24].w[i])); vx[6] = tmp; }
    a1 = a1 & 0xff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a1; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a0; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[11].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[9].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[21].w[i] - (s64)(s32)vx[26].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[21].w[i] - (s64)(s32)vx[26].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[21].w[i] - (s64)(s32)vx[26].w[i])); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[20].w[i] - (s64)(s32)vx[25].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[20].w[i] - (s64)(s32)vx[25].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[20].w[i] - (s64)(s32)vx[25].w[i])); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[19].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[19].w[i] + vx[1].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (0)))[i] = vx[5].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[18].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[11].w[i] + vx[1].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(sp + (16)))[i] = vx[5].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[23].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[11].w[i] - (s64)(s32)vx[23].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[23].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] * (u32)vx[18].w[i]; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[18].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[21].w[i] | vx[21].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[20].w[i] | vx[20].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[6].w[i] + vx[16].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (7 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[18].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[19].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[19].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[19].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[14].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[14].w[i] + vx[16].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[7].w[i] + vx[16].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[14].w[i] >> (7 & 31); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[7].w[i] >> (7 & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[6].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[30] = tmp; }
    a2 = a2 & 0xff;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = a2; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[4].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[3].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[3].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[3].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[5].w[i] + vx[16].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[11].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[23].w[i] - (s64)(s32)vx[11].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[11].w[i])); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (7 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[14].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[7].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[18].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[30].w[i]) | (vx[1].w[i] & vx[30].w[i]); vx[30] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[5].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[18].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[18].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[12].w[i]) | (vx[1].w[i] & vx[12].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[31].w[i]) | (vx[1].w[i] & vx[31].w[i]); vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[14].w[i]) ? ~0U : 0; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[7].w[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[18].w[i]; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[30].w[i] & ~vx[6].w[i]) | (vx[13].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[15].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[15].w[i] + vx[1].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[2].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[2].w[i] + vx[16].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[29].w[i]) | (vx[1].w[i] & vx[29].w[i]); vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (7 & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[5].w[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[15].w[i]  < (s32)vx[19].w[i]) ? ~0U : 0; vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] + (u32)vx[6].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[14].w[i]) | (vx[13].w[i] & vx[14].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[31].w[i] & ~vx[7].w[i]) | (vx[13].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[22].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[22].w[i] + vx[1].w[i]); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[10].w[i] + vx[1].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[4].w[i] + vx[16].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[3].w[i] + vx[16].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (7 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[3].w[i] >> (7 & 31); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[10].w[i]  < (s32)vx[20].w[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[22].w[i]  < (s32)vx[21].w[i]) ? ~0U : 0; vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[18].w[i] + vx[16].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[18].w[i] + vx[16].w[i]); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[26].w[i] + (u32)vx[12].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[16].w[i] >> (7 & 31); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[29].w[i] & ~vx[5].w[i]) | (vx[13].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[7].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[15].w[i]) | (vx[6].w[i] & vx[15].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[2].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[0].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[0].w[i] + vx[1].w[i]); vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[0].w[i]  < (s32)vx[11].w[i]) ? ~0U : 0; vx[0] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[21].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[21].w[i] + vx[1].w[i]); vx[28] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[20].w[i] + vx[1].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[20].w[i] + vx[1].w[i]); vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[23].w[i] + (u32)vx[5].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[22].w[i]) | (vx[12].w[i] & vx[22].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[10].w[i]) | (vx[7].w[i] & vx[10].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[4].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[3].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[6].w[i]) | (vx[8].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[16].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[2].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[13].w[i] | vx[13].w[i]; vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[0].w[i]) | (vx[5].w[i] & vx[0].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[12].w[i]) | (vx[8].w[i] & vx[12].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[10].w[i]) | (vx[8].w[i] & vx[10].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[4].w[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[3].w[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[16].w[i]) ? ~0U : 0; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[2].w[i]) | (vx[17].w[i] & vx[2].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[16].w[i] & ~vx[1].w[i]) | (vx[8].w[i] & vx[1].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[4].w[i]) | (vx[17].w[i] & vx[4].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[3].w[i]) | (vx[17].w[i] & vx[3].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[2].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[2].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[2].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[13].w[i]) | (vx[17].w[i] & vx[13].w[i]); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[0].w[i]  < (s32)vx[24].w[i]) ? ~0U : 0; vx[24] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(sp + (16)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[3].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[3].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[3].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[17].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[23].w[i] - (s64)(s32)vx[17].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[17].w[i])); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[4].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[27].w[i]  < (s32)vx[25].w[i]) ? ~0U : 0; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[28].w[i]  < (s32)vx[26].w[i]) ? ~0U : 0; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[0].w[i]  < (s32)vx[23].w[i]) ? ~0U : 0; vx[23] = tmp; }
    v1 = hi_4d0b4;
    v1 = v1 - hi_4d0b4 + (u32)(unsigned long)ref_t32_data_ce180;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[25].w[i]) | (vx[3].w[i] & vx[25].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[26].w[i]) | (vx[4].w[i] & vx[26].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[23].w[i]) | (vx[17].w[i] & vx[23].w[i]); vx[0] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[24].w[i]) | (vx[2].w[i] & vx[24].w[i]); vx[15] = tmp; }
    v1 = hi_4d0d0;
    v1 = v1 - hi_4d0d0 + (u32)(unsigned long)ref_t32_data_ce190;
    a3 = a3 + 16;
    t1 = v0 + 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[20].b[(sel & 31) >> 1] : vx[21].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[15].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    t2 = v0 + 20;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[15].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[5].b[i]; }
L_4d0f8:
    t0 = *(volatile u8 *)(unsigned long)(a3 + (0));
    v0 = *(volatile u8 *)(unsigned long)(t1 + (0));
    t3 = a1 + t0;
    v1 = (s32)t3 < (s32)(v0);
    branch = (v1 == 0); v1 = a1 + v0;
    if (branch) goto L_4d14c;
    goto L_4d110;
L_4d110:
    v1 = v0 - t0;
    v1 = v1 * a0;
    v1 = v1 + 64;
    v1 = (s32)v1 >> (0x7 & 31);
    v0 = (s32)v1 < (s32)(a1);
    branch = (v0 == 0); v0 = (s32)a2 < (s32)(v1);
    if (branch) goto L_4d134;
    goto L_4d12c;
L_4d12c:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = t3; goto L_4d194;
L_4d134:
    if (v0 == 0) { v1 = t0 + v1; goto L_4d144; }
    goto L_4d13c;
L_4d13c:
    t0 = a2 + t0; goto L_4d188;
L_4d144:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = v1; goto L_4d194;
L_4d14c:
    v1 = (s32)v1 < (s32)(t0);
    if (v1 == 0) { t1 = t1 + 1; goto L_4d198; }
    goto L_4d158;
L_4d158:
    v0 = t0 - v0;
    v0 = v0 * a0;
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v1 = (s32)v0 < (s32)(a1);
    branch = (v1 == 0); v1 = (s32)a2 < (s32)(v0);
    if (branch) goto L_4d17c;
    goto L_4d174;
L_4d174:
    t0 = t0 - a1; goto L_4d188;
L_4d17c:
    if (v1 == 0) { v0 = t0 - v0; goto L_4d190; }
    goto L_4d184;
L_4d184:
    t0 = t0 - a2;
L_4d188:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = t0; goto L_4d194;
L_4d190:
    *(volatile u8 *)(unsigned long)(t1 + (0)) = v0;
L_4d194:
    t1 = t1 + 1;
L_4d198:
    branch = (t1 != t2); a3 = a3 + 1;
    if (branch) goto L_4d0f8;
    goto L_4d1a0;
L_4d1a0:
    sp = sp + 32;
    return ((u64)v1 << 32) | v0;
}
