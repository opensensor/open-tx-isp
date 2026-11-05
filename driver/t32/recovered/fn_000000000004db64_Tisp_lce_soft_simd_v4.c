/* Mechanical C translation of decoded MIPS/MXU2 instructions.
 * Control flow and delay slots are explicit; runtime equivalence is unverified.
 * No executable OEM bytes or assembly implementation are linked. */
#include "../compat.h"
extern unsigned char ref_memset[] __asm__("memset");
extern unsigned char ref_t32_data_ce200[] __asm__("t32_data_ce200");
extern unsigned char ref_t32_data_d6c65[] __asm__("t32_data_d6c65");
extern unsigned char ref_t32_data_d6c64[] __asm__("t32_data_d6c64");
extern unsigned char ref_t32_data_ce140[] __asm__("t32_data_ce140");
extern unsigned char ref_t32_data_d6b50[] __asm__("t32_data_d6b50");
extern unsigned char ref_t32_data_ce150[] __asm__("t32_data_ce150");
extern unsigned char ref_t32_data_ce160[] __asm__("t32_data_ce160");
extern unsigned char ref_t32_data_ce170[] __asm__("t32_data_ce170");
extern unsigned char ref_t32_data_d6b60[] __asm__("t32_data_d6b60");
extern unsigned char ref_t32_data_e188c[] __asm__("t32_data_e188c");
extern unsigned char ref_t32_data_bf994[] __asm__("t32_data_bf994");
extern unsigned char ref_memcpy_simd[] __asm__("memcpy_simd");
extern unsigned char ref_tisp_lce_thres_search_simd_v4[] __asm__("tisp_lce_thres_search_simd_v4");
extern unsigned char ref_t32_data_e1e48[] __asm__("t32_data_e1e48");
extern unsigned char ref_t32_data_e1e58[] __asm__("t32_data_e1e58");
extern unsigned char ref_t32_data_ce1b0[] __asm__("t32_data_ce1b0");
extern unsigned char ref_t32_data_ce1c0[] __asm__("t32_data_ce1c0");
extern unsigned char ref_t32_data_e1e68[] __asm__("t32_data_e1e68");
extern unsigned char ref_t32_data_ce1d0[] __asm__("t32_data_ce1d0");
extern unsigned char ref_t32_data_e1e78[] __asm__("t32_data_e1e78");
extern unsigned char ref_t32_data_e1e88[] __asm__("t32_data_e1e88");
extern unsigned char ref_t32_data_e1e98[] __asm__("t32_data_e1e98");
extern unsigned char ref_t32_data_e1ea8[] __asm__("t32_data_e1ea8");
extern unsigned char ref_t32_data_e1eb8[] __asm__("t32_data_e1eb8");
extern unsigned char ref_t32_data_e1ec8[] __asm__("t32_data_e1ec8");
extern unsigned char ref_t32_data_e1ed8[] __asm__("t32_data_e1ed8");
extern unsigned char ref_t32_data_e1ee8[] __asm__("t32_data_e1ee8");
extern unsigned char ref_t32_data_e1ef8[] __asm__("t32_data_e1ef8");
extern unsigned char ref_t32_data_e1f08[] __asm__("t32_data_e1f08");
extern unsigned char ref_t32_data_e1f18[] __asm__("t32_data_e1f18");
extern unsigned char ref_t32_data_e1f28[] __asm__("t32_data_e1f28");
extern unsigned char ref_t32_data_e1f38[] __asm__("t32_data_e1f38");
extern unsigned char ref_t32_data_e1f48[] __asm__("t32_data_e1f48");
extern unsigned char ref_t32_data_e1f58[] __asm__("t32_data_e1f58");
extern unsigned char ref_t32_data_e1f68[] __asm__("t32_data_e1f68");
extern unsigned char ref_t32_data_e1f78[] __asm__("t32_data_e1f78");
extern unsigned char ref_t32_data_e1f88[] __asm__("t32_data_e1f88");
extern unsigned char ref_t32_data_ce1e0[] __asm__("t32_data_ce1e0");
extern unsigned char ref_t32_data_ce1f0[] __asm__("t32_data_ce1f0");
extern unsigned char ref_t32_data_ce1a0[] __asm__("t32_data_ce1a0");
extern unsigned char ref_t32_data_ce180[] __asm__("t32_data_ce180");
extern unsigned char ref_t32_data_ce190[] __asm__("t32_data_ce190");
extern unsigned char ref_t32_data_bf9ec[] __asm__("t32_data_bf9ec");
extern unsigned char ref_t32_data_d6be4[] __asm__("t32_data_d6be4");
extern unsigned char ref_t32_data_d6b64[] __asm__("t32_data_d6b64");
extern unsigned char ref_t32_data_e1f98[] __asm__("t32_data_e1f98");
extern unsigned char ref_t32_data_e1fa8[] __asm__("t32_data_e1fa8");
extern unsigned char ref_t32_data_e1fb8[] __asm__("t32_data_e1fb8");
extern unsigned char ref_t32_data_e1fc8[] __asm__("t32_data_e1fc8");
extern unsigned char ref_t32_data_e1fd8[] __asm__("t32_data_e1fd8");
extern unsigned char ref_t32_data_e1fe8[] __asm__("t32_data_e1fe8");
extern unsigned char ref_t32_data_e1ff8[] __asm__("t32_data_e1ff8");
extern unsigned char ref_t32_data_e2008[] __asm__("t32_data_e2008");
extern unsigned char ref_t32_data_e2018[] __asm__("t32_data_e2018");
extern unsigned char ref_t32_data_e2028[] __asm__("t32_data_e2028");
extern unsigned char ref_t32_data_e2038[] __asm__("t32_data_e2038");
extern unsigned char ref_t32_data_e2048[] __asm__("t32_data_e2048");
extern unsigned char ref_t32_data_e2058[] __asm__("t32_data_e2058");
extern unsigned char ref_t32_data_e2068[] __asm__("t32_data_e2068");
extern unsigned char ref_t32_data_e2078[] __asm__("t32_data_e2078");
extern unsigned char ref_t32_data_e2088[] __asm__("t32_data_e2088");
extern unsigned char ref_t32_data_d6c67[] __asm__("t32_data_d6c67");
extern unsigned char ref_t32_data_e20a8[] __asm__("t32_data_e20a8");
extern unsigned char ref_t32_data_e20b8[] __asm__("t32_data_e20b8");
extern unsigned char ref_t32_data_e20c8[] __asm__("t32_data_e20c8");
extern unsigned char ref_t32_data_e2098[] __asm__("t32_data_e2098");
extern unsigned char ref_memcpy[] __asm__("memcpy");
extern unsigned char ref_tisp_lce_thres_search[] __asm__("tisp_lce_thres_search");
extern unsigned char ref_tisp_lce_hist_method[] __asm__("tisp_lce_hist_method");
extern unsigned char ref_printk[] __asm__("printk");
extern unsigned char ref_t32_data_c9660[] __asm__("t32_data_c9660");
extern unsigned char ref_tisp_lce_hist_adjust[] __asm__("tisp_lce_hist_adjust");
extern unsigned char ref_tisp_lce_16bit_data_converge[] __asm__("tisp_lce_16bit_data_converge");
extern unsigned char ref_get_distance_1dim[] __asm__("get_distance_1dim");
extern unsigned char ref_t32_data_e1892[] __asm__("t32_data_e1892");
extern unsigned char ref_t32_data_e1898[] __asm__("t32_data_e1898");
extern unsigned char ref_t32_data_e189e[] __asm__("t32_data_e189e");
union t32_vec { u8 b[16]; u16 h[8]; u32 w[4]; u64 d[2]; };
u64 Tisp_lce_soft_simd_v4(u32 a0, u32 a1, u32 a2, u32 a3)
{
    u32 stack[322] __aligned(16) = {0};
    u32 at = 0, v0 = 0, v1 = 0, t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, s0 = 0, s1 = 0, s2 = 0, s3 = 0, s4 = 0, s5 = 0, s6 = 0, s7 = 0, t8 = 0, t9 = 0, gp = (u32)(unsigned long)current_thread_info(), sp = 0, s8 = 0, ra = 0;
    u32 hi = 0, lo = 0, callee, ll_addr, ll_value;
    u64 result, product;
    int branch;
    union t32_vec vx[32];
    const u32 hi_4dba4 = (((u32)(unsigned long)ref_memset + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4dc68 = ((u32)(unsigned long)ref_t32_data_ce200 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dc0c = ((u32)(unsigned long)ref_t32_data_d6c65 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dc10 = ((u32)(unsigned long)ref_t32_data_d6c64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dca4 = ((u32)(unsigned long)ref_t32_data_ce140 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dcb4 = ((u32)(unsigned long)ref_t32_data_d6b50 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dcc0 = ((u32)(unsigned long)ref_t32_data_ce150 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dcd0 = ((u32)(unsigned long)ref_t32_data_ce160 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dcec = ((u32)(unsigned long)ref_t32_data_ce170 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dd2c = ((u32)(unsigned long)ref_t32_data_d6b60 + 0x8000U) & 0xffff0000U;
    const u32 hi_4df2c = ((u32)(unsigned long)ref_t32_data_e188c + 0x8000U) & 0xffff0000U;
    const u32 hi_4df34 = ((u32)(unsigned long)ref_t32_data_bf994 + 0x8000U) & 0xffff0000U;
    const u32 hi_4df48 = ((u32)(unsigned long)ref_memcpy_simd + 0x8000U) & 0xffff0000U;
    const u32 hi_4dfa8 = ((u32)(unsigned long)ref_t32_data_e188c + 0x8000U) & 0xffff0000U;
    const u32 hi_4dfbc = ((u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4dfdc = ((u32)(unsigned long)ref_t32_data_e1e48 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e0cc = ((u32)(unsigned long)ref_t32_data_e1e58 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e0d8 = ((u32)(unsigned long)ref_t32_data_ce1b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e0ec = ((u32)(unsigned long)ref_t32_data_ce1c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e104 = ((u32)(unsigned long)ref_t32_data_e1e68 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e148 = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e164 = ((u32)(unsigned long)ref_t32_data_e1e78 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e174 = ((u32)(unsigned long)ref_t32_data_e1e88 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e1bc = ((u32)(unsigned long)ref_t32_data_e1e98 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e1d0 = ((u32)(unsigned long)ref_t32_data_e1ea8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e1dc = ((u32)(unsigned long)ref_t32_data_e1eb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e1f0 = ((u32)(unsigned long)ref_t32_data_e1ec8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e204 = ((u32)(unsigned long)ref_t32_data_e1ed8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e21c = ((u32)(unsigned long)ref_t32_data_e1ee8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e240 = ((u32)(unsigned long)ref_t32_data_e1ef8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e258 = ((u32)(unsigned long)ref_t32_data_e1f08 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e280 = ((u32)(unsigned long)ref_t32_data_e1f18 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e28c = ((u32)(unsigned long)ref_t32_data_e1f28 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e29c = ((u32)(unsigned long)ref_t32_data_e1f38 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e2b4 = ((u32)(unsigned long)ref_t32_data_e1f48 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e2d0 = ((u32)(unsigned long)ref_t32_data_e1f58 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e2e4 = ((u32)(unsigned long)ref_t32_data_e1f68 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e300 = ((u32)(unsigned long)ref_t32_data_e1f78 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e30c = ((u32)(unsigned long)ref_t32_data_e1f88 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e330 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e33c = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e354 = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e378 = ((u32)(unsigned long)ref_t32_data_ce180 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e38c = ((u32)(unsigned long)ref_t32_data_ce190 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e3a4 = ((u32)(unsigned long)ref_t32_data_bf9ec + 0x8000U) & 0xffff0000U;
    const u32 hi_4e3bc = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e424 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e4a0 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e4b8 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e534 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e5a8 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e5f0 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e690 = ((u32)(unsigned long)ref_t32_data_e1f98 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e69c = ((u32)(unsigned long)ref_t32_data_e1fa8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6a8 = ((u32)(unsigned long)ref_t32_data_e1fb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6b4 = ((u32)(unsigned long)ref_t32_data_e1fc8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6c0 = ((u32)(unsigned long)ref_t32_data_e1fd8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6cc = ((u32)(unsigned long)ref_t32_data_e1fe8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6d8 = ((u32)(unsigned long)ref_t32_data_e1ff8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6e4 = ((u32)(unsigned long)ref_t32_data_e2008 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6f0 = ((u32)(unsigned long)ref_t32_data_e2018 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e6fc = ((u32)(unsigned long)ref_t32_data_e2028 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e708 = ((u32)(unsigned long)ref_t32_data_e2038 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e714 = ((u32)(unsigned long)ref_t32_data_e2048 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e720 = ((u32)(unsigned long)ref_t32_data_e2058 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e72c = ((u32)(unsigned long)ref_t32_data_e2068 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e740 = ((u32)(unsigned long)ref_t32_data_e2078 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e750 = ((u32)(unsigned long)ref_t32_data_e2088 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e7dc = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e870 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e988 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e9c4 = ((u32)(unsigned long)ref_t32_data_e20a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e9cc = ((u32)(unsigned long)ref_t32_data_e20b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e9d4 = ((u32)(unsigned long)ref_t32_data_e20c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4e9e4 = ((u32)(unsigned long)ref_t32_data_e2098 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f00c = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4df3c = ((u32)(unsigned long)ref_tisp_lce_thres_search + 0x8000U) & 0xffff0000U;
    const u32 hi_4f058 = ((u32)(unsigned long)ref_tisp_lce_hist_method + 0x8000U) & 0xffff0000U;
    const u32 hi_4f0c8 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4f0c4 = ((u32)(unsigned long)ref_t32_data_c9660 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f0f0 = ((u32)(unsigned long)ref_tisp_lce_hist_adjust + 0x8000U) & 0xffff0000U;
    const u32 hi_4f128 = ((u32)(unsigned long)ref_tisp_lce_16bit_data_converge + 0x8000U) & 0xffff0000U;
    const u32 hi_4f140 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4f194 = ((u32)(unsigned long)ref_get_distance_1dim + 0x8000U) & 0xffff0000U;
    const u32 hi_4f1c8 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f2ec = ((u32)(unsigned long)ref_t32_data_e1892 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f2f0 = ((u32)(unsigned long)ref_t32_data_bf994 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f2e4 = ((u32)(unsigned long)ref_memcpy_simd + 0x8000U) & 0xffff0000U;
    const u32 hi_4f370 = ((u32)(unsigned long)ref_t32_data_e1892 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f384 = ((u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f3a4 = ((u32)(unsigned long)ref_t32_data_e1e48 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f494 = ((u32)(unsigned long)ref_t32_data_e1e58 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f4a0 = ((u32)(unsigned long)ref_t32_data_ce1b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f4b4 = ((u32)(unsigned long)ref_t32_data_ce1c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f4c0 = ((u32)(unsigned long)ref_t32_data_e1e68 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f50c = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f528 = ((u32)(unsigned long)ref_t32_data_e1e78 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f538 = ((u32)(unsigned long)ref_t32_data_e1e88 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f580 = ((u32)(unsigned long)ref_t32_data_e1e98 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f594 = ((u32)(unsigned long)ref_t32_data_e1ea8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f5a0 = ((u32)(unsigned long)ref_t32_data_e1eb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f5b4 = ((u32)(unsigned long)ref_t32_data_e1ec8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f5c8 = ((u32)(unsigned long)ref_t32_data_e1ed8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f5e0 = ((u32)(unsigned long)ref_t32_data_e1ee8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f604 = ((u32)(unsigned long)ref_t32_data_e1ef8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f61c = ((u32)(unsigned long)ref_t32_data_e1f08 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f644 = ((u32)(unsigned long)ref_t32_data_e1f18 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f650 = ((u32)(unsigned long)ref_t32_data_e1f28 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f660 = ((u32)(unsigned long)ref_t32_data_e1f38 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f678 = ((u32)(unsigned long)ref_t32_data_e1f48 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f694 = ((u32)(unsigned long)ref_t32_data_e1f58 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f6a8 = ((u32)(unsigned long)ref_t32_data_e1f68 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f6c4 = ((u32)(unsigned long)ref_t32_data_e1f78 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f6d0 = ((u32)(unsigned long)ref_t32_data_e1f88 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f6f4 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f700 = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f718 = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f73c = ((u32)(unsigned long)ref_t32_data_ce180 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f750 = ((u32)(unsigned long)ref_t32_data_ce190 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f768 = ((u32)(unsigned long)ref_t32_data_bf9ec + 0x8000U) & 0xffff0000U;
    const u32 hi_4f780 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f7e8 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f864 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f87c = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f8f8 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f96c = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4f9b4 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa54 = ((u32)(unsigned long)ref_t32_data_e1f98 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa60 = ((u32)(unsigned long)ref_t32_data_e1fa8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa6c = ((u32)(unsigned long)ref_t32_data_e1fb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa78 = ((u32)(unsigned long)ref_t32_data_e1fc8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa84 = ((u32)(unsigned long)ref_t32_data_e1fd8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa90 = ((u32)(unsigned long)ref_t32_data_e1fe8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fa9c = ((u32)(unsigned long)ref_t32_data_e1ff8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4faa8 = ((u32)(unsigned long)ref_t32_data_e2008 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fab4 = ((u32)(unsigned long)ref_t32_data_e2018 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fac0 = ((u32)(unsigned long)ref_t32_data_e2028 + 0x8000U) & 0xffff0000U;
    const u32 hi_4facc = ((u32)(unsigned long)ref_t32_data_e2038 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fad8 = ((u32)(unsigned long)ref_t32_data_e2048 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fae4 = ((u32)(unsigned long)ref_t32_data_e2058 + 0x8000U) & 0xffff0000U;
    const u32 hi_4faf0 = ((u32)(unsigned long)ref_t32_data_e2068 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fb04 = ((u32)(unsigned long)ref_t32_data_e2078 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fb14 = ((u32)(unsigned long)ref_t32_data_e2088 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fba0 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fc34 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fd4c = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fd88 = ((u32)(unsigned long)ref_t32_data_e20a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fd90 = ((u32)(unsigned long)ref_t32_data_e20b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fd98 = ((u32)(unsigned long)ref_t32_data_e20c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_4fda8 = ((u32)(unsigned long)ref_t32_data_e2098 + 0x8000U) & 0xffff0000U;
    const u32 hi_503e4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_4f308 = ((u32)(unsigned long)ref_tisp_lce_thres_search + 0x8000U) & 0xffff0000U;
    const u32 hi_50430 = ((u32)(unsigned long)ref_tisp_lce_hist_method + 0x8000U) & 0xffff0000U;
    const u32 hi_504a0 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_5049c = ((u32)(unsigned long)ref_t32_data_c9660 + 0x8000U) & 0xffff0000U;
    const u32 hi_504c8 = ((u32)(unsigned long)ref_tisp_lce_hist_adjust + 0x8000U) & 0xffff0000U;
    const u32 hi_50500 = ((u32)(unsigned long)ref_tisp_lce_16bit_data_converge + 0x8000U) & 0xffff0000U;
    const u32 hi_50518 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_50570 = ((u32)(unsigned long)ref_get_distance_1dim + 0x8000U) & 0xffff0000U;
    const u32 hi_505a4 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_50794 = ((u32)(unsigned long)ref_t32_data_e1898 + 0x8000U) & 0xffff0000U;
    const u32 hi_5079c = ((u32)(unsigned long)ref_t32_data_bf994 + 0x8000U) & 0xffff0000U;
    const u32 hi_507b0 = ((u32)(unsigned long)ref_memcpy_simd + 0x8000U) & 0xffff0000U;
    const u32 hi_50818 = ((u32)(unsigned long)ref_t32_data_e1898 + 0x8000U) & 0xffff0000U;
    const u32 hi_5082c = ((u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5084c = ((u32)(unsigned long)ref_t32_data_e1e48 + 0x8000U) & 0xffff0000U;
    const u32 hi_5093c = ((u32)(unsigned long)ref_t32_data_e1e58 + 0x8000U) & 0xffff0000U;
    const u32 hi_50948 = ((u32)(unsigned long)ref_t32_data_ce1b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_5095c = ((u32)(unsigned long)ref_t32_data_ce1c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_50968 = ((u32)(unsigned long)ref_t32_data_e1e68 + 0x8000U) & 0xffff0000U;
    const u32 hi_50998 = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_509c8 = ((u32)(unsigned long)ref_t32_data_e1e78 + 0x8000U) & 0xffff0000U;
    const u32 hi_509d8 = ((u32)(unsigned long)ref_t32_data_e1e88 + 0x8000U) & 0xffff0000U;
    const u32 hi_50a20 = ((u32)(unsigned long)ref_t32_data_e1e98 + 0x8000U) & 0xffff0000U;
    const u32 hi_50a34 = ((u32)(unsigned long)ref_t32_data_e1ea8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50a40 = ((u32)(unsigned long)ref_t32_data_e1eb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50a54 = ((u32)(unsigned long)ref_t32_data_e1ec8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50a68 = ((u32)(unsigned long)ref_t32_data_e1ed8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50a80 = ((u32)(unsigned long)ref_t32_data_e1ee8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50aa4 = ((u32)(unsigned long)ref_t32_data_e1ef8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50abc = ((u32)(unsigned long)ref_t32_data_e1f08 + 0x8000U) & 0xffff0000U;
    const u32 hi_50ae4 = ((u32)(unsigned long)ref_t32_data_e1f18 + 0x8000U) & 0xffff0000U;
    const u32 hi_50af0 = ((u32)(unsigned long)ref_t32_data_e1f28 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b00 = ((u32)(unsigned long)ref_t32_data_e1f38 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b18 = ((u32)(unsigned long)ref_t32_data_e1f48 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b34 = ((u32)(unsigned long)ref_t32_data_e1f58 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b48 = ((u32)(unsigned long)ref_t32_data_e1f68 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b64 = ((u32)(unsigned long)ref_t32_data_e1f78 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b70 = ((u32)(unsigned long)ref_t32_data_e1f88 + 0x8000U) & 0xffff0000U;
    const u32 hi_50b9c = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_50bb0 = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_50bc4 = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_50be8 = ((u32)(unsigned long)ref_t32_data_ce180 + 0x8000U) & 0xffff0000U;
    const u32 hi_50bfc = ((u32)(unsigned long)ref_t32_data_ce190 + 0x8000U) & 0xffff0000U;
    const u32 hi_50c14 = ((u32)(unsigned long)ref_t32_data_bf9ec + 0x8000U) & 0xffff0000U;
    const u32 hi_50c2c = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_50c94 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_50d10 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_50d28 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_50da4 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_50e18 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_50e60 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f00 = ((u32)(unsigned long)ref_t32_data_e1f98 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f0c = ((u32)(unsigned long)ref_t32_data_e1fa8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f18 = ((u32)(unsigned long)ref_t32_data_e1fb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f24 = ((u32)(unsigned long)ref_t32_data_e1fc8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f30 = ((u32)(unsigned long)ref_t32_data_e1fd8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f3c = ((u32)(unsigned long)ref_t32_data_e1fe8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f48 = ((u32)(unsigned long)ref_t32_data_e1ff8 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f54 = ((u32)(unsigned long)ref_t32_data_e2008 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f60 = ((u32)(unsigned long)ref_t32_data_e2018 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f6c = ((u32)(unsigned long)ref_t32_data_e2028 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f78 = ((u32)(unsigned long)ref_t32_data_e2038 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f84 = ((u32)(unsigned long)ref_t32_data_e2048 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f90 = ((u32)(unsigned long)ref_t32_data_e2058 + 0x8000U) & 0xffff0000U;
    const u32 hi_50f9c = ((u32)(unsigned long)ref_t32_data_e2068 + 0x8000U) & 0xffff0000U;
    const u32 hi_50fb0 = ((u32)(unsigned long)ref_t32_data_e2078 + 0x8000U) & 0xffff0000U;
    const u32 hi_50fc0 = ((u32)(unsigned long)ref_t32_data_e2088 + 0x8000U) & 0xffff0000U;
    const u32 hi_5104c = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_510e0 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_511f8 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_51238 = ((u32)(unsigned long)ref_t32_data_e20a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51244 = ((u32)(unsigned long)ref_t32_data_e20b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_5124c = ((u32)(unsigned long)ref_t32_data_e20c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_5125c = ((u32)(unsigned long)ref_t32_data_e2098 + 0x8000U) & 0xffff0000U;
    const u32 hi_518a4 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_507a4 = ((u32)(unsigned long)ref_tisp_lce_thres_search + 0x8000U) & 0xffff0000U;
    const u32 hi_518fc = ((u32)(unsigned long)ref_tisp_lce_hist_method + 0x8000U) & 0xffff0000U;
    const u32 hi_51984 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_51980 = ((u32)(unsigned long)ref_t32_data_c9660 + 0x8000U) & 0xffff0000U;
    const u32 hi_519b4 = ((u32)(unsigned long)ref_tisp_lce_hist_adjust + 0x8000U) & 0xffff0000U;
    const u32 hi_519ec = ((u32)(unsigned long)ref_tisp_lce_16bit_data_converge + 0x8000U) & 0xffff0000U;
    const u32 hi_51a10 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_51a68 = ((u32)(unsigned long)ref_get_distance_1dim + 0x8000U) & 0xffff0000U;
    const u32 hi_51aa4 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_51bc4 = ((u32)(unsigned long)ref_t32_data_e189e + 0x8000U) & 0xffff0000U;
    const u32 hi_51bc8 = ((u32)(unsigned long)ref_t32_data_bf994 + 0x8000U) & 0xffff0000U;
    const u32 hi_51bbc = ((u32)(unsigned long)ref_memcpy_simd + 0x8000U) & 0xffff0000U;
    const u32 hi_51c50 = ((u32)(unsigned long)ref_t32_data_e189e + 0x8000U) & 0xffff0000U;
    const u32 hi_51c64 = ((u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4 + 0x8000U) & 0xffff0000U;
    const u32 hi_51c84 = ((u32)(unsigned long)ref_t32_data_e1e48 + 0x8000U) & 0xffff0000U;
    const u32 hi_51d74 = ((u32)(unsigned long)ref_t32_data_e1e58 + 0x8000U) & 0xffff0000U;
    const u32 hi_51d80 = ((u32)(unsigned long)ref_t32_data_ce1b0 + 0x8000U) & 0xffff0000U;
    const u32 hi_51d94 = ((u32)(unsigned long)ref_t32_data_ce1c0 + 0x8000U) & 0xffff0000U;
    const u32 hi_51da0 = ((u32)(unsigned long)ref_t32_data_e1e68 + 0x8000U) & 0xffff0000U;
    const u32 hi_51dd8 = ((u32)(unsigned long)ref_t32_data_ce1d0 + 0x8000U) & 0xffff0000U;
    const u32 hi_51e08 = ((u32)(unsigned long)ref_t32_data_e1e78 + 0x8000U) & 0xffff0000U;
    const u32 hi_51e18 = ((u32)(unsigned long)ref_t32_data_e1e88 + 0x8000U) & 0xffff0000U;
    const u32 hi_51e60 = ((u32)(unsigned long)ref_t32_data_e1e98 + 0x8000U) & 0xffff0000U;
    const u32 hi_51e74 = ((u32)(unsigned long)ref_t32_data_e1ea8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51e80 = ((u32)(unsigned long)ref_t32_data_e1eb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51e94 = ((u32)(unsigned long)ref_t32_data_e1ec8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51ea8 = ((u32)(unsigned long)ref_t32_data_e1ed8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51ec0 = ((u32)(unsigned long)ref_t32_data_e1ee8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51ee4 = ((u32)(unsigned long)ref_t32_data_e1ef8 + 0x8000U) & 0xffff0000U;
    const u32 hi_51efc = ((u32)(unsigned long)ref_t32_data_e1f08 + 0x8000U) & 0xffff0000U;
    const u32 hi_51f24 = ((u32)(unsigned long)ref_t32_data_e1f18 + 0x8000U) & 0xffff0000U;
    const u32 hi_51f30 = ((u32)(unsigned long)ref_t32_data_e1f28 + 0x8000U) & 0xffff0000U;
    const u32 hi_51f40 = ((u32)(unsigned long)ref_t32_data_e1f38 + 0x8000U) & 0xffff0000U;
    const u32 hi_51f58 = ((u32)(unsigned long)ref_t32_data_e1f48 + 0x8000U) & 0xffff0000U;
    const u32 hi_51f74 = ((u32)(unsigned long)ref_t32_data_e1f58 + 0x8000U) & 0xffff0000U;
    const u32 hi_51f88 = ((u32)(unsigned long)ref_t32_data_e1f68 + 0x8000U) & 0xffff0000U;
    const u32 hi_51fa4 = ((u32)(unsigned long)ref_t32_data_e1f78 + 0x8000U) & 0xffff0000U;
    const u32 hi_51fb0 = ((u32)(unsigned long)ref_t32_data_e1f88 + 0x8000U) & 0xffff0000U;
    const u32 hi_51fd4 = ((u32)(unsigned long)ref_t32_data_ce1e0 + 0x8000U) & 0xffff0000U;
    const u32 hi_51fe8 = ((u32)(unsigned long)ref_t32_data_ce1f0 + 0x8000U) & 0xffff0000U;
    const u32 hi_51ffc = ((u32)(unsigned long)ref_t32_data_ce1a0 + 0x8000U) & 0xffff0000U;
    const u32 hi_52010 = ((u32)(unsigned long)ref_t32_data_ce140 + 0x8000U) & 0xffff0000U;
    const u32 hi_52024 = ((u32)(unsigned long)ref_t32_data_ce150 + 0x8000U) & 0xffff0000U;
    const u32 hi_52038 = ((u32)(unsigned long)ref_t32_data_ce160 + 0x8000U) & 0xffff0000U;
    const u32 hi_52050 = ((u32)(unsigned long)ref_t32_data_bf9ec + 0x8000U) & 0xffff0000U;
    const u32 hi_52068 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_520d0 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5214c = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_52164 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_521e0 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_52254 = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5229c = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_5233c = ((u32)(unsigned long)ref_t32_data_e1f98 + 0x8000U) & 0xffff0000U;
    const u32 hi_52348 = ((u32)(unsigned long)ref_t32_data_e1fa8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52354 = ((u32)(unsigned long)ref_t32_data_e1fb8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52360 = ((u32)(unsigned long)ref_t32_data_e1fc8 + 0x8000U) & 0xffff0000U;
    const u32 hi_5236c = ((u32)(unsigned long)ref_t32_data_e1fd8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52378 = ((u32)(unsigned long)ref_t32_data_e1fe8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52384 = ((u32)(unsigned long)ref_t32_data_e1ff8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52390 = ((u32)(unsigned long)ref_t32_data_e2008 + 0x8000U) & 0xffff0000U;
    const u32 hi_5239c = ((u32)(unsigned long)ref_t32_data_e2018 + 0x8000U) & 0xffff0000U;
    const u32 hi_523a8 = ((u32)(unsigned long)ref_t32_data_e2028 + 0x8000U) & 0xffff0000U;
    const u32 hi_523b4 = ((u32)(unsigned long)ref_t32_data_e2038 + 0x8000U) & 0xffff0000U;
    const u32 hi_523c0 = ((u32)(unsigned long)ref_t32_data_e2048 + 0x8000U) & 0xffff0000U;
    const u32 hi_523cc = ((u32)(unsigned long)ref_t32_data_e2058 + 0x8000U) & 0xffff0000U;
    const u32 hi_523d8 = ((u32)(unsigned long)ref_t32_data_e2068 + 0x8000U) & 0xffff0000U;
    const u32 hi_523ec = ((u32)(unsigned long)ref_t32_data_e2078 + 0x8000U) & 0xffff0000U;
    const u32 hi_523fc = ((u32)(unsigned long)ref_t32_data_e2088 + 0x8000U) & 0xffff0000U;
    const u32 hi_52488 = ((u32)(unsigned long)ref_t32_data_d6b64 + 0x8000U) & 0xffff0000U;
    const u32 hi_5251c = ((u32)(unsigned long)ref_t32_data_d6be4 + 0x8000U) & 0xffff0000U;
    const u32 hi_52634 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    const u32 hi_52674 = ((u32)(unsigned long)ref_t32_data_e20a8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52680 = ((u32)(unsigned long)ref_t32_data_e20b8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52688 = ((u32)(unsigned long)ref_t32_data_e20c8 + 0x8000U) & 0xffff0000U;
    const u32 hi_52698 = ((u32)(unsigned long)ref_t32_data_e2098 + 0x8000U) & 0xffff0000U;
    const u32 hi_527d0 = ((u32)(unsigned long)ref_t32_data_ce170 + 0x8000U) & 0xffff0000U;
    const u32 hi_528e8 = ((u32)(unsigned long)ref_t32_data_ce180 + 0x8000U) & 0xffff0000U;
    const u32 hi_528fc = ((u32)(unsigned long)ref_t32_data_ce190 + 0x8000U) & 0xffff0000U;
    const u32 hi_52d40 = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_51be0 = ((u32)(unsigned long)ref_tisp_lce_thres_search + 0x8000U) & 0xffff0000U;
    const u32 hi_52d98 = ((u32)(unsigned long)ref_tisp_lce_hist_method + 0x8000U) & 0xffff0000U;
    const u32 hi_52e20 = (((u32)(unsigned long)ref_printk + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_52e1c = ((u32)(unsigned long)ref_t32_data_c9660 + 0x8000U) & 0xffff0000U;
    const u32 hi_52e50 = ((u32)(unsigned long)ref_tisp_lce_hist_adjust + 0x8000U) & 0xffff0000U;
    const u32 hi_52e88 = ((u32)(unsigned long)ref_tisp_lce_16bit_data_converge + 0x8000U) & 0xffff0000U;
    const u32 hi_52eac = (((u32)(unsigned long)ref_memcpy + (0)) + 0x8000U) & 0xffff0000U;
    const u32 hi_52f08 = ((u32)(unsigned long)ref_get_distance_1dim + 0x8000U) & 0xffff0000U;
    const u32 hi_52f44 = ((u32)(unsigned long)ref_t32_data_d6c67 + 0x8000U) & 0xffff0000U;
    sp = (u32)(unsigned long)&stack[258];
L_4db64:
    sp = sp + -952;
    v0 = a3 & 0xff;
    *(volatile u32 *)(unsigned long)(sp + (944)) = s8;
    *(volatile u32 *)(unsigned long)(sp + (940)) = s7;
    s8 = sp;
    *(volatile u32 *)(unsigned long)(sp + (924)) = s3;
    *(volatile u32 *)(unsigned long)(sp + (920)) = s2;
    *(volatile u32 *)(unsigned long)(sp + (916)) = s1;
    *(volatile u32 *)(unsigned long)(sp + (912)) = s0;
    *(volatile u32 *)(unsigned long)(sp + (948)) = ra;
    *(volatile u32 *)(unsigned long)(sp + (936)) = s6;
    *(volatile u32 *)(unsigned long)(sp + (932)) = s5;
    *(volatile u32 *)(unsigned long)(sp + (928)) = s4;
    *(volatile u32 *)(unsigned long)(s8 + (276)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (12));
    s3 = 0x1U << 16;
    s2 = hi_4dba4;
    *(volatile u32 *)(unsigned long)(s8 + (816)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(a1 + (13));
    s1 = a1;
    *(volatile u32 *)(unsigned long)(s8 + (960)) = a2;
    *(volatile u32 *)(unsigned long)(s8 + (268)) = v0;
    v0 = 0x9000;
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (680)) = v0;
    v0 = 0x9900;
    v0 = a2 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (272)) = v0;
    v0 = s3 + 10496;
    v0 = a2 + v0;
    sp = sp + -80;
    a2 = 32;
    a1 = 0;
    a0 = s8 + 88;
    s2 = s2 - hi_4dba4 + ((u32)(unsigned long)ref_memset + (0));
    callee = s2; *(volatile u32 *)(unsigned long)(s8 + (296)) = v0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4dbf8;
L_4dbf8:
    v0 = *(volatile u8 *)(unsigned long)(s1 + (119));
    s3 = s3 + 22016;
    a0 = *(volatile u8 *)(unsigned long)(s1 + (108));
    *(volatile u32 *)(unsigned long)(s8 + (264)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (120));
    t1 = hi_4dc0c;
    t0 = hi_4dc10;
    *(volatile u32 *)(unsigned long)(s8 + (224)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (121));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = 0;
    *(volatile u16 *)(unsigned long)(s8 + (184)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (228)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    *(volatile u8 *)(unsigned long)(s8 + (186)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (152)) = 0;
    v0 = v0 + s3;
    *(volatile u32 *)(unsigned long)(s8 + (300)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (109));
    *(volatile u32 *)(unsigned long)(s8 + (156)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (160)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (340)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (276));
    *(volatile u32 *)(unsigned long)(s8 + (164)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (136)) = 0;
    v1 = (u32)0 < (u32)(v0);
    v0 = 1;
    if (a0 != 0) v0 = v1;
    *(volatile u32 *)(unsigned long)(s8 + (336)) = v0;
    v0 = hi_4dc68;
    v0 = v0 - hi_4dc68 + (u32)(unsigned long)ref_t32_data_ce200;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u8 *)(unsigned long)(t1 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    *(volatile u32 *)(unsigned long)(s8 + (140)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (144)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (148)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (120)) = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (232)))[i] = vx[1].b[i]; }
    *(volatile u32 *)(unsigned long)(s8 + (124)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (128)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (132)) = 0;
    *(volatile u32 *)(unsigned long)(s8 + (544)) = s2;
    *(volatile u32 *)(unsigned long)(s8 + (168)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(t0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    a2 = hi_4dca4;
    a2 = a2 - hi_4dca4 + (u32)(unsigned long)ref_t32_data_ce140;
    *(volatile u32 *)(unsigned long)(s8 + (172)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (168)))[i]; }
    v0 = hi_4dcb4;
    v0 = v0 - hi_4dcb4 + (u32)(unsigned long)ref_t32_data_d6b50;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[0] = tmp; }
    a1 = hi_4dcc0;
    a1 = a1 - hi_4dcc0 + (u32)(unsigned long)ref_t32_data_ce150;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    a0 = hi_4dcd0;
    a0 = a0 - hi_4dcd0 + (u32)(unsigned long)ref_t32_data_ce160;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (208)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    v0 = s8 + 696;
    v1 = hi_4dcec;
    v1 = v1 - hi_4dcec + (u32)(unsigned long)ref_t32_data_ce170;
    a3 = 32;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    s0 = sp + 39;
    s0 = s0 >> (0x4 & 31);
    s0 = s0 << (0x4 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    v0 = s8 + 712;
    s7 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    v0 = s8 + 728;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    v0 = hi_4dd2c;
    v0 = v0 - hi_4dd2c + (u32)(unsigned long)ref_t32_data_d6b60;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (344)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s1 + 181;
    *(volatile u32 *)(unsigned long)(s8 + (376)) = v0;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (360)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s1 + 161;
    *(volatile u32 *)(unsigned long)(s8 + (380)) = v0;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (384)))[i] = vx[6].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (400)))[i] = vx[6].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (416)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (432)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s1 + (197)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (448)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 512;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (464)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (480)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (496)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s1 + (177)))[i]; }
    v0 = s8 + 528;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (680));
    *(volatile u32 *)(unsigned long)(s8 + (332)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (268));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (268));
    *(volatile u32 *)(unsigned long)(s8 + (600)) = 0;
    v0 = a3 - v0;
    v0 = v0 >> (0x4 & 31);
    v0 = v0 << (0x4 & 31);
    t2 = v0 + t2;
    a3 = a3 - t2;
    v0 = v0 & 0xffff;
    *(volatile u32 *)(unsigned long)(s8 + (628)) = v0;
    v0 = a3 & 0xffff;
    *(volatile u32 *)(unsigned long)(s8 + (744)) = v0;
    v0 = s8 + 696;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    *(volatile u32 *)(unsigned long)(s8 + (328)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (304)) = t1;
    *(volatile u32 *)(unsigned long)(s8 + (308)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (548)) = a2;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 712;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 648;
    *(volatile u32 *)(unsigned long)(s8 + (616)) = a1;
    *(volatile u32 *)(unsigned long)(s8 + (620)) = a0;
    *(volatile u32 *)(unsigned long)(s8 + (624)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 728;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 664;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 632;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 768;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] << (8 & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 648;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 784;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] << (8 & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 664;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 800;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] << (8 & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[1] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (248)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (192)))[i] = vx[1].b[i]; }
L_4de98:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (816));
    *(volatile u32 *)(unsigned long)(s8 + (312)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (312));
    v0 = *(volatile u32 *)(unsigned long)(s8 + (600));
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); a0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    if (branch) goto L_50678;
    goto L_4deb4;
L_4deb4:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (32));
    a3 = *(volatile u32 *)(unsigned long)(s1 + (68));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (201));
    a2 = s8 + 88;
    v1 = a2;
    *(volatile u16 *)(unsigned long)(s8 + (188)) = v0;
L_4ded0:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (268));
    v0 = v1 - a2;
    v0 = (s32)v0 < (s32)(a1);
    branch = (v0 == 0); v1 = v1 + 1;
    if (branch) goto L_4df04;
    goto L_4dee4;
L_4dee4:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 + 4;
    v0 = a3 * v0;
    a1 = (v0 >> 0x17) & ((1U << 0x1) - 1);
    v0 = v0 >> (0x18 & 31);
    v0 = a1 + v0;
    *(volatile u8 *)(unsigned long)(v1 + (-1)) = v0; goto L_4ded0;
L_4df04:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (188)))[i]; }
    s2 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[0]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (280)))[i] = vx[1].b[i]; }
L_4df14:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (268));
    s3 = s7 + s2;
    v0 = v0 + -16;
    v0 = (s32)v0 < (s32)(s2);
    branch = (v0 == 0); s3 = s3 & 0xffff;
    if (branch) goto L_4df48;
    goto L_4df2c;
L_4df2c:
    s4 = hi_4df2c;
    v0 = s4 - hi_4df2c + (u32)(unsigned long)ref_t32_data_e188c;
    s5 = hi_4df34;
    *(volatile u32 *)(unsigned long)(s8 + (280)) = v0;
    s6 = hi_4df3c;
    s5 = s5 - hi_4df34 + (u32)(unsigned long)ref_t32_data_bf994; goto L_4f164;
L_4df48:
    s6 = hi_4df48;
    s5 = s3 << (0x6 & 31);
    v1 = 0;
    s6 = s6 - hi_4df48 + (u32)(unsigned long)ref_memcpy_simd;
    a3 = 1024;
    v0 = s8 + 552;
L_4df60:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a0 = s5 + v1;
    a2 = 64;
    a1 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    *(volatile u32 *)(unsigned long)(s8 + (568)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (312)) = v1;
    callee = s6; a0 = v0 + a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4df88;
L_4df88:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (312));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (568));
    v0 = s8 + 552;
    v1 = v1 + 64;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (v1 != a3); s4 = s6;
    if (branch) goto L_4df60;
    goto L_4dfa4;
L_4dfa4:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a1 = hi_4dfa8;
    a3 = s8 + 120;
    s5 = v0 + s5;
    v0 = s8 + 136;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_4dfbc;
    a0 = s5;
    a1 = a1 - hi_4dfa8 + (u32)(unsigned long)ref_t32_data_e188c;
    v0 = v0 - hi_4dfbc + (u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a2 = s8 + 152;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4dfd8;
L_4dfd8:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    a1 = hi_4dfdc;
    v1 = a0;
    a3 = s5;
    a0 = 0;
    a1 = a1 - hi_4dfdc + (u32)(unsigned long)ref_t32_data_e1e48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    t4 = 32;
L_4dffc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v1 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v1 + (32)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v1 + (48)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    t5 = a1 + a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[12].h[i] > vx[1].h[i] ? vx[12].h[i] - vx[1].h[i] : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[11].h[i] > vx[1].h[i] ? vx[11].h[i] - vx[1].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[10].h[i] > vx[1].h[i] ? vx[10].h[i] - vx[1].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[9].h[i] > vx[1].h[i] ? vx[9].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[12].h[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[11].h[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[10].h[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[9].h[i]) ? ~0U : 0; vx[4] = tmp; }
    a0 = a0 + 2;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[3].w[i] & vx[7].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[8].w[i] & vx[5].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[4].w[i]) | (vx[1].w[i] & vx[4].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[7].w[i]) | (vx[13].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[3].h[i] + vx[2].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[3].h[i] + vx[2].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[6].w[i]) | (vx[13].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[2].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[2].h[i] + vx[1].h[i]); vx[1] = tmp; }
    a2 = (s16)vx[1].h[1];
    v0 = (s16)vx[1].h[0];
    t0 = (s16)vx[1].h[5];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[5].w[i]) | (vx[13].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[4].w[i]) | (vx[13].w[i] & vx[4].w[i]); vx[4] = tmp; }
    v0 = v0 + a2;
    a2 = (s16)vx[1].h[2];
    v1 = v1 + 64;
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[3];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[4];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[6];
    v0 = t0 + v0;
    a2 = a2 + v0;
    v0 = (s16)vx[1].h[7];
    v0 = v0 + a2;
    *(volatile u16 *)(unsigned long)(t5 + (0)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-64)))[i] = vx[7].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-48)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-32)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-16)))[i] = vx[4].b[i]; }
    branch = (a0 != t4); s5 = a1;
    if (branch) goto L_4dffc;
    goto L_4e0c4;
L_4e0c4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(s8 + (120)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(s8 + (152)))[i]; }
    v0 = hi_4e0cc;
    v0 = v0 - hi_4e0cc + (u32)(unsigned long)ref_t32_data_e1e58;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e0d8;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) < (-128LL) ? (-128LL) : (((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) > 127LL ? 127LL : ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i])); vx[9] = tmp; }
    v0 = v0 - hi_4e0d8 + (u32)(unsigned long)ref_t32_data_ce1b0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e0ec;
    v0 = v0 - hi_4e0ec + (u32)(unsigned long)ref_t32_data_ce1c0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[1].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[2] = tmp; }
    v0 = hi_4e104;
    v0 = v0 - hi_4e104 + (u32)(unsigned long)ref_t32_data_e1e68;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[1].h[i] == 0) ? ~0U : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[4].h[i] == 0) ? ~0U : 0; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(s8 + (136)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[19] = tmp; }
    t0 = a1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[8].w[i]) | (vx[1].w[i] & vx[8].w[i]); vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[3].w[i]) | (vx[4].w[i] & vx[3].w[i]); vx[14] = tmp; }
    a1 = 20;
    a1 = s3 * a1;
    s3 = hi_4e148;
    s3 = s3 - hi_4e148 + (u32)(unsigned long)ref_t32_data_ce1d0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[14].w[i]) | (vx[0].w[i] & vx[14].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[8].w[i]) | (vx[0].w[i] & vx[8].w[i]); vx[1] = tmp; }
    s6 = s5;
    t2 = 16;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_4e164;
    v0 = v0 - hi_4e164 + (u32)(unsigned long)ref_t32_data_e1e78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 1; vx[1] = tmp; }
    v0 = hi_4e174;
    v0 = v0 - hi_4e174 + (u32)(unsigned long)ref_t32_data_e1e88;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[6].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[6].h[i] + vx[1].h[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[5].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[5].h[i] + vx[1].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[2].h[i] >> (1 & 15); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] >> (1 & 15); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[6].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[6].h[i] + vx[1].h[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[9].h[i] >> (2 & 15); vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = vx[10].b[i] > vx[11].b[i] ? vx[10].b[i] - vx[11].b[i] : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[5].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[5].h[i] + vx[1].h[i]); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[8].w[i]) | (vx[0].w[i] & vx[8].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[14].w[i]) | (vx[0].w[i] & vx[14].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[17].h[i] >> (2 & 15); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[14].w[i]) | (vx[18].w[i] & vx[14].w[i]); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[2].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    v0 = hi_4e1bc;
    v0 = v0 - hi_4e1bc + (u32)(unsigned long)ref_t32_data_e1e98;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[8].w[i]) | (vx[17].w[i] & vx[8].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    v0 = hi_4e1d0;
    v0 = v0 - hi_4e1d0 + (u32)(unsigned long)ref_t32_data_e1ea8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[16].b[i]; }
    v0 = hi_4e1dc;
    v0 = v0 - hi_4e1dc + (u32)(unsigned long)ref_t32_data_e1eb8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[13].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[19].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    v0 = hi_4e1f0;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[19].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[2].h[i] == 0) ? ~0U : 0; vx[19] = tmp; }
    v0 = v0 - hi_4e1f0 + (u32)(unsigned long)ref_t32_data_e1ec8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[16].b[i]; }
    v0 = hi_4e204;
    v0 = v0 - hi_4e204 + (u32)(unsigned long)ref_t32_data_e1ed8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[9].h[i] == 0) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[19].w[i]) | (vx[2].w[i] & vx[19].w[i]); vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    v0 = hi_4e21c;
    v0 = v0 - hi_4e21c + (u32)(unsigned long)ref_t32_data_e1ee8;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[7].w[i]) | (vx[9].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[5].h[i] > vx[1].h[i] ? vx[5].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[5].h[i] > vx[15].h[i] ? vx[5].h[i] - vx[15].h[i] : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[13].w[i]) | (vx[0].w[i] & vx[13].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[7].w[i]) | (vx[0].w[i] & vx[7].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[13].w[i]) | (vx[18].w[i] & vx[13].w[i]); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    v0 = hi_4e240;
    v0 = v0 - hi_4e240 + (u32)(unsigned long)ref_t32_data_e1ef8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[6].h[i] > vx[3].h[i] ? vx[6].h[i] - vx[3].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[6].h[i] > vx[16].h[i] ? vx[6].h[i] - vx[16].h[i] : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[5].h[i] > vx[15].h[i] ? vx[5].h[i] - vx[15].h[i] : 0; vx[5] = tmp; }
    v0 = hi_4e258;
    v0 = v0 - hi_4e258 + (u32)(unsigned long)ref_t32_data_e1f08;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[17].w[i] & vx[7].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[6].h[i] > vx[16].h[i] ? vx[6].h[i] - vx[16].h[i] : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[8].w[i]) | (vx[5].w[i] & vx[8].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[7].w[i]) | (vx[0].w[i] & vx[7].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[14].w[i]) | (vx[6].w[i] & vx[14].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[6].h[i] > vx[9].h[i] ? vx[6].h[i] - vx[9].h[i] : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[13].w[i]) | (vx[0].w[i] & vx[13].w[i]); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    v0 = hi_4e280;
    v0 = v0 - hi_4e280 + (u32)(unsigned long)ref_t32_data_e1f18;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    v0 = hi_4e28c;
    v0 = v0 - hi_4e28c + (u32)(unsigned long)ref_t32_data_e1f28;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[9].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[15] = tmp; }
    v0 = hi_4e29c;
    v0 = v0 - hi_4e29c + (u32)(unsigned long)ref_t32_data_e1f38;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[2].h[i] > vx[9].h[i] ? vx[2].h[i] - vx[9].h[i] : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[5].h[i] > vx[15].h[i] ? vx[5].h[i] - vx[15].h[i] : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[i] > vx[15].h[i] ? vx[1].h[i] - vx[15].h[i] : 0; vx[2] = tmp; }
    v0 = hi_4e2b4;
    v0 = v0 - hi_4e2b4 + (u32)(unsigned long)ref_t32_data_e1f48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[14].w[i]) | (vx[6].w[i] & vx[14].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[8].w[i]) | (vx[5].w[i] & vx[8].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[13].w[i]) | (vx[3].w[i] & vx[13].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[1].w[i] & vx[7].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_4e2d0;
    v0 = v0 - hi_4e2d0 + (u32)(unsigned long)ref_t32_data_e1f58;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = (vx[10].b[i] == vx[0].b[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 1; vx[2] = tmp; }
    v0 = hi_4e2e4;
    v0 = v0 - hi_4e2e4 + (u32)(unsigned long)ref_t32_data_e1f68;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[12].b[i]; }
    v0 = hi_4e300;
    v0 = v0 - hi_4e300 + (u32)(unsigned long)ref_t32_data_e1f78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[11].b[i]; }
    v0 = hi_4e30c;
    v0 = v0 - hi_4e30c + (u32)(unsigned long)ref_t32_data_e1f88;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[10].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (300));
    t1 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (296));
    a1 = v0 + a1;
    v0 = s8 + 848;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4e330;
    v0 = v0 - hi_4e330 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e33c;
    v0 = v0 - hi_4e33c + (u32)(unsigned long)ref_t32_data_ce1f0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4e354;
    v0 = v0 - hi_4e354 + (u32)(unsigned long)ref_t32_data_ce1a0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 864;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (548));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4e378;
    v0 = v0 - hi_4e378 + (u32)(unsigned long)ref_t32_data_ce180;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4e38c;
    v0 = v0 - hi_4e38c + (u32)(unsigned long)ref_t32_data_ce190;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 752;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
L_4e3a0:
    a2 = *(volatile u16 *)(unsigned long)(t0 + (32));
    v0 = hi_4e3a4;
    a0 = 1;
    branch = (a2 != a0); v1 = v0 - hi_4e3a4 + (u32)(unsigned long)ref_t32_data_bf9ec;
    if (branch) goto L_4e4b0;
    goto L_4e3b4;
L_4e3b4:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (64));
    t3 = hi_4e3bc;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = 0;
    t3 = t3 - hi_4e3bc + (u32)(unsigned long)ref_t32_data_d6be4;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_4e3ec:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a2);
    if (v0 != 0) { t4 = *(volatile u32 *)(unsigned long)(s8 + (24)); goto L_4e420; }
    goto L_4e400;
L_4e400:
    v0 = a0 + 336;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t3 + (a0)))[i]; }
    v0 = a0 + 464;
    a2 = a2 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[2].b[i]; }
    a0 = a0 + 16; goto L_4e3ec;
L_4e420:
    v0 = a2 << (0x2 & 31);
    t3 = hi_4e424;
    v0 = s5 + v0;
    t3 = t3 - hi_4e424 + (u32)(unsigned long)ref_t32_data_d6be4;
L_4e430:
    a0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = (s32)a2 < (s32)(a0);
    branch = (a0 == 0); v0 = v0 + 4;
    if (branch) goto L_4e45c;
    goto L_4e440;
L_4e440:
    a0 = a2 << (0x2 & 31);
    a0 = t3 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (332)) = t4;
    a2 = a2 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (460)) = a0; goto L_4e430;
L_4e45c:
    a0 = *(volatile u16 *)(unsigned long)(t0 + (160));
    v0 = 1;
    branch = (a0 != v0); v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    if (branch) goto L_4e7d8;
    goto L_4e46c;
L_4e46c:
    a0 = 31;
    a0 = a0 - v0;
    a0 = a0 << (0x1 & 31);
    v1 = v1 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (192));
    a2 = v0 << (0x2 & 31);
    t4 = a2 + 336;
    v1 = v1 * a0;
    t5 = a2 + 464;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v1 = hi_4e4a0;
    v1 = v1 - hi_4e4a0 + (u32)(unsigned long)ref_t32_data_d6b64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; } goto L_4e630;
L_4e4b0:
    a2 = *(volatile u8 *)(unsigned long)(s6 + (288));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (96));
    t4 = hi_4e4b8;
    v0 = a2 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t3 = 0;
    t4 = t4 - hi_4e4b8 + (u32)(unsigned long)ref_t32_data_d6b64;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = 32;
    a2 = v0 - a2;
    a2 = a2 & 0xff;
    a2 = a2 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_4e4f8:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (288));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a0);
    branch = (v0 != 0); t5 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_4e530;
    goto L_4e50c;
L_4e50c:
    v0 = t3 + 336;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[1].b[i]; }
    v0 = t3 + a2;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t4 + (v0)))[i]; }
    v0 = t3 + 464;
    a0 = a0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[2].b[i]; }
    t3 = t3 + 16; goto L_4e4f8;
L_4e530:
    v0 = a0 << (0x2 & 31);
    t4 = hi_4e534;
    v0 = s5 + v0;
    t4 = t4 - hi_4e534 + (u32)(unsigned long)ref_t32_data_d6b64;
L_4e540:
    t3 = *(volatile u8 *)(unsigned long)(s6 + (288));
    t6 = (s32)a0 < (s32)(t3);
    branch = (t6 == 0); v0 = v0 + 4;
    if (branch) goto L_4e570;
    goto L_4e550;
L_4e550:
    t3 = a0 << (0x2 & 31);
    t3 = t3 + a2;
    t3 = t4 + t3;
    t3 = *(volatile u32 *)(unsigned long)(t3 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (332)) = t5;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (460)) = t3; goto L_4e540;
L_4e570:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (128));
    a2 = t3 + 84;
    v0 = v0 - t3;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = a2 << (0x2 & 31);
    a2 = s5 + a2;
    v0 = v0 * a0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = t3;
    t3 = hi_4e5a8;
    t3 = t3 - hi_4e5a8 + (u32)(unsigned long)ref_t32_data_d6be4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[0]; vx[2] = tmp; }
L_4e5b4:
    a0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = a0 + -4;
    a0 = (s32)a0 < (s32)(v0);
    branch = (a0 != 0); t4 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_4e5ec;
    goto L_4e5c8;
L_4e5c8:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(s6 + (288));
    a2 = a2 + 16;
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t3 + (a0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (112)))[i] = vx[1].b[i]; }
    v0 = v0 + 4; goto L_4e5b4;
L_4e5ec:
    a2 = v0 << (0x2 & 31);
    t3 = hi_4e5f0;
    a2 = s5 + a2;
    t3 = t3 - hi_4e5f0 + (u32)(unsigned long)ref_t32_data_d6be4;
L_4e5fc:
    a0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = (s32)v0 < (s32)(a0);
    branch = (a0 == 0); a2 = a2 + 4;
    if (branch) goto L_4e45c;
    goto L_4e60c;
L_4e60c:
    *(volatile u32 *)(unsigned long)(a2 + (332)) = t4;
    a0 = *(volatile u8 *)(unsigned long)(s6 + (288));
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + t3;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a2 + (460)) = a0; goto L_4e5fc;
L_4e630:
    t3 = (s32)v0 < (s32)(29);
    branch = (t3 == 0); t3 = t4 + a0;
    if (branch) goto L_4e65c;
    goto L_4e63c;
L_4e63c:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (t3)))[i] = vx[1].b[i]; }
    t3 = a0 + a2;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v1 + (t3)))[i]; }
    t3 = t5 + a0;
    v0 = v0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (t3)))[i] = vx[2].b[i]; }
    a0 = a0 + 16; goto L_4e630;
L_4e65c:
    t3 = *(volatile u32 *)(unsigned long)(s8 + (24));
    a2 = v0 << (0x2 & 31);
    a0 = s5 + a2;
    v1 = v1 + a2;
L_4e66c:
    a2 = (s32)v0 < (s32)(32);
    branch = (a2 == 0); a0 = a0 + 4;
    if (branch) goto L_4e690;
    goto L_4e678;
L_4e678:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (332)) = t3;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (460)) = a2;
    v1 = v1 + 4; goto L_4e66c;
L_4e690:
    v0 = hi_4e690;
    v0 = v0 - hi_4e690 + (u32)(unsigned long)ref_t32_data_e1f98;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e69c;
    v0 = v0 - hi_4e69c + (u32)(unsigned long)ref_t32_data_e1fa8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6a8;
    v0 = v0 - hi_4e6a8 + (u32)(unsigned long)ref_t32_data_e1fb8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[16].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6b4;
    v0 = v0 - hi_4e6b4 + (u32)(unsigned long)ref_t32_data_e1fc8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6c0;
    v0 = v0 - hi_4e6c0 + (u32)(unsigned long)ref_t32_data_e1fd8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6cc;
    v0 = v0 - hi_4e6cc + (u32)(unsigned long)ref_t32_data_e1fe8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6d8;
    v0 = v0 - hi_4e6d8 + (u32)(unsigned long)ref_t32_data_e1ff8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6e4;
    v0 = v0 - hi_4e6e4 + (u32)(unsigned long)ref_t32_data_e2008;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6f0;
    v0 = v0 - hi_4e6f0 + (u32)(unsigned long)ref_t32_data_e2018;
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e6fc;
    v0 = v0 - hi_4e6fc + (u32)(unsigned long)ref_t32_data_e2028;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e708;
    v0 = v0 - hi_4e708 + (u32)(unsigned long)ref_t32_data_e2038;
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e714;
    v0 = v0 - hi_4e714 + (u32)(unsigned long)ref_t32_data_e2048;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e720;
    v0 = v0 - hi_4e720 + (u32)(unsigned long)ref_t32_data_e2058;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4e72c;
    v0 = v0 - hi_4e72c + (u32)(unsigned long)ref_t32_data_e2068;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[4].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[5].w[i]; vx[5] = tmp; }
    v0 = hi_4e740;
    v0 = v0 - hi_4e740 + (u32)(unsigned long)ref_t32_data_e2078;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    v0 = hi_4e750;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 15; vx[1] = tmp; }
    v0 = v0 - hi_4e750 + (u32)(unsigned long)ref_t32_data_e2088;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 848;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[2].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[12].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[5].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[13].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[15].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[14].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[16].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    t3 = a3 + 16;
    a2 = a3 + 32;
    a0 = a3 + 48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[4].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[8].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[10].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[9].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[11].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[3].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[6].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    t4 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    v0 = 0;
    t6 = s0 + 48;
    t5 = 16; goto L_4e8b4;
L_4e7d8:
    t3 = *(volatile u8 *)(unsigned long)(s6 + (320));
    t6 = hi_4e7dc;
    t4 = v0 << (0x2 & 31);
    a0 = t3 - v0;
    a0 = a0 + -1;
    a0 = a0 << (0x1 & 31);
    a0 = v1 + a0;
    a2 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (224));
    t5 = 0;
    t6 = t6 - hi_4e7dc + (u32)(unsigned long)ref_t32_data_d6b64;
    a2 = a2 * a0;
    a0 = v0;
    v0 = 32;
    v0 = v0 - t3;
    v0 = v0 & 0xff;
    v0 = v0 + a0;
    v0 = v0 << (0x2 & 31);
L_4e820:
    t3 = *(volatile u8 *)(unsigned long)(s6 + (320));
    t7 = (s32)a0 < (s32)(t3);
    branch = (t7 == 0); t7 = t5 + v0;
    if (branch) goto L_4e854;
    goto L_4e830;
L_4e830:
    t7 = t6 + t7;
    t7 = *(volatile u32 *)(unsigned long)(t7 + (0));
    t3 = t5 + t4;
    t3 = s5 + t3;
    *(volatile u32 *)(unsigned long)(t3 + (336)) = a2;
    *(volatile u32 *)(unsigned long)(t3 + (464)) = t7;
    a0 = a0 + 1;
    t5 = t5 + 4; goto L_4e820;
L_4e854:
    v0 = 31;
    v0 = v0 - t3;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(t0 + (256));
    v1 = t3 << (0x2 & 31);
    a2 = hi_4e870;
    a0 = a0 * v0;
    v1 = s5 + v1;
    a2 = a2 - hi_4e870 + (u32)(unsigned long)ref_t32_data_d6be4;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = a0;
L_4e884:
    v0 = (s32)t3 < (s32)(32);
    branch = (v0 == 0); v1 = v1 + 4;
    if (branch) goto L_4e690;
    goto L_4e890;
L_4e890:
    *(volatile u32 *)(unsigned long)(v1 + (332)) = a0;
    v0 = *(volatile u8 *)(unsigned long)(s6 + (320));
    v0 = t3 - v0;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + a2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t3 = t3 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (460)) = v0; goto L_4e884;
L_4e8b4:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (592)) = v0;
    v1 = t6 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_4e8b4;
    goto L_4e8d4;
L_4e8d4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(s3 + (0)))[i]; }
    t4 = 0;
    t6 = s0 + 32;
    t5 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[1].h[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (32)))[i] = vx[5].b[i]; }
L_4e8f0:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (608)) = v0;
    v1 = t6 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_4e8f0;
    goto L_4e910;
L_4e910:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s3 + (0)))[i]; }
    t4 = 0;
    t6 = s0 + 16;
    t5 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[13].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
L_4e92c:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (624)) = v0;
    v1 = t6 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_4e92c;
    goto L_4e94c;
L_4e94c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s3 + (0)))[i]; }
    t4 = 0;
    t5 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[9].h[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (0)))[i] = vx[2].b[i]; }
L_4e964:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (640)) = v0;
    v1 = s0 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_4e964;
    goto L_4e984;
L_4e984:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[4].b[i]; }
    v1 = hi_4e988;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t3 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_4e988 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[4].h[i] + (u16)vx[5].h[i]; vx[4] = tmp; }
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[2].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    t3 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    a2 = hi_4e9c4;
    a2 = a2 - hi_4e9c4 + (u32)(unsigned long)ref_t32_data_e20a8;
    a0 = hi_4e9cc;
    a0 = a0 - hi_4e9cc + (u32)(unsigned long)ref_t32_data_e20b8;
    v1 = hi_4e9d4;
    v1 = v1 - hi_4e9d4 + (u32)(unsigned long)ref_t32_data_e20c8;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (176)) = v0;
    v0 = hi_4e9e4;
    v0 = v0 - hi_4e9e4 + (u32)(unsigned long)ref_t32_data_e2098;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (176)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[1].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    t3 = s8 + 864;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[7].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[3].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[6].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[10].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[5].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[9].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[4].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] >> (vx[4].w[i] & 31)) + ((vx[4].w[i] & 31) ? ((vx[1].w[i] >> (((vx[4].w[i] & 31) - 1) & 31)) & 1) : 0); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[5].b[i]; }
    a2 = 12;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (0)))[i] = vx[3].b[i]; }
    v1 = 0;
L_4eac0:
    a0 = v1 << (0x2 & 31);
    a0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (18));
    t3 = a1 + v1;
    v1 = v1 + 1;
    branch = (v1 != a2); *(volatile u8 *)(unsigned long)(t3 + (8)) = a0;
    if (branch) goto L_4eac0;
    goto L_4eadc;
L_4eadc:
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (616));
    a2 = a1 + 16;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (620));
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (448)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (624));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[19] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 648;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i])); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 664;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i])); vx[19] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 512;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i])); vx[16] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (344)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i])); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[17] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (360)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (416)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (464)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] * (u32)vx[2].w[i]; vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (432)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] << (8 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[3].w[i]; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[1].w[i]; vx[21] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (480)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] * (u32)vx[1].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (496)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] * (u32)vx[1].w[i]; vx[14] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 528;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[16].w[i] < 0) ? ~0U : 0; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i] < 0) ? ~0U : 0; vx[12] = tmp; }
    v0 = s8 + 768;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[16].w[i]) | (vx[4].w[i] & vx[16].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (384)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i] < 0) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[12].w[i]) | (vx[2].w[i] & vx[12].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[17].w[i] << (8 & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (400)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[15].w[i] < 0) ? ~0U : 0; vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[11].w[i]) | (vx[20].w[i] & vx[11].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 784;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[15].w[i]) | (vx[9].w[i] & vx[15].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[19].w[i] < 0) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i])); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 800;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[19].w[i]) | (vx[1].w[i] & vx[19].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i])); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[1] = tmp; }
    v0 = s8 + 584;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] >> (8 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] >> (8 & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] >> (8 & 31); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] >> (8 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (8 & 31); vx[2] = tmp; }
    v0 = s8 + 752;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = (s32)vx[4].w[0];
    *(volatile u8 *)(unsigned long)(a1 + (16)) = v0;
    v0 = (s32)vx[4].w[1];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    *(volatile u8 *)(unsigned long)(a1 + (17)) = v0;
    v0 = (s32)vx[4].w[2];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[3].b[i]; }
    *(volatile u8 *)(unsigned long)(a1 + (18)) = v0;
    v0 = (s32)vx[4].w[3];
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    *(volatile u8 *)(unsigned long)(a1 + (19)) = v0;
    v0 = 4;
    branch = (v1 != v0); t3 = a1 + 20;
    if (branch) goto L_4ecf8;
    goto L_4ec90;
L_4ec90:
    v0 = s8 + 880;
L_4ec94:
    a0 = t1;
    a2 = 20;
    *(volatile u32 *)(unsigned long)(s8 + (904)) = t3;
    *(volatile u32 *)(unsigned long)(s8 + (900)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (896)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (748)) = t0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    callee = s4; *(volatile u32 *)(unsigned long)(s8 + (832)) = t1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4ecb8;
L_4ecb8:
    t2 = *(volatile u32 *)(unsigned long)(s8 + (900));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (748));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (832));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (904));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (896));
    v0 = s8 + 880;
    t2 = t2 + -1;
    t0 = t0 + 2;
    t1 = t1 + 20;
    a1 = t3;
    a3 = a3 + 64;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (t2 != 0); s6 = s6 + 1;
    if (branch) goto L_4e3a0;
    goto L_4ecf0;
L_4ecf0:
    s2 = s2 + 16; goto L_4df14;
L_4ecf8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[9] = tmp; }
    v0 = 64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[14] = tmp; }
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[22].w[i] | vx[22].w[i]; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] | vx[2].w[i]; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[23].w[i] | vx[23].w[i]; vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[13].w[i] | vx[13].w[i]; vx[25] = tmp; }
    v0 = s8 + 832;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[23].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[23].w[i] + vx[7].w[i]); vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[22].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[22].w[i] + vx[7].w[i]); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[13].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[13].w[i] + vx[7].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[2].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[2].w[i] + vx[7].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[17].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[17].w[i] + vx[7].w[i]); vx[30] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[8].w[i] + vx[7].w[i]); vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[18].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[18].w[i] + vx[7].w[i]); vx[28] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[1].w[i] + vx[7].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[7].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i])); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i])); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i])); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[2].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[15].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[15].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[15].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[15].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[23].w[i]  < (s32)vx[17].w[i]) ? ~0U : 0; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[7].w[i] + vx[14].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[7].w[i] >> (7 & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[12].w[i] + vx[14].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[11].w[i] + vx[14].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[10].w[i] + vx[14].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (7 & 31); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[7].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[11].w[i] >> (7 & 31); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[10].w[i] >> (7 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] | vx[15].w[i]; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[31].w[i]) | (vx[15].w[i] & vx[31].w[i]); vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[7].w[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[10].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[21].w[i]) | (vx[15].w[i] & vx[21].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[12].w[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[31].w[i] & ~vx[7].w[i]) | (vx[9].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[20].w[i]) | (vx[15].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[19].w[i]) | (vx[15].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[11].w[i]) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] + (u32)vx[7].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[10].w[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[12].w[i]) | (vx[9].w[i] & vx[12].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[22].w[i]  < (s32)vx[8].w[i]) ? ~0U : 0; vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[2].w[i]) | (vx[7].w[i] & vx[2].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[11].w[i]) | (vx[9].w[i] & vx[11].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[10].w[i]) | (vx[9].w[i] & vx[10].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[18].w[i]) ? ~0U : 0; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[27].w[i] + (u32)vx[12].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[26].w[i] + (u32)vx[11].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[10].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[17].w[i] & ~vx[23].w[i]) | (vx[12].w[i] & vx[23].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[8].w[i] & ~vx[22].w[i]) | (vx[11].w[i] & vx[22].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[6].w[i] + vx[14].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[5].w[i] + vx[14].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[4].w[i] + vx[14].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[3].w[i] + vx[14].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (7 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (7 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (7 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[14].w[i] >> (7 & 31); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[18].w[i] & ~vx[13].w[i]) | (vx[10].w[i] & vx[13].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[6].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[5].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[4].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[14].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[21].w[i]) | (vx[16].w[i] & vx[21].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[20].w[i]) | (vx[16].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[19].w[i]) | (vx[16].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[2].w[i]) | (vx[16].w[i] & vx[2].w[i]); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[5].w[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[4].w[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[14].w[i]) ? ~0U : 0; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[6].w[i]) | (vx[9].w[i] & vx[6].w[i]); vx[6] = tmp; }
    v0 = s8 + 584;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[5].w[i]) | (vx[9].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[4].w[i]) | (vx[9].w[i] & vx[4].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[16].w[i] & ~vx[14].w[i]) | (vx[9].w[i] & vx[14].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i])); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[30].w[i]  < (s32)vx[27].w[i]) ? ~0U : 0; vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[24].w[i]) ? ~0U : 0; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[29].w[i]  < (s32)vx[26].w[i]) ? ~0U : 0; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[28].w[i]  < (s32)vx[25].w[i]) ? ~0U : 0; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[27].w[i]) | (vx[6].w[i] & vx[27].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[24].w[i]) | (vx[15].w[i] & vx[24].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[26].w[i]) | (vx[5].w[i] & vx[26].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[25].w[i]) | (vx[4].w[i] & vx[25].w[i]); vx[10] = tmp; }
    v0 = s8 + 752;
    t4 = t1 + 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[11].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[10].b[i]; }
L_4ef10:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u8 *)(unsigned long)(t4 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    t5 = v1 + a0;
    v1 = (s32)t5 < (s32)(v0);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    if (branch) goto L_4ef78;
    goto L_4ef2c;
L_4ef2c:
    v1 = v0 - a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v1 = v1 + 64;
    v1 = (s32)v1 >> (0x7 & 31);
    v0 = (s32)v1 < (s32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_4ef58;
    goto L_4ef50;
L_4ef50:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = t5; goto L_4efd4;
L_4ef58:
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); v1 = a0 + v1;
    if (branch) goto L_4ef70;
    goto L_4ef64;
L_4ef64:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    a0 = v0 + a0; goto L_4efb4;
L_4ef70:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = v1; goto L_4efd4;
L_4ef78:
    v1 = v1 + v0;
    v1 = (s32)v1 < (s32)(a0);
    if (v1 == 0) { a2 = a2 + 1; goto L_4efd8; }
    goto L_4ef88;
L_4ef88:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = a0 - v0;
    v0 = v0 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v1 = (s32)v0 < (s32)(v1);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_4efbc;
    goto L_4efac;
L_4efac:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
L_4efb0:
    a0 = a0 - v0;
L_4efb4:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = a0; goto L_4efd4;
L_4efbc:
    v1 = (s32)v1 < (s32)(v0);
    if (v1 == 0) { v0 = a0 - v0; goto L_4efd0; }
    goto L_4efc8;
L_4efc8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228)); goto L_4efb0;
L_4efd0:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = v0;
L_4efd4:
    a2 = a2 + 1;
L_4efd8:
    branch = (t3 != a2); t4 = t4 + 1;
    if (branch) goto L_4ef10;
    goto L_4efe0;
L_4efe0:
    v0 = s8 + 880; goto L_4ec94;
L_4efe8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (336));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    branch = (v0 == 0); s4 = s3 << (0x6 & 31);
    if (branch) goto L_4f180;
    goto L_4eff8;
L_4eff8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a2 = 64;
    a1 = v0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    a0 = v0 + s4;
L_4f00c:
    v0 = hi_4f00c;
    v0 = v0 - hi_4f00c + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f01c;
L_4f01c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (280));
    a2 = s8 + 184;
    s4 = v0 + s4;
    v0 = s6 - hi_4df3c + (u32)(unsigned long)ref_tisp_lce_thres_search;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f040;
L_4f040:
    v0 = s8 + s2;
    a3 = *(volatile u8 *)(unsigned long)(v0 + (88));
    v0 = *(volatile u16 *)(unsigned long)(s8 + (180));
    a2 = s8 + 184;
    a1 = s8 + 188;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_4f058;
    v0 = v0 - hi_4f058 + (u32)(unsigned long)ref_tisp_lce_hist_method;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f068;
L_4f068:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (544));
    a0 = s8 + 24;
    a2 = 64;
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f07c;
L_4f07c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    v1 = 0;
    v0 = 0;
    a0 = 64;
L_4f08c:
    a1 = s8 + 24;
    a1 = a1 + v1;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = v0;
    a1 = s4 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v1 = v1 + 2;
    v0 = v0 + a1;
    branch = (v1 != a0); v0 = v0 & 0xffff;
    if (branch) goto L_4f08c;
    goto L_4f0b0;
L_4f0b0:
    v1 = 20;
    s3 = s3 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (296));
    branch = (v0 != 0); s4 = v1 + s3;
    if (branch) goto L_4f1c8;
    goto L_4f0c4;
L_4f0c4:
    a0 = hi_4f0c4;
    v0 = hi_4f0c8;
    a2 = 1065;
    a1 = s5;
    v0 = v0 - hi_4f0c8 + ((u32)(unsigned long)ref_printk + (0));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = a0 - hi_4f0c4 + (u32)(unsigned long)ref_t32_data_c9660;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f0e4;
L_4f0e4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    a2 = *(volatile u32 *)(unsigned long)(s8 + (376));
L_4f0ec:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (380));
    v0 = hi_4f0f0;
    v0 = v0 - hi_4f0f0 + (u32)(unsigned long)ref_tisp_lce_hist_adjust;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f104;
L_4f104:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    v0 = 4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    s3 = v1 + s3;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    branch = (v1 == v0); a2 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_4f140;
    goto L_4f120;
L_4f120:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = hi_4f128;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s4;
    v0 = v0 - hi_4f128 + (u32)(unsigned long)ref_tisp_lce_16bit_data_converge;
    callee = v0; a3 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f13c;
L_4f13c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
L_4f140:
    v0 = hi_4f140;
    a2 = 20;
    a1 = s4;
    v0 = v0 - hi_4f140 + ((u32)(unsigned long)ref_memcpy + (0));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f15c;
L_4f15c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    s2 = s2 + 1;
L_4f164:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (268));
    s3 = s7 + s2;
    v0 = (s32)s2 < (s32)(v0);
    branch = (v0 != 0); s3 = s3 & 0xffff;
    if (branch) goto L_4efe8;
    goto L_4f178;
L_4f178:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (36)); goto L_4f278;
L_4f180:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    t1 = v0 + s4;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a0 = t1;
    t2 = v0 + s4;
    v0 = hi_4f194;
    v0 = v0 - hi_4f194 + (u32)(unsigned long)ref_get_distance_1dim;
    callee = v0; a1 = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f1a4;
L_4f1a4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (340));
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    v0 = (u32)v1 < (u32)(v0);
    if (v0 == 0) { s2 = s2 + 1; goto L_4f164; }
    goto L_4f1b8;
L_4f1b8:
    a2 = 64;
    a1 = t2;
    a0 = t1; goto L_4f00c;
L_4f1c8:
    v1 = hi_4f1c8;
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_4f1c8 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    a2 = s8 + 24;
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a1 = s4;
    a3 = s4 + 8;
    v0 = lo;
L_4f1ec:
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    v1 = v1 * v0;
    a0 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    t1 = *(volatile u8 *)(unsigned long)(t0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a1 = a1 + 1;
    a2 = a2 + 2;
    a0 = v1 >> (a0 & 31);
    a0 = a0 & 0x1;
    v1 = v1 >> (t1 & 31);
    v1 = a0 + v1;
    branch = (a3 != a1); *(volatile u8 *)(unsigned long)(a1 + (-1)) = v1;
    if (branch) goto L_4f1ec;
    goto L_4f224;
L_4f224:
    a2 = 0;
    a3 = 12;
L_4f22c:
    v1 = a2 << (0x2 & 31);
    a0 = s8 + 24;
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (18));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t1 = s4 + a2;
    v1 = v1 * v0;
    a1 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    a0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a2 = a2 + 1;
    a0 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    a0 = v1 >> (a0 & 31);
    a0 = a1 + a0;
    branch = (a2 != a3); *(volatile u8 *)(unsigned long)(t1 + (8)) = a0;
    if (branch) goto L_4f22c;
    goto L_4f270;
L_4f270:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (376)); goto L_4f0ec;
L_4f278:
    a2 = *(volatile u32 *)(unsigned long)(s1 + (72));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (268));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (202));
    a1 = 32;
    *(volatile u16 *)(unsigned long)(s8 + (188)) = v0;
L_4f290:
    branch = (v1 == a1); a0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    if (branch) goto L_4f2c8;
    goto L_4f298;
L_4f298:
    v0 = v1 << (0x2 & 31);
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = s8 + 88;
    a3 = a0 + v1;
    v0 = a2 * v0;
    v1 = v1 + 1;
    a0 = (v0 >> 0x17) & ((1U << 0x1) - 1);
    v0 = v0 >> (0x18 & 31);
    v0 = a0 + v0;
    *(volatile u8 *)(unsigned long)(a3 + (0)) = v0; goto L_4f290;
L_4f2c8:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (188)))[i]; }
    s4 = *(volatile u32 *)(unsigned long)(s8 + (268));
    s2 = s3;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[0]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (280)))[i] = vx[1].b[i]; }
L_4f2dc:
    v0 = (s32)s4 < (s32)(17);
    if (v0 != 0) { s7 = hi_4f2e4; goto L_4f314; }
    goto L_4f2e8;
L_4f2e8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (628));
    s5 = hi_4f2ec;
    s6 = hi_4f2f0;
    s3 = s3 + v0;
    v0 = s5 - hi_4f2ec + (u32)(unsigned long)ref_t32_data_e1892;
    s3 = s3 & 0xffff;
    s4 = *(volatile u32 *)(unsigned long)(s8 + (328));
    *(volatile u32 *)(unsigned long)(s8 + (280)) = v0;
    s7 = hi_4f308;
    s6 = s6 - hi_4f2f0 + (u32)(unsigned long)ref_t32_data_bf994; goto L_5053c;
L_4f314:
    s6 = s2 << (0x6 & 31);
    v1 = 0;
    s7 = s7 - hi_4f2e4 + (u32)(unsigned long)ref_memcpy_simd;
    a3 = 1024;
    v0 = s8 + 552;
L_4f328:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a0 = s6 + v1;
    a2 = 64;
    a1 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    *(volatile u32 *)(unsigned long)(s8 + (568)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (312)) = v1;
    callee = s7; a0 = v0 + a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f350;
L_4f350:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (312));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (568));
    v0 = s8 + 552;
    v1 = v1 + 64;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (v1 != a3); s5 = s7;
    if (branch) goto L_4f328;
    goto L_4f36c;
L_4f36c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a1 = hi_4f370;
    a3 = s8 + 120;
    s6 = v0 + s6;
    v0 = s8 + 136;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_4f384;
    a0 = s6;
    a1 = a1 - hi_4f370 + (u32)(unsigned long)ref_t32_data_e1892;
    v0 = v0 - hi_4f384 + (u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a2 = s8 + 152;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_4f3a0;
L_4f3a0:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    a1 = hi_4f3a4;
    v1 = a0;
    a3 = s6;
    a0 = 0;
    a1 = a1 - hi_4f3a4 + (u32)(unsigned long)ref_t32_data_e1e48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    t4 = 32;
L_4f3c4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v1 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v1 + (32)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v1 + (48)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    t5 = a1 + a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[12].h[i] > vx[1].h[i] ? vx[12].h[i] - vx[1].h[i] : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[11].h[i] > vx[1].h[i] ? vx[11].h[i] - vx[1].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[10].h[i] > vx[1].h[i] ? vx[10].h[i] - vx[1].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[9].h[i] > vx[1].h[i] ? vx[9].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[12].h[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[11].h[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[10].h[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[9].h[i]) ? ~0U : 0; vx[4] = tmp; }
    a0 = a0 + 2;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[3].w[i] & vx[7].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[8].w[i] & vx[5].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[4].w[i]) | (vx[1].w[i] & vx[4].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[7].w[i]) | (vx[13].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[3].h[i] + vx[2].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[3].h[i] + vx[2].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[6].w[i]) | (vx[13].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[2].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[2].h[i] + vx[1].h[i]); vx[1] = tmp; }
    a2 = (s16)vx[1].h[1];
    v0 = (s16)vx[1].h[0];
    t0 = (s16)vx[1].h[5];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[5].w[i]) | (vx[13].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[4].w[i]) | (vx[13].w[i] & vx[4].w[i]); vx[4] = tmp; }
    v0 = v0 + a2;
    a2 = (s16)vx[1].h[2];
    v1 = v1 + 64;
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[3];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[4];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[6];
    v0 = t0 + v0;
    a2 = a2 + v0;
    v0 = (s16)vx[1].h[7];
    v0 = v0 + a2;
    *(volatile u16 *)(unsigned long)(t5 + (0)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-64)))[i] = vx[7].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-48)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-32)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-16)))[i] = vx[4].b[i]; }
    branch = (a0 != t4); s6 = a1;
    if (branch) goto L_4f3c4;
    goto L_4f48c;
L_4f48c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(s8 + (120)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(s8 + (152)))[i]; }
    v0 = hi_4f494;
    v0 = v0 - hi_4f494 + (u32)(unsigned long)ref_t32_data_e1e58;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4f4a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) < (-128LL) ? (-128LL) : (((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) > 127LL ? 127LL : ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i])); vx[9] = tmp; }
    v0 = v0 - hi_4f4a0 + (u32)(unsigned long)ref_t32_data_ce1b0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4f4b4;
    v0 = v0 - hi_4f4b4 + (u32)(unsigned long)ref_t32_data_ce1c0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4f4c0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[1].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[1] = tmp; }
    v0 = v0 - hi_4f4c0 + (u32)(unsigned long)ref_t32_data_e1e68;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(s8 + (136)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[5].h[i] == 0) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[13].h[i] == 0) ? ~0U : 0; vx[3] = tmp; }
    t0 = a1;
    a1 = 20;
    a1 = s2 * a1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[1].w[i]) | (vx[5].w[i] & vx[1].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[3].w[i]) | (vx[13].w[i] & vx[3].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = vx[10].b[i] > vx[11].b[i] ? vx[10].b[i] - vx[11].b[i] : 0; vx[9] = tmp; }
    t1 = hi_4f50c;
    t1 = t1 - hi_4f50c + (u32)(unsigned long)ref_t32_data_ce1d0;
    s7 = s6;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[14].w[i]) | (vx[0].w[i] & vx[14].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[1] = tmp; }
    t3 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_4f528;
    v0 = v0 - hi_4f528 + (u32)(unsigned long)ref_t32_data_e1e78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 1; vx[1] = tmp; }
    v0 = hi_4f538;
    v0 = v0 - hi_4f538 + (u32)(unsigned long)ref_t32_data_e1e88;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[1].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[2].h[i] >> (1 & 15); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] >> (1 & 15); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[1].h[i]); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[13].h[i] >> (2 & 15); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[14].w[i]) | (vx[0].w[i] & vx[14].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[17].h[i] >> (2 & 15); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[2].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[14].w[i]) | (vx[13].w[i] & vx[14].w[i]); vx[20] = tmp; }
    v0 = hi_4f580;
    v0 = v0 - hi_4f580 + (u32)(unsigned long)ref_t32_data_e1e98;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[17].w[i] & vx[5].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    v0 = hi_4f594;
    v0 = v0 - hi_4f594 + (u32)(unsigned long)ref_t32_data_e1ea8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[20].b[i]; }
    v0 = hi_4f5a0;
    v0 = v0 - hi_4f5a0 + (u32)(unsigned long)ref_t32_data_e1eb8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    v0 = hi_4f5b4;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[16].h[i] == 0) ? ~0U : 0; vx[2] = tmp; }
    v0 = v0 - hi_4f5b4 + (u32)(unsigned long)ref_t32_data_e1ec8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[20].b[i]; }
    v0 = hi_4f5c8;
    v0 = v0 - hi_4f5c8 + (u32)(unsigned long)ref_t32_data_e1ed8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[15].h[i] == 0) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[2].w[i]) | (vx[16].w[i] & vx[2].w[i]); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    v0 = hi_4f5e0;
    v0 = v0 - hi_4f5e0 + (u32)(unsigned long)ref_t32_data_e1ee8;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[6].w[i]) | (vx[15].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[1].h[i] ? vx[7].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[19].h[i] ? vx[7].h[i] - vx[19].h[i] : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[9].w[i]) | (vx[0].w[i] & vx[9].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[6].w[i]) | (vx[0].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[9].w[i]) | (vx[13].w[i] & vx[9].w[i]); vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    v0 = hi_4f604;
    v0 = v0 - hi_4f604 + (u32)(unsigned long)ref_t32_data_e1ef8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[3].h[i] ? vx[8].h[i] - vx[3].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[20].h[i] ? vx[8].h[i] - vx[20].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[19].h[i] ? vx[7].h[i] - vx[19].h[i] : 0; vx[7] = tmp; }
    v0 = hi_4f61c;
    v0 = v0 - hi_4f61c + (u32)(unsigned long)ref_t32_data_e1f08;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[17].w[i] & vx[6].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[20].h[i] ? vx[8].h[i] - vx[20].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[7].w[i] & vx[5].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[6].w[i]) | (vx[0].w[i] & vx[6].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[14].w[i]) | (vx[8].w[i] & vx[14].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[13].h[i] ? vx[8].h[i] - vx[13].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[9].w[i]) | (vx[0].w[i] & vx[9].w[i]); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    v0 = hi_4f644;
    v0 = v0 - hi_4f644 + (u32)(unsigned long)ref_t32_data_e1f18;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    v0 = hi_4f650;
    v0 = v0 - hi_4f650 + (u32)(unsigned long)ref_t32_data_e1f28;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[13].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[15] = tmp; }
    v0 = hi_4f660;
    v0 = v0 - hi_4f660 + (u32)(unsigned long)ref_t32_data_e1f38;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[2].h[i] > vx[13].h[i] ? vx[2].h[i] - vx[13].h[i] : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[i] > vx[15].h[i] ? vx[1].h[i] - vx[15].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[15].h[i] ? vx[7].h[i] - vx[15].h[i] : 0; vx[1] = tmp; }
    v0 = hi_4f678;
    v0 = v0 - hi_4f678 + (u32)(unsigned long)ref_t32_data_e1f48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[14].w[i]) | (vx[8].w[i] & vx[14].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[5].w[i]) | (vx[1].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[9].w[i]) | (vx[3].w[i] & vx[9].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[1].w[i] & vx[6].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_4f694;
    v0 = v0 - hi_4f694 + (u32)(unsigned long)ref_t32_data_e1f58;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = (vx[10].b[i] == vx[0].b[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 1; vx[2] = tmp; }
    v0 = hi_4f6a8;
    v0 = v0 - hi_4f6a8 + (u32)(unsigned long)ref_t32_data_e1f68;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[12].b[i]; }
    v0 = hi_4f6c4;
    v0 = v0 - hi_4f6c4 + (u32)(unsigned long)ref_t32_data_e1f78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[11].b[i]; }
    v0 = hi_4f6d0;
    v0 = v0 - hi_4f6d0 + (u32)(unsigned long)ref_t32_data_e1f88;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[10].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (300));
    t2 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (296));
    a1 = v0 + a1;
    v0 = s8 + 848;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4f6f4;
    v0 = v0 - hi_4f6f4 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4f700;
    v0 = v0 - hi_4f700 + (u32)(unsigned long)ref_t32_data_ce1f0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4f718;
    v0 = v0 - hi_4f718 + (u32)(unsigned long)ref_t32_data_ce1a0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 864;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (548));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4f73c;
    v0 = v0 - hi_4f73c + (u32)(unsigned long)ref_t32_data_ce180;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_4f750;
    v0 = v0 - hi_4f750 + (u32)(unsigned long)ref_t32_data_ce190;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 752;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
L_4f764:
    a2 = *(volatile u16 *)(unsigned long)(t0 + (32));
    v0 = hi_4f768;
    a0 = 1;
    branch = (a2 != a0); v1 = v0 - hi_4f768 + (u32)(unsigned long)ref_t32_data_bf9ec;
    if (branch) goto L_4f874;
    goto L_4f778;
L_4f778:
    v0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (64));
    a2 = hi_4f780;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t4 = 0;
    a2 = a2 - hi_4f780 + (u32)(unsigned long)ref_t32_data_d6be4;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_4f7b0:
    v0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a0);
    branch = (v0 != 0); v0 = t4 + 336;
    if (branch) goto L_4f7e0;
    goto L_4f7c4;
L_4f7c4:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (t4)))[i]; }
    v0 = t4 + 464;
    a0 = a0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v0)))[i] = vx[2].b[i]; }
    t4 = t4 + 16; goto L_4f7b0;
L_4f7e0:
    t5 = *(volatile u32 *)(unsigned long)(s8 + (24));
    a2 = a0 << (0x2 & 31);
    t4 = hi_4f7e8;
    a2 = s6 + a2;
    t4 = t4 - hi_4f7e8 + (u32)(unsigned long)ref_t32_data_d6be4;
L_4f7f4:
    v0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    v0 = (s32)a0 < (s32)(v0);
    branch = (v0 == 0); a2 = a2 + 4;
    if (branch) goto L_4f820;
    goto L_4f804;
L_4f804:
    v0 = a0 << (0x2 & 31);
    v0 = t4 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(a2 + (332)) = t5;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(a2 + (460)) = v0; goto L_4f7f4;
L_4f820:
    a0 = *(volatile u16 *)(unsigned long)(t0 + (160));
    v0 = 1;
    branch = (a0 != v0); v0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    if (branch) goto L_4fb9c;
    goto L_4f830;
L_4f830:
    a0 = 31;
    t4 = 0;
    a0 = a0 - v0;
    a0 = a0 << (0x1 & 31);
    v1 = v1 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (192));
    t5 = v0 << (0x2 & 31);
    t6 = t5 + 336;
    v1 = v1 * a0;
    t7 = t5 + 464;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v1 = hi_4f864;
    a2 = v1 - hi_4f864 + (u32)(unsigned long)ref_t32_data_d6b64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; } goto L_4f9f4;
L_4f874:
    a2 = *(volatile u8 *)(unsigned long)(s7 + (288));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (96));
    t5 = hi_4f87c;
    v0 = a2 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    t4 = 0;
    t5 = t5 - hi_4f87c + (u32)(unsigned long)ref_t32_data_d6b64;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = 32;
    a2 = v0 - a2;
    a2 = a2 & 0xff;
    a2 = a2 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_4f8bc:
    v0 = *(volatile u8 *)(unsigned long)(s7 + (288));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a0);
    branch = (v0 != 0); t6 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_4f8f4;
    goto L_4f8d0;
L_4f8d0:
    v0 = t4 + 336;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v0)))[i] = vx[1].b[i]; }
    v0 = t4 + a2;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t5 + (v0)))[i]; }
    v0 = t4 + 464;
    a0 = a0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v0)))[i] = vx[2].b[i]; }
    t4 = t4 + 16; goto L_4f8bc;
L_4f8f4:
    v0 = a0 << (0x2 & 31);
    t5 = hi_4f8f8;
    v0 = s6 + v0;
    t5 = t5 - hi_4f8f8 + (u32)(unsigned long)ref_t32_data_d6b64;
L_4f904:
    t4 = *(volatile u8 *)(unsigned long)(s7 + (288));
    t7 = (s32)a0 < (s32)(t4);
    branch = (t7 == 0); v0 = v0 + 4;
    if (branch) goto L_4f934;
    goto L_4f914;
L_4f914:
    t4 = a0 << (0x2 & 31);
    t4 = t4 + a2;
    t4 = t5 + t4;
    t4 = *(volatile u32 *)(unsigned long)(t4 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (332)) = t6;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (460)) = t4; goto L_4f904;
L_4f934:
    v0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (128));
    a2 = t4 + 84;
    v0 = v0 - t4;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = a2 << (0x2 & 31);
    a2 = s6 + a2;
    v0 = v0 * a0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = t4;
    t4 = hi_4f96c;
    t4 = t4 - hi_4f96c + (u32)(unsigned long)ref_t32_data_d6be4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[0]; vx[2] = tmp; }
L_4f978:
    a0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    a0 = a0 + -4;
    a0 = (s32)a0 < (s32)(v0);
    branch = (a0 != 0); t5 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_4f9b0;
    goto L_4f98c;
L_4f98c:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(s7 + (288));
    a2 = a2 + 16;
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t4 + (a0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (112)))[i] = vx[1].b[i]; }
    v0 = v0 + 4; goto L_4f978;
L_4f9b0:
    a2 = v0 << (0x2 & 31);
    t4 = hi_4f9b4;
    a2 = s6 + a2;
    t4 = t4 - hi_4f9b4 + (u32)(unsigned long)ref_t32_data_d6be4;
L_4f9c0:
    a0 = *(volatile u8 *)(unsigned long)(s7 + (304));
    a0 = (s32)v0 < (s32)(a0);
    branch = (a0 == 0); a2 = a2 + 4;
    if (branch) goto L_4f820;
    goto L_4f9d0;
L_4f9d0:
    *(volatile u32 *)(unsigned long)(a2 + (332)) = t5;
    a0 = *(volatile u8 *)(unsigned long)(s7 + (288));
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + t4;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a2 + (460)) = a0; goto L_4f9c0;
L_4f9f4:
    v1 = (s32)v0 < (s32)(29);
    branch = (v1 == 0); v1 = t6 + t4;
    if (branch) goto L_4fa20;
    goto L_4fa00;
L_4fa00:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v1)))[i] = vx[1].b[i]; }
    a0 = t4 + t5;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (a0)))[i]; }
    v1 = t7 + t4;
    v0 = v0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v1)))[i] = vx[2].b[i]; }
    t4 = t4 + 16; goto L_4f9f4;
L_4fa20:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (24));
    v1 = v0 << (0x2 & 31);
    a0 = s6 + v1;
    v1 = a2 + v1;
L_4fa30:
    a2 = (s32)v0 < (s32)(32);
    branch = (a2 == 0); a0 = a0 + 4;
    if (branch) goto L_4fa54;
    goto L_4fa3c;
L_4fa3c:
    a2 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (332)) = t4;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (460)) = a2;
    v1 = v1 + 4; goto L_4fa30;
L_4fa54:
    v0 = hi_4fa54;
    v0 = v0 - hi_4fa54 + (u32)(unsigned long)ref_t32_data_e1f98;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fa60;
    v0 = v0 - hi_4fa60 + (u32)(unsigned long)ref_t32_data_e1fa8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fa6c;
    v0 = v0 - hi_4fa6c + (u32)(unsigned long)ref_t32_data_e1fb8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[16].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fa78;
    v0 = v0 - hi_4fa78 + (u32)(unsigned long)ref_t32_data_e1fc8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fa84;
    v0 = v0 - hi_4fa84 + (u32)(unsigned long)ref_t32_data_e1fd8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fa90;
    v0 = v0 - hi_4fa90 + (u32)(unsigned long)ref_t32_data_e1fe8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fa9c;
    v0 = v0 - hi_4fa9c + (u32)(unsigned long)ref_t32_data_e1ff8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4faa8;
    v0 = v0 - hi_4faa8 + (u32)(unsigned long)ref_t32_data_e2008;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fab4;
    v0 = v0 - hi_4fab4 + (u32)(unsigned long)ref_t32_data_e2018;
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fac0;
    v0 = v0 - hi_4fac0 + (u32)(unsigned long)ref_t32_data_e2028;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4facc;
    v0 = v0 - hi_4facc + (u32)(unsigned long)ref_t32_data_e2038;
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fad8;
    v0 = v0 - hi_4fad8 + (u32)(unsigned long)ref_t32_data_e2048;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4fae4;
    v0 = v0 - hi_4fae4 + (u32)(unsigned long)ref_t32_data_e2058;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_4faf0;
    v0 = v0 - hi_4faf0 + (u32)(unsigned long)ref_t32_data_e2068;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[4].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[5].w[i]; vx[5] = tmp; }
    v0 = hi_4fb04;
    v0 = v0 - hi_4fb04 + (u32)(unsigned long)ref_t32_data_e2078;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    v0 = hi_4fb14;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 15; vx[1] = tmp; }
    v0 = v0 - hi_4fb14 + (u32)(unsigned long)ref_t32_data_e2088;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 848;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[2].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[12].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[5].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[13].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[15].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[14].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[16].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    t4 = a3 + 16;
    a2 = a3 + 32;
    a0 = a3 + 48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[4].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[8].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[10].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[9].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[11].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[3].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[6].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t4 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    t5 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    v0 = 0;
    t7 = s0 + 48;
    t6 = 16; goto L_4fc78;
L_4fb9c:
    t4 = *(volatile u8 *)(unsigned long)(s7 + (320));
    t7 = hi_4fba0;
    t5 = v0 << (0x2 & 31);
    a0 = t4 - v0;
    a0 = a0 + -1;
    a0 = a0 << (0x1 & 31);
    a0 = v1 + a0;
    a2 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (224));
    t6 = 0;
    t7 = t7 - hi_4fba0 + (u32)(unsigned long)ref_t32_data_d6b64;
    a2 = a2 * a0;
    a0 = v0;
    v0 = 32;
    v0 = v0 - t4;
    v0 = v0 & 0xff;
    v0 = v0 + a0;
    v0 = v0 << (0x2 & 31);
L_4fbe4:
    t4 = *(volatile u8 *)(unsigned long)(s7 + (320));
    t8 = (s32)a0 < (s32)(t4);
    branch = (t8 == 0); t8 = t6 + v0;
    if (branch) goto L_4fc18;
    goto L_4fbf4;
L_4fbf4:
    t8 = t7 + t8;
    t8 = *(volatile u32 *)(unsigned long)(t8 + (0));
    t4 = t6 + t5;
    t4 = s6 + t4;
    *(volatile u32 *)(unsigned long)(t4 + (336)) = a2;
    *(volatile u32 *)(unsigned long)(t4 + (464)) = t8;
    a0 = a0 + 1;
    t6 = t6 + 4; goto L_4fbe4;
L_4fc18:
    v0 = 31;
    v0 = v0 - t4;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(t0 + (256));
    v1 = t4 << (0x2 & 31);
    a2 = hi_4fc34;
    a0 = a0 * v0;
    v1 = s6 + v1;
    a2 = a2 - hi_4fc34 + (u32)(unsigned long)ref_t32_data_d6be4;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = a0;
L_4fc48:
    v0 = (s32)t4 < (s32)(32);
    branch = (v0 == 0); v1 = v1 + 4;
    if (branch) goto L_4fa54;
    goto L_4fc54;
L_4fc54:
    *(volatile u32 *)(unsigned long)(v1 + (332)) = a0;
    v0 = *(volatile u8 *)(unsigned long)(s7 + (320));
    v0 = t4 - v0;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + a2;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    t4 = t4 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (460)) = v0; goto L_4fc48;
L_4fc78:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (592)) = v0;
    v1 = t7 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_4fc78;
    goto L_4fc98;
L_4fc98:
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    t5 = 0;
    t7 = s0 + 32;
    t6 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[1].h[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (32)))[i] = vx[5].b[i]; }
L_4fcb4:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (608)) = v0;
    v1 = t7 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_4fcb4;
    goto L_4fcd4;
L_4fcd4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    t5 = 0;
    t7 = s0 + 16;
    t6 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[13].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
L_4fcf0:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (624)) = v0;
    v1 = t7 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_4fcf0;
    goto L_4fd10;
L_4fd10:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    t5 = 0;
    t6 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[9].h[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (0)))[i] = vx[2].b[i]; }
L_4fd28:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (640)) = v0;
    v1 = s0 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_4fd28;
    goto L_4fd48;
L_4fd48:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[4].b[i]; }
    v1 = hi_4fd4c;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t4 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_4fd4c + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[4].h[i] + (u16)vx[5].h[i]; vx[4] = tmp; }
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[2].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    t4 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(t4 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    a2 = hi_4fd88;
    a2 = a2 - hi_4fd88 + (u32)(unsigned long)ref_t32_data_e20a8;
    a0 = hi_4fd90;
    a0 = a0 - hi_4fd90 + (u32)(unsigned long)ref_t32_data_e20b8;
    v1 = hi_4fd98;
    v1 = v1 - hi_4fd98 + (u32)(unsigned long)ref_t32_data_e20c8;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (176)) = v0;
    v0 = hi_4fda8;
    v0 = v0 - hi_4fda8 + (u32)(unsigned long)ref_t32_data_e2098;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (176)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(t4 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[1].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t4 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t4 + (0)))[i]; }
    t4 = s8 + 864;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[7].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[3].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[6].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[10].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[5].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[9].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[4].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] >> (vx[4].w[i] & 31)) + ((vx[4].w[i] & 31) ? ((vx[1].w[i] >> (((vx[4].w[i] & 31) - 1) & 31)) & 1) : 0); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t4 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[5].b[i]; }
    a2 = 12;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (0)))[i] = vx[3].b[i]; }
    v1 = 0;
L_4fe84:
    a0 = v1 << (0x2 & 31);
    a0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (18));
    t4 = a1 + v1;
    v1 = v1 + 1;
    branch = (v1 != a2); *(volatile u8 *)(unsigned long)(t4 + (8)) = a0;
    if (branch) goto L_4fe84;
    goto L_4fea0;
L_4fea0:
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (616));
    a2 = a1 + 16;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (620));
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (448)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (624));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[19] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 648;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i])); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 664;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i])); vx[19] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 512;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i])); vx[16] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (344)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i])); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[17] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (360)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (416)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (464)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] * (u32)vx[2].w[i]; vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (432)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] << (8 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[3].w[i]; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[1].w[i]; vx[21] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (480)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] * (u32)vx[1].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (496)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] * (u32)vx[1].w[i]; vx[14] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 528;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[16].w[i] < 0) ? ~0U : 0; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i] < 0) ? ~0U : 0; vx[12] = tmp; }
    v0 = s8 + 768;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[16].w[i]) | (vx[4].w[i] & vx[16].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (384)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i] < 0) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[12].w[i]) | (vx[2].w[i] & vx[12].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[17].w[i] << (8 & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (400)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[15].w[i] < 0) ? ~0U : 0; vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[11].w[i]) | (vx[20].w[i] & vx[11].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 784;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[15].w[i]) | (vx[9].w[i] & vx[15].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[19].w[i] < 0) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i])); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 800;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[19].w[i]) | (vx[1].w[i] & vx[19].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i])); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[1] = tmp; }
    v0 = s8 + 584;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] >> (8 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] >> (8 & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] >> (8 & 31); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] >> (8 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (8 & 31); vx[2] = tmp; }
    v0 = s8 + 752;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = (s32)vx[4].w[0];
    *(volatile u8 *)(unsigned long)(a1 + (16)) = v0;
    v0 = (s32)vx[4].w[1];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    *(volatile u8 *)(unsigned long)(a1 + (17)) = v0;
    v0 = (s32)vx[4].w[2];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[3].b[i]; }
    *(volatile u8 *)(unsigned long)(a1 + (18)) = v0;
    v0 = (s32)vx[4].w[3];
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    *(volatile u8 *)(unsigned long)(a1 + (19)) = v0;
    v0 = 4;
    branch = (v1 != v0); t4 = a1 + 20;
    if (branch) goto L_500d0;
    goto L_50054;
L_50054:
    v0 = s8 + 880;
L_50058:
    a0 = t2;
    a2 = 20;
    *(volatile u32 *)(unsigned long)(s8 + (908)) = t1;
    *(volatile u32 *)(unsigned long)(s8 + (904)) = t4;
    *(volatile u32 *)(unsigned long)(s8 + (900)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (896)) = t3;
    *(volatile u32 *)(unsigned long)(s8 + (748)) = t0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    callee = s5; *(volatile u32 *)(unsigned long)(s8 + (832)) = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50080;
L_50080:
    t3 = *(volatile u32 *)(unsigned long)(s8 + (896));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (748));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (832));
    t4 = *(volatile u32 *)(unsigned long)(s8 + (904));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (900));
    v1 = s8 + 880;
    t3 = t3 + 1;
    v0 = 16;
    t0 = t0 + 2;
    t2 = t2 + 20;
    a1 = t4;
    a3 = a3 + 64;
    s7 = s7 + 1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    branch = (t3 != v0); t1 = *(volatile u32 *)(unsigned long)(s8 + (908));
    if (branch) goto L_4f764;
    goto L_500c0;
L_500c0:
    s2 = s2 + 16;
    s2 = s2 & 0xffff;
    s4 = s4 + 16; goto L_4f2dc;
L_500d0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[9] = tmp; }
    v0 = 64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[14] = tmp; }
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[22].w[i] | vx[22].w[i]; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] | vx[2].w[i]; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[23].w[i] | vx[23].w[i]; vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[13].w[i] | vx[13].w[i]; vx[25] = tmp; }
    v0 = s8 + 832;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[23].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[23].w[i] + vx[7].w[i]); vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[22].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[22].w[i] + vx[7].w[i]); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[13].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[13].w[i] + vx[7].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[2].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[2].w[i] + vx[7].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[17].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[17].w[i] + vx[7].w[i]); vx[30] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[8].w[i] + vx[7].w[i]); vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[18].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[18].w[i] + vx[7].w[i]); vx[28] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[1].w[i] + vx[7].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[7].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i])); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i])); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i])); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[2].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[15].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[15].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[15].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[15].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[23].w[i]  < (s32)vx[17].w[i]) ? ~0U : 0; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[7].w[i] + vx[14].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[7].w[i] >> (7 & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[12].w[i] + vx[14].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[11].w[i] + vx[14].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[10].w[i] + vx[14].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (7 & 31); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[7].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[11].w[i] >> (7 & 31); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[10].w[i] >> (7 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] | vx[15].w[i]; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[31].w[i]) | (vx[15].w[i] & vx[31].w[i]); vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[7].w[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[10].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[21].w[i]) | (vx[15].w[i] & vx[21].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[12].w[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[31].w[i] & ~vx[7].w[i]) | (vx[9].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[20].w[i]) | (vx[15].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[19].w[i]) | (vx[15].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[11].w[i]) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] + (u32)vx[7].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[10].w[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[12].w[i]) | (vx[9].w[i] & vx[12].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[22].w[i]  < (s32)vx[8].w[i]) ? ~0U : 0; vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[2].w[i]) | (vx[7].w[i] & vx[2].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[11].w[i]) | (vx[9].w[i] & vx[11].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[10].w[i]) | (vx[9].w[i] & vx[10].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[18].w[i]) ? ~0U : 0; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[27].w[i] + (u32)vx[12].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[26].w[i] + (u32)vx[11].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[10].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[17].w[i] & ~vx[23].w[i]) | (vx[12].w[i] & vx[23].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[8].w[i] & ~vx[22].w[i]) | (vx[11].w[i] & vx[22].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[6].w[i] + vx[14].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[5].w[i] + vx[14].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[4].w[i] + vx[14].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[3].w[i] + vx[14].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (7 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (7 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (7 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[14].w[i] >> (7 & 31); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[18].w[i] & ~vx[13].w[i]) | (vx[10].w[i] & vx[13].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[6].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[5].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[4].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[14].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[21].w[i]) | (vx[16].w[i] & vx[21].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[20].w[i]) | (vx[16].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[19].w[i]) | (vx[16].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[2].w[i]) | (vx[16].w[i] & vx[2].w[i]); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[5].w[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[4].w[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[14].w[i]) ? ~0U : 0; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[6].w[i]) | (vx[9].w[i] & vx[6].w[i]); vx[6] = tmp; }
    v0 = s8 + 584;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[5].w[i]) | (vx[9].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[4].w[i]) | (vx[9].w[i] & vx[4].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[16].w[i] & ~vx[14].w[i]) | (vx[9].w[i] & vx[14].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i])); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[30].w[i]  < (s32)vx[27].w[i]) ? ~0U : 0; vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[24].w[i]) ? ~0U : 0; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[29].w[i]  < (s32)vx[26].w[i]) ? ~0U : 0; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[28].w[i]  < (s32)vx[25].w[i]) ? ~0U : 0; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[27].w[i]) | (vx[6].w[i] & vx[27].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[24].w[i]) | (vx[15].w[i] & vx[24].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[26].w[i]) | (vx[5].w[i] & vx[26].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[25].w[i]) | (vx[4].w[i] & vx[25].w[i]); vx[10] = tmp; }
    v0 = s8 + 752;
    t5 = t2 + 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[11].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[10].b[i]; }
L_502e8:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u8 *)(unsigned long)(t5 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    t6 = v1 + a0;
    v1 = (s32)t6 < (s32)(v0);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    if (branch) goto L_50350;
    goto L_50304;
L_50304:
    v1 = v0 - a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v1 = v1 + 64;
    v1 = (s32)v1 >> (0x7 & 31);
    v0 = (s32)v1 < (s32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_50330;
    goto L_50328;
L_50328:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = t6; goto L_503ac;
L_50330:
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); v1 = a0 + v1;
    if (branch) goto L_50348;
    goto L_5033c;
L_5033c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    a0 = v0 + a0; goto L_5038c;
L_50348:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = v1; goto L_503ac;
L_50350:
    v1 = v1 + v0;
    v1 = (s32)v1 < (s32)(a0);
    if (v1 == 0) { a2 = a2 + 1; goto L_503b0; }
    goto L_50360;
L_50360:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = a0 - v0;
    v0 = v0 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v1 = (s32)v0 < (s32)(v1);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_50394;
    goto L_50384;
L_50384:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
L_50388:
    a0 = a0 - v0;
L_5038c:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = a0; goto L_503ac;
L_50394:
    v1 = (s32)v1 < (s32)(v0);
    if (v1 == 0) { v0 = a0 - v0; goto L_503a8; }
    goto L_503a0;
L_503a0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228)); goto L_50388;
L_503a8:
    *(volatile u8 *)(unsigned long)(a2 + (0)) = v0;
L_503ac:
    a2 = a2 + 1;
L_503b0:
    branch = (a2 != t4); t5 = t5 + 1;
    if (branch) goto L_502e8;
    goto L_503b8;
L_503b8:
    v0 = s8 + 880; goto L_50058;
L_503c0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (336));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    branch = (v0 == 0); s5 = s2 << (0x6 & 31);
    if (branch) goto L_5055c;
    goto L_503d0;
L_503d0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a2 = 64;
    a1 = v0 + s5;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    a0 = v0 + s5;
L_503e4:
    v0 = hi_503e4;
    v0 = v0 - hi_503e4 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_503f4;
L_503f4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (280));
    a2 = s8 + 184;
    s5 = v0 + s5;
    v0 = s7 - hi_4f308 + (u32)(unsigned long)ref_tisp_lce_thres_search;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50418;
L_50418:
    v0 = s8 + s4;
    a3 = *(volatile u8 *)(unsigned long)(v0 + (88));
    v0 = *(volatile u16 *)(unsigned long)(s8 + (180));
    a2 = s8 + 184;
    a1 = s8 + 188;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_50430;
    v0 = v0 - hi_50430 + (u32)(unsigned long)ref_tisp_lce_hist_method;
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50440;
L_50440:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (544));
    a0 = s8 + 24;
    a2 = 64;
    callee = v0; a1 = 0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50454;
L_50454:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    v1 = 0;
    v0 = 0;
    a0 = 64;
L_50464:
    a1 = s8 + 24;
    a1 = a1 + v1;
    *(volatile u16 *)(unsigned long)(a1 + (0)) = v0;
    a1 = s5 + v1;
    a1 = *(volatile u16 *)(unsigned long)(a1 + (0));
    v1 = v1 + 2;
    v0 = v0 + a1;
    branch = (v1 != a0); v0 = v0 & 0xffff;
    if (branch) goto L_50464;
    goto L_50488;
L_50488:
    v1 = 20;
    s2 = s2 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (296));
    branch = (v0 != 0); s5 = v1 + s2;
    if (branch) goto L_505a4;
    goto L_5049c;
L_5049c:
    a0 = hi_5049c;
    v0 = hi_504a0;
    a2 = 1065;
    a1 = s6;
    v0 = v0 - hi_504a0 + ((u32)(unsigned long)ref_printk + (0));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = a0 - hi_5049c + (u32)(unsigned long)ref_t32_data_c9660;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_504bc;
L_504bc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    a2 = *(volatile u32 *)(unsigned long)(s8 + (376));
L_504c4:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (380));
    v0 = hi_504c8;
    v0 = v0 - hi_504c8 + (u32)(unsigned long)ref_tisp_lce_hist_adjust;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_504dc;
L_504dc:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    v0 = 4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    s2 = v1 + s2;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    branch = (v1 == v0); a2 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_50518;
    goto L_504f8;
L_504f8:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = hi_50500;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s5;
    v0 = v0 - hi_50500 + (u32)(unsigned long)ref_tisp_lce_16bit_data_converge;
    callee = v0; a3 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50514;
L_50514:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
L_50518:
    v0 = hi_50518;
    a2 = 20;
    a1 = s5;
    v0 = v0 - hi_50518 + ((u32)(unsigned long)ref_memcpy + (0));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (312)))[i] = vx[0].b[i]; }
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50534;
L_50534:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    s4 = s4 + 1;
L_5053c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (328));
    s2 = s3 - v0;
    s2 = s2 + s4;
    v0 = 32;
    branch = (s4 != v0); s2 = s2 & 0xffff;
    if (branch) goto L_503c0;
    goto L_50554;
L_50554:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (744)); goto L_50654;
L_5055c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    t1 = v0 + s5;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a0 = t1;
    t2 = v0 + s5;
    v0 = hi_50570;
    v0 = v0 - hi_50570 + (u32)(unsigned long)ref_get_distance_1dim;
    callee = v0; a1 = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50580;
L_50580:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (340));
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (312)))[i]; }
    v0 = (u32)v1 < (u32)(v0);
    if (v0 == 0) { s4 = s4 + 1; goto L_5053c; }
    goto L_50594;
L_50594:
    a2 = 64;
    a1 = t2;
    a0 = t1; goto L_503e4;
L_505a4:
    v1 = hi_505a4;
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_505a4 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    a2 = s8 + 24;
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a1 = s5;
    a3 = s5 + 8;
    v0 = lo;
L_505c8:
    v1 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    v1 = v1 * v0;
    a0 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    t1 = *(volatile u8 *)(unsigned long)(t0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a1 = a1 + 1;
    a2 = a2 + 2;
    a0 = v1 >> (a0 & 31);
    a0 = a0 & 0x1;
    v1 = v1 >> (t1 & 31);
    v1 = a0 + v1;
    branch = (a3 != a1); *(volatile u8 *)(unsigned long)(a1 + (-1)) = v1;
    if (branch) goto L_505c8;
    goto L_50600;
L_50600:
    a2 = 0;
    a3 = 12;
L_50608:
    v1 = a2 << (0x2 & 31);
    a0 = s8 + 24;
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (18));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t1 = s5 + a2;
    v1 = v1 * v0;
    a1 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    a0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a2 = a2 + 1;
    a0 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    a0 = v1 >> (a0 & 31);
    a0 = a1 + a0;
    branch = (a2 != a3); *(volatile u8 *)(unsigned long)(t1 + (8)) = a0;
    if (branch) goto L_50608;
    goto L_5064c;
L_5064c:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (376)); goto L_504c4;
L_50654:
    s3 = v0 + s3;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (600));
    s7 = s3 & 0xffff;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (600)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (332)) = v0; goto L_4de98;
L_50678:
    v0 = v1 << (0x7 & 31);
    v1 = *(volatile u32 *)(unsigned long)(s8 + (680));
    v0 = v1 + v0;
    *(volatile u32 *)(unsigned long)(s8 + (332)) = v0;
    v0 = s8 + 696;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 648;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 712;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 664;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 728;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 680;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 648;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 696;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] << (8 & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 664;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 712;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] << (8 & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = s8 + 680;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 728;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] << (8 & 31); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[1] = tmp; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (248)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (192)))[i] = vx[1].b[i]; }
L_5070c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (312));
    v0 = (s32)v0 < (s32)(18);
    branch = (v0 == 0); a0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    if (branch) goto L_53014;
    goto L_5071c;
L_5071c:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (40));
    a3 = *(volatile u32 *)(unsigned long)(s1 + (76));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (203));
    a2 = s8 + 88;
    v1 = a2;
    *(volatile u16 *)(unsigned long)(s8 + (188)) = v0;
L_50738:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (268));
    v0 = v1 - a2;
    v0 = (s32)v0 < (s32)(a1);
    branch = (v0 == 0); v1 = v1 + 1;
    if (branch) goto L_5076c;
    goto L_5074c;
L_5074c:
    v0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    a0 = a0 + 4;
    v0 = a3 * v0;
    a1 = (v0 >> 0x17) & ((1U << 0x1) - 1);
    v0 = v0 >> (0x18 & 31);
    v0 = a1 + v0;
    *(volatile u8 *)(unsigned long)(v1 + (-1)) = v0; goto L_50738;
L_5076c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (188)))[i]; }
    s2 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[0]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (280)))[i] = vx[1].b[i]; }
L_5077c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (268));
    s3 = s7 + s2;
    v0 = v0 + -16;
    v0 = (s32)v0 < (s32)(s2);
    branch = (v0 == 0); s3 = s3 & 0xffff;
    if (branch) goto L_507b0;
    goto L_50794;
L_50794:
    s4 = hi_50794;
    v0 = s4 - hi_50794 + (u32)(unsigned long)ref_t32_data_e1898;
    s5 = hi_5079c;
    *(volatile u32 *)(unsigned long)(s8 + (280)) = v0;
    s6 = hi_507a4;
    s5 = s5 - hi_5079c + (u32)(unsigned long)ref_t32_data_bf994; goto L_51a34;
L_507b0:
    s6 = hi_507b0;
    s5 = s3 << (0x6 & 31);
    v1 = 0;
    s6 = s6 - hi_507b0 + (u32)(unsigned long)ref_memcpy_simd;
    a3 = 1024;
    v0 = s8 + 568;
L_507c8:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a0 = s5 + v1;
    a2 = 64;
    a1 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    *(volatile u32 *)(unsigned long)(s8 + (584)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (552)) = v1;
    callee = s6; a0 = v0 + a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_507f0;
L_507f0:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (552));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (584));
    v0 = s8 + 568;
    v1 = v1 + 64;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (v1 != a3); s4 = s6;
    if (branch) goto L_507c8;
    goto L_5080c;
L_5080c:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a1 = hi_50818;
    a3 = s8 + 120;
    s5 = v0 + s5;
    v0 = s8 + 136;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_5082c;
    a0 = s5;
    a1 = a1 - hi_50818 + (u32)(unsigned long)ref_t32_data_e1898;
    v0 = v0 - hi_5082c + (u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4;
    callee = v0; a2 = s8 + 152;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_50844;
L_50844:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    v0 = s8 + 552;
    a1 = hi_5084c;
    v1 = a0;
    a3 = s5;
    a0 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    a1 = a1 - hi_5084c + (u32)(unsigned long)ref_t32_data_e1e48;
    t4 = 32;
L_5086c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v1 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v1 + (32)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v1 + (48)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    t5 = a1 + a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[12].h[i] > vx[1].h[i] ? vx[12].h[i] - vx[1].h[i] : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[11].h[i] > vx[1].h[i] ? vx[11].h[i] - vx[1].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[10].h[i] > vx[1].h[i] ? vx[10].h[i] - vx[1].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[9].h[i] > vx[1].h[i] ? vx[9].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[12].h[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[11].h[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[10].h[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[9].h[i]) ? ~0U : 0; vx[4] = tmp; }
    a0 = a0 + 2;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[3].w[i] & vx[7].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[8].w[i] & vx[5].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[4].w[i]) | (vx[1].w[i] & vx[4].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[7].w[i]) | (vx[13].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[3].h[i] + vx[2].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[3].h[i] + vx[2].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[6].w[i]) | (vx[13].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[2].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[2].h[i] + vx[1].h[i]); vx[1] = tmp; }
    a2 = (s16)vx[1].h[1];
    v0 = (s16)vx[1].h[0];
    t0 = (s16)vx[1].h[5];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[5].w[i]) | (vx[13].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[4].w[i]) | (vx[13].w[i] & vx[4].w[i]); vx[4] = tmp; }
    v0 = v0 + a2;
    a2 = (s16)vx[1].h[2];
    v1 = v1 + 64;
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[3];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[4];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[6];
    v0 = t0 + v0;
    a2 = a2 + v0;
    v0 = (s16)vx[1].h[7];
    v0 = v0 + a2;
    *(volatile u16 *)(unsigned long)(t5 + (0)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-64)))[i] = vx[7].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-48)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-32)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-16)))[i] = vx[4].b[i]; }
    branch = (a0 != t4); s5 = a1;
    if (branch) goto L_5086c;
    goto L_50934;
L_50934:
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(s8 + (120)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(s8 + (152)))[i]; }
    v0 = hi_5093c;
    v0 = v0 - hi_5093c + (u32)(unsigned long)ref_t32_data_e1e58;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50948;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) < (-128LL) ? (-128LL) : (((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) > 127LL ? 127LL : ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i])); vx[9] = tmp; }
    v0 = v0 - hi_50948 + (u32)(unsigned long)ref_t32_data_ce1b0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_5095c;
    v0 = v0 - hi_5095c + (u32)(unsigned long)ref_t32_data_ce1c0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50968;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[1].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[1] = tmp; }
    v0 = v0 - hi_50968 + (u32)(unsigned long)ref_t32_data_e1e68;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(s8 + (136)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[5].h[i] == 0) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[13].h[i] == 0) ? ~0U : 0; vx[3] = tmp; }
    t1 = hi_50998;
    t1 = t1 - hi_50998 + (u32)(unsigned long)ref_t32_data_ce1d0;
    t0 = a1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[1].w[i]) | (vx[5].w[i] & vx[1].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[3].w[i]) | (vx[13].w[i] & vx[3].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = vx[10].b[i] > vx[11].b[i] ? vx[10].b[i] - vx[11].b[i] : 0; vx[9] = tmp; }
    s6 = a1;
    t3 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[14].w[i]) | (vx[0].w[i] & vx[14].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_509c8;
    v0 = v0 - hi_509c8 + (u32)(unsigned long)ref_t32_data_e1e78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 1; vx[1] = tmp; }
    v0 = hi_509d8;
    v0 = v0 - hi_509d8 + (u32)(unsigned long)ref_t32_data_e1e88;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[1].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[2].h[i] >> (1 & 15); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] >> (1 & 15); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[1].h[i]); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[13].h[i] >> (2 & 15); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[14].w[i]) | (vx[0].w[i] & vx[14].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[17].h[i] >> (2 & 15); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[2].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[14].w[i]) | (vx[13].w[i] & vx[14].w[i]); vx[20] = tmp; }
    v0 = hi_50a20;
    v0 = v0 - hi_50a20 + (u32)(unsigned long)ref_t32_data_e1e98;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[17].w[i] & vx[5].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    v0 = hi_50a34;
    v0 = v0 - hi_50a34 + (u32)(unsigned long)ref_t32_data_e1ea8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[20].b[i]; }
    v0 = hi_50a40;
    v0 = v0 - hi_50a40 + (u32)(unsigned long)ref_t32_data_e1eb8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    v0 = hi_50a54;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[16].h[i] == 0) ? ~0U : 0; vx[2] = tmp; }
    v0 = v0 - hi_50a54 + (u32)(unsigned long)ref_t32_data_e1ec8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[20].b[i]; }
    v0 = hi_50a68;
    v0 = v0 - hi_50a68 + (u32)(unsigned long)ref_t32_data_e1ed8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[15].h[i] == 0) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[2].w[i]) | (vx[16].w[i] & vx[2].w[i]); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    v0 = hi_50a80;
    v0 = v0 - hi_50a80 + (u32)(unsigned long)ref_t32_data_e1ee8;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[6].w[i]) | (vx[15].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[1].h[i] ? vx[7].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[19].h[i] ? vx[7].h[i] - vx[19].h[i] : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[9].w[i]) | (vx[0].w[i] & vx[9].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[6].w[i]) | (vx[0].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[9].w[i]) | (vx[13].w[i] & vx[9].w[i]); vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    v0 = hi_50aa4;
    v0 = v0 - hi_50aa4 + (u32)(unsigned long)ref_t32_data_e1ef8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[3].h[i] ? vx[8].h[i] - vx[3].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[20].h[i] ? vx[8].h[i] - vx[20].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[19].h[i] ? vx[7].h[i] - vx[19].h[i] : 0; vx[7] = tmp; }
    v0 = hi_50abc;
    v0 = v0 - hi_50abc + (u32)(unsigned long)ref_t32_data_e1f08;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[17].w[i] & vx[6].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[20].h[i] ? vx[8].h[i] - vx[20].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[7].w[i] & vx[5].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[6].w[i]) | (vx[0].w[i] & vx[6].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[14].w[i]) | (vx[8].w[i] & vx[14].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[13].h[i] ? vx[8].h[i] - vx[13].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[9].w[i]) | (vx[0].w[i] & vx[9].w[i]); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    v0 = hi_50ae4;
    v0 = v0 - hi_50ae4 + (u32)(unsigned long)ref_t32_data_e1f18;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    v0 = hi_50af0;
    v0 = v0 - hi_50af0 + (u32)(unsigned long)ref_t32_data_e1f28;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[13].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[15] = tmp; }
    v0 = hi_50b00;
    v0 = v0 - hi_50b00 + (u32)(unsigned long)ref_t32_data_e1f38;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[2].h[i] > vx[13].h[i] ? vx[2].h[i] - vx[13].h[i] : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[i] > vx[15].h[i] ? vx[1].h[i] - vx[15].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[15].h[i] ? vx[7].h[i] - vx[15].h[i] : 0; vx[1] = tmp; }
    v0 = hi_50b18;
    v0 = v0 - hi_50b18 + (u32)(unsigned long)ref_t32_data_e1f48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[14].w[i]) | (vx[8].w[i] & vx[14].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[5].w[i]) | (vx[1].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[9].w[i]) | (vx[3].w[i] & vx[9].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[1].w[i] & vx[6].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_50b34;
    v0 = v0 - hi_50b34 + (u32)(unsigned long)ref_t32_data_e1f58;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = (vx[10].b[i] == vx[0].b[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 1; vx[2] = tmp; }
    v0 = hi_50b48;
    v0 = v0 - hi_50b48 + (u32)(unsigned long)ref_t32_data_e1f68;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[12].b[i]; }
    v0 = hi_50b64;
    v0 = v0 - hi_50b64 + (u32)(unsigned long)ref_t32_data_e1f78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[11].b[i]; }
    v0 = hi_50b70;
    v0 = v0 - hi_50b70 + (u32)(unsigned long)ref_t32_data_e1f88;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[10].b[i]; }
    v0 = 20;
    s3 = s3 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (300));
    t2 = v0 + s3;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (296));
    s3 = v0 + s3;
    v0 = s8 + 768;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_50b9c;
    v0 = v0 - hi_50b9c + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_50bb0;
    v0 = v0 - hi_50bb0 + (u32)(unsigned long)ref_t32_data_ce1f0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_50bc4;
    v0 = v0 - hi_50bc4 + (u32)(unsigned long)ref_t32_data_ce1a0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 784;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (548));
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_50be8;
    v0 = v0 - hi_50be8 + (u32)(unsigned long)ref_t32_data_ce180;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 600;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_50bfc;
    v0 = v0 - hi_50bfc + (u32)(unsigned long)ref_t32_data_ce190;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
L_50c10:
    a1 = *(volatile u16 *)(unsigned long)(t0 + (32));
    v0 = hi_50c14;
    a0 = 1;
    branch = (a1 != a0); v1 = v0 - hi_50c14 + (u32)(unsigned long)ref_t32_data_bf9ec;
    if (branch) goto L_50d20;
    goto L_50c24;
L_50c24:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (64));
    a1 = hi_50c2c;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = 0;
    a1 = a1 - hi_50c2c + (u32)(unsigned long)ref_t32_data_d6be4;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_50c5c:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a0);
    branch = (v0 != 0); v0 = a2 + 336;
    if (branch) goto L_50c8c;
    goto L_50c70;
L_50c70:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (a2)))[i]; }
    v0 = a2 + 464;
    a0 = a0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[2].b[i]; }
    a2 = a2 + 16; goto L_50c5c;
L_50c8c:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (24));
    a1 = a0 << (0x2 & 31);
    a2 = hi_50c94;
    a1 = s5 + a1;
    a2 = a2 - hi_50c94 + (u32)(unsigned long)ref_t32_data_d6be4;
L_50ca0:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    v0 = (s32)a0 < (s32)(v0);
    branch = (v0 == 0); a1 = a1 + 4;
    if (branch) goto L_50ccc;
    goto L_50cb0;
L_50cb0:
    v0 = a0 << (0x2 & 31);
    v0 = a2 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    *(volatile u32 *)(unsigned long)(a1 + (332)) = t4;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(a1 + (460)) = v0; goto L_50ca0;
L_50ccc:
    a0 = *(volatile u16 *)(unsigned long)(t0 + (160));
    v0 = 1;
    branch = (a0 != v0); v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    if (branch) goto L_51048;
    goto L_50cdc;
L_50cdc:
    a0 = 31;
    a2 = 0;
    a0 = a0 - v0;
    a0 = a0 << (0x1 & 31);
    v1 = v1 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (192));
    t4 = v0 << (0x2 & 31);
    t5 = t4 + 336;
    v1 = v1 * a0;
    t6 = t4 + 464;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v1 = hi_50d10;
    a1 = v1 - hi_50d10 + (u32)(unsigned long)ref_t32_data_d6b64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; } goto L_50ea0;
L_50d20:
    a1 = *(volatile u8 *)(unsigned long)(s6 + (288));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (96));
    t4 = hi_50d28;
    v0 = a1 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = 0;
    t4 = t4 - hi_50d28 + (u32)(unsigned long)ref_t32_data_d6b64;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = 32;
    a1 = v0 - a1;
    a1 = a1 & 0xff;
    a1 = a1 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_50d68:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (288));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a0);
    branch = (v0 != 0); t5 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_50da0;
    goto L_50d7c;
L_50d7c:
    v0 = a2 + 336;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[1].b[i]; }
    v0 = a2 + a1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t4 + (v0)))[i]; }
    v0 = a2 + 464;
    a0 = a0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v0)))[i] = vx[2].b[i]; }
    a2 = a2 + 16; goto L_50d68;
L_50da0:
    v0 = a0 << (0x2 & 31);
    t4 = hi_50da4;
    v0 = s5 + v0;
    t4 = t4 - hi_50da4 + (u32)(unsigned long)ref_t32_data_d6b64;
L_50db0:
    a2 = *(volatile u8 *)(unsigned long)(s6 + (288));
    t6 = (s32)a0 < (s32)(a2);
    branch = (t6 == 0); v0 = v0 + 4;
    if (branch) goto L_50de0;
    goto L_50dc0;
L_50dc0:
    a2 = a0 << (0x2 & 31);
    a2 = a2 + a1;
    a2 = t4 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (332)) = t5;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (460)) = a2; goto L_50db0;
L_50de0:
    v0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (128));
    a1 = a2 + 84;
    v0 = v0 - a2;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = a1 << (0x2 & 31);
    a1 = s5 + a1;
    v0 = v0 * a0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = a2;
    a2 = hi_50e18;
    a2 = a2 - hi_50e18 + (u32)(unsigned long)ref_t32_data_d6be4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[0]; vx[2] = tmp; }
L_50e24:
    a0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = a0 + -4;
    a0 = (s32)a0 < (s32)(v0);
    branch = (a0 != 0); t4 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_50e5c;
    goto L_50e38;
L_50e38:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(s6 + (288));
    a1 = a1 + 16;
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (a0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (112)))[i] = vx[1].b[i]; }
    v0 = v0 + 4; goto L_50e24;
L_50e5c:
    a1 = v0 << (0x2 & 31);
    a2 = hi_50e60;
    a1 = s5 + a1;
    a2 = a2 - hi_50e60 + (u32)(unsigned long)ref_t32_data_d6be4;
L_50e6c:
    a0 = *(volatile u8 *)(unsigned long)(s6 + (304));
    a0 = (s32)v0 < (s32)(a0);
    branch = (a0 == 0); a1 = a1 + 4;
    if (branch) goto L_50ccc;
    goto L_50e7c;
L_50e7c:
    *(volatile u32 *)(unsigned long)(a1 + (332)) = t4;
    a0 = *(volatile u8 *)(unsigned long)(s6 + (288));
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + a2;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 + (460)) = a0; goto L_50e6c;
L_50ea0:
    v1 = (s32)v0 < (s32)(29);
    branch = (v1 == 0); v1 = t5 + a2;
    if (branch) goto L_50ecc;
    goto L_50eac;
L_50eac:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v1)))[i] = vx[1].b[i]; }
    a0 = a2 + t4;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (a0)))[i]; }
    v1 = t6 + a2;
    v0 = v0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s5 + (v1)))[i] = vx[2].b[i]; }
    a2 = a2 + 16; goto L_50ea0;
L_50ecc:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (24));
    v1 = v0 << (0x2 & 31);
    a0 = s5 + v1;
    v1 = a1 + v1;
L_50edc:
    a1 = (s32)v0 < (s32)(32);
    branch = (a1 == 0); a0 = a0 + 4;
    if (branch) goto L_50f00;
    goto L_50ee8;
L_50ee8:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (332)) = a2;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (460)) = a1;
    v1 = v1 + 4; goto L_50edc;
L_50f00:
    v0 = hi_50f00;
    v0 = v0 - hi_50f00 + (u32)(unsigned long)ref_t32_data_e1f98;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f0c;
    v0 = v0 - hi_50f0c + (u32)(unsigned long)ref_t32_data_e1fa8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f18;
    v0 = v0 - hi_50f18 + (u32)(unsigned long)ref_t32_data_e1fb8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[16].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f24;
    v0 = v0 - hi_50f24 + (u32)(unsigned long)ref_t32_data_e1fc8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f30;
    v0 = v0 - hi_50f30 + (u32)(unsigned long)ref_t32_data_e1fd8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f3c;
    v0 = v0 - hi_50f3c + (u32)(unsigned long)ref_t32_data_e1fe8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f48;
    v0 = v0 - hi_50f48 + (u32)(unsigned long)ref_t32_data_e1ff8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f54;
    v0 = v0 - hi_50f54 + (u32)(unsigned long)ref_t32_data_e2008;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f60;
    v0 = v0 - hi_50f60 + (u32)(unsigned long)ref_t32_data_e2018;
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f6c;
    v0 = v0 - hi_50f6c + (u32)(unsigned long)ref_t32_data_e2028;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f78;
    v0 = v0 - hi_50f78 + (u32)(unsigned long)ref_t32_data_e2038;
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f84;
    v0 = v0 - hi_50f84 + (u32)(unsigned long)ref_t32_data_e2048;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f90;
    v0 = v0 - hi_50f90 + (u32)(unsigned long)ref_t32_data_e2058;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_50f9c;
    v0 = v0 - hi_50f9c + (u32)(unsigned long)ref_t32_data_e2068;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[4].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[5].w[i]; vx[5] = tmp; }
    v0 = hi_50fb0;
    v0 = v0 - hi_50fb0 + (u32)(unsigned long)ref_t32_data_e2078;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    v0 = hi_50fc0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 15; vx[1] = tmp; }
    v0 = v0 - hi_50fc0 + (u32)(unsigned long)ref_t32_data_e2088;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 768;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[2].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[12].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[5].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[13].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[15].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[14].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[16].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    a2 = a3 + 16;
    a1 = a3 + 32;
    a0 = a3 + 48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[4].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[8].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[10].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[9].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[11].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[3].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[6].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    t4 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    v0 = 0;
    t6 = s0 + 48;
    t5 = 16; goto L_51124;
L_51048:
    a2 = *(volatile u8 *)(unsigned long)(s6 + (320));
    t6 = hi_5104c;
    t4 = v0 << (0x2 & 31);
    a0 = a2 - v0;
    a0 = a0 + -1;
    a0 = a0 << (0x1 & 31);
    a0 = v1 + a0;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t0 + (224));
    t5 = 0;
    t6 = t6 - hi_5104c + (u32)(unsigned long)ref_t32_data_d6b64;
    a1 = a1 * a0;
    a0 = v0;
    v0 = 32;
    v0 = v0 - a2;
    v0 = v0 & 0xff;
    v0 = v0 + a0;
    v0 = v0 << (0x2 & 31);
L_51090:
    a2 = *(volatile u8 *)(unsigned long)(s6 + (320));
    t7 = (s32)a0 < (s32)(a2);
    branch = (t7 == 0); t7 = t5 + v0;
    if (branch) goto L_510c4;
    goto L_510a0;
L_510a0:
    t7 = t6 + t7;
    t7 = *(volatile u32 *)(unsigned long)(t7 + (0));
    a2 = t5 + t4;
    a2 = s5 + a2;
    *(volatile u32 *)(unsigned long)(a2 + (336)) = a1;
    *(volatile u32 *)(unsigned long)(a2 + (464)) = t7;
    a0 = a0 + 1;
    t5 = t5 + 4; goto L_51090;
L_510c4:
    v0 = 31;
    v0 = v0 - a2;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(t0 + (256));
    v1 = a2 << (0x2 & 31);
    a1 = hi_510e0;
    a0 = a0 * v0;
    v1 = s5 + v1;
    a1 = a1 - hi_510e0 + (u32)(unsigned long)ref_t32_data_d6be4;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = a0;
L_510f4:
    v0 = (s32)a2 < (s32)(32);
    branch = (v0 == 0); v1 = v1 + 4;
    if (branch) goto L_50f00;
    goto L_51100;
L_51100:
    *(volatile u32 *)(unsigned long)(v1 + (332)) = a0;
    v0 = *(volatile u8 *)(unsigned long)(s6 + (320));
    v0 = a2 - v0;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a2 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (460)) = v0; goto L_510f4;
L_51124:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (592)) = v0;
    v1 = t6 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_51124;
    goto L_51144;
L_51144:
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    t4 = 0;
    t6 = s0 + 32;
    t5 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[1].h[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (32)))[i] = vx[5].b[i]; }
L_51160:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (608)) = v0;
    v1 = t6 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_51160;
    goto L_51180;
L_51180:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    t4 = 0;
    t6 = s0 + 16;
    t5 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[13].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
L_5119c:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (624)) = v0;
    v1 = t6 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_5119c;
    goto L_511bc;
L_511bc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    t4 = 0;
    t5 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[9].h[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (0)))[i] = vx[2].b[i]; }
L_511d4:
    v1 = s5 + t4;
    *(volatile u16 *)(unsigned long)(v1 + (640)) = v0;
    v1 = s0 + t4;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t4 = t4 + 2;
    v0 = v0 + v1;
    branch = (t4 != t5); v0 = v0 & 0xffff;
    if (branch) goto L_511d4;
    goto L_511f4;
L_511f4:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a3 + (0)))[i] = vx[4].b[i]; }
    v1 = hi_511f8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_511f8 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[4].h[i] + (u16)vx[5].h[i]; vx[4] = tmp; }
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[2].h[i]; vx[1] = tmp; }
    a2 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
    a2 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a1 = hi_51238;
    a1 = a1 - hi_51238 + (u32)(unsigned long)ref_t32_data_e20a8;
    a2 = s8 + 552;
    a0 = hi_51244;
    a0 = a0 - hi_51244 + (u32)(unsigned long)ref_t32_data_e20b8;
    v1 = hi_5124c;
    v1 = v1 - hi_5124c + (u32)(unsigned long)ref_t32_data_e20c8;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (176)) = v0;
    v0 = hi_5125c;
    v0 = v0 - hi_5125c + (u32)(unsigned long)ref_t32_data_e2098;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (176)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 568;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 552;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[1].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 568;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 552;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 568;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 784;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[7].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[3].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[6].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[10].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[5].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[9].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[4].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] >> (vx[4].w[i] & 31)) + ((vx[4].w[i] & 31) ? ((vx[1].w[i] >> (((vx[4].w[i] & 31) - 1) & 31)) & 1) : 0); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s3 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[5].b[i]; }
    a1 = 12;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (0)))[i] = vx[3].b[i]; }
    v1 = 0;
L_5134c:
    a0 = v1 << (0x2 & 31);
    a0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (18));
    a2 = s3 + v1;
    v1 = v1 + 1;
    branch = (v1 != a1); *(volatile u8 *)(unsigned long)(a2 + (8)) = a0;
    if (branch) goto L_5134c;
    goto L_51368;
L_51368:
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (616));
    a1 = s3 + 16;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s3 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (620));
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (448)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (624));
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[19] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 648;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 664;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[15].w[i] - (s64)(s32)vx[1].w[i])); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 680;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[19].w[i] - (s64)(s32)vx[1].w[i])); vx[19] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 512;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[16].w[i] - (s64)(s32)vx[1].w[i])); vx[16] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (344)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] - (s64)(s32)vx[1].w[i])); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[17] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (360)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (416)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (464)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] * (u32)vx[2].w[i]; vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (432)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] << (8 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[3].w[i]; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[1].w[i]; vx[21] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (480)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[2].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] * (u32)vx[1].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (496)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] * (u32)vx[1].w[i]; vx[14] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 528;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[16].w[i] < 0) ? ~0U : 0; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i] < 0) ? ~0U : 0; vx[12] = tmp; }
    v0 = s8 + 696;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[16].w[i]) | (vx[4].w[i] & vx[16].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (384)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i] < 0) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[12].w[i]) | (vx[2].w[i] & vx[12].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[17].w[i] << (8 & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[15].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (400)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[15].w[i] < 0) ? ~0U : 0; vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[11].w[i]) | (vx[20].w[i] & vx[11].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 712;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[2].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[19].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[15].w[i]) | (vx[9].w[i] & vx[15].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[19].w[i] < 0) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[10].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i])); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 728;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[19].w[i]) | (vx[1].w[i] & vx[19].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[6].w[i])); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[1] = tmp; }
    v0 = s8 + 600;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] >> (8 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[1].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[3].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] >> (8 & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] >> (8 & 31); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] >> (8 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (8 & 31); vx[2] = tmp; }
    v0 = s8 + 632;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = (s32)vx[4].w[0];
    *(volatile u8 *)(unsigned long)(s3 + (16)) = v0;
    v0 = (s32)vx[4].w[1];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[3].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    *(volatile u8 *)(unsigned long)(s3 + (17)) = v0;
    v0 = (s32)vx[4].w[2];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s3 + (0)))[i] = vx[3].b[i]; }
    *(volatile u8 *)(unsigned long)(s3 + (18)) = v0;
    v0 = (s32)vx[4].w[3];
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    *(volatile u8 *)(unsigned long)(s3 + (19)) = v0;
    v0 = 4;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_5158c;
    goto L_5151c;
L_5151c:
    v0 = s8 + 800;
L_51520:
    a1 = s3;
    a0 = t2;
    a2 = 20;
    *(volatile u32 *)(unsigned long)(s8 + (864)) = t1;
    *(volatile u32 *)(unsigned long)(s8 + (848)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (832)) = t3;
    *(volatile u32 *)(unsigned long)(s8 + (816)) = t0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    callee = s4; *(volatile u32 *)(unsigned long)(s8 + (752)) = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51548;
L_51548:
    t3 = *(volatile u32 *)(unsigned long)(s8 + (832));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (816));
    t2 = *(volatile u32 *)(unsigned long)(s8 + (752));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (848));
    v1 = s8 + 800;
    t3 = t3 + 1;
    v0 = 16;
    t0 = t0 + 2;
    t2 = t2 + 20;
    s3 = s3 + 20;
    a3 = a3 + 64;
    s6 = s6 + 1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    branch = (t3 != v0); t1 = *(volatile u32 *)(unsigned long)(s8 + (864));
    if (branch) goto L_50c10;
    goto L_51584;
L_51584:
    s2 = s2 + 16; goto L_5077c;
L_5158c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[9] = tmp; }
    v0 = 64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[14] = tmp; }
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[8].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[22].w[i] | vx[22].w[i]; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[i] | vx[2].w[i]; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[23].w[i] | vx[23].w[i]; vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[13].w[i] | vx[13].w[i]; vx[25] = tmp; }
    v0 = s8 + 752;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[23].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[23].w[i] + vx[7].w[i]); vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[22].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[22].w[i] + vx[7].w[i]); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[13].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[13].w[i] + vx[7].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[2].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[2].w[i] + vx[7].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[17].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[17].w[i] + vx[7].w[i]); vx[30] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[8].w[i] + vx[7].w[i]); vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[18].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[18].w[i] + vx[7].w[i]); vx[28] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] + vx[7].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[1].w[i] + vx[7].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[7].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] - (s64)(s32)vx[24].w[i])); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[27].w[i])); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[26].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[18].w[i] - (s64)(s32)vx[25].w[i])); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[2].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[1].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[17].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[15].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[15].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[15].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[15].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[8].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[18].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[23].w[i]  < (s32)vx[17].w[i]) ? ~0U : 0; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[7].w[i] + vx[14].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[7].w[i] >> (7 & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[12].w[i] + vx[14].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[11].w[i] + vx[14].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[10].w[i] + vx[14].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[12].w[i] >> (7 & 31); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[7].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[11].w[i] >> (7 & 31); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[10].w[i] >> (7 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] | vx[15].w[i]; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[31].w[i]) | (vx[15].w[i] & vx[31].w[i]); vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[7].w[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[10].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[21].w[i]) | (vx[15].w[i] & vx[21].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[12].w[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[31].w[i] & ~vx[7].w[i]) | (vx[9].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[20].w[i]) | (vx[15].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[19].w[i]) | (vx[15].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[11].w[i]) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] + (u32)vx[7].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[10].w[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[12].w[i]) | (vx[9].w[i] & vx[12].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[22].w[i]  < (s32)vx[8].w[i]) ? ~0U : 0; vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[2].w[i]) | (vx[7].w[i] & vx[2].w[i]); vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[11].w[i]) | (vx[9].w[i] & vx[11].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[10].w[i]) | (vx[9].w[i] & vx[10].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[18].w[i]) ? ~0U : 0; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[27].w[i] + (u32)vx[12].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[26].w[i] + (u32)vx[11].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[10].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[17].w[i] & ~vx[23].w[i]) | (vx[12].w[i] & vx[23].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[8].w[i] & ~vx[22].w[i]) | (vx[11].w[i] & vx[22].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[6].w[i] + vx[14].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[5].w[i] + vx[14].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[4].w[i] + vx[14].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] + vx[14].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[3].w[i] + vx[14].w[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (7 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (7 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[4].w[i] >> (7 & 31); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[14].w[i] >> (7 & 31); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[18].w[i] & ~vx[13].w[i]) | (vx[10].w[i] & vx[13].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[6].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[5].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[4].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[14].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[21].w[i]) | (vx[16].w[i] & vx[21].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[20].w[i]) | (vx[16].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[19].w[i]) | (vx[16].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[2].w[i]) | (vx[16].w[i] & vx[2].w[i]); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[5].w[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[4].w[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[14].w[i]) ? ~0U : 0; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[21].w[i] & ~vx[6].w[i]) | (vx[9].w[i] & vx[6].w[i]); vx[6] = tmp; }
    v0 = s8 + 600;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[5].w[i]) | (vx[9].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[4].w[i]) | (vx[9].w[i] & vx[4].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[16].w[i] & ~vx[14].w[i]) | (vx[9].w[i] & vx[14].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[27].w[i] - (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[4].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[15].w[i])); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[30].w[i]  < (s32)vx[27].w[i]) ? ~0U : 0; vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[24].w[i]) ? ~0U : 0; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[29].w[i]  < (s32)vx[26].w[i]) ? ~0U : 0; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[28].w[i]  < (s32)vx[25].w[i]) ? ~0U : 0; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[27].w[i]) | (vx[6].w[i] & vx[27].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[24].w[i]) | (vx[15].w[i] & vx[24].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[26].w[i]) | (vx[5].w[i] & vx[26].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[25].w[i]) | (vx[4].w[i] & vx[25].w[i]); vx[10] = tmp; }
    v0 = s8 + 632;
    a2 = t2 + 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[11].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    t4 = s3 + 20;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s3 + (0)))[i] = vx[10].b[i]; }
L_517a4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t5 = v1 + a0;
    v1 = (s32)t5 < (s32)(v0);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    if (branch) goto L_5180c;
    goto L_517c0;
L_517c0:
    v1 = v0 - a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v1 = v1 + 64;
    v1 = (s32)v1 >> (0x7 & 31);
    v0 = (s32)v1 < (s32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_517ec;
    goto L_517e4;
L_517e4:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = t5; goto L_51868;
L_517ec:
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); v1 = a0 + v1;
    if (branch) goto L_51804;
    goto L_517f8;
L_517f8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    a0 = v0 + a0; goto L_51848;
L_51804:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v1; goto L_51868;
L_5180c:
    v1 = v1 + v0;
    v1 = (s32)v1 < (s32)(a0);
    if (v1 == 0) { a1 = a1 + 1; goto L_5186c; }
    goto L_5181c;
L_5181c:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = a0 - v0;
    v0 = v0 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v1 = (s32)v0 < (s32)(v1);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_51850;
    goto L_51840;
L_51840:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
L_51844:
    a0 = a0 - v0;
L_51848:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = a0; goto L_51868;
L_51850:
    v1 = (s32)v1 < (s32)(v0);
    if (v1 == 0) { v0 = a0 - v0; goto L_51864; }
    goto L_5185c;
L_5185c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228)); goto L_51844;
L_51864:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v0;
L_51868:
    a1 = a1 + 1;
L_5186c:
    branch = (t4 != a1); a2 = a2 + 1;
    if (branch) goto L_517a4;
    goto L_51874;
L_51874:
    v0 = s8 + 800; goto L_51520;
L_5187c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (336));
    branch = (v0 == 0); a0 = s3 << (0x6 & 31);
    if (branch) goto L_51a50;
    goto L_51888;
L_51888:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a2 = 64;
    a1 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    a0 = v0 + a0;
L_518a4:
    v0 = hi_518a4;
    v0 = v0 - hi_518a4 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_518b4;
L_518b4:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 568;
    t0 = s3 << (0x6 & 31);
    a1 = *(volatile u32 *)(unsigned long)(s8 + (280));
    a2 = s8 + 184;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    s4 = v0 + t0;
    v0 = s6 - hi_507a4 + (u32)(unsigned long)ref_tisp_lce_thres_search;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_518e4;
L_518e4:
    v0 = s8 + s2;
    a3 = *(volatile u8 *)(unsigned long)(v0 + (88));
    v0 = *(volatile u16 *)(unsigned long)(s8 + (180));
    a2 = s8 + 184;
    a1 = s8 + 188;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_518fc;
    v0 = v0 - hi_518fc + (u32)(unsigned long)ref_tisp_lce_hist_method;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5190c;
L_5190c:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (544));
    v1 = s8 + 24;
    a0 = v1;
    a2 = 64;
    a1 = 0;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (552)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51928;
L_51928:
    a2 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(s8 + (552));
    a1 = 0;
    v0 = 0;
    a0 = v1;
    v1 = 64;
L_51944:
    a2 = a0 + a1;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = v0;
    a2 = s4 + a1;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a1 = a1 + 2;
    v0 = v0 + a2;
    branch = (a1 != v1); v0 = v0 & 0xffff;
    if (branch) goto L_51944;
    goto L_51964;
L_51964:
    v1 = 20;
    s3 = s3 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (296));
    branch = (v0 != 0); s4 = v1 + s3;
    if (branch) goto L_51aa4;
    goto L_51978;
L_51978:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    a0 = hi_51980;
    v0 = hi_51984;
    a2 = 1065;
    a1 = s5;
    v0 = v0 - hi_51984 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_51980 + (u32)(unsigned long)ref_t32_data_c9660;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_5199c;
L_5199c:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 552;
L_519a8:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (376));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (380));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = hi_519b4;
    v0 = v0 - hi_519b4 + (u32)(unsigned long)ref_tisp_lce_hist_adjust;
    callee = v0; a0 = s4;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_519c4;
L_519c4:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    a0 = s8 + 552;
    v0 = 4;
    s3 = v1 + s3;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    branch = (v1 == v0); a2 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_51a08;
    goto L_519e4;
L_519e4:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = hi_519ec;
    v0 = v0 - hi_519ec + (u32)(unsigned long)ref_tisp_lce_16bit_data_converge;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s4;
    callee = v0; a3 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51a00;
L_51a00:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
L_51a08:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = hi_51a10;
    a2 = 20;
    a1 = s4;
    v0 = v0 - hi_51a10 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51a28;
L_51a28:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    s2 = s2 + 1;
L_51a34:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (268));
    s3 = s7 + s2;
    v0 = (s32)s2 < (s32)(v0);
    branch = (v0 != 0); s3 = s3 & 0xffff;
    if (branch) goto L_5187c;
    goto L_51a48;
L_51a48:
    v0 = *(volatile u32 *)(unsigned long)(s1 + (44)); goto L_51b50;
L_51a50:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    t2 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    t1 = v0 + a0;
    v0 = hi_51a68;
    a1 = t1;
    v0 = v0 - hi_51a68 + (u32)(unsigned long)ref_get_distance_1dim;
    callee = v0; a0 = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51a7c;
L_51a7c:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (340));
    v0 = (u32)v1 < (u32)(v0);
    v1 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    if (v0 == 0) { s2 = s2 + 1; goto L_51a34; }
    goto L_51a94;
L_51a94:
    a2 = 64;
    a1 = t1;
    a0 = t2; goto L_518a4;
L_51aa4:
    v1 = hi_51aa4;
    a1 = *(volatile u8 *)(unsigned long)(v1 - hi_51aa4 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    a2 = s4;
    v1 = v1 << (a1 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a3 = s4 + 8;
    v0 = lo;
L_51ac4:
    v1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    v1 = v1 * v0;
    a1 = *(volatile u8 *)(unsigned long)(a1 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    t1 = *(volatile u8 *)(unsigned long)(t0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a2 = a2 + 1;
    a0 = a0 + 2;
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    v1 = v1 >> (t1 & 31);
    v1 = a1 + v1;
    branch = (a3 != a2); *(volatile u8 *)(unsigned long)(a2 + (-1)) = v1;
    if (branch) goto L_51ac4;
    goto L_51afc;
L_51afc:
    a2 = 0;
    a3 = 12;
L_51b04:
    v1 = a2 << (0x2 & 31);
    a0 = s8 + 24;
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (18));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t1 = s4 + a2;
    v1 = v1 * v0;
    a1 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    a0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a2 = a2 + 1;
    a0 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    a0 = v1 >> (a0 & 31);
    a0 = a1 + a0;
    branch = (a2 != a3); *(volatile u8 *)(unsigned long)(t1 + (8)) = a0;
    if (branch) goto L_51b04;
    goto L_51b48;
L_51b48:
    v0 = s8 + 552; goto L_519a8;
L_51b50:
    a2 = *(volatile u32 *)(unsigned long)(s1 + (80));
    v1 = *(volatile u32 *)(unsigned long)(s8 + (268));
    *(volatile u32 *)(unsigned long)(s8 + (180)) = v0;
    v0 = *(volatile u8 *)(unsigned long)(s1 + (204));
    a1 = 32;
    *(volatile u16 *)(unsigned long)(s8 + (188)) = v0;
L_51b68:
    branch = (v1 == a1); a0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    if (branch) goto L_51ba0;
    goto L_51b70;
L_51b70:
    v0 = v1 << (0x2 & 31);
    v0 = a0 + v0;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a0 = s8 + 88;
    a3 = a0 + v1;
    v0 = a2 * v0;
    v1 = v1 + 1;
    a0 = (v0 >> 0x17) & ((1U << 0x1) - 1);
    v0 = v0 >> (0x18 & 31);
    v0 = a0 + v0;
    *(volatile u8 *)(unsigned long)(a3 + (0)) = v0; goto L_51b68;
L_51ba0:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (188)))[i]; }
    s4 = *(volatile u32 *)(unsigned long)(s8 + (268));
    s2 = s3;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[0]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s8 + (280)))[i] = vx[1].b[i]; }
L_51bb4:
    v0 = (s32)s4 < (s32)(17);
    if (v0 != 0) { s7 = hi_51bbc; goto L_51bec; }
    goto L_51bc0;
L_51bc0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (628));
    s5 = hi_51bc4;
    s6 = hi_51bc8;
    s3 = s3 + v0;
    v0 = s5 - hi_51bc4 + (u32)(unsigned long)ref_t32_data_e189e;
    s3 = s3 & 0xffff;
    s4 = *(volatile u32 *)(unsigned long)(s8 + (328));
    *(volatile u32 *)(unsigned long)(s8 + (280)) = v0;
    s7 = hi_51be0;
    s6 = s6 - hi_51bc8 + (u32)(unsigned long)ref_t32_data_bf994; goto L_52ed0;
L_51bec:
    s6 = s2 << (0x6 & 31);
    v1 = 0;
    s7 = s7 - hi_51bbc + (u32)(unsigned long)ref_memcpy_simd;
    a3 = 1024;
    v0 = s8 + 568;
L_51c00:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a0 = s6 + v1;
    a2 = 64;
    a1 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    *(volatile u32 *)(unsigned long)(s8 + (584)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (552)) = v1;
    callee = s7; a0 = v0 + a0;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51c28;
L_51c28:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (552));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (584));
    v0 = s8 + 568;
    v1 = v1 + 64;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (v1 != a3); s5 = s7;
    if (branch) goto L_51c00;
    goto L_51c44;
L_51c44:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a1 = hi_51c50;
    a1 = a1 - hi_51c50 + (u32)(unsigned long)ref_t32_data_e189e;
    s6 = v0 + s6;
    v0 = s8 + 136;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_51c64;
    a0 = s6;
    v0 = v0 - hi_51c64 + (u32)(unsigned long)ref_tisp_lce_thres_search_simd_v4;
    a3 = s8 + 120;
    callee = v0; a2 = s8 + 152;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_51c7c;
L_51c7c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    v0 = s8 + 552;
    a1 = hi_51c84;
    t0 = s6;
    v1 = s6;
    a0 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[0].w[i] | vx[0].w[i]; vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    a1 = a1 - hi_51c84 + (u32)(unsigned long)ref_t32_data_e1e48;
    t4 = 32;
L_51ca4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v1 + (16)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v1 + (32)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v1 + (48)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(s8 + (280)))[i]; }
    t5 = a1 + a0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[12].h[i] > vx[1].h[i] ? vx[12].h[i] - vx[1].h[i] : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[11].h[i] > vx[1].h[i] ? vx[11].h[i] - vx[1].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[10].h[i] > vx[1].h[i] ? vx[10].h[i] - vx[1].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[9].h[i] > vx[1].h[i] ? vx[9].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[12].h[i]) ? ~0U : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[11].h[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[10].h[i]) ? ~0U : 0; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (vx[14].h[i] < vx[9].h[i]) ? ~0U : 0; vx[4] = tmp; }
    a0 = a0 + 2;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[7].w[i]) | (vx[3].w[i] & vx[7].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[2].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[8].w[i] & vx[5].w[i]); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[4].w[i]) | (vx[1].w[i] & vx[4].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[7].w[i]) | (vx[13].w[i] & vx[7].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[3].h[i] + vx[2].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[3].h[i] + vx[2].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[6].w[i]) | (vx[13].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[2].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[2].h[i] + vx[1].h[i]); vx[1] = tmp; }
    a2 = (s16)vx[1].h[1];
    v0 = (s16)vx[1].h[0];
    a3 = (s16)vx[1].h[5];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[5].w[i]) | (vx[13].w[i] & vx[5].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[4].w[i]) | (vx[13].w[i] & vx[4].w[i]); vx[4] = tmp; }
    v0 = v0 + a2;
    a2 = (s16)vx[1].h[2];
    v1 = v1 + 64;
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[3];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[4];
    v0 = a2 + v0;
    a2 = (s16)vx[1].h[6];
    v0 = a3 + v0;
    a2 = a2 + v0;
    v0 = (s16)vx[1].h[7];
    v0 = v0 + a2;
    *(volatile u16 *)(unsigned long)(t5 + (0)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-64)))[i] = vx[7].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-48)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-32)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (-16)))[i] = vx[4].b[i]; }
    branch = (a0 != t4); s6 = a1;
    if (branch) goto L_51ca4;
    goto L_51d6c;
L_51d6c:
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(s8 + (120)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(s8 + (152)))[i]; }
    v0 = hi_51d74;
    v0 = v0 - hi_51d74 + (u32)(unsigned long)ref_t32_data_e1e58;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_51d80;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) < (-128LL) ? (-128LL) : (((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i]) > 127LL ? 127LL : ((s64)(int8_t)vx[11].b[i] - (s64)(int8_t)vx[12].b[i])); vx[9] = tmp; }
    v0 = v0 - hi_51d80 + (u32)(unsigned long)ref_t32_data_ce1b0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[18].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_51d94;
    v0 = v0 - hi_51d94 + (u32)(unsigned long)ref_t32_data_ce1c0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_51da0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[1].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[1] = tmp; }
    v0 = v0 - hi_51da0 + (u32)(unsigned long)ref_t32_data_e1e68;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(s8 + (136)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[5].h[i] == 0) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[14].h[i] == 0) ? ~0U : 0; vx[3] = tmp; }
    s7 = 20;
    s7 = s2 * s7;
    t2 = hi_51dd8;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[1].w[i]) | (vx[5].w[i] & vx[1].w[i]); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[3].w[i]) | (vx[14].w[i] & vx[3].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = vx[10].b[i] > vx[11].b[i] ? vx[10].b[i] - vx[11].b[i] : 0; vx[9] = tmp; }
    t2 = t2 - hi_51dd8 + (u32)(unsigned long)ref_t32_data_ce1d0;
    t1 = a1;
    a3 = a1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[13].w[i]) | (vx[0].w[i] & vx[13].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[1] = tmp; }
    t4 = 16;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_51e08;
    v0 = v0 - hi_51e08 + (u32)(unsigned long)ref_t32_data_e1e78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 1; vx[1] = tmp; }
    v0 = hi_51e18;
    v0 = v0 - hi_51e18 + (u32)(unsigned long)ref_t32_data_e1e88;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[1].h[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[2].h[i] >> (1 & 15); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = 2; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[4].h[i] >> (1 & 15); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[8].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[8].h[i] + vx[1].h[i]); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((u64)vx[7].h[i] + vx[1].h[i]) > 65535ULL ? 65535ULL : ((u64)vx[7].h[i] + vx[1].h[i]); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[5].w[i]) | (vx[0].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 2; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[14].h[i] >> (2 & 15); vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[13].w[i]) | (vx[0].w[i] & vx[13].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u32)vx[17].h[i] >> (2 & 15); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = ((int8_t)vx[2].b[i]  < (int8_t)vx[9].b[i]) ? ~0U : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = -1; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[13].w[i]) | (vx[14].w[i] & vx[13].w[i]); vx[20] = tmp; }
    v0 = hi_51e60;
    v0 = v0 - hi_51e60 + (u32)(unsigned long)ref_t32_data_e1e98;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[5].w[i]) | (vx[17].w[i] & vx[5].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[16] = tmp; }
    v0 = hi_51e74;
    v0 = v0 - hi_51e74 + (u32)(unsigned long)ref_t32_data_e1ea8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[20].b[i]; }
    v0 = hi_51e80;
    v0 = v0 - hi_51e80 + (u32)(unsigned long)ref_t32_data_e1eb8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[18].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    v0 = hi_51e94;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[16].h[i] == 0) ? ~0U : 0; vx[2] = tmp; }
    v0 = v0 - hi_51e94 + (u32)(unsigned long)ref_t32_data_e1ec8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[20].b[i]; }
    v0 = hi_51ea8;
    v0 = v0 - hi_51ea8 + (u32)(unsigned long)ref_t32_data_e1ed8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[19].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = ((s16)vx[15].h[i] == 0) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[2].w[i]) | (vx[16].w[i] & vx[2].w[i]); vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (232)))[i]; }
    v0 = hi_51ec0;
    v0 = v0 - hi_51ec0 + (u32)(unsigned long)ref_t32_data_e1ee8;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[6].w[i]) | (vx[15].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[1].h[i] ? vx[7].h[i] - vx[1].h[i] : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[19].h[i] ? vx[7].h[i] - vx[19].h[i] : 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[9].w[i]) | (vx[0].w[i] & vx[9].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[6].w[i]) | (vx[0].w[i] & vx[6].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[9].w[i]) | (vx[14].w[i] & vx[9].w[i]); vx[14] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    v0 = hi_51ee4;
    v0 = v0 - hi_51ee4 + (u32)(unsigned long)ref_t32_data_e1ef8;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[3].h[i] ? vx[8].h[i] - vx[3].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[20].h[i] ? vx[8].h[i] - vx[20].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[19].h[i] ? vx[7].h[i] - vx[19].h[i] : 0; vx[7] = tmp; }
    v0 = hi_51efc;
    v0 = v0 - hi_51efc + (u32)(unsigned long)ref_t32_data_e1f08;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[17].w[i] & vx[6].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[20].h[i] ? vx[8].h[i] - vx[20].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[1].w[i] & ~vx[5].w[i]) | (vx[7].w[i] & vx[5].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[6].w[i]) | (vx[0].w[i] & vx[6].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[13].w[i]) | (vx[8].w[i] & vx[13].w[i]); vx[15] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[8].h[i] > vx[14].h[i] ? vx[8].h[i] - vx[14].h[i] : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[15].w[i] & ~vx[9].w[i]) | (vx[0].w[i] & vx[9].w[i]); vx[15] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[15].b[i]; }
    v0 = hi_51f24;
    v0 = v0 - hi_51f24 + (u32)(unsigned long)ref_t32_data_e1f18;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[3].b[i]; }
    v0 = hi_51f30;
    v0 = v0 - hi_51f30 + (u32)(unsigned long)ref_t32_data_e1f28;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[14].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[4].w[i] | vx[4].w[i]; vx[15] = tmp; }
    v0 = hi_51f40;
    v0 = v0 - hi_51f40 + (u32)(unsigned long)ref_t32_data_e1f38;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[4].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[2].h[i] > vx[14].h[i] ? vx[2].h[i] - vx[14].h[i] : 0; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[1].h[i] > vx[15].h[i] ? vx[1].h[i] - vx[15].h[i] : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = vx[7].h[i] > vx[15].h[i] ? vx[7].h[i] - vx[15].h[i] : 0; vx[1] = tmp; }
    v0 = hi_51f58;
    v0 = v0 - hi_51f58 + (u32)(unsigned long)ref_t32_data_e1f48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[4].w[i] & ~vx[13].w[i]) | (vx[8].w[i] & vx[13].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[5].w[i]) | (vx[1].w[i] & vx[5].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[9].w[i]) | (vx[3].w[i] & vx[9].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[0].w[i] & ~vx[6].w[i]) | (vx[1].w[i] & vx[6].w[i]); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[2].b[i]; }
    v0 = hi_51f74;
    v0 = v0 - hi_51f74 + (u32)(unsigned long)ref_t32_data_e1f58;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = (vx[10].b[i] == vx[0].b[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 1; vx[2] = tmp; }
    v0 = hi_51f88;
    v0 = v0 - hi_51f88 + (u32)(unsigned long)ref_t32_data_e1f68;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[12].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[1].w[i]) | (vx[2].w[i] & vx[1].w[i]); vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[12].b[i]; }
    v0 = hi_51fa4;
    v0 = v0 - hi_51fa4 + (u32)(unsigned long)ref_t32_data_e1f78;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[11].b[i]; }
    v0 = hi_51fb0;
    v0 = v0 - hi_51fb0 + (u32)(unsigned long)ref_t32_data_e1f88;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[10].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (300));
    t3 = v0 + s7;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (296));
    s7 = v0 + s7;
    v0 = s8 + 800;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_51fd4;
    v0 = v0 - hi_51fd4 + (u32)(unsigned long)ref_t32_data_ce1e0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_51fe8;
    v0 = v0 - hi_51fe8 + (u32)(unsigned long)ref_t32_data_ce1f0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_51ffc;
    v0 = v0 - hi_51ffc + (u32)(unsigned long)ref_t32_data_ce1a0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 816;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_52010;
    v0 = v0 - hi_52010 + (u32)(unsigned long)ref_t32_data_ce140;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_52024;
    v0 = v0 - hi_52024 + (u32)(unsigned long)ref_t32_data_ce150;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 600;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
    v0 = hi_52038;
    v0 = v0 - hi_52038 + (u32)(unsigned long)ref_t32_data_ce160;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[1].b[i]; }
L_5204c:
    a1 = *(volatile u16 *)(unsigned long)(t1 + (32));
    v0 = hi_52050;
    a0 = 1;
    branch = (a1 != a0); v1 = v0 - hi_52050 + (u32)(unsigned long)ref_t32_data_bf9ec;
    if (branch) goto L_5215c;
    goto L_52060;
L_52060:
    v0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t1 + (64));
    a1 = hi_52068;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = 0;
    a1 = a1 - hi_52068 + (u32)(unsigned long)ref_t32_data_d6be4;
    v0 = v0 * a0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = 0;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_52098:
    a0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    a0 = a0 + -4;
    a0 = (s32)a0 < (s32)(v0);
    branch = (a0 != 0); a0 = a2 + 336;
    if (branch) goto L_520c8;
    goto L_520ac;
L_520ac:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (a0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (a2)))[i]; }
    a0 = a2 + 464;
    v0 = v0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (a0)))[i] = vx[2].b[i]; }
    a2 = a2 + 16; goto L_52098;
L_520c8:
    t5 = *(volatile u32 *)(unsigned long)(s8 + (24));
    a1 = v0 << (0x2 & 31);
    a2 = hi_520d0;
    a1 = s6 + a1;
    a2 = a2 - hi_520d0 + (u32)(unsigned long)ref_t32_data_d6be4;
L_520dc:
    a0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    a0 = (s32)v0 < (s32)(a0);
    branch = (a0 == 0); a1 = a1 + 4;
    if (branch) goto L_52108;
    goto L_520ec;
L_520ec:
    a0 = v0 << (0x2 & 31);
    a0 = a2 + a0;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    *(volatile u32 *)(unsigned long)(a1 + (332)) = t5;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 + (460)) = a0; goto L_520dc;
L_52108:
    a0 = *(volatile u16 *)(unsigned long)(t1 + (160));
    v0 = 1;
    branch = (a0 != v0); v0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    if (branch) goto L_52484;
    goto L_52118;
L_52118:
    a0 = 31;
    a2 = 0;
    a0 = a0 - v0;
    a0 = a0 << (0x1 & 31);
    v1 = v1 + a0;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t1 + (192));
    t5 = v0 << (0x2 & 31);
    t6 = t5 + 336;
    v1 = v1 * a0;
    t7 = t5 + 464;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v1 = hi_5214c;
    a1 = v1 - hi_5214c + (u32)(unsigned long)ref_t32_data_d6b64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; } goto L_522dc;
L_5215c:
    a1 = *(volatile u8 *)(unsigned long)(a3 + (288));
    a0 = *(volatile u16 *)(unsigned long)(t1 + (96));
    t5 = hi_52164;
    v0 = a1 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a2 = 0;
    t5 = t5 - hi_52164 + (u32)(unsigned long)ref_t32_data_d6b64;
    v0 = v0 * a0;
    a0 = 0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = 32;
    a1 = v0 - a1;
    a1 = a1 & 0xff;
    a1 = a1 << (0x2 & 31);
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
L_521a4:
    v0 = *(volatile u8 *)(unsigned long)(a3 + (288));
    v0 = v0 + -4;
    v0 = (s32)v0 < (s32)(a0);
    branch = (v0 != 0); t6 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_521dc;
    goto L_521b8;
L_521b8:
    v0 = a2 + 336;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v0)))[i] = vx[1].b[i]; }
    v0 = a2 + a1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t5 + (v0)))[i]; }
    v0 = a2 + 464;
    a0 = a0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v0)))[i] = vx[2].b[i]; }
    a2 = a2 + 16; goto L_521a4;
L_521dc:
    v0 = a0 << (0x2 & 31);
    t5 = hi_521e0;
    v0 = s6 + v0;
    t5 = t5 - hi_521e0 + (u32)(unsigned long)ref_t32_data_d6b64;
L_521ec:
    a2 = *(volatile u8 *)(unsigned long)(a3 + (288));
    t7 = (s32)a0 < (s32)(a2);
    branch = (t7 == 0); v0 = v0 + 4;
    if (branch) goto L_5221c;
    goto L_521fc;
L_521fc:
    a2 = a0 << (0x2 & 31);
    a2 = a2 + a1;
    a2 = t5 + a2;
    a2 = *(volatile u32 *)(unsigned long)(a2 + (0));
    *(volatile u32 *)(unsigned long)(v0 + (332)) = t6;
    a0 = a0 + 1;
    *(volatile u32 *)(unsigned long)(v0 + (460)) = a2; goto L_521ec;
L_5221c:
    v0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    a0 = *(volatile u16 *)(unsigned long)(t1 + (128));
    a1 = a2 + 84;
    v0 = v0 - a2;
    v0 = v0 + -1;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    v0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    a1 = a1 << (0x2 & 31);
    a1 = s6 + a1;
    v0 = v0 * a0;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = v0;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (24)))[i]; }
    v0 = a2;
    a2 = hi_52254;
    a2 = a2 - hi_52254 + (u32)(unsigned long)ref_t32_data_d6be4;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[2].w[0]; vx[2] = tmp; }
L_52260:
    a0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    a0 = a0 + -4;
    a0 = (s32)a0 < (s32)(v0);
    branch = (a0 != 0); t5 = *(volatile u32 *)(unsigned long)(s8 + (24));
    if (branch) goto L_52298;
    goto L_52274;
L_52274:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(a3 + (288));
    a1 = a1 + 16;
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (a0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (112)))[i] = vx[1].b[i]; }
    v0 = v0 + 4; goto L_52260;
L_52298:
    a1 = v0 << (0x2 & 31);
    a2 = hi_5229c;
    a1 = s6 + a1;
    a2 = a2 - hi_5229c + (u32)(unsigned long)ref_t32_data_d6be4;
L_522a8:
    a0 = *(volatile u8 *)(unsigned long)(a3 + (304));
    a0 = (s32)v0 < (s32)(a0);
    branch = (a0 == 0); a1 = a1 + 4;
    if (branch) goto L_52108;
    goto L_522b8;
L_522b8:
    *(volatile u32 *)(unsigned long)(a1 + (332)) = t5;
    a0 = *(volatile u8 *)(unsigned long)(a3 + (288));
    a0 = v0 - a0;
    a0 = a0 << (0x2 & 31);
    a0 = a0 + a2;
    a0 = *(volatile u32 *)(unsigned long)(a0 + (0));
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a1 + (460)) = a0; goto L_522a8;
L_522dc:
    v1 = (s32)v0 < (s32)(29);
    branch = (v1 == 0); v1 = t6 + a2;
    if (branch) goto L_52308;
    goto L_522e8;
L_522e8:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v1)))[i] = vx[1].b[i]; }
    a0 = a2 + t5;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a1 + (a0)))[i]; }
    v1 = t7 + a2;
    v0 = v0 + 4;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s6 + (v1)))[i] = vx[2].b[i]; }
    a2 = a2 + 16; goto L_522dc;
L_52308:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (24));
    v1 = v0 << (0x2 & 31);
    a0 = s6 + v1;
    v1 = a1 + v1;
L_52318:
    a1 = (s32)v0 < (s32)(32);
    branch = (a1 == 0); a0 = a0 + 4;
    if (branch) goto L_5233c;
    goto L_52324;
L_52324:
    a1 = *(volatile u32 *)(unsigned long)(v1 + (0));
    *(volatile u32 *)(unsigned long)(a0 + (332)) = a2;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(a0 + (460)) = a1;
    v1 = v1 + 4; goto L_52318;
L_5233c:
    v0 = hi_5233c;
    v0 = v0 - hi_5233c + (u32)(unsigned long)ref_t32_data_e1f98;
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_52348;
    v0 = v0 - hi_52348 + (u32)(unsigned long)ref_t32_data_e1fa8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_52354;
    v0 = v0 - hi_52354 + (u32)(unsigned long)ref_t32_data_e1fb8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[16].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_52360;
    v0 = v0 - hi_52360 + (u32)(unsigned long)ref_t32_data_e1fc8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_5236c;
    v0 = v0 - hi_5236c + (u32)(unsigned long)ref_t32_data_e1fd8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_52378;
    v0 = v0 - hi_52378 + (u32)(unsigned long)ref_t32_data_e1fe8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_52384;
    v0 = v0 - hi_52384 + (u32)(unsigned long)ref_t32_data_e1ff8;
    { unsigned int i; for (i = 0; i < 16; i++) vx[14].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_52390;
    v0 = v0 - hi_52390 + (u32)(unsigned long)ref_t32_data_e2008;
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_5239c;
    v0 = v0 - hi_5239c + (u32)(unsigned long)ref_t32_data_e2018;
    { unsigned int i; for (i = 0; i < 16; i++) vx[12].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_523a8;
    v0 = v0 - hi_523a8 + (u32)(unsigned long)ref_t32_data_e2028;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_523b4;
    v0 = v0 - hi_523b4 + (u32)(unsigned long)ref_t32_data_e2038;
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_523c0;
    v0 = v0 - hi_523c0 + (u32)(unsigned long)ref_t32_data_e2048;
    { unsigned int i; for (i = 0; i < 16; i++) vx[8].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_523cc;
    v0 = v0 - hi_523cc + (u32)(unsigned long)ref_t32_data_e2058;
    { unsigned int i; for (i = 0; i < 16; i++) vx[10].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_523d8;
    v0 = v0 - hi_523d8 + (u32)(unsigned long)ref_t32_data_e2068;
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[4].w[i]; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[5].w[i]; vx[5] = tmp; }
    v0 = hi_523ec;
    v0 = v0 - hi_523ec + (u32)(unsigned long)ref_t32_data_e2078;
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    v0 = hi_523fc;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 15; vx[1] = tmp; }
    v0 = v0 - hi_523fc + (u32)(unsigned long)ref_t32_data_e2088;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 800;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[2].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[12].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[5].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[13].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[15].w[i]; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[14].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[16].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[12].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    a2 = t0 + 16;
    a1 = t0 + 32;
    a0 = t0 + 48;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[4].h[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[8].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[8].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[10].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[9].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[11].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[3].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[1].w[i] & 31)) + ((vx[1].w[i] & 31) ? ((vx[6].w[i] >> (((vx[1].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[13].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[9].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    t5 = 0;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    v0 = 0;
    t7 = s0 + 48;
    t6 = 16; goto L_52560;
L_52484:
    a2 = *(volatile u8 *)(unsigned long)(a3 + (320));
    t7 = hi_52488;
    t5 = v0 << (0x2 & 31);
    a0 = a2 - v0;
    a0 = a0 + -1;
    a0 = a0 << (0x1 & 31);
    a0 = v1 + a0;
    a1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a0 = *(volatile u16 *)(unsigned long)(t1 + (224));
    t6 = 0;
    t7 = t7 - hi_52488 + (u32)(unsigned long)ref_t32_data_d6b64;
    a1 = a1 * a0;
    a0 = v0;
    v0 = 32;
    v0 = v0 - a2;
    v0 = v0 & 0xff;
    v0 = v0 + a0;
    v0 = v0 << (0x2 & 31);
L_524cc:
    a2 = *(volatile u8 *)(unsigned long)(a3 + (320));
    t8 = (s32)a0 < (s32)(a2);
    branch = (t8 == 0); t8 = t6 + v0;
    if (branch) goto L_52500;
    goto L_524dc;
L_524dc:
    t8 = t7 + t8;
    t8 = *(volatile u32 *)(unsigned long)(t8 + (0));
    a2 = t6 + t5;
    a2 = s6 + a2;
    *(volatile u32 *)(unsigned long)(a2 + (336)) = a1;
    *(volatile u32 *)(unsigned long)(a2 + (464)) = t8;
    a0 = a0 + 1;
    t6 = t6 + 4; goto L_524cc;
L_52500:
    v0 = 31;
    v0 = v0 - a2;
    v0 = v0 << (0x1 & 31);
    v0 = v1 + v0;
    a0 = *(volatile u16 *)(unsigned long)(v0 + (0));
    v0 = *(volatile u16 *)(unsigned long)(t1 + (256));
    v1 = a2 << (0x2 & 31);
    a1 = hi_5251c;
    a0 = a0 * v0;
    v1 = s6 + v1;
    a1 = a1 - hi_5251c + (u32)(unsigned long)ref_t32_data_d6be4;
    *(volatile u32 *)(unsigned long)(s8 + (24)) = a0;
L_52530:
    v0 = (s32)a2 < (s32)(32);
    branch = (v0 == 0); v1 = v1 + 4;
    if (branch) goto L_5233c;
    goto L_5253c;
L_5253c:
    *(volatile u32 *)(unsigned long)(v1 + (332)) = a0;
    v0 = *(volatile u8 *)(unsigned long)(a3 + (320));
    v0 = a2 - v0;
    v0 = v0 << (0x2 & 31);
    v0 = v0 + a1;
    v0 = *(volatile u32 *)(unsigned long)(v0 + (0));
    a2 = a2 + 1;
    *(volatile u32 *)(unsigned long)(v1 + (460)) = v0; goto L_52530;
L_52560:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (592)) = v0;
    v1 = t7 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_52560;
    goto L_52580;
L_52580:
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    t5 = 0;
    t7 = s0 + 32;
    t6 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[5].h[i] + (u16)vx[1].h[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (32)))[i] = vx[5].b[i]; }
L_5259c:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (608)) = v0;
    v1 = t7 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_5259c;
    goto L_525bc;
L_525bc:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    t5 = 0;
    t7 = s0 + 16;
    t6 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[3].b[(sel & 31) >> 1] : vx[10].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[13].h[i]; vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
L_525d8:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (624)) = v0;
    v1 = t7 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_525d8;
    goto L_525f8;
L_525f8:
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    t5 = 0;
    t6 = 16;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[8].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[2].h[i] + (u16)vx[9].h[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (0)))[i] = vx[2].b[i]; }
L_52610:
    v1 = s6 + t5;
    *(volatile u16 *)(unsigned long)(v1 + (640)) = v0;
    v1 = s0 + t5;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (0));
    t5 = t5 + 2;
    v0 = v0 + v1;
    branch = (t5 != t6); v0 = v0 & 0xffff;
    if (branch) goto L_52610;
    goto L_52630;
L_52630:
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(t0 + (0)))[i] = vx[4].b[i]; }
    v1 = hi_52634;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a2 + (0)))[i] = vx[5].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[1].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[2].b[i]; }
    a0 = *(volatile u8 *)(unsigned long)(v1 - hi_52634 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[4].h[i] + (u16)vx[5].h[i]; vx[4] = tmp; }
    v1 = v1 << (a0 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 8; i++) tmp.h[i] = (u16)vx[1].h[i] + (u16)vx[2].h[i]; vx[1] = tmp; }
    a2 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (48)))[i] = vx[4].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s0 + (16)))[i] = vx[1].b[i]; }
    a2 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[7].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a1 = hi_52674;
    a1 = a1 - hi_52674 + (u32)(unsigned long)ref_t32_data_e20a8;
    a2 = s8 + 552;
    a0 = hi_52680;
    a0 = a0 - hi_52680 + (u32)(unsigned long)ref_t32_data_e20b8;
    v1 = hi_52688;
    v1 = v1 - hi_52688 + (u32)(unsigned long)ref_t32_data_e20c8;
    v0 = lo;
    *(volatile u32 *)(unsigned long)(s8 + (176)) = v0;
    v0 = hi_52698;
    v0 = v0 - hi_52698 + (u32)(unsigned long)ref_t32_data_e2098;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (176)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[7].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 568;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[0]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 552;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[1].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[6].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 568;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 552;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 568;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    a2 = s8 + 816;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[7].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] >> (vx[2].w[i] & 31)) + ((vx[2].w[i] & 31) ? ((vx[3].w[i] >> (((vx[2].w[i] & 31) - 1) & 31)) & 1) : 0); vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[3].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[6].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[10].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[5].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[9].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] >> (vx[3].w[i] & 31)) + ((vx[3].w[i] & 31) ? ((vx[4].w[i] >> (((vx[3].w[i] & 31) - 1) & 31)) & 1) : 0); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(s8 + (208)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] >> (vx[4].w[i] & 31)) + ((vx[4].w[i] & 31) ? ((vx[1].w[i] >> (((vx[4].w[i] & 31) - 1) & 31)) & 1) : 0); vx[1] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[4].b[i] = ((volatile u8 *)(unsigned long)(t2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[1].b[(sel & 31) >> 1] : vx[3].b[(sel & 31) >> 1]); } vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[6].b[(sel & 31) >> 1]); } vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[4].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[8].b[(sel & 31) >> 1] : vx[5].b[(sel & 31) >> 1]); } vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s7 + (0)))[i] = vx[2].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a1 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(a0 + (0)))[i] = vx[5].b[i]; }
    a1 = 12;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v1 + (0)))[i] = vx[3].b[i]; }
    v1 = 0;
L_52788:
    a0 = v1 << (0x2 & 31);
    a0 = v0 + a0;
    a0 = *(volatile u16 *)(unsigned long)(a0 + (18));
    a2 = s7 + v1;
    v1 = v1 + 1;
    branch = (v1 != a1); *(volatile u8 *)(unsigned long)(a2 + (8)) = a0;
    if (branch) goto L_52788;
    goto L_527a4;
L_527a4:
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(s7 + (0)))[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 600;
    a1 = s7 + 16;
    { unsigned int i; for (i = 0; i < 16; i++) vx[11].b[i] = ((volatile u8 *)(unsigned long)(a1 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = hi_527d0;
    v0 = v0 - hi_527d0 + (u32)(unsigned long)ref_t32_data_ce170;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 584;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 648;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[15].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[2].b[(sel & 31) >> 1]); } vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[1].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[0].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 664;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[14].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[14].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[14].w[i] - (s64)(s32)vx[1].w[i])); vx[14] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 680;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[13].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[13].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[13].w[i] - (s64)(s32)vx[1].w[i])); vx[13] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 512;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[12].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[12].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[12].w[i] - (s64)(s32)vx[1].w[i])); vx[12] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (344)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[8].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[8].w[i] - (s64)(s32)vx[1].w[i])); vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[16] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (360)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[11].w[i] - (s64)(s32)vx[1].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[17] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (464)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[17].w[i] << (8 & 31); vx[17] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] * (u32)vx[1].w[i]; vx[10] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (480)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] * (u32)vx[1].w[i]; vx[9] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (496)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[18] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 528;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 696;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (384)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[14].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (400)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[14].w[i] < 0) ? ~0U : 0; vx[14] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[13].w[i] * (u32)vx[1].w[i]; vx[7] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (416)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i] < 0) ? ~0U : 0; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[14].w[i]) | (vx[4].w[i] & vx[14].w[i]); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[12].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (432)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i] < 0) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[13].w[i]) | (vx[7].w[i] & vx[13].w[i]); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[8].w[i] * (u32)vx[1].w[i]; vx[2] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (448)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i] < 0) ? ~0U : 0; vx[8] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[18].w[i] & ~vx[12].w[i]) | (vx[3].w[i] & vx[12].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[1].w[i]; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i] < 0) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[8].w[i]) | (vx[2].w[i] & vx[8].w[i]); vx[3] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[16].w[i] << (8 & 31); vx[2] = tmp; }
    v0 = s8 + 712;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[11].w[i]) | (vx[1].w[i] & vx[11].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[5].w[i])); vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[2].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[3].w[i] + (s64)(s32)vx[2].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[2].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[17].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[1].w[i] + (s64)(s32)vx[17].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[1].w[i] + (s64)(s32)vx[17].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[1] = tmp; }
    v0 = s8 + 728;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[7].w[i] + (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[7].w[i] + (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[7].w[i] + (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[4].w[i] + (s64)(s32)vx[1].w[i])); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = 128; vx[4] = tmp; }
    v0 = hi_528e8;
    v0 = v0 - hi_528e8 + (u32)(unsigned long)ref_t32_data_ce180;
    { unsigned int i; for (i = 0; i < 16; i++) vx[27].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[3].w[i] + (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[3].w[i] + (s64)(s32)vx[4].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] >> (8 & 31); vx[3] = tmp; }
    v0 = hi_528fc;
    v0 = v0 - hi_528fc + (u32)(unsigned long)ref_t32_data_ce190;
    { unsigned int i; for (i = 0; i < 16; i++) vx[28].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[9].w[i] + (s64)(s32)vx[6].w[i])); vx[6] = tmp; }
    v0 = (s32)vx[3].w[0];
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[5].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[5].w[i] + (s64)(s32)vx[1].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[4].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[2].w[i] + (s64)(s32)vx[4].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[2].w[i] + (s64)(s32)vx[4].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[6].w[i] + (s64)(s32)vx[1].w[i])); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[7].w[i] >> (8 & 31); vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] >> (8 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[1].w[i] >> (8 & 31); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] >> (8 & 31); vx[2] = tmp; }
    *(volatile u8 *)(unsigned long)(s7 + (16)) = v0;
    v0 = (s32)vx[3].w[1];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[27].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[5].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[27].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[2] = tmp; }
    *(volatile u8 *)(unsigned long)(s7 + (17)) = v0;
    v0 = (s32)vx[3].w[2];
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[28].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[2].b[(sel & 31) >> 1] : vx[7].b[(sel & 31) >> 1]); } vx[4] = tmp; }
    *(volatile u8 *)(unsigned long)(s7 + (18)) = v0;
    v0 = (s32)vx[3].w[3];
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s7 + (0)))[i] = vx[4].b[i]; }
    *(volatile u8 *)(unsigned long)(s7 + (19)) = v0;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    v0 = 4;
    branch = (v1 != v0); v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_529e4;
    goto L_52968;
L_52968:
    v0 = s8 + 768;
L_5296c:
    a1 = s7;
    a0 = t3;
    a2 = 20;
    *(volatile u32 *)(unsigned long)(s8 + (880)) = t2;
    *(volatile u32 *)(unsigned long)(s8 + (864)) = t4;
    *(volatile u32 *)(unsigned long)(s8 + (848)) = t0;
    *(volatile u32 *)(unsigned long)(s8 + (832)) = a3;
    *(volatile u32 *)(unsigned long)(s8 + (784)) = t1;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    callee = s5; *(volatile u32 *)(unsigned long)(s8 + (752)) = t3;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52998;
L_52998:
    t4 = *(volatile u32 *)(unsigned long)(s8 + (864));
    t1 = *(volatile u32 *)(unsigned long)(s8 + (784));
    t3 = *(volatile u32 *)(unsigned long)(s8 + (752));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (848));
    a3 = *(volatile u32 *)(unsigned long)(s8 + (832));
    v0 = s8 + 768;
    t4 = t4 + -1;
    t1 = t1 + 2;
    t3 = t3 + 20;
    s7 = s7 + 20;
    t0 = t0 + 64;
    a3 = a3 + 1;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    branch = (t4 != 0); t2 = *(volatile u32 *)(unsigned long)(s8 + (880));
    if (branch) goto L_5204c;
    goto L_529d4;
L_529d4:
    s2 = s2 + 16;
    s2 = s2 & 0xffff;
    s4 = s4 + 16; goto L_51bb4;
L_529e4:
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(t3 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 16; i++) tmp.b[i] = 0; vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[8] = tmp; }
    v0 = 64;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = v0; vx[13] = tmp; }
    v0 = s8 + 584;
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 600;
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    a2 = t3 + 16;
    t5 = s7 + 20;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[22] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[22].w[i] | vx[22].w[i]; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[22].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[22].w[i] + vx[6].w[i]); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[21] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 584;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[21].w[i] | vx[21].w[i]; vx[25] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[21].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[21].w[i] + vx[6].w[i]); vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[12] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 600;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[15].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[1].b[(sel & 31) >> 1]); } vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[12].w[i] | vx[12].w[i]; vx[24] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[12].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[12].w[i] + vx[6].w[i]); vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[17] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[2].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 632;
    { unsigned int i; for (i = 0; i < 16; i++) vx[5].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[1].w[i] | vx[1].w[i]; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[17].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[17].w[i] + vx[6].w[i]); vx[29] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[1].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[1].w[i] + vx[6].w[i]); vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[2].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[14] = tmp; }
    v0 = s8 + 752;
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[5].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[30] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[15].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[7].b[(sel & 31) >> 1] : vx[4].b[(sel & 31) >> 1]); } vx[7] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[14].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[14].w[i] + vx[6].w[i]); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    v0 = s8 + 768;
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[26].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[17].w[i] - (s64)(s32)vx[26].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[17].w[i] - (s64)(s32)vx[26].w[i])); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[14].w[i] - (s64)(s32)vx[25].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[14].w[i] - (s64)(s32)vx[25].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[14].w[i] - (s64)(s32)vx[25].w[i])); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[30].w[i] - (s64)(s32)vx[24].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[30].w[i] - (s64)(s32)vx[24].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[30].w[i] - (s64)(s32)vx[24].w[i])); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[30].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[30].w[i] + vx[6].w[i]); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[6].b[i]; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[6].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    v0 = s8 + 784;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[11].w[i] * (u32)vx[15].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[10].w[i] * (u32)vx[15].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[9].w[i] * (u32)vx[15].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[7].w[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[7].w[i] + vx[6].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[7].w[i] + vx[6].w[i]); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[6].b[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[7].w[i] - (s64)(s32)vx[23].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[7].w[i] - (s64)(s32)vx[23].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[7].w[i] - (s64)(s32)vx[23].w[i])); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[14].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[14].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[14].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[17].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[17].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[17].w[i])); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[30].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[30].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[30].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[7].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[23].w[i] - (s64)(s32)vx[7].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[7].w[i])); vx[4] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[10].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[10].w[i] + vx[13].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[10].w[i] >> (7 & 31); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[6].w[i] * (u32)vx[15].w[i]; vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[15].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[11].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[11].w[i] + vx[13].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[9].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[9].w[i] + vx[13].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[11].w[i] >> (7 & 31); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[9].w[i] >> (7 & 31); vx[9] = tmp; }
    v0 = s8 + 752;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[10].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[6].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[6].w[i] + vx[13].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[6].w[i] >> (7 & 31); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[11].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[9].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[19].w[i]) | (vx[15].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[10].w[i]) ? ~0U : 0; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[6].w[i]  < (s32)vx[15].w[i]) ? ~0U : 0; vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[20].w[i]) | (vx[15].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[18].w[i]) | (vx[15].w[i] & vx[18].w[i]); vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[11].w[i]) ? ~0U : 0; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[9].w[i]) ? ~0U : 0; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[31].w[i]) | (vx[15].w[i] & vx[31].w[i]); vx[31] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[6].w[i]) ? ~0U : 0; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[10].w[i]) | (vx[8].w[i] & vx[10].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = vx[15].w[i] | vx[15].w[i]; vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[11].w[i]) | (vx[8].w[i] & vx[11].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[18].w[i] & ~vx[9].w[i]) | (vx[8].w[i] & vx[9].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[31].w[i] & ~vx[6].w[i]) | (vx[8].w[i] & vx[6].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[25].w[i] + (u32)vx[10].w[i]; vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[22].w[i]  < (s32)vx[17].w[i]) ? ~0U : 0; vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[26].w[i] + (u32)vx[11].w[i]; vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[23].w[i] + (u32)vx[6].w[i]; vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[24].w[i] + (u32)vx[9].w[i]; vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[21].w[i]  < (s32)vx[14].w[i]) ? ~0U : 0; vx[21] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[12].w[i]  < (s32)vx[30].w[i]) ? ~0U : 0; vx[12] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[7].w[i] & ~vx[1].w[i]) | (vx[6].w[i] & vx[1].w[i]); vx[6] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (248)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[17].w[i] & ~vx[22].w[i]) | (vx[11].w[i] & vx[22].w[i]); vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[14].w[i] & ~vx[21].w[i]) | (vx[10].w[i] & vx[21].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[30].w[i] & ~vx[12].w[i]) | (vx[9].w[i] & vx[12].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[2].w[i] * (u32)vx[1].w[i]; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[3].w[i] * (u32)vx[1].w[i]; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[5].w[i] * (u32)vx[1].w[i]; vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (u32)vx[4].w[i] * (u32)vx[1].w[i]; vx[4] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(s8 + (192)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[2].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[2].w[i] + vx[13].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[2].w[i] >> (7 & 31); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[3].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[3].w[i] + vx[13].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[5].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[5].w[i] + vx[13].w[i]); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((u64)vx[4].w[i] + vx[13].w[i]) > 4294967295ULL ? 4294967295ULL : ((u64)vx[4].w[i] + vx[13].w[i]); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[3].w[i] >> (7 & 31); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[5].w[i] >> (7 & 31); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (s32)vx[13].w[i] >> (7 & 31); vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[2].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[3].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[5].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[13].w[i]  < (s32)vx[1].w[i]) ? ~0U : 0; vx[1] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[2].w[i] & ~vx[19].w[i]) | (vx[16].w[i] & vx[19].w[i]); vx[19] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[2].w[i]) ? ~0U : 0; vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[3].w[i] & ~vx[20].w[i]) | (vx[16].w[i] & vx[20].w[i]); vx[20] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[5].w[i] & ~vx[18].w[i]) | (vx[16].w[i] & vx[18].w[i]); vx[18] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[13].w[i] & ~vx[1].w[i]) | (vx[16].w[i] & vx[1].w[i]); vx[16] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[19].w[i] & ~vx[2].w[i]) | (vx[8].w[i] & vx[2].w[i]); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[5].w[i]) ? ~0U : 0; vx[5] = tmp; }
    v0 = s8 + 768;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[3].w[i]) ? ~0U : 0; vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[2].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[25].w[i] - (s64)(s32)vx[2].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[25].w[i] - (s64)(s32)vx[2].w[i])); vx[2] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[25].w[i]) ? ~0U : 0; vx[25] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[8].w[i]  < (s32)vx[13].w[i]) ? ~0U : 0; vx[13] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[18].w[i] & ~vx[5].w[i]) | (vx[8].w[i] & vx[5].w[i]); vx[5] = tmp; }
    v0 = s8 + 784;
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[20].w[i] & ~vx[3].w[i]) | (vx[8].w[i] & vx[3].w[i]); vx[3] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[10].w[i] & ~vx[25].w[i]) | (vx[2].w[i] & vx[25].w[i]); vx[10] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[5].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[24].w[i] - (s64)(s32)vx[5].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[24].w[i] - (s64)(s32)vx[5].w[i])); vx[5] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[16].w[i] & ~vx[13].w[i]) | (vx[8].w[i] & vx[13].w[i]); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[24].w[i]) ? ~0U : 0; vx[24] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) vx[1].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[3].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[26].w[i] - (s64)(s32)vx[3].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[26].w[i] - (s64)(s32)vx[3].w[i])); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[16].w[i]) < (-2147483648LL) ? (-2147483648LL) : (((s64)(s32)vx[23].w[i] - (s64)(s32)vx[16].w[i]) > 2147483647LL ? 2147483647LL : ((s64)(s32)vx[23].w[i] - (s64)(s32)vx[16].w[i])); vx[16] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[29].w[i]  < (s32)vx[26].w[i]) ? ~0U : 0; vx[26] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[9].w[i] & ~vx[24].w[i]) | (vx[5].w[i] & vx[24].w[i]); vx[9] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = ((s32)vx[1].w[i]  < (s32)vx[23].w[i]) ? ~0U : 0; vx[23] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[11].w[i] & ~vx[26].w[i]) | (vx[22].w[i] & vx[26].w[i]); vx[22] = tmp; }
    { union t32_vec tmp; unsigned int i; for (i = 0; i < 4; i++) tmp.w[i] = (vx[6].w[i] & ~vx[23].w[i]) | (vx[16].w[i] & vx[23].w[i]); vx[6] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[27].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[10].b[(sel & 31) >> 1] : vx[22].b[(sel & 31) >> 1]); } vx[11] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[27].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[6].b[(sel & 31) >> 1] : vx[9].b[(sel & 31) >> 1]); } vx[27] = tmp; }
    { union t32_vec tmp; unsigned int i, sel; for (i = 0; i < 16; i++) { sel = vx[28].b[i]; tmp.b[i] = (sel & 128) ? 0 : ((sel & 1) ? vx[27].b[(sel & 31) >> 1] : vx[11].b[(sel & 31) >> 1]); } vx[27] = tmp; }
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(s7 + (0)))[i] = vx[27].b[i]; }
L_52c40:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u8 *)(unsigned long)(a2 + (0));
    v0 = *(volatile u8 *)(unsigned long)(a1 + (0));
    t6 = v1 + a0;
    v1 = (s32)t6 < (s32)(v0);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    if (branch) goto L_52ca8;
    goto L_52c5c;
L_52c5c:
    v1 = v0 - a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v1 = v1 * v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v1 = v1 + 64;
    v1 = (s32)v1 >> (0x7 & 31);
    v0 = (s32)v1 < (s32)(v0);
    branch = (v0 == 0); v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_52c88;
    goto L_52c80;
L_52c80:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = t6; goto L_52d04;
L_52c88:
    v0 = (s32)v0 < (s32)(v1);
    branch = (v0 == 0); v1 = a0 + v1;
    if (branch) goto L_52ca0;
    goto L_52c94;
L_52c94:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228));
    a0 = v0 + a0; goto L_52ce4;
L_52ca0:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v1; goto L_52d04;
L_52ca8:
    v1 = v1 + v0;
    v1 = (s32)v1 < (s32)(a0);
    if (v1 == 0) { a1 = a1 + 1; goto L_52d08; }
    goto L_52cb8;
L_52cb8:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = a0 - v0;
    v0 = v0 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    v0 = v0 + 64;
    v0 = (s32)v0 >> (0x7 & 31);
    v1 = (s32)v0 < (s32)(v1);
    branch = (v1 == 0); v1 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_52cec;
    goto L_52cdc;
L_52cdc:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (224));
L_52ce0:
    a0 = a0 - v0;
L_52ce4:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = a0; goto L_52d04;
L_52cec:
    v1 = (s32)v1 < (s32)(v0);
    if (v1 == 0) { v0 = a0 - v0; goto L_52d00; }
    goto L_52cf8;
L_52cf8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (228)); goto L_52ce0;
L_52d00:
    *(volatile u8 *)(unsigned long)(a1 + (0)) = v0;
L_52d04:
    a1 = a1 + 1;
L_52d08:
    branch = (t5 != a1); a2 = a2 + 1;
    if (branch) goto L_52c40;
    goto L_52d10;
L_52d10:
    v0 = s8 + 768; goto L_5296c;
L_52d18:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (336));
    branch = (v0 == 0); a0 = s2 << (0x6 & 31);
    if (branch) goto L_52ef0;
    goto L_52d24;
L_52d24:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    a2 = 64;
    a1 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    a0 = v0 + a0;
L_52d40:
    v0 = hi_52d40;
    v0 = v0 - hi_52d40 + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; ;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52d50;
L_52d50:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 568;
    t0 = s2 << (0x6 & 31);
    a1 = *(volatile u32 *)(unsigned long)(s8 + (280));
    a2 = s8 + 184;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    s5 = v0 + t0;
    v0 = s7 - hi_51be0 + (u32)(unsigned long)ref_tisp_lce_thres_search;
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52d80;
L_52d80:
    v0 = s8 + s4;
    a3 = *(volatile u8 *)(unsigned long)(v0 + (88));
    v0 = *(volatile u16 *)(unsigned long)(s8 + (180));
    a2 = s8 + 184;
    a1 = s8 + 188;
    *(volatile u32 *)(unsigned long)(sp + (16)) = v0;
    v0 = hi_52d98;
    v0 = v0 - hi_52d98 + (u32)(unsigned long)ref_tisp_lce_hist_method;
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52da8;
L_52da8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (544));
    v1 = s8 + 24;
    a0 = v1;
    a2 = 64;
    a1 = 0;
    callee = v0; *(volatile u32 *)(unsigned long)(s8 + (552)) = v1;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52dc4;
L_52dc4:
    a2 = s8 + 568;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a2 + (0)))[i]; }
    v1 = *(volatile u32 *)(unsigned long)(s8 + (552));
    a1 = 0;
    v0 = 0;
    a0 = v1;
    v1 = 64;
L_52de0:
    a2 = a0 + a1;
    *(volatile u16 *)(unsigned long)(a2 + (0)) = v0;
    a2 = s5 + a1;
    a2 = *(volatile u16 *)(unsigned long)(a2 + (0));
    a1 = a1 + 2;
    v0 = v0 + a2;
    branch = (a1 != v1); v0 = v0 & 0xffff;
    if (branch) goto L_52de0;
    goto L_52e00;
L_52e00:
    v1 = 20;
    s2 = s2 * v1;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (296));
    branch = (v0 != 0); s5 = v1 + s2;
    if (branch) goto L_52f44;
    goto L_52e14;
L_52e14:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    a0 = hi_52e1c;
    v0 = hi_52e20;
    a2 = 1065;
    a1 = s6;
    v0 = v0 - hi_52e20 + ((u32)(unsigned long)ref_printk + (0));
    callee = v0; a0 = a0 - hi_52e1c + (u32)(unsigned long)ref_t32_data_c9660;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52e38;
L_52e38:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    v0 = s8 + 552;
L_52e44:
    a2 = *(volatile u32 *)(unsigned long)(s8 + (376));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (380));
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = hi_52e50;
    v0 = v0 - hi_52e50 + (u32)(unsigned long)ref_tisp_lce_hist_adjust;
    callee = v0; a0 = s5;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52e60;
L_52e60:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (300));
    a0 = s8 + 552;
    v0 = 4;
    s2 = v1 + s2;
    v1 = *(volatile u32 *)(unsigned long)(s8 + (276));
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(a0 + (0)))[i]; }
    branch = (v1 == v0); a2 = *(volatile u32 *)(unsigned long)(s8 + (228));
    if (branch) goto L_52ea4;
    goto L_52e80;
L_52e80:
    a1 = *(volatile u32 *)(unsigned long)(s8 + (224));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (264));
    v0 = hi_52e88;
    v0 = v0 - hi_52e88 + (u32)(unsigned long)ref_tisp_lce_16bit_data_converge;
    *(volatile u32 *)(unsigned long)(sp + (16)) = s5;
    callee = v0; a3 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52e9c;
L_52e9c:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
L_52ea4:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = hi_52eac;
    a2 = 20;
    a1 = s5;
    v0 = v0 - hi_52eac + ((u32)(unsigned long)ref_memcpy + (0));
    callee = v0; a0 = s2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52ec4;
L_52ec4:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v0 + (0)))[i]; }
    s4 = s4 + 1;
L_52ed0:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (328));
    s2 = s3 - v0;
    s2 = s2 + s4;
    v0 = 32;
    branch = (s4 != v0); s2 = s2 & 0xffff;
    if (branch) goto L_52d18;
    goto L_52ee8;
L_52ee8:
    v0 = *(volatile u32 *)(unsigned long)(s8 + (744)); goto L_52ff0;
L_52ef0:
    v0 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) ((volatile u8 *)(unsigned long)(v0 + (0)))[i] = vx[0].b[i]; }
    v0 = *(volatile u32 *)(unsigned long)(s8 + (272));
    t2 = v0 + a0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (960));
    t1 = v0 + a0;
    v0 = hi_52f08;
    a1 = t1;
    v0 = v0 - hi_52f08 + (u32)(unsigned long)ref_get_distance_1dim;
    callee = v0; a0 = t2;
    result = ((u64 (*)(u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32,u32))(unsigned long)callee)(a0,a1,a2,a3, *(u32 *)(unsigned long)(sp + 16), *(u32 *)(unsigned long)(sp + 20), *(u32 *)(unsigned long)(sp + 24), *(u32 *)(unsigned long)(sp + 28), *(u32 *)(unsigned long)(sp + 32), *(u32 *)(unsigned long)(sp + 36), *(u32 *)(unsigned long)(sp + 40), *(u32 *)(unsigned long)(sp + 44), *(u32 *)(unsigned long)(sp + 48), *(u32 *)(unsigned long)(sp + 52), *(u32 *)(unsigned long)(sp + 56), *(u32 *)(unsigned long)(sp + 60), *(u32 *)(unsigned long)(sp + 64), *(u32 *)(unsigned long)(sp + 68), *(u32 *)(unsigned long)(sp + 72), *(u32 *)(unsigned long)(sp + 76), *(u32 *)(unsigned long)(sp + 80), *(u32 *)(unsigned long)(sp + 84), *(u32 *)(unsigned long)(sp + 88), *(u32 *)(unsigned long)(sp + 92), *(u32 *)(unsigned long)(sp + 96), *(u32 *)(unsigned long)(sp + 100), *(u32 *)(unsigned long)(sp + 104), *(u32 *)(unsigned long)(sp + 108), *(u32 *)(unsigned long)(sp + 112), *(u32 *)(unsigned long)(sp + 116), *(u32 *)(unsigned long)(sp + 120), *(u32 *)(unsigned long)(sp + 124), *(u32 *)(unsigned long)(sp + 128), *(u32 *)(unsigned long)(sp + 132), *(u32 *)(unsigned long)(sp + 136), *(u32 *)(unsigned long)(sp + 140), *(u32 *)(unsigned long)(sp + 144), *(u32 *)(unsigned long)(sp + 148), *(u32 *)(unsigned long)(sp + 152), *(u32 *)(unsigned long)(sp + 156), *(u32 *)(unsigned long)(sp + 160), *(u32 *)(unsigned long)(sp + 164), *(u32 *)(unsigned long)(sp + 168), *(u32 *)(unsigned long)(sp + 172), *(u32 *)(unsigned long)(sp + 176), *(u32 *)(unsigned long)(sp + 180), *(u32 *)(unsigned long)(sp + 184), *(u32 *)(unsigned long)(sp + 188), *(u32 *)(unsigned long)(sp + 192), *(u32 *)(unsigned long)(sp + 196), *(u32 *)(unsigned long)(sp + 200), *(u32 *)(unsigned long)(sp + 204), *(u32 *)(unsigned long)(sp + 208), *(u32 *)(unsigned long)(sp + 212), *(u32 *)(unsigned long)(sp + 216), *(u32 *)(unsigned long)(sp + 220), *(u32 *)(unsigned long)(sp + 224), *(u32 *)(unsigned long)(sp + 228), *(u32 *)(unsigned long)(sp + 232), *(u32 *)(unsigned long)(sp + 236), *(u32 *)(unsigned long)(sp + 240), *(u32 *)(unsigned long)(sp + 244), *(u32 *)(unsigned long)(sp + 248), *(u32 *)(unsigned long)(sp + 252));
    v0 = result; v1 = result >> 32;
    goto L_52f1c;
L_52f1c:
    v1 = *(volatile u32 *)(unsigned long)(s8 + (340));
    v0 = (u32)v1 < (u32)(v0);
    v1 = s8 + 552;
    { unsigned int i; for (i = 0; i < 16; i++) vx[0].b[i] = ((volatile u8 *)(unsigned long)(v1 + (0)))[i]; }
    if (v0 == 0) { s4 = s4 + 1; goto L_52ed0; }
    goto L_52f34;
L_52f34:
    a2 = 64;
    a1 = t1;
    a0 = t2; goto L_52d40;
L_52f44:
    v1 = hi_52f44;
    a1 = *(volatile u8 *)(unsigned long)(v1 - hi_52f44 + (u32)(unsigned long)ref_t32_data_d6c67);
    v1 = 1;
    a2 = s5;
    v1 = v1 << (a1 & 31);
    if (v1 == 0x80000000U && v0 == ~0U) { lo = 0x80000000U; hi = 0; } else if (v0) { lo = (s32)v1 / (s32)v0; hi = (s32)v1 % (s32)v0; } else { lo = (s32)v1 < 0 ? 1 : ~0U; hi = v1; }
    a3 = s5 + 8;
    v0 = lo;
L_52f64:
    v1 = *(volatile u16 *)(unsigned long)(a0 + (0));
    a1 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    v1 = v1 * v0;
    a1 = *(volatile u8 *)(unsigned long)(a1 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    t1 = *(volatile u8 *)(unsigned long)(t0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a2 = a2 + 1;
    a0 = a0 + 2;
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    v1 = v1 >> (t1 & 31);
    v1 = a1 + v1;
    branch = (a3 != a2); *(volatile u8 *)(unsigned long)(a2 + (-1)) = v1;
    if (branch) goto L_52f64;
    goto L_52f9c;
L_52f9c:
    a2 = 0;
    a3 = 12;
L_52fa4:
    v1 = a2 << (0x2 & 31);
    a0 = s8 + 24;
    v1 = a0 + v1;
    v1 = *(volatile u16 *)(unsigned long)(v1 + (18));
    a0 = *(volatile u32 *)(unsigned long)(s8 + (308));
    t1 = s5 + a2;
    v1 = v1 * v0;
    a1 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc10 + (u32)(unsigned long)ref_t32_data_d6c64);
    a0 = *(volatile u32 *)(unsigned long)(s8 + (304));
    a2 = a2 + 1;
    a0 = *(volatile u8 *)(unsigned long)(a0 - hi_4dc0c + (u32)(unsigned long)ref_t32_data_d6c65);
    a1 = v1 >> (a1 & 31);
    a1 = a1 & 0x1;
    a0 = v1 >> (a0 & 31);
    a0 = a1 + a0;
    branch = (a2 != a3); *(volatile u8 *)(unsigned long)(t1 + (8)) = a0;
    if (branch) goto L_52fa4;
    goto L_52fe8;
L_52fe8:
    v0 = s8 + 552; goto L_52e44;
L_52ff0:
    s3 = v0 + s3;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (312));
    s7 = s3 & 0xffff;
    v0 = v0 + 1;
    *(volatile u32 *)(unsigned long)(s8 + (312)) = v0;
    v0 = *(volatile u32 *)(unsigned long)(s8 + (332));
    v0 = v0 + 128;
    *(volatile u32 *)(unsigned long)(s8 + (332)) = v0; goto L_5070c;
L_53014:
    sp = s8;
    ra = *(volatile u32 *)(unsigned long)(sp + (948));
    s8 = *(volatile u32 *)(unsigned long)(sp + (944));
    s7 = *(volatile u32 *)(unsigned long)(sp + (940));
    s6 = *(volatile u32 *)(unsigned long)(sp + (936));
    s5 = *(volatile u32 *)(unsigned long)(sp + (932));
    s4 = *(volatile u32 *)(unsigned long)(sp + (928));
    s3 = *(volatile u32 *)(unsigned long)(sp + (924));
    s2 = *(volatile u32 *)(unsigned long)(sp + (920));
    s1 = *(volatile u32 *)(unsigned long)(sp + (916));
    s0 = *(volatile u32 *)(unsigned long)(sp + (912));
    sp = sp + 952;
    return ((u64)v1 << 32) | v0;
}
